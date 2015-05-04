
@begin
include "ucl_var.h"
@end

// - static members of UclVar -

interpreter_thread_s *UclVar::it_ptr;
pointer_array_s UclVar::static_const_array;

// - built in class indexes -
unsigned UclVar::c_bi_class_Blank;
unsigned UclVar::c_bi_class_Char;
unsigned UclVar::c_bi_class_Integer;
unsigned UclVar::c_bi_class_Float;
unsigned UclVar::c_bi_class_String;
unsigned UclVar::c_bi_class_Array;
unsigned UclVar::c_bi_class_Error;
unsigned UclVar::c_bi_class_Exception;
unsigned UclVar::c_bi_class_Type;
unsigned UclVar::c_bi_class_Mutex;
unsigned UclVar::c_bi_class_Thread;
unsigned UclVar::c_bi_class_Delegate;
unsigned UclVar::c_bi_class_Buffer;
unsigned UclVar::c_bi_class_NodeCallback;
unsigned UclVar::c_bi_class_Sys;
unsigned UclVar::c_bi_class_Pipe;
unsigned UclVar::c_bi_class_File;
unsigned UclVar::c_bi_class_SocketAddr;
unsigned UclVar::c_bi_class_Socket;
unsigned UclVar::c_bi_class_Regex;
unsigned UclVar::c_bi_class_Signal;
unsigned UclVar::c_bi_class_Poll;
unsigned UclVar::c_bi_class_Timer;
unsigned UclVar::c_bi_class_Clock;
unsigned UclVar::c_bi_class_Stack;
unsigned UclVar::c_bi_class_Queue;
unsigned UclVar::c_bi_class_Set;
unsigned UclVar::c_bi_class_List;
unsigned UclVar::c_bi_class_Tree;
unsigned UclVar::c_bi_class_Dict;
unsigned UclVar::c_bi_class_Json;
unsigned UclVar::c_bi_class_WsContext;
unsigned UclVar::c_bi_class_WsConn;
unsigned UclVar::c_bi_class_WsClient;
unsigned UclVar::c_bi_class_WsBase64;
unsigned UclVar::c_bi_class_JitContext;
unsigned UclVar::c_bi_class_JitFunction;

// - built in method name indexes -
unsigned UclVar::c_bi_mni_operator_binary_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_plus_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_minus_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_asterisk_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_slash_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_percent_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_double_ls_br_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_double_rs_br_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_ampersand_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_pipe_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_circumflex_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_double_ampersand_1;
unsigned UclVar::c_bi_mni_operator_binary_double_pipe_1;
unsigned UclVar::c_bi_mni_operator_binary_ampersand_1;
unsigned UclVar::c_bi_mni_operator_binary_pipe_1;
unsigned UclVar::c_bi_mni_operator_binary_circumflex_1;
unsigned UclVar::c_bi_mni_operator_binary_double_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_exclamation_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_rs_br_1;
unsigned UclVar::c_bi_mni_operator_binary_ls_br_1;
unsigned UclVar::c_bi_mni_operator_binary_rs_br_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_ls_br_equal_1;
unsigned UclVar::c_bi_mni_operator_binary_double_rs_br_1;
unsigned UclVar::c_bi_mni_operator_binary_double_ls_br_1;
unsigned UclVar::c_bi_mni_operator_binary_plus_1;
unsigned UclVar::c_bi_mni_operator_binary_minus_1;
unsigned UclVar::c_bi_mni_operator_binary_asterisk_1;
unsigned UclVar::c_bi_mni_operator_binary_slash_1;
unsigned UclVar::c_bi_mni_operator_binary_percent_1;
unsigned UclVar::c_bi_mni_operator_unary_post_double_plus_0;
unsigned UclVar::c_bi_mni_operator_unary_post_double_minus_0;
unsigned UclVar::c_bi_mni_operator_unary_pre_double_plus_0;
unsigned UclVar::c_bi_mni_operator_unary_pre_double_minus_0;
unsigned UclVar::c_bi_mni_operator_unary_pre_plus_0;
unsigned UclVar::c_bi_mni_operator_unary_pre_minus_0;
unsigned UclVar::c_bi_mni_operator_unary_pre_exclamation_0;
unsigned UclVar::c_bi_mni_operator_unary_pre_tilde_0;
unsigned UclVar::c_bi_mni_operator_binary_le_br_re_br_1;
unsigned UclVar::c_bi_mni_Blank_0;
unsigned UclVar::c_bi_mni_compare_1;
unsigned UclVar::c_bi_mni_to_string_0;
unsigned UclVar::c_bi_mni_print_0;
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
unsigned UclVar::c_bi_mni__isnan_0;
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
unsigned UclVar::c_bi_mni_item_1;
unsigned UclVar::c_bi_mni_first_idx_0;
unsigned UclVar::c_bi_mni_next_idx_1;
unsigned UclVar::c_bi_mni_length_0;
unsigned UclVar::c_bi_mni_Array_0;
unsigned UclVar::c_bi_mni_Array_1;
unsigned UclVar::c_bi_mni_clear_0;
unsigned UclVar::c_bi_mni_resize_1;
unsigned UclVar::c_bi_mni_push_1;
unsigned UclVar::c_bi_mni_push_ref_1;
unsigned UclVar::c_bi_mni_pop_0;
unsigned UclVar::c_bi_mni_last_0;
unsigned UclVar::c_bi_mni_fill_1;
unsigned UclVar::c_bi_mni_last_idx_0;
unsigned UclVar::c_bi_mni_prev_idx_1;
unsigned UclVar::c_bi_mni_to_string_1;
unsigned UclVar::c_bi_mni_Error_0;
unsigned UclVar::c_bi_mni_Exception_0;
unsigned UclVar::c_bi_mni_Exception_1;
unsigned UclVar::c_bi_mni__throw_0;
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
unsigned UclVar::c_bi_mni_call_0;
unsigned UclVar::c_bi_mni_call_2;
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
unsigned UclVar::c_bi_mni_next_item_0;
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
unsigned UclVar::c_bi_mni_getres_1;
unsigned UclVar::c_bi_mni_gettime_1;
unsigned UclVar::c_bi_mni_settime_2;
unsigned UclVar::c_bi_mni_Stack_0;
unsigned UclVar::c_bi_mni_Stack_1;
unsigned UclVar::c_bi_mni_items_0;
unsigned UclVar::c_bi_mni_Queue_0;
unsigned UclVar::c_bi_mni_Queue_1;
unsigned UclVar::c_bi_mni_insert_1;
unsigned UclVar::c_bi_mni_insert_ref_1;
unsigned UclVar::c_bi_mni_next_0;
unsigned UclVar::c_bi_mni_Set_0;
unsigned UclVar::c_bi_mni_Set_1;
unsigned UclVar::c_bi_mni_contain_1;
unsigned UclVar::c_bi_mni_List_0;
unsigned UclVar::c_bi_mni_List_1;
unsigned UclVar::c_bi_mni_append_1;
unsigned UclVar::c_bi_mni_append_ref_1;
unsigned UclVar::c_bi_mni_prepend_1;
unsigned UclVar::c_bi_mni_prepend_ref_1;
unsigned UclVar::c_bi_mni_insert_before_2;
unsigned UclVar::c_bi_mni_insert_before_ref_2;
unsigned UclVar::c_bi_mni_insert_after_2;
unsigned UclVar::c_bi_mni_insert_after_ref_2;
unsigned UclVar::c_bi_mni_has_idx_1;
unsigned UclVar::c_bi_mni_Tree_0;
unsigned UclVar::c_bi_mni_Tree_1;
unsigned UclVar::c_bi_mni_Dict_0;
unsigned UclVar::c_bi_mni_Dict_1;
unsigned UclVar::c_bi_mni_keys_0;
unsigned UclVar::c_bi_mni_store_ref_2;
unsigned UclVar::c_bi_mni_has_key_1;
unsigned UclVar::c_bi_mni_remove_key_1;
unsigned UclVar::c_bi_mni_first_key_0;
unsigned UclVar::c_bi_mni_last_key_0;
unsigned UclVar::c_bi_mni_next_key_1;
unsigned UclVar::c_bi_mni_prev_key_1;
unsigned UclVar::c_bi_mni_lee_key_1;
unsigned UclVar::c_bi_mni_gre_key_1;
unsigned UclVar::c_bi_mni_create_1;
unsigned UclVar::c_bi_mni_create_nice_2;
unsigned UclVar::c_bi_mni_parse_1;
unsigned UclVar::c_bi_mni_WsContext_2;
unsigned UclVar::c_bi_mni_version_0;
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

