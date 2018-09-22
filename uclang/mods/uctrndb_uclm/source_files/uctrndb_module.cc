
@begin
include "uctrndb_module.h"
@end

// - UCTRNDB indexes of built in classes -
unsigned c_bi_class_trndb_client = c_idx_not_exist;

// - UCTRNDB module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  uctrndb_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  uctrndb_error_strings,   // Error strings

  uctrndb_initialize,      // Initialize function
  uctrndb_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRNDB classes -
built_in_class_s *uctrndb_classes[] =
{/*{{{*/
  &trndb_client_class,
};/*}}}*/

// - UCTRNDB error strings -
const char *uctrndb_error_strings[] =
{/*{{{*/
  "error_TRNDB_DUMMY_ERROR",
};/*}}}*/

// - UCTRNDB initialize -
bool uctrndb_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trndb_client class identifier -
  c_bi_class_trndb_client = class_base_idx++;

  return true;
}/*}}}*/

// - UCTRNDB print exception -
bool uctrndb_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TRNDB_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRNDB dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRNDB_CLIENT -
built_in_class_s trndb_client_class =
{/*{{{*/
  "TrndbClient",
  c_modifier_public | c_modifier_final,
  4, trndb_client_methods,
  0, trndb_client_variables,
  bic_trndb_client_consts,
  bic_trndb_client_init,
  bic_trndb_client_clear,
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

built_in_method_s trndb_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_operator_binary_equal
  },
  {
    "TrndbClient#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_TrndbClient_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_client_method_print_0
  },
};/*}}}*/

built_in_variable_s trndb_client_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trndb_client_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trndb_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TrnDb::OpTrnDbProxy *)nullptr;
}/*}}}*/

void bic_trndb_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TrnDb::OpTrnDbProxy *ftdp_ptr = (TrnDb::OpTrnDbProxy *)location_ptr->v_data_ptr;

  if (ftdp_ptr != nullptr)
  {
    delete ftdp_ptr;
  }
}/*}}}*/

bool bic_trndb_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trndb_client_method_TrndbClient_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_trndb_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrndbClient"),"TrndbClient");
  );

  return true;
}/*}}}*/

bool bic_trndb_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrndbClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

