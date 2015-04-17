
#ifndef __LTG_PARSE_ACTIONS_H
#define __LTG_PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool ltg_pa_null(ltg_parser_s &_this);
bool ltg_pa_function(ltg_parser_s &_this);
bool ltg_pa_function_name(ltg_parser_s &_this);
bool ltg_pa_fun_parameter(ltg_parser_s &_this);
bool ltg_pa_type(ltg_parser_s &_this);
bool ltg_pa_pointer(ltg_parser_s &_this);
bool ltg_pa_declaration_end(ltg_parser_s &_this);
bool ltg_pa_modifier_volatile(ltg_parser_s &_this);
bool ltg_pa_declare(ltg_parser_s &_this);
bool ltg_pa_declare_expression(ltg_parser_s &_this);
bool ltg_pa_declare_array(ltg_parser_s &_this);
bool ltg_pa_variable(ltg_parser_s &_this);
bool ltg_pa_command_block_done(ltg_parser_s &_this);
bool ltg_pa_command_block_begin(ltg_parser_s &_this);
bool ltg_pa_if_condition(ltg_parser_s &_this);
bool ltg_pa_if_statement(ltg_parser_s &_this);
bool ltg_pa_if_else_statement(ltg_parser_s &_this);
bool ltg_pa_if_else(ltg_parser_s &_this);
bool ltg_pa_while_statement(ltg_parser_s &_this);
bool ltg_pa_while_begin(ltg_parser_s &_this);
bool ltg_pa_while_condition(ltg_parser_s &_this);
bool ltg_pa_do_while_statement(ltg_parser_s &_this);
bool ltg_pa_do_while_begin(ltg_parser_s &_this);
bool ltg_pa_do_while_pre_condition(ltg_parser_s &_this);
bool ltg_pa_break(ltg_parser_s &_this);
bool ltg_pa_continue(ltg_parser_s &_this);
bool ltg_pa_return(ltg_parser_s &_this);
bool ltg_pa_expression(ltg_parser_s &_this);
bool ltg_pa_operator_binary_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_plus_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_minus_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_asterisk_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_slash_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_percent_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_ls_br_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_rs_br_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_ampersand_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_pipe_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_circumflex_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_ampersand(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_pipe(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_exclamation_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_rs_br(ltg_parser_s &_this);
bool ltg_pa_operator_binary_ls_br(ltg_parser_s &_this);
bool ltg_pa_operator_binary_rs_br_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_ls_br_equal(ltg_parser_s &_this);
bool ltg_pa_operator_binary_ampersand(ltg_parser_s &_this);
bool ltg_pa_operator_binary_pipe(ltg_parser_s &_this);
bool ltg_pa_operator_binary_circumflex(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_rs_br(ltg_parser_s &_this);
bool ltg_pa_operator_binary_double_ls_br(ltg_parser_s &_this);
bool ltg_pa_operator_binary_plus(ltg_parser_s &_this);
bool ltg_pa_operator_binary_minus(ltg_parser_s &_this);
bool ltg_pa_operator_binary_asterisk(ltg_parser_s &_this);
bool ltg_pa_operator_binary_slash(ltg_parser_s &_this);
bool ltg_pa_operator_binary_percent(ltg_parser_s &_this);
bool ltg_pa_operator_unary_post_double_plus(ltg_parser_s &_this);
bool ltg_pa_operator_unary_post_double_minus(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_double_plus(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_double_minus(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_plus(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_minus(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_exclamation(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_tilde(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_asterisk(ltg_parser_s &_this);
bool ltg_pa_operator_unary_pre_ampersand(ltg_parser_s &_this);
bool ltg_pa_operator_binary_le_br_re_br(ltg_parser_s &_this);
bool ltg_pa_cast(ltg_parser_s &_this);
bool ltg_pa_identifier(ltg_parser_s &_this);
bool ltg_pa_conditional_expression(ltg_parser_s &_this);
bool ltg_pa_conditional_condition(ltg_parser_s &_this);
bool ltg_pa_conditional_true(ltg_parser_s &_this);
bool ltg_pa_function_call(ltg_parser_s &_this);
bool ltg_pa_parameters_begin(ltg_parser_s &_this);
bool ltg_pa_parameter(ltg_parser_s &_this);
bool ltg_pa_const_char(ltg_parser_s &_this);
bool ltg_pa_const_octal_char(ltg_parser_s &_this);
bool ltg_pa_const_hex_char(ltg_parser_s &_this);
bool ltg_pa_const_backslash_char(ltg_parser_s &_this);
bool ltg_pa_const_oct_i32(ltg_parser_s &_this);
bool ltg_pa_const_dec_i32(ltg_parser_s &_this);
bool ltg_pa_const_hex_i32(ltg_parser_s &_this);
bool ltg_pa_const_oct_i64(ltg_parser_s &_this);
bool ltg_pa_const_dec_i64(ltg_parser_s &_this);
bool ltg_pa_const_hex_i64(ltg_parser_s &_this);
bool ltg_pa_const_f32(ltg_parser_s &_this);
bool ltg_pa_const_f64(ltg_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*ltg_pa_callers[])(ltg_parser_s &_this);

#endif