// - built in variable name indexes -
unsigned UclVar::c_bi_vni_USER_EXCEPTION;
unsigned UclVar::c_bi_vni_TODO_EXCEPTION;
unsigned UclVar::c_bi_vni_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR;
unsigned UclVar::c_bi_vni_CLASS_DOES_NOT_CONTAIN_METHOD;
unsigned UclVar::c_bi_vni_CLASS_DOES_NOT_CONTAIN_VARIABLE;
unsigned UclVar::c_bi_vni_CANNOT_ACCESS_PRIVATE_METHOD;
unsigned UclVar::c_bi_vni_CANNOT_ACCESS_PRIVATE_VARIABLE;
unsigned UclVar::c_bi_vni_METHOD_CANNOT_RETURN_VALUE;
unsigned UclVar::c_bi_vni_CANNOT_TEST_TYPE_VALUE;
unsigned UclVar::c_bi_vni_CANNOT_CONVERT_TYPE_TO_INTEGER;
unsigned UclVar::c_bi_vni_CANNOT_USE_NEGATIVE_NUMBER;
unsigned UclVar::c_bi_vni_SLICE_NOT_INTEGER_ARGUMENTS;
unsigned UclVar::c_bi_vni_SLICE_START_LESS_THAN_ZERO;
unsigned UclVar::c_bi_vni_SLICE_STOP_LESS_THAN_ZERO;
unsigned UclVar::c_bi_vni_SLICE_STEP_EQUAL_TO_ZERO;
unsigned UclVar::c_bi_vni_OBJECT_OF_CLASS_IS_NOT_ITERABLE;
unsigned UclVar::c_bi_vni_UNEXPECTED_END_OF_ITERABLE;
unsigned UclVar::c_bi_vni_BUILT_IN_NOT_IMPLEMENTED_METHOD;
unsigned UclVar::c_bi_vni_METHOD_NOT_DEFINED_WITH_PARAMETERS;
unsigned UclVar::c_bi_vni_WRONG_METHOD_PARAMETER_VALUE;
unsigned UclVar::c_bi_vni_DIVISION_BY_ZERO;
unsigned UclVar::c_bi_vni_NEGATIVE_SHIFT_COUNT;
unsigned UclVar::c_bi_vni_METHOD_NOT_RETURN_INTEGER;
unsigned UclVar::c_bi_vni_METHOD_NOT_RETURN_STRING;
unsigned UclVar::c_bi_vni_METHOD_NOT_RETURN_INDEX;
unsigned UclVar::c_bi_vni_INTEGER_BASE_OUT_OF_RANGE;
unsigned UclVar::c_bi_vni_INTEGER_CONVERT_INVALID_STRING;
unsigned UclVar::c_bi_vni_FLOAT_CONVERT_INVALID_STRING;
unsigned UclVar::c_bi_vni_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS;
unsigned UclVar::c_bi_vni_STRING_FORMAT_WRONG_ARGUMENT_TYPE;
unsigned UclVar::c_bi_vni_STRING_FORMAT_ARGUMENT_FORMAT_ERROR;
unsigned UclVar::c_bi_vni_STRING_FORMAT_WRONG_FORMAT_SPECIFIER;
unsigned UclVar::c_bi_vni_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED;
unsigned UclVar::c_bi_vni_STRING_INDEX_EXCEEDS_RANGE;
unsigned UclVar::c_bi_vni_STRING_WRONG_RANGE_INDEXES;
unsigned UclVar::c_bi_vni_STRING_CONVERT_FROM_INTEGER;
unsigned UclVar::c_bi_vni_STRING_CONVERT_FROM_FLOAT;
unsigned UclVar::c_bi_vni_ARRAY_INDEX_EXCEEDS_RANGE;
unsigned UclVar::c_bi_vni_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE;
unsigned UclVar::c_bi_vni_ARRAY_NO_ELEMENTS;
unsigned UclVar::c_bi_vni_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH;
unsigned UclVar::c_bi_vni_DELEGATE_NEGATIVE_PARAMETER_COUNT;
unsigned UclVar::c_bi_vni_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD;
unsigned UclVar::c_bi_vni_DELEGATE_CALL_WRONG_PARAMETER_COUNT;
unsigned UclVar::c_bi_vni_DELEGATE_WRONG_RETURN_VALUE_TYPE;
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
unsigned UclVar::c_bi_vni__SIGQUIT;
unsigned UclVar::c_bi_vni__SIGILL;
unsigned UclVar::c_bi_vni__SIGTRAP;
unsigned UclVar::c_bi_vni__SIGABRT;
unsigned UclVar::c_bi_vni__SIGIOT;
unsigned UclVar::c_bi_vni__SIGBUS;
unsigned UclVar::c_bi_vni__SIGFPE;
unsigned UclVar::c_bi_vni__SIGKILL;
unsigned UclVar::c_bi_vni__SIGUSR1;
unsigned UclVar::c_bi_vni__SIGSEGV;
unsigned UclVar::c_bi_vni__SIGUSR2;
unsigned UclVar::c_bi_vni__SIGPIPE;
unsigned UclVar::c_bi_vni__SIGALRM;
unsigned UclVar::c_bi_vni__SIGSTKFLT;
unsigned UclVar::c_bi_vni__SIGCHLD;
unsigned UclVar::c_bi_vni__SIGCONT;
unsigned UclVar::c_bi_vni__SIGSTOP;
unsigned UclVar::c_bi_vni__SIGTSTP;
unsigned UclVar::c_bi_vni__SIGTTIN;
unsigned UclVar::c_bi_vni__SIGTTOU;
unsigned UclVar::c_bi_vni__SIGURG;
unsigned UclVar::c_bi_vni__SIGXCPU;
unsigned UclVar::c_bi_vni__SIGXFSZ;
unsigned UclVar::c_bi_vni__SIGVTALRM;
unsigned UclVar::c_bi_vni__SIGPROF;
unsigned UclVar::c_bi_vni__SIGWINCH;
unsigned UclVar::c_bi_vni__SIGIO;
unsigned UclVar::c_bi_vni__SIGPOLL;
unsigned UclVar::c_bi_vni__SIGPWR;
unsigned UclVar::c_bi_vni__SIGSYS;
unsigned UclVar::c_bi_vni__SIGUNUSED;
unsigned UclVar::c_bi_vni__SIGRTMIN;
unsigned UclVar::c_bi_vni__SIGRTMAX;
unsigned UclVar::c_bi_vni_POLLIN;
unsigned UclVar::c_bi_vni_POLLPRI;
unsigned UclVar::c_bi_vni_POLLOUT;
unsigned UclVar::c_bi_vni_POLLERR;
unsigned UclVar::c_bi_vni_POLLHUP;
unsigned UclVar::c_bi_vni_POLLNVAL;
unsigned UclVar::c_bi_vni__CLOCK_REALTIME;
unsigned UclVar::c_bi_vni__CLOCK_MONOTONIC;
unsigned UclVar::c_bi_vni__CLOCK_PROCESS_CPUTIME_ID;
unsigned UclVar::c_bi_vni__CLOCK_THREAD_CPUTIME_ID;
unsigned UclVar::c_bi_vni_PORT_NO_LISTEN;
unsigned UclVar::c_bi_vni_WRITE_TEXT;
unsigned UclVar::c_bi_vni_WRITE_BINARY;
unsigned UclVar::c_bi_vni_WRITE_CONTINUATION;
unsigned UclVar::c_bi_vni_WRITE_HTTP;
unsigned UclVar::c_bi_vni_WRITE_CLOSE;
unsigned UclVar::c_bi_vni_WRITE_PING;
unsigned UclVar::c_bi_vni_WRITE_PONG;
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

// - built in static method indexes -
unsigned UclVar::Blank::c_bi_mi_operator_binary_double_equal_1;
unsigned UclVar::Blank::c_bi_mi_operator_binary_exclamation_equal_1;
unsigned UclVar::Blank::c_bi_mi_compare_1;
unsigned UclVar::Blank::c_bi_mi_to_string_0;
unsigned UclVar::Blank::c_bi_mi_print_0;
unsigned UclVar::Exception::c_bi_mi_to_string_0;
unsigned UclVar::Exception::c_bi_mi_print_0;
unsigned UclVar::Mutex::c_bi_mi_to_string_0;
unsigned UclVar::Mutex::c_bi_mi_print_0;
unsigned UclVar::Thread::c_bi_mi_yield_0;
unsigned UclVar::Thread::c_bi_mi_to_string_0;
unsigned UclVar::Thread::c_bi_mi_print_0;
unsigned UclVar::Delegate::c_bi_mi_to_string_0;
unsigned UclVar::Delegate::c_bi_mi_print_0;
unsigned UclVar::Buffer::c_bi_mi_size_0;
unsigned UclVar::Buffer::c_bi_mi_to_string_0;
unsigned UclVar::Buffer::c_bi_mi_print_0;
unsigned UclVar::NodeCallback::c_bi_mi_to_string_0;
unsigned UclVar::NodeCallback::c_bi_mi_print_0;
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
unsigned UclVar::Sys::c_bi_mi_to_string_0;
unsigned UclVar::Sys::c_bi_mi_print_0;
unsigned UclVar::Pipe::c_bi_mi_to_string_0;
unsigned UclVar::Pipe::c_bi_mi_print_0;
unsigned UclVar::File::c_bi_mi_to_string_0;
unsigned UclVar::File::c_bi_mi_print_0;

