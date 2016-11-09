
#ifndef __SYS_MODULE_H
#define __SYS_MODULE_H

@begin
include "ucl_sys.h"
@end

// - SYS indexes of built in classes -
extern unsigned c_bi_class_sys;
extern unsigned c_bi_class_pipe;
extern unsigned c_bi_class_file;

#ifdef ENABLE_CLASS_SOCKET
extern unsigned c_bi_class_socket_addr;
extern unsigned c_bi_class_socket;
#endif

#ifdef ENABLE_CLASS_REGEX
extern unsigned c_bi_class_regex;
#endif

extern unsigned c_bi_class_signal;

#ifdef ENABLE_CLASS_POLL
extern unsigned c_bi_class_poll;
#endif

extern unsigned c_bi_class_timer;

#ifdef ENABLE_CLASS_CLOCK
extern unsigned c_bi_class_clock;
#endif

// - SYS module -
extern built_in_module_s module;

// - SYS classes -
extern built_in_class_s *sys_classes[];

// - SYS error identifiers -
enum
{
  c_error_SYS_DIR_CREATE_ERROR = 0,
  c_error_SYS_DIR_REMOVE_ERROR,
  c_error_SYS_DIR_CHANGE_ERROR,
  c_error_SYS_DIR_LIST_ERROR,

  c_error_SYS_MAKE_FIFO_ERROR,
  c_error_SYS_FILE_REMOVE_ERROR,
  c_error_SYS_FILE_RENAME_ERROR,
  c_error_SYS_FILE_DOES_NOT_EXIST,
  c_error_SYS_SETENV_ERROR,
  c_error_SYS_GET_TIME_ERROR,

  c_error_PIPE_CREATE_ERROR,
  c_error_PIPE_OPEN_ERROR,
  c_error_PIPE_CLOSE_ERROR,
  c_error_PIPE_NOT_OPENED,

  c_error_FILE_OPEN_ERROR,
  c_error_FILE_SEEK_ERROR,
  c_error_FILE_TELL_ERROR,
  c_error_FILE_CLOSE_ERROR,
  c_error_FILE_NOT_OPENED,

#ifdef ENABLE_CLASS_SOCKET
  c_error_SOCKET_ADDRESS_RESOLVE_ERROR,
  c_error_SOCKET_ADDRESS_UNKNOWN_FORMAT,

  c_error_SOCKET_CREATE_ERROR,
  c_error_SOCKET_CLOSE_ERROR,
  c_error_SOCKET_NOT_OPENED,
  c_error_SOCKET_UNKNOWN_DOMAIN,
  c_error_SOCKET_BIND_ERROR,
  c_error_SOCKET_LISTEN_ERROR,
  c_error_SOCKET_ACCEPT_ERROR,
  c_error_SOCKET_CONNECT_ERROR,
  c_error_SOCKET_SENDTO_ERROR,
  c_error_SOCKET_RECVFROM_ERROR,
  c_error_SOCKET_UDP_MAX_MSG_SIZE_EXCEEDED,

  c_error_SOCKET_SET_TIMEOUT_ERROR,
#endif

  c_error_STREAM_WRITE_ERROR,
  c_error_STREAM_FLUSH_ERROR,
  c_error_STREAM_READ_ERROR,
  c_error_STREAM_READ_NEGATIVE_BYTE_COUNT,
  c_error_STREAM_NOT_OPENED,

  c_error_FD_WRITE_ERROR,
  c_error_FD_READ_ERROR,
  c_error_FD_READ_NEGATIVE_BYTE_COUNT,
  c_error_FD_NOT_OPENED,

#ifdef ENABLE_CLASS_REGEX
  c_error_REGEX_COMPILE_ERROR,
  c_error_REGEX_NOT_COMPILED,
  c_error_REGEX_WRONG_MATCH_COUNT,
  c_error_REGEX_WRONG_MATCH_OFFSET,
  c_error_REGEX_STRING_SPLIT_EMPTY_MATCH,
#endif

  c_error_SIGNAL_WRONG_SIGNAL_NUMBER,
  c_error_SIGNAL_WRONG_DELEGATE_PARAMETER_COUNT,
  c_error_SIGNAL_CANNOT_BE_EXECUTED_BY_NON_MAIN_THREAD,
  c_error_SIGNAL_WRONG_PROCESS_IDENTIFIER,
  c_error_SIGNAL_SEND_ERROR,

#ifdef ENABLE_CLASS_POLL
  c_error_POLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE,
  c_error_POLL_WRONG_FD_OR_EVENT_VALUE_TYPE,
  c_error_POLL_POLL_ERROR,
#endif

