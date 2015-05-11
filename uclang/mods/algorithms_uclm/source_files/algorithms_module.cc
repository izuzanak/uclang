
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
  "error_ALGO_DUMMY_ERROR",
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
  case c_error_ALGO_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAlgorithms dummy error\n");
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
  2, algo_methods,
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