#ifdef ENABLE_CLASS_SOCKET
unsigned UclVar::SocketAddr::c_bi_mi_to_string_0;
unsigned UclVar::SocketAddr::c_bi_mi_print_0;
unsigned UclVar::Socket::c_bi_mi_to_string_0;
unsigned UclVar::Socket::c_bi_mi_print_0;
#endif

#ifdef ENABLE_CLASS_REGEX
unsigned UclVar::Regex::c_bi_mi_to_string_0;
unsigned UclVar::Regex::c_bi_mi_print_0;
#endif

unsigned UclVar::Signal::c_bi_mi_bind_2;
unsigned UclVar::Signal::c_bi_mi_unbind_1;
unsigned UclVar::Signal::c_bi_mi_send_2;
unsigned UclVar::Signal::c_bi_mi_to_string_0;
unsigned UclVar::Signal::c_bi_mi_print_0;
unsigned UclVar::Poll::c_bi_mi_to_string_0;
unsigned UclVar::Poll::c_bi_mi_print_0;
unsigned UclVar::Timer::c_bi_mi_to_string_0;
unsigned UclVar::Timer::c_bi_mi_print_0;
unsigned UclVar::Clock::c_bi_mi_getres_1;
unsigned UclVar::Clock::c_bi_mi_gettime_1;
unsigned UclVar::Clock::c_bi_mi_settime_2;
unsigned UclVar::Clock::c_bi_mi_to_string_0;
unsigned UclVar::Clock::c_bi_mi_print_0;
unsigned UclVar::Json::c_bi_mi_create_1;
unsigned UclVar::Json::c_bi_mi_create_nice_2;
unsigned UclVar::Json::c_bi_mi_parse_1;
unsigned UclVar::Json::c_bi_mi_to_string_0;
unsigned UclVar::Json::c_bi_mi_print_0;
unsigned UclVar::WsContext::c_bi_mi_version_0;
unsigned UclVar::WsContext::c_bi_mi_to_string_0;
unsigned UclVar::WsContext::c_bi_mi_print_0;
unsigned UclVar::WsConn::c_bi_mi_to_string_0;
unsigned UclVar::WsConn::c_bi_mi_print_0;
unsigned UclVar::WsClient::c_bi_mi_to_string_0;
unsigned UclVar::WsClient::c_bi_mi_print_0;
unsigned UclVar::WsBase64::c_bi_mi_encode_1;
unsigned UclVar::WsBase64::c_bi_mi_decode_1;
unsigned UclVar::WsBase64::c_bi_mi_to_string_0;
unsigned UclVar::WsBase64::c_bi_mi_print_0;
unsigned UclVar::JitContext::c_bi_mi_to_string_0;
unsigned UclVar::JitContext::c_bi_mi_print_0;
unsigned UclVar::JitFunction::c_bi_mi_to_string_0;
unsigned UclVar::JitFunction::c_bi_mi_print_0;

// - built in variable values -
UclVar UclVar::Exception::USER_EXCEPTION = UclVar(NO_INIT());
UclVar UclVar::Exception::TODO_EXCEPTION = UclVar(NO_INIT());
UclVar UclVar::Exception::CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR = UclVar(NO_INIT());
UclVar UclVar::Exception::CLASS_DOES_NOT_CONTAIN_METHOD = UclVar(NO_INIT());
UclVar UclVar::Exception::CLASS_DOES_NOT_CONTAIN_VARIABLE = UclVar(NO_INIT());
UclVar UclVar::Exception::CANNOT_ACCESS_PRIVATE_METHOD = UclVar(NO_INIT());
UclVar UclVar::Exception::CANNOT_ACCESS_PRIVATE_VARIABLE = UclVar(NO_INIT());
UclVar UclVar::Exception::METHOD_CANNOT_RETURN_VALUE = UclVar(NO_INIT());
UclVar UclVar::Exception::CANNOT_TEST_TYPE_VALUE = UclVar(NO_INIT());
UclVar UclVar::Exception::CANNOT_CONVERT_TYPE_TO_INTEGER = UclVar(NO_INIT());
UclVar UclVar::Exception::CANNOT_USE_NEGATIVE_NUMBER = UclVar(NO_INIT());
UclVar UclVar::Exception::SLICE_NOT_INTEGER_ARGUMENTS = UclVar(NO_INIT());
UclVar UclVar::Exception::SLICE_START_LESS_THAN_ZERO = UclVar(NO_INIT());
UclVar UclVar::Exception::SLICE_STOP_LESS_THAN_ZERO = UclVar(NO_INIT());
UclVar UclVar::Exception::SLICE_STEP_EQUAL_TO_ZERO = UclVar(NO_INIT());
UclVar UclVar::Exception::OBJECT_OF_CLASS_IS_NOT_ITERABLE = UclVar(NO_INIT());
UclVar UclVar::Exception::UNEXPECTED_END_OF_ITERABLE = UclVar(NO_INIT());
UclVar UclVar::Exception::BUILT_IN_NOT_IMPLEMENTED_METHOD = UclVar(NO_INIT());
UclVar UclVar::Exception::METHOD_NOT_DEFINED_WITH_PARAMETERS = UclVar(NO_INIT());
UclVar UclVar::Exception::WRONG_METHOD_PARAMETER_VALUE = UclVar(NO_INIT());
UclVar UclVar::Exception::DIVISION_BY_ZERO = UclVar(NO_INIT());
UclVar UclVar::Exception::NEGATIVE_SHIFT_COUNT = UclVar(NO_INIT());
UclVar UclVar::Exception::METHOD_NOT_RETURN_INTEGER = UclVar(NO_INIT());
UclVar UclVar::Exception::METHOD_NOT_RETURN_STRING = UclVar(NO_INIT());
UclVar UclVar::Exception::METHOD_NOT_RETURN_INDEX = UclVar(NO_INIT());
UclVar UclVar::Exception::INTEGER_BASE_OUT_OF_RANGE = UclVar(NO_INIT());
UclVar UclVar::Exception::INTEGER_CONVERT_INVALID_STRING = UclVar(NO_INIT());
UclVar UclVar::Exception::FLOAT_CONVERT_INVALID_STRING = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_FORMAT_NOT_ENOUGH_ARGUMENTS = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_FORMAT_WRONG_ARGUMENT_TYPE = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_FORMAT_ARGUMENT_FORMAT_ERROR = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_FORMAT_WRONG_FORMAT_SPECIFIER = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_INDEX_EXCEEDS_RANGE = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_WRONG_RANGE_INDEXES = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_CONVERT_FROM_INTEGER = UclVar(NO_INIT());
UclVar UclVar::Exception::STRING_CONVERT_FROM_FLOAT = UclVar(NO_INIT());
UclVar UclVar::Exception::ARRAY_INDEX_EXCEEDS_RANGE = UclVar(NO_INIT());
UclVar UclVar::Exception::ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE = UclVar(NO_INIT());
UclVar UclVar::Exception::ARRAY_NO_ELEMENTS = UclVar(NO_INIT());
UclVar UclVar::Exception::ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH = UclVar(NO_INIT());
UclVar UclVar::Exception::DELEGATE_NEGATIVE_PARAMETER_COUNT = UclVar(NO_INIT());
UclVar UclVar::Exception::DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD = UclVar(NO_INIT());
UclVar UclVar::Exception::DELEGATE_CALL_WRONG_PARAMETER_COUNT = UclVar(NO_INIT());
UclVar UclVar::Exception::DELEGATE_WRONG_RETURN_VALUE_TYPE = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_INVALID = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_DEADLOCK = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_BUSY = UclVar(NO_INIT());
UclVar UclVar::Mutex::ERROR_PERMISSION = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_AGAIN = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_SEARCH = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_INVALID = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_DEADLOCK = UclVar(NO_INIT());
UclVar UclVar::Thread::ERROR_BUSY = UclVar(NO_INIT());
UclVar UclVar::Sys::NAME = UclVar(NO_INIT());
UclVar UclVar::Sys::SEP = UclVar(NO_INIT());
UclVar UclVar::File::stdin = UclVar(NO_INIT());
UclVar UclVar::File::stdout = UclVar(NO_INIT());
UclVar UclVar::File::stderr = UclVar(NO_INIT());

