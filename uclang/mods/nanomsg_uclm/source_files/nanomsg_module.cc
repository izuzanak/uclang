
@begin
include "nanomsg_module.h"
@end

// - NANOMSG indexes of built in classes -
unsigned c_bi_class_nano_msg = c_idx_not_exist;
unsigned c_bi_class_nano_socket = c_idx_not_exist;
unsigned c_bi_class_nano_endpoint = c_idx_not_exist;

// - NANOMSG module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                       // Class count
  nanomsg_classes,         // Classes

  0,                       // Error base index
  1,                       // Error count
  nanomsg_error_strings,   // Error strings

  nanomsg_initialize,      // Initialize function
  nanomsg_print_exception, // Print exceptions function
};/*}}}*/

// - NANOMSG classes -
built_in_class_s *nanomsg_classes[] =
{/*{{{*/
  &nano_msg_class,
  &nano_socket_class,
  &nano_endpoint_class,
};/*}}}*/

// - NANOMSG error strings -
const char *nanomsg_error_strings[] =
{/*{{{*/
  "error_NANOMSG_DUMMY_ERROR",
};/*}}}*/

// - NANOMSG initialize -
bool nanomsg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize nano_msg class identifier -
  c_bi_class_nano_msg = class_base_idx++;

  // - initialize nano_socket class identifier -
  c_bi_class_nano_socket = class_base_idx++;

  // - initialize nano_endpoint class identifier -
  c_bi_class_nano_endpoint = class_base_idx++;

  return true;
}/*}}}*/

// - NANOMSG print exception -
bool nanomsg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_NANOMSG_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNanoMsg dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class NANO_MSG -
built_in_class_s nano_msg_class =
{/*{{{*/
  "NanoMsg",
  c_modifier_public | c_modifier_final,
  3, nano_msg_methods,
  0, nano_msg_variables,
  bic_nano_msg_consts,
  bic_nano_msg_init,
  bic_nano_msg_clear,
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

built_in_method_s nano_msg_methods[] =
{/*{{{*/
  {
    "term#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_msg_method_term_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_msg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_msg_method_print_0
  },
};/*}}}*/

built_in_variable_s nano_msg_variables[] =
{/*{{{*/
};/*}}}*/

void bic_nano_msg_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nano_msg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_nano_msg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_nano_msg_method_term_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  nn_term();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_nano_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NanoMsg"),"NanoMsg");
  );

  return true;
}/*}}}*/

bool bic_nano_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NanoMsg");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NANO_SOCKET -
built_in_class_s nano_socket_class =
{/*{{{*/
  "NanoSocket",
  c_modifier_public | c_modifier_final,
  10, nano_socket_methods,
  2 + 10 + 4 + 1 + 23 + 2, nano_socket_variables,
  bic_nano_socket_consts,
  bic_nano_socket_init,
  bic_nano_socket_clear,
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

built_in_method_s nano_socket_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_operator_binary_equal
  },
  {
    "NanoSocket#2",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_NanoSocket_2
  },
  {
    "setsockopt#3",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_setsockopt_3
  },
  {
    "getsockopt#2",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_getsockopt_2
  },
  {
    "bind#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_bind_1
  },
  {
    "connect#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_connect_1
  },
  {
    "send#2",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_send_2
  },
  {
    "recv#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_recv_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_socket_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_socket_method_print_0
  },
};/*}}}*/

