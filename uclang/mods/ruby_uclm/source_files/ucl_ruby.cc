
@begin
include "ucl_ruby.h"
@end

// - static members of class ruby_c -
VALUE ruby_c::values;
ui_array_s ruby_c::free_idxs;

// - ruby global init object -
ruby_c g_ruby;

/*
 * methods of class ruby_c
 */

VALUE ruby_c::rb_load_protect(VALUE a_file_name)
{/*{{{*/
  rb_load(a_file_name,0);

  return Qnil;
}/*}}}*/

VALUE ruby_c::rb_require_protect(VALUE a_file_name)
{/*{{{*/
  return rb_f_require(Qnil,a_file_name);
}/*}}}*/

VALUE ruby_c::rb_big2ll_protect(VALUE a_big_num)
{/*{{{*/
  rb_big2ll(a_big_num);

  return Qnil;
}/*}}}*/

VALUE ruby_c::rb_funcallv_protect(VALUE a_args)
{/*{{{*/
  call_args_s *args = (call_args_s *)a_args;

  return rb_funcallv(args->recv,args->mid,args->argc,args->argv);
}/*}}}*/

int ruby_c::hash_kv_pair(VALUE key,VALUE value,VALUE array)
{/*{{{*/
  rb_ary_push(array,key);
  rb_ary_push(array,value);

  return ST_CONTINUE;
}/*}}}*/

VALUE ruby_c::create_ruby_value(interpreter_thread_s &it,location_s *location_ptr,int &status)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_ruby_value)
  {
    return ruby_c::get_value((unsigned)location_ptr->v_data_ptr);
  }
  if (location_ptr->v_type == c_bi_class_ruby_iv_ref)
  {
    return ((ruby_reference_s *)location_ptr->v_data_ptr)->get_iv(status);
  }
  if (location_ptr->v_type == c_bi_class_ruby_item_ref)
  {
    return ((ruby_reference_s *)location_ptr->v_data_ptr)->get_item(status);
  }
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;
    VALUE rv_hash = rb_hash_new();

    if (tree_ptr->root_idx != c_idx_not_exist)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        pointer_map_tree_s_node &node = tree_ptr->data[t_idx];

        location_s *key_location = it.get_location_value(node.object.key);
        VALUE rv_key = create_ruby_value(it,key_location,status);

        // - ERROR -
        if (status)
        {
          return Qnil;
        }

        location_s *value_location = it.get_location_value(node.object.value);
        VALUE rv_value = create_ruby_value(it,value_location,status);

        // - ERROR -
        if (status)
        {
          return Qnil;
        }

        rb_hash_aset(rv_hash,rv_key,rv_value);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return rv_hash;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      return Qnil;
    case c_bi_class_char:
      return LONG2FIX((char)location_ptr->v_data_ptr);
    case c_bi_class_integer:
      return LL2NUM((long long int)location_ptr->v_data_ptr);
    case c_bi_class_float:
      return DBL2NUM((double)location_ptr->v_data_ptr);
    case c_bi_class_string:
      {/*{{{*/
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        return rb_str_new(string_ptr->data,string_ptr->size - 1);
      }/*}}}*/
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
        VALUE rv_array = rb_ary_new_capa(array_ptr->used);

        if (array_ptr->used != 0)
        {
          pointer *i_ptr = array_ptr->data;
          pointer *i_ptr_end = i_ptr + array_ptr->used;
          do {
            VALUE rv_item = create_ruby_value(it,it.get_location_value(*i_ptr),status);

            // - ERROR -
            if (status)
            {
              return Qnil;
            }

            // - push value to ruby array -
            rb_ary_push(rv_array,rv_item);

          } while(++i_ptr < i_ptr_end);
        }

        return rv_array;
      }/*}}}*/

    // - ERROR -
    default:
      status = STATUS_ERROR;
      return Qnil;
    }
  }
}/*}}}*/

location_s *ruby_c::ruby_value_value(interpreter_thread_s &it,VALUE rv_value,uli source_pos)
{/*{{{*/
  switch (TYPE(rv_value))
  {
  case T_NIL:
    {/*{{{*/
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
      return (location_s *)it.blank_location;
    }/*}}}*/
  case T_FIXNUM:
    {/*{{{*/
      long long int value = FIX2LONG(rv_value);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
      return new_location;
    }/*}}}*/
  case T_BIGNUM:
    {/*{{{*/
      int status;
      rb_protect(ruby_c::rb_big2ll_protect,rv_value,&status);

      // - ERROR -
      if (status)
      {
        return NULL;
      }

      long long int value = rb_big2ll(rv_value);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
      return new_location;
    }/*}}}*/
  case T_FLOAT:
    {/*{{{*/
      double value = RFLOAT_VALUE(rv_value);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
      return new_location;
    }/*}}}*/
  case T_STRING:
    {/*{{{*/
      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(RSTRING_LEN(rv_value),RSTRING_PTR(rv_value));

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
      return new_location;
    }/*}}}*/
  case T_TRUE:
    {/*{{{*/
      long long int value = 1;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
      return new_location;
    }/*}}}*/
  case T_FALSE:
    {/*{{{*/
      long long int value = 0;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
      return new_location;
    }/*}}}*/
  case T_ARRAY:
    {/*{{{*/
      pointer_array_s *array_ptr = it.get_new_array_ptr();
      BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

      long size = RARRAY_LEN(rv_value);
      if (size > 0)
      {
        long idx = 0;
        do {
          VALUE rv_item = RARRAY_AREF(rv_value,idx);

          location_s *item_location = ruby_value_value(it,rv_item,source_pos);

          // - ERROR -
          if (item_location == NULL)
          {
            it.release_location_ptr(arr_location);
            return NULL;
          }

          // - insert item to array -
          array_ptr->push(item_location);

        } while(++idx < size);
      }

      return arr_location;
    }/*}}}*/
  case T_HASH:
    {/*{{{*/
      pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
      tree_ptr->init();
      tree_ptr->it_ptr = &it;
      tree_ptr->source_pos = source_pos;

      BIC_CREATE_NEW_LOCATION(dict_location,c_rm_class_dict,tree_ptr);

      size_t size = RHASH_SIZE(rv_value);
      if (size > 0)
      {
        size_t kv_size = size << 1;

        VALUE kv_pairs = rb_ary_new_capa(kv_size);
        rb_hash_foreach(rv_value,(int (*)(ANYARGS))&hash_kv_pair,kv_pairs);

        size_t idx = 0;
        do {
          VALUE rv_key = RARRAY_AREF(kv_pairs,idx);
          VALUE rv_value = RARRAY_AREF(kv_pairs,idx + 1);

          location_s *key_location = ruby_value_value(it,rv_key,source_pos);

          // - ERROR -
          if (key_location == NULL)
          {
            it.release_location_ptr(dict_location);
            return NULL;
          }

          location_s *value_location = ruby_value_value(it,rv_value,source_pos);

          // - ERROR -
          if (value_location == NULL)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(dict_location);

            return NULL;
          }

          pointer_map_s insert_map = {key_location,NULL};
          unsigned index = tree_ptr->unique_insert(insert_map);

          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(value_location);
            it.release_location_ptr(dict_location);

            return NULL;
          }

          pointer_map_s &map = tree_ptr->data[index].object;

          if (map.value != NULL)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(value_location);
            it.release_location_ptr(dict_location);

            return NULL;
          }

          map.value = (pointer)value_location;

        } while((idx += 2) < kv_size);
      }

      return dict_location;
    }/*}}}*/

  case T_SYMBOL:
  case T_DATA:
  default:
    return NULL;
  }
}/*}}}*/

