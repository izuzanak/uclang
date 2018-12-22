
@begin
include "node_module.h"
@end

// - NODE indexes of built in classes -
unsigned c_bi_class_node_callback = c_idx_not_exist;

// - NODE module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  node_classes,          // Classes

  0,                     // Error base index
  2,                     // Error count
  node_error_strings,    // Error strings

  node_initialize,       // Initialize function
  node_print_exception,  // Print exceptions function
};/*}}}*/

// - NODE classes -
built_in_class_s *node_classes[] =
{/*{{{*/
  &node_callback_class,
};/*}}}*/

// - NODE error strings -
const char *node_error_strings[] =
{/*{{{*/
  "error_NODE_CALLBACK_MAX_PARAM_COUNT_EXCEEDED",
  "error_NODE_CALLBACK_WRONG_PARAM_COUNT",
};/*}}}*/

// - NODE initialize -
bool node_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize node_callback class identifier -
  c_bi_class_node_callback = class_base_idx++;

  return true;
}/*}}}*/

// - NODE print exception -
bool node_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_NODE_CALLBACK_MAX_PARAM_COUNT_EXCEEDED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExceeded maximal count of callback paramaeters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NODE_CALLBACK_WRONG_PARAM_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong parameter count, expected %" HOST_LL_FORMAT "d parameters\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class NODE_CALLBACK -
built_in_class_s node_callback_class =
{/*{{{*/
  "NodeCallback",
  c_modifier_public | c_modifier_final,
  7, node_callback_methods,
  0, node_callback_variables,
  bic_node_callback_consts,
  bic_node_callback_init,
  bic_node_callback_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s node_callback_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_node_callback_operator_binary_equal
  },
  {
    "NodeCallback#2",
    c_modifier_public | c_modifier_final,
    bic_node_callback_method_NodeCallback_2
  },
  {
    "call#0",
    c_modifier_public | c_modifier_final,
    bic_node_callback_method_call_0
  },
  {
    "call#1",
    c_modifier_public | c_modifier_final,
    bic_node_callback_method_call_1
  },
  {
    "call#2",
    c_modifier_public | c_modifier_final,
    bic_node_callback_method_call_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_node_callback_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_node_callback_method_print_0
  },
};/*}}}*/

built_in_variable_s node_callback_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_node_callback_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_node_callback_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (node_callback_s *)nullptr;
}/*}}}*/

void bic_node_callback_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  node_callback_s *nc_ptr = (node_callback_s *)location_ptr->v_data_ptr;

  // - if session exists -
  if (nc_ptr != nullptr)
  {
    nc_ptr->clear(it);
    cfree(nc_ptr);
  }
}/*}}}*/

bool bic_node_callback_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_node_callback_method_NodeCallback_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
callback_ptr:c_bi_class_integer
param_cnt:retrieve_integer
>
method NodeCallback
; @end

  // - ERROR -
  if (param_cnt > c_node_callback_max_param)
  {
    exception_s::throw_exception(it,module.error_base + c_error_NODE_CALLBACK_MAX_PARAM_COUNT_EXCEEDED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create new node callback object -
  node_callback_s *nc_ptr = (node_callback_s *)cmalloc(sizeof(node_callback_s));
  nc_ptr->init();

  // - set node callback properties -
  nc_ptr->callback_ptr = (void *)src_0_location->v_data_ptr;
  nc_ptr->param_cnt = param_cnt;

  dst_location->v_data_ptr = (node_callback_s *)nc_ptr;

  return true;
}/*}}}*/

bool bic_node_callback_method_call_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  node_callback_s *nc_ptr = (node_callback_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (nc_ptr->param_cnt != 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_NODE_CALLBACK_WRONG_PARAM_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);

    return false;
  }

  // - call C/C++ callback -
  UclVar result = ((t_node_callback_0)nc_ptr->callback_ptr)();

  // - retrieve result location -
  location_s *result_loc = result.location_ptr;
  result_loc->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(result_loc);

  return true;
}/*}}}*/

bool bic_node_callback_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  node_callback_s *nc_ptr = (node_callback_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (nc_ptr->param_cnt != 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_NODE_CALLBACK_WRONG_PARAM_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);

    return false;
  }

  src_0_location->v_reference_cnt.atomic_inc();

  // - call C/C++ callback -
  UclVar result = ((t_node_callback_1)nc_ptr->callback_ptr)(UclVar(&src_0_location));

  it.release_location_ptr(src_0_location);

  // - retrieve result location -
  location_s *result_loc = result.location_ptr;
  result_loc->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(result_loc);

  return true;
}/*}}}*/

bool bic_node_callback_method_call_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  node_callback_s *nc_ptr = (node_callback_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (nc_ptr->param_cnt != 2)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_NODE_CALLBACK_WRONG_PARAM_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(2);

    return false;
  }

  src_0_location->v_reference_cnt.atomic_inc();
  src_1_location->v_reference_cnt.atomic_inc();

  // - call C/C++ callback -
  UclVar result = ((t_node_callback_2)nc_ptr->callback_ptr)(
    UclVar(&src_0_location),
    UclVar(&src_1_location));

  it.release_location_ptr(src_0_location);
  it.release_location_ptr(src_1_location);

  // - retrieve result location -
  location_s *result_loc = result.location_ptr;
  result_loc->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(result_loc);

  return true;
}/*}}}*/

bool bic_node_callback_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NodeCallback"),"NodeCallback");
  );

  return true;
}/*}}}*/

bool bic_node_callback_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NodeCallback");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

