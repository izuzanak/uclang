
@begin
include "curses_module.h"
@end

// - CURSES indexes of built in classes -
unsigned c_bi_class_curses = c_idx_not_exist;

// - CURSES module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  curses_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  curses_error_strings,   // Error strings

  curses_initialize,      // Initialize function
  curses_print_exception, // Print exceptions function
};/*}}}*/

// - CURSES classes -
built_in_class_s *curses_classes[] =
{/*{{{*/
  &curses_class,
};/*}}}*/

// - CURSES error strings -
const char *curses_error_strings[] =
{/*{{{*/
  "error_CURSES_DUMMY_ERROR",
};/*}}}*/

// - CURSES initialize -
bool curses_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize curses class identifier -
  c_bi_class_curses = class_base_idx++;

  return true;
}/*}}}*/

// - CURSES print exception -
bool curses_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CURSES_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCurses dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CURSES -
built_in_class_s curses_class =
{/*{{{*/
  "Curses",
  c_modifier_public | c_modifier_final,
  3, curses_methods,
  0, curses_variables,
  bic_curses_consts,
  bic_curses_init,
  bic_curses_clear,
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

built_in_method_s curses_methods[] =
{/*{{{*/
  {
    "dummy#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_dummy_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_print_0
  },
};/*}}}*/

built_in_variable_s curses_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_curses_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_curses_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_curses_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_curses_method_dummy_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  
  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_curses_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Curses"),"Curses");
  );

  return true;
}/*}}}*/

bool bic_curses_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Curses");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

