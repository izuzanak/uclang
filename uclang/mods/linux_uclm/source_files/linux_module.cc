
@begin
include "linux_module.h"
@end

// - LINUX indexes of built in classes -
unsigned c_bi_class_linux = c_idx_not_exist;
unsigned c_bi_class_fd = c_idx_not_exist;
unsigned c_bi_class_timer_fd = c_idx_not_exist;
unsigned c_bi_class_mmap = c_idx_not_exist;

// - LINUX module -
EXPORT built_in_module_s module =
{/*{{{*/
  4,                     // Class count
  linux_classes,         // Classes
  0,                     // Error base index
  30,                    // Error count
  linux_error_strings,   // Error strings
  linux_initialize,      // Initialize function
  linux_print_exception, // Print exceptions function
};/*}}}*/

// - LINUX classes -
built_in_class_s *linux_classes[] =
{/*{{{*/
  &linux_class,
  &fd_class,
  &timer_fd_class,
  &mmap_class,
};/*}}}*/

// - LINUX error strings -
const char *linux_error_strings[] =
{/*{{{*/
  "error_LINUX_SYSCONF_ERROR",
  "error_FD_DUPLICATE_ERROR",
  "error_FD_OPEN_ERROR",
  "error_FD_CREATE_ERROR",
  "error_FD_CLOSE_ERROR",
  "error_FD_WRITE_INVALID_SOURCE_OFFSET",
  "error_FD_OPERATION_INVALID_IOV_SEGMENT_COUNT",
  "error_FD_WRITE_INVALID_IOV_SEGMENT_DATA_TYPE",
  "error_FD_WRITE_ERROR",
  "error_FD_READ_INVALID_BYTE_COUNT",
  "error_FD_READ_INVALID_IOV_SEGMENT_SIZE",
  "error_FD_READ_ERROR",
  "error_FD_SYNC_ERROR",
  "error_FD_ADVISE_ERROR",
  "error_FD_SEEK_ERROR",
  "error_FD_IOCTL_INVALID_ARGUMENT_TYPE",
  "error_FD_IOCTL_UNKNOWN_REQUEST",
  "error_FD_IOCTL_ERROR",
  "error_FD_FLOCK_ERROR",
  "error_FD_NOT_OPENED",
  "error_TIMER_FD_CREATE_ERROR",
  "error_TIMER_FD_SETTIME_ERROR",
  "error_TIMER_FD_EXP_COUNTER_READ_ERROR",
  "error_MMAP_INVALID_OFFSET",
  "error_MMAP_INVALID_LENGTH",
  "error_MMAP_CREATE_ERROR",
  "error_MMAP_REMAP_ERROR",
  "error_MMAP_PROTECT_ERROR",
  "error_MMAP_SYNC_ERROR",
  "error_MMAP_ADVISE_ERROR",
};/*}}}*/

// - LINUX initialize -
bool linux_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize linux class identifier -
  c_bi_class_linux = class_base_idx++;

  // - initialize fd class identifier -
  c_bi_class_fd = class_base_idx++;

  // - initialize timer_fd class identifier -
  c_bi_class_timer_fd = class_base_idx++;

  // - initialize mmap class identifier -
  c_bi_class_mmap = class_base_idx++;

  return true;
}/*}}}*/

// - LINUX print exception -
bool linux_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_LINUX_SYSCONF_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLinux sysconf error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_DUPLICATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot duplicate file descriptor %d: ",(int)exception.params[0]);
    errno = exception.params[1];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open file \"%s\": ",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create file \"%s\": ",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor close error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_WRITE_INVALID_SOURCE_OFFSET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor operation, invalid source data offset %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_OPERATION_INVALID_IOV_SEGMENT_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor operation, invalid count of iov segments %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_WRITE_INVALID_IOV_SEGMENT_DATA_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor write, invalid iov segment data type, expected String\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor write error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_READ_INVALID_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor read, invalid count of bytes to read %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_READ_INVALID_IOV_SEGMENT_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor read, invalid iov segment size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor read error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_SYNC_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor sync error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_ADVISE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor advise error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_SEEK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor seek error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_IOCTL_INVALID_ARGUMENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor ioctl invalid argument type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_IOCTL_UNKNOWN_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor ioctl unknown request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_IOCTL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor ioctl error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_FLOCK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor flock error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FD_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIMER_FD_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating TimerFd\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIMER_FD_SETTIME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while setting TimerFd time\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIMER_FD_EXP_COUNTER_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading TimerFd expiration counter\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_INVALID_OFFSET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap operation, invalid data offset %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_INVALID_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap operation, invalid data length %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap error while mapping resource to memory: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_REMAP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap remap error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_PROTECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap protect error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_SYNC_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap sync error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MMAP_ADVISE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMmap advise error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class LINUX -
