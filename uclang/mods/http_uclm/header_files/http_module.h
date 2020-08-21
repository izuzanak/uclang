
#ifndef __HTTP_MODULE_H
#define __HTTP_MODULE_H

@begin
include "ucl_http.h"
@end

// - HTTP indexes of built in classes -
extern unsigned c_bi_class_http_server;
extern unsigned c_bi_class_http_conn;
extern unsigned c_bi_class_http_resp;
extern unsigned c_bi_class_http_post_proc;

// - HTTP module -
extern "C" EXPORT built_in_module_s module;

// - HTTP classes -
extern built_in_class_s *http_classes[];

// - HTTP error identifiers -
enum
{
  c_error_HTTP_SERVER_WRONG_CALLBACK_DELEGATE = 0,
  c_error_HTTP_SERVER_CANNOT_START_DAEMON,
  c_error_HTTP_SERVER_INTERNAL_ERROR,
  c_error_HTTP_SERVER_WAS_STOPPED,
  c_error_HTTP_SERVER_EXPECTED_INTEGER_AS_OPTION_ID,
  c_error_HTTP_SERVER_UNKNOWN_OPTION_ID,
  c_error_HTTP_SERVER_INVALID_OPTION_VALUE_TYPE,
  c_error_HTTP_CONN_UNKNOWN_VALUES_TYPE,
  c_error_HTTP_CONN_ALREADY_SUSPENDED,
  c_error_HTTP_CONN_NOT_SUSPENDED,
  c_error_HTTP_CONN_CANNOT_QUEUE_RESPONSE,
  c_error_HTTP_CONN_CANNOT_RETRIEVE_CLIENT_IP,
  c_error_HTTP_RESP_CREATE_ERROR,
  c_error_HTTP_RESP_UNKNOWN_DATA_SOURCE_IDENTIFIER,
  c_error_HTTP_RESP_CANNOT_READ_SOURCE_FILE,
  c_error_HTTP_RESP_CANNOT_ADD_HEADER_FOOTER,
  c_error_HTTP_POST_PROC_BUFFER_TOO_SMALL,
  c_error_HTTP_POST_PROC_WRONG_CALLBACK_DELEGATE,
  c_error_HTTP_POST_PROC_CREATE_ERROR,
  c_error_HTTP_POST_PROC_INTERNAL_ERROR,
};

// - HTTP error strings -
extern const char *http_error_strings[];

// - HTTP initialize -
bool http_initialize(script_parser_s &sp);

// - HTTP print exception -
bool http_print_exception(interpreter_s &it,exception_s &exception);

// - class HTTP_SERVER -
extern built_in_variable_s http_server_variables[];
extern built_in_method_s http_server_methods[];
extern built_in_class_s http_server_class;

void bic_http_server_consts(location_array_s &const_locations);
void bic_http_server_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_http_server_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_http_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_HttpServer_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class HTTP_CONN -
extern built_in_variable_s http_conn_variables[];
extern built_in_method_s http_conn_methods[];
extern built_in_class_s http_conn_class;

void bic_http_conn_consts(location_array_s &const_locations);
void bic_http_conn_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_http_conn_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_http_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_url_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_method_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_upload_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_values_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_http_conn_method_value_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_client_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_suspend_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_resume_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_queue_response_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_queue_basic_auth_fail_response_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_basic_auth_username_password_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_queue_digest_auth_fail_response_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_digest_auth_username_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_digest_auth_check_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_post_processor_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class HTTP_RESP -
extern built_in_variable_s http_resp_variables[];
extern built_in_method_s http_resp_methods[];
extern built_in_class_s http_resp_class;

void bic_http_resp_consts(location_array_s &const_locations);
void bic_http_resp_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_http_resp_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_http_resp_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_resp_method_HttpResp_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_resp_method_HttpResp_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_resp_method_add_header_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_resp_method_add_footer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_resp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_resp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class HTTP_POST_PROC -
extern built_in_variable_s http_post_proc_variables[];
extern built_in_method_s http_post_proc_methods[];
extern built_in_class_s http_post_proc_class;

void bic_http_post_proc_consts(location_array_s &const_locations);
void bic_http_post_proc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_http_post_proc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_http_post_proc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_http_post_proc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

