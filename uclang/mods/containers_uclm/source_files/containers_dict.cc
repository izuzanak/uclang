
@begin
include "containers_dict.h"
@end

// - class DICT -
built_in_class_s dict_class =
{/*{{{*/
  "Dict",
  c_modifier_public | c_modifier_final,
  29, dict_methods,
  0, dict_variables,
  bic_dict_consts,
  bic_dict_init,
  bic_dict_clear,
  NULL,
  bic_dict_length,
  bic_dict_item,
  bic_dict_first_idx,
  bic_dict_next_idx,
  NULL,
  NULL,
  bic_dict_pack,
  bic_dict_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s dict_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_dict_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_dict_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_dict_operator_binary_exclamation_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_dict_operator_binary_le_br_re_br
  },
  {
    "Dict#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_Dict_0
  },
  {
    "Dict#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_Dict_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_clear_0
  },
  {
    "keys#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_keys_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_items_0
  },
  {
    "store_ref#2",
    c_modifier_public | c_modifier_final,
    bic_dict_method_store_ref_2
  },
  {
    "has_key#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_has_key_1
  },
  {
    "remove_key#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_remove_key_1
  },
  {
    "first_key#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_first_key_0
  },
  {
    "last_key#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_last_key_0
  },
  {
    "next_key#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_next_key_1
  },
  {
    "prev_key#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_prev_key_1
  },
  {
    "lee_key#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_lee_key_1
  },
  {
    "gre_key#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_gre_key_1
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_has_key_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_dict_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_dict_method_print_0
  },
};/*}}}*/

built_in_variable_s dict_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_DICT_COMPARE(SOURCE_POS) \
  {/*{{{*/\
    if (src_0_location->v_type == c_bi_class_dict) {\
      pointer_map_tree_s *f_tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;\
      pointer_map_tree_s *s_tree_ptr = (pointer_map_tree_s *)src_0_location->v_data_ptr;\
      \
      if (f_tree_ptr->count != s_tree_ptr->count)\
      {\
        result = f_tree_ptr->count < s_tree_ptr->count ? -1 : 1;\
      }\
      else {\
        result = 0;\
        \
        if (f_tree_ptr->count != 0)\
        {\
          unsigned f_stack[f_tree_ptr->get_descent_stack_size()];\
          unsigned s_stack[s_tree_ptr->get_descent_stack_size()];\
          \
          unsigned *f_stack_ptr = f_stack;\
          unsigned *s_stack_ptr = s_stack;\
          \
          unsigned ft_idx = f_tree_ptr->get_stack_min_value_idx(f_tree_ptr->root_idx,&f_stack_ptr);\
          unsigned st_idx = s_tree_ptr->get_stack_min_value_idx(s_tree_ptr->root_idx,&s_stack_ptr);\
          \
          do {\
            pointer_map_s &f_map = f_tree_ptr->data[ft_idx].object;\
            pointer_map_s &s_map = s_tree_ptr->data[st_idx].object;\
            \
            BIC_CALL_COMPARE(it,f_map.key,s_map.key,SOURCE_POS,return false);\
            if (result != 0) {\
              break;\
            }\
            \
            BIC_CALL_COMPARE(it,f_map.value,s_map.value,SOURCE_POS,return false);\
            if (result != 0) {\
              break;\
            }\
            \
            ft_idx = f_tree_ptr->get_stack_next_idx(ft_idx,&f_stack_ptr,f_stack);\
            st_idx = s_tree_ptr->get_stack_next_idx(st_idx,&s_stack_ptr,s_stack);\
          } while(ft_idx != c_idx_not_exist);\
        }\
      }\
    }\
    else {\
      result = c_bi_class_dict < src_0_location->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_DICT_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    pointer_array_s *source_ptr = (pointer_array_s *)SRC_LOCATION->v_data_ptr;\
    \
    /* - ERROR - */\
    if (source_ptr->used & 1)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_DICT_SOURCE_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    if (source_ptr->used != 0)\
    {\
      pointer *ptr = source_ptr->data;\
      pointer *ptr_end = ptr + source_ptr->used;\
      \
      do\
      {\
        location_s *key_location = it.get_location_value(ptr[0]);\
        location_s *val_location = it.get_location_value(ptr[1]);\
        \
        /* - push key and value locations to dictionary - */\
        pointer_map_s insert_map = {key_location,NULL};\
        unsigned index = TARGET_PTR->unique_insert(insert_map);\
        \
        /* - ERROR - */\
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
        {\
          return false;\
        }\
        \
        pointer_map_s &map = TARGET_PTR->data[index].object;\
        \
        if (map.value)\
        {\
          it.release_location_ptr((location_s *)map.value);\
        }\
        else\
        {\
          key_location->v_reference_cnt.atomic_inc();\
        }\
        \
        val_location->v_reference_cnt.atomic_inc();\
        map.value = (pointer)val_location;\
      }\
      while((ptr += 2) < ptr_end);\
    }\
  }/*}}}*/

#define BIC_DICT_APPEND_ITERABLE_BODY(TARGET_PTR) \
  {/*{{{*/\
    key_location->v_reference_cnt.atomic_inc();\
    val_location->v_reference_cnt.atomic_inc();\
    \
    it.release_location_ptr(key_reference);\
    it.release_location_ptr(val_reference);\
    \
    /* - push key and value locations to dictionary - */\
    pointer_map_s insert_map = {key_location,NULL};\
    unsigned map_idx = TARGET_PTR->unique_insert(insert_map);\
    \
    /* - ERROR - */\
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
      it.release_location_ptr(key_location);\
      it.release_location_ptr(val_location);\
      \
      return false;\
    }\
    \
    pointer_map_s &map = TARGET_PTR->data[map_idx].object;\
    \
    if (map.value)\
    {\
      it.release_location_ptr(key_location);\
      it.release_location_ptr((location_s *)map.value);\
    }\
    \
    map.value = (pointer)val_location;\
  }/*}}}*/