built_in_class_s linux_class =
{/*{{{*/
  "Linux",
  c_modifier_public | c_modifier_final,
  4, linux_methods,
  14, linux_variables,
  bic_linux_consts,
  bic_linux_init,
  bic_linux_clear,
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

built_in_method_s linux_methods[] =
{/*{{{*/
  {
    "sync#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_linux_method_sync_0
  },
  {
    "sysconf#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_linux_method_sysconf_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_linux_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_linux_method_print_0
  },
};/*}}}*/

built_in_variable_s linux_variables[] =
{/*{{{*/

  // - sysconf variable identifiers -
  { "ARG_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CHILD_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HOST_NAME_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOGIN_NAME_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NGROUPS_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLK_TCK",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PAGESIZE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RE_DUP_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STREAM_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SYMLOOP_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TTY_NAME_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TZNAME_MAX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VERSION",  c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_linux_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert sysconf variable identifiers -
  {
    const_locations.push_blanks(14);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 14);

#define CREATE_LINUX_SYSCONF_ID_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_ARG_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_CHILD_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_HOST_NAME_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_LOGIN_NAME_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_NGROUPS_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_CLK_TCK);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_OPEN_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_PAGESIZE);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_RE_DUP_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_STREAM_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_SYMLOOP_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_TTY_NAME_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_TZNAME_MAX);
    CREATE_LINUX_SYSCONF_ID_BIC_STATIC(_SC_VERSION);
  }

}/*}}}*/

void bic_linux_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_linux_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_linux_method_sync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  sync();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_linux_method_sysconf_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:retrieve_integer
>
class c_bi_class_linux
method sysconf
static_method
; @end

  errno = 0;
  long long int result = sysconf(name);

  if (result == -1)
  {
    // - ERROR -
    if (errno != 0)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LINUX_SYSCONF_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(errno);

      return false;
    }

    BIC_SET_RESULT_BLANK();
  }
  else
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }

  return true;
}/*}}}*/

bool bic_linux_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Linux"),"Linux")
  );

  return true;
}/*}}}*/

bool bic_linux_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Linux");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FD -
built_in_class_s fd_class =
{/*{{{*/
  "Fd",
  c_modifier_public | c_modifier_final,
  25
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
  + 2
#endif
  , fd_methods,
  16 + 12 + 1 + 4 + 1 + 3 + 6
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,16,0)
  + 5
#endif
  , fd_variables,
  bic_fd_consts,
  bic_fd_init,
  bic_fd_clear,
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

built_in_method_s fd_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fd_operator_binary_equal
  },
  {
    "Fd#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_Fd_1
  },
  {
    "open#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fd_method_open_3
  },
  {
    "creat#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fd_method_creat_2
  },
  {
    "ioctl#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_ioctl_2
  },
  {
    "ioctl#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fd_method_ioctl_3
  },
  {
    "flock#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_flock_1
  },
  {
    "openat#3",
    c_modifier_public | c_modifier_final,
    bic_fd_method_openat_3
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_close_0
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_write_2
  },
  {
    "write_all#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_write_all_1
  },
  {
    "pwrite#3",
    c_modifier_public | c_modifier_final,
    bic_fd_method_pwrite_3
  },
  {
    "pwrite_all#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_pwrite_all_2
  },
  {
    "writev#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_writev_1
  },
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
  {
    "pwritev2#3",
    c_modifier_public | c_modifier_final,
    bic_fd_method_pwritev2_3
  },
#endif
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_read_1
  },
  {
    "pread#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_pread_2
  },
  {
    "readv#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_readv_1
  },
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
  {
    "preadv2#3",
    c_modifier_public | c_modifier_final,
    bic_fd_method_preadv2_3
  },
#endif
  {
    "sync#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_sync_0
  },
  {
    "datasync#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_datasync_0
  },
  {
    "advise#1",
    c_modifier_public | c_modifier_final,
    bic_fd_method_advise_1
  },
  {
    "seek#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_seek_2
  },
  {
    "mmap#4",
    c_modifier_public | c_modifier_final,
    bic_fd_method_mmap_4
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_get_fd_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fd_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fd_method_print_0
  },
};/*}}}*/