#ifdef ENABLE_CLASS_SOCKET
UclVar UclVar::Socket::AF_UNIX = UclVar(NO_INIT());
UclVar UclVar::Socket::AF_FILE = UclVar(NO_INIT());
UclVar UclVar::Socket::AF_INET = UclVar(NO_INIT());
UclVar UclVar::Socket::SOCK_STREAM = UclVar(NO_INIT());
UclVar UclVar::Socket::SOCK_DGRAM = UclVar(NO_INIT());
UclVar UclVar::Socket::SOCK_RAW = UclVar(NO_INIT());
UclVar UclVar::Socket::SO_RCVTIMEO = UclVar(NO_INIT());
UclVar UclVar::Socket::SO_SNDTIMEO = UclVar(NO_INIT());
#endif

UclVar UclVar::Signal::_SIGINT = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGTERM = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGHUP = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGQUIT = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGILL = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGTRAP = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGABRT = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGIOT = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGBUS = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGFPE = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGKILL = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGUSR1 = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGSEGV = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGUSR2 = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGPIPE = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGALRM = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGSTKFLT = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGCHLD = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGCONT = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGSTOP = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGTSTP = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGTTIN = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGTTOU = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGURG = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGXCPU = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGXFSZ = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGVTALRM = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGPROF = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGWINCH = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGIO = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGPOLL = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGPWR = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGSYS = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGUNUSED = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGRTMIN = UclVar(NO_INIT());
UclVar UclVar::Signal::_SIGRTMAX = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLIN = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLPRI = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLOUT = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLERR = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLHUP = UclVar(NO_INIT());
UclVar UclVar::Poll::POLLNVAL = UclVar(NO_INIT());
UclVar UclVar::Clock::_CLOCK_REALTIME = UclVar(NO_INIT());
UclVar UclVar::Clock::_CLOCK_MONOTONIC = UclVar(NO_INIT());
UclVar UclVar::Clock::_CLOCK_PROCESS_CPUTIME_ID = UclVar(NO_INIT());
UclVar UclVar::Clock::_CLOCK_THREAD_CPUTIME_ID = UclVar(NO_INIT());
UclVar UclVar::WsContext::PORT_NO_LISTEN = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_TEXT = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_BINARY = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_CONTINUATION = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_HTTP = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_CLOSE = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_PING = UclVar(NO_INIT());
UclVar UclVar::WsConn::WRITE_PONG = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_ESTABLISHED = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_CONNECTION_ERROR = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_FILTER_PRE_ESTABLISH = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_ESTABLISHED = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLOSED = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_RECEIVE = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_RECEIVE = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_RECEIVE_PONG = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_WRITEABLE = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_SERVER_WRITEABLE = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_HTTP = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_HTTP_FILE_COMPLETION = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_FILTER_NETWORK_CONNECTION = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_FILTER_PROTOCOL_CONNECTION = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_APPEND_HANDSHAKE_HEADER = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CONFIRM_EXTENSION_OKAY = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_PROTOCOL_INIT = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_PROTOCOL_DESTROY = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_ADD_POLL_FD = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_DEL_POLL_FD = UclVar(NO_INIT());
UclVar UclVar::WsConn::CB_CHANGE_MODE_POLL_FD = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_NO_PENDING = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_PROXY_RESPONSE = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_CONNECT_RESPONSE = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_ESTABLISH_WITH_SERVER = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_SERVER_RESPONSE = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_PING = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_CLOSE_ACK = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_SENT_CLIENT_HANDSHAKE = UclVar(NO_INIT());
UclVar UclVar::WsConn::TIMEOUT_SSL_ACCEPT = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_I8 = UclVar(NO_INIT());
UclVar UclVar::JitContext::TYPE_U8 = UclVar(NO_INIT());
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

  // - retrieve class indexes -
  /*{{{*/

#define UCLVAR_RETRIEVE_CLASS_IDX(ID,NAME) \
  ID = a_parser.resolve_class_idx_by_name(NAME,c_idx_not_exist);\
  cassert(ID != c_idx_not_exist);

  // - module base -
  if (a_modules[c_uclvar_module_base])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Blank,"Blank");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Char,"Char");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Integer,"Integer");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Float,"Float");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_String,"String");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Array,"Array");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Error,"Error");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Exception,"Exception");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Type,"Type");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Mutex,"Mutex");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Thread,"Thread");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Delegate,"Delegate");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Buffer,"Buffer");
  }

  // - module node -
  if (a_modules[c_uclvar_module_node])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_NodeCallback,"NodeCallback");
  }

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Sys,"Sys");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Pipe,"Pipe");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_File,"File");

#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_SocketAddr,"SocketAddr");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Socket,"Socket");
#endif

#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Regex,"Regex");
#endif

    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Signal,"Signal");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Poll,"Poll");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Timer,"Timer");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Clock,"Clock");
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Stack,"Stack");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Queue,"Queue");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Set,"Set");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_List,"List");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Tree,"Tree");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Dict,"Dict");
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_Json,"Json");
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_WsContext,"WsContext");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_WsConn,"WsConn");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_WsClient,"WsClient");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_WsBase64,"WsBase64");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_JitContext,"JitContext");
    UCLVAR_RETRIEVE_CLASS_IDX(c_bi_class_JitFunction,"JitFunction");
  }

  /*}}}*/

  // - retrieve method name indexes -
  /*{{{*/

