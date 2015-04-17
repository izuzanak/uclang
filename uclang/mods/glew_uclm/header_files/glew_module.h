
#ifndef __GLEW_MODULE_H
#define __GLEW_MODULE_H

@begin
include "script_parser.h"
@end

#if defined(LINUX)
#include <GL/glew.h>
#endif

// - GLEW indexes of built in classes -
extern unsigned c_bi_class_glew;

// - GLEW module -
extern built_in_module_s module;

// - GLEW classes -
extern built_in_class_s *glew_classes[];

// - GLEW error identifiers -
enum
{
  c_error_GLEW_INITIALIZATION_FAILED = 0,
};

// - GLEW error strings -
extern const char *glew_error_strings[];

// - GLEW initialize -
bool glew_initialize(script_parser_s &sp);

// - GLEW print exception -
bool glew_print_exception(interpreter_s &it,exception_s &exception);

// - class GLEW -
extern built_in_variable_s glew_variables[];
extern built_in_method_s glew_methods[];
extern built_in_class_s glew_class;

void bic_glew_consts(location_array_s &const_locations);
void bic_glew_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_glew_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_glew_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glew_method_Glew_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glew_method_IsSupported_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glew_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glew_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

