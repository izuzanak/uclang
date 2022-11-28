
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
  18, curses_methods,
  103 + 13, curses_variables,
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
    "cbreak#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_cbreak_1
  },
  {
    "echo#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_echo_1
  },
  {
    "keypad#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_keypad_1
  },
  {
    "nl#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_nl_1
  },
  {
    "raw#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_raw_1
  },
  {
    "move#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_move_1
  },
  {
    "movexy#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_movexy_2
  },
  {
    "curxy#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_curxy_0
  },
  {
    "maxxy#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_maxxy_0
  },
  {
    "addch#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_addch_1
  },
  {
    "addstr#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_addstr_1
  },
  {
    "attr#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_attr_2
  },
  {
    "attrset#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_attrset_1
  },
  {
    "refresh#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_refresh_0
  },
  {
    "getch#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_getch_0
  },
  {
    "getstr#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curses_method_getstr_1
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

  // - curses key constants -
  { "KEY_BREAK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_DOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_UP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_HOME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_BACKSPACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F9", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F11", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_F12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_DL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_IL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_DC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_IC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_EIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_CLEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_EOS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_EOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_NPAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_PPAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_STAB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_CTAB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_CATAB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_ENTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SRESET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_RESET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_PRINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_LL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_A1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_A3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_B2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_C1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_C3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_BTAB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_BEG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_CANCEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_CLOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_COMMAND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_COPY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_CREATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_END", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_EXIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_FIND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_HELP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_MARK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_MESSAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_MOUSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_MOVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_NEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_OPEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_OPTIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_PREVIOUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_REDO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_REFERENCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_REFRESH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_REPLACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_RESIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_RESTART", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_RESUME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SAVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SBEG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SCANCEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SCOMMAND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SCOPY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SCREATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SDC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SDL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SELECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SEND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SEOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SEXIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SFIND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SHELP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SHOME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SLEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SMESSAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SMOVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SNEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SOPTIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SPREVIOUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SPRINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SREDO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SREPLACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SRIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SRSUME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SSAVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SSUSPEND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SUNDO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_SUSPEND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "KEY_UNDO", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - curses char attribute constants -
  { "A_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_STANDOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_UNDERLINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_REVERSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_BLINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_DIM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_BOLD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_PROTECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_INVIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_ALTCHARSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_ITALIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_CHARTEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "A_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_curses_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert curses key constants -
  {
    const_locations.push_blanks(103);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 103);

#define CREATE_CURSES_KEY_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CURSES_KEY_BIC_STATIC(KEY_BREAK);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_DOWN);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_UP);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_LEFT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_RIGHT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_HOME);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_BACKSPACE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F0);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(1));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(2));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(3));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(4));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(5));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(6));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(7));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(8));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(9));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(10));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(11));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_F(12));
    CREATE_CURSES_KEY_BIC_STATIC(KEY_DL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_IL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_DC);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_IC);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_EIC);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_CLEAR);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_EOS);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_EOL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SF);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SR);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_NPAGE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_PPAGE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_STAB);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_CTAB);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_CATAB);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_ENTER);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SRESET);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_RESET);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_PRINT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_LL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_A1);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_A3);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_B2);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_C1);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_C3);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_BTAB);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_BEG);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_CANCEL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_CLOSE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_COMMAND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_COPY);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_CREATE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_END);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_EXIT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_FIND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_HELP);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_MARK);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_MESSAGE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_MOUSE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_MOVE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_NEXT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_OPEN);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_OPTIONS);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_PREVIOUS);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_REDO);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_REFERENCE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_REFRESH);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_REPLACE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_RESIZE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_RESTART);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_RESUME);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SAVE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SBEG);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SCANCEL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SCOMMAND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SCOPY);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SCREATE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SDC);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SDL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SELECT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SEND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SEOL);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SEXIT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SFIND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SHELP);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SHOME);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SIC);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SLEFT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SMESSAGE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SMOVE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SNEXT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SOPTIONS);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SPREVIOUS);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SPRINT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SREDO);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SREPLACE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SRIGHT);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SRSUME);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SSAVE);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SSUSPEND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SUNDO);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_SUSPEND);
    CREATE_CURSES_KEY_BIC_STATIC(KEY_UNDO);
  }

  // - insert curses char attribute constants -
  {
    const_locations.push_blanks(13);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 13);

