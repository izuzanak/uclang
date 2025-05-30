
@begin
include "mqtt_module.h"
@end

// - MQTT indexes of built in classes -
unsigned c_bi_class_mqtt_client = c_idx_not_exist;

// - MQTT module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  mqtt_classes,         // Classes
  0,                    // Error base index
  22,                   // Error count
  mqtt_error_strings,   // Error strings
  mqtt_initialize,      // Initialize function
  mqtt_print_exception, // Print exceptions function
};/*}}}*/

// - MQTT classes -
built_in_class_s *mqtt_classes[] =
{/*{{{*/
  &mqtt_client_class,
};/*}}}*/

// - MQTT error strings -
const char *mqtt_error_strings[] =
{/*{{{*/
  "error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT",
  "error_MQTT_CLIENT_INVALID_IP_ADDRESS",
  "error_MQTT_CLIENT_CREATE_ERROR",
  "error_MQTT_CLIENT_PROCESS_INVALID_FD",
  "error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED",
  "error_MQTT_CLIENT_SSL_INIT_ERROR",
  "error_MQTT_CLIENT_INVALID_PROPERTIES_ARRAY_SIZE",
  "error_MQTT_CLIENT_INVALID_PROPERTY_CODE_VALUE",
  "error_MQTT_CLIENT_INVALID_PROPERTY_VALUE",
  "error_MQTT_CLIENT_INVALID_PROPERTY_VALUE_SIZE",
  "error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR",
  "error_MQTT_CLIENT_INVALID_TOPIC_SIZE",
  "error_MQTT_CLIENT_INVALID_QOS_LEVEL",
  "error_MQTT_CLIENT_INVALID_FILTER_COUNT",
  "error_MQTT_CLIENT_INVALID_FILTER_VALUE_TYPE",
  "error_MQTT_CLIENT_INVALID_FILTER_SIZE",
  "error_MQTT_CLIENT_INVALID_MAX_QOS_LEVEL",
  "error_MQTT_CLIENT_PUBLISH_ERROR",
  "error_MQTT_CLIENT_SUBSCRIBE_ERROR",
  "error_MQTT_CLIENT_UNSUBSCRIBE_ERROR",
  "error_MQTT_CLIENT_DISCONNECT_ERROR",
  "error_MQTT_CLIENT_PINGREQ_ERROR",
};/*}}}*/

// - MQTT initialize -
bool mqtt_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize mqtt_client class identifier -
  c_bi_class_mqtt_client = class_base_idx++;

  return true;
}/*}}}*/

// - MQTT print exception -
bool mqtt_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of MqttClient delegate parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_IP_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid MqttClient ip address: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating MqttClient\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, SSL is already initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_SSL_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, error while initializing SSL\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_PROPERTIES_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid properties array size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_PROPERTY_CODE_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid property code value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid property value, code: 0x%2.2" HOST_LL_FORMAT "x\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid property value size, code: 0x%2.2" HOST_LL_FORMAT "x\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, cannot access event property outside of proper event callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_TOPIC_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid topic size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_QOS_LEVEL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid QOS level\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_FILTER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid filter count, expected at least one\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_FILTER_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid filter value type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_FILTER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid filter size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_INVALID_MAX_QOS_LEVEL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, invalid maximal QOS level\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_PUBLISH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, publish error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_SUBSCRIBE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, subscribe error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_UNSUBSCRIBE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, unsubscribe error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_DISCONNECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, disconnect error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MQTT_CLIENT_PINGREQ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMqttClient, pingreq error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class MQTT_CLIENT -
built_in_class_s mqtt_client_class =
{/*{{{*/
  "MqttClient",
  c_modifier_public | c_modifier_final,
  24
#ifdef UCL_WITH_OPENSSL
  + 1
#endif
  , mqtt_client_methods,
  9 + 27, mqtt_client_variables,
  bic_mqtt_client_consts,
  bic_mqtt_client_init,
  bic_mqtt_client_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s mqtt_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_operator_binary_equal
  },
  {
    "MqttClient#5",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_MqttClient_5
  },
#ifdef UCL_WITH_OPENSSL
  {
    "init_ssl#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_init_ssl_0
  },
