
@begin
include "tcp_module.h"
@end

// - TCP indexes of built in classes -
unsigned c_bi_class_tcp_server = c_idx_not_exist;
unsigned c_bi_class_tcp_conn = c_idx_not_exist;
unsigned c_bi_class_tcp_client = c_idx_not_exist;

// - TCP module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  tcp_classes,         // Classes
  0,                   // Error base index
  20,                  // Error count
  tcp_error_strings,   // Error strings
  tcp_initialize,      // Initialize function
  tcp_print_exception, // Print exceptions function
};/*}}}*/

// - TCP classes -
built_in_class_s *tcp_classes[] =
{/*{{{*/
  &tcp_server_class,
  &tcp_conn_class,
  &tcp_client_class,
};/*}}}*/

// - TCP error strings -
const char *tcp_error_strings[] =
{/*{{{*/
  "error_TCP_SERVER_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_TCP_SERVER_INVALID_IP_ADDRESS",
  "error_TCP_SERVER_CREATE_ERROR",
  "error_TCP_SERVER_ACCEPT_ERROR",
  "error_TCP_SERVER_PROCESS_INVALID_FD",
  "error_TCP_SERVER_INVALID_CONNECTION_INDEX",
  "error_TCP_SERVER_SSL_ALREADY_INITIALIZED",
  "error_TCP_SERVER_SSL_NOT_INITIALIZED",
  "error_TCP_SERVER_SSL_INIT_ERROR",
  "error_TCP_SERVER_SSL_CERTIFICATE_FILE_ERROR",
  "error_TCP_SERVER_SSL_PRIVATE_KEY_FILE_ERROR",
  "error_TCP_SERVER_SSL_ACCEPT_ERROR",
  "error_TCP_SERVER_CONN_SSL_ALREADY_INITIALIZED",
  "error_TCP_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_TCP_CLIENT_INVALID_IP_ADDRESS",
  "error_TCP_CLIENT_CREATE_ERROR",
  "error_TCP_CLIENT_PROCESS_INVALID_FD",
  "error_TCP_CLIENT_NOT_CONNECTED",
  "error_TCP_CLIENT_SSL_ALREADY_INITIALIZED",
  "error_TCP_CLIENT_SSL_INIT_ERROR",
};/*}}}*/

// - TCP initialize -
bool tcp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize tcp_server class identifier -
  c_bi_class_tcp_server = class_base_idx++;

  // - initialize tcp_conn class identifier -
  c_bi_class_tcp_conn = class_base_idx++;

  // - initialize tcp_client class identifier -
  c_bi_class_tcp_client = class_base_idx++;

  return true;
}/*}}}*/

// - TCP print exception -
bool tcp_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TCP_SERVER_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of TcpServer delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_INVALID_IP_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid TcpServer ip address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating TcpServer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_ACCEPT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while accepting TcpServer connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_INVALID_CONNECTION_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, invalid connection index\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_SSL_ALREADY_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, SSL is already initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_SSL_NOT_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, SSL is not initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_SSL_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, error while initializing SSL\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_SSL_CERTIFICATE_FILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, cannot read SSL certificate from file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_SSL_PRIVATE_KEY_FILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, cannot read SSL private key from file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_SSL_ACCEPT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, error while accepting SSL connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_SERVER_CONN_SSL_ALREADY_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpServer, connection SSL is already initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of TcpClient delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_INVALID_IP_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid TcpClient ip address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating TcpClient\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpClient, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_NOT_CONNECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpClient is not connected\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_SSL_ALREADY_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpClient, SSL is already initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCP_CLIENT_SSL_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcpClient, error while initializing SSL\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TCP_SERVER -
built_in_class_s tcp_server_class =
{/*{{{*/
  "TcpServer",
  c_modifier_public | c_modifier_final,
  9
#ifdef UCL_WITH_OPENSSL
  + 1
#endif
  , tcp_server_methods,
  3, tcp_server_variables,
  bic_tcp_server_consts,
  bic_tcp_server_init,
  bic_tcp_server_clear,
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

built_in_method_s tcp_server_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_operator_binary_equal
  },
  {
    "TcpServer#5",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_TcpServer_5
  },
