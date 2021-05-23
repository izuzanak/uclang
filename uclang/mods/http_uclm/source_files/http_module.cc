
@begin
include "http_module.h"
@end

// - HTTP indexes of built in classes -
unsigned c_bi_class_http_server = c_idx_not_exist;
unsigned c_bi_class_http_conn = c_idx_not_exist;
unsigned c_bi_class_http_resp = c_idx_not_exist;
unsigned c_bi_class_http_post_proc = c_idx_not_exist;

#ifdef ENABLE_RM_CLASS_SOCKET
unsigned c_rm_class_socket_addr = c_idx_not_exist;
#endif

// - HTTP module -
EXPORT built_in_module_s module =
{/*{{{*/
  4,                     // Class count
  http_classes,          // Classes

  0,                     // Error base index
  21,                    // Error count
  http_error_strings,    // Error strings

  http_initialize,       // Initialize function
  http_print_exception,  // Print exceptions function
};/*}}}*/

// - HTTP classes -
built_in_class_s *http_classes[] =
{/*{{{*/
  &http_server_class,
  &http_conn_class,
  &http_resp_class,
  &http_post_proc_class,
};/*}}}*/

// - HTTP error strings -
const char *http_error_strings[] =
{/*{{{*/
  "error_HTTP_SERVER_WRONG_CALLBACK_DELEGATE",
  "error_HTTP_SERVER_CANNOT_START_DAEMON",
  "error_HTTP_SERVER_INTERNAL_ERROR",
  "error_HTTP_SERVER_WAS_STOPPED",
  "error_HTTP_SERVER_EXPECTED_INTEGER_AS_OPTION_ID",
  "error_HTTP_SERVER_UNKNOWN_OPTION_ID",
  "error_HTTP_SERVER_INVALID_OPTION_VALUE_TYPE",
  "error_HTTP_CONN_UNKNOWN_VALUES_TYPE",
  "error_HTTP_CONN_INVALID_VALUE_NAME",
  "error_HTTP_CONN_ALREADY_SUSPENDED",
  "error_HTTP_CONN_NOT_SUSPENDED",
  "error_HTTP_CONN_CANNOT_QUEUE_RESPONSE",
  "error_HTTP_CONN_CANNOT_RETRIEVE_CLIENT_IP",
  "error_HTTP_RESP_CREATE_ERROR",
  "error_HTTP_RESP_UNKNOWN_DATA_SOURCE_IDENTIFIER",
  "error_HTTP_RESP_CANNOT_READ_SOURCE_FILE",
  "error_HTTP_RESP_CANNOT_ADD_HEADER_FOOTER",
  "error_HTTP_POST_PROC_BUFFER_TOO_SMALL",
  "error_HTTP_POST_PROC_WRONG_CALLBACK_DELEGATE",
  "error_HTTP_POST_PROC_CREATE_ERROR",
  "error_HTTP_POST_PROC_INTERNAL_ERROR",
};/*}}}*/

// - HTTP initialize -
bool http_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize http_server class identifier -
  c_bi_class_http_server = class_base_idx++;

  // - initialize http_conn class identifier -
  c_bi_class_http_conn = class_base_idx++;

  // - initialize http_resp class identifier -
  c_bi_class_http_resp = class_base_idx++;

  // - initialize http_post_proc class identifier -
  c_bi_class_http_post_proc = class_base_idx++;

#ifdef ENABLE_RM_CLASS_SOCKET
  // - retrieve remote dict class index -
  c_rm_class_socket_addr = sp.resolve_class_idx_by_name("SocketAddr",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_socket_addr == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }
#endif

  return true;
}/*}}}*/

// - HTTP print exception -
bool http_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_HTTP_SERVER_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for HTTP server connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_SERVER_CANNOT_START_DAEMON:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot start HTTP server daemon\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_SERVER_INTERNAL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInternal error of HTTP server\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_SERVER_WAS_STOPPED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP server was stopped (cannot be used any more)\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_SERVER_EXPECTED_INTEGER_AS_OPTION_ID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP server, expected integer as option identifier\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_SERVER_UNKNOWN_OPTION_ID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP server, unknown option identifier\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_SERVER_INVALID_OPTION_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP server, invalid type of option value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_CONN_UNKNOWN_VALUES_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown type of requested HTTP connection values\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_CONN_INVALID_VALUE_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid name \"%s\" of requested HTTP connection value\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_CONN_ALREADY_SUSPENDED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP connection is already suspended\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_CONN_NOT_SUSPENDED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP connection is not suspended\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_CONN_CANNOT_QUEUE_RESPONSE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot queue response to HTTP connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_CONN_CANNOT_RETRIEVE_CLIENT_IP:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve client IP of HTTP connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_RESP_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating HTTP response\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_RESP_UNKNOWN_DATA_SOURCE_IDENTIFIER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown identifier of HTTP response data source\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_RESP_CANNOT_READ_SOURCE_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read HTTP response file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_RESP_CANNOT_ADD_HEADER_FOOTER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot add header or footer to response\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_POST_PROC_BUFFER_TOO_SMALL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nHTTP post processor buffer is too small\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_POST_PROC_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for HTTP post processor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_POST_PROC_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating HTTP post processor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_HTTP_POST_PROC_INTERNAL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInternal error of HTTP post processor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class HTTP_SERVER -
built_in_class_s http_server_class =
{/*{{{*/
  "HttpServer",
  c_modifier_public | c_modifier_final,
  9, http_server_methods,
  3 + 2
#ifdef ENABLE_RM_CLASS_SOCKET
  + 1
#endif
  , http_server_variables,
  bic_http_server_consts,
  bic_http_server_init,
  bic_http_server_clear,
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

built_in_method_s http_server_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_http_server_operator_binary_equal
  },
  {
    "HttpServer#4",
    c_modifier_public | c_modifier_final,
    bic_http_server_method_HttpServer_4
  },
  {
    "stop#0",
    c_modifier_public | c_modifier_final,
    bic_http_server_method_stop_0
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_http_server_method_get_fds_0
  },
  {
    "timeout#0",
    c_modifier_public | c_modifier_final,
    bic_http_server_method_timeout_0
  },
  {
    "process#0",
    c_modifier_public | c_modifier_final,
    bic_http_server_method_process_0
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final,
    bic_http_server_method_process_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_server_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_server_method_print_0
  },
};/*}}}*/