built_in_variable_s fd_variables[] =
{/*{{{*/

  // - file open flags -
  { "O_RDONLY",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_WRONLY",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_RDWR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_APPEND",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_ASYNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_CLOEXEC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_CREAT",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_DIRECT",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_DIRECTORY",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_EXCL",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_LARGEFILE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_NOATIME",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_NOCTTY",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_NONBLOCK",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_SYNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "O_TRUNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - file open modes -
  { "S_IRWXU",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IRUSR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IWUSR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IXUSR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IRWXG",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IRGRP",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IWGRP",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IXGRP",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IRWXO",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IROTH",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IWOTH",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IXOTH",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - ioctl requests -
  { "FIONBIO",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - flock operations -
  { "LOCK_SH",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOCK_EX",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOCK_NB",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOCK_UN",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - special file descriptor values -
  { "AT_FDCWD",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - file seek whence values -
  { "SEEK_SET",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_CUR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_END",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - file advise flag values -
  { "FADV_NORMAL",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FADV_RANDOM",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FADV_SEQUENTIAL",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FADV_WILLNEED",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FADV_DONTNEED",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FADV_NOREUSE",  c_modifier_public | c_modifier_static | c_modifier_static_const },

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,16,0)
  // - per call read/write flag values -
  { "RWF_HIPRI",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RWF_DSYNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RWF_SYNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RWF_NOWAIT",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RWF_APPEND",  c_modifier_public | c_modifier_static | c_modifier_static_const },
#endif

};/*}}}*/

#define BIC_FD_METHOD_IOCTL(VALUE_LOCATION) \
{/*{{{*/\
  char arg[32];\
\
  switch (request)\
  {\
  case FIONBIO:\
    {\
      long long int argument;\
\
      /* - ERROR - */\
      if (!it.retrieve_integer(VALUE_LOCATION,argument))\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_FD_IOCTL_INVALID_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
\
      *((int *)arg) = argument;\
    }\
    break;\
\
  default:\
    exception_s::throw_exception(it,module.error_base + c_error_FD_IOCTL_UNKNOWN_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (ioctl(fd,request,arg) == -1)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_IOCTL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(errno);\
\
    return false;\
  }\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

#define BIC_FD_METHOD_WRITE_READ_RELEASE_IOV() \
{/*{{{*/\
  if (array_ptr->used > 32)\
  {\
    cfree(iov_data);\
  }\
}/*}}}*/

#define BIC_FD_METHOD_WRITEV(CODE) \
/*{{{*/\
\
  /* - ERROR - */\
  if (array_ptr->used <= 0 || array_ptr->used > IOV_MAX)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_OPERATION_INVALID_IOV_SEGMENT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(array_ptr->used);\
\
    return false;\
  }\
\
  iovec iov_stack[32];\
  iovec *iov_data = iov_stack;\
\
  if (array_ptr->used > 32)\
  {\
    iov_data = (iovec *)cmalloc(array_ptr->used*sizeof(iovec));\
  }\
\
  pointer *p_ptr = array_ptr->data;\
  pointer *p_ptr_end = p_ptr + array_ptr->used;\
  iovec *iov_ptr = iov_data;\
  do {\
    location_s *item_location = it.get_location_value(*p_ptr);\
\
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_string)\
    {\
      BIC_FD_METHOD_WRITE_READ_RELEASE_IOV();\
\
      exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_INVALID_IOV_SEGMENT_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
    string_s *string_ptr = (string_s *)item_location->v_data_ptr;\
    iov_ptr->iov_base = string_ptr->data;\
    iov_ptr->iov_len = string_ptr->size - 1;\
\
  } while(++iov_ptr,++p_ptr < p_ptr_end);\
\
  /* - write to file descriptor - */\
  CODE;\
\
  /* - ERROR - */\
  if (cnt == -1)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(errno);\
\
    BIC_FD_METHOD_WRITE_READ_RELEASE_IOV();\
\
    return false;\
  }\
\
  BIC_FD_METHOD_WRITE_READ_RELEASE_IOV();\
\
  long long int result = cnt;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
/*}}}*/

#define BIC_FD_METHOD_READV_ERROR_RELEASE() \
{/*{{{*/\
  it.release_location_ptr(result_array_loc);\
  BIC_FD_METHOD_WRITE_READ_RELEASE_IOV()\
}/*}}}*/

#define BIC_FD_METHOD_READV(CODE) \
/*{{{*/\
\
  /* - ERROR - */\
  if (array_ptr->used <= 0 || array_ptr->used > IOV_MAX)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_OPERATION_INVALID_IOV_SEGMENT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(array_ptr->used);\
\
    return false;\
  }\
\
  iovec iov_stack[32];\
  iovec *iov_data = iov_stack;\
\
  if (array_ptr->used > 32)\
  {\
    iov_data = (iovec *)cmalloc(array_ptr->used*sizeof(iovec));\
  }\
\
  pointer_array_s *result_array_ptr = it.get_new_array_ptr();\
  BIC_CREATE_NEW_LOCATION(result_array_loc,c_bi_class_array,result_array_ptr);\
\
  pointer *p_ptr = array_ptr->data;\
  pointer *p_ptr_end = p_ptr + array_ptr->used;\
  iovec *iov_ptr = iov_data;\
  ssize_t request_cnt = 0;\
  do {\
    location_s *item_location = it.get_location_value(*p_ptr);\
\
    long long int count;\
\
    /* - ERROR - */\
    if (!it.retrieve_integer(item_location,count) || count <= 0)\
    {\
      BIC_FD_METHOD_READV_ERROR_RELEASE();\
\
      exception_s::throw_exception(it,module.error_base + c_error_FD_READ_INVALID_IOV_SEGMENT_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->create(count);\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    result_array_ptr->push(new_location);\
\
    iov_ptr->iov_base = string_ptr->data;\
    iov_ptr->iov_len = count;\
\
    request_cnt += count;\
\
  } while(++iov_ptr,++p_ptr < p_ptr_end);\
\
  /* - read from file descriptor - */\
  CODE;\
\
  /* - ERROR - */\
  if (cnt == -1)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(errno);\
\
    BIC_FD_METHOD_READV_ERROR_RELEASE();\
\
    return false;\
  }\
\
  BIC_FD_METHOD_WRITE_READ_RELEASE_IOV();\
\
  if (cnt < request_cnt)\
  {\
    /* - find string on read count boundary - */\
    pointer *p_ptr = result_array_ptr->data;\
    pointer *p_ptr_end = p_ptr + result_array_ptr->used;\
    ssize_t output_cnt = 0;\
    do {\
      string_s *string_ptr = (string_s *)((location_s *)*p_ptr)->v_data_ptr;\
      ssize_t string_length = string_ptr->size - 1;\
\
      /* - truncate string at read count boundary - */\
      if (output_cnt + string_length >= cnt)\
      {\
        string_ptr->size = (cnt - output_cnt) + 1;\
        break;\
      }\
\
      output_cnt += string_length;\
    } while(++p_ptr < p_ptr_end);\
\
    /* - clear all strings after read count boundary - */\
    while (++p_ptr < p_ptr_end)\
    {\
      string_s *string_ptr = (string_s *)((location_s *)*p_ptr)->v_data_ptr;\
      string_ptr->clear();\
    }\
  }\
\
  BIC_SET_RESULT(result_array_loc);\
\
  return true;\
/*}}}*/

void bic_fd_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert file open flags -
  {
    const_locations.push_blanks(16);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 16);

#define CREATE_FD_OPEN_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_RDONLY);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_WRONLY);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_RDWR);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_APPEND);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_ASYNC);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_CLOEXEC);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_CREAT);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_DIRECT);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_DIRECTORY);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_EXCL);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_LARGEFILE);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_NOATIME);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_NOCTTY);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_NONBLOCK);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_SYNC);
    CREATE_FD_OPEN_FLAG_BIC_STATIC(O_TRUNC);
  }

  // - insert file open modes -
  {
    const_locations.push_blanks(12);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 12);

#define CREATE_FD_OPEN_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IRWXU);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IRUSR);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IWUSR);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IXUSR);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IRWXG);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IRGRP);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IWGRP);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IXGRP);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IRWXO);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IROTH);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IWOTH);
    CREATE_FD_OPEN_MODE_BIC_STATIC(S_IXOTH);
  }

  // - insert ioctl requests -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_FD_IOCTL_REQUEST_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_IOCTL_REQUEST_BIC_STATIC(FIONBIO);
  }

  // - insert flock operations -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_FD_IOCTL_REQUEST_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_IOCTL_REQUEST_BIC_STATIC(LOCK_SH);
    CREATE_FD_IOCTL_REQUEST_BIC_STATIC(LOCK_EX);
    CREATE_FD_IOCTL_REQUEST_BIC_STATIC(LOCK_NB);
    CREATE_FD_IOCTL_REQUEST_BIC_STATIC(LOCK_UN);
  }

  // - insert special file descriptor values -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_FD_SPECIAL_VALUE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_SPECIAL_VALUE_BIC_STATIC(AT_FDCWD);
  }

  // - insert file seek whence values -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_FD_SEEK_WHENCE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_SEEK_WHENCE_BIC_STATIC(SEEK_SET);
    CREATE_FD_SEEK_WHENCE_BIC_STATIC(SEEK_CUR);
    CREATE_FD_SEEK_WHENCE_BIC_STATIC(SEEK_END);
  }

  // - insert file advise flag values -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_FD_ADVISE_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_ADVISE_FLAG_BIC_STATIC(POSIX_FADV_NORMAL);
    CREATE_FD_ADVISE_FLAG_BIC_STATIC(POSIX_FADV_RANDOM);
    CREATE_FD_ADVISE_FLAG_BIC_STATIC(POSIX_FADV_SEQUENTIAL);
    CREATE_FD_ADVISE_FLAG_BIC_STATIC(POSIX_FADV_WILLNEED);
    CREATE_FD_ADVISE_FLAG_BIC_STATIC(POSIX_FADV_DONTNEED);
    CREATE_FD_ADVISE_FLAG_BIC_STATIC(POSIX_FADV_NOREUSE);
  }

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,16,0)
  // - insert per call read/write flag values -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_FD_PER_CALL_RW_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FD_PER_CALL_RW_FLAG_BIC_STATIC(RWF_HIPRI);
    CREATE_FD_PER_CALL_RW_FLAG_BIC_STATIC(RWF_DSYNC);
    CREATE_FD_PER_CALL_RW_FLAG_BIC_STATIC(RWF_SYNC);
    CREATE_FD_PER_CALL_RW_FLAG_BIC_STATIC(RWF_NOWAIT);
    CREATE_FD_PER_CALL_RW_FLAG_BIC_STATIC(RWF_APPEND);
  }
