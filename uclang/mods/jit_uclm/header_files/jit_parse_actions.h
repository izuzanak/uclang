
#ifndef __JIT_PARSE_ACTIONS_H
#define __JIT_PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool jit_pa_null(jit_parser_s &_this);
bool jit_pa_function(jit_parser_s &_this);
bool jit_pa_function_name(jit_parser_s &_this);
bool jit_pa_fun_parameter(jit_parser_s &_this);
bool jit_pa_type(jit_parser_s &_this);
bool jit_pa_pointer(jit_parser_s &_this);
bool jit_pa_declaration_end(jit_parser_s &_this);
bool jit_pa_modifier_volatile(jit_parser_s &_this);
bool jit_pa_declare(jit_parser_s &_this);
bool jit_pa_declare_expression(jit_parser_s &_this);
bool jit_pa_declare_array(jit_parser_s &_this);
bool jit_pa_variable(jit_parser_s &_this);
bool jit_pa_command_block_done(jit_parser_s &_this);
bool jit_pa_command_block_begin(jit_parser_s &_this);
bool jit_pa_if_condition(jit_parser_s &_this);
bool jit_pa_if_statement(jit_parser_s &_this);
bool jit_pa_if_else_statement(jit_parser_s &_this);
bool jit_pa_if_else(jit_parser_s &_this);
bool jit_pa_while_statement(jit_parser_s &_this);
bool jit_pa_while_begin(jit_parser_s &_this);
bool jit_pa_while_condition(jit_parser_s &_this);
bool jit_pa_do_while_statement(jit_parser_s &_this);
bool jit_pa_do_while_begin(jit_parser_s &_this);
bool jit_pa_do_while_pre_condition(jit_parser_s &_this);
bool jit_pa_break(jit_parser_s &_this);
bool jit_pa_continue(jit_parser_s &_this);
bool jit_pa_return(jit_parser_s &_this);
bool jit_pa_label(jit_parser_s &_this);
bool jit_pa_goto(jit_parser_s &_this);
bool jit_pa_expression(jit_parser_s &_this);
bool jit_pa_operator_binary_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_plus_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_minus_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_asterisk_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_slash_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_percent_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_double_ls_br_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_double_rs_br_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_ampersand_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_pipe_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_circumflex_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_double_ampersand(jit_parser_s &_this);
bool jit_pa_operator_binary_double_pipe(jit_parser_s &_this);
bool jit_pa_operator_binary_double_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_exclamation_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_rs_br(jit_parser_s &_this);
bool jit_pa_operator_binary_ls_br(jit_parser_s &_this);
bool jit_pa_operator_binary_rs_br_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_ls_br_equal(jit_parser_s &_this);
bool jit_pa_operator_binary_ampersand(jit_parser_s &_this);
bool jit_pa_operator_binary_pipe(jit_parser_s &_this);
bool jit_pa_operator_binary_circumflex(jit_parser_s &_this);
bool jit_pa_operator_binary_double_rs_br(jit_parser_s &_this);
bool jit_pa_operator_binary_double_ls_br(jit_parser_s &_this);
bool jit_pa_operator_binary_plus(jit_parser_s &_this);
bool jit_pa_operator_binary_minus(jit_parser_s &_this);
bool jit_pa_operator_binary_asterisk(jit_parser_s &_this);
bool jit_pa_operator_binary_slash(jit_parser_s &_this);
bool jit_pa_operator_binary_percent(jit_parser_s &_this);
bool jit_pa_operator_unary_post_double_plus(jit_parser_s &_this);
bool jit_pa_operator_unary_post_double_minus(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_double_plus(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_double_minus(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_plus(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_minus(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_exclamation(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_tilde(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_asterisk(jit_parser_s &_this);
bool jit_pa_operator_unary_pre_ampersand(jit_parser_s &_this);
bool jit_pa_operator_binary_le_br_re_br(jit_parser_s &_this);
bool jit_pa_cast(jit_parser_s &_this);
bool jit_pa_identifier(jit_parser_s &_this);
bool jit_pa_conditional_expression(jit_parser_s &_this);
bool jit_pa_conditional_condition(jit_parser_s &_this);
bool jit_pa_conditional_true(jit_parser_s &_this);
bool jit_pa_function_call(jit_parser_s &_this);
bool jit_pa_parameters_begin(jit_parser_s &_this);
bool jit_pa_parameter(jit_parser_s &_this);
bool jit_pa_const_char(jit_parser_s &_this);
bool jit_pa_const_octal_char(jit_parser_s &_this);
bool jit_pa_const_hex_char(jit_parser_s &_this);
bool jit_pa_const_backslash_char(jit_parser_s &_this);
bool jit_pa_const_oct_i32(jit_parser_s &_this);
bool jit_pa_const_dec_i32(jit_parser_s &_this);
bool jit_pa_const_hex_i32(jit_parser_s &_this);
bool jit_pa_const_oct_i64(jit_parser_s &_this);
bool jit_pa_const_dec_i64(jit_parser_s &_this);
bool jit_pa_const_hex_i64(jit_parser_s &_this);
bool jit_pa_const_f32(jit_parser_s &_this);
bool jit_pa_const_f64(jit_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*jit_pa_callers[])(jit_parser_s &_this);

#endif

