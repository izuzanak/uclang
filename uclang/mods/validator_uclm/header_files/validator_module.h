
#ifndef __VALIDATOR_MODULE_H
#define __VALIDATOR_MODULE_H

@begin
include "ucl_validator.h"
@end

// - VALIDATOR indexes of built in classes -
extern unsigned c_bi_class_validator;

// - VALIDATOR module -
extern "C" IMPORT built_in_module_s module;

// - VALIDATOR classes -
extern built_in_class_s *validator_classes[];

// - VALIDATOR error strings -
extern const char *validator_error_strings[];

// - VALIDATOR initialize -
bool validator_initialize(script_parser_s &sp);

// - VALIDATOR print exception -
bool validator_print_exception(interpreter_s &it,exception_s &exception);

// - class VALIDATOR -
extern built_in_variable_s validator_variables[];
extern built_in_method_s validator_methods[];
extern built_in_class_s validator_class;

void bic_validator_consts(location_array_s &const_locations);
void bic_validator_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_validator_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_validator_method_Validator_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_validator_method_validate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_validator_method_value_stack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_validator_method_props_stack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_validator_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_validator_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

