
#ifndef __CHANNEL_MODULE_H
#define __CHANNEL_MODULE_H

@begin
include "ucl_channel.h"
@end

// - CHANNEL indexes of built in classes -
extern unsigned c_bi_class_channel_server;

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
bool bic_channel_server_method_ChannelServer_6(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_message_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_multi_message_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_channel_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

