
@begin
include "containers_queue.h"
@end

// - class QUEUE -
built_in_class_s queue_class =
{/*{{{*/
  "Queue",
  c_modifier_public | c_modifier_final,
  23, queue_methods,
  0, queue_variables,
  bic_queue_consts,
  bic_queue_init,
  bic_queue_clear,
  nullptr,
  bic_queue_length,
  bic_queue_item,
  bic_queue_first_idx,
  bic_queue_next_idx,
  nullptr,
  nullptr,
  bic_queue_pack,
  bic_queue_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s queue_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_queue_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_queue_operator_binary_plus_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_queue_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_queue_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_queue_operator_binary_plus
  },
  {
    "Queue#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_Queue_0
  },
  {
    "Queue#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_Queue_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_clear_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_items_0
  },
  {
    "insert#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_insert_1
  },
  {
    "insert_ref#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_insert_ref_1
  },
  {
    "next#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_next_0
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_queue_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_queue_method_print_0
  },
};/*}}}*/

built_in_variable_s queue_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_QUEUE_COMPARE(SOURCE_POS) \
  {/*{{{*/\
    if (src_0_location->v_type == c_bi_class_queue)\
    {\
      pointer_queue_s &fq = *((pointer_queue_s *)dst_location->v_data_ptr);\
      pointer_queue_s &sq = *((pointer_queue_s *)src_0_location->v_data_ptr);\
      \
      if (fq.used != sq.used)\
      {\
        result = fq.used < sq.used ? -1 : 1;\
      }\
      else {\
        result = 0;\
        \
        if (fq.used != 0)\
        {\
          pointer *f_ptr = fq.data + fq.begin;\
          pointer *f_ptr_break = fq.data + fq.size;\
          pointer *f_ptr_end;\
          pointer *s_ptr = sq.data + sq.begin;\
          pointer *s_ptr_break = sq.data + sq.size;\
          \
          if (fq.begin + fq.used > fq.size) {\
            f_ptr_end = fq.data + (fq.begin + fq.used - fq.size);\
          }\
          else {\
            f_ptr_end = f_ptr + fq.used;\
          }\
          \
          do {\
            \
            BIC_CALL_COMPARE(it,*f_ptr,*s_ptr,SOURCE_POS,return false);\
            if (result != 0) {\
              break;\
            }\
            \
            if (++f_ptr == f_ptr_end) {\
              break;\
            }\
            \
            if (f_ptr >= f_ptr_break) {\
              f_ptr = fq.data;\
            }\
            \
            if (++s_ptr >= s_ptr_break) {\
              s_ptr = sq.data;\
            }\
            \
          } while(true);\
        }\
      }\
    }\
    else {\
      result = c_bi_class_queue < src_0_location->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_QUEUE_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
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
        /* - push item location to queue - */\
        TARGET_PTR->insert(item_location);\
      }\
      while(++ptr < ptr_end);\
    }\
  }/*}}}*/

#define BIC_QUEUE_APPEND_QUEUE(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    pointer_queue_s *source_ptr = (pointer_queue_s *)SRC_LOCATION->v_data_ptr;\
    \
    if (source_ptr->used != 0)\
    {\
      unsigned fir_cnt;\
      unsigned sec_cnt;\
      \
      if (source_ptr->begin + source_ptr->used > source_ptr->size)\
      {\
        sec_cnt = source_ptr->begin + source_ptr->used - source_ptr->size;\
        fir_cnt = source_ptr->used - sec_cnt;\
      }\
      else\
      {\
        fir_cnt = source_ptr->used;\
        sec_cnt = 0;\
      }\
      \
      pointer *e_ptr = source_ptr->data + source_ptr->begin;\
      pointer *e_ptr_end = e_ptr + fir_cnt;\
      \
      do\
      {\
        location_s *item_location = it.get_location_value(*e_ptr);\
        item_location->v_reference_cnt.atomic_inc();\
        \
        /* - push item location to queue - */\
        TARGET_PTR->insert(item_location);\
      }\
      while(++e_ptr < e_ptr_end);\
      \
      if (sec_cnt != 0)\
      {\
        e_ptr = source_ptr->data;\
        e_ptr_end = e_ptr + sec_cnt;\
        \
        do\
        {\
          location_s *item_location = it.get_location_value(*e_ptr);\
          item_location->v_reference_cnt.atomic_inc();\
          \
          /* - push item location to queue - */\
          TARGET_PTR->insert(item_location);\
        }\
        while(++e_ptr < e_ptr_end);\
      }\
    }\
  }/*}}}*/

