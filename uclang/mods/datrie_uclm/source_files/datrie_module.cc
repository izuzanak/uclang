
@begin
include "datrie_module.h"
@end

// - DATRIE indexes of built in classes -
unsigned c_bi_class_datrie = c_idx_not_exist;

// - DATRIE module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  datrie_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  datrie_error_strings,   // Error strings

  datrie_initialize,      // Initialize function
  datrie_print_exception, // Print exceptions function
};/*}}}*/

// - DATRIE classes -
built_in_class_s *datrie_classes[] =
{/*{{{*/
  &datrie_class,
};/*}}}*/

// - DATRIE error strings -
const char *datrie_error_strings[] =
{/*{{{*/
  "error_DATRIE_DUMMY_ERROR",
};/*}}}*/

// - DATRIE initialize -
bool datrie_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize datrie class identifier -
  c_bi_class_datrie = class_base_idx++;

  return true;
}/*}}}*/

// - DATRIE print exception -
bool datrie_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_DATRIE_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDaTrie dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DATRIE -
built_in_class_s datrie_class =
{/*{{{*/
  "DaTrie",
  c_modifier_public | c_modifier_final,
  3, datrie_methods,
  0, datrie_variables,
  bic_datrie_consts,
  bic_datrie_init,
  bic_datrie_clear,
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

built_in_method_s datrie_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_method_print_0
  },
};/*}}}*/

built_in_variable_s datrie_variables[] =
{/*{{{*/
};/*}}}*/

void bic_datrie_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_datrie_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  
  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

void bic_datrie_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  
  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

bool bic_datrie_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_datrie_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DaTrie"),"DaTrie");
  );

  return true;
}/*}}}*/

bool bic_datrie_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("DaTrie");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