built_in_variable_s http_server_variables[] =
{/*{{{*/

  // - http server use constants -
  { "USE_SSL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "USE_POLL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "USE_EPOLL", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - http server option constants -
#ifdef ENABLE_RM_CLASS_SOCKET
  { "OPTION_SOCK_ADDR", c_modifier_public | c_modifier_static | c_modifier_static_const },
#endif
  { "OPTION_HTTPS_MEM_KEY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPTION_HTTPS_MEM_CERT", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_http_server_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert http server use constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_HTTP_SERVER_USE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_HTTP_SERVER_USE_BIC_STATIC(MHD_USE_SSL);
    CREATE_HTTP_SERVER_USE_BIC_STATIC(MHD_USE_POLL);
    CREATE_HTTP_SERVER_USE_BIC_STATIC(MHD_USE_EPOLL);
  }

  // - insert http server option constants -
  {
    const_locations.push_blanks(2
#ifdef ENABLE_RM_CLASS_SOCKET
  + 1
#endif
    );
    location_s *cv_ptr = const_locations.data + (const_locations.used - (2
#ifdef ENABLE_RM_CLASS_SOCKET
  + 1
#endif
    ));

#define CREATE_HTTP_SERVER_OPTION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

#ifdef ENABLE_RM_CLASS_SOCKET
    CREATE_HTTP_SERVER_OPTION_BIC_STATIC(MHD_OPTION_SOCK_ADDR);
#endif
    CREATE_HTTP_SERVER_OPTION_BIC_STATIC(MHD_OPTION_HTTPS_MEM_KEY);
    CREATE_HTTP_SERVER_OPTION_BIC_STATIC(MHD_OPTION_HTTPS_MEM_CERT);
  }

}/*}}}*/

void bic_http_server_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (http_server_s *)nullptr;
}/*}}}*/

void bic_http_server_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  http_server_s *srv_ptr = (http_server_s *)location_ptr->v_data_ptr;

  if (srv_ptr != nullptr)
  {
    srv_ptr->clear(it);
    cfree(srv_ptr);
  }
}/*}}}*/

