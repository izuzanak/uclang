
#ifndef __RUST_MODULE_H
#define __RUST_MODULE_H

@begin
include "script_parser.h"
@end

// - RUST indexes of built in classes -
extern unsigned c_bi_class_rust_string;

// - RUST module -
extern built_in_module_s module;

// - RUST classes -
extern built_in_class_s *rust_classes[];

// - RUST error identifiers -
enum
{
  c_error_RUST_STRING_UTF8_ENCODING_ERROR = 0,
};

// - RUST error strings -
extern const char *rust_error_strings[];

// - RUST initialize -
bool rust_initialize(script_parser_s &sp);

// - RUST print exception -
bool rust_print_exception(interpreter_s &it,exception_s &exception);

// - class RUST_STRING -
extern built_in_variable_s rust_string_variables[];
extern built_in_method_s rust_string_methods[];
extern built_in_class_s rust_string_class;

extern "C" {
void bic_rust_string_consts(location_array_s &const_locations);
void bic_rust_string_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_rust_string_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_rust_string_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_method_RustString_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_method_RustString_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_rust_string_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
}

#endif

