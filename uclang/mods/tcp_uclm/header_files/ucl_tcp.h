
#ifndef __UCL_TCP_H
#define __UCL_TCP_H

@begin
include "script_parser.h"
@end

#include <netdb.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <netinet/tcp.h>

#ifdef UCL_WITH_OPENSSL
#include <openssl/ssl.h>
#include <openssl/err.h>
#endif

/*
 * basic definitions and constants
 */

extern unsigned c_bi_class_tcp_server;
extern unsigned c_bi_class_tcp_client;

// - tcp event types -
enum
{
  c_tcp_EVENT_ERROR = -1,
  c_tcp_EVENT_ACCEPTED,
  c_tcp_EVENT_CONNECTED,
  c_tcp_EVENT_DROPPED,
};

// - special connection indexes -
enum
{
  c_conn_index_CONN_ALL = -1,
};

#ifdef UCL_WITH_OPENSSL
// - ssl repeated actions -
enum
{
  SSL_ACTION_NONE = 0,
  SSL_ACTION_SEND_MSG,
  SSL_ACTION_RECV_MSG
};
#endif

#define TCP_CALL_CALLBACK_DELEGATE(NAME,SOURCE_POS,PARAM_CODE,ERROR_CODE) \
{/*{{{*/\
  delegate_s *delegate_ptr = (delegate_s *)((location_s *)NAME)->v_data_ptr;\
\
  PARAM_CODE;\
\
  /* - call delegate method - */\
  location_s *trg_location = nullptr;\
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,SOURCE_POS,\
    ERROR_CODE;\
  );\
  it.release_location_ptr(trg_location);\
}/*}}}*/

/*
 * definition of class tcp_c
 */

class tcp_c
{
  public:
  inline tcp_c();
  inline ~tcp_c();
};

/*
 * definition of generated structures
 */

// -- fd_conn_map_s --
@begin
struct
<
bi:fd
ui:conn_index
>
fd_conn_map_s;
@end

// -- fd_conn_map_tree_s --
@begin
safe_rb_tree<fd_conn_map_s> fd_conn_map_tree_s;
@end

// -- tcp_conn_s --
@begin
struct
<
bi:conn_fd
ui:events
bool:connecting
bool:connected

pointer:event_callback
pointer:message_callback
pointer:user_data
ui:conn_index

bc_array_s:in_msg

pointer_queue_s:out_msg_queue
ui:out_msg_offset
>

additions
{
#ifdef UCL_WITH_OPENSSL
  SSL *ssl;

  ui ssl_action;
  ui ssl_events;
#endif

  bool send_msg(interpreter_thread_s &it);
  bool recv_msg(interpreter_thread_s &it,location_s *dst_location,unsigned a_source_pos);

  inline void init_static();
  inline void clear(interpreter_thread_s &it);
}

tcp_conn_s;
@end

// -- tcp_conn_list_s --
@begin
safe_list<tcp_conn_s> tcp_conn_list_s;
@end

// -- tcp_server_s --
@begin
struct
<
bi:server_fd
pointer:event_callback
pointer:message_callback
pointer:user_data
tcp_conn_list_s:conn_list
fd_conn_map_tree_s:fd_conn_map
>

additions
{
#ifdef UCL_WITH_OPENSSL
  SSL_CTX *ssl_ctx;
#endif

  inline void init_static();
  inline void clear(interpreter_thread_s &it);
}

tcp_server_s;
@end

/*
 * inline methods of class tcp_c
 */

inline tcp_c::tcp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"tcp_init()\n"););

#ifdef UCL_WITH_OPENSSL
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();
#endif
}/*}}}*/

inline tcp_c::~tcp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"tcp_exit()\n"););

#ifdef UCL_WITH_OPENSSL
  EVP_cleanup();
#endif
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- fd_conn_map_s --
@begin
inlines fd_conn_map_s
@end

// -- fd_conn_map_tree_s --
@begin
inlines fd_conn_map_tree_s
@end

inline int fd_conn_map_tree_s::__compare_value(fd_conn_map_s &a_first,fd_conn_map_s &a_second)
{/*{{{*/
  return a_first.fd < a_second.fd ? -1 : a_first.fd > a_second.fd ? 1 : 0;
}/*}}}*/

// -- tcp_conn_s --
@begin
inlines tcp_conn_s
@end

inline void tcp_conn_s::init_static()
{/*{{{*/
#ifdef UCL_WITH_OPENSSL
  ssl = nullptr;
  ssl_action = SSL_ACTION_NONE;
  ssl_events = 0;
#endif

  conn_fd = -1;
  events = 0;
  connecting = false;
  connected = false;

  event_callback = nullptr;
  message_callback = nullptr;
  user_data = nullptr;
  conn_index = c_idx_not_exist;

  out_msg_offset = 0;
}/*}}}*/

inline void tcp_conn_s::clear(interpreter_thread_s &it)
{/*{{{*/
#ifdef UCL_WITH_OPENSSL
  if (ssl != nullptr)
  {
    SSL_free(ssl);
  }
#endif

  if (conn_fd != -1)
  {
    close(conn_fd);
  }

  if (event_callback != nullptr)
  {
    it.release_location_ptr((location_s *)event_callback);
  }

  if (message_callback != nullptr)
  {
    it.release_location_ptr((location_s *)message_callback);
  }

  if (user_data != nullptr)
  {
    it.release_location_ptr((location_s *)user_data);
  }

  // - release not send output messages  -
  while (out_msg_queue.used != 0)
  {
    it.release_location_ptr((location_s *)out_msg_queue.next());
  }

  clear();
  init_static();
}/*}}}*/

// -- tcp_conn_list_s --
@begin
inlines tcp_conn_list_s
@end

// -- tcp_server_s --
@begin
inlines tcp_server_s
@end

inline void tcp_server_s::init_static()
{/*{{{*/
#ifdef UCL_WITH_OPENSSL
  ssl_ctx = nullptr;
#endif
  server_fd = -1;
  event_callback = nullptr;
  message_callback = nullptr;
  user_data = nullptr;
}/*}}}*/

inline void tcp_server_s::clear(interpreter_thread_s &it)
{/*{{{*/
#ifdef UCL_WITH_OPENSSL
  if (ssl_ctx != nullptr)
  {
    SSL_CTX_free(ssl_ctx);
  }
#endif

  if (server_fd != -1)
  {
    close(server_fd);
  }

  // - release callbacks -
  if (event_callback != nullptr)
  {
    it.release_location_ptr((location_s *)event_callback);
  }

  if (message_callback != nullptr)
  {
    it.release_location_ptr((location_s *)message_callback);
  }

  // - release user data -
  if (user_data != nullptr)
  {
    it.release_location_ptr((location_s *)user_data);
  }

  // - release tcp connections -
  if (conn_list.first_idx != c_idx_not_exist)
  {
    unsigned cl_idx = conn_list.first_idx;
    do {
      conn_list[cl_idx].clear(it);

      cl_idx = conn_list.next_idx(cl_idx);
    } while(cl_idx != c_idx_not_exist);
  }

  clear();
  init_static();
}/*}}}*/

#endif