#define BIC_DICT_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    \
    /* - retrieve iterable type - */\
    unsigned iter_type = it.get_iterable_type(SRC_LOCATION);\
    \
    /* - ERROR - */\
    if (iter_type == c_idx_not_exist)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(SRC_LOCATION->v_type);\
      \
      return false;\
    }\
    \
    if (iter_type == c_iter_first_idx_next_idx_item)\
    {\
      long long int index;\
      location_s *key_reference;\
      location_s *key_location;\
      location_s *val_reference;\
      location_s *val_location;\
      \
      BIC_CALL_FIRST_IDX(it,SRC_LOCATION,index,operands[c_source_pos_idx],return false;);\
      \
      while (index != c_idx_not_exist)\
      {\
        BIC_CALL_ITEM(it,SRC_LOCATION,index,key_reference,operands[c_source_pos_idx],return false;);\
        key_location = it.get_location_value(key_reference);\
        \
        BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],\
                          it.release_location_ptr(key_reference);\
                          return false;\
                         );\
        \
        /* - ERROR - */\
        if (index == c_idx_not_exist)\
        {\
          it.release_location_ptr(key_reference);\
          \
          exception_s::throw_exception(it,module.error_base + c_error_DICT_SOURCE_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          return false;\
        }\
        \
        BIC_CALL_ITEM(it,SRC_LOCATION,index,val_reference,operands[c_source_pos_idx],\
                      it.release_location_ptr(key_reference);\
                      return false;\
                     );\
        val_location = it.get_location_value(val_reference);\
        \
        BIC_DICT_APPEND_ITERABLE_BODY(TARGET_PTR);\
        \
        BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],return false;);\
      }\
    }\
    else if (iter_type == c_iter_next_item)\
    {\
      location_s *key_reference;\
      location_s *key_location;\
      location_s *val_reference;\
      location_s *val_location;\
      \
      do\
      {\
        BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,key_reference,operands[c_source_pos_idx],return false;);\
        key_location = it.get_location_value(key_reference);\
        \
        if (key_location->v_type == c_bi_class_blank)\
        {\
          it.release_location_ptr(key_reference);\
          break;\
        }\
        \
        BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,val_reference,operands[c_source_pos_idx],\
                           it.release_location_ptr(key_reference);\
                           \
                           exception_s::throw_exception(it,module.error_base + c_error_DICT_SOURCE_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
                           return false;\
                          );\
        val_location = it.get_location_value(val_reference);\
        \
        BIC_DICT_APPEND_ITERABLE_BODY(TARGET_PTR);\
        \
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

#define BIC_DICT_CHECK_INDEX() \
  /*{{{*/\
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)dst_location)->v_data_ptr;\
  \
  /* - ERROR - */\
  if (index < 0 || index >= tree_ptr->used || !tree_ptr->data[index].valid)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