#ifdef UCL_WITH_OPENSSL
  {
    "init_ssl#2",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_init_ssl_2
  },
#endif
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_get_fds_0
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_process_2
  },
  {
    "message#2",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_message_2
  },
  {
    "connection#1",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_connection_1
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_server_method_user_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcp_server_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcp_server_method_print_0
  },
};/*}}}*/

built_in_variable_s tcp_server_variables[] =
{/*{{{*/

  // - tcp server event type constants -
  { "EVENT_ACCEPTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DROPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - tcp connection index constants -
  { "CONN_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_tcp_server_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert tcp server event type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_TCP_SERVER_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCP_SERVER_EVENT_TYPE_BIC_STATIC(c_tcp_EVENT_ACCEPTED);
    CREATE_TCP_SERVER_EVENT_TYPE_BIC_STATIC(c_tcp_EVENT_DROPPED);
  }

  // - insert tcp connection index constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_TCP_SERVER_CONN_INDEX_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCP_SERVER_CONN_INDEX_BIC_STATIC(c_conn_index_CONN_ALL);
  }

}/*}}}*/

void bic_tcp_server_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcp_server_s *)nullptr;
}/*}}}*/

void bic_tcp_server_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcp_server_s *ts_ptr = (tcp_server_s *)location_ptr->v_data_ptr;

  if (ts_ptr != nullptr)
  {
    ts_ptr->clear(it);
    cfree(ts_ptr);
  }
}/*}}}*/

