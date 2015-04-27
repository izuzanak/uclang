
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

// - callback prototypes -
typedef class UclVar UclVar;
typedef UclVar (*t_node_callback_0)();
typedef UclVar (*t_node_callback_1)(UclVar);
typedef UclVar (*t_node_callback_2)(UclVar,UclVar);

// - uclang uclvar modules -
enum
{/*{{{*/
  c_uclvar_module_sys = 0,
  c_uclvar_module_containers,
  c_uclvar_module_json,
  c_uclvar_module_websocket,
  c_uclvar_module_jit,

  c_uclvar_module_count,
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

  // - built in class indexes -
  static unsigned c_bi_class_node_callback;
  static unsigned c_bi_class_sys;
  static unsigned c_bi_class_pipe;
  static unsigned c_bi_class_file;

#ifdef ENABLE_CLASS_SOCKET
  static unsigned c_bi_class_socket_addr;
  static unsigned c_bi_class_socket;
#endif

#ifdef ENABLE_CLASS_REGEX
  static unsigned c_bi_class_regex;
#endif

  static unsigned c_bi_class_signal;
  static unsigned c_bi_class_poll;
  static unsigned c_bi_class_timer;
  static unsigned c_bi_class_clock;
  static unsigned c_bi_class_stack;
  static unsigned c_bi_class_queue;
  static unsigned c_bi_class_set;
  static unsigned c_bi_class_list;
  static unsigned c_bi_class_tree;
  static unsigned c_bi_class_dict;
  static unsigned c_bi_class_json;
  static unsigned c_bi_class_ws_context;
  static unsigned c_bi_class_ws_conn;
  static unsigned c_bi_class_ws_client;
  static unsigned c_bi_class_ws_base64;
  static unsigned c_bi_class_jit_context;
  static unsigned c_bi_class_jit_function;

  // - built in method name indexes -
  static unsigned c_bi_mni_binary_equal;
  static unsigned c_bi_mni_binary_plus_equal;
  static unsigned c_bi_mni_binary_minus_equal;
  static unsigned c_bi_mni_binary_asterisk_equal;
  static unsigned c_bi_mni_binary_slash_equal;
  static unsigned c_bi_mni_binary_percent_equal;
  static unsigned c_bi_mni_binary_double_ls_br_equal;
  static unsigned c_bi_mni_binary_double_rs_br_equal;
  static unsigned c_bi_mni_binary_ampersand_equal;
  static unsigned c_bi_mni_binary_pipe_equal;
  static unsigned c_bi_mni_binary_circumflex_equal;
  static unsigned c_bi_mni_binary_double_ampersand;
  static unsigned c_bi_mni_binary_double_pipe;
  static unsigned c_bi_mni_binary_ampersand;
  static unsigned c_bi_mni_binary_pipe;
  static unsigned c_bi_mni_binary_circumflex;
  static unsigned c_bi_mni_binary_double_equal;
  static unsigned c_bi_mni_binary_exclamation_equal;
  static unsigned c_bi_mni_binary_rs_br;
  static unsigned c_bi_mni_binary_ls_br;
  static unsigned c_bi_mni_binary_rs_br_equal;
  static unsigned c_bi_mni_binary_ls_br_equal;
  static unsigned c_bi_mni_binary_double_rs_br;
  static unsigned c_bi_mni_binary_double_ls_br;
  static unsigned c_bi_mni_binary_plus;
  static unsigned c_bi_mni_binary_minus;
  static unsigned c_bi_mni_binary_asterisk;
  static unsigned c_bi_mni_binary_slash;
  static unsigned c_bi_mni_binary_percent;
  static unsigned c_bi_mni_unary_post_double_plus;
  static unsigned c_bi_mni_unary_post_double_minus;
  static unsigned c_bi_mni_unary_pre_double_plus;
  static unsigned c_bi_mni_unary_pre_double_minus;
  static unsigned c_bi_mni_unary_pre_plus;
  static unsigned c_bi_mni_unary_pre_minus;
  static unsigned c_bi_mni_unary_pre_exclamation;
  static unsigned c_bi_mni_unary_pre_tilde;
  static unsigned c_bi_mni_binary_le_br_re_br;
  static unsigned c_bi_mni_compare_1;
  static unsigned c_bi_mni_item_1;
  static unsigned c_bi_mni_first_idx_0;
  static unsigned c_bi_mni_last_idx_0;
  static unsigned c_bi_mni_next_idx_1;
  static unsigned c_bi_mni_prev_idx_1;
  static unsigned c_bi_mni_next_item_0;
  static unsigned c_bi_mni_length_0;
  static unsigned c_bi_mni_to_string_0;
  static unsigned c_bi_mni_print_0;

  // - class BLANK -
  static unsigned c_bi_mni_Blank_0;

  // - class CHAR -
  static unsigned c_bi_mni_Char_0;
  static unsigned c_bi_mni_Char_1;

  // - class INTEGER -
  static unsigned c_bi_mni_Integer_0;
  static unsigned c_bi_mni_Integer_1;
  static unsigned c_bi_mni_Integer_2;

  // - class FLOAT -
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
  static unsigned c_bi_mni_isnan_0;

  // - class STRING -
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