bool bic_http_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_http_server_method_HttpServer_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
flags:retrieve_integer
port:retrieve_integer
delegate:c_bi_class_delegate
opts:c_bi_class_array
>
method HttpServer
; @end

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process options -
  pointer_array_s *opts_array = (pointer_array_s *)src_3_location->v_data_ptr;

  MHD_OptionItem mhd_opts[(opts_array->used >> 1) + 2];
  MHD_OptionItem *mhd_opt_ptr = mhd_opts;

  if (opts_array->used != 0)
  {
    pointer *ptr = opts_array->data;
    pointer *ptr_end = ptr + opts_array->used;
    do {
      location_s *option_loc = it.get_location_value(*ptr);

      // - ERROR -
      long long int option;
      if (!it.retrieve_integer(option_loc,option))
      {
        exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_EXPECTED_INTEGER_AS_OPTION_ID,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      switch (option)
      {
#ifdef ENABLE_RM_CLASS_SOCKET
      case MHD_OPTION_SOCK_ADDR:
        {
          location_s *value_loc = it.get_location_value(ptr[1]);

          // - ERROR -
          if (value_loc->v_type != c_rm_class_socket_addr)
          {
            exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INVALID_OPTION_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          sockaddr *addr_ptr = (sockaddr *)value_loc->v_data_ptr;
          *mhd_opt_ptr++ = MHD_OptionItem{ (MHD_OPTION)option,0,addr_ptr };

          ptr += 2;
        }
        break;
#endif
      case MHD_OPTION_HTTPS_MEM_KEY:
      case MHD_OPTION_HTTPS_MEM_CERT:
        {
          location_s *value_loc = it.get_location_value(ptr[1]);

          // - ERROR -
          if (value_loc->v_type != c_bi_class_string)
          {
            exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INVALID_OPTION_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          string_s *string_ptr = (string_s *)value_loc->v_data_ptr;
          *mhd_opt_ptr++ = MHD_OptionItem{ (MHD_OPTION)option,0,string_ptr->data };

          ptr += 2;
        }
        break;

      // - ERROR -
      default:
        exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_UNKNOWN_OPTION_ID,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

    } while(ptr < ptr_end);
  }

  *mhd_opt_ptr++ = MHD_OptionItem{ MHD_OPTION_NOTIFY_COMPLETED,(intptr_t)completed_func,nullptr };
  *mhd_opt_ptr++ = MHD_OptionItem{ MHD_OPTION_END,0,nullptr };

  // - create http_server object -
  http_server_s *srv_ptr = (http_server_s *)cmalloc(sizeof(http_server_s));
  srv_ptr->init();

  // - register connection delegate -
  src_2_location->v_reference_cnt.atomic_inc();
  srv_ptr->connection_dlg = src_2_location;

  // - start http server -
  MHD_Daemon *daemon_ptr = MHD_start_daemon(
      MHD_USE_SUSPEND_RESUME | flags,port,nullptr,nullptr,
      &connection_func,dst_location,
      MHD_OPTION_ARRAY,mhd_opts,
      MHD_OPTION_END);

  // - ERROR -
  if (daemon_ptr == nullptr)
  {
    srv_ptr->clear(it);
    cfree(srv_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_CANNOT_START_DAEMON,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set server daemon pointer -
  srv_ptr->daemon_ptr = daemon_ptr;

  // - set http_server destination location -
  dst_location->v_data_ptr = (http_server_s *)srv_ptr;

  return true;
}/*}}}*/

bool bic_http_server_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve server pointer -
  http_server_s *srv_ptr = (http_server_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (srv_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_WAS_STOPPED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - stop http server -
  srv_ptr->clear(it);
  cfree(srv_ptr);

  dst_location->v_data_ptr = (http_server_s *)nullptr;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_http_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve server pointer -
  http_server_s *srv_ptr = (http_server_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (srv_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_WAS_STOPPED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - prepare file descriptor sets -
  fd_set rs; FD_ZERO(&rs);
  fd_set ws; FD_ZERO(&ws);
  fd_set es; FD_ZERO(&es);

  // - ERROR -
#if MHD_VERSION <= 0x00093300
  int max_fd = 0;
  if (MHD_YES != MHD_get_fdset(srv_ptr->daemon_ptr,&rs,&ws,&es,&max_fd))
#else
  MHD_socket max_fd = 0;
  if (MHD_YES != MHD_get_fdset2(srv_ptr->daemon_ptr,&rs,&ws,&es,&max_fd,FD_SETSIZE))
#endif
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INTERNAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (max_fd >= 0)
  {
#if MHD_VERSION <= 0x00093300
    int fd = 0;
#else
    MHD_socket fd = 0;
#endif
    do {
      long long int fd_value = -1;
      long long int flags = 0;

      // - test fd in read fd_set -
      if (FD_ISSET(fd,&rs))
      {
        fd_value = fd;
        flags |= POLLIN;
      }

      // - test fd in write fd_set -
      if (FD_ISSET(fd,&ws))
      {
        fd_value = fd;
        flags |= POLLOUT;
      }

      // - test fd in except fd_set -
      if (FD_ISSET(fd,&es))
      {
        fd_value = fd;
        flags |= POLLERR | POLLHUP | POLLNVAL;
      }

      if (fd_value != -1)
      {
        // - create fd value -
        {
          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,fd_value);
          array_ptr->push(new_location);
        }

        // - create flags -
        {
          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,flags);
          array_ptr->push(new_location);
        }
      }

    } while(++fd <= max_fd);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_http_server_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve server pointer -
  http_server_s *srv_ptr = (http_server_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (srv_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_WAS_STOPPED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MHD_UNSIGNED_LONG_LONG mhd_timeout;
  long long int result;

  // - retrieve mhd timeout -
  if (MHD_get_timeout(srv_ptr->daemon_ptr,&mhd_timeout) == MHD_YES)
  {
    result = mhd_timeout;
  }
  else
  {
    result = LLONG_MAX;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_http_server_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve server pointer -
  http_server_s *srv_ptr = (http_server_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (srv_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_WAS_STOPPED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  srv_ptr->it_ptr = &it;
  srv_ptr->source_pos = operands[c_source_pos_idx];
  srv_ptr->ret_code = c_run_return_code_OK;

  // - ERROR -
  if (MHD_run(srv_ptr->daemon_ptr) != MHD_YES)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INTERNAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - if exception occurred -
  if (srv_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_server_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
timeout:retrieve_integer
>
method process
; @end

  // - retrieve server pointer -
  http_server_s *srv_ptr = (http_server_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (srv_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_WAS_STOPPED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  srv_ptr->it_ptr = &it;
  srv_ptr->source_pos = operands[c_source_pos_idx];
  srv_ptr->ret_code = c_run_return_code_OK;

  MHD_Daemon *daemon_ptr = srv_ptr->daemon_ptr;

  // - prepare file descriptor sets -
  fd_set rs; FD_ZERO(&rs);
  fd_set ws; FD_ZERO(&ws);
  fd_set es; FD_ZERO(&es);

  // - ERROR -
#if MHD_VERSION <= 0x00093300
  int max_fd = 0;
  if (MHD_YES != MHD_get_fdset(daemon_ptr,&rs,&ws,&es,&max_fd))
#else
  MHD_socket max_fd = 0;
  if (MHD_YES != MHD_get_fdset2(daemon_ptr,&rs,&ws,&es,&max_fd,FD_SETSIZE))
#endif
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INTERNAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MHD_UNSIGNED_LONG_LONG mhd_timeout;

  // - retrieve mhd timeout -
  if (MHD_get_timeout(daemon_ptr,&mhd_timeout) == MHD_YES)
  {
    if ((long long int)mhd_timeout < timeout)
    {
      timeout = mhd_timeout;
    }
  }

  // - create time_value structure -
  struct timeval tv;
  tv.tv_sec = timeout / 1000;
  tv.tv_usec = (timeout - (tv.tv_sec * 1000)) * 1000;

  // - select prepared file descriptors -
  if (select(max_fd + 1,&rs,&ws,&es,&tv) >= 0)
  {
    // - ERROR -
    if (MHD_run(daemon_ptr) != MHD_YES)
    {
      exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INTERNAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }
  else
  {
    // - ERROR -
    if (errno != EINTR)
    {
      exception_s::throw_exception(it,module.error_base + c_error_HTTP_SERVER_INTERNAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - if exception occurred -
  if (srv_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("HttpServer"),"HttpServer");
  );

  return true;
}/*}}}*/

bool bic_http_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("HttpServer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class HTTP_CONN -
built_in_class_s http_conn_class =
{/*{{{*/
  "HttpConn",
  c_modifier_public | c_modifier_final,
  22, http_conn_methods,
  8 + 5 + 3, http_conn_variables,
  bic_http_conn_consts,
  bic_http_conn_init,
  bic_http_conn_clear,
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

built_in_method_s http_conn_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_http_conn_operator_binary_equal
  },
  {
    "id#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_id_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_get_type_0
  },
  {
    "url#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_url_0
  },
  {
    "method#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_method_0
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_version_0
  },
  {
    "upload_data#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_upload_data_0
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_user_data_0
  },
  {
    "values#1",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_values_1
  },
  {
    "value#2",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_value_2
  },
  {
    "client_ip#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_client_ip_0
  },
  {
    "suspend#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_suspend_0
  },
  {
    "resume#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_resume_0
  },
  {
    "queue_response#2",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_queue_response_2
  },
  {
    "queue_basic_auth_fail_response#2",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_queue_basic_auth_fail_response_2
  },
  {
    "basic_auth_username_password#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_basic_auth_username_password_0
  },
  {
    "queue_digest_auth_fail_response#4",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_queue_digest_auth_fail_response_4
  },
  {
    "digest_auth_username#0",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_digest_auth_username_0
  },
  {
    "digest_auth_check#4",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_digest_auth_check_4
  },
  {
    "post_processor#2",
    c_modifier_public | c_modifier_final,
    bic_http_conn_method_post_processor_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_conn_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_conn_method_print_0
  },
};/*}}}*/

built_in_variable_s http_conn_variables[] =
{/*{{{*/

  // - http conn type constants -
  { "TYPE_CONNECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DELETE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_HEAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_OPTIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_POST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TRACE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - http conn value type constants -
  { "VALS_HEADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VALS_COOKIE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VALS_POSTDATA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VALS_GET_ARGUMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VALS_FOOTER", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - http conn value result constants -
  { "YES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INVALID_NONCE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_HTTP_CONN_STRING_VARIABLE(VARIABLE) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;\
  const char *VARIABLE = conn_ptr->VARIABLE;\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(VARIABLE),VARIABLE);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

void bic_http_conn_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert http conn type constants -
  {
    const_locations.push_blanks(8);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 8);

#define CREATE_HTTP_CONN_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_CONNECT);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_DELETE);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_GET);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_HEAD);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_OPTIONS);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_POST);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_PUT);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_conn_type_TRACE);
  }

  // - insert http conn value type constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_HTTP_CONN_VALUES_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_HTTP_CONN_VALUES_TYPE_BIC_STATIC(MHD_HEADER_KIND);
    CREATE_HTTP_CONN_VALUES_TYPE_BIC_STATIC(MHD_COOKIE_KIND);
    CREATE_HTTP_CONN_VALUES_TYPE_BIC_STATIC(MHD_POSTDATA_KIND);
    CREATE_HTTP_CONN_VALUES_TYPE_BIC_STATIC(MHD_GET_ARGUMENT_KIND);
    CREATE_HTTP_CONN_VALUES_TYPE_BIC_STATIC(MHD_FOOTER_KIND);
  }

  // - insert http conn value result constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_HTTP_CONN_RESULT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_HTTP_CONN_RESULT_BIC_STATIC(MHD_YES);
    CREATE_HTTP_CONN_RESULT_BIC_STATIC(MHD_NO);
    CREATE_HTTP_CONN_RESULT_BIC_STATIC(MHD_INVALID_NONCE);
  }
}/*}}}*/

void bic_http_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (http_conn_s *)nullptr;
}/*}}}*/

void bic_http_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  http_conn_s *conn_ptr = (http_conn_s *)location_ptr->v_data_ptr;

  if (conn_ptr != nullptr)
  {
    conn_ptr->clear(it);
    cfree(conn_ptr);
  }
}/*}}}*/

bool bic_http_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_http_conn_method_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (long long int)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_http_conn_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  long long int result = conn_ptr->conn_type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_http_conn_method_url_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_HTTP_CONN_STRING_VARIABLE(url);
}/*}}}*/

bool bic_http_conn_method_method_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_HTTP_CONN_STRING_VARIABLE(method);
}/*}}}*/

bool bic_http_conn_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_HTTP_CONN_STRING_VARIABLE(version);
}/*}}}*/

bool bic_http_conn_method_upload_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  // - if upload data are available and are not empty -
  if (conn_ptr->upload_data != nullptr &&
      *conn_ptr->upload_data_size > 0)
  {
    // - create uploaded data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(*conn_ptr->upload_data_size,conn_ptr->upload_data);

    // - reset upload data size -
    *conn_ptr->upload_data_size = 0;

    BIC_SET_RESULT_STRING(string_ptr);
  }
  else
  {
    // - no more data available -
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_http_conn_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&conn_ptr->user_data_ptr);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_http_conn_method_values_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
vals_type:retrieve_integer
>
method values
; @end

  // - test requested values type -
  switch (vals_type)
  {
  case MHD_HEADER_KIND:
  case MHD_COOKIE_KIND:
  case MHD_POSTDATA_KIND:
  case MHD_GET_ARGUMENT_KIND:
  case MHD_FOOTER_KIND:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_UNKNOWN_VALUES_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  // - create target key value array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  // - retrieve key value locations -
  conn_ptr->key_value_arr_ptr = array_ptr;
  MHD_get_connection_values(conn_ptr->connection_ptr,(MHD_ValueKind)vals_type,&conn_key_value_func,conn_ptr);
  conn_ptr->key_value_arr_ptr = nullptr;

  return true;
}/*}}}*/

bool bic_http_conn_method_value_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
vals_type:retrieve_integer
key:c_bi_class_string
>
method value
; @end

  // - test requested values type -
  switch (vals_type)
  {
  case MHD_HEADER_KIND:
  case MHD_COOKIE_KIND:
  case MHD_POSTDATA_KIND:
  case MHD_GET_ARGUMENT_KIND:
  case MHD_FOOTER_KIND:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_UNKNOWN_VALUES_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  const char *value = MHD_lookup_connection_value(conn_ptr->connection_ptr,(MHD_ValueKind)vals_type,string_ptr->data);

  // - ERROR -
  if (value == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_INVALID_VALUE_NAME,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  string_s *value_ptr = it.get_new_string_ptr();
  value_ptr->set(strlen(value),value);

  BIC_SET_RESULT_STRING(value_ptr);

  return true;
}/*}}}*/

bool bic_http_conn_method_client_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve connection pointer -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  const union MHD_ConnectionInfo *info;
  info = MHD_get_connection_info(conn_ptr->connection_ptr,MHD_CONNECTION_INFO_CLIENT_ADDRESS);

  // - ERROR -
  if (info == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_CANNOT_RETRIEVE_CLIENT_IP,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(256);

  // - ERROR -
  if (getnameinfo((sockaddr *)info->client_addr,sizeof(sockaddr_in),string_ptr->data,
        string_ptr->size - 1,nullptr,0,NI_NUMERICHOST | NI_NUMERICSERV) != 0)
  {
    string_ptr->clear();
    cfree(string_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_CANNOT_RETRIEVE_CLIENT_IP,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set string size -
  string_ptr->size = strlen(string_ptr->data) + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_http_conn_method_suspend_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve connection pointer -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (conn_ptr->suspend_idx != c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_ALREADY_SUSPENDED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - suspend connection -
  MHD_suspend_connection(conn_ptr->connection_ptr);

  // - add suspended connection to server -
  conn_ptr->suspend_idx = conn_ptr->srv_ptr->suspended_conns.append(dst_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_conn_method_resume_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve connection pointer -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (conn_ptr->suspend_idx == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_NOT_SUSPENDED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - resume connection -
  MHD_resume_connection(conn_ptr->connection_ptr);

  // - remove suspended connection from server -
  conn_ptr->srv_ptr->suspended_conns.remove(conn_ptr->suspend_idx);
  conn_ptr->suspend_idx = c_idx_not_exist;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_conn_method_queue_response_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
status_code:retrieve_integer
response:c_bi_class_http_resp
>
method queue_response
; @end

  // - retrieve connection and response pointers -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;
  MHD_Response *resp_ptr = (MHD_Response *)src_1_location->v_data_ptr;

  // - queue response to be transmitted to client -
  int result = MHD_queue_response(conn_ptr->connection_ptr,status_code,resp_ptr);

  // - ERROR -
  if (result != MHD_YES)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_CANNOT_QUEUE_RESPONSE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_conn_method_queue_basic_auth_fail_response_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
realm:c_bi_class_string
response:c_bi_class_http_resp
>
method queue_basic_auth_fail_response
; @end

  // - retrieve connection and response pointers -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;
  MHD_Response *resp_ptr = (MHD_Response *)src_1_location->v_data_ptr;

  string_s *realm_ptr = (string_s *)src_0_location->v_data_ptr;

  // - queue response to be transmitted to client -
  int result = MHD_queue_basic_auth_fail_response(conn_ptr->connection_ptr,realm_ptr->data,resp_ptr);

  // - ERROR -
  if (result != MHD_YES)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_CANNOT_QUEUE_RESPONSE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_conn_method_basic_auth_username_password_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve connection pointer -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  char *user;
  char *pass = nullptr;

  user = MHD_basic_auth_get_username_password(conn_ptr->connection_ptr,&pass);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

#define BIC_HTTP_CONN_METHOD_BASIC_AUTH_USERNAME_PASSWORD_ADD_VALUE(NAME) \
{/*{{{*/\
  if (NAME != nullptr)\
  {\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->set(strlen(NAME),NAME);\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    array_ptr->push(new_location);\
\
    free(NAME);\
  }\
  else\
  {\
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
    array_ptr->push(it.blank_location);\
  }\
}/*}}}*/

  BIC_HTTP_CONN_METHOD_BASIC_AUTH_USERNAME_PASSWORD_ADD_VALUE(user);
  BIC_HTTP_CONN_METHOD_BASIC_AUTH_USERNAME_PASSWORD_ADD_VALUE(pass);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_http_conn_method_queue_digest_auth_fail_response_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
realm:c_bi_class_string
opaque:c_bi_class_string
response:c_bi_class_http_resp
signal_stale:retrieve_integer
>
method queue_digest_auth_fail_response
; @end

  // - retrieve connection and response pointers -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;
  MHD_Response *resp_ptr = (MHD_Response *)src_2_location->v_data_ptr;

  string_s *realm_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *opaque_ptr = (string_s *)src_1_location->v_data_ptr;

  // - queue response to be transmitted to client -
  int result = MHD_queue_auth_fail_response(
      conn_ptr->connection_ptr,realm_ptr->data,opaque_ptr->data,resp_ptr,signal_stale);

  // - ERROR -
  if (result != MHD_YES)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_CONN_CANNOT_QUEUE_RESPONSE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_conn_method_digest_auth_username_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve connection pointer -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  char *user_name = MHD_digest_auth_get_username(conn_ptr->connection_ptr);

  if (user_name != nullptr)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(user_name),user_name);
    free(user_name);

    BIC_SET_RESULT_STRING(string_ptr);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_http_conn_method_digest_auth_check_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
realm:c_bi_class_string
user:c_bi_class_string
password:c_bi_class_string
nonce_timeout:retrieve_integer
>
method digest_auth_check
; @end

  // - retrieve connection and response pointers -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  string_s *realm_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *user_ptr = (string_s *)src_1_location->v_data_ptr;
  string_s *pass_ptr = (string_s *)src_2_location->v_data_ptr;

  // - queue response to be transmitted to client -
  long long int result = MHD_digest_auth_check(
      conn_ptr->connection_ptr,realm_ptr->data,user_ptr->data,pass_ptr->data,nonce_timeout);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_http_conn_method_post_processor_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
buffer_size:retrieve_integer
delegate:c_bi_class_delegate
>
method post_processor
; @end

  // - retrieve connection pointer -
  http_conn_s *conn_ptr = (http_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (buffer_size < 256)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_POST_PROC_BUFFER_TOO_SMALL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_POST_PROC_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create http_post_proc object -
  http_post_proc_s *pp_ptr = (http_post_proc_s *)cmalloc(sizeof(http_post_proc_s));
  pp_ptr->init();

  BIC_CREATE_NEW_LOCATION(pp_location,c_bi_class_http_post_proc,pp_ptr);

  // - create http post processor -
  pp_ptr->post_proc = MHD_create_post_processor(conn_ptr->connection_ptr,
    buffer_size,post_proc_func,pp_location);

  // - ERROR -
  if (pp_ptr->post_proc == nullptr)
  {
    it.release_location_ptr(pp_location);

    exception_s::throw_exception(it,module.error_base + c_error_HTTP_POST_PROC_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  pp_ptr->user_data_ptr = (location_s *)it.blank_location;

  src_1_location->v_reference_cnt.atomic_inc();
  pp_ptr->callback_dlg = src_1_location;

  BIC_SET_RESULT(pp_location);

  return true;
}/*}}}*/

bool bic_http_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("HttpConn"),"HttpConn");
  );

  return true;
}/*}}}*/

bool bic_http_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("HttpConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class HTTP_RESP -
built_in_class_s http_resp_class =
{/*{{{*/
  "HttpResp",
  c_modifier_public | c_modifier_final,
  7, http_resp_methods,
  2 + 53, http_resp_variables,
  bic_http_resp_consts,
  bic_http_resp_init,
  bic_http_resp_clear,
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

built_in_method_s http_resp_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_http_resp_operator_binary_equal
  },
  {
    "HttpResp#1",
    c_modifier_public | c_modifier_final,
    bic_http_resp_method_HttpResp_1
  },
  {
    "HttpResp#2",
    c_modifier_public | c_modifier_final,
    bic_http_resp_method_HttpResp_2
  },
  {
    "add_header#2",
    c_modifier_public | c_modifier_final,
    bic_http_resp_method_add_header_2
  },
  {
    "add_footer#2",
    c_modifier_public | c_modifier_final,
    bic_http_resp_method_add_footer_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_resp_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_resp_method_print_0
  },
};/*}}}*/

built_in_variable_s http_resp_variables[] =
{/*{{{*/

  // - create constants -
  { "FROM_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FROM_FILE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - response codes -
  { "HTTP_CONTINUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_SWITCHING_PROTOCOLS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_PROCESSING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_CREATED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_ACCEPTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NON_AUTHORITATIVE_INFORMATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NO_CONTENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_RESET_CONTENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_PARTIAL_CONTENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_MULTI_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_MULTIPLE_CHOICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_MOVED_PERMANENTLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_SEE_OTHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NOT_MODIFIED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_USE_PROXY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_SWITCH_PROXY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_TEMPORARY_REDIRECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_BAD_REQUEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_UNAUTHORIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_PAYMENT_REQUIRED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_FORBIDDEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_METHOD_NOT_ALLOWED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_METHOD_NOT_ACCEPTABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_PROXY_AUTHENTICATION_REQUIRED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_REQUEST_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_CONFLICT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_GONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_LENGTH_REQUIRED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_PRECONDITION_FAILED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_UNSUPPORTED_MEDIA_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_EXPECTATION_FAILED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_UNPROCESSABLE_ENTITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_LOCKED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_FAILED_DEPENDENCY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_UNORDERED_COLLECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_UPGRADE_REQUIRED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NO_RESPONSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_RETRY_WITH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_UNAVAILABLE_FOR_LEGAL_REASONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_INTERNAL_SERVER_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NOT_IMPLEMENTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_BAD_GATEWAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_SERVICE_UNAVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_GATEWAY_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_HTTP_VERSION_NOT_SUPPORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_VARIANT_ALSO_NEGOTIATES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_INSUFFICIENT_STORAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_BANDWIDTH_LIMIT_EXCEEDED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HTTP_NOT_EXTENDED", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_http_resp_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert http resp create constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_HTTP_RESP_CREATE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_resp_from_string);
    CREATE_HTTP_CONN_TYPE_BIC_STATIC(c_resp_from_file);
  }

  // - insert http resp response codes -
  {
    const_locations.push_blanks(53);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 53);

#define CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_CONTINUE);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_SWITCHING_PROTOCOLS);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_PROCESSING);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_OK);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_CREATED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_ACCEPTED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NON_AUTHORITATIVE_INFORMATION);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NO_CONTENT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_RESET_CONTENT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_PARTIAL_CONTENT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_MULTI_STATUS);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_MULTIPLE_CHOICES);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_MOVED_PERMANENTLY);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_FOUND);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_SEE_OTHER);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NOT_MODIFIED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_USE_PROXY);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_SWITCH_PROXY);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_TEMPORARY_REDIRECT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_BAD_REQUEST);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_UNAUTHORIZED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_PAYMENT_REQUIRED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_FORBIDDEN);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NOT_FOUND);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_METHOD_NOT_ALLOWED);
#ifdef MHD_HTTP_NOT_ACCEPTABLE
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NOT_ACCEPTABLE);
#else
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_METHOD_NOT_ACCEPTABLE);
#endif
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_PROXY_AUTHENTICATION_REQUIRED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_REQUEST_TIMEOUT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_CONFLICT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_GONE);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_LENGTH_REQUIRED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_PRECONDITION_FAILED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_UNSUPPORTED_MEDIA_TYPE);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_EXPECTATION_FAILED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_UNPROCESSABLE_ENTITY);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_LOCKED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_FAILED_DEPENDENCY);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_UNORDERED_COLLECTION);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_UPGRADE_REQUIRED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NO_RESPONSE);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_RETRY_WITH);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_UNAVAILABLE_FOR_LEGAL_REASONS);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_INTERNAL_SERVER_ERROR);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NOT_IMPLEMENTED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_BAD_GATEWAY);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_SERVICE_UNAVAILABLE);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_GATEWAY_TIMEOUT);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_HTTP_VERSION_NOT_SUPPORTED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_VARIANT_ALSO_NEGOTIATES);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_INSUFFICIENT_STORAGE);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_BANDWIDTH_LIMIT_EXCEEDED);
    CREATE_HTTP_RESP_RESPONSE_BIC_STATIC(MHD_HTTP_NOT_EXTENDED);
  }

}/*}}}*/

