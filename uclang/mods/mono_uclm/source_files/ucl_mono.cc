
@begin
include "ucl_mono.h"
@end

/*
 * static members of class mono_c
 */

location_s *mono_c::assembly_loc = NULL;
bool mono_c::assembly_opened = false;;

MonoObject *mono_c::mono_exc = NULL;

MonoDomain   *mono_c::domain   = NULL;
MonoAssembly *mono_c::assembly = NULL;
MonoImage    *mono_c::image    = NULL;

MonoClass *mono_c::array_class = NULL;
MonoClass *mono_c::list_class  = NULL;
MonoClass *mono_c::stack_class = NULL;
MonoClass *mono_c::queue_class = NULL;
MonoClass *mono_c::hset_class  = NULL;
MonoClass *mono_c::llist_class = NULL;
MonoClass *mono_c::dict_class  = NULL;

MonoMethod *mono_c::list_constr  = NULL;
MonoMethod *mono_c::stack_constr = NULL;
MonoMethod *mono_c::queue_constr = NULL;
MonoMethod *mono_c::hset_constr  = NULL;
MonoMethod *mono_c::llist_constr = NULL;
MonoMethod *mono_c::dict_constr  = NULL;

MonoMethod *mono_c::hset_arr  = NULL;
MonoMethod *mono_c::llist_arr = NULL;
MonoMethod *mono_c::dict_arr  = NULL;

MonoMethod *mono_c::list_to_array  = NULL;
MonoMethod *mono_c::stack_to_array = NULL;
MonoMethod *mono_c::queue_to_array = NULL;

MonoMethod *mono_c::dict_add = NULL;

MonoProperty *mono_c::list_item = NULL;
MonoProperty *mono_c::dict_item = NULL;

/*
 * methods of class mono_c
 */