  // - class ARRAY -
  static unsigned c_bi_mni_Array_0;
  static unsigned c_bi_mni_Array_1;
  static unsigned c_bi_mni_clear_0;
  static unsigned c_bi_mni_resize_1;
  static unsigned c_bi_mni_push_1;
  static unsigned c_bi_mni_pop_0;
  static unsigned c_bi_mni_last_0;
  static unsigned c_bi_mni_fill_1;
  static unsigned c_bi_mni_to_string_1;

  // - class ERROR -
  static unsigned c_bi_mni_Error_0;

  // - class EXCEPTION -
  static unsigned c_bi_mni_Exception_0;
  static unsigned c_bi_mni_Exception_1;
  static unsigned c_bi_mni_throw_0;
  static unsigned c_bi_mni_get_type_0;
  static unsigned c_bi_mni_get_value_0;
  static unsigned c_bi_mni_get_file_name_0;
  static unsigned c_bi_mni_get_line_0;
  static unsigned c_bi_mni_error_print_0;

  // - class TYPE -
  static unsigned c_bi_mni_Type_0;
  static unsigned c_bi_mni_Type_1;

  // - class MUTEX -
  static unsigned c_bi_mni_Mutex_0;
  static unsigned c_bi_mni_lock_0;
  static unsigned c_bi_mni_try_lock_0;
  static unsigned c_bi_mni_unlock_0;

  // - class THREAD -
  static unsigned c_bi_mni_join_0;
  static unsigned c_bi_mni_try_join_0;
  static unsigned c_bi_mni_detach_0;
  static unsigned c_bi_mni_yield_0;

  // - class DELEGATE -
  static unsigned c_bi_mni_Delegate_3;
  static unsigned c_bi_mni_call_1;

  // - class BUFFER -
  static unsigned c_bi_mni_size_0;

  // - class NODE_CALLBACK -
  static unsigned c_bi_mni_NodeCallback_2;

  // - class SYS -
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

  // - class PIPE -
  static unsigned c_bi_mni_Pipe_0;
  static unsigned c_bi_mni_Pipe_2;
  static unsigned c_bi_mni_close_0;
  static unsigned c_bi_mni_write_1;
  static unsigned c_bi_mni_flush_0;
  static unsigned c_bi_mni_read_0;
  static unsigned c_bi_mni_readln_0;
  static unsigned c_bi_mni_read_1;
  static unsigned c_bi_mni_get_fd_0;

  // - class FILE -
  static unsigned c_bi_mni_File_0;
  static unsigned c_bi_mni_File_2;

  // - class SOCKET_ADDR -
  static unsigned c_bi_mni_SocketAddr_2;
  static unsigned c_bi_mni_name_0;
  static unsigned c_bi_mni_port_0;

  // - class SOCKET -
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

  // - class REGEX -
  static unsigned c_bi_mni_Regex_0;
  static unsigned c_bi_mni_Regex_1;
  static unsigned c_bi_mni_match_1;
  static unsigned c_bi_mni_match_2;
  static unsigned c_bi_mni_match_from_2;

  // - class SIGNAL -
  static unsigned c_bi_mni_bind_2;
  static unsigned c_bi_mni_unbind_1;
  static unsigned c_bi_mni_send_2;

  // - class POLL -
  static unsigned c_bi_mni_Poll_1;
  static unsigned c_bi_mni_ready_1;
  static unsigned c_bi_mni_poll_1;

  // - class TIMER -
  static unsigned c_bi_mni_Timer_0;
  static unsigned c_bi_mni_schedule_3;
  static unsigned c_bi_mni_process_0;
  static unsigned c_bi_mni_remain_0;

  // - class STACK -
  static unsigned c_bi_mni_Stack_0;
  static unsigned c_bi_mni_Stack_1;
  static unsigned c_bi_mni_items_0;

  // - class QUEUE -
  static unsigned c_bi_mni_Queue_0;
  static unsigned c_bi_mni_Queue_1;
  static unsigned c_bi_mni_insert_1;
  static unsigned c_bi_mni_next_0;

  // - class SET -
  static unsigned c_bi_mni_Set_0;
  static unsigned c_bi_mni_Set_1;
  static unsigned c_bi_mni_contain_1;

  // - class LIST -
  static unsigned c_bi_mni_List_0;
  static unsigned c_bi_mni_List_1;
  static unsigned c_bi_mni_append_1;
  static unsigned c_bi_mni_prepend_1;
  static unsigned c_bi_mni_insert_after_2;
  static unsigned c_bi_mni_insert_before_2;
  static unsigned c_bi_mni_has_idx_1;

  // - class TREE -
  static unsigned c_bi_mni_Tree_0;
  static unsigned c_bi_mni_Tree_1;

  // - class DICT -
  static unsigned c_bi_mni_Dict_0;
  static unsigned c_bi_mni_Dict_1;
  static unsigned c_bi_mni_keys_0;
  static unsigned c_bi_mni_has_key_1;
  static unsigned c_bi_mni_remove_key_1;
  static unsigned c_bi_mni_first_key_0;
  static unsigned c_bi_mni_next_key_1;

  // - class JSON -
  static unsigned c_bi_mni_create_1;
  static unsigned c_bi_mni_create_nice_2;
  static unsigned c_bi_mni_parse_1;

