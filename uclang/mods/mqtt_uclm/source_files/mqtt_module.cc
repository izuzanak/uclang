
@begin
include "mqtt_module.h"
@end

// - MQTT indexes of built in classes -
unsigned c_bi_class_mqtt_client = c_idx_not_exist;

// - MQTT module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  mqtt_classes,         // Classes
  0,                    // Error base index
  7,                    // Error count
  mqtt_error_strings,   // Error strings
  mqtt_initialize,      // Initialize function
  mqtt_print_exception, // Print exceptions function
};/*}}}*/

// - MQTT classes -
built_in_class_s *mqtt_classes[] =
{/*{{{*/
  &mqtt_client_class,
};/*}}}*/

// - MQTT error strings -
const char *mqtt_error_strings[] =
{/*{{{*/
  "error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_MQTT_CLIENT_INVALID_IP_ADDRESS",
  "error_MQTT_CLIENT_CREATE_ERROR",
  "error_MQTT_CLIENT_PROCESS_INVALID_FD",
  "error_MQTT_CLIENT_NOT_CONNECTED",
  "error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED",
  "error_MQTT_CLIENT_SSL_INIT_ERROR",
};/*}}}*/

// - MQTT initialize -
bool mqtt_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize mqtt_client class identifier -
  c_bi_class_mqtt_client = class_base_idx++;

  return true;
}/*}}}*/

// - MQTT print exception -
bool mqtt_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of MqttClient delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_IP_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid MqttClient ip address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating MqttClient\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_NOT_CONNECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient is not connected\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, SSL is already initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_SSL_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, error while initializing SSL\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class MQTT_CLIENT -
built_in_class_s mqtt_client_class =
{/*{{{*/
  "MqttClient",
  c_modifier_public | c_modifier_final,
  10
#ifdef UCL_WITH_OPENSSL
  + 1
#endif
  , mqtt_client_methods,
  3, mqtt_client_variables,
  bic_mqtt_client_consts,
  bic_mqtt_client_init,
  bic_mqtt_client_clear,
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

built_in_method_s mqtt_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_operator_binary_equal
  },
  {
    "MqttClient#5",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_MqttClient_5
  },
#ifdef UCL_WITH_OPENSSL
  {
    "init_ssl#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_init_ssl_0
  },
#endif
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_get_fd_0
  },
  {
    "events#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_events_0
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_get_fds_0
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_process_2
  },
  {
    "message#1",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_message_1
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_user_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mqtt_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mqtt_client_method_print_0
  },
};/*}}}*/

built_in_variable_s mqtt_client_variables[] =
{/*{{{*/

  // - mqtt client event type constants -
  { "EVENT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_CONNECTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DROPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_mqtt_client_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert mqtt client event type constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_ERROR);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_CONNECTED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_DROPPED);
  }

}/*}}}*/

void bic_mqtt_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (mqtt_conn_s *)nullptr;
}/*}}}*/

void bic_mqtt_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)location_ptr->v_data_ptr;

  if (cc_ptr != nullptr)
  {
    cc_ptr->clear(it);
    cfree(cc_ptr);
  }
}/*}}}*/

