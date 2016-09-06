
#ifndef __IM_GEN_ACTIONS_H
#define __IM_GEN_ACTIONS_H

/*
 * declaration of functions describing intermediate code generation
 */

bool im_elements_array(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_switch_test(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_slice_range(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_plus_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_minus_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_asterisk_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_slash_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_percent_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_ls_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_rs_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_ampersand_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_pipe_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_circumflex_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_ampersand(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_pipe(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_ampersand(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_pipe(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_circumflex(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_exclamation_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_rs_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_ls_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_rs_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_ls_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_rs_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_double_ls_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_asterisk(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_slash(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_percent(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_post_double_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_post_double_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_pre_double_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_pre_double_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_pre_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_pre_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_pre_exclamation(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_unary_pre_tilde(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_operator_binary_le_br_re_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_identifier(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_element_identifier(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_this_access(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_new_object(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_new_objects_array(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_free_object(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_type_identification(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_object_reference_copy(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_conditional_expression(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_logical_and(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_logical_or(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_class_access(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_object_member_select(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_this_method_call(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_object_method_call(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_const_char(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_const_int(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_const_float(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);
bool im_const_string(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*script_im_callers[])(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this);

#endif

