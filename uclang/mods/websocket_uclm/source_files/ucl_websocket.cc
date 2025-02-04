
@begin
include "ucl_websocket.h"
@end

// - websocket default extensions -
const lws_extension ws_default_extensions[] =
{/*{{{*/
  { "permessage-deflate",lws_extension_callback_pm_deflate,"permessage-deflate" },
  { "deflate-frame",lws_extension_callback_pm_deflate,"deflate_frame" },
  { NULL,NULL,NULL }
};/*}}}*/

// - websocket global init object -
websocket_c g_websocket;

/*
 * methods of generated structures
 */

// -- fd_flags_s --
@begin
methods fd_flags_s
@end

// -- fd_flags_rb_tree_s --
@begin
methods fd_flags_rb_tree_s
@end

/*
 * global functions
 */

void log_emit(int level,const char *line)
{/*{{{*/
  //fprintf(stderr,"LWS_LOG: %d,%s",level,line);
}/*}}}*/

int http_func(lws *wsi,enum lws_callback_reasons reason,void *user,void *in,size_t len)
{/*{{{*/
  switch (reason)
  {
    case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
      break;
    case LWS_CALLBACK_ADD_POLL_FD:
    case LWS_CALLBACK_DEL_POLL_FD:
    case LWS_CALLBACK_CHANGE_MODE_POLL_FD:
      {
        ws_context_s *wsc_ptr = (ws_context_s *)lws_context_user(lws_get_context(wsi));
        fd_flags_rb_tree_s &poll_fds = wsc_ptr->poll_fds;

        lws_pollargs *args_ptr = (lws_pollargs *)in;

#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
        int events =
          ((args_ptr->events & 0x01) ? POLLIN  : 0) |
          // - POLLPRI ignored on windows -
          ((args_ptr->events & 0x04) ? POLLOUT : 0) |
          // - POLLERR ignored on windows -
          ((args_ptr->events & 0x10) ? POLLHUP : 0);

        fd_flags_s fd_flags = {args_ptr->fd,events};
#else
        fd_flags_s fd_flags = {args_ptr->fd,args_ptr->events};
#endif

        switch (reason)
        {
          // - add poll fd -
          case LWS_CALLBACK_ADD_POLL_FD:
            {
              poll_fds.insert(fd_flags);
            }
            break;

          // - delete poll fd -
          case LWS_CALLBACK_DEL_POLL_FD:
            {
              unsigned ff_idx = poll_fds.get_idx(fd_flags);
              cassert(ff_idx != c_idx_not_exist);

              poll_fds.remove(ff_idx);
            }
            break;

          // - change poll fd mode -
          case LWS_CALLBACK_CHANGE_MODE_POLL_FD:
            {
              unsigned ff_idx = poll_fds.get_idx(fd_flags);
              cassert(ff_idx != c_idx_not_exist);

              poll_fds[ff_idx].flags = fd_flags.flags;
            }
            break;

          default:
            break;
        }
      }
      break;
    default:
      break;
  }

  return 0;
}/*}}}*/

