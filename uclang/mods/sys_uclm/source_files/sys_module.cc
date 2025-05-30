
@begin
include "sys_module.h"
@end

// - SYS indexes of built in classes -
unsigned c_bi_class_sys = c_idx_not_exist;
unsigned c_bi_class_pipe = c_idx_not_exist;
unsigned c_bi_class_file = c_idx_not_exist;

#ifdef ENABLE_CLASS_SOCKET
unsigned c_bi_class_socket_addr = c_idx_not_exist;
unsigned c_bi_class_socket = c_idx_not_exist;
#endif

unsigned c_bi_class_signal = c_idx_not_exist;
unsigned c_bi_class_poll = c_idx_not_exist;

unsigned c_bi_class_timer = c_idx_not_exist;

#ifdef ENABLE_CLASS_CLOCK
unsigned c_bi_class_clock = c_idx_not_exist;
#endif

// - SYS module -
EXPORT built_in_module_s module =
{/*{{{*/
  6                     // Class count

#ifdef ENABLE_CLASS_SOCKET
  + 2
#endif

#ifdef ENABLE_CLASS_CLOCK
  + 1
#endif
  ,
  sys_classes,          // Classes

  0,                    // Error base index
  37                    // Error count
#ifdef ENABLE_CLASS_SOCKET
  + 18
#endif
  + 3
#ifdef ENABLE_CLASS_CLOCK
  + 3
#endif
  ,
  sys_error_strings,    // Error strings

  sys_initialize,       // Initialize function
  sys_print_exception,  // Print exceptions function
};/*}}}*/

// - SYS classes -
built_in_class_s *sys_classes[] =
{/*{{{*/
  &sys_class,
  &pipe_class,
  &file_class,

#ifdef ENABLE_CLASS_SOCKET
  &socket_addr_class,
  &socket_class,
#endif

  &signal_class,
  &poll_class,
  &timer_class,

#ifdef ENABLE_CLASS_CLOCK
  &clock_class,
#endif
};/*}}}*/

// - SYS error strings -
const char *sys_error_strings[] =
{/*{{{*/
  "error_SYS_DIR_CREATE_ERROR",
  "error_SYS_DIR_REMOVE_ERROR",
  "error_SYS_DIR_CHANGE_ERROR",
  "error_SYS_DIR_LIST_ERROR",
  "error_SYS_MAKE_FIFO_ERROR",
  "error_SYS_FILE_CHMOD_ERROR",
  "error_SYS_FILE_REMOVE_ERROR",
  "error_SYS_FILE_RENAME_ERROR",
  "error_SYS_FILE_LINK_ERROR",
  "error_SYS_FILE_DOES_NOT_EXIST",
  "error_SYS_SETENV_ERROR",
  "error_SYS_GET_TIME_ERROR",
  "error_PIPE_CREATE_ERROR",
  "error_PIPE_OPEN_ERROR",
  "error_PIPE_CLOSE_ERROR",
  "error_PIPE_NOT_OPENED",
  "error_FILE_OPEN_ERROR",
  "error_FILE_SEEK_ERROR",
  "error_FILE_TELL_ERROR",
  "error_FILE_CLOSE_ERROR",
  "error_FILE_NOT_OPENED",

#ifdef ENABLE_CLASS_SOCKET
  "error_SOCKET_ADDRESS_RESOLVE_ERROR",
  "error_SOCKET_ADDRESS_UNKNOWN_FORMAT",

  "error_SOCKET_CREATE_ERROR",
  "error_SOCKET_CLOSE_ERROR",
  "error_SOCKET_NOT_OPENED",
  "error_SOCKET_UNKNOWN_DOMAIN",
  "error_SOCKET_BIND_ERROR",
  "error_SOCKET_LISTEN_ERROR",
  "error_SOCKET_ACCEPT_ERROR",
  "error_SOCKET_CONNECT_ERROR",
  "error_SOCKET_SENDTO_ERROR",
  "error_SOCKET_RECVFROM_ERROR",
  "error_SOCKET_UDP_MAX_MSG_SIZE_EXCEEDED",

  "error_SOCKET_SET_TIMEOUT_ERROR",
  "error_SOCKET_SOCKOPT_INVALID_LEVEL",
  "error_SOCKET_SOCKOPT_INVALID_OPTNAME",
  "error_SOCKET_SOCKOPT_INVALID_VALUE_TYPE",
  "error_SOCKET_SOCKOPT_OPERATION_ERROR",
#endif

  "error_STREAM_WRITE_ERROR",
  "error_STREAM_FLUSH_ERROR",
  "error_STREAM_READ_ERROR",
  "error_STREAM_READ_NEGATIVE_BYTE_COUNT",
  "error_STREAM_NOT_OPENED",
  "error_FD_WRITE_ERROR",
  "error_FD_READ_ERROR",
  "error_FD_READ_NEGATIVE_BYTE_COUNT",
  "error_FD_NOT_OPENED",

  "error_SIGNAL_WRONG_SIGNAL_NUMBER",
  "error_SIGNAL_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_SIGNAL_CANNOT_BE_EXECUTED_BY_NON_MAIN_THREAD",
  "error_SIGNAL_SEND_ERROR",

  "error_POLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE",
  "error_POLL_WRONG_FD_OR_EVENTS_VALUE_TYPE",
  "error_POLL_POLL_ERROR",

  "error_TIMER_NEGATIVE_DELAY",
  "error_TIMER_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_TIMER_INVALID_TIMER_RECORD_INDEX",

#ifdef ENABLE_CLASS_CLOCK
  "error_CLOCK_CANNOT_GET_RESOLUTION",
  "error_CLOCK_CANNOT_GET_TIME",
  "error_CLOCK_CANNOT_SET_TIME",
#endif
};/*}}}*/

// - SYS initialize -
bool sys_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize sys class identifier -
  c_bi_class_sys = class_base_idx++;

  // - initialize pipe class identifier -
  c_bi_class_pipe = class_base_idx++;

  // - initialize file class identifier -
  c_bi_class_file = class_base_idx++;

#ifdef ENABLE_CLASS_SOCKET
  // - initialize socket_addr class identifier -
  c_bi_class_socket_addr = class_base_idx++;

  // - initialize socket class identifier -
  c_bi_class_socket = class_base_idx++;
#endif

  // - initialize signal class identifier -
  c_bi_class_signal = class_base_idx++;

  // - initialize poll class identifier -
  c_bi_class_poll = class_base_idx++;

  // - initialize timer class identifier -
  c_bi_class_timer = class_base_idx++;

#ifdef ENABLE_CLASS_CLOCK
  // - initialize clock class identifier -
  c_bi_class_clock = class_base_idx++;
#endif

  return true;
}/*}}}*/

// - SYS print exception -
bool sys_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SYS_DIR_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_DIR_REMOVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot remove directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_DIR_CHANGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot change directory to \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_DIR_LIST_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot list directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_MAKE_FIFO_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create fifo file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_FILE_CHMOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot change permissions of file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_FILE_REMOVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot remove file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_FILE_RENAME_ERROR:
  {
    pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)exception.obj_location)->v_data_ptr;
    string_s *old_file_name = (string_s *)(((location_s *)(*array_ptr)[0])->v_data_ptr);
    string_s *new_file_name = (string_s *)(((location_s *)(*array_ptr)[1])->v_data_ptr);

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot rename file \"%s\" to \"%s\"\n",old_file_name->data,new_file_name->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_SYS_FILE_LINK_ERROR:
  {
    pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)exception.obj_location)->v_data_ptr;
    string_s *old_file_name = (string_s *)(((location_s *)(*array_ptr)[0])->v_data_ptr);
    string_s *new_file_name = (string_s *)(((location_s *)(*array_ptr)[1])->v_data_ptr);

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot link file \"%s\" to \"%s\"\n",old_file_name->data,new_file_name->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_SYS_FILE_DOES_NOT_EXIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile \"%s\" does not exist\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
  break;
  case c_error_SYS_SETENV_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set environment variable \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_GET_TIME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve system time\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PIPE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create unnamed pipe\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PIPE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open pipe, command \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PIPE_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot close pipe\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PIPE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPipe is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FILE_SEEK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set position (seek) in file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FILE_TELL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve position in file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FILE_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot close file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FILE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;

#ifdef ENABLE_CLASS_SOCKET
  case c_error_SOCKET_ADDRESS_RESOLVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while resolving socket address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_ADDRESS_UNKNOWN_FORMAT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown socket address format\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create socket\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot close socket\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSocket is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_UNKNOWN_DOMAIN:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown (unimplemented) socket domain\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_BIND_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while binding address to socket\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_LISTEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while initiating listening\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_ACCEPT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while accepting connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_CONNECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while connecting to host\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_SENDTO_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while sending data to address\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_RECVFROM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while receiving data from socket\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_UDP_MAX_MSG_SIZE_EXCEEDED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMaximal UDP message size %" HOST_LL_FORMAT "d was exceeded\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_SET_TIMEOUT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while setting socket send/receive timeout\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_SOCKOPT_INVALID_LEVEL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid socket option level\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_SOCKOPT_INVALID_OPTNAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid socket option name\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_SOCKOPT_INVALID_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid socket option value type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SOCKET_SOCKOPT_OPERATION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while %s socket option\n",exception.params[0] ? "setting" : "getting");
    fprintf(stderr," ---------------------------------------- \n");
    break;
