
#ifndef __QRENCODE_MODULE_H
#define __QRENCODE_MODULE_H

@begin
include "ucl_qrencode.h"
@end

// - QRENCODE indexes of built in classes -
extern unsigned c_bi_class_qr_code;

// - QRENCODE module -
extern "C" EXPORT built_in_module_s module;

// - QRENCODE classes -
extern built_in_class_s *qrencode_classes[];

// - QRENCODE error identifiers -
enum
{
  c_error_QRENCODE_QRCODE_ENCODE_ERROR = 0,
};

// - QRENCODE error strings -
extern const char *qrencode_error_strings[];

// - QRENCODE initialize -
bool qrencode_initialize(script_parser_s &sp);

// - QRENCODE print exception -
bool qrencode_print_exception(interpreter_s &it,exception_s &exception);

// - class QR_CODE -
extern built_in_variable_s qr_code_variables[];
extern built_in_method_s qr_code_methods[];
extern built_in_class_s qr_code_class;

void bic_qr_code_consts(location_array_s &const_locations);
void bic_qr_code_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_qr_code_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_qr_code_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_encode_string_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_encode_data_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_qr_code_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

