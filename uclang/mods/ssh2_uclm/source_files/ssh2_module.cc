
@begin
include "ssh2_module.h"
@end

// - SSH2 indexes of built in classes -
unsigned c_bi_class_ssh2_session = c_idx_not_exist;
unsigned c_bi_class_sftp_session = c_idx_not_exist;
unsigned c_bi_class_sftp_handle = c_idx_not_exist;
unsigned c_bi_class_ssh2_channel = c_idx_not_exist;

// - SSH2 indexes of remote classes -
unsigned c_rm_class_socket = c_idx_not_exist;

// - SSH2 module -
built_in_module_s module =
{/*{{{*/
  4,                     // Class count
  ssh2_classes,          // Classes

  0,                     // Error base index
  27,                    // Error count
  ssh2_error_strings,    // Error strings

  ssh2_initialize,       // Initialize function
  ssh2_print_exception,  // Print exceptions function
};/*}}}*/

// - SSH2 classes -
built_in_class_s *ssh2_classes[] =
{/*{{{*/
  &ssh2_session_class,
  &sftp_session_class,
  &sftp_handle_class,
  &ssh2_channel_class,
};/*}}}*/

// - SSH2 error strings -
const char *ssh2_error_strings[] =
{/*{{{*/
  "error_SSH2_SESSION_SOCKET_NOT_OPENED",
  "error_SSH2_SESSION_INIT_ERROR",
  "error_SSH2_SESSION_HANDSHAKE_ERROR",
  "error_SSH2_SESSION_CANNOT_RETRIEVE_HOSTKEY_HASH",
  "error_SSH2_SESSION_CANNOT_RETRIEVE_USERAUTH_LIST",
  "error_SSH2_SESSION_USERAUTH_PASSWORD_ERROR",
  "error_SSH2_SESSION_USERAUTH_FAKE_INTERACTIVE_ERROR",
  "error_SSH2_SESSION_USERAUTH_PUBLICKEY_FROMFILE_ERROR",
  "error_SSH2_SESSION_NOT_AUTHENTICATED",
  "error_SSH2_SESSION_CHANNEL_OPEN_ERROR",
  "error_SFTP_SESSION_INIT_ERROR",
  "error_SFTP_SESSION_DIR_CREATE_ERROR",
  "error_SFTP_SESSION_DIR_REMOVE_ERROR",
  "error_SFTP_SESSION_DIR_LIST_ERROR",
  "error_SFTP_SESSION_FILE_REMOVE_ERROR",
  "error_SFTP_SESSION_FILE_OPEN_ERROR",
  "error_SFTP_HANDLE_CLOSE_ERROR",
  "error_SFTP_HANDLE_NOT_OPENED",
  "error_SFTP_HANDLE_WRITE_ERROR",
  "error_SFTP_HANDLE_READ_ERROR",
  "error_SFTP_HANDLE_READ_NEGATIVE_BYTE_COUNT",
  "error_SSH2_CHANNEL_EXEC_ERROR",
  "error_SSH2_CHANNEL_SHELL_ERROR",
  "error_SSH2_CHANNEL_WRITE_ERROR",
  "error_SSH2_CHANNEL_READ_ERROR",
  "error_SSH2_CHANNEL_FLUSH_ERROR",
  "error_SSH2_CHANNEL_SEND_EOF_ERROR",
};/*}}}*/

