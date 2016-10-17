
@begin
include "pigpio_module.h"
@end

// - PIGPIO indexes of built in classes -
unsigned c_bi_class_pigpio = c_idx_not_exist;

// - PIGPIO module -
built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  pigpio_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  pigpio_error_strings,   // Error strings

  pigpio_initialize,      // Initialize function
  pigpio_print_exception, // Print exceptions function
};/*}}}*/

// - PIGPIO classes -
built_in_class_s *pigpio_classes[] =
{/*{{{*/
  &pigpio_class,
};/*}}}*/

// - PIGPIO error strings -
const char *pigpio_error_strings[] =
{/*{{{*/
  "error_PIGPIO_DUMMY_ERROR",
};/*}}}*/

// - PIGPIO initialize -
bool pigpio_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize pigpio class identifier -
  c_bi_class_pigpio = class_base_idx++;

  return true;
}/*}}}*/

// - PIGPIO print exception -
bool pigpio_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_PIGPIO_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPiGpio dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class PIGPIO -
built_in_class_s pigpio_class =
{/*{{{*/
  "PiGpio",
  c_modifier_public | c_modifier_final,
  2, pigpio_methods,
  0, pigpio_variables,
  bic_pigpio_consts,
  bic_pigpio_init,
  bic_pigpio_clear,
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

built_in_method_s pigpio_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pigpio_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pigpio_method_print_0
  },
};/*}}}*/

built_in_variable_s pigpio_variables[] =
{/*{{{*/
};/*}}}*/

void bic_pigpio_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pigpio_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_pigpio_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_pigpio_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PiGpio"),"PiGpio");
  );

  return true;
}/*}}}*/

bool bic_pigpio_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PiGpio");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