#define BIC_QUEUE_APPEND_ITERABLE_BODY(TARGET_PTR) \
  {/*{{{*/\
    item_location->v_reference_cnt.atomic_inc();\
    it.release_location_ptr(item_reference);\
    \
    /* - append item location to queue - */\
    TARGET_PTR->insert(item_location);\
  }/*}}}*/

#define BIC_QUEUE_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
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
        BIC_QUEUE_APPEND_ITERABLE_BODY(TARGET_PTR);\
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
        BIC_QUEUE_APPEND_ITERABLE_BODY(TARGET_PTR);\
        \
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

#define BIC_QUEUE_CHECK_INDEX() \
  /*{{{*/\
  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;\
  \
  /* - ERROR - */\
  \
  unsigned req_used = ((index + queue_ptr->size) - queue_ptr->begin) % queue_ptr->size;\
  if (index < 0 || req_used >= queue_ptr->used) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_QUEUE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

void bic_queue_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_queue_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)cmalloc(sizeof(pointer_queue_s));
  queue_ptr->init();

  location_ptr->v_data_ptr = (pointer_queue_s *)queue_ptr;
}/*}}}*/

void bic_queue_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)location_ptr->v_data_ptr;

  if (queue_ptr->used != 0)
  {
    do
    {
      it.release_location_ptr((location_s *)queue_ptr->next());
    }
    while(queue_ptr->used > 0);
  }

  queue_ptr->clear();
  cfree(queue_ptr);
}/*}}}*/

unsigned bic_queue_length(location_s *location_ptr)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)((location_s *)location_ptr)->v_data_ptr;
  return queue_ptr->used;
}/*}}}*/

location_s *bic_queue_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  unsigned req_used = ((index + queue_ptr->size) - queue_ptr->begin)%queue_ptr->size;
  cassert(req_used < queue_ptr->used);

  pointer *element_location = &queue_ptr->data[index];
  return it.get_new_reference((location_s **)element_location);
}/*}}}*/

unsigned bic_queue_first_idx(location_s *location_ptr)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)((location_s *)location_ptr)->v_data_ptr;
  return queue_ptr->used != 0 ? queue_ptr->begin : c_idx_not_exist;
}/*}}}*/

unsigned bic_queue_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  unsigned req_used = ((index + queue_ptr->size) - queue_ptr->begin) % queue_ptr->size;
  cassert(req_used < queue_ptr->used);

  if (++index >= queue_ptr->size)
  {
    index = 0;
  }

  if (index != (queue_ptr->begin + queue_ptr->used) % queue_ptr->size)
  {
    return index;
  }

  return c_idx_not_exist;
}/*}}}*/

bool bic_queue_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&queue_ptr->used);

  if (queue_ptr->used != 0)
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

    pointer *l_ptr = queue_ptr->data + queue_ptr->begin;
    pointer *l_ptr_end = l_ptr + fir_cnt;

    do
    {
      loc_stack.push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);

    if (sec_cnt != 0)
    {
      l_ptr = queue_ptr->data;
      l_ptr_end = l_ptr + sec_cnt;

      do
      {
        loc_stack.push(*l_ptr);
      }
      while(++l_ptr < l_ptr_end);
    }
  }

  return true;
}/*}}}*/

