
@begin
include "algorithms_module.h"
@end

// - ALGORITHMS indexes of built in classes -
unsigned c_bi_class_algo = c_idx_not_exist;
unsigned c_bi_class_filter = c_idx_not_exist;
unsigned c_bi_class_range = c_idx_not_exist;

// - ALGORITHMS indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - ALGORITHMS module -
built_in_module_s module =
{/*{{{*/
  3,                          // Class count
  algorithms_classes,         // Classes

  0,                          // Error base index
  5,                          // Error count
  algorithms_error_strings,   // Error strings

  algorithms_initialize,      // Initialize function
  algorithms_print_exception, // Print exceptions function
};/*}}}*/

// - ALGORITHMS classes -
built_in_class_s *algorithms_classes[] =
{/*{{{*/
  &algo_class,
  &filter_class,
  &range_class,
};/*}}}*/

// - ALGORITHMS error strings -
const char *algorithms_error_strings[] =
{/*{{{*/
  "error_ALGO_FILTER_WRONG_DELEGATE",
  "error_ALGO_FILTER_EXPECTED_INTEGER_AS_ARRAY_INDEX",
  "error_ALGO_FILTER_INDEX_EXCEEDS_ARRAY_RANGE",
  "error_ALGO_FILTER_UNDEFINED_DICTIONARY_KEY",
  "error_RANGE_START_END_TYPES_DIFFERS",
};/*}}}*/

// - ALGORITHMS initialize -
bool algorithms_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize algo class identifier -
  c_bi_class_algo = class_base_idx++;

  // - initialize filter class identifier -
  c_bi_class_filter = class_base_idx++;

  // - initialize range class identifier -
  c_bi_class_range = class_base_idx++;

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

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
  case c_error_ALGO_FILTER_WRONG_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong delegate for algorithm, expected %" HOST_LL_FORMAT "d parameter/s\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ALGO_FILTER_EXPECTED_INTEGER_AS_ARRAY_INDEX:
    {
      class_record_s &class_record = it.class_records[exception.params[0]];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nReceived ");
      print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
      fprintf(stderr,"%s while expecting Integer as map array index\n",it.class_symbol_names[class_record.name_idx].data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_ALGO_FILTER_INDEX_EXCEEDS_ARRAY_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nReceived index %" HOST_LL_FORMAT "d exceeds map array range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ALGO_FILTER_UNDEFINED_DICTIONARY_KEY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nReceived key is undefined in map dictionary\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RANGE_START_END_TYPES_DIFFERS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDifferent types of range start/end values\n");
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
  8, algo_methods,
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
    "reduce#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_reduce_3
  },
  {
    "filter#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_filter_2
  },
  {
    "zip#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_algo_method_zip_1
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

#define BIC_ALGO_PROCESS_ITERABLE(SRC_LOCATION,ALGO_CODE,ERR_CODE) \
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
      ERR_CODE;\
    }\
\
    if (iter_type == c_iter_first_idx_next_idx_item)\
    {\
      long long index;\
      location_s *item_reference;\
      location_s *item_location;\
\
      /* - retrieve first index - */\
      BIC_CALL_FIRST_IDX(it,SRC_LOCATION,index,operands[c_source_pos_idx],ERR_CODE;);\
\
      while (index != c_idx_not_exist)\
      {\
        /* - retrieve item location - */\
        BIC_CALL_ITEM(it,SRC_LOCATION,index,item_reference,operands[c_source_pos_idx],ERR_CODE;);\
        item_location = it.get_location_value(item_reference);\
\
        ALGO_CODE;\
\
        /* - retrieve next index - */\
        BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],ERR_CODE;);\
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
        BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,item_reference,operands[c_source_pos_idx],ERR_CODE;);\
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
    ,
      return false;
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
    ,
      return false;
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

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

#define BIC_ALGO_METHOD_MAP_MAP_ARRAY(RELEASE_REFERENCE) \
/*{{{*/\
  long long int map_index;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(item_location,map_index))\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_EXPECTED_INTEGER_AS_ARRAY_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(item_location->v_type);\
\
    return false;\
  }\
\
  /* - ERROR - */\
  if (map_index < 0 || map_index >= map_arr_ptr->used)\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_INDEX_EXCEEDS_ARRAY_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(map_index);\
\
    return false;\
  }\
\
  location_s *trg_location = it.get_location_value(map_arr_ptr->data[map_index]);\
  trg_location->v_reference_cnt.atomic_inc();\
\
  RELEASE_REFERENCE;\
/*}}}*/

#define BIC_ALGO_METHOD_MAP_MAP_DICT(RELEASE_REFERENCE) \
/*{{{*/\
  map_tree_ptr->it_ptr = &it;\
  map_tree_ptr->source_pos = operands[c_source_pos_idx];\
\
  pointer_map_s search_map = {(pointer)item_location MP_COMMA NULL};\
  unsigned index = map_tree_ptr->get_idx(search_map);\
\
  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (index == c_idx_not_exist)\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
\
    exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_UNDEFINED_DICTIONARY_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  location_s *trg_location = it.get_location_value(map_tree_ptr->data[index].object.value);\
  trg_location->v_reference_cnt.atomic_inc();\
