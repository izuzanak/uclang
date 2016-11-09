
@begin
include "containers_stack.h"
@end

// - class STACK -
built_in_class_s stack_class =
{/*{{{*/
  "Stack",
  c_modifier_public | c_modifier_final,
  23, stack_methods,
  0, stack_variables,
  bic_stack_consts,
  bic_stack_init,
  bic_stack_clear,
  NULL,
  bic_stack_length,
  bic_stack_item,
  bic_stack_first_idx,
  bic_stack_next_idx,
  NULL,
  NULL,
  bic_stack_pack,
  bic_stack_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s stack_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_stack_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_stack_operator_binary_plus_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_stack_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_stack_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_stack_operator_binary_plus
  },
  {
    "Stack#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_Stack_0
  },
  {
    "Stack#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_Stack_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_clear_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_items_0
  },
  {
    "push#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_push_1
  },
  {
    "push_ref#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_push_ref_1
  },
  {
    "pop#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_pop_0
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_stack_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_stack_method_print_0
  },
};/*}}}*/

built_in_variable_s stack_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_STACK_COMPARE(SOURCE_POS) \
  {/*{{{*/\
    if (src_0_location->v_type == c_bi_class_stack) {\
      pointer_array_s *f_array_ptr = (pointer_array_s *)dst_location->v_data_ptr;\
      pointer_array_s *s_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;\
      \
      if (f_array_ptr->used != s_array_ptr->used)\
      {\
        result = f_array_ptr->used < s_array_ptr->used ? -1 : 1;\
      }\
      else {\
        result = 0;\
        \
        if (f_array_ptr->used != 0)\
        {\
          pointer *f_ptr = f_array_ptr->data;\
          pointer *f_ptr_end = f_ptr + f_array_ptr->used;\
          pointer *s_ptr = s_array_ptr->data;\
          \
          do {\
            BIC_CALL_COMPARE(it,*f_ptr,*s_ptr,SOURCE_POS,return false);\
            if (result != 0) {\
              break;\
            }\
          } while(++s_ptr,++f_ptr < f_ptr_end);\
        }\
      }\
    }\
    else {\
      result = c_bi_class_stack < src_0_location->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_STACK_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
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
        /* - push item location to stack - */\
        TARGET_PTR->push(item_location);\
      }\
      while(++ptr < ptr_end);\
    }\
  }/*}}}*/

#define BIC_STACK_APPEND_STACK(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    BIC_STACK_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR);\
  }/*}}}*/

#define BIC_STACK_APPEND_ITERABLE_BODY_BODY(TARGET_PTR) \
  {/*{{{*/\
    item_location->v_reference_cnt.atomic_inc();\
    it.release_location_ptr(item_reference);\
    \
    /* - push item location to stack - */\
    TARGET_PTR->push(item_location);\
  }/*}}}*/

#define BIC_STACK_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
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
        BIC_STACK_APPEND_ITERABLE_BODY_BODY(TARGET_PTR);\
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
        \
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
        BIC_STACK_APPEND_ITERABLE_BODY_BODY(TARGET_PTR);\
        \
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

#define BIC_STACK_CHECK_INDEX() \
  /*{{{*/\
  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;\
  \
  /* - ERROR - */\
  if (index < 0 || index >= array_ptr->used) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_STACK_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

void bic_stack_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_stack_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pointer_array_s *)it.get_new_array_ptr();
}/*}}}*/

void bic_stack_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      it.release_location_ptr((location_s *)*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  array_ptr->clear();
  cfree(array_ptr);
}/*}}}*/

unsigned bic_stack_length(location_s *location_ptr)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
  return array_ptr->used;
}/*}}}*/

location_s *bic_stack_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < array_ptr->used);

  pointer *element_location = &array_ptr->data[index];
  return it.get_new_reference((location_s **)element_location);
}/*}}}*/

unsigned bic_stack_first_idx(location_s *location_ptr)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
  return array_ptr->used != 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_stack_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < array_ptr->used);

  return (index + 1 < array_ptr->used) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_stack_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&array_ptr->used);

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      loc_stack.push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  return true;
}/*}}}*/

