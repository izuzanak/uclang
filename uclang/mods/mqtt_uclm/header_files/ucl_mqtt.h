
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
  c_mqtt_EVENT_CONNECTED,
  c_mqtt_EVENT_DISCONNECTED,
  c_mqtt_EVENT_DROPPED,

  c_mqtt_EVENT_PUBLISHED,
  c_mqtt_EVENT_SUBSCRIBED,
  c_mqtt_EVENT_UNSUBSCRIBED,
  c_mqtt_EVENT_RECEIVED,
};

#define MQTT_VAR_BYTE_INT_MAX_ONE   0x80
#define MQTT_VAR_BYTE_INT_MAX_TWO   0x4000
#define MQTT_VAR_BYTE_INT_MAX_THREE 0x200000
#define MQTT_VAR_BYTE_INT_MAX_FOUR  0x10000000

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

// -- usi_queue_s --
@begin
queue<usi> usi_queue_s;
@end

// -- mqtt_buffer_s --
@begin
struct
<
ui:size
cbc_pointer:data
>
mqtt_buffer_s;
@end

// -- mqtt_prop_s --
@begin
struct
<
uc:code
ui:offset
>
mqtt_prop_s;
@end

// -- mqtt_prop_array_s --
@begin
array<mqtt_prop_s> mqtt_prop_array_s;
@end

// -- mqtt_prop_descr_s --
@begin
struct
<
cbc_pointer:descr
ui:control_pkt_mask
uc:code
uc:type
>
mqtt_prop_descr_s;
@end

// -- mqtt_publish_s --
@begin
struct
<
usi:packet_id
bi:released
string_s:topic
bc_array_s:payload
uc:qos
bi:retain
bc_array_s:props
>
mqtt_publish_s;
@end

// -- mqtt_publish_array_s --
@begin
array<mqtt_publish_s> mqtt_publish_array_s;
@end

// -- mqtt_subscribe_s --
@begin
struct
<
usi:packet_id
string_array_s:filters
uc:max_qos
bc_array_s:props
>
mqtt_subscribe_s;
@end

// -- mqtt_subscribe_array_s --
@begin
array<mqtt_subscribe_s> mqtt_subscribe_array_s;
@end

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

usi:next_packet_id
usi_queue_s:packet_ids
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

  static inline void two_byte_enc(uint16_t a_value,bc_array_s *a_trg);
  static inline uint16_t two_byte_dec(const char *a_src);
  static inline void four_byte_enc(uint32_t a_value,bc_array_s *a_trg);
  static inline uint32_t four_byte_dec(const char *a_src);
  static inline int var_byte_len(uint32_t a_value,uint32_t *a_trg);
  static int var_byte_enc(uint32_t a_value,bc_array_s *a_trg);
  static int var_byte_dec(const char *a_src,const char *a_src_end,const char **a_end,
      uint32_t *a_trg);
  int get_next_packet_id(uint16_t *a_packet_id);

  inline void init_static();
  inline void clear(interpreter_thread_s &it);
}

mqtt_conn_s;
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

// -- usi_queue_s --
@begin
inlines usi_queue_s
@end

// -- mqtt_buffer_s --
@begin
inlines mqtt_buffer_s
@end

// -- mqtt_prop_s --
@begin
inlines mqtt_prop_s
@end

// -- mqtt_prop_array_s --
@begin
inlines mqtt_prop_array_s
@end

// -- mqtt_prop_descr_s --
@begin
inlines mqtt_prop_descr_s
@end

// -- mqtt_publish_s --
@begin
inlines mqtt_publish_s
@end

// -- mqtt_publish_array_s --
@begin
inlines mqtt_publish_array_s
@end

// -- mqtt_subscribe_s --
@begin
inlines mqtt_subscribe_s
@end

// -- mqtt_subscribe_array_s --
@begin
inlines mqtt_subscribe_array_s
@end

// -- mqtt_conn_s --
@begin
inlines mqtt_conn_s
@end

inline void mqtt_conn_s::two_byte_enc(uint16_t a_value,bc_array_s *a_trg)
{/*{{{*/
  uint16_t net_value = htons(a_value);
  a_trg->append(2,(char *)&net_value);
}/*}}}*/

inline uint16_t mqtt_conn_s::two_byte_dec(const char *a_src)
{/*{{{*/
  uint16_t net_value;
  memcpy(&net_value,a_src,2);
  return ntohs(net_value);
}/*}}}*/

inline void mqtt_conn_s::four_byte_enc(uint32_t a_value,bc_array_s *a_trg)
{/*{{{*/
  uint32_t net_value = htonl(a_value);
  a_trg->append(4,(char *)&net_value);
}/*}}}*/

inline uint32_t mqtt_conn_s::four_byte_dec(const char *a_src)
{/*{{{*/
  uint32_t net_value;
  memcpy(&net_value,a_src,4);
  return ntohl(net_value);
}/*}}}*/

inline int mqtt_conn_s::var_byte_len(uint32_t a_value,uint32_t *a_trg)
{/*{{{*/
  if (a_value >= MQTT_VAR_BYTE_INT_MAX_FOUR)
  {
    return -1;
  }

  *a_trg += a_value < MQTT_VAR_BYTE_INT_MAX_TWO ?
    (a_value < MQTT_VAR_BYTE_INT_MAX_ONE ? 1 : 2)
    : (a_value < MQTT_VAR_BYTE_INT_MAX_THREE ? 3 : 4);

  return 0;
}/*}}}*/

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

  next_packet_id = 1;
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

#endif

