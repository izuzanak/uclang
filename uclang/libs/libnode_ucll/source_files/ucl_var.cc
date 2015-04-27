
@begin
include "ucl_var.h"
@end

// - static members of UclVar -

interpreter_thread_s *UclVar::it_ptr;
pointer_array_s UclVar::static_const_array;

// - built in class indexes -
unsigned UclVar::c_bi_class_node_callback;
unsigned UclVar::c_bi_class_sys;
unsigned UclVar::c_bi_class_pipe;
unsigned UclVar::c_bi_class_file;

#ifdef ENABLE_CLASS_SOCKET
unsigned UclVar::c_bi_class_socket_addr;
unsigned UclVar::c_bi_class_socket;
#endif

#ifdef ENABLE_CLASS_REGEX
unsigned UclVar::c_bi_class_regex;
#endif

unsigned UclVar::c_bi_class_signal;
unsigned UclVar::c_bi_class_poll;
unsigned UclVar::c_bi_class_timer;
unsigned UclVar::c_bi_class_clock;
unsigned UclVar::c_bi_class_stack;
unsigned UclVar::c_bi_class_queue;
unsigned UclVar::c_bi_class_set;
unsigned UclVar::c_bi_class_list;
unsigned UclVar::c_bi_class_tree;
unsigned UclVar::c_bi_class_dict;
unsigned UclVar::c_bi_class_json;
unsigned UclVar::c_bi_class_ws_context;
unsigned UclVar::c_bi_class_ws_conn;
unsigned UclVar::c_bi_class_ws_client;
unsigned UclVar::c_bi_class_ws_base64;
unsigned UclVar::c_bi_class_jit_context;
unsigned UclVar::c_bi_class_jit_function;

// - built in method name indexes -
unsigned UclVar::c_bi_mni_binary_equal;
unsigned UclVar::c_bi_mni_binary_plus_equal;
unsigned UclVar::c_bi_mni_binary_minus_equal;
unsigned UclVar::c_bi_mni_binary_asterisk_equal;
unsigned UclVar::c_bi_mni_binary_slash_equal;
unsigned UclVar::c_bi_mni_binary_percent_equal;
unsigned UclVar::c_bi_mni_binary_double_ls_br_equal;
unsigned UclVar::c_bi_mni_binary_double_rs_br_equal;
unsigned UclVar::c_bi_mni_binary_ampersand_equal;
unsigned UclVar::c_bi_mni_binary_pipe_equal;
unsigned UclVar::c_bi_mni_binary_circumflex_equal;
unsigned UclVar::c_bi_mni_binary_double_ampersand;
unsigned UclVar::c_bi_mni_binary_double_pipe;
unsigned UclVar::c_bi_mni_binary_ampersand;
unsigned UclVar::c_bi_mni_binary_pipe;
unsigned UclVar::c_bi_mni_binary_circumflex;
unsigned UclVar::c_bi_mni_binary_double_equal;
unsigned UclVar::c_bi_mni_binary_exclamation_equal;
unsigned UclVar::c_bi_mni_binary_rs_br;
unsigned UclVar::c_bi_mni_binary_ls_br;
unsigned UclVar::c_bi_mni_binary_rs_br_equal;
unsigned UclVar::c_bi_mni_binary_ls_br_equal;
unsigned UclVar::c_bi_mni_binary_double_rs_br;
unsigned UclVar::c_bi_mni_binary_double_ls_br;
unsigned UclVar::c_bi_mni_binary_plus;
unsigned UclVar::c_bi_mni_binary_minus;
unsigned UclVar::c_bi_mni_binary_asterisk;
unsigned UclVar::c_bi_mni_binary_slash;
unsigned UclVar::c_bi_mni_binary_percent;
unsigned UclVar::c_bi_mni_unary_post_double_plus;
unsigned UclVar::c_bi_mni_unary_post_double_minus;
unsigned UclVar::c_bi_mni_unary_pre_double_plus;
unsigned UclVar::c_bi_mni_unary_pre_double_minus;
unsigned UclVar::c_bi_mni_unary_pre_plus;
unsigned UclVar::c_bi_mni_unary_pre_minus;
unsigned UclVar::c_bi_mni_unary_pre_exclamation;
unsigned UclVar::c_bi_mni_unary_pre_tilde;
unsigned UclVar::c_bi_mni_binary_le_br_re_br;
unsigned UclVar::c_bi_mni_compare_1;
unsigned UclVar::c_bi_mni_item_1;
unsigned UclVar::c_bi_mni_first_idx_0;
unsigned UclVar::c_bi_mni_last_idx_0;
unsigned UclVar::c_bi_mni_next_idx_1;
unsigned UclVar::c_bi_mni_prev_idx_1;
unsigned UclVar::c_bi_mni_next_item_0;
unsigned UclVar::c_bi_mni_length_0;
unsigned UclVar::c_bi_mni_to_string_0;
unsigned UclVar::c_bi_mni_print_0;

unsigned UclVar::c_bi_mni_Blank_0;

unsigned UclVar::c_bi_mni_Char_0;
unsigned UclVar::c_bi_mni_Char_1;

unsigned UclVar::c_bi_mni_Integer_0;
unsigned UclVar::c_bi_mni_Integer_1;
unsigned UclVar::c_bi_mni_Integer_2;

unsigned UclVar::c_bi_mni_Float_0;
unsigned UclVar::c_bi_mni_Float_1;
unsigned UclVar::c_bi_mni_sin_0;
unsigned UclVar::c_bi_mni_cos_0;
unsigned UclVar::c_bi_mni_tan_0;
unsigned UclVar::c_bi_mni_asin_0;
unsigned UclVar::c_bi_mni_acos_0;
unsigned UclVar::c_bi_mni_atan_0;
unsigned UclVar::c_bi_mni_exp_0;
unsigned UclVar::c_bi_mni_log_0;
unsigned UclVar::c_bi_mni_pow_1;
unsigned UclVar::c_bi_mni_sqrt_0;
unsigned UclVar::c_bi_mni_cbrt_0;
unsigned UclVar::c_bi_mni_hypot_1;
unsigned UclVar::c_bi_mni_isnan_0;

unsigned UclVar::c_bi_mni_String_0;
unsigned UclVar::c_bi_mni_String_1;
unsigned UclVar::c_bi_mni_split_1;
unsigned UclVar::c_bi_mni_join_1;
unsigned UclVar::c_bi_mni_head_1;
unsigned UclVar::c_bi_mni_tail_1;
unsigned UclVar::c_bi_mni_range_2;
unsigned UclVar::c_bi_mni_get_idx_1;
unsigned UclVar::c_bi_mni_get_idxs_1;
unsigned UclVar::c_bi_mni_replace_2;

unsigned UclVar::c_bi_mni_Array_0;
unsigned UclVar::c_bi_mni_Array_1;
unsigned UclVar::c_bi_mni_clear_0;
unsigned UclVar::c_bi_mni_resize_1;
unsigned UclVar::c_bi_mni_push_1;
unsigned UclVar::c_bi_mni_pop_0;
unsigned UclVar::c_bi_mni_last_0;
unsigned UclVar::c_bi_mni_fill_1;
unsigned UclVar::c_bi_mni_to_string_1;

unsigned UclVar::c_bi_mni_Error_0;

unsigned UclVar::c_bi_mni_Exception_0;
unsigned UclVar::c_bi_mni_Exception_1;
unsigned UclVar::c_bi_mni_throw_0;
unsigned UclVar::c_bi_mni_get_type_0;
unsigned UclVar::c_bi_mni_get_value_0;
unsigned UclVar::c_bi_mni_get_file_name_0;
unsigned UclVar::c_bi_mni_get_line_0;
unsigned UclVar::c_bi_mni_error_print_0;

unsigned UclVar::c_bi_mni_Type_0;
unsigned UclVar::c_bi_mni_Type_1;

unsigned UclVar::c_bi_mni_Mutex_0;
unsigned UclVar::c_bi_mni_lock_0;
unsigned UclVar::c_bi_mni_try_lock_0;
unsigned UclVar::c_bi_mni_unlock_0;

unsigned UclVar::c_bi_mni_join_0;
unsigned UclVar::c_bi_mni_try_join_0;
unsigned UclVar::c_bi_mni_detach_0;
unsigned UclVar::c_bi_mni_yield_0;

unsigned UclVar::c_bi_mni_Delegate_3;
unsigned UclVar::c_bi_mni_call_1;

unsigned UclVar::c_bi_mni_size_0;

unsigned UclVar::c_bi_mni_NodeCallback_2;

unsigned UclVar::c_bi_mni_sleep_1;
unsigned UclVar::c_bi_mni_srand_1;
unsigned UclVar::c_bi_mni_rand_0;
unsigned UclVar::c_bi_mni_getpid_0;
unsigned UclVar::c_bi_mni_getuid_0;
unsigned UclVar::c_bi_mni_getgid_0;
unsigned UclVar::c_bi_mni_system_1;
unsigned UclVar::c_bi_mni_exit_1;
unsigned UclVar::c_bi_mni_open_2;
unsigned UclVar::c_bi_mni_popen_2;
unsigned UclVar::c_bi_mni_mkdir_1;
unsigned UclVar::c_bi_mni_rmdir_1;
unsigned UclVar::c_bi_mni_chdir_1;
unsigned UclVar::c_bi_mni_listdir_1;
unsigned UclVar::c_bi_mni_mkfifo_1;
unsigned UclVar::c_bi_mni_remove_1;
unsigned UclVar::c_bi_mni_rename_2;
unsigned UclVar::c_bi_mni_getcwd_0;
unsigned UclVar::c_bi_mni_setenv_2;
unsigned UclVar::c_bi_mni_getenv_1;
unsigned UclVar::c_bi_mni_is_file_1;
unsigned UclVar::c_bi_mni_is_dir_1;
unsigned UclVar::c_bi_mni_size_1;
unsigned UclVar::c_bi_mni_time_0;

unsigned UclVar::c_bi_mni_Pipe_0;
unsigned UclVar::c_bi_mni_Pipe_2;
unsigned UclVar::c_bi_mni_close_0;
unsigned UclVar::c_bi_mni_write_1;
unsigned UclVar::c_bi_mni_flush_0;
unsigned UclVar::c_bi_mni_read_0;
unsigned UclVar::c_bi_mni_readln_0;
unsigned UclVar::c_bi_mni_read_1;
unsigned UclVar::c_bi_mni_get_fd_0;

unsigned UclVar::c_bi_mni_File_0;
unsigned UclVar::c_bi_mni_File_2;

unsigned UclVar::c_bi_mni_SocketAddr_2;
unsigned UclVar::c_bi_mni_name_0;
unsigned UclVar::c_bi_mni_port_0;

unsigned UclVar::c_bi_mni_Socket_0;
unsigned UclVar::c_bi_mni_Socket_2;
unsigned UclVar::c_bi_mni_listen_2;
unsigned UclVar::c_bi_mni_accept_0;
unsigned UclVar::c_bi_mni_accept_nonblock_0;
unsigned UclVar::c_bi_mni_connect_1;
unsigned UclVar::c_bi_mni_bind_1;
unsigned UclVar::c_bi_mni_sendto_2;
unsigned UclVar::c_bi_mni_recvfrom_0;
unsigned UclVar::c_bi_mni_set_timeout_2;
unsigned UclVar::c_bi_mni_read_nonblock_0;

unsigned UclVar::c_bi_mni_Regex_0;
unsigned UclVar::c_bi_mni_Regex_1;
unsigned UclVar::c_bi_mni_match_1;
unsigned UclVar::c_bi_mni_match_2;
unsigned UclVar::c_bi_mni_match_from_2;

unsigned UclVar::c_bi_mni_bind_2;
unsigned UclVar::c_bi_mni_unbind_1;
unsigned UclVar::c_bi_mni_send_2;

unsigned UclVar::c_bi_mni_Poll_1;
unsigned UclVar::c_bi_mni_ready_1;
unsigned UclVar::c_bi_mni_poll_1;

unsigned UclVar::c_bi_mni_Timer_0;
unsigned UclVar::c_bi_mni_schedule_3;
unsigned UclVar::c_bi_mni_process_0;
unsigned UclVar::c_bi_mni_remain_0;

unsigned UclVar::c_bi_mni_Stack_0;
unsigned UclVar::c_bi_mni_Stack_1;
unsigned UclVar::c_bi_mni_items_0;

unsigned UclVar::c_bi_mni_Queue_0;
unsigned UclVar::c_bi_mni_Queue_1;
unsigned UclVar::c_bi_mni_insert_1;
unsigned UclVar::c_bi_mni_next_0;

unsigned UclVar::c_bi_mni_Set_0;
unsigned UclVar::c_bi_mni_Set_1;
unsigned UclVar::c_bi_mni_contain_1;

unsigned UclVar::c_bi_mni_List_0;
unsigned UclVar::c_bi_mni_List_1;
unsigned UclVar::c_bi_mni_append_1;
unsigned UclVar::c_bi_mni_prepend_1;
unsigned UclVar::c_bi_mni_insert_after_2;
unsigned UclVar::c_bi_mni_insert_before_2;
unsigned UclVar::c_bi_mni_has_idx_1;

unsigned UclVar::c_bi_mni_Tree_0;
unsigned UclVar::c_bi_mni_Tree_1;

unsigned UclVar::c_bi_mni_Dict_0;
unsigned UclVar::c_bi_mni_Dict_1;
unsigned UclVar::c_bi_mni_keys_0;
unsigned UclVar::c_bi_mni_has_key_1;
unsigned UclVar::c_bi_mni_remove_key_1;
unsigned UclVar::c_bi_mni_first_key_0;
unsigned UclVar::c_bi_mni_next_key_1;

unsigned UclVar::c_bi_mni_create_1;
unsigned UclVar::c_bi_mni_create_nice_2;
unsigned UclVar::c_bi_mni_parse_1;

unsigned UclVar::c_bi_mni_WsContext_2;
unsigned UclVar::c_bi_mni_user_data_0;
unsigned UclVar::c_bi_mni_client_4;
unsigned UclVar::c_bi_mni_get_fds_0;
unsigned UclVar::c_bi_mni_process_1;
unsigned UclVar::c_bi_mni_protocol_idx_1;
unsigned UclVar::c_bi_mni_callback_on_writable_1;

unsigned UclVar::c_bi_mni_reason_0;
unsigned UclVar::c_bi_mni_received_data_0;
unsigned UclVar::c_bi_mni_ctx_user_data_0;
unsigned UclVar::c_bi_mni_protocol_name_0;
unsigned UclVar::c_bi_mni_callback_on_writable_0;
unsigned UclVar::c_bi_mni_write_2;

unsigned UclVar::c_bi_mni_connected_0;

unsigned UclVar::c_bi_mni_encode_1;
unsigned UclVar::c_bi_mni_decode_1;

unsigned UclVar::c_bi_mni_JitContext_0;
unsigned UclVar::c_bi_mni_create_fun_1;

unsigned UclVar::c_bi_mni_signature_0;

// - built in constants name indexes -
unsigned UclVar::c_bi_vni_ERROR_INVALID;
unsigned UclVar::c_bi_vni_ERROR_DEADLOCK;
unsigned UclVar::c_bi_vni_ERROR_BUSY;
unsigned UclVar::c_bi_vni_ERROR_PERMISSION;

unsigned UclVar::c_bi_vni_ERROR_AGAIN;
unsigned UclVar::c_bi_vni_ERROR_SEARCH;