#endif

  case c_error_STREAM_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to stream\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STREAM_FLUSH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while flushing stream\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STREAM_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from stream\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STREAM_READ_NEGATIVE_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read %" HOST_LL_FORMAT "d bytes from stream\n", exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STREAM_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nStream is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to file descriptor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from file descriptor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_READ_NEGATIVE_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read %" HOST_LL_FORMAT "d bytes from file descriptor\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SIGNAL_WRONG_SIGNAL_NUMBER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong identification number of signal %" HOST_LL_FORMAT "d\n", exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SIGNAL_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of parameters of signal handler %" HOST_LL_FORMAT "d, expected 1\n", exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SIGNAL_CANNOT_BE_EXECUTED_BY_NON_MAIN_THREAD:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s can be executed only from main thread of process\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_SIGNAL_SEND_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while sending signal\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_POLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong size of poll file descriptors and events array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_POLL_WRONG_FD_OR_EVENTS_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of file descriptor or events value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_POLL_POLL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while polling file descriptors\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIMER_NEGATIVE_DELAY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNegative requested timer delay %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIMER_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIMER_INVALID_TIMER_RECORD_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid timer record index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;

#ifdef ENABLE_CLASS_CLOCK
  case c_error_CLOCK_CANNOT_GET_RESOLUTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get clock resolution\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CLOCK_CANNOT_GET_TIME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get clock time\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CLOCK_CANNOT_SET_TIME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set clock time\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
#endif

  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class SYS -
built_in_class_s sys_class =
{/*{{{*/
  "Sys",
  c_modifier_public | c_modifier_final,
  29, sys_methods,
  3, sys_variables,
  bic_sys_consts,
  bic_sys_init,
  bic_sys_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s sys_methods[] =
{/*{{{*/
  {
    "sleep#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_sleep_1
  },
  {
    "srand#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_srand_1
  },
  {
    "rand#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_rand_0
  },
  {
    "getpid#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_getpid_0
  },
  {
    "getuid#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_getuid_0
  },
  {
    "getgid#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_getgid_0
  },
  {
    "system#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_system_1
  },
  {
    "exit#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_exit_1
  },
  {
    "open#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_open_2
  },
  {
    "popen#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_popen_2
  },
  {
    "pipe#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_pipe_0
  },
  {
    "mkdir#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_mkdir_1
  },
  {
    "rmdir#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_rmdir_1
  },
  {
    "chdir#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_chdir_1
  },
  {
    "listdir#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_listdir_1
  },
  {
    "mkfifo#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_mkfifo_1
  },
  {
    "chmod#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_chmod_2
  },
  {
    "remove#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_remove_1
  },
  {
    "rename#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_rename_2
  },
  {
    "link#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_link_2
  },
  {
    "getcwd#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_getcwd_0
  },
  {
    "setenv#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_setenv_2
  },
  {
    "getenv#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_getenv_1
  },
  {
    "is_file#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_is_file_1
  },
  {
    "is_dir#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_is_dir_1
  },
  {
    "size#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_size_1
  },
  {
    "time#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_time_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_method_print_0
  },
};/*}}}*/

built_in_variable_s sys_variables[] =
{/*{{{*/
  { "NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RAND_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define SYS_FILE_OPEN(CLASS_IDX,NAME) \
  /*{{{*/\
@begin ucl_params
<
file_name:c_bi_class_string
file_mode:c_bi_class_string
>
class CLASS_IDX
method NAME
static_method
macro
; @end\
\
  string_s *file_name = (string_s *)src_0_location->v_data_ptr;\
  string_s *file_mode = (string_s *)src_1_location->v_data_ptr;\
\
  /* - open file - */\
  FILE *f = fopen(file_name->data,file_mode->data);\
\
  /* - ERROR - */\
  if (f == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
  /*}}}*/

#define SYS_PIPE_OPEN(CLASS_IDX,NAME) \
  /*{{{*/\
@begin ucl_params
<
command:c_bi_class_string
type:c_bi_class_string
>
class CLASS_IDX
method NAME
static_method
macro
; @end\
\
  string_s *command = (string_s *)src_0_location->v_data_ptr;\
  string_s *type = (string_s *)src_1_location->v_data_ptr;\
\
  /* - open file - */\
  FILE *f = POPEN_FNAME(command->data,type->data);\
\
  /* - ERROR - */\
  if (f == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_PIPE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
  /*}}}*/

void bic_sys_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(2);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_SYS_BIC_STATIC_STRING(VALUE)\
  {\
    string_s *string_ptr = (string_s *)cmalloc(sizeof(string_s));\
    string_ptr->init();\
    string_ptr->set(strlen(VALUE),VALUE);\
\
    cv_ptr->v_type = c_bi_class_string;\
    cv_ptr->v_reference_cnt.atomic_set(1);\
    cv_ptr->v_data_ptr = (string_s *)string_ptr;\
    cv_ptr++;\
  }

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  CREATE_SYS_BIC_STATIC_STRING("Unix");
  CREATE_SYS_BIC_STATIC_STRING("/");
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  CREATE_SYS_BIC_STATIC_STRING("Windows");
  CREATE_SYS_BIC_STATIC_STRING("\\");
#else
  CREATE_SYS_BIC_STATIC_STRING("Unknown");
  CREATE_SYS_BIC_STATIC_STRING("/");
#endif

  // - insert sys rand values -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_SYS_RAND_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SYS_RAND_BIC_STATIC(RAND_MAX);
  }
}/*}}}*/

void bic_sys_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_sys_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_sys_method_sleep_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
delay:retrieve_integer
>
class c_bi_class_sys
method sleep
static_method
; @end

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  struct timespec ts;

  ts.tv_sec = delay / 1000;
  ts.tv_nsec = (delay % 1000) * 1000000L;

  nanosleep(&ts,nullptr);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  ::Sleep(delay);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"sleep#1");

  return false;
#endif

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_srand_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
seed:retrieve_integer
>
class c_bi_class_sys
method srand
static_method
; @end

  srand(seed);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_rand_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = rand(); // NOLINT
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_getpid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = getpid();
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  result = _getpid();
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"getpid#0");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_getuid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = getuid();
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"getuid#0");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_getgid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = getgid();
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"getgid#0");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_system_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
command:c_bi_class_string
>
class c_bi_class_sys
method system
static_method
; @end

  int ret_val = system(((string_s *)src_0_location->v_data_ptr)->data); // NOLINT

  BIC_SIMPLE_SET_RES(c_bi_class_integer,ret_val);

  return true;
}/*}}}*/

bool bic_sys_method_exit_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
status:retrieve_integer
>
class c_bi_class_sys
method exit
static_method
; @end

  exit(status);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_open_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  SYS_FILE_OPEN(c_bi_class_sys,"open#2");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_file,f);
  BIC_SET_RESULT(new_location); // NOLINT(clang-analyzer-unix.Stream)

  return true;
}/*}}}*/

bool bic_sys_method_popen_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  SYS_PIPE_OPEN(c_bi_class_sys,"popen#2"); // NOLINT

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pipe,f);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sys_method_pipe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  // - create pipe -
  int pipefd[2];

  // - ERROR -
  if (pipe(pipefd) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PIPE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - open pipe read end -
  FILE *fr = fdopen(pipefd[0],"rb");

  // - ERROR -
  if (fr == nullptr)
  {
    close(pipefd[0]);
    close(pipefd[1]);

    exception_s::throw_exception(it,module.error_base + c_error_PIPE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - open pipe write end -
  FILE *fw = fdopen(pipefd[1],"w");

  // - ERROR -
  if (fw == nullptr)
  {
    fclose(fr);
    close(pipefd[1]);

    exception_s::throw_exception(it,module.error_base + c_error_PIPE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  array_ptr->copy_resize(2);

  // - create read file -
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_file,fr);
    array_ptr->push(new_location); // NOLINT(clang-analyzer-unix.Stream)
  }

  // - create write file -
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_file,fw);
    array_ptr->push(new_location); // NOLINT(clang-analyzer-unix.Stream)
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"pipe#0");

  return false;
#endif

  return true;
}/*}}}*/

bool bic_sys_method_mkdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method mkdir
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = mkdir(string_ptr->data,0777) == 0;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  result = _mkdir(string_ptr->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"mkdir#1");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_DIR_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_rmdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method rmdir
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = rmdir(string_ptr->data) == 0;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  result = _rmdir(string_ptr->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"rmdir#1");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_DIR_REMOVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_chdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method chdir
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = chdir(string_ptr->data) == 0;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  result = _chdir(string_ptr->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"chdir#1");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_DIR_CHANGE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_listdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method listdir
static_method
; @end

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  string_s *dir_path = (string_s *)src_0_location->v_data_ptr;

  // - open directory -
  DIR *dir = opendir(dir_path->data);
  if (dir == nullptr)
  {
    result = false;
  }
  else
  {
    struct dirent *entry;

    // - read directory entries -
    while ((entry = readdir(dir)) != nullptr)
    {
      char *name = entry->d_name;

      // - skip reference to this and parent directory -
      if (!(name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))))
      {
        string_s *entry_name = it.get_new_string_ptr();
        entry_name->set(strlen(name),name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,entry_name);
        array_ptr->push(new_location);
      }
    }

    // - close directory -
    result = closedir(dir) == 0;
  }
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  string_s *dir_path = (string_s *)src_0_location->v_data_ptr;

  // - create file mask -
  char fmask[MAX_PATH + 2];
  memcpy(fmask,dir_path->data,dir_path->size - 1);

  // - append "\*" to directory name -
  char *f_ptr = fmask + dir_path->size - 1;
  *f_ptr++ = '\\';
  *f_ptr++ = '*';
  *f_ptr++ = '\0';

  WIN32_FIND_DATA ffd;
  HANDLE hFind = INVALID_HANDLE_VALUE;

  if ((hFind = FindFirstFile(fmask,&ffd)) == INVALID_HANDLE_VALUE)
  {
    result = false;
  }
  else
  {
    do {
      char *name = ffd.cFileName;

      // - skip reference to this and parent directory -
      if (!(name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'))))
      {
        string_s *entry_name = it.get_new_string_ptr();
        entry_name->set(strlen(name),name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,entry_name);
        array_ptr->push(new_location);
      }
    } while(FindNextFile(hFind,&ffd));

    result = FindClose(hFind) != 0;
  }
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"listdir#1");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_sys_method_mkfifo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method mkfifo
static_method
; @end

  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  result = mkfifo(string_ptr->data,0777) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"mkfifo#1");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_MAKE_FIFO_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_chmod_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