#endif

}/*}}}*/

void bic_fd_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (int)-1;
}/*}}}*/

void bic_fd_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  int fd = (int)location_ptr->v_data_ptr;

  if (fd != -1)
  {
    close(fd);
  }
}/*}}}*/

bool bic_fd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fd_method_Fd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int src_fd;

  if (!it.retrieve_integer(src_0_location,src_fd))
  {
    if (src_0_location->v_type == c_bi_class_fd)
    {
      src_fd = (int)src_0_location->v_data_ptr;
    }
    else
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("Fd#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  // - duplicate file descriptor -
  int fd = dup(src_fd);

  // - ERROR -
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_DUPLICATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(fd);
    new_exception->params.push(errno);

    return false;
  }

  dst_location->v_data_ptr = (int)fd;

  return true;
}/*}}}*/

bool bic_fd_method_open_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
flags:retrieve_integer
mode:retrieve_integer
>
class c_bi_class_fd
method open
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  int fd = open(string_ptr->data,flags,mode);
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fd,fd);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_creat_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
mode:retrieve_integer
>
class c_bi_class_fd
method creat
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  int fd = creat(string_ptr->data,mode);
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fd,fd);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_ioctl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
request:retrieve_integer
value:ignore
>
method ioctl
; @end

  int fd = (int)dst_location->v_data_ptr;

  BIC_FD_METHOD_IOCTL(src_1_location);

  return true;
}/*}}}*/

