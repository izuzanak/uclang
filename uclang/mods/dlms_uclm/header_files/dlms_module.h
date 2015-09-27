
#ifndef __DLMS_MODULE_H
#define __DLMS_MODULE_H

@begin
include "ucl_dlms.h"
@end

// - DLMS indexes of built in classes -
extern unsigned c_bi_class_dlms_server;
extern unsigned c_bi_class_dlms_object;

// - DLMS module -
extern built_in_module_s module;

// - DLMS classes -
extern built_in_class_s *dlms_classes[];

// - DLMS error identifiers -
enum
{
  c_error_DLMS_SERVER_INVALID_MANUFACTURER_ID = 0,
  c_error_DLMS_SERVER_INVALID_SERIAL_NUMBER,
  c_error_DLMS_SERVER_INVALID_PORT_VALUE,
  c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_SIZE,
  c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_VALUE_TYPE,
  c_error_DLMS_SERVER_CREATE_ERROR,
  c_error_DLMS_SERVER_OBJECT_CODE_NOT_FOUND,
  c_error_DLMS_SERVER_OBJECT_INDEX_EXCEEDS_RANGE,
  c_error_DLMS_OBJECT_UNSUPPORTED_OBJECT_TYPE,
  c_error_DLMS_OBJECT_UNSUPPORTED_DATA_TYPE,
  c_error_DLMS_OBJECT_WRITE_WRONG_TYPE,
};

// - DLMS error strings -
extern const char *dlms_error_strings[];

// - DLMS initialize -
bool dlms_initialize(script_parser_s &sp);

// - DLMS print exception -
bool dlms_print_exception(interpreter_s &it,exception_s &exception);

// - class DLMS_SERVER -
extern built_in_variable_s dlms_server_variables[];
extern built_in_method_s dlms_server_methods[];
extern built_in_class_s dlms_server_class;

void bic_dlms_server_consts(location_array_s &const_locations);
void bic_dlms_server_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_dlms_server_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_dlms_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_DlmsServer_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DLMS_OBJECT -
extern built_in_variable_s dlms_object_variables[];
extern built_in_method_s dlms_object_methods[];
extern built_in_class_s dlms_object_class;

void bic_dlms_object_consts(location_array_s &const_locations);
void bic_dlms_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_dlms_object_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_dlms_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_object_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_data_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_value_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dlms_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