built_in_variable_s nano_socket_variables[] =
{/*{{{*/

  // - socket constants -
  { "AF_SP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AF_SP_RAW", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket protocol constants -
  { "NN_BUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PAIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PUSH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PUB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SUB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_REQ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_REP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SURVEYOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RESPONDENT", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket transport mechanism constants -
  { "NN_INPROC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_IPC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_TCP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_WS", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket level constants -
  { "NN_SOL_SOCKET", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket option constants -
  { "NN_DOMAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PROTOCOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_LINGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SNDBUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RCVBUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RCVMAXSIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SNDTIMEO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RCVTIMEO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RECONNECT_IVL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RECONNECT_IVL_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SNDPRIO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RCVPRIO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_IPV4ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SNDFD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RCVFD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SOCKET_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_MAXTTL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_REQ_RESEND_IVL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SUB_SUBSCRIBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SUB_UNSUBSCRIBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SURVEYOR_DEADLINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_TCP_NODELAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_WS_MSG_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - socket ws option values -
  { "NN_WS_MSG_TYPE_TEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_WS_MSG_TYPE_BINARY", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_nano_socket_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert socket constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_NANO_SOCKET_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_BIC_STATIC(AF_SP);
    CREATE_NANO_SOCKET_BIC_STATIC(AF_SP_RAW);
  }

  // - insert socket protocol constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_BUS);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PAIR);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PUSH);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PULL);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PUB);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_SUB);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_REQ);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_REP);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_SURVEYOR);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_RESPONDENT);
  }

  // - insert socket transport mechanism constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_NANO_SOCKET_TRANSPORT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_TRANSPORT_BIC_STATIC(NN_INPROC);
    CREATE_NANO_SOCKET_TRANSPORT_BIC_STATIC(NN_IPC);
    CREATE_NANO_SOCKET_TRANSPORT_BIC_STATIC(NN_TCP);
    CREATE_NANO_SOCKET_TRANSPORT_BIC_STATIC(NN_WS);
  }

  // - insert socket level constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_NANO_SOCKET_LEVEL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_LEVEL_BIC_STATIC(NN_SOL_SOCKET);\
  }

  // - insert socket option constants -
  {
    const_locations.push_blanks(23);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 23);

#define CREATE_NANO_SOCKET_OPTION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_DOMAIN);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_PROTOCOL);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_LINGER);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SNDBUF);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RCVBUF);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RCVMAXSIZE);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SNDTIMEO);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RCVTIMEO);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RECONNECT_IVL);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RECONNECT_IVL_MAX);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SNDPRIO);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RCVPRIO);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_IPV4ONLY);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SNDFD);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_RCVFD);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SOCKET_NAME);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_MAXTTL);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_REQ_RESEND_IVL);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SUB_SUBSCRIBE);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SUB_UNSUBSCRIBE);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_SURVEYOR_DEADLINE);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_TCP_NODELAY);
    CREATE_NANO_SOCKET_OPTION_BIC_STATIC(NN_WS_MSG_TYPE);
  }

  // - insert socket ws option values -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_NANO_SOCKET_WS_VALUE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_WS_VALUE_BIC_STATIC(NN_WS_MSG_TYPE_TEXT);
    CREATE_NANO_SOCKET_WS_VALUE_BIC_STATIC(NN_WS_MSG_TYPE_BINARY);
  }

}/*}}}*/

void bic_nano_socket_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (int)-1;
}/*}}}*/

void bic_nano_socket_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  int nn_fd = (int)location_ptr->v_data_ptr;

  if (nn_fd != -1)
  {
    nn_close(nn_fd);
  }
}/*}}}*/

bool bic_nano_socket_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_nano_socket_method_NanoSocket_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
domain:retrieve_integer
protocol:retrieve_integer
>
method NanoSocket
; @end

  int nn_fd;

  // - ERROR -
  if ((nn_fd = nn_socket(domain,protocol)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  dst_location->v_data_ptr = (int)nn_fd;

  return true;
}/*}}}*/

bool bic_nano_socket_method_setsockopt_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
level:retrieve_integer
option:retrieve_integer
value:ignore
>
method setsockopt
; @end

  int nn_fd = (int)dst_location->v_data_ptr;

  switch (nano_msg_s::option_type(level,option))
  {
  case c_option_type_int:
    {/*{{{*/
      long long int parameter;

      // - ERROR -
      if (!it.retrieve_integer(src_2_location,parameter))
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      int value = parameter;

      // - ERROR -
      if (nn_setsockopt(nn_fd,level,option,&value,sizeof(value)) == -1)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }
    }/*}}}*/
    break;
  case c_option_type_string:
    {/*{{{*/
      
      // - ERROR -
      if (src_2_location->v_type != c_bi_class_string)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      string_s *string_ptr = (string_s *)src_2_location->v_data_ptr;

      // - ERROR -
      if (nn_setsockopt(nn_fd,level,option,string_ptr->data,string_ptr->size - 1) == -1)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }
    }/*}}}*/
    break;
  default:
    
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_nano_socket_method_getsockopt_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
level:retrieve_integer
option:retrieve_integer
>
method getsockopt
; @end

  int nn_fd = (int)dst_location->v_data_ptr;

  switch (nano_msg_s::option_type(level,option))
  {
  case c_option_type_int:
    {/*{{{*/
      int value;
      size_t value_len = sizeof(value);

      // - ERROR -
      if (nn_getsockopt(nn_fd,level,option,&value,&value_len) == -1)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      long long int result = value;

      BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
    }/*}}}*/
    break;
  case c_option_type_string:
    {/*{{{*/
      char buffer[512];
      size_t buffer_size = sizeof(buffer);

      // - ERROR -
      if (nn_getsockopt(nn_fd,level,option,buffer,&buffer_size) == -1)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(buffer_size,buffer);

      BIC_SET_RESULT_STRING(string_ptr);
    }/*}}}*/
    break;
  default:
    
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  return true;
}/*}}}*/

