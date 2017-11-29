
@begin
include "ftp_module.h"
@end

// - FTP indexes of built in classes -
unsigned c_bi_class_ftp_session = c_idx_not_exist;
unsigned c_bi_class_ftp_handle = c_idx_not_exist;

// - FTP module -
built_in_module_s module =
{/*{{{*/
  2,                   // Class count
  ftp_classes,         // Classes

  0,                   // Error base index
  17,                  // Error count
  ftp_error_strings,   // Error strings

  ftp_initialize,      // Initialize function
  ftp_print_exception, // Print exceptions function
};/*}}}*/

// - FTP classes -
built_in_class_s *ftp_classes[] =
{/*{{{*/
  &ftp_session_class,
  &ftp_handle_class,
};/*}}}*/

// - FTP error strings -
const char *ftp_error_strings[] =
{/*{{{*/
  "error_FTP_SESSION_CONNECT_ERROR",
  "error_FTP_SESSION_LOGIN_ERROR",
  "error_FTP_SESSION_DIR_CREATE_ERROR",
  "error_FTP_SESSION_DIR_REMOVE_ERROR",
  "error_FTP_SESSION_DIR_CHANGE_ERROR",
  "error_FTP_SESSION_DIR_GET_CWD_ERROR",
  "error_FTP_SESSION_DIR_LIST_ERROR",
  "error_FTP_SESSION_FILE_GET_ERROR",
  "error_FTP_SESSION_FILE_PUT_ERROR",
  "error_FTP_SESSION_FILE_REMOVE_ERROR",
  "error_FTP_SESSION_FILE_RENAME_ERROR",
  "error_FTP_SESSION_ACCESS_ERROR",
  "error_FTP_HANDLE_CLOSE_ERROR",
  "error_FTP_HANDLE_NOT_OPENED",
  "error_FTP_HANDLE_WRITE_ERROR",
  "error_FTP_HANDLE_READ_ERROR",
  "error_FTP_HANDLE_READ_NEGATIVE_BYTE_COUNT",
};/*}}}*/

// - FTP initialize -
bool ftp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ftp_session class identifier -
  c_bi_class_ftp_session = class_base_idx++;

  // - initialize ftp_handle class identifier -
  c_bi_class_ftp_handle = class_base_idx++;

  return true;
}/*}}}*/

// - FTP print exception -
bool ftp_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_FTP_SESSION_CONNECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP session connect error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_LOGIN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while login to FTP server\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_DIR_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP cannot create directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_DIR_REMOVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP cannot remove directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_DIR_CHANGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot change directory to \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_DIR_GET_CWD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving current working directory\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_DIR_LIST_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP cannot list directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_FILE_GET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving file \"%s\" from FTP server\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_FILE_PUT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while uploading file \"%s\" to FTP server\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_FILE_REMOVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP cannot remove file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_FILE_RENAME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP cannot rename file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_SESSION_ACCESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot access \"%s\" at FTP server\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_HANDLE_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while closing FTP handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_HANDLE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFTP handle is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_HANDLE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to FTP handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_HANDLE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from FTP handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FTP_HANDLE_READ_NEGATIVE_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read %" HOST_LL_FORMAT "d bytes from FTP handle\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class FTP_SESSION -
built_in_class_s ftp_session_class =
{/*{{{*/
  "FtpSession",
  c_modifier_public | c_modifier_final,
  15, ftp_session_methods,
  6, ftp_session_variables,
  bic_ftp_session_consts,
  bic_ftp_session_init,
  bic_ftp_session_clear,
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

built_in_method_s ftp_session_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_operator_binary_equal
  },
  {
    "FtpSession#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_FtpSession_1
  },
  {
    "login#2",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_login_2
  },
  {
    "mkdir#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_mkdir_1
  },
  {
    "rmdir#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_rmdir_1
  },
  {
    "listdir#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_listdir_1
  },
  {
    "chdir#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_chdir_1
  },
  {
    "getcwd#0",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_getcwd_0
  },
  {
    "get_file#2",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_get_file_2
  },
  {
    "put_file#2",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_put_file_2
  },
  {
    "remove#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_remove_1
  },
  {
    "rename#2",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_rename_2
  },
  {
    "open#2",
    c_modifier_public | c_modifier_final,
    bic_ftp_session_method_open_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ftp_session_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ftp_session_method_print_0
  },
};/*}}}*/

