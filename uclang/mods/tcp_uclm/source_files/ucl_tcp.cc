
@begin
include "ucl_tcp.h"
@end

// - tcp global init object -
tcp_c g_tcp;

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

// -- tcp_conn_s --
@begin
methods tcp_conn_s
@end

bool tcp_conn_s::send_msg(interpreter_thread_s &it)
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

    ssize_t cnt;

#ifdef UCL_WITH_OPENSSL
    if (ssl != nullptr)
    {
      cnt = SSL_write(ssl,message->data + this->out_msg_offset,write_cnt);

      if (cnt <= 0)
      {
        switch (SSL_get_error(ssl,cnt))
        {
          case SSL_ERROR_WANT_READ:
            ssl_action = SSL_ACTION_SEND_MSG;
            ssl_events = POLLIN | POLLPRI;
            break;
          case SSL_ERROR_WANT_WRITE:
            break;
          default:
            return false;
        }

        cnt = 0;
      }
    }
    else
    {
#endif
      cnt = write(conn_fd,message->data + this->out_msg_offset,write_cnt);

      // - ERROR -
      if (cnt == -1)
      {
        return false;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

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

bool tcp_conn_s::recv_msg(interpreter_thread_s &it,location_s *dst_location,unsigned a_source_pos)
{/*{{{*/
  const long int c_buffer_add = 4096;
  in_msg.used = 0;

  long int read_cnt;
  do
  {
    in_msg.reserve(c_buffer_add);

#ifdef UCL_WITH_OPENSSL
    if (ssl != nullptr)
    {
      read_cnt = SSL_read(ssl,in_msg.data + in_msg.used,c_buffer_add);

      if (read_cnt <= 0)
      {
        switch (SSL_get_error(ssl,read_cnt))
        {
          case SSL_ERROR_WANT_READ:
            break;
          case SSL_ERROR_WANT_WRITE:
            ssl_action = SSL_ACTION_RECV_MSG;
            ssl_events = POLLOUT;
            break;
          default:
            return false;
        }

        break;
      }
    }
    else
    {
#endif
      read_cnt = read(conn_fd,in_msg.data + in_msg.used,c_buffer_add);

      // - ERROR -
      if (read_cnt == -1)
      {
        return false;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    in_msg.used += read_cnt;

#ifdef UCL_WITH_OPENSSL
    if (ssl == nullptr)
    {
#endif

      // - ERROR -
      int inq_cnt;
      if (ioctl(conn_fd,TIOCINQ,&inq_cnt) == -1)
      {
        return false;
      }

      if (inq_cnt <= 0)
      {
        break;
      }
#ifdef UCL_WITH_OPENSSL
    }
    else
    {
      if (read_cnt <= 0)
      {
        break;
      }
    }
#endif
  } while(true);

#ifdef UCL_WITH_OPENSSL
  if (ssl == nullptr)
  {
#endif
    if (in_msg.used == 0)
    {
      return false;
    }
#ifdef UCL_WITH_OPENSSL
  }
  else
  {
    if (in_msg.used == 0)
    {
      return true;
    }
  }
#endif

  // - call message callback -
  TCP_CALL_CALLBACK_DELEGATE(message_callback,a_source_pos,

    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(in_msg.used,in_msg.data);
    BIC_CREATE_NEW_LOCATION_REFS(message_loc,c_bi_class_string,string_ptr,0);

    unsigned param_cnt;
    pointer param_data[3];

    // - server callback -
    if (dst_location->v_type == c_bi_class_tcp_server)
    {
      BIC_CREATE_NEW_LOCATION_REFS(conn_index_loc,c_bi_class_integer,conn_index,0);

      param_cnt = 3;
      param_data[0] = dst_location;
      param_data[1] = conn_index_loc;
      param_data[2] = message_loc;
    }

    // - client callback -
    else
    {
      param_cnt = 2;
      param_data[0] = dst_location;
      param_data[1] = message_loc;
    }
  ,
    return false;
  );

  return true;
}/*}}}*/

// -- tcp_conn_list_s --
@begin
methods tcp_conn_list_s
@end

// -- tcp_server_s --
@begin
methods tcp_server_s
@end