MonoObject *mono_c::create_mono_object(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_mono_object)
  {
    return mono_gchandle_get_target((guint32)location_ptr->v_data_ptr);
  }
  else if (location_ptr->v_type == c_bi_class_mono_property)
  {/*{{{*/
    mono_property_s *mp_ptr = (mono_property_s *)location_ptr->v_data_ptr;

    mono_c::mono_exc = NULL;
    MonoObject *mono_result = mono_property_get_value(mp_ptr->mono_prop,
      mono_gchandle_get_target(mp_ptr->gchandle),
      NULL,&mono_exc);

    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    return mono_result;
  }/*}}}*/
  else if (location_ptr->v_type == c_bi_class_mono_item_ref)
  {/*{{{*/
    return ((mono_reference_s *)location_ptr->v_data_ptr)->get_item();
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_stack)
  {/*{{{*/
    pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),array_ptr->used);

    if (array_ptr->used > 0)
    {
      pointer *ptr = array_ptr->data;
      pointer *ptr_end = ptr + array_ptr->used;
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = create_mono_object(it,it.get_location_value(*ptr));

        // - ERROR -
        if (mono_item == NULL)
        {
          return NULL;
        }

        mono_array_set(mono_array,MonoObject *,idx++,mono_item);

      } while(++ptr < ptr_end);
    }

    mono_c::mono_exc = NULL;
    MonoObject *mono_stack = mono_runtime_invoke(stack_constr,NULL,(void **)&mono_array,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    return mono_stack;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_queue)
  {/*{{{*/
    pointer_queue_s *queue_ptr = (pointer_queue_s *)location_ptr->v_data_ptr;
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),queue_ptr->used);

    if (queue_ptr->used > 0)
    {
      unsigned fir_cnt;
      unsigned sec_cnt;

      if (queue_ptr->begin + queue_ptr->used > queue_ptr->size)
      {
        sec_cnt = queue_ptr->begin + queue_ptr->used - queue_ptr->size;
        fir_cnt = queue_ptr->used - sec_cnt;
      }
      else
      {
        fir_cnt = queue_ptr->used;
        sec_cnt = 0;
      }

      pointer *ptr = queue_ptr->data + queue_ptr->begin;
      pointer *ptr_end = ptr + fir_cnt;
      uintptr_t idx = 0;

      do
      {
        MonoObject *mono_item = create_mono_object(it,it.get_location_value(*ptr));

        // - ERROR -
        if (mono_item == NULL)
        {
          return NULL;
        }

        mono_array_set(mono_array,MonoObject *,idx++,mono_item);
      }
      while(++ptr < ptr_end);

      if (sec_cnt != 0)
      {
        ptr = queue_ptr->data;
        ptr_end = ptr + sec_cnt;

        do
        {
          MonoObject *mono_item = create_mono_object(it,it.get_location_value(*ptr));

          // - ERROR -
          if (mono_item == NULL)
          {
            return NULL;
          }

          mono_array_set(mono_array,MonoObject *,idx++,mono_item);
        }
        while(++ptr < ptr_end);
      }
    }

    mono_c::mono_exc = NULL;
    MonoObject *mono_queue = mono_runtime_invoke(queue_constr,NULL,(void **)&mono_array,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    return mono_queue;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_set)
  {/*{{{*/
    pointer_tree_s *tree_ptr = (pointer_tree_s *)location_ptr->v_data_ptr;
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),tree_ptr->count);

    if (tree_ptr->count != 0)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
      uintptr_t idx = 0;

      do
      {
        MonoObject *mono_item = create_mono_object(it,it.get_location_value(tree_ptr->data[t_idx].object));

        // - ERROR -
        if (mono_item == NULL)
        {
          return NULL;
        }

        mono_array_set(mono_array,MonoObject *,idx++,mono_item);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    mono_c::mono_exc = NULL;
    MonoObject *mono_hset = mono_runtime_invoke(hset_constr,NULL,(void **)&mono_array,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    return mono_hset;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_list)
  {/*{{{*/
    pointer_list_s *list_ptr = (pointer_list_s *)location_ptr->v_data_ptr;
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),list_ptr->count);

    if (list_ptr->count != 0)
    {
      unsigned l_idx = list_ptr->first_idx;
      uintptr_t idx = 0;

      do
      {
        MonoObject *mono_item = create_mono_object(it,it.get_location_value(list_ptr->data[l_idx].object));

        // - ERROR -
        if (mono_item == NULL)
        {
          return NULL;
        }

        mono_array_set(mono_array,MonoObject *,idx++,mono_item);

        l_idx = list_ptr->next_idx(l_idx);
      }
      while(l_idx != c_idx_not_exist);
    }

    mono_c::mono_exc = NULL;
    MonoObject *mono_list = mono_runtime_invoke(llist_constr,NULL,(void **)&mono_array,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    return mono_list;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;

    // - create new dictionary -
    mono_c::mono_exc = NULL;
    MonoObject *mono_dict = mono_runtime_invoke(dict_constr,NULL,NULL,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    if (tree_ptr->root_idx != c_idx_not_exist)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        pointer_map_tree_s_node &node = tree_ptr->data[t_idx];

        location_s *key_location = it.get_location_value(node.object.key);
        MonoObject *mono_key = create_mono_object(it,key_location);

        // - ERROR -
        if (mono_dict == NULL)
        {
          return NULL;
        }

        location_s *value_location = it.get_location_value(node.object.value);
        MonoObject *mono_value = create_mono_object(it,value_location);

        // - ERROR -
        if (mono_value == NULL)
        {
          return NULL;
        }

        void *mono_params[2] = {mono_key,mono_value};
        mono_runtime_invoke(dict_add,mono_dict,mono_params,&mono_exc);
        BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return mono_dict;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      {
        return NULL;
      }
    case c_bi_class_char:
      {
        return NULL;
      }
    case c_bi_class_integer:
      {
        long long int value = (long long int)location_ptr->v_data_ptr;
        return mono_value_box(domain,mono_get_int64_class(),&value);
      }
    case c_bi_class_float:
      {
        double value = (double)location_ptr->v_data_ptr;
        return mono_value_box(domain,mono_get_double_class(),&value);
      }
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        return (MonoObject *)mono_string_new_len(domain,string_ptr->data,string_ptr->size - 1);
      }
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
        MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),array_ptr->used);

        if (array_ptr->used > 0)
        {
          pointer *ptr = array_ptr->data;
          pointer *ptr_end = ptr + array_ptr->used;
          uintptr_t idx = 0;
          do {
            MonoObject *mono_item = create_mono_object(it,it.get_location_value(*ptr));

            // - ERROR -
            if (mono_item == NULL)
            {
              return NULL;
            }

            mono_array_set(mono_array,MonoObject *,idx++,mono_item);

          } while(++ptr < ptr_end);
        }

        mono_c::mono_exc = NULL;
        MonoObject *mono_list = mono_runtime_invoke(list_constr,NULL,(void **)&mono_array,&mono_exc);
        BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

        return mono_list;
      }/*}}}*/

    // - ERROR -
    default:
      return NULL;
    }
  }
}/*}}}*/

