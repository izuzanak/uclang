
#ifndef __VA_MODULE_H
#define __VA_MODULE_H

@begin
include "ucl_va.h"
@end

// - VA indexes of built in classes -
extern unsigned c_bi_class_va_display;

// - VA module -
extern "C" EXPORT built_in_module_s module;

// - VA classes -
extern built_in_class_s *va_classes[];

// - VA error identifiers -
enum
{
  c_error_VA_DISPLAY_NATIVE_OPEN_ERROR = 0,
  c_error_VA_DISPLAY_GET_DISPLAY_ERROR,
  c_error_VA_DISPLAY_INITIALIZE_ERROR,
};

// - VA error strings -
extern const char *va_error_strings[];

// - VA initialize -
bool va_initialize(script_parser_s &sp);

// - VA print exception -
bool va_print_exception(interpreter_s &it,exception_s &exception);

// - class VA_DISPLAY -
extern built_in_variable_s va_display_variables[];
extern built_in_method_s va_display_methods[];
extern built_in_class_s va_display_class;

void bic_va_display_consts(location_array_s &const_locations);
void bic_va_display_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_va_display_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_va_display_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_va_display_method_VaDisplay_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_va_display_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_va_display_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

