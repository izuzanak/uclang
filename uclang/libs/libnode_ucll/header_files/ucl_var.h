
#ifndef __UCL_VAR_H
#define __UCL_VAR_H

@begin
include "script_parser.h"
@end

#include <string>

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#if SYSTEM_TYPE_UNIX_SOCKET == ENABLED
#define ENABLE_CLASS_SOCKET
#endif
#define ENABLE_CLASS_REGEX
#endif

// - max method name length -
const unsigned c_max_method_name_length = 256;

// - callback prototypes -
typedef class UclVar UclVar;
typedef UclVar (*t_node_callback_0)();
typedef UclVar (*t_node_callback_1)(UclVar);
typedef UclVar (*t_node_callback_2)(UclVar,UclVar);

// - uclang uclvar modules -
enum
{/*{{{*/
  c_uclvar_module_base = 0,
  c_uclvar_module_node,
  c_uclvar_module_sys,
  c_uclvar_module_containers,
  c_uclvar_module_json,
  c_uclvar_module_websocket,
  c_uclvar_module_jit,
  c_uclvar_module_count
};/*}}}*/

// - retrieve length of C style array -
#define ARRAY_LENGTH(ARRAY) sizeof(ARRAY)/sizeof(*ARRAY)

// - definition of class UclVar -
class UclVar
{/*{{{*/
  friend bool bic_node_callback_method_call_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
  friend bool bic_node_callback_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
  friend bool bic_node_callback_method_call_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);

  private:
  static interpreter_thread_s *it_ptr;
  static pointer_array_s static_const_array;
  location_s *location_ptr;

  // - built in class indexes declaration -
  static unsigned c_bi_class_Blank;
  static unsigned c_bi_class_Char;
  static unsigned c_bi_class_Integer;
  static unsigned c_bi_class_Float;
  static unsigned c_bi_class_String;
  static unsigned c_bi_class_Array;
  static unsigned c_bi_class_Error;
  static unsigned c_bi_class_Exception;
  static unsigned c_bi_class_Type;
  static unsigned c_bi_class_Mutex;
  static unsigned c_bi_class_Thread;
  static unsigned c_bi_class_Delegate;
  static unsigned c_bi_class_Buffer;
  static unsigned c_bi_class_NodeCallback;
  static unsigned c_bi_class_Sys;
  static unsigned c_bi_class_Pipe;
  static unsigned c_bi_class_File;
  static unsigned c_bi_class_SocketAddr;
  static unsigned c_bi_class_Socket;
  static unsigned c_bi_class_Regex;
  static unsigned c_bi_class_Signal;
  static unsigned c_bi_class_Poll;
  static unsigned c_bi_class_Timer;
  static unsigned c_bi_class_Clock;
  static unsigned c_bi_class_Stack;
  static unsigned c_bi_class_Queue;
  static unsigned c_bi_class_Set;
  static unsigned c_bi_class_List;
  static unsigned c_bi_class_Tree;
  static unsigned c_bi_class_Dict;
  static unsigned c_bi_class_Json;
  static unsigned c_bi_class_WsContext;
  static unsigned c_bi_class_WsConn;
  static unsigned c_bi_class_WsClient;
  static unsigned c_bi_class_WsBase64;
  static unsigned c_bi_class_JitContext;
  static unsigned c_bi_class_JitFunction;

  // - built in method name indexes declaration -
  static unsigned c_bi_mni_operator_binary_equal_1;
  static unsigned c_bi_mni_operator_binary_plus_equal_1;
  static unsigned c_bi_mni_operator_binary_minus_equal_1;
  static unsigned c_bi_mni_operator_binary_asterisk_equal_1;
  static unsigned c_bi_mni_operator_binary_slash_equal_1;
  static unsigned c_bi_mni_operator_binary_percent_equal_1;
  static unsigned c_bi_mni_operator_binary_double_ls_br_equal_1;
  static unsigned c_bi_mni_operator_binary_double_rs_br_equal_1;
  static unsigned c_bi_mni_operator_binary_ampersand_equal_1;
  static unsigned c_bi_mni_operator_binary_pipe_equal_1;
  static unsigned c_bi_mni_operator_binary_circumflex_equal_1;
  static unsigned c_bi_mni_operator_binary_double_ampersand_1;
  static unsigned c_bi_mni_operator_binary_double_pipe_1;
  static unsigned c_bi_mni_operator_binary_ampersand_1;
  static unsigned c_bi_mni_operator_binary_pipe_1;
  static unsigned c_bi_mni_operator_binary_circumflex_1;
  static unsigned c_bi_mni_operator_binary_double_equal_1;
  static unsigned c_bi_mni_operator_binary_exclamation_equal_1;
  static unsigned c_bi_mni_operator_binary_rs_br_1;
  static unsigned c_bi_mni_operator_binary_ls_br_1;
  static unsigned c_bi_mni_operator_binary_rs_br_equal_1;
  static unsigned c_bi_mni_operator_binary_ls_br_equal_1;
  static unsigned c_bi_mni_operator_binary_double_rs_br_1;
  static unsigned c_bi_mni_operator_binary_double_ls_br_1;
  static unsigned c_bi_mni_operator_binary_plus_1;
  static unsigned c_bi_mni_operator_binary_minus_1;
  static unsigned c_bi_mni_operator_binary_asterisk_1;
  static unsigned c_bi_mni_operator_binary_slash_1;
  static unsigned c_bi_mni_operator_binary_percent_1;
  static unsigned c_bi_mni_operator_unary_post_double_plus_0;
  static unsigned c_bi_mni_operator_unary_post_double_minus_0;
  static unsigned c_bi_mni_operator_unary_pre_double_plus_0;
  static unsigned c_bi_mni_operator_unary_pre_double_minus_0;
  static unsigned c_bi_mni_operator_unary_pre_plus_0;
  static unsigned c_bi_mni_operator_unary_pre_minus_0;
  static unsigned c_bi_mni_operator_unary_pre_exclamation_0;
  static unsigned c_bi_mni_operator_unary_pre_tilde_0;
  static unsigned c_bi_mni_operator_binary_le_br_re_br_1;
  static unsigned c_bi_mni_Blank_0;
  static unsigned c_bi_mni_compare_1;
  static unsigned c_bi_mni_to_string_0;
  static unsigned c_bi_mni_print_0;
  static unsigned c_bi_mni_Char_0;
  static unsigned c_bi_mni_Char_1;
  static unsigned c_bi_mni_Integer_0;
  static unsigned c_bi_mni_Integer_1;
  static unsigned c_bi_mni_Integer_2;
  static unsigned c_bi_mni_Float_0;
  static unsigned c_bi_mni_Float_1;
  static unsigned c_bi_mni_sin_0;
  static unsigned c_bi_mni_cos_0;
  static unsigned c_bi_mni_tan_0;
  static unsigned c_bi_mni_asin_0;
  static unsigned c_bi_mni_acos_0;
  static unsigned c_bi_mni_atan_0;
  static unsigned c_bi_mni_exp_0;
  static unsigned c_bi_mni_log_0;
  static unsigned c_bi_mni_pow_1;
  static unsigned c_bi_mni_sqrt_0;
  static unsigned c_bi_mni_cbrt_0;
  static unsigned c_bi_mni_hypot_1;
  static unsigned c_bi_mni__isnan_0;
  static unsigned c_bi_mni_String_0;
  static unsigned c_bi_mni_String_1;
  static unsigned c_bi_mni_split_1;
  static unsigned c_bi_mni_join_1;
  static unsigned c_bi_mni_head_1;
  static unsigned c_bi_mni_tail_1;
  static unsigned c_bi_mni_range_2;
  static unsigned c_bi_mni_get_idx_1;
  static unsigned c_bi_mni_get_idxs_1;
  static unsigned c_bi_mni_replace_2;
  static unsigned c_bi_mni_item_1;
  static unsigned c_bi_mni_first_idx_0;
  static unsigned c_bi_mni_next_idx_1;
  static unsigned c_bi_mni_length_0;
  static unsigned c_bi_mni_Array_0;
  static unsigned c_bi_mni_Array_1;
  static unsigned c_bi_mni_clear_0;
  static unsigned c_bi_mni_resize_1;
  static unsigned c_bi_mni_push_1;
  static unsigned c_bi_mni_push_ref_1;
  static unsigned c_bi_mni_pop_0;
  static unsigned c_bi_mni_last_0;
  static unsigned c_bi_mni_fill_1;
  static unsigned c_bi_mni_last_idx_0;
  static unsigned c_bi_mni_prev_idx_1;
  static unsigned c_bi_mni_to_string_1;
  static unsigned c_bi_mni_Error_0;
  static unsigned c_bi_mni_Exception_0;
  static unsigned c_bi_mni_Exception_1;
  static unsigned c_bi_mni__throw_0;
  static unsigned c_bi_mni_get_type_0;
  static unsigned c_bi_mni_get_value_0;
  static unsigned c_bi_mni_get_file_name_0;
  static unsigned c_bi_mni_get_line_0;
  static unsigned c_bi_mni_error_print_0;
  static unsigned c_bi_mni_Type_0;
  static unsigned c_bi_mni_Type_1;
  static unsigned c_bi_mni_Mutex_0;
  static unsigned c_bi_mni_lock_0;
  static unsigned c_bi_mni_try_lock_0;
  static unsigned c_bi_mni_unlock_0;
  static unsigned c_bi_mni_join_0;
  static unsigned c_bi_mni_try_join_0;
  static unsigned c_bi_mni_detach_0;
  static unsigned c_bi_mni_yield_0;
  static unsigned c_bi_mni_Delegate_3;
  static unsigned c_bi_mni_call_1;
  static unsigned c_bi_mni_size_0;
  static unsigned c_bi_mni_NodeCallback_2;
  static unsigned c_bi_mni_call_0;
  static unsigned c_bi_mni_call_2;
  static unsigned c_bi_mni_sleep_1;
  static unsigned c_bi_mni_srand_1;
  static unsigned c_bi_mni_rand_0;
  static unsigned c_bi_mni_getpid_0;
  static unsigned c_bi_mni_getuid_0;
  static unsigned c_bi_mni_getgid_0;
  static unsigned c_bi_mni_system_1;
  static unsigned c_bi_mni_exit_1;
  static unsigned c_bi_mni_open_2;
  static unsigned c_bi_mni_popen_2;
  static unsigned c_bi_mni_mkdir_1;
  static unsigned c_bi_mni_rmdir_1;
  static unsigned c_bi_mni_chdir_1;
  static unsigned c_bi_mni_listdir_1;
  static unsigned c_bi_mni_mkfifo_1;
  static unsigned c_bi_mni_remove_1;
  static unsigned c_bi_mni_rename_2;
  static unsigned c_bi_mni_getcwd_0;
  static unsigned c_bi_mni_setenv_2;
  static unsigned c_bi_mni_getenv_1;
  static unsigned c_bi_mni_is_file_1;
  static unsigned c_bi_mni_is_dir_1;
  static unsigned c_bi_mni_size_1;
  static unsigned c_bi_mni_time_0;
  static unsigned c_bi_mni_Pipe_0;
  static unsigned c_bi_mni_Pipe_2;
  static unsigned c_bi_mni_close_0;
  static unsigned c_bi_mni_write_1;
  static unsigned c_bi_mni_flush_0;
  static unsigned c_bi_mni_read_0;
  static unsigned c_bi_mni_readln_0;
  static unsigned c_bi_mni_read_1;
  static unsigned c_bi_mni_get_fd_0;
  static unsigned c_bi_mni_next_item_0;
  static unsigned c_bi_mni_File_0;
  static unsigned c_bi_mni_File_2;
  static unsigned c_bi_mni_SocketAddr_2;
  static unsigned c_bi_mni_name_0;
  static unsigned c_bi_mni_port_0;
  static unsigned c_bi_mni_Socket_0;
  static unsigned c_bi_mni_Socket_2;
  static unsigned c_bi_mni_listen_2;
  static unsigned c_bi_mni_accept_0;
  static unsigned c_bi_mni_accept_nonblock_0;
  static unsigned c_bi_mni_connect_1;
  static unsigned c_bi_mni_bind_1;
  static unsigned c_bi_mni_sendto_2;
  static unsigned c_bi_mni_recvfrom_0;
  static unsigned c_bi_mni_set_timeout_2;
  static unsigned c_bi_mni_read_nonblock_0;
  static unsigned c_bi_mni_Regex_0;
  static unsigned c_bi_mni_Regex_1;
  static unsigned c_bi_mni_match_1;
  static unsigned c_bi_mni_match_2;
  static unsigned c_bi_mni_match_from_2;
  static unsigned c_bi_mni_bind_2;
  static unsigned c_bi_mni_unbind_1;
  static unsigned c_bi_mni_send_2;
  static unsigned c_bi_mni_Poll_1;
  static unsigned c_bi_mni_ready_1;
  static unsigned c_bi_mni_poll_1;
  static unsigned c_bi_mni_Timer_0;
  static unsigned c_bi_mni_schedule_3;
  static unsigned c_bi_mni_process_0;
  static unsigned c_bi_mni_remain_0;
  static unsigned c_bi_mni_getres_1;
  static unsigned c_bi_mni_gettime_1;
  static unsigned c_bi_mni_settime_2;
  static unsigned c_bi_mni_Stack_0;
  static unsigned c_bi_mni_Stack_1;
  static unsigned c_bi_mni_items_0;
  static unsigned c_bi_mni_Queue_0;
  static unsigned c_bi_mni_Queue_1;
  static unsigned c_bi_mni_insert_1;
  static unsigned c_bi_mni_insert_ref_1;
  static unsigned c_bi_mni_next_0;
  static unsigned c_bi_mni_Set_0;
  static unsigned c_bi_mni_Set_1;
  static unsigned c_bi_mni_contain_1;
  static unsigned c_bi_mni_List_0;
  static unsigned c_bi_mni_List_1;
  static unsigned c_bi_mni_append_1;
  static unsigned c_bi_mni_append_ref_1;
  static unsigned c_bi_mni_prepend_1;
  static unsigned c_bi_mni_prepend_ref_1;
  static unsigned c_bi_mni_insert_before_2;
  static unsigned c_bi_mni_insert_before_ref_2;
  static unsigned c_bi_mni_insert_after_2;
  static unsigned c_bi_mni_insert_after_ref_2;
  static unsigned c_bi_mni_has_idx_1;
  static unsigned c_bi_mni_Tree_0;
  static unsigned c_bi_mni_Tree_1;
  static unsigned c_bi_mni_Dict_0;
  static unsigned c_bi_mni_Dict_1;
  static unsigned c_bi_mni_keys_0;
  static unsigned c_bi_mni_store_ref_2;
  static unsigned c_bi_mni_has_key_1;
  static unsigned c_bi_mni_remove_key_1;
  static unsigned c_bi_mni_first_key_0;
  static unsigned c_bi_mni_last_key_0;
  static unsigned c_bi_mni_next_key_1;
  static unsigned c_bi_mni_prev_key_1;
  static unsigned c_bi_mni_lee_key_1;
  static unsigned c_bi_mni_gre_key_1;
  static unsigned c_bi_mni_create_1;
  static unsigned c_bi_mni_create_nice_2;
  static unsigned c_bi_mni_parse_1;
  static unsigned c_bi_mni_WsContext_2;
  static unsigned c_bi_mni_version_0;
  static unsigned c_bi_mni_user_data_0;
  static unsigned c_bi_mni_client_4;
  static unsigned c_bi_mni_get_fds_0;
  static unsigned c_bi_mni_process_1;
  static unsigned c_bi_mni_protocol_idx_1;
  static unsigned c_bi_mni_callback_on_writable_1;
  static unsigned c_bi_mni_reason_0;
  static unsigned c_bi_mni_received_data_0;
  static unsigned c_bi_mni_ctx_user_data_0;
  static unsigned c_bi_mni_protocol_name_0;
  static unsigned c_bi_mni_callback_on_writable_0;
  static unsigned c_bi_mni_write_2;
  static unsigned c_bi_mni_connected_0;
  static unsigned c_bi_mni_encode_1;
  static unsigned c_bi_mni_decode_1;
  static unsigned c_bi_mni_JitContext_0;
  static unsigned c_bi_mni_create_fun_1;
  static unsigned c_bi_mni_signature_0;

  // - built in variable name indexes declaration -
  static unsigned c_bi_vni_USER_EXCEPTION;
  static unsigned c_bi_vni_TODO_EXCEPTION;
  static unsigned c_bi_vni_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR;
  static unsigned c_bi_vni_CLASS_DOES_NOT_CONTAIN_METHOD;
  static unsigned c_bi_vni_CLASS_DOES_NOT_CONTAIN_VARIABLE;
  static unsigned c_bi_vni_CANNOT_ACCESS_PRIVATE_METHOD;
  static unsigned c_bi_vni_CANNOT_ACCESS_PRIVATE_VARIABLE;
  static unsigned c_bi_vni_METHOD_CANNOT_RETURN_VALUE;
  static unsigned c_bi_vni_CANNOT_TEST_TYPE_VALUE;
  static unsigned c_bi_vni_CANNOT_CONVERT_TYPE_TO_INTEGER;
  static unsigned c_bi_vni_CANNOT_USE_NEGATIVE_NUMBER;
  static unsigned c_bi_vni_SLICE_NOT_INTEGER_ARGUMENTS;
  static unsigned c_bi_vni_SLICE_START_LESS_THAN_ZERO;
  static unsigned c_bi_vni_SLICE_STOP_LESS_THAN_ZERO;
  static unsigned c_bi_vni_SLICE_STEP_EQUAL_TO_ZERO;
  static unsigned c_bi_vni_OBJECT_OF_CLASS_IS_NOT_ITERABLE;
  static unsigned c_bi_vni_UNEXPECTED_END_OF_ITERABLE;
  static unsigned c_bi_vni_BUILT_IN_NOT_IMPLEMENTED_METHOD;
  static unsigned c_bi_vni_METHOD_NOT_DEFINED_WITH_PARAMETERS;
  static unsigned c_bi_vni_WRONG_METHOD_PARAMETER_VALUE;
  static unsigned c_bi_vni_DIVISION_BY_ZERO;
  static unsigned c_bi_vni_NEGATIVE_SHIFT_COUNT;
  static unsigned c_bi_vni_METHOD_NOT_RETURN_INTEGER;
  static unsigned c_bi_vni_METHOD_NOT_RETURN_STRING;
  static unsigned c_bi_vni_METHOD_NOT_RETURN_INDEX;
  static unsigned c_bi_vni_INTEGER_BASE_OUT_OF_RANGE;
  static unsigned c_bi_vni_INTEGER_CONVERT_INVALID_STRING;
  static unsigned c_bi_vni_FLOAT_CONVERT_INVALID_STRING;
  static unsigned c_bi_vni_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS;
  static unsigned c_bi_vni_STRING_FORMAT_WRONG_ARGUMENT_TYPE;
  static unsigned c_bi_vni_STRING_FORMAT_ARGUMENT_FORMAT_ERROR;
  static unsigned c_bi_vni_STRING_FORMAT_WRONG_FORMAT_SPECIFIER;
  static unsigned c_bi_vni_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED;
  static unsigned c_bi_vni_STRING_INDEX_EXCEEDS_RANGE;
  static unsigned c_bi_vni_STRING_WRONG_RANGE_INDEXES;
  static unsigned c_bi_vni_STRING_CONVERT_FROM_INTEGER;
  static unsigned c_bi_vni_STRING_CONVERT_FROM_FLOAT;
  static unsigned c_bi_vni_ARRAY_INDEX_EXCEEDS_RANGE;
  static unsigned c_bi_vni_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE;
  static unsigned c_bi_vni_ARRAY_NO_ELEMENTS;
  static unsigned c_bi_vni_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH;
  static unsigned c_bi_vni_DELEGATE_NEGATIVE_PARAMETER_COUNT;
  static unsigned c_bi_vni_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD;
  static unsigned c_bi_vni_DELEGATE_CALL_WRONG_PARAMETER_COUNT;
  static unsigned c_bi_vni_DELEGATE_WRONG_RETURN_VALUE_TYPE;
  static unsigned c_bi_vni__ERROR_INVALID;
  static unsigned c_bi_vni__ERROR_DEADLOCK;
  static unsigned c_bi_vni__ERROR_BUSY;
  static unsigned c_bi_vni__ERROR_PERMISSION;
  static unsigned c_bi_vni__ERROR_AGAIN;
  static unsigned c_bi_vni__ERROR_SEARCH;
  static unsigned c_bi_vni_NAME;
  static unsigned c_bi_vni_SEP;
  static unsigned c_bi_vni__stdin;
  static unsigned c_bi_vni__stdout;
  static unsigned c_bi_vni__stderr;
  static unsigned c_bi_vni_AF_UNIX;
  static unsigned c_bi_vni_AF_FILE;
  static unsigned c_bi_vni_AF_INET;
  static unsigned c_bi_vni_SOCK_STREAM;
  static unsigned c_bi_vni_SOCK_DGRAM;
  static unsigned c_bi_vni_SOCK_RAW;
  static unsigned c_bi_vni_SO_RCVTIMEO;
  static unsigned c_bi_vni_SO_SNDTIMEO;
  static unsigned c_bi_vni__SIGINT;
  static unsigned c_bi_vni__SIGTERM;
  static unsigned c_bi_vni__SIGHUP;
  static unsigned c_bi_vni__SIGQUIT;
  static unsigned c_bi_vni__SIGILL;
  static unsigned c_bi_vni__SIGTRAP;
  static unsigned c_bi_vni__SIGABRT;
  static unsigned c_bi_vni__SIGIOT;
  static unsigned c_bi_vni__SIGBUS;
  static unsigned c_bi_vni__SIGFPE;
  static unsigned c_bi_vni__SIGKILL;
  static unsigned c_bi_vni__SIGUSR1;
  static unsigned c_bi_vni__SIGSEGV;
  static unsigned c_bi_vni__SIGUSR2;
  static unsigned c_bi_vni__SIGPIPE;
  static unsigned c_bi_vni__SIGALRM;
  static unsigned c_bi_vni__SIGSTKFLT;
  static unsigned c_bi_vni__SIGCHLD;
  static unsigned c_bi_vni__SIGCONT;
  static unsigned c_bi_vni__SIGSTOP;
  static unsigned c_bi_vni__SIGTSTP;
  static unsigned c_bi_vni__SIGTTIN;
  static unsigned c_bi_vni__SIGTTOU;
  static unsigned c_bi_vni__SIGURG;
  static unsigned c_bi_vni__SIGXCPU;
  static unsigned c_bi_vni__SIGXFSZ;
  static unsigned c_bi_vni__SIGVTALRM;
  static unsigned c_bi_vni__SIGPROF;
  static unsigned c_bi_vni__SIGWINCH;
  static unsigned c_bi_vni__SIGIO;
  static unsigned c_bi_vni__SIGPOLL;
  static unsigned c_bi_vni__SIGPWR;
  static unsigned c_bi_vni__SIGSYS;
  static unsigned c_bi_vni__SIGUNUSED;
  static unsigned c_bi_vni__SIGRTMIN;
  static unsigned c_bi_vni__SIGRTMAX;
  static unsigned c_bi_vni_POLLIN;
  static unsigned c_bi_vni_POLLPRI;
  static unsigned c_bi_vni_POLLOUT;
  static unsigned c_bi_vni_POLLERR;
  static unsigned c_bi_vni_POLLHUP;
  static unsigned c_bi_vni_POLLNVAL;
  static unsigned c_bi_vni__CLOCK_REALTIME;
  static unsigned c_bi_vni__CLOCK_MONOTONIC;
  static unsigned c_bi_vni__CLOCK_PROCESS_CPUTIME_ID;
  static unsigned c_bi_vni__CLOCK_THREAD_CPUTIME_ID;
  static unsigned c_bi_vni_PORT_NO_LISTEN;
  static unsigned c_bi_vni_WRITE_TEXT;
  static unsigned c_bi_vni_WRITE_BINARY;
  static unsigned c_bi_vni_WRITE_CONTINUATION;
  static unsigned c_bi_vni_WRITE_HTTP;
  static unsigned c_bi_vni_WRITE_CLOSE;
  static unsigned c_bi_vni_WRITE_PING;
  static unsigned c_bi_vni_WRITE_PONG;
  static unsigned c_bi_vni_CB_ESTABLISHED;
  static unsigned c_bi_vni_CB_CLIENT_CONNECTION_ERROR;
  static unsigned c_bi_vni_CB_CLIENT_FILTER_PRE_ESTABLISH;
  static unsigned c_bi_vni_CB_CLIENT_ESTABLISHED;
  static unsigned c_bi_vni_CB_CLOSED;
  static unsigned c_bi_vni_CB_RECEIVE;
  static unsigned c_bi_vni_CB_CLIENT_RECEIVE;
  static unsigned c_bi_vni_CB_CLIENT_RECEIVE_PONG;
  static unsigned c_bi_vni_CB_CLIENT_WRITEABLE;
  static unsigned c_bi_vni_CB_SERVER_WRITEABLE;
  static unsigned c_bi_vni_CB_HTTP;
  static unsigned c_bi_vni_CB_HTTP_FILE_COMPLETION;
  static unsigned c_bi_vni_CB_FILTER_NETWORK_CONNECTION;
  static unsigned c_bi_vni_CB_FILTER_PROTOCOL_CONNECTION;
  static unsigned c_bi_vni_CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS;
  static unsigned c_bi_vni_CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS;
  static unsigned c_bi_vni_CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION;
  static unsigned c_bi_vni_CB_CLIENT_APPEND_HANDSHAKE_HEADER;
  static unsigned c_bi_vni_CB_CONFIRM_EXTENSION_OKAY;
  static unsigned c_bi_vni_CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED;
  static unsigned c_bi_vni_CB_PROTOCOL_INIT;
  static unsigned c_bi_vni_CB_PROTOCOL_DESTROY;
  static unsigned c_bi_vni_CB_ADD_POLL_FD;
  static unsigned c_bi_vni_CB_DEL_POLL_FD;
  static unsigned c_bi_vni_CB_CHANGE_MODE_POLL_FD;
  static unsigned c_bi_vni_TIMEOUT_NO_PENDING;
  static unsigned c_bi_vni_TIMEOUT_AWAITING_PROXY_RESPONSE;
  static unsigned c_bi_vni_TIMEOUT_AWAITING_CONNECT_RESPONSE;
  static unsigned c_bi_vni_TIMEOUT_ESTABLISH_WITH_SERVER;
  static unsigned c_bi_vni_TIMEOUT_AWAITING_SERVER_RESPONSE;
  static unsigned c_bi_vni_TIMEOUT_AWAITING_PING;
  static unsigned c_bi_vni_TIMEOUT_CLOSE_ACK;
  static unsigned c_bi_vni_TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE;
  static unsigned c_bi_vni_TIMEOUT_SENT_CLIENT_HANDSHAKE;
  static unsigned c_bi_vni_TIMEOUT_SSL_ACCEPT;
  static unsigned c_bi_vni_TYPE_I8;
  static unsigned c_bi_vni_TYPE_U8;
  static unsigned c_bi_vni_TYPE_I16;
  static unsigned c_bi_vni_TYPE_U16;
  static unsigned c_bi_vni_TYPE_I32;
  static unsigned c_bi_vni_TYPE_U32;
  static unsigned c_bi_vni_TYPE_I64;
  static unsigned c_bi_vni_TYPE_U64;
  static unsigned c_bi_vni_TYPE_F32;
  static unsigned c_bi_vni_TYPE_F64;

  private:
  inline void BLANK();
  inline void CHAR(char a_value);
  inline void INTEGER(long long int a_value);
  inline void FLOAT(double a_value);
  inline void STRING(unsigned a_length,const char *a_data);
  inline void ARRAY(unsigned a_size,const UclVar *a_array);

  UclVar __call_0(unsigned a_method_idx);
  UclVar __call_1(unsigned a_method_idx,UclVar a_op);
  UclVar __call_2(unsigned a_method_idx,UclVar a_op,UclVar a_op_1);
  UclVar __call_3(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2);
  UclVar __call_4(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3);

  static UclVar __static_call_0(unsigned a_method_idx);
  static UclVar __static_call_1(unsigned a_method_idx,UclVar a_op);
  static UclVar __static_call_2(unsigned a_method_idx,UclVar a_op,UclVar a_op_1);

  static UclVar __new_object_0(unsigned a_class_idx,unsigned a_name_idx);
  static UclVar __new_object_1(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op);
  static UclVar __new_object_2(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1);
  static UclVar __new_object_3(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2);

  public:
  static UclVar __new(std::string a_name);
  static UclVar __new(std::string a_name,UclVar a_op);
  static UclVar __new(std::string a_name,UclVar a_op,UclVar a_op_1);
  static UclVar __new(std::string a_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2);

  UclVar __call(std::string a_name);
  UclVar __call(std::string a_name,UclVar a_op);
  UclVar __call(std::string a_name,UclVar a_op,UclVar a_op_1);
  UclVar __call(std::string a_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2);
  UclVar __call(std::string a_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3);

  UclVar __member(std::string a_name);

  static void Initialize(script_parser_s &a_parser,bool *a_modules);
  static void Initialize(interpreter_s &a_interpreter,bool *a_modules);
  static void InitThread(interpreter_thread_s &a_it);
  static void Release(interpreter_s &a_interpreter);

  inline UclVar(const UclVar &a_src)
  {/*{{{*/
    a_src.location_ptr->v_reference_cnt.atomic_inc();
    location_ptr = a_src.location_ptr;
  }/*}}}*/

  inline UclVar(location_s **a_location_ptr)
  {/*{{{*/
    location_ptr = it_ptr->get_new_reference(a_location_ptr);
  }/*}}}*/

  inline ~UclVar()
  {/*{{{*/
    if (location_ptr != NULL)
    {
      it_ptr->release_location_ptr(location_ptr);
    }
  }/*}}}*/

  class NO_INIT {};

  inline UclVar(NO_INIT)                              { location_ptr = NULL; }
  inline UclVar()                                     { BLANK(); }
  inline UclVar(char a_value)                         { CHAR(a_value); }
  inline UclVar(int a_value)                          { INTEGER(a_value); }
  inline UclVar(long int a_value)                     { INTEGER(a_value); }
  inline UclVar(long long int a_value)                { INTEGER(a_value); }
  inline UclVar(unsigned a_value)                     { INTEGER(a_value); }
  inline UclVar(long unsigned a_value)                { INTEGER(a_value); }
  inline UclVar(long long unsigned a_value)           { INTEGER(a_value); }
  inline UclVar(float a_value)                        { FLOAT(a_value); }
  inline UclVar(double a_value)                       { FLOAT(a_value); }
  inline UclVar(const char *a_data)                   { STRING(strlen(a_data),a_data); }
  inline UclVar(unsigned a_length,const char *a_data) { STRING(a_length,a_data); }
  inline UclVar(unsigned a_size,UclVar *a_array)      { ARRAY(a_size,a_array); }