built_in_variable_s ftp_session_variables[] =
{/*{{{*/
  {
    "TYPE_DIR",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TYPE_DIR_VERBOSE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TYPE_FILE_READ",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TYPE_FILE_WRITE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_ASCII",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_IMAGE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_ftp_session_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert transfer type constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_FTP_TRANSFER_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FTP_TRANSFER_TYPE_BIC_STATIC(FTPLIB_DIR);
    CREATE_FTP_TRANSFER_TYPE_BIC_STATIC(FTPLIB_DIR_VERBOSE);
    CREATE_FTP_TRANSFER_TYPE_BIC_STATIC(FTPLIB_FILE_READ);
    CREATE_FTP_TRANSFER_TYPE_BIC_STATIC(FTPLIB_FILE_WRITE);
  }

  // - insert transfer mode constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_FTP_TRANSFER_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FTP_TRANSFER_MODE_BIC_STATIC(FTPLIB_ASCII);
    CREATE_FTP_TRANSFER_MODE_BIC_STATIC(FTPLIB_IMAGE);
  }
}/*}}}*/

void bic_ftp_session_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ftp_session_s *)nullptr;
}/*}}}*/

void bic_ftp_session_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ftp_session_s *ftps_ptr = (ftp_session_s *)location_ptr->v_data_ptr;

  // - if session exists -
  if (ftps_ptr != nullptr)
  {
    ftps_ptr->clear(it);
    cfree(ftps_ptr);
  }
}/*}}}*/