  // - class WS_CONTEXT -
  static unsigned c_bi_mni_WsContext_2;
  static unsigned c_bi_mni_user_data_0;
  static unsigned c_bi_mni_client_4;
  static unsigned c_bi_mni_get_fds_0;
  static unsigned c_bi_mni_process_1;
  static unsigned c_bi_mni_protocol_idx_1;
  static unsigned c_bi_mni_callback_on_writable_1;

  // - class WS_CONN -
  static unsigned c_bi_mni_reason_0;
  static unsigned c_bi_mni_received_data_0;
  static unsigned c_bi_mni_ctx_user_data_0;
  static unsigned c_bi_mni_protocol_name_0;
  static unsigned c_bi_mni_callback_on_writable_0;
  static unsigned c_bi_mni_write_2;

  // - class WS_CLIENT -
  static unsigned c_bi_mni_connected_0;

  // - class WS_BASE64 -
  static unsigned c_bi_mni_encode_1;
  static unsigned c_bi_mni_decode_1;

  // - class JIT_CONTEXT -
  static unsigned c_bi_mni_JitContext_0;
  static unsigned c_bi_mni_create_fun_1;

  // - class JIT_FUNCTION -
  static unsigned c_bi_mni_signature_0;

  // - built in constants name indexes -

  // - class MUTEX -
  static unsigned c_bi_vni_ERROR_INVALID;
  static unsigned c_bi_vni_ERROR_DEADLOCK;
  static unsigned c_bi_vni_ERROR_BUSY;
  static unsigned c_bi_vni_ERROR_PERMISSION;

  // - class THREAD -
  static unsigned c_bi_vni_ERROR_AGAIN;
  static unsigned c_bi_vni_ERROR_SEARCH;

  // - class SYS -
  static unsigned c_bi_vni_NAME;
  static unsigned c_bi_vni_SEP;

  // - class FILE -
  static unsigned c_bi_vni_stdin;
  static unsigned c_bi_vni_stdout;
  static unsigned c_bi_vni_stderr;

  // - class SOCKET -
  static unsigned c_bi_vni_AF_UNIX;
  static unsigned c_bi_vni_AF_FILE;
  static unsigned c_bi_vni_AF_INET;
  static unsigned c_bi_vni_SOCK_STREAM;
  static unsigned c_bi_vni_SOCK_DGRAM;
  static unsigned c_bi_vni_SOCK_RAW;
  static unsigned c_bi_vni_SO_RCVTIMEO;
  static unsigned c_bi_vni_SO_SNDTIMEO;

  // - class SIGNAL -
  static unsigned c_bi_vni__SIGINT;
  static unsigned c_bi_vni__SIGTERM;
  static unsigned c_bi_vni__SIGHUP;

  // - class POLL -
  static unsigned c_bi_vni_POLLIN;
  static unsigned c_bi_vni_POLLPRI;
  static unsigned c_bi_vni_POLLOUT;
  static unsigned c_bi_vni_POLLERR;
  static unsigned c_bi_vni_POLLHUP;
  static unsigned c_bi_vni_POLLNVAL;

  // - class WS_CONTEXT -
  static unsigned c_bi_vni_PORT_NO_LISTEN;

  // - class WS_CONN -
  static unsigned c_bi_vni_WRITE_TEXT;
  static unsigned c_bi_vni_WRITE_BINARY;
  static unsigned c_bi_vni_WRITE_CONTINUATION;
  static unsigned c_bi_vni_WRITE_HTTP;
  static unsigned c_bi_vni_WRITE_CLOSE;
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

  // - class JIT_CONTEXT -
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
  inline void ARRAY(unsigned a_size,UclVar a_array[]);

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
  inline UclVar(unsigned a_size,UclVar a_array[])     { ARRAY(a_size,a_array); }

  inline char __char();
  inline long long int __int();
  inline double __float();
  inline const char *__str();

  inline UclVar __type();

  inline static UclVar Delegate(t_node_callback_0 cb_ptr)
  {/*{{{*/
    const UclVar parm_cnt(0);
    UclVar callback = __new_object_2(c_bi_class_node_callback,c_bi_mni_NodeCallback_2,UclVar((long long int)cb_ptr),parm_cnt);
    return __new_object_3(c_bi_class_delegate,c_bi_mni_Delegate_3,callback,UclVar("call"),parm_cnt);
  }/*}}}*/

  inline static UclVar Delegate(t_node_callback_1 cb_ptr)
  {/*{{{*/
    const UclVar parm_cnt(1);
    UclVar callback = __new_object_2(c_bi_class_node_callback,c_bi_mni_NodeCallback_2,UclVar((long long int)cb_ptr),parm_cnt);
    return __new_object_3(c_bi_class_delegate,c_bi_mni_Delegate_3,callback,UclVar("call"),parm_cnt);
  }/*}}}*/

  inline static UclVar Delegate(t_node_callback_2 cb_ptr)
  {/*{{{*/
    const UclVar parm_cnt(2);
    UclVar callback = __new_object_2(c_bi_class_node_callback,c_bi_mni_NodeCallback_2,UclVar((long long int)cb_ptr),parm_cnt);
    return __new_object_3(c_bi_class_delegate,c_bi_mni_Delegate_3,callback,UclVar("call"),parm_cnt);
  }/*}}}*/