void bic_http_resp_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (MHD_Response *)nullptr;
}/*}}}*/

void bic_http_resp_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  MHD_Response *resp_ptr = (MHD_Response *)location_ptr->v_data_ptr;

  if (resp_ptr != nullptr)
  {
    MHD_destroy_response(resp_ptr);
  }
}/*}}}*/

bool bic_http_resp_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_http_resp_method_HttpResp_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method HttpResp
; @end

  // - create http_resp object -
  MHD_Response *resp_ptr = MHD_create_response_from_buffer(
      data_size,(void *)data_ptr,MHD_RESPMEM_MUST_COPY);

  // - ERROR -
  if (resp_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set http_resp destination location -
  dst_location->v_data_ptr = (MHD_Response *)resp_ptr;

  return true;
}/*}}}*/

bool bic_http_resp_method_HttpResp_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
from_type:retrieve_integer
string:c_bi_class_string
>
method HttpResp
; @end

  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - http_resp object pointer -
  MHD_Response *resp_ptr;

  switch (from_type)
  {
  case c_resp_from_string:
    {
      // - create response from buffer -
      resp_ptr = MHD_create_response_from_buffer(string_ptr->size - 1,
          string_ptr->data,MHD_RESPMEM_MUST_COPY);
    }
    break;

  case c_resp_from_file:
    {
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
      // - open file descriptor -
      int fd = _open(string_ptr->data,_O_RDONLY);

      // - ERROR -
      if (fd == -1)
      {
        exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CANNOT_READ_SOURCE_FILE,operands[c_source_pos_idx],src_1_location);
        return false;
      }

      // - retrieve file size -
      struct _stat file_stat;

      // - ERROR -
      if (_fstat(fd,&file_stat) != 0)
      {
        _close(fd);

        exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CANNOT_READ_SOURCE_FILE,operands[c_source_pos_idx],src_1_location);
        return false;
      }