#define UCLVAR_RETRIEVE_METHOD_NAME_IDX(ID,NAME) \
  ID = a_parser.method_symbol_names.get_idx_char_ptr(strlen(NAME),NAME);\
  cassert(ID != c_idx_not_exist);

  c_bi_mni_operator_binary_equal_1 = c_built_in_method_idxs[c_operator_binary_equal];
  c_bi_mni_operator_binary_plus_equal_1 = c_built_in_method_idxs[c_operator_binary_plus_equal];
  c_bi_mni_operator_binary_minus_equal_1 = c_built_in_method_idxs[c_operator_binary_minus_equal];
  c_bi_mni_operator_binary_asterisk_equal_1 = c_built_in_method_idxs[c_operator_binary_asterisk_equal];
  c_bi_mni_operator_binary_slash_equal_1 = c_built_in_method_idxs[c_operator_binary_slash_equal];
  c_bi_mni_operator_binary_percent_equal_1 = c_built_in_method_idxs[c_operator_binary_percent_equal];
  c_bi_mni_operator_binary_double_ls_br_equal_1 = c_built_in_method_idxs[c_operator_binary_double_ls_br_equal];
  c_bi_mni_operator_binary_double_rs_br_equal_1 = c_built_in_method_idxs[c_operator_binary_double_rs_br_equal];
  c_bi_mni_operator_binary_ampersand_equal_1 = c_built_in_method_idxs[c_operator_binary_ampersand_equal];
  c_bi_mni_operator_binary_pipe_equal_1 = c_built_in_method_idxs[c_operator_binary_pipe_equal];
  c_bi_mni_operator_binary_circumflex_equal_1 = c_built_in_method_idxs[c_operator_binary_circumflex_equal];
  c_bi_mni_operator_binary_double_ampersand_1 = c_built_in_method_idxs[c_operator_binary_double_ampersand];
  c_bi_mni_operator_binary_double_pipe_1 = c_built_in_method_idxs[c_operator_binary_double_pipe];
  c_bi_mni_operator_binary_ampersand_1 = c_built_in_method_idxs[c_operator_binary_ampersand];
  c_bi_mni_operator_binary_pipe_1 = c_built_in_method_idxs[c_operator_binary_pipe];
  c_bi_mni_operator_binary_circumflex_1 = c_built_in_method_idxs[c_operator_binary_circumflex];
  c_bi_mni_operator_binary_double_equal_1 = c_built_in_method_idxs[c_operator_binary_double_equal];
  c_bi_mni_operator_binary_exclamation_equal_1 = c_built_in_method_idxs[c_operator_binary_exclamation_equal];
  c_bi_mni_operator_binary_rs_br_1 = c_built_in_method_idxs[c_operator_binary_rs_br];
  c_bi_mni_operator_binary_ls_br_1 = c_built_in_method_idxs[c_operator_binary_ls_br];
  c_bi_mni_operator_binary_rs_br_equal_1 = c_built_in_method_idxs[c_operator_binary_rs_br_equal];
  c_bi_mni_operator_binary_ls_br_equal_1 = c_built_in_method_idxs[c_operator_binary_ls_br_equal];
  c_bi_mni_operator_binary_double_rs_br_1 = c_built_in_method_idxs[c_operator_binary_double_rs_br];
  c_bi_mni_operator_binary_double_ls_br_1 = c_built_in_method_idxs[c_operator_binary_double_ls_br];
  c_bi_mni_operator_binary_plus_1 = c_built_in_method_idxs[c_operator_binary_plus];
  c_bi_mni_operator_binary_minus_1 = c_built_in_method_idxs[c_operator_binary_minus];
  c_bi_mni_operator_binary_asterisk_1 = c_built_in_method_idxs[c_operator_binary_asterisk];
  c_bi_mni_operator_binary_slash_1 = c_built_in_method_idxs[c_operator_binary_slash];
  c_bi_mni_operator_binary_percent_1 = c_built_in_method_idxs[c_operator_binary_percent];
  c_bi_mni_operator_unary_post_double_plus_0 = c_built_in_method_idxs[c_operator_unary_post_double_plus];
  c_bi_mni_operator_unary_post_double_minus_0 = c_built_in_method_idxs[c_operator_unary_post_double_minus];
  c_bi_mni_operator_unary_pre_double_plus_0 = c_built_in_method_idxs[c_operator_unary_pre_double_plus];
  c_bi_mni_operator_unary_pre_double_minus_0 = c_built_in_method_idxs[c_operator_unary_pre_double_minus];
  c_bi_mni_operator_unary_pre_plus_0 = c_built_in_method_idxs[c_operator_unary_pre_plus];
  c_bi_mni_operator_unary_pre_minus_0 = c_built_in_method_idxs[c_operator_unary_pre_minus];
  c_bi_mni_operator_unary_pre_exclamation_0 = c_built_in_method_idxs[c_operator_unary_pre_exclamation];
  c_bi_mni_operator_unary_pre_tilde_0 = c_built_in_method_idxs[c_operator_unary_pre_tilde];
  c_bi_mni_operator_binary_le_br_re_br_1 = c_built_in_method_idxs[c_operator_binary_le_br_re_br];

  // - module base -
  if (a_modules[c_uclvar_module_base])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Blank_0,"Blank#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Char_0,"Char#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Char_1,"Char#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Integer_0,"Integer#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Integer_1,"Integer#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Integer_2,"Integer#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Float_0,"Float#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Float_1,"Float#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_sin_0,"sin#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_cos_0,"cos#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_tan_0,"tan#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_asin_0,"asin#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_acos_0,"acos#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_atan_0,"atan#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_exp_0,"exp#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_log_0,"log#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_pow_1,"pow#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_sqrt_0,"sqrt#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_cbrt_0,"cbrt#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_hypot_1,"hypot#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni__isnan_0,"isnan#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_String_0,"String#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_String_1,"String#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_split_1,"split#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_join_1,"join#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_head_1,"head#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_tail_1,"tail#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_range_2,"range#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idx_1,"get_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idxs_1,"get_idxs#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_replace_2,"replace#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Array_0,"Array#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Array_1,"Array#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_resize_1,"resize#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_push_1,"push#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_push_ref_1,"push_ref#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_pop_0,"pop#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_0,"last#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_fill_1,"fill#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idx_1,"get_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idxs_1,"get_idxs#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Error_0,"Error#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Exception_0,"Exception#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Exception_1,"Exception#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni__throw_0,"throw#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_type_0,"get_type#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_value_0,"get_value#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_file_name_0,"get_file_name#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_line_0,"get_line#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_error_print_0,"error_print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Type_0,"Type#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Type_1,"Type#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Mutex_0,"Mutex#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_lock_0,"lock#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_try_lock_0,"try_lock#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_unlock_0,"unlock#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_join_0,"join#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_try_join_0,"try_join#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_detach_0,"detach#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_yield_0,"yield#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Delegate_3,"Delegate#3");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_call_1,"call#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_size_0,"size#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  // - module node -
  if (a_modules[c_uclvar_module_node])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_NodeCallback_2,"NodeCallback#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_call_0,"call#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_call_1,"call#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_call_2,"call#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_sleep_1,"sleep#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_srand_1,"srand#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_rand_0,"rand#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_getpid_0,"getpid#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_getuid_0,"getuid#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_getgid_0,"getgid#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_system_1,"system#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_exit_1,"exit#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_open_2,"open#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_popen_2,"popen#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_mkdir_1,"mkdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_rmdir_1,"rmdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_chdir_1,"chdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_listdir_1,"listdir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_mkfifo_1,"mkfifo#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_remove_1,"remove#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_rename_2,"rename#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_getcwd_0,"getcwd#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_setenv_2,"setenv#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_getenv_1,"getenv#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_is_file_1,"is_file#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_is_dir_1,"is_dir#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_size_1,"size#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_time_0,"time#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Pipe_0,"Pipe#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Pipe_2,"Pipe#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_close_0,"close#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_write_1,"write#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_flush_0,"flush#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_0,"read#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_readln_0,"readln#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_1,"read#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_fd_0,"get_fd#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_item_0,"next_item#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_File_0,"File#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_File_2,"File#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_close_0,"close#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_write_1,"write#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_flush_0,"flush#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_0,"read#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_readln_0,"readln#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_1,"read#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_fd_0,"get_fd#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_item_0,"next_item#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");

#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_SocketAddr_2,"SocketAddr#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_name_0,"name#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_port_0,"port#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Socket_0,"Socket#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Socket_2,"Socket#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_listen_2,"listen#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_accept_0,"accept#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_accept_nonblock_0,"accept_nonblock#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_connect_1,"connect#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_bind_1,"bind#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_sendto_2,"sendto#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_recvfrom_0,"recvfrom#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_close_0,"close#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_set_timeout_2,"set_timeout#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_write_1,"write#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_0,"read#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_nonblock_0,"read_nonblock#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_read_1,"read#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_fd_0,"get_fd#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
#endif

#ifdef ENABLE_CLASS_REGEX
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Regex_0,"Regex#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Regex_1,"Regex#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_match_1,"match#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_match_2,"match#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_match_from_2,"match_from#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
#endif

    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_bind_2,"bind#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_unbind_1,"unbind#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_send_2,"send#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Poll_1,"Poll#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_ready_1,"ready#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_poll_1,"poll#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Timer_0,"Timer#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_schedule_3,"schedule#3");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_process_0,"process#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_remain_0,"remain#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_getres_1,"getres#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_gettime_1,"gettime#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_settime_2,"settime#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Stack_0,"Stack#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Stack_1,"Stack#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_items_0,"items#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_push_1,"push#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_push_ref_1,"push_ref#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_pop_0,"pop#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Queue_0,"Queue#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Queue_1,"Queue#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_items_0,"items#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_1,"insert#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_ref_1,"insert_ref#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_0,"next#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Set_0,"Set#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Set_1,"Set#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_items_0,"items#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_1,"insert#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_remove_1,"remove#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_contain_1,"contain#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_List_0,"List#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_List_1,"List#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_items_0,"items#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_append_1,"append#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_append_ref_1,"append_ref#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prepend_1,"prepend#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prepend_ref_1,"prepend_ref#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_before_2,"insert_before#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_before_ref_2,"insert_before_ref#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_after_2,"insert_after#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_after_ref_2,"insert_after_ref#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_remove_1,"remove#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_has_idx_1,"has_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idx_1,"get_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idxs_1,"get_idxs#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Tree_0,"Tree#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Tree_1,"Tree#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_items_0,"items#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_insert_1,"insert#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_remove_1,"remove#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idx_1,"get_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_idxs_1,"get_idxs#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Dict_0,"Dict#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_Dict_1,"Dict#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_clear_0,"clear#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_keys_0,"keys#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_items_0,"items#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_store_ref_2,"store_ref#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_has_key_1,"has_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_remove_key_1,"remove_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_key_0,"first_key#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_key_0,"last_key#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_key_1,"next_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_key_1,"prev_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_lee_key_1,"lee_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_gre_key_1,"gre_key#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_compare_1,"compare#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_item_1,"item#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_first_idx_0,"first_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_last_idx_0,"last_idx#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_next_idx_1,"next_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_prev_idx_1,"prev_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_length_0,"length#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_1,"to_string#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_create_1,"create#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_create_nice_2,"create_nice#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_parse_1,"parse#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_WsContext_2,"WsContext#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_version_0,"version#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_user_data_0,"user_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_client_4,"client#4");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_get_fds_0,"get_fds#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_process_1,"process#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_protocol_idx_1,"protocol_idx#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_callback_on_writable_1,"callback_on_writable#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_reason_0,"reason#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_received_data_0,"received_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_user_data_0,"user_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_ctx_user_data_0,"ctx_user_data#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_protocol_name_0,"protocol_name#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_callback_on_writable_0,"callback_on_writable#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_set_timeout_2,"set_timeout#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_write_1,"write#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_write_2,"write#2");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_connected_0,"connected#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_callback_on_writable_0,"callback_on_writable#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_encode_1,"encode#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_decode_1,"decode#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_JitContext_0,"JitContext#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_create_fun_1,"create_fun#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_signature_0,"signature#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_call_1,"call#1");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_to_string_0,"to_string#0");
    UCLVAR_RETRIEVE_METHOD_NAME_IDX(c_bi_mni_print_0,"print#0");
  }

  /*}}}*/

  // - retrieve variable name indexes -
  /*{{{*/

