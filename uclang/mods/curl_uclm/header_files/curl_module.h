
#ifndef __CURL_MODULE_H
#define __CURL_MODULE_H

@begin
include "ucl_curl.h"
@end

// - CURL indexes of built in classes -
extern unsigned c_bi_class_curl;
extern unsigned c_bi_class_curl_result;

// - CURL module -
extern built_in_module_s module;

// - CURL classes -
extern built_in_class_s *curl_classes[];

// - CURL error identifiers -
enum
{
  c_error_CURL_CANNOT_CREATE_SESSION = 0,
  c_error_CURL_ERROR_WHILE_PERFORMING_GET_REQUEST,
  c_error_CURL_ERROR_WHILE_PERFORMING_PUT_REQUEST,
  c_error_CURL_ERROR_WHILE_PERFORMING_POST_REQUEST,
  c_error_CURL_ERROR_WHILE_PERFORMING_DELETE_REQUEST,
  c_error_CURL_ERROR_WHILE_PERFORMING_HEAD_REQUEST,
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

// - class CURL_RESULT -
extern built_in_variable_s curl_result_variables[];
extern built_in_method_s curl_result_methods[];
extern built_in_class_s curl_result_class;

void bic_curl_result_consts(location_array_s &const_locations);
void bic_curl_result_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_curl_result_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_curl_result_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curl_result_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