bool bic_fd_method_ioctl_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
request:retrieve_integer
value:ignore
>
class c_bi_class_fd
method ioctl
static_method
; @end

  BIC_FD_METHOD_IOCTL(src_2_location);

  return true;
}/*}}}*/

bool bic_fd_method_flock_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
operation:retrieve_integer
>
method flock
; @end

  int fd = (int)dst_location->v_data_ptr;

  long long int result = 1;

  if (flock(fd,operation) != 0)
  {
    switch (errno)
    {
      case EINTR:
      case EWOULDBLOCK:
        result = 0;
        break;

      // - ERROR -
      default:
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_FLOCK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(errno);

        return false;
      }
    }
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fd_method_openat_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
flags:retrieve_integer
mode:retrieve_integer
>
method openat
; @end

  int dirfd = (int)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  int fd = openat(dirfd,string_ptr->data,flags,mode);
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fd,fd);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (close(fd) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  // - reset file descriptor value -
  dst_location->v_data_ptr = (int)-1;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
from:retrieve_integer
>
method write
; @end

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (from < 0 || from > data_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_INVALID_SOURCE_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(from);

    return false;
  }

  // - write to file descriptor -
  long int cnt = write(fd,(const char *)data_ptr + from,data_size - from);

  // - ERROR -
  if (cnt == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  long long int result = cnt;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fd_method_write_all_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write_all
; @end

  int fd = (int)dst_location->v_data_ptr;

  if (data_size > 0)
  {
    long int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = write(fd,(const char *)data_ptr + writed,data_size - writed)) == -1)
      {
        // - if interrupted by signal -
        if (errno == EINTR)
        {
          continue;
        }

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(errno);

        return false;
      }
      else
      {
        writed += cnt;
      }
    }
    while(writed < data_size);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_pwrite_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
from:retrieve_integer
offset:retrieve_integer
>
method pwrite
; @end

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (from < 0 || from > data_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_INVALID_SOURCE_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(from);

    return false;
  }

  // - write to file descriptor -
  long int cnt = pwrite(fd,(const char *)data_ptr + from,data_size - from,offset);

  // - ERROR -
  if (cnt == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  long long int result = cnt;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fd_method_pwrite_all_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
offset:retrieve_integer
>
method pwrite_all
; @end

  int fd = (int)dst_location->v_data_ptr;

  if (data_size > 0)
  {
    long int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = pwrite(fd,(const char *)data_ptr + writed,data_size - writed,offset + writed)) == -1)
      {
        // - if interrupted by signal -
        if (errno == EINTR)
        {
          continue;
        }

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(errno);

        return false;
      }
      else
      {
        writed += cnt;
      }
    }
    while(writed < data_size);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_writev_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data_array:c_bi_class_array