void bic_dict_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_dict_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
  tree_ptr->init();

  location_ptr->v_data_ptr = (pointer_map_tree_s *)tree_ptr;
}/*}}}*/

void bic_dict_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    do
    {
      pointer_map_s &map = tree_ptr->data[t_idx].object;

      it.release_location_ptr((location_s *)map.key);
      it.release_location_ptr((location_s *)map.value);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  tree_ptr->clear();
  cfree(tree_ptr);
}/*}}}*/

unsigned bic_dict_length(location_s *location_ptr)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)location_ptr)->v_data_ptr;
  return tree_ptr->count;
}/*}}}*/

location_s *bic_dict_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)location_ptr)->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < tree_ptr->used);

  pointer_map_tree_s_node &node = tree_ptr->data[index];

  // FIXME TODO check index ...
  cassert(node.valid);

  location_s *element_location = (location_s *)node.object.key;
  element_location->v_reference_cnt.atomic_inc();

  return element_location;
}/*}}}*/

unsigned bic_dict_first_idx(location_s *location_ptr)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)location_ptr)->v_data_ptr;

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    return tree_ptr->get_min_value_idx(tree_ptr->root_idx);
  }
  else
  {
    return c_idx_not_exist;
  }
}/*}}}*/

unsigned bic_dict_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)location_ptr)->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < tree_ptr->used && tree_ptr->data[index].valid);

  return tree_ptr->get_next_idx(index);
}/*}}}*/

bool bic_dict_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&tree_ptr->count);

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    do
    {
      pointer_map_s &map = tree_ptr->data[t_idx].object;

      loc_stack.push(map.key);
      loc_stack.push(map.value);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  return true;
}/*}}}*/

bool bic_dict_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
  tree_ptr->init();

  location_ptr->v_data_ptr = (pointer_map_tree_s *)tree_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = source_pos;

  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned count;
  stream.from_end(sizeof(unsigned),(char *)&count,order_bytes);

  if (loc_stack.used < (count << 1))
  {
    return false;
  }

  if (count > 0)
  {
    pointer *l_ptr = loc_stack.data + (loc_stack.used - (count << 1));
    pointer *l_ptr_end = loc_stack.data + loc_stack.used;
    do
    {
      pointer_map_s insert_map = {l_ptr[0],NULL};

      unsigned index = tree_ptr->unique_insert(insert_map);

      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        return false;
      }

      pointer_map_s &map = tree_ptr->data[index].object;

      if (map.value != NULL)
      {
        return false;
      }

      map.value = l_ptr[1];
    }
    while((l_ptr += 2) < l_ptr_end);

    loc_stack.used -= (count << 1);
  }

  return true;
}/*}}}*/

