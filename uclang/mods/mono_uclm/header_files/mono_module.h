
#ifndef __MONO_MODULE_H
#define __MONO_MODULE_H

@begin
include "ucl_mono.h"
@end

// - MONO indexes of built in classes -
extern unsigned c_bi_class_mono_assembly;

// - MONO module -
extern built_in_module_s module;

// - MONO classes -
extern built_in_class_s *mono_classes[];

// - MONO error identifiers -
enum
{
  c_error_MONO_ASSEMBLY_DUMMY_ERROR = 0,
};

// - MONO error strings -
extern const char *mono_error_strings[];

// - MONO initialize -
bool mono_initialize(script_parser_s &sp);

// - MONO print exception -
bool mono_print_exception(interpreter_s &it,exception_s &exception);

// - class MONO_ASSEMBLY -
extern built_in_variable_s mono_assembly_variables[];
extern built_in_method_s mono_assembly_methods[];
extern built_in_class_s mono_assembly_class;

void bic_mono_assembly_consts(location_array_s &const_locations);
void bic_mono_assembly_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mono_assembly_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mono_assembly_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_MonoAssembly_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

