
@begin
include "containers_list.h"
@end

// - class LIST -
built_in_class_s list_class =
{/*{{{*/
  "List",
  c_modifier_public | c_modifier_final,
  32, list_methods,
  0, list_variables,
  bic_list_consts,
  bic_list_init,
  bic_list_clear,
  NULL,
  bic_list_length,
  bic_list_item,
  bic_list_first_idx,
  bic_list_next_idx,
  NULL,
  bic_list_pack,
  bic_list_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s list_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_list_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_list_operator_binary_plus_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_list_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_list_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_list_operator_binary_plus
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_list_operator_binary_le_br_re_br
  },
  {
    "List#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_List_0
  },
  {
    "List#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_List_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_clear_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_items_0
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_append_1
  },
  {
    "append_ref#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_append_ref_1
  },
  {
    "prepend#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_prepend_1
  },
  {
    "prepend_ref#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_prepend_ref_1
  },
  {
    "insert_before#2",
    c_modifier_public | c_modifier_final,
    bic_list_method_insert_before_2
  },
  {
    "insert_before_ref#2",
    c_modifier_public | c_modifier_final,
    bic_list_method_insert_before_ref_2
  },
  {
    "insert_after#2",
    c_modifier_public | c_modifier_final,
    bic_list_method_insert_after_2
  },
  {
    "insert_after_ref#2",
    c_modifier_public | c_modifier_final,
    bic_list_method_insert_after_ref_2
  },
  {
    "remove#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_remove_1
  },
  {
    "has_idx#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_has_idx_1
  },
  {
    "get_idx#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_get_idx_1
  },
  {
    "get_idxs#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_get_idxs_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_list_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_list_method_print_0
  },
};/*}}}*/

built_in_variable_s list_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_LIST_COMPARE(SOURCE_POS) \
  {/*{{{*/\
    if (src_0_location->v_type == c_bi_class_list) {\
      pointer_list_s *f_list_ptr = (pointer_list_s *)dst_location->v_data_ptr;\
      pointer_list_s *s_list_ptr = (pointer_list_s *)src_0_location->v_data_ptr;\
      \
      if (f_list_ptr->count != s_list_ptr->count)\
      {\
        result = f_list_ptr->count < s_list_ptr->count ? -1 : 1;\
      }\
      else {\
        result = 0;\
        \
        if (f_list_ptr->count != 0)\
        {\
          unsigned fl_idx = f_list_ptr->first_idx;\
          unsigned sl_idx = s_list_ptr->first_idx;\
          \
          do {\
            BIC_CALL_COMPARE(it,f_list_ptr->data[fl_idx].object,s_list_ptr->data[sl_idx].object,SOURCE_POS,return false);\
            if (result != 0) {\
              break;\
            }\
            \
            fl_idx = f_list_ptr->next_idx(fl_idx);\
            sl_idx = s_list_ptr->next_idx(sl_idx);\
          } while(fl_idx != c_idx_not_exist);\
        }\
      }\
    }\
    else {\
      result = c_bi_class_list < src_0_location->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_LIST_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    pointer_array_s *source_ptr = (pointer_array_s *)SRC_LOCATION->v_data_ptr;\
    \
    if (source_ptr->used != 0)\
    {\
      pointer *ptr = source_ptr->data;\
      pointer *ptr_end = ptr + source_ptr->used;\
      \
      do\
      {\
        location_s *item_location = it.get_location_value(*ptr);\
        item_location->v_reference_cnt.atomic_inc();\
        \
        /* - append item location to list - */\
        TARGET_PTR->append(item_location);\
      }\
      while(++ptr < ptr_end);\
    }\
  }/*}}}*/

#define BIC_LIST_APPEND_LIST(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    pointer_list_s *source_ptr = (pointer_list_s *)SRC_LOCATION->v_data_ptr;\
    \
    if (source_ptr->count != 0)\
    {\
      unsigned l_idx = source_ptr->first_idx;\
      \
      do\
      {\
        location_s *item_location = it.get_location_value(source_ptr->data[l_idx].object);\
        item_location->v_reference_cnt.atomic_inc();\
        \
        /* - append item location to list - */\
        TARGET_PTR->append(item_location);\
        \
        l_idx = source_ptr->next_idx(l_idx);\
      }\
      while(l_idx != c_idx_not_exist);\
    }\
  }/*}}}*/