  // - class BLANK -
  inline static UclVar Blank()
  {/*{{{*/
    return __new_object_0(c_bi_class_blank,c_bi_mni_Blank_0);
  }/*}}}*/

  // - class CHAR -
  inline static UclVar Char()
  {/*{{{*/
    return __new_object_0(c_bi_class_char,c_bi_mni_Char_0);
  }/*}}}*/

  inline static UclVar Char(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_char,c_bi_mni_Char_1,a_op);
  }/*}}}*/

  // - class INTEGER -
  inline static UclVar Integer()
  {/*{{{*/
    return __new_object_0(c_bi_class_integer,c_bi_mni_Integer_0);
  }/*}}}*/

  inline static UclVar Integer(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_integer,c_bi_mni_Integer_1,a_op);
  }/*}}}*/

  inline static UclVar Integer(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_integer,c_bi_mni_Integer_2,a_op,a_op_1);
  }/*}}}*/

  // - class FLOAT -
  inline static UclVar Float()
  {/*{{{*/
    return __new_object_0(c_bi_class_float,c_bi_mni_Float_0);
  }/*}}}*/

  inline static UclVar Float(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_float,c_bi_mni_Float_1,a_op);
  }/*}}}*/

  // - class STRING -
  inline static UclVar String()
  {/*{{{*/
    return __new_object_0(c_bi_class_string,c_bi_mni_String_0);
  }/*}}}*/

  inline static UclVar String(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_string,c_bi_mni_String_1,a_op);
  }/*}}}*/

  // - class ARRAY -
  inline static UclVar Array()
  {/*{{{*/
    return __new_object_0(c_bi_class_array,c_bi_mni_Array_0);
  }/*}}}*/

  inline static UclVar Array(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_array,c_bi_mni_Array_1,a_op);
  }/*}}}*/

  // - class ERROR -
  inline static UclVar Error()
  {/*{{{*/
    return __new_object_0(c_bi_class_error,c_bi_mni_Error_0);
  }/*}}}*/

  // - class EXCEPTION -
  inline static UclVar Exception()
  {/*{{{*/
    return __new_object_0(c_bi_class_exception,c_bi_mni_Exception_0);
  }/*}}}*/

  inline static UclVar Exception(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_exception,c_bi_mni_Exception_1,a_op);
  }/*}}}*/

  // - class TYPE -
  inline static UclVar Type()
  {/*{{{*/
    return __new_object_0(c_bi_class_type,c_bi_mni_Type_0);
  }/*}}}*/

  inline static UclVar Type(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_type,c_bi_mni_Type_1,a_op);
  }/*}}}*/

  // - class MUTEX -
  class Mutex
  {/*{{{*/
    public:
    static UclVar ERROR_INVALID;
    static UclVar ERROR_DEADLOCK;
    static UclVar ERROR_BUSY;
    static UclVar ERROR_PERMISSION;
  };/*}}}*/

  inline static UclVar Mutex()
  {/*{{{*/
    return __new_object_0(c_bi_class_mutex,c_bi_mni_Mutex_0);
  }/*}}}*/

  // - class THREAD -
  class Thread
  {/*{{{*/
    public:
    static UclVar ERROR_AGAIN;
    static UclVar ERROR_SEARCH;
    static UclVar ERROR_INVALID;
    static UclVar ERROR_DEADLOCK;
    static UclVar ERROR_BUSY;
  };/*}}}*/

  // - class SYS -
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

    public:
    static UclVar NAME;
    static UclVar SEP;

    inline static UclVar sleep(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_sleep_1,a_op);
    }/*}}}*/

    inline static UclVar srand(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_srand_1,a_op);
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

    inline static UclVar system(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_system_1,a_op);
    }/*}}}*/

    inline static UclVar exit(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_exit_1,a_op);
    }/*}}}*/

    inline static UclVar open(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_open_2,a_op,a_op_1);
    }/*}}}*/

    inline static UclVar popen(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_popen_2,a_op,a_op_1);
    }/*}}}*/

    inline static UclVar mkdir(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_mkdir_1,a_op);
    }/*}}}*/

    inline static UclVar rmdir(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_rmdir_1,a_op);
    }/*}}}*/

    inline static UclVar chdir(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_chdir_1,a_op);
    }/*}}}*/

    inline static UclVar listdir(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_listdir_1,a_op);
    }/*}}}*/

    inline static UclVar mkfifo(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_mkfifo_1,a_op);
    }/*}}}*/

    inline static UclVar remove(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_remove_1,a_op);
    }/*}}}*/

    inline static UclVar rename(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_rename_2,a_op,a_op_1);
    }/*}}}*/

    inline static UclVar getcwd()
    {/*{{{*/
      return __static_call_0(c_bi_mi_getcwd_0);
    }/*}}}*/

    inline static UclVar setenv(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_setenv_2,a_op,a_op_1);
    }/*}}}*/

    inline static UclVar getenv(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_getenv_1,a_op);
    }/*}}}*/

    inline static UclVar is_file(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_is_file_1,a_op);
    }/*}}}*/

    inline static UclVar is_dir(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_is_dir_1,a_op);
    }/*}}}*/

    inline static UclVar size(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_size_1,a_op);
    }/*}}}*/

    inline static UclVar time()
    {/*{{{*/
      return __static_call_0(c_bi_mi_time_0);
    }/*}}}*/

  };/*}}}*/

  // - class PIPE -
  inline static UclVar Pipe()
  {/*{{{*/
    return __new_object_0(c_bi_class_pipe,c_bi_mni_Pipe_0);
  }/*}}}*/

  inline static UclVar Pipe(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_pipe,c_bi_mni_Pipe_2,a_op,a_op_1);
  }/*}}}*/

  // - class FILE -
  class File
  {/*{{{*/
    public:
    static UclVar stdin;
    static UclVar stdout;
    static UclVar stderr;
  };/*}}}*/

  inline static UclVar File()
  {/*{{{*/
    return __new_object_0(c_bi_class_file,c_bi_mni_File_0);
  }/*}}}*/

  inline static UclVar File(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_file,c_bi_mni_File_2,a_op,a_op_1);
  }/*}}}*/

