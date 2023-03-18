
@begin
include "ucl_mqtt.h"
@end

// - mqtt global init object -
mqtt_c g_mqtt;

/*
 * methods of generated structures
 */

// -- mqtt_conn_s --
@begin
methods mqtt_conn_s
@end

bool mqtt_conn_s::send_msg(interpreter_thread_s &it)
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

bool mqtt_conn_s::recv_msg(interpreter_thread_s &it,location_s *dst_location,unsigned a_source_pos)
{/*{{{*/
  const long int c_buffer_add = 4096;
  unsigned msg_old_used = in_msg.used;

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
    if (in_msg.used == msg_old_used)
    {
      return false;
    }
#ifdef UCL_WITH_OPENSSL
  }
#endif

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

      // - call message callback -
      MQTT_CALL_CALLBACK_DELEGATE(message_callback,a_source_pos,

        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(in_msg_length,in_msg.data + msg_offset);
        BIC_CREATE_NEW_LOCATION_REFS(message_loc,c_bi_class_string,string_ptr,0);

        const unsigned param_cnt = 2;
        pointer param_data[param_cnt] = {dst_location MP_COMMA message_loc};
      ,
        return false;
      );

      msg_offset += in_msg_length;

      // - reset message length -
      in_msg_length = 0;
    }
  } while(true);

  in_msg.tail(in_msg.used - msg_offset);

  return true;
}/*}}}*/

// -- mqtt_conn_list_s --
@begin
methods mqtt_conn_list_s
@end