\
  RELEASE_REFERENCE;\
/*}}}*/

#define BIC_ALGO_METHOD_MAP_MAP_DLG(RELEASE_REFERENCE) \
/*{{{*/\
\
  /* - call delegate method - */\
  location_s *trg_location = NULL;\
  BIC_CALL_DELEGATE(it,delegate_ptr,(pointer *)&item_location,1,trg_location,operands[c_source_pos_idx],\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
    return false;\
  );\
\
  RELEASE_REFERENCE;\
/*}}}*/

  if (src_1_location->v_type == c_rm_class_dict)
  {/*{{{*/

    // - retrieve map dict -
    pointer_map_tree_s *map_tree_ptr = (pointer_map_tree_s *)src_1_location->v_data_ptr;

    // - process array -
    if (src_0_location->v_type == c_bi_class_array)
    {
      BIC_ALGO_PROCESS_ARRAY(src_0_location,
        BIC_ALGO_METHOD_MAP_MAP_DICT();
        array_ptr->push(trg_location);
      );
    }

    // - process iterable -
    else
    {
      BIC_ALGO_PROCESS_ITERABLE(src_0_location,
        BIC_ALGO_METHOD_MAP_MAP_DICT(it.release_location_ptr(item_reference););
        array_ptr->push(trg_location);
      ,
        it.release_location_ptr(array_location);
        return false;
      );
    }
  }/*}}}*/
  else
  {
    switch (src_1_location->v_type)
    {
    case c_bi_class_array:
      {/*{{{*/

        // - retrieve map array -
        pointer_array_s *map_arr_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

        // - process array -
        if (src_0_location->v_type == c_bi_class_array)
        {
          BIC_ALGO_PROCESS_ARRAY(src_0_location,
            BIC_ALGO_METHOD_MAP_MAP_ARRAY();
            array_ptr->push(trg_location);
          );
        }

        // - process iterable -
        else
        {
          BIC_ALGO_PROCESS_ITERABLE(src_0_location,
            BIC_ALGO_METHOD_MAP_MAP_ARRAY(it.release_location_ptr(item_reference););
            array_ptr->push(trg_location);
          ,
            it.release_location_ptr(array_location);
            return false;
          );
        }
      }/*}}}*/
      break;
    case c_bi_class_delegate:
      {/*{{{*/

        // - retrieve delegate pointer -
        delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

        // - ERROR -
        if (delegate_ptr->param_cnt != 1)
        {
          it.release_location_ptr(array_location);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_WRONG_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(1);

          return false;
        }

        // - process array -
        if (src_0_location->v_type == c_bi_class_array)
        {
          BIC_ALGO_PROCESS_ARRAY(src_0_location,
            BIC_ALGO_METHOD_MAP_MAP_DLG();
            array_ptr->push(trg_location);
          );
        }

        // - process iterable -
        else
        {
          BIC_ALGO_PROCESS_ITERABLE(src_0_location,
            BIC_ALGO_METHOD_MAP_MAP_DLG(it.release_location_ptr(item_reference););
            array_ptr->push(trg_location);
          ,
            it.release_location_ptr(array_location);
            return false;
          );
        }
      }/*}}}*/
      break;

    // - ERROR -
    default:
      {
        it.release_location_ptr(array_location);

        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_algo,"map#2");
        new_exception->params.push(2);
        new_exception->params.push(src_0_location->v_type);
        new_exception->params.push(src_1_location->v_type);

        return false;
      }
    }
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_algo_method_reduce_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  if (src_2_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_algo,"reduce#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 2)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_WRONG_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(2);

    return false;
  }

  // - result location -
  src_0_location->v_reference_cnt.atomic_inc();
  location_s *inter_location = src_0_location;

  // - process array -
  if (src_1_location->v_type == c_bi_class_array)
  {
    BIC_ALGO_PROCESS_ARRAY(src_1_location,
      pointer params[2] = {inter_location MP_COMMA item_location};

      // - call delegate method -
      location_s *trg_location = NULL;
      BIC_CALL_DELEGATE(it,delegate_ptr,params,2,trg_location,operands[c_source_pos_idx],
        it.release_location_ptr(inter_location);
        return false;
      );

      it.release_location_ptr(inter_location);
      inter_location = trg_location;
    );
  }

  // - process iterable -
  else
  {
    BIC_ALGO_PROCESS_ITERABLE(src_1_location,
      pointer params[2] = {inter_location MP_COMMA item_location};

      // - call delegate method -
      location_s *trg_location = NULL;
      BIC_CALL_DELEGATE(it,delegate_ptr,params,2,trg_location,operands[c_source_pos_idx],
        it.release_location_ptr(item_reference);
        it.release_location_ptr(inter_location);
        return false;
      );

      it.release_location_ptr(item_reference);
      it.release_location_ptr(inter_location);
      inter_location = trg_location;
    ,
      it.release_location_ptr(inter_location);
      return false;
    );
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(inter_location);

  return true;
}/*}}}*/

bool bic_algo_method_filter_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