#define UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(ID,NAME) \
  ID = a_parser.variable_symbol_names.get_idx_char_ptr(strlen(NAME),NAME);\
  cassert(ID != c_idx_not_exist);

  // - module base -
  if (a_modules[c_uclvar_module_base])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_USER_EXCEPTION,"USER_EXCEPTION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TODO_EXCEPTION,"TODO_EXCEPTION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR,"CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CLASS_DOES_NOT_CONTAIN_METHOD,"CLASS_DOES_NOT_CONTAIN_METHOD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CLASS_DOES_NOT_CONTAIN_VARIABLE,"CLASS_DOES_NOT_CONTAIN_VARIABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CANNOT_ACCESS_PRIVATE_METHOD,"CANNOT_ACCESS_PRIVATE_METHOD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CANNOT_ACCESS_PRIVATE_VARIABLE,"CANNOT_ACCESS_PRIVATE_VARIABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_METHOD_CANNOT_RETURN_VALUE,"METHOD_CANNOT_RETURN_VALUE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CANNOT_TEST_TYPE_VALUE,"CANNOT_TEST_TYPE_VALUE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CANNOT_CONVERT_TYPE_TO_INTEGER,"CANNOT_CONVERT_TYPE_TO_INTEGER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CANNOT_USE_NEGATIVE_NUMBER,"CANNOT_USE_NEGATIVE_NUMBER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SLICE_NOT_INTEGER_ARGUMENTS,"SLICE_NOT_INTEGER_ARGUMENTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SLICE_START_LESS_THAN_ZERO,"SLICE_START_LESS_THAN_ZERO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SLICE_STOP_LESS_THAN_ZERO,"SLICE_STOP_LESS_THAN_ZERO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SLICE_STEP_EQUAL_TO_ZERO,"SLICE_STEP_EQUAL_TO_ZERO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_OBJECT_OF_CLASS_IS_NOT_ITERABLE,"OBJECT_OF_CLASS_IS_NOT_ITERABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_UNEXPECTED_END_OF_ITERABLE,"UNEXPECTED_END_OF_ITERABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_BUILT_IN_NOT_IMPLEMENTED_METHOD,"BUILT_IN_NOT_IMPLEMENTED_METHOD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_METHOD_NOT_DEFINED_WITH_PARAMETERS,"METHOD_NOT_DEFINED_WITH_PARAMETERS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRONG_METHOD_PARAMETER_VALUE,"WRONG_METHOD_PARAMETER_VALUE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_DIVISION_BY_ZERO,"DIVISION_BY_ZERO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_NEGATIVE_SHIFT_COUNT,"NEGATIVE_SHIFT_COUNT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_METHOD_NOT_RETURN_INTEGER,"METHOD_NOT_RETURN_INTEGER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_METHOD_NOT_RETURN_STRING,"METHOD_NOT_RETURN_STRING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_METHOD_NOT_RETURN_INDEX,"METHOD_NOT_RETURN_INDEX");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_INTEGER_BASE_OUT_OF_RANGE,"INTEGER_BASE_OUT_OF_RANGE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_INTEGER_CONVERT_INVALID_STRING,"INTEGER_CONVERT_INVALID_STRING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_FLOAT_CONVERT_INVALID_STRING,"FLOAT_CONVERT_INVALID_STRING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,"STRING_FORMAT_NOT_ENOUGH_ARGUMENTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_FORMAT_WRONG_ARGUMENT_TYPE,"STRING_FORMAT_WRONG_ARGUMENT_TYPE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_FORMAT_ARGUMENT_FORMAT_ERROR,"STRING_FORMAT_ARGUMENT_FORMAT_ERROR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_FORMAT_WRONG_FORMAT_SPECIFIER,"STRING_FORMAT_WRONG_FORMAT_SPECIFIER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED,"STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_INDEX_EXCEEDS_RANGE,"STRING_INDEX_EXCEEDS_RANGE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_WRONG_RANGE_INDEXES,"STRING_WRONG_RANGE_INDEXES");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_CONVERT_FROM_INTEGER,"STRING_CONVERT_FROM_INTEGER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_STRING_CONVERT_FROM_FLOAT,"STRING_CONVERT_FROM_FLOAT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ARRAY_INDEX_EXCEEDS_RANGE,"ARRAY_INDEX_EXCEEDS_RANGE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE,"ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ARRAY_NO_ELEMENTS,"ARRAY_NO_ELEMENTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH,"ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_DELEGATE_NEGATIVE_PARAMETER_COUNT,"DELEGATE_NEGATIVE_PARAMETER_COUNT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,"DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_DELEGATE_CALL_WRONG_PARAMETER_COUNT,"DELEGATE_CALL_WRONG_PARAMETER_COUNT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_DELEGATE_WRONG_RETURN_VALUE_TYPE,"DELEGATE_WRONG_RETURN_VALUE_TYPE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ERROR_INVALID,"ERROR_INVALID");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ERROR_DEADLOCK,"ERROR_DEADLOCK");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ERROR_BUSY,"ERROR_BUSY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ERROR_PERMISSION,"ERROR_PERMISSION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ERROR_AGAIN,"ERROR_AGAIN");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_ERROR_SEARCH,"ERROR_SEARCH");
  }

  // - module node -
  if (a_modules[c_uclvar_module_node])
  {
  }

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_NAME,"NAME");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SEP,"SEP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_stdin,"stdin");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_stdout,"stdout");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_stderr,"stderr");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_AF_UNIX,"AF_UNIX");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_AF_FILE,"AF_FILE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_AF_INET,"AF_INET");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SOCK_STREAM,"SOCK_STREAM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SOCK_DGRAM,"SOCK_DGRAM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SOCK_RAW,"SOCK_RAW");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SO_RCVTIMEO,"SO_RCVTIMEO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_SO_SNDTIMEO,"SO_SNDTIMEO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGINT,"SIGINT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGTERM,"SIGTERM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGHUP,"SIGHUP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGQUIT,"SIGQUIT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGILL,"SIGILL");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGTRAP,"SIGTRAP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGABRT,"SIGABRT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGIOT,"SIGIOT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGBUS,"SIGBUS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGFPE,"SIGFPE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGKILL,"SIGKILL");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGUSR1,"SIGUSR1");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGSEGV,"SIGSEGV");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGUSR2,"SIGUSR2");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGPIPE,"SIGPIPE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGALRM,"SIGALRM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGSTKFLT,"SIGSTKFLT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGCHLD,"SIGCHLD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGCONT,"SIGCONT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGSTOP,"SIGSTOP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGTSTP,"SIGTSTP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGTTIN,"SIGTTIN");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGTTOU,"SIGTTOU");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGURG,"SIGURG");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGXCPU,"SIGXCPU");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGXFSZ,"SIGXFSZ");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGVTALRM,"SIGVTALRM");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGPROF,"SIGPROF");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGWINCH,"SIGWINCH");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGIO,"SIGIO");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGPOLL,"SIGPOLL");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGPWR,"SIGPWR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGSYS,"SIGSYS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGUNUSED,"SIGUNUSED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGRTMIN,"SIGRTMIN");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__SIGRTMAX,"SIGRTMAX");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_POLLIN,"POLLIN");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_POLLPRI,"POLLPRI");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_POLLOUT,"POLLOUT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_POLLERR,"POLLERR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_POLLHUP,"POLLHUP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_POLLNVAL,"POLLNVAL");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__CLOCK_REALTIME,"CLOCK_REALTIME");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__CLOCK_MONOTONIC,"CLOCK_MONOTONIC");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__CLOCK_PROCESS_CPUTIME_ID,"CLOCK_PROCESS_CPUTIME_ID");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni__CLOCK_THREAD_CPUTIME_ID,"CLOCK_THREAD_CPUTIME_ID");
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_PORT_NO_LISTEN,"PORT_NO_LISTEN");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_TEXT,"WRITE_TEXT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_BINARY,"WRITE_BINARY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_CONTINUATION,"WRITE_CONTINUATION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_HTTP,"WRITE_HTTP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_CLOSE,"WRITE_CLOSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_PING,"WRITE_PING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_WRITE_PONG,"WRITE_PONG");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_ESTABLISHED,"CB_ESTABLISHED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_CONNECTION_ERROR,"CB_CLIENT_CONNECTION_ERROR");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_FILTER_PRE_ESTABLISH,"CB_CLIENT_FILTER_PRE_ESTABLISH");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_ESTABLISHED,"CB_CLIENT_ESTABLISHED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLOSED,"CB_CLOSED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_RECEIVE,"CB_RECEIVE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_RECEIVE,"CB_CLIENT_RECEIVE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_RECEIVE_PONG,"CB_CLIENT_RECEIVE_PONG");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_WRITEABLE,"CB_CLIENT_WRITEABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_SERVER_WRITEABLE,"CB_SERVER_WRITEABLE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_HTTP,"CB_HTTP");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_HTTP_FILE_COMPLETION,"CB_HTTP_FILE_COMPLETION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_FILTER_NETWORK_CONNECTION,"CB_FILTER_NETWORK_CONNECTION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_FILTER_PROTOCOL_CONNECTION,"CB_FILTER_PROTOCOL_CONNECTION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS,"CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS,"CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION,"CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_APPEND_HANDSHAKE_HEADER,"CB_CLIENT_APPEND_HANDSHAKE_HEADER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CONFIRM_EXTENSION_OKAY,"CB_CONFIRM_EXTENSION_OKAY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED,"CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_PROTOCOL_INIT,"CB_PROTOCOL_INIT");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_PROTOCOL_DESTROY,"CB_PROTOCOL_DESTROY");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_ADD_POLL_FD,"CB_ADD_POLL_FD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_DEL_POLL_FD,"CB_DEL_POLL_FD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_CB_CHANGE_MODE_POLL_FD,"CB_CHANGE_MODE_POLL_FD");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_NO_PENDING,"TIMEOUT_NO_PENDING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_AWAITING_PROXY_RESPONSE,"TIMEOUT_AWAITING_PROXY_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_AWAITING_CONNECT_RESPONSE,"TIMEOUT_AWAITING_CONNECT_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_ESTABLISH_WITH_SERVER,"TIMEOUT_ESTABLISH_WITH_SERVER");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_AWAITING_SERVER_RESPONSE,"TIMEOUT_AWAITING_SERVER_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_AWAITING_PING,"TIMEOUT_AWAITING_PING");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_CLOSE_ACK,"TIMEOUT_CLOSE_ACK");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE,"TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_SENT_CLIENT_HANDSHAKE,"TIMEOUT_SENT_CLIENT_HANDSHAKE");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TIMEOUT_SSL_ACCEPT,"TIMEOUT_SSL_ACCEPT");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_I8,"TYPE_I8");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_U8,"TYPE_U8");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_I16,"TYPE_I16");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_U16,"TYPE_U16");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_I32,"TYPE_I32");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_U32,"TYPE_U32");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_I64,"TYPE_I64");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_U64,"TYPE_U64");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_F32,"TYPE_F32");
    UCLVAR_RETRIEVE_VARIABLE_NAME_IDX(c_bi_vni_TYPE_F64,"TYPE_F64");
  }

  /*}}}*/

  // - retrieve static method indexes -
  /*{{{*/