mode:retrieve_integer
>
class c_bi_class_sys
method chmod
static_method
; @end

  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  result = chmod(string_ptr->data,mode) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"chmod#2");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_FILE_CHMOD_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method remove
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = remove(string_ptr->data) == 0;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  result = remove(string_ptr->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"remove#1");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_FILE_REMOVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_rename_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
old_path:c_bi_class_string
new_path:c_bi_class_string
>
class c_bi_class_sys
method rename
static_method
; @end

  string_s *string_old = (string_s *)src_0_location->v_data_ptr;
  string_s *string_new = (string_s *)src_1_location->v_data_ptr;
  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = rename(string_old->data,string_new->data) == 0;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  result = rename(string_old->data,string_new->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"rename#2");

  return false;
#endif

  if (!result)
  {
    // - construct array containing old and new file names -
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    src_0_location->v_reference_cnt.atomic_inc();
    array_ptr->push(src_0_location);

    src_1_location->v_reference_cnt.atomic_inc();
    array_ptr->push(src_1_location);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_array,array_ptr,0);

    exception_s::throw_exception(it,module.error_base + c_error_SYS_FILE_RENAME_ERROR,operands[c_source_pos_idx],new_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_link_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
old_path:c_bi_class_string
new_path:c_bi_class_string
>
class c_bi_class_sys
method link
static_method
; @end

  string_s *string_old = (string_s *)src_0_location->v_data_ptr;
  string_s *string_new = (string_s *)src_1_location->v_data_ptr;
  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = link(string_old->data,string_new->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"link#2");

  return false;
#endif

  if (!result)
  {
    // - construct array containing old and new file names -
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    src_0_location->v_reference_cnt.atomic_inc();
    array_ptr->push(src_0_location);

    src_1_location->v_reference_cnt.atomic_inc();
    array_ptr->push(src_1_location);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_array,array_ptr,0);

    exception_s::throw_exception(it,module.error_base + c_error_SYS_FILE_LINK_ERROR,operands[c_source_pos_idx],new_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_getcwd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  string_s *string_ptr = it.get_new_string_ptr();

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  string_ptr->create(1024);
  do
  {
    if (getcwd(string_ptr->data,string_ptr->size) != nullptr)
    {
      string_ptr->size = strlen(string_ptr->data) + 1;
      break;
    }

    string_ptr->create(string_ptr->size << 1);
  }
  while(true);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  unsigned path_length = GetCurrentDirectory(0,nullptr) - 1;
  string_ptr->create(path_length);
  GetCurrentDirectory(string_ptr->size,string_ptr->data);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"getcwd#0");

  return false;
#endif

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_sys_method_setenv_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
value:c_bi_class_string
>
class c_bi_class_sys
method setenv
static_method
; @end

  bool result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  string_s *name = (string_s *)src_0_location->v_data_ptr;
  string_s *value = (string_s *)src_1_location->v_data_ptr;

  result = setenv(name->data,value->data,1) == 0;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  string_s *name = (string_s *)src_0_location->v_data_ptr;
  string_s *value = (string_s *)src_1_location->v_data_ptr;

  result = _putenv_s(name->data,value->data) == 0;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"setenv#2");

  return false;
#endif

  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_SETENV_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sys_method_getenv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
class c_bi_class_sys
method getenv
static_method
; @end

  char *result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX || SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  result = getenv(string_ptr->data);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"getenv#1");

  return false;
#endif

  if (result != nullptr)
  {
    // - create result string location -
    string_s *new_string_ptr = it.get_new_string_ptr();
    new_string_ptr->set(strlen(result),result);

    BIC_SET_RESULT_STRING(new_string_ptr);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_sys_method_is_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method is_file
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  struct stat st;
  result = stat(string_ptr->data,&st) == 0 && !S_ISDIR(st.st_mode);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  struct _stat st;
  result = _stat(string_ptr->data,&st) == 0 && !(st.st_mode & S_IFDIR);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"is_file#1");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_is_dir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method is_dir
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  struct stat st;
  result = stat(string_ptr->data,&st) == 0 && S_ISDIR(st.st_mode);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  struct _stat st;
  result = _stat(string_ptr->data,&st) == 0 && st.st_mode & S_IFDIR;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"is_dir#1");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_size_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_sys
method size
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  struct stat st;

  // - ERROR -
  if (stat(string_ptr->data,&st) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_FILE_DOES_NOT_EXIST,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - retrieve file size -
  result = st.st_size;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  struct _stat st;

  // - ERROR -
  if (_stat(string_ptr->data,&st) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_FILE_DOES_NOT_EXIST,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - retrieve file size -
  result = st.st_size;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"size#1");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  timeval tv;

  // - ERROR -
  if (gettimeofday(&tv,nullptr) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_GET_TIME_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  result = 1000000LL*tv.tv_sec + tv.tv_usec;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);

  ULARGE_INTEGER ularge_int = { ft.dwLowDateTime,ft.dwHighDateTime };
  result = (ularge_int.QuadPart - 116444736000000000ULL)/10ULL;
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys,"time#0");

  return false;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sys_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Sys"),"Sys")
  );

  return true;
}/*}}}*/

bool bic_sys_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Sys");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PIPE -
built_in_class_s pipe_class =
{/*{{{*/
  "Pipe",
  c_modifier_public | c_modifier_final,
  15
#ifdef __GNUC__
  + 1
#endif
  , pipe_methods,
  0, pipe_variables,
  bic_pipe_consts,
  bic_pipe_init,
  bic_pipe_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_stream_next_item,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s pipe_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pipe_operator_binary_equal
  },
  {
    "Pipe#2",
    c_modifier_public | c_modifier_final,
    bic_pipe_method_Pipe_2
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_pipe_method_close_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_stream_method_write_1
  },
  {
    "write_close#1",
    c_modifier_public | c_modifier_final,
    bic_pipe_method_write_close_1
  },
  {
    "flush#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_flush_0
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_read_0
  },
  {
    "readln#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_readln_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_stream_method_read_1
  },
  {
    "read_max#1",
    c_modifier_public | c_modifier_final,
    bic_stream_method_read_max_1
  },
  {
    "read_close#0",
    c_modifier_public | c_modifier_final,
    bic_pipe_method_read_close_0
  },
#ifdef __GNUC__
  {
    "pid#0",
    c_modifier_public | c_modifier_final,
    bic_pipe_method_pid_0
  },
#endif
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_get_fd_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pipe_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pipe_method_print_0
  },
};/*}}}*/

built_in_variable_s pipe_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_STREAM_METHOD_WRITE_1() \
/*{{{*/\
\
  /* - retrieve pointer to stream - */\
  FILE *f = (FILE *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (f == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (fwrite(data_ptr,1,data_size,f) != data_size)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

#define BIC_STREAM_METHOD_READ_0() \
/*{{{*/\
\
  /* - retrieve pointer to stream - */\
  FILE *f = (FILE *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (f == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  const unsigned c_buffer_add = 1024;\
\
  /* - target data buffer - */\
  bc_array_s data_buffer;\
  data_buffer.init();\
\
  unsigned read_cnt;\
  do\
  {\
    unsigned old_used = data_buffer.used;\
    data_buffer.push_blanks(c_buffer_add);\
    read_cnt = fread(data_buffer.data + old_used,1,c_buffer_add,f);\
  }\
  while(read_cnt >= c_buffer_add);\
\
  /* - ERROR - */\
  if (ferror(f))\
  {\
    data_buffer.clear();\
\
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  data_buffer.used = (data_buffer.used - c_buffer_add) + read_cnt;\
\
  /* - was any data read from file - */\
  if (data_buffer.used == 0)\
  {\
    data_buffer.clear();\
\
    BIC_SET_RESULT_BLANK();\
  }\
  else\
  {\
    data_buffer.push('\0');\
\
    /* - return data string - */\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->data = data_buffer.data;\
    string_ptr->size = data_buffer.used;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
/*}}}*/

#define BIC_PIPE_METHOD_CLOSE_0() \
/*{{{*/\
\
  /* - ERROR - */\
  if (PCLOSE_FNAME(f) == -1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_PIPE_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  dst_location->v_data_ptr = (FILE *)nullptr;\
/*}}}*/

void bic_pipe_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pipe_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (FILE *)nullptr;
}/*}}}*/

void bic_pipe_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve pipe file pointer -
  FILE *f = (FILE *)location_ptr->v_data_ptr;

  // - if pipe file pointer is not null -
  if (f != nullptr)
  {
    PCLOSE_FNAME(f);
  }

}/*}}}*/

bool bic_pipe_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pipe_method_Pipe_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SYS_PIPE_OPEN(c_bi_class_pipe,"Pipe#2"); // NOLINT

  dst_location->v_data_ptr = (FILE *)f;

  return true;
}/*}}}*/

bool bic_pipe_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to file -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PIPE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_PIPE_METHOD_CLOSE_0();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pipe_method_write_close_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write_close
; @end

  BIC_STREAM_METHOD_WRITE_1();
  BIC_PIPE_METHOD_CLOSE_0();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pipe_method_read_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_STREAM_METHOD_READ_0();
  BIC_PIPE_METHOD_CLOSE_0();

  return true;
}/*}}}*/

#ifdef __GNUC__
bool bic_pipe_method_pid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  /* - retrieve pointer to stream - */
  FILE *f = (FILE *)dst_location->v_data_ptr;

  /* - ERROR - */
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ((IO_proc_file *)f)->pid;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/
#endif

bool bic_pipe_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Pipe"),"Pipe")
  );

  return true;
}/*}}}*/

bool bic_pipe_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Pipe");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FILE -
built_in_class_s file_class =
{/*{{{*/
  "File",
  c_modifier_public | c_modifier_final,
  17, file_methods,
  3 + 3, file_variables,
  bic_file_consts,
  bic_file_init,
  bic_file_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_stream_next_item,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s file_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_file_operator_binary_equal
  },
  {
    "File#2",
    c_modifier_public | c_modifier_final,
    bic_file_method_File_2
  },
  {
    "seek#2",
    c_modifier_public | c_modifier_final,
    bic_file_method_seek_2
  },
  {
    "tell#0",
    c_modifier_public | c_modifier_final,
    bic_file_method_tell_0
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_file_method_close_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_stream_method_write_1
  },
  {
    "write_close#1",
    c_modifier_public | c_modifier_final,
    bic_file_method_write_close_1
  },
  {
    "flush#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_flush_0
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_read_0
  },
  {
    "readln#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_readln_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_stream_method_read_1
  },
  {
    "read_max#1",
    c_modifier_public | c_modifier_final,
    bic_stream_method_read_max_1
  },
  {
    "read_close#0",
    c_modifier_public | c_modifier_final,
    bic_file_method_read_close_0
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_get_fd_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_stream_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_file_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_file_method_print_0
  },
};/*}}}*/

