
@begin
include "ucl_mqtt.h"
@end

// - mqtt global init object -
mqtt_c g_mqtt;

#define PACKET_PROP_CNT 43
const mqtt_prop_descr_s g_mqtt_packet_props[PACKET_PROP_CNT] =
{/*{{{*/
  {""                                 , 0x000000, 0xff, 0},
  {"Payload Format Indicator"         , 0x010008, 0x01, MQTT_DATA_TYPE_BYTE},
  {"Message Expiry Interval"          , 0x010008, 0x02, MQTT_DATA_TYPE_FOUR_BYTE_INTEGER},
  {"Content Type"                     , 0x010008, 0x03, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {"Response Topic"                   , 0x010008, 0x08, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {"Correlation Data"                 , 0x010008, 0x09, MQTT_DATA_TYPE_BINARY_DATA},
  {""                                 , 0x000000, 0xff, 0},
  {"Subscription Identifier"          , 0x000108, 0x0b, MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {"Session Expiry Interval"          , 0x004006, 0x11, MQTT_DATA_TYPE_FOUR_BYTE_INTEGER},
  {"Assigned Client Identifier"       , 0x000004, 0x12, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {"Server Keep Alive"                , 0x000004, 0x13, MQTT_DATA_TYPE_TWO_BYTE_INTEGER},
  {""                                 , 0x000000, 0xff, 0},
  {"Authentication Method"            , 0x008006, 0x15, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {"Authentication Data"              , 0x008006, 0x16, MQTT_DATA_TYPE_BINARY_DATA},
  {"Request Problem Information"      , 0x000002, 0x17, MQTT_DATA_TYPE_BYTE},
  {"Will Delay Interval"              , 0x010000, 0x18, MQTT_DATA_TYPE_FOUR_BYTE_INTEGER},
  {"Request Response Information"     , 0x000002, 0x19, MQTT_DATA_TYPE_BYTE},
  {"Response Information"             , 0x000004, 0x1a, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {""                                 , 0x000000, 0xff, 0},
  {"Server Reference"                 , 0x004004, 0x1c, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {""                                 , 0x000000, 0xff, 0},
  {""                                 , 0x000000, 0xff, 0},
  {"Reason String"                    , 0x00caf4, 0x1f, MQTT_DATA_TYPE_UTF_8_ENCODED_STRING},
  {""                                 , 0x000000, 0xff, 0},
  {"Receive Maximum"                  , 0x000006, 0x21, MQTT_DATA_TYPE_TWO_BYTE_INTEGER},
  {"Topic Alias Maximum"              , 0x000006, 0x22, MQTT_DATA_TYPE_TWO_BYTE_INTEGER},
  {"Topic Alias"                      , 0x000008, 0x23, MQTT_DATA_TYPE_TWO_BYTE_INTEGER},
  {"Maximum QoS"                      , 0x000004, 0x24, MQTT_DATA_TYPE_BYTE},
  {"Retain Available"                 , 0x000004, 0x25, MQTT_DATA_TYPE_BYTE},
  {"User Property"                    , 0x01cffe, 0x26, MQTT_DATA_TYPE_UTF_8_STRING_PAIR},
  {"Maximum Packet Size"              , 0x000006, 0x27, MQTT_DATA_TYPE_FOUR_BYTE_INTEGER},
  {"Wildcard Subscription Available"  , 0x000004, 0x28, MQTT_DATA_TYPE_BYTE},
  {"Subscription Identifier Available", 0x000004, 0x29, MQTT_DATA_TYPE_BYTE},
  {"Shared Subscription Available"    , 0x000004, 0x2a, MQTT_DATA_TYPE_BYTE},
};/*}}}*/

/*
 * methods of generated structures
 */

// -- usi_queue_s --
@begin
methods usi_queue_s
@end

// -- bc_array_queue_s --
@begin
methods bc_array_queue_s
@end

// -- mqtt_buffer_s --
@begin
methods mqtt_buffer_s
@end

// -- mqtt_prop_s --
@begin
methods mqtt_prop_s
@end

// -- mqtt_prop_array_s --
@begin
methods mqtt_prop_array_s
@end

// -- mqtt_prop_descr_s --
@begin
methods mqtt_prop_descr_s
@end

// -- mqtt_publish_s --
@begin
methods mqtt_publish_s
@end

// -- mqtt_publish_array_s --
@begin
methods mqtt_publish_array_s
@end

// -- mqtt_subscribe_s --
@begin
methods mqtt_subscribe_s
@end

// -- mqtt_subscribe_array_s --
@begin
methods mqtt_subscribe_array_s
@end

// -- mqtt_conn_s --
@begin
methods mqtt_conn_s
@end

int mqtt_conn_s::send_msg(interpreter_thread_s &it)
{/*{{{*/
  if (this->out_msg_queue.used != 0)
  {
    bc_array_s *message = out_msg_queue.data + out_msg_queue.begin;
    size_t write_cnt = message->used - this->out_msg_offset;

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
            return -1;
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
        return -1;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - whole message was send -
    if ((this->out_msg_offset += cnt) >= message->used)
    {
      // - remove message from queue -
      out_msg_queue.next();

      // - reset out message offset -
      this->out_msg_offset = 0;
    }
  }
  else
  {
    events = POLLIN | POLLPRI;
  }

  return 0;
}/*}}}*/

int mqtt_conn_s::recv_msg(interpreter_thread_s &it)
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
            return -1;
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
        return -1;
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
        return -1;
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
      return -1;
    }
#ifdef UCL_WITH_OPENSSL
  }
#endif

  uint32_t packet_off = 0;

  do {
    const char *packet = in_msg.data + packet_off;
    uint32_t buff_size = in_msg.used - packet_off;

    const char *remain;
    uint32_t remain_size;
    uint32_t packet_size;

    if (
      // - variable byte integer is complete -
      var_byte_dec(packet + 1,packet + buff_size,&remain,&remain_size) == 0 &&

      // - whole control packet was received -
      buff_size >= (packet_size = remain_size + (remain - packet)))
    {
      if (process_packet(it,packet[0],remain_size,remain))
      {
        return MQTT_CONN_PROCESS_PACKET_ERROR;
      }

      // - update packet offset -
      packet_off += packet_size;
    }
    else
    {
      // - remove processed packets from receive buffer -
      in_msg.tail(in_msg.used - packet_off);

      break;
    }
  } while(true);

  return 0;
}/*}}}*/

int mqtt_conn_s::process_properties(uint8_t a_pkt_type,uint32_t a_size,const char *a_data)
{/*{{{*/

  // - set properties -
  this->properties.set(a_size,a_data);

  // - reset property references -
  this->prop_refs.used = 0;

  if (a_size > 0)
  {
    // - process all properties -
    const char *data_begin = a_data;
    const char *data_end   = a_data + a_size;
    do {
      uint8_t code = a_data[0];

      const mqtt_prop_descr_s *prop_descr;
      if (code >= PACKET_PROP_CNT || (prop_descr = &g_mqtt_packet_props[code])->code != code
          || (prop_descr->control_pkt_mask & (1 << (a_pkt_type >> 4))) == 0)
      {
        return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
      }

      // - store property reference -
      this->prop_refs.push_blank();
      this->prop_refs.last().set(code,a_data - data_begin);

      switch (prop_descr->type)
      {
        case MQTT_DATA_TYPE_BYTE:
        {/*{{{*/
          if (data_end - a_data < 1 + 1)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 1 + 1;
        }/*}}}*/
        break;
        case MQTT_DATA_TYPE_TWO_BYTE_INTEGER:
        {/*{{{*/
          if (data_end - a_data < 1 + 2)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 1 + 2;
        }/*}}}*/
        break;
        case MQTT_DATA_TYPE_FOUR_BYTE_INTEGER:
        {/*{{{*/
          if (data_end - a_data < 1 + 4)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 1 + 4;
        }/*}}}*/
        break;
        case MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER:
        {/*{{{*/
          uint32_t value;
          if (var_byte_dec(a_data + 1,data_end,&a_data,&value))
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }
        }/*}}}*/
        break;
        case MQTT_DATA_TYPE_UTF_8_ENCODED_STRING:
        {/*{{{*/
          if (data_end - a_data < 1 + 2)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          uint16_t length = two_byte_dec(a_data + 1);

          if (data_end - a_data < 1 + 2 + length)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 1 + 2 + length;
        }/*}}}*/
        break;
        case MQTT_DATA_TYPE_UTF_8_STRING_PAIR:
        {/*{{{*/
          // - retrieve first string -
          if (data_end - a_data < 1 + 2)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          uint16_t length = two_byte_dec(a_data + 1);

          if (data_end - a_data < 1 + 2 + length)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 1 + 2 + length;

          // - retrieve second string -
          if (data_end - a_data < 2)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          length = two_byte_dec(a_data);

          if (data_end - a_data < 2 + length)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 2 + length;
        }/*}}}*/
        break;
        case MQTT_DATA_TYPE_BINARY_DATA:
        {/*{{{*/
          if (data_end - a_data < 1 + 2)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          uint16_t length = two_byte_dec(a_data + 1);

          if (data_end - a_data < 1 + 2 + length)
          {
            return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
          }

          a_data += 1 + 2 + length;
        }/*}}}*/
        break;
        default:
          return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
      }
    } while (a_data < data_end);
  }

  return 0;
}/*}}}*/

int mqtt_conn_s::process_packet(interpreter_thread_s &it,uint8_t pkt_type,uint32_t size,const char *data)
{/*{{{*/
  const char *data_end = data + size;

  switch (pkt_type >> 4)
  {
    case MQTT_PACKET_TYPE_CONNECT:
      return MQTT_UNSUPPORTED_CONTROL_PACKET_TYPE;
    case MQTT_PACKET_TYPE_CONNACK:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0 || // reserved
          size < 3)                 // minimal size
      {
        return MQTT_INVALID_CONNACK_PACKET;
      }

      if ((data[0] & 0xfe) != 0 ||  // connect acknowledge flags
          data[1] != 0x00)          // connect reason code
      {
        return MQTT_INVALID_CONNACK_PACKET;
      }

      data += 2;

      // - properties length -
      uint32_t props_length;
      if (var_byte_dec(data,data_end,&data,&props_length)
          || (uint32_t)(data_end - data) < props_length)
      {
        return MQTT_INVALID_CONNACK_PACKET;
      }

      if (process_properties(pkt_type,props_length,data))
      {
        return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
      }

      data += props_length;

      // - set mqtt_connected flag -
      this->mqtt_connected = true;

      // - resend all unacknowledged published packets -
      // - both publish and pubrel packets are resend -
      if (this->published.used != 0)
      {
        mqtt_publish_s *p_ptr = this->published.data;
        mqtt_publish_s *p_ptr_end = p_ptr + this->published.used;
        do {
          if (p_ptr->packet_id != 0)
          {
            if (p_ptr->released)
            {
              if (send_pubrel(p_ptr->packet_id,0x00))
              {
                return MQTT_SEND_PUBREL_ERROR;
              }
            }
            else
            {
              if (send_publish(p_ptr,1))
              {
                return MQTT_SEND_PUBLISH_ERROR;
              }
            }
          }
        } while(++p_ptr < p_ptr_end);
      }

      // - call event connected callback -
      callback_event = c_mqtt_EVENT_CONNECTED;
      MQTT_CALL_CALLBACK_DELEGATE(this,
        return MQTT_CONN_CALLBACK_ERROR;
      );
    } /*}}}*/
    break;
    case MQTT_PACKET_TYPE_PUBLISH:
    {/*{{{*/
      uint8_t dup = (pkt_type & 0x04) >> 3;
      uint8_t qos = (pkt_type & 0x06) >> 1;

      // - retrieve retained flag -
      this->retained = pkt_type & 0x01;

      uint32_t topic_length;
      if (data_end - data < 2
          || (uint32_t)(data_end - data) < 2 + (topic_length = two_byte_dec(data)))
      {
        return MQTT_INVALID_PUBLISH_PACKET;
      }

      this->topic.set(topic_length,data + 2);
      data += 2 + topic_length;

      this->packet_id = 0;
      if (qos > 0)
      {
        if (data_end - data < 2)
        {
          return MQTT_INVALID_PUBLISH_PACKET;
        }

        this->packet_id = two_byte_dec(data);
        data += 2;
      }

      // - properties -
      uint32_t props_length;
      if (var_byte_dec(data,data_end,&data,&props_length)
          || (uint32_t)(data_end - data) < props_length)
      {
        return MQTT_INVALID_PUBLISH_PACKET;
      }

      if (process_properties(pkt_type,props_length,data))
      {
        return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
      }

      data += props_length;

      uint32_t payload_length = data_end - data;
      this->payload.set(payload_length,data);

      switch (qos)
      {
        case 0:

          // - call event received callback -
          callback_event = c_mqtt_EVENT_RECEIVED;
          MQTT_CALL_CALLBACK_DELEGATE(this,
            return MQTT_CONN_CALLBACK_ERROR;
          );
          break;
        case 1:
        {
          // - call event received callback -
          callback_event = c_mqtt_EVENT_RECEIVED;
          MQTT_CALL_CALLBACK_DELEGATE(this,
            return MQTT_CONN_CALLBACK_ERROR;
          );

          // - send puback packet -
          bc_array_s buffer;
          buffer.init();
          buffer.reserve(4);

          buffer.push(0x40); // PUBACK
          buffer.push(0x02); // remaining length

          // - packet identifier -
          two_byte_enc(this->packet_id,&buffer);

          cassert(buffer.used == 4);

          if (schedule_message(&buffer))
          {
            buffer.clear();

            return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
          }

          buffer.clear();
        }
        break;
        case 2:
        {
          // - resize pubrec vector -
          while (this->packet_id >= this->pubrec.used)
          {
            this->pubrec.push(0);
          }

          // - not duplicate or not received yet -
          if (dup == 0 || !this->pubrec.data[this->packet_id])
          {
            // - call event received callback -
            callback_event = c_mqtt_EVENT_RECEIVED;
            MQTT_CALL_CALLBACK_DELEGATE(this,
              return MQTT_CONN_CALLBACK_ERROR;
            );

            // - mark packet as received -
            this->pubrec.data[this->packet_id] = 1;
          }

          // - send pubrec packet -
          bc_array_s buffer;
          buffer.init();
          buffer.reserve(4);

          buffer.push(0x50); // PUBREC
          buffer.push(0x02); // remaining length

          // - packet identifier -
          two_byte_enc(this->packet_id,&buffer);

          cassert(buffer.used == 4);

          if (schedule_message(&buffer))
          {
            buffer.clear();

            return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
          }

          buffer.clear();
        }
        break;
      }
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_PUBACK:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0 || // reserved
          size < 2)                 // minimal size
      {
        return MQTT_INVALID_PUBACK_PACKET;
      }

      // - packet identifier -
      this->packet_id = two_byte_dec(data);
      data += 2;

      // - optional reason code,defaults to 0x00 -
      if (data < data_end)
      {
        // - reason code -
        if ((uint8_t)(*data++) >= 0x80)
        {
          return MQTT_INVALID_PUBACK_PACKET;
        }

        // - optional properties -
        if (data < data_end)
        {
          // - properties -
          uint32_t props_length;
          if (var_byte_dec(data,data_end,&data,&props_length)
              || (uint32_t)(data_end - data) < props_length)
          {
            return MQTT_INVALID_PUBACK_PACKET;
          }

          if (process_properties(pkt_type,props_length,data))
          {
            return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
          }

          data += props_length;
        }
      }

      mqtt_publish_s *publish;

      // - unknown packet id or invalid qos -
      if (this->packet_id >= this->published.used
          || (publish = &this->published[this->packet_id])->packet_id != this->packet_id
          || publish->qos != 1)
      {
        return MQTT_INVALID_PUBACK_PACKET;
      }

      // - release packet id -
      this->packet_ids.insert(this->packet_id);

      // - reset publish data -
      publish->clear();
      publish->packet_id = 0;

      // - call event published callback -
      callback_event = c_mqtt_EVENT_PUBLISHED;
      MQTT_CALL_CALLBACK_DELEGATE(this,
        return MQTT_CONN_CALLBACK_ERROR;
      );
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_PUBREC:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0 || // reserved
          size < 2)                 // minimal size
      {
        return MQTT_INVALID_PUBREC_PACKET;
      }

      // - packet identifier -
      this->packet_id = two_byte_dec(data);
      data += 2;

      // - optional reason code,defaults to 0x00 -
      if (data < data_end)
      {
        // - reason code -
        if ((uint8_t)(*data++) >= 0x80)
        {
          return MQTT_INVALID_PUBREC_PACKET;
        }

        // - optional properties -
        if (data < data_end)
        {
          // - properties -
          uint32_t props_length;
          if (var_byte_dec(data,data_end,&data,&props_length)
              || (uint32_t)(data_end - data) < props_length)
          {
            return MQTT_INVALID_PUBREC_PACKET;
          }

          if (process_properties(pkt_type,props_length,data))
          {
            return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
          }

          data += props_length;
        }
      }

      // - default reason code: Packet identifier not found -
      uint8_t reason_code = 0x92;

      mqtt_publish_s *publish;

      // - packet id is ok and qos matches -
      if (this->packet_id < this->published.used
          && (publish = &this->published[this->packet_id])->packet_id == this->packet_id
          && publish->qos == 2)
      {
        // - reason code: Success -
        reason_code = 0x00;

        // - mark publish as released -
        publish->released = 1;

        // - release data buffers -
        publish->topic.clear();
        publish->payload.clear();
        publish->props.clear();
      }

      if (send_pubrel(this->packet_id,reason_code))
      {
        return MQTT_SEND_PUBREL_ERROR;
      }
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_PUBREL:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0x02 || // reserved
          size < 2)                    // minimal size
      {
        return MQTT_INVALID_PUBREL_PACKET;
      }

      // - packet identifier -
      this->packet_id = two_byte_dec(data);
      data += 2;

      // - optional reason code,defaults to 0x00 -
      if (data < data_end)
      {
        // - reason code -
        if ((uint8_t)(*data++) >= 0x80)
        {
          return MQTT_INVALID_PUBREL_PACKET;
        }

        // - optional properties -
        if (data < data_end)
        {
          // - properties -
          uint32_t props_length;
          if (var_byte_dec(data,data_end,&data,&props_length)
              || (uint32_t)(data_end - data) < props_length)
          {
            return MQTT_INVALID_PUBREL_PACKET;
          }

          if (process_properties(pkt_type,props_length,data))
          {
            return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
          }

          data += props_length;
        }
      }

      // - default reason code: Packet identifier not found -
      uint8_t reason_code = 0x92;

      // - packet id is ok -
      if (this->packet_id < this->pubrec.used && this->pubrec.data[this->packet_id])
      {
        // - reason code: Success -
        reason_code = 0x00;

        // - reset pubrec flag -
        this->pubrec.data[this->packet_id] = 0;
      }

      // - send pubcomp packet -
      uint32_t remaining_length = 2 + (reason_code == 0x00 ? 0 : 1);

      bc_array_s buffer;
      buffer.init();
      buffer.reserve(2 + remaining_length);

      buffer.push(0x70);  // PUBCOMP
      buffer.push(remaining_length);

      // - packet identifier -
      two_byte_enc(this->packet_id,&buffer);

      // - reason code -
      if (reason_code != 0x00)
      {
        buffer.push(reason_code);
      }

      cassert(buffer.used == 2 + remaining_length);

      if (schedule_message(&buffer))
      {
        buffer.clear();

        return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
      }

      buffer.clear();
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_PUBCOMP:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0 ||  // reserved
          size < 2)                  // minimal size
      {
        return MQTT_INVALID_PUBCOMP_PACKET;
      }

      // - packet identifier -
      this->packet_id = two_byte_dec(data);
      data += 2;

      // - optional reason code,defaults to 0x00 -
      if (data < data_end)
      {
        // - reason code -
        if ((uint8_t)(*data++) >= 0x80)
        {
          return MQTT_INVALID_PUBCOMP_PACKET;
        }

        // - optional properties -
        if (data < data_end)
        {
          // - properties -
          uint32_t props_length;
          if (var_byte_dec(data,data_end,&data,&props_length)
              || (uint32_t)(data_end - data) < props_length)
          {
            return MQTT_INVALID_PUBCOMP_PACKET;
          }

          if (process_properties(pkt_type,props_length,data))
          {
            return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
          }

          data += props_length;
        }
      }

      mqtt_publish_s *publish;

      // - unknown packet id or invalid qos -
      if (this->packet_id >= this->published.used
          || (publish = &this->published[this->packet_id])->packet_id != this->packet_id
          || publish->qos != 2)
      {
        return MQTT_INVALID_PUBCOMP_PACKET;
      }

      // - release packet id -
      this->packet_ids.insert(this->packet_id);

      // - reset publish data -
      publish->clear();
      publish->packet_id = 0;

      // - call event published callback -
      callback_event = c_mqtt_EVENT_PUBLISHED;
      MQTT_CALL_CALLBACK_DELEGATE(this,
        return MQTT_CONN_CALLBACK_ERROR;
      );
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_SUBSCRIBE:
      return MQTT_UNSUPPORTED_CONTROL_PACKET_TYPE;
    case MQTT_PACKET_TYPE_SUBACK:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0 || // reserved
          size < 2 + 1 + 1)         // minimal size
      {
        return MQTT_INVALID_SUBACK_PACKET;
      }

      // - packet identifier -
      this->packet_id = two_byte_dec(data);
      data += 2;

      mqtt_subscribe_s *subscribe;

      // - unknown packet id -
      if (this->packet_id >= this->subscribed.used
          || (subscribe = &this->subscribed[this->packet_id])->packet_id != this->packet_id)
      {
        return MQTT_INVALID_SUBACK_PACKET;
      }

      // - properties -
      uint32_t props_length;
      if (var_byte_dec(data,data_end,&data,&props_length)
          || (uint32_t)(data_end - data) < props_length)
      {
        return MQTT_INVALID_SUBACK_PACKET;
      }

      if (process_properties(pkt_type,props_length,data))
      {
        return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
      }

      data += props_length;

      // - check reason code count -
      if ((uint32_t)(data_end - data) != subscribe->filters.used)
      {
        return MQTT_INVALID_SUBACK_PACKET;
      }

      // - check reason codes -
      do {
        if (*data != subscribe->max_qos)
        {
          return MQTT_INVALID_SUBACK_PACKET;
        }
      } while (++data < data_end);

      this->packet_ids.insert(this->packet_id);

      // - reset subscribe data -
      subscribe->clear();
      subscribe->packet_id = 0;

      // - call event subscribed callback -
      callback_event = c_mqtt_EVENT_SUBSCRIBED;
      MQTT_CALL_CALLBACK_DELEGATE(this,
        return MQTT_CONN_CALLBACK_ERROR;
      );
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_UNSUBSCRIBE:
      return MQTT_UNSUPPORTED_CONTROL_PACKET_TYPE;
    case MQTT_PACKET_TYPE_UNSUBACK:
    {/*{{{*/
      if ((pkt_type & 0x0f) != 0 ||  // reserved
          size < 2 + 1 + 1)          // minimal size
      {
        return MQTT_INVALID_UNSUBACK_PACKET;
      }

      // - packet identifier -
      this->packet_id = two_byte_dec(data);
      data += 2;

      mqtt_subscribe_s *unsubscribe;

      // - unknown packet id -
      if (this->packet_id >= this->subscribed.used
          || (unsubscribe = &this->subscribed[this->packet_id])->packet_id != this->packet_id)
      {
        return MQTT_INVALID_UNSUBACK_PACKET;
      }

      // - properties -
      uint32_t props_length;
      if (var_byte_dec(data,data_end,&data,&props_length)
          || (uint32_t)(data_end - data) < props_length)
      {
        return MQTT_INVALID_UNSUBACK_PACKET;
      }

      if (process_properties(pkt_type,props_length,data))
      {
        return MQTT_CONN_PROCESS_PROPERTIES_ERROR;
      }

      data += props_length;

      // - check reason code count -
      if ((uint32_t)(data_end - data) != unsubscribe->filters.used)
      {
        return MQTT_INVALID_UNSUBACK_PACKET;
      }

      // - check reason codes -
      do {
        if ((uint8_t)(*data) >= 0x80)
        {
          return MQTT_INVALID_UNSUBACK_PACKET;
        }
      } while (++data < data_end);

      // - release packet id -
      this->packet_ids.insert(this->packet_id);

      // - reset subscribe data -
      unsubscribe->clear();
      unsubscribe->packet_id = 0;

      // - call event unsubscribed callback -
      callback_event = c_mqtt_EVENT_UNSUBSCRIBED;
      MQTT_CALL_CALLBACK_DELEGATE(this,
        return MQTT_CONN_CALLBACK_ERROR;
      );
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_PINGREQ:
      return MQTT_UNSUPPORTED_CONTROL_PACKET_TYPE;
    case MQTT_PACKET_TYPE_PINGRESP:
    {/*{{{*/

      // - call event pingresp callback -
      callback_event = c_mqtt_EVENT_PINGRESP;
      MQTT_CALL_CALLBACK_DELEGATE(this,
        return MQTT_CONN_CALLBACK_ERROR;
      );
    }/*}}}*/
    break;
    case MQTT_PACKET_TYPE_DISCONNECT:
    case MQTT_PACKET_TYPE_AUTH:
      return MQTT_UNSUPPORTED_CONTROL_PACKET_TYPE;
    default:
      return MQTT_UNKNOWN_CONTROL_PACKET_TYPE;
  }

  return 0;
}/*}}}*/

