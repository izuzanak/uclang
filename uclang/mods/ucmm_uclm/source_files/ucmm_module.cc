
@begin
include "ucmm_module.h"
@end

// - UCMM indexes of built in classes -
unsigned c_bi_class_modem_manager = c_idx_not_exist;

// - UCMM module -
built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  ucmm_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  ucmm_error_strings,   // Error strings

  ucmm_initialize,      // Initialize function
  ucmm_print_exception, // Print exceptions function
};/*}}}*/

// - UCMM classes -
built_in_class_s *ucmm_classes[] =
{/*{{{*/
  &modem_manager_class,
};/*}}}*/

// - UCMM error strings -
const char *ucmm_error_strings[] =
{/*{{{*/
  "error_UCMM_DUMMY_ERROR",
};/*}}}*/

// - UCMM initialize -
bool ucmm_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize modem_manager class identifier -
  c_bi_class_modem_manager = class_base_idx++;

  return true;
}/*}}}*/

// - UCMM print exception -
bool ucmm_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_UCMM_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUC modem manager dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class MODEM_MANAGER -
built_in_class_s modem_manager_class =
{/*{{{*/
  "ModemManager",
  c_modifier_public | c_modifier_final,
  4, modem_manager_methods,
  0, modem_manager_variables,
  bic_modem_manager_consts,
  bic_modem_manager_init,
  bic_modem_manager_clear,
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

built_in_method_s modem_manager_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_operator_binary_equal
  },
  {
    "ModemManager#1",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_method_ModemManager_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_modem_manager_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_modem_manager_method_print_0
  },
};/*}}}*/

built_in_variable_s modem_manager_variables[] =
{/*{{{*/
};/*}}}*/

void bic_modem_manager_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_modem_manager_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_modem_manager_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ModemManager *mm_ptr = (ModemManager *)location_ptr->v_data_ptr;

  if (mm_ptr != NULL)
  {
    mm_ptr->Close();

    delete mm_ptr;
  }
}/*}}}*/

bool bic_modem_manager_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_modem_manager_method_ModemManager_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // FIXME TODO continue ...
  cassert(0);

  return true;
}/*}}}*/

bool bic_modem_manager_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ModemManager"),"ModemManager");
  );

  return true;
}/*}}}*/

bool bic_modem_manager_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ModemManager");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