built_in_variable_s file_variables[] =
{/*{{{*/

  // - standard file stream constants -
  { "stdin",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "stdout", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "stderr", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - seek whence values -
  { "SEEK_SET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_CUR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_END", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_FILE_METHOD_CLOSE_0() \
/*{{{*/\
\
  /* - ERROR - */\
  if (fclose(f) != 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_FILE_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  dst_location->v_data_ptr = (FILE *)nullptr;\
/*}}}*/

void bic_file_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert standard file stream constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_FILE_STREAM_BIC_STATIC(STREAM)\
  cv_ptr->v_type = c_bi_class_file;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (FILE *)STREAM;\
  cv_ptr++;

    CREATE_FILE_STREAM_BIC_STATIC(stdin);
    CREATE_FILE_STREAM_BIC_STATIC(stdout);
    CREATE_FILE_STREAM_BIC_STATIC(stderr);
  }

  // - insert seek whence values -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_FILE_SEEK_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FILE_SEEK_BIC_STATIC(SEEK_SET);
    CREATE_FILE_SEEK_BIC_STATIC(SEEK_CUR);
    CREATE_FILE_SEEK_BIC_STATIC(SEEK_END);
  }

}/*}}}*/

void bic_file_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (FILE *)nullptr;
}/*}}}*/

void bic_file_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve file pointer -
  FILE *f = (FILE *)location_ptr->v_data_ptr;

  // - if file pointer is not null or standard stream pointer -
  if (f != nullptr && f != stdin && f != stdout && f != stderr)
  {
    fclose(f);
  }

}/*}}}*/

bool bic_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_file_method_File_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SYS_FILE_OPEN(c_bi_class_file,"File#2");

  dst_location->v_data_ptr = (FILE *)f;

  return true; // NOLINT(clang-analyzer-unix.Stream)
}/*}}}*/

bool bic_file_method_seek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offset:retrieve_integer
whence:retrieve_integer
>
method seek
; @end

  // - retrieve pointer to file -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (fseek(f,offset,whence) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FILE_SEEK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_file_method_tell_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to file -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ftell(f);

  // - ERROR -
  if (result < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FILE_TELL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_file_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to file -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_FILE_METHOD_CLOSE_0();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_file_method_write_close_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write_close
; @end

  BIC_STREAM_METHOD_WRITE_1();
  BIC_FILE_METHOD_CLOSE_0();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_file_method_read_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_STREAM_METHOD_READ_0();
  BIC_FILE_METHOD_CLOSE_0();

  return true;
}/*}}}*/

bool bic_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("File"),"File")
  );

  return true;
}/*}}}*/

bool bic_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("File");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

#ifdef ENABLE_CLASS_SOCKET
// - class SOCKET_ADDR -
built_in_class_s socket_addr_class =
{/*{{{*/
  "SocketAddr",
  c_modifier_public | c_modifier_final,
  6, socket_addr_methods,
  0, socket_addr_variables,
  bic_socket_addr_consts,
  bic_socket_addr_init,
  bic_socket_addr_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s socket_addr_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_socket_addr_operator_binary_equal
  },
  {
    "SocketAddr#2",
    c_modifier_public | c_modifier_final,
    bic_socket_addr_method_SocketAddr_2
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_socket_addr_method_name_0
  },
  {
    "port#0",
    c_modifier_public | c_modifier_final,
    bic_socket_addr_method_port_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_socket_addr_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_socket_addr_method_print_0
  },
};/*}}}*/

built_in_variable_s socket_addr_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_socket_addr_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_socket_addr_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (sockaddr_in *)nullptr;
}/*}}}*/

void bic_socket_addr_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  sockaddr_in *addr_ptr = (sockaddr_in *)location_ptr->v_data_ptr;

  if (addr_ptr != nullptr)
  {
    cfree(addr_ptr);
  }
}/*}}}*/

bool bic_socket_addr_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_socket_addr_method_SocketAddr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_string
port:retrieve_integer
>
method SocketAddr
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  struct addrinfo addr_hints;
  memset(&addr_hints,0,sizeof(struct addrinfo));
  addr_hints.ai_family = AF_INET;

  // - ERROR -
  struct addrinfo *addr_info;
  if (getaddrinfo(string_ptr->data,nullptr,&addr_hints,&addr_info) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_ADDRESS_RESOLVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - fill address structure -
  sockaddr_in *addr_ptr = (sockaddr_in *)cmalloc(sizeof(sockaddr_in));

  addr_ptr->sin_addr = ((struct sockaddr_in *)addr_info->ai_addr)->sin_addr;
  addr_ptr->sin_port = htons(port);
  addr_ptr->sin_family = AF_INET;

  // - release address info -
  freeaddrinfo(addr_info);

  dst_location->v_data_ptr = (sockaddr_in *)addr_ptr;

  return true;
}/*}}}*/

bool bic_socket_addr_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  sockaddr_in *addr_ptr = (sockaddr_in *)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(256);

  if (getnameinfo((sockaddr *)addr_ptr,sizeof(sockaddr_in),string_ptr->data,
        string_ptr->size - 1,nullptr,0,NI_NUMERICHOST | NI_NUMERICSERV) == 0)
  {
    // - set string size -
    string_ptr->size = strlen(string_ptr->data) + 1;

    BIC_SET_RESULT_STRING(string_ptr);
  }
  else
  {
    string_ptr->clear();
    cfree(string_ptr);

    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_socket_addr_method_port_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  sockaddr_in *addr_ptr = (sockaddr_in *)dst_location->v_data_ptr;

  long long int result = (unsigned short)ntohs(addr_ptr->sin_port);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_socket_addr_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SocketAddr"),"SocketAddr")
  );

  return true;
}/*}}}*/

bool bic_socket_addr_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("SocketAddr");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SOCKET -
built_in_class_s socket_class =
{/*{{{*/
  "Socket",
  c_modifier_public | c_modifier_final,
  18, socket_methods,
  3 + 3 + 1 + 6 + 1 + 2, socket_variables,
  bic_socket_consts,
  bic_socket_init,
  bic_socket_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s socket_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_socket_operator_binary_equal
  },
  {
    "Socket#2",
    c_modifier_public | c_modifier_final,
    bic_socket_method_Socket_2
  },
  {
    "listen#2",
    c_modifier_public | c_modifier_final,
    bic_socket_method_listen_2
  },
  {
    "accept#0",
    c_modifier_public | c_modifier_final,
    bic_socket_method_accept_0
  },
  {
    "connect#1",
    c_modifier_public | c_modifier_final,
    bic_socket_method_connect_1
  },
  {
    "bind#1",
    c_modifier_public | c_modifier_final,
    bic_socket_method_bind_1
  },
  {
    "sendto#2",
    c_modifier_public | c_modifier_final,
    bic_socket_method_sendto_2
  },
  {
    "recvfrom#0",
    c_modifier_public | c_modifier_final,
    bic_socket_method_recvfrom_0
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_socket_method_close_0
  },
  {
    "set_timeout#2",
    c_modifier_public | c_modifier_final,
    bic_socket_method_set_timeout_2
  },
  {
    "sockopt#3",
    c_modifier_public | c_modifier_final,
    bic_socket_method_sockopt_3
  },
  {
    "sockopt#2",
    c_modifier_public | c_modifier_final,
    bic_socket_method_sockopt_2
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_read_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_read_1
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_get_fd_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_socket_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_socket_method_print_0
  },
};/*}}}*/

