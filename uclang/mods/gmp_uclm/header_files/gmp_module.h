
#ifndef __GMP_MODULE_H
#define __GMP_MODULE_H

@begin
include "ucl_gmp.h"
@end

// - GMP indexes of built in classes -
extern unsigned c_bi_class_gmp;
extern unsigned c_bi_class_gmp_integer;
extern unsigned c_bi_class_gmp_rational;
extern unsigned c_bi_class_gmp_fixed_point;

// - GMP module -
extern built_in_module_s module;

// - GMP classes -
extern built_in_class_s *gmp_classes[];

// - GMP error identifiers -
enum
{
  c_error_GMP_INTEGER_BASE_OUT_OF_RANGE = 0,
  c_error_GMP_INTEGER_CONVERT_INVALID_STRING,
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

bool bic_gmp_integer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_GmpInteger_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_GmpInteger_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_GmpInteger_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_integer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GMP_RATIONAL -
extern built_in_variable_s gmp_rational_variables[];
extern built_in_method_s gmp_rational_methods[];
extern built_in_class_s gmp_rational_class;

void bic_gmp_rational_consts(location_array_s &const_locations);
void bic_gmp_rational_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gmp_rational_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gmp_rational_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_GmpRational_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_GmpRational_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_rational_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GMP_FIXED_POINT -
extern built_in_variable_s gmp_fixed_point_variables[];
extern built_in_method_s gmp_fixed_point_methods[];
extern built_in_class_s gmp_fixed_point_class;

void bic_gmp_fixed_point_consts(location_array_s &const_locations);
void bic_gmp_fixed_point_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gmp_fixed_point_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gmp_fixed_point_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_fixed_point_method_GmpFixedPoint_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_fixed_point_method_GmpFixedPoint_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_fixed_point_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gmp_fixed_point_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif
