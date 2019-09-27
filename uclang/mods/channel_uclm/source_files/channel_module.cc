
@begin
include "channel_module.h"
@end

// - CHANNEL indexes of built in classes -
unsigned c_bi_class_channel_server = c_idx_not_exist;
unsigned c_bi_class_channel_client = c_idx_not_exist;

// - CHANNEL module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                       // Class count
  channel_classes,         // Classes
  0,                       // Error base index
  10,                      // Error count
  channel_error_strings,   // Error strings
  channel_initialize,      // Initialize function
  channel_print_exception, // Print exceptions function
};/*}}}*/

// - CHANNEL classes -
built_in_class_s *channel_classes[] =
{/*{{{*/
  &channel_server_class,
  &channel_client_class,
};/*}}}*/

// - CHANNEL error strings -
const char *channel_error_strings[] =
{/*{{{*/
  "error_CHANNEL_SERVER_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_CHANNEL_SERVER_INVALID_IP_ADDRESS",
  "error_CHANNEL_SERVER_CREATE_ERROR",
  "error_CHANNEL_SERVER_ACCEPT_ERROR",
  "error_CHANNEL_SERVER_PROCESS_INVALID_FD",
  "error_CHANNEL_SERVER_MESSAGE_INVALID_CONNECTION_INDEX",
  "error_CHANNEL_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_CHANNEL_CLIENT_INVALID_IP_ADDRESS",
  "error_CHANNEL_CLIENT_CREATE_ERROR",
  "error_CHANNEL_CLIENT_PROCESS_INVALID_FD",
};/*}}}*/

// - CHANNEL initialize -
bool channel_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize channel_server class identifier -
  c_bi_class_channel_server = class_base_idx++;

  // - initialize channel_client class identifier -
  c_bi_class_channel_client = class_base_idx++;

  return true;
}/*}}}*/

// - CHANNEL print exception -
bool channel_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_CHANNEL_SERVER_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of ChannelServer delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_SERVER_INVALID_IP_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid ChannelServer ip address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_SERVER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating ChannelServer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_SERVER_ACCEPT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while accepting ChannelServer connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_SERVER_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nChannelServer, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_SERVER_MESSAGE_INVALID_CONNECTION_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nChannelServer, invalid connection index\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of ChannelClient delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_CLIENT_INVALID_IP_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid ChannelClient ip address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_CLIENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating ChannelClient\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CHANNEL_CLIENT_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nChannelClient, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class CHANNEL_SERVER -
built_in_class_s channel_server_class =
{/*{{{*/
  "ChannelServer",
  c_modifier_public | c_modifier_final,
  8, channel_server_methods,
  3, channel_server_variables,
  bic_channel_server_consts,
  bic_channel_server_init,
  bic_channel_server_clear,
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

built_in_method_s channel_server_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_channel_server_operator_binary_equal
  },
  {
    "ChannelServer#5",
    c_modifier_public | c_modifier_final,
    bic_channel_server_method_ChannelServer_5
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_channel_server_method_get_fds_0
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_channel_server_method_process_2
  },
  {
    "message#2",
    c_modifier_public | c_modifier_final,
    bic_channel_server_method_message_2
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_channel_server_method_user_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_channel_server_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_channel_server_method_print_0
  },
};/*}}}*/

built_in_variable_s channel_server_variables[] =
{/*{{{*/

  // - channel server event type constants -
  { "EVENT_ACCEPTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DROPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - channel connection index constants -
  { "CONN_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_channel_server_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert channel server event type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_CHANNEL_SERVER_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CHANNEL_SERVER_EVENT_TYPE_BIC_STATIC(c_channel_EVENT_ACCEPTED);
    CREATE_CHANNEL_SERVER_EVENT_TYPE_BIC_STATIC(c_channel_EVENT_DROPPED);
  }

  // - insert channel connection index constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_CHANNEL_SERVER_CONN_INDEX_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CHANNEL_SERVER_CONN_INDEX_BIC_STATIC(c_conn_index_CONN_ALL);
  }

}/*}}}*/

void bic_channel_server_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (channel_server_s *)nullptr;
}/*}}}*/

void bic_channel_server_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  channel_server_s *cs_ptr = (channel_server_s *)location_ptr->v_data_ptr;

  if (cs_ptr != nullptr)
  {
    cs_ptr->clear(it);
    cfree(cs_ptr);
  }
}/*}}}*/

bool bic_channel_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_channel_server_method_ChannelServer_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ip:c_bi_class_string
port:retrieve_integer
event_delegate:c_bi_class_delegate
message_delegate:c_bi_class_delegate
user_data:ignore
>
method ChannelServer
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  delegate_s *event_delegate = (delegate_s *)src_2_location->v_data_ptr;
  delegate_s *message_delegate = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (event_delegate->param_cnt != 3 ||
      message_delegate->param_cnt != 3)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  sockaddr_in address;

  // - retrieve host by name address -
  struct hostent *host = gethostbyname(string_ptr->data);

  // - ERROR -
  if (host == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_INVALID_IP_ADDRESS,operands[c_source_pos_idx],src_0_location);
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
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set server socket as reusable -
  int yes = 1;
  setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

  // - ERROR -
  if (bind(fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (listen(fd,256) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create channel_server object -
  channel_server_s *cs_ptr = (channel_server_s *)cmalloc(sizeof(channel_server_s));
  cs_ptr->init();
  cs_ptr->init_static();

  // - set file descriptor -
  cs_ptr->server_fd = fd;

  // - retrieve callbacks -
  src_2_location->v_reference_cnt.atomic_inc();
  cs_ptr->event_callback = src_2_location;

  src_3_location->v_reference_cnt.atomic_inc();
  cs_ptr->message_callback = src_3_location;

  // - retrieve user data -
  src_4_location->v_reference_cnt.atomic_inc();
  cs_ptr->user_data = src_4_location;

  // - set destination data pointer -
  dst_location->v_data_ptr = (channel_server_s *)cs_ptr;

  return true;
}/*}}}*/

bool bic_channel_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  channel_server_s *cs_ptr = (channel_server_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,cs_ptr->server_fd);
  array_ptr->push(fd_location);

  BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,POLLIN | POLLPRI);
  array_ptr->push(events_location);

  if (cs_ptr->fd_conn_map.root_idx != c_idx_not_exist)
  {
    fd_conn_map_tree_s_node *fcmtn_ptr = cs_ptr->fd_conn_map.data;
    fd_conn_map_tree_s_node *fcmtn_ptr_end = fcmtn_ptr + cs_ptr->fd_conn_map.used;
    do {
      if (fcmtn_ptr->valid)
      {
        BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,fcmtn_ptr->object.fd);
        array_ptr->push(fd_location);

        BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,
          cs_ptr->conn_list[fcmtn_ptr->object.conn_index].events);
        array_ptr->push(events_location);
      }
    } while(++fcmtn_ptr < fcmtn_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_channel_server_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  channel_server_s *cs_ptr = (channel_server_s *)dst_location->v_data_ptr;

  if (fd == cs_ptr->server_fd)
  {
    socklen_t addr_len = sizeof(struct sockaddr_in);
    sockaddr_in address;

    // - ERROR -
    int conn_fd = accept(cs_ptr->server_fd,(struct sockaddr *)&address,&addr_len);
    if (conn_fd == -1)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - ERROR -
    if (addr_len != sizeof(struct sockaddr_in))
    {
      close(conn_fd);

      exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - create new connection -
    unsigned conn_index = cs_ptr->conn_list.append_blank();

    channel_conn_s &conn = cs_ptr->conn_list[conn_index];
    conn.init_static();

    conn.conn_fd = conn_fd;
    conn.events = POLLIN | POLLPRI;

    ((location_s *)cs_ptr->message_callback)->v_reference_cnt.atomic_inc();
    conn.message_callback = cs_ptr->message_callback;

    conn.conn_index = conn_index;

    // - update fd connection map -
    fd_conn_map_s fd_conn_map = {conn_fd,conn_index};
    unsigned fd_conn_map_index = cs_ptr->fd_conn_map.insert(fd_conn_map);

    // - call new connection callback -
    CHANNEL_CALL_CALLBACK_DELEGATE(cs_ptr->event_callback,operands[c_source_pos_idx],
      BIC_CREATE_NEW_LOCATION_REFS(conn_index_loc,c_bi_class_integer,conn_index,0);
      BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_channel_EVENT_ACCEPTED,0);

      const unsigned param_cnt = 3;
      pointer param_data[param_cnt] = {dst_location MP_COMMA conn_index_loc MP_COMMA event_type_loc};
    ,
      // - drop connection without callback -
      conn.clear(it);
      cs_ptr->conn_list.remove(conn_index);
      cs_ptr->fd_conn_map.remove(fd_conn_map_index);

      return false;
    );
  }
  else
  {
    fd_conn_map_s search_fd_conn_map = {(int)fd,0};
    unsigned fd_conn_map_index = cs_ptr->fd_conn_map.get_idx(search_fd_conn_map);

    // - ERROR -
    if (fd_conn_map_index == c_idx_not_exist)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    unsigned conn_index = cs_ptr->fd_conn_map[fd_conn_map_index].conn_index;
    channel_conn_s &conn = cs_ptr->conn_list[conn_index];

    // - mask events with connection events -
    unsigned conn_events = conn.events & events;

    // - drop connection flag -
    bool drop_connection = false;

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

    // - drop connection flag is set -
    if (drop_connection)
    {
      // - call drop connection callback -
      CHANNEL_CALL_CALLBACK_DELEGATE(cs_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(conn_index_loc,c_bi_class_integer,conn_index,0);
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_channel_EVENT_DROPPED,0);

        const unsigned param_cnt = 3;
        pointer param_data[param_cnt] = {dst_location MP_COMMA conn_index_loc MP_COMMA event_type_loc};
      ,
      );

      // - drop connection -
      conn.clear(it);
      cs_ptr->conn_list.remove(conn_index);
      cs_ptr->fd_conn_map.remove(fd_conn_map_index);

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

bool bic_channel_server_method_message_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
conn_index:retrieve_integer_init
conn_index:c_bi_class_array
message:c_bi_class_string
>
method process
; @end

  channel_server_s *cs_ptr = (channel_server_s *)dst_location->v_data_ptr;
  string_s *message_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create message length string -
  string_s *length_ptr = it.get_new_string_ptr();
  length_ptr->setf("0x%8.8x;",message_ptr->size - 1);

  BIC_CREATE_NEW_LOCATION(length_location,c_bi_class_string,length_ptr);

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
          it.release_location_ptr(length_location);

          exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_MESSAGE_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        if (conn_index >= cs_ptr->conn_list.used || !cs_ptr->conn_list.data[conn_index].valid)
        {
          it.release_location_ptr(length_location);

          exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_MESSAGE_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        channel_conn_s &conn = cs_ptr->conn_list[conn_index];

        // - insert length of message to queue -
        length_location->v_reference_cnt.atomic_inc();
        conn.out_msg_queue.insert(length_location);

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
      if (cs_ptr->conn_list.first_idx != c_idx_not_exist)
      {
        unsigned cl_idx = cs_ptr->conn_list.first_idx;
        do {
          channel_conn_s &conn = cs_ptr->conn_list[cl_idx];

          // - insert length of message to queue -
          length_location->v_reference_cnt.atomic_inc();
          conn.out_msg_queue.insert(length_location);

          // - insert message to queue -
          src_1_location->v_reference_cnt.atomic_inc();
          conn.out_msg_queue.insert(src_1_location);

          // - update connection events -
          conn.events = POLLIN | POLLPRI | POLLOUT;

          cl_idx = cs_ptr->conn_list.next_idx(cl_idx);
        } while(cl_idx != c_idx_not_exist);
      }
    }
    else
    {
      // - ERROR -
      if (conn_index < 0 || conn_index >= cs_ptr->conn_list.used ||
          !cs_ptr->conn_list.data[conn_index].valid)
      {
        it.release_location_ptr(length_location);

        exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_SERVER_MESSAGE_INVALID_CONNECTION_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      channel_conn_s &conn = cs_ptr->conn_list[conn_index];

      // - insert length of message to queue -
      length_location->v_reference_cnt.atomic_inc();
      conn.out_msg_queue.insert(length_location);

      // - insert message to queue -
      src_1_location->v_reference_cnt.atomic_inc();
      conn.out_msg_queue.insert(src_1_location);

      // - update connection events -
      conn.events = POLLIN | POLLPRI | POLLOUT;
    }
  }

  it.release_location_ptr(length_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_channel_server_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  channel_server_s *cs_ptr = (channel_server_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&cs_ptr->user_data);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_channel_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ChannelServer"),"ChannelServer")
  );

  return true;
}/*}}}*/

bool bic_channel_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ChannelServer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CHANNEL_CLIENT -
built_in_class_s channel_client_class =
{/*{{{*/
  "ChannelClient",
  c_modifier_public | c_modifier_final,
  10, channel_client_methods,
  3, channel_client_variables,
  bic_channel_client_consts,
  bic_channel_client_init,
  bic_channel_client_clear,
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

built_in_method_s channel_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_channel_client_operator_binary_equal
  },
  {
    "ChannelClient#5",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_ChannelClient_5
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_get_fd_0
  },
  {
    "events#0",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_events_0
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_get_fds_0
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_process_2
  },
  {
    "message#1",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_message_1
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_channel_client_method_user_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_channel_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_channel_client_method_print_0
  },
};/*}}}*/