#else
      // - open file descriptor -
      int fd = open(string_ptr->data,O_RDONLY);

      // - ERROR -
      if (fd == -1)
      {
        exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CANNOT_READ_SOURCE_FILE,operands[c_source_pos_idx],src_1_location);
        return false;
      }

      // - retrieve file size -
      struct stat file_stat;

      // - ERROR -
      if (fstat(fd,&file_stat) != 0)
      {
        close(fd);

        exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CANNOT_READ_SOURCE_FILE,operands[c_source_pos_idx],src_1_location);
        return false;
      }
#endif

      // - create response from file descriptor -
      resp_ptr = MHD_create_response_from_fd(file_stat.st_size,fd);
    }
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_UNKNOWN_DATA_SOURCE_IDENTIFIER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (resp_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set http_resp destination location -
  dst_location->v_data_ptr = (MHD_Response *)resp_ptr;

  return true;
}/*}}}*/

bool bic_http_resp_method_add_header_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
header:c_bi_class_string
value:c_bi_class_string
>
method add_header
; @end

  MHD_Response *resp_ptr = (MHD_Response *)dst_location->v_data_ptr;

  string_s *header_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *value_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (MHD_add_response_header(resp_ptr,header_ptr->data,value_ptr->data) == MHD_NO)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CANNOT_ADD_HEADER_FOOTER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_resp_method_add_footer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