bool bic_stack_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  location_ptr->v_data_ptr = (pointer_array_s *)array_ptr;

  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned length;
  stream.from_end(sizeof(unsigned),(char *)&length,order_bytes);

  if (loc_stack.used < length)
  {
    return false;
  }

  if (length > 0)
  {
    array_ptr->copy_resize(length);

    pointer *l_ptr = loc_stack.data + (loc_stack.used - length);
    pointer *l_ptr_end = loc_stack.data + loc_stack.used;
    do
    {
      array_ptr->push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);

    loc_stack.used -= length;
  }

  return true;
}/*}}}*/

bool bic_stack_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

bool bic_stack_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_STACK_APPEND_ARRAY(src_0_location,array_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_STACK_APPEND_ITERABLE(src_0_location,array_ptr);
  }

  dst_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_stack_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_STACK_COMPARE(operands[c_source_pos_idx]);
  result = result == 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_stack_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_STACK_COMPARE(operands[c_source_pos_idx]);
  result = result != 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_stack_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)cmalloc(sizeof(pointer_array_s));
  array_ptr->init();

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_stack,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  // - copy elements from stack -
  BIC_STACK_APPEND_STACK(dst_location,array_ptr);

  // - append elements from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_STACK_APPEND_ARRAY(src_0_location,array_ptr);
  }

  // - append elements from iterable -
  else
  {
    BIC_STACK_APPEND_ITERABLE(src_0_location,array_ptr);
  }

  return true;
}/*}}}*/

bool bic_stack_method_Stack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_stack_method_Stack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_STACK_APPEND_ARRAY(src_0_location,array_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_STACK_APPEND_ITERABLE(src_0_location,array_ptr);
  }

  return true;
}/*}}}*/

bool bic_stack_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      it.release_location_ptr((location_s *)*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  array_ptr->clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_stack_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;
  pointer_array_s *new_array_ptr = it.get_new_array_ptr();

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *ptr_end = e_ptr + array_ptr->used;

    do
    {
      location_s *item_location = it.get_location_value(*e_ptr);
      item_location->v_reference_cnt.atomic_inc();
      new_array_ptr->push(item_location);
    }
    while(++e_ptr < ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,new_array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_stack_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;

  src_0_location->v_reference_cnt.atomic_inc();
  array_ptr->push((pointer)src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_stack_method_push_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  pointer &src_0_location = it.data_stack[stack_base + operands[c_src_0_op_idx]];

  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_0_location);
  array_ptr->push((pointer)new_ref_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_stack_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STACK_NO_OTHER_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // pop next value from array -
  location_s *location_ptr = (location_s *)array_ptr->pop();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_stack_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  long long int found = 0;
  long long int result;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      BIC_CALL_COMPARE(it,*l_ptr,src_0_location,operands[c_source_pos_idx],return false);

      if (result == 0)
      {
        found = 1;
        break;
      }
    }
    while(++l_ptr < l_ptr_end);
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,found);

  return true;
}/*}}}*/

bool bic_stack_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_STACK_COMPARE(operands[c_source_pos_idx]);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_stack_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  /* - ERROR - */
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("item#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_STACK_CHECK_INDEX();

  pointer *element_location = &array_ptr->data[index];
  location_s *new_ref_location = it.get_new_reference((location_s **)element_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_stack_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;

  if (array_ptr->used > 0)
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_stack_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)dst_location)->v_data_ptr;

  if (array_ptr->used > 0)
  {
    long long int result = array_ptr->used - 1;

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

bool bic_stack_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_STACK_CHECK_INDEX();

  if (++index < array_ptr->used)
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_stack_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_STACK_CHECK_INDEX();

  if (index >= 1)
  {
    long long int result = index - 1;

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

bool bic_stack_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((pointer_array_s *)dst_location->v_data_ptr)->used;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_stack_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(array_ptr->used);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *e_ptr_end = e_ptr + array_ptr->used;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
    }
    while(++s_ptr,++e_ptr < e_ptr_end);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_stack_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(array_ptr->used);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *e_ptr_end = e_ptr + array_ptr->used;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
    }
    while(++s_ptr,++e_ptr < e_ptr_end);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_stack_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = ((pointer_array_s *)dst_location->v_data_ptr);

  putchar('[');

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *e_ptr_end = e_ptr + array_ptr->used;

    do
    {
      BIC_CALL_PRINT(it,*e_ptr,operands[c_source_pos_idx],return false;);
      if (++e_ptr >= e_ptr_end) break;
      putchar(',');
    }
    while(true);
  }

  putchar(']');

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