#if __cplusplus >= 201103
  inline UclVar(std::initializer_list<UclVar> list)   { ARRAY(list.size(),list.begin()); }
#endif

  inline char __char();
  inline long long int __int();
  inline double __float();
  inline const char *__str();

  inline void __free();
  inline UclVar __type();

  inline static UclVar Delegate(t_node_callback_0 cb_ptr)
  {/*{{{*/
    const UclVar parm_cnt(0);
    UclVar callback = __new_object_2(c_bi_class_NodeCallback,c_bi_mni_NodeCallback_2,UclVar((long long int)cb_ptr),parm_cnt);
    return __new_object_3(c_bi_class_delegate,c_bi_mni_Delegate_3,callback,UclVar("call"),parm_cnt);
  }/*}}}*/

  inline static UclVar Delegate(t_node_callback_1 cb_ptr)
  {/*{{{*/
    const UclVar parm_cnt(1);
    UclVar callback = __new_object_2(c_bi_class_NodeCallback,c_bi_mni_NodeCallback_2,UclVar((long long int)cb_ptr),parm_cnt);
    return __new_object_3(c_bi_class_delegate,c_bi_mni_Delegate_3,callback,UclVar("call"),parm_cnt);
  }/*}}}*/

  inline static UclVar Delegate(t_node_callback_2 cb_ptr)
  {/*{{{*/
    const UclVar parm_cnt(2);
    UclVar callback = __new_object_2(c_bi_class_NodeCallback,c_bi_mni_NodeCallback_2,UclVar((long long int)cb_ptr),parm_cnt);
    return __new_object_3(c_bi_class_delegate,c_bi_mni_Delegate_3,callback,UclVar("call"),parm_cnt);
  }/*}}}*/

  // - built in classes declaration -
  /*{{{*/

  // - class Blank -
  class Blank
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_operator_binary_double_equal_1;
    static unsigned c_bi_mi_operator_binary_exclamation_equal_1;
    static unsigned c_bi_mi_compare_1;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar operator_binary_double_equal(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_operator_binary_double_equal_1,op_0);
    }/*}}}*/

    inline static UclVar operator_binary_exclamation_equal(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_operator_binary_exclamation_equal_1,op_0);
    }/*}}}*/

    inline static UclVar compare(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_compare_1,op_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Blank()
  {/*{{{*/
    return __new_object_0(c_bi_class_Blank,c_bi_mni_Blank_0);
  }/*}}}*/

  // - class Char -
  inline static UclVar Char()
  {/*{{{*/
    return __new_object_0(c_bi_class_Char,c_bi_mni_Char_0);
  }/*}}}*/

  inline static UclVar Char(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Char,c_bi_mni_Char_1,op_0);
  }/*}}}*/

  // - class Integer -
  inline static UclVar Integer()
  {/*{{{*/
    return __new_object_0(c_bi_class_Integer,c_bi_mni_Integer_0);
  }/*}}}*/

  inline static UclVar Integer(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Integer,c_bi_mni_Integer_1,op_0);
  }/*}}}*/

  inline static UclVar Integer(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_Integer,c_bi_mni_Integer_2,op_0,op_1);
  }/*}}}*/

  // - class Float -
  inline static UclVar Float()
  {/*{{{*/
    return __new_object_0(c_bi_class_Float,c_bi_mni_Float_0);
  }/*}}}*/

  inline static UclVar Float(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Float,c_bi_mni_Float_1,op_0);
  }/*}}}*/

  // - class String -
  inline static UclVar String()
  {/*{{{*/
    return __new_object_0(c_bi_class_String,c_bi_mni_String_0);
  }/*}}}*/

  inline static UclVar String(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_String,c_bi_mni_String_1,op_0);
  }/*}}}*/

  // - class Array -
  inline static UclVar Array()
  {/*{{{*/
    return __new_object_0(c_bi_class_Array,c_bi_mni_Array_0);
  }/*}}}*/

  inline static UclVar Array(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Array,c_bi_mni_Array_1,op_0);
  }/*}}}*/

  // - class Error -
  inline static UclVar Error()
  {/*{{{*/
    return __new_object_0(c_bi_class_Error,c_bi_mni_Error_0);
  }/*}}}*/

  // - class Exception -
  class Exception
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar USER_EXCEPTION;
    static UclVar TODO_EXCEPTION;
    static UclVar CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR;
    static UclVar CLASS_DOES_NOT_CONTAIN_METHOD;
    static UclVar CLASS_DOES_NOT_CONTAIN_VARIABLE;
    static UclVar CANNOT_ACCESS_PRIVATE_METHOD;
    static UclVar CANNOT_ACCESS_PRIVATE_VARIABLE;
    static UclVar METHOD_CANNOT_RETURN_VALUE;
    static UclVar CANNOT_TEST_TYPE_VALUE;
    static UclVar CANNOT_CONVERT_TYPE_TO_INTEGER;
    static UclVar CANNOT_USE_NEGATIVE_NUMBER;
    static UclVar SLICE_NOT_INTEGER_ARGUMENTS;
    static UclVar SLICE_START_LESS_THAN_ZERO;
    static UclVar SLICE_STOP_LESS_THAN_ZERO;
    static UclVar SLICE_STEP_EQUAL_TO_ZERO;
    static UclVar OBJECT_OF_CLASS_IS_NOT_ITERABLE;
    static UclVar UNEXPECTED_END_OF_ITERABLE;
    static UclVar BUILT_IN_NOT_IMPLEMENTED_METHOD;
    static UclVar METHOD_NOT_DEFINED_WITH_PARAMETERS;
    static UclVar WRONG_METHOD_PARAMETER_VALUE;
    static UclVar DIVISION_BY_ZERO;
    static UclVar NEGATIVE_SHIFT_COUNT;
    static UclVar METHOD_NOT_RETURN_INTEGER;
    static UclVar METHOD_NOT_RETURN_STRING;
    static UclVar METHOD_NOT_RETURN_INDEX;
    static UclVar INTEGER_BASE_OUT_OF_RANGE;
    static UclVar INTEGER_CONVERT_INVALID_STRING;
    static UclVar FLOAT_CONVERT_INVALID_STRING;
    static UclVar STRING_FORMAT_NOT_ENOUGH_ARGUMENTS;
    static UclVar STRING_FORMAT_WRONG_ARGUMENT_TYPE;
    static UclVar STRING_FORMAT_ARGUMENT_FORMAT_ERROR;
    static UclVar STRING_FORMAT_WRONG_FORMAT_SPECIFIER;
    static UclVar STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED;
    static UclVar STRING_INDEX_EXCEEDS_RANGE;
    static UclVar STRING_WRONG_RANGE_INDEXES;
    static UclVar STRING_CONVERT_FROM_INTEGER;
    static UclVar STRING_CONVERT_FROM_FLOAT;
    static UclVar ARRAY_INDEX_EXCEEDS_RANGE;
    static UclVar ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE;
    static UclVar ARRAY_NO_ELEMENTS;
    static UclVar ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH;
    static UclVar DELEGATE_NEGATIVE_PARAMETER_COUNT;
    static UclVar DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD;
    static UclVar DELEGATE_CALL_WRONG_PARAMETER_COUNT;
    static UclVar DELEGATE_WRONG_RETURN_VALUE_TYPE;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Exception()
  {/*{{{*/
    return __new_object_0(c_bi_class_Exception,c_bi_mni_Exception_0);
  }/*}}}*/

  inline static UclVar Exception(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Exception,c_bi_mni_Exception_1,op_0);
  }/*}}}*/

  // - class Type -
  inline static UclVar Type()
  {/*{{{*/
    return __new_object_0(c_bi_class_Type,c_bi_mni_Type_0);
  }/*}}}*/

  inline static UclVar Type(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Type,c_bi_mni_Type_1,op_0);
  }/*}}}*/

  // - class Mutex -
  class Mutex
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar _ERROR_INVALID;
    static UclVar _ERROR_DEADLOCK;
    static UclVar _ERROR_BUSY;
    static UclVar _ERROR_PERMISSION;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Mutex()
  {/*{{{*/
    return __new_object_0(c_bi_class_Mutex,c_bi_mni_Mutex_0);
  }/*}}}*/

  // - class Thread -
  class Thread
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_yield_0;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar _ERROR_AGAIN;
    static UclVar _ERROR_SEARCH;
    static UclVar _ERROR_INVALID;
    static UclVar _ERROR_DEADLOCK;
    static UclVar _ERROR_BUSY;

    public:
    inline static UclVar yield()
    {/*{{{*/
      return __static_call_0(c_bi_mi_yield_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class Delegate -
  class Delegate
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Delegate(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __new_object_3(c_bi_class_Delegate,c_bi_mni_Delegate_3,op_0,op_1,op_2);
  }/*}}}*/

  // - class Buffer -
  class Buffer
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_size_0;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar size()
    {/*{{{*/
      return __static_call_0(c_bi_mi_size_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class NodeCallback -
  class NodeCallback
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar NodeCallback(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_NodeCallback,c_bi_mni_NodeCallback_2,op_0,op_1);
  }/*}}}*/

  // - class Sys -
  class Sys
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_sleep_1;
    static unsigned c_bi_mi_srand_1;
    static unsigned c_bi_mi_rand_0;
    static unsigned c_bi_mi_getpid_0;
    static unsigned c_bi_mi_getuid_0;
    static unsigned c_bi_mi_getgid_0;
    static unsigned c_bi_mi_system_1;
    static unsigned c_bi_mi_exit_1;
    static unsigned c_bi_mi_open_2;
    static unsigned c_bi_mi_popen_2;
    static unsigned c_bi_mi_mkdir_1;
    static unsigned c_bi_mi_rmdir_1;
    static unsigned c_bi_mi_chdir_1;
    static unsigned c_bi_mi_listdir_1;
    static unsigned c_bi_mi_mkfifo_1;
    static unsigned c_bi_mi_remove_1;
    static unsigned c_bi_mi_rename_2;
    static unsigned c_bi_mi_getcwd_0;
    static unsigned c_bi_mi_setenv_2;
    static unsigned c_bi_mi_getenv_1;
    static unsigned c_bi_mi_is_file_1;
    static unsigned c_bi_mi_is_dir_1;
    static unsigned c_bi_mi_size_1;
    static unsigned c_bi_mi_time_0;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar NAME;
    static UclVar SEP;

    public:
    inline static UclVar sleep(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_sleep_1,op_0);
    }/*}}}*/

    inline static UclVar srand(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_srand_1,op_0);
    }/*}}}*/

    inline static UclVar rand()
    {/*{{{*/
      return __static_call_0(c_bi_mi_rand_0);
    }/*}}}*/

    inline static UclVar getpid()
    {/*{{{*/
      return __static_call_0(c_bi_mi_getpid_0);
    }/*}}}*/

    inline static UclVar getuid()
    {/*{{{*/
      return __static_call_0(c_bi_mi_getuid_0);
    }/*}}}*/

    inline static UclVar getgid()
    {/*{{{*/
      return __static_call_0(c_bi_mi_getgid_0);
    }/*}}}*/

    inline static UclVar system(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_system_1,op_0);
    }/*}}}*/

    inline static UclVar exit(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_exit_1,op_0);
    }/*}}}*/

    inline static UclVar open(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_open_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar popen(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_popen_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar mkdir(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_mkdir_1,op_0);
    }/*}}}*/

    inline static UclVar rmdir(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_rmdir_1,op_0);
    }/*}}}*/

    inline static UclVar chdir(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_chdir_1,op_0);
    }/*}}}*/

    inline static UclVar listdir(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_listdir_1,op_0);
    }/*}}}*/

    inline static UclVar mkfifo(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_mkfifo_1,op_0);
    }/*}}}*/

    inline static UclVar remove(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_remove_1,op_0);
    }/*}}}*/

    inline static UclVar rename(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_rename_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar getcwd()
    {/*{{{*/
      return __static_call_0(c_bi_mi_getcwd_0);
    }/*}}}*/

    inline static UclVar setenv(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_setenv_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar getenv(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_getenv_1,op_0);
    }/*}}}*/

    inline static UclVar is_file(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_is_file_1,op_0);
    }/*}}}*/

    inline static UclVar is_dir(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_is_dir_1,op_0);
    }/*}}}*/

    inline static UclVar size(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_size_1,op_0);
    }/*}}}*/

    inline static UclVar time()
    {/*{{{*/
      return __static_call_0(c_bi_mi_time_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class Pipe -
  class Pipe
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Pipe()
  {/*{{{*/
    return __new_object_0(c_bi_class_Pipe,c_bi_mni_Pipe_0);
  }/*}}}*/

  inline static UclVar Pipe(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_Pipe,c_bi_mni_Pipe_2,op_0,op_1);
  }/*}}}*/

  // - class File -
  class File
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar _stdin;
    static UclVar _stdout;
    static UclVar _stderr;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar File()
  {/*{{{*/
    return __new_object_0(c_bi_class_File,c_bi_mni_File_0);
  }/*}}}*/

  inline static UclVar File(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_File,c_bi_mni_File_2,op_0,op_1);
  }/*}}}*/