unsigned UclVar::c_bi_vni_NAME;
unsigned UclVar::c_bi_vni_SEP;

unsigned UclVar::c_bi_vni_stdin;
unsigned UclVar::c_bi_vni_stdout;
unsigned UclVar::c_bi_vni_stderr;

unsigned UclVar::c_bi_vni_AF_UNIX;
unsigned UclVar::c_bi_vni_AF_FILE;
unsigned UclVar::c_bi_vni_AF_INET;
unsigned UclVar::c_bi_vni_SOCK_STREAM;
unsigned UclVar::c_bi_vni_SOCK_DGRAM;
unsigned UclVar::c_bi_vni_SOCK_RAW;
unsigned UclVar::c_bi_vni_SO_RCVTIMEO;
unsigned UclVar::c_bi_vni_SO_SNDTIMEO;

unsigned UclVar::c_bi_vni__SIGINT;
unsigned UclVar::c_bi_vni__SIGTERM;
unsigned UclVar::c_bi_vni__SIGHUP;

unsigned UclVar::c_bi_vni_POLLIN;
unsigned UclVar::c_bi_vni_POLLPRI;
unsigned UclVar::c_bi_vni_POLLOUT;
unsigned UclVar::c_bi_vni_POLLERR;
unsigned UclVar::c_bi_vni_POLLHUP;
unsigned UclVar::c_bi_vni_POLLNVAL;

unsigned UclVar::c_bi_vni_PORT_NO_LISTEN;

unsigned UclVar::c_bi_vni_WRITE_TEXT;
unsigned UclVar::c_bi_vni_WRITE_BINARY;
unsigned UclVar::c_bi_vni_WRITE_CONTINUATION;
unsigned UclVar::c_bi_vni_WRITE_HTTP;
unsigned UclVar::c_bi_vni_WRITE_CLOSE;
unsigned UclVar::c_bi_vni_CB_ESTABLISHED;
unsigned UclVar::c_bi_vni_CB_CLIENT_CONNECTION_ERROR;
unsigned UclVar::c_bi_vni_CB_CLIENT_FILTER_PRE_ESTABLISH;
unsigned UclVar::c_bi_vni_CB_CLIENT_ESTABLISHED;
unsigned UclVar::c_bi_vni_CB_CLOSED;
unsigned UclVar::c_bi_vni_CB_RECEIVE;
unsigned UclVar::c_bi_vni_CB_CLIENT_RECEIVE;
unsigned UclVar::c_bi_vni_CB_CLIENT_RECEIVE_PONG;
unsigned UclVar::c_bi_vni_CB_CLIENT_WRITEABLE;
unsigned UclVar::c_bi_vni_CB_SERVER_WRITEABLE;
unsigned UclVar::c_bi_vni_CB_HTTP;
unsigned UclVar::c_bi_vni_CB_HTTP_FILE_COMPLETION;
unsigned UclVar::c_bi_vni_CB_FILTER_NETWORK_CONNECTION;
unsigned UclVar::c_bi_vni_CB_FILTER_PROTOCOL_CONNECTION;
unsigned UclVar::c_bi_vni_CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS;
unsigned UclVar::c_bi_vni_CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS;
unsigned UclVar::c_bi_vni_CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION;
unsigned UclVar::c_bi_vni_CB_CLIENT_APPEND_HANDSHAKE_HEADER;
unsigned UclVar::c_bi_vni_CB_CONFIRM_EXTENSION_OKAY;
unsigned UclVar::c_bi_vni_CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED;
unsigned UclVar::c_bi_vni_CB_PROTOCOL_INIT;
unsigned UclVar::c_bi_vni_CB_PROTOCOL_DESTROY;
unsigned UclVar::c_bi_vni_CB_ADD_POLL_FD;
unsigned UclVar::c_bi_vni_CB_DEL_POLL_FD;
unsigned UclVar::c_bi_vni_CB_CHANGE_MODE_POLL_FD;
unsigned UclVar::c_bi_vni_TIMEOUT_NO_PENDING;
unsigned UclVar::c_bi_vni_TIMEOUT_AWAITING_PROXY_RESPONSE;
unsigned UclVar::c_bi_vni_TIMEOUT_AWAITING_CONNECT_RESPONSE;
unsigned UclVar::c_bi_vni_TIMEOUT_ESTABLISH_WITH_SERVER;
unsigned UclVar::c_bi_vni_TIMEOUT_AWAITING_SERVER_RESPONSE;
unsigned UclVar::c_bi_vni_TIMEOUT_AWAITING_PING;
unsigned UclVar::c_bi_vni_TIMEOUT_CLOSE_ACK;
unsigned UclVar::c_bi_vni_TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE;
unsigned UclVar::c_bi_vni_TIMEOUT_SENT_CLIENT_HANDSHAKE;
unsigned UclVar::c_bi_vni_TIMEOUT_SSL_ACCEPT;

unsigned UclVar::c_bi_vni_TYPE_I8;
unsigned UclVar::c_bi_vni_TYPE_U8;
unsigned UclVar::c_bi_vni_TYPE_I16;
unsigned UclVar::c_bi_vni_TYPE_U16;
unsigned UclVar::c_bi_vni_TYPE_I32;
unsigned UclVar::c_bi_vni_TYPE_U32;
unsigned UclVar::c_bi_vni_TYPE_I64;
unsigned UclVar::c_bi_vni_TYPE_U64;
unsigned UclVar::c_bi_vni_TYPE_F32;
unsigned UclVar::c_bi_vni_TYPE_F64;

// - static method indexes -
unsigned UclVar::Sys::c_bi_mi_sleep_1;
unsigned UclVar::Sys::c_bi_mi_srand_1;
unsigned UclVar::Sys::c_bi_mi_rand_0;
unsigned UclVar::Sys::c_bi_mi_getpid_0;
unsigned UclVar::Sys::c_bi_mi_getuid_0;
unsigned UclVar::Sys::c_bi_mi_getgid_0;
unsigned UclVar::Sys::c_bi_mi_system_1;
unsigned UclVar::Sys::c_bi_mi_exit_1;
unsigned UclVar::Sys::c_bi_mi_open_2;
unsigned UclVar::Sys::c_bi_mi_popen_2;
unsigned UclVar::Sys::c_bi_mi_mkdir_1;
unsigned UclVar::Sys::c_bi_mi_rmdir_1;
unsigned UclVar::Sys::c_bi_mi_chdir_1;
unsigned UclVar::Sys::c_bi_mi_listdir_1;
unsigned UclVar::Sys::c_bi_mi_mkfifo_1;
unsigned UclVar::Sys::c_bi_mi_remove_1;
unsigned UclVar::Sys::c_bi_mi_rename_2;
unsigned UclVar::Sys::c_bi_mi_getcwd_0;
unsigned UclVar::Sys::c_bi_mi_setenv_2;
unsigned UclVar::Sys::c_bi_mi_getenv_1;
unsigned UclVar::Sys::c_bi_mi_is_file_1;
unsigned UclVar::Sys::c_bi_mi_is_dir_1;
unsigned UclVar::Sys::c_bi_mi_size_1;
unsigned UclVar::Sys::c_bi_mi_time_0;

unsigned UclVar::Signal::c_bi_mi_bind_2;
unsigned UclVar::Signal::c_bi_mi_unbind_1;
unsigned UclVar::Signal::c_bi_mi_send_2;

unsigned UclVar::Json::c_bi_mi_create_1;
unsigned UclVar::Json::c_bi_mi_create_nice_2;
unsigned UclVar::Json::c_bi_mi_parse_1;

unsigned UclVar::WsBase64::c_bi_mi_encode_1;
unsigned UclVar::WsBase64::c_bi_mi_decode_1;

