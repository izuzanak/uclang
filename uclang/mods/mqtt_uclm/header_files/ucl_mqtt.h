
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

// - error codes -
#define MQTT_CONN_CALLBACK_ERROR 1
#define MQTT_CONN_SCHEDULE_MESSAGE_ERROR 2
#define MQTT_CONN_PROCESS_PACKET_ERROR 3
#define MQTT_CONN_PROCESS_PROPERTIES_ERROR 4
#define MQTT_CONN_OUT_OF_PACKET_IDENTIFIERS 5
#define MQTT_CONN_NEXT_PACKET_ID_ERROR 6
#define MQTT_INVALID_VARIABLE_BYTE_INTEGER 7
#define MQTT_UNSUPPORTED_CONTROL_PACKET_TYPE 8
#define MQTT_UNKNOWN_CONTROL_PACKET_TYPE 9
#define MQTT_INVALID_CONTROL_PACKET_PROPERTY 10
#define MQTT_INVALID_CONNECT_PACKET 11
#define MQTT_INVALID_CONNACK_PACKET 12
#define MQTT_INVALID_PUBLISH_PACKET 13
#define MQTT_INVALID_PUBACK_PACKET 14
#define MQTT_INVALID_PUBREC_PACKET 15
#define MQTT_INVALID_PUBREL_PACKET 16
#define MQTT_INVALID_PUBCOMP_PACKET 17
#define MQTT_INVALID_SUBSCRIBE_PACKET 18
#define MQTT_INVALID_SUBACK_PACKET 19
#define MQTT_INVALID_UNSUBSCRIBE_PACKET 20
#define MQTT_INVALID_UNSUBACK_PACKET 21
#define MQTT_SEND_PUBLISH_ERROR 22
#define MQTT_SEND_PUBREL_ERROR 23
#define MQTT_SEND_SUBSCRIBE_ERROR 24
#define MQTT_SEND_UNSUBSCRIBE_ERROR 25
#define MQTT_INVALID_PUBLISH_REQUEST 26
#define MQTT_INVALID_SUBSCRIBE_REQUEST 27
#define MQTT_INVALID_UNSUBSCRIBE_REQUEST 28

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

#define MQTT_CALL_CALLBACK_DELEGATE(NAME,ERROR_CODE) \
{/*{{{*/\
  delegate_s *delegate_ptr = (delegate_s *)((location_s *)NAME->event_callback_loc)->v_data_ptr;\
\
  /* - call delegate method - */\
  location_s *trg_location = nullptr;\
  BIC_CALL_DELEGATE(it,delegate_ptr,(pointer *)&NAME->conn_location,1,trg_location,NAME->source_pos,\
    NAME->callback_event = 0;\
\
    ERROR_CODE;\
  );\
  NAME->callback_event = 0;\
\
  it.release_location_ptr(trg_location);\
}/*}}}*/

// - mqtt callback event types -
enum
{/*{{{*/
  c_mqtt_EVENT_ERROR = 1,
  c_mqtt_EVENT_CONNECTED,
  c_mqtt_EVENT_DISCONNECTED,
  c_mqtt_EVENT_DROPPED,

  c_mqtt_EVENT_PUBLISHED,
  c_mqtt_EVENT_SUBSCRIBED,
  c_mqtt_EVENT_UNSUBSCRIBED,
  c_mqtt_EVENT_RECEIVED,
  c_mqtt_EVENT_PINGRESP,
};/*}}}*/

// - property identifiers -
enum
{/*{{{*/
  PROP_PAYLOAD_FORMAT_INDICATOR          = 0x01,
  PROP_MESSAGE_EXPIRY_INTERVAL           = 0x02,
  PROP_CONTENT_TYPE                      = 0x03,
  PROP_RESPONSE_TOPIC                    = 0x08,
  PROP_CORRELATION_DATA                  = 0x09,
  PROP_SUBSCRIPTION_IDENTIFIER           = 0x0b,
  PROP_SESSION_EXPIRY_INTERVAL           = 0x11,
  PROP_ASSIGNED_CLIENT_IDENTIFIER        = 0x12,
  PROP_SERVER_KEEP_ALIVE                 = 0x13,
  PROP_AUTHENTICATION_METHOD             = 0x15,
  PROP_AUTHENTICATION_DATA               = 0x16,
  PROP_REQUEST_PROBLEM_INFORMATION       = 0x17,
  PROP_WILL_DELAY_INTERVAL               = 0x18,
  PROP_REQUEST_RESPONSE_INFORMATION      = 0x19,
  PROP_RESPONSE_INFORMATION              = 0x1a,
  PROP_SERVER_REFERENCE                  = 0x1c,
  PROP_REASON_STRING                     = 0x1f,
  PROP_RECEIVE_MAXIMUM                   = 0x21,
  PROP_TOPIC_ALIAS_MAXIMUM               = 0x22,
  PROP_TOPIC_ALIAS                       = 0x23,
  PROP_MAXIMUM_QOS                       = 0x24,
  PROP_RETAIN_AVAILABLE                  = 0x25,
  PROP_USER_PROPERTY                     = 0x26,
  PROP_MAXIMUM_PACKET_SIZE               = 0x27,
  PROP_WILDCARD_SUBSCRIPTION_AVAILABLE   = 0x28,
  PROP_SUBSCRIPTION_IDENTIFIER_AVAILABLE = 0x29,
  PROP_SHARED_SUBSCRIPTION_AVAILABLE     = 0x2a,
};/*}}}*/

