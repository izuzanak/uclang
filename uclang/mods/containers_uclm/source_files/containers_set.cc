
@begin
include "containers_set.h"
@end

// - class SET -
built_in_class_s set_class =
{/*{{{*/
  "Set",
  c_modifier_public | c_modifier_final,
  33, set_methods,
  0, set_variables,
  bic_set_consts,
  bic_set_init,
  bic_set_clear,
  NULL,
  bic_set_length,
  bic_set_item,
  bic_set_first_idx,
  bic_set_next_idx,
  NULL,
  bic_set_pack,
  bic_set_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s set_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_minus_equal
  },
  {
    "operator_binary_ampersand_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_ampersand_equal
  },
  {
    "operator_binary_pipe_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_pipe_equal
  },
  {
    "operator_binary_circumflex_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_circumflex_equal
  },
  {
    "operator_binary_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_ampersand
  },
  {
    "operator_binary_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_pipe
  },
  {
    "operator_binary_circumflex#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_circumflex
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_ls_br_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_minus
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_set_operator_binary_le_br_re_br
  },
  {
    "Set#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_Set_0
  },
  {
    "Set#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_Set_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_clear_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_items_0
  },
  {
    "insert#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_insert_1
  },
  {
    "remove#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_remove_1
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_set_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_set_method_print_0
  },
};/*}}}*/

built_in_variable_s set_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_SET_COMPARE(SOURCE_POS) \
  {/*{{{*/\
    if (src_0_location->v_type == c_bi_class_set) {\
      pointer_tree_s *f_tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;\
      pointer_tree_s *s_tree_ptr = (pointer_tree_s *)src_0_location->v_data_ptr;\
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
            BIC_CALL_COMPARE(it,f_tree_ptr->data[ft_idx].object,s_tree_ptr->data[st_idx].object,SOURCE_POS,return false);\
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
      result = c_bi_class_set < src_0_location->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_SET_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
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
        \
        /* - push item location to set - */\
        if (TARGET_PTR->set_unique_insert(item_location))\
        {\
          item_location->v_reference_cnt.atomic_inc();\
        }\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
        {\
          return false;\
        }\
        \
      }\
      while(++ptr < ptr_end);\
    }\
  }/*}}}*/

#define BIC_SET_APPEND_SET(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    pointer_tree_s *source_ptr = (pointer_tree_s *)SRC_LOCATION->v_data_ptr;\
    \
    if (source_ptr->count != 0)\
    {\
      unsigned stack[source_ptr->get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned t_idx = source_ptr->get_stack_min_value_idx(source_ptr->root_idx,&stack_ptr);\
      \
      do\
      {\
        location_s *item_location = it.get_location_value(source_ptr->data[t_idx].object);\
        \
        /* - push item location to set - */\
        if (TARGET_PTR->set_unique_insert(item_location))\
        {\
          item_location->v_reference_cnt.atomic_inc();\
        }\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
        {\
          return false;\
        }\
        \
        t_idx = source_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);\
      }\
      while(t_idx != c_idx_not_exist);\
    }\
  }/*}}}*/

#define BIC_SET_APPEND_ITERABLE_BODY(TARGET_PTR) \
  {/*{{{*/\
    \
    /* - insert item location to set - */\
    if (TARGET_PTR->set_unique_insert(item_location)) {\
      item_location->v_reference_cnt.atomic_inc();\
    }\
    \
    it.release_location_ptr(item_reference);\
    \
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
      return false;\
    }\
  }/*}}}*/

#define BIC_SET_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
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
        BIC_SET_APPEND_ITERABLE_BODY(TARGET_PTR);\
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
        BIC_SET_APPEND_ITERABLE_BODY(TARGET_PTR);\
        \
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