#define BIC_LIST_APPEND_ITERABLE_BODY(TARGET_PTR) \
  {/*{{{*/\
    item_location->v_reference_cnt.atomic_inc();\
    it.release_location_ptr(item_reference);\
    \
    /* - append item location to list - */\
    TARGET_PTR->append(item_location);\
  }/*}}}*/

#define BIC_LIST_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
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
      long long index;\
      location_s *item_reference;\
      location_s *item_location;\
      \
      /* - retrieve first index - */\
      BIC_CALL_FIRST_IDX(it,SRC_LOCATION,index,operands[c_source_pos_idx],return false;);\
      \
      while (index != c_idx_not_exist)\
      {\
        /* - retrieve item location - */\
        BIC_CALL_ITEM(it,SRC_LOCATION,index,item_reference,operands[c_source_pos_idx],return false;);\
        item_location = it.get_location_value(item_reference);\
        \
        BIC_LIST_APPEND_ITERABLE_BODY(TARGET_PTR);\
        \
        /* - retrieve next index - */\
        BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],return false;);\
      }\
    }\
    else if (iter_type == c_iter_next_item)\
    {\
      location_s *item_reference;\
      location_s *item_location;\
      \
      do\
      {\
        /* - retrieve next item location - */\
        BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,item_reference,operands[c_source_pos_idx],return false;);\
        item_location = it.get_location_value(item_reference);\
        \
        if (item_location->v_type == c_bi_class_blank)\
        {\
          it.release_location_ptr(item_reference);\
          break;\
        }\
        \
        BIC_LIST_APPEND_ITERABLE_BODY(TARGET_PTR);\
        \
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

#define BIC_LIST_CHECK_INDEX() \
  /*{{{*/\
  pointer_list_s *list_ptr = (pointer_list_s *)((location_s *)dst_location)->v_data_ptr;\
  \
  /* - ERROR - */\
  if (index < 0 || index >= list_ptr->used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LIST_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  \
  pointer_list_s_element &element = list_ptr->data[index];\
  \
  /* - ERROR - */\
  if (!element.valid)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LIST_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_LIST_ITEM(NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int index;\
    \
    /* - ERROR - */\
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
    \
    BIC_LIST_CHECK_INDEX();\
    \
    pointer *element_location = &list_ptr->data[index].object;\
    location_s *new_ref_location = it.get_new_reference((location_s **)element_location);\
    \
    BIC_SET_RESULT(new_ref_location);\
  }/*}}}*/

void bic_list_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_list_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)cmalloc(sizeof(pointer_list_s));
  list_ptr->init();

  location_ptr->v_data_ptr = (basic_64b)list_ptr;
}/*}}}*/

void bic_list_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)location_ptr->v_data_ptr;

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    do
    {
      it.release_location_ptr((location_s *)list_ptr->data[l_idx].object);
      l_idx = list_ptr->next_idx(l_idx);
    }
    while(l_idx != c_idx_not_exist);
  }

  list_ptr->clear();
  cfree(list_ptr);
}/*}}}*/

unsigned bic_list_length(location_s *location_ptr)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)location_ptr->v_data_ptr;
  return list_ptr->count;
}/*}}}*/

location_s *bic_list_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < list_ptr->used);

  pointer_list_s_element &element = list_ptr->data[index];

  // FIXME TODO check index ...
  cassert(element.valid);

  return it.get_new_reference((location_s **)&element.object);
}/*}}}*/

unsigned bic_list_first_idx(location_s *location_ptr)
{/*{{{*/
  return ((pointer_list_s *)location_ptr->v_data_ptr)->first_idx;
}/*}}}*/

unsigned bic_list_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < list_ptr->used);

  // FIXME TODO check index ...
  pointer_list_s_element &element = list_ptr->data[index];
  cassert(element.valid);

  return list_ptr->next_idx(index);
}/*}}}*/