// - type of control packet -
enum
{/*{{{*/
  MQTT_PACKET_TYPE_CONNECT     = 1,
  MQTT_PACKET_TYPE_CONNACK     = 2,
  MQTT_PACKET_TYPE_PUBLISH     = 3,
  MQTT_PACKET_TYPE_PUBACK      = 4,
  MQTT_PACKET_TYPE_PUBREC      = 5,
  MQTT_PACKET_TYPE_PUBREL      = 6,
  MQTT_PACKET_TYPE_PUBCOMP     = 7,
  MQTT_PACKET_TYPE_SUBSCRIBE   = 8,
  MQTT_PACKET_TYPE_SUBACK      = 9,
  MQTT_PACKET_TYPE_UNSUBSCRIBE = 10,
  MQTT_PACKET_TYPE_UNSUBACK    = 11,
  MQTT_PACKET_TYPE_PINGREQ     = 12,
  MQTT_PACKET_TYPE_PINGRESP    = 13,
  MQTT_PACKET_TYPE_DISCONNECT  = 14,
  MQTT_PACKET_TYPE_AUTH        = 15,
};/*}}}*/

// - type of control packet data -
enum
{/*{{{*/
  MQTT_DATA_TYPE_BYTE = 0,
  MQTT_DATA_TYPE_TWO_BYTE_INTEGER,
  MQTT_DATA_TYPE_FOUR_BYTE_INTEGER,
  MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER,
  MQTT_DATA_TYPE_UTF_8_ENCODED_STRING,
  MQTT_DATA_TYPE_UTF_8_STRING_PAIR,
  MQTT_DATA_TYPE_BINARY_DATA,
};/*}}}*/

/*
 * definition of class mqtt_c
 */

class mqtt_c
{
  public:
  inline mqtt_c() noexcept;
  inline ~mqtt_c();
};

/*
 * definition of generated structures
 */

// -- usi_queue_s --
@begin
queue<usi> usi_queue_s;
@end

// -- bc_array_queue_s --
@begin
queue<bc_array_s> bc_array_queue_s;
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

const unsigned c_packet_prop_cnt = 43;
extern const mqtt_prop_descr_s g_mqtt_packet_props[c_packet_prop_cnt];

// -- mqtt_publish_s --
@begin
struct
<
usi:packet_id
bi:released
pointer:topic_loc
pointer:payload_loc
uc:qos
bi:retain
pointer:props_loc
>

additions
{
  inline void init_locations();
  inline void release_locations(interpreter_thread_s &it);
}

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
pointer:filters_loc
uc:max_qos
pointer:props_loc
>

additions
{
  inline void init_locations();
  inline void release_locations(interpreter_thread_s &it);
}

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

bool:tcp_connecting
bool:tcp_connected

pointer:event_callback_loc
pointer:user_data_loc

pointer:conn_location
ui:source_pos

bc_array_s:in_msg

bc_array_queue_s:out_msg_queue
ui:out_msg_offset

pointer:connect_props_loc
mqtt_publish_s:will
string_s:user_name
string_s:password
string_s:client_id

usi:next_packet_id
usi_queue_s:packet_ids

mqtt_publish_array_s:published
mqtt_subscribe_array_s:subscribed
bc_array_s:pubrec

$// - callback parameters -
ui:callback_event
usi:packet_id
mqtt_buffer_s:topic
mqtt_buffer_s:payload
bi:retained
mqtt_buffer_s:properties

mqtt_prop_array_s:prop_refs

bool:mqtt_connected
bool:mqtt_disconnecting
>

