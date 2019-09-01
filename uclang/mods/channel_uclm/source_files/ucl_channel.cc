
@begin
include "ucl_channel.h"
@end

/*
 * methods of generated structures
 */

// -- fd_conn_map_s --
@begin
methods fd_conn_map_s
@end

// -- fd_conn_map_tree_s --
@begin
methods fd_conn_map_tree_s
@end

// -- channel_conn_s --
@begin
methods channel_conn_s
@end

bool channel_conn_s::send_msg(interpreter_thread_s &it)
{/*{{{*/
  if (this->out_msg_queue.used != 0)
  {
    string_s *message = (string_s *)((location_s *)*(out_msg_queue.data + out_msg_queue.begin))->v_data_ptr;
    size_t write_cnt = (message->size - 1) - this->out_msg_offset;

    // - limit maximal write size -
    if (write_cnt > 4096)
    {
      write_cnt = 4096;
    }

    ssize_t cnt = write(conn_fd,message->data + this->out_msg_offset,write_cnt);

    // - ERROR -
    if (cnt == -1)
    {
      return false;
    }

    // - whole message was send -
    if ((this->out_msg_offset += cnt) >= message->size - 1)
    {
      // - remove message from queue -
      it.release_location_ptr((location_s *)out_msg_queue.next());

      // - reset out message offset -
      this->out_msg_offset = 0;
    }
  }
  else
  {
    events = POLLIN | POLLPRI;
  }

  return true;
}/*}}}*/

bool channel_conn_s::recv_msg(interpreter_thread_s &it)
{/*{{{*/
  const long int c_buffer_add = 1024;
  unsigned msg_old_used = in_msg.used;

  int inq_cnt;
  long int read_cnt;
  do
  {
    in_msg.reserve(c_buffer_add);
    read_cnt = read(conn_fd,in_msg.data + in_msg.used,c_buffer_add);

    // - ERROR -
    if (read_cnt == -1)
    {
      return false;
    }

    in_msg.used += read_cnt;

    // - ERROR -
    if (ioctl(conn_fd,TIOCINQ,&inq_cnt) == -1)
    {
      return false;
    }
  }
  while(inq_cnt > 0);

  if (in_msg.used == msg_old_used)
  {
    return false;
  }

  unsigned msg_offset = 0;
  do
  {
    if (in_msg_length == 0)
    {
      if ((in_msg.used - msg_offset) < 11)
      {
        break;
      }

      debug_message_6(fprintf(stderr,"message length: %.*s\n",11,in_msg.data + msg_offset));

      // - retrieve length of message -
      char *ptr = in_msg.data + msg_offset;
      char *end_ptr;

      in_msg_length = strtol(ptr,&end_ptr,16);

      if (end_ptr - ptr != 10)
      {
        return false;
      }

      msg_offset += 11;
    }
    else
    {
      if ((in_msg.used - msg_offset) < in_msg_length)
      {
        break;
      }

      debug_message_6(fprintf(stderr,"recevived message: %.*s\n",in_msg_length,in_msg.data + msg_offset));

      // FIXME TODO call new connection callback
      fprintf(stderr,"CALLBACK: MESSAGE RECEIVED: %.*s\n",in_msg_length,in_msg.data + msg_offset);

      //bc_array_s message = {in_msg_length,in_msg_length,in_msg.data + msg_offset};

      //// - call conn_message_callback -
      //if (((channel_conn_message_callback_t)this->conn_message_callback)(this->cb_object,this->cb_index,&message))
      //{
      //  throw_error(CHANNEL_CONN_CALLBACK_ERROR);
      //}

      msg_offset += in_msg_length;

      // - reset message length -
      in_msg_length = 0;
    }
  } while(1);

  in_msg.tail(in_msg.used - msg_offset);

  return true;
}/*}}}*/

// -- channel_conn_list_s --
@begin
methods channel_conn_list_s
@end

// -- channel_server_s --
@begin
methods channel_server_s
@end

bool channel_server_s::create(const string_s &a_ip,unsigned short a_port,
    location_s *a_new_callback,
    location_s *a_drop_callback,
    location_s *a_message_callback,
    location_s *a_user_data)
{/*{{{*/
  debug_assert(server_fd == -1);

  sockaddr_in address;

  // - retrieve host by name address -
  struct hostent *host = gethostbyname(a_ip.data);

  // - ERROR -
  if (host == NULL)
  {
    return false;
  }

  memcpy(&address.sin_addr.s_addr,host->h_addr,host->h_length);
  address.sin_port = htons(a_port);
  address.sin_family = AF_INET;

  // - create socket -
  server_fd = socket(AF_INET,SOCK_STREAM,0);

  // - ERROR -
  if (server_fd == -1)
  {
    return false;
  }

  // - set server socket as reusable -
  int yes = 1;
  setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

  // - ERROR -
  if (bind(server_fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    close(server_fd);

    return false;
  }

  // - ERROR -
  if (listen(server_fd,256) != 0)
  {
    close(server_fd);

    return false;
  }

  // - retrieve callbacks -
  a_new_callback->v_reference_cnt.atomic_inc();
  new_callback = a_new_callback;

  a_drop_callback->v_reference_cnt.atomic_inc();
  drop_callback = a_drop_callback;

  a_message_callback->v_reference_cnt.atomic_inc();
  message_callback = a_message_callback;

  // - retrieve user data -
  a_user_data->v_reference_cnt.atomic_inc();
  user_data = a_user_data;

  return true;
}/*}}}*/