bool bic_nano_socket_method_bind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_string
>
method bind
; @end

  int nn_fd = (int)dst_location->v_data_ptr;
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  int end_id;

  // - ERROR -
  if ((end_id = nn_bind(nn_fd,address_ptr->data)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create nano_endpoint object -
  nano_endpoint_s *ne_ptr = (nano_endpoint_s *)cmalloc(sizeof(nano_endpoint_s));
  ne_ptr->init();

  // - store reference to socket -
  dst_location->v_reference_cnt.atomic_inc();
  ne_ptr->socket_ptr = dst_location;

  ne_ptr->end_id = end_id;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_nano_endpoint,ne_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_nano_socket_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_string
>
method connect
; @end

  int nn_fd = (int)dst_location->v_data_ptr;
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  int end_id;

  // - ERROR -
  if ((end_id = nn_connect(nn_fd,address_ptr->data)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create nano_endpoint object -
  nano_endpoint_s *ne_ptr = (nano_endpoint_s *)cmalloc(sizeof(nano_endpoint_s));
  ne_ptr->init();

  // - store reference to socket -
  dst_location->v_reference_cnt.atomic_inc();
  ne_ptr->socket_ptr = dst_location;

  ne_ptr->end_id = end_id;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_nano_endpoint,ne_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_nano_socket_method_send_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
flags:retrieve_integer
>
method send
; @end

  int nn_fd = (int)dst_location->v_data_ptr;

  // - ERROR -
  if (nn_send(nn_fd,data_ptr,data_size,flags) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_nano_socket_method_recv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
flags:retrieve_integer
>
method recv
; @end

  int nn_fd = (int)dst_location->v_data_ptr;

  void *buffer;
  int cnt;

  // - ERROR -
  if ((cnt = nn_recv(nn_fd,&buffer,NN_MSG,flags)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(cnt,(char *)buffer);

  nn_freemsg(buffer);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_nano_socket_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NanoSocket"),"NanoSocket");
  );

  return true;
}/*}}}*/

bool bic_nano_socket_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NanoSocket");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NANO_ENDPOINT -
built_in_class_s nano_endpoint_class =
{/*{{{*/
  "NanoEndpoint",
  c_modifier_public | c_modifier_final,
  3, nano_endpoint_methods,
  0, nano_endpoint_variables,
  bic_nano_endpoint_consts,
  bic_nano_endpoint_init,
  bic_nano_endpoint_clear,
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

built_in_method_s nano_endpoint_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_nano_endpoint_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_endpoint_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_endpoint_method_print_0
  },
};/*}}}*/

built_in_variable_s nano_endpoint_variables[] =
{/*{{{*/
};/*}}}*/

void bic_nano_endpoint_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nano_endpoint_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (nano_endpoint_s *)nullptr;
}/*}}}*/

void bic_nano_endpoint_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  nano_endpoint_s *ne_ptr = (nano_endpoint_s *)location_ptr->v_data_ptr;

  if (ne_ptr != nullptr)
  {
    ne_ptr->clear(it);
    cfree(ne_ptr);
  }
}/*}}}*/

bool bic_nano_endpoint_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_nano_endpoint_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NanoEndpoint"),"NanoEndpoint");
  );

  return true;
}/*}}}*/

bool bic_nano_endpoint_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NanoEndpoint");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

