
@begin
include "algorithms_module.h"
@end

// - ALGORITHMS indexes of built in classes -
unsigned c_bi_class_algo = c_idx_not_exist;

// - ALGORITHMS module -
built_in_module_s module =
{/*{{{*/
  1,                          // Class count
  algorithms_classes,         // Classes

  0,                          // Error base index
  1,                          // Error count
  algorithms_error_strings,   // Error strings

  algorithms_initialize,      // Initialize function
  algorithms_print_exception, // Print exceptions function
};/*}}}*/

// - ALGORITHMS classes -
built_in_class_s *algorithms_classes[] =
{/*{{{*/
  &algo_class,
};/*}}}*/

// - ALGORITHMS error strings -
const char *algorithms_error_strings[] =
{/*{{{*/
  "error_ALGO_WRONG_DELEGATE",
};/*}}}*/

// - ALGORITHMS initialize -
bool algorithms_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize algo class identifier -
  c_bi_class_algo = class_base_idx++;

  return true;
}/*}}}*/

// - ALGORITHMS print exception -
bool algorithms_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_ALGO_WRONG_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong delegate for algorithm, expected %" HOST_LL_FORMAT "d parameter/s\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class ALGO -
built_in_class_s algo_class =
{/*{{{*/
  "Algo",
  c_modifier_public | c_modifier_final,
  5, algo_methods,
  0, algo_variables,
  bic_algo_consts,
  bic_algo_init,
  bic_algo_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s algo_methods[] =
{/*{{{*/
  {
    "all_true#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_all_true_1
  },
  {
    "any_true#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_any_true_1
  },
  {
    "map#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_map_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_print_0
  },
};/*}}}*/

built_in_variable_s algo_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ALGO_PROCESS_ARRAY(SRC_LOCATION,ALGO_CODE) \
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
        ALGO_CODE;\
      }\
      while(++ptr < ptr_end);\
    }\
  }/*}}}*/

#define BIC_ALGO_PROCESS_ITERABLE(SRC_LOCATION,ALGO_CODE) \
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
      location_s *item_location;\
      location_s *item_reference;\
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
        ALGO_CODE;\
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
        ALGO_CODE;\
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

void bic_algo_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_algo_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_algo_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_algo_method_all_true_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  bool all_true = true;
  bool result;

  // - process array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_ALGO_PROCESS_ARRAY(src_0_location,

      // - test value -
      if (!it.test_value(item_location,result))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(item_location->v_type);

        return false;
      }

      all_true &= result;
    );
  }

  // - process iterable -
  else
  {
    BIC_ALGO_PROCESS_ITERABLE(src_0_location,

      // - test value -
      if (!it.test_value(item_location,result))
      {
        it.release_location_ptr(item_reference);

        exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(item_location->v_type);

        return false;
      }

      it.release_location_ptr(item_reference);
      all_true &= result;
    );
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,all_true);

  return true;
}/*}}}*/

bool bic_algo_method_any_true_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  bool any_true = false;
  bool result;

  // - process array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_ALGO_PROCESS_ARRAY(src_0_location,

      // - test value -
      if (!it.test_value(item_location,result))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(item_location->v_type);

        return false;
      }

      any_true |= result;
    );
  }

  // - process iterable -
  else
  {
    BIC_ALGO_PROCESS_ITERABLE(src_0_location,

      // - test value -
      if (!it.test_value(item_location,result))
      {
        it.release_location_ptr(item_reference);

        exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(item_location->v_type);

        return false;
      }

      it.release_location_ptr(item_reference);
      any_true |= result;
    );
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,any_true);

  return true;
}/*}}}*/

bool bic_algo_method_map_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_1_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_algo,"map#2");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);
    
    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_WRONG_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);

    return false;
  }

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  // - process array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_ALGO_PROCESS_ARRAY(src_0_location,

      // - call delegate method -
      location_s *trg_location = NULL;
      BIC_CALL_DELEGATE(it,delegate_ptr,(pointer *)&item_location,1,trg_location,operands[c_source_pos_idx],
        it.release_location_ptr(array_location);
        return false
      );

      array_ptr->push(trg_location);
    );
  }

  // - process iterable -
  else
  {
    BIC_ALGO_PROCESS_ITERABLE(src_0_location,

      // - call delegate method -
      location_s *trg_location = NULL;
      BIC_CALL_DELEGATE(it,delegate_ptr,(pointer *)&item_location,1,trg_location,operands[c_source_pos_idx],
        it.release_location_ptr(item_reference);
        it.release_location_ptr(array_location);
        return false
      );

      it.release_location_ptr(item_reference);
      array_ptr->push(trg_location);
    );
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_algo_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Algo"),"Algo");
  );

  return true;
}/*}}}*/

bool bic_algo_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Algo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