// - initialize built in constants values -
UclVar UclVar::Mutex::ERROR_INVALID    = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_DEADLOCK   = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_BUSY       = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_PERMISSION = UclVar(NO_INIT());

UclVar UclVar::Thread::ERROR_AGAIN    = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_SEARCH   = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_INVALID  = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_DEADLOCK = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_BUSY     = UclVar(NO_INIT());

UclVar UclVar::Sys::NAME = UclVar(NO_INIT());
UclVar UclVar::Sys::SEP  = UclVar(NO_INIT());

UclVar UclVar::File::stdin  = UclVar(NO_INIT());
UclVar UclVar::File::stdout = UclVar(NO_INIT());
UclVar UclVar::File::stderr = UclVar(NO_INIT());

UclVar UclVar::Socket::AF_UNIX     = UclVar(NO_INIT());
UclVar UclVar::Socket::AF_FILE     = UclVar(NO_INIT());
UclVar UclVar::Socket::AF_INET     = UclVar(NO_INIT());
UclVar UclVar::Socket::SOCK_STREAM = UclVar(NO_INIT());
UclVar UclVar::Socket::SOCK_DGRAM  = UclVar(NO_INIT());
UclVar UclVar::Socket::SOCK_RAW    = UclVar(NO_INIT());
UclVar UclVar::Socket::SO_RCVTIMEO = UclVar(NO_INIT());
UclVar UclVar::Socket::SO_SNDTIMEO = UclVar(NO_INIT());

UclVar UclVar::Signal::_SIGINT  = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGTERM = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGHUP  = UclVar(NO_INIT());

UclVar UclVar::Poll::POLLIN   = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLPRI  = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLOUT  = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLERR  = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLHUP  = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLNVAL = UclVar(NO_INIT());

UclVar UclVar::WsContext::PORT_NO_LISTEN = UclVar(NO_INIT());

UclVar UclVar::WsConn::WRITE_TEXT                                  = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_BINARY                                = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_CONTINUATION                          = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_HTTP                                  = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_CLOSE                                 = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_ESTABLISHED                              = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_CONNECTION_ERROR                  = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_FILTER_PRE_ESTABLISH              = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_ESTABLISHED                       = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLOSED                                   = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_RECEIVE                                  = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_RECEIVE                           = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_RECEIVE_PONG                      = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_WRITEABLE                         = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_SERVER_WRITEABLE                         = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_HTTP                                     = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_HTTP_FILE_COMPLETION                     = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_FILTER_NETWORK_CONNECTION                = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_FILTER_PROTOCOL_CONNECTION               = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS   = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS   = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_APPEND_HANDSHAKE_HEADER           = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CONFIRM_EXTENSION_OKAY                   = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED       = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_PROTOCOL_INIT                            = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_PROTOCOL_DESTROY                         = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_ADD_POLL_FD                              = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_DEL_POLL_FD                              = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CHANGE_MODE_POLL_FD                      = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_NO_PENDING                          = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_PROXY_RESPONSE             = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_CONNECT_RESPONSE           = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_ESTABLISH_WITH_SERVER               = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_SERVER_RESPONSE            = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_PING                       = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_CLOSE_ACK                           = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_SENT_CLIENT_HANDSHAKE               = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_SSL_ACCEPT                          = UclVar(NO_INIT());

UclVar UclVar::JitContext::TYPE_I8  = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_U8  = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_I16 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_U16 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_I32 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_U32 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_I64 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_U64 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_F32 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_F64 = UclVar(NO_INIT());

// - methods of class UclVar -