#ifdef ENABLE_CLASS_SOCKET
  // - class SocketAddr -
  class SocketAddr
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar SocketAddr(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_SocketAddr,c_bi_mni_SocketAddr_2,op_0,op_1);
  }/*}}}*/

  // - class Socket -
  class Socket
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar AF_UNIX;
    static UclVar AF_FILE;
    static UclVar AF_INET;
    static UclVar SOCK_STREAM;
    static UclVar SOCK_DGRAM;
    static UclVar SOCK_RAW;
    static UclVar SO_RCVTIMEO;
    static UclVar SO_SNDTIMEO;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Socket()
  {/*{{{*/
    return __new_object_0(c_bi_class_Socket,c_bi_mni_Socket_0);
  }/*}}}*/

  inline static UclVar Socket(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_Socket,c_bi_mni_Socket_2,op_0,op_1);
  }/*}}}*/
#endif

#ifdef ENABLE_CLASS_SOCKET
  // - class Regex -
  class Regex
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Regex()
  {/*{{{*/
    return __new_object_0(c_bi_class_Regex,c_bi_mni_Regex_0);
  }/*}}}*/

  inline static UclVar Regex(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Regex,c_bi_mni_Regex_1,op_0);
  }/*}}}*/
#endif

  // - class Signal -
  class Signal
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_bind_2;
    static unsigned c_bi_mi_unbind_1;
    static unsigned c_bi_mi_send_2;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar _SIGINT;
    static UclVar _SIGTERM;
    static UclVar _SIGHUP;
    static UclVar _SIGQUIT;
    static UclVar _SIGILL;
    static UclVar _SIGTRAP;
    static UclVar _SIGABRT;
    static UclVar _SIGIOT;
    static UclVar _SIGBUS;
    static UclVar _SIGFPE;
    static UclVar _SIGKILL;
    static UclVar _SIGUSR1;
    static UclVar _SIGSEGV;
    static UclVar _SIGUSR2;
    static UclVar _SIGPIPE;
    static UclVar _SIGALRM;
    static UclVar _SIGSTKFLT;
    static UclVar _SIGCHLD;
    static UclVar _SIGCONT;
    static UclVar _SIGSTOP;
    static UclVar _SIGTSTP;
    static UclVar _SIGTTIN;
    static UclVar _SIGTTOU;
    static UclVar _SIGURG;
    static UclVar _SIGXCPU;
    static UclVar _SIGXFSZ;
    static UclVar _SIGVTALRM;
    static UclVar _SIGPROF;
    static UclVar _SIGWINCH;
    static UclVar _SIGIO;
    static UclVar _SIGPOLL;
    static UclVar _SIGPWR;
    static UclVar _SIGSYS;
    static UclVar _SIGUNUSED;
    static UclVar _SIGRTMIN;
    static UclVar _SIGRTMAX;

    public:
    inline static UclVar bind(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_bind_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar unbind(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_unbind_1,op_0);
    }/*}}}*/

    inline static UclVar send(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_send_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class Poll -
  class Poll
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar POLLIN;
    static UclVar POLLPRI;
    static UclVar POLLOUT;
    static UclVar POLLERR;
    static UclVar POLLHUP;
    static UclVar POLLNVAL;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Poll(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Poll,c_bi_mni_Poll_1,op_0);
  }/*}}}*/

  // - class Timer -
  class Timer
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar Timer()
  {/*{{{*/
    return __new_object_0(c_bi_class_Timer,c_bi_mni_Timer_0);
  }/*}}}*/

  // - class Clock -
  class Clock
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_getres_1;
    static unsigned c_bi_mi_gettime_1;
    static unsigned c_bi_mi_settime_2;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar _CLOCK_REALTIME;
    static UclVar _CLOCK_MONOTONIC;
    static UclVar _CLOCK_PROCESS_CPUTIME_ID;
    static UclVar _CLOCK_THREAD_CPUTIME_ID;

    public:
    inline static UclVar getres(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_getres_1,op_0);
    }/*}}}*/

    inline static UclVar gettime(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_gettime_1,op_0);
    }/*}}}*/

    inline static UclVar settime(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_settime_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class Stack -
  inline static UclVar Stack()
  {/*{{{*/
    return __new_object_0(c_bi_class_Stack,c_bi_mni_Stack_0);
  }/*}}}*/

  inline static UclVar Stack(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Stack,c_bi_mni_Stack_1,op_0);
  }/*}}}*/

  // - class Queue -
  inline static UclVar Queue()
  {/*{{{*/
    return __new_object_0(c_bi_class_Queue,c_bi_mni_Queue_0);
  }/*}}}*/

  inline static UclVar Queue(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Queue,c_bi_mni_Queue_1,op_0);
  }/*}}}*/

  // - class Set -
  inline static UclVar Set()
  {/*{{{*/
    return __new_object_0(c_bi_class_Set,c_bi_mni_Set_0);
  }/*}}}*/

  inline static UclVar Set(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Set,c_bi_mni_Set_1,op_0);
  }/*}}}*/

  // - class List -
  inline static UclVar List()
  {/*{{{*/
    return __new_object_0(c_bi_class_List,c_bi_mni_List_0);
  }/*}}}*/

  inline static UclVar List(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_List,c_bi_mni_List_1,op_0);
  }/*}}}*/

  // - class Tree -
  inline static UclVar Tree()
  {/*{{{*/
    return __new_object_0(c_bi_class_Tree,c_bi_mni_Tree_0);
  }/*}}}*/

  inline static UclVar Tree(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Tree,c_bi_mni_Tree_1,op_0);
  }/*}}}*/

  // - class Dict -
  inline static UclVar Dict()
  {/*{{{*/
    return __new_object_0(c_bi_class_Dict,c_bi_mni_Dict_0);
  }/*}}}*/

  inline static UclVar Dict(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Dict,c_bi_mni_Dict_1,op_0);
  }/*}}}*/

  // - class Json -
  class Json
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_create_1;
    static unsigned c_bi_mi_create_nice_2;
    static unsigned c_bi_mi_parse_1;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar create(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_create_1,op_0);
    }/*}}}*/

    inline static UclVar create_nice(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_create_nice_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar parse(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_parse_1,op_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class WsContext -
  class WsContext
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_version_0;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar PORT_NO_LISTEN;

    public:
    inline static UclVar version()
    {/*{{{*/
      return __static_call_0(c_bi_mi_version_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar WsContext(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_WsContext,c_bi_mni_WsContext_2,op_0,op_1);
  }/*}}}*/

  // - class WsConn -
  class WsConn
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar WRITE_TEXT;
    static UclVar WRITE_BINARY;
    static UclVar WRITE_CONTINUATION;
    static UclVar WRITE_HTTP;
    static UclVar WRITE_CLOSE;
    static UclVar WRITE_PING;
    static UclVar WRITE_PONG;
    static UclVar CB_ESTABLISHED;
    static UclVar CB_CLIENT_CONNECTION_ERROR;
    static UclVar CB_CLIENT_FILTER_PRE_ESTABLISH;
    static UclVar CB_CLIENT_ESTABLISHED;
    static UclVar CB_CLOSED;
    static UclVar CB_RECEIVE;
    static UclVar CB_CLIENT_RECEIVE;
    static UclVar CB_CLIENT_RECEIVE_PONG;
    static UclVar CB_CLIENT_WRITEABLE;
    static UclVar CB_SERVER_WRITEABLE;
    static UclVar CB_HTTP;
    static UclVar CB_HTTP_FILE_COMPLETION;
    static UclVar CB_FILTER_NETWORK_CONNECTION;
    static UclVar CB_FILTER_PROTOCOL_CONNECTION;
    static UclVar CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS;
    static UclVar CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS;
    static UclVar CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION;
    static UclVar CB_CLIENT_APPEND_HANDSHAKE_HEADER;
    static UclVar CB_CONFIRM_EXTENSION_OKAY;
    static UclVar CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED;
    static UclVar CB_PROTOCOL_INIT;
    static UclVar CB_PROTOCOL_DESTROY;
    static UclVar CB_ADD_POLL_FD;
    static UclVar CB_DEL_POLL_FD;
    static UclVar CB_CHANGE_MODE_POLL_FD;
    static UclVar TIMEOUT_NO_PENDING;
    static UclVar TIMEOUT_AWAITING_PROXY_RESPONSE;
    static UclVar TIMEOUT_AWAITING_CONNECT_RESPONSE;
    static UclVar TIMEOUT_ESTABLISH_WITH_SERVER;
    static UclVar TIMEOUT_AWAITING_SERVER_RESPONSE;
    static UclVar TIMEOUT_AWAITING_PING;
    static UclVar TIMEOUT_CLOSE_ACK;
    static UclVar TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE;
    static UclVar TIMEOUT_SENT_CLIENT_HANDSHAKE;
    static UclVar TIMEOUT_SSL_ACCEPT;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class WsClient -
  class WsClient
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class WsBase64 -
  class WsBase64
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_encode_1;
    static unsigned c_bi_mi_decode_1;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar encode(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_encode_1,op_0);
    }/*}}}*/

    inline static UclVar decode(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_decode_1,op_0);
    }/*}}}*/

    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  // - class JitContext -
  class JitContext
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    static UclVar TYPE_I8;
    static UclVar TYPE_U8;
    static UclVar TYPE_I16;
    static UclVar TYPE_U16;
    static UclVar TYPE_I32;
    static UclVar TYPE_U32;
    static UclVar TYPE_I64;
    static UclVar TYPE_U64;
    static UclVar TYPE_F32;
    static UclVar TYPE_F64;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  inline static UclVar JitContext()
  {/*{{{*/
    return __new_object_0(c_bi_class_JitContext,c_bi_mni_JitContext_0);
  }/*}}}*/

  // - class JitFunction -
  class JitFunction
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar to_string()
    {/*{{{*/
      return __static_call_0(c_bi_mi_to_string_0);
    }/*}}}*/

    inline static UclVar print()
    {/*{{{*/
      return __static_call_0(c_bi_mi_print_0);
    }/*}}}*/

  };/*}}}*/

  /*}}}*/

  // - operator methods -
  /*{{{*/
  inline UclVar operator=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator+=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_plus_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator-=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_minus_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator*=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_asterisk_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator/=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_slash_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator%=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_percent_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator<<=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_ls_br_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator>>=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_rs_br_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator&=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_ampersand_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator|=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_pipe_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator^=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_circumflex_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator&&(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_ampersand_1,a_op);
  }/*}}}*/

  inline UclVar operator||(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_pipe_1,a_op);
  }/*}}}*/

  inline UclVar operator&(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_ampersand_1,a_op);
  }/*}}}*/

  inline UclVar operator|(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_pipe_1,a_op);
  }/*}}}*/

  inline UclVar operator^(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_circumflex_1,a_op);
  }/*}}}*/

  inline UclVar operator==(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator!=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_exclamation_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator>(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_rs_br_1,a_op);
  }/*}}}*/

  inline UclVar operator<(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_ls_br_1,a_op);
  }/*}}}*/

  inline UclVar operator>=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_rs_br_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator<=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_ls_br_equal_1,a_op);
  }/*}}}*/

  inline UclVar operator>>(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_rs_br_1,a_op);
  }/*}}}*/

  inline UclVar operator<<(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_double_ls_br_1,a_op);
  }/*}}}*/

  inline UclVar operator+(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_plus_1,a_op);
  }/*}}}*/

  inline UclVar operator-(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_minus_1,a_op);
  }/*}}}*/

  inline UclVar operator*(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_asterisk_1,a_op);
  }/*}}}*/

  inline UclVar operator/(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_slash_1,a_op);
  }/*}}}*/

  inline UclVar operator%(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_percent_1,a_op);
  }/*}}}*/

  inline UclVar operator++(int)
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_post_double_plus_0);
  }/*}}}*/

  inline UclVar operator--(int)
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_post_double_minus_0);
  }/*}}}*/

  inline UclVar operator++()
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_pre_double_plus_0);
  }/*}}}*/

  inline UclVar operator--()
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_pre_double_minus_0);
  }/*}}}*/

  inline UclVar operator+()
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_pre_plus_0);
  }/*}}}*/

  inline UclVar operator-()
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_pre_minus_0);
  }/*}}}*/

  inline UclVar operator!()
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_pre_exclamation_0);
  }/*}}}*/

  inline UclVar operator~()
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_pre_tilde_0);
  }/*}}}*/

  inline UclVar operator[](UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_operator_binary_le_br_re_br_1,a_op);
  }/*}}}*/
  /*}}}*/

  // - built in methods -
  /*{{{*/

  inline UclVar compare(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_compare_1,op_0);
  }/*}}}*/

  inline UclVar to_string()
  {/*{{{*/
    return __call_0(c_bi_mni_to_string_0);
  }/*}}}*/

  inline UclVar print()
  {/*{{{*/
    return __call_0(c_bi_mni_print_0);
  }/*}}}*/

  inline UclVar sin()
  {/*{{{*/
    return __call_0(c_bi_mni_sin_0);
  }/*}}}*/

  inline UclVar cos()
  {/*{{{*/
    return __call_0(c_bi_mni_cos_0);
  }/*}}}*/

  inline UclVar tan()
  {/*{{{*/
    return __call_0(c_bi_mni_tan_0);
  }/*}}}*/

  inline UclVar asin()
  {/*{{{*/
    return __call_0(c_bi_mni_asin_0);
  }/*}}}*/

  inline UclVar acos()
  {/*{{{*/
    return __call_0(c_bi_mni_acos_0);
  }/*}}}*/

  inline UclVar atan()
  {/*{{{*/
    return __call_0(c_bi_mni_atan_0);
  }/*}}}*/

  inline UclVar exp()
  {/*{{{*/
    return __call_0(c_bi_mni_exp_0);
  }/*}}}*/

  inline UclVar log()
  {/*{{{*/
    return __call_0(c_bi_mni_log_0);
  }/*}}}*/

  inline UclVar pow(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_pow_1,op_0);
  }/*}}}*/

  inline UclVar sqrt()
  {/*{{{*/
    return __call_0(c_bi_mni_sqrt_0);
  }/*}}}*/

  inline UclVar cbrt()
  {/*{{{*/
    return __call_0(c_bi_mni_cbrt_0);
  }/*}}}*/

  inline UclVar hypot(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_hypot_1,op_0);
  }/*}}}*/

  inline UclVar _isnan()
  {/*{{{*/
    return __call_0(c_bi_mni__isnan_0);
  }/*}}}*/

  inline UclVar split(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_split_1,op_0);
  }/*}}}*/

  inline UclVar join(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_join_1,op_0);
  }/*}}}*/

  inline UclVar head(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_head_1,op_0);
  }/*}}}*/

  inline UclVar tail(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_tail_1,op_0);
  }/*}}}*/

  inline UclVar range(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_range_2,op_0,op_1);
  }/*}}}*/

  inline UclVar get_idx(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_get_idx_1,op_0);
  }/*}}}*/

  inline UclVar get_idxs(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_get_idxs_1,op_0);
  }/*}}}*/

  inline UclVar replace(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_replace_2,op_0,op_1);
  }/*}}}*/

  inline UclVar item(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_item_1,op_0);
  }/*}}}*/

  inline UclVar first_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_first_idx_0);
  }/*}}}*/

  inline UclVar next_idx(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_next_idx_1,op_0);
  }/*}}}*/

  inline UclVar length()
  {/*{{{*/
    return __call_0(c_bi_mni_length_0);
  }/*}}}*/

  inline UclVar clear()
  {/*{{{*/
    return __call_0(c_bi_mni_clear_0);
  }/*}}}*/

  inline UclVar resize(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_resize_1,op_0);
  }/*}}}*/

  inline UclVar push(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_push_1,op_0);
  }/*}}}*/

  inline UclVar push_ref(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_push_ref_1,op_0);
  }/*}}}*/

  inline UclVar pop()
  {/*{{{*/
    return __call_0(c_bi_mni_pop_0);
  }/*}}}*/

  inline UclVar last()
  {/*{{{*/
    return __call_0(c_bi_mni_last_0);
  }/*}}}*/

  inline UclVar fill(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_fill_1,op_0);
  }/*}}}*/

  inline UclVar last_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_last_idx_0);
  }/*}}}*/

  inline UclVar prev_idx(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_prev_idx_1,op_0);
  }/*}}}*/

  inline UclVar to_string(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_to_string_1,op_0);
  }/*}}}*/

  inline UclVar _throw()
  {/*{{{*/
    return __call_0(c_bi_mni__throw_0);
  }/*}}}*/

  inline UclVar get_type()
  {/*{{{*/
    return __call_0(c_bi_mni_get_type_0);
  }/*}}}*/

  inline UclVar get_value()
  {/*{{{*/
    return __call_0(c_bi_mni_get_value_0);
  }/*}}}*/

  inline UclVar get_file_name()
  {/*{{{*/
    return __call_0(c_bi_mni_get_file_name_0);
  }/*}}}*/

  inline UclVar get_line()
  {/*{{{*/
    return __call_0(c_bi_mni_get_line_0);
  }/*}}}*/

  inline UclVar error_print()
  {/*{{{*/
    return __call_0(c_bi_mni_error_print_0);
  }/*}}}*/

  inline UclVar lock()
  {/*{{{*/
    return __call_0(c_bi_mni_lock_0);
  }/*}}}*/

  inline UclVar try_lock()
  {/*{{{*/
    return __call_0(c_bi_mni_try_lock_0);
  }/*}}}*/

  inline UclVar unlock()
  {/*{{{*/
    return __call_0(c_bi_mni_unlock_0);
  }/*}}}*/

  inline UclVar join()
  {/*{{{*/
    return __call_0(c_bi_mni_join_0);
  }/*}}}*/

  inline UclVar try_join()
  {/*{{{*/
    return __call_0(c_bi_mni_try_join_0);
  }/*}}}*/

  inline UclVar detach()
  {/*{{{*/
    return __call_0(c_bi_mni_detach_0);
  }/*}}}*/

  inline UclVar yield()
  {/*{{{*/
    return __call_0(c_bi_mni_yield_0);
  }/*}}}*/

  inline UclVar call(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_call_1,op_0);
  }/*}}}*/

  inline UclVar size()
  {/*{{{*/
    return __call_0(c_bi_mni_size_0);
  }/*}}}*/

  inline UclVar call()
  {/*{{{*/
    return __call_0(c_bi_mni_call_0);
  }/*}}}*/

  inline UclVar call(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_call_2,op_0,op_1);
  }/*}}}*/

  inline UclVar sleep(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_sleep_1,op_0);
  }/*}}}*/

  inline UclVar srand(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_srand_1,op_0);
  }/*}}}*/

  inline UclVar rand()
  {/*{{{*/
    return __call_0(c_bi_mni_rand_0);
  }/*}}}*/

  inline UclVar getpid()
  {/*{{{*/
    return __call_0(c_bi_mni_getpid_0);
  }/*}}}*/

  inline UclVar getuid()
  {/*{{{*/
    return __call_0(c_bi_mni_getuid_0);
  }/*}}}*/

  inline UclVar getgid()
  {/*{{{*/
    return __call_0(c_bi_mni_getgid_0);
  }/*}}}*/

  inline UclVar system(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_system_1,op_0);
  }/*}}}*/

  inline UclVar exit(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_exit_1,op_0);
  }/*}}}*/

  inline UclVar open(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_open_2,op_0,op_1);
  }/*}}}*/

  inline UclVar popen(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_popen_2,op_0,op_1);
  }/*}}}*/

  inline UclVar mkdir(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_mkdir_1,op_0);
  }/*}}}*/

  inline UclVar rmdir(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_rmdir_1,op_0);
  }/*}}}*/

  inline UclVar chdir(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_chdir_1,op_0);
  }/*}}}*/

  inline UclVar listdir(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_listdir_1,op_0);
  }/*}}}*/

  inline UclVar mkfifo(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_mkfifo_1,op_0);
  }/*}}}*/

  inline UclVar remove(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_remove_1,op_0);
  }/*}}}*/

  inline UclVar rename(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_rename_2,op_0,op_1);
  }/*}}}*/

  inline UclVar getcwd()
  {/*{{{*/
    return __call_0(c_bi_mni_getcwd_0);
  }/*}}}*/

  inline UclVar setenv(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_setenv_2,op_0,op_1);
  }/*}}}*/

  inline UclVar getenv(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_getenv_1,op_0);
  }/*}}}*/

  inline UclVar is_file(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_is_file_1,op_0);
  }/*}}}*/

  inline UclVar is_dir(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_is_dir_1,op_0);
  }/*}}}*/

  inline UclVar size(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_size_1,op_0);
  }/*}}}*/

  inline UclVar time()
  {/*{{{*/
    return __call_0(c_bi_mni_time_0);
  }/*}}}*/

  inline UclVar close()
  {/*{{{*/
    return __call_0(c_bi_mni_close_0);
  }/*}}}*/

  inline UclVar write(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_write_1,op_0);
  }/*}}}*/

  inline UclVar flush()
  {/*{{{*/
    return __call_0(c_bi_mni_flush_0);
  }/*}}}*/

  inline UclVar read()
  {/*{{{*/
    return __call_0(c_bi_mni_read_0);
  }/*}}}*/

  inline UclVar readln()
  {/*{{{*/
    return __call_0(c_bi_mni_readln_0);
  }/*}}}*/

  inline UclVar read(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_read_1,op_0);
  }/*}}}*/

  inline UclVar get_fd()
  {/*{{{*/
    return __call_0(c_bi_mni_get_fd_0);
  }/*}}}*/

  inline UclVar next_item()
  {/*{{{*/
    return __call_0(c_bi_mni_next_item_0);
  }/*}}}*/

  inline UclVar name()
  {/*{{{*/
    return __call_0(c_bi_mni_name_0);
  }/*}}}*/

  inline UclVar port()
  {/*{{{*/
    return __call_0(c_bi_mni_port_0);
  }/*}}}*/

  inline UclVar listen(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_listen_2,op_0,op_1);
  }/*}}}*/

  inline UclVar accept()
  {/*{{{*/
    return __call_0(c_bi_mni_accept_0);
  }/*}}}*/

  inline UclVar accept_nonblock()
  {/*{{{*/
    return __call_0(c_bi_mni_accept_nonblock_0);
  }/*}}}*/

  inline UclVar connect(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_connect_1,op_0);
  }/*}}}*/

  inline UclVar bind(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_bind_1,op_0);
  }/*}}}*/

  inline UclVar sendto(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_sendto_2,op_0,op_1);
  }/*}}}*/

  inline UclVar recvfrom()
  {/*{{{*/
    return __call_0(c_bi_mni_recvfrom_0);
  }/*}}}*/

  inline UclVar set_timeout(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_set_timeout_2,op_0,op_1);
  }/*}}}*/

  inline UclVar read_nonblock()
  {/*{{{*/
    return __call_0(c_bi_mni_read_nonblock_0);
  }/*}}}*/

  inline UclVar match(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_match_1,op_0);
  }/*}}}*/

  inline UclVar match(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_match_2,op_0,op_1);
  }/*}}}*/

  inline UclVar match_from(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_match_from_2,op_0,op_1);
  }/*}}}*/

  inline UclVar bind(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_bind_2,op_0,op_1);
  }/*}}}*/

  inline UclVar unbind(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_unbind_1,op_0);
  }/*}}}*/

  inline UclVar send(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_send_2,op_0,op_1);
  }/*}}}*/

  inline UclVar ready(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_ready_1,op_0);
  }/*}}}*/

  inline UclVar poll(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_poll_1,op_0);
  }/*}}}*/

  inline UclVar schedule(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __call_3(c_bi_mni_schedule_3,op_0,op_1,op_2);
  }/*}}}*/

  inline UclVar process()
  {/*{{{*/
    return __call_0(c_bi_mni_process_0);
  }/*}}}*/

  inline UclVar remain()
  {/*{{{*/
    return __call_0(c_bi_mni_remain_0);
  }/*}}}*/

  inline UclVar getres(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_getres_1,op_0);
  }/*}}}*/

  inline UclVar gettime(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_gettime_1,op_0);
  }/*}}}*/

  inline UclVar settime(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_settime_2,op_0,op_1);
  }/*}}}*/

  inline UclVar items()
  {/*{{{*/
    return __call_0(c_bi_mni_items_0);
  }/*}}}*/

  inline UclVar insert(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_insert_1,op_0);
  }/*}}}*/

  inline UclVar insert_ref(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_insert_ref_1,op_0);
  }/*}}}*/

  inline UclVar next()
  {/*{{{*/
    return __call_0(c_bi_mni_next_0);
  }/*}}}*/

  inline UclVar contain(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_contain_1,op_0);
  }/*}}}*/

  inline UclVar append(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_append_1,op_0);
  }/*}}}*/

  inline UclVar append_ref(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_append_ref_1,op_0);
  }/*}}}*/

  inline UclVar prepend(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_prepend_1,op_0);
  }/*}}}*/

  inline UclVar prepend_ref(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_prepend_ref_1,op_0);
  }/*}}}*/

  inline UclVar insert_before(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_insert_before_2,op_0,op_1);
  }/*}}}*/

  inline UclVar insert_before_ref(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_insert_before_ref_2,op_0,op_1);
  }/*}}}*/

  inline UclVar insert_after(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_insert_after_2,op_0,op_1);
  }/*}}}*/

  inline UclVar insert_after_ref(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_insert_after_ref_2,op_0,op_1);
  }/*}}}*/

  inline UclVar has_idx(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_has_idx_1,op_0);
  }/*}}}*/

  inline UclVar keys()
  {/*{{{*/
    return __call_0(c_bi_mni_keys_0);
  }/*}}}*/

  inline UclVar store_ref(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_store_ref_2,op_0,op_1);
  }/*}}}*/

  inline UclVar has_key(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_has_key_1,op_0);
  }/*}}}*/

  inline UclVar remove_key(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_remove_key_1,op_0);
  }/*}}}*/

  inline UclVar first_key()
  {/*{{{*/
    return __call_0(c_bi_mni_first_key_0);
  }/*}}}*/

  inline UclVar last_key()
  {/*{{{*/
    return __call_0(c_bi_mni_last_key_0);
  }/*}}}*/

  inline UclVar next_key(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_next_key_1,op_0);
  }/*}}}*/

  inline UclVar prev_key(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_prev_key_1,op_0);
  }/*}}}*/

  inline UclVar lee_key(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_lee_key_1,op_0);
  }/*}}}*/

  inline UclVar gre_key(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_gre_key_1,op_0);
  }/*}}}*/

  inline UclVar create(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_create_1,op_0);
  }/*}}}*/

  inline UclVar create_nice(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_create_nice_2,op_0,op_1);
  }/*}}}*/

  inline UclVar parse(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_parse_1,op_0);
  }/*}}}*/

  inline UclVar version()
  {/*{{{*/
    return __call_0(c_bi_mni_version_0);
  }/*}}}*/

  inline UclVar user_data()
  {/*{{{*/
    return __call_0(c_bi_mni_user_data_0);
  }/*}}}*/

  inline UclVar client(UclVar op_0,UclVar op_1,UclVar op_2,UclVar op_3)
  {/*{{{*/
    return __call_4(c_bi_mni_client_4,op_0,op_1,op_2,op_3);
  }/*}}}*/

  inline UclVar get_fds()
  {/*{{{*/
    return __call_0(c_bi_mni_get_fds_0);
  }/*}}}*/

  inline UclVar process(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_process_1,op_0);
  }/*}}}*/

  inline UclVar protocol_idx(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_protocol_idx_1,op_0);
  }/*}}}*/

  inline UclVar callback_on_writable(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_callback_on_writable_1,op_0);
  }/*}}}*/

  inline UclVar reason()
  {/*{{{*/
    return __call_0(c_bi_mni_reason_0);
  }/*}}}*/

  inline UclVar received_data()
  {/*{{{*/
    return __call_0(c_bi_mni_received_data_0);
  }/*}}}*/

  inline UclVar ctx_user_data()
  {/*{{{*/
    return __call_0(c_bi_mni_ctx_user_data_0);
  }/*}}}*/

  inline UclVar protocol_name()
  {/*{{{*/
    return __call_0(c_bi_mni_protocol_name_0);
  }/*}}}*/

  inline UclVar callback_on_writable()
  {/*{{{*/
    return __call_0(c_bi_mni_callback_on_writable_0);
  }/*}}}*/

  inline UclVar write(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_write_2,op_0,op_1);
  }/*}}}*/

  inline UclVar connected()
  {/*{{{*/
    return __call_0(c_bi_mni_connected_0);
  }/*}}}*/

  inline UclVar encode(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_encode_1,op_0);
  }/*}}}*/

  inline UclVar decode(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_decode_1,op_0);
  }/*}}}*/

  inline UclVar create_fun(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_create_fun_1,op_0);
  }/*}}}*/

  inline UclVar signature()
  {/*{{{*/
    return __call_0(c_bi_mni_signature_0);
  }/*}}}*/

  /*}}}*/

};/*}}}*/