#define BIC_ALGO_METHOD_FILTER_MAP_ARRAY(RELEASE_REFERENCE) \
/*{{{*/\
  long long int map_index;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(item_location,map_index))\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_EXPECTED_INTEGER_AS_ARRAY_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(item_location->v_type);\
\
    return false;\
  }\
\
  /* - ERROR - */\
  if (map_index < 0 || map_index >= map_arr_ptr->used)\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_INDEX_EXCEEDS_ARRAY_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(map_index);\
\
    return false;\
  }\
\
  location_s *trg_location = it.get_location_value(map_arr_ptr->data[map_index]);\
  trg_location->v_reference_cnt.atomic_inc();\
/*}}}*/

#define BIC_ALGO_METHOD_FILTER_MAP_DICT(RELEASE_REFERENCE) \
/*{{{*/\
  map_tree_ptr->it_ptr = &it;\
  map_tree_ptr->source_pos = operands[c_source_pos_idx];\
\
  pointer_map_s search_map = {(pointer)item_location MP_COMMA NULL};\
  unsigned index = map_tree_ptr->get_idx(search_map);\
\
  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (index == c_idx_not_exist)\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
\
    exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_UNDEFINED_DICTIONARY_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  location_s *trg_location = it.get_location_value(map_tree_ptr->data[index].object.value);\
  trg_location->v_reference_cnt.atomic_inc();\
/*}}}*/

#define BIC_ALGO_METHOD_FILTER_MAP_DLG(RELEASE_REFERENCE) \
/*{{{*/\
\
  /* - call delegate method - */\
  location_s *trg_location = NULL;\
  BIC_CALL_DELEGATE(it,delegate_ptr,(pointer *)&item_location,1,trg_location,operands[c_source_pos_idx],\
    RELEASE_REFERENCE;\
    it.release_location_ptr(array_location);\
    return false;\
  );\
/*}}}*/

#define BIC_ALGO_METHOD_FILTER_OUT_FILTER(RELEASE_REFERENCE) \
/*{{{*/\
\
  /* - test value - */\
  bool result;\
  if (!it.test_value(trg_location,result))\
  {\
    RELEASE_REFERENCE;\
    it.release_location_ptr(trg_location);\
    it.release_location_ptr(array_location);\
\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(trg_location->v_type);\
\
    return false;\
  }\
\
  it.release_location_ptr(trg_location);\
\
  /* - if test was successfull - */\
  if (result)\
  {\
    item_location->v_reference_cnt.atomic_inc();\
    array_ptr->push(item_location);\
  }\
\
  RELEASE_REFERENCE;\