bool bic_list_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&list_ptr->count);

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    do
    {
      loc_stack.push(list_ptr->data[l_idx].object);

      l_idx = list_ptr->next_idx(l_idx);
    }
    while(l_idx != c_idx_not_exist);
  }

  return true;
}/*}}}*/

bool bic_list_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_list_s *list_ptr = (pointer_list_s *)cmalloc(sizeof(pointer_list_s));
  list_ptr->init();

  location_ptr->v_data_ptr = (basic_64b)list_ptr;

  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned count;
  stream.from_end(sizeof(unsigned),(char *)&count,order_bytes);

  if (loc_stack.used < count)
  {
    return false;
  }

  if (count > 0)
  {
    pointer *l_ptr = loc_stack.data + (loc_stack.used - count);
    pointer *l_ptr_end = loc_stack.data + loc_stack.used;
    do
    {
      list_ptr->append(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);

    loc_stack.used -= count;
  }

  return true;
}/*}}}*/

bool bic_list_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

bool bic_list_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_LIST_APPEND_ARRAY(src_0_location,list_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_LIST_APPEND_ITERABLE(src_0_location,list_ptr);
  }

  dst_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_list_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_LIST_COMPARE(operands[c_source_pos_idx]);
  result = result == 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_LIST_COMPARE(operands[c_source_pos_idx]);
  result = result != 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)cmalloc(sizeof(pointer_list_s));
  list_ptr->init();

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_list,list_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  // - copy elements from list -
  BIC_LIST_APPEND_LIST(dst_location,list_ptr);

  // - append elements from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_LIST_APPEND_ARRAY(src_0_location,list_ptr);
  }

  // - append elements from iterable -
  else
  {
    BIC_LIST_APPEND_ITERABLE(src_0_location,list_ptr);
  }

  return true;
}/*}}}*/

bool bic_list_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_LIST_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_list_method_List_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_list_method_List_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_LIST_APPEND_ARRAY(src_0_location,list_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_LIST_APPEND_ITERABLE(src_0_location,list_ptr);
  }

  return true;
}/*}}}*/