// - SSH2 initialize -
bool ssh2_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ssh2_session class identifier -
  c_bi_class_ssh2_session = class_base_idx++;

  // - initialize sftp_session class identifier -
  c_bi_class_sftp_session = class_base_idx++;

  // - initialize sftp_handle class identifier -
  c_bi_class_sftp_handle = class_base_idx++;

  // - initialize ssh2_channel class identifier -
  c_bi_class_ssh2_channel = class_base_idx++;

  // - retrieve remote socket class index -
  c_rm_class_socket = sp.resolve_class_idx_by_name("Socket",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_socket == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - SSH2 print exception -
bool ssh2_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SSH2_SESSION_SOCKET_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nReceived socket is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSH2 session initalization error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_HANDSHAKE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSH2 session handshake error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_CANNOT_RETRIEVE_HOSTKEY_HASH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve requested hostkey hash value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_CANNOT_RETRIEVE_USERAUTH_LIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve userauth list for given user\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_USERAUTH_PASSWORD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while authentication of user by password\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_USERAUTH_FAKE_INTERACTIVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while authentication of user by fake interactive method\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_USERAUTH_PUBLICKEY_FROMFILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while authentication of user by publickey fromfile\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_NOT_AUTHENTICATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSH2 session is not authenticated yet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_SESSION_CHANNEL_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSH2 session error while opening channel\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_SESSION_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP session initalization error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_SESSION_DIR_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP cannot create directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_SESSION_DIR_REMOVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP cannot remove directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_SESSION_DIR_LIST_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP cannot list directory \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_SESSION_FILE_REMOVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP cannot remove file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_SESSION_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP cannot open file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_HANDLE_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while closing SFTP handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_HANDLE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSFTP handle is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_HANDLE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to SFTP handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_HANDLE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from SFTP handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SFTP_HANDLE_READ_NEGATIVE_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read %" HOST_LL_FORMAT "d bytes from SFTP handle\n", exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_CHANNEL_EXEC_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSH2 channel cannot execute remote command\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_CHANNEL_SHELL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSH2 channel cannot start remote shell\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_CHANNEL_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to SSH2 channel\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_CHANNEL_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from SSH2 channel\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_CHANNEL_FLUSH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while flushing stream to SSH2 channel\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSH2_CHANNEL_SEND_EOF_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while sending EOF to SSH2 channel\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class SSH2_SESSION -
built_in_class_s ssh2_session_class =
{/*{{{*/
  "Ssh2Session",
  c_modifier_public | c_modifier_final,
  12, ssh2_session_methods,
  2, ssh2_session_variables,
  bic_ssh2_session_consts,
  bic_ssh2_session_init,
  bic_ssh2_session_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ssh2_session_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_operator_binary_equal
  },
  {
    "Ssh2Session#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_Ssh2Session_1
  },
  {
    "hostkey_hash#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_hostkey_hash_1
  },
  {
    "userauth_list#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_userauth_list_1
  },
  {
    "userauth_password#2",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_userauth_password_2
  },
  {
    "userauth_fake_interactive#2",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_userauth_fake_interactive_2
  },
  {
    "userauth_publickey_fromfile#4",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_userauth_publickey_fromfile_4
  },
  {
    "sftp_session#0",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_sftp_session_0
  },
  {
    "exec#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_exec_1
  },
  {
    "shell#0",
    c_modifier_public | c_modifier_final,
    bic_ssh2_session_method_shell_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssh2_session_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssh2_session_method_print_0
  },
};/*}}}*/

