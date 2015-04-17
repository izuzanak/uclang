
#ifndef __LLVM_PARSE_ACTIONS_H
#define __LLVM_PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool llvm_pa_null(llvm_parser_s &_this);
bool llvm_pa_function(llvm_parser_s &_this);
bool llvm_pa_function_name(llvm_parser_s &_this);
bool llvm_pa_fun_parameter(llvm_parser_s &_this);
bool llvm_pa_type(llvm_parser_s &_this);
bool llvm_pa_pointer(llvm_parser_s &_this);
bool llvm_pa_declaration_end(llvm_parser_s &_this);
bool llvm_pa_modifier_volatile(llvm_parser_s &_this);
bool llvm_pa_declare(llvm_parser_s &_this);
bool llvm_pa_declare_expression(llvm_parser_s &_this);
bool llvm_pa_declare_array(llvm_parser_s &_this);
bool llvm_pa_variable(llvm_parser_s &_this);
bool llvm_pa_command_block_done(llvm_parser_s &_this);
bool llvm_pa_command_block_begin(llvm_parser_s &_this);
bool llvm_pa_if_condition(llvm_parser_s &_this);
bool llvm_pa_if_statement(llvm_parser_s &_this);
bool llvm_pa_if_else_statement(llvm_parser_s &_this);
bool llvm_pa_if_else(llvm_parser_s &_this);
bool llvm_pa_while_statement(llvm_parser_s &_this);
bool llvm_pa_while_begin(llvm_parser_s &_this);
bool llvm_pa_while_condition(llvm_parser_s &_this);
bool llvm_pa_do_while_statement(llvm_parser_s &_this);
bool llvm_pa_do_while_begin(llvm_parser_s &_this);
bool llvm_pa_do_while_pre_condition(llvm_parser_s &_this);
bool llvm_pa_break(llvm_parser_s &_this);
bool llvm_pa_continue(llvm_parser_s &_this);
bool llvm_pa_return(llvm_parser_s &_this);
bool llvm_pa_expression(llvm_parser_s &_this);
bool llvm_pa_operator_binary_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_plus_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_minus_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_asterisk_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_slash_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_percent_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_ls_br_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_rs_br_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_ampersand_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_pipe_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_circumflex_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_ampersand(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_pipe(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_exclamation_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_rs_br(llvm_parser_s &_this);
bool llvm_pa_operator_binary_ls_br(llvm_parser_s &_this);
bool llvm_pa_operator_binary_rs_br_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_ls_br_equal(llvm_parser_s &_this);
bool llvm_pa_operator_binary_ampersand(llvm_parser_s &_this);
bool llvm_pa_operator_binary_pipe(llvm_parser_s &_this);
bool llvm_pa_operator_binary_circumflex(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_rs_br(llvm_parser_s &_this);
bool llvm_pa_operator_binary_double_ls_br(llvm_parser_s &_this);
bool llvm_pa_operator_binary_plus(llvm_parser_s &_this);
bool llvm_pa_operator_binary_minus(llvm_parser_s &_this);
bool llvm_pa_operator_binary_asterisk(llvm_parser_s &_this);
bool llvm_pa_operator_binary_slash(llvm_parser_s &_this);
bool llvm_pa_operator_binary_percent(llvm_parser_s &_this);
bool llvm_pa_operator_unary_post_double_plus(llvm_parser_s &_this);
bool llvm_pa_operator_unary_post_double_minus(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_double_plus(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_double_minus(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_plus(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_minus(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_exclamation(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_tilde(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_asterisk(llvm_parser_s &_this);
bool llvm_pa_operator_unary_pre_ampersand(llvm_parser_s &_this);
bool llvm_pa_operator_binary_le_br_re_br(llvm_parser_s &_this);
bool llvm_pa_cast(llvm_parser_s &_this);
bool llvm_pa_identifier(llvm_parser_s &_this);
bool llvm_pa_conditional_expression(llvm_parser_s &_this);
bool llvm_pa_conditional_condition(llvm_parser_s &_this);
bool llvm_pa_conditional_true(llvm_parser_s &_this);
bool llvm_pa_function_call(llvm_parser_s &_this);
bool llvm_pa_parameters_begin(llvm_parser_s &_this);
bool llvm_pa_parameter(llvm_parser_s &_this);
bool llvm_pa_const_char(llvm_parser_s &_this);
bool llvm_pa_const_octal_char(llvm_parser_s &_this);
bool llvm_pa_const_hex_char(llvm_parser_s &_this);
bool llvm_pa_const_backslash_char(llvm_parser_s &_this);
bool llvm_pa_const_oct_i32(llvm_parser_s &_this);
bool llvm_pa_const_dec_i32(llvm_parser_s &_this);
bool llvm_pa_const_hex_i32(llvm_parser_s &_this);
bool llvm_pa_const_oct_i64(llvm_parser_s &_this);
bool llvm_pa_const_dec_i64(llvm_parser_s &_this);
bool llvm_pa_const_hex_i64(llvm_parser_s &_this);
bool llvm_pa_const_f32(llvm_parser_s &_this);
bool llvm_pa_const_f64(llvm_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*llvm_pa_callers[])(llvm_parser_s &_this);

#endif