// - inline methods of class UclVar -

inline void UclVar::BLANK()
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_blank;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = 0;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::CHAR(char a_value)
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_char;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (basic_64b)a_value;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::INTEGER(long long int a_value)
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_integer;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (basic_64b)a_value;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::FLOAT(double a_value)
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_float;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = *((basic_64b *)&a_value);

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::STRING(unsigned a_length,const char *a_data)
{/*{{{*/
  string_s *string_ptr = it_ptr->get_new_string_ptr();
  string_ptr->set(a_length,a_data);

  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_string;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (basic_64b)string_ptr;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::ARRAY(unsigned a_size,const UclVar *a_array)
{/*{{{*/
  pointer_array_s *array_ptr = it_ptr->get_new_array_ptr();

  if (a_size > 0)
  {
    const UclVar *ucv_ptr = a_array;
    const UclVar *ucv_ptr_end = ucv_ptr + a_size;
    
    do {
      ucv_ptr->location_ptr->v_reference_cnt.atomic_inc();
      array_ptr->push((pointer)ucv_ptr->location_ptr);
    } while(++ucv_ptr < ucv_ptr_end);
  }

  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_array;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (basic_64b)array_ptr;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline char UclVar::__char()
{/*{{{*/
  location_s *tmp_location = it_ptr->get_location_value(location_ptr);

  // - ERROR -
  if (tmp_location->v_type != c_bi_class_char)
  {
    throw std::string("Conversion to __char error");
  }

  return (char)tmp_location->v_data_ptr;
}/*}}}*/

inline long long int UclVar::__int()
{/*{{{*/
  long long int value;

  // - ERROR -
  if (!it_ptr->retrieve_integer(it_ptr->get_location_value(location_ptr),value))
  {
    throw std::string("Conversion to __int error");
  }

  return value;
}/*}}}*/

inline double UclVar::__float()
{/*{{{*/
  double value;

  // - ERROR -
  if (!it_ptr->retrieve_float(it_ptr->get_location_value(location_ptr),value))
  {
    throw std::string("Conversion to __float error");
  }

  return value;
}/*}}}*/

inline const char *UclVar::__str()
{/*{{{*/
  location_s *tmp_location = it_ptr->get_location_value(location_ptr);

  // - ERROR -
  if (tmp_location->v_type != c_bi_class_string)
  {
    throw std::string("Conversion to __str error");
  }

  return ((string_s *)tmp_location->v_data_ptr)->data;
}/*}}}*/


inline void UclVar::__free()
{/*{{{*/
  it_ptr->release_location_ptr(location_ptr);

  BLANK();
}/*}}}*/

inline UclVar UclVar::__type()
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_type;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (basic_64b)it_ptr->get_location_value(location_ptr)->v_type;

  UclVar ret_value(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);

  return ret_value;
}/*}}}*/

#endif

