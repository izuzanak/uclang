
#ifndef __INTELHEX_MODULE_H
#define __INTELHEX_MODULE_H

@begin
include "ucl_intelhex.h"
@end

// - INTELHEX indexes of built in classes -
extern unsigned c_bi_class_intel_hex;

// - INTELHEX module -
extern built_in_module_s module;

// - INTELHEX classes -
extern built_in_class_s *intelhex_classes[];

// - INTELHEX error identifiers -
enum
{
  c_error_INTEL_HEX_FILE_OPEN_ERROR = 0,
  c_error_INTEL_HEX_WRONG_CALLBACK_DELEGATE,
  c_error_INTEL_HEX_INVALID_RECORD_LENGTH,
  c_error_INTEL_HEX_INVALID_RECORD_DATA,
  c_error_INTEL_HEX_INVALID_RECORD_TYPE,
  c_error_INTEL_HEX_UNEXPECTED_DATA_END,
};

// - INTELHEX error strings -
extern const char *intelhex_error_strings[];

// - INTELHEX initialize -
bool intelhex_initialize(script_parser_s &sp);

// - INTELHEX print exception -
bool intelhex_print_exception(interpreter_s &it,exception_s &exception);

// - class INTEL_HEX -
extern built_in_variable_s intel_hex_variables[];
extern built_in_method_s intel_hex_methods[];
extern built_in_class_s intel_hex_class;

void bic_intel_hex_consts(location_array_s &const_locations);
void bic_intel_hex_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_intel_hex_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_intel_hex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_IntelHex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_IntelHex_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_esa_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_ssa_cs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_ssa_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_ela_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_sla_eip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_intel_hex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

