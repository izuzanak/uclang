
@begin
include "linux_module.h"
@end

// - LINUX indexes of built in classes -
unsigned c_bi_class_linux = c_idx_not_exist;
unsigned c_bi_class_fd = c_idx_not_exist;

// - LINUX module -
built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  linux_classes,         // Classes
  0,                     // Error base index
  10,                    // Error count
  linux_error_strings,   // Error strings
  linux_initialize,      // Initialize function
  linux_print_exception, // Print exceptions function
};/*}}}*/

// - LINUX classes -
built_in_class_s *linux_classes[] =
{/*{{{*/
  &linux_class,
  &fd_class,
};/*}}}*/

// - LINUX error strings -
const char *linux_error_strings[] =
{/*{{{*/
  "error_FD_OPEN_ERROR",
  "error_FD_CREATE_ERROR",
  "error_FD_WRITE_INVALID_DATA_OFFSET",
  "error_FD_WRITE_ERROR",
  "error_FD_READ_INVALID_BYTE_COUNT",
  "error_FD_READ_ERROR",
  "error_FD_SYNC_ERROR",
  "error_FD_SEEK_ERROR",
  "error_FD_CLOSE_ERROR",
  "error_FD_NOT_OPENED",
};/*}}}*/

// - LINUX initialize -
bool linux_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize linux class identifier -
  c_bi_class_linux = class_base_idx++;

  // - initialize fd class identifier -
  c_bi_class_fd = class_base_idx++;

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
  case c_error_FD_WRITE_INVALID_DATA_OFFSET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor write, invalid source data offset %" HOST_LL_FORMAT "d\n",exception.params[0]);
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
  case c_error_FD_SEEK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor seek error: ");
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
  case c_error_FD_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile descriptor is not opened\n");
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
  3, linux_methods,
  0, linux_variables,
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
};/*}}}*/

void bic_linux_consts(location_array_s &const_locations)
{/*{{{*/
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
  18, fd_methods,
  16 + 12 + 1 + 3, fd_variables,
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
    "Fd#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_Fd_2
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
    "openat#3",
    c_modifier_public | c_modifier_final,
    bic_fd_method_openat_3
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
    "fsync#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_fsync_0
  },
  {
    "fdatasync#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_fdatasync_0
  },
  {
    "lseek#2",
    c_modifier_public | c_modifier_final,
    bic_fd_method_lseek_2
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_fd_method_close_0
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

  // - special file descriptor values -
  { "AT_FDCWD",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - file seek whence values -
  { "SEEK_SET",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_CUR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_END",  c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

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

}/*}}}*/

void bic_fd_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fd_s *)nullptr;
}/*}}}*/

void bic_fd_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fd_s *fd_ptr = (fd_s *)location_ptr->v_data_ptr;

  if (fd_ptr != nullptr)
  {
    fd_ptr->clear(it);
    cfree(fd_ptr);
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

bool bic_fd_method_Fd_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int fd;
  long long int close;

  if (!it.retrieve_integer(src_0_location,fd) ||
      !it.retrieve_integer(src_1_location,close))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Fd#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - create fd object -
  fd_s *fd_ptr = (fd_s *)cmalloc(sizeof(fd_s));
  fd_ptr->init();

  fd_ptr->fd = fd;

  // - set no close flag if requested -
  if (!close)
  {
    fd_ptr->flags |= FD_FLAG_NO_CLOSE;
  }

  dst_location->v_data_ptr = (fd_s *)fd_ptr;

  return true;
}/*}}}*/

bool bic_fd_method_open_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int flags;
  long long int mode;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,flags) ||
      !it.retrieve_integer(src_2_location,mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fd,"open#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  int fd = open(string_ptr->data,flags,mode);
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(errno);

    return false;
  }

  // - create fd object -
  fd_s *fd_ptr = (fd_s *)cmalloc(sizeof(fd_s));
  fd_ptr->init();

  fd_ptr->fd = fd;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fd,fd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_creat_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int mode;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fd,"creat#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  int fd = creat(string_ptr->data,mode);
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(errno);

    return false;
  }

  // - create fd object -
  fd_s *fd_ptr = (fd_s *)cmalloc(sizeof(fd_s));
  fd_ptr->init();

  fd_ptr->fd = fd;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fd,fd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_openat_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int flags;
  long long int mode;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,flags) ||
      !it.retrieve_integer(src_2_location,mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("openat#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  fd_s *dirfd_ptr = (fd_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  int fd = openat(dirfd_ptr->fd,string_ptr->data,flags,mode);
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(errno);

    return false;
  }

  // - create fd object -
  fd_s *fd_ptr = (fd_s *)cmalloc(sizeof(fd_s));
  fd_ptr->init();

  fd_ptr->fd = fd;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fd,fd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fd_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int from;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,from))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (from < 0 || from >= string_ptr->size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_INVALID_DATA_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(from);

    return false;
  }

  // - write to file descriptor -
  long int cnt = write(fd_ptr->fd,string_ptr->data + from,string_ptr->size - 1 - from);

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
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned length = string_ptr->size - 1;

  if (length > 0)
  {
    long int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = write(fd_ptr->fd,string_ptr->data + writed,length - writed)) == -1)
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
    while(writed < length);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_pwrite_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int from;
  long long int offset;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,from) ||
      !it.retrieve_integer(src_2_location,offset))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("pwrite#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (from < 0 || from >= string_ptr->size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_WRITE_INVALID_DATA_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(from);

    return false;
  }

  // - write to file descriptor -
  long int cnt = pwrite(fd_ptr->fd,string_ptr->data + from,string_ptr->size - 1 - from,offset);

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
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int offset;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,offset))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("pwrite_all#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned length = string_ptr->size - 1;

  if (length > 0)
  {
    long int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = pwrite(fd_ptr->fd,string_ptr->data + writed,length - writed,offset + writed)) == -1)
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
    while(writed < length);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int count;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,count))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("read#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (count < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_INVALID_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(count);

    return false;
  }

  char *buffer = (char *)cmalloc(count + 1);

  // - read from file descriptor -
  long int cnt = read(fd_ptr->fd,buffer,count);

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
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int count;
  long long int offset;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,count) ||
      !it.retrieve_integer(src_1_location,offset))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("pread#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (count < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_READ_INVALID_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(count);

    return false;
  }

  char *buffer = (char *)cmalloc(count + 1);

  // - read from file descriptor -
  long int cnt = pread(fd_ptr->fd,buffer,count,offset);

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

bool bic_fd_method_fsync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fsync(fd_ptr->fd) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_SYNC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_fdatasync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fdatasync(fd_ptr->fd) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_SYNC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_lseek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int offset;
  long long int whence;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,offset) ||
      !it.retrieve_integer(src_1_location,whence))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("lseek#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  long long int result = lseek(fd_ptr->fd,offset,whence);

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

bool bic_fd_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (close(fd_ptr->fd) == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FD_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  // - reset file descriptor value -
  fd_ptr->fd = -1;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fd_s *fd_ptr = (fd_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fd_ptr->fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FD_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = fd_ptr->fd;

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