#endif
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_get_fd_0
  },
  {
    "events#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_events_0
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_get_fds_0
  },
  {
    "properties#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mqtt_client_method_properties_1
  },
  {
    "connect_properties#1",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_connect_properties_1
  },
  {
    "authentication#2",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_authentication_2
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_process_2
  },
  {
    "event#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_event_0
  },
  {
    "packet_id#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_packet_id_0
  },
  {
    "topic#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_topic_0
  },
  {
    "payload#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_payload_0
  },
  {
    "properties#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_properties_0
  },
  {
    "retained#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_retained_0
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_user_data_0
  },
  {
    "will#5",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_will_5
  },
  {
    "publish#5",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_publish_5
  },
  {
    "subscribe#3",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_subscribe_3
  },
  {
    "unsubscribe#2",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_unsubscribe_2
  },
  {
    "disconnect#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_disconnect_0
  },
  {
    "pingreq#0",
    c_modifier_public | c_modifier_final,
    bic_mqtt_client_method_pingreq_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mqtt_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mqtt_client_method_print_0
  },
};/*}}}*/

built_in_variable_s mqtt_client_variables[] =
{/*{{{*/

  // - mqtt client event type constants -
  { "EVENT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_CONNECTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DISCONNECTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_DROPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "EVENT_PUBLISHED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_SUBSCRIBED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_UNSUBSCRIBED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_RECEIVED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_PINGRESP", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - mqtt property identifiers -
  { "PROP_PAYLOAD_FORMAT_INDICATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_MESSAGE_EXPIRY_INTERVAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_CONTENT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_RESPONSE_TOPIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_CORRELATION_DATA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SUBSCRIPTION_IDENTIFIER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SESSION_EXPIRY_INTERVAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ASSIGNED_CLIENT_IDENTIFIER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SERVER_KEEP_ALIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_AUTHENTICATION_METHOD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_AUTHENTICATION_DATA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_REQUEST_PROBLEM_INFORMATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_WILL_DELAY_INTERVAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_REQUEST_RESPONSE_INFORMATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_RESPONSE_INFORMATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SERVER_REFERENCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_REASON_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_RECEIVE_MAXIMUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_TOPIC_ALIAS_MAXIMUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_TOPIC_ALIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_MAXIMUM_QOS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_RETAIN_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_USER_PROPERTY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_MAXIMUM_PACKET_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_WILDCARD_SUBSCRIPTION_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SUBSCRIPTION_IDENTIFIER_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SHARED_SUBSCRIPTION_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_mqtt_client_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert mqtt client event type constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_ERROR);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_CONNECTED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_DISCONNECTED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_DROPPED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_PUBLISHED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_SUBSCRIBED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_UNSUBSCRIBED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_RECEIVED);
    CREATE_MQTT_CLIENT_EVENT_TYPE_BIC_STATIC(c_mqtt_EVENT_PINGRESP);
  }

  // - insert mqtt property identifiers -
  {
    const_locations.push_blanks(27);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 27);

#define CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_PAYLOAD_FORMAT_INDICATOR);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_MESSAGE_EXPIRY_INTERVAL);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_CONTENT_TYPE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_RESPONSE_TOPIC);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_CORRELATION_DATA);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_SUBSCRIPTION_IDENTIFIER);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_SESSION_EXPIRY_INTERVAL);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_ASSIGNED_CLIENT_IDENTIFIER);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_SERVER_KEEP_ALIVE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_AUTHENTICATION_METHOD);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_AUTHENTICATION_DATA);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_REQUEST_PROBLEM_INFORMATION);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_WILL_DELAY_INTERVAL);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_REQUEST_RESPONSE_INFORMATION);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_RESPONSE_INFORMATION);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_SERVER_REFERENCE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_REASON_STRING);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_RECEIVE_MAXIMUM);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_TOPIC_ALIAS_MAXIMUM);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_TOPIC_ALIAS);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_MAXIMUM_QOS);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_RETAIN_AVAILABLE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_USER_PROPERTY);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_MAXIMUM_PACKET_SIZE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_WILDCARD_SUBSCRIPTION_AVAILABLE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_SUBSCRIPTION_IDENTIFIER_AVAILABLE);
    CREATE_MQTT_CLIENT_PROP_ID_BIC_STATIC(PROP_SHARED_SUBSCRIPTION_AVAILABLE);
  }

}/*}}}*/

void bic_mqtt_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (mqtt_conn_s *)nullptr;
}/*}}}*/

void bic_mqtt_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)location_ptr->v_data_ptr;

  if (cc_ptr != nullptr)
  {
    cc_ptr->clear(it);
    cfree(cc_ptr);
  }
}/*}}}*/

