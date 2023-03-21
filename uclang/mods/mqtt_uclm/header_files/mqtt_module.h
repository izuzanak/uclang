
#ifndef __MQTT_MODULE_H
#define __MQTT_MODULE_H

@begin
include "ucl_mqtt.h"
@end

// - MQTT indexes of built in classes -
extern unsigned c_bi_class_mqtt_client;

// - MQTT module -
extern "C" EXPORT built_in_module_s module;

// - MQTT classes -
extern built_in_class_s *mqtt_classes[];

// - MQTT error identifiers -
enum
{
  c_error_MQTT_CLIENT_WRONG_DELEGATE_PARAMETER_COUNT,
  c_error_MQTT_CLIENT_INVALID_IP_ADDRESS,
  c_error_MQTT_CLIENT_CREATE_ERROR,
  c_error_MQTT_CLIENT_PROCESS_INVALID_FD,
  c_error_MQTT_CLIENT_NOT_CONNECTED,
  c_error_MQTT_CLIENT_SSL_ALREADY_INITIALIZED,
  c_error_MQTT_CLIENT_SSL_INIT_ERROR,
};

// - MQTT error strings -
extern const char *mqtt_error_strings[];

// - MQTT initialize -
bool mqtt_initialize(script_parser_s &sp);

// - MQTT print exception -
bool mqtt_print_exception(interpreter_s &it,exception_s &exception);

// - class MQTT_CLIENT -
extern built_in_variable_s mqtt_client_variables[];
extern built_in_method_s mqtt_client_methods[];
extern built_in_class_s mqtt_client_class;

void bic_mqtt_client_consts(location_array_s &const_locations);
void bic_mqtt_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mqtt_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mqtt_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_MqttClient_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef UCL_WITH_OPENSSL
bool bic_mqtt_client_method_init_ssl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_mqtt_client_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_event_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_packet_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_topic_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_payload_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_retained_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_publish_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_subscribe_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_unsubscribe_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mqtt_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