  c_error_TIMER_NEGATIVE_DELAY,
  c_error_TIMER_WRONG_DELEGATE_PARAMETER_COUNT,

#ifdef ENABLE_CLASS_CLOCK
  c_error_CLOCK_CANNOT_GET_RESOLUTION,
  c_error_CLOCK_CANNOT_GET_TIME,
  c_error_CLOCK_CANNOT_SET_TIME,
#endif
};

// - SYS error strings -
extern const char *sys_error_strings[];

// - SYS initialize -
bool sys_initialize(script_parser_s &sp);

// - SYS print exception -
bool sys_print_exception(interpreter_s &it,exception_s &exception);

// - class SYS -
extern built_in_variable_s sys_variables[];
extern built_in_method_s sys_methods[];
extern built_in_class_s sys_class;

void bic_sys_consts(location_array_s &const_locations);
void bic_sys_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sys_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sys_method_sleep_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_srand_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_rand_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_getpid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_getuid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_getgid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_system_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_exit_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_open_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_popen_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_mkdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_rmdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_chdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_listdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_mkfifo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_rename_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_getcwd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_setenv_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_getenv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_is_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_is_dir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_size_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PIPE -
extern built_in_variable_s pipe_variables[];
extern built_in_method_s pipe_methods[];
extern built_in_class_s pipe_class;

void bic_pipe_consts(location_array_s &const_locations);
void bic_pipe_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pipe_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pipe_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_Pipe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_Pipe_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_write_close_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_read_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pipe_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FILE -
extern built_in_variable_s file_variables[];
extern built_in_method_s file_methods[];
extern built_in_class_s file_class;

void bic_file_consts(location_array_s &const_locations);
void bic_file_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_file_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_File_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_File_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_seek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_tell_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_write_close_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_read_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#ifdef ENABLE_CLASS_SOCKET
// - class SOCKET_ADDR -
extern built_in_variable_s socket_addr_variables[];
extern built_in_method_s socket_addr_methods[];
extern built_in_class_s socket_addr_class;

void bic_socket_addr_consts(location_array_s &const_locations);
void bic_socket_addr_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_socket_addr_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_socket_addr_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_addr_method_SocketAddr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_addr_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_addr_method_port_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_addr_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_addr_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SOCKET -
extern built_in_variable_s socket_variables[];
extern built_in_method_s socket_methods[];
extern built_in_class_s socket_class;

void bic_socket_consts(location_array_s &const_locations);
void bic_socket_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_socket_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_socket_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_Socket_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_Socket_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_listen_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_accept_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_accept_nonblock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_bind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_sendto_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_recvfrom_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_set_timeout_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_socket_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif

// - class dummy STREAM -
location_s *bic_stream_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_stream_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stream_method_flush_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stream_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stream_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stream_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stream_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stream_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class dummy FD -
location_s *bic_fd_next_item(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fd_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_read_nonblock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#ifdef ENABLE_CLASS_REGEX
// - class REGEX -
extern built_in_variable_s regex_variables[];
extern built_in_method_s regex_methods[];
extern built_in_class_s regex_class;

void bic_regex_consts(location_array_s &const_locations);
void bic_regex_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_regex_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_regex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_Regex_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_Regex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_match_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_match_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_match_from_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_split_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif

// - class SIGNAL -
extern built_in_variable_s signal_variables[];
extern built_in_method_s signal_methods[];
extern built_in_class_s signal_class;

void bic_signal_consts(location_array_s &const_locations);
void bic_signal_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_signal_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_signal_method_bind_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_signal_method_unbind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_signal_method_send_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_signal_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_signal_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#ifdef ENABLE_CLASS_POLL
// - class POLL -
extern built_in_variable_s poll_variables[];
extern built_in_method_s poll_methods[];
extern built_in_class_s poll_class;

void bic_poll_consts(location_array_s &const_locations);
void bic_poll_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_poll_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_poll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_poll_method_Poll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_poll_method_ready_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_poll_method_poll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_poll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_poll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif

// - class TIMER -
extern built_in_variable_s timer_variables[];
extern built_in_method_s timer_methods[];
extern built_in_class_s timer_class;

void bic_timer_consts(location_array_s &const_locations);
void bic_timer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_timer_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_timer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_method_Timer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_method_schedule_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_method_remain_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#ifdef ENABLE_CLASS_CLOCK
// - class CLOCK -
extern built_in_variable_s clock_variables[];
extern built_in_method_s clock_methods[];
extern built_in_class_s clock_class;

void bic_clock_consts(location_array_s &const_locations);
void bic_clock_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_clock_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_clock_method_getres_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_clock_method_gettime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_clock_method_settime_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_clock_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_clock_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif

#endif