footer:c_bi_class_string
value:c_bi_class_string
>
method add_footer
; @end

  MHD_Response *resp_ptr = (MHD_Response *)dst_location->v_data_ptr;

  string_s *footer_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *value_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (MHD_add_response_footer(resp_ptr,footer_ptr->data,value_ptr->data) == MHD_NO)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_RESP_CANNOT_ADD_HEADER_FOOTER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_resp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("HttpResp"),"HttpResp");
  );

  return true;
}/*}}}*/

bool bic_http_resp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("HttpResp");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class HTTP_POST_PROC -
built_in_class_s http_post_proc_class =
{/*{{{*/
  "HttpPostProc",
  c_modifier_public | c_modifier_final,
  8, http_post_proc_methods,
  0, http_post_proc_variables,
  bic_http_post_proc_consts,
  bic_http_post_proc_init,
  bic_http_post_proc_clear,
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

built_in_method_s http_post_proc_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_http_post_proc_operator_binary_equal
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_http_post_proc_method_user_data_0
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final,
    bic_http_post_proc_method_process_1
  },
  {
    "key#0",
    c_modifier_public | c_modifier_final,
    bic_http_post_proc_method_key_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_http_post_proc_method_data_0
  },
  {
    "offset#0",
    c_modifier_public | c_modifier_final,
    bic_http_post_proc_method_offset_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_post_proc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_http_post_proc_method_print_0
  },
};/*}}}*/