#define BIC_SET_CHECK_INDEX() \
  /*{{{*/\
  pointer_tree_s *tree_ptr = (pointer_tree_s *)((location_s *)dst_location)->v_data_ptr;\
  \
  /* - ERROR - */\
  if (index < 0 || index >= tree_ptr->used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SET_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  \
  pointer_tree_s_node &node = tree_ptr->data[index];\
  \
  /* - ERROR - */\
  if (!node.valid)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SET_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_SET_ITEM(NAME) \
  {/*{{{*/\
    unsigned res_loc_idx = stack_base + operands[c_res_op_idx];\
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
    BIC_SET_CHECK_INDEX();\
    \
    location_s *element_location = (location_s *)tree_ptr->data[index].object;\
    element_location->v_reference_cnt.atomic_inc();\
    \
    pointer &res_location = it.data_stack[res_loc_idx];\
    BIC_SET_RESULT(element_location);\
    \
    return true;\
  }/*}}}*/

#define BIC_SET_INTERSECTION() \
  {/*{{{*/\
    /* - configure second - */\
    second.it_ptr = &it;\
    second.source_pos = operands[c_source_pos_idx];\
    \
    /* - configure target - */\
    target_ptr->it_ptr = &it;\
    target_ptr->source_pos = operands[c_source_pos_idx];\
    \
    /* - if first and second are not empty - */\
    if (first.count != 0 && second.count != 0)\
    {\
      pointer_tree_s *first_ptr;\
      pointer_tree_s *second_ptr;\
      \
      /* - order sets by size - */\
      if (first.count <= second.count)\
      {\
        first_ptr = &first;\
        second_ptr = &second;\
      }\
      else\
      {\
        first_ptr = &second;\
        second_ptr = &first;\
      }\
      \
      /* - traverse through first - */\
      unsigned stack[first_ptr->get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned f_idx = first_ptr->get_stack_min_value_idx(first_ptr->root_idx,&stack_ptr);\
      do {\
        location_s *elm_location = (location_s *)first_ptr->data[f_idx].object;\
        \
        /* - retrieve index in second - */\
        unsigned s_idx = second_ptr->get_idx((pointer)elm_location);\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
          it.release_location_ptr(new_location);\
          return false;\
        }\
        \
        /* - if element exist in second - */\
        if (s_idx != c_idx_not_exist)\
        {\
          /* - insert to target - */\
          elm_location->v_reference_cnt.atomic_inc();\
          target_ptr->insert((pointer)elm_location);\
          \
          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
            it.release_location_ptr(new_location);\
            return false;\
          }\
        }\
        \
        f_idx = first_ptr->get_stack_next_idx(f_idx,&stack_ptr,stack);\
      } while(f_idx != c_idx_not_exist);\
    }\
  }/*}}}*/

#define BIC_SET_UNION() \
  {/*{{{*/\
    if (first.count != 0)\
    {\
      /* - traverse through first - */\
      unsigned stack[first.get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned f_idx = first.get_stack_min_value_idx(first.root_idx,&stack_ptr);\
      do {\
        \
        /* - increase element reference count - */\
        ((location_s *)first.data[f_idx].object)->v_reference_cnt.atomic_inc();\
        \
        f_idx = first.get_stack_next_idx(f_idx,&stack_ptr,stack);\
      } while(f_idx != c_idx_not_exist);\
    }\
    \
    /* - copy first to target - */\
    *target_ptr = first;\
    \
    /* - configure target - */\
    target_ptr->it_ptr = &it;\
    target_ptr->source_pos = operands[c_source_pos_idx];\
    \
    if (second.count != 0)\
    {\
      /* - traverse through second - */\
      unsigned stack[second.get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned s_idx = second.get_stack_min_value_idx(second.root_idx,&stack_ptr);\
      do {\
        location_s *elm_location = (location_s *)second.data[s_idx].object;\
        \
        /* - unique insert element to target - */\
        if (target_ptr->set_unique_insert((pointer)elm_location)) {\
          elm_location->v_reference_cnt.atomic_inc();\
        }\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
          it.release_location_ptr(new_location);\
          return false;\
        }\
        \
        s_idx = second.get_stack_next_idx(s_idx,&stack_ptr,stack);\
      } while(s_idx != c_idx_not_exist);\
    }\
  }/*}}}*/

#define BIC_SET_DIFFERENCE() \
  {/*{{{*/\
    /* - configure second - */\
    second.it_ptr = &it;\
    second.source_pos = operands[c_source_pos_idx];\
    \
    /* - configure target - */\
    target_ptr->it_ptr = &it;\
    target_ptr->source_pos = operands[c_source_pos_idx];\
    \
    /* - if first is not empty - */\
    if (first.count != 0) {\
      \
      /* - traverse through first - */\
      unsigned stack[first.get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned f_idx = first.get_stack_min_value_idx(first.root_idx,&stack_ptr);\
      do {\
        location_s *elm_location = (location_s *)first.data[f_idx].object;\
        \
        /* - retrieve index in second - */\
        unsigned s_idx = second.get_idx((pointer)elm_location);\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
          it.release_location_ptr(new_location);\
          return false;\
        }\
        \
        /* - if element not exist in second - */\
        if (s_idx == c_idx_not_exist)\
        {\
          /* - insert to target - */\
          elm_location->v_reference_cnt.atomic_inc();\
          target_ptr->insert((pointer)elm_location);\
          \
          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
            it.release_location_ptr(new_location);\
            return false;\
          }\
        }\
        \
        f_idx = first.get_stack_next_idx(f_idx,&stack_ptr,stack);\
      } while(f_idx != c_idx_not_exist);\
    }\
  }/*}}}*/