built_in_variable_s socket_variables[] =
{/*{{{*/

  // - socket domain values -
  { "AF_UNIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AF_FILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AF_INET", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket type values -
  { "SOCK_STREAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SOCK_DGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SOCK_RAW", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket level values -
  { "SOL_SOCKET", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket options values -
  { "SO_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SO_SNDBUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SO_RCVBUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SO_RCVTIMEO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SO_SNDTIMEO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SO_BROADCAST", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - ip protocol values -
  { "IPPROTO_IP", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - ip options values -
  { "IP_ADD_MEMBERSHIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IP_DROP_MEMBERSHIP", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_socket_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert socket domain values -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_SOCKET_DOMAIN_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SOCKET_DOMAIN_BIC_STATIC(AF_UNIX);
    CREATE_SOCKET_DOMAIN_BIC_STATIC(AF_UNIX);
    CREATE_SOCKET_DOMAIN_BIC_STATIC(AF_INET);
  }

  // - insert socket type values -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_SOCKET_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SOCKET_TYPE_BIC_STATIC(SOCK_STREAM);
    CREATE_SOCKET_TYPE_BIC_STATIC(SOCK_DGRAM);
    CREATE_SOCKET_TYPE_BIC_STATIC(SOCK_RAW);
  }

  // - insert socket level values -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_SOCKET_LEVEL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SOCKET_LEVEL_BIC_STATIC(SOL_SOCKET);
  }

  // - insert socket options values -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_SOCKET_OPTION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SOCKET_OPTION_BIC_STATIC(SO_ERROR);
    CREATE_SOCKET_OPTION_BIC_STATIC(SO_SNDBUF);
    CREATE_SOCKET_OPTION_BIC_STATIC(SO_RCVBUF);
    CREATE_SOCKET_OPTION_BIC_STATIC(SO_RCVTIMEO);
    CREATE_SOCKET_OPTION_BIC_STATIC(SO_SNDTIMEO);
    CREATE_SOCKET_OPTION_BIC_STATIC(SO_BROADCAST);
  }

  // - insert ip protocol values -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_IP_PROTOCOL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_IP_PROTOCOL_BIC_STATIC(IPPROTO_IP);
  }


  // - insert ip options values -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_IP_OPTION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_IP_OPTION_BIC_STATIC(IP_ADD_MEMBERSHIP);
    CREATE_IP_OPTION_BIC_STATIC(IP_DROP_MEMBERSHIP);
  }

}/*}}}*/

void bic_socket_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (int)-1;
}/*}}}*/

void bic_socket_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve socket fd -
  int fd = (int)location_ptr->v_data_ptr;

  // - if socket fd is not invalid -
  if (fd != -1)
  {
    close(fd);
  }

}/*}}}*/

bool bic_socket_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_socket_method_Socket_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
domain:retrieve_integer
type:retrieve_integer
>
method Socket
; @end

  int protocol = 0;

  // - create socket -
  int sock = socket(domain,type,protocol);
  if (sock == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (int)sock;

  return true;
}/*}}}*/

bool bic_socket_method_listen_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_socket_addr
queue_len:retrieve_integer
>
method listen
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set server socket as reusable -
  int yes = 1;
  setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

