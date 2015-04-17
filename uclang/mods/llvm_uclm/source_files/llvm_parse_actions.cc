
@begin
include "ucl_llvm.h"
@end

/*
 * constants and definitions
 */

const unsigned max_number_string_length = 12;

// - callers of parse action functions -
const unsigned c_llvm_parse_action_cnt = 122;
bool(*llvm_pa_callers[c_llvm_parse_action_cnt])(llvm_parser_s &_this) =
{/*{{{*/
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_function,
  llvm_pa_function_name,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_fun_parameter,
  llvm_pa_null,
  llvm_pa_type,
  llvm_pa_pointer,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_declaration_end,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_modifier_volatile,
  llvm_pa_type,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_declare,
  llvm_pa_declare_expression,
  llvm_pa_declare_array,
  llvm_pa_variable,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_command_block_done,
  llvm_pa_command_block_begin,
  llvm_pa_null,
  llvm_pa_if_condition,
  llvm_pa_if_statement,
  llvm_pa_if_else_statement,
  llvm_pa_if_else,
  llvm_pa_while_statement,
  llvm_pa_while_begin,
  llvm_pa_while_condition,
  llvm_pa_do_while_statement,
  llvm_pa_do_while_begin,
  llvm_pa_do_while_pre_condition,
  llvm_pa_break,
  llvm_pa_continue,
  llvm_pa_return,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_expression,
  llvm_pa_null,
  llvm_pa_operator_binary_equal,
  llvm_pa_operator_binary_plus_equal,
  llvm_pa_operator_binary_minus_equal,
  llvm_pa_operator_binary_asterisk_equal,
  llvm_pa_operator_binary_slash_equal,
  llvm_pa_operator_binary_percent_equal,
  llvm_pa_operator_binary_double_ls_br_equal,
  llvm_pa_operator_binary_double_rs_br_equal,
  llvm_pa_operator_binary_ampersand_equal,
  llvm_pa_operator_binary_pipe_equal,
  llvm_pa_operator_binary_circumflex_equal,
  llvm_pa_null,
  llvm_pa_operator_binary_double_ampersand,
  llvm_pa_operator_binary_double_pipe,
  llvm_pa_null,
  llvm_pa_operator_binary_double_equal,
  llvm_pa_operator_binary_exclamation_equal,
  llvm_pa_operator_binary_rs_br,
  llvm_pa_operator_binary_ls_br,
  llvm_pa_operator_binary_rs_br_equal,
  llvm_pa_operator_binary_ls_br_equal,
  llvm_pa_null,
  llvm_pa_operator_binary_ampersand,
  llvm_pa_operator_binary_pipe,
  llvm_pa_operator_binary_circumflex,
  llvm_pa_null,
  llvm_pa_operator_binary_double_rs_br,
  llvm_pa_operator_binary_double_ls_br,
  llvm_pa_null,
  llvm_pa_operator_binary_plus,
  llvm_pa_operator_binary_minus,
  llvm_pa_null,
  llvm_pa_operator_binary_asterisk,
  llvm_pa_operator_binary_slash,
  llvm_pa_operator_binary_percent,
  llvm_pa_null,
  llvm_pa_operator_unary_post_double_plus,
  llvm_pa_operator_unary_post_double_minus,
  llvm_pa_operator_unary_pre_double_plus,
  llvm_pa_operator_unary_pre_double_minus,
  llvm_pa_operator_unary_pre_plus,
  llvm_pa_operator_unary_pre_minus,
  llvm_pa_operator_unary_pre_exclamation,
  llvm_pa_operator_unary_pre_tilde,
  llvm_pa_operator_unary_pre_asterisk,
  llvm_pa_operator_unary_pre_ampersand,
  llvm_pa_operator_binary_le_br_re_br,
  llvm_pa_cast,
  llvm_pa_null,
  llvm_pa_identifier,
  llvm_pa_conditional_expression,
  llvm_pa_conditional_condition,
  llvm_pa_conditional_true,
  llvm_pa_function_call,
  llvm_pa_null,
  llvm_pa_null,
  llvm_pa_parameters_begin,
  llvm_pa_parameter,
  llvm_pa_parameter,
  llvm_pa_const_char,
  llvm_pa_const_octal_char,
  llvm_pa_const_hex_char,
  llvm_pa_const_backslash_char,
  llvm_pa_const_oct_i32,
  llvm_pa_const_dec_i32,
  llvm_pa_const_hex_i32,
  llvm_pa_const_oct_i64,
  llvm_pa_const_dec_i64,
  llvm_pa_const_hex_i64,
  llvm_pa_const_f32,
  llvm_pa_const_f64,
};/*}}}*/

/*
 * parse action macros
 */

/*
 * functions implementing parse actions of parser
 */

bool llvm_pa_null(llvm_parser_s &_this)
{/*{{{*/
  cassert(0);

  return true;
}/*}}}*/

bool llvm_pa_function(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_function\n");

  return true;
}/*}}}*/

bool llvm_pa_function_name(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_function_name\n");

  return true;
}/*}}}*/

bool llvm_pa_fun_parameter(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_fun_parameter\n");

  return true;
}/*}}}*/

bool llvm_pa_type(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_type\n");

  return true;
}/*}}}*/

bool llvm_pa_pointer(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_pointer\n");

  return true;
}/*}}}*/

bool llvm_pa_declaration_end(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_declaration_end\n");

  return true;
}/*}}}*/

