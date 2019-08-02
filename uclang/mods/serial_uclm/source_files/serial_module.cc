
@begin
include "serial_module.h"
@end

// - SERIAL indexes of built in classes -
unsigned c_bi_class_serial = c_idx_not_exist;

// - SERIAL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  serial_classes,         // Classes
  0,                     // Error base index
  1,                     // Error count
  serial_error_strings,   // Error strings
  serial_initialize,      // Initialize function
  serial_print_exception, // Print exceptions function
};/*}}}*/

// - SERIAL classes -
built_in_class_s *serial_classes[] =
{/*{{{*/
  &serial_class,
};/*}}}*/

// - SERIAL error strings -
const char *serial_error_strings[] =
{/*{{{*/
  "error_SERIAL_DUMMY_ERROR",
};/*}}}*/

// - SERIAL initialize -
bool serial_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize serial class identifier -
  c_bi_class_serial = class_base_idx++;

  return true;
}/*}}}*/

// - SERIAL print exception -
bool serial_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SERIAL_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSerial dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class SERIAL -
built_in_class_s serial_class =
{/*{{{*/
  "Serial",
  c_modifier_public | c_modifier_final,
  4, serial_methods,
  3 + 3, serial_variables,
  bic_serial_consts,
  bic_serial_init,
  bic_serial_clear,
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

built_in_method_s serial_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_serial_operator_binary_equal
  },
  {
    "Serial#1",
    c_modifier_public | c_modifier_final,
    bic_serial_method_Serial_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_serial_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_serial_method_print_0
  },
};/*}}}*/

built_in_variable_s serial_variables[] =
{/*{{{*/

  // - serial flow control constants -
  { "FC_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FC_RTS_CTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FC_RS_485", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - serial parity constants -
  { "PAR_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PAR_EVEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PAR_ODD", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_serial_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert serial flow control constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(c_serial_FC_NONE);
    CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(c_serial_FC_RTS_CTS);
    CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(c_serial_FC_RS_485);
  }

  // - insert serial parity constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_SERIAL_PARITY_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SERIAL_PARITY_BIC_STATIC(c_serial_PAR_NONE);
    CREATE_SERIAL_PARITY_BIC_STATIC(c_serial_PAR_EVEN);
    CREATE_SERIAL_PARITY_BIC_STATIC(c_serial_PAR_ODD);
  }

}/*}}}*/

void bic_serial_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_serial_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_serial_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_serial_method_Serial_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_serial_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Serial"),"Serial")
  );

  return true;
}/*}}}*/

bool bic_serial_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Serial");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