#define UCLVAR_RETRIEVE_STATIC_METHOD_IDX(CLASS_NAME,CLASS_ID,METHOD_ID,METHOD_NAME_ID) \
  CLASS_NAME::METHOD_ID = a_parser.class_records[CLASS_ID].mnri_map[METHOD_NAME_ID];\
  cassert(CLASS_NAME::METHOD_ID != c_idx_not_exist);

  // - module base -
  if (a_modules[c_uclvar_module_base])
  {
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Blank,c_bi_class_Blank,c_bi_mi_operator_binary_double_equal_1,c_bi_mni_operator_binary_double_equal_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Blank,c_bi_class_Blank,c_bi_mi_operator_binary_exclamation_equal_1,c_bi_mni_operator_binary_exclamation_equal_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Blank,c_bi_class_Blank,c_bi_mi_compare_1,c_bi_mni_compare_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Blank,c_bi_class_Blank,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Blank,c_bi_class_Blank,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Exception,c_bi_class_Exception,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Exception,c_bi_class_Exception,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Mutex,c_bi_class_Mutex,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Mutex,c_bi_class_Mutex,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Thread,c_bi_class_Thread,c_bi_mi_yield_0,c_bi_mni_yield_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Thread,c_bi_class_Thread,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Thread,c_bi_class_Thread,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Delegate,c_bi_class_Delegate,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Delegate,c_bi_class_Delegate,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Buffer,c_bi_class_Buffer,c_bi_mi_size_0,c_bi_mni_size_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Buffer,c_bi_class_Buffer,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Buffer,c_bi_class_Buffer,c_bi_mi_print_0,c_bi_mni_print_0);
  }

  // - module node -
  if (a_modules[c_uclvar_module_node])
  {
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(NodeCallback,c_bi_class_NodeCallback,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(NodeCallback,c_bi_class_NodeCallback,c_bi_mi_print_0,c_bi_mni_print_0);
  }

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_sleep_1,c_bi_mni_sleep_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_srand_1,c_bi_mni_srand_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_rand_0,c_bi_mni_rand_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_getpid_0,c_bi_mni_getpid_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_getuid_0,c_bi_mni_getuid_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_getgid_0,c_bi_mni_getgid_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_system_1,c_bi_mni_system_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_exit_1,c_bi_mni_exit_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_open_2,c_bi_mni_open_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_popen_2,c_bi_mni_popen_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_mkdir_1,c_bi_mni_mkdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_rmdir_1,c_bi_mni_rmdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_chdir_1,c_bi_mni_chdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_listdir_1,c_bi_mni_listdir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_mkfifo_1,c_bi_mni_mkfifo_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_remove_1,c_bi_mni_remove_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_rename_2,c_bi_mni_rename_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_getcwd_0,c_bi_mni_getcwd_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_setenv_2,c_bi_mni_setenv_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_getenv_1,c_bi_mni_getenv_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_is_file_1,c_bi_mni_is_file_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_is_dir_1,c_bi_mni_is_dir_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_size_1,c_bi_mni_size_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_time_0,c_bi_mni_time_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Sys,c_bi_class_Sys,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Pipe,c_bi_class_Pipe,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Pipe,c_bi_class_Pipe,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(File,c_bi_class_File,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(File,c_bi_class_File,c_bi_mi_print_0,c_bi_mni_print_0);

#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(SocketAddr,c_bi_class_SocketAddr,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(SocketAddr,c_bi_class_SocketAddr,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Socket,c_bi_class_Socket,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Socket,c_bi_class_Socket,c_bi_mi_print_0,c_bi_mni_print_0);
#endif

#ifdef ENABLE_CLASS_REGEX
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Regex,c_bi_class_Regex,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Regex,c_bi_class_Regex,c_bi_mi_print_0,c_bi_mni_print_0);
#endif

    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,c_bi_class_Signal,c_bi_mi_bind_2,c_bi_mni_bind_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,c_bi_class_Signal,c_bi_mi_unbind_1,c_bi_mni_unbind_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,c_bi_class_Signal,c_bi_mi_send_2,c_bi_mni_send_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,c_bi_class_Signal,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Signal,c_bi_class_Signal,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Poll,c_bi_class_Poll,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Poll,c_bi_class_Poll,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Timer,c_bi_class_Timer,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Timer,c_bi_class_Timer,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Clock,c_bi_class_Clock,c_bi_mi_getres_1,c_bi_mni_getres_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Clock,c_bi_class_Clock,c_bi_mi_gettime_1,c_bi_mni_gettime_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Clock,c_bi_class_Clock,c_bi_mi_settime_2,c_bi_mni_settime_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Clock,c_bi_class_Clock,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Clock,c_bi_class_Clock,c_bi_mi_print_0,c_bi_mni_print_0);
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,c_bi_class_Json,c_bi_mi_create_1,c_bi_mni_create_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,c_bi_class_Json,c_bi_mi_create_nice_2,c_bi_mni_create_nice_2);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,c_bi_class_Json,c_bi_mi_parse_1,c_bi_mni_parse_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,c_bi_class_Json,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(Json,c_bi_class_Json,c_bi_mi_print_0,c_bi_mni_print_0);
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsContext,c_bi_class_WsContext,c_bi_mi_version_0,c_bi_mni_version_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsContext,c_bi_class_WsContext,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsContext,c_bi_class_WsContext,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsConn,c_bi_class_WsConn,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsConn,c_bi_class_WsConn,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsClient,c_bi_class_WsClient,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsClient,c_bi_class_WsClient,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsBase64,c_bi_class_WsBase64,c_bi_mi_encode_1,c_bi_mni_encode_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsBase64,c_bi_class_WsBase64,c_bi_mi_decode_1,c_bi_mni_decode_1);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsBase64,c_bi_class_WsBase64,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(WsBase64,c_bi_class_WsBase64,c_bi_mi_print_0,c_bi_mni_print_0);
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(JitContext,c_bi_class_JitContext,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(JitContext,c_bi_class_JitContext,c_bi_mi_print_0,c_bi_mni_print_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(JitFunction,c_bi_class_JitFunction,c_bi_mi_to_string_0,c_bi_mni_to_string_0);
    UCLVAR_RETRIEVE_STATIC_METHOD_IDX(JitFunction,c_bi_class_JitFunction,c_bi_mi_print_0,c_bi_mni_print_0);
  }

  /*}}}*/

}/*}}}*/

