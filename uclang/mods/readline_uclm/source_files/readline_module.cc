
@begin
include "readline_module.h"
@end

// - READLINE indexes of built in classes -
unsigned c_bi_class_readline = c_idx_not_exist;

// - READLINE module -
built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  readline_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  readline_error_strings,   // Error strings

  readline_initialize,      // Initialize function
  readline_print_exception, // Print exceptions function
};/*}}}*/

// - READLINE classes -
built_in_class_s *readline_classes[] =
{/*{{{*/
  &readline_class,
};/*}}}*/

// - READLINE error strings -
const char *readline_error_strings[] =
{/*{{{*/
  "error_READLINE_DUMMY_ERROR",
};/*}}}*/

// - READLINE initialize -
bool readline_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize readline class identifier -
  c_bi_class_readline = class_base_idx++;

  return true;
}/*}}}*/

// - READLINE print exception -
bool readline_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_READLINE_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nReadline dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class READLINE -
built_in_class_s readline_class =
{/*{{{*/
  "Readline",
  c_modifier_public | c_modifier_final,
  4, readline_methods,
  0, readline_variables,
  bic_readline_consts,
  bic_readline_init,
  bic_readline_clear,
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

built_in_method_s readline_methods[] =
{/*{{{*/
  {
    "readline#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_readline_method_readline_1
  },
  {
    "add_history#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_readline_method_add_history_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_readline_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_readline_method_print_0
  },
};/*}}}*/

built_in_variable_s readline_variables[] =
{/*{{{*/
};/*}}}*/

void bic_readline_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_readline_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_readline_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_readline_method_readline_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
prompt:c_bi_class_string
>
class c_bi_class_readline
method readline
static_method
; @end

  char *line = readline(((string_s *)src_0_location->v_data_ptr)->data);

  if (line != nullptr)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = line;
    string_ptr->size = strlen(line) + 1;

    BIC_SET_RESULT_STRING(string_ptr);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_readline_method_add_history_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
line:c_bi_class_string
>
class c_bi_class_readline
method add_history
static_method
; @end

  add_history(((string_s *)src_0_location->v_data_ptr)->data);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_readline_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Readline"),"Readline");
  );

  return true;
}/*}}}*/

bool bic_readline_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Readline");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