built_in_variable_s http_post_proc_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_http_post_proc_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_http_post_proc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (http_post_proc_s *)nullptr;
}/*}}}*/

void bic_http_post_proc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  http_post_proc_s *pp_ptr = (http_post_proc_s *)location_ptr->v_data_ptr;

  if (pp_ptr != nullptr)
  {
    pp_ptr->clear(it);
    cfree(pp_ptr);
  }
}/*}}}*/

bool bic_http_post_proc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_http_post_proc_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  http_post_proc_s *pp_ptr = (http_post_proc_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&pp_ptr->user_data_ptr);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_http_post_proc_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method process
; @end

  // - retrieve post processor pointer -
  http_post_proc_s *pp_ptr = (http_post_proc_s *)dst_location->v_data_ptr;
  pp_ptr->it_ptr = &it;
  pp_ptr->source_pos = operands[c_source_pos_idx];
  pp_ptr->ret_code = c_run_return_code_OK;

  int res = MHD_post_process(pp_ptr->post_proc,(const char *)data_ptr,data_size);

  // - if exception occurred -
  if (pp_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  // - ERROR -
  if (res != MHD_YES)
  {
    exception_s::throw_exception(it,module.error_base + c_error_HTTP_POST_PROC_INTERNAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_http_post_proc_method_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  http_post_proc_s *pp_ptr = (http_post_proc_s *)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(pp_ptr->key),pp_ptr->key);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_http_post_proc_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  http_post_proc_s *pp_ptr = (http_post_proc_s *)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(pp_ptr->size,pp_ptr->data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_http_post_proc_method_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((http_post_proc_s *)dst_location->v_data_ptr)->offset;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_http_post_proc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("HttpPostProc"),"HttpPostProc");
  );

  return true;
}/*}}}*/

bool bic_http_post_proc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("HttpPostProc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

