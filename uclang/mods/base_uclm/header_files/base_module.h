
#ifndef __BASE_MODULE_H
#define __BASE_MODULE_H

@begin
include "ucl_base.h"
@end

// - BASE module -
extern built_in_module_s module;

// - BASE classes -
extern built_in_class_s *base_classes[];

// - BASE error identifiers -
// Already defined in basic.h

// - BASE error strings -
extern const char *base_error_strings[];

// - BASE initialize -
bool base_initialize(script_parser_s &sp);

// - BASE print exception -
bool base_print_exception(interpreter_s &it,exception_s &exception);

// - class BLANK -
extern built_in_variable_s blank_variables[];
extern built_in_method_s blank_methods[];
extern built_in_class_s blank_class;

void bic_blank_consts(location_array_s &const_locations);
void bic_blank_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_blank_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_blank_compare(location_s *first_loc,location_s *second_loc);
bool bic_blank_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_blank_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_blank_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_blank_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_blank_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_blank_method_Blank_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_blank_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_blank_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_blank_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CHAR -
extern built_in_variable_s char_variables[];
extern built_in_method_s char_methods[];
extern built_in_class_s char_class;

void bic_char_consts(location_array_s &const_locations);
void bic_char_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_char_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_char_compare(location_s *first_loc,location_s *second_loc);
bool bic_char_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_char_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_char_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_percent_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_operator_unary_pre_tilde(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_method_Char_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_method_Char_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_char_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class INTEGER -
extern built_in_variable_s integer_variables[];
extern built_in_method_s integer_methods[];
extern built_in_class_s integer_class;

void bic_integer_consts(location_array_s &const_locations);
void bic_integer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_integer_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_integer_compare(location_s *first_loc,location_s *second_loc);
bool bic_integer_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_integer_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_integer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_percent_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_operator_unary_pre_tilde(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_method_Integer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_method_Integer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_method_Integer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_integer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FLOAT -
extern built_in_variable_s float_variables[];
extern built_in_method_s float_methods[];
extern built_in_class_s float_class;

void bic_float_consts(location_array_s &const_locations);
void bic_float_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_float_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_float_compare(location_s *first_loc,location_s *second_loc);
bool bic_float_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_float_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_float_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_Float_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_Float_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_sin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_cos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_tan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_asin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_acos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_atan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_exp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_log_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_pow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_sqrt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_cbrt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_hypot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_isnan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_float_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class STRING -
extern built_in_variable_s string_variables[];
extern built_in_method_s string_methods[];
extern built_in_class_s string_class;

void bic_string_consts(location_array_s &const_locations);
void bic_string_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_string_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_string_compare(location_s *first_loc,location_s *second_loc);
unsigned bic_string_length(location_s *location_ptr);
location_s *bic_string_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_string_first_idx(location_s *location_ptr);
unsigned bic_string_next_idx(location_s *location_ptr,unsigned index);
bool bic_string_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_string_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_string_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_String_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_String_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_create_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_split_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_join_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_head_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_tail_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_replace_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_string_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ARRAY -
extern built_in_variable_s array_variables[];
extern built_in_method_s array_methods[];
extern built_in_class_s array_class;

void bic_array_consts(location_array_s &const_locations);
void bic_array_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_array_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_array_length(location_s *location_ptr);
location_s *bic_array_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_array_first_idx(location_s *location_ptr);
unsigned bic_array_next_idx(location_s *location_ptr,unsigned index);
bool bic_array_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_array_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_array_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_Array_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_Array_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_push_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_last_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_array_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ERROR -
extern built_in_variable_s error_variables[];
extern built_in_method_s error_methods[];
extern built_in_class_s error_class;

void bic_error_consts(location_array_s &const_locations);
void bic_error_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_error_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_error_compare(location_s *first_loc,location_s *second_loc);

bool bic_error_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_error_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_error_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_error_method_Error_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_error_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_error_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_error_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class EXCEPTION -
extern built_in_variable_s exception_variables[];
extern built_in_method_s exception_methods[];
extern built_in_class_s exception_class;

void bic_exception_consts(location_array_s &const_locations);
void bic_exception_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_exception_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_exception_method_Exception_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_Exception_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_throw_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_get_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_get_file_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_get_line_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_error_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_exception_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TYPE -
extern built_in_variable_s type_variables[];
extern built_in_method_s type_methods[];
extern built_in_class_s type_class;

void bic_type_consts(location_array_s &const_locations);
void bic_type_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_type_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_type_compare(location_s *first_loc,location_s *second_loc);

bool bic_type_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_method_Type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_method_Type_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_type_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MUTEX -
extern built_in_variable_s mutex_variables[];
extern built_in_method_s mutex_methods[];
extern built_in_class_s mutex_class;

void bic_mutex_consts(location_array_s &const_locations);
void bic_mutex_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mutex_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mutex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mutex_method_Mutex_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mutex_method_lock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mutex_method_try_lock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mutex_method_unlock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mutex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mutex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class THREAD -
extern built_in_variable_s thread_variables[];
extern built_in_method_s thread_methods[];
extern built_in_class_s thread_class;

void bic_thread_consts(location_array_s &const_locations);
void bic_thread_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_thread_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_thread_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_thread_method_join_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef ENABLE_THREAD_TRY_JOIN
bool bic_thread_method_try_join_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_thread_method_detach_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_thread_method_yield_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_thread_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_thread_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DELEGATE -
extern built_in_variable_s delegate_variables[];
extern built_in_method_s delegate_methods[];
extern built_in_class_s delegate_class;

void bic_delegate_consts(location_array_s &const_locations);
void bic_delegate_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_delegate_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_delegate_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_delegate_method_Delegate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_delegate_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_delegate_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_delegate_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BUFFER -
extern built_in_variable_s buffer_variables[];
extern built_in_method_s buffer_methods[];
extern built_in_class_s buffer_class;

void bic_buffer_consts(location_array_s &const_locations);
void bic_buffer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_buffer_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_buffer_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RANGE -
extern built_in_variable_s range_variables[];
extern built_in_method_s range_methods[];
extern built_in_class_s range_class;

void bic_range_consts(location_array_s &const_locations);
void bic_range_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_range_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_range_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_range_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_Range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_Range_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