>
method writev
; @end

  int fd = (int)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  BIC_FD_METHOD_WRITEV(
    ssize_t cnt = writev(fd,iov_data,array_ptr->used);
  );
}/*}}}*/

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
bool bic_fd_method_pwritev2_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data_array:c_bi_class_array
offset:retrieve_integer
flags:retrieve_integer
>
method pwritev2
; @end

  int fd = (int)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  BIC_FD_METHOD_WRITEV(
    ssize_t cnt = pwritev2(fd,iov_data,array_ptr->used,offset,flags);
  );
}/*}}}*/
#endif

bool bic_fd_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
count:retrieve_integer
>
method read
; @end

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (count < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_INVALID_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(count);

    return false;
  }

  char *buffer = (char *)cmalloc(count + 1);

  // - read from file descriptor -
  long int cnt = read(fd,buffer,count);

  // - ERROR -
  if (cnt == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    cfree(buffer);

    return false;
  }

  if (cnt > 0 || count == 0)
  {
    buffer[cnt] = '\0';

    // - return data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = buffer;
    string_ptr->size = cnt + 1;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    BIC_SET_RESULT(new_location);
  }
  else
  {
    cfree(buffer);

    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_fd_method_pread_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
count:retrieve_integer
offset:retrieve_integer
>
method pread
; @end

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (count < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_INVALID_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(count);

    return false;
  }

  char *buffer = (char *)cmalloc(count + 1);

  // - read from file descriptor -
  long int cnt = pread(fd,buffer,count,offset);

  // - ERROR -
  if (cnt == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    cfree(buffer);

    return false;
  }

  if (cnt > 0 || count == 0)
  {
    buffer[cnt] = '\0';

    // - return data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = buffer;
    string_ptr->size = cnt + 1;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    BIC_SET_RESULT(new_location);
  }
  else
  {
    cfree(buffer);

    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_fd_method_readv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
count_array:c_bi_class_array
>
method readv
; @end

  int fd = (int)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  BIC_FD_METHOD_READV(
    ssize_t cnt = readv(fd,iov_data,array_ptr->used);
  );
}/*}}}*/

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
bool bic_fd_method_preadv2_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
count_array:c_bi_class_array
offset:retrieve_integer
flags:retrieve_integer
>
method preadv2
; @end

  int fd = (int)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  BIC_FD_METHOD_READV(
    ssize_t cnt = preadv2(fd,iov_data,array_ptr->used,offset,flags);
  );
}/*}}}*/
#endif

bool bic_fd_method_sync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fsync(fd) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_SYNC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_datasync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fdatasync(fd) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_SYNC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_advise_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
advice:retrieve_integer
>
method advise
; @end

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  int error = posix_fadvise(fd,0,0,advice);
  if (error != 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_ADVISE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(error);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_seek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offset:retrieve_integer
whence:retrieve_integer
>
method seek
; @end

  int fd = (int)dst_location->v_data_ptr;

  long long int result = lseek(fd,offset,whence);

  // - ERROR -
  if (result == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_SEEK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fd_method_mmap_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offset:retrieve_integer
length:retrieve_integer
prot:retrieve_integer
flags:retrieve_integer
>
method mmap
; @end

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (offset < 0 || offset % sysconf(_SC_PAGE_SIZE) != 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(offset);

    return false;
  }

  // - ERROR -
  if (length <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(length);

    return false;
  }

  void *mem_ptr = mmap(nullptr,length,prot,flags,fd,offset);

  // - ERROR -
  if (mem_ptr == MAP_FAILED)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  // - create mmap object -
  mmap_s *mm_ptr = (mmap_s *)cmalloc(sizeof(mmap_s));
  mm_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  mm_ptr->fd_location = dst_location;

  mm_ptr->mem_ptr = mem_ptr;
  mm_ptr->length = length;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mmap,mm_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Fd"),"Fd")
  );

  return true;
}/*}}}*/

bool bic_fd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Fd");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TIMER_FD -
built_in_class_s timer_fd_class =
{/*{{{*/
  "TimerFd",
  c_modifier_public | c_modifier_final,
  7, timer_fd_methods,
  4 + 2 + 2, timer_fd_variables,
  bic_timer_fd_consts,
  bic_timer_fd_init,
  bic_timer_fd_clear,
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

built_in_method_s timer_fd_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_timer_fd_operator_binary_equal
  },
  {
    "TimerFd#2",
    c_modifier_public | c_modifier_final,
    bic_timer_fd_method_TimerFd_2
  },
  {
    "settime#3",
    c_modifier_public | c_modifier_final,
    bic_timer_fd_method_settime_3
  },
  {
    "read_counter#0",
    c_modifier_public | c_modifier_final,
    bic_timer_fd_method_read_counter_0
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_timer_fd_method_get_fd_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_timer_fd_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_timer_fd_method_print_0
  },
};/*}}}*/