int protocol_func(lws *wsi,enum lws_callback_reasons reason,void *user,void *in,size_t len)
{/*{{{*/
  ws_context_s *wsc_ptr = (ws_context_s *)lws_context_user(lws_get_context(wsi));
  interpreter_thread_s &it = *wsc_ptr->it_ptr;

  location_s *conn_location = nullptr;
  ws_conn_s *wscn_ptr = nullptr;

  switch (reason)
  {
    case LWS_CALLBACK_ESTABLISHED:
    case LWS_CALLBACK_CLIENT_ESTABLISHED:
      {/*{{{*/

        // - create websocket connection object -
        wscn_ptr = (ws_conn_s *)cmalloc(sizeof(ws_conn_s));
        wscn_ptr->init();

        // - set websocket context pointer -
        wscn_ptr->wsc_ptr = wsc_ptr;

        // - set protocol index pointer -
        wscn_ptr->prot_idx = wsc_ptr->get_protocol_idx(wsi);
        debug_assert(wscn_ptr->prot_idx != c_idx_not_exist);

        // - set websocket pointer -
        wscn_ptr->ws_ptr = wsi;

        // - retrieve user data pointer -
        location_s *user_data_loc = (location_s *)lws_get_opaque_user_data(wsi);
        if (user_data_loc == nullptr)
        {
          user_data_loc = (location_s *)it.blank_location;
        }

        // - initialize connection user data pointer -
        user_data_loc->v_reference_cnt.atomic_inc();
        wscn_ptr->user_data_ptr = user_data_loc;

        // - create websocket connection location -
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ws_conn,wscn_ptr);
        conn_location = new_location;

        *((pointer *)user) = new_location;
      }/*}}}*/
      break;
    case LWS_CALLBACK_CLOSED:
    case LWS_CALLBACK_CLIENT_CLOSED:
    case LWS_CALLBACK_RECEIVE:
    case LWS_CALLBACK_RECEIVE_PONG:
    case LWS_CALLBACK_CLIENT_RECEIVE:
    case LWS_CALLBACK_CLIENT_RECEIVE_PONG:
    case LWS_CALLBACK_CLIENT_WRITEABLE:
    case LWS_CALLBACK_SERVER_WRITEABLE:
      {/*{{{*/

        // - retrieve connection pointer -
        conn_location = (location_s *)*((pointer *)user);
        wscn_ptr = (ws_conn_s *)conn_location->v_data_ptr;
      }/*}}}*/
      break;
    default:
      break;
  }

  if (wsc_ptr->ret_code == c_run_return_code_OK)
  {
    switch (reason)
    {
      case LWS_CALLBACK_RECEIVE:
      case LWS_CALLBACK_CLIENT_RECEIVE:
        {/*{{{*/

          // - retrieve count of remaining bytes of packet -
          size_t remaining = lws_remaining_packet_payload(wsi);
          int final_frag = lws_is_final_fragment(wsi);
          bc_array_s &data_buffer = wscn_ptr->data_buffer;

          // - message is not complete or buffered data exists -
          if (remaining != 0 || !final_frag || data_buffer.used != 0)
          {
            data_buffer.reserve(len + remaining);
            data_buffer.append(len,(const char *)in);
          }

          if (remaining == 0 && (data_buffer.used == 0 || final_frag))
          {
            // - retrieve delegate pointer -
            location_s *dlg_location = (location_s *)wsc_ptr->prot_dlgs[wscn_ptr->prot_idx];
            delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;

            // - set callback reason -
            wscn_ptr->reason = reason;

            // - set callback input data -
            if (data_buffer.used != 0)
            {
              wscn_ptr->data_in = data_buffer.data;
              wscn_ptr->data_len = data_buffer.used;
              data_buffer.used = 0;
            }
            else
            {
              wscn_ptr->data_in = in;
              wscn_ptr->data_len = len;
            }

            // - callback parameters -
            const unsigned param_cnt = 1;
            pointer *param_data = (pointer *)&conn_location;

            // - call delegate method -
            location_s *trg_location = nullptr;
            BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,wsc_ptr->source_pos,
                wsc_ptr->ret_code = c_run_return_code_EXCEPTION;

                // - release connection location -
                it.release_location_ptr(conn_location);

                return 1;
                );
            it.release_location_ptr(trg_location);
          }
        }/*}}}*/
        break;
      case LWS_CALLBACK_ESTABLISHED:
      case LWS_CALLBACK_CLIENT_ESTABLISHED:
      case LWS_CALLBACK_CLOSED:
      case LWS_CALLBACK_CLIENT_CLOSED:
      case LWS_CALLBACK_RECEIVE_PONG:
      case LWS_CALLBACK_CLIENT_RECEIVE_PONG:
      case LWS_CALLBACK_CLIENT_WRITEABLE:
      case LWS_CALLBACK_SERVER_WRITEABLE:
        {/*{{{*/

          // - retrieve delegate pointer -
          location_s *dlg_location = (location_s *)wsc_ptr->prot_dlgs[wscn_ptr->prot_idx];
          delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;

          // - set callback reason -
          wscn_ptr->reason = reason;

          wscn_ptr->data_in = nullptr;
          wscn_ptr->data_len = 0;

          // - callback parameters -
          const unsigned param_cnt = 1;
          pointer *param_data = (pointer *)&conn_location;

          // - call delegate method -
          location_s *trg_location = nullptr;
          BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,wsc_ptr->source_pos,
              wsc_ptr->ret_code = c_run_return_code_EXCEPTION;

              // - release connection location -
              it.release_location_ptr(conn_location);

              return 1;
              );
          it.release_location_ptr(trg_location);

          // - if connection closed -
          if (reason == LWS_CALLBACK_CLOSED || reason == LWS_CALLBACK_CLIENT_CLOSED)
          {
            // - release connection location -
            it.release_location_ptr(conn_location);
          }
        }/*}}}*/
        break;
      default:
        break;
    }
  }

  return 0;
}/*}}}*/

/*
 * base64 decode functions
 */

int base64_decode_value(int value_in)
{/*{{{*/
  static const int decoding[] = {62,-1,-1,-1,63,52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-2,-1,-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
  static const int decoding_size = 80;
  value_in -= 43;
  if (value_in < 0 || value_in >= decoding_size)
  {
    return -1;
  }
  return decoding[(int)value_in];
}/*}}}*/

void base64_init_decodestate(base64_decodestate* state_in)
{/*{{{*/
  state_in->step = step_a;
  state_in->plainchar = 0;
}/*}}}*/

int base64_decode_block(const char* code_in,const int length_in,char* plaintext_out,base64_decodestate* state_in)
{/*{{{*/
  const char* codechar = code_in;
  char* plainchar = plaintext_out;
  char fragment;

  *plainchar = state_in->plainchar;

  switch (state_in->step)
  {
    while (1)
    {
    case step_a:
      do
      {
        if (codechar == code_in+length_in)
        {
          state_in->step = step_a;
          state_in->plainchar = *plainchar;
          return plainchar - plaintext_out;
        }
        fragment = (char)base64_decode_value(*codechar++);
      }
      while (fragment < 0);
      *plainchar    = (fragment & 0x03f) << 2;
    case step_b:
      do
      {
        if (codechar == code_in+length_in)
        {
          state_in->step = step_b;
          state_in->plainchar = *plainchar;
          return plainchar - plaintext_out;
        }
        fragment = (char)base64_decode_value(*codechar++);
      }
      while (fragment < 0);
      *plainchar++ |= (fragment & 0x030) >> 4;
      *plainchar    = (fragment & 0x00f) << 4;
    case step_c:
      do
      {
        if (codechar == code_in+length_in)
        {
          state_in->step = step_c;
          state_in->plainchar = *plainchar;
          return plainchar - plaintext_out;
        }
        fragment = (char)base64_decode_value(*codechar++);
      }
      while (fragment < 0);
      *plainchar++ |= (fragment & 0x03c) >> 2;
      *plainchar    = (fragment & 0x003) << 6;
    case step_d:
      do
      {
        if (codechar == code_in+length_in)
        {
          state_in->step = step_d;
          state_in->plainchar = *plainchar;
          return plainchar - plaintext_out;
        }
        fragment = (char)base64_decode_value(*codechar++);
      }
      while (fragment < 0);
      *plainchar++   |= (fragment & 0x03f);
    }
  }
  /* control should not reach here */
  return plainchar - plaintext_out;
}/*}}}*/