/*}}}*/

  if (src_1_location->v_type == c_rm_class_dict)
  {/*{{{*/

    // - retrieve map dict -
    pointer_map_tree_s *map_tree_ptr = (pointer_map_tree_s *)src_1_location->v_data_ptr;

    // - process array -
    if (src_0_location->v_type == c_bi_class_array)
    {
      BIC_ALGO_PROCESS_ARRAY(src_0_location,
        BIC_ALGO_METHOD_FILTER_MAP_DICT();
        BIC_ALGO_METHOD_FILTER_OUT_FILTER();
      );
    }

    // - process iterable -
    else
    {
      BIC_ALGO_PROCESS_ITERABLE(src_0_location,
        BIC_ALGO_METHOD_FILTER_MAP_DICT(it.release_location_ptr(item_reference););
        BIC_ALGO_METHOD_FILTER_OUT_FILTER(it.release_location_ptr(item_reference););
      ,
        it.release_location_ptr(array_location);
        return false;
      );
    }
  }/*}}}*/
  else
  {
    switch (src_1_location->v_type)
    {
    case c_bi_class_array:
      {/*{{{*/

        // - retrieve map array -
        pointer_array_s *map_arr_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

        // - process array -
        if (src_0_location->v_type == c_bi_class_array)
        {
          BIC_ALGO_PROCESS_ARRAY(src_0_location,
            BIC_ALGO_METHOD_FILTER_MAP_ARRAY();
            BIC_ALGO_METHOD_FILTER_OUT_FILTER();
          );
        }

        // - process iterable -
        else
        {
          BIC_ALGO_PROCESS_ITERABLE(src_0_location,
            BIC_ALGO_METHOD_FILTER_MAP_ARRAY(it.release_location_ptr(item_reference););
            BIC_ALGO_METHOD_FILTER_OUT_FILTER(it.release_location_ptr(item_reference););
          ,
            it.release_location_ptr(array_location);
            return false;
          );
        }
      }/*}}}*/
      break;
    case c_bi_class_delegate:
      {/*{{{*/

        // - retrieve delegate pointer -
        delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

        // - ERROR -
        if (delegate_ptr->param_cnt != 1)
        {
          it.release_location_ptr(array_location);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_WRONG_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(1);

          return false;
        }

        // - process array -
        if (src_0_location->v_type == c_bi_class_array)
        {
          BIC_ALGO_PROCESS_ARRAY(src_0_location,
            BIC_ALGO_METHOD_FILTER_MAP_DLG();
            BIC_ALGO_METHOD_FILTER_OUT_FILTER();
          );
        }

        // - process iterable -
        else
        {
          BIC_ALGO_PROCESS_ITERABLE(src_0_location,
            BIC_ALGO_METHOD_FILTER_MAP_DLG(it.release_location_ptr(item_reference););
            BIC_ALGO_METHOD_FILTER_OUT_FILTER(it.release_location_ptr(item_reference););
          ,
            it.release_location_ptr(array_location);
            return false;
          );
        }
      }/*}}}*/
      break;

      // - ERROR -
      default:
      {
        it.release_location_ptr(array_location);

        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_algo,"filter#2");
        new_exception->params.push(2);
        new_exception->params.push(src_0_location->v_type);
        new_exception->params.push(src_1_location->v_type);

        return false;
      }
    }
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_algo_method_zip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_algo,"zip#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - create result location -
  pointer_array_s *result_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,result_ptr);

  if (array_ptr->used > 0)
  {
    unsigned iter_cnt = array_ptr->used;
    iterable_s iterables[iter_cnt];

    // - retrieve iterable locations -
    iterable_s *i_ptr = iterables;
    iterable_s *i_ptr_end = i_ptr + iter_cnt;
    pointer *p_ptr = array_ptr->data;
    do {
      // - initialize iterable structure -
      i_ptr->init();

      // - retrieve iterable location and type -
      i_ptr->location = it.get_location_value(*p_ptr);
      i_ptr->type = it.get_iterable_type(i_ptr->location);

      // - ERROR -
      if (i_ptr->type == c_idx_not_exist)
      {
        it.release_location_ptr(array_location);

        exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(i_ptr->location->v_type);

        return false;
      }
    } while(++p_ptr,++i_ptr < i_ptr_end);

    // - retrieve first indexes -
    i_ptr = iterables;
    i_ptr_end = i_ptr + iter_cnt;
    do {
      if (i_ptr->type == c_iter_first_idx_next_idx_item)
      {
        // - retrieve first index -
        BIC_CALL_FIRST_IDX(it,i_ptr->location,i_ptr->index,operands[c_source_pos_idx],
          it.release_location_ptr(array_location);
          return false;
        );
      }
    } while(++i_ptr < i_ptr_end);

#define BIC_ALGO_ZIP_RELEASE_ITERABLES() \
{/*{{{*/\
  iterable_s *i_ptr = iterables;\
  iterable_s *i_ptr_end = i_ptr + iter_cnt;\
  do {\
    i_ptr->clear(it);\
  } while(++i_ptr < i_ptr_end);\
}/*}}}*/

#define BIC_ALGO_ZIP_RELEASE() \
{/*{{{*/\
  BIC_ALGO_ZIP_RELEASE_ITERABLES();\
  it.release_location_ptr(array_location);\
}/*}}}*/

    bool done = false;
    do {
      i_ptr = iterables;
      i_ptr_end = i_ptr + iter_cnt;
      do {
        switch (i_ptr->type)
        {
        case c_iter_first_idx_next_idx_item:
          {
            if (i_ptr->index == c_idx_not_exist)
            {
              // - stop iteration -
              i_ptr = i_ptr_end;
              done = true;
              break;
            }

            // - retrieve item location -
            BIC_CALL_ITEM(it,i_ptr->location,i_ptr->index,i_ptr->item_reference,operands[c_source_pos_idx],
              BIC_ALGO_ZIP_RELEASE();
              return false;
            );

            i_ptr->item_location = it.get_location_value(i_ptr->item_reference);

            // - retrieve next index -
            BIC_CALL_NEXT_IDX(it,i_ptr->location,i_ptr->index,i_ptr->index,operands[c_source_pos_idx],
              BIC_ALGO_ZIP_RELEASE();
              return false;
            );
          }
          break;

        case c_iter_next_item:
          {
            // - retrieve next item location -
            BIC_CALL_NEXT_ITEM(it,i_ptr->location,i_ptr->item_reference,operands[c_source_pos_idx],
              BIC_ALGO_ZIP_RELEASE();
              return false;
            );

            i_ptr->item_location = it.get_location_value(i_ptr->item_reference);

            if (i_ptr->item_location->v_type == c_bi_class_blank)
            {
              // - stop iteration -
              i_ptr = i_ptr_end;
              done = true;
              break;
            }
          }
          break;

        default:
          cassert(0);
        }
      } while(++i_ptr < i_ptr_end);

      // - end of loop -
      if (done)
      {
        break;
      }

      // - push items to result array -
      i_ptr = iterables;
      i_ptr_end = i_ptr + iter_cnt;
      do {

        // - push item to result array -
        i_ptr->item_location->v_reference_cnt.atomic_inc();
        result_ptr->push(i_ptr->item_location);

        // - release item reference -
        it.release_location_ptr(i_ptr->item_reference);
        i_ptr->item_reference = NULL;

      } while(++i_ptr < i_ptr_end);

    } while(true);

    // - release iterables -
    BIC_ALGO_ZIP_RELEASE_ITERABLES();
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

// - class FILTER -
built_in_class_s filter_class =
{/*{{{*/
  "Filter",
  c_modifier_public | c_modifier_final,
  6, filter_methods,
  0, filter_variables,
  bic_filter_consts,
  bic_filter_init,
  bic_filter_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_filter_next_item,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s filter_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_filter_operator_binary_equal
  },
  {
    "map#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_filter_method_map_2
  },
  {
    "filter#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_filter_method_filter_2
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_filter_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_filter_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_filter_method_print_0
  },
};/*}}}*/

