
#ifndef __UCL_VAR_H
#define __UCL_VAR_H

@begin
include "script_parser.h"
@end

#include <string>

#if defined(_GNU_SOURCE) && !defined(ANDROID)
#define ENABLE_THREAD_TRY_JOIN
#endif

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#if SYSTEM_TYPE_UNIX_SOCKET == ENABLED
#define ENABLE_CLASS_SOCKET
#endif
#define ENABLE_CLASS_POLL
#define ENABLE_CLASS_CLOCK
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
  c_uclvar_module_sys,
  c_uclvar_module_inotify,
  c_uclvar_module_time,
  c_uclvar_module_pack,
  c_uclvar_module_parser,
  c_uclvar_module_sqlite,
  c_uclvar_module_http,
  c_uclvar_module_websocket,
  c_uclvar_module_curl,
  c_uclvar_module_ftp,
  c_uclvar_module_ssh2,
  c_uclvar_module_jit,
  c_uclvar_module_node,
  c_uclvar_module_containers,
  c_uclvar_module_algorithms,
  c_uclvar_module_json,
  c_uclvar_module_xml,
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
  libnode_ucll_EXPORT static interpreter_thread_s *it_ptr;
  static pointer_array_s static_const_array;
  location_s *location_ptr;

  // - built in class indexes declaration -
  libnode_ucll_EXPORT static unsigned c_bi_class_Blank;
  libnode_ucll_EXPORT static unsigned c_bi_class_Char;
  libnode_ucll_EXPORT static unsigned c_bi_class_Integer;
  libnode_ucll_EXPORT static unsigned c_bi_class_Float;
  libnode_ucll_EXPORT static unsigned c_bi_class_String;
  libnode_ucll_EXPORT static unsigned c_bi_class_Array;
  libnode_ucll_EXPORT static unsigned c_bi_class_Error;
  libnode_ucll_EXPORT static unsigned c_bi_class_Exception;
  libnode_ucll_EXPORT static unsigned c_bi_class_Type;
  libnode_ucll_EXPORT static unsigned c_bi_class_Mutex;
  libnode_ucll_EXPORT static unsigned c_bi_class_Thread;
  libnode_ucll_EXPORT static unsigned c_bi_class_Delegate;
  libnode_ucll_EXPORT static unsigned c_bi_class_Buffer;
  libnode_ucll_EXPORT static unsigned c_bi_class_Sys;
  libnode_ucll_EXPORT static unsigned c_bi_class_Pipe;
  libnode_ucll_EXPORT static unsigned c_bi_class_File;
  libnode_ucll_EXPORT static unsigned c_bi_class_SocketAddr;
  libnode_ucll_EXPORT static unsigned c_bi_class_Socket;
  libnode_ucll_EXPORT static unsigned c_bi_class_Signal;
  libnode_ucll_EXPORT static unsigned c_bi_class_Poll;
  libnode_ucll_EXPORT static unsigned c_bi_class_Timer;
  libnode_ucll_EXPORT static unsigned c_bi_class_Clock;
  libnode_ucll_EXPORT static unsigned c_bi_class_Inotify;
  libnode_ucll_EXPORT static unsigned c_bi_class_InotifyWatch;
  libnode_ucll_EXPORT static unsigned c_bi_class_InotifyEvent;
  libnode_ucll_EXPORT static unsigned c_bi_class_Time;
  libnode_ucll_EXPORT static unsigned c_bi_class_Pack;
  libnode_ucll_EXPORT static unsigned c_bi_class_FinalAutomata;
  libnode_ucll_EXPORT static unsigned c_bi_class_FaSource;
  libnode_ucll_EXPORT static unsigned c_bi_class_Parser;
  libnode_ucll_EXPORT static unsigned c_bi_class_ParseState;
  libnode_ucll_EXPORT static unsigned c_bi_class_SQLiteConn;
  libnode_ucll_EXPORT static unsigned c_bi_class_SQLiteStatement;
  libnode_ucll_EXPORT static unsigned c_bi_class_HttpServer;
  libnode_ucll_EXPORT static unsigned c_bi_class_HttpConn;
  libnode_ucll_EXPORT static unsigned c_bi_class_HttpResp;
  libnode_ucll_EXPORT static unsigned c_bi_class_WsContext;
  libnode_ucll_EXPORT static unsigned c_bi_class_WsConn;
  libnode_ucll_EXPORT static unsigned c_bi_class_WsClient;
  libnode_ucll_EXPORT static unsigned c_bi_class_WsBase64;
  libnode_ucll_EXPORT static unsigned c_bi_class_CurlResult;
  libnode_ucll_EXPORT static unsigned c_bi_class_Curl;
  libnode_ucll_EXPORT static unsigned c_bi_class_FtpSession;
  libnode_ucll_EXPORT static unsigned c_bi_class_FtpHandle;
  libnode_ucll_EXPORT static unsigned c_bi_class_Ssh2Session;
  libnode_ucll_EXPORT static unsigned c_bi_class_SftpSession;
  libnode_ucll_EXPORT static unsigned c_bi_class_SftpHandle;
  libnode_ucll_EXPORT static unsigned c_bi_class_Ssh2Channel;
  libnode_ucll_EXPORT static unsigned c_bi_class_JitContext;
  libnode_ucll_EXPORT static unsigned c_bi_class_JitFunction;
  libnode_ucll_EXPORT static unsigned c_bi_class_NodeCallback;
  libnode_ucll_EXPORT static unsigned c_bi_class_Stack;
  libnode_ucll_EXPORT static unsigned c_bi_class_Queue;
  libnode_ucll_EXPORT static unsigned c_bi_class_Set;
  libnode_ucll_EXPORT static unsigned c_bi_class_List;
  libnode_ucll_EXPORT static unsigned c_bi_class_Tree;
  libnode_ucll_EXPORT static unsigned c_bi_class_Dict;
  libnode_ucll_EXPORT static unsigned c_bi_class_Algo;
  libnode_ucll_EXPORT static unsigned c_bi_class_Filter;
  libnode_ucll_EXPORT static unsigned c_bi_class_Range;
  libnode_ucll_EXPORT static unsigned c_bi_class_Json;
  libnode_ucll_EXPORT static unsigned c_bi_class_Xml;
  libnode_ucll_EXPORT static unsigned c_bi_class_XmlNode;

  // - built in method name indexes declaration -
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_plus_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_minus_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_asterisk_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_slash_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_percent_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_ls_br_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_rs_br_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_ampersand_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_pipe_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_circumflex_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_ampersand_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_pipe_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_ampersand_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_pipe_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_circumflex_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_exclamation_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_rs_br_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_ls_br_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_rs_br_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_ls_br_equal_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_rs_br_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_double_ls_br_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_plus_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_minus_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_asterisk_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_slash_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_percent_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_post_double_plus_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_post_double_minus_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_pre_double_plus_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_pre_double_minus_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_pre_plus_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_pre_minus_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_pre_exclamation_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_unary_pre_tilde_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_operator_binary_le_br_re_br_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Blank_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_compare_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_to_string_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_print_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Char_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Char_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Integer_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Integer_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Integer_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Float_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Float_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sin_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_cos_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_tan_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_asin_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_acos_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_atan_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_exp_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_log_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_pow_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sqrt_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_cbrt_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_hypot_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_classify_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni__isnan_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_String_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_String_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_create_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_split_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_join_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_head_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_tail_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_range_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_idx_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_idxs_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_replace_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_contain_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_item_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_first_idx_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_next_idx_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_length_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Array_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Array_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_clear_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_resize_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_push_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_push_ref_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_pop_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_last_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_fill_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_last_idx_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_prev_idx_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_to_string_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Error_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Exception_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Exception_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni__throw_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_type_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_value_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_file_name_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_line_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_error_print_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Type_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Type_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Mutex_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_lock_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_try_lock_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_unlock_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_join_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_try_join_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_detach_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_yield_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Delegate_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_call_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_papply_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_size_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sleep_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_srand_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_rand_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_getpid_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_getuid_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_getgid_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_system_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_exit_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_open_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_popen_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_pipe_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_mkdir_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_rmdir_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_chdir_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_listdir_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_mkfifo_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_chmod_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_remove_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_rename_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_getcwd_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_setenv_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_getenv_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_is_file_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_is_dir_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_size_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_time_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Pipe_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_close_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_write_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_write_close_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_flush_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_read_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_readln_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_read_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_read_max_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_read_close_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_pid_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_fd_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_next_item_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_File_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_seek_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_tell_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_SocketAddr_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_name_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_port_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Socket_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_listen_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_accept_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_connect_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_bind_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sendto_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_recvfrom_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_set_timeout_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sockopt_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sockopt_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_bind_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_unbind_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_send_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Poll_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_ready_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_poll_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Timer_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_schedule_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_cancel_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_process_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_remain_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_timeout_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_getres_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_gettime_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_settime_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Inotify_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_add_watch_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_watch_id_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_mask_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_cookie_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Time_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Time_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_value_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_nano_sec_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_micro_sec_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_milli_sec_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_seconds_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_minutes_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_hours_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_days_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_datetime_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_pack_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_unpack_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_code_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_decode_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_FinalAutomata_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_source_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_next_terminal_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_old_input_idx_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_input_idx_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_terminal_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_terminal_length_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Parser_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_parse_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_rule_idx_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_rule_body_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_SQLiteConn_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_SQLiteConn_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_threadsafe_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_execute_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_prepare_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_errmsg_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_bind_blob_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_step_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_reset_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_reset_clear_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_HttpServer_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_stop_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_fds_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_process_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_id_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_url_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_method_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_version_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_upload_data_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_user_data_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_values_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_suspend_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_resume_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_queue_response_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_queue_basic_auth_fail_response_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_basic_auth_username_password_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_queue_digest_auth_fail_response_4;
  libnode_ucll_EXPORT static unsigned c_bi_mni_digest_auth_username_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_digest_auth_check_4;
  libnode_ucll_EXPORT static unsigned c_bi_mni_post_processor_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_HttpResp_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_HttpResp_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_add_header_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_add_footer_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_WsContext_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_client_4;
  libnode_ucll_EXPORT static unsigned c_bi_mni_protocol_idx_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_callback_on_writable_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_reason_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_received_data_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_ctx_user_data_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_protocol_name_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_callback_on_writable_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_write_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_encode_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_decode_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_data_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_info_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni__GET_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni__PUT_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni__POST_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni__DELETE_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni__HEAD_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_FtpSession_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_login_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_get_file_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_put_file_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Ssh2Session_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_hostkey_hash_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_userauth_list_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_userauth_password_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_userauth_fake_interactive_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_userauth_publickey_fromfile_4;
  libnode_ucll_EXPORT static unsigned c_bi_mni_sftp_session_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_exec_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_shell_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_mkdir_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_open_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_send_eof_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_read_stderr_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_JitContext_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_create_fun_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_signature_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_NodeCallback_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_call_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_call_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Stack_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Stack_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_items_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Queue_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Queue_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_insert_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_insert_ref_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_next_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Set_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Set_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_List_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_List_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_append_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_append_ref_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_prepend_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_prepend_ref_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_insert_before_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_insert_before_ref_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_insert_after_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_insert_after_ref_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_has_idx_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Tree_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Tree_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Dict_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Dict_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_keys_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_store_ref_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_has_key_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_remove_key_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_first_key_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_last_key_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_next_key_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_prev_key_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_lee_key_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_gre_key_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_all_true_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_any_true_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_map_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_reduce_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_filter_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_zip_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_tuple_zip_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Range_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Range_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_Range_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_create_nice_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_create_nice_3;
  libnode_ucll_EXPORT static unsigned c_bi_mni_parse_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_XmlNode_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_update_node_dict_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_escape_texts_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_attr__2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_node_1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_node__1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_node_2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_node__2;
  libnode_ucll_EXPORT static unsigned c_bi_mni_text__1;
  libnode_ucll_EXPORT static unsigned c_bi_mni_text_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_attributes_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_node_dict_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_nodes_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_texts_0;
  libnode_ucll_EXPORT static unsigned c_bi_mni_content_0;

  // - built in variable name indexes declaration -
  libnode_ucll_EXPORT static unsigned c_bi_vni__INFINITY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_NAN;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_INFINITE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_ZERO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_SUBNORMAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_NORMAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_USER_EXCEPTION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TODO_EXCEPTION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_DOES_NOT_CONTAIN_METHOD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CLASS_DOES_NOT_CONTAIN_VARIABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CANNOT_ACCESS_PRIVATE_METHOD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CANNOT_ACCESS_PRIVATE_VARIABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_METHOD_CANNOT_RETURN_VALUE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CANNOT_TEST_TYPE_VALUE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CANNOT_CONVERT_TYPE_TO_INTEGER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CANNOT_USE_NEGATIVE_NUMBER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SLICE_NOT_INTEGER_ARGUMENTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SLICE_START_LESS_THAN_ZERO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SLICE_STOP_LESS_THAN_ZERO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SLICE_STEP_EQUAL_TO_ZERO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OBJECT_OF_CLASS_IS_NOT_ITERABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_UNEXPECTED_END_OF_ITERABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_BUILT_IN_NOT_IMPLEMENTED_METHOD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_METHOD_NOT_DEFINED_WITH_PARAMETERS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRONG_METHOD_PARAMETER_VALUE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_DIVISION_BY_ZERO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_NEGATIVE_SHIFT_COUNT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_METHOD_NOT_RETURN_INTEGER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_METHOD_NOT_RETURN_STRING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_METHOD_NOT_RETURN_INDEX;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INTEGER_BASE_OUT_OF_RANGE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INTEGER_CONVERT_INVALID_STRING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_FLOAT_CONVERT_INVALID_STRING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_FORMAT_WRONG_ARGUMENT_TYPE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_FORMAT_ARGUMENT_FORMAT_ERROR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_FORMAT_WRONG_FORMAT_SPECIFIER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_INDEX_EXCEEDS_RANGE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_WRONG_RANGE_INDEXES;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_CONVERT_FROM_INTEGER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_STRING_CONVERT_FROM_FLOAT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_ARRAY_INDEX_EXCEEDS_RANGE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_ARRAY_NO_ELEMENTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH;
  libnode_ucll_EXPORT static unsigned c_bi_vni_DELEGATE_NEGATIVE_PARAMETER_COUNT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_DELEGATE_CALL_WRONG_PARAMETER_COUNT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_DELEGATE_WRONG_RETURN_VALUE_TYPE;
  libnode_ucll_EXPORT static unsigned c_bi_vni__ERROR_INVALID;
  libnode_ucll_EXPORT static unsigned c_bi_vni__ERROR_DEADLOCK;
  libnode_ucll_EXPORT static unsigned c_bi_vni__ERROR_BUSY;
  libnode_ucll_EXPORT static unsigned c_bi_vni__ERROR_PERMISSION;
  libnode_ucll_EXPORT static unsigned c_bi_vni__ERROR_AGAIN;
  libnode_ucll_EXPORT static unsigned c_bi_vni__ERROR_SEARCH;
  libnode_ucll_EXPORT static unsigned c_bi_vni_NAME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SEP;
  libnode_ucll_EXPORT static unsigned c_bi_vni__RAND_MAX;
  libnode_ucll_EXPORT static unsigned c_bi_vni__stdin;
  libnode_ucll_EXPORT static unsigned c_bi_vni__stdout;
  libnode_ucll_EXPORT static unsigned c_bi_vni__stderr;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SEEK_SET;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SEEK_CUR;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SEEK_END;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AF_UNIX;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AF_FILE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AF_INET;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SOCK_STREAM;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SOCK_DGRAM;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SOCK_RAW;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SOL_SOCKET;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SO_ERROR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SO_SNDBUF;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SO_RCVBUF;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SO_RCVTIMEO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_SO_SNDTIMEO;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGINT;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGTERM;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGHUP;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGQUIT;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGILL;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGTRAP;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGABRT;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGIOT;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGBUS;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGFPE;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGKILL;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGUSR1;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGSEGV;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGUSR2;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGPIPE;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGALRM;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGSTKFLT;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGCHLD;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGCONT;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGSTOP;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGTSTP;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGTTIN;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGTTOU;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGURG;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGXCPU;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGXFSZ;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGVTALRM;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGPROF;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGWINCH;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGIO;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGPOLL;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGPWR;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGSYS;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGRTMIN;
  libnode_ucll_EXPORT static unsigned c_bi_vni__SIGRTMAX;
  libnode_ucll_EXPORT static unsigned c_bi_vni_POLLIN;
  libnode_ucll_EXPORT static unsigned c_bi_vni_POLLPRI;
  libnode_ucll_EXPORT static unsigned c_bi_vni_POLLOUT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_POLLERR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_POLLHUP;
  libnode_ucll_EXPORT static unsigned c_bi_vni_POLLNVAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni__CLOCK_REALTIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni__CLOCK_MONOTONIC;
  libnode_ucll_EXPORT static unsigned c_bi_vni__CLOCK_PROCESS_CPUTIME_ID;
  libnode_ucll_EXPORT static unsigned c_bi_vni__CLOCK_THREAD_CPUTIME_ID;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_ACCESS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_MODIFY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_ATTRIB;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_CLOSE_WRITE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_CLOSE_NOWRITE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_CLOSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_OPEN;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_MOVED_FROM;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_MOVED_TO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_MOVE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_CREATE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_DELETE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_DELETE_SELF;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_MOVE_SELF;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_UNMOUNT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_Q_OVERFLOW;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_IGNORED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_ONLYDIR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_DONT_FOLLOW;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_MASK_ADD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_ISDIR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_ONESHOT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_IN_ALL_EVENTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_READONLY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_READWRITE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_CREATE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_DELETEONCLOSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_EXCLUSIVE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_AUTOPROXY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_URI;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_MEMORY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_MAIN_DB;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_TEMP_DB;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_TRANSIENT_DB;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_MAIN_JOURNAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_TEMP_JOURNAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_SUBJOURNAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_MASTER_JOURNAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_NOMUTEX;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_FULLMUTEX;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_SHAREDCACHE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_PRIVATECACHE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPEN_WAL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_CONNECT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_DELETE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_GET;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_HEAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_OPTIONS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_POST;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_PUT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_TRACE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_VALS_HEADER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_VALS_COOKIE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_VALS_POSTDATA;
  libnode_ucll_EXPORT static unsigned c_bi_vni_VALS_GET_ARGUMENT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_VALS_FOOTER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_YES;
  libnode_ucll_EXPORT static unsigned c_bi_vni_NO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INVALID_NONCE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_FROM_STRING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_FROM_FILE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_CONTINUE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_SWITCHING_PROTOCOLS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_PROCESSING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_OK;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_CREATED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_ACCEPTED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NON_AUTHORITATIVE_INFORMATION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NO_CONTENT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_RESET_CONTENT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_PARTIAL_CONTENT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_MULTI_STATUS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_MULTIPLE_CHOICES;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_MOVED_PERMANENTLY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_FOUND;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_SEE_OTHER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NOT_MODIFIED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_USE_PROXY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_SWITCH_PROXY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_TEMPORARY_REDIRECT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_BAD_REQUEST;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_UNAUTHORIZED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_PAYMENT_REQUIRED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_FORBIDDEN;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NOT_FOUND;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_METHOD_NOT_ALLOWED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_METHOD_NOT_ACCEPTABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_PROXY_AUTHENTICATION_REQUIRED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_REQUEST_TIMEOUT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_CONFLICT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_GONE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_LENGTH_REQUIRED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_PRECONDITION_FAILED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_UNSUPPORTED_MEDIA_TYPE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_EXPECTATION_FAILED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_UNPROCESSABLE_ENTITY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_LOCKED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_FAILED_DEPENDENCY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_UNORDERED_COLLECTION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_UPGRADE_REQUIRED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NO_RESPONSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_RETRY_WITH;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_UNAVAILABLE_FOR_LEGAL_REASONS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_INTERNAL_SERVER_ERROR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NOT_IMPLEMENTED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_BAD_GATEWAY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_SERVICE_UNAVAILABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_GATEWAY_TIMEOUT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_HTTP_VERSION_NOT_SUPPORTED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_VARIANT_ALSO_NEGOTIATES;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_INSUFFICIENT_STORAGE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_BANDWIDTH_LIMIT_EXCEEDED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HTTP_NOT_EXTENDED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_PORT_NO_LISTEN;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRITE_TEXT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRITE_BINARY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRITE_CONTINUATION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRITE_HTTP;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRITE_PING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_WRITE_PONG;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_ESTABLISHED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_CONNECTION_ERROR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_FILTER_PRE_ESTABLISH;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_ESTABLISHED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLOSED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_RECEIVE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_RECEIVE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_RECEIVE_PONG;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_WRITEABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_SERVER_WRITEABLE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_HTTP;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_HTTP_FILE_COMPLETION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_FILTER_NETWORK_CONNECTION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_FILTER_PROTOCOL_CONNECTION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_APPEND_HANDSHAKE_HEADER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CONFIRM_EXTENSION_OKAY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_PROTOCOL_INIT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_PROTOCOL_DESTROY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_ADD_POLL_FD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_DEL_POLL_FD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_CB_CHANGE_MODE_POLL_FD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_NO_PENDING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_AWAITING_PROXY_RESPONSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_AWAITING_CONNECT_RESPONSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_ESTABLISH_WITH_SERVER;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_AWAITING_SERVER_RESPONSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_AWAITING_PING;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_CLOSE_ACK;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_SENT_CLIENT_HANDSHAKE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TIMEOUT_SSL_ACCEPT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_EFFECTIVE_URL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_RESPONSE_CODE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_TOTAL_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_NAMELOOKUP_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_CONNECT_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_PRETRANSFER_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_SIZE_UPLOAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_SIZE_DOWNLOAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_SPEED_DOWNLOAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_SPEED_UPLOAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_HEADER_SIZE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_REQUEST_SIZE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_SSL_VERIFYRESULT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_FILETIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_CONTENT_LENGTH_DOWNLOAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_CONTENT_LENGTH_UPLOAD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_STARTTRANSFER_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_CONTENT_TYPE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_REDIRECT_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_REDIRECT_COUNT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_PRIVATE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_HTTP_CONNECTCODE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_HTTPAUTH_AVAIL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_PROXYAUTH_AVAIL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_OS_ERRNO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_NUM_CONNECTS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_SSL_ENGINES;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_COOKIELIST;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_LASTSOCKET;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_FTP_ENTRY_PATH;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_REDIRECT_URL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_PRIMARY_IP;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_APPCONNECT_TIME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_CERTINFO;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_CONDITION_UNMET;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_RTSP_SESSION_ID;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_RTSP_CLIENT_CSEQ;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_RTSP_SERVER_CSEQ;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_RTSP_CSEQ_RECV;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_PRIMARY_PORT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_LOCAL_IP;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_LOCAL_PORT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_INFO_TLS_SESSION;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPT_TIMEOUT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPT_TIMEOUT_MS;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPT_HTTPAUTH;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPT_USERNAME;
  libnode_ucll_EXPORT static unsigned c_bi_vni_OPT_PASSWORD;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_ANY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_ANYSAFE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_BASIC;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_DIGEST;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_GSSNEGOTIATE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_NTLM;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_DIGEST_IE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_NTLM_WB;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_ONLY;
  libnode_ucll_EXPORT static unsigned c_bi_vni_AUTH_NONE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_DIR;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_DIR_VERBOSE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_FILE_READ;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_FILE_WRITE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_ASCII;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_IMAGE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HOSTKEY_HASH_MD5;
  libnode_ucll_EXPORT static unsigned c_bi_vni_HOSTKEY_HASH_SHA1;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_READ;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_WRITE;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_APPEND;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_CREAT;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_TRUNC;
  libnode_ucll_EXPORT static unsigned c_bi_vni_MODE_EXCL;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_I8;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_U8;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_I16;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_U16;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_I32;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_U32;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_I64;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_U64;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_F32;
  libnode_ucll_EXPORT static unsigned c_bi_vni_TYPE_F64;

  private:
  inline void BLANK();
  inline void CHAR(char a_value);
  inline void INTEGER(long long int a_value);
  inline void FLOAT(double a_value);
  inline void STRING(unsigned a_length,const char *a_data);
  inline void ARRAY(unsigned a_size,const UclVar *a_array);

  libnode_ucll_EXPORT UclVar __call_0(unsigned a_method_idx);
  libnode_ucll_EXPORT UclVar __call_1(unsigned a_method_idx,UclVar a_op);
  libnode_ucll_EXPORT UclVar __call_2(unsigned a_method_idx,UclVar a_op,UclVar a_op_1);
  libnode_ucll_EXPORT UclVar __call_3(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2);
  libnode_ucll_EXPORT UclVar __call_4(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3);
  libnode_ucll_EXPORT UclVar __call_5(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3,UclVar a_op_4);

  libnode_ucll_EXPORT static UclVar __static_call_0(unsigned a_method_idx);
  libnode_ucll_EXPORT static UclVar __static_call_1(unsigned a_method_idx,UclVar a_op);
  libnode_ucll_EXPORT static UclVar __static_call_2(unsigned a_method_idx,UclVar a_op,UclVar a_op_1);
  libnode_ucll_EXPORT static UclVar __static_call_3(unsigned a_method_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2);

  libnode_ucll_EXPORT static UclVar __new_object_0(unsigned a_class_idx,unsigned a_name_idx);
  libnode_ucll_EXPORT static UclVar __new_object_1(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op);
  libnode_ucll_EXPORT static UclVar __new_object_2(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1);
  libnode_ucll_EXPORT static UclVar __new_object_3(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2);
  libnode_ucll_EXPORT static UclVar __new_object_4(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3);
  libnode_ucll_EXPORT static UclVar __new_object_5(unsigned a_class_idx,unsigned a_name_idx,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3,UclVar a_op_4);

  public:
  libnode_ucll_EXPORT UclVar __call(std::string a_method_name);
  libnode_ucll_EXPORT UclVar __call(std::string a_method_name,UclVar a_op);
  libnode_ucll_EXPORT UclVar __call(std::string a_method_name,UclVar a_op,UclVar a_op_1);
  libnode_ucll_EXPORT UclVar __call(std::string a_method_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2);
  libnode_ucll_EXPORT UclVar __call(std::string a_method_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3);
  libnode_ucll_EXPORT UclVar __call(std::string a_method_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3,UclVar a_op_4);

  libnode_ucll_EXPORT static UclVar __static_call(std::string a_class_name,std::string a_method_name);
  libnode_ucll_EXPORT static UclVar __static_call(std::string a_class_name,std::string a_method_name,UclVar a_op);
  libnode_ucll_EXPORT static UclVar __static_call(std::string a_class_name,std::string a_method_name,UclVar a_op,UclVar a_op_1);

  libnode_ucll_EXPORT static UclVar __new(std::string a_name);
  libnode_ucll_EXPORT static UclVar __new(std::string a_name,UclVar a_op);
  libnode_ucll_EXPORT static UclVar __new(std::string a_name,UclVar a_op,UclVar a_op_1);
  libnode_ucll_EXPORT static UclVar __new(std::string a_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2);
  libnode_ucll_EXPORT static UclVar __new(std::string a_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3);
  libnode_ucll_EXPORT static UclVar __new(std::string a_name,UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3,UclVar a_op_4);

  libnode_ucll_EXPORT UclVar __member(std::string a_name);
  libnode_ucll_EXPORT UclVar __slice(UclVar a_start,UclVar a_stop,UclVar a_step);

  static void Initialize(script_parser_s &a_parser,bool *a_modules);
  static void Initialize(interpreter_s &a_interpreter,bool *a_modules);
  static void InitThread(interpreter_thread_s &a_it);
  static void Release(interpreter_s &a_interpreter);

  inline UclVar(const UclVar &a_src)
  {/*{{{*/
    a_src.location_ptr->v_reference_cnt.atomic_inc();
    location_ptr = a_src.location_ptr;
  }/*}}}*/