#ifdef ENABLE_CLASS_SOCKET
  // - class SOCKET_ADDR -
  inline static UclVar SocketAddr(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_socket_addr,c_bi_mni_SocketAddr_2,a_op,a_op_1);
  }/*}}}*/

  // - class SOCKET -
  class Socket
  {/*{{{*/
    public:
    static UclVar AF_UNIX;
    static UclVar AF_FILE;
    static UclVar AF_INET;
    static UclVar SOCK_STREAM;
    static UclVar SOCK_DGRAM;
    static UclVar SOCK_RAW;
    static UclVar SO_RCVTIMEO;
    static UclVar SO_SNDTIMEO;
  };/*}}}*/

  inline static UclVar Socket()
  {/*{{{*/
    return __new_object_0(c_bi_class_socket,c_bi_mni_Socket_0);
  }/*}}}*/

  inline static UclVar Socket(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_socket,c_bi_mni_Socket_2,a_op,a_op_1);
  }/*}}}*/
#endif

#ifdef ENABLE_CLASS_REGEX
  // - class REGEX -
  inline static UclVar Regex()
  {/*{{{*/
    return __new_object_0(c_bi_class_regex,c_bi_mni_Regex_0);
  }/*}}}*/

  inline static UclVar Regex(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_regex,c_bi_mni_Regex_1,a_op);
  }/*}}}*/