#ifndef DISABLE_SO_DOMAIN
  // - retrieve socket domain -
  int domain;
  socklen_t domain_len = sizeof(int);
  getsockopt(fd,SOL_SOCKET,SO_DOMAIN,&domain,&domain_len);

  switch (domain)
  {
  case AF_INET:
  {
#endif
    // - retrieve socket address -
    sockaddr_in *addr_ptr = (sockaddr_in *)src_0_location->v_data_ptr;

    // - ERROR -
    if (bind(fd,(sockaddr *)addr_ptr,sizeof(sockaddr_in)) != 0)
    {
      exception_s::throw_exception(it,module.error_base + c_error_SOCKET_BIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - ERROR -
    if (listen(fd,queue_len) != 0)
    {
      exception_s::throw_exception(it,module.error_base + c_error_SOCKET_LISTEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
#ifndef DISABLE_SO_DOMAIN
  }
  break;

  default:
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_UNKNOWN_DOMAIN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }
#endif

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_accept_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#ifndef DISABLE_SO_DOMAIN
  // - retrieve socket domain -
  int domain;
  socklen_t domain_len = sizeof(int);
  getsockopt(fd,SOL_SOCKET,SO_DOMAIN,&domain,&domain_len);

  switch (domain)
  {
  case AF_INET:
  {
#endif
    sockaddr_in *addr_ptr = (sockaddr_in *)cmalloc(sizeof(sockaddr_in));
    socklen_t addr_len = sizeof(sockaddr_in);

    // - ERROR -
    int acc_fd = accept(fd,(sockaddr *)addr_ptr,&addr_len);
    if (acc_fd < 0)
    {
      cfree(addr_ptr);

      // - if nonblocking return BLANK value -
      if (errno == EAGAIN || errno == EWOULDBLOCK)
      {
        BIC_SET_RESULT_BLANK();

        return true;
      }

      exception_s::throw_exception(it,module.error_base + c_error_SOCKET_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - ERROR -
    if (addr_len != sizeof(sockaddr_in))
    {
      close(acc_fd);
      cfree(addr_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_SOCKET_ADDRESS_UNKNOWN_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - create result array location -
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    array_ptr->copy_resize(2);

    // - create socket location -
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_socket,acc_fd);
      array_ptr->push(new_location);
    }

    // - create address location -
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_socket_addr,addr_ptr);
      array_ptr->push(new_location);
    }

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    BIC_SET_RESULT(new_location);
#ifndef DISABLE_SO_DOMAIN
  }
  break;

  default:
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_UNKNOWN_DOMAIN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }
#endif

  return true;
}/*}}}*/

bool bic_socket_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_socket_addr
>
method connect
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#ifndef DISABLE_SO_DOMAIN
  // - retrieve socket domain -
  int domain;
  socklen_t domain_len = sizeof(int);
  getsockopt(fd,SOL_SOCKET,SO_DOMAIN,&domain,&domain_len);

  switch (domain)
  {
  case AF_INET:
  {
#endif
    // - fill address structure -
    sockaddr_in *addr_ptr = (sockaddr_in *)src_0_location->v_data_ptr;

    // - ERROR -
    if (connect(fd,(sockaddr *)addr_ptr,sizeof(sockaddr_in)) != 0)
    {
      if (errno != EINPROGRESS)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SOCKET_CONNECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
#ifndef DISABLE_SO_DOMAIN
  }
  break;

  default:
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_UNKNOWN_DOMAIN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }
#endif

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_bind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_socket_addr
>
method bind
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#ifndef DISABLE_SO_DOMAIN
  // - retrieve socket domain -
  int domain;
  socklen_t domain_len = sizeof(int);
  getsockopt(fd,SOL_SOCKET,SO_DOMAIN,&domain,&domain_len);

  switch (domain)
  {
  case AF_INET:
  {
#endif
    // - fill address structure -
    sockaddr_in *addr_ptr = (sockaddr_in *)src_0_location->v_data_ptr;

    // - ERROR -
    if (bind(fd,(sockaddr *)addr_ptr,sizeof(sockaddr_in)) != 0)
    {
      exception_s::throw_exception(it,module.error_base + c_error_SOCKET_BIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
#ifndef DISABLE_SO_DOMAIN
  }
  break;

  default:
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_UNKNOWN_DOMAIN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }
#endif

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_sendto_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_socket_addr
data:retrieve_data_buffer
>
method sendto
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve destination address -
  sockaddr_in *addr_ptr = (sockaddr_in *)src_0_location->v_data_ptr;

  if (data_size > 0)
  {
    long int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = sendto(fd,(const char *)data_ptr + writed,data_size - writed,0,(sockaddr *)addr_ptr,sizeof(sockaddr_in))) == -1)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SENDTO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    while((writed += cnt) < data_size);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_recvfrom_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - max count of udp message bytes -
  const ssize_t c_udp_max_cnt = 4096;

  // - udp message string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(c_udp_max_cnt);

  // - udp message source address -
  sockaddr_in *addr_ptr = (sockaddr_in *)cmalloc(sizeof(sockaddr_in));
  socklen_t addr_len = sizeof(sockaddr_in);

#define SOCKET_RECVFROM_CLEAR() \
{/*{{{*/\
  cfree(addr_ptr);\
\
  string_ptr->clear();\
  cfree(string_ptr);\
}/*}}}*/

  // - ERROR -
  ssize_t cnt;
  if ((cnt = recvfrom(fd,string_ptr->data,string_ptr->size - 1,0,(sockaddr *)addr_ptr,&addr_len)) == -1)
  {
    SOCKET_RECVFROM_CLEAR();

    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_RECVFROM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (cnt >= c_udp_max_cnt)
  {
    SOCKET_RECVFROM_CLEAR();

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SOCKET_UDP_MAX_MSG_SIZE_EXCEEDED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(c_udp_max_cnt);

    return false;
  }

  // - update string length -
  string_ptr->data[cnt] = '\0';
  string_ptr->size = cnt + 1;

  // - ERROR -
  if (addr_len != sizeof(sockaddr_in))
  {
    SOCKET_RECVFROM_CLEAR();

    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_ADDRESS_UNKNOWN_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result array location -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  array_ptr->copy_resize(2);

  // - create socket location -
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    array_ptr->push(new_location);
  }

  // - create address location -
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_socket_addr,addr_ptr);
    array_ptr->push(new_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_socket_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (close(fd) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (int)-1;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_set_timeout_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
optname:retrieve_integer
microsec:retrieve_integer
>
method set_timeout
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  struct timeval timeout;
  timeout.tv_sec = microsec / 1000000;
  timeout.tv_usec = microsec % 1000000;

  // - ERROR -
  if (setsockopt(fd,SOL_SOCKET,optname,(char *)&timeout,sizeof(timeout)) < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SET_TIMEOUT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_sockopt_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
level:retrieve_integer
optname:retrieve_integer
value:ignore
>
method sockopt
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;
  char optval[32];
  socklen_t optlen;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (level)
  {
  case SOL_SOCKET:
    {
      switch (optname)
      {
      case SO_SNDBUF:
      case SO_RCVBUF:
      case SO_BROADCAST:
        {
          long long int value;

          // - ERROR -
          if (!it.retrieve_integer(src_2_location,value))
          {
            exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          *((int *)optval) = value;
          optlen = sizeof(int);
        }
        break;

      default:
        exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_OPTNAME,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  case IPPROTO_IP:
    {
      switch (optname)
      {
      case IP_ADD_MEMBERSHIP:
      case IP_DROP_MEMBERSHIP:
        {
          // - ERROR -
          if (src_2_location->v_type != c_bi_class_string)
          {
            exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          string_s *string_ptr = (string_s *)src_2_location->v_data_ptr;

          ip_mreq *opt = (ip_mreq *)optval;
          opt->imr_interface.s_addr = INADDR_ANY;

          // - ERROR -
          if (inet_aton(string_ptr->data,&opt->imr_multiaddr) == 0)
          {
            exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          optlen = sizeof(ip_mreq);
        }
        break;

      default:
        exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_OPTNAME,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  default:
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (setsockopt(fd,level,optname,optval,optlen) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_OPERATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_socket_method_sockopt_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
level:retrieve_integer
optname:retrieve_integer
>
method sockopt
; @end

  // - retrieve socket fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  char optval[32];
  socklen_t optlen = 32;

  switch (level)
  {
  case SOL_SOCKET:
    {
      switch (optname)
      {
      case SO_ERROR:
      case SO_SNDBUF:
      case SO_RCVBUF:
      case SO_BROADCAST:
        {
          // - ERROR -
          if (getsockopt(fd,level,optname,optval,&optlen) == -1)
          {
            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_OPERATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(0);

            return false;
          }

          long long int result = *((int *)optval);

          BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
        }
        break;

      default:
        exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_OPTNAME,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  default:
    exception_s::throw_exception(it,module.error_base + c_error_SOCKET_SOCKOPT_INVALID_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_socket_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Socket"),"Socket")
  );

  return true;
}/*}}}*/

bool bic_socket_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Socket");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/
#endif

// - class dummy STREAM -

#define BIC_STREAM_READLN() \
  /*{{{*/\
  const unsigned c_init_buffer_size = 1024;\
\
  /* - target data buffer - */\
  bc_array_s line_buffer;\
  line_buffer.init_size(c_init_buffer_size);\
\
  int ch;\
  do {\
    /* - read next character from file stream - */\
    ch = fgetc(f);\
\
    /* - test end of line - */\
    if (ch == '\n' || ch == EOF)\
      break;\
\
    /* - insert character to line buffer - */\
    line_buffer.push(ch);\
\
  } while(true);\
  /*}}}*/

#define BIC_STREAM_NEXT_ITEM() \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    /* - retrieve pointer to stream - */\
    FILE *f = (FILE *)dst_location->v_data_ptr;\
\
    /* - ERROR - */\
    if (f == nullptr)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
    BIC_STREAM_READLN();\
\
    /* - ERROR - */\
    if (ferror(f))\
    {\
      line_buffer.clear();\
\
      exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
    if (feof(f) && line_buffer.used == 0)\
    {\
      line_buffer.clear();\
\
      BIC_SET_RESULT_BLANK();\
    }\
    else {\
      line_buffer.push('\0');\
\
      /* - return data string - */\
      string_s *string_ptr = it.get_new_string_ptr();\
      string_ptr->data = line_buffer.data;\
      string_ptr->size = line_buffer.used;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
      BIC_SET_RESULT(new_location)\
    }\
\
    return true;\
  }/*}}}*/

location_s *bic_stream_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/

  // - retrieve pointer to stream -
  FILE *f = (FILE *)location_ptr->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  BIC_STREAM_READLN();

  // - ERROR -
  if (ferror(f))
  {
    line_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_ERROR,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  if ((feof(f) && line_buffer.used == 0))
  {
    line_buffer.clear();

    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return ((location_s *)it.blank_location);
  }

  line_buffer.push('\0');

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = line_buffer.data;
  string_ptr->size = line_buffer.used;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);

  return new_location;
}/*}}}*/

bool bic_stream_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write
; @end

  BIC_STREAM_METHOD_WRITE_1();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_stream_method_flush_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to stream -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (fflush(f) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_FLUSH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_stream_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_STREAM_METHOD_READ_0();

  return true;
}/*}}}*/

bool bic_stream_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STREAM_NEXT_ITEM();
}/*}}}*/

bool bic_stream_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
byte_cnt:retrieve_integer
>
method read
; @end

  // - retrieve pointer to stream -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data string -
  string_s data_string;
  data_string.init();
  data_string.create(byte_cnt);

  unsigned read_cnt = fread(data_string.data,1,byte_cnt,f);

  // - ERROR -
  if (read_cnt < byte_cnt)
  {
    data_string.clear();

    exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->swap(data_string);
  data_string.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_stream_method_read_max_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
byte_cnt:retrieve_integer
>
method read_max
; @end

  // - retrieve pointer to stream -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data string -
  string_s data_string;
  data_string.init();
  data_string.create(byte_cnt);

  unsigned read_cnt = fread(data_string.data,1,byte_cnt,f);

  if (read_cnt < byte_cnt)
  {
    // - ERROR -
    if (ferror(f))
    {
      data_string.clear();

      exception_s::throw_exception(it,module.error_base + c_error_STREAM_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - shorten data string -
    data_string.size = read_cnt + 1;
    data_string.data[read_cnt] = '\0';
  }

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->swap(data_string);
  data_string.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_stream_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to stream -
  FILE *f = (FILE *)dst_location->v_data_ptr;

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_STREAM_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  long long int result = _fileno(f);
#else
  long long int result = fileno(f);
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_stream_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STREAM_NEXT_ITEM();
}/*}}}*/

#ifdef ENABLE_CLASS_SOCKET
// - class dummy FD -

#define BIC_FD_READLN() \
/*{{{*/\
\
  /* - initial line buffer size - */\
  const unsigned c_init_buffer_size = 1024;\
\
  /* - create target line buffer - */\
  bc_array_s line_buffer;\
  line_buffer.init_size(c_init_buffer_size);\
\
  char ch;\
  ssize_t read_cnt;\
  do\
  {\
    read_cnt = read(fd,&ch,1);\
\
    /* - test end of line - */\
    if (read_cnt <= 0 || ch == '\n')\
    {\
      break;\
    }\
\
    /* - insert character to line buffer - */\
    line_buffer.push(ch);\
  }\
  while(true);\
/*}}}*/

#define BIC_FD_NEXT_ITEM() \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  /* - retrieve fd - */\
  int fd = (int)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (fd == -1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  BIC_FD_READLN();\
\
  /* - ERROR - */\
  if (read_cnt == -1)\
  {\
    line_buffer.clear();\
\
    exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  if (read_cnt == 0 && line_buffer.used == 0)\
  {\
    line_buffer.clear();\
\
    BIC_SET_RESULT_BLANK();\
  }\
  else\
  {\
    line_buffer.push('\0');\
\
    /* - return data string - */\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->data = line_buffer.data;\
    string_ptr->size = line_buffer.used;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    BIC_SET_RESULT(new_location)\
  }\
\
  return true;\
}/*}}}*/

location_s *bic_fd_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/

  // - retrieve fd -
  int fd = (int)location_ptr->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  BIC_FD_READLN();

  // - ERROR -
  if (read_cnt == -1)
  {
    line_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  if (read_cnt == 0 && line_buffer.used == 0)
  {
    line_buffer.clear();

    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return ((location_s *)it.blank_location);
  }

  line_buffer.push('\0');

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = line_buffer.data;
  string_ptr->size = line_buffer.used;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);

  return new_location;
}/*}}}*/

bool bic_fd_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write
; @end

  // - retrieve fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (data_size > 0)
  {
    long int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = write(fd,(const char *)data_ptr + writed,data_size - writed)) == -1)
      {
        exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    while((writed += cnt) < data_size);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const long int c_buffer_add = 1024;

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  int inq_cnt;
  long int read_cnt;
  do
  {
    data_buffer.reserve(c_buffer_add);
    read_cnt = read(fd,data_buffer.data + data_buffer.used,c_buffer_add);

    // - ERROR -
    if (read_cnt == -1)
    {
      data_buffer.clear();

      exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    data_buffer.used += read_cnt;

    // - ERROR -
    if (ioctl(fd,TIOCINQ,&inq_cnt) == -1)
    {
      data_buffer.clear();

      exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }
  while(inq_cnt > 0);

  // - was any data read -
  if (data_buffer.used == 0)
  {
    data_buffer.clear();

    BIC_SET_RESULT_BLANK();
  }
  else
  {
    data_buffer.push('\0');

    // - return data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = data_buffer.data;
    string_ptr->size = data_buffer.used;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    BIC_SET_RESULT(new_location);
  }

  return true;
}/*}}}*/

bool bic_fd_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FD_NEXT_ITEM();
}/*}}}*/

bool bic_fd_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
byte_cnt:retrieve_integer
>
method read
; @end

  // - retrieve fd -
  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data string -
  string_s data_string;
  data_string.init();
  data_string.create(byte_cnt);

  unsigned readed = 0;
  long int read_cnt;

  do
  {
    read_cnt = read(fd,data_string.data + readed,byte_cnt - readed);

    // - ERROR -
    if (read_cnt == -1)
    {
      data_string.clear();

      exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    readed += read_cnt;
  }
  while(readed < byte_cnt && read_cnt != 0);

  // - ERROR -
  if (readed < byte_cnt)
  {
    data_string.clear();

    exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->swap(data_string);
  data_string.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (int)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fd_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FD_NEXT_ITEM();
}/*}}}*/
#endif

// - class SIGNAL -
built_in_class_s signal_class =
{/*{{{*/
  "Signal",
  c_modifier_public | c_modifier_final,
  5, signal_methods,
  2

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  + 32
#ifndef MSYS2
  + 1
#endif
#endif

  , signal_variables,
  bic_signal_consts,
  bic_signal_init,
  bic_signal_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s signal_methods[] =
{/*{{{*/
  {
    "bind#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_signal_method_bind_2
  },
  {
    "unbind#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_signal_method_unbind_1
  },
  {
    "send#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_signal_method_send_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_signal_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_signal_method_print_0
  },
};/*}}}*/

built_in_variable_s signal_variables[] =
{/*{{{*/
  { "SIGINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGTERM", c_modifier_public | c_modifier_static | c_modifier_static_const },

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  { "SIGHUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGQUIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGILL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGTRAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGABRT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGIOT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGBUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGFPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGKILL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGUSR1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGSEGV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGUSR2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGPIPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGALRM", c_modifier_public | c_modifier_static | c_modifier_static_const },
#ifndef MSYS2
  { "SIGSTKFLT", c_modifier_public | c_modifier_static | c_modifier_static_const },
#endif
  { "SIGCHLD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGCONT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGSTOP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGTSTP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGTTIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGTTOU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGURG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGXCPU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGXFSZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGVTALRM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGPROF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGWINCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGIO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGPOLL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGPWR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGSYS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGRTMIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGRTMAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
#endif

};/*}}}*/

void bic_signal_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert signal numeral identifiers -
  {
    const_locations.push_blanks(signal_class.variable_cnt);
    location_s *cv_ptr = const_locations.data + (const_locations.used - signal_class.variable_cnt);

#define CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGNUM)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)SIGNUM;\
  cv_ptr++;

    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGINT);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGTERM);

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGHUP);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGQUIT);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGILL);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGTRAP);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGABRT);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGIOT);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGBUS);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGFPE);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGKILL);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGUSR1);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGSEGV);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGUSR2);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGPIPE);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGALRM);
#ifndef MSYS2
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGSTKFLT);
#endif
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGCHLD);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGCONT);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGSTOP);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGTSTP);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGTTIN);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGTTOU);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGURG);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGXCPU);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGXFSZ);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGVTALRM);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGPROF);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGWINCH);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGIO);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGPOLL);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGPWR);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGSYS);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGRTMIN);
    CREATE_SIGNAL_NUMERAL_IDENTIFIER(SIGRTMAX);