bool bic_mqtt_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_MqttClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ip:c_bi_class_string
port:retrieve_integer
event_delegate:c_bi_class_delegate
message_delegate:c_bi_class_delegate
user_data:ignore
>
method MqttClient
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  delegate_s *event_delegate = (delegate_s *)src_2_location->v_data_ptr;
  delegate_s *message_delegate = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (event_delegate->param_cnt != 2 ||
      message_delegate->param_cnt != 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  sockaddr_in address;

  // - retrieve host by name address -
  struct hostent *host = gethostbyname(string_ptr->data);

  // - ERROR -
  if (host == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_IP_ADDRESS,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  memcpy(&address.sin_addr.s_addr,host->h_addr,host->h_length);
  address.sin_port = htons(port);
  address.sin_family = AF_INET;

  // - create socket -
  int fd = socket(AF_INET,SOCK_STREAM,0);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  int nonblock_io = 1;
  if (ioctl(fd,FIONBIO,&nonblock_io) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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

      exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - create mqtt_client object -
  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)cmalloc(sizeof(mqtt_conn_s));
  cc_ptr->init();
  cc_ptr->init_static();

  // - set file descriptor -
  cc_ptr->conn_fd = fd;
  cc_ptr->events = POLLIN | POLLOUT | POLLPRI;
  cc_ptr->connecting = true;

  // - retrieve callbacks -
  src_2_location->v_reference_cnt.atomic_inc();
  cc_ptr->event_callback = src_2_location;

  src_3_location->v_reference_cnt.atomic_inc();
  cc_ptr->message_callback = src_3_location;

  // - retrieve user data -
  src_4_location->v_reference_cnt.atomic_inc();
  cc_ptr->user_data = src_4_location;

  cc_ptr->conn_index = 0;

  // - set destination data pointer -
  dst_location->v_data_ptr = (mqtt_conn_s *)cc_ptr;

  return true;
}/*}}}*/

#ifdef UCL_WITH_OPENSSL
bool bic_mqtt_client_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (cc_ptr->ssl != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
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
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL *ssl = SSL_new(ssl_ctx);

  // - ERROR -
  if (ssl == nullptr)
  {
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_set_fd(ssl,cc_ptr->conn_fd) != 1)
  {
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL_set_connect_state(ssl);
  cc_ptr->ssl = ssl;

  SSL_CTX_free(ssl_ctx);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/
#endif

bool bic_mqtt_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((mqtt_conn_s *)dst_location->v_data_ptr)->conn_fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

#ifdef UCL_WITH_OPENSSL
  long long int result = cc_ptr->ssl_action ? cc_ptr->ssl_events : cc_ptr->events;
#else
  long long int result = cc_ptr->events;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

#ifdef UCL_WITH_OPENSSL
  unsigned events = cc_ptr->ssl_action ? cc_ptr->ssl_events : cc_ptr->events;
#else
  unsigned events = cc_ptr->events;
#endif

  if (events != 0)
  {
    BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,cc_ptr->conn_fd);
    array_ptr->push(fd_location);

    BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,events);
    array_ptr->push(events_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fd != cc_ptr->conn_fd)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (cc_ptr->connecting)
  {
    // - reset connecting flag -
    cc_ptr->connecting = false;

    int error;
    socklen_t length = sizeof(error);

    // - check connect result -
    if (getsockopt(cc_ptr->conn_fd,SOL_SOCKET,SO_ERROR,&error,&length))
    {
      error = 1;
    }

#ifdef UCL_WITH_OPENSSL
    if (cc_ptr->ssl == nullptr)
    {
#endif
      // - disable nonblocking io -
      int nonblock_io = 0;
      if (!error && ioctl(cc_ptr->conn_fd,FIONBIO,&nonblock_io))
      {
        error = 1;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - error occured -
    if (error)
    {
      cc_ptr->events = 0;

      // - call event error callback -
      MQTT_CALL_CALLBACK_DELEGATE(cc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_mqtt_EVENT_ERROR,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA event_type_loc};
      ,
        return false;
      );
    }
    else
    {
      // - set connected flag -
      cc_ptr->connected = true;

      // - call event new callback -
      MQTT_CALL_CALLBACK_DELEGATE(cc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_mqtt_EVENT_CONNECTED,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA event_type_loc};
      ,
        cc_ptr->events = 0;
        return false;
      );

      // - no messages are queued to send -
      if (cc_ptr->out_msg_queue.used == 0)
      {
        cc_ptr->events = POLLIN | POLLPRI;
      }
    }
  }
  else
  {
    // - drop connection flag -
    bool drop_connection = false;

#ifdef UCL_WITH_OPENSSL
    if (cc_ptr->ssl_action)
    {
      if (cc_ptr->ssl_events & events)
      {
        // - reset ssl action -
        unsigned ssl_action = cc_ptr->ssl_action;
        cc_ptr->ssl_action = SSL_ACTION_NONE;

        switch (ssl_action)
        {
        case SSL_ACTION_SEND_MSG:
          if (!cc_ptr->send_msg(it))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        case SSL_ACTION_RECV_MSG:
          if (!cc_ptr->recv_msg(it,dst_location,operands[c_source_pos_idx]))
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
      unsigned conn_events = cc_ptr->events & events;

      if (conn_events & POLLOUT)
      {
        if (!cc_ptr->send_msg(it))
        {
          // - set drop connection flag -
          drop_connection = true;

          // - reset conn_events -
          conn_events = 0;
        }
      }

      if (conn_events & POLLIN)
      {
        if (!cc_ptr->recv_msg(it,dst_location,operands[c_source_pos_idx]))
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
      cc_ptr->events = 0;

      // - reset connected flag -
      cc_ptr->connected = false;

      // - call event drop callback -
      MQTT_CALL_CALLBACK_DELEGATE(cc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_mqtt_EVENT_DROPPED,0);

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

bool bic_mqtt_client_method_message_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
message:c_bi_class_string
>
method message
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;
  string_s *message_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (!cc_ptr->connected)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_NOT_CONNECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create message length string -
  string_s *length_ptr = it.get_new_string_ptr();
  length_ptr->setf("0x%8.8x;",message_ptr->size - 1);

  BIC_CREATE_NEW_LOCATION(length_location,c_bi_class_string,length_ptr);

  // - insert length of message to queue -
  cc_ptr->out_msg_queue.insert(length_location);

  // - insert message to queue -
  src_0_location->v_reference_cnt.atomic_inc();
  cc_ptr->out_msg_queue.insert(src_0_location);

  // - update connection events -
  cc_ptr->events = POLLIN | POLLPRI | POLLOUT;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&cc_ptr->user_data);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MqttClient"),"MqttClient")
  );

  return true;
}/*}}}*/

bool bic_mqtt_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("MqttClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