MonoObject *mono_c::create_mono_array(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_mono_object)
  {
    MonoObject *mono_obj = mono_gchandle_get_target((guint32)location_ptr->v_data_ptr);

    // - object is already mono array -
    if (mono_object_get_class(mono_obj) == mono_c::array_class)
    {
      return mono_obj;
    }
  }

  // - convert array to mono array -
  if (location_ptr->v_type == c_bi_class_array)
  {
    pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

    // - create new array -
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),array_ptr->used);

    if (array_ptr->used > 0)
    {
      pointer *ptr = array_ptr->data;
      pointer *ptr_end = ptr + array_ptr->used;
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = create_mono_object(it,it.get_location_value(*ptr));

        // - ERROR -
        if (mono_item == NULL)
        {
          return NULL;
        }

        mono_array_set(mono_array,MonoObject *,idx++,mono_item);

      } while(++ptr < ptr_end);
    }

    return (MonoObject *)mono_array;
  }

  // - convert single object to mono array -
  else
  {
    // - create new array -
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),1);
    MonoObject *mono_item = create_mono_object(it,location_ptr);

    // - ERROR -
    if (mono_item == NULL)
    {
      return NULL;
    }

    // - set mono array item -
    mono_array_set(mono_array,MonoObject *,0,mono_item);

    return (MonoObject *)mono_array;
  }
}/*}}}*/