#endif

  }
}/*}}}*/

void bic_signal_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_signal_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_signal_method_bind_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
signal_number:retrieve_integer
delegate:c_bi_class_delegate
>
class c_bi_class_signal
method bind
static_method
; @end

  // - ERROR -
  if (signal_number < 0 || signal_number > UCHAR_MAX)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_WRONG_SIGNAL_NUMBER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(signal_number);

    return false;
  }

  // - retrieve delegate -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(delegate_ptr->param_cnt);

    return false;
  }

  // - retrieve interpreter reference -
  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);

  // - ERROR -
  if (&it != interpreter.main_thread_ptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_CANNOT_BE_EXECUTED_BY_NON_MAIN_THREAD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_signal,"bind#2");

    return false;
  }

  // - retrieve signal handler locations -
  pointer_array_s &sh_locations = interpreter.signal_handler_locations;

  // - if signal handlers array is not big enough -
  if (signal_number >= sh_locations.used)
  {
    unsigned add_count = (signal_number + 1) - sh_locations.used;

    // - insert blank locations to signal handlers -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(add_count);
    do
    {
      sh_locations.push(it.blank_location);
    }
    while(--add_count > 0);
  }

  // - set new signal handler -
  pointer &sh_location = sh_locations[signal_number];

  src_1_location->v_reference_cnt.atomic_inc();
  it.release_location_ptr((location_s *)sh_location);
  sh_location = (pointer)src_1_location;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_signal_method_unbind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
signal_number:retrieve_integer
>
class c_bi_class_signal
method unbind
static_method
; @end

  // - ERROR -
  if (signal_number < 0 || signal_number > UCHAR_MAX)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_WRONG_SIGNAL_NUMBER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(signal_number);

    return false;
  }

  // - retrieve interpreter reference -
  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);

  // - ERROR -
  if (&it != interpreter.main_thread_ptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_CANNOT_BE_EXECUTED_BY_NON_MAIN_THREAD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_signal,"unbind#1");

    return false;
  }

  // - retrieve signal handler locations -
  pointer_array_s &sh_locations = interpreter.signal_handler_locations;

  // - if signal handlers array is big enough -
  if (signal_number < sh_locations.used)
  {
    pointer &sh_location = sh_locations[signal_number];

    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    it.release_location_ptr((location_s *)sh_location);
    sh_location = it.blank_location;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_signal_method_send_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
target_pid:retrieve_integer
signal_number:retrieve_integer
>
class c_bi_class_signal
method send
static_method
; @end

  // - ERROR -
  if (signal_number < 0 || signal_number > UCHAR_MAX)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_WRONG_SIGNAL_NUMBER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(signal_number);

    return false;
  }

  int result = 0;

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  result = kill(target_pid,signal_number);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_signal,"send#2");

  return false;
#endif

  // - ERROR -
  if (result != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_SEND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_signal_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Signal"),"Signal")
  );

  return true;
}/*}}}*/

bool bic_signal_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Signal");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class POLL -
built_in_class_s poll_class =
{/*{{{*/
  "Poll",
  c_modifier_public | c_modifier_final,
  6, poll_methods,
  6, poll_variables,
  bic_poll_consts,
  bic_poll_init,
  bic_poll_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s poll_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_poll_operator_binary_equal
  },
  {
    "Poll#1",
    c_modifier_public | c_modifier_final,
    bic_poll_method_Poll_1
  },
  {
    "ready#1",
    c_modifier_public | c_modifier_final,
    bic_poll_method_ready_1
  },
  {
    "poll#1",
    c_modifier_public | c_modifier_final,
    bic_poll_method_poll_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_poll_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_poll_method_print_0
  },
};/*}}}*/

built_in_variable_s poll_variables[] =
{/*{{{*/

  // - poll event bits -
  { "POLLIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "POLLPRI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "POLLOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "POLLERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "POLLHUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "POLLNVAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_poll_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert poll event bits constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_POLL_EVENT_BIT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_POLL_EVENT_BIT_BIC_STATIC(POLLIN);
    CREATE_POLL_EVENT_BIT_BIC_STATIC(POLLPRI);
    CREATE_POLL_EVENT_BIT_BIC_STATIC(POLLOUT);
    CREATE_POLL_EVENT_BIT_BIC_STATIC(POLLERR);
    CREATE_POLL_EVENT_BIT_BIC_STATIC(POLLHUP);
    CREATE_POLL_EVENT_BIT_BIC_STATIC(POLLNVAL);
  }
}/*}}}*/

void bic_poll_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (poll_s *)nullptr;
}/*}}}*/

void bic_poll_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve poll pointer -
  poll_s *poll_ptr = (poll_s *)location_ptr->v_data_ptr;

  if (poll_ptr != nullptr)
  {
    poll_ptr->clear(it);
    cfree(poll_ptr);
  }
}/*}}}*/

bool bic_poll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_poll_method_Poll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fds:c_bi_class_array
>
method Poll
; @end

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_POLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - allocate pollfd structures -
  pollfd *fds = nullptr;
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  ULONG nfds = array_ptr->used >> 1;
#else
  nfds_t nfds = array_ptr->used >> 1;