bool bic_queue_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_queue_s *queue_ptr = (pointer_queue_s *)cmalloc(sizeof(pointer_queue_s));
  queue_ptr->init();

  location_ptr->v_data_ptr = (pointer_queue_s *)queue_ptr;

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
    queue_ptr->copy_resize(length);

    pointer *l_ptr = loc_stack.data + (loc_stack.used - length);
    pointer *l_ptr_end = loc_stack.data + loc_stack.used;
    do
    {
      queue_ptr->insert(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);

    loc_stack.used -= length;
  }

  return true;
}/*}}}*/

bool bic_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

bool bic_queue_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_QUEUE_APPEND_ARRAY(src_0_location,queue_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_QUEUE_APPEND_ITERABLE(src_0_location,queue_ptr);
  }

  dst_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_queue_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_QUEUE_COMPARE(operands[c_source_pos_idx]);
  result = result == 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_queue_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_QUEUE_COMPARE(operands[c_source_pos_idx]);
  result = result != 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_queue_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)cmalloc(sizeof(pointer_queue_s));
  queue_ptr->init();

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_queue,queue_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  // - copy elements from queue -
  BIC_QUEUE_APPEND_QUEUE(dst_location,queue_ptr);

  // - append elements from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_QUEUE_APPEND_ARRAY(src_0_location,queue_ptr);
  }

  // - append elements from iterable -
  else
  {
    BIC_QUEUE_APPEND_ITERABLE(src_0_location,queue_ptr);
  }

  return true;
}/*}}}*/

bool bic_queue_method_Queue_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_queue_method_Queue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_QUEUE_APPEND_ARRAY(src_0_location,queue_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_QUEUE_APPEND_ITERABLE(src_0_location,queue_ptr);
  }

  return true;
}/*}}}*/

bool bic_queue_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  if (queue_ptr->used != 0)
  {
    do
    {
      it.release_location_ptr((location_s *)queue_ptr->next());
    }
    while(queue_ptr->used > 0);
  }

  queue_ptr->clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_queue_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (queue_ptr->used != 0)
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

    pointer *e_ptr = queue_ptr->data + queue_ptr->begin;
    pointer *e_ptr_end = e_ptr + fir_cnt;

    do
    {
      location_s *item_location = it.get_location_value(*e_ptr);
      item_location->v_reference_cnt.atomic_inc();
      array_ptr->push(item_location);
    }
    while(++e_ptr < e_ptr_end);

    if (sec_cnt != 0)
    {
      e_ptr = queue_ptr->data;
      e_ptr_end = e_ptr + sec_cnt;

      do
      {
        location_s *item_location = it.get_location_value(*e_ptr);
        item_location->v_reference_cnt.atomic_inc();
        array_ptr->push(item_location);
      }
      while(++e_ptr < e_ptr_end);
    }
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_queue_method_insert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  src_0_location->v_reference_cnt.atomic_inc();
  queue_ptr->insert((pointer)src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_queue_method_insert_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  pointer &src_0_location = it.data_stack[stack_base + operands[c_src_0_op_idx]];

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_0_location);
  queue_ptr->insert((pointer)new_ref_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_queue_method_next_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (queue_ptr->used == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_QUEUE_NO_OTHER_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve next location from queue -
  location_s *location_ptr = (location_s *)queue_ptr->next();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_queue_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  long long int found = 0;
  long long int result;

  if (queue_ptr->used != 0)
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

    pointer *e_ptr = queue_ptr->data + queue_ptr->begin;
    pointer *e_ptr_end = e_ptr + fir_cnt;

    do
    {
      BIC_CALL_COMPARE(it,*e_ptr,src_0_location,operands[c_source_pos_idx],return false);

      if (result == 0)
      {
        found = 1;
        break;
      }
    }
    while(++e_ptr < e_ptr_end);

    if (!found && sec_cnt != 0)
    {
      e_ptr = queue_ptr->data;
      e_ptr_end = e_ptr + sec_cnt;

      do
      {
        BIC_CALL_COMPARE(it,*e_ptr,src_0_location,operands[c_source_pos_idx],return false);

        if (result == 0)
        {
          found = 1;
          break;
        }
      }
      while(++e_ptr < e_ptr_end);
    }
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,found);

  return true;
}/*}}}*/

