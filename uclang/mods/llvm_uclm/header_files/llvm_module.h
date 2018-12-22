
#ifndef __LLVM_MODULE_H
#define __LLVM_MODULE_H

@begin
include "ucl_llvm.h"
@end

// - LLVM indexes of built in classes -
extern unsigned c_bi_class_llvm_context;
extern unsigned c_bi_class_llvm_module;

// - LLVM module -
extern "C" IMPORT built_in_module_s module;

// - LLVM classes -
extern built_in_class_s *llvm_classes[];

// - LLVM error identifiers -
// - moved to file llvm_parser.h -

// - LLVM error strings -
extern const char *llvm_error_strings[];

// - LLVM initialize -
bool llvm_initialize(script_parser_s &sp);

// - LLVM print exception -
bool llvm_print_exception(interpreter_s &it,exception_s &exception);

// - class LLVM_CONTEXT -
extern built_in_variable_s llvm_context_variables[];
extern built_in_method_s llvm_context_methods[];
extern built_in_class_s llvm_context_class;

void bic_llvm_context_consts(location_array_s &const_locations);
void bic_llvm_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_llvm_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_llvm_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_context_method_LlvmContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_context_method_module_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class LLVM_MODULE -
extern built_in_variable_s llvm_module_variables[];
extern built_in_method_s llvm_module_methods[];
extern built_in_class_s llvm_module_class;

void bic_llvm_module_consts(location_array_s &const_locations);
void bic_llvm_module_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_llvm_module_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_llvm_module_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_module_method_create_fun_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_module_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_llvm_module_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

