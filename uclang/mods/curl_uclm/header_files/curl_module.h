
#ifndef __CURL_MODULE_H
#define __CURL_MODULE_H

@begin
include "ucl_curl.h"
@end

// - CURL indexes of built in classes -
extern unsigned c_bi_class_curl;
extern unsigned c_bi_class_curl_multi;
extern unsigned c_bi_class_curl_multi_request;
extern unsigned c_bi_class_curl_result;

// - CURL module -
extern "C" IMPORT built_in_module_s module;

// - CURL classes -
extern built_in_class_s *curl_classes[];

// - CURL error identifiers -
enum
{
  c_error_CURL_CANNOT_CREATE_SESSION = 0,
  c_error_CURL_ERROR_WHILE_PERFORMING_HTTP_REQUEST,
  c_error_CURL_HTTP_HEADER_EXPECTED_STRING,
  c_error_CURL_MULTI_WRONG_CALLBACK_DELEGATE,
  c_error_CURL_MULTI_CANNOT_CREATE_SESSION,
  c_error_CURL_MULTI_CANNOT_ADD_HANDLER,
  c_error_CURL_MULTI_SOCKET_ACTION_ERROR,
  c_error_CURL_MULTI_INVALID_REQUEST_INDEX,
  c_error_CURL_MULTI_POLL_ERROR,
  c_error_CURL_MULTI_REQUEST_INVALID_REFERENCE,
  c_error_CURL_MULTI_REQUEST_UNSUPPORTED_OPTION_TYPE,
  c_error_CURL_MULTI_REQUEST_WRONG_OPTION_VALUE_TYPE,
  c_error_CURL_RESULT_UNSUPPORTED_INFO_VALUE_TYPE,
  c_error_CURL_RESULT_ERROR_WHILE_GET_INFO,
};

// - CURL error strings -
extern const char *curl_error_strings[];

// - CURL initialize -
bool curl_initialize(script_parser_s &sp);

// - CURL print exception -
bool curl_print_exception(interpreter_s &it,exception_s &exception);

// - class CURL -
extern built_in_variable_s curl_variables[];
extern built_in_method_s curl_methods[];
extern built_in_class_s curl_class;

void bic_curl_consts(location_array_s &const_locations);
void bic_curl_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_curl_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_curl_method_GET_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_method_PUT_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_method_POST_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_method_DELETE_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_method_HEAD_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CURL_MULTI -
extern built_in_variable_s curl_multi_variables[];
extern built_in_method_s curl_multi_methods[];
extern built_in_class_s curl_multi_class;

void bic_curl_multi_consts(location_array_s &const_locations);
void bic_curl_multi_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_curl_multi_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_curl_multi_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_CurlMulti_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_GET_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_PUT_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_POST_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_DELETE_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_HEAD_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CURL_MULTI_REQUEST -
extern built_in_variable_s curl_multi_request_variables[];
extern built_in_method_s curl_multi_request_methods[];
extern built_in_class_s curl_multi_request_class;

void bic_curl_multi_request_consts(location_array_s &const_locations);
void bic_curl_multi_request_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_curl_multi_request_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_curl_multi_request_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_request_method_add_headers_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_request_method_setopt_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_request_method_cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_request_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_multi_request_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CURL_RESULT -
extern built_in_variable_s curl_result_variables[];
extern built_in_method_s curl_result_methods[];
extern built_in_class_s curl_result_class;

void bic_curl_result_consts(location_array_s &const_locations);
void bic_curl_result_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_curl_result_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_curl_result_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