built_in_variable_s filter_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_FILTER_NEXT_ITEM_MAP_ARRAY(SOURCE_POS,ERROR_CODE) \
/*{{{*/\
  long long int map_index;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(iter.item_location,map_index))\
  {\
    /* - release item reference - */\
    it.release_location_ptr(iter.item_reference);\
    iter.item_reference = NULL;\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_EXPECTED_INTEGER_AS_ARRAY_INDEX,SOURCE_POS,(location_s *)it.blank_location);\
    new_exception->params.push(iter.item_location->v_type);\
\
    ERROR_CODE;\
  }\
\
  /* - ERROR - */\
  if (map_index < 0 || map_index >= ((pointer_array_s *)map_ptr)->used)\
  {\
    /* - release item reference - */\
    it.release_location_ptr(iter.item_reference);\
    iter.item_reference = NULL;\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_INDEX_EXCEEDS_ARRAY_RANGE,SOURCE_POS,(location_s *)it.blank_location);\
    new_exception->params.push(map_index);\
\
    ERROR_CODE;\
  }\
\
  location_s *trg_location = it.get_location_value(((pointer_array_s *)map_ptr)->data[map_index]);\
  trg_location->v_reference_cnt.atomic_inc();\
/*}}}*/

#define BIC_FILTER_NEXT_ITEM_MAP_DICT(SOURCE_POS,ERROR_CODE) \
/*{{{*/\
  pointer_map_tree_s *map_tree_ptr = (pointer_map_tree_s *)map_ptr;\
\
  map_tree_ptr->it_ptr = &it;\
  map_tree_ptr->source_pos = SOURCE_POS;\
\
  pointer_map_s search_map = {(pointer)iter.item_location MP_COMMA NULL};\
  unsigned index = map_tree_ptr->get_idx(search_map);\
\
  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
  {\
    /* - release item reference - */\
    it.release_location_ptr(iter.item_reference);\
    iter.item_reference = NULL;\
\
    ERROR_CODE;\
  }\
\
  /* - ERROR - */\
  if (index == c_idx_not_exist)\
  {\
    /* - release item reference - */\
    it.release_location_ptr(iter.item_reference);\
    iter.item_reference = NULL;\
\
    exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_UNDEFINED_DICTIONARY_KEY,SOURCE_POS,(location_s *)it.blank_location);\
\
    ERROR_CODE;\
  }\
\
  location_s *trg_location = it.get_location_value(map_tree_ptr->data[index].object.value);\
  trg_location->v_reference_cnt.atomic_inc();\
/*}}}*/

#define BIC_FILTER_NEXT_ITEM_MAP_DELEGATE(SOURCE_POS,ERROR_CODE) \
/*{{{*/\
\
  /* - call delegate method - */\
  location_s *trg_location = NULL;\
  BIC_CALL_DELEGATE(it,((delegate_s *)map_ptr),(pointer *)&iter.item_location,1,trg_location,SOURCE_POS,\
\
    /* - release item reference - */\
    it.release_location_ptr(iter.item_reference);\
    iter.item_reference = NULL;\
\
    ERROR_CODE;\
  );\
/*}}}*/

#define BIC_FILTER_NEXT_ITEM_OUT_MAP(SET_RESULT,SOURCE_POS,ERROR_CODE) \
/*{{{*/\
\
  /* - set result - */\
  SET_RESULT trg_location;\
\
  /* - stop iteration - */\
  done = true;\
/*}}}*/

#define BIC_FILTER_NEXT_ITEM_OUT_FILTER(SET_RESULT,SOURCE_POS,ERROR_CODE) \
/*{{{*/\
\
  /* - test value - */\
  bool result;\
  if (!it.test_value(trg_location,result))\
  {\
    it.release_location_ptr(trg_location);\
\
    /* - release item reference - */\
    it.release_location_ptr(iter.item_reference);\
    iter.item_reference = NULL;\
\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,SOURCE_POS,(location_s *)it.blank_location);\
    new_exception->params.push(trg_location->v_type);\
\
    ERROR_CODE;\
  }\
\
  it.release_location_ptr(trg_location);\
\
  /* - if test was successfull - */\
  if (result)\
  {\
    iter.item_location->v_reference_cnt.atomic_inc();\
\
    /* - set result - */\
    SET_RESULT iter.item_location;\
\
    /* - stop iteration - */\
    done = true;\
  }\
/*}}}*/

