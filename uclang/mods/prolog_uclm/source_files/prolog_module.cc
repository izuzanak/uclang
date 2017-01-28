
@begin
include "prolog_module.h"
@end

// - PROLOG indexes of built in classes -
unsigned c_bi_class_prolog_context = c_idx_not_exist;

// - PROLOG indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - PROLOG module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  prolog_classes,          // Classes

  0,                     // Error base index
  1,                     // Error count
  prolog_error_strings,    // Error strings

  prolog_initialize,       // Initialize function
  prolog_print_exception,  // Print exceptions function
};/*}}}*/

// - PROLOG classes -
built_in_class_s *prolog_classes[] =
{/*{{{*/
  &prolog_context_class,
};/*}}}*/

// - PROLOG error strings -
const char *prolog_error_strings[] =
{/*{{{*/
  "error_PROLOG_DUMMY_ERROR",
};/*}}}*/

// - PROLOG initialize -
bool prolog_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize prolog_context class identifier -
  c_bi_class_prolog_context = class_base_idx++;

  return true;
}/*}}}*/

// - PROLOG print exception -
bool prolog_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PROLOG_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProlog dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class PROLOG_CONTEXT -
built_in_class_s prolog_context_class =
{/*{{{*/
  "PrologContext",
  c_modifier_public | c_modifier_final,
  4, prolog_context_methods,
  0, prolog_context_variables,
  bic_prolog_context_consts,
  bic_prolog_context_init,
  bic_prolog_context_clear,
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

built_in_method_s prolog_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_context_operator_binary_equal
  },
  {
    "PrologContext#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_context_method_PrologContext_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_context_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_context_variables[] =
{/*{{{*/
};/*}}}*/

void bic_prolog_context_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

void bic_prolog_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

bool bic_prolog_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_context_method_PrologContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  
  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_prolog_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologContext"),"PrologContext");
  );

  return true;
}/*}}}*/

bool bic_prolog_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PrologContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

