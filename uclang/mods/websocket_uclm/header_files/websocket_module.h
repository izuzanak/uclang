
#ifndef __WEBSOCKET_MODULE_H
#define __WEBSOCKET_MODULE_H

@begin
include "ucl_websocket.h"
@end

// - WEBSOCKET indexes of built in classes -
extern unsigned c_bi_class_ws_context;
extern unsigned c_bi_class_ws_conn;
extern unsigned c_bi_class_ws_client;
extern unsigned c_bi_class_ws_base64;

// - WEBSOCKET module -
extern "C" EXPORT built_in_module_s module;

// - WEBSOCKET classes -
extern built_in_class_s *websocket_classes[];

// - WEBSOCKET error identifiers -
enum
{
  c_error_WS_CONTEXT_CREATE_ERROR = 0,
  c_error_WS_CONTEXT_EMPTY_PROTOCOL_ARRAY,
  c_error_WS_CONTEXT_NOT_EVEN_PROTOCOL_ARRAY,
  c_error_WS_CONTEXT_WRONG_PAIR_NAME_DELEGATE,
  c_error_WS_CONTEXT_WRONG_CALLBACK_DELEGATE,
  c_error_WS_CONTEXT_CANNOT_CREATE_CLIENT_CONNECTION,
  c_error_WS_CONTEXT_PROTOCOL_NAME_NOT_FOUND,
  c_error_WS_CONTEXT_PROTOCOL_INDEX_EXCEEDS_RANGE,
  c_error_WS_CONN_SET_TIMEOUT_UNKNOWN_REASON,
  c_error_WS_CONN_SET_TIMEOUT_WRONG_VALUE,
  c_error_WS_CONN_WRITE_ERROR,
  c_error_WS_CLIENT_NOT_CONNECTED_TO_SERVER,
  c_error_WS_BASE64_ENCODE_ERROR,
  c_error_WS_BASE64_DECODE_ERROR,
};

// - WEBSOCKET error strings -
extern const char *websocket_error_strings[];

// - WEBSOCKET initialize -
bool websocket_initialize(script_parser_s &sp);

// - WEBSOCKET print exception -
bool websocket_print_exception(interpreter_s &it,exception_s &exception);

// - class WS_CONTEXT -
extern built_in_variable_s ws_context_variables[];
extern built_in_method_s ws_context_methods[];
extern built_in_class_s ws_context_class;

void bic_ws_context_consts(location_array_s &const_locations);
void bic_ws_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ws_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ws_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_WsContext_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_client_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_protocol_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_callback_on_writable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class WS_CONN -
extern built_in_variable_s ws_conn_variables[];
extern built_in_method_s ws_conn_methods[];
extern built_in_class_s ws_conn_class;

void bic_ws_conn_consts(location_array_s &const_locations);
void bic_ws_conn_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ws_conn_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ws_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_reason_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_received_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_ctx_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_protocol_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_callback_on_writable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_set_timeout_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class WS_CLIENT -
extern built_in_variable_s ws_client_variables[];
extern built_in_method_s ws_client_methods[];
extern built_in_class_s ws_client_class;

void bic_ws_client_consts(location_array_s &const_locations);
void bic_ws_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ws_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ws_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_client_method_connected_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_client_method_callback_on_writable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class WS_BASE64 -
extern built_in_variable_s ws_base64_variables[];
extern built_in_method_s ws_base64_methods[];
extern built_in_class_s ws_base64_class;

void bic_ws_base64_consts(location_array_s &const_locations);
void bic_ws_base64_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ws_base64_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ws_base64_method_encode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_base64_method_decode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_base64_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ws_base64_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

