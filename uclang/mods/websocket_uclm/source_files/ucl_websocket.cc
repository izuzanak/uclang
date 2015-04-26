
@begin
include "ucl_websocket.h"
@end

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

int http_func(libwebsocket_context *ctx,libwebsocket *wsi,
              enum libwebsocket_callback_reasons reason,void *user,void *in,size_t len)
{/*{{{*/
  switch (reason)
  {
    case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
      break;
    case LWS_CALLBACK_ADD_POLL_FD:
    case LWS_CALLBACK_DEL_POLL_FD:
    case LWS_CALLBACK_CHANGE_MODE_POLL_FD:
      {
        ws_context_s *wsc_ptr = (ws_context_s *)libwebsocket_context_user(ctx);
        fd_flags_rb_tree_s &poll_fds = wsc_ptr->poll_fds;

        libwebsocket_pollargs *args_ptr = (libwebsocket_pollargs *)in;
        fd_flags_s fd_flags = {args_ptr->fd,args_ptr->events};

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

int protocol_func(libwebsocket_context *ctx,libwebsocket *wsi,
                  enum libwebsocket_callback_reasons reason,void *user,void *in,size_t len)
{/*{{{*/
  switch (reason)
  {
    case LWS_CALLBACK_ESTABLISHED:
    case LWS_CALLBACK_CLIENT_ESTABLISHED:
    case LWS_CALLBACK_CLOSED:
    case LWS_CALLBACK_RECEIVE:
    case LWS_CALLBACK_CLIENT_RECEIVE:
    case LWS_CALLBACK_CLIENT_RECEIVE_PONG:
    case LWS_CALLBACK_CLIENT_WRITEABLE:
    case LWS_CALLBACK_SERVER_WRITEABLE:
      {
        ws_context_s *wsc_ptr = (ws_context_s *)libwebsocket_context_user(ctx);
        interpreter_thread_s &it = *wsc_ptr->it_ptr;

        if (wsc_ptr->ret_code == c_run_return_code_OK)
        {
          // - if connection established -
          if (reason == LWS_CALLBACK_ESTABLISHED ||
              reason == LWS_CALLBACK_CLIENT_ESTABLISHED)
          {
            // - create websocket connection object -
            ws_conn_s *wscn_ptr = (ws_conn_s *)cmalloc(sizeof(ws_conn_s));
            wscn_ptr->init();

            // - set websocket context pointer -
            wscn_ptr->wsc_ptr = wsc_ptr;

            // - set protocol index pointer -
            wscn_ptr->prot_idx = wsc_ptr->get_protocol_idx(wsi);
            debug_assert(wscn_ptr->prot_idx != c_idx_not_exist);

            // - set websocket pointer -
            wscn_ptr->ws_ptr = wsi;

            // - set websocket client status -
            if (reason == LWS_CALLBACK_CLIENT_ESTABLISHED)
            {
              ws_client_s *wscl_ptr = *((ws_client_s **)user);

              // - set websocket client connected flag -
              wscl_ptr->connected = true;
            }

            // - set user data pointer to blank location -
            ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
            wscn_ptr->user_data_ptr = (location_s *)it.blank_location;

            // - create websocket connection location -
            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ws_conn,wscn_ptr);
            *((pointer *)user) = new_location;
          }

          // - retrieve connection pointer -
          location_s *conn_location = (location_s *)*((pointer *)user);
          ws_conn_s *wscn_ptr = (ws_conn_s *)conn_location->v_data_ptr;

          // - retrieve delegate pointer -
          location_s *dlg_location = (location_s *)wsc_ptr->prot_dlgs[wscn_ptr->prot_idx];
          delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;

          // - set callback reason -
          wscn_ptr->reason = reason;

          // - set callback input data -
          wscn_ptr->data_in = in;
          wscn_ptr->data_len = len;

          // - callback parameters -
          const unsigned param_cnt = 1;
          pointer *param_data = (pointer *)&conn_location;

          // - call delegate method -
          location_s *trg_location = NULL;
          BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,wsc_ptr->source_pos,
              wsc_ptr->ret_code = c_run_return_code_EXCEPTION;

              // - release connection location -
              it.release_location_ptr(conn_location);

              return 1;
              );
          it.release_location_ptr(trg_location);

          // - if connection closed -
          if (reason == LWS_CALLBACK_CLOSED)
          {
            // - release connection location -
            it.release_location_ptr(conn_location);
          }
        }
      }
      break;
    default:
      break;
  }

  return 0;
}/*}}}*/

/*
 * base64 decode functions
 */

int base64_decode_value(char value_in)
{/*{{{*/
  static const char decoding[] = {62,-1,-1,-1,63,52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-2,-1,-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
  static const char decoding_size = sizeof(decoding);
  value_in -= 43;
  if (value_in < 0 || value_in > decoding_size) return -1;
  return decoding[(int)value_in];
}/*}}}*/

void base64_init_decodestate(base64_decodestate* state_in)
{/*{{{*/
  state_in->step = step_a;
  state_in->plainchar = 0;
}/*}}}*/

int base64_decode_block(const char* code_in, const int length_in, char* plaintext_out, base64_decodestate* state_in)
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