#define BIC_SET_SYMMETRIC_DIFFERENCE() \
  {/*{{{*/\
    if (first.count != 0)\
    {\
      /* - traverse through first - */\
      unsigned stack[first.get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned f_idx = first.get_stack_min_value_idx(first.root_idx,&stack_ptr);\
      do {\
        \
        /* - increase element reference count - */\
        ((location_s *)first.data[f_idx].object)->v_reference_cnt.atomic_inc();\
        \
        f_idx = first.get_stack_next_idx(f_idx,&stack_ptr,stack);\
      } while(f_idx != c_idx_not_exist);\
    }\
    \
    /* - copy first to target - */\
    *target_ptr = first;\
    \
    /* - configure target - */\
    target_ptr->it_ptr = &it;\
    target_ptr->source_pos = operands[c_source_pos_idx];\
    \
    if (second.count != 0)\
    {\
      /* - traverse through second - */\
      unsigned stack[second.get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned s_idx = second.get_stack_min_value_idx(second.root_idx,&stack_ptr);\
      do {\
        location_s *elm_location = (location_s *)second.data[s_idx].object;\
        \
        /* - find index of element in target - */\
        unsigned index = target_ptr->get_idx((pointer)elm_location);\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
          it.release_location_ptr(new_location);\
          return false;\
        }\
        \
        if (index == c_idx_not_exist)\
        {\
          /* - insert element to target - */\
          elm_location->v_reference_cnt.atomic_inc();\
          target_ptr->insert((pointer)elm_location);\
          \
          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
            it.release_location_ptr(new_location);\
            return false;\
          }\
        }\
        else {\
          /* - remove element from target - */\
          it.release_location_ptr((location_s *)target_ptr->data[index].object);\
          target_ptr->remove(index);\
        }\
        \
        s_idx = second.get_stack_next_idx(s_idx,&stack_ptr,stack);\
      } while(s_idx != c_idx_not_exist);\
    }\
  }/*}}}*/

#define BIC_SET_SUBSET_TEST() \
  {/*{{{*/\
    if (first.count <= second.count)\
    {\
      unsigned stack[first.get_descent_stack_size()];\
      unsigned *stack_ptr = stack;\
      \
      unsigned f_idx = first.get_stack_min_value_idx(first.root_idx,&stack_ptr);\
      do {\
        location_s *elm_location = (location_s *)first.data[f_idx].object;\
        \
        /* - retrieve index in second - */\
        unsigned s_idx = second.get_idx((pointer)elm_location);\
        \
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank) {\
          return false;\
        }\
        \
        /* - if element exist in second - */\
        if (s_idx == c_idx_not_exist)\
        {\
          result = 0;\
          break;\
        }\
        \
        f_idx = first.get_stack_next_idx(f_idx,&stack_ptr,stack);\
      } while(f_idx != c_idx_not_exist);\
    }\
    else {\
      result = 0;\
    }\
  }/*}}}*/

void bic_set_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_set_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  tree_ptr->init();

  location_ptr->v_data_ptr = (basic_64b)tree_ptr;
}/*}}}*/