#define BIC_FILTER_NEXT_ITEM(SET_RESULT,SOURCE_POS,ERROR_CODE) \
{/*{{{*/\
  void *map_ptr = (void *)filter_ptr->map_loc->v_data_ptr;\
  iterable_s &iter = filter_ptr->iterable;\
\
  bool iter_empty = false;\
  bool done = false;\
\
  do {\
\
    /* - retrieve next value from iterable - */\
    switch (iter.type)\
    {\
      case c_iter_first_idx_next_idx_item:\
        {\
          if (iter.index == c_idx_not_exist)\
          {\
            /* - iterable is empty - */\
            iter_empty = true;\
            break;\
          }\
\
          /* - retrieve item location - */\
          BIC_CALL_ITEM(it,iter.location,iter.index,iter.item_reference,SOURCE_POS,ERROR_CODE);\
\
          iter.item_location = it.get_location_value(iter.item_reference);\
\
          /* - retrieve next index - */\
          BIC_CALL_NEXT_IDX(it,iter.location,iter.index,iter.index,SOURCE_POS,ERROR_CODE);\
        }\
        break;\
      case c_iter_next_item:\
        {\
          /* - retrieve next item location - */\
          BIC_CALL_NEXT_ITEM(it,iter.location,iter.item_reference,SOURCE_POS,ERROR_CODE);\
\
          iter.item_location = it.get_location_value(iter.item_reference);\
\
          if (iter.item_location->v_type == c_bi_class_blank)\
          {\
            /* - release item reference - */\
            it.release_location_ptr(iter.item_reference);\
            iter.item_reference = NULL;\
\
            /* - iterable is empty - */\
            iter_empty = true;\
            break;\
          }\
        }\
        break;\
    }\
\
    /* - if there are no data in iterable - */\
    if (iter_empty)\
    {\
      /* - set blank result - */\
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
      SET_RESULT (location_s *)it.blank_location;\
\
      /* - stop iteration - */\
      done = true;\
    }\
    else\
    {\
      switch (filter_ptr->type)\
      {\
        case c_filter_type_array_map:\
          {\
            BIC_FILTER_NEXT_ITEM_MAP_ARRAY(SOURCE_POS,ERROR_CODE);\
            BIC_FILTER_NEXT_ITEM_OUT_MAP(SET_RESULT,SOURCE_POS,ERROR_CODE);\
          }\
          break;\
        case c_filter_type_array_filter:\
          {\
            BIC_FILTER_NEXT_ITEM_MAP_ARRAY(SOURCE_POS,ERROR_CODE);\
            BIC_FILTER_NEXT_ITEM_OUT_FILTER(SET_RESULT,SOURCE_POS,ERROR_CODE);\
          }\
          break;\
        case c_filter_type_dict_map:\
          {\
            BIC_FILTER_NEXT_ITEM_MAP_DICT(SOURCE_POS,ERROR_CODE);\
            BIC_FILTER_NEXT_ITEM_OUT_MAP(SET_RESULT,SOURCE_POS,ERROR_CODE);\
          }\
          break;\
        case c_filter_type_dict_filter:\
          {\
            BIC_FILTER_NEXT_ITEM_MAP_DICT(SOURCE_POS,ERROR_CODE);\
            BIC_FILTER_NEXT_ITEM_OUT_FILTER(SET_RESULT,SOURCE_POS,ERROR_CODE);\
          }\
          break;\
        case c_filter_type_dlg_map:\
          {\
            BIC_FILTER_NEXT_ITEM_MAP_DELEGATE(SOURCE_POS,ERROR_CODE);\
            BIC_FILTER_NEXT_ITEM_OUT_MAP(SET_RESULT,SOURCE_POS,ERROR_CODE);\
          }\
          break;\
        case c_filter_type_dlg_filter:\
          {\
            BIC_FILTER_NEXT_ITEM_MAP_DELEGATE(SOURCE_POS,ERROR_CODE);\
            BIC_FILTER_NEXT_ITEM_OUT_FILTER(SET_RESULT,SOURCE_POS,ERROR_CODE);\
          }\
          break;\
        default:\
          cassert(0);\
      }\
\
      /* - release item reference - */\
      it.release_location_ptr(iter.item_reference);\
      iter.item_reference = NULL;\
    }\
  } while(!done);\
}/*}}}*/

#define BIC_FILTER_METHODS_MAP_FILTER(TYPE) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);\
\
  unsigned filter_type;\
\
  if (src_1_location->v_type == c_rm_class_dict)\
  {\
    /* set filter type */\
    filter_type = c_filter_type_dict_ ## TYPE;\
  }\
  else\
  {\
    switch (src_1_location->v_type)\
    {\
      case c_bi_class_array:\
        {\
          /* set filter type */\
          filter_type = c_filter_type_array_ ## TYPE;\
        }\
        break;\
      case c_bi_class_delegate:\
        {/*{{{*/\
\
          /* - retrieve delegate pointer - */\
          delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;\
\
          /* - ERROR - */\
          if (delegate_ptr->param_cnt != 1)\
          {\
            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ALGO_FILTER_WRONG_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
            new_exception->params.push(1);\
\
            return false;\
          }\
\
          /* set filter type */\
          filter_type = c_filter_type_dlg_ ## TYPE;\
        }/*}}}*/\
        break;\
      default:\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_filter,#TYPE "#2");\
        new_exception->params.push(2);\
        new_exception->params.push(src_0_location->v_type);\
        new_exception->params.push(src_1_location->v_type);\
\
        return false;\
      }\
    }\
  }\
