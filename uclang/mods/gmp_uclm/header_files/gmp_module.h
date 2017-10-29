
#ifndef __GMP_MODULE_H
#define __GMP_MODULE_H

@begin
include "ucl_gmp.h"
@end

// - GMP indexes of built in classes -
extern unsigned c_bi_class_gmp;
extern unsigned c_bi_class_gmp_integer;
extern unsigned c_bi_class_gmp_rational;
extern unsigned c_bi_class_mpfr_fixed;

// - GMP module -
extern built_in_module_s module;

// - GMP classes -
extern built_in_class_s *gmp_classes[];

// - GMP error identifiers -
enum
{
  c_error_GMP_NUMBER_BASE_OUT_OF_RANGE = 0,
  c_error_GMP_NUMBER_CONVERT_INVALID_STRING,
};

// - GMP error strings -
extern const char *gmp_error_strings[];

// - GMP initialize -
bool gmp_initialize(script_parser_s &sp);

// - GMP print exception -
bool gmp_print_exception(interpreter_s &it,exception_s &exception);

// - class GMP -
extern built_in_variable_s gmp_variables[];
extern built_in_method_s gmp_methods[];
extern built_in_class_s gmp_class;

void bic_gmp_consts(location_array_s &const_locations);
void bic_gmp_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gmp_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gmp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GMP_INTEGER -
extern built_in_variable_s gmp_integer_variables[];
extern built_in_method_s gmp_integer_methods[];
extern built_in_class_s gmp_integer_class;

void bic_gmp_integer_consts(location_array_s &const_locations);
void bic_gmp_integer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gmp_integer_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_gmp_integer_compare(location_s *first_loc,location_s *second_loc);
bool bic_gmp_integer_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_gmp_integer_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_gmp_integer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_percent_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_operator_unary_pre_tilde(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_GmpInteger_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_GmpInteger_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_GmpInteger_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GMP_RATIONAL -
extern built_in_variable_s gmp_rational_variables[];
extern built_in_method_s gmp_rational_methods[];
extern built_in_class_s gmp_rational_class;

void bic_gmp_rational_consts(location_array_s &const_locations);
void bic_gmp_rational_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gmp_rational_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_gmp_rational_compare(location_s *first_loc,location_s *second_loc);
bool bic_gmp_rational_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_gmp_rational_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_gmp_rational_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);\
bool bic_gmp_rational_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_GmpRational_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_GmpRational_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_GmpRational_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MPFR_FIXED -
extern built_in_variable_s mpfr_fixed_variables[];
extern built_in_method_s mpfr_fixed_methods[];
extern built_in_class_s mpfr_fixed_class;

void bic_mpfr_fixed_consts(location_array_s &const_locations);
void bic_mpfr_fixed_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mpfr_fixed_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_mpfr_fixed_compare(location_s *first_loc,location_s *second_loc);
bool bic_mpfr_fixed_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_mpfr_fixed_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_mpfr_fixed_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_MpfrFixed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_MpfrFixed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_MpfrFixed_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_sin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_cos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_tan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_asin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_acos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_atan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_exp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_log_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_pow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_sqrt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_cbrt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_hypot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpfr_fixed_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