int mqtt_conn_s::var_byte_enc(uint32_t a_value,bc_array_s *a_trg)
{/*{{{*/
  if (a_value < MQTT_VAR_BYTE_INT_MAX_TWO)
  {
    if (a_value < MQTT_VAR_BYTE_INT_MAX_ONE)
    {
      a_trg->push(a_value);
    }
    else
    {
      a_trg->push(0x80 | (a_value & 0x7f));
      a_trg->push(a_value >> 7);
    }
  }
  else
  {
    if (a_value < MQTT_VAR_BYTE_INT_MAX_THREE)
    {
      a_trg->push(0x80 | (a_value & 0x7f));
      a_trg->push(0x80 | ((a_value >>= 7) & 0x7f));
      a_trg->push(a_value >> 7);
    }
    else
    {
      if (a_value >= MQTT_VAR_BYTE_INT_MAX_FOUR)
      {
        return MQTT_INVALID_VARIABLE_BYTE_INTEGER;
      }

      a_trg->push(0x80 | (a_value & 0x7f));
      a_trg->push(0x80 | ((a_value >>= 7) & 0x7f));
      a_trg->push(0x80 | ((a_value >>= 7) & 0x7f));
      a_trg->push(a_value >> 7);
    }
  }

  return 0;
}/*}}}*/