#endif

  // - class SIGNAL -
  class Signal
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_bind_2;
    static unsigned c_bi_mi_unbind_1;
    static unsigned c_bi_mi_send_2;

    public:
    static UclVar _SIGINT;
    static UclVar _SIGTERM;
    static UclVar _SIGHUP;

    inline static UclVar bind(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_bind_2,a_op,a_op_1);
    }/*}}}*/

    inline static UclVar unbind(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_unbind_1,a_op);
    }/*}}}*/

    inline static UclVar send(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_send_2,a_op,a_op_1);
    }/*}}}*/

  };/*}}}*/

  // - class POLL -
  class Poll
  {/*{{{*/
    public:
    static UclVar POLLIN;
    static UclVar POLLPRI;
    static UclVar POLLOUT;
    static UclVar POLLERR;
    static UclVar POLLHUP;
    static UclVar POLLNVAL;
  };/*}}}*/

  inline static UclVar Poll(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_poll,c_bi_mni_Poll_1,a_op);
  }/*}}}*/

  // - class TIMER -
  inline static UclVar Timer()
  {/*{{{*/
    return __new_object_0(c_bi_class_timer,c_bi_mni_Timer_0);
  }/*}}}*/

  // - class STACK -
  inline static UclVar Stack()
  {/*{{{*/
    return __new_object_0(c_bi_class_stack,c_bi_mni_Stack_0);
  }/*}}}*/

  inline static UclVar Stack(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_stack,c_bi_mni_Stack_1,a_op);
  }/*}}}*/

  // - class QUEUE -
  inline static UclVar Queue()
  {/*{{{*/
    return __new_object_0(c_bi_class_queue,c_bi_mni_Queue_0);
  }/*}}}*/

  inline static UclVar Queue(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_queue,c_bi_mni_Queue_1,a_op);
  }/*}}}*/

  // - class SET -
  inline static UclVar Set()
  {/*{{{*/
    return __new_object_0(c_bi_class_set,c_bi_mni_Set_0);
  }/*}}}*/

  inline static UclVar Set(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_set,c_bi_mni_Set_1,a_op);
  }/*}}}*/

  // - class LIST -
  inline static UclVar List()
  {/*{{{*/
    return __new_object_0(c_bi_class_list,c_bi_mni_List_0);
  }/*}}}*/

  inline static UclVar List(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_list,c_bi_mni_List_1,a_op);
  }/*}}}*/

  // - class TREE -
  inline static UclVar Tree()
  {/*{{{*/
    return __new_object_0(c_bi_class_tree,c_bi_mni_Tree_0);
  }/*}}}*/

  inline static UclVar Tree(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_tree,c_bi_mni_Tree_1,a_op);
  }/*}}}*/

  // - class DICT - 
  inline static UclVar Dict()
  {/*{{{*/
    return __new_object_0(c_bi_class_dict,c_bi_mni_Dict_0);
  }/*}}}*/

  inline static UclVar Dict(UclVar a_op)
  {/*{{{*/
    return __new_object_1(c_bi_class_dict,c_bi_mni_Dict_1,a_op);
  }/*}}}*/

  // - class JSON -
  class Json
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_create_1;
    static unsigned c_bi_mi_create_nice_2;
    static unsigned c_bi_mi_parse_1;

    public:
    inline static UclVar create(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_create_1,a_op);
    }/*}}}*/

    inline static UclVar create_nice(UclVar a_op,UclVar a_op_1)
    {/*{{{*/
      return __static_call_2(c_bi_mi_create_nice_2,a_op,a_op_1);
    }/*}}}*/

    inline static UclVar parse(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_parse_1,a_op);
    }/*}}}*/
  };/*}}}*/

  // - class WS_CONTEXT -
  inline static UclVar WsContext(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __new_object_2(c_bi_class_ws_context,c_bi_mni_WsContext_2,a_op,a_op_1);
  }/*}}}*/

  class WsContext
  {/*{{{*/
  public:
    static UclVar PORT_NO_LISTEN;
  };/*}}}*/

  // - class WS_CONN -
  class WsConn
  {/*{{{*/
  public:
    static UclVar WRITE_TEXT;
    static UclVar WRITE_BINARY;
    static UclVar WRITE_CONTINUATION;
    static UclVar WRITE_HTTP;
    static UclVar WRITE_CLOSE;
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
  };/*}}}*/

  // - class WS_BASE64 -
  class WsBase64
  {/*{{{*/
    friend class UclVar;
    protected:
    static unsigned c_bi_mi_encode_1;
    static unsigned c_bi_mi_decode_1;

    public:
    inline static UclVar encode(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_encode_1,a_op);
    }/*}}}*/

    inline static UclVar decode(UclVar a_op)
    {/*{{{*/
      return __static_call_1(c_bi_mi_decode_1,a_op);
    }/*}}}*/

  };/*}}}*/

  // - class JIT_CONTEXT -
  inline static UclVar JitContext()
  {/*{{{*/
    return __new_object_0(c_bi_class_jit_context,c_bi_mni_JitContext_0);
  }/*}}}*/

  class JitContext
  {/*{{{*/
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
  };/*}}}*/

  // - operator methods -
  /*{{{*/
  inline UclVar operator=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_equal,a_op);
  }/*}}}*/

  inline UclVar operator+=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_plus_equal,a_op);
  }/*}}}*/

  inline UclVar operator-=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_minus_equal,a_op);
  }/*}}}*/

  inline UclVar operator*=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_asterisk_equal,a_op);
  }/*}}}*/

  inline UclVar operator/=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_slash_equal,a_op);
  }/*}}}*/

  inline UclVar operator%=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_percent_equal,a_op);
  }/*}}}*/

  inline UclVar operator<<=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_ls_br_equal,a_op);
  }/*}}}*/

  inline UclVar operator>>=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_rs_br_equal,a_op);
  }/*}}}*/

  inline UclVar operator&=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_ampersand_equal,a_op);
  }/*}}}*/

  inline UclVar operator|=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_pipe_equal,a_op);
  }/*}}}*/

  inline UclVar operator^=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_circumflex_equal,a_op);
  }/*}}}*/

  inline UclVar operator&&(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_ampersand,a_op);
  }/*}}}*/

  inline UclVar operator||(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_pipe,a_op);
  }/*}}}*/

  inline UclVar operator&(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_ampersand,a_op);
  }/*}}}*/

  inline UclVar operator|(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_pipe,a_op);
  }/*}}}*/

  inline UclVar operator^(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_circumflex,a_op);
  }/*}}}*/

  inline UclVar operator==(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_equal,a_op);
  }/*}}}*/

  inline UclVar operator!=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_exclamation_equal,a_op);
  }/*}}}*/

  inline UclVar operator>(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_rs_br,a_op);
  }/*}}}*/

  inline UclVar operator<(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_ls_br,a_op);
  }/*}}}*/

  inline UclVar operator>=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_rs_br_equal,a_op);
  }/*}}}*/

  inline UclVar operator<=(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_ls_br_equal,a_op);
  }/*}}}*/

  inline UclVar operator>>(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_rs_br,a_op);
  }/*}}}*/

  inline UclVar operator<<(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_double_ls_br,a_op);
  }/*}}}*/

  inline UclVar operator+(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_plus,a_op);
  }/*}}}*/

  inline UclVar operator-(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_minus,a_op);
  }/*}}}*/

  inline UclVar operator*(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_asterisk,a_op);
  }/*}}}*/

  inline UclVar operator/(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_slash,a_op);
  }/*}}}*/

  inline UclVar operator%(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_percent,a_op);
  }/*}}}*/

  inline UclVar operator++(int)
  {/*{{{*/
    return __call_0(c_bi_mni_unary_post_double_plus);
  }/*}}}*/

  inline UclVar operator--(int)
  {/*{{{*/
    return __call_0(c_bi_mni_unary_post_double_minus);
  }/*}}}*/

  inline UclVar operator++()
  {/*{{{*/
    return __call_0(c_bi_mni_unary_pre_double_plus);
  }/*}}}*/

  inline UclVar operator--()
  {/*{{{*/
    return __call_0(c_bi_mni_unary_pre_double_minus);
  }/*}}}*/

  inline UclVar operator+()
  {/*{{{*/
    return __call_0(c_bi_mni_unary_pre_plus);
  }/*}}}*/

  inline UclVar operator-()
  {/*{{{*/
    return __call_0(c_bi_mni_unary_pre_minus);
  }/*}}}*/

  inline UclVar operator!()
  {/*{{{*/
    return __call_0(c_bi_mni_unary_pre_exclamation);
  }/*}}}*/

  inline UclVar operator~()
  {/*{{{*/
    return __call_0(c_bi_mni_unary_pre_tilde);
  }/*}}}*/

  inline UclVar operator[](UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_binary_le_br_re_br,a_op);
  }/*}}}*/
  /*}}}*/

  inline UclVar compare(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_compare_1,a_op);
  }/*}}}*/

  inline UclVar item(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_item_1,a_op);
  }/*}}}*/

  inline UclVar first_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_first_idx_0);
  }/*}}}*/

  inline UclVar last_idx()
  {/*{{{*/
    return __call_0(c_bi_mni_last_idx_0);
  }/*}}}*/

  inline UclVar next_idx(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_next_idx_1,a_op);
  }/*}}}*/

  inline UclVar prev_idx(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_prev_idx_1,a_op);
  }/*}}}*/

  inline UclVar next_item()
  {/*{{{*/
    return __call_0(c_bi_mni_next_item_0);
  }/*}}}*/

  inline UclVar length()
  {/*{{{*/
    return __call_0(c_bi_mni_length_0);
  }/*}}}*/

  inline UclVar to_string()
  {/*{{{*/
    return __call_0(c_bi_mni_to_string_0);
  }/*}}}*/

  inline UclVar print()
  {/*{{{*/
    return __call_0(c_bi_mni_print_0);
  }/*}}}*/

  inline UclVar get_idx(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_get_idx_1,a_op);
  }/*}}}*/

  inline UclVar get_idxs(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_get_idxs_1,a_op);
  }/*}}}*/

  inline UclVar replace(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_replace_2,a_op,a_op_1);
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

  inline UclVar pow(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_pow_1,a_op);
  }/*}}}*/

  inline UclVar sqrt()
  {/*{{{*/
    return __call_0(c_bi_mni_sqrt_0);
  }/*}}}*/

  inline UclVar cbrt()
  {/*{{{*/
    return __call_0(c_bi_mni_cbrt_0);
  }/*}}}*/

  inline UclVar hypot(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_hypot_1,a_op);
  }/*}}}*/

  inline UclVar _isnan()
  {/*{{{*/
    return __call_0(c_bi_mni_isnan_0);
  }/*}}}*/

  inline UclVar split(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_split_1,a_op);
  }/*}}}*/

  inline UclVar join(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_join_1,a_op);
  }/*}}}*/

  inline UclVar head(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_head_1,a_op);
  }/*}}}*/

  inline UclVar tail(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_tail_1,a_op);
  }/*}}}*/

  inline UclVar range(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_range_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar clear()
  {/*{{{*/
    return __call_0(c_bi_mni_clear_0);
  }/*}}}*/

  inline UclVar resize(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_resize_1,a_op);
  }/*}}}*/

  inline UclVar push(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_push_1,a_op);
  }/*}}}*/

  inline UclVar pop()
  {/*{{{*/
    return __call_0(c_bi_mni_pop_0);
  }/*}}}*/

  inline UclVar last()
  {/*{{{*/
    return __call_0(c_bi_mni_last_0);
  }/*}}}*/

  inline UclVar fill(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_fill_1,a_op);
  }/*}}}*/

  inline UclVar to_string(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_to_string_1,a_op);
  }/*}}}*/

  inline UclVar __throw()
  {/*{{{*/
    return __call_0(c_bi_mni_throw_0);
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

  inline UclVar call(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_call_1,a_op);
  }/*}}}*/

  inline UclVar size()
  {/*{{{*/
    return __call_0(c_bi_mni_size_0);
  }/*}}}*/

  inline UclVar close()
  {/*{{{*/
    return __call_0(c_bi_mni_close_0);
  }/*}}}*/

  inline UclVar write(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_write_1,a_op);
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

  inline UclVar read(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_read_1,a_op);
  }/*}}}*/

  inline UclVar get_fd()
  {/*{{{*/
    return __call_0(c_bi_mni_get_fd_0);
  }/*}}}*/

  inline UclVar name()
  {/*{{{*/
    return __call_0(c_bi_mni_name_0);
  }/*}}}*/

  inline UclVar port()
  {/*{{{*/
    return __call_0(c_bi_mni_port_0);
  }/*}}}*/

  inline UclVar listen(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_listen_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar accept()
  {/*{{{*/
    return __call_0(c_bi_mni_accept_0);
  }/*}}}*/

  inline UclVar accept_nonblock()
  {/*{{{*/
    return __call_0(c_bi_mni_accept_nonblock_0);
  }/*}}}*/

  inline UclVar connect(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_connect_1,a_op);
  }/*}}}*/

  inline UclVar bind(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_bind_1,a_op);
  }/*}}}*/

  inline UclVar sendto(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_sendto_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar recvfrom()
  {/*{{{*/
    return __call_0(c_bi_mni_recvfrom_0);
  }/*}}}*/

  inline UclVar set_timeout(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_set_timeout_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar read_nonblock()
  {/*{{{*/
    return __call_0(c_bi_mni_read_nonblock_0);
  }/*}}}*/

  inline UclVar match(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_match_1,a_op);
  }/*}}}*/

  inline UclVar match(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_match_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar match_from(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_match_from_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar ready(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_ready_1,a_op);
  }/*}}}*/

  inline UclVar poll(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_poll_1,a_op);
  }/*}}}*/

  inline UclVar schedule(UclVar a_op,UclVar a_op_1,UclVar a_op_2)
  {/*{{{*/
    return __call_3(c_bi_mni_schedule_3,a_op,a_op_1,a_op_2);
  }/*}}}*/

  inline UclVar process()
  {/*{{{*/
    return __call_0(c_bi_mni_process_0);
  }/*}}}*/

  inline UclVar remain()
  {/*{{{*/
    return __call_0(c_bi_mni_remain_0);
  }/*}}}*/

  inline UclVar items()
  {/*{{{*/
    return __call_0(c_bi_mni_items_0);
  }/*}}}*/

  inline UclVar insert(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_insert_1,a_op);
  }/*}}}*/

  inline UclVar next()
  {/*{{{*/
    return __call_0(c_bi_mni_next_0);
  }/*}}}*/

  inline UclVar remove(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_remove_1,a_op);
  }/*}}}*/

  inline UclVar contain(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_contain_1,a_op);
  }/*}}}*/

  inline UclVar append(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_append_1,a_op);
  }/*}}}*/

  inline UclVar prepend(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_prepend_1,a_op);
  }/*}}}*/

  inline UclVar insert_after(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_insert_after_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar insert_before(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_insert_before_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar has_idx(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_has_idx_1,a_op);
  }/*}}}*/

  inline UclVar keys()
  {/*{{{*/
    return __call_0(c_bi_mni_keys_0);
  }/*}}}*/

  inline UclVar has_key(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_has_key_1,a_op);
  }/*}}}*/

  inline UclVar remove_key(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_remove_key_1,a_op);
  }/*}}}*/

  inline UclVar first_key()
  {/*{{{*/
    return __call_0(c_bi_mni_first_key_0);
  }/*}}}*/

  inline UclVar next_key(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_next_key_1,a_op);
  }/*}}}*/

  inline UclVar user_data()
  {/*{{{*/
    return __call_0(c_bi_mni_user_data_0);
  }/*}}}*/

  inline UclVar client(UclVar a_op,UclVar a_op_1,UclVar a_op_2,UclVar a_op_3)
  {/*{{{*/
    return __call_4(c_bi_mni_client_4,a_op,a_op_1,a_op_2,a_op_3);
  }/*}}}*/

  inline UclVar get_fds()
  {/*{{{*/
    return __call_0(c_bi_mni_get_fds_0);
  }/*}}}*/

  inline UclVar process(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_process_1,a_op);
  }/*}}}*/

  inline UclVar protocol_idx(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_protocol_idx_1,a_op);
  }/*}}}*/

  inline UclVar callback_on_writable(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_callback_on_writable_1,a_op);
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

  inline UclVar write(UclVar a_op,UclVar a_op_1)
  {/*{{{*/
    return __call_2(c_bi_mni_write_2,a_op,a_op_1);
  }/*}}}*/

  inline UclVar connected()
  {/*{{{*/
    return __call_0(c_bi_mni_connected_0);
  }/*}}}*/

  inline UclVar create_fun(UclVar a_op)
  {/*{{{*/
    return __call_1(c_bi_mni_create_fun_1,a_op);
  }/*}}}*/

  inline UclVar signature()
  {/*{{{*/
    return __call_0(c_bi_mni_signature_0);
  }/*}}}*/

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

