
@begin
include "ucl_mqtt.h"
@end

// - mqtt global init object -
mqtt_c g_mqtt;

const mqtt_prop_descr_s g_mqtt_packet_props[c_packet_prop_cnt] =
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
  if (out_msg_queue.used != 0)
  {
    bc_array_s *message = out_msg_queue.data + out_msg_queue.begin;
    size_t write_cnt = message->used - out_msg_offset;

    // - limit maximal write size -
    if (write_cnt > 4096)
    {
      write_cnt = 4096;
    }

    ssize_t cnt;

#ifdef UCL_WITH_OPENSSL
    if (ssl != nullptr)
    {
      cnt = SSL_write(ssl,message->data + out_msg_offset,write_cnt);

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
      cnt = write(conn_fd,message->data + out_msg_offset,write_cnt);

      // - ERROR -
      if (cnt == -1)
      {
        return -1;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - whole message was send -
    if ((out_msg_offset += cnt) >= message->used)
    {
      // - remove message from queue -
      out_msg_queue.next();

      // - reset out message offset -
      out_msg_offset = 0;
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
  properties.set(a_size,a_data);

  // - reset property references -
  prop_refs.used = 0;

  if (a_size > 0)
  {
    // - process all properties -
    const char *data_begin = a_data;
    const char *data_end   = a_data + a_size;
    do {
      uint8_t code = a_data[0];

      const mqtt_prop_descr_s *prop_descr;
      if (code >= c_packet_prop_cnt || (prop_descr = &g_mqtt_packet_props[code])->code != code
          || (prop_descr->control_pkt_mask & (1 << (a_pkt_type >> 4))) == 0)
      {
        return MQTT_INVALID_CONTROL_PACKET_PROPERTY;
      }

      // - store property reference -
      prop_refs.push_blank();
      prop_refs.last().set(code,a_data - data_begin);

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
      mqtt_connected = true;

      // - resend all unacknowledged published packets -
      // - both publish and pubrel packets are resend -
      if (published.used != 0)
      {
        mqtt_publish_s *p_ptr = published.data;
        mqtt_publish_s *p_ptr_end = p_ptr + published.used;
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
      retained = pkt_type & 0x01;

      uint32_t topic_length;
      if (data_end - data < 2
          || (uint32_t)(data_end - data) < 2 + (topic_length = two_byte_dec(data)))
      {
        return MQTT_INVALID_PUBLISH_PACKET;
      }

      topic.set(topic_length,data + 2);
      data += 2 + topic_length;

      packet_id = 0;
      if (qos > 0)
      {
        if (data_end - data < 2)
        {
          return MQTT_INVALID_PUBLISH_PACKET;
        }

        packet_id = two_byte_dec(data);
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
      payload.set(payload_length,data);

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
          two_byte_enc(packet_id,&buffer);

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
          while (packet_id >= pubrec.used)
          {
            pubrec.push(0);
          }

          // - not duplicate or not received yet -
          if (dup == 0 || !pubrec.data[packet_id])
          {
            // - call event received callback -
            callback_event = c_mqtt_EVENT_RECEIVED;
            MQTT_CALL_CALLBACK_DELEGATE(this,
              return MQTT_CONN_CALLBACK_ERROR;
            );

            // - mark packet as received -
            pubrec.data[packet_id] = 1;
          }

          // - send pubrec packet -
          bc_array_s buffer;
          buffer.init();
          buffer.reserve(4);

          buffer.push(0x50); // PUBREC
          buffer.push(0x02); // remaining length

          // - packet identifier -
          two_byte_enc(packet_id,&buffer);

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
      packet_id = two_byte_dec(data);
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
      if (packet_id >= published.used
          || (publish = &published[packet_id])->packet_id != packet_id
          || publish->qos != 1)
      {
        return MQTT_INVALID_PUBACK_PACKET;
      }

      // - release packet id -
      packet_ids.insert(packet_id);

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
      packet_id = two_byte_dec(data);
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
      if (packet_id < published.used
          && (publish = &published[packet_id])->packet_id == packet_id
          && publish->qos == 2)
      {
        // - reason code: Success -
        reason_code = 0x00;

        // - mark publish as released -
        publish->released = 1;

        // - release data locations -
        publish->release_locations(it);
      }

      if (send_pubrel(packet_id,reason_code))
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
      packet_id = two_byte_dec(data);
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
      if (packet_id < pubrec.used && pubrec.data[packet_id])
      {
        // - reason code: Success -
        reason_code = 0x00;

        // - reset pubrec flag -
        pubrec.data[packet_id] = 0;
      }

      // - send pubcomp packet -
      uint32_t remaining_length = 2 + (reason_code == 0x00 ? 0 : 1);

      bc_array_s buffer;
      buffer.init();
      buffer.reserve(2 + remaining_length);

      buffer.push(0x70);  // PUBCOMP
      buffer.push(remaining_length);

      // - packet identifier -
      two_byte_enc(packet_id,&buffer);

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
      packet_id = two_byte_dec(data);
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
      if (packet_id >= published.used
          || (publish = &published[packet_id])->packet_id != packet_id
          || publish->qos != 2)
      {
        return MQTT_INVALID_PUBCOMP_PACKET;
      }

      // - release packet id -
      packet_ids.insert(packet_id);

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
      packet_id = two_byte_dec(data);
      data += 2;

      mqtt_subscribe_s *subscribe;

      // - unknown packet id -
      if (packet_id >= subscribed.used
          || (subscribe = &subscribed[packet_id])->packet_id != packet_id)
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
      pointer_array_s *filters_ptr = (pointer_array_s *)((location_s *)subscribe->filters_loc)->v_data_ptr;
      if ((uint32_t)(data_end - data) != filters_ptr->used)
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

      packet_ids.insert(packet_id);

      // - release subscribe locations -
      subscribe->release_locations(it);

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
      packet_id = two_byte_dec(data);
      data += 2;

      mqtt_subscribe_s *unsubscribe;

      // - unknown packet id -
      if (packet_id >= subscribed.used
          || (unsubscribe = &subscribed[packet_id])->packet_id != packet_id)
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
      pointer_array_s *filters_ptr = (pointer_array_s *)((location_s *)unsubscribe->filters_loc)->v_data_ptr;
      if ((uint32_t)(data_end - data) != filters_ptr->used)
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
      packet_ids.insert(packet_id);

      // - release unsubscribe locations -
      unsubscribe->release_locations(it);

      // - reset unsubscribe data -
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
  if (packet_ids.used == 0)
  {
    if (next_packet_id >= UINT16_MAX)
    {
      return MQTT_CONN_OUT_OF_PACKET_IDENTIFIERS;
    }

    *a_packet_id = next_packet_id++;
  }
  else {
    *a_packet_id = packet_ids.next();
  }

  return 0;
}/*}}}*/

int mqtt_conn_s::send_connect()
{/*{{{*/
  string_s connect_props;
  connect_props.init();

  if (connect_props_loc != nullptr)
  {
    string_s *connect_props_ptr = (string_s *)((location_s *)connect_props_loc)->v_data_ptr;
    connect_props.size = connect_props_ptr->size;
    connect_props.data = connect_props_ptr->data;
  }

  // - send connect packet -
  uint32_t remaining_length = 10 + // variable header
    connect_props.size - 1 +           // properties
    2 + client_id.size - 1;        // client id

  if (var_byte_len(connect_props.size - 1,&remaining_length))
  {
    return MQTT_INVALID_CONNECT_PACKET;
  }

  string_s *will_topic_ptr = nullptr;
  string_s *will_payload_ptr = nullptr;
  string_s *will_props_ptr = nullptr;

  // - will will be registered by connection -
  if (will.topic_loc != nullptr)
  {
    will_topic_ptr = (string_s *)((location_s *)will.topic_loc)->v_data_ptr;
    will_payload_ptr = (string_s *)((location_s *)will.payload_loc)->v_data_ptr;
    will_props_ptr = (string_s *)((location_s *)will.props_loc)->v_data_ptr;

    remaining_length += will_props_ptr->size - 1 + // will properties
      2 + will_topic_ptr->size - 1 +               // will topic length
      2 + will_payload_ptr->size - 1;              // will payload length

    if (var_byte_len(will_props_ptr->size - 1,&remaining_length))
    {
      return MQTT_INVALID_CONNECT_PACKET;
    }
  }

  // - user name will be send -
  if (user_name.size > 1)
  {
    remaining_length += 2 + user_name.size - 1;
  }

  // - password will be send -
  if (password.size > 1)
  {
    remaining_length += 2 + password.size - 1;
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
      (user_name.size > 1) << 7 |  // user name flag
      (password.size > 1) << 6 |   // password flag
      (will.topic_loc != nullptr && will.retain) << 5 |    // will retain
      (will.topic_loc != nullptr ? will.qos : 0x00) << 3 | // will qos (2 bits)
      (will.topic_loc != nullptr) << 2 | // will flag
      1 << 1 |                     // clean start
      0 << 0);                     // reserved

  // - zero keep alive -
  two_byte_enc(0,&buffer);

  // - properties length -
  if (var_byte_enc(connect_props.size - 1,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_CONNECT_PACKET;
  }

  // - properties -
  buffer.append(connect_props.size - 1,connect_props.data);

  // - client id -
  two_byte_enc(client_id.size - 1,&buffer);
  buffer.append(client_id.size - 1,client_id.data);

  if (will.topic_loc != nullptr)
  {
    // - will properties length -
    if (var_byte_enc(will_props_ptr->size - 1,&buffer))
    {
      buffer.clear();

      return MQTT_INVALID_CONNECT_PACKET;
    }

    buffer.append(will_props_ptr->size - 1,will_props_ptr->data);

    // - will topic -
    two_byte_enc(will_topic_ptr->size - 1,&buffer);
    buffer.append(will_topic_ptr->size - 1,will_topic_ptr->data);

    // - will payload -
    two_byte_enc(will_payload_ptr->size - 1,&buffer);
    buffer.append(will_payload_ptr->size - 1,will_payload_ptr->data);
  }

  // - user name -
  if (user_name.size > 1)
  {
    two_byte_enc(user_name.size - 1,&buffer);
    buffer.append(user_name.size - 1,user_name.data);
  }

  // - password -
  if (password.size > 1)
  {
    two_byte_enc(password.size - 1,&buffer);
    buffer.append(password.size - 1,password.data);
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
  string_s *topic_ptr = (string_s *)((location_s *)a_publish->topic_loc)->v_data_ptr;
  string_s *payload_ptr = (string_s *)((location_s *)a_publish->payload_loc)->v_data_ptr;
  string_s *props_ptr = (string_s *)((location_s *)a_publish->props_loc)->v_data_ptr;

  uint32_t remaining_length = 2 + topic_ptr->size - 1 + // topic length
    (a_publish->packet_id != 0 ? 2 : 0) +  // packet identifier length
    props_ptr->size - 1 + // properties length
    payload_ptr->size - 1; // payload length

  if (var_byte_len(props_ptr->size - 1,&remaining_length))
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
  two_byte_enc(topic_ptr->size - 1,&buffer);
  buffer.append(topic_ptr->size - 1,topic_ptr->data);

  if (a_publish->packet_id != 0) {
    // - packet identifier -
    two_byte_enc(a_publish->packet_id,&buffer);
  }

  // - properties length -
  if (var_byte_enc(props_ptr->size - 1,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_PUBLISH_PACKET;
  }

  // - properties -
  buffer.append(props_ptr->size - 1,props_ptr->data);

  // - payload -
  buffer.append(payload_ptr->size - 1,payload_ptr->data);

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
  pointer_array_s *filters_ptr = (pointer_array_s *)((location_s *)a_subscribe->filters_loc)->v_data_ptr;
  string_s *props_ptr = (string_s *)((location_s *)a_subscribe->props_loc)->v_data_ptr;

  uint32_t remaining_length = 2 + props_ptr->size - 1;

  if (var_byte_len(props_ptr->size - 1,&remaining_length))
  {
    return MQTT_INVALID_SUBSCRIBE_PACKET;
  }

  // - retrieve topic filters length -
  if (filters_ptr->used != 0)
  {
    pointer *ptr = filters_ptr->data;
    pointer *ptr_end = ptr + filters_ptr->used;
    do {
      location_s *item_location = interpreter_thread_s::get_location_value(*ptr);
      string_s *filter_ptr = (string_s *)item_location->v_data_ptr;

      remaining_length += 2 + 1 + filter_ptr->size - 1;
    } while(++ptr < ptr_end);
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
  if (var_byte_enc(props_ptr->size - 1,&buffer))
  {
    return MQTT_INVALID_SUBSCRIBE_PACKET;
  }

  // - properties -
  buffer.append(props_ptr->size - 1,props_ptr->data);

  // - process topic filters -
  if (filters_ptr->used != 0)
  {
    pointer *ptr = filters_ptr->data;
    pointer *ptr_end = ptr + filters_ptr->used;
    do {
      location_s *item_location = interpreter_thread_s::get_location_value(*ptr);
      string_s *filter_ptr = (string_s *)item_location->v_data_ptr;

      // - topic filter -
      two_byte_enc(filter_ptr->size - 1,&buffer);
      buffer.append(filter_ptr->size - 1,filter_ptr->data);

      // - subscription options -
      buffer.push(
          0 << 4 |  // retain handling (send retained messages at the time of the subscribe)
          1 << 3 |  // retain as published
          0 << 2 |  // no local (off)
          a_subscribe->max_qos);
    } while(++ptr < ptr_end);
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
  pointer_array_s *filters_ptr = (pointer_array_s *)((location_s *)a_subscribe->filters_loc)->v_data_ptr;
  string_s *props_ptr = (string_s *)((location_s *)a_subscribe->props_loc)->v_data_ptr;

  uint32_t remaining_length = 2 + props_ptr->size - 1;

  if (var_byte_len(props_ptr->size - 1,&remaining_length))
  {
    return MQTT_INVALID_UNSUBSCRIBE_PACKET;
  }

  // Retrieve topic filters length
  if (filters_ptr->used != 0)
  {
    pointer *ptr = filters_ptr->data;
    pointer *ptr_end = ptr + filters_ptr->used;
    do {
      location_s *item_location = interpreter_thread_s::get_location_value(*ptr);
      string_s *filter_ptr = (string_s *)item_location->v_data_ptr;

      remaining_length += 2 + filter_ptr->size - 1;
    } while(++ptr < ptr_end);
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
  if (var_byte_enc(props_ptr->size - 1,&buffer))
  {
    buffer.clear();

    return MQTT_INVALID_UNSUBSCRIBE_PACKET;
  }

  // Properties
  buffer.append(props_ptr->size - 1,props_ptr->data);

  // Process topic filters
  if (filters_ptr->used != 0)
  {
    pointer *ptr = filters_ptr->data;
    pointer *ptr_end = ptr + filters_ptr->used;
    do {
      location_s *item_location = interpreter_thread_s::get_location_value(*ptr);
      string_s *filter_ptr = (string_s *)item_location->v_data_ptr;

      // Topic filter
      two_byte_enc(filter_ptr->size - 1,&buffer);
      buffer.append(filter_ptr->size - 1,filter_ptr->data);
    } while(++ptr < ptr_end);
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

int mqtt_conn_s::publish(location_s *a_topic,location_s *a_payload,
      location_s *a_props,uint8_t a_qos, int a_retain,uint16_t *a_packet_id)
{/*{{{*/
  if (mqtt_disconnecting || a_qos >= 3)
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

    while (packet_id >= published.used)
    {
      published.push_blank();
      mqtt_publish_s &publish = published.last();
      publish.packet_id = 0;
      publish.init_locations();
    }

    mqtt_publish_s &publish = published[packet_id];

    publish.packet_id = packet_id;
    publish.released = 0;

    a_topic->v_reference_cnt.atomic_inc();
    publish.topic_loc = a_topic;

    a_payload->v_reference_cnt.atomic_inc();
    publish.payload_loc = a_payload;

    publish.qos = a_qos;
    publish.retain = a_retain;

    a_props->v_reference_cnt.atomic_inc();
    publish.props_loc = a_props;

    if (mqtt_connected)
    {
      if (send_publish(&published[packet_id],0))
      {
        return MQTT_SEND_PUBLISH_ERROR;
      }
    }
  }
  else
  {
    if (mqtt_connected)
    {
      mqtt_publish_s publish;
      publish.init();

      publish.packet_id = packet_id;
      publish.released = 0;
      publish.topic_loc = a_topic;
      publish.payload_loc = a_payload;
      publish.qos = a_qos;
      publish.retain = a_retain;
      publish.props_loc = a_props;

      int send_err = send_publish(&publish,0);

      publish.clear();

      if (send_err)
      {
        return MQTT_SEND_PUBLISH_ERROR;
      }
    }
  }

  *a_packet_id = packet_id;

  return 0;
}/*}}}*/

int mqtt_conn_s::subscribe(location_s *a_filters,location_s *a_props,
    uint8_t a_max_qos,uint16_t *a_packet_id)
{/*{{{*/
  if (mqtt_disconnecting || a_max_qos >= 3)
  {
    return MQTT_INVALID_SUBSCRIBE_REQUEST;
  }

  uint16_t packet_id;
  if (get_next_packet_id(&packet_id))
  {
    return MQTT_CONN_NEXT_PACKET_ID_ERROR;
  }

  while (packet_id >= subscribed.used)
  {
    subscribed.push_blank();
    mqtt_subscribe_s &subscribe = subscribed.last();
    subscribe.packet_id = 0;
    subscribe.init_locations();
  }

  mqtt_subscribe_s &subscribe = subscribed[packet_id];
  subscribe.packet_id = packet_id;

  a_filters->v_reference_cnt.atomic_inc();
  subscribe.filters_loc = a_filters;

  subscribe.max_qos = a_max_qos;

  a_props->v_reference_cnt.atomic_inc();
  subscribe.props_loc = a_props;

  if (send_subscribe(&subscribe))
  {
    return MQTT_SEND_SUBSCRIBE_ERROR;
  }

  *a_packet_id = packet_id;

  return 0;
}/*}}}*/

int mqtt_conn_s::unsubscribe(location_s *a_filters,location_s *a_props,
    uint16_t *a_packet_id)
{/*{{{*/
  if (mqtt_disconnecting)
  {
    return MQTT_INVALID_UNSUBSCRIBE_REQUEST;
  }

  uint16_t packet_id;
  if (get_next_packet_id(&packet_id))
  {
    return MQTT_CONN_NEXT_PACKET_ID_ERROR;
  }

  while (packet_id >= subscribed.used)
  {
    subscribed.push_blank();
    mqtt_subscribe_s &subscribe = subscribed.last();
    subscribe.packet_id = 0;
    subscribe.init_locations();
  }

  mqtt_subscribe_s &subscribe = subscribed[packet_id];
  subscribe.packet_id = packet_id;

  a_filters->v_reference_cnt.atomic_inc();
  subscribe.filters_loc = a_filters;

  subscribe.max_qos = 0;

  a_props->v_reference_cnt.atomic_inc();
  subscribe.props_loc = a_props;

  if (send_unsubscribe(&subscribe))
  {
    return MQTT_SEND_UNSUBSCRIBE_ERROR;
  }

  *a_packet_id = packet_id;

  return 0;
}/*}}}*/

int mqtt_conn_s::disconnect()
{/*{{{*/
  if (mqtt_connected)
  {
    bc_array_s buffer;
    buffer.init();
    buffer.reserve(2);

    buffer.push(0xe0);  // DISCONNECT
    buffer.push(0x00);  // Remaining length

    cassert(buffer.used == 2);

    if (schedule_message(&buffer))
    {
      buffer.clear();

      return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
    }

    buffer.clear();
  }

  mqtt_connected = false;
  mqtt_disconnecting = true;

  return 0;
}/*}}}*/

int mqtt_conn_s::pingreq()
{/*{{{*/
  if (mqtt_connected)
  {
    // - send pingreq packet -
    bc_array_s buffer;
    buffer.init();
    buffer.reserve(2);

    buffer.push(0xc0);  // PINGREQ
    buffer.push(0x00);  // Remaining length

    cassert(buffer.used == 2);

    if (schedule_message(&buffer))
    {
      buffer.clear();

      return MQTT_CONN_SCHEDULE_MESSAGE_ERROR;
    }

    buffer.clear();
  }

  return 0;
}/*}}}*/