\
  /* - retrieve iterable type - */\
  unsigned iter_type = it.get_iterable_type(src_0_location);\
\
  /* - ERROR - */\
  if (iter_type == c_idx_not_exist)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  /* - create new filter object - */\
  filter_s *filter_ptr = (filter_s *)cmalloc(sizeof(filter_s));\
  filter_ptr->init();\
\
  /* - set filter type - */\
  filter_ptr->type = filter_type;\
\
  /* - set map location - */\
  src_1_location->v_reference_cnt.atomic_inc();\
  filter_ptr->map_loc = src_1_location;\
\
  /* - retrieve iterable location - */\
  iterable_s &iter = filter_ptr->iterable;\
  iter.location = it.get_location_value(src_0_location);\
  iter.location->v_reference_cnt.atomic_inc();\
\
  /* - set iterable type - */\
  iter.type = iter_type;\
\
  /* - create result location - */\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_filter,filter_ptr);\
  BIC_SET_RESULT(new_location);\
\
  if (iter_type == c_iter_first_idx_next_idx_item)\
  {\
    /* - retrieve first index - */\
    BIC_CALL_FIRST_IDX(it,iter.location,iter.index,operands[c_source_pos_idx],return false;);\
  }\
\
  return true;\
}/*}}}*/

void bic_filter_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_filter_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_filter_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  filter_s *filter_ptr = (filter_s *)location_ptr->v_data_ptr;

  // - if filter exist -
  if (filter_ptr != NULL)
  {
    filter_ptr->clear(it);
    cfree(filter_ptr);
  }
}/*}}}*/

location_s *bic_filter_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/
  filter_s *filter_ptr = (filter_s *)location_ptr->v_data_ptr;

  location_s *return_location;
  BIC_FILTER_NEXT_ITEM(return_location = ,source_pos,return NULL);

  return return_location;
}/*}}}*/

bool bic_filter_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_filter_method_map_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FILTER_METHODS_MAP_FILTER(map);
}/*}}}*/

bool bic_filter_method_filter_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FILTER_METHODS_MAP_FILTER(filter);
}/*}}}*/

bool bic_filter_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  filter_s *filter_ptr = (filter_s *)dst_location->v_data_ptr;

  BIC_FILTER_NEXT_ITEM(
    pointer &res_location = it.data_stack[res_loc_idx];
    it.release_location_ptr((location_s *)res_location);
    res_location = 
  ,operands[c_source_pos_idx],return false;);

  return true;
}/*}}}*/

bool bic_filter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Filter"),"Filter");
  );

  return true;
}/*}}}*/

bool bic_filter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Filter");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class RANGE -
built_in_class_s range_class =
{/*{{{*/
  "Range",
  c_modifier_public | c_modifier_final,
  6, range_methods,
  0, range_variables,
  bic_range_consts,
  bic_range_init,
  bic_range_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_range_next_item,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s range_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_range_operator_binary_equal
  },
  {
    "Range#2",
    c_modifier_public | c_modifier_final,
    bic_range_method_Range_2
  },
  {
    "Range#3",
    c_modifier_public | c_modifier_final,
    bic_range_method_Range_3
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_range_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_range_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_range_method_print_0
  }
};/*}}}*/

built_in_variable_s range_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_RANGE_NEXT_ITEM(SET_RESULT,SOURCE_POS,ERROR_CODE) \
{/*{{{*/\
  uli *tmp_code = range_ptr->tmp_code;\
\
  /* - retrieve next value - */\
  {\
    unsigned new_stack_base = it.data_stack.used;\
\
    /* - push this location on stack - */\
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
    it.data_stack.push(it.blank_location);\
\
    /* - push first parameter on stack - */\
    location_s *location = (location_s *)(range_ptr->actual_location);\
    location->v_reference_cnt.atomic_inc();\
    it.data_stack.push((pointer)location);\
\
    if (range_ptr->step_location != NULL)\
    {\
      /* - push second parameter on stack - */\
      location_s *src_location = (location_s *)(range_ptr->step_location);\
      src_location->v_reference_cnt.atomic_inc();\
      it.data_stack.push((pointer)src_location);\
    }\
\
    /* - set source position in temporary code - */\
    tmp_code[icl_source_pos] = SOURCE_POS;\
\
    /* - test if caller address for built in class is stored - */\
    if (tmp_code[icl_last_class] == range_ptr->actual_location->v_type)\
    {\
      /* - call built in method - */\
      if (!((bi_method_caller_dt)(tmp_code[icl_last_bi_mc]))(it,new_stack_base,tmp_code + icl_source_pos))\
      {\
        it.release_stack_from(new_stack_base);\
        ERROR_CODE;\
      }\
    }\
    else\
    {\
      /* - proper call of method - */\
      if (!it.call_method(tmp_code,new_stack_base))\
      {\
        it.release_stack_from(new_stack_base);\
        ERROR_CODE;\
      }\
    }\
\
    /* - get result value - */\
    location_s *ret_location = (location_s *)it.data_stack[new_stack_base];\
    ret_location->v_reference_cnt.atomic_inc();\
\
    /* - get original value - */\
    location_s *this_location = (location_s *)it.data_stack[new_stack_base + 1];\
    this_location->v_reference_cnt.atomic_inc();\
\
    if (range_ptr->step_location == NULL)\
    {\
      it.release_location_ptr(range_ptr->actual_location);\
      range_ptr->actual_location = this_location;\
\
      SET_RESULT ret_location;\
    }\
    else\
    {\
      it.release_location_ptr(range_ptr->actual_location);\
      range_ptr->actual_location = ret_location;\
\
      SET_RESULT this_location;\
    }\
\
    it.release_stack_from(new_stack_base);\
  }\
\
  /* - compare actual value with end value - */\
  long long int result;\
  BIC_CALL_COMPARE(it,range_ptr->actual_location,range_ptr->end_location,SOURCE_POS,ERROR_CODE);\
\
  /* - if actual value is greater than end value - */\
  if ((range_ptr->type == c_range_type_ascending) ? result > 0 : result < 0)\
  {\
    it.release_location_ptr(range_ptr->actual_location);\
    range_ptr->actual_location = NULL;\
  }\
}/*}}}*/