built_in_variable_s channel_client_variables[] =
{/*{{{*/

  // - channel client event type constants -
  { "EVENT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_CONNECTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DROPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_channel_client_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert channel client event type constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_CHANNEL_CLIENT_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CHANNEL_CLIENT_EVENT_TYPE_BIC_STATIC(c_channel_EVENT_ERROR);
    CREATE_CHANNEL_CLIENT_EVENT_TYPE_BIC_STATIC(c_channel_EVENT_CONNECTED);
    CREATE_CHANNEL_CLIENT_EVENT_TYPE_BIC_STATIC(c_channel_EVENT_DROPPED);
  }

}/*}}}*/

void bic_channel_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (channel_conn_s *)nullptr;
}/*}}}*/

void bic_channel_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  channel_conn_s *cc_ptr = (channel_conn_s *)location_ptr->v_data_ptr;

  if (cc_ptr != nullptr)
  {
    cc_ptr->clear(it);
    cfree(cc_ptr);
  }
}/*}}}*/

bool bic_channel_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_channel_client_method_ChannelClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ip:c_bi_class_string
port:retrieve_integer
event_delegate:c_bi_class_delegate
message_delegate:c_bi_class_delegate
user_data:ignore
>
method ChannelClient
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  delegate_s *event_delegate = (delegate_s *)src_2_location->v_data_ptr;
  delegate_s *message_delegate = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (event_delegate->param_cnt != 2 ||
      message_delegate->param_cnt != 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  sockaddr_in address;

  // - retrieve host by name address -
  struct hostent *host = gethostbyname(string_ptr->data);

  // - ERROR -
  if (host == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_CLIENT_INVALID_IP_ADDRESS,operands[c_source_pos_idx],src_0_location);
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
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  int nonblock_io = 1;
  if (ioctl(fd,FIONBIO,&nonblock_io) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (connect(fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    if (errno != EINPROGRESS)
    {
      close(fd);

      exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - create channel_client object -
  channel_conn_s *cc_ptr = (channel_conn_s *)cmalloc(sizeof(channel_conn_s));
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
  dst_location->v_data_ptr = (channel_conn_s *)cc_ptr;

  return true;
}/*}}}*/

bool bic_channel_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((channel_conn_s *)dst_location->v_data_ptr)->conn_fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_channel_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((channel_conn_s *)dst_location->v_data_ptr)->events;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_channel_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  channel_conn_s *cc_ptr = (channel_conn_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (cc_ptr->events != 0)
  {
    BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,cc_ptr->conn_fd);
    array_ptr->push(fd_location);

    BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,cc_ptr->events);
    array_ptr->push(events_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_channel_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  channel_conn_s *cc_ptr = (channel_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fd != cc_ptr->conn_fd)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CHANNEL_CLIENT_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (cc_ptr->connecting)
  {
    // - reset connecting flag -
    cc_ptr->connecting = false;

    int nonblock_io = 0;
    int error;
    socklen_t length = sizeof(error);

    // - check connect result -
    // - disable nonblocking io -
    // - modify fd epoll events: only input -
    if (getsockopt(cc_ptr->conn_fd,SOL_SOCKET,SO_ERROR,&error,&length) ||
        error != 0 ||
        ioctl(cc_ptr->conn_fd,FIONBIO,&nonblock_io))
    {
      cc_ptr->events = 0;

      // - call event error callback -
      CHANNEL_CALL_CALLBACK_DELEGATE(cc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_channel_EVENT_ERROR,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA event_type_loc};
      ,
        return false;
      );
    }
    else
    {
      // - call event new callback -
      CHANNEL_CALL_CALLBACK_DELEGATE(cc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_channel_EVENT_CONNECTED,0);

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
    // - mask events with connection events -
    unsigned conn_events = cc_ptr->events & events;

    // - drop connection flag -
    bool drop_connection = false;

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

    // - drop connection flag is set -
    if (drop_connection)
    {
      cc_ptr->events = 0;

      // - call event drop callback -
      CHANNEL_CALL_CALLBACK_DELEGATE(cc_ptr->event_callback,operands[c_source_pos_idx],
        BIC_CREATE_NEW_LOCATION_REFS(event_type_loc,c_bi_class_integer,c_channel_EVENT_DROPPED,0);

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

bool bic_channel_client_method_message_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
message:c_bi_class_string
>
method process
; @end

  channel_conn_s *cc_ptr = (channel_conn_s *)dst_location->v_data_ptr;
  string_s *message_ptr = (string_s *)src_0_location->v_data_ptr;

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

bool bic_channel_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  channel_conn_s *cc_ptr = (channel_conn_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&cc_ptr->user_data);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_channel_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ChannelClient"),"ChannelClient")
  );

  return true;
}/*}}}*/

bool bic_channel_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ChannelClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

