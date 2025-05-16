
#ifndef __CHANNEL_MODULE_H
#define __CHANNEL_MODULE_H

@begin
include "ucl_channel.h"
@end

// - CHANNEL module -
extern "C" EXPORT built_in_module_s module;

// - CHANNEL classes -
extern built_in_class_s *channel_classes[];

// - CHANNEL error identifiers -
enum
{
  c_error_CHANNEL_SERVER_WRONG_DELEGATE_PARAMETER_COUNT = 0,
  c_error_CHANNEL_SERVER_INVALID_IP_ADDRESS,
  c_error_CHANNEL_SERVER_CREATE_ERROR,
  c_error_CHANNEL_SERVER_ACCEPT_ERROR,
  c_error_CHANNEL_SERVER_PROCESS_INVALID_FD,
  c_error_CHANNEL_SERVER_MESSAGE_INVALID_CONNECTION_INDEX,
  c_error_CHANNEL_SERVER_SSL_ALREADY_INITIALIZED,
  c_error_CHANNEL_SERVER_SSL_INIT_ERROR,
  c_error_CHANNEL_SERVER_SSL_CERTIFICATE_FILE_ERROR,
  c_error_CHANNEL_SERVER_SSL_PRIVATE_KEY_FILE_ERROR,
  c_error_CHANNEL_SERVER_SSL_ACCEPT_ERROR,
  c_error_CHANNEL_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,
  c_error_CHANNEL_CLIENT_INVALID_IP_ADDRESS,
  c_error_CHANNEL_CLIENT_CREATE_ERROR,
  c_error_CHANNEL_CLIENT_PROCESS_INVALID_FD,
  c_error_CHANNEL_CLIENT_NOT_CONNECTED,
  c_error_CHANNEL_CLIENT_SSL_ALREADY_INITIALIZED,
  c_error_CHANNEL_CLIENT_SSL_INIT_ERROR,
};

// - CHANNEL error strings -
extern const char *channel_error_strings[];

// - CHANNEL initialize -
bool channel_initialize(script_parser_s &sp);

// - CHANNEL print exception -
bool channel_print_exception(interpreter_s &it,exception_s &exception);

// - class CHANNEL_SERVER -
extern built_in_variable_s channel_server_variables[];
extern built_in_method_s channel_server_methods[];
extern built_in_class_s channel_server_class;

void bic_channel_server_consts(location_array_s &const_locations);
void bic_channel_server_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_channel_server_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_channel_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_ChannelServer_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef UCL_WITH_OPENSSL
bool bic_channel_server_method_init_ssl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_channel_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_message_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_address_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_out_queue_len_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CHANNEL_CLIENT -
extern built_in_variable_s channel_client_variables[];
extern built_in_method_s channel_client_methods[];
extern built_in_class_s channel_client_class;

void bic_channel_client_consts(location_array_s &const_locations);
void bic_channel_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_channel_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_channel_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_ChannelClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef UCL_WITH_OPENSSL
bool bic_channel_client_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_channel_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_message_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_out_queue_len_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

