
#ifndef __TCP_MODULE_H
#define __TCP_MODULE_H

@begin
include "ucl_tcp.h"
@end

// - TCP indexes of built in classes -
extern unsigned c_bi_class_tcp_server;
extern unsigned c_bi_class_tcp_client;

// - TCP module -
extern "C" EXPORT built_in_module_s module;

// - TCP classes -
extern built_in_class_s *tcp_classes[];

// - TCP error identifiers -
enum
{
  c_error_TCP_SERVER_WRONG_DELEGATE_PARAMETER_COUNT = 0,
  c_error_TCP_SERVER_INVALID_IP_ADDRESS,
  c_error_TCP_SERVER_CREATE_ERROR,
  c_error_TCP_SERVER_ACCEPT_ERROR,
  c_error_TCP_SERVER_PROCESS_INVALID_FD,
  c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,
  c_error_TCP_SERVER_SSL_ALREADY_INITIALIZED,
  c_error_TCP_SERVER_SSL_NOT_INITIALIZED,
  c_error_TCP_SERVER_SSL_INIT_ERROR,
  c_error_TCP_SERVER_SSL_CERTIFICATE_FILE_ERROR,
  c_error_TCP_SERVER_SSL_PRIVATE_KEY_FILE_ERROR,
  c_error_TCP_SERVER_SSL_ACCEPT_ERROR,
  c_error_TCP_SERVER_CONN_SSL_ALREADY_INITIALIZED,
  c_error_TCP_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,
  c_error_TCP_CLIENT_INVALID_IP_ADDRESS,
  c_error_TCP_CLIENT_CREATE_ERROR,
  c_error_TCP_CLIENT_PROCESS_INVALID_FD,
  c_error_TCP_CLIENT_NOT_CONNECTED,
  c_error_TCP_CLIENT_SSL_ALREADY_INITIALIZED,
  c_error_TCP_CLIENT_SSL_INIT_ERROR,
};

// - TCP error strings -
extern const char *tcp_error_strings[];

// - TCP initialize -
bool tcp_initialize(script_parser_s &sp);

// - TCP print exception -
bool tcp_print_exception(interpreter_s &it,exception_s &exception);

// - class TCP_SERVER -
extern built_in_variable_s tcp_server_variables[];
extern built_in_method_s tcp_server_methods[];
extern built_in_class_s tcp_server_class;

void bic_tcp_server_consts(location_array_s &const_locations);
void bic_tcp_server_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcp_server_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcp_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_TcpServer_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef UCL_WITH_OPENSSL
bool bic_tcp_server_method_init_ssl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_conn_ssl_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_tcp_server_method_conn_fd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_message_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCP_CLIENT -
extern built_in_variable_s tcp_client_variables[];
extern built_in_method_s tcp_client_methods[];
extern built_in_class_s tcp_client_class;

void bic_tcp_client_consts(location_array_s &const_locations);
void bic_tcp_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcp_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcp_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_TcpClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef UCL_WITH_OPENSSL
bool bic_tcp_client_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_tcp_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_message_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcp_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