void UclVar::Initialize(script_parser_s &a_parser,bool *a_modules)
{/*{{{*/
  string_rb_tree_s &msn = a_parser.method_symbol_names;
  string_rb_tree_s &vsn = a_parser.variable_symbol_names;

  // - retrieve class indexes -
#define UCLVAR_RETRIEVE_CLASS_IDX(ID,NAME) \
  c_bi_class_ ## ID = a_parser.resolve_class_idx_by_name(NAME,c_idx_not_exist);\
  cassert(c_bi_class_ ## ID != c_idx_not_exist);

  UCLVAR_RETRIEVE_CLASS_IDX(node_callback,"NodeCallback");

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(sys,"Sys");

    UCLVAR_RETRIEVE_CLASS_IDX(pipe,"Pipe");
    UCLVAR_RETRIEVE_CLASS_IDX(file,"File");
  
#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_CLASS_IDX(socket_addr,"SocketAddr");
    UCLVAR_RETRIEVE_CLASS_IDX(socket,"Socket");
#endif

#ifdef ENABLE_CLASS_REGEX
    UCLVAR_RETRIEVE_CLASS_IDX(regex,"Regex");
#endif

    UCLVAR_RETRIEVE_CLASS_IDX(signal,"Signal");
    UCLVAR_RETRIEVE_CLASS_IDX(poll,"Poll");
    UCLVAR_RETRIEVE_CLASS_IDX(timer,"Timer");
    UCLVAR_RETRIEVE_CLASS_IDX(clock,"Clock");
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(stack,"Stack");
    UCLVAR_RETRIEVE_CLASS_IDX(queue,"Queue");
    UCLVAR_RETRIEVE_CLASS_IDX(set,"Set");
    UCLVAR_RETRIEVE_CLASS_IDX(list,"List");
    UCLVAR_RETRIEVE_CLASS_IDX(tree,"Tree");
    UCLVAR_RETRIEVE_CLASS_IDX(dict,"Dict");
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(json,"Json");
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(ws_context,"WsContext");
    UCLVAR_RETRIEVE_CLASS_IDX(ws_conn,"WsConn");
    UCLVAR_RETRIEVE_CLASS_IDX(ws_client,"WsClient");
    UCLVAR_RETRIEVE_CLASS_IDX(ws_base64,"WsBase64");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(jit_context,"JitContext");
    UCLVAR_RETRIEVE_CLASS_IDX(jit_function,"JitFunction");
  }

  // - retrieve method name indexes -
  c_bi_mni_binary_equal              = c_built_in_method_idxs[c_operator_binary_equal];
  c_bi_mni_binary_plus_equal         = c_built_in_method_idxs[c_operator_binary_plus_equal];
  c_bi_mni_binary_minus_equal        = c_built_in_method_idxs[c_operator_binary_minus_equal];
  c_bi_mni_binary_asterisk_equal     = c_built_in_method_idxs[c_operator_binary_asterisk_equal];
  c_bi_mni_binary_slash_equal        = c_built_in_method_idxs[c_operator_binary_slash_equal];
  c_bi_mni_binary_percent_equal      = c_built_in_method_idxs[c_operator_binary_percent_equal];
  c_bi_mni_binary_double_ls_br_equal = c_built_in_method_idxs[c_operator_binary_double_ls_br_equal];
  c_bi_mni_binary_double_rs_br_equal = c_built_in_method_idxs[c_operator_binary_double_rs_br_equal];
  c_bi_mni_binary_ampersand_equal    = c_built_in_method_idxs[c_operator_binary_ampersand_equal];
  c_bi_mni_binary_pipe_equal         = c_built_in_method_idxs[c_operator_binary_pipe_equal];
  c_bi_mni_binary_circumflex_equal   = c_built_in_method_idxs[c_operator_binary_circumflex_equal];
  c_bi_mni_binary_double_ampersand   = c_built_in_method_idxs[c_operator_binary_double_ampersand];
  c_bi_mni_binary_double_pipe        = c_built_in_method_idxs[c_operator_binary_double_pipe];
  c_bi_mni_binary_ampersand          = c_built_in_method_idxs[c_operator_binary_ampersand];
  c_bi_mni_binary_pipe               = c_built_in_method_idxs[c_operator_binary_pipe];
  c_bi_mni_binary_circumflex         = c_built_in_method_idxs[c_operator_binary_circumflex];
  c_bi_mni_binary_double_equal       = c_built_in_method_idxs[c_operator_binary_double_equal];
  c_bi_mni_binary_exclamation_equal  = c_built_in_method_idxs[c_operator_binary_exclamation_equal];
  c_bi_mni_binary_rs_br              = c_built_in_method_idxs[c_operator_binary_rs_br];
  c_bi_mni_binary_ls_br              = c_built_in_method_idxs[c_operator_binary_ls_br];
  c_bi_mni_binary_rs_br_equal        = c_built_in_method_idxs[c_operator_binary_rs_br_equal];
  c_bi_mni_binary_ls_br_equal        = c_built_in_method_idxs[c_operator_binary_ls_br_equal];
  c_bi_mni_binary_double_rs_br       = c_built_in_method_idxs[c_operator_binary_double_rs_br];
  c_bi_mni_binary_double_ls_br       = c_built_in_method_idxs[c_operator_binary_double_ls_br];
  c_bi_mni_binary_plus               = c_built_in_method_idxs[c_operator_binary_plus];
  c_bi_mni_binary_minus              = c_built_in_method_idxs[c_operator_binary_minus];
  c_bi_mni_binary_asterisk           = c_built_in_method_idxs[c_operator_binary_asterisk];
  c_bi_mni_binary_slash              = c_built_in_method_idxs[c_operator_binary_slash];
  c_bi_mni_binary_percent            = c_built_in_method_idxs[c_operator_binary_percent];
  c_bi_mni_unary_post_double_plus    = c_built_in_method_idxs[c_operator_unary_post_double_plus];
  c_bi_mni_unary_post_double_minus   = c_built_in_method_idxs[c_operator_unary_post_double_minus];
  c_bi_mni_unary_pre_double_plus     = c_built_in_method_idxs[c_operator_unary_pre_double_plus];
  c_bi_mni_unary_pre_double_minus    = c_built_in_method_idxs[c_operator_unary_pre_double_minus];
  c_bi_mni_unary_pre_plus            = c_built_in_method_idxs[c_operator_unary_pre_plus];
  c_bi_mni_unary_pre_minus           = c_built_in_method_idxs[c_operator_unary_pre_minus];
  c_bi_mni_unary_pre_exclamation     = c_built_in_method_idxs[c_operator_unary_pre_exclamation];
  c_bi_mni_unary_pre_tilde           = c_built_in_method_idxs[c_operator_unary_pre_tilde];
  c_bi_mni_binary_le_br_re_br        = c_built_in_method_idxs[c_operator_binary_le_br_re_br];
  c_bi_mni_compare_1                 = c_built_in_method_idxs[c_built_in_method_compare_1];
  c_bi_mni_item_1                    = c_built_in_method_idxs[c_built_in_method_item_1];
  c_bi_mni_first_idx_0               = c_built_in_method_idxs[c_built_in_method_first_idx_0];
  c_bi_mni_last_idx_0                = c_built_in_method_idxs[c_built_in_method_last_idx_0];
  c_bi_mni_next_idx_1                = c_built_in_method_idxs[c_built_in_method_next_idx_1];
  c_bi_mni_prev_idx_1                = c_built_in_method_idxs[c_built_in_method_prev_idx_1];
  c_bi_mni_next_item_0               = c_built_in_method_idxs[c_built_in_method_next_item_0];
  c_bi_mni_length_0                  = c_built_in_method_idxs[c_built_in_method_length_0];
  c_bi_mni_to_string_0               = c_built_in_method_idxs[c_built_in_method_to_string_0];
  c_bi_mni_print_0                   = c_built_in_method_idxs[c_built_in_method_print_0];

#define UCLVAR_RETRIEVE_METHOD_NAME_IDX(ID,NAME) \
  c_bi_mni_ ## ID = msn.get_idx_char_ptr(strlen(NAME),NAME);\
  cassert(c_bi_mni_ ## ID != c_idx_not_exist);

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Blank_0,"Blank#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Char_0,"Char#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Char_1,"Char#1");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Integer_0,"Integer#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Integer_1,"Integer#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Integer_2,"Integer#2");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Float_0,"Float#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Float_1,"Float#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(sin_0,"sin#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(cos_0,"cos#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(tan_0,"tan#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(asin_0,"asin#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(acos_0,"acos#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(atan_0,"atan#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(exp_0,"exp#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(log_0,"log#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(pow_1,"pow#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(sqrt_0,"sqrt#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(cbrt_0,"cbrt#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(hypot_1,"hypot#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(isnan_0,"isnan#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(String_0,"String#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(String_1,"String#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(split_1,"split#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(join_1,"join#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(head_1,"head#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(tail_1,"tail#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(range_2,"range#2");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_idx_1,"get_idx#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_idxs_1,"get_idxs#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(replace_2,"replace#2");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Array_0,"Array#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Array_1,"Array#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(clear_0,"clear#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(resize_1,"resize#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(push_1,"push#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(pop_0,"pop#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(last_0,"last#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(fill_1,"fill#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(to_string_1,"to_string#1");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Error_0,"Error#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Exception_0,"Exception#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Exception_1,"Exception#1");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(throw_0,"throw#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_type_0,"get_type#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_value_0,"get_value#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_file_name_0,"get_file_name#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_line_0,"get_line#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(error_print_0,"error_print#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Type_0,"Type#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Type_1,"Type#1");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Mutex_0,"Mutex#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(lock_0,"lock#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(try_lock_0,"try_lock#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(unlock_0,"unlock#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(join_0,"join#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(try_join_0,"try_join#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(detach_0,"detach#0");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(yield_0,"yield#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(Delegate_3,"Delegate#3");
  UCLVAR_RETRIEVE_METHOD_NAME_IDX(call_1,"call#1");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(size_0,"size#0");

  UCLVAR_RETRIEVE_METHOD_NAME_IDX(NodeCallback_2,"NodeCallback#2");

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(sleep_1,"sleep#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(srand_1,"srand#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(rand_0,"rand#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(getpid_0,"getpid#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(getuid_0,"getuid#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(getgid_0,"getgid#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(system_1,"system#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(exit_1,"exit#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(open_2,"open#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(popen_2,"popen#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(mkdir_1,"mkdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(rmdir_1,"rmdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(chdir_1,"chdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(listdir_1,"listdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(mkfifo_1,"mkfifo#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(remove_1,"remove#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(rename_2,"rename#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(getcwd_0,"getcwd#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(setenv_2,"setenv#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(getenv_1,"getenv#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(is_file_1,"is_file#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(is_dir_1,"is_dir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(size_1,"size#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(time_0,"time#0");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Pipe_0,"Pipe#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Pipe_2,"Pipe#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(close_0,"close#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(write_1,"write#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(flush_0,"flush#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(read_0,"read#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(readln_0,"readln#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(read_1,"read#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_fd_0,"get_fd#0");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(File_0,"File#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(File_2,"File#2");

#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(SocketAddr_2,"SocketAddr#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(name_0,"name#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(port_0,"port#0");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Socket_0,"Socket#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Socket_2,"Socket#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(listen_2,"listen#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(accept_0,"accept#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(accept_nonblock_0,"accept_nonblock#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(connect_1,"connect#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(bind_1,"bind#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(sendto_2,"sendto#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(recvfrom_0,"recvfrom#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(set_timeout_2,"set_timeout#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(read_nonblock_0,"read_nonblock#0");
#endif

#ifdef ENABLE_CLASS_REGEX
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Regex_0,"Regex#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Regex_1,"Regex#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(match_1,"match#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(match_2,"match#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(match_from_2,"match_from#2");
#endif

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(bind_2,"bind#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(unbind_1,"unbind#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(send_2,"send#2");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Poll_1,"Poll#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(ready_1,"ready#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(poll_1,"poll#1");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Timer_0,"Timer#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(schedule_3,"schedule#3");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(process_0,"process#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(remain_0,"remain#0");
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Stack_0,"Stack#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Stack_1,"Stack#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(items_0,"items#0");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Queue_0,"Queue#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Queue_1,"Queue#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(insert_1,"insert#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(next_0,"next#0");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Set_0,"Set#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Set_1,"Set#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(remove_1,"remove#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(contain_1,"contain#1");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(List_0,"List#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(List_1,"List#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(append_1,"append#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(prepend_1,"prepend#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(insert_after_2,"insert_after#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(insert_before_2,"insert_before#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(has_idx_1,"has_idx#1");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Tree_0,"Tree#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Tree_1,"Tree#1");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Dict_0,"Dict#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(Dict_1,"Dict#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(keys_0,"keys#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(has_key_1,"has_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(remove_key_1,"remove_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(first_key_0,"first_key#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(next_key_1,"next_key#1");
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(create_1,"create#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(create_nice_2,"create_nice#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(parse_1,"parse#1");
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(WsContext_2,"WsContext#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(user_data_0,"user_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(client_4,"client#4");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(get_fds_0,"get_fds#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(process_1,"process#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(protocol_idx_1,"protocol_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(callback_on_writable_1,"callback_on_writable#1");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(reason_0,"reason#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(received_data_0,"received_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(ctx_user_data_0,"ctx_user_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(protocol_name_0,"protocol_name#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(callback_on_writable_0,"callback_on_writable#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(set_timeout_2,"set_timeout#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(write_1,"write#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(write_2,"write#2");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(connected_0,"connected#0");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(encode_1,"encode#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(decode_1,"decode#1");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(JitContext_0,"JitContext#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(create_fun_1,"create_fun#1");

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(signature_0,"signature#0");
  }

  // - retrieve variable name indexes -
#define UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ID,NAME) \
  c_bi_vni_ ## ID = vsn.get_idx_char_ptr(strlen(NAME),NAME);\
  cassert(c_bi_vni_ ## ID != c_idx_not_exist);

  UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ERROR_INVALID,"ERROR_INVALID");
  UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ERROR_DEADLOCK,"ERROR_DEADLOCK");
  UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ERROR_BUSY,"ERROR_BUSY");
  UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ERROR_PERMISSION,"ERROR_PERMISSION");

  UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ERROR_AGAIN,"ERROR_AGAIN");
  UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ERROR_SEARCH,"ERROR_SEARCH");

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(NAME,"NAME");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(SEP,"SEP");

    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(stdin,"stdin");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(stdout,"stdout");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(stderr,"stderr");

    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(AF_UNIX,"AF_UNIX");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(AF_FILE,"AF_FILE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(AF_INET,"AF_INET");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(SOCK_STREAM,"SOCK_STREAM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(SOCK_DGRAM,"SOCK_DGRAM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(SOCK_RAW,"SOCK_RAW");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(SO_RCVTIMEO,"SO_RCVTIMEO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(SO_SNDTIMEO,"SO_SNDTIMEO");

    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(_SIGINT,"SIGINT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(_SIGTERM,"SIGTERM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(_SIGHUP,"SIGHUP");

    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(POLLIN,"POLLIN");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(POLLPRI,"POLLPRI");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(POLLOUT,"POLLOUT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(POLLERR,"POLLERR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(POLLHUP,"POLLHUP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(POLLNVAL,"POLLNVAL");
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(PORT_NO_LISTEN,"PORT_NO_LISTEN");

    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(WRITE_TEXT,"WRITE_TEXT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(WRITE_BINARY,"WRITE_BINARY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(WRITE_CONTINUATION,"WRITE_CONTINUATION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(WRITE_HTTP,"WRITE_HTTP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(WRITE_CLOSE,"WRITE_CLOSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_ESTABLISHED,"CB_ESTABLISHED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_CONNECTION_ERROR,"CB_CLIENT_CONNECTION_ERROR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_FILTER_PRE_ESTABLISH,"CB_CLIENT_FILTER_PRE_ESTABLISH");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_ESTABLISHED,"CB_CLIENT_ESTABLISHED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLOSED,"CB_CLOSED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_RECEIVE,"CB_RECEIVE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_RECEIVE,"CB_CLIENT_RECEIVE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_RECEIVE_PONG,"CB_CLIENT_RECEIVE_PONG");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_WRITEABLE,"CB_CLIENT_WRITEABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_SERVER_WRITEABLE,"CB_SERVER_WRITEABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_HTTP,"CB_HTTP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_HTTP_FILE_COMPLETION,"CB_HTTP_FILE_COMPLETION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_FILTER_NETWORK_CONNECTION,"CB_FILTER_NETWORK_CONNECTION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_FILTER_PROTOCOL_CONNECTION,"CB_FILTER_PROTOCOL_CONNECTION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS,"CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS,"CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION,"CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_APPEND_HANDSHAKE_HEADER,"CB_CLIENT_APPEND_HANDSHAKE_HEADER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CONFIRM_EXTENSION_OKAY,"CB_CONFIRM_EXTENSION_OKAY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED,"CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_PROTOCOL_INIT,"CB_PROTOCOL_INIT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_PROTOCOL_DESTROY,"CB_PROTOCOL_DESTROY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_ADD_POLL_FD,"CB_ADD_POLL_FD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_DEL_POLL_FD,"CB_DEL_POLL_FD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(CB_CHANGE_MODE_POLL_FD,"CB_CHANGE_MODE_POLL_FD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_NO_PENDING,"TIMEOUT_NO_PENDING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_AWAITING_PROXY_RESPONSE,"TIMEOUT_AWAITING_PROXY_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_AWAITING_CONNECT_RESPONSE,"TIMEOUT_AWAITING_CONNECT_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_ESTABLISH_WITH_SERVER,"TIMEOUT_ESTABLISH_WITH_SERVER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_AWAITING_SERVER_RESPONSE,"TIMEOUT_AWAITING_SERVER_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_AWAITING_PING,"TIMEOUT_AWAITING_PING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_CLOSE_ACK,"TIMEOUT_CLOSE_ACK");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE,"TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_SENT_CLIENT_HANDSHAKE,"TIMEOUT_SENT_CLIENT_HANDSHAKE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TIMEOUT_SSL_ACCEPT,"TIMEOUT_SSL_ACCEPT");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_I8,"TYPE_I8");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_U8,"TYPE_U8");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_I16,"TYPE_I16");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_U16,"TYPE_U16");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_I32,"TYPE_I32");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_U32,"TYPE_U32");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_I64,"TYPE_I64");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_U64,"TYPE_U64");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_F32,"TYPE_F32");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(TYPE_F64,"TYPE_F64");
  }

  // - retrieve static method indexes -
