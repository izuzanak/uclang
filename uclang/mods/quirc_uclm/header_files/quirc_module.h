
#ifndef __QUIRC_MODULE_H
#define __QUIRC_MODULE_H

@begin
include "ucl_quirc.h"
@end

// - QUIRC indexes of built in classes -
extern unsigned c_bi_class_quirc;
extern unsigned c_bi_class_quirc_code;
extern unsigned c_bi_class_quirc_data;

// - QUIRC module -
extern "C" EXPORT built_in_module_s module;

// - QUIRC classes -
extern built_in_class_s *quirc_classes[];

// - QUIRC error identifiers -
enum
{
  c_error_QUIRC_INDEX_DOES_NOT_REFER_TO_VALID_VALUE = 0,
  c_error_QUIRC_INVALID_IMAGE_SIZE_PROPERTIES,
  c_error_QUIRC_CREATE_INSTANCE_ERROR,
  c_error_QUIRC_PTROCESS_INVALID_DATA_SIZE,
  c_error_QUIRC_CODE_DECODE_DATA_ERROR,
};

// - QUIRC error strings -
extern const char *quirc_error_strings[];

// - QUIRC initialize -
bool quirc_initialize(script_parser_s &sp);

// - QUIRC print exception -
bool quirc_print_exception(interpreter_s &it,exception_s &exception);

// - class QUIRC -
extern built_in_variable_s quirc_variables[];
extern built_in_method_s quirc_methods[];
extern built_in_class_s quirc_class;

void bic_quirc_consts(location_array_s &const_locations);
void bic_quirc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_quirc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_quirc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_Quirc_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class QUIRC_CODE -
extern built_in_variable_s quirc_code_variables[];
extern built_in_method_s quirc_code_methods[];
extern built_in_class_s quirc_code_class;

void bic_quirc_code_consts(location_array_s &const_locations);
void bic_quirc_code_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_quirc_code_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_quirc_code_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_code_method_decode_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_code_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_code_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class QUIRC_DATA -
extern built_in_variable_s quirc_data_variables[];
extern built_in_method_s quirc_data_methods[];
extern built_in_class_s quirc_data_class;

void bic_quirc_data_consts(location_array_s &const_locations);
void bic_quirc_data_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_quirc_data_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_quirc_data_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_data_method_payload_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_data_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_quirc_data_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