built_in_variable_s ssh2_session_variables[] =
{/*{{{*/
  {
    "HOSTKEY_HASH_MD5",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "HOSTKEY_HASH_SHA1",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

#define BIC_SSH2_SESSION_CHANNEL_OPEN_BEGIN() \
/*{{{*/\
\
  /* - retrieve ssh2 session - */\
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (ssh2s_ptr->state < SSH2_SESSION_STATE_AUTHENTICATED)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_NOT_AUTHENTICATED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - create new ssh2 channel object - */\
  ssh2_channel_s *ssh2ch_ptr = (ssh2_channel_s *)cmalloc(sizeof(ssh2_channel_s));\
  ssh2ch_ptr->init();\
\
  /* - open ssh2 channel - */\
  ssh2ch_ptr->channel = libssh2_channel_open_session(ssh2s_ptr->session);\
\
  /* - ERROR - */\
  if (ssh2ch_ptr->channel == NULL)\
  {\
    ssh2ch_ptr->clear(it);\
    cfree(ssh2ch_ptr);\
\
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_CHANNEL_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

#define BIC_SSH2_SESSION_CHANNEL_OPEN_END() \
/*{{{*/\
\
  /* - create reference to ssh2 session - */\
  dst_location->v_reference_cnt.atomic_inc();\
  ssh2ch_ptr->ssh2s_ptr = dst_location;\
\
  /* - create result location - */\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ssh2_channel,ssh2ch_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
/*}}}*/

void bic_ssh2_session_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert hostkey type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_SSH2_HOSTKEY_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SSH2_HOSTKEY_TYPE_BIC_STATIC(LIBSSH2_HOSTKEY_HASH_MD5);
    CREATE_SSH2_HOSTKEY_TYPE_BIC_STATIC(LIBSSH2_HOSTKEY_HASH_SHA1);
  }
}/*}}}*/

void bic_ssh2_session_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ssh2_session_s *)NULL;
}/*}}}*/

void bic_ssh2_session_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)location_ptr->v_data_ptr;

  // - if session exists -
  if (ssh2s_ptr != NULL)
  {
    ssh2s_ptr->clear(it);
    cfree(ssh2s_ptr);
  }
}/*}}}*/