location_s *mono_c::mono_object_value(interpreter_thread_s &it,MonoObject *mono_obj,uli source_pos)
{/*{{{*/
  MonoClass *mono_class = mono_object_get_class(mono_obj);

#define MONO_OBJECT_UNBOX_INTEGER(TYPE) \
{/*{{{*/\
  long long int value = *((TYPE *)mono_object_unbox(mono_obj));\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
  return new_location;\
}/*}}}*/

  if (mono_class == mono_get_int32_class())
  {
    MONO_OBJECT_UNBOX_INTEGER(int32_t)
  }
  if (mono_class == mono_get_int64_class())
  {
    MONO_OBJECT_UNBOX_INTEGER(int64_t)
  }

#define MONO_OBJECT_UNBOX_FLOAT(TYPE) \
{/*{{{*/\
  double value = *((TYPE *)mono_object_unbox(mono_obj));\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
  return new_location;\
}/*}}}*/

  if (mono_class == mono_get_single_class())
  {
    MONO_OBJECT_UNBOX_FLOAT(float);
  }
  if (mono_class == mono_get_double_class())
  {
    MONO_OBJECT_UNBOX_FLOAT(double);
  }
  if (mono_class == mono_get_string_class())
  {/*{{{*/
    MonoError error;
    char *utf8_str = mono_string_to_utf8_checked((MonoString *)mono_obj,&error);

    // - ERROR -
    if (!mono_error_ok(&error))
    {
      mono_error_cleanup(&error);
      return NULL;
    }

    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(utf8_str),utf8_str);
    mono_free(utf8_str);
    
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    return new_location;
  }/*}}}*/
  if (mono_class == array_class)
  {/*{{{*/
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

    MonoArray *mono_array = (MonoArray *)mono_obj;
    uintptr_t length = mono_array_length(mono_array);

    if (length > 0)
    {
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = mono_array_get(mono_array,MonoObject *,idx);
        location_s *item_location = mono_object_value(it,mono_item,source_pos);

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
  if (mono_class == list_class)
  {/*{{{*/
    mono_c::mono_exc = NULL;
    MonoArray *mono_array = (MonoArray *)mono_runtime_invoke(list_to_array,mono_obj,NULL,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    uintptr_t length = mono_array_length(mono_array);

    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

    if (length > 0)
    {
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = mono_array_get(mono_array,MonoObject *,idx);
        location_s *item_location = mono_object_value(it,mono_item,source_pos);

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
  if (mono_class == stack_class)
  {/*{{{*/
    mono_c::mono_exc = NULL;
    MonoArray *mono_array = (MonoArray *)mono_runtime_invoke(stack_to_array,mono_obj,NULL,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    uintptr_t length = mono_array_length(mono_array);

    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(stack_location,c_rm_class_stack,array_ptr);

    if (length > 0)
    {
      uintptr_t idx = length;
      do {
        MonoObject *mono_item = mono_array_get(mono_array,MonoObject *,--idx);
        location_s *item_location = mono_object_value(it,mono_item,source_pos);

        // - ERROR -
        if (item_location == NULL)
        {
          it.release_location_ptr(stack_location);
          return NULL;
        }

        // - insert item to stack -
        array_ptr->push(item_location);

      } while(idx > 0);
    }

    return stack_location;
  }/*}}}*/
  if (mono_class == queue_class)
  {/*{{{*/
    mono_c::mono_exc = NULL;

    MonoArray *mono_array = (MonoArray *)mono_runtime_invoke(queue_to_array,mono_obj,NULL,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    uintptr_t length = mono_array_length(mono_array);

    pointer_queue_s *queue_ptr = (pointer_queue_s *)cmalloc(sizeof(pointer_queue_s));
    queue_ptr->init();

    BIC_CREATE_NEW_LOCATION(queue_location,c_rm_class_queue,queue_ptr);

    if (length > 0)
    {
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = mono_array_get(mono_array,MonoObject *,idx);
        location_s *item_location = mono_object_value(it,mono_item,source_pos);

        // - ERROR -
        if (item_location == NULL)
        {
          it.release_location_ptr(queue_location);
          return NULL;
        }

        // - insert item to queue -
        queue_ptr->insert(item_location);

      } while(++idx < length);
    }

    return queue_location;
  }/*}}}*/
  if (mono_class == hset_class)
  {/*{{{*/
    mono_c::mono_exc = NULL;

    MonoArray *mono_array = (MonoArray *)mono_runtime_invoke(hset_arr,NULL,(void **)&mono_obj,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    uintptr_t length = mono_array_length(mono_array);

    pointer_tree_s *tree_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
    tree_ptr->init();
    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = source_pos;

    BIC_CREATE_NEW_LOCATION(set_location,c_rm_class_set,tree_ptr);

    if (length > 0)
    {
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = mono_array_get(mono_array,MonoObject *,idx);
        location_s *item_location = mono_object_value(it,mono_item,source_pos);

        // - ERROR -
        if (item_location == NULL)
        {
          it.release_location_ptr(set_location);
          return NULL;
        }

        // - insert item to set -
        if (!tree_ptr->set_unique_insert((pointer)item_location))
        {
          it.release_location_ptr(item_location);
          it.release_location_ptr(set_location);

          return NULL;
        }

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          it.release_location_ptr(item_location);
          it.release_location_ptr(set_location);

          return NULL;
        }

      } while(++idx < length);
    }

    return set_location;
  }/*}}}*/
  if (mono_class == llist_class)
  {/*{{{*/
    mono_c::mono_exc = NULL;

    MonoArray *mono_array = (MonoArray *)mono_runtime_invoke(llist_arr,NULL,(void **)&mono_obj,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    uintptr_t length = mono_array_length(mono_array);

    pointer_list_s *list_ptr = (pointer_list_s *)cmalloc(sizeof(pointer_list_s));
    list_ptr->init();

    BIC_CREATE_NEW_LOCATION(list_location,c_rm_class_list,list_ptr);

    if (length > 0)
    {
      uintptr_t idx = 0;
      do {
        MonoObject *mono_item = mono_array_get(mono_array,MonoObject *,idx);
        location_s *item_location = mono_object_value(it,mono_item,source_pos);

        // - ERROR -
        if (item_location == NULL)
        {
          it.release_location_ptr(list_location);
          return NULL;
        }

        // - insert item to list -
        list_ptr->append(item_location);

      } while(++idx < length);
    }

    return list_location;
  }/*}}}*/
  if (mono_class == dict_class)
  {/*{{{*/
    MonoObject *mono_keys = NULL;
    MonoObject *mono_values = NULL;

    void *mono_params[3] = {mono_obj,&mono_keys,&mono_values};

    MonoObject *mono_exc;
    mono_runtime_invoke(dict_arr,NULL,mono_params,&mono_exc);
    BIC_MONO_CHECK_EXCEPTION_RETURN_NULL();

    MonoArray *mono_array_keys = (MonoArray *)mono_keys;
    MonoArray *mono_array_values = (MonoArray *)mono_values;

    // - create new dictionary -
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();
    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = source_pos;

    BIC_CREATE_NEW_LOCATION(dict_location,c_rm_class_dict,tree_ptr);

    uintptr_t length = mono_array_length(mono_array_keys);

    if (length > 0)
    {
      uintptr_t idx = 0;
      do {
        MonoObject *mono_key = mono_array_get(mono_array_keys,MonoObject *,idx);
        location_s *key_location = mono_object_value(it,mono_key,source_pos);

        // - ERROR -
        if (key_location == NULL)
        {
          it.release_location_ptr(dict_location);
          return NULL;
        }

        MonoObject *mono_value = mono_array_get(mono_array_values,MonoObject *,idx);
        location_s *value_location = mono_object_value(it,mono_value,source_pos);

        // - ERROR -
        if (value_location == NULL)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(dict_location);

          return NULL;
        }

        pointer_map_s insert_map = {key_location,NULL};
        unsigned index = tree_ptr->unique_insert(insert_map);

        // - ERROR -
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(value_location);
          it.release_location_ptr(dict_location);

          return NULL;
        }

        pointer_map_s &map = tree_ptr->data[index].object;

        // - ERROR -
        if (map.value != NULL)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(value_location);
          it.release_location_ptr(dict_location);

          return NULL;
        }

        map.value = (pointer)value_location;

      } while(++idx < length);
    }

    return dict_location;
  }/*}}}*/

  return NULL;
}/*}}}*/

location_s *mono_c::get_exc_obj_location(interpreter_thread_s &it)
{/*{{{*/
  cassert(mono_exc != NULL);

  char *utf8_str = NULL;

  // - retrieve exception string -
  MonoObject *other_exc;
  MonoString *exc_str = mono_object_to_string(mono_exc,&other_exc);

  if (other_exc == NULL)
  {
    // - retrieve string as utf8 c string -
    MonoError error;
    utf8_str = mono_string_to_utf8_checked(exc_str,&error);

    if (!mono_error_ok(&error))
    {
      mono_error_cleanup(&error);
      utf8_str = NULL;
    }
  }

  // if exception string was retrieved
  if (utf8_str != NULL)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(utf8_str),utf8_str);
    mono_free(utf8_str);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);

    return new_location;
  }

  return (location_s *)it.blank_location;
}/*}}}*/