void UclVar::Initialize(interpreter_s &a_interpreter,bool *a_modules)
{/*{{{*/
  
  // - initialize static constants array -
  static_const_array.init();

  // - retrieve static constant values -
  /*{{{*/

#define UCLVAR_RETRIEVE_STATIC_CONST(CLASS_NAME,CLASS_ID,VAR_NAME) \
{/*{{{*/\
  ri_ep_s &e_ri_ep = a_interpreter.class_records[CLASS_ID].vn_ri_ep_map.map_name(c_bi_vni_ ## VAR_NAME);\
  cassert(e_ri_ep.record_idx != c_idx_not_exist);\
  variable_record_s &vr = a_interpreter.variable_records[e_ri_ep.record_idx];\
  cassert((vr.modifiers & c_modifier_static) &&\
          (vr.modifiers & c_modifier_static_const));\
  location_s *tmp_location = a_interpreter.const_locations.data + e_ri_ep.element_position;\
  tmp_location->v_reference_cnt.atomic_inc();\
  CLASS_NAME::VAR_NAME.location_ptr = tmp_location;\
  static_const_array.push(&CLASS_NAME::VAR_NAME);\
}/*}}}*/

  // - module base -
  if (a_modules[c_uclvar_module_base])
  {
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,USER_EXCEPTION);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,TODO_EXCEPTION);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CLASS_DOES_NOT_CONTAIN_METHOD);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CLASS_DOES_NOT_CONTAIN_VARIABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CANNOT_ACCESS_PRIVATE_METHOD);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CANNOT_ACCESS_PRIVATE_VARIABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,METHOD_CANNOT_RETURN_VALUE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CANNOT_TEST_TYPE_VALUE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CANNOT_CONVERT_TYPE_TO_INTEGER);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,CANNOT_USE_NEGATIVE_NUMBER);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,SLICE_NOT_INTEGER_ARGUMENTS);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,SLICE_START_LESS_THAN_ZERO);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,SLICE_STOP_LESS_THAN_ZERO);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,SLICE_STEP_EQUAL_TO_ZERO);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,OBJECT_OF_CLASS_IS_NOT_ITERABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,UNEXPECTED_END_OF_ITERABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,BUILT_IN_NOT_IMPLEMENTED_METHOD);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,METHOD_NOT_DEFINED_WITH_PARAMETERS);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,WRONG_METHOD_PARAMETER_VALUE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,DIVISION_BY_ZERO);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,NEGATIVE_SHIFT_COUNT);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,METHOD_NOT_RETURN_INTEGER);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,METHOD_NOT_RETURN_STRING);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,METHOD_NOT_RETURN_INDEX);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,INTEGER_BASE_OUT_OF_RANGE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,INTEGER_CONVERT_INVALID_STRING);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,FLOAT_CONVERT_INVALID_STRING);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_FORMAT_NOT_ENOUGH_ARGUMENTS);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_FORMAT_WRONG_ARGUMENT_TYPE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_FORMAT_ARGUMENT_FORMAT_ERROR);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_FORMAT_WRONG_FORMAT_SPECIFIER);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_INDEX_EXCEEDS_RANGE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_WRONG_RANGE_INDEXES);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_CONVERT_FROM_INTEGER);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,STRING_CONVERT_FROM_FLOAT);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,ARRAY_INDEX_EXCEEDS_RANGE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,ARRAY_NO_ELEMENTS);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,DELEGATE_NEGATIVE_PARAMETER_COUNT);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,DELEGATE_CALL_WRONG_PARAMETER_COUNT);
    UCLVAR_RETRIEVE_STATIC_CONST(Exception,c_bi_class_Exception,DELEGATE_WRONG_RETURN_VALUE_TYPE);
    UCLVAR_RETRIEVE_STATIC_CONST(Mutex,c_bi_class_Mutex,ERROR_INVALID);
    UCLVAR_RETRIEVE_STATIC_CONST(Mutex,c_bi_class_Mutex,ERROR_DEADLOCK);
    UCLVAR_RETRIEVE_STATIC_CONST(Mutex,c_bi_class_Mutex,ERROR_BUSY);
    UCLVAR_RETRIEVE_STATIC_CONST(Mutex,c_bi_class_Mutex,ERROR_PERMISSION);
    UCLVAR_RETRIEVE_STATIC_CONST(Thread,c_bi_class_Thread,ERROR_AGAIN);
    UCLVAR_RETRIEVE_STATIC_CONST(Thread,c_bi_class_Thread,ERROR_SEARCH);
    UCLVAR_RETRIEVE_STATIC_CONST(Thread,c_bi_class_Thread,ERROR_INVALID);
    UCLVAR_RETRIEVE_STATIC_CONST(Thread,c_bi_class_Thread,ERROR_DEADLOCK);
    UCLVAR_RETRIEVE_STATIC_CONST(Thread,c_bi_class_Thread,ERROR_BUSY);
  }

  // - module node -
  if (a_modules[c_uclvar_module_node])
  {
  }

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCLVAR_RETRIEVE_STATIC_CONST(Sys,c_bi_class_Sys,NAME);
    UCLVAR_RETRIEVE_STATIC_CONST(Sys,c_bi_class_Sys,SEP);
    UCLVAR_RETRIEVE_STATIC_CONST(File,c_bi_class_File,stdin);
    UCLVAR_RETRIEVE_STATIC_CONST(File,c_bi_class_File,stdout);
    UCLVAR_RETRIEVE_STATIC_CONST(File,c_bi_class_File,stderr);

#ifdef ENABLE_CLASS_SOCKET
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,AF_UNIX);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,AF_FILE);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,AF_INET);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,SOCK_STREAM);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,SOCK_DGRAM);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,SOCK_RAW);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,SO_RCVTIMEO);
    UCLVAR_RETRIEVE_STATIC_CONST(Socket,c_bi_class_Socket,SO_SNDTIMEO);
#endif

    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGINT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGTERM);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGHUP);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGQUIT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGILL);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGTRAP);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGABRT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGIOT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGBUS);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGFPE);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGKILL);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGUSR1);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGSEGV);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGUSR2);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGPIPE);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGALRM);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGSTKFLT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGCHLD);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGCONT);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGSTOP);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGTSTP);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGTTIN);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGTTOU);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGURG);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGXCPU);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGXFSZ);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGVTALRM);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGPROF);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGWINCH);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGIO);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGPOLL);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGPWR);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGSYS);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGUNUSED);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGRTMIN);
    UCLVAR_RETRIEVE_STATIC_CONST(Signal,c_bi_class_Signal,_SIGRTMAX);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,c_bi_class_Poll,POLLIN);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,c_bi_class_Poll,POLLPRI);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,c_bi_class_Poll,POLLOUT);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,c_bi_class_Poll,POLLERR);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,c_bi_class_Poll,POLLHUP);
    UCLVAR_RETRIEVE_STATIC_CONST(Poll,c_bi_class_Poll,POLLNVAL);
    UCLVAR_RETRIEVE_STATIC_CONST(Clock,c_bi_class_Clock,_CLOCK_REALTIME);
    UCLVAR_RETRIEVE_STATIC_CONST(Clock,c_bi_class_Clock,_CLOCK_MONOTONIC);
    UCLVAR_RETRIEVE_STATIC_CONST(Clock,c_bi_class_Clock,_CLOCK_PROCESS_CPUTIME_ID);
    UCLVAR_RETRIEVE_STATIC_CONST(Clock,c_bi_class_Clock,_CLOCK_THREAD_CPUTIME_ID);
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCLVAR_RETRIEVE_STATIC_CONST(WsContext,c_bi_class_WsContext,PORT_NO_LISTEN);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_TEXT);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_BINARY);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_CONTINUATION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_HTTP);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_CLOSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_PING);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,WRITE_PONG);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_ESTABLISHED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_CONNECTION_ERROR);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_FILTER_PRE_ESTABLISH);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_ESTABLISHED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLOSED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_RECEIVE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_RECEIVE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_RECEIVE_PONG);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_WRITEABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_SERVER_WRITEABLE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_HTTP);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_HTTP_FILE_COMPLETION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_FILTER_NETWORK_CONNECTION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_FILTER_PROTOCOL_CONNECTION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_APPEND_HANDSHAKE_HEADER);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CONFIRM_EXTENSION_OKAY);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_PROTOCOL_INIT);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_PROTOCOL_DESTROY);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_ADD_POLL_FD);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_DEL_POLL_FD);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,CB_CHANGE_MODE_POLL_FD);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_NO_PENDING);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_AWAITING_PROXY_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_AWAITING_CONNECT_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_ESTABLISH_WITH_SERVER);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_AWAITING_SERVER_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_AWAITING_PING);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_CLOSE_ACK);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_SENT_CLIENT_HANDSHAKE);
    UCLVAR_RETRIEVE_STATIC_CONST(WsConn,c_bi_class_WsConn,TIMEOUT_SSL_ACCEPT);
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_I8);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_U8);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_I16);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_U16);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_I32);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_U32);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_I64);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_U64);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_F32);
    UCLVAR_RETRIEVE_STATIC_CONST(JitContext,c_bi_class_JitContext,TYPE_F64);
  }

  /*}}}*/

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