void bic_range_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_range_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_range_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  range_s *range_ptr = (range_s *)location_ptr->v_data_ptr;

  // - if range exist -
  if (range_ptr != NULL)
  {
    range_ptr->clear(it);
    cfree(range_ptr);
  }
}/*}}}*/

location_s *bic_range_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/
  range_s *range_ptr = (range_s *)location_ptr->v_data_ptr;

  if (range_ptr->actual_location == NULL)
  {
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return ((location_s *)it.blank_location);
  }
  else
  {
    location_s *return_location;
    BIC_RANGE_NEXT_ITEM(return_location = ,source_pos,return NULL);

    return return_location;
  }
}/*}}}*/

bool bic_range_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_range_method_Range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != src_1_location->v_type)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RANGE_START_END_TYPES_DIFFERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result;
  BIC_CALL_COMPARE(it,src_0_location,src_1_location,operands[c_source_pos_idx],return false);

  // - create range object -
  range_s *range_ptr = (range_s *)cmalloc(sizeof(range_s));
  range_ptr->init();

  src_0_location->v_reference_cnt.atomic_add(2);
  range_ptr->start_location = src_0_location;
  range_ptr->actual_location = src_0_location;

  src_1_location->v_reference_cnt.atomic_inc();
  range_ptr->end_location = src_1_location;

  uli *tmp_code = range_ptr->tmp_code;
  tmp_code[0] = i_call;
  tmp_code[1] = 1;

  if (result <= 0)
  {
    range_ptr->type = c_range_type_ascending;
    tmp_code[2] = c_built_in_method_idxs[c_operator_unary_post_double_plus];
  }
  else
  {
    range_ptr->type = c_range_type_descending;
    tmp_code[2] = c_built_in_method_idxs[c_operator_unary_post_double_minus];
  }

  tmp_code[3] = c_idx_not_exist;
  tmp_code[4] = c_idx_not_exist;
  tmp_code[5] = 0;
  tmp_code[6] = 0;
  tmp_code[7] = 1;

  // - set object pointer to result -
  dst_location->v_data_ptr = (basic_64b)range_ptr;

  return true;
}/*}}}*/

bool bic_range_method_Range_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != src_1_location->v_type)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RANGE_START_END_TYPES_DIFFERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result;
  BIC_CALL_COMPARE(it,src_0_location,src_1_location,operands[c_source_pos_idx],return false);

  // - create range object -
  range_s *range_ptr = (range_s *)cmalloc(sizeof(range_s));
  range_ptr->init();

  range_ptr->type = result <= 0 ? c_range_type_ascending : c_range_type_descending;

  src_0_location->v_reference_cnt.atomic_add(2);
  range_ptr->start_location = src_0_location;
  range_ptr->actual_location = src_0_location;

  src_1_location->v_reference_cnt.atomic_inc();
  range_ptr->end_location = src_1_location;

  src_2_location->v_reference_cnt.atomic_inc();
  range_ptr->step_location = src_2_location;

  uli *tmp_code = range_ptr->tmp_code;
  tmp_code[0] = i_call;
  tmp_code[1] = 2;
  tmp_code[2] = c_built_in_method_idxs[c_operator_binary_plus];
  tmp_code[3] = c_idx_not_exist;
  tmp_code[4] = c_idx_not_exist;
  tmp_code[5] = 0;
  tmp_code[6] = 0;
  tmp_code[7] = 1;
  tmp_code[8] = 2;

  // - set object pointer to result -
  dst_location->v_data_ptr = (basic_64b)range_ptr;

  return true;
}/*}}}*/

bool bic_range_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  range_s *range_ptr = (range_s *)dst_location->v_data_ptr;

  if (range_ptr->actual_location == NULL)
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    BIC_RANGE_NEXT_ITEM(
      pointer &res_location = it.data_stack[res_loc_idx];
      it.release_location_ptr((location_s *)res_location);
      res_location = 
    ,operands[c_source_pos_idx],return false);
  }

  return true;
}/*}}}*/

bool bic_range_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Range"),"Range")
  );

  return true;
}/*}}}*/

bool bic_range_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Range");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