inline void UclVar::ARRAY(unsigned a_size,UclVar a_array[])
{/*{{{*/
  pointer_array_s *array_ptr = it_ptr->get_new_array_ptr();

  if (a_size > 0)
  {
    UclVar *ucv_ptr = a_array;
    UclVar *ucv_ptr_end = ucv_ptr + a_size;
    
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

  if (tmp_location->v_type != c_bi_class_char)
  {
    throw std::string("Conversion error");
  }

  return (char)tmp_location->v_data_ptr;
}/*}}}*/

inline long long int UclVar::__int()
{/*{{{*/
  long long int value;

  if (!it_ptr->retrieve_integer(it_ptr->get_location_value(location_ptr),value))
  {
    throw std::string("Conversion error");
  }

  return value;
}/*}}}*/

inline double UclVar::__float()
{/*{{{*/
  double value;

  if (!it_ptr->retrieve_float(it_ptr->get_location_value(location_ptr),value))
  {
    throw std::string("Conversion error");
  }

  return value;
}/*}}}*/

inline const char *UclVar::__str()
{/*{{{*/
  location_s *tmp_location = it_ptr->get_location_value(location_ptr);

  if (tmp_location->v_type != c_bi_class_string)
  {
    throw std::string("Conversion error");
  }

  return ((string_s *)tmp_location->v_data_ptr)->data;
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

