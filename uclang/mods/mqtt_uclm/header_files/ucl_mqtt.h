
#ifndef __UCL_MQTT_H
#define __UCL_MQTT_H

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

extern unsigned c_bi_class_mqtt_client;

// - mqtt event types -
enum
{
  c_mqtt_EVENT_ERROR = -1,
  c_mqtt_EVENT_ACCEPTED,
  c_mqtt_EVENT_CONNECTED,
  c_mqtt_EVENT_DROPPED,
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

#define MQTT_CALL_CALLBACK_DELEGATE(NAME,SOURCE_POS,PARAM_CODE,ERROR_CODE) \
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
 * definition of class mqtt_c
 */

class mqtt_c
{
  public:
  inline mqtt_c();
  inline ~mqtt_c();
};

/*
 * definition of generated structures
 */

// -- mqtt_conn_s --
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
ui:in_msg_length

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

mqtt_conn_s;
@end

// -- mqtt_conn_list_s --
@begin
safe_list<mqtt_conn_s> mqtt_conn_list_s;
@end

/*
 * inline methods of class mqtt_c
 */

inline mqtt_c::mqtt_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"mqtt_init()\n"););

#ifdef UCL_WITH_OPENSSL
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();
#endif
}/*}}}*/

inline mqtt_c::~mqtt_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"mqtt_exit()\n"););

#ifdef UCL_WITH_OPENSSL
  EVP_cleanup();
#endif
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- mqtt_conn_s --
@begin
inlines mqtt_conn_s
@end

inline void mqtt_conn_s::init_static()
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

  in_msg_length = 0;
  out_msg_offset = 0;
}/*}}}*/

inline void mqtt_conn_s::clear(interpreter_thread_s &it)
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

// -- mqtt_conn_list_s --
@begin
inlines mqtt_conn_list_s
@end

#endif