additions
{
#ifdef UCL_WITH_OPENSSL
  SSL *ssl;

  ui ssl_action;
  ui ssl_events;
#endif

  int send_msg(interpreter_thread_s &it);
  int recv_msg(interpreter_thread_s &it);

  int process_properties(uint8_t a_pkt_type,uint32_t a_size,const char *a_data);
  int process_packet(interpreter_thread_s &it,uint8_t pkt_type,uint32_t size,const char *data);

  inline int schedule_message(bc_array_s *a_message);

  static inline void two_byte_enc(uint16_t a_value,bc_array_s *a_trg);
  static inline uint16_t two_byte_dec(const char *a_src);
  static inline void four_byte_enc(uint32_t a_value,bc_array_s *a_trg);
  static inline uint32_t four_byte_dec(const char *a_src);
  static inline int var_byte_len(uint32_t a_value,uint32_t *a_trg);
  static int var_byte_enc(uint32_t a_value,bc_array_s *a_trg);
  static int var_byte_dec(const char *a_src,const char *a_src_end,const char **a_end,
      uint32_t *a_trg);
  int get_next_packet_id(uint16_t *a_packet_id);

  int send_connect();
  int send_publish(mqtt_publish_s *a_publish,int a_dup);
  int send_pubrel(uint16_t a_packet_id,uint8_t a_reason_code);
  int send_subscribe(mqtt_subscribe_s *a_subscribe);
  int send_unsubscribe(mqtt_subscribe_s *a_subscribe);

  int publish(location_s *a_topic,location_s *a_payload,
      location_s *a_props,uint8_t a_qos, int a_retain,uint16_t *a_packet_id);
  int subscribe(location_s *a_filters,location_s *a_props,
      uint8_t a_max_qos,uint16_t *a_packet_id);
  int unsubscribe(location_s *a_filters,location_s *a_props,
      uint16_t *a_packet_id);
  int disconnect();
  int pingreq();

  inline void init_static();
  inline void clear(interpreter_thread_s &it);
}

mqtt_conn_s;
@end

/*
 * inline methods of class mqtt_c
 */

inline mqtt_c::mqtt_c() noexcept
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

// -- bc_array_queue_s --
@begin
inlines bc_array_queue_s
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

inline void mqtt_publish_s::init_locations()
{/*{{{*/
  topic_loc = nullptr;
  payload_loc = nullptr;
  props_loc = nullptr;
}/*}}}*/

inline void mqtt_publish_s::release_locations(interpreter_thread_s &it)
{/*{{{*/
  if (topic_loc != nullptr)
  {
    it.release_location_ptr((location_s *)topic_loc);
  }

  if (payload_loc != nullptr)
  {
    it.release_location_ptr((location_s *)payload_loc);
  }

  if (props_loc != nullptr)
  {
    it.release_location_ptr((location_s *)props_loc);
  }

  init_locations();
}/*}}}*/

// -- mqtt_publish_array_s --
@begin
inlines mqtt_publish_array_s
@end

// -- mqtt_subscribe_s --
@begin
inlines mqtt_subscribe_s
@end

inline void mqtt_subscribe_s::init_locations()
{/*{{{*/
  filters_loc = nullptr;
  props_loc = nullptr;
}/*}}}*/

inline void mqtt_subscribe_s::release_locations(interpreter_thread_s &it)
{/*{{{*/
  if (filters_loc != nullptr)
  {
    it.release_location_ptr((location_s *)filters_loc);
  }

  if (props_loc != nullptr)
  {
    it.release_location_ptr((location_s *)props_loc);
  }

  init_locations();
}/*}}}*/

// -- mqtt_subscribe_array_s --
@begin
inlines mqtt_subscribe_array_s
@end

// -- mqtt_conn_s --
@begin
inlines mqtt_conn_s
@end

inline int mqtt_conn_s::schedule_message(bc_array_s *a_message)
{/*{{{*/
  out_msg_queue.insert_blank();
  out_msg_queue.last().swap(*a_message);

  // - update connection events -
  events = POLLIN | POLLPRI | POLLOUT;

  return 0;
}/*}}}*/

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
    return MQTT_INVALID_VARIABLE_BYTE_INTEGER;
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

  tcp_connecting = false;
  tcp_connected = false;

  event_callback_loc = nullptr;
  user_data_loc = nullptr;
  connect_props_loc = nullptr;

  out_msg_offset = 0;

  will.init_locations();

  next_packet_id = 1;

  callback_event = 0;
  packet_id = 0;

  mqtt_connected = false;
  mqtt_disconnecting = false;
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

  if (event_callback_loc != nullptr)
  {
    it.release_location_ptr((location_s *)event_callback_loc);
  }

  if (user_data_loc != nullptr)
  {
    it.release_location_ptr((location_s *)user_data_loc);
  }

  if (connect_props_loc != nullptr)
  {
    it.release_location_ptr((location_s *)connect_props_loc);
  }

  will.release_locations(it);

  // - release published locations -
  if (published.used != 0)
  {
    mqtt_publish_s *mp_ptr = published.data;
    mqtt_publish_s *mp_ptr_end = mp_ptr + published.used;
    do {
      mp_ptr->release_locations(it);
    } while(++mp_ptr < mp_ptr_end);
  }

  // - release subscribed locations -
  if (subscribed.used != 0)
  {
    mqtt_subscribe_s *ms_ptr = subscribed.data;
    mqtt_subscribe_s *ms_ptr_end = ms_ptr + subscribed.used;
    do {
      ms_ptr->release_locations(it);
    } while(++ms_ptr < ms_ptr_end);
  }

  clear();
  init_static();
}/*}}}*/

#endif