#define UCLVAR_RETRIEVE_STATIC_METHOD_IDX(CLASS_NAME,CLASS_REC,NAME_IDX) \
  CLASS_NAME::c_bi_mi_ ## NAME_IDX = CLASS_REC.mnri_map[c_bi_mni_ ## NAME_IDX];\
  cassert(CLASS_NAME::c_bi_mi_ ## NAME_IDX != c_idx_not_exist);

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    class_record_s &class_sys = a_parser.class_records[c_bi_class_sys];
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,sleep_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,srand_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,rand_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,getpid_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,getuid_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,getgid_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,system_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,exit_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,open_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,popen_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,mkdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,rmdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,chdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,listdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,mkfifo_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,remove_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,rename_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,getcwd_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,setenv_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,getenv_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,is_file_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,is_dir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,size_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,class_sys,time_0);

    class_record_s &class_signal = a_parser.class_records[c_bi_class_signal];
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,class_signal,bind_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,class_signal,unbind_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,class_signal,send_2);
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    class_record_s &class_json = a_parser.class_records[c_bi_class_json];
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,class_json,create_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,class_json,create_nice_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,class_json,parse_1);
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    class_record_s &class_ws_base64 = a_parser.class_records[c_bi_class_ws_base64];
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsBase64,class_ws_base64,encode_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsBase64,class_ws_base64,decode_1);
  }

}/*}}}*/