void bic_set_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)location_ptr->v_data_ptr;

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    do
    {
      it.release_location_ptr((location_s *)tree_ptr->data[t_idx].object);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  tree_ptr->clear();
  cfree(tree_ptr);
}/*}}}*/

unsigned bic_set_length(location_s *location_ptr)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)((location_s *)location_ptr)->v_data_ptr;
  return tree_ptr->count;
}/*}}}*/

location_s *bic_set_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)((location_s *)location_ptr)->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < tree_ptr->used);

  pointer_tree_s_node &node = tree_ptr->data[index];

  // FIXME TODO check index ...
  cassert(node.valid);

  location_s *element_location = (location_s *)node.object;
  element_location->v_reference_cnt.atomic_inc();

  return element_location;
}/*}}}*/

unsigned bic_set_first_idx(location_s *location_ptr)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)((location_s *)location_ptr)->v_data_ptr;

  if (tree_ptr->root_idx != c_idx_not_exist)
  {
    return tree_ptr->get_min_value_idx(tree_ptr->root_idx);
  }
  else
  {
    return c_idx_not_exist;
  }
}/*}}}*/

unsigned bic_set_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)((location_s *)location_ptr)->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < tree_ptr->used);

  // FIXME TODO check index ...
  pointer_tree_s_node &node = tree_ptr->data[index];
  cassert(node.valid);

  return tree_ptr->get_next_idx(index);
}/*}}}*/

bool bic_set_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&tree_ptr->count);

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

    do
    {
      loc_stack.push(tree_ptr->data[t_idx].object);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  return true;
}/*}}}*/

bool bic_set_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_tree_s *tree_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  tree_ptr->init();

  location_ptr->v_data_ptr = (basic_64b)tree_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = source_pos;

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
      cassert(tree_ptr->set_unique_insert(*l_ptr));

      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        return false;
      }

    }
    while(++l_ptr < l_ptr_end);

    loc_stack.used -= count;
  }

  return true;
}/*}}}*/

bool bic_set_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

bool bic_set_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_SET_APPEND_ARRAY(src_0_location,tree_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_SET_APPEND_ITERABLE(src_0_location,tree_ptr);
  }

  dst_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  unsigned dst_loc_idx = stack_base + operands[c_dst_op_idx];
  pointer &dst_location = it.get_stack_value(dst_loc_idx);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_minus_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)((location_s *)dst_location)->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_DIFFERENCE();

  new_location->v_reference_cnt.atomic_inc();

  {
    pointer &dst_location = it.get_stack_value(dst_loc_idx);
    BIC_SET_DESTINATION(new_location);
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  unsigned dst_loc_idx = stack_base + operands[c_dst_op_idx];
  pointer &dst_location = it.get_stack_value(dst_loc_idx);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_ampersand_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)((location_s *)dst_location)->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_INTERSECTION();

  new_location->v_reference_cnt.atomic_inc();

  {
    pointer &dst_location = it.get_stack_value(dst_loc_idx);
    BIC_SET_DESTINATION(new_location);
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  unsigned dst_loc_idx = stack_base + operands[c_dst_op_idx];
  pointer &dst_location = it.get_stack_value(dst_loc_idx);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_pipe_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)((location_s *)dst_location)->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_UNION();

  new_location->v_reference_cnt.atomic_inc();

  {
    pointer &dst_location = it.get_stack_value(dst_loc_idx);
    BIC_SET_DESTINATION(new_location);
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  unsigned dst_loc_idx = stack_base + operands[c_dst_op_idx];
  pointer &dst_location = it.get_stack_value(dst_loc_idx);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_circumflex_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)((location_s *)dst_location)->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_SYMMETRIC_DIFFERENCE();

  new_location->v_reference_cnt.atomic_inc();

  {
    pointer &dst_location = it.get_stack_value(dst_loc_idx);
    BIC_SET_DESTINATION(new_location);
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_ampersand#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)((location_s *)dst_location)->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_INTERSECTION();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_pipe#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)((location_s *)dst_location)->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_UNION();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_circumflex#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)dst_location->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_SYMMETRIC_DIFFERENCE();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_SET_COMPARE(operands[c_source_pos_idx]);
  result = result == 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_SET_COMPARE(operands[c_source_pos_idx]);
  result = result != 0;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_rs_br_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &second = *((pointer_tree_s *)dst_location->v_data_ptr);
  pointer_tree_s &first = *((pointer_tree_s *)src_0_location->v_data_ptr);

  long long int result = 1;

  BIC_SET_SUBSET_TEST();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_ls_br_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)dst_location->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  long long int result = 1;

  BIC_SET_SUBSET_TEST();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  tree_ptr->init();

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,tree_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  // - copy elements from set -
  BIC_SET_APPEND_SET(dst_location,tree_ptr);

  // - append elements from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_SET_APPEND_ARRAY(src_0_location,tree_ptr);
  }

  // - append elements from iterable -
  else
  {
    BIC_SET_APPEND_ITERABLE(src_0_location,tree_ptr);
  }

  return true;
}/*}}}*/

