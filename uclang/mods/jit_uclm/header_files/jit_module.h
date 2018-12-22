
#ifndef __JIT_MODULE_H
#define __JIT_MODULE_H

@begin
include "ucl_jit.h"
@end

// - JIT indexes of built in classes -
extern unsigned c_bi_class_jit_context;
extern unsigned c_bi_class_jit_function;

// - JIT module -
extern "C" IMPORT built_in_module_s module;

// - JIT classes -
extern built_in_class_s *jit_classes[];

// - JIT error identifiers -
// - moved to file jit_parser.h -

// - JIT error strings -
extern const char *jit_error_strings[];

// - JIT initialize -
bool jit_initialize(script_parser_s &sp);

// - JIT print exception -
bool jit_print_exception(interpreter_s &it,exception_s &exception);

// - class JIT_CONTEXT -
extern built_in_variable_s jit_context_variables[];
extern built_in_method_s jit_context_methods[];
extern built_in_class_s jit_context_class;

void bic_jit_context_consts(location_array_s &const_locations);
void bic_jit_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_jit_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_jit_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_context_method_JitContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_context_method_create_fun_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class JIT_FUNCTION -
extern built_in_variable_s jit_function_variables[];
extern built_in_method_s jit_function_methods[];
extern built_in_class_s jit_function_class;

void bic_jit_function_consts(location_array_s &const_locations);
void bic_jit_function_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_jit_function_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_jit_function_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_function_method_signature_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_function_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_function_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_jit_function_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