bool bic_ssh2_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ssh2_session_method_Ssh2Session_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_socket)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Ssh2Session#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  int sock = (int)src_0_location->v_data_ptr;

  // - ERROR -
  if (sock == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_SOCKET_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create new ssh2 session object -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)cmalloc(sizeof(ssh2_session_s));
  ssh2s_ptr->init();

  // - ERROR -
  if ((ssh2s_ptr->session = libssh2_session_init()) == NULL)
  {
    ssh2s_ptr->clear(it);
    cfree(ssh2s_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set blocking mode -
  libssh2_session_set_blocking(ssh2s_ptr->session,1);

  // - ERROR -
  if (libssh2_session_handshake(ssh2s_ptr->session,sock) != 0)
  {
    ssh2s_ptr->clear(it);
    cfree(ssh2s_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_HANDSHAKE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference to socket location -
  src_0_location->v_reference_cnt.atomic_inc();
  ssh2s_ptr->sock_ptr = src_0_location;

  // - set ssh2 session state to handshaked -
  ssh2s_ptr->state = SSH2_SESSION_STATE_HANDSHAKED;

  dst_location->v_data_ptr = (ssh2_session_s *)ssh2s_ptr;

  return true;
}/*}}}*/

bool bic_ssh2_session_method_hostkey_hash_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int hostkey_type;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,hostkey_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("hostkey_hash#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ssh2 session -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;

  // - ERROR -
  const char *hostkey_hash;
  if ((hostkey_hash = libssh2_hostkey_hash(ssh2s_ptr->session,hostkey_type)) == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_CANNOT_RETRIEVE_HOSTKEY_HASH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();

  switch (hostkey_type)
  {
  case LIBSSH2_HOSTKEY_HASH_MD5:
    string_ptr->set(HOSTKEY_HASH_MD5_SIZE,hostkey_hash);
    break;
  case LIBSSH2_HOSTKEY_HASH_SHA1:
    string_ptr->set(HOSTKEY_HASH_SHA1_SIZE,hostkey_hash);
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ssh2_session_method_userauth_list_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("userauth_list#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve ssh2 session -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;

  // - retrieve user string -
  string_s *user_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve user authentication list -
  char *userauth_list = libssh2_userauth_list(ssh2s_ptr->session,user_ptr->data,user_ptr->size - 1);

  // - ERROR -
  if (userauth_list == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_CANNOT_RETRIEVE_USERAUTH_LIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(userauth_list),userauth_list);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ssh2_session_method_userauth_password_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("userauth_password#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ssh2 session -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;

  // - retrieve user string -
  string_s *user_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve password string -
  string_s *pass_ptr = (string_s *)src_1_location->v_data_ptr;

  // - authenticate user by password -
  int result = libssh2_userauth_password_ex(
                 ssh2s_ptr->session,
                 user_ptr->data,user_ptr->size - 1,
                 pass_ptr->data,pass_ptr->size - 1,
                 NULL);

  // - ERROR -
  if (result != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_USERAUTH_PASSWORD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set ssh2 session state to authenticated -
  ssh2s_ptr->state = SSH2_SESSION_STATE_AUTHENTICATED;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ssh2_session_method_userauth_fake_interactive_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("userauth_fake_interactive#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve ssh2 session -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;

  // - retrieve user string -
  string_s *user_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve password string -
  string_s *pass_ptr = (string_s *)src_1_location->v_data_ptr;

  // - authenticate user by password -
  int result = ssh2_c::userauth_fake_kbd(*ssh2s_ptr,*user_ptr,*pass_ptr);

  // - ERROR -
  if (result != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_USERAUTH_FAKE_INTERACTIVE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set ssh2 session state to authenticated -
  ssh2s_ptr->state = SSH2_SESSION_STATE_AUTHENTICATED;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ssh2_session_method_userauth_publickey_fromfile_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string ||
      src_2_location->v_type != c_bi_class_string ||
      src_3_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("userauth_publickey_fromfile#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - retrieve ssh2 session -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;

  // - retrieve user string -
  string_s *user_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve key file names -
  string_s *public_ptr = (string_s *)src_1_location->v_data_ptr;
  string_s *private_ptr = (string_s *)src_2_location->v_data_ptr;

  // - retrieve passphrase string -
  string_s *pass_ptr = (string_s *)src_3_location->v_data_ptr;

  // - authenticate user by publickey from file -
  int result = libssh2_userauth_publickey_fromfile(
    ssh2s_ptr->session,
    user_ptr->data,
    public_ptr->data,
    private_ptr->data,
    pass_ptr->data);

  // - ERROR -
  if (result != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_USERAUTH_PUBLICKEY_FROMFILE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set ssh2 session state to authenticated -
  ssh2s_ptr->state = SSH2_SESSION_STATE_AUTHENTICATED;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ssh2_session_method_sftp_session_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve ssh2 session -
  ssh2_session_s *ssh2s_ptr = (ssh2_session_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ssh2s_ptr->state < SSH2_SESSION_STATE_AUTHENTICATED)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_SESSION_NOT_AUTHENTICATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create new sftp session object -
  sftp_session_s *sftps_ptr = (sftp_session_s *)cmalloc(sizeof(sftp_session_s));
  sftps_ptr->init();

  // - create sftp session -
  sftps_ptr->session = libssh2_sftp_init(ssh2s_ptr->session);

  // - ERROR -
  if (sftps_ptr->session == NULL)
  {
    sftps_ptr->clear(it);
    cfree(sftps_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference to ssh2 session -
  dst_location->v_reference_cnt.atomic_inc();
  sftps_ptr->ssh2s_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sftp_session,sftps_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ssh2_session_method_exec_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("exec#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SSH2_SESSION_CHANNEL_OPEN_BEGIN();

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (libssh2_channel_exec(ssh2ch_ptr->channel,string_ptr->data) != 0)
  {
    ssh2ch_ptr->clear(it);
    cfree(ssh2ch_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSH2_CHANNEL_EXEC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SSH2_SESSION_CHANNEL_OPEN_END();
}/*}}}*/

bool bic_ssh2_session_method_shell_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_SSH2_SESSION_CHANNEL_OPEN_BEGIN();

  // - ERROR -
  if (libssh2_channel_shell(ssh2ch_ptr->channel) != 0)
  {
    ssh2ch_ptr->clear(it);
    cfree(ssh2ch_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSH2_CHANNEL_SHELL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SSH2_SESSION_CHANNEL_OPEN_END();
}/*}}}*/

bool bic_ssh2_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Ssh2Session"),"Ssh2Session");
  );

  return true;
}/*}}}*/

bool bic_ssh2_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Ssh2Session");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SFTP_SESSION -
built_in_class_s sftp_session_class =
{/*{{{*/
  "SftpSession",
  c_modifier_public | c_modifier_final,
  8, sftp_session_methods,
  6, sftp_session_variables,
  bic_sftp_session_consts,
  bic_sftp_session_init,
  bic_sftp_session_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s sftp_session_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_session_operator_binary_equal
  },
  {
    "mkdir#2",
    c_modifier_public | c_modifier_final,
    bic_sftp_session_method_mkdir_2
  },
  {
    "rmdir#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_session_method_rmdir_1
  },
  {
    "listdir#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_session_method_listdir_1
  },
  {
    "remove#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_session_method_remove_1
  },
  {
    "open#3",
    c_modifier_public | c_modifier_final,
    bic_sftp_session_method_open_3
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sftp_session_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sftp_session_method_print_0
  },
};/*}}}*/

built_in_variable_s sftp_session_variables[] =
{/*{{{*/
  {
    "MODE_READ",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_WRITE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_APPEND",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_CREAT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_TRUNC",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "MODE_EXCL",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_sftp_session_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert open mode constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_SFTP_OPEN_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SFTP_OPEN_MODE_BIC_STATIC(LIBSSH2_FXF_READ);
    CREATE_SFTP_OPEN_MODE_BIC_STATIC(LIBSSH2_FXF_WRITE);
    CREATE_SFTP_OPEN_MODE_BIC_STATIC(LIBSSH2_FXF_APPEND);
    CREATE_SFTP_OPEN_MODE_BIC_STATIC(LIBSSH2_FXF_CREAT);
    CREATE_SFTP_OPEN_MODE_BIC_STATIC(LIBSSH2_FXF_TRUNC);
    CREATE_SFTP_OPEN_MODE_BIC_STATIC(LIBSSH2_FXF_EXCL);
  }
}/*}}}*/

void bic_sftp_session_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (sftp_session_s *)NULL;
}/*}}}*/

void bic_sftp_session_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  sftp_session_s *sftps_ptr = (sftp_session_s *)location_ptr->v_data_ptr;

  // - if session exists -
  if (sftps_ptr != NULL)
  {
    sftps_ptr->clear(it);
    cfree(sftps_ptr);
  }
}/*}}}*/

bool bic_sftp_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sftp_session_method_mkdir_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int dir_mode;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,dir_mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("mkdir#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve sftp session -
  sftp_session_s *sftps_ptr = (sftp_session_s *)dst_location->v_data_ptr;

  // - retrieve directory name -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (libssh2_sftp_mkdir_ex(sftps_ptr->session,path_ptr->data,path_ptr->size - 1,dir_mode) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_DIR_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sftp_session_method_rmdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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

  // - retrieve sftp session -
  sftp_session_s *sftps_ptr = (sftp_session_s *)dst_location->v_data_ptr;

  // - retrieve directory name -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (libssh2_sftp_rmdir_ex(sftps_ptr->session,path_ptr->data,path_ptr->size - 1) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_DIR_REMOVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sftp_session_method_listdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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

  // - retrieve sftp session -
  sftp_session_s *sftps_ptr = (sftp_session_s *)dst_location->v_data_ptr;

  // - retrieve path string -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  // - open directory handle -
  LIBSSH2_SFTP_HANDLE *sftp_handle = libssh2_sftp_open_ex(sftps_ptr->session,path_ptr->data,path_ptr->size - 1,LIBSSH2_FXF_READ,0,LIBSSH2_SFTP_OPENDIR);

  // - ERROR -
  if (sftp_handle == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create name buffer -
  const size_t c_buffer_size = 1024;
  char *buffer = (char *)cmalloc(c_buffer_size*sizeof(char));

  // - create logentry buffer -
  const size_t c_logentry_size = 1024;
  char *logentry = (char *)cmalloc(c_logentry_size*sizeof(char));

  // - sftp attributes storage -
  LIBSSH2_SFTP_ATTRIBUTES attrs;

  int read_cnt;
  do
  {
    read_cnt = libssh2_sftp_readdir_ex(sftp_handle,buffer,c_buffer_size,logentry,c_logentry_size,&attrs);

    if (read_cnt <= 0)
    {
      break;
    }

    // - skip reference to this and parent directory -
    if (!(buffer[0] == '.' && (buffer[1] == '\0' || (buffer[1] == '.' && buffer[2] == '\0'))))
    {
      string_s *entry_name = it.get_new_string_ptr();
      entry_name->set(read_cnt,buffer);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,entry_name);
      array_ptr->push(new_location);
    }
  }
  while(true);

  cfree(buffer);
  cfree(logentry);

  // - ERROR -
  if (read_cnt < 0)
  {
    libssh2_sftp_closedir(sftp_handle);

    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  if (libssh2_sftp_closedir(sftp_handle) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_DIR_LIST_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_sftp_session_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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

  // - retrieve sftp session -
  sftp_session_s *sftps_ptr = (sftp_session_s *)dst_location->v_data_ptr;

  // - retrieve file name -
  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (libssh2_sftp_unlink_ex(sftps_ptr->session,path_ptr->data,path_ptr->size - 1) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_FILE_REMOVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sftp_session_method_open_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int open_flags;
  long long int open_mode;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,open_flags) ||
      !it.retrieve_integer(src_2_location,open_mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("open#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - retrieve sftp session -
  sftp_session_s *sftps_ptr = (sftp_session_s *)dst_location->v_data_ptr;

  // - retrieve file name -
  string_s *file_name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create sftp handle object -
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)cmalloc(sizeof(sftp_handle_s));
  sftph_ptr->init();

  // - open file handle -
  sftph_ptr->handle = libssh2_sftp_open_ex(sftps_ptr->session,file_name_ptr->data,file_name_ptr->size - 1,open_flags,open_mode,LIBSSH2_SFTP_OPENFILE);

  // - ERROR -
  if (sftph_ptr->handle == NULL)
  {
    sftph_ptr->clear(it);
    cfree(sftph_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SFTP_SESSION_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create reference to sftp session -
  dst_location->v_reference_cnt.atomic_inc();
  sftph_ptr->sftps_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sftp_handle,sftph_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sftp_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SftpSession"),"SftpSession");
  );

  return true;
}/*}}}*/

bool bic_sftp_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SftpSession");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SFTP_HANDLE -
built_in_class_s sftp_handle_class =
{/*{{{*/
  "SftpHandle",
  c_modifier_public | c_modifier_final,
  9, sftp_handle_methods,
  0, sftp_handle_variables,
  bic_sftp_handle_consts,
  bic_sftp_handle_init,
  bic_sftp_handle_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_sftp_handle_next_item,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s sftp_handle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_operator_binary_equal
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_method_close_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_method_read_0
  },
  {
    "readln#0",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_method_readln_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_method_read_1
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_sftp_handle_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sftp_handle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sftp_handle_method_print_0
  },
};/*}}}*/

built_in_variable_s sftp_handle_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_SFTP_HANDLE_READLN() \
  /*{{{*/\
  const unsigned c_init_buffer_size = 1024;\
  \
  /* - target data buffer - */\
  bc_array_s line_buffer;\
  line_buffer.init_size(c_init_buffer_size);\
  \
  ssize_t read_cnt;\
  do\
  {\
    read_cnt = sftph_ptr->buff_read(line_buffer,1);\
    \
    if (read_cnt <= 0)\
    {\
      break;\
    }\
    \
    if (line_buffer.last() == '\n')\
    {\
      line_buffer.pop();\
      break;\
    }\
  }\
  while(true);\
  /*}}}*/

#define BIC_SFTP_HANDLE_NEXT_ITEM() \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    \
    /* - retrieve sftp handle - */\
    sftp_handle_s *sftph_ptr = (sftp_handle_s *)dst_location->v_data_ptr;\
    \
    /* - ERROR - */\
    if (sftph_ptr == NULL)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    BIC_SFTP_HANDLE_READLN();\
    \
    /* - ERROR - */\
    if (read_cnt < 0)\
    {\
      line_buffer.clear();\
      \
      exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
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

void bic_sftp_handle_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_sftp_handle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (sftp_handle_s *)NULL;
}/*}}}*/

void bic_sftp_handle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)location_ptr->v_data_ptr;

  // - if handle exists -
  if (sftph_ptr != NULL)
  {
    sftph_ptr->clear(it);
    cfree(sftph_ptr);
  }
}/*}}}*/

location_s *bic_sftp_handle_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/

  /* - retrieve sftp handle - */
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)location_ptr->v_data_ptr;

  // - ERROR -
  if (sftph_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_NOT_OPENED,source_pos,(location_s *)it.blank_location);
    return NULL;
  }

  BIC_SFTP_HANDLE_READLN();

  // - ERROR -
  if (read_cnt < 0)
  {
    line_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_READ_ERROR,source_pos,(location_s *)it.blank_location);
    return NULL;
  }

  if (read_cnt == 0 && line_buffer.used == 0)
  {
    line_buffer.clear();

    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return ((location_s *)it.blank_location);
  }
  else
  {
    line_buffer.push('\0');

    // - return data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = line_buffer.data;
    string_ptr->size = line_buffer.used;

    // - create result location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);

    return new_location;
  }
}/*}}}*/

bool bic_sftp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sftp_handle_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve sftp handle -
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (sftph_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - close sftp handle -
  int result = libssh2_sftp_close_handle(sftph_ptr->handle);
  // - ERROR -
  if (result != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  sftph_ptr->handle = NULL;

  // - release sftp handle object -
  sftph_ptr->clear(it);
  cfree(sftph_ptr);

  dst_location->v_data_ptr = (sftp_handle_s *)NULL;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sftp_handle_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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

  // - retrieve sftp handle -
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (sftph_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  ssize_t string_length = string_ptr->size - 1;

  ssize_t writed = 0;
  do {
    ssize_t write_cnt = libssh2_sftp_write(sftph_ptr->handle,string_ptr->data + writed,string_length - writed);

    if (write_cnt < 0)
    {
      break;
    }

    writed += write_cnt;

  } while(writed < string_length);

  // - ERROR -
  if (writed != string_length)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sftp_handle_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve sftp handle -
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (sftph_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const unsigned c_buffer_add = 32768;

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  ssize_t read_cnt;
  do
  {
    read_cnt = sftph_ptr->buff_read(data_buffer,c_buffer_add);

    if (read_cnt <= 0)
    {
      break;
    }
  }
  while(true);

  if (read_cnt < 0)
  {
    data_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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

bool bic_sftp_handle_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SFTP_HANDLE_NEXT_ITEM();
}/*}}}*/

bool bic_sftp_handle_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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

  // - retrieve sftp handle -
  sftp_handle_s *sftph_ptr = (sftp_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (sftph_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  ssize_t read_cnt;
  do
  {
    read_cnt = sftph_ptr->buff_read(data_buffer,byte_cnt - data_buffer.used);

    if (read_cnt <= 0)
    {
      break;
    }
  }
  while(data_buffer.used < byte_cnt);

  // - if all requested bytes were not read -
  if (data_buffer.used < byte_cnt)
  {
    data_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_SFTP_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  data_buffer.push('\0');

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = data_buffer.data;
  string_ptr->size = data_buffer.used;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sftp_handle_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SFTP_HANDLE_NEXT_ITEM();
}/*}}}*/

bool bic_sftp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SftpHandle"),"SftpHandle");
  );

  return true;
}/*}}}*/

bool bic_sftp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SftpHandle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SSH2_CHANNEL -
built_in_class_s ssh2_channel_class =
{/*{{{*/
  "Ssh2Channel",
  c_modifier_public | c_modifier_final,
  8, ssh2_channel_methods,
  0, ssh2_channel_variables,
  bic_ssh2_channel_consts,
  bic_ssh2_channel_init,
  bic_ssh2_channel_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ssh2_channel_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_channel_operator_binary_equal
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_ssh2_channel_method_write_1
  },
  {
    "flush#0",
    c_modifier_public | c_modifier_final,
    bic_ssh2_channel_method_flush_0
  },
  {
    "send_eof#0",
    c_modifier_public | c_modifier_final,
    bic_ssh2_channel_method_send_eof_0
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_ssh2_channel_method_read_0
  },
  {
    "read_stderr#0",
    c_modifier_public | c_modifier_final,
    bic_ssh2_channel_method_read_stderr_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssh2_channel_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssh2_channel_method_print_0
  },
};/*}}}*/

built_in_variable_s ssh2_channel_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_SSH2_CHANNEL_READ(FUNCTION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  /* - retrieve ssh2 channel - */\
  ssh2_channel_s *ssh2ch_ptr = (ssh2_channel_s *)dst_location->v_data_ptr;\
\
  const int c_buffer_add = 1024;\
\
  /* - target data buffer - */\
  bc_array_s data_buffer;\
  data_buffer.init();\
\
  ssize_t read_cnt;\
  do\
  {\
    unsigned old_used = data_buffer.used;\
    data_buffer.push_blanks(c_buffer_add);\
    read_cnt = FUNCTION(ssh2ch_ptr->channel,data_buffer.data + old_used,c_buffer_add);\
  }\
  while(read_cnt >= c_buffer_add);\
\
  /* - ERROR - */\
  if (read_cnt < 0)\
  {\
    data_buffer.clear();\
\
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_CHANNEL_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
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
\
  return true;\
}/*}}}*/

void bic_ssh2_channel_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ssh2_channel_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ssh2_channel_s *)NULL;
}/*}}}*/

void bic_ssh2_channel_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ssh2_channel_s *ssh2ch_ptr = (ssh2_channel_s *)location_ptr->v_data_ptr;

  // - if handle exists -
  if (ssh2ch_ptr != NULL)
  {
    ssh2ch_ptr->clear(it);
    cfree(ssh2ch_ptr);
  }
}/*}}}*/

bool bic_ssh2_channel_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ssh2_channel_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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

  // - retrieve ssh2 channel -
  ssh2_channel_s *ssh2ch_ptr = (ssh2_channel_s *)dst_location->v_data_ptr;

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  int string_length = string_ptr->size - 1;

  // - ERROR -
  if (libssh2_channel_write(ssh2ch_ptr->channel,string_ptr->data,string_length) != string_length)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_CHANNEL_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ssh2_channel_method_flush_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve ssh2 channel -
  ssh2_channel_s *ssh2ch_ptr = (ssh2_channel_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (libssh2_channel_flush(ssh2ch_ptr->channel) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_CHANNEL_FLUSH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ssh2_channel_method_send_eof_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve ssh2 channel -
  ssh2_channel_s *ssh2ch_ptr = (ssh2_channel_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (libssh2_channel_send_eof(ssh2ch_ptr->channel) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSH2_CHANNEL_SEND_EOF_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ssh2_channel_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SSH2_CHANNEL_READ(libssh2_channel_read);
}/*}}}*/

bool bic_ssh2_channel_method_read_stderr_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SSH2_CHANNEL_READ(libssh2_channel_read_stderr);
}/*}}}*/

bool bic_ssh2_channel_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Ssh2Channel"),"Ssh2Channel");
  );

  return true;
}/*}}}*/

bool bic_ssh2_channel_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Ssh2Channel");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

