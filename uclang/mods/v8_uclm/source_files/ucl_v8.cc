
@begin
include "ucl_v8.h"
@end

// - v8 global init object -
v8_c g_v8;

/*
 * methods of class v8_c
 */

Handle<Value> v8_c::create_v8_object(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_v8_object)
  {
    v8_htype hnd_value = (v8_htype)location_ptr->v_data_ptr;
    return *((Persistent<Value> *)&hnd_value);
  }
  else if (location_ptr->v_type == c_bi_class_v8_reference)
  {/*{{{*/
    return ((v8_reference_s *)location_ptr->v_data_ptr)->get();
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;
    Handle<Object> hnd_object = Object::New();

    if (tree_ptr->root_idx != c_idx_not_exist)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        pointer_map_tree_s_node &node = tree_ptr->data[t_idx];

        location_s *key_location = it.get_location_value(node.object.key);
        Handle<Value> hnd_key = create_v8_object(it,key_location);

        // - ERROR -
        if (hnd_key->IsUndefined())
        {
          return Undefined();
        }

        location_s *value_location = it.get_location_value(node.object.value);
        Handle<Value> hnd_value = create_v8_object(it,value_location);

        // - ERROR -
        if (hnd_value->IsUndefined())
        {
          return Undefined();
        }

        // - set v8 object attribute -
        hnd_object->Set(hnd_key,hnd_value);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return hnd_object;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      {
        return Null();
      }
    case c_bi_class_char:
      {
        return Number::New((char)location_ptr->v_data_ptr);
      }
    case c_bi_class_integer:
      {
        return Number::New((long long int)location_ptr->v_data_ptr);
      }
    case c_bi_class_float:
      {
        return Number::New(*((double *)&location_ptr->v_data_ptr));
      }
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        return String::New(string_ptr->data,string_ptr->size - 1);
      }
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
        Handle<Array> hnd_array = Array::New(array_ptr->used);

        if (array_ptr->used)
        {
          unsigned idx = 0;
          do {
            Handle<Value> hnd_item = create_v8_object(it,(location_s *)array_ptr->data[idx]);

            // - ERROR -
            if (hnd_item->IsUndefined())
            {
              return Undefined();
            }

            // - set v8 array item -
            hnd_array->Set(idx,hnd_item);

          } while(++idx < array_ptr->used);
        }

        return hnd_array;
      }/*}}}*/

    // - ERROR -
    default:
      return Undefined();
    }
  }
}/*}}}*/

location_s *v8_c::v8_object_value(interpreter_thread_s &it,Handle<Value> hnd_value,uli source_pos)
{/*{{{*/
  if (hnd_value->IsNull())
  {
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return (location_s *)it.blank_location;
  }
  else if (hnd_value->IsBoolean())
  {
    long long int value = hnd_value->BooleanValue();

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    return new_location;
  }
  else if (hnd_value->IsNumber())
  {
    double value = hnd_value->NumberValue();

    basic_64b &v_data_ptr = *((basic_64b *)&value);
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,v_data_ptr);
    return new_location;
  }
  else if (hnd_value->IsString())
  {
    Handle<String> hnd_string = Handle<String>::Cast(hnd_value);
    int length = hnd_string->Utf8Length();

    // - create string object -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->create(length);
    hnd_string->WriteUtf8(string_ptr->data,length);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    return new_location;
  }
  else if (hnd_value->IsArray())
  {/*{{{*/
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

    Handle<Array> hnd_array = Handle<Array>::Cast(hnd_value);
    int length = hnd_array->Length();

    if (length > 0)
    {
      int idx = 0;
      do {
        location_s *item_location = v8_object_value(it,hnd_array->Get(idx),source_pos);

        // - ERROR -
        if (item_location == NULL)
        {
          it.release_location_ptr(arr_location);
          return NULL;
        }

        // - insert item to array -
        array_ptr->push(item_location);

      } while(++idx < length);
    }

    return arr_location;
  }/*}}}*/
  else if (hnd_value->IsObject())
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();
    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = source_pos;

    BIC_CREATE_NEW_LOCATION(dict_location,c_rm_class_dict,tree_ptr);

    Handle<Object> hnd_object = Handle<Object>::Cast(hnd_value);
    Handle<Array> hnd_keys = hnd_object->GetOwnPropertyNames();
    int length = hnd_keys->Length();

    if (length > 0)
    {
      int idx = 0;
      do {
        Handle<Value> hnd_key = hnd_keys->Get(idx);
        Handle<Value> hnd_item = hnd_object->Get(hnd_key);

        location_s *key_location = v8_object_value(it,hnd_key,source_pos);

        // - ERROR -
        if (key_location == NULL)
        {
          it.release_location_ptr(dict_location);
          return NULL;
        }

        location_s *value_location = v8_object_value(it,hnd_item,source_pos);

        // - ERROR -
        if (value_location == NULL)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(dict_location);

          return NULL;
        }

        pointer_map_s map = {key_location,value_location};
        unsigned index = tree_ptr->get_idx(map);

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank ||
            index != c_idx_not_exist)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(value_location);
          it.release_location_ptr(dict_location);

          return NULL;
        }

        // - insert map to dictionary -
        tree_ptr->insert(map);

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(value_location);
          it.release_location_ptr(dict_location);

          return NULL;
        }

      } while(++idx < length);
    }

    return dict_location;
  }/*}}}*/

  return NULL;
}/*}}}*/

