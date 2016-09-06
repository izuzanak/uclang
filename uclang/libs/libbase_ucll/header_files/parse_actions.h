
#ifndef __PARSE_ACTIONS_H
#define __PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool pa_null(string_s &source_string,script_parser_s &_this);
bool pa_import(string_s &source_string,script_parser_s &_this);
bool pa_namespace_def_end(string_s &source_string,script_parser_s &_this);
bool pa_namespace_def_name(string_s &source_string,script_parser_s &_this);
bool pa_namespace_using_end(string_s &source_string,script_parser_s &_this);
bool pa_namespace_using_name(string_s &source_string,script_parser_s &_this);
bool pa_namespace_identifier(string_s &source_string,script_parser_s &_this);
bool pa_namespace_identifier_arrow(string_s &source_string,script_parser_s &_this);
bool pa_modifier_public(string_s &source_string,script_parser_s &_this);
bool pa_modifier_private(string_s &source_string,script_parser_s &_this);
bool pa_modifier_static(string_s &source_string,script_parser_s &_this);
bool pa_modifier_abstract(string_s &source_string,script_parser_s &_this);
bool pa_modifier_final(string_s &source_string,script_parser_s &_this);
bool pa_modifier_parallel(string_s &source_string,script_parser_s &_this);
bool pa_class_def_end(string_s &source_string,script_parser_s &_this);
bool pa_class_name(string_s &source_string,script_parser_s &_this);
bool pa_class_extends(string_s &source_string,script_parser_s &_this);
bool pa_element_name(string_s &source_string,script_parser_s &_this);
bool pa_init_expression(string_s &source_string,script_parser_s &_this);
bool pa_element_name_pa_identifier(string_s &source_string,script_parser_s &_this);
bool pa_method_def_end(string_s &source_string,script_parser_s &_this);
bool pa_method_name(string_s &source_string,script_parser_s &_this);
bool pa_method_parameters_done(string_s &source_string,script_parser_s &_this);
bool pa_method_parameter(string_s &source_string,script_parser_s &_this);
bool pa_method_reference_parameter(string_s &source_string,script_parser_s &_this);
bool pa_method_body_semicolon(string_s &source_string,script_parser_s &_this);
bool pa_method_body_empty(string_s &source_string,script_parser_s &_this);
bool pa_method_body_begin(string_s &source_string,script_parser_s &_this);
bool pa_command_join(string_s &source_string,script_parser_s &_this);
bool pa_blank_command_block(string_s &source_string,script_parser_s &_this);
bool pa_try_catch_done(string_s &source_string,script_parser_s &_this);
bool pa_try_begin(string_s &source_string,script_parser_s &_this);
bool pa_catch_begin(string_s &source_string,script_parser_s &_this);
bool pa_if_statement(string_s &source_string,script_parser_s &_this);
bool pa_if_else_statement(string_s &source_string,script_parser_s &_this);
bool pa_while_statement(string_s &source_string,script_parser_s &_this);
bool pa_while_begin(string_s &source_string,script_parser_s &_this);
bool pa_do_while_statement(string_s &source_string,script_parser_s &_this);
bool pa_do_while_begin(string_s &source_string,script_parser_s &_this);
bool pa_for_statement(string_s &source_string,script_parser_s &_this);
bool pa_for_expression(string_s &source_string,script_parser_s &_this);
bool pa_for_begin(string_s &source_string,script_parser_s &_this);
bool pa_switch_statement(string_s &source_string,script_parser_s &_this);
bool pa_switch_expression(string_s &source_string,script_parser_s &_this);
bool pa_switch_item(string_s &source_string,script_parser_s &_this);
bool pa_switch_item_begin(string_s &source_string,script_parser_s &_this);
bool pa_break(string_s &source_string,script_parser_s &_this);
bool pa_continue(string_s &source_string,script_parser_s &_this);
bool pa_return(string_s &source_string,script_parser_s &_this);
bool pa_elements_array(string_s &source_string,script_parser_s &_this);
bool pa_array_elements_begin(string_s &source_string,script_parser_s &_this);
bool pa_array_element(string_s &source_string,script_parser_s &_this);
bool pa_condition(string_s &source_string,script_parser_s &_this);
bool pa_expression(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_plus_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_minus_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_asterisk_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_slash_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_percent_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_ls_br_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_rs_br_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_ampersand_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_pipe_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_circumflex_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_ampersand(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_pipe(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_exclamation_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_rs_br(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_ls_br(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_rs_br_equal(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_ls_br_equal(string_s &source_string,script_parser_s &_this);
bool pa_presence_test(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_ampersand(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_pipe(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_circumflex(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_rs_br(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_double_ls_br(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_plus(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_minus(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_asterisk(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_slash(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_percent(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_post_double_plus(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_post_double_minus(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_pre_double_plus(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_pre_double_minus(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_pre_plus(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_pre_minus(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_pre_exclamation(string_s &source_string,script_parser_s &_this);
bool pa_operator_unary_pre_tilde(string_s &source_string,script_parser_s &_this);
bool pa_operator_binary_le_br_re_br(string_s &source_string,script_parser_s &_this);
bool pa_slice_range(string_s &source_string,script_parser_s &_this);
bool pa_slice_blank_value(string_s &source_string,script_parser_s &_this);
bool pa_identifier(string_s &source_string,script_parser_s &_this);
bool pa_this_access(string_s &source_string,script_parser_s &_this);
bool pa_new_object(string_s &source_string,script_parser_s &_this);
bool pa_new_objects_array(string_s &source_string,script_parser_s &_this);
bool pa_free_object(string_s &source_string,script_parser_s &_this);
bool pa_type_identification(string_s &source_string,script_parser_s &_this);
bool pa_convert_to_string(string_s &source_string,script_parser_s &_this);
bool pa_object_reference_copy(string_s &source_string,script_parser_s &_this);
bool pa_conditional_expression(string_s &source_string,script_parser_s &_this);
bool pa_logical_and(string_s &source_string,script_parser_s &_this);
bool pa_logical_or(string_s &source_string,script_parser_s &_this);
bool pa_class_access(string_s &source_string,script_parser_s &_this);
bool pa_object_member_select(string_s &source_string,script_parser_s &_this);
bool pa_this_method_call(string_s &source_string,script_parser_s &_this);
bool pa_object_method_call(string_s &source_string,script_parser_s &_this);
bool pa_parameters_begin(string_s &source_string,script_parser_s &_this);
bool pa_parameter(string_s &source_string,script_parser_s &_this);
bool pa_object_member_name(string_s &source_string,script_parser_s &_this);
bool pa_const_char(string_s &source_string,script_parser_s &_this);
bool pa_const_octal_char(string_s &source_string,script_parser_s &_this);
bool pa_const_hex_char(string_s &source_string,script_parser_s &_this);
bool pa_const_backslash_char(string_s &source_string,script_parser_s &_this);
bool pa_const_oct_int(string_s &source_string,script_parser_s &_this);
bool pa_const_dec_int(string_s &source_string,script_parser_s &_this);
bool pa_const_hex_int(string_s &source_string,script_parser_s &_this);
bool pa_const_float(string_s &source_string,script_parser_s &_this);
bool pa_const_string(string_s &source_string,script_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*script_pa_callers[])(string_s &source_string,script_parser_s &_this);

#endif

