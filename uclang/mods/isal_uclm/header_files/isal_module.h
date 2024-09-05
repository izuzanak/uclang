
#ifndef __ISAL_MODULE_H
#define __ISAL_MODULE_H

@begin
include "ucl_isal.h"
@end

// - ISAL indexes of built in classes -
extern unsigned c_bi_class_isal_crc_16;

// - ISAL module -
extern "C" EXPORT built_in_module_s module;

// - ISAL classes -
extern built_in_class_s *isal_classes[];

// - ISAL error identifiers -
enum
{
  c_error_ISAL_DUMMY_ERROR = 0,
};

// - ISAL error strings -
extern const char *isal_error_strings[];

// - ISAL initialize -
bool isal_initialize(script_parser_s &sp);

// - ISAL print exception -
bool isal_print_exception(interpreter_s &it,exception_s &exception);

// - class ISAL_CRC_16 -
extern built_in_variable_s isal_crc_16_variables[];
extern built_in_method_s isal_crc_16_methods[];
extern built_in_class_s isal_crc_16_class;

void bic_isal_crc_16_consts(location_array_s &const_locations);
void bic_isal_crc_16_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_isal_crc_16_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_isal_crc_16_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_isal_crc_16_method_IsalCrc16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_isal_crc_16_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_isal_crc_16_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_isal_crc_16_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_isal_crc_16_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