built_in_variable_s timer_fd_variables[] =
{/*{{{*/

  // - clock type values -
  { "CLOCK_REALTIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLOCK_MONOTONIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLOCK_PROCESS_CPUTIME_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLOCK_THREAD_CPUTIME_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - timerfd create flags -
  { "TFD_NONBLOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TFD_CLOEXEC", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - timerfd settime flags -
  { "TFD_TIMER_ABSTIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TFD_TIMER_CANCEL_ON_SET", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_timer_fd_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert clock type values -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_TIMERFD_CLOCK_TYPE_ID_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TIMERFD_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_REALTIME);
    CREATE_TIMERFD_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_MONOTONIC);
    CREATE_TIMERFD_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_PROCESS_CPUTIME_ID);
    CREATE_TIMERFD_CLOCK_TYPE_ID_BIC_STATIC(CLOCK_THREAD_CPUTIME_ID);
  }

  // - insert timerfd create flags -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_TIMERFD_CREATE_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TIMERFD_CREATE_FLAG_BIC_STATIC(TFD_NONBLOCK);
    CREATE_TIMERFD_CREATE_FLAG_BIC_STATIC(TFD_CLOEXEC);
  }

  // - insert timerfd settime flags -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_TIMERFD_SETTIME_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TIMERFD_SETTIME_FLAG_BIC_STATIC(TFD_TIMER_ABSTIME);
    CREATE_TIMERFD_SETTIME_FLAG_BIC_STATIC(TFD_TIMER_CANCEL_ON_SET);
  }

}/*}}}*/

void bic_timer_fd_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (int)-1;
}/*}}}*/

void bic_timer_fd_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  int fd = (int)location_ptr->v_data_ptr;

  if (fd != -1)
  {
    close(fd);
  }
}/*}}}*/

bool bic_timer_fd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_timer_fd_method_TimerFd_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
clock_id:retrieve_integer
flags:retrieve_integer
>
method TimerFd
; @end

  int fd = timerfd_create(clock_id,flags);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TIMER_FD_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (int)fd;

  return true;
}/*}}}*/

bool bic_timer_fd_method_settime_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
interval:retrieve_integer
value:retrieve_integer
flags:retrieve_integer
>
method settime
; @end

  int fd = (int)dst_location->v_data_ptr;

  itimerspec itspec;

  // - fill timer time structure -
  itspec.it_interval.tv_sec = interval/1000000000ULL;
  itspec.it_interval.tv_nsec = interval%1000000000ULL;
  itspec.it_value.tv_sec = value/1000000000ULL;
  itspec.it_value.tv_nsec = value%1000000000ULL;

  // - ERROR -
  if (timerfd_settime(fd,flags,&itspec,NULL) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TIMER_FD_SETTIME_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_timer_fd_method_read_counter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  long long unsigned exp_counter;
  if (read(fd,&exp_counter,sizeof(exp_counter)) != sizeof(exp_counter))
  {
    exception_s::throw_exception(it,module.error_base + c_error_TIMER_FD_EXP_COUNTER_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = exp_counter;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_timer_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (int)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_timer_fd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TimerFd"),"TimerFd")
  );

  return true;
}/*}}}*/

bool bic_timer_fd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TimerFd");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MMAP -
built_in_class_s mmap_class =
{/*{{{*/
  "Mmap",
  c_modifier_public | c_modifier_final,
  10, mmap_methods,
  4 + 15 + 3 + 5, mmap_variables,
  bic_mmap_consts,
  bic_mmap_init,
  bic_mmap_clear,
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

built_in_method_s mmap_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mmap_operator_binary_equal
  },
  {
    "remap#1",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_remap_1
  },
  {
    "protect#1",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_protect_1
  },
  {
    "sync#1",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_sync_1
  },
  {
    "advise#1",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_advise_1
  },
  {
    "write#3",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_write_3
  },
  {
    "read#2",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_read_2
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_mmap_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mmap_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mmap_method_print_0
  },
};/*}}}*/

