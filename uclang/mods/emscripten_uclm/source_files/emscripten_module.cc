
@begin
include "emscripten_module.h"
@end

// - EMSCRIPTEN indexes of built in classes -
unsigned c_bi_class_emscripten = c_idx_not_exist;

// - EMSCRIPTEN module -
built_in_module_s module =
{/*{{{*/
  1,                          // Class count
  emscripten_classes,         // Classes

  0,                          // Error base index
  1,                          // Error count
  emscripten_error_strings,   // Error strings

  emscripten_initialize,      // Initialize function
  emscripten_print_exception, // Print exceptions function
};/*}}}*/

// - EMSCRIPTEN classes -
built_in_class_s *emscripten_classes[] =
{/*{{{*/
  &emscripten_class,
};/*}}}*/

// - EMSCRIPTEN error strings -
const char *emscripten_error_strings[] =
{/*{{{*/
  "error_EMSCRIPTEN_DUMMY_ERROR",
};/*}}}*/

// - EMSCRIPTEN initialize -
bool emscripten_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize emscripten class identifier -
  c_bi_class_emscripten = class_base_idx++;

  return true;
}/*}}}*/

// - EMSCRIPTEN print exception -
bool emscripten_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_EMSCRIPTEN_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEmscripten dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class EMSCRIPTEN -
built_in_class_s emscripten_class =
{/*{{{*/
  "Emscripten",
  c_modifier_public | c_modifier_final,
  2, emscripten_methods,
  0, emscripten_variables,
  bic_emscripten_consts,
  bic_emscripten_init,
  bic_emscripten_clear,
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

built_in_method_s emscripten_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_emscripten_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_emscripten_method_print_0
  },
};/*}}}*/

built_in_variable_s emscripten_variables[] =
{/*{{{*/
};/*}}}*/

void bic_emscripten_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_emscripten_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_emscripten_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_emscripten_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Emscripten"),"Emscripten");
  );

  return true;
}/*}}}*/

bool bic_emscripten_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Emscripten");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/