bool bic_mqtt_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_MqttClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ip:c_bi_class_string
port:retrieve_integer
client_id:c_bi_class_string
event_delegate:c_bi_class_delegate
user_data:ignore
>
method MqttClient
; @end

  string_s *ip_str_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *client_id_str_ptr = (string_s *)src_2_location->v_data_ptr;
  delegate_s *event_delegate = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (event_delegate->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  struct addrinfo addr_hints;
  memset(&addr_hints,0,sizeof(struct addrinfo));
  addr_hints.ai_family = AF_INET;

  // - ERROR -
  struct addrinfo *addr_info;
  if (getaddrinfo(ip_str_ptr->data,nullptr,&addr_hints,&addr_info) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_IP_ADDRESS,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  sockaddr_in address;
  address.sin_addr = ((struct sockaddr_in *)addr_info->ai_addr)->sin_addr;
  address.sin_port = htons(port);
  address.sin_family = AF_INET;

  // - release address info -
  freeaddrinfo(addr_info);

  // - create socket -
  int fd = socket(AF_INET,SOCK_STREAM,0);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  int nonblock_io = 1;
  if (ioctl(fd,FIONBIO,&nonblock_io) != 0)
  {
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set client socket options -
  int yes = 1;
  setsockopt(fd,SOL_TCP,TCP_NODELAY,&yes,sizeof(int));

  // - ERROR -
  if (connect(fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    if (errno != EINPROGRESS)
    {
      close(fd);

      exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - create mqtt_client object -
  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)cmalloc(sizeof(mqtt_conn_s));
  cc_ptr->init();
  cc_ptr->init_static();

  // - set file descriptor -
  cc_ptr->conn_fd = fd;
  cc_ptr->events = POLLIN | POLLOUT | POLLPRI;
  cc_ptr->tcp_connecting = true;

  // - set client id -
  cc_ptr->client_id = *client_id_str_ptr;

  // - retrieve callback -
  src_3_location->v_reference_cnt.atomic_inc();
  cc_ptr->event_callback_loc = src_3_location;

  // - retrieve user data -
  src_4_location->v_reference_cnt.atomic_inc();
  cc_ptr->user_data_loc = src_4_location;

  // - unreferenced conn_location pointer -
  cc_ptr->conn_location = dst_location;

  // - set destination data pointer -
  dst_location->v_data_ptr = (mqtt_conn_s *)cc_ptr;

  return true;
}/*}}}*/

#ifdef UCL_WITH_OPENSSL
bool bic_mqtt_client_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (cc_ptr->ssl != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#if OPENSSL_VERSION_NUMBER >= 0x10100000L
  const SSL_METHOD *method = TLS_client_method();
#else
  const SSL_METHOD *method = TLSv1_2_client_method();
#endif

  SSL_CTX *ssl_ctx = SSL_CTX_new(method);

  // - ERROR -
  if (ssl_ctx == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL *ssl = SSL_new(ssl_ctx);

  // - ERROR -
  if (ssl == nullptr)
  {
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_set_fd(ssl,cc_ptr->conn_fd) != 1)
  {
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SSL_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL_set_connect_state(ssl);
  cc_ptr->ssl = ssl;

  SSL_CTX_free(ssl_ctx);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/
#endif

bool bic_mqtt_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((mqtt_conn_s *)dst_location->v_data_ptr)->conn_fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

#ifdef UCL_WITH_OPENSSL
  long long int result = cc_ptr->ssl_action ? cc_ptr->ssl_events : cc_ptr->events;
#else
  long long int result = cc_ptr->events;
#endif

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

#ifdef UCL_WITH_OPENSSL
  unsigned events = cc_ptr->ssl_action ? cc_ptr->ssl_events : cc_ptr->events;
#else
  unsigned events = cc_ptr->events;
#endif

  if (events != 0)
  {
    BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,cc_ptr->conn_fd);
    array_ptr->push(fd_location);

    BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,events);
    array_ptr->push(events_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_properties_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
properties:c_bi_class_array
>
class c_bi_class_mqtt_client
method properties
static_method
; @end

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTIES_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  bc_array_s buffer;
  buffer.init();

  if (array_ptr->used != 0)
  {
    pointer *ptr = array_ptr->data;
    pointer *ptr_end = ptr + array_ptr->used;
    do {
      location_s *code_location = it.get_location_value(ptr[0]);
      location_s *value_location = it.get_location_value(ptr[1]);

      long long int code;

      // - ERROR -
      if (!it.retrieve_integer(code_location,code))
      {
        buffer.clear();

        exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_CODE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      const mqtt_prop_descr_s *prop_descr;

      // - ERROR -
      if (code >= c_packet_prop_cnt || (prop_descr = &g_mqtt_packet_props[code])->code != code)
      {
        buffer.clear();

        exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_CODE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      switch (prop_descr->type)
      {
      case MQTT_DATA_TYPE_BYTE:
      case MQTT_DATA_TYPE_TWO_BYTE_INTEGER:
      case MQTT_DATA_TYPE_FOUR_BYTE_INTEGER:
      case MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER:
        {/*{{{*/
          long long int value;

          // - ERROR -
          if (!it.retrieve_integer(value_location,value))
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          switch (prop_descr->type)
          {
          case MQTT_DATA_TYPE_BYTE:
            buffer.push(code);
            buffer.push(value);
            break;
          case MQTT_DATA_TYPE_TWO_BYTE_INTEGER:
            buffer.push(code);
            mqtt_conn_s::two_byte_enc(value,&buffer);
            break;
          case MQTT_DATA_TYPE_FOUR_BYTE_INTEGER:
            buffer.push(code);
            mqtt_conn_s::four_byte_enc(value,&buffer);
            break;
          case MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER:
            buffer.push(code);
            mqtt_conn_s::var_byte_enc(value,&buffer);
            break;
          }
        }/*}}}*/
        break;
      case MQTT_DATA_TYPE_UTF_8_ENCODED_STRING:
        {/*{{{*/

          // - ERROR -
          if (value_location->v_type != c_bi_class_string)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          string_s *string_ptr = (string_s *)value_location->v_data_ptr;

          // - ERROR -
          if (string_ptr->size - 1 > UINT16_MAX)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          buffer.push(code);
          mqtt_conn_s::two_byte_enc(string_ptr->size - 1,&buffer);
          buffer.append(string_ptr->size - 1,string_ptr->data);
        }/*}}}*/
        break;
      case MQTT_DATA_TYPE_UTF_8_STRING_PAIR:
        {/*{{{*/

          // - ERROR -
          if (value_location->v_type != c_bi_class_array)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          pointer_array_s *pair_ptr = (pointer_array_s *)value_location->v_data_ptr;

          // - ERROR -
          if (pair_ptr->used != 2)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          location_s *pair_key_location = it.get_location_value(pair_ptr->data[0]);
          location_s *pair_value_location = it.get_location_value(pair_ptr->data[1]);

          // - ERROR -
          if (pair_key_location->v_type != c_bi_class_string ||
              pair_value_location->v_type != c_bi_class_string)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          string_s *pair_key_ptr = (string_s *)pair_key_location->v_data_ptr;
          string_s *pair_value_ptr = (string_s *)pair_value_location->v_data_ptr;

          // - ERROR -
          if (pair_key_ptr->size - 1 > UINT16_MAX ||
              pair_value_ptr->size - 1 > UINT16_MAX)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          buffer.push(code);
          mqtt_conn_s::two_byte_enc(pair_key_ptr->size - 1,&buffer);
          buffer.append(pair_key_ptr->size - 1,pair_key_ptr->data);
          mqtt_conn_s::two_byte_enc(pair_value_ptr->size - 1,&buffer);
          buffer.append(pair_value_ptr->size - 1,pair_value_ptr->data);
        }/*}}}*/
        break;
      case MQTT_DATA_TYPE_BINARY_DATA:
        {/*{{{*/
          const void *data_ptr;
          unsigned data_size;

          // - ERROR -
          if (!it.retrieve_data_buffer(value_location,data_ptr,data_size))
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          // - ERROR -
          if (data_size > UINT16_MAX)
          {
            buffer.clear();

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_PROPERTY_VALUE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(code);

            return false;
          }

          buffer.push(code);
          mqtt_conn_s::two_byte_enc(data_size,&buffer);
          buffer.append(data_size,(const char *)data_ptr);
        }/*}}}*/
        break;

      default:
        cassert(false);
      }

    } while((ptr += 2) < ptr_end);
  }

  buffer.push('\0');

  // - take buffer data -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_connect_properties_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
props:c_bi_class_string
>
method connect_properties
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  if (cc_ptr->connect_props_loc != nullptr)
  {
    // - release connection properties -
    it.release_location_ptr((location_s *)cc_ptr->connect_props_loc);
  }

  // - set connection properties -
  src_0_location->v_reference_cnt.atomic_inc();
  cc_ptr->connect_props_loc = src_0_location;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_authentication_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
user_name:c_bi_class_string
password:c_bi_class_string
>
method authentication
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;
  string_s *user_name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *password_ptr = (string_s *)src_1_location->v_data_ptr;

  cc_ptr->user_name = *user_name_ptr;
  cc_ptr->password = *password_ptr;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fd != cc_ptr->conn_fd)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set source position for callbacks -
  cc_ptr->source_pos = operands[c_source_pos_idx];

  if (cc_ptr->tcp_connecting)
  {
    // - reset tcp_connecting flag -
    cc_ptr->tcp_connecting = false;

    int error;
    socklen_t length = sizeof(error);

    // - check connect result -
    if (getsockopt(cc_ptr->conn_fd,SOL_SOCKET,SO_ERROR,&error,&length))
    {
      error = 1;
    }

#ifdef UCL_WITH_OPENSSL
    if (cc_ptr->ssl == nullptr)
    {
#endif
      // - disable nonblocking io -
      int nonblock_io = 0;
      if (!error && ioctl(cc_ptr->conn_fd,FIONBIO,&nonblock_io))
      {
        error = 1;
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - error occured -
    if (error)
    {
      cc_ptr->events = 0;

      // - call event error callback -
      cc_ptr->callback_event = c_mqtt_EVENT_ERROR;
      MQTT_CALL_CALLBACK_DELEGATE(cc_ptr,
        return false;
      );
    }
    else
    {
      // - set tcp_connected flag -
      cc_ptr->tcp_connected = true;

      // - send connect packet -
      cc_ptr->send_connect();
    }
  }
  else
  {
    // - drop connection flag -
    bool drop_connection = false;

#ifdef UCL_WITH_OPENSSL
    if (cc_ptr->ssl_action)
    {
      if (cc_ptr->ssl_events & events)
      {
        // - reset ssl action -
        unsigned ssl_action = cc_ptr->ssl_action;
        cc_ptr->ssl_action = SSL_ACTION_NONE;

        switch (ssl_action)
        {
        case SSL_ACTION_SEND_MSG:
          if (cc_ptr->send_msg(it))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        case SSL_ACTION_RECV_MSG:
          if (cc_ptr->recv_msg(it))
          {
            // - set drop connection flag -
            drop_connection = true;
          }
          break;
        default:
          cassert(0);
        }
      }
    }
    else
    {
#endif
      // - mask events with connection events -
      unsigned conn_events = cc_ptr->events & events;

      if (conn_events & POLLOUT)
      {
        if (cc_ptr->send_msg(it))
        {
          // - set drop connection flag -
          drop_connection = true;

          // - reset conn_events -
          conn_events = 0;
        }
      }

      if (conn_events & POLLIN)
      {
        if (cc_ptr->recv_msg(it))
        {
          // - set drop connection flag -
          drop_connection = true;
        }
      }
#ifdef UCL_WITH_OPENSSL
    }
#endif

    // - drop connection flag is set -
    if (drop_connection)
    {
      cc_ptr->events = 0;

      // - reset tcp_connected flag -
      cc_ptr->tcp_connected = false;

      // - reset mqtt_connected flag -
      cc_ptr->mqtt_connected = false;

      if (cc_ptr->mqtt_disconnecting)
      {
        // - reset disconnecting flag -
        cc_ptr->mqtt_disconnecting = false;

        // - call event drop callback -
        cc_ptr->callback_event = c_mqtt_EVENT_DISCONNECTED;
        MQTT_CALL_CALLBACK_DELEGATE(cc_ptr,);

        // - drop due to exception -
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          return false;
        }
      }
      else
      {
        // - reset disconnecting flag -
        cc_ptr->mqtt_disconnecting = false;

        // - call event drop callback -
        cc_ptr->callback_event = c_mqtt_EVENT_DROPPED;
        MQTT_CALL_CALLBACK_DELEGATE(cc_ptr,);

        // - drop due to exception -
        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          return false;
        }
      }
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_event_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!cc_ptr->callback_event)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = cc_ptr->callback_event;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_packet_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!(cc_ptr->callback_event & (
          c_mqtt_EVENT_PUBLISHED | c_mqtt_EVENT_SUBSCRIBED | c_mqtt_EVENT_UNSUBSCRIBED)))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = cc_ptr->packet_id;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_topic_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!(cc_ptr->callback_event & c_mqtt_EVENT_RECEIVED))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(cc_ptr->topic.size,cc_ptr->topic.data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_payload_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!(cc_ptr->callback_event & c_mqtt_EVENT_RECEIVED))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(cc_ptr->payload.size,cc_ptr->payload.data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_properties_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!(cc_ptr->callback_event & (
          c_mqtt_EVENT_CONNECTED | c_mqtt_EVENT_PUBLISHED | c_mqtt_EVENT_SUBSCRIBED |
          c_mqtt_EVENT_UNSUBSCRIBED | c_mqtt_EVENT_RECEIVED)))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  if (cc_ptr->prop_refs.used != 0)
  {
    const char *prop_data_end = cc_ptr->properties.data + cc_ptr->properties.size;

    mqtt_prop_s *ptr = cc_ptr->prop_refs.data;
    mqtt_prop_s *ptr_end = ptr + cc_ptr->prop_refs.used;
    do {
      const mqtt_prop_descr_s &prop_descr = g_mqtt_packet_props[ptr->code];
      const char *prop_data = cc_ptr->properties.data + ptr->offset + 1;

      long long int code_value = ptr->code;
      BIC_CREATE_NEW_LOCATION(code_location,c_bi_class_integer,code_value);
      array_ptr->push(code_location);

      switch (prop_descr.type)
      {
      case MQTT_DATA_TYPE_BYTE:
      case MQTT_DATA_TYPE_TWO_BYTE_INTEGER:
      case MQTT_DATA_TYPE_FOUR_BYTE_INTEGER:
      case MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER:
        {/*{{{*/
          long long int value;

          switch (prop_descr.type)
          {
          case MQTT_DATA_TYPE_BYTE:
            value = prop_data[0]; // NOLINT(cert-str34-c)
            break;
          case MQTT_DATA_TYPE_TWO_BYTE_INTEGER:
            value = mqtt_conn_s::two_byte_dec(prop_data);
            break;
          case MQTT_DATA_TYPE_FOUR_BYTE_INTEGER:
            value = mqtt_conn_s::four_byte_dec(prop_data);
            break;
          case MQTT_DATA_TYPE_VARIABLE_BYTE_INTEGER:
            {
              const char *src_end;
              uint32_t value_u32;
              mqtt_conn_s::var_byte_dec(prop_data,prop_data_end,&src_end,&value_u32);
              value = value_u32;
            }
            break;
          }

          BIC_CREATE_NEW_LOCATION(value_location,c_bi_class_integer,value);
          array_ptr->push(value_location);
        }/*}}}*/
        break;
      case MQTT_DATA_TYPE_UTF_8_ENCODED_STRING:
      case MQTT_DATA_TYPE_BINARY_DATA:
        {/*{{{*/
          unsigned length = mqtt_conn_s::two_byte_dec(prop_data);

          string_s *string_ptr = it.get_new_string_ptr();
          string_ptr->set(length,prop_data + 2);

          BIC_CREATE_NEW_LOCATION(value_location,c_bi_class_string,string_ptr);
          array_ptr->push(value_location);
        }/*}}}*/
        break;
      case MQTT_DATA_TYPE_UTF_8_STRING_PAIR:
        {/*{{{*/
          pointer_array_s *pair_ptr = it.get_new_array_ptr();
          BIC_CREATE_NEW_LOCATION(pair_location,c_bi_class_array,pair_ptr);

          // - retrieve pair key -
          unsigned pair_key_length = mqtt_conn_s::two_byte_dec(prop_data);

          string_s *pair_key_ptr = it.get_new_string_ptr();
          pair_key_ptr->set(pair_key_length,prop_data + 2);

          BIC_CREATE_NEW_LOCATION(pair_key_location,c_bi_class_string,pair_key_ptr);
          pair_ptr->push(pair_key_location);

          // - retrieve pair value -
          unsigned pair_value_length = mqtt_conn_s::two_byte_dec(prop_data + 2 + pair_key_length);

          string_s *pair_value_ptr = it.get_new_string_ptr();
          pair_value_ptr->set(pair_value_length,prop_data + 2 + pair_key_length + 2);

          BIC_CREATE_NEW_LOCATION(pair_value_location,c_bi_class_string,pair_value_ptr);
          pair_ptr->push(pair_value_location);

          array_ptr->push(pair_location);
        }/*}}}*/
        break;

      // - ERROR -
      default:
        cassert(false);
      }
    } while(++ptr < ptr_end);
  }

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_retained_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!(cc_ptr->callback_event & c_mqtt_EVENT_RECEIVED))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_EVENT_PROPERTY_ACCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = cc_ptr->retained;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&cc_ptr->user_data_loc);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_will_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
topic:c_bi_class_string
payload:c_bi_class_string
props:c_bi_class_string
qos:retrieve_integer
retain:retrieve_integer
>
method will
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;
  string_s *topic_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (topic_ptr->size <= 1 || topic_ptr->size - 1 > UINT16_MAX)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_TOPIC_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (qos < 0 || qos >= 3)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_QOS_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  mqtt_publish_s &will = cc_ptr->will;

  // - release last will locations -
  will.release_locations(it);

  will.packet_id = 1;
  will.released = 0;

  src_0_location->v_reference_cnt.atomic_inc();
  will.topic_loc = src_0_location;

  src_1_location->v_reference_cnt.atomic_inc();
  will.payload_loc = src_1_location;

  will.qos = qos;
  will.retain = retain;

  src_2_location->v_reference_cnt.atomic_inc();
  will.props_loc = src_2_location;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_publish_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
topic:c_bi_class_string
payload:c_bi_class_string
props:c_bi_class_string
qos:retrieve_integer
retain:retrieve_integer
>
method publish
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;
  string_s *topic_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (topic_ptr->size <= 1 || topic_ptr->size - 1 > UINT16_MAX)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_TOPIC_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (qos < 0 || qos >= 3)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_QOS_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  uint16_t packet_id;
  if (cc_ptr->publish(src_0_location,src_1_location,src_2_location,qos,!!retain,&packet_id))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_PUBLISH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = packet_id;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_subscribe_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
filters:c_bi_class_array
props:c_bi_class_string
max_qos:retrieve_integer
>
method subscribe
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;
  pointer_array_s *filters_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (filters_ptr->used < 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_FILTER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer *ptr = filters_ptr->data;
  pointer *ptr_end = ptr + filters_ptr->used;
  do {
    location_s *item_location = it.get_location_value(*ptr);

    // - ERROR -
    if (item_location->v_type != c_bi_class_string)
    {
      exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_FILTER_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    string_s *filter_ptr = (string_s *)item_location->v_data_ptr;

    // - ERROR -
    if (filter_ptr->size <= 1 || filter_ptr->size - 1 > UINT16_MAX)
    {
      exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_FILTER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

  } while(++ptr < ptr_end);

  // - ERROR -
  if (max_qos < 0 || max_qos >= 3)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_MAX_QOS_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  uint16_t packet_id;
  if (cc_ptr->subscribe(src_0_location,src_1_location,max_qos,&packet_id))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_SUBSCRIBE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = packet_id;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_unsubscribe_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
filters:c_bi_class_array
props:c_bi_class_string
>
method unsubscribe
; @end

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;
  pointer_array_s *filters_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (filters_ptr->used < 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_FILTER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer *ptr = filters_ptr->data;
  pointer *ptr_end = ptr + filters_ptr->used;
  do {
    location_s *item_location = it.get_location_value(*ptr);

    // - ERROR -
    if (item_location->v_type != c_bi_class_string)
    {
      exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_FILTER_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    string_s *filter_ptr = (string_s *)item_location->v_data_ptr;

    // - ERROR -
    if (filter_ptr->size <= 1 || filter_ptr->size - 1 > UINT16_MAX)
    {
      exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_INVALID_FILTER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

  } while(++ptr < ptr_end);

  // - ERROR -
  uint16_t packet_id;
  if (cc_ptr->unsubscribe(src_0_location,src_1_location,&packet_id))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_UNSUBSCRIBE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = packet_id;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mqtt_client_method_disconnect_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (cc_ptr->disconnect())
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_DISCONNECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_pingreq_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mqtt_conn_s *cc_ptr = (mqtt_conn_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (cc_ptr->pingreq())
  {
    exception_s::throw_exception(it,module.error_base + c_error_MQTT_CLIENT_PINGREQ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_mqtt_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MqttClient"),"MqttClient")
  );

  return true;
}/*}}}*/

bool bic_mqtt_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("MqttClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