#endif

  if (array_ptr->used > 0)
  {
    fds = (pollfd *)cmalloc(nfds*sizeof(pollfd));

    // - fill pollfd structures -
    pointer *p_ptr = array_ptr->data;
    pointer *p_ptr_end = p_ptr + array_ptr->used;
    pollfd *fd_ptr = fds;
    do {
      location_s *fd_location = it.get_location_value(p_ptr[0]);
      location_s *events_location = it.get_location_value(p_ptr[1]);

      // - ERROR -
      if (fd_location->v_type != c_bi_class_integer ||
          events_location->v_type != c_bi_class_integer)
      {
        cfree(fds);

        exception_s::throw_exception(it,module.error_base + c_error_POLL_WRONG_FD_OR_EVENTS_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - fill pollfd structure -
      fd_ptr->fd = (long long int)fd_location->v_data_ptr;
      fd_ptr->events = (long long int)events_location->v_data_ptr;
      fd_ptr->revents = 0;

    } while(++fd_ptr,(p_ptr += 2) < p_ptr_end);
  }

  poll_s *poll_ptr = (poll_s *)cmalloc(sizeof(poll_s));
  poll_ptr->init();

  poll_ptr->fds = fds;
  poll_ptr->nfds = nfds;

  dst_location->v_data_ptr = (poll_s *)poll_ptr;

  return true;
}/*}}}*/

bool bic_poll_method_ready_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
timeout:retrieve_integer
>
method ready
; @end

  // - retrieve poll object -
  poll_s *poll_ptr = (poll_s *)dst_location->v_data_ptr;

  // - call poll function -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  int res = poll_ptr->nfds > 0 ? WSAPoll(poll_ptr->fds,poll_ptr->nfds,timeout) : 0;
#else
  int res = poll(poll_ptr->fds,poll_ptr->nfds,timeout);
#endif

  // - ERROR -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  if (res == SOCKET_ERROR)
#else
  if (res == -1)
#endif
  {
    exception_s::throw_exception(it,module.error_base + c_error_POLL_POLL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = res != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_poll_method_poll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
timeout:retrieve_integer
>
method poll
; @end

  // - retrieve poll object -
  poll_s *poll_ptr = (poll_s *)dst_location->v_data_ptr;

  // - call poll function -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  int res = WSAPoll(poll_ptr->fds,poll_ptr->nfds,timeout);
#else
  int res = poll(poll_ptr->fds,poll_ptr->nfds,timeout);
#endif

  switch (res)
  {
    // - ERROR -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
    case SOCKET_ERROR:
#else
    case -1:
#endif
    {
      exception_s::throw_exception(it,module.error_base + c_error_POLL_POLL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    case 0:
      BIC_SET_RESULT_BLANK();
      break;

    default:
    {
      pointer_array_s *array_ptr = it.get_new_array_ptr();

      pollfd *fd_ptr = poll_ptr->fds;
      pollfd *fd_ptr_end = fd_ptr + poll_ptr->nfds;
      do {
        long long int revents = fd_ptr->revents;

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,revents);
        array_ptr->push(new_location);
      } while(++fd_ptr < fd_ptr_end);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
      BIC_SET_RESULT(new_location);
    }
  }

  return true;
}/*}}}*/

bool bic_poll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Poll"),"Poll")
  );

  return true;
}/*}}}*/

bool bic_poll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Poll");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TIMER -
built_in_class_s timer_class =
{/*{{{*/
  "Timer",
  c_modifier_public | c_modifier_final,
  9, timer_methods,
  0, timer_variables,
  bic_timer_consts,
  bic_timer_init,
  bic_timer_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s timer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_timer_operator_binary_equal
  },
  {
    "Timer#0",
    c_modifier_public | c_modifier_final,
    bic_timer_method_Timer_0
  },
  {
    "schedule#3",
    c_modifier_public | c_modifier_final,
    bic_timer_method_schedule_3
  },
  {
    "cancel#1",
    c_modifier_public | c_modifier_final,
    bic_timer_method_cancel_1
  },
  {
    "process#0",
    c_modifier_public | c_modifier_final,
    bic_timer_method_process_0
  },
  {
    "remain#0",
    c_modifier_public | c_modifier_final,
    bic_timer_method_remain_0
  },
  {
    "timeout#0",
    c_modifier_public | c_modifier_final,
    bic_timer_method_timeout_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_timer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_timer_method_print_0
  },
};/*}}}*/

built_in_variable_s timer_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_timer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_timer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (timer_s *)nullptr;
}/*}}}*/

void bic_timer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve timer pointer -
  timer_s *timer_ptr = (timer_s *)location_ptr->v_data_ptr;

  // - if timer pointer is not null release it -
  if (timer_ptr != nullptr)
  {
    timer_ptr->clear(it);
    cfree(timer_ptr);
  }

}/*}}}*/

bool bic_timer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_timer_method_Timer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create timer object -
  timer_s *timer_ptr = (timer_s *)cmalloc(sizeof(timer_s));
  timer_ptr->init();

  dst_location->v_data_ptr = (timer_s *)timer_ptr;

  return true;
}/*}}}*/

bool bic_timer_method_schedule_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
delay:retrieve_integer
delegate:c_bi_class_delegate
user_data:ignore
>
method schedule
; @end

  // - ERROR -
  if (delay < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TIMER_NEGATIVE_DELAY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(delay);

    return false;
  }

  timer_s *timer_ptr = (timer_s *)dst_location->v_data_ptr;

  // - retrieve delegate -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TIMER_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - reference timer record values -
  src_1_location->v_reference_cnt.atomic_inc();
  src_2_location->v_reference_cnt.atomic_inc();

  timer_record_s record;
  record.set(timer_s::get_stamp() + delay,src_1_location,src_2_location);

  // - insert record to timer records list -
  long long int result = timer_ptr->records.swap_insert(record);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_timer_method_cancel_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method cancel
; @end

  timer_record_rb_tree_s &records = ((timer_s *)dst_location->v_data_ptr)->records;

  // - ERROR -
  if (index < 0 || index >= records.used || !records.data[index].valid)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TIMER_INVALID_TIMER_RECORD_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  timer_record_s &record = records.data[index].object;

  // - release record callback delegate -
  it.release_location_ptr((location_s *)record.callback_dlg);

  // - release record callback parameter -
  it.release_location_ptr((location_s *)record.parameter);

  // - remove record from records list -
  records.remove(index);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_timer_method_remain_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  timer_s *timer_ptr = (timer_s *)dst_location->v_data_ptr;
  timer_record_rb_tree_s &records = timer_ptr->records;

  if (records.root_idx != c_idx_not_exist)
  {
    unsigned r_idx = records.get_min_value_idx(records.root_idx);
    timer_record_s &record = records.data[r_idx].object;

    long long int result = record.target_stamp - timer_s::get_stamp();
    if (result < 0) { result = 0; }

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_timer_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  timer_s *timer_ptr = (timer_s *)dst_location->v_data_ptr;
  timer_record_rb_tree_s &records = timer_ptr->records;

  long long int result;

  if (records.root_idx != c_idx_not_exist)
  {
    unsigned r_idx = records.get_min_value_idx(records.root_idx);
    timer_record_s &record = records.data[r_idx].object;

    result = record.target_stamp - timer_s::get_stamp();
    if (result < 0) { result = 0; }
  }
  else
  {
    result = LLONG_MAX;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_timer_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  timer_s *timer_ptr = (timer_s *)dst_location->v_data_ptr;
  timer_record_rb_tree_s &records = timer_ptr->records;

  // - if some timer records exists -
  if (records.root_idx != c_idx_not_exist)
  {
    // - get actual time stamp -
    long long int stamp = timer_s::get_stamp();

    // - process all timer records -
    unsigned next_idx = records.get_min_value_idx(records.root_idx);
    do {
      unsigned r_idx = next_idx;
      next_idx = records.get_next_idx(r_idx);

      // - retrieve timer record -
      timer_record_s &record = records.data[r_idx].object;

      // - if timer record stamp was reached -
      if (stamp >= record.target_stamp)
      {
        delegate_s *delegate_ptr = (delegate_s *)((location_s *)record.callback_dlg)->v_data_ptr;

        location_s *trg_location;
        BIC_CALL_DELEGATE(it,delegate_ptr,&record.parameter,1,trg_location,operands[c_source_pos_idx],

          // - release callback locations -
          it.release_location_ptr((location_s *)record.callback_dlg);
          it.release_location_ptr((location_s *)record.parameter);

          // - remove timer record -
          records.remove(r_idx);

          return false;
        );

        it.release_location_ptr(trg_location);

        // - release callback locations -
        it.release_location_ptr((location_s *)record.callback_dlg);
        it.release_location_ptr((location_s *)record.parameter);

        // - remove timer record -
        records.remove(r_idx);
      }
      else
      {
        break;
      }
    } while(next_idx != c_idx_not_exist);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_timer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Timer"),"Timer")
  );

  return true;
}/*}}}*/

bool bic_timer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Timer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

#ifdef ENABLE_CLASS_CLOCK
// - class CLOCK -
built_in_class_s clock_class =
{/*{{{*/
  "Clock",
  c_modifier_public | c_modifier_final,
  5, clock_methods,
  4, clock_variables,
  bic_clock_consts,
  bic_clock_init,
  bic_clock_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s clock_methods[] =
{/*{{{*/
  {
    "getres#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_clock_method_getres_1
  },
  {
    "gettime#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_clock_method_gettime_1
  },
  {
    "settime#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_clock_method_settime_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_clock_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_clock_method_print_0
  },
};/*}}}*/

built_in_variable_s clock_variables[] =
{/*{{{*/
  { "CLOCK_REALTIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLOCK_MONOTONIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLOCK_PROCESS_CPUTIME_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLOCK_THREAD_CPUTIME_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_clock_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(4);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_CLOCK_TYPE_ID_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

  CREATE_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_REALTIME);
  CREATE_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_MONOTONIC);
  CREATE_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_PROCESS_CPUTIME_ID);
  CREATE_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_THREAD_CPUTIME_ID);
}/*}}}*/

void bic_clock_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_clock_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_clock_method_getres_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
clock_id:retrieve_integer
>
class c_bi_class_clock
method getres
static_method
; @end

  timespec res;

  // - ERROR -
  if (clock_getres(clock_id,&res) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CLOCK_CANNOT_GET_RESOLUTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = (res.tv_sec*1000000000LL) + res.tv_nsec;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_clock_method_gettime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
clock_id:retrieve_integer
>
class c_bi_class_clock
method gettime
static_method
; @end

  timespec tp;

  // - ERROR -
  if (clock_gettime(clock_id,&tp) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CLOCK_CANNOT_GET_TIME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = (tp.tv_sec*1000000000LL) + tp.tv_nsec;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_clock_method_settime_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
clock_id:retrieve_integer
time:retrieve_integer
>
class c_bi_class_clock
method settime
static_method
; @end

#ifdef LINUX
  timespec tp;
  tp.tv_sec = time / 1000000000LL;
  tp.tv_nsec = time % 1000000000LL;

  // - ERROR -
  if (clock_settime(clock_id,&tp) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CLOCK_CANNOT_SET_TIME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_clock,"settime#2");

  return false;
#endif

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_clock_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Clock"),"Clock")
  );

  return true;
}/*}}}*/

bool bic_clock_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Clock");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/
#endif