bool bic_queue_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_QUEUE_COMPARE(operands[c_source_pos_idx]);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_queue_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
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

  BIC_QUEUE_CHECK_INDEX();

  pointer *element_location = &queue_ptr->data[index];
  location_s *new_ref_location = it.get_new_reference((location_s **)element_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_queue_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)((location_s *)dst_location)->v_data_ptr;

  if (queue_ptr->used > 0)
  {
    long long int result = queue_ptr->begin;

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

bool bic_queue_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)((location_s *)dst_location)->v_data_ptr;

  if (queue_ptr->used > 0)
  {
    long long int result = (queue_ptr->begin + queue_ptr->used - 1) % queue_ptr->size;

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

bool bic_queue_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
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

  BIC_QUEUE_CHECK_INDEX();

  // - increase index value -
  if (++index >= queue_ptr->size)
  {
    index = 0;
  }

  if (index != (queue_ptr->begin + queue_ptr->used) % queue_ptr->size)
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

bool bic_queue_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
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

  BIC_QUEUE_CHECK_INDEX();

  if (index != queue_ptr->begin)
  {
    long long int result = index == 0 ? queue_ptr->size - 1 : index - 1;

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

bool bic_queue_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((pointer_queue_s *)dst_location->v_data_ptr)->used;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(queue_ptr->used);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (queue_ptr->used != 0)
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

    pointer *e_ptr = queue_ptr->data + queue_ptr->begin;
    pointer *e_ptr_end = e_ptr + fir_cnt;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
    }
    while(++s_ptr,++e_ptr < e_ptr_end);

    if (sec_cnt != 0)
    {
      e_ptr = queue_ptr->data;
      e_ptr_end = e_ptr + sec_cnt;

      do
      {
        BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                           strings.clear();
                           return false;
                          );
      }
      while(++s_ptr,++e_ptr < e_ptr_end);
    }
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_queue_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  pointer_queue_s *queue_ptr = (pointer_queue_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(queue_ptr->used);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (queue_ptr->used != 0)
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

    pointer *e_ptr = queue_ptr->data + queue_ptr->begin;
    pointer *e_ptr_end = e_ptr + fir_cnt;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
    }
    while(++s_ptr,++e_ptr < e_ptr_end);

    if (sec_cnt != 0)
    {
      e_ptr = queue_ptr->data;
      e_ptr_end = e_ptr + sec_cnt;

      do
      {
        BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                           strings.clear();
                           return false;
                          );
      }
      while(++s_ptr,++e_ptr < e_ptr_end);
    }
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_queue_s *queue_ptr = ((pointer_queue_s *)dst_location->v_data_ptr);

  putchar('[');

  if (queue_ptr->used != 0)
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

    pointer *e_ptr = queue_ptr->data + queue_ptr->begin;
    pointer *e_ptr_end = e_ptr + fir_cnt;

    BIC_CALL_PRINT(it,*e_ptr,operands[c_source_pos_idx],return false;);

    if (++e_ptr < e_ptr_end)
    {
      do
      {
        putchar(',');
        BIC_CALL_PRINT(it,*e_ptr,operands[c_source_pos_idx],return false;);
      }
      while(++e_ptr < e_ptr_end);
    }

    if (sec_cnt != 0)
    {
      e_ptr = queue_ptr->data;
      e_ptr_end = e_ptr + sec_cnt;

      do
      {
        putchar(',');
        BIC_CALL_PRINT(it,*e_ptr,operands[c_source_pos_idx],return false;);
      }
      while(++e_ptr < e_ptr_end);
    }
  }

  putchar(']');

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