bool bic_set_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_set)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_minus#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - get references to first and second -
  pointer_tree_s &first = *((pointer_tree_s *)dst_location->v_data_ptr);
  pointer_tree_s &second = *((pointer_tree_s *)src_0_location->v_data_ptr);

  // - create target -
  pointer_tree_s *target_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
  target_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_set,target_ptr);

  BIC_SET_DIFFERENCE();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_set_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SET_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_set_method_Set_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_set_method_Set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_SET_APPEND_ARRAY(src_0_location,tree_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_SET_APPEND_ITERABLE(src_0_location,tree_ptr);
  }

  return true;
}/*}}}*/

bool bic_set_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
    do
    {
      it.release_location_ptr((location_s *)tree_ptr->data[t_idx].object);

      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(t_idx != c_idx_not_exist);
  }

  tree_ptr->clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_set_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

    do
    {
      location_s *item_location = it.get_location_value(tree_ptr->data[t_idx].object);
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

bool bic_set_method_insert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  if (tree_ptr->set_unique_insert((pointer)src_0_location))
  {
    src_0_location->v_reference_cnt.atomic_inc();
  }

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_set_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  long long int index = tree_ptr->get_idx((pointer)src_0_location);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  if (index == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SET_DOES_NOT_CONTAIN_ELEMENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  it.release_location_ptr((location_s *)tree_ptr->data[index].object);
  tree_ptr->remove(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_set_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  long long int index = tree_ptr->get_idx((pointer)src_0_location);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  long long int result = index != c_idx_not_exist;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_SET_COMPARE(operands[c_source_pos_idx]);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SET_ITEM("item#1");
}/*}}}*/

bool bic_set_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;

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

bool bic_set_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;

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

bool bic_set_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_SET_CHECK_INDEX();

  long long int next_idx = tree_ptr->get_next_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(next_idx);

  return true;
}/*}}}*/

bool bic_set_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_SET_CHECK_INDEX();

  long long int prev_idx = tree_ptr->get_prev_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(prev_idx);

  return true;
}/*}}}*/

bool bic_set_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((pointer_tree_s *)dst_location->v_data_ptr)->count;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_set_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(tree_ptr->count);
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
      BIC_CALL_TO_STRING(it,tree_ptr->data[t_idx].object,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(++s_ptr,t_idx != c_idx_not_exist);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_set_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  pointer_tree_s *tree_ptr = (pointer_tree_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(tree_ptr->count);
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
      BIC_CALL_TO_STRING(it,tree_ptr->data[t_idx].object,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
      t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
    }
    while(++s_ptr,t_idx != c_idx_not_exist);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_set_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_tree_s *tree_ptr = ((pointer_tree_s *)dst_location->v_data_ptr);

  putchar('[');

  if (tree_ptr->count != 0)
  {
    unsigned stack[tree_ptr->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

    BIC_CALL_PRINT(it,tree_ptr->data[t_idx].object,operands[c_source_pos_idx],return false;);
    t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);

    if (t_idx != c_idx_not_exist)
    {
      do
      {
        putchar(',');
        BIC_CALL_PRINT(it,tree_ptr->data[t_idx].object,operands[c_source_pos_idx],return false;);
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