built_in_variable_s mmap_variables[] =
{/*{{{*/

  // - mmap protection flags -
  { "PROT_NONE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROT_READ",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROT_WRITE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROT_EXEC",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - mmap flags -
  { "MAP_SHARED",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_PRIVATE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_ANON",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_ANONYMOUS",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_DENYWRITE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_EXECUTABLE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_FILE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_FIXED",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_GROWSDOWN",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_HUGETLB",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_LOCKED",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_NONBLOCK",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_NORESERVE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_POPULATE",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_STACK",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - memory sync flags -
  { "MS_ASYNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MS_SYNC",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MS_INVALIDATE",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - memory advise flags -
  { "MADV_NORMAL",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MADV_RANDOM",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MADV_SEQUENTIAL",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MADV_WILLNEED",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MADV_DONTNEED",  c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_mmap_consts(location_array_s &const_locations)
{/*{{{*/

  // - mmap protection flags -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_MMAP_PROT_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MMAP_PROT_FLAG_BIC_STATIC(PROT_NONE);
    CREATE_MMAP_PROT_FLAG_BIC_STATIC(PROT_READ);
    CREATE_MMAP_PROT_FLAG_BIC_STATIC(PROT_WRITE);
    CREATE_MMAP_PROT_FLAG_BIC_STATIC(PROT_EXEC);
  }

  // - mmap flags -
  {
    const_locations.push_blanks(15);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 15);

#define CREATE_MMAP_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MMAP_FLAG_BIC_STATIC(MAP_SHARED);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_PRIVATE);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_ANON);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_ANONYMOUS);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_DENYWRITE);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_EXECUTABLE);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_FILE);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_FIXED);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_GROWSDOWN);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_HUGETLB);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_LOCKED);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_NONBLOCK);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_NORESERVE);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_POPULATE);
    CREATE_MMAP_FLAG_BIC_STATIC(MAP_STACK);
  }

  // - insert memory sync flags -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_MEMORY_SYNC_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MEMORY_SYNC_FLAG_BIC_STATIC(MS_ASYNC);
    CREATE_MEMORY_SYNC_FLAG_BIC_STATIC(MS_SYNC);
    CREATE_MEMORY_SYNC_FLAG_BIC_STATIC(MS_INVALIDATE);
  }

  // - insert memory advise flags -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_MEMORY_ADVISE_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MEMORY_ADVISE_FLAG_BIC_STATIC(MADV_NORMAL);
    CREATE_MEMORY_ADVISE_FLAG_BIC_STATIC(MADV_RANDOM);
    CREATE_MEMORY_ADVISE_FLAG_BIC_STATIC(MADV_SEQUENTIAL);
    CREATE_MEMORY_ADVISE_FLAG_BIC_STATIC(MADV_WILLNEED);
    CREATE_MEMORY_ADVISE_FLAG_BIC_STATIC(MADV_DONTNEED);
  }

}/*}}}*/

void bic_mmap_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (mmap_s *)nullptr;
}/*}}}*/

void bic_mmap_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mmap_s *mm_ptr = (mmap_s *)location_ptr->v_data_ptr;

  if (mm_ptr != nullptr)
  {
    mm_ptr->clear(it);
    cfree(mm_ptr);
  }
}/*}}}*/

bool bic_mmap_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mmap_method_remap_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
length:retrieve_integer
>
method remap
; @end

  mmap_s *mm_ptr = (mmap_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (length <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(length);

    return false;
  }

  void *mem_ptr = mremap(mm_ptr->mem_ptr,mm_ptr->length,length,MREMAP_MAYMOVE);

  // - ERROR -
  if (mem_ptr == MAP_FAILED)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_REMAP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  mm_ptr->mem_ptr = mem_ptr;
  mm_ptr->length = length;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mmap_method_protect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
prot:retrieve_integer
>
method protect
; @end

  mmap_s *mm_ptr = (mmap_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mprotect(mm_ptr->mem_ptr,mm_ptr->length,prot) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_PROTECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mmap_method_sync_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
flags:retrieve_integer
>
method sync
; @end

  mmap_s *mm_ptr = (mmap_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (msync(mm_ptr->mem_ptr,mm_ptr->length,flags) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_SYNC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mmap_method_advise_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
advice:retrieve_integer
>
method advise
; @end

  mmap_s *mm_ptr = (mmap_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (madvise(mm_ptr->mem_ptr,mm_ptr->length,advice) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_ADVISE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mmap_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offset:retrieve_integer
data:retrieve_data_buffer
from:retrieve_integer
>
method write
; @end

  mmap_s *mm_ptr = (mmap_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (offset < 0 || offset > mm_ptr->length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(offset);

    return false;
  }

  // - ERROR -
  if (from < 0 || from > data_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(from);

    return false;
  }

  long long int length = data_size - from;

  // - ERROR -
  if ((offset + length) > mm_ptr->length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(data_size);

    return false;
  }

  memcpy((char *)mm_ptr->mem_ptr + offset,(const char *)data_ptr + from,length);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mmap_method_read_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offset:retrieve_integer
length:retrieve_integer
>
method read
; @end

  mmap_s *mm_ptr = (mmap_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (offset < 0 || offset > mm_ptr->length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(offset);

    return false;
  }

  // - ERROR -
  if (length < 0 || (offset + length) > mm_ptr->length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MMAP_INVALID_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(length);

    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(length);

  memcpy(string_ptr->data,mm_ptr->mem_ptr,length);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mmap_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((mmap_s *)dst_location->v_data_ptr)->length;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mmap_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Mmap"),"Mmap")
  );

  return true;
}/*}}}*/

bool bic_mmap_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Mmap");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