int mqtt_conn_s::var_byte_dec(const char *a_src,const char *a_src_end,
    const char **a_end,uint32_t *a_trg)
{/*{{{*/

  // - check buffer size -
  if (a_src >= a_src_end)
  {
    return 1;
  }

  uint32_t value = 0;
  uint32_t shift = 0;

  do {
    value += (*a_src & 0x7f) << shift;

    // - check buffer size and variable byte integer length -
    if (a_src >= a_src_end || (shift += 7) > 28)
    {
      return 1;
    }
  } while ((*a_src++ & 0x80) != 0);

  *a_end = a_src;
  *a_trg = value;

  return 0;
}/*}}}*/

int mqtt_conn_s::get_next_packet_id(uint16_t *a_packet_id)
{/*{{{*/
  if (this->packet_ids.used == 0)
  {
    if (this->next_packet_id >= UINT16_MAX)
    {
      return MQTT_CONN_OUT_OF_PACKET_IDENTIFIERS;
    }

    *a_packet_id = this->next_packet_id++;
  }
  else {
    *a_packet_id = this->packet_ids.next();
  }

  return 0;
}/*}}}*/

int mqtt_conn_s::send_connect()
{/*{{{*/

  // - send connect packet -
  uint32_t remaining_length = 10 + // variable header
    this->connect_props.used +     // properties
    2 + this->client_id.size - 1;  // client id

  if (var_byte_len(this->connect_props.used,&remaining_length))
  {
    return MQTT_INVALID_CONNECT_PACKET;
  }

  // - will will be registered by connection -
  if (this->will.topic.size > 1)
  {
    remaining_length += this->will.props.used + // will properties
      2 + this->will.topic.size - 1 +           // will topic length
      2 + this->will.payload.used;              // will payload length

    if (var_byte_len(this->will.props.used,&remaining_length))
    {
      return MQTT_INVALID_CONNECT_PACKET;
    }
  }

  // - user name will be send -
  if (this->user_name.size > 1)
  {
    remaining_length += 2 + this->user_name.size - 1;
  }

  // - password will be send -
  if (this->password.size > 1)
  {
    remaining_length += 2 + this->password.size - 1;
  }

  uint32_t buffer_size = 1 + remaining_length;

  if (var_byte_len(remaining_length,&buffer_size))
  {
    return MQTT_INVALID_CONNECT_PACKET;
  }

  bc_array_s buffer;
  buffer.init();
  buffer.reserve(buffer_size);

  buffer.push(0x10);  // CONNECT
  if (var_byte_enc(remaining_length,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_CONNECT_PACKET;
  }

  static const char HEADER[] = "\x00\x04MQTT\x05";
  buffer.append(7,HEADER);

  // - connect flags -
  buffer.push(
      (this->user_name.size > 1) << 7 |  // user name flag
      (this->password.size > 1) << 6 |   // password flag
      (this->will.topic.size > 1 && this->will.retain) << 5 |    // will retain
      (this->will.topic.size > 1 ? this->will.qos : 0x00) << 3 | // will qos (2 bits)
      (this->will.topic.size > 1) << 2 | // will flag
      1 << 1 |                           // clean start
      0 << 0);                           // reserved

  // - zero keep alive -
  two_byte_enc(0,&buffer);

  // - properties length -
  if (var_byte_enc(this->connect_props.used,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_CONNECT_PACKET;
  }

  // - properties -
  buffer.append(this->connect_props.used,this->connect_props.data);

  // - client id -
  two_byte_enc(this->client_id.size - 1,&buffer);
  buffer.append(this->client_id.size - 1,this->client_id.data);

  if (this->will.topic.size > 1)
  {
    // - will properties length -
    if (var_byte_enc(this->will.props.used,&buffer))
    {
      buffer.clear();

      return MQTT_INVALID_CONNECT_PACKET;
    }

    buffer.append(this->will.props.used,this->will.props.data);

    // - will topic -
    two_byte_enc(this->will.topic.size - 1,&buffer);
    buffer.append(this->will.topic.size - 1,this->will.topic.data);

    // - will payload -
    two_byte_enc(this->will.payload.used,&buffer);
    buffer.append(this->will.payload.used,this->will.payload.data);
  }

  // - user name -
  if (this->user_name.size > 1)
  {
    two_byte_enc(this->user_name.size - 1,&buffer);
    buffer.append(this->user_name.size - 1,this->user_name.data);
  }

  // - password -
  if (this->password.size > 1)
  {
    two_byte_enc(this->password.size - 1,&buffer);
    buffer.append(this->password.size - 1,this->password.data);
  }

  cassert(buffer.used == buffer_size);

  if (schedule_message(&buffer))
  {
    buffer.clear();

    return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
  }

  buffer.clear();

  return 0;
}/*}}}*/

int mqtt_conn_s::send_publish(mqtt_publish_s *a_publish,int a_dup)
{/*{{{*/
  uint32_t remaining_length = 2 + a_publish->topic.size - 1 + // topic length
    (a_publish->packet_id != 0 ? 2 : 0) +  // packet identifier length
    a_publish->props.used + // properties length
    a_publish->payload.used; // payload length

  if (var_byte_len(a_publish->props.used,&remaining_length))
  {
    return MQTT_INVALID_PUBLISH_PACKET;
  }

  uint32_t buffer_size = 1 + remaining_length;

  if (var_byte_len(remaining_length,&buffer_size))
  {
    return MQTT_INVALID_PUBLISH_PACKET;
  }

  bc_array_s buffer;
  buffer.init();
  buffer.reserve(buffer_size);

  buffer.push(0x30 |    // PUBLISH
      (a_dup ? 8 : 0) |             // dup
      a_publish->qos << 1 |         // qos level
      (a_publish->retain ? 1 : 0)); // retain

  if (var_byte_enc(remaining_length,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_PUBLISH_PACKET;
  }

  // - topic name -
  two_byte_enc(a_publish->topic.size - 1,&buffer);
  buffer.append(a_publish->topic.size - 1,a_publish->topic.data);

  if (a_publish->packet_id != 0) {
    // - packet identifier -
    two_byte_enc(a_publish->packet_id,&buffer);
  }

  // - properties length -
  if (var_byte_enc(a_publish->props.used,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_PUBLISH_PACKET;
  }

  // - properties -
  buffer.append(a_publish->props.used,a_publish->props.data);

  // - payload -
  buffer.append(a_publish->payload.used,a_publish->payload.data);

  cassert(buffer.used == buffer_size);

  if (schedule_message(&buffer))
  {
    buffer.clear();

    return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
  }

  buffer.clear();

  return 0;
}/*}}}*/

int mqtt_conn_s::send_pubrel(uint16_t a_packet_id,uint8_t a_reason_code)
{/*{{{*/
  uint32_t remaining_length = 2 + (a_reason_code != 0x00 ? 1 : 0);

  bc_array_s buffer;
  buffer.init();
  buffer.reserve(2 + remaining_length);

  buffer.push(0x62); // PUBREL
  buffer.push(remaining_length);

  // - packet identifier -
  two_byte_enc(a_packet_id,&buffer);

  // - reason code -
  if (a_reason_code != 0x00)
  {
    buffer.push(a_reason_code);
  }

  cassert(buffer.used == 2 + remaining_length);

  if (schedule_message(&buffer))
  {
    buffer.clear();

    return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
  }

  buffer.clear();

  return 0;
}/*}}}*/

int mqtt_conn_s::send_subscribe(mqtt_subscribe_s *a_subscribe)
{/*{{{*/
  uint32_t remaining_length = 2 + a_subscribe->props.used;

  if (var_byte_len(a_subscribe->props.used,&remaining_length))
  {
    return MQTT_INVALID_SUBSCRIBE_PACKET;
  }

  // - retrieve topic filters length -
  if (a_subscribe->filters.used != 0)
  {
    string_s *f_ptr = a_subscribe->filters.data;
    string_s *f_ptr_end = f_ptr + a_subscribe->filters.used;
    do {
      remaining_length += 2 + 1 + f_ptr->size - 1;
    } while(++f_ptr < f_ptr_end);
  }

  uint32_t buffer_size = 1 + remaining_length;

  if (var_byte_len(remaining_length,&buffer_size))
  {
    return MQTT_INVALID_SUBSCRIBE_PACKET;
  }

  bc_array_s buffer;
  buffer.init();
  buffer.reserve(buffer_size);

  buffer.push(0x82); // SUBSCRIBE
  if (var_byte_enc(remaining_length,&buffer))
  {
    return MQTT_INVALID_SUBSCRIBE_PACKET;
  }

  // - packet identifier -
  two_byte_enc(a_subscribe->packet_id,&buffer);

  // - properties length -
  if (var_byte_enc(a_subscribe->props.used,&buffer))
  {
    return MQTT_INVALID_SUBSCRIBE_PACKET;
  }

  // - properties -
  buffer.append(a_subscribe->props.used,a_subscribe->props.data);

  // - process topic filters -
  if (a_subscribe->filters.used != 0)
  {
    string_s *f_ptr = a_subscribe->filters.data;
    string_s *f_ptr_end = f_ptr + a_subscribe->filters.used;
    do {
      // - topic filter -
      two_byte_enc(f_ptr->size - 1,&buffer);
      buffer.append(f_ptr->size - 1,f_ptr->data);

      // - subscription options -
      buffer.push(
          0 << 4 |  // retain handling (send retained messages at the time of the subscribe)
          1 << 3 |  // retain as published
          0 << 2 |  // no local (off)
          a_subscribe->max_qos);
    } while(++f_ptr < f_ptr_end);
  }

  cassert(buffer.used == buffer_size);

  if (schedule_message(&buffer))
  {
    buffer.clear();

    return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
  }

  buffer.clear();

  return 0;
}/*}}}*/

int mqtt_conn_s::send_unsubscribe(mqtt_subscribe_s *a_subscribe)
{/*{{{*/
  uint32_t remaining_length = 2 + a_subscribe->props.used;

  if (var_byte_len(a_subscribe->props.used,&remaining_length))
  {
    return MQTT_INVALID_UNSUBSCRIBE_PACKET;
  }

  // Retrieve topic filters length
  if (a_subscribe->filters.used != 0)
  {
    string_s *f_ptr = a_subscribe->filters.data;
    string_s *f_ptr_end = f_ptr + a_subscribe->filters.used;
    do {
      remaining_length += 2 + f_ptr->size - 1;
    } while(++f_ptr < f_ptr_end);
  }

  uint32_t buffer_size = 1 + remaining_length;

  if (var_byte_len(remaining_length,&buffer_size))
  {
    return MQTT_INVALID_UNSUBSCRIBE_PACKET;
  }

  bc_array_s buffer;
  buffer.init();
  buffer.reserve(buffer_size);

  buffer.push(0xa2); // UNSUBSCRIBE

  if (var_byte_enc(remaining_length,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_UNSUBSCRIBE_PACKET;
  }

  // Packet identifier
  two_byte_enc(a_subscribe->packet_id,&buffer);

  // Properties length
  if (var_byte_enc(a_subscribe->props.used,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_UNSUBSCRIBE_PACKET;
  }

  // Properties
  buffer.append(a_subscribe->props.used,a_subscribe->props.data);

  // Process topic filters
  if (a_subscribe->filters.used != 0)
  {
    string_s *f_ptr = a_subscribe->filters.data;
    string_s *f_ptr_end = f_ptr + a_subscribe->filters.used;
    do {
      // Topic filter
      two_byte_enc(f_ptr->size - 1,&buffer);
      buffer.append(f_ptr->size - 1,f_ptr->data);
    } while(++f_ptr < f_ptr_end);
  }

  cassert(buffer.used == buffer_size);

  if (schedule_message(&buffer))
  {
    buffer.clear();

    return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
  }

  buffer.clear();

  return 0;
}/*}}}*/

int mqtt_conn_s::publish(string_s *a_topic,bc_array_s *a_payload,
    bc_array_s *a_props,uint8_t a_qos, int a_retain,uint16_t *a_packet_id)
{/*{{{*/
  if (this->mqtt_disconnecting || a_topic->size - 1 > UINT16_MAX || a_qos >= 3)
  {
    return MQTT_INVALID_PUBLISH_REQUEST;
  }

  uint16_t packet_id = 0;

  if (a_qos > 0)
  {
    if (get_next_packet_id(&packet_id))
    {
      return MQTT_CONN_NEXT_PACKET_ID_ERROR;
    }

    while (packet_id >= this->published.used)
    {
      this->published.push_blank();
      this->published.last().packet_id = 0;
    }

    mqtt_publish_s &publish = this->published[packet_id];

    publish.packet_id = packet_id;
    publish.released = 0;
    publish.topic.swap(*a_topic);
    publish.payload.swap(*a_payload);
    publish.qos = a_qos;
    publish.retain = a_retain;
    publish.props.swap(*a_props);

    if (this->mqtt_connected)
    {
      if (send_publish(&this->published[packet_id],0))
      {
        return MQTT_SEND_PUBLISH_ERROR;
      }
    }
  }
  else
  {
    if (this->mqtt_connected)
    {
      mqtt_publish_s publish;
      publish.init();

      publish.packet_id = packet_id;
      publish.released = 0;
      publish.topic.swap(*a_topic);
      publish.payload.swap(*a_payload);
      publish.qos = a_qos;
      publish.retain = a_retain;
      publish.props.swap(*a_props);

      if (send_publish(&publish,0))
      {
        publish.clear();

        return MQTT_SEND_PUBLISH_ERROR;
      }

      publish.clear();
    }
  }

  *a_packet_id = packet_id;

  return 0;
}/*}}}*/

int mqtt_conn_s::subscribe(string_array_s *a_filters,bc_array_s *a_props,
    uint8_t a_max_qos,uint16_t *a_packet_id)
{/*{{{*/
  if (this->mqtt_disconnecting || a_filters->used == 0 || a_max_qos >= 3)
  {
    return MQTT_INVALID_SUBSCRIBE_REQUEST;
  }

  uint16_t packet_id;
  if (get_next_packet_id(&packet_id))
  {
    return MQTT_CONN_NEXT_PACKET_ID_ERROR;
  }

  while (packet_id >= this->subscribed.used)
  {
    this->subscribed.push_blank();
    this->subscribed.last().packet_id = 0;
  }

  mqtt_subscribe_s &subscribe = this->subscribed[packet_id];
  subscribe.packet_id = packet_id;
  subscribe.filters.swap(*a_filters);
  subscribe.max_qos = a_max_qos;
  subscribe.props.swap(*a_props);

  if (send_subscribe(&subscribe))
  {
    return MQTT_SEND_SUBSCRIBE_ERROR;
  }

  *a_packet_id = packet_id;

  return 0;
}/*}}}*/

int mqtt_conn_s::unsubscribe( string_array_s *a_filters,bc_array_s *a_props,
    uint16_t *a_packet_id)
{/*{{{*/
  if (this->mqtt_disconnecting || a_filters->used == 0)
  {
    return MQTT_INVALID_UNSUBSCRIBE_REQUEST;
  }

  uint16_t packet_id;
  if (get_next_packet_id(&packet_id))
  {
    return MQTT_CONN_NEXT_PACKET_ID_ERROR;
  }

  while (packet_id >= this->subscribed.used)
  {
    this->subscribed.push_blank();
    this->subscribed.last().packet_id = 0;
  }

  mqtt_subscribe_s &subscribe = this->subscribed[packet_id];
  subscribe.packet_id = packet_id;
  subscribe.filters.swap(*a_filters);
  subscribe.max_qos = 0;
  subscribe.props.swap(*a_props);

  if (send_unsubscribe(&subscribe))
  {
    return MQTT_SEND_UNSUBSCRIBE_ERROR;
  }

  *a_packet_id = packet_id;

  return 0;
}/*}}}*/

