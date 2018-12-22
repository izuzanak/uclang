
#ifndef __MPG_MODULE_H
#define __MPG_MODULE_H

@begin
include "ucl_mpg.h"
@end

// - MPG indexes of built in classes -
extern unsigned c_bi_class_mpg;
extern unsigned c_bi_class_mpg_handle;

// - MPG module -
extern "C" EXPORT built_in_module_s module;

// - MPG classes -
extern built_in_class_s *mpg_classes[];

// - MPG error identifiers -
enum
{
  c_error_MPG_HANDLE_CREATE_NEW_ERROR = 0,
  c_error_MPG_HANDLE_ALREADY_OPENED,
  c_error_MPG_HANDLE_NOT_OPENED,
  c_error_MPG_HANDLE_NOT_OPENED_IN_FEED_MODE,
  c_error_MPG_HANDLE_OPEN_FILE_ERROR,
  c_error_MPG_HANDLE_OPEN_FEED_ERROR,
  c_error_MPG_HANDLE_UNKNOWN_PARAMETER_ID,
  c_error_MPG_HANDLE_WRONG_PARAMETER_VALUE_TYPE,
  c_error_MPG_HANDLE_PARAMETER_SET_ERROR,
  c_error_MPG_HANDLE_PARAMETER_GET_ERROR,
  c_error_MPG_HANDLE_VOLUME_SET_ERROR,
  c_error_MPG_HANDLE_VOLUME_GET_ERROR,
  c_error_MPG_HANDLE_FEED_ERROR,
  c_error_MPG_HANDLE_READ_WRONG_BUFFER_SIZE,
  c_error_MPG_HANDLE_ADJUST_OUTPUT_FORMAT_ERROR,
  c_error_MPG_HANDLE_READ_ERROR,
  c_error_MPG_HANDLE_CLOSE_ERROR,
};

// - MPG error strings -
extern const char *mpg_error_strings[];

// - MPG initialize -
bool mpg_initialize(script_parser_s &sp);

// - MPG print exception -
bool mpg_print_exception(interpreter_s &it,exception_s &exception);

// - class MPG -
extern built_in_variable_s mpg_variables[];
extern built_in_method_s mpg_methods[];
extern built_in_class_s mpg_class;

void bic_mpg_consts(location_array_s &const_locations);
void bic_mpg_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mpg_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mpg_method_decoders_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_method_supported_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_method_feature_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MPG_HANDLE -
extern built_in_variable_s mpg_handle_variables[];
extern built_in_method_s mpg_handle_methods[];
extern built_in_class_s mpg_handle_class;

void bic_mpg_handle_consts(location_array_s &const_locations);
void bic_mpg_handle_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mpg_handle_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mpg_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_MpgHandle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_MpgHandle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_open_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_open_feed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_set_param_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_get_param_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_volume_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_volume_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_rate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_channels_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_encoding_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_feed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mpg_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