bool llvm_pa_modifier_volatile(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_modifier_volatile\n");

  return true;
}/*}}}*/

bool llvm_pa_declare(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_declare\n");

  return true;
}/*}}}*/

bool llvm_pa_declare_expression(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_declare_expression\n");

  return true;
}/*}}}*/

bool llvm_pa_declare_array(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_declare_array\n");

  return true;
}/*}}}*/

bool llvm_pa_variable(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_variable\n");

  return true;
}/*}}}*/

bool llvm_pa_command_block_done(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_command_block_done\n");

  return true;
}/*}}}*/

bool llvm_pa_command_block_begin(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_command_block_begin\n");

  return true;
}/*}}}*/

bool llvm_pa_if_condition(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_if_condition\n");

  return true;
}/*}}}*/

bool llvm_pa_if_statement(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_if_statement\n");

  return true;
}/*}}}*/

bool llvm_pa_if_else_statement(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_if_else_statement\n");

  return true;
}/*}}}*/

bool llvm_pa_if_else(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_if_else\n");

  return true;
}/*}}}*/

bool llvm_pa_while_statement(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_while_statement\n");

  return true;
}/*}}}*/

bool llvm_pa_while_begin(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_while_begin\n");

  return true;
}/*}}}*/

bool llvm_pa_while_condition(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_while_condition\n");

  return true;
}/*}}}*/

bool llvm_pa_do_while_statement(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_do_while_statement\n");

  return true;
}/*}}}*/

bool llvm_pa_do_while_begin(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_do_while_begin\n");

  return true;
}/*}}}*/

bool llvm_pa_do_while_pre_condition(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_do_while_pre_condition\n");

  return true;
}/*}}}*/

bool llvm_pa_break(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_break\n");

  return true;
}/*}}}*/

bool llvm_pa_continue(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_continue\n");

  return true;
}/*}}}*/

bool llvm_pa_return(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_return\n");

  return true;
}/*}}}*/

bool llvm_pa_expression(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_expression\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_plus_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_plus_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_minus_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_minus_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_asterisk_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_asterisk_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_slash_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_slash_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_percent_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_percent_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_ls_br_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_ls_br_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_rs_br_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_rs_br_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_ampersand_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_ampersand_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_pipe_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_pipe_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_circumflex_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_circumflex_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_ampersand(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_ampersand\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_pipe(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_pipe\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_exclamation_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_exclamation_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_rs_br(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_rs_br\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_ls_br(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_ls_br\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_rs_br_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_rs_br_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_ls_br_equal(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_ls_br_equal\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_ampersand(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_ampersand\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_pipe(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_pipe\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_circumflex(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_circumflex\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_rs_br(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_rs_br\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_double_ls_br(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_double_ls_br\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_plus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_plus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_minus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_minus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_asterisk(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_asterisk\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_slash(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_slash\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_percent(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_percent\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_post_double_plus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_post_double_plus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_post_double_minus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_post_double_minus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_double_plus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_double_plus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_double_minus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_double_minus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_plus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_plus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_minus(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_minus\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_exclamation(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_exclamation\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_tilde(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_tilde\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_asterisk(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_asterisk\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_unary_pre_ampersand(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_unary_pre_ampersand\n");

  return true;
}/*}}}*/

bool llvm_pa_operator_binary_le_br_re_br(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_operator_binary_le_br_re_br\n");

  return true;
}/*}}}*/

bool llvm_pa_cast(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_cast\n");

  return true;
}/*}}}*/

bool llvm_pa_identifier(llvm_parser_s &_this)
{/*{{{*/
fprintf(stderr,"llvm_pa_identifier\n");

return true;
}/*}}}*/

bool llvm_pa_conditional_expression(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_conditional_expression\n");

  return true;
}/*}}}*/

bool llvm_pa_conditional_condition(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_conditional_condition\n");

  return true;
}/*}}}*/

bool llvm_pa_conditional_true(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_conditional_true\n");

  return true;
}/*}}}*/

bool llvm_pa_function_call(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_function_call\n");

  return true;
}/*}}}*/

bool llvm_pa_parameters_begin(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_parameters_begin\n");

  return true;
}/*}}}*/

bool llvm_pa_parameter(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_parameter\n");

  return true;
}/*}}}*/

bool llvm_pa_const_char(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_char\n");

  return true;
}/*}}}*/

bool llvm_pa_const_octal_char(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_octal_char\n");

  return true;
}/*}}}*/

bool llvm_pa_const_hex_char(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_hex_char\n");

  return true;
}/*}}}*/

bool llvm_pa_const_backslash_char(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_backslash_char\n");

  return true;
}/*}}}*/

bool llvm_pa_const_oct_i32(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_oct_i32\n");

  return true;
}/*}}}*/

bool llvm_pa_const_dec_i32(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_dec_i32\n");

  return true;
}/*}}}*/

bool llvm_pa_const_hex_i32(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_hex_i32\n");

  return true;
}/*}}}*/

bool llvm_pa_const_oct_i64(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_oct_i64\n");

  return true;
}/*}}}*/

bool llvm_pa_const_dec_i64(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_dec_i64\n");

  return true;
}/*}}}*/

bool llvm_pa_const_hex_i64(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_hex_i64\n");

  return true;
}/*}}}*/

bool llvm_pa_const_f32(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_f32\n");

  return true;
}/*}}}*/

bool llvm_pa_const_f64(llvm_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"llvm_pa_const_f64\n");

  return true;
}/*}}}*/