bool bic_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_dict_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_DICT_COMPARE(operands[c_source_pos_idx]);
  result = result == 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_dict_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_DICT_COMPARE(operands[c_source_pos_idx]);
  result = result != 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_dict_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s insert_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->unique_insert(insert_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer_map_s &map = tree_ptr->data[index].object;

  if (map.value == NULL)
  {
    src_0_location->v_reference_cnt.atomic_inc();

    location_s *value_location = it.get_new_location_ptr();
    value_location->v_type = c_bi_class_blank;
    value_location->v_reference_cnt.atomic_set(1);

    map.value = value_location;
  }

  pointer *value_location = &tree_ptr->data[index].object.value;
  location_s *new_ref_location = it.get_new_reference((location_s **)value_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_dict_method_Dict_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_dict_method_Dict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_DICT_APPEND_ARRAY(src_0_location,tree_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_DICT_APPEND_ITERABLE(src_0_location,tree_ptr);
  }

  return true;
}/*}}}*/

bool bic_dict_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    do
    {
      pointer_map_s &map = tree_ptr->data[t_idx].object;

      it.release_location_ptr((location_s *)map.key);
      it.release_location_ptr((location_s *)map.value);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  tree_ptr->clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_dict_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    array_ptr->init_size(tree_ptr->count);

    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

    do
    {
      location_s *key_location = it.get_location_value(tree_ptr->data[t_idx].object.key);
      key_location->v_reference_cnt.atomic_inc();

      array_ptr->push(key_location);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_dict_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

    do
    {
      location_s *item_location = it.get_location_value(tree_ptr->data[t_idx].object.value);
      item_location->v_reference_cnt.atomic_inc();
      array_ptr->push(item_location);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_dict_method_store_ref_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  pointer &src_1_location = it.data_stack[stack_base + operands[c_src_1_op_idx]];

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s insert_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->unique_insert(insert_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer_map_s &map = tree_ptr->data[index].object;
  location_s *new_ref_location = it.get_new_reference((location_s **)&src_1_location);

  if (map.value)
  {
    it.release_location_ptr((location_s *)map.value);
  }
  else
  {
    src_0_location->v_reference_cnt.atomic_inc();
  }

  map.value = (pointer)new_ref_location;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_dict_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  long long int result = index != c_idx_not_exist;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_dict_method_remove_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  // - ERROR -
  if (index == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DICT_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve tree node -
  pointer_map_tree_s_node &node = tree_ptr->data[index];

  it.release_location_ptr((location_s *)node.object.key);
  it.release_location_ptr((location_s *)node.object.value);
  tree_ptr->remove(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_dict_method_first_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    unsigned min_value_idx = tree_ptr->get_min_value_idx(tree_ptr->root_idx);

    location_s *location_ptr = (location_s *)tree_ptr->data[min_value_idx].object.key;
    location_ptr->v_reference_cnt.atomic_inc();

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(location_ptr)
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dict_method_last_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    unsigned max_value_idx = tree_ptr->get_max_value_idx(tree_ptr->root_idx);

    location_s *location_ptr = (location_s *)tree_ptr->data[max_value_idx].object.key;
    location_ptr->v_reference_cnt.atomic_inc();

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(location_ptr)
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dict_method_next_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  if (index != c_idx_not_exist)
  {
    unsigned next_value_idx = tree_ptr->get_next_idx(index);

    if (next_value_idx != c_idx_not_exist)
    {
      location_s *location_ptr = (location_s *)tree_ptr->data[next_value_idx].object.key;
      location_ptr->v_reference_cnt.atomic_inc();

      pointer &res_location = it.data_stack[res_loc_idx];
      BIC_SET_RESULT(location_ptr)
    }
    else
    {
      pointer &res_location = it.data_stack[res_loc_idx];
      BIC_SET_RESULT_BLANK();
    }
  }
  else
  {
    exception_s::throw_exception(it,module.error_base + c_error_DICT_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_dict_method_prev_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  if (index != c_idx_not_exist)
  {
    unsigned prev_value_idx = tree_ptr->get_prev_idx(index);

    if (prev_value_idx != c_idx_not_exist)
    {
      location_s *location_ptr = (location_s *)tree_ptr->data[prev_value_idx].object.key;
      location_ptr->v_reference_cnt.atomic_inc();

      pointer &res_location = it.data_stack[res_loc_idx];
      BIC_SET_RESULT(location_ptr)
    }
    else
    {
      pointer &res_location = it.data_stack[res_loc_idx];
      BIC_SET_RESULT_BLANK();
    }
  }
  else
  {
    exception_s::throw_exception(it,module.error_base + c_error_DICT_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_dict_method_lee_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->get_lee_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  if (index != c_idx_not_exist)
  {
    location_s *location_ptr = (location_s *)tree_ptr->data[index].object.key;
    location_ptr->v_reference_cnt.atomic_inc();

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(location_ptr)
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dict_method_gre_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,NULL};
  unsigned index = tree_ptr->get_gre_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  if (index != c_idx_not_exist)
  {
    location_s *location_ptr = (location_s *)tree_ptr->data[index].object.key;
    location_ptr->v_reference_cnt.atomic_inc();

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(location_ptr)
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dict_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_DICT_COMPARE(operands[c_source_pos_idx]);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_dict_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("item#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_DICT_CHECK_INDEX();

  location_s *element_location = (location_s *)tree_ptr->data[index].object.key;
  element_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(element_location);

  return true;
}/*}}}*/

bool bic_dict_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)dst_location)->v_data_ptr;

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    long long int result = tree_ptr->get_min_value_idx(tree_ptr->root_idx);

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dict_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)((location_s *)dst_location)->v_data_ptr;

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    long long int result = tree_ptr->get_max_value_idx(tree_ptr->root_idx);

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dict_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_DICT_CHECK_INDEX();

  long long int next_idx = tree_ptr->get_next_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(next_idx);

  return true;
}/*}}}*/

bool bic_dict_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("prev_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_DICT_CHECK_INDEX();

  long long int prev_idx = tree_ptr->get_prev_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(prev_idx);

  return true;
}/*}}}*/

bool bic_dict_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((pointer_map_tree_s *)dst_location->v_data_ptr)->count;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(tree_ptr->count << 1);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    string_s *s_ptr = strings.data;

    do
    {
      pointer_map_s &map = tree_ptr->data[t_idx].object;

      BIC_CALL_TO_STRING(it,map.key,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      ++s_ptr;

      BIC_CALL_TO_STRING(it,map.value,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      ++s_ptr;

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  // - construct result string -
  {
    // - adjust result string size -
    strings_size += 1 + (strings.used != 0 ? strings.used - 1 : 0) + 2;

    // - create result string data -
    string_ptr->size = strings_size;
    string_ptr->data = (char *)cmalloc(strings_size*sizeof(char));

    char *rs_ptr = string_ptr->data;
    *rs_ptr++ = '[';

    if (strings.used != 0)
    {
      // - strings cocatenation -
      string_s *s_ptr = strings.data;
      string_s *s_ptr_end = s_ptr + strings.used;

      // - copy first string -
      memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
      rs_ptr += (s_ptr++)->size - 1;
      *rs_ptr++ = ':';
      memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
      rs_ptr += (s_ptr++)->size - 1;

      if (s_ptr < s_ptr_end)
      {
        do
        {
          *rs_ptr++ = ',';
          memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
          rs_ptr += (s_ptr++)->size - 1;
          *rs_ptr++ = ':';
          memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
          rs_ptr += (s_ptr++)->size - 1;

        }
        while(s_ptr < s_ptr_end);
      }
    }

    *rs_ptr++ = ']';
    *rs_ptr = '\0';
  }

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_dict_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("to_string#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(tree_ptr->count << 1);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    string_s *s_ptr = strings.data;

    do
    {
      pointer_map_s &map = tree_ptr->data[t_idx].object;

      BIC_CALL_TO_STRING(it,map.key,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      ++s_ptr;

      BIC_CALL_TO_STRING(it,map.value,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      ++s_ptr;

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  {
    if (strings.used != 0)
    {
      // - adjust result string size -
      strings_size += (del_string_ptr->size - 1)*((strings.used >> 1) - 1) + (strings.used >> 1) + 1;

      // - create result string data -
      string_ptr->size = strings_size;
      string_ptr->data = (char *)cmalloc(strings_size*sizeof(char));

      // - strings cocatenation -
      char *rs_ptr = string_ptr->data;
      string_s *s_ptr = strings.data;
      string_s *s_ptr_end = s_ptr + strings.used;

      // - copy first string -
      memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
      rs_ptr += (s_ptr++)->size - 1;
      *rs_ptr++ = ':';
      memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
      rs_ptr += (s_ptr++)->size - 1;

      if (s_ptr < s_ptr_end)
      {
        do
        {
          memcpy(rs_ptr,del_string_ptr->data,(del_string_ptr->size - 1)*sizeof(char));
          rs_ptr += del_string_ptr->size - 1;
          memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
          rs_ptr += (s_ptr++)->size - 1;
          *rs_ptr++ = ':';
          memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));
          rs_ptr += (s_ptr++)->size - 1;
        }
        while(s_ptr < s_ptr_end);
      }

      *rs_ptr = '\0';
    }
  }

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_map_tree_s *tree_ptr = ((pointer_map_tree_s *)dst_location->v_data_ptr);

  putchar('[');

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

    {
      pointer_map_s &map = tree_ptr->data[t_idx].object;

      BIC_CALL_PRINT(it,map.key,operands[c_source_pos_idx],return false;);
      putchar(':');
      BIC_CALL_PRINT(it,map.value,operands[c_source_pos_idx],return false;);
    }

    t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);

    if (t_idx != c_idx_not_exist)
    {
      do
      {
        pointer_map_s &map = tree_ptr->data[t_idx].object;

        putchar(',');
        BIC_CALL_PRINT(it,map.key,operands[c_source_pos_idx],return false;);
        putchar(':');
        BIC_CALL_PRINT(it,map.value,operands[c_source_pos_idx],return false;);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }
  }

  putchar(']');

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