#define CREATE_CURSES_CHAR_ATTR_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_NORMAL);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_STANDOUT);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_UNDERLINE);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_REVERSE);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_BLINK);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_DIM);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_BOLD);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_PROTECT);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_INVIS);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_ALTCHARSET);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_ITALIC);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_CHARTEXT);
    CREATE_CURSES_CHAR_ATTR_BIC_STATIC(A_COLOR);
  }

}/*}}}*/

void bic_curses_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_curses_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_curses_method_cbreak_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:retrieve_integer
>
class c_bi_class_curses
method cbreak
static_method
; @end

  // - ERROR -
  if ((value ? cbreak() : nocbreak()) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_echo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:retrieve_integer
>
class c_bi_class_curses
method echo
static_method
; @end

  // - ERROR -
  if ((value ? echo() : noecho()) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_keypad_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:retrieve_integer
>
class c_bi_class_curses
method keypad
static_method
; @end

  // - ERROR -
  if (keypad(stdscr,value != 0) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_nl_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:retrieve_integer
>
class c_bi_class_curses
method nl
static_method
; @end

  // - ERROR -
  if ((value ? nl() : nonl()) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_raw_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:retrieve_integer
>
class c_bi_class_curses
method raw
static_method
; @end

  // - ERROR -
  if ((value ? raw() : noraw()) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_move_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
position:c_bi_class_array
>
class c_bi_class_curses
method move
static_method
; @end

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used != 2)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  location_s *x_location = (location_s *)it.get_location_value(array_ptr->data[0]);
  location_s *y_location = (location_s *)it.get_location_value(array_ptr->data[1]);

  long long int x;
  long long int y;

  // - ERROR -
  if (!it.retrieve_integer(x_location,x) || x < 0 ||
      !it.retrieve_integer(y_location,y) || y < 0)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  if (move(y,x) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_movexy_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
x:retrieve_integer
y:retrieve_integer
>
class c_bi_class_curses
method movexy
static_method
; @end

  // - ERROR -
  if (x < 0 || y < 0)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  if (move(y,x) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_curxy_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  int x;
  int y;

  getyx(stdscr,y,x);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  long long int x_value = x;
  BIC_CREATE_NEW_LOCATION(x_loc,c_bi_class_integer,x_value);
  array_ptr->push(x_loc);

  long long int y_value = y;
  BIC_CREATE_NEW_LOCATION(y_loc,c_bi_class_integer,y_value);
  array_ptr->push(y_loc);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curses_method_maxxy_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  int x;
  int y;

  getmaxyx(stdscr,y,x);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  long long int x_value = x;
  BIC_CREATE_NEW_LOCATION(x_loc,c_bi_class_integer,x_value);
  array_ptr->push(x_loc);

  long long int y_value = y;
  BIC_CREATE_NEW_LOCATION(y_loc,c_bi_class_integer,y_value);
  array_ptr->push(y_loc);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curses_method_addch_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
character:retrieve_integer
>
class c_bi_class_curses
method addch
static_method
; @end

  // - ERROR -
  if (addch(character) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_addstr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
string:c_bi_class_string
>
class c_bi_class_curses
method addstr
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (addnstr(string_ptr->data,string_ptr->size - 1) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_attr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offon:retrieve_integer
attrs:retrieve_integer
>
class c_bi_class_curses
method attr
static_method
; @end

  // - ERROR -
  if ((offon ? attron(attrs) : attroff(attrs)) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_attrset_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
attrs:retrieve_integer
>
class c_bi_class_curses
method attrset
static_method
; @end

  // - ERROR -
  if (attrset(attrs) == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_refresh_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - ERROR -
  if (refresh() == ERR)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_curses_method_getch_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = getch();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_curses_method_getstr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
max_length:retrieve_integer
>
class c_bi_class_curses
method getstr
static_method
; @end

  // - ERROR -
  if (max_length < 1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(max_length);

  // - ERROR -
  if (getnstr(string_ptr->data,max_length) == ERR)
  {
    string_ptr->clear();
    cfree(string_ptr);
  }

  // - adjust string size -
  string_ptr->size = strlen(string_ptr->data) + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
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

