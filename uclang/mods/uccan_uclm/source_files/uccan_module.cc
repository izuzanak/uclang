
@begin
include "uccan_module.h"
@end

// - UCCAN indexes of built in classes -
unsigned c_bi_class_traffic_store = c_idx_not_exist;

// - UCCAN module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  uccan_classes,         // Classes

  0,                     // Error base index
  1,                     // Error count
  uccan_error_strings,   // Error strings

  uccan_initialize,      // Initialize function
  uccan_print_exception, // Print exceptions function
};/*}}}*/

// - UCCAN classes -
built_in_class_s *uccan_classes[] =
{/*{{{*/
  &traffic_store_class,
};/*}}}*/

// - UCCAN error strings -
const char *uccan_error_strings[] =
{/*{{{*/
  "error_CAN_DUMMY_ERROR",
};/*}}}*/

// - UCCAN initialize -
bool uccan_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize traffic_store class identifier -
  c_bi_class_traffic_store = class_base_idx++;

  return true;
}/*}}}*/

// - UCCAN print exception -
bool uccan_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_CAN_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCAN dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRAFFIC_STORE -
built_in_class_s traffic_store_class =
{/*{{{*/
  "TrafficStore",
  c_modifier_public | c_modifier_final,
  4, traffic_store_methods,
  0, traffic_store_variables,
  bic_traffic_store_consts,
  bic_traffic_store_init,
  bic_traffic_store_clear,
  NULL,
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

built_in_method_s traffic_store_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_operator_binary_equal
  },
  {
    "TrafficStore#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_method_TrafficStore_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_traffic_store_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_traffic_store_method_print_0
  },
};/*}}}*/

built_in_variable_s traffic_store_variables[] =
{/*{{{*/
};/*}}}*/

void bic_traffic_store_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_traffic_store_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = 0LL;
}/*}}}*/

void bic_traffic_store_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_traffic_store_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_traffic_store_method_TrafficStore_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_traffic_store_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrafficStore"),"TrafficStore")
  );

  return true;
}/*}}}*/

bool bic_traffic_store_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("TrafficStore");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