void UclVar::Initialize(interpreter_s &a_interpreter,bool *a_modules)
{/*{{{*/
  
  // - initialize static constants array -
  static_const_array.init();

  // - retrieve integer static constants -
#define UCLVAR_RETRIEVE_STATIC_CONST(CLASS_NAME,CLASS_REC,VAR_NAME) \
{/*{{{*/\
  ri_ep_s &e_ri_ep = CLASS_REC.vn_ri_ep_map.map_name(c_bi_vni_ ## VAR_NAME);\
  cassert(e_ri_ep.record_idx != c_idx_not_exist);\
  variable_record_s &vr = a_interpreter.variable_records[e_ri_ep.record_idx];\
  cassert((vr.modifiers & c_modifier_static) &&\
          (vr.modifiers & c_modifier_static_const));\
  location_s *tmp_location = a_interpreter.const_locations.data + e_ri_ep.element_position;\
  tmp_location->v_reference_cnt.atomic_inc();\
  CLASS_NAME::VAR_NAME.location_ptr = tmp_location;\
  static_const_array.push(&CLASS_NAME::VAR_NAME);\
}/*}}}*/

  class_record_s &class_mutex = a_interpreter.class_records[c_bi_class_mutex];
  UCLVAR_RETRIEVE_STATIC_CONST(Mutex,class_mutex,ERROR_INVALID);
  UCLVAR_RETRIEVE_STATIC_CONST(Mutex,class_mutex,ERROR_DEADLOCK);
  UCLVAR_RETRIEVE_STATIC_CONST(Mutex,class_mutex,ERROR_BUSY);
  UCLVAR_RETRIEVE_STATIC_CONST(Mutex,class_mutex,ERROR_PERMISSION);

  class_record_s &class_thread = a_interpreter.class_records[c_bi_class_thread];
  UCLVAR_RETRIEVE_STATIC_CONST(Thread,class_thread,ERROR_AGAIN);
  UCLVAR_RETRIEVE_STATIC_CONST(Thread,class_thread,ERROR_SEARCH);
  UCLVAR_RETRIEVE_STATIC_CONST(Thread,class_thread,ERROR_INVALID);
  UCLVAR_RETRIEVE_STATIC_CONST(Thread,class_thread,ERROR_DEADLOCK);
  UCLVAR_RETRIEVE_STATIC_CONST(Thread,class_thread,ERROR_BUSY);

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    class_record_s &class_sys = a_interpreter.class_records[c_bi_class_sys];
    UCLVAR_RETRIEVE_STATIC_CONST(Sys,class_sys,NAME);
    UCLVAR_RETRIEVE_STATIC_CONST(Sys,class_sys,SEP);

    class_record_s &class_file = a_interpreter.class_records[c_bi_class_file];
    UCLVAR_RETRIEVE_STATIC_CONST(File,class_file,stdin);
    UCLVAR_RETRIEVE_STATIC_CONST(File,class_file,stdout);
    UCLVAR_RETRIEVE_STATIC_CONST(File,class_file,stderr);

    class_record_s &class_socket = a_interpreter.class_records[c_bi_class_socket];
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,AF_UNIX);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,AF_FILE);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,AF_INET);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,SOCK_STREAM);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,SOCK_DGRAM);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,SOCK_RAW);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,SO_RCVTIMEO);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,class_socket,SO_SNDTIMEO);

    class_record_s &class_signal = a_interpreter.class_records[c_bi_class_signal];
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,class_signal,_SIGINT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,class_signal,_SIGTERM);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,class_signal,_SIGHUP);

    class_record_s &class_poll = a_interpreter.class_records[c_bi_class_poll];
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,class_poll,POLLIN);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,class_poll,POLLPRI);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,class_poll,POLLOUT);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,class_poll,POLLERR);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,class_poll,POLLHUP);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,class_poll,POLLNVAL);
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    class_record_s &class_ws_context = a_interpreter.class_records[c_bi_class_ws_context];
    UCLVAR_RETRIEVE_STATIC_CONST(WsContext,class_ws_context,PORT_NO_LISTEN);

    class_record_s &class_ws_conn = a_interpreter.class_records[c_bi_class_ws_conn];
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,WRITE_TEXT);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,WRITE_BINARY);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,WRITE_CONTINUATION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,WRITE_HTTP);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,WRITE_CLOSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_ESTABLISHED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_CONNECTION_ERROR);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_FILTER_PRE_ESTABLISH);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_ESTABLISHED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLOSED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_RECEIVE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_RECEIVE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_RECEIVE_PONG);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_WRITEABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_SERVER_WRITEABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_HTTP);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_HTTP_FILE_COMPLETION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_FILTER_NETWORK_CONNECTION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_FILTER_PROTOCOL_CONNECTION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_APPEND_HANDSHAKE_HEADER);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CONFIRM_EXTENSION_OKAY);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_PROTOCOL_INIT);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_PROTOCOL_DESTROY);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_ADD_POLL_FD);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_DEL_POLL_FD);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,CB_CHANGE_MODE_POLL_FD);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_NO_PENDING);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_AWAITING_PROXY_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_AWAITING_CONNECT_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_ESTABLISH_WITH_SERVER);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_AWAITING_SERVER_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_AWAITING_PING);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_CLOSE_ACK);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_SENT_CLIENT_HANDSHAKE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,class_ws_conn,TIMEOUT_SSL_ACCEPT);
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    class_record_s &class_jit_context = a_interpreter.class_records[c_bi_class_jit_context];
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_I8);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_U8);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_I16);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_U16);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_I32);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_U32);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_I64);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_U64);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_F32);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,class_jit_context,TYPE_F64);
  }
}/*}}}*/

void UclVar::InitThread(interpreter_thread_s &a_it)
{/*{{{*/
  it_ptr = &a_it;
}/*}}}*/

void UclVar::Release(interpreter_s &a_interpreter)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)a_interpreter.main_thread_ptr);

  // - release static constants -
  if (static_const_array.used > 0)
  {
    pointer *uv_ptr = static_const_array.data;
    pointer *uv_ptr_end = uv_ptr + static_const_array.used;
    do {
      location_s **tmp_location_ptr = &(((UclVar *)*uv_ptr)->location_ptr);

      it.release_location_ptr(*tmp_location_ptr);
      *tmp_location_ptr = NULL;
    } while(++uv_ptr < uv_ptr_end);
  }

  // - release static const array -
  static_const_array.clear();
}/*}}}*/

#define UCLVAR_CALL(PARAM_CODE,CODE_CODE) \
{/*{{{*/\
  unsigned new_stack_base = it_ptr->data_stack.used;\
\
  ((location_s *)it_ptr->blank_location)->v_reference_cnt.atomic_inc();\
  it_ptr->data_stack.push(it_ptr->blank_location);\
\
  location_ptr->v_reference_cnt.atomic_inc();\
  it_ptr->data_stack.push((pointer)location_ptr);\
\
  PARAM_CODE;\
\
  /* - create dummy code - */\
  CODE_CODE;\
  uli *tmp_code_ptr = tmp_code;\
  unsigned return_value;\
\
  inst_params_s params = {it_ptr,&tmp_code_ptr,new_stack_base,&return_value};\
\
  /* - ERROR - */\
  if (inst_call(&params) == c_run_return_code_EXCEPTION)\
  {\
    it_ptr->release_stack_from(new_stack_base);\
\
    throw std::string("Exception");\
  }\
\
  /* - create return ucl variable - */\
  UclVar ret_value((location_s **)&it_ptr->data_stack[new_stack_base]);\
\
  it_ptr->release_stack_from(new_stack_base);\
\
  return ret_value;\
}/*}}}*/