#if __cplusplus >= 201103
  inline UclVar(UclVar &&a_src)
  {/*{{{*/
    location_ptr = a_src.location_ptr;
    a_src.location_ptr = nullptr;
  }/*}}}*/
#endif

  inline UclVar(location_s **a_location_ptr)
  {/*{{{*/
    location_ptr = it_ptr->get_new_reference(a_location_ptr);
  }/*}}}*/

  inline ~UclVar()
  {/*{{{*/
    if (location_ptr != nullptr)
    {
      it_ptr->release_location_ptr(location_ptr);
    }
  }/*}}}*/

  class NO_INIT {};

  inline UclVar(NO_INIT)                              { location_ptr = nullptr; }
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

  inline static interpreter_thread_s *__it_ptr();
  inline location_s *__loc();

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
  class Float
  {/*{{{*/
    public:
    libnode_ucll_EXPORT static UclVar _INFINITY;
    libnode_ucll_EXPORT static UclVar CLASS_NAN;
    libnode_ucll_EXPORT static UclVar CLASS_INFINITE;
    libnode_ucll_EXPORT static UclVar CLASS_ZERO;
    libnode_ucll_EXPORT static UclVar CLASS_SUBNORMAL;
    libnode_ucll_EXPORT static UclVar CLASS_NORMAL;

  };/*}}}*/

  inline static UclVar Float()
  {/*{{{*/
    return __new_object_0(c_bi_class_Float,c_bi_mni_Float_0);
  }/*}}}*/

  inline static UclVar Float(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Float,c_bi_mni_Float_1,op_0);
  }/*}}}*/

  // - class String -
  class String
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_create_1;

    public:
    inline static UclVar create(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_create_1,op_0);
    }/*}}}*/

  };/*}}}*/

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
    libnode_ucll_EXPORT static UclVar USER_EXCEPTION;
    libnode_ucll_EXPORT static UclVar TODO_EXCEPTION;
    libnode_ucll_EXPORT static UclVar CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR;
    libnode_ucll_EXPORT static UclVar CLASS_DOES_NOT_CONTAIN_METHOD;
    libnode_ucll_EXPORT static UclVar CLASS_DOES_NOT_CONTAIN_VARIABLE;
    libnode_ucll_EXPORT static UclVar CANNOT_ACCESS_PRIVATE_METHOD;
    libnode_ucll_EXPORT static UclVar CANNOT_ACCESS_PRIVATE_VARIABLE;
    libnode_ucll_EXPORT static UclVar METHOD_CANNOT_RETURN_VALUE;
    libnode_ucll_EXPORT static UclVar CANNOT_TEST_TYPE_VALUE;
    libnode_ucll_EXPORT static UclVar CANNOT_CONVERT_TYPE_TO_INTEGER;
    libnode_ucll_EXPORT static UclVar CANNOT_USE_NEGATIVE_NUMBER;
    libnode_ucll_EXPORT static UclVar SLICE_NOT_INTEGER_ARGUMENTS;
    libnode_ucll_EXPORT static UclVar SLICE_START_LESS_THAN_ZERO;
    libnode_ucll_EXPORT static UclVar SLICE_STOP_LESS_THAN_ZERO;
    libnode_ucll_EXPORT static UclVar SLICE_STEP_EQUAL_TO_ZERO;
    libnode_ucll_EXPORT static UclVar OBJECT_OF_CLASS_IS_NOT_ITERABLE;
    libnode_ucll_EXPORT static UclVar UNEXPECTED_END_OF_ITERABLE;
    libnode_ucll_EXPORT static UclVar BUILT_IN_NOT_IMPLEMENTED_METHOD;
    libnode_ucll_EXPORT static UclVar METHOD_NOT_DEFINED_WITH_PARAMETERS;
    libnode_ucll_EXPORT static UclVar WRONG_METHOD_PARAMETER_VALUE;
    libnode_ucll_EXPORT static UclVar DIVISION_BY_ZERO;
    libnode_ucll_EXPORT static UclVar NEGATIVE_SHIFT_COUNT;
    libnode_ucll_EXPORT static UclVar METHOD_NOT_RETURN_INTEGER;
    libnode_ucll_EXPORT static UclVar METHOD_NOT_RETURN_STRING;
    libnode_ucll_EXPORT static UclVar METHOD_NOT_RETURN_INDEX;
    libnode_ucll_EXPORT static UclVar INTEGER_BASE_OUT_OF_RANGE;
    libnode_ucll_EXPORT static UclVar INTEGER_CONVERT_INVALID_STRING;
    libnode_ucll_EXPORT static UclVar FLOAT_CONVERT_INVALID_STRING;
    libnode_ucll_EXPORT static UclVar STRING_FORMAT_NOT_ENOUGH_ARGUMENTS;
    libnode_ucll_EXPORT static UclVar STRING_FORMAT_WRONG_ARGUMENT_TYPE;
    libnode_ucll_EXPORT static UclVar STRING_FORMAT_ARGUMENT_FORMAT_ERROR;
    libnode_ucll_EXPORT static UclVar STRING_FORMAT_WRONG_FORMAT_SPECIFIER;
    libnode_ucll_EXPORT static UclVar STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED;
    libnode_ucll_EXPORT static UclVar STRING_INDEX_EXCEEDS_RANGE;
    libnode_ucll_EXPORT static UclVar STRING_WRONG_RANGE_INDEXES;
    libnode_ucll_EXPORT static UclVar STRING_CONVERT_FROM_INTEGER;
    libnode_ucll_EXPORT static UclVar STRING_CONVERT_FROM_FLOAT;
    libnode_ucll_EXPORT static UclVar ARRAY_INDEX_EXCEEDS_RANGE;
    libnode_ucll_EXPORT static UclVar ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE;
    libnode_ucll_EXPORT static UclVar ARRAY_NO_ELEMENTS;
    libnode_ucll_EXPORT static UclVar ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH;
    libnode_ucll_EXPORT static UclVar DELEGATE_NEGATIVE_PARAMETER_COUNT;
    libnode_ucll_EXPORT static UclVar DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD;
    libnode_ucll_EXPORT static UclVar DELEGATE_CALL_WRONG_PARAMETER_COUNT;
    libnode_ucll_EXPORT static UclVar DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT;
    libnode_ucll_EXPORT static UclVar DELEGATE_WRONG_RETURN_VALUE_TYPE;

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
    libnode_ucll_EXPORT static UclVar _ERROR_INVALID;
    libnode_ucll_EXPORT static UclVar _ERROR_DEADLOCK;
    libnode_ucll_EXPORT static UclVar _ERROR_BUSY;
    libnode_ucll_EXPORT static UclVar _ERROR_PERMISSION;

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
    libnode_ucll_EXPORT static UclVar _ERROR_AGAIN;
    libnode_ucll_EXPORT static UclVar _ERROR_SEARCH;
    libnode_ucll_EXPORT static UclVar _ERROR_INVALID;
    libnode_ucll_EXPORT static UclVar _ERROR_DEADLOCK;
    libnode_ucll_EXPORT static UclVar _ERROR_BUSY;

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
    static unsigned c_bi_mi_pipe_0;
    static unsigned c_bi_mi_mkdir_1;
    static unsigned c_bi_mi_rmdir_1;
    static unsigned c_bi_mi_chdir_1;
    static unsigned c_bi_mi_listdir_1;
    static unsigned c_bi_mi_mkfifo_1;
    static unsigned c_bi_mi_chmod_2;
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
    libnode_ucll_EXPORT static UclVar NAME;
    libnode_ucll_EXPORT static UclVar SEP;
    libnode_ucll_EXPORT static UclVar _RAND_MAX;

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

    inline static UclVar pipe()
    {/*{{{*/
      return __static_call_0(c_bi_mi_pipe_0);
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

    inline static UclVar chmod(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_chmod_2,op_0,op_1);
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
    libnode_ucll_EXPORT static UclVar _stdin;
    libnode_ucll_EXPORT static UclVar _stdout;
    libnode_ucll_EXPORT static UclVar _stderr;
    libnode_ucll_EXPORT static UclVar _SEEK_SET;
    libnode_ucll_EXPORT static UclVar _SEEK_CUR;
    libnode_ucll_EXPORT static UclVar _SEEK_END;

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
    libnode_ucll_EXPORT static UclVar AF_UNIX;
    libnode_ucll_EXPORT static UclVar AF_FILE;
    libnode_ucll_EXPORT static UclVar AF_INET;
    libnode_ucll_EXPORT static UclVar SOCK_STREAM;
    libnode_ucll_EXPORT static UclVar SOCK_DGRAM;
    libnode_ucll_EXPORT static UclVar SOCK_RAW;
    libnode_ucll_EXPORT static UclVar SOL_SOCKET;
    libnode_ucll_EXPORT static UclVar SO_ERROR;
    libnode_ucll_EXPORT static UclVar SO_SNDBUF;
    libnode_ucll_EXPORT static UclVar SO_RCVBUF;
    libnode_ucll_EXPORT static UclVar SO_RCVTIMEO;
    libnode_ucll_EXPORT static UclVar SO_SNDTIMEO;

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

  inline static UclVar Socket(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_Socket,c_bi_mni_Socket_2,op_0,op_1);
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
    libnode_ucll_EXPORT static UclVar _SIGINT;
    libnode_ucll_EXPORT static UclVar _SIGTERM;
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
    libnode_ucll_EXPORT static UclVar _SIGHUP;
    libnode_ucll_EXPORT static UclVar _SIGQUIT;
    libnode_ucll_EXPORT static UclVar _SIGILL;
    libnode_ucll_EXPORT static UclVar _SIGTRAP;
    libnode_ucll_EXPORT static UclVar _SIGABRT;
    libnode_ucll_EXPORT static UclVar _SIGIOT;
    libnode_ucll_EXPORT static UclVar _SIGBUS;
    libnode_ucll_EXPORT static UclVar _SIGFPE;
    libnode_ucll_EXPORT static UclVar _SIGKILL;
    libnode_ucll_EXPORT static UclVar _SIGUSR1;
    libnode_ucll_EXPORT static UclVar _SIGSEGV;
    libnode_ucll_EXPORT static UclVar _SIGUSR2;
    libnode_ucll_EXPORT static UclVar _SIGPIPE;
    libnode_ucll_EXPORT static UclVar _SIGALRM;
    libnode_ucll_EXPORT static UclVar _SIGSTKFLT;
    libnode_ucll_EXPORT static UclVar _SIGCHLD;
    libnode_ucll_EXPORT static UclVar _SIGCONT;
    libnode_ucll_EXPORT static UclVar _SIGSTOP;
    libnode_ucll_EXPORT static UclVar _SIGTSTP;
    libnode_ucll_EXPORT static UclVar _SIGTTIN;
    libnode_ucll_EXPORT static UclVar _SIGTTOU;
    libnode_ucll_EXPORT static UclVar _SIGURG;
    libnode_ucll_EXPORT static UclVar _SIGXCPU;
    libnode_ucll_EXPORT static UclVar _SIGXFSZ;
    libnode_ucll_EXPORT static UclVar _SIGVTALRM;
    libnode_ucll_EXPORT static UclVar _SIGPROF;
    libnode_ucll_EXPORT static UclVar _SIGWINCH;
    libnode_ucll_EXPORT static UclVar _SIGIO;
    libnode_ucll_EXPORT static UclVar _SIGPOLL;
    libnode_ucll_EXPORT static UclVar _SIGPWR;
    libnode_ucll_EXPORT static UclVar _SIGSYS;
    libnode_ucll_EXPORT static UclVar _SIGRTMIN;
    libnode_ucll_EXPORT static UclVar _SIGRTMAX;
#endif

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

#ifdef ENABLE_CLASS_POLL
  // - class Poll -
  class Poll
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar POLLIN;
    libnode_ucll_EXPORT static UclVar POLLPRI;
    libnode_ucll_EXPORT static UclVar POLLOUT;
    libnode_ucll_EXPORT static UclVar POLLERR;
    libnode_ucll_EXPORT static UclVar POLLHUP;
    libnode_ucll_EXPORT static UclVar POLLNVAL;

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
#endif

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

#ifdef ENABLE_CLASS_CLOCK
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
    libnode_ucll_EXPORT static UclVar _CLOCK_REALTIME;
    libnode_ucll_EXPORT static UclVar _CLOCK_MONOTONIC;
    libnode_ucll_EXPORT static UclVar _CLOCK_PROCESS_CPUTIME_ID;
    libnode_ucll_EXPORT static UclVar _CLOCK_THREAD_CPUTIME_ID;

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
#endif

  // - class Inotify -
  class Inotify
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar IN_ACCESS;
    libnode_ucll_EXPORT static UclVar IN_MODIFY;
    libnode_ucll_EXPORT static UclVar IN_ATTRIB;
    libnode_ucll_EXPORT static UclVar IN_CLOSE_WRITE;
    libnode_ucll_EXPORT static UclVar IN_CLOSE_NOWRITE;
    libnode_ucll_EXPORT static UclVar IN_CLOSE;
    libnode_ucll_EXPORT static UclVar IN_OPEN;
    libnode_ucll_EXPORT static UclVar IN_MOVED_FROM;
    libnode_ucll_EXPORT static UclVar IN_MOVED_TO;
    libnode_ucll_EXPORT static UclVar IN_MOVE;
    libnode_ucll_EXPORT static UclVar IN_CREATE;
    libnode_ucll_EXPORT static UclVar IN_DELETE;
    libnode_ucll_EXPORT static UclVar IN_DELETE_SELF;
    libnode_ucll_EXPORT static UclVar IN_MOVE_SELF;
    libnode_ucll_EXPORT static UclVar IN_UNMOUNT;
    libnode_ucll_EXPORT static UclVar IN_Q_OVERFLOW;
    libnode_ucll_EXPORT static UclVar IN_IGNORED;
    libnode_ucll_EXPORT static UclVar IN_ONLYDIR;
    libnode_ucll_EXPORT static UclVar IN_DONT_FOLLOW;
    libnode_ucll_EXPORT static UclVar IN_MASK_ADD;
    libnode_ucll_EXPORT static UclVar IN_ISDIR;
    libnode_ucll_EXPORT static UclVar IN_ONESHOT;
    libnode_ucll_EXPORT static UclVar IN_ALL_EVENTS;

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

  inline static UclVar Inotify()
  {/*{{{*/
    return __new_object_0(c_bi_class_Inotify,c_bi_mni_Inotify_0);
  }/*}}}*/

  // - class InotifyWatch -
  class InotifyWatch
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

  // - class InotifyEvent -
  class InotifyEvent
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

  // - class Time -
  inline static UclVar Time()
  {/*{{{*/
    return __new_object_0(c_bi_class_Time,c_bi_mni_Time_0);
  }/*}}}*/

  inline static UclVar Time(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Time,c_bi_mni_Time_1,op_0);
  }/*}}}*/

  // - class Pack -
  class Pack
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_pack_1;
    static unsigned c_bi_mi_unpack_1;
    static unsigned c_bi_mi_code_2;
    static unsigned c_bi_mi_decode_2;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar pack(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_pack_1,op_0);
    }/*}}}*/

    inline static UclVar unpack(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_unpack_1,op_0);
    }/*}}}*/

    inline static UclVar code(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_code_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar decode(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_decode_2,op_0,op_1);
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

  // - class FinalAutomata -
  class FinalAutomata
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

  inline static UclVar FinalAutomata(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_FinalAutomata,c_bi_mni_FinalAutomata_1,op_0);
  }/*}}}*/

  // - class FaSource -
  class FaSource
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

  // - class Parser -
  class Parser
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

  inline static UclVar Parser(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Parser,c_bi_mni_Parser_1,op_0);
  }/*}}}*/

  // - class ParseState -
  class ParseState
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

  // - class SQLiteConn -
  class SQLiteConn
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_threadsafe_0;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar OPEN_READONLY;
    libnode_ucll_EXPORT static UclVar OPEN_READWRITE;
    libnode_ucll_EXPORT static UclVar OPEN_CREATE;
    libnode_ucll_EXPORT static UclVar OPEN_DELETEONCLOSE;
    libnode_ucll_EXPORT static UclVar OPEN_EXCLUSIVE;
    libnode_ucll_EXPORT static UclVar OPEN_AUTOPROXY;
    libnode_ucll_EXPORT static UclVar OPEN_URI;
    libnode_ucll_EXPORT static UclVar OPEN_MEMORY;
    libnode_ucll_EXPORT static UclVar OPEN_MAIN_DB;
    libnode_ucll_EXPORT static UclVar OPEN_TEMP_DB;
    libnode_ucll_EXPORT static UclVar OPEN_TRANSIENT_DB;
    libnode_ucll_EXPORT static UclVar OPEN_MAIN_JOURNAL;
    libnode_ucll_EXPORT static UclVar OPEN_TEMP_JOURNAL;
    libnode_ucll_EXPORT static UclVar OPEN_SUBJOURNAL;
    libnode_ucll_EXPORT static UclVar OPEN_MASTER_JOURNAL;
    libnode_ucll_EXPORT static UclVar OPEN_NOMUTEX;
    libnode_ucll_EXPORT static UclVar OPEN_FULLMUTEX;
    libnode_ucll_EXPORT static UclVar OPEN_SHAREDCACHE;
    libnode_ucll_EXPORT static UclVar OPEN_PRIVATECACHE;
    libnode_ucll_EXPORT static UclVar OPEN_WAL;

    public:
    inline static UclVar threadsafe()
    {/*{{{*/
      return __static_call_0(c_bi_mi_threadsafe_0);
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

  inline static UclVar SQLiteConn(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_SQLiteConn,c_bi_mni_SQLiteConn_1,op_0);
  }/*}}}*/

  inline static UclVar SQLiteConn(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_SQLiteConn,c_bi_mni_SQLiteConn_2,op_0,op_1);
  }/*}}}*/

  // - class SQLiteStatement -
  class SQLiteStatement
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

  // - class HttpServer -
  class HttpServer
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

  inline static UclVar HttpServer(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_HttpServer,c_bi_mni_HttpServer_2,op_0,op_1);
  }/*}}}*/

  // - class HttpConn -
  class HttpConn
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar TYPE_CONNECT;
    libnode_ucll_EXPORT static UclVar TYPE_DELETE;
    libnode_ucll_EXPORT static UclVar TYPE_GET;
    libnode_ucll_EXPORT static UclVar TYPE_HEAD;
    libnode_ucll_EXPORT static UclVar TYPE_OPTIONS;
    libnode_ucll_EXPORT static UclVar TYPE_POST;
    libnode_ucll_EXPORT static UclVar TYPE_PUT;
    libnode_ucll_EXPORT static UclVar TYPE_TRACE;
    libnode_ucll_EXPORT static UclVar VALS_HEADER;
    libnode_ucll_EXPORT static UclVar VALS_COOKIE;
    libnode_ucll_EXPORT static UclVar VALS_POSTDATA;
    libnode_ucll_EXPORT static UclVar VALS_GET_ARGUMENT;
    libnode_ucll_EXPORT static UclVar VALS_FOOTER;
    libnode_ucll_EXPORT static UclVar YES;
    libnode_ucll_EXPORT static UclVar NO;
    libnode_ucll_EXPORT static UclVar INVALID_NONCE;

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

  // - class HttpResp -
  class HttpResp
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar FROM_STRING;
    libnode_ucll_EXPORT static UclVar FROM_FILE;
    libnode_ucll_EXPORT static UclVar HTTP_CONTINUE;
    libnode_ucll_EXPORT static UclVar HTTP_SWITCHING_PROTOCOLS;
    libnode_ucll_EXPORT static UclVar HTTP_PROCESSING;
    libnode_ucll_EXPORT static UclVar HTTP_OK;
    libnode_ucll_EXPORT static UclVar HTTP_CREATED;
    libnode_ucll_EXPORT static UclVar HTTP_ACCEPTED;
    libnode_ucll_EXPORT static UclVar HTTP_NON_AUTHORITATIVE_INFORMATION;
    libnode_ucll_EXPORT static UclVar HTTP_NO_CONTENT;
    libnode_ucll_EXPORT static UclVar HTTP_RESET_CONTENT;
    libnode_ucll_EXPORT static UclVar HTTP_PARTIAL_CONTENT;
    libnode_ucll_EXPORT static UclVar HTTP_MULTI_STATUS;
    libnode_ucll_EXPORT static UclVar HTTP_MULTIPLE_CHOICES;
    libnode_ucll_EXPORT static UclVar HTTP_MOVED_PERMANENTLY;
    libnode_ucll_EXPORT static UclVar HTTP_FOUND;
    libnode_ucll_EXPORT static UclVar HTTP_SEE_OTHER;
    libnode_ucll_EXPORT static UclVar HTTP_NOT_MODIFIED;
    libnode_ucll_EXPORT static UclVar HTTP_USE_PROXY;
    libnode_ucll_EXPORT static UclVar HTTP_SWITCH_PROXY;
    libnode_ucll_EXPORT static UclVar HTTP_TEMPORARY_REDIRECT;
    libnode_ucll_EXPORT static UclVar HTTP_BAD_REQUEST;
    libnode_ucll_EXPORT static UclVar HTTP_UNAUTHORIZED;
    libnode_ucll_EXPORT static UclVar HTTP_PAYMENT_REQUIRED;
    libnode_ucll_EXPORT static UclVar HTTP_FORBIDDEN;
    libnode_ucll_EXPORT static UclVar HTTP_NOT_FOUND;
    libnode_ucll_EXPORT static UclVar HTTP_METHOD_NOT_ALLOWED;
    libnode_ucll_EXPORT static UclVar HTTP_METHOD_NOT_ACCEPTABLE;
    libnode_ucll_EXPORT static UclVar HTTP_PROXY_AUTHENTICATION_REQUIRED;
    libnode_ucll_EXPORT static UclVar HTTP_REQUEST_TIMEOUT;
    libnode_ucll_EXPORT static UclVar HTTP_CONFLICT;
    libnode_ucll_EXPORT static UclVar HTTP_GONE;
    libnode_ucll_EXPORT static UclVar HTTP_LENGTH_REQUIRED;
    libnode_ucll_EXPORT static UclVar HTTP_PRECONDITION_FAILED;
    libnode_ucll_EXPORT static UclVar HTTP_UNSUPPORTED_MEDIA_TYPE;
    libnode_ucll_EXPORT static UclVar HTTP_EXPECTATION_FAILED;
    libnode_ucll_EXPORT static UclVar HTTP_UNPROCESSABLE_ENTITY;
    libnode_ucll_EXPORT static UclVar HTTP_LOCKED;
    libnode_ucll_EXPORT static UclVar HTTP_FAILED_DEPENDENCY;
    libnode_ucll_EXPORT static UclVar HTTP_UNORDERED_COLLECTION;
    libnode_ucll_EXPORT static UclVar HTTP_UPGRADE_REQUIRED;
    libnode_ucll_EXPORT static UclVar HTTP_NO_RESPONSE;
    libnode_ucll_EXPORT static UclVar HTTP_RETRY_WITH;
    libnode_ucll_EXPORT static UclVar HTTP_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS;
    libnode_ucll_EXPORT static UclVar HTTP_UNAVAILABLE_FOR_LEGAL_REASONS;
    libnode_ucll_EXPORT static UclVar HTTP_INTERNAL_SERVER_ERROR;
    libnode_ucll_EXPORT static UclVar HTTP_NOT_IMPLEMENTED;
    libnode_ucll_EXPORT static UclVar HTTP_BAD_GATEWAY;
    libnode_ucll_EXPORT static UclVar HTTP_SERVICE_UNAVAILABLE;
    libnode_ucll_EXPORT static UclVar HTTP_GATEWAY_TIMEOUT;
    libnode_ucll_EXPORT static UclVar HTTP_HTTP_VERSION_NOT_SUPPORTED;
    libnode_ucll_EXPORT static UclVar HTTP_VARIANT_ALSO_NEGOTIATES;
    libnode_ucll_EXPORT static UclVar HTTP_INSUFFICIENT_STORAGE;
    libnode_ucll_EXPORT static UclVar HTTP_BANDWIDTH_LIMIT_EXCEEDED;
    libnode_ucll_EXPORT static UclVar HTTP_NOT_EXTENDED;

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

  inline static UclVar HttpResp(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_HttpResp,c_bi_mni_HttpResp_1,op_0);
  }/*}}}*/

  inline static UclVar HttpResp(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_HttpResp,c_bi_mni_HttpResp_2,op_0,op_1);
  }/*}}}*/

  // - class WsContext -
  class WsContext
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_version_0;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar PORT_NO_LISTEN;

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
    libnode_ucll_EXPORT static UclVar WRITE_TEXT;
    libnode_ucll_EXPORT static UclVar WRITE_BINARY;
    libnode_ucll_EXPORT static UclVar WRITE_CONTINUATION;
    libnode_ucll_EXPORT static UclVar WRITE_HTTP;
    libnode_ucll_EXPORT static UclVar WRITE_PING;
    libnode_ucll_EXPORT static UclVar WRITE_PONG;
    libnode_ucll_EXPORT static UclVar CB_ESTABLISHED;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_CONNECTION_ERROR;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_FILTER_PRE_ESTABLISH;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_ESTABLISHED;
    libnode_ucll_EXPORT static UclVar CB_CLOSED;
    libnode_ucll_EXPORT static UclVar CB_RECEIVE;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_RECEIVE;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_RECEIVE_PONG;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_WRITEABLE;
    libnode_ucll_EXPORT static UclVar CB_SERVER_WRITEABLE;
    libnode_ucll_EXPORT static UclVar CB_HTTP;
    libnode_ucll_EXPORT static UclVar CB_HTTP_FILE_COMPLETION;
    libnode_ucll_EXPORT static UclVar CB_FILTER_NETWORK_CONNECTION;
    libnode_ucll_EXPORT static UclVar CB_FILTER_PROTOCOL_CONNECTION;
    libnode_ucll_EXPORT static UclVar CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS;
    libnode_ucll_EXPORT static UclVar CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS;
    libnode_ucll_EXPORT static UclVar CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_APPEND_HANDSHAKE_HEADER;
    libnode_ucll_EXPORT static UclVar CB_CONFIRM_EXTENSION_OKAY;
    libnode_ucll_EXPORT static UclVar CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED;
    libnode_ucll_EXPORT static UclVar CB_PROTOCOL_INIT;
    libnode_ucll_EXPORT static UclVar CB_PROTOCOL_DESTROY;
    libnode_ucll_EXPORT static UclVar CB_ADD_POLL_FD;
    libnode_ucll_EXPORT static UclVar CB_DEL_POLL_FD;
    libnode_ucll_EXPORT static UclVar CB_CHANGE_MODE_POLL_FD;
    libnode_ucll_EXPORT static UclVar TIMEOUT_NO_PENDING;
    libnode_ucll_EXPORT static UclVar TIMEOUT_AWAITING_PROXY_RESPONSE;
    libnode_ucll_EXPORT static UclVar TIMEOUT_AWAITING_CONNECT_RESPONSE;
    libnode_ucll_EXPORT static UclVar TIMEOUT_ESTABLISH_WITH_SERVER;
    libnode_ucll_EXPORT static UclVar TIMEOUT_AWAITING_SERVER_RESPONSE;
    libnode_ucll_EXPORT static UclVar TIMEOUT_AWAITING_PING;
    libnode_ucll_EXPORT static UclVar TIMEOUT_CLOSE_ACK;
    libnode_ucll_EXPORT static UclVar TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE;
    libnode_ucll_EXPORT static UclVar TIMEOUT_SENT_CLIENT_HANDSHAKE;
    libnode_ucll_EXPORT static UclVar TIMEOUT_SSL_ACCEPT;

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

  // - class CurlResult -
  class CurlResult
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar INFO_EFFECTIVE_URL;
    libnode_ucll_EXPORT static UclVar INFO_RESPONSE_CODE;
    libnode_ucll_EXPORT static UclVar INFO_TOTAL_TIME;
    libnode_ucll_EXPORT static UclVar INFO_NAMELOOKUP_TIME;
    libnode_ucll_EXPORT static UclVar INFO_CONNECT_TIME;
    libnode_ucll_EXPORT static UclVar INFO_PRETRANSFER_TIME;
    libnode_ucll_EXPORT static UclVar INFO_SIZE_UPLOAD;
    libnode_ucll_EXPORT static UclVar INFO_SIZE_DOWNLOAD;
    libnode_ucll_EXPORT static UclVar INFO_SPEED_DOWNLOAD;
    libnode_ucll_EXPORT static UclVar INFO_SPEED_UPLOAD;
    libnode_ucll_EXPORT static UclVar INFO_HEADER_SIZE;
    libnode_ucll_EXPORT static UclVar INFO_REQUEST_SIZE;
    libnode_ucll_EXPORT static UclVar INFO_SSL_VERIFYRESULT;
    libnode_ucll_EXPORT static UclVar INFO_FILETIME;
    libnode_ucll_EXPORT static UclVar INFO_CONTENT_LENGTH_DOWNLOAD;
    libnode_ucll_EXPORT static UclVar INFO_CONTENT_LENGTH_UPLOAD;
    libnode_ucll_EXPORT static UclVar INFO_STARTTRANSFER_TIME;
    libnode_ucll_EXPORT static UclVar INFO_CONTENT_TYPE;
    libnode_ucll_EXPORT static UclVar INFO_REDIRECT_TIME;
    libnode_ucll_EXPORT static UclVar INFO_REDIRECT_COUNT;
    libnode_ucll_EXPORT static UclVar INFO_PRIVATE;
    libnode_ucll_EXPORT static UclVar INFO_HTTP_CONNECTCODE;
    libnode_ucll_EXPORT static UclVar INFO_HTTPAUTH_AVAIL;
    libnode_ucll_EXPORT static UclVar INFO_PROXYAUTH_AVAIL;
    libnode_ucll_EXPORT static UclVar INFO_OS_ERRNO;
    libnode_ucll_EXPORT static UclVar INFO_NUM_CONNECTS;
    libnode_ucll_EXPORT static UclVar INFO_SSL_ENGINES;
    libnode_ucll_EXPORT static UclVar INFO_COOKIELIST;
    libnode_ucll_EXPORT static UclVar INFO_LASTSOCKET;
    libnode_ucll_EXPORT static UclVar INFO_FTP_ENTRY_PATH;
    libnode_ucll_EXPORT static UclVar INFO_REDIRECT_URL;
    libnode_ucll_EXPORT static UclVar INFO_PRIMARY_IP;
    libnode_ucll_EXPORT static UclVar INFO_APPCONNECT_TIME;
    libnode_ucll_EXPORT static UclVar INFO_CERTINFO;
    libnode_ucll_EXPORT static UclVar INFO_CONDITION_UNMET;
    libnode_ucll_EXPORT static UclVar INFO_RTSP_SESSION_ID;
    libnode_ucll_EXPORT static UclVar INFO_RTSP_CLIENT_CSEQ;
    libnode_ucll_EXPORT static UclVar INFO_RTSP_SERVER_CSEQ;
    libnode_ucll_EXPORT static UclVar INFO_RTSP_CSEQ_RECV;
    libnode_ucll_EXPORT static UclVar INFO_PRIMARY_PORT;
    libnode_ucll_EXPORT static UclVar INFO_LOCAL_IP;
    libnode_ucll_EXPORT static UclVar INFO_LOCAL_PORT;
    libnode_ucll_EXPORT static UclVar INFO_TLS_SESSION;

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

  // - class Curl -
  class Curl
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi__GET_1;
    static unsigned c_bi_mi__PUT_2;
    static unsigned c_bi_mi__POST_2;
    static unsigned c_bi_mi__DELETE_1;
    static unsigned c_bi_mi__HEAD_1;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar OPT_TIMEOUT;
    libnode_ucll_EXPORT static UclVar OPT_TIMEOUT_MS;
    libnode_ucll_EXPORT static UclVar OPT_HTTPAUTH;
    libnode_ucll_EXPORT static UclVar OPT_USERNAME;
    libnode_ucll_EXPORT static UclVar OPT_PASSWORD;
    libnode_ucll_EXPORT static UclVar AUTH_ANY;
    libnode_ucll_EXPORT static UclVar AUTH_ANYSAFE;
    libnode_ucll_EXPORT static UclVar AUTH_BASIC;
    libnode_ucll_EXPORT static UclVar AUTH_DIGEST;
    libnode_ucll_EXPORT static UclVar AUTH_GSSNEGOTIATE;
    libnode_ucll_EXPORT static UclVar AUTH_NTLM;
    libnode_ucll_EXPORT static UclVar AUTH_DIGEST_IE;
    libnode_ucll_EXPORT static UclVar AUTH_NTLM_WB;
    libnode_ucll_EXPORT static UclVar AUTH_ONLY;
    libnode_ucll_EXPORT static UclVar AUTH_NONE;

    public:
    inline static UclVar _GET(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi__GET_1,op_0);
    }/*}}}*/

    inline static UclVar _PUT(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi__PUT_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar _POST(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi__POST_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar _DELETE(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi__DELETE_1,op_0);
    }/*}}}*/

    inline static UclVar _HEAD(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi__HEAD_1,op_0);
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

  // - class FtpSession -
  class FtpSession
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar TYPE_DIR;
    libnode_ucll_EXPORT static UclVar TYPE_DIR_VERBOSE;
    libnode_ucll_EXPORT static UclVar TYPE_FILE_READ;
    libnode_ucll_EXPORT static UclVar TYPE_FILE_WRITE;
    libnode_ucll_EXPORT static UclVar MODE_ASCII;
    libnode_ucll_EXPORT static UclVar MODE_IMAGE;

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

  inline static UclVar FtpSession(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_FtpSession,c_bi_mni_FtpSession_1,op_0);
  }/*}}}*/

  // - class FtpHandle -
  class FtpHandle
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

  // - class Ssh2Session -
  class Ssh2Session
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar HOSTKEY_HASH_MD5;
    libnode_ucll_EXPORT static UclVar HOSTKEY_HASH_SHA1;

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

  inline static UclVar Ssh2Session(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Ssh2Session,c_bi_mni_Ssh2Session_1,op_0);
  }/*}}}*/

  // - class SftpSession -
  class SftpSession
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar MODE_READ;
    libnode_ucll_EXPORT static UclVar MODE_WRITE;
    libnode_ucll_EXPORT static UclVar MODE_APPEND;
    libnode_ucll_EXPORT static UclVar MODE_CREAT;
    libnode_ucll_EXPORT static UclVar MODE_TRUNC;
    libnode_ucll_EXPORT static UclVar MODE_EXCL;

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

  // - class SftpHandle -
  class SftpHandle
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

  // - class Ssh2Channel -
  class Ssh2Channel
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

  // - class JitContext -
  class JitContext
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    libnode_ucll_EXPORT static UclVar TYPE_I8;
    libnode_ucll_EXPORT static UclVar TYPE_U8;
    libnode_ucll_EXPORT static UclVar TYPE_I16;
    libnode_ucll_EXPORT static UclVar TYPE_U16;
    libnode_ucll_EXPORT static UclVar TYPE_I32;
    libnode_ucll_EXPORT static UclVar TYPE_U32;
    libnode_ucll_EXPORT static UclVar TYPE_I64;
    libnode_ucll_EXPORT static UclVar TYPE_U64;
    libnode_ucll_EXPORT static UclVar TYPE_F32;
    libnode_ucll_EXPORT static UclVar TYPE_F64;

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

  // - class Algo -
  class Algo
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_all_true_1;
    static unsigned c_bi_mi_any_true_1;
    static unsigned c_bi_mi_map_2;
    static unsigned c_bi_mi_reduce_3;
    static unsigned c_bi_mi_filter_2;
    static unsigned c_bi_mi_zip_1;
    static unsigned c_bi_mi_tuple_zip_1;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar all_true(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_all_true_1,op_0);
    }/*}}}*/

    inline static UclVar any_true(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_any_true_1,op_0);
    }/*}}}*/

    inline static UclVar map(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_map_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar reduce(UclVar op_0,UclVar op_1,UclVar op_2)
    {/*{{{*/
      return __static_call_3(c_bi_mi_reduce_3,op_0,op_1,op_2);
    }/*}}}*/

    inline static UclVar filter(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_filter_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar zip(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_zip_1,op_0);
    }/*}}}*/

    inline static UclVar tuple_zip(UclVar op_0)
    {/*{{{*/
      return __static_call_1(c_bi_mi_tuple_zip_1,op_0);
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

  // - class Filter -
  class Filter
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_map_2;
    static unsigned c_bi_mi_filter_2;
    static unsigned c_bi_mi_to_string_0;
    static unsigned c_bi_mi_print_0;

    public:
    inline static UclVar map(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_map_2,op_0,op_1);
    }/*}}}*/

    inline static UclVar filter(UclVar op_0,UclVar op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_filter_2,op_0,op_1);
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

  // - class Range -
  class Range
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

  inline static UclVar Range(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_Range,c_bi_mni_Range_1,op_0);
  }/*}}}*/

  inline static UclVar Range(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_Range,c_bi_mni_Range_2,op_0,op_1);
  }/*}}}*/

  inline static UclVar Range(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __new_object_3(c_bi_class_Range,c_bi_mni_Range_3,op_0,op_1,op_2);
  }/*}}}*/

  // - class Json -
  class Json
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_create_1;
    static unsigned c_bi_mi_create_nice_2;
    static unsigned c_bi_mi_create_nice_3;
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

    inline static UclVar create_nice(UclVar op_0,UclVar op_1,UclVar op_2)
    {/*{{{*/
      return __static_call_3(c_bi_mi_create_nice_3,op_0,op_1,op_2);
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

  // - class Xml -
  class Xml
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_create_1;
    static unsigned c_bi_mi_create_nice_2;
    static unsigned c_bi_mi_create_nice_3;
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

    inline static UclVar create_nice(UclVar op_0,UclVar op_1,UclVar op_2)
    {/*{{{*/
      return __static_call_3(c_bi_mi_create_nice_3,op_0,op_1,op_2);
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

  // - class XmlNode -
  class XmlNode
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

  inline static UclVar XmlNode(UclVar op_0)
  {/*{{{*/
    return __new_object_1(c_bi_class_XmlNode,c_bi_mni_XmlNode_1,op_0);
  }/*}}}*/

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

  inline UclVar operator++(int) // NOLINT
  {/*{{{*/
    return __call_0(c_bi_mni_operator_unary_post_double_plus_0);
  }/*}}}*/

  inline UclVar operator--(int) // NOLINT
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

  inline UclVar classify()
  {/*{{{*/
    return __call_0(c_bi_mni_classify_0);
  }/*}}}*/

  inline UclVar _isnan()
  {/*{{{*/
    return __call_0(c_bi_mni__isnan_0);
  }/*}}}*/

  inline UclVar create(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_create_1,op_0);
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

  inline UclVar contain(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_contain_1,op_0);
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

#ifdef ENABLE_THREAD_TRY_JOIN
  inline UclVar try_join()
  {/*{{{*/
    return __call_0(c_bi_mni_try_join_0);
  }/*}}}*/
#endif

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

  inline UclVar papply(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_papply_1,op_0);
  }/*}}}*/

  inline UclVar size()
  {/*{{{*/
    return __call_0(c_bi_mni_size_0);
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

  inline UclVar pipe()
  {/*{{{*/
    return __call_0(c_bi_mni_pipe_0);
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

  inline UclVar chmod(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_chmod_2,op_0,op_1);
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

  inline UclVar write_close(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_write_close_1,op_0);
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

  inline UclVar read_max(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_read_max_1,op_0);
  }/*}}}*/

  inline UclVar read_close()
  {/*{{{*/
    return __call_0(c_bi_mni_read_close_0);
  }/*}}}*/

  inline UclVar pid()
  {/*{{{*/
    return __call_0(c_bi_mni_pid_0);
  }/*}}}*/

  inline UclVar get_fd()
  {/*{{{*/
    return __call_0(c_bi_mni_get_fd_0);
  }/*}}}*/

  inline UclVar next_item()
  {/*{{{*/
    return __call_0(c_bi_mni_next_item_0);
  }/*}}}*/

  inline UclVar seek(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_seek_2,op_0,op_1);
  }/*}}}*/

  inline UclVar tell()
  {/*{{{*/
    return __call_0(c_bi_mni_tell_0);
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

  inline UclVar sockopt(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __call_3(c_bi_mni_sockopt_3,op_0,op_1,op_2);
  }/*}}}*/

  inline UclVar sockopt(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_sockopt_2,op_0,op_1);
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

  inline UclVar cancel(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_cancel_1,op_0);
  }/*}}}*/

  inline UclVar process()
  {/*{{{*/
    return __call_0(c_bi_mni_process_0);
  }/*}}}*/

  inline UclVar remain()
  {/*{{{*/
    return __call_0(c_bi_mni_remain_0);
  }/*}}}*/

  inline UclVar timeout()
  {/*{{{*/
    return __call_0(c_bi_mni_timeout_0);
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

  inline UclVar add_watch(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_add_watch_2,op_0,op_1);
  }/*}}}*/

  inline UclVar watch_id()
  {/*{{{*/
    return __call_0(c_bi_mni_watch_id_0);
  }/*}}}*/

  inline UclVar mask()
  {/*{{{*/
    return __call_0(c_bi_mni_mask_0);
  }/*}}}*/

  inline UclVar cookie()
  {/*{{{*/
    return __call_0(c_bi_mni_cookie_0);
  }/*}}}*/

  inline UclVar value()
  {/*{{{*/
    return __call_0(c_bi_mni_value_0);
  }/*}}}*/

  inline UclVar nano_sec()
  {/*{{{*/
    return __call_0(c_bi_mni_nano_sec_0);
  }/*}}}*/

  inline UclVar micro_sec()
  {/*{{{*/
    return __call_0(c_bi_mni_micro_sec_0);
  }/*}}}*/

  inline UclVar milli_sec()
  {/*{{{*/
    return __call_0(c_bi_mni_milli_sec_0);
  }/*}}}*/

  inline UclVar seconds()
  {/*{{{*/
    return __call_0(c_bi_mni_seconds_0);
  }/*}}}*/

  inline UclVar minutes()
  {/*{{{*/
    return __call_0(c_bi_mni_minutes_0);
  }/*}}}*/

  inline UclVar hours()
  {/*{{{*/
    return __call_0(c_bi_mni_hours_0);
  }/*}}}*/

  inline UclVar days()
  {/*{{{*/
    return __call_0(c_bi_mni_days_0);
  }/*}}}*/

  inline UclVar datetime()
  {/*{{{*/
    return __call_0(c_bi_mni_datetime_0);
  }/*}}}*/

  inline UclVar pack(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_pack_1,op_0);
  }/*}}}*/

  inline UclVar unpack(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_unpack_1,op_0);
  }/*}}}*/

  inline UclVar code(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_code_2,op_0,op_1);
  }/*}}}*/

  inline UclVar decode(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_decode_2,op_0,op_1);
  }/*}}}*/

  inline UclVar get_source(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_get_source_1,op_0);
  }/*}}}*/

  inline UclVar next_terminal()
  {/*{{{*/
    return __call_0(c_bi_mni_next_terminal_0);
  }/*}}}*/

  inline UclVar old_input_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_old_input_idx_0);
  }/*}}}*/

  inline UclVar input_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_input_idx_0);
  }/*}}}*/

  inline UclVar terminal(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_terminal_2,op_0,op_1);
  }/*}}}*/

  inline UclVar terminal_length()
  {/*{{{*/
    return __call_0(c_bi_mni_terminal_length_0);
  }/*}}}*/

  inline UclVar parse(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_parse_2,op_0,op_1);
  }/*}}}*/

  inline UclVar rule_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_rule_idx_0);
  }/*}}}*/

  inline UclVar rule_body(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_rule_body_1,op_0);
  }/*}}}*/

  inline UclVar threadsafe()
  {/*{{{*/
    return __call_0(c_bi_mni_threadsafe_0);
  }/*}}}*/

  inline UclVar execute(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_execute_1,op_0);
  }/*}}}*/

  inline UclVar prepare(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_prepare_1,op_0);
  }/*}}}*/

  inline UclVar errmsg()
  {/*{{{*/
    return __call_0(c_bi_mni_errmsg_0);
  }/*}}}*/

  inline UclVar bind_blob(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_bind_blob_2,op_0,op_1);
  }/*}}}*/

  inline UclVar step()
  {/*{{{*/
    return __call_0(c_bi_mni_step_0);
  }/*}}}*/

  inline UclVar reset()
  {/*{{{*/
    return __call_0(c_bi_mni_reset_0);
  }/*}}}*/

  inline UclVar reset_clear()
  {/*{{{*/
    return __call_0(c_bi_mni_reset_clear_0);
  }/*}}}*/

  inline UclVar stop()
  {/*{{{*/
    return __call_0(c_bi_mni_stop_0);
  }/*}}}*/

  inline UclVar get_fds()
  {/*{{{*/
    return __call_0(c_bi_mni_get_fds_0);
  }/*}}}*/

  inline UclVar process(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_process_1,op_0);
  }/*}}}*/

  inline UclVar id()
  {/*{{{*/
    return __call_0(c_bi_mni_id_0);
  }/*}}}*/

  inline UclVar url()
  {/*{{{*/
    return __call_0(c_bi_mni_url_0);
  }/*}}}*/

  inline UclVar method()
  {/*{{{*/
    return __call_0(c_bi_mni_method_0);
  }/*}}}*/

  inline UclVar version()
  {/*{{{*/
    return __call_0(c_bi_mni_version_0);
  }/*}}}*/

  inline UclVar upload_data()
  {/*{{{*/
    return __call_0(c_bi_mni_upload_data_0);
  }/*}}}*/

  inline UclVar user_data()
  {/*{{{*/
    return __call_0(c_bi_mni_user_data_0);
  }/*}}}*/

  inline UclVar values(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_values_1,op_0);
  }/*}}}*/

  inline UclVar suspend()
  {/*{{{*/
    return __call_0(c_bi_mni_suspend_0);
  }/*}}}*/

  inline UclVar resume()
  {/*{{{*/
    return __call_0(c_bi_mni_resume_0);
  }/*}}}*/

  inline UclVar queue_response(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_queue_response_2,op_0,op_1);
  }/*}}}*/

  inline UclVar queue_basic_auth_fail_response(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_queue_basic_auth_fail_response_2,op_0,op_1);
  }/*}}}*/

  inline UclVar basic_auth_username_password()
  {/*{{{*/
    return __call_0(c_bi_mni_basic_auth_username_password_0);
  }/*}}}*/

  inline UclVar queue_digest_auth_fail_response(UclVar op_0,UclVar op_1,UclVar op_2,UclVar op_3)
  {/*{{{*/
    return __call_4(c_bi_mni_queue_digest_auth_fail_response_4,op_0,op_1,op_2,op_3);
  }/*}}}*/

  inline UclVar digest_auth_username()
  {/*{{{*/
    return __call_0(c_bi_mni_digest_auth_username_0);
  }/*}}}*/

  inline UclVar digest_auth_check(UclVar op_0,UclVar op_1,UclVar op_2,UclVar op_3)
  {/*{{{*/
    return __call_4(c_bi_mni_digest_auth_check_4,op_0,op_1,op_2,op_3);
  }/*}}}*/

  inline UclVar post_processor(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_post_processor_2,op_0,op_1);
  }/*}}}*/

  inline UclVar add_header(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_add_header_2,op_0,op_1);
  }/*}}}*/

  inline UclVar add_footer(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_add_footer_2,op_0,op_1);
  }/*}}}*/

  inline UclVar client(UclVar op_0,UclVar op_1,UclVar op_2,UclVar op_3)
  {/*{{{*/
    return __call_4(c_bi_mni_client_4,op_0,op_1,op_2,op_3);
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

  inline UclVar encode(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_encode_1,op_0);
  }/*}}}*/

  inline UclVar decode(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_decode_1,op_0);
  }/*}}}*/

  inline UclVar data()
  {/*{{{*/
    return __call_0(c_bi_mni_data_0);
  }/*}}}*/

  inline UclVar info(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_info_1,op_0);
  }/*}}}*/

  inline UclVar _GET(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni__GET_1,op_0);
  }/*}}}*/

  inline UclVar _PUT(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni__PUT_2,op_0,op_1);
  }/*}}}*/

  inline UclVar _POST(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni__POST_2,op_0,op_1);
  }/*}}}*/

  inline UclVar _DELETE(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni__DELETE_1,op_0);
  }/*}}}*/

  inline UclVar _HEAD(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni__HEAD_1,op_0);
  }/*}}}*/

  inline UclVar login(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_login_2,op_0,op_1);
  }/*}}}*/

  inline UclVar get_file(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_get_file_2,op_0,op_1);
  }/*}}}*/

  inline UclVar put_file(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_put_file_2,op_0,op_1);
  }/*}}}*/

  inline UclVar hostkey_hash(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_hostkey_hash_1,op_0);
  }/*}}}*/

  inline UclVar userauth_list(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_userauth_list_1,op_0);
  }/*}}}*/

  inline UclVar userauth_password(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_userauth_password_2,op_0,op_1);
  }/*}}}*/

  inline UclVar userauth_fake_interactive(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_userauth_fake_interactive_2,op_0,op_1);
  }/*}}}*/

  inline UclVar userauth_publickey_fromfile(UclVar op_0,UclVar op_1,UclVar op_2,UclVar op_3)
  {/*{{{*/
    return __call_4(c_bi_mni_userauth_publickey_fromfile_4,op_0,op_1,op_2,op_3);
  }/*}}}*/

  inline UclVar sftp_session()
  {/*{{{*/
    return __call_0(c_bi_mni_sftp_session_0);
  }/*}}}*/

  inline UclVar exec(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_exec_1,op_0);
  }/*}}}*/

  inline UclVar shell()
  {/*{{{*/
    return __call_0(c_bi_mni_shell_0);
  }/*}}}*/

  inline UclVar mkdir(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_mkdir_2,op_0,op_1);
  }/*}}}*/

  inline UclVar open(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __call_3(c_bi_mni_open_3,op_0,op_1,op_2);
  }/*}}}*/

  inline UclVar send_eof()
  {/*{{{*/
    return __call_0(c_bi_mni_send_eof_0);
  }/*}}}*/

  inline UclVar read_stderr()
  {/*{{{*/
    return __call_0(c_bi_mni_read_stderr_0);
  }/*}}}*/

  inline UclVar create_fun(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_create_fun_1,op_0);
  }/*}}}*/

  inline UclVar signature()
  {/*{{{*/
    return __call_0(c_bi_mni_signature_0);
  }/*}}}*/

  inline UclVar call()
  {/*{{{*/
    return __call_0(c_bi_mni_call_0);
  }/*}}}*/

  inline UclVar call(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_call_2,op_0,op_1);
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

  inline UclVar all_true(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_all_true_1,op_0);
  }/*}}}*/

  inline UclVar any_true(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_any_true_1,op_0);
  }/*}}}*/

  inline UclVar map(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_map_2,op_0,op_1);
  }/*}}}*/

  inline UclVar reduce(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __call_3(c_bi_mni_reduce_3,op_0,op_1,op_2);
  }/*}}}*/

  inline UclVar filter(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_filter_2,op_0,op_1);
  }/*}}}*/

  inline UclVar zip(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_zip_1,op_0);
  }/*}}}*/

  inline UclVar tuple_zip(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_tuple_zip_1,op_0);
  }/*}}}*/

  inline UclVar create_nice(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_create_nice_2,op_0,op_1);
  }/*}}}*/

  inline UclVar create_nice(UclVar op_0,UclVar op_1,UclVar op_2)
  {/*{{{*/
    return __call_3(c_bi_mni_create_nice_3,op_0,op_1,op_2);
  }/*}}}*/

  inline UclVar parse(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_parse_1,op_0);
  }/*}}}*/

  inline UclVar update_node_dict()
  {/*{{{*/
    return __call_0(c_bi_mni_update_node_dict_0);
  }/*}}}*/

  inline UclVar escape_texts(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_escape_texts_1,op_0);
  }/*}}}*/

  inline UclVar attr_(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_attr__2,op_0,op_1);
  }/*}}}*/

  inline UclVar node(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_node_1,op_0);
  }/*}}}*/

  inline UclVar node_(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_node__1,op_0);
  }/*}}}*/

  inline UclVar node(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_node_2,op_0,op_1);
  }/*}}}*/

  inline UclVar node_(UclVar op_0,UclVar op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_node__2,op_0,op_1);
  }/*}}}*/

  inline UclVar text_(UclVar op_0)
  {/*{{{*/
    return __call_1(c_bi_mni_text__1,op_0);
  }/*}}}*/

  inline UclVar text()
  {/*{{{*/
    return __call_0(c_bi_mni_text_0);
  }/*}}}*/

  inline UclVar attributes()
  {/*{{{*/
    return __call_0(c_bi_mni_attributes_0);
  }/*}}}*/

  inline UclVar node_dict()
  {/*{{{*/
    return __call_0(c_bi_mni_node_dict_0);
  }/*}}}*/

  inline UclVar nodes()
  {/*{{{*/
    return __call_0(c_bi_mni_nodes_0);
  }/*}}}*/

  inline UclVar texts()
  {/*{{{*/
    return __call_0(c_bi_mni_texts_0);
  }/*}}}*/

  inline UclVar content()
  {/*{{{*/
    return __call_0(c_bi_mni_content_0);
  }/*}}}*/

  /*}}}*/

};/*}}}*/