bool bic_list_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)((location_s *)dst_location)->v_data_ptr;

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    do
    {
      it.release_location_ptr((location_s *)list_ptr->data[l_idx].object);
      l_idx = list_ptr->next_idx(l_idx);
    }
    while(l_idx != c_idx_not_exist);
  }

  list_ptr->clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_list_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;

    do
    {
      location_s *item_location = it.get_location_value(list_ptr->data[l_idx].object);
      item_location->v_reference_cnt.atomic_inc();
      array_ptr->push(item_location);

      l_idx = list_ptr->next_idx(l_idx);
    }
    while(l_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_list_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  src_0_location->v_reference_cnt.atomic_inc();

  long long int result = list_ptr->append((pointer)src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_append_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  pointer &src_0_location = it.data_stack[stack_base + operands[c_src_0_op_idx]];

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_0_location);

  long long int result = list_ptr->append((pointer)new_ref_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_prepend_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  src_0_location->v_reference_cnt.atomic_inc();

  long long int result = list_ptr->prepend((pointer)src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_prepend_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  pointer &src_0_location = it.data_stack[stack_base + operands[c_src_0_op_idx]];

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_0_location);

  long long int result = list_ptr->prepend((pointer)new_ref_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_insert_before_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("insert_before#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  BIC_LIST_CHECK_INDEX();

  src_1_location->v_reference_cnt.atomic_inc();

  long long int result = list_ptr->insert_before(index,(pointer)src_1_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_insert_before_ref_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  pointer &src_1_location = it.data_stack[stack_base + operands[c_src_1_op_idx]];

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("insert_before_ref#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(it.get_location_value(src_1_location)->v_type);

    return false;
  }

  BIC_LIST_CHECK_INDEX();

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_1_location);

  long long int result = list_ptr->insert_before(index,(pointer)new_ref_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_insert_after_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("insert_after#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  BIC_LIST_CHECK_INDEX();

  src_1_location->v_reference_cnt.atomic_inc();

  long long int result = list_ptr->insert_after(index,(pointer)src_1_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_insert_after_ref_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  pointer &src_1_location = it.data_stack[stack_base + operands[c_src_1_op_idx]];

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("insert_after_ref#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(it.get_location_value(src_1_location)->v_type);

    return false;
  }

  BIC_LIST_CHECK_INDEX();

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_1_location);

  long long int result = list_ptr->insert_after(index,(pointer)new_ref_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("remove#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_LIST_CHECK_INDEX();

  it.release_location_ptr((location_s *)element.object);
  list_ptr->remove(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_list_method_has_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("has_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_list_s *list_ptr = (pointer_list_s *)((location_s *)dst_location)->v_data_ptr;
  long long int result;

  if (index < 0 || index >= list_ptr->used)
  {
    result = 0;
  }
  else
  {
    result = list_ptr->data[index].valid;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  long long int index = c_idx_not_exist;
  long long int result;

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    do
    {
      BIC_CALL_COMPARE(it,list_ptr->data[l_idx].object,src_0_location,operands[c_source_pos_idx],return false);
      if (result == 0)
      {
        index = l_idx;
        break;
      }

      l_idx = list_ptr->next_idx(l_idx);
    }
    while(l_idx != c_idx_not_exist);
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(index);

  return true;
}/*}}}*/

bool bic_list_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  ui_array_s idxs_array;
  idxs_array.init();

  long long int result;

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    do
    {
      BIC_CALL_COMPARE(it,list_ptr->data[l_idx].object,src_0_location,operands[c_source_pos_idx],
                           idxs_array.clear();
                           return false;
                          );

      if (result == 0)
      {
        idxs_array.push(l_idx);
      }

      l_idx = list_ptr->next_idx(l_idx);
    }
    while(l_idx != c_idx_not_exist);
  }

  // - construct array from temporary array of indexes -
  pointer_array_s *res_array_ptr = it.get_new_array_ptr();

  BIC_CONT_CONSTRUCT_IDXS_ARRAY();

  idxs_array.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,res_array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_list_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_LIST_COMPARE(operands[c_source_pos_idx]);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_LIST_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_list_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int first_idx = ((pointer_list_s *)dst_location->v_data_ptr)->first_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(first_idx);

  return true;
}/*}}}*/

bool bic_list_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int last_idx = ((pointer_list_s *)dst_location->v_data_ptr)->last_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(last_idx);

  return true;
}/*}}}*/

bool bic_list_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_LIST_CHECK_INDEX();

  long long int next_idx = list_ptr->next_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(next_idx);

  return true;
}/*}}}*/

bool bic_list_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_LIST_CHECK_INDEX();

  long long int prev_idx = list_ptr->prev_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(prev_idx);

  return true;
}/*}}}*/

bool bic_list_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((pointer_list_s *)dst_location->v_data_ptr)->count;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_list_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(list_ptr->count);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,list_ptr->data[l_idx].object,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      l_idx = list_ptr->next_idx(l_idx);
    }
    while(++s_ptr,l_idx != c_idx_not_exist);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_list_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  pointer_list_s *list_ptr = (pointer_list_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(list_ptr->count);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,list_ptr->data[l_idx].object,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      l_idx = list_ptr->next_idx(l_idx);
    }
    while(++s_ptr,l_idx != c_idx_not_exist);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_list_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_list_s *list_ptr = ((pointer_list_s *)dst_location->v_data_ptr);

  putchar('[');

  if (list_ptr->count != 0)
  {
    unsigned l_idx = list_ptr->first_idx;

    BIC_CALL_PRINT(it,list_ptr->data[l_idx].object,operands[c_source_pos_idx],return false;);
    l_idx = list_ptr->next_idx(l_idx);

    if (l_idx != c_idx_not_exist)
    {
      do
      {
        putchar(',');
        BIC_CALL_PRINT(it,list_ptr->data[l_idx].object,operands[c_source_pos_idx],return false;);
        l_idx = list_ptr->next_idx(l_idx);
      }
      while(l_idx != c_idx_not_exist);
    }
  }

  putchar(']');

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