bool bic_ftp_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ftp_session_method_FtpSession_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FtpSession#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve host name pointer -
  string_s *host_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create ftp session object -
  ftp_session_s *ftps_ptr = (ftp_session_s *)cmalloc(sizeof(ftp_session_s));
  ftps_ptr->init();

  // - ERROR -
  if (FtpConnect(host_ptr->data,&ftps_ptr->nb_ptr) != 1)
  {
    ftps_ptr->clear(it);
    cfree(ftps_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_CONNECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set ftp session state to connected -
  ftps_ptr->state = FTP_SESSION_STATE_CONNECTED;

  dst_location->v_data_ptr = (ftp_session_s *)ftps_ptr;

  return true;
}/*}}}*/

bool bic_ftp_session_method_login_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("login#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve user string -
  string_s *user_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve password string -
  string_s *pass_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (FtpLogin(user_ptr->data,pass_ptr->data,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_LOGIN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set ftp session state to authenticated -
  ftps_ptr->state = FTP_SESSION_STATE_AUTHENTICATED;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_mkdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("mkdir#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (FtpMkdir(path_ptr->data,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_rmdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("rmdir#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (FtpRmdir(path_ptr->data,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_REMOVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_listdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("listdir#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  // - netbuf data object -
  netbuf *n_data;

  // - ERROR -
  if (FtpAccess(path_ptr->data,FTPLIB_DIR,FTPLIB_ASCII,ftps_ptr->nb_ptr,&n_data) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create read buffer -
  const int c_read_buff_size = 1024;
  char *read_buff = (char *)cmalloc(c_read_buff_size*sizeof(char));

  int read_cnt;
  do
  {
    read_cnt = FtpRead(read_buff,c_read_buff_size,n_data);

    if (read_cnt <= 0)
    {
      break;
    }

    string_s *entry_name = it.get_new_string_ptr();
    entry_name->set(read_cnt - 1,read_buff);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,entry_name);
    array_ptr->push(new_location);
  }
  while(true);

  cfree(read_buff);

  // - ERROR -
  if (read_cnt == -1)
  {
    FtpClose(n_data);

    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - ERROR -
  if (FtpClose(n_data) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_ftp_session_method_chdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("chdir#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (FtpChdir(path_ptr->data,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_CHANGE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_getcwd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - create target string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(1024);

  // - ERROR -
  if (FtpPwd(string_ptr->data,string_ptr->size - 1,ftps_ptr->nb_ptr) != 1)
  {
    string_ptr->clear();
    cfree(string_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_DIR_GET_CWD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_ptr->size = strlen(string_ptr->data) + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ftp_session_method_get_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_file#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve file string -
  string_s *file_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (FtpGet(file_ptr->data,path_ptr->data,FTPLIB_IMAGE,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_FILE_GET_ERROR,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_put_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("put_file#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve file string -
  string_s *file_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (FtpPut(file_ptr->data,path_ptr->data,FTPLIB_IMAGE,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_FILE_PUT_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("remove#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve file string -
  string_s *file_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (FtpDelete(file_ptr->data,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_FILE_REMOVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_rename_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("rename#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve source string -
  string_s *src_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve destination string -
  string_s *dst_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (FtpRename(src_ptr->data,dst_ptr->data,ftps_ptr->nb_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_FILE_RENAME_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_session_method_open_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int tr_type;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,tr_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("open#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ftp session -
  ftp_session_s *ftps_ptr = (ftp_session_s *)dst_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create ftp handle object -
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)cmalloc(sizeof(ftp_handle_s));
  ftph_ptr->init();

  // - ERROR -
  if (FtpAccess(path_ptr->data,tr_type,FTPLIB_IMAGE,ftps_ptr->nb_ptr,&ftph_ptr->nb_ptr) != 1)
  {
    ftph_ptr->clear(it);
    cfree(ftph_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_FTP_SESSION_ACCESS_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create reference to ftp session -
  dst_location->v_reference_cnt.atomic_inc();
  ftph_ptr->ftps_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ftp_handle,ftph_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ftp_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FtpSession"),"FtpSession");
  );

  return true;
}/*}}}*/

bool bic_ftp_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FtpSession");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FTP_HANDLE -
built_in_class_s ftp_handle_class =
{/*{{{*/
  "FtpHandle",
  c_modifier_public | c_modifier_final,
  9, ftp_handle_methods,
  0, ftp_handle_variables,
  bic_ftp_handle_consts,
  bic_ftp_handle_init,
  bic_ftp_handle_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_ftp_handle_next_item,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s ftp_handle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_operator_binary_equal
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_method_close_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_method_read_0
  },
  {
    "readln#0",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_method_readln_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_method_read_1
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_ftp_handle_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ftp_handle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ftp_handle_method_print_0
  },
};/*}}}*/

built_in_variable_s ftp_handle_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_FTP_HANDLE_READLN() \
  /*{{{*/\
  \
  /* - target data buffer - */\
  bc_array_s line_buffer;\
  line_buffer.init();\
  \
  char ch;\
  int read_cnt;\
  do\
  {\
    read_cnt = FtpRead(&ch,1,ftph_ptr->nb_ptr);\
    \
    if (read_cnt <= 0 || ch == '\n')\
    {\
      break;\
    }\
    \
    line_buffer.push(ch);\
  }\
  while(true);\
  /*}}}*/

#define BIC_FTP_HANDLE_NEXT_ITEM() \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    \
    /* - retrieve ftp handle - */\
    ftp_handle_s *ftph_ptr = (ftp_handle_s *)dst_location->v_data_ptr;\
    \
    /* - ERROR - */\
    if (ftph_ptr == nullptr)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    BIC_FTP_HANDLE_READLN();\
    \
    /* - ERROR - */\
    if (read_cnt < 0)\
    {\
      line_buffer.clear();\
      \
      exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    /* - was any data read from file - */\
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
      BIC_SET_RESULT(new_location);\
    }\
    \
    return true;\
  }/*}}}*/

void bic_ftp_handle_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ftp_handle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ftp_handle_s *)nullptr;
}/*}}}*/

void bic_ftp_handle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)location_ptr->v_data_ptr;

  // - if handle exists -
  if (ftph_ptr != nullptr)
  {
    ftph_ptr->clear(it);
    cfree(ftph_ptr);
  }
}/*}}}*/

location_s *bic_ftp_handle_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/
  // - retrieve ftp handle -
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)location_ptr->v_data_ptr;

  // - ERROR -
  if (ftph_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_NOT_OPENED,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  BIC_FTP_HANDLE_READLN();

  // - ERROR -
  if (read_cnt < 0)
  {
    line_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_READ_ERROR,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  // - was any data read from file -
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

bool bic_ftp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ftp_handle_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve ftp handle -
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ftph_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - close ftp handle -
  int result = FtpClose(ftph_ptr->nb_ptr);

  // - ERROR -
  if (result != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ftph_ptr->nb_ptr = nullptr;

  // - release sftp handle object -
  ftph_ptr->clear(it);
  cfree(ftph_ptr);

  dst_location->v_data_ptr = (ftp_handle_s *)nullptr;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_handle_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  // - retrieve ftp handle -
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ftph_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  ssize_t string_length = string_ptr->size - 1;

  // - ERROR -
  if (FtpWrite(string_ptr->data,string_length,ftph_ptr->nb_ptr) != string_length)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ftp_handle_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve ftp handle -
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ftph_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const unsigned c_buffer_add = 1024;

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  int read_cnt;
  do
  {
    data_buffer.reserve(c_buffer_add);

    read_cnt = FtpRead(data_buffer.data + data_buffer.used,data_buffer.size - data_buffer.used,ftph_ptr->nb_ptr);

    if (read_cnt <= 0)
    {
      break;
    }

    data_buffer.used += read_cnt;
  }
  while(true);

  // - ERROR -
  if (read_cnt < 0)
  {
    data_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - was any data read from file -
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

bool bic_ftp_handle_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FTP_HANDLE_NEXT_ITEM();
}/*}}}*/

bool bic_ftp_handle_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int byte_cnt;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,byte_cnt))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("read#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ftp handle -
  ftp_handle_s *ftph_ptr = (ftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ftph_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data string -
  string_s data_string;
  data_string.init();
  data_string.create(byte_cnt);

  int read_cnt = FtpRead(data_string.data,byte_cnt,ftph_ptr->nb_ptr);

  // - ERROR -
  if (read_cnt < byte_cnt)
  {
    data_string.clear();

    exception_s::throw_exception(it,module.error_base + c_error_FTP_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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

bool bic_ftp_handle_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FTP_HANDLE_NEXT_ITEM();
}/*}}}*/

bool bic_ftp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FtpHandle"),"FtpHandle");
  );

  return true;
}/*}}}*/

bool bic_ftp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FtpHandle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