bool bic_tcp_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcp_server_method_TcpServer_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ip:c_bi_class_string
port:retrieve_integer
event_delegate:c_bi_class_delegate
message_delegate:c_bi_class_delegate
user_data:ignore
>
method TcpServer
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  delegate_s *event_delegate = (delegate_s *)src_2_location->v_data_ptr;
  delegate_s *message_delegate = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (event_delegate->param_cnt != 3 ||
      message_delegate->param_cnt != 3)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  struct addrinfo addr_hints;
  memset(&addr_hints,0,sizeof(struct addrinfo));
  addr_hints.ai_family = AF_INET;

  // - ERROR -
  struct addrinfo *addr_info;
  if (getaddrinfo(string_ptr->data,nullptr,&addr_hints,&addr_info) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_IP_ADDRESS,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  sockaddr_in address;
  address.sin_addr = ((struct sockaddr_in *)addr_info->ai_addr)->sin_addr;
  address.sin_port = htons(port);
  address.sin_family = AF_INET;

  // - release address info -
  freeaddrinfo(addr_info);

  // - create socket -
  int fd = socket(AF_INET,SOCK_STREAM | SOCK_CLOEXEC,0);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set server socket options -
  int yes = 1;
  setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));
  setsockopt(fd,SOL_TCP,TCP_NODELAY,&yes,sizeof(int));

  // - ERROR -
  if (bind(fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (listen(fd,256) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create tcp_server object -
  tcp_server_s *ts_ptr = (tcp_server_s *)cmalloc(sizeof(tcp_server_s));
  ts_ptr->init();
  ts_ptr->init_static();

  // - set file descriptor -
  ts_ptr->server_fd = fd;

  // - retrieve callbacks -
  src_2_location->v_reference_cnt.atomic_inc();
  ts_ptr->event_callback = src_2_location;

  src_3_location->v_reference_cnt.atomic_inc();
  ts_ptr->message_callback = src_3_location;

  // - retrieve user data -
  src_4_location->v_reference_cnt.atomic_inc();
  ts_ptr->user_data = src_4_location;

  // - set destination data pointer -
  dst_location->v_data_ptr = (tcp_server_s *)ts_ptr;

  return true;
}/*}}}*/

#ifdef UCL_WITH_OPENSSL
bool bic_tcp_server_method_init_ssl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
cert_file_name:c_bi_class_string
pkey_file_name:c_bi_class_string
>
method init_ssl
; @end

  tcp_server_s *ts_ptr = (tcp_server_s *)dst_location->v_data_ptr;
  string_s *cert_file_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *pkey_file_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (ts_ptr->ssl_ctx != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_ALREADY_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#if OPENSSL_VERSION_NUMBER >= 0x10100000L
  const SSL_METHOD *method = TLS_server_method();
#else
  const SSL_METHOD *method = TLSv1_2_server_method();
#endif

  SSL_CTX *ssl_ctx = SSL_CTX_new(method);

  // - ERROR -
  if (ssl_ctx == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_CTX_use_certificate_file(ssl_ctx,cert_file_ptr->data,SSL_FILETYPE_PEM) != 1)
  {
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_CERTIFICATE_FILE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_CTX_use_PrivateKey_file(ssl_ctx,pkey_file_ptr->data,SSL_FILETYPE_PEM) != 1)
  {
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_PRIVATE_KEY_FILE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ts_ptr->ssl_ctx = ssl_ctx;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/
#endif

bool bic_tcp_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_server_s *ts_ptr = (tcp_server_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,ts_ptr->server_fd);
  array_ptr->push(fd_location);

  BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,POLLIN | POLLPRI);
  array_ptr->push(events_location);

  if (ts_ptr->fd_conn_map.root_idx != c_idx_not_exist)
  {
    fd_conn_map_tree_s_node *fcmtn_ptr = ts_ptr->fd_conn_map.data;
    fd_conn_map_tree_s_node *fcmtn_ptr_end = fcmtn_ptr + ts_ptr->fd_conn_map.used;
    do {
      if (fcmtn_ptr->valid)
      {
        tcp_conn_s &conn = ts_ptr->conn_list[fcmtn_ptr->object.conn_index];

#ifdef UCL_WITH_OPENSSL
        unsigned events = conn.ssl_action ? conn.ssl_events : conn.events;
#else
        unsigned events = conn.events;
#endif

        BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,fcmtn_ptr->object.fd);
        array_ptr->push(fd_location);

        BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,events);
        array_ptr->push(events_location);
      }
    } while(++fcmtn_ptr < fcmtn_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_tcp_server_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  tcp_server_s *ts_ptr = (tcp_server_s *)dst_location->v_data_ptr;

  if (fd == ts_ptr->server_fd)
  {
    socklen_t addr_len = sizeof(struct sockaddr_in);
    sockaddr_in address;

    // - ERROR -
    int conn_fd = accept(ts_ptr->server_fd,(struct sockaddr *)&address,&addr_len);
    if (conn_fd == -1)
    {
      exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - ERROR -
    if (addr_len != sizeof(struct sockaddr_in))
    {
      close(conn_fd);

      exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - create new connection -
    unsigned conn_index = ts_ptr->conn_list.append_blank();

    tcp_conn_s &conn = ts_ptr->conn_list[conn_index];
    conn.init_static();

    conn.conn_fd = conn_fd;
    conn.events = POLLIN | POLLPRI;

    ((location_s *)ts_ptr->message_callback)->v_reference_cnt.atomic_inc();
    conn.message_callback = ts_ptr->message_callback;

    conn.conn_index = conn_index;
    conn.address.addr = address;

    // - update fd connection map -
    fd_conn_map_s fd_conn_map = {conn_fd,conn_index};
    unsigned fd_conn_map_index = ts_ptr->fd_conn_map.insert(fd_conn_map);

    // - call new connection callback -
    TCP_CALL_CALLBACK_DELEGATE(ts_ptr->event_callback,operands[c_source_pos_idx],
      BIC_CREATE_NEW_LOCATION_REFS(conn_index_loc,c_bi_class_integer,conn_index,0);
      BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_tcp_EVENT_ACCEPTED,0);

      const unsigned param_cnt = 3;
      pointer param_data[param_cnt] = {dst_location MP_COMMA conn_index_loc MP_COMMA event_type_loc};
    ,
      // - drop connection without callback -
      conn.clear(it);
      ts_ptr->conn_list.remove(conn_index);
      ts_ptr->fd_conn_map.remove(fd_conn_map_index);

      return false;
    );
  }
  else
  {
    fd_conn_map_s search_fd_conn_map = {(int)fd,0};
    unsigned fd_conn_map_index = ts_ptr->fd_conn_map.get_idx(search_fd_conn_map);

    // - ERROR -
    if (fd_conn_map_index == c_idx_not_exist)
    {
      exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    unsigned conn_index = ts_ptr->fd_conn_map[fd_conn_map_index].conn_index;
    tcp_conn_s &conn = ts_ptr->conn_list[conn_index];

    // - drop connection flag -
    bool drop_connection = false;

#ifdef UCL_WITH_OPENSSL
    if (conn.ssl_action)
    {
      if (conn.ssl_events & events)
      {
        // - reset ssl action -
        unsigned ssl_action = conn.ssl_action;
        conn.ssl_action = SSL_ACTION_NONE;

        switch (ssl_action)
        {
        case SSL_ACTION_SEND_MSG:
          if (!conn.send_msg(it))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        case SSL_ACTION_RECV_MSG:
          if (!conn.recv_msg(it,dst_location,operands[c_source_pos_idx]))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        default:
          cassert(0);
        }
      }
    }
    else
    {
#endif
      // - mask events with connection events -
      unsigned conn_events = conn.events & events;

      if (conn_events & POLLOUT)
      {
        if (!conn.send_msg(it))
        {
          // - set drop connection flag -
          drop_connection = true;

          // - reset conn_events -
          conn_events = 0;
        }
      }

      if (conn_events & POLLIN)
      {
        if (!conn.recv_msg(it,dst_location,operands[c_source_pos_idx]))
        {
          // - set drop connection flag -
          drop_connection = true;
        }
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - drop connection flag is set -
    if (drop_connection)
    {
      // - call drop connection callback -
      TCP_CALL_CALLBACK_DELEGATE(ts_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(conn_index_loc,c_bi_class_integer,conn_index,0);
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_tcp_EVENT_DROPPED,0);

        const unsigned param_cnt = 3;
        pointer param_data[param_cnt] = {dst_location MP_COMMA conn_index_loc MP_COMMA event_type_loc};
      ,
      );

      // - drop connection -
      conn.clear(it);
      ts_ptr->conn_list.remove(conn_index);
      ts_ptr->fd_conn_map.remove(fd_conn_map_index);

      // - drop due to exception -
      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        return false;
      }
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcp_server_method_message_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
conn_index:retrieve_integer_init
conn_index:c_bi_class_array
message:c_bi_class_string
>
method message
; @end

  tcp_server_s *ts_ptr = (tcp_server_s *)dst_location->v_data_ptr;

  if (src_0_location->v_type == c_bi_class_array)
  {
    pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

    if (array_ptr->used != 0)
    {
      // - process connection array -
      pointer *ptr = array_ptr->data;
      pointer *ptr_end = ptr + array_ptr->used;
      do {
        location_s *item_location = it.get_location_value(*ptr);

        long long int conn_index;

        // - ERROR -
        if (!it.retrieve_integer(item_location,conn_index))
        {
          exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        if (conn_index >= ts_ptr->conn_list.used || !ts_ptr->conn_list.data[conn_index].valid)
        {
          exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        tcp_conn_s &conn = ts_ptr->conn_list[conn_index];

        // - insert message to queue -
        src_1_location->v_reference_cnt.atomic_inc();
        conn.out_msg_queue.insert(src_1_location);

        // - update connection events -
        conn.events = POLLIN | POLLPRI | POLLOUT;

      } while(++ptr < ptr_end);
    }
  }
  else
  {
    if (conn_index == c_conn_index_CONN_ALL)
    {
      if (ts_ptr->conn_list.first_idx != c_idx_not_exist)
      {
        unsigned cl_idx = ts_ptr->conn_list.first_idx;
        do {
          tcp_conn_s &conn = ts_ptr->conn_list[cl_idx];

          // - insert message to queue -
          src_1_location->v_reference_cnt.atomic_inc();
          conn.out_msg_queue.insert(src_1_location);

          // - update connection events -
          conn.events = POLLIN | POLLPRI | POLLOUT;

          cl_idx = ts_ptr->conn_list.next_idx(cl_idx);
        } while(cl_idx != c_idx_not_exist);
      }
    }
    else
    {
      // - ERROR -
      if (conn_index < 0 || conn_index >= ts_ptr->conn_list.used ||
          !ts_ptr->conn_list.data[conn_index].valid)
      {
        exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      tcp_conn_s &conn = ts_ptr->conn_list[conn_index];

      // - insert message to queue -
      src_1_location->v_reference_cnt.atomic_inc();
      conn.out_msg_queue.insert(src_1_location);

      // - update connection events -
      conn.events = POLLIN | POLLPRI | POLLOUT;
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcp_server_method_connection_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
conn_index:retrieve_integer
>
method connection
; @end

  tcp_server_s *ts_ptr = (tcp_server_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (conn_index < 0 || conn_index >= ts_ptr->conn_list.used ||
      !ts_ptr->conn_list.data[conn_index].valid)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create tcp_conn object -
  tcp_conn_ref_s *tcr_ptr = (tcp_conn_ref_s *)cmalloc(sizeof(tcp_conn_ref_s));
  tcr_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  tcr_ptr->server = dst_location;

  tcr_ptr->index = conn_index;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_tcp_conn,tcr_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_tcp_server_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_server_s *ts_ptr = (tcp_server_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&ts_ptr->user_data);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_tcp_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcpServer"),"TcpServer")
  );

  return true;
}/*}}}*/

bool bic_tcp_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcpServer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCP_CONN -
built_in_class_s tcp_conn_class =
{/*{{{*/
  "TcpConn",
  c_modifier_public | c_modifier_final,
  6
#ifdef UCL_WITH_OPENSSL
  + 1
#endif
  , tcp_conn_methods,
  0, tcp_conn_variables,
  bic_tcp_conn_consts,
  bic_tcp_conn_init,
  bic_tcp_conn_clear,
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

built_in_method_s tcp_conn_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcp_conn_operator_binary_equal
  },
#ifdef UCL_WITH_OPENSSL
  {
    "init_ssl#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_conn_method_init_ssl_0
  },
#endif
  {
    "fd#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_conn_method_fd_0
  },
  {
    "ip#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_conn_method_ip_0
  },
  {
    "port#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_conn_method_port_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcp_conn_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcp_conn_method_print_0
  },
};/*}}}*/

built_in_variable_s tcp_conn_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_tcp_conn_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcp_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcp_conn_ref_s *)nullptr;
}/*}}}*/

void bic_tcp_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcp_conn_ref_s *tcr_ptr = (tcp_conn_ref_s *)location_ptr->v_data_ptr;

  if (tcr_ptr != nullptr)
  {
    tcr_ptr->clear(it);
    cfree(tcr_ptr);
  }
}/*}}}*/

bool bic_tcp_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#ifdef UCL_WITH_OPENSSL
bool bic_tcp_conn_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_ref_s *tcr_ptr = (tcp_conn_ref_s *)dst_location->v_data_ptr;
  tcp_server_s *ts_ptr = (tcp_server_s *)tcr_ptr->server->v_data_ptr;

  // - ERROR -
  if (ts_ptr->ssl_ctx == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_NOT_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (tcr_ptr->index < 0 || tcr_ptr->index >= ts_ptr->conn_list.used ||
      !ts_ptr->conn_list.data[tcr_ptr->index].valid)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  tcp_conn_s &conn = ts_ptr->conn_list[tcr_ptr->index];

  // - ERROR -
  if (conn.ssl != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_CONN_SSL_ALREADY_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int nonblock_io = 1;
  if (ioctl(conn.conn_fd,FIONBIO,&nonblock_io))
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL *ssl = SSL_new(ts_ptr->ssl_ctx);

  // - ERROR -
  if (ssl == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_set_fd(ssl,conn.conn_fd) != 1)
  {
    SSL_free(ssl);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_SSL_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL_set_accept_state(ssl);
  conn.ssl = ssl;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/
#endif

bool bic_tcp_conn_method_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_ref_s *tcr_ptr = (tcp_conn_ref_s *)dst_location->v_data_ptr;
  tcp_server_s *ts_ptr = (tcp_server_s *)tcr_ptr->server->v_data_ptr;

  // - ERROR -
  if (tcr_ptr->index < 0 || tcr_ptr->index >= ts_ptr->conn_list.used ||
      !ts_ptr->conn_list.data[tcr_ptr->index].valid)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ts_ptr->conn_list[tcr_ptr->index].conn_fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcp_conn_method_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_ref_s *tcr_ptr = (tcp_conn_ref_s *)dst_location->v_data_ptr;
  tcp_server_s *ts_ptr = (tcp_server_s *)tcr_ptr->server->v_data_ptr;

  // - ERROR -
  if (tcr_ptr->index < 0 || tcr_ptr->index >= ts_ptr->conn_list.used ||
      !ts_ptr->conn_list.data[tcr_ptr->index].valid)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  sockaddr_in *addr_ptr = &ts_ptr->conn_list[tcr_ptr->index].address.addr;

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

bool bic_tcp_conn_method_port_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_ref_s *tcr_ptr = (tcp_conn_ref_s *)dst_location->v_data_ptr;
  tcp_server_s *ts_ptr = (tcp_server_s *)tcr_ptr->server->v_data_ptr;

  // - ERROR -
  if (tcr_ptr->index < 0 || tcr_ptr->index >= ts_ptr->conn_list.used ||
      !ts_ptr->conn_list.data[tcr_ptr->index].valid)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_SERVER_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  sockaddr_in *addr_ptr = &ts_ptr->conn_list[tcr_ptr->index].address.addr;

  long long int result = (unsigned short)ntohs(addr_ptr->sin_port);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcp_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcpConn"),"TcpConn")
  );

  return true;
}/*}}}*/

bool bic_tcp_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcpConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCP_CLIENT -
built_in_class_s tcp_client_class =
{/*{{{*/
  "TcpClient",
  c_modifier_public | c_modifier_final,
  10
#ifdef UCL_WITH_OPENSSL
  + 1
#endif
  , tcp_client_methods,
  3, tcp_client_variables,
  bic_tcp_client_consts,
  bic_tcp_client_init,
  bic_tcp_client_clear,
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

built_in_method_s tcp_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_operator_binary_equal
  },
  {
    "TcpClient#5",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_TcpClient_5
  },
#ifdef UCL_WITH_OPENSSL
  {
    "init_ssl#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_init_ssl_0
  },
#endif
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_get_fd_0
  },
  {
    "events#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_events_0
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_get_fds_0
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_process_2
  },
  {
    "message#1",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_message_1
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_tcp_client_method_user_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcp_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcp_client_method_print_0
  },
};/*}}}*/

built_in_variable_s tcp_client_variables[] =
{/*{{{*/

  // - tcp client event type constants -
  { "EVENT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_CONNECTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DROPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_tcp_client_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert tcp client event type constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_TCP_CLIENT_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCP_CLIENT_EVENT_TYPE_BIC_STATIC(c_tcp_EVENT_ERROR);
    CREATE_TCP_CLIENT_EVENT_TYPE_BIC_STATIC(c_tcp_EVENT_CONNECTED);
    CREATE_TCP_CLIENT_EVENT_TYPE_BIC_STATIC(c_tcp_EVENT_DROPPED);
  }

}/*}}}*/

void bic_tcp_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcp_conn_s *)nullptr;
}/*}}}*/

void bic_tcp_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcp_conn_s *tc_ptr = (tcp_conn_s *)location_ptr->v_data_ptr;

  if (tc_ptr != nullptr)
  {
    tc_ptr->clear(it);
    cfree(tc_ptr);
  }
}/*}}}*/

bool bic_tcp_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcp_client_method_TcpClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ip:c_bi_class_string
port:retrieve_integer
event_delegate:c_bi_class_delegate
message_delegate:c_bi_class_delegate
user_data:ignore
>
method TcpClient
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  delegate_s *event_delegate = (delegate_s *)src_2_location->v_data_ptr;
  delegate_s *message_delegate = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (event_delegate->param_cnt != 2 ||
      message_delegate->param_cnt != 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  struct addrinfo addr_hints;
  memset(&addr_hints,0,sizeof(struct addrinfo));
  addr_hints.ai_family = AF_INET;

  // - ERROR -
  struct addrinfo *addr_info;
  if (getaddrinfo(string_ptr->data,nullptr,&addr_hints,&addr_info) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_INVALID_IP_ADDRESS,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  sockaddr_in address;
  address.sin_addr = ((struct sockaddr_in *)addr_info->ai_addr)->sin_addr;
  address.sin_port = htons(port);
  address.sin_family = AF_INET;

  // - release address info -
  freeaddrinfo(addr_info);

  // - create socket -
  int fd = socket(AF_INET,SOCK_STREAM,0);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  int nonblock_io = 1;
  if (ioctl(fd,FIONBIO,&nonblock_io) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set client socket options -
  int yes = 1;
  setsockopt(fd,SOL_TCP,TCP_NODELAY,&yes,sizeof(int));

  // - ERROR -
  if (connect(fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    if (errno != EINPROGRESS)
    {
      close(fd);

      exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - create tcp_client object -
  tcp_conn_s *tc_ptr = (tcp_conn_s *)cmalloc(sizeof(tcp_conn_s));
  tc_ptr->init();
  tc_ptr->init_static();

  // - set file descriptor -
  tc_ptr->conn_fd = fd;
  tc_ptr->events = POLLIN | POLLOUT | POLLPRI;
  tc_ptr->connecting = true;

  // - retrieve callbacks -
  src_2_location->v_reference_cnt.atomic_inc();
  tc_ptr->event_callback = src_2_location;

  src_3_location->v_reference_cnt.atomic_inc();
  tc_ptr->message_callback = src_3_location;

  // - retrieve user data -
  src_4_location->v_reference_cnt.atomic_inc();
  tc_ptr->user_data = src_4_location;

  tc_ptr->conn_index = 0;

  // - set destination data pointer -
  dst_location->v_data_ptr = (tcp_conn_s *)tc_ptr;

  return true;
}/*}}}*/

#ifdef UCL_WITH_OPENSSL
bool bic_tcp_client_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_s *tc_ptr = (tcp_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (tc_ptr->ssl != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_SSL_ALREADY_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#if OPENSSL_VERSION_NUMBER >= 0x10100000L
  const SSL_METHOD *method = TLS_client_method();
#else
  const SSL_METHOD *method = TLSv1_2_client_method();
#endif

  SSL_CTX *ssl_ctx = SSL_CTX_new(method);

  // - ERROR -
  if (ssl_ctx == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL *ssl = SSL_new(ssl_ctx);

  // - ERROR -
  if (ssl == nullptr)
  {
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_set_fd(ssl,tc_ptr->conn_fd) != 1)
  {
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL_set_connect_state(ssl);
  tc_ptr->ssl = ssl;

  SSL_CTX_free(ssl_ctx);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/
#endif

bool bic_tcp_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((tcp_conn_s *)dst_location->v_data_ptr)->conn_fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcp_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_s *tc_ptr = (tcp_conn_s *)dst_location->v_data_ptr;

#ifdef UCL_WITH_OPENSSL
  long long int result = tc_ptr->ssl_action ? tc_ptr->ssl_events : tc_ptr->events;
#else
  long long int result = tc_ptr->events;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcp_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_s *tc_ptr = (tcp_conn_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

#ifdef UCL_WITH_OPENSSL
  unsigned events = tc_ptr->ssl_action ? tc_ptr->ssl_events : tc_ptr->events;
#else
  unsigned events = tc_ptr->events;
#endif

  if (events != 0)
  {
    BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,tc_ptr->conn_fd);
    array_ptr->push(fd_location);

    BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,events);
    array_ptr->push(events_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_tcp_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  tcp_conn_s *tc_ptr = (tcp_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fd != tc_ptr->conn_fd)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (tc_ptr->connecting)
  {
    // - reset connecting flag -
    tc_ptr->connecting = false;

    int error;
    socklen_t length = sizeof(error);

    // - check connect result -
    if (getsockopt(tc_ptr->conn_fd,SOL_SOCKET,SO_ERROR,&error,&length))
    {
      error = 1;
    }

#ifdef UCL_WITH_OPENSSL
    if (tc_ptr->ssl == nullptr)
    {
#endif
      // - disable nonblocking io -
      int nonblock_io = 0;
      if (!error && ioctl(tc_ptr->conn_fd,FIONBIO,&nonblock_io))
      {
        error = 1;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - error occured -
    if (error)
    {
      tc_ptr->events = 0;

      // - call event error callback -
      TCP_CALL_CALLBACK_DELEGATE(tc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_tcp_EVENT_ERROR,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA event_type_loc};
      ,
        return false;
      );
    }
    else
    {
      // - set connected flag -
      tc_ptr->connected = true;

      // - call event new callback -
      TCP_CALL_CALLBACK_DELEGATE(tc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_tcp_EVENT_CONNECTED,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA event_type_loc};
      ,
        tc_ptr->events = 0;
        return false;
      );

      // - no messages are queued to send -
      if (tc_ptr->out_msg_queue.used == 0)
      {
        tc_ptr->events = POLLIN | POLLPRI;
      }
    }
  }
  else
  {
    // - drop connection flag -
    bool drop_connection = false;

#ifdef UCL_WITH_OPENSSL
    if (tc_ptr->ssl_action)
    {
      if (tc_ptr->ssl_events & events)
      {
        // - reset ssl action -
        unsigned ssl_action = tc_ptr->ssl_action;
        tc_ptr->ssl_action = SSL_ACTION_NONE;

        switch (ssl_action)
        {
        case SSL_ACTION_SEND_MSG:
          if (!tc_ptr->send_msg(it))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        case SSL_ACTION_RECV_MSG:
          if (!tc_ptr->recv_msg(it,dst_location,operands[c_source_pos_idx]))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        default:
          cassert(0);
        }
      }
    }
    else
    {
#endif
      // - mask events with connection events -
      unsigned conn_events = tc_ptr->events & events;

      if (conn_events & POLLOUT)
      {
        if (!tc_ptr->send_msg(it))
        {
          // - set drop connection flag -
          drop_connection = true;

          // - reset conn_events -
          conn_events = 0;
        }
      }

      if (conn_events & POLLIN)
      {
        if (!tc_ptr->recv_msg(it,dst_location,operands[c_source_pos_idx]))
        {
          // - set drop connection flag -
          drop_connection = true;
        }
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - drop connection flag is set -
    if (drop_connection)
    {
      tc_ptr->events = 0;

      // - reset connected flag -
      tc_ptr->connected = false;

      // - call event drop callback -
      TCP_CALL_CALLBACK_DELEGATE(tc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_tcp_EVENT_DROPPED,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA event_type_loc};
      ,
      );

      // - drop due to exception -
      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        return false;
      }
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcp_client_method_message_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
message:c_bi_class_string
>
method message
; @end

  tcp_conn_s *tc_ptr = (tcp_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!tc_ptr->connected)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCP_CLIENT_NOT_CONNECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - insert message to queue -
  src_0_location->v_reference_cnt.atomic_inc();
  tc_ptr->out_msg_queue.insert(src_0_location);

  // - update connection events -
  tc_ptr->events = POLLIN | POLLPRI | POLLOUT;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcp_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcp_conn_s *tc_ptr = (tcp_conn_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&tc_ptr->user_data);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_tcp_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcpClient"),"TcpClient")
  );

  return true;
}/*}}}*/

bool bic_tcp_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcpClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

