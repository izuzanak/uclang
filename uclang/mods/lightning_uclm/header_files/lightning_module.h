
#ifndef __LTG_MODULE_H
#define __LTG_MODULE_H

@begin
include "ucl_lightning.h"
@end

// - LIGHTNING indexes of built in classes -
extern unsigned c_bi_class_ltg_jit_state;

// - LIGHTNING module -
extern "C" EXPORT built_in_module_s module;

// - LIGHTNING classes -
extern built_in_class_s *lightning_classes[];

// - LIGHTNING error identifiers -
// - moved to file lightning_parser.h -

// - LIGHTNING error strings -
extern const char *lightning_error_strings[];

// - LIGHTNING initialize -
bool lightning_initialize(script_parser_s &sp);

// - LIGHTNING print exception -
bool lightning_print_exception(interpreter_s &it,exception_s &exception);

// - class LTG_JIT_STATE -
extern built_in_variable_s ltg_jit_state_variables[];
extern built_in_method_s ltg_jit_state_methods[];
extern built_in_class_s ltg_jit_state_class;

void bic_ltg_jit_state_consts(location_array_s &const_locations);
void bic_ltg_jit_state_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ltg_jit_state_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ltg_jit_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ltg_jit_state_method_LtgJitState_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ltg_jit_state_method_create_fun_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ltg_jit_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ltg_jit_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