// - inline methods of class UclVar -

inline void UclVar::BLANK()
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_blank;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (int)0;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::CHAR(char a_value)
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_char;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (char)a_value;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::INTEGER(long long int a_value)
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_integer;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (long long int)a_value;

  location_ptr = it_ptr->get_new_reference(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);
}/*}}}*/

inline void UclVar::FLOAT(double a_value)
{/*{{{*/
  location_s *tmp_location = it_ptr->get_new_location_ptr();
  tmp_location->v_type = c_bi_class_float;
  tmp_location->v_reference_cnt.atomic_set(1);
  tmp_location->v_data_ptr = (double)a_value;

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
  tmp_location->v_data_ptr = (string_s *)string_ptr;

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
  tmp_location->v_data_ptr = (pointer_array_s *)array_ptr;

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

inline interpreter_thread_s *UclVar::__it_ptr()
{/*{{{*/
  return it_ptr;
}/*}}}*/

inline location_s *UclVar::__loc()
{/*{{{*/
  return location_ptr;
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
  tmp_location->v_data_ptr = (unsigned)it_ptr->get_location_value(location_ptr)->v_type;

  UclVar ret_value(&tmp_location);
  it_ptr->release_location_ptr(tmp_location);

  return ret_value;
}/*}}}*/

#endif

