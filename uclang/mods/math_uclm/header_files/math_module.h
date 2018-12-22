
#ifndef __MATH_MODULE_H
#define __MATH_MODULE_H

@begin
include "ucl_math.h"
@end

// - MATH indexes of built in classes -
extern unsigned c_bi_class_math;
extern unsigned c_bi_class_vec2;
extern unsigned c_bi_class_vec3;
extern unsigned c_bi_class_vec4;
extern unsigned c_bi_class_mat4;
extern unsigned c_bi_class_primes;

// - MATH module -
extern "C" IMPORT built_in_module_s module;

// - MATH classes -
extern built_in_class_s *math_classes[];

// - MATH error identifiers -
enum
{
  c_error_MATH_ARRAY_OF_NUMBERS_WRONG_LENGTH = 0,
  c_error_MATH_ARRAY_OF_NUMBERS_EXPECTED,
  c_error_MAT4_INDEX_EXCEEDS_ROW_COUNT,
  c_error_MAT4_INDEX_EXCEEDS_COLUMN_COUNT,
  c_error_PRIMES_SIEVE_SIZE_NEGATIVE,
  c_error_PRIMES_SIEVE_SIZE_TOO_BIG,
  c_error_PRIMES_SIEVE_SIZE_NOT_ENOUGH,
  c_error_PRIMES_PRIME_FACTORS_NUMBER_LESS_THAN_ONE,
  c_error_PRIMES_INDEX_DOES_NOT_REFER_TO_VALID_VALUE
};

// - MATH error strings -
extern const char *math_error_strings[];

// - MATH initialize -
bool math_initialize(script_parser_s &sp);

// - MATH print exception -
bool math_print_exception(interpreter_s &it,exception_s &exception);

// - class MATH -
extern built_in_variable_s math_variables[];
extern built_in_method_s math_methods[];
extern built_in_class_s math_class;

void bic_math_consts(location_array_s &const_locations);
void bic_math_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_math_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_math_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_math_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VEC2 -
extern built_in_variable_s vec2_variables[];
extern built_in_method_s vec2_methods[];
extern built_in_class_s vec2_class;

void bic_vec2_consts(location_array_s &const_locations);
void bic_vec2_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vec2_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_vec2_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_vec2_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_vec2_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_Vec2_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_Vec2_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_Vec2_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_dot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec2_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VEC3 -
extern built_in_variable_s vec3_variables[];
extern built_in_method_s vec3_methods[];
extern built_in_class_s vec3_class;

void bic_vec3_consts(location_array_s &const_locations);
void bic_vec3_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vec3_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_vec3_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_vec3_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_vec3_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_Vec3_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_Vec3_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_Vec3_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_z_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_dot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_cross_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec3_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VEC4 -
extern built_in_variable_s vec4_variables[];
extern built_in_method_s vec4_methods[];
extern built_in_class_s vec4_class;

void bic_vec4_consts(location_array_s &const_locations);
void bic_vec4_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vec4_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_vec4_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_vec4_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_vec4_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_Vec4_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_Vec4_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_Vec4_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_z_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_w_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_dot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vec4_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MAT4 -
extern built_in_variable_s mat4_variables[];
extern built_in_method_s mat4_methods[];
extern built_in_class_s mat4_class;

void bic_mat4_consts(location_array_s &const_locations);
void bic_mat4_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mat4_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mat4_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_Mat4_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_Mat4_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_row_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_col_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_translate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_rotate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_scale_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_ortho_6(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_perspective_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_perspective_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_look_at_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_nice_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mat4_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PRIMES -
extern built_in_variable_s primes_variables[];
extern built_in_method_s primes_methods[];
extern built_in_class_s primes_class;

void bic_primes_consts(location_array_s &const_locations);
void bic_primes_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_primes_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_primes_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_primes_first_idx(location_s *location_ptr);
unsigned bic_primes_next_idx(location_s *location_ptr,unsigned index);

bool bic_primes_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_Primes_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_prime_factors_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_primes_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