UclVar UclVar::__call_0(unsigned a_method_idx)
{/*{{{*/
  UCLVAR_CALL(
  ,
    uli tmp_code[8] = {
      i_call MP_COMMA
      1 MP_COMMA
      a_method_idx MP_COMMA
      c_idx_not_exist MP_COMMA
      c_idx_not_exist MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      1
    };
  );
}/*}}}*/

UclVar UclVar::__call_1(unsigned a_method_idx,UclVar a_op)
{/*{{{*/
  UCLVAR_CALL(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);
  ,
    uli tmp_code[9] = {
      i_call MP_COMMA
      2 MP_COMMA
      a_method_idx MP_COMMA
      c_idx_not_exist MP_COMMA
      c_idx_not_exist MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      1 MP_COMMA
      2
    };
  );
}/*}}}*/

UclVar UclVar::__call_2(unsigned a_method_idx,UclVar a_op,UclVar a_op_1)
{/*{{{*/
  UCLVAR_CALL(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);

    a_op_1.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_1.location_ptr);
  ,
    uli tmp_code[10] = {
      i_call MP_COMMA
      3 MP_COMMA
      a_method_idx MP_COMMA
      c_idx_not_exist MP_COMMA
      c_idx_not_exist MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      1 MP_COMMA
      2 MP_COMMA
      3
    };
  );
}/*}}}*/

UclVar UclVar::__call_3(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2)
{/*{{{*/
  UCLVAR_CALL(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);

    a_op_1.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_1.location_ptr);

    a_op_2.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_2.location_ptr);
  ,
    uli tmp_code[11] = {
      i_call MP_COMMA
      4 MP_COMMA
      a_method_idx MP_COMMA
      c_idx_not_exist MP_COMMA
      c_idx_not_exist MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      1 MP_COMMA
      2 MP_COMMA
      3 MP_COMMA
      4
    };
  );
}/*}}}*/

UclVar UclVar::__call_4(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3)
{/*{{{*/
  UCLVAR_CALL(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);

    a_op_1.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_1.location_ptr);

    a_op_2.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_2.location_ptr);

    a_op_3.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_3.location_ptr);
  ,
    uli tmp_code[12] = {
      i_call MP_COMMA
      5 MP_COMMA
      a_method_idx MP_COMMA
      c_idx_not_exist MP_COMMA
      c_idx_not_exist MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      1 MP_COMMA
      2 MP_COMMA
      3 MP_COMMA
      4 MP_COMMA
      5
    };
  );
}/*}}}*/

#define UCLVAR_STATIC_CALL(PARAM_CODE,CODE_CODE) \
{/*{{{*/\
  unsigned new_stack_base = it_ptr->data_stack.used;\
\
  ((location_s *)it_ptr->blank_location)->v_reference_cnt.atomic_inc();\
  it_ptr->data_stack.push(it_ptr->blank_location);\
\
  PARAM_CODE;\
\
  /* - create dummy code - */\
  CODE_CODE;\
  uli *tmp_code_ptr = tmp_code;\
  unsigned return_value;\
\
  inst_params_s params = {it_ptr,&tmp_code_ptr,new_stack_base,&return_value};\
\
  /* - ERROR - */\
  if (inst_static_call(&params) == c_run_return_code_EXCEPTION)\
  {\
    it_ptr->release_stack_from(new_stack_base);\
\
    throw std::string("Exception");\
  }\
\
  /* - create return ucl variable - */\
  UclVar ret_value((location_s **)&it_ptr->data_stack[new_stack_base]);\
\
  it_ptr->release_stack_from(new_stack_base);\
\
  return ret_value;\
}/*}}}*/

UclVar UclVar::__static_call_0(unsigned a_method_idx)
{/*{{{*/
  UCLVAR_STATIC_CALL(
  ,
    uli tmp_code[5] = {
      i_static_call MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      a_method_idx
    };
  );
}/*}}}*/

UclVar UclVar::__static_call_1(unsigned a_method_idx,UclVar a_op)
{/*{{{*/
  UCLVAR_STATIC_CALL(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);
  ,
    uli tmp_code[6] = {
      i_static_call MP_COMMA
      1 MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      a_method_idx MP_COMMA
      1
    };
  );
}/*}}}*/

UclVar UclVar::__static_call_2(unsigned a_method_idx,UclVar a_op,UclVar a_op_1)
{/*{{{*/
  UCLVAR_STATIC_CALL(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);

    a_op_1.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_1.location_ptr);
  ,
    uli tmp_code[7] = {
      i_static_call MP_COMMA
      2 MP_COMMA
      0 MP_COMMA
      0 MP_COMMA
      a_method_idx MP_COMMA
      1 MP_COMMA
      2
    };
  );
}/*}}}*/

#define UCLVAR_NEW_OBJECT(PARAM_CODE,CODE_CODE) \
{/*{{{*/\
  unsigned new_stack_base = it_ptr->data_stack.used;\
\
  ((location_s *)it_ptr->blank_location)->v_reference_cnt.atomic_inc();\
  it_ptr->data_stack.push(it_ptr->blank_location);\
\
  PARAM_CODE;\
\
  /* - create dummy code - */\
  CODE_CODE;\
  uli *tmp_code_ptr = tmp_code;\
  unsigned return_value;\
\
  inst_params_s params = {it_ptr,&tmp_code_ptr,new_stack_base,&return_value};\
\
  /* - ERROR - */\
  if (inst_new_object(&params) == c_run_return_code_EXCEPTION)\
  {\
    it_ptr->release_stack_from(new_stack_base);\
\
    throw std::string("Exception");\
  }\
\
  /* - create return ucl variable - */\
  UclVar ret_value((location_s **)&it_ptr->data_stack[new_stack_base]);\
\
  it_ptr->release_stack_from(new_stack_base);\
\
  return ret_value;\
}/*}}}*/

UclVar UclVar::__new_object_0(unsigned a_class_idx,unsigned a_name_idx)
{/*{{{*/
  UCLVAR_NEW_OBJECT(
  ,
    uli tmp_code[6] = {
      i_new_object MP_COMMA
      0 MP_COMMA
      a_class_idx MP_COMMA
      0 MP_COMMA
      a_name_idx MP_COMMA
      0
    }
  );
}/*}}}*/

UclVar UclVar::__new_object_1(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op)
{/*{{{*/
  UCLVAR_NEW_OBJECT(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);
  ,
    uli tmp_code[7] = {
      i_new_object MP_COMMA
      1 MP_COMMA
      a_class_idx MP_COMMA
      0 MP_COMMA
      a_name_idx MP_COMMA
      0 MP_COMMA
      1
    }
  );
}/*}}}*/

UclVar UclVar::__new_object_2(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1)
{/*{{{*/
  UCLVAR_NEW_OBJECT(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);

    a_op_1.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_1.location_ptr);
  ,
    uli tmp_code[8] = {
      i_new_object MP_COMMA
      2 MP_COMMA
      a_class_idx MP_COMMA
      0 MP_COMMA
      a_name_idx MP_COMMA
      0 MP_COMMA
      1 MP_COMMA
      2
    }
  );
}/*}}}*/

UclVar UclVar::__new_object_3(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2)
{/*{{{*/
  UCLVAR_NEW_OBJECT(
    a_op.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op.location_ptr);

    a_op_1.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_1.location_ptr);

    a_op_2.location_ptr->v_reference_cnt.atomic_inc();
    it_ptr->data_stack.push((pointer)a_op_2.location_ptr);
  ,
    uli tmp_code[9] = {
      i_new_object MP_COMMA
      3 MP_COMMA
      a_class_idx MP_COMMA
      0 MP_COMMA
      a_name_idx MP_COMMA
      0 MP_COMMA
      1 MP_COMMA
      2 MP_COMMA
      3
    }
  );
}/*}}}*/

