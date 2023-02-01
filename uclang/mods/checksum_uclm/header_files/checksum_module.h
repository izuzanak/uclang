
#ifndef __CHECKSUM_MODULE_H
#define __CHECKSUM_MODULE_H

@begin
include "ucl_checksum.h"
@end

// - CHECKSUM indexes of built in classes -
extern unsigned c_bi_class_bcc;
extern unsigned c_bi_class_crc_16;
extern unsigned c_bi_class_crc_32;

// - CHECKSUM module -
extern "C" EXPORT built_in_module_s module;

// - CHECKSUM classes -
extern built_in_class_s *checksum_classes[];

// - CHECKSUM error identifiers -
enum
{
  c_error_CHECKSUM_DUMMY_ERROR = 0,
};

// - CHECKSUM error strings -
extern const char *checksum_error_strings[];

// - CHECKSUM initialize -
bool checksum_initialize(script_parser_s &sp);

// - CHECKSUM print exception -
bool checksum_print_exception(interpreter_s &it,exception_s &exception);

// - class BCC -
extern built_in_variable_s bcc_variables[];
extern built_in_method_s bcc_methods[];
extern built_in_class_s bcc_class;

void bic_bcc_consts(location_array_s &const_locations);
void bic_bcc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bcc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_bcc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_Bcc_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRC_16 -
extern built_in_variable_s crc_16_variables[];
extern built_in_method_s crc_16_methods[];
extern built_in_class_s crc_16_class;

void bic_crc_16_consts(location_array_s &const_locations);
void bic_crc_16_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crc_16_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crc_16_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_16_method_Crc16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_16_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_16_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_16_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_16_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRC_32 -
extern built_in_variable_s crc_32_variables[];
extern built_in_method_s crc_32_methods[];
extern built_in_class_s crc_32_class;

void bic_crc_32_consts(location_array_s &const_locations);
void bic_crc_32_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crc_32_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crc_32_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_32_method_Crc32_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_32_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_32_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_32_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_32_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

