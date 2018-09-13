
#ifndef __UCTRDPMD_MODULE_H
#define __UCTRDPMD_MODULE_H

@begin
include "ucl_uctrdpmd.h"
@end

// - UCTRDPMD indexes of built in classes -
extern unsigned c_bi_class_trdp_md;
extern unsigned c_bi_class_trdp_md_gate;
extern unsigned c_bi_class_trdp_md_gate_params;
extern unsigned c_bi_class_trdp_md_address;
extern unsigned c_bi_class_trdp_md_message;
extern unsigned c_bi_class_trdp_md_call;
extern unsigned c_bi_class_trdp_md_listener;
extern unsigned c_bi_class_trdp_md_event;

// - UCTRDPMD module -
extern built_in_module_s module;

// - UCTRDPMD classes -
extern built_in_class_s *uctrdpmd_classes[];

// - UCTRDPMD error identifiers -
enum
{
  c_error_TRDP_MD_INVALID_PORT_VALUE = 0,
  c_error_TRDP_MD_INVALID_PARAMETER_VALUE,
  c_error_TRDP_MD_SET_MODE_INVALID_MODE,
  c_error_TRDP_MD_SET_MODE_ERROR,
  c_error_TRDP_MD_SET_PERIOD_ERROR,
  c_error_TRDP_MD_SET_COMPARS_ERROR,
  c_error_TRDP_MD_INITIALIZE_ERROR,
  c_error_TRDP_MD_GATE_WRONG_CALLBACK_DELEGATE,
  c_error_TRDP_MD_GATE_OPEN_ERROR,
  c_error_TRDP_MD_GATE_REQUEST_LISTEN_INVALID_SCOPE,
  c_error_TRDP_MD_GATE_REQUEST_INVALID_NUMBER_OF_RESPONSES,
  c_error_TRDP_MD_GATE_REQUEST_INVALID_NUMBER_OF_RETRIES,
  c_error_TRDP_MD_GATE_REQUEST_ERROR,
  c_error_TRDP_MD_GATE_LISTEN_ERROR,
  c_error_TRDP_MD_ADDRESS_INVALID_ADDRESS,
  c_error_TRDP_MD_ADDRESS_INVALID_USER_NAME,
  c_error_TRDP_MD_MESSAGE_DATA_TOO_BIG,
  c_error_TRDP_MD_MESSAGE_INVALID_TYPE,
  c_error_TRDP_MD_EVENT_HANDLER_USER_DATA_ERROR,
  c_error_TRDP_MD_EVENT_MESSAGE_READ_ERROR,
  c_error_TRDP_MD_EVENT_REPLY_ERROR,
  c_error_TRDP_MD_EVENT_CONFIRM_ERROR,
};

// - UCTRDPMD error strings -
extern const char *uctrdpmd_error_strings[];

// - UCTRDPMD initialize -
bool uctrdpmd_initialize(script_parser_s &sp);

// - UCTRDPMD print exception -
bool uctrdpmd_print_exception(interpreter_s &it,exception_s &exception);

// - class TRDP_MD -
extern built_in_variable_s trdp_md_variables[];
extern built_in_method_s trdp_md_methods[];
extern built_in_class_s trdp_md_class;

void bic_trdp_md_consts(location_array_s &const_locations);
void bic_trdp_md_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_TrdpMd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_SetMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_SetPeriod_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_SetComParsUdp_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_SetComParsTcp_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_OpenGate_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_trdp_md_method_EnableAll_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_trdp_md_method_DisableAll_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_GATE -
extern built_in_variable_s trdp_md_gate_variables[];
extern built_in_method_s trdp_md_gate_methods[];
extern built_in_class_s trdp_md_gate_class;

void bic_trdp_md_gate_consts(location_array_s &const_locations);
void bic_trdp_md_gate_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_gate_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_gate_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_method_Listen_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_method_Request_6(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_GATE_PARAMS -
extern built_in_variable_s trdp_md_gate_params_variables[];
extern built_in_method_s trdp_md_gate_params_methods[];
extern built_in_class_s trdp_md_gate_params_class;

void bic_trdp_md_gate_params_consts(location_array_s &const_locations);
void bic_trdp_md_gate_params_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_gate_params_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_gate_params_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_params_method_TrdpMdGateParams_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_params_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_gate_params_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_ADDRESS -
extern built_in_variable_s trdp_md_address_variables[];
extern built_in_method_s trdp_md_address_methods[];
extern built_in_class_s trdp_md_address_class;

void bic_trdp_md_address_consts(location_array_s &const_locations);
void bic_trdp_md_address_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_address_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_address_method_TrdpMdAddress_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_MESSAGE -
extern built_in_variable_s trdp_md_message_variables[];
extern built_in_method_s trdp_md_message_methods[];
extern built_in_class_s trdp_md_message_class;

void bic_trdp_md_message_consts(location_array_s &const_locations);
void bic_trdp_md_message_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_message_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_message_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_message_method_TrdpMdMessage_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_message_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_message_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_CALL -
extern built_in_variable_s trdp_md_call_variables[];
extern built_in_method_s trdp_md_call_methods[];
extern built_in_class_s trdp_md_call_class;

void bic_trdp_md_call_consts(location_array_s &const_locations);
void bic_trdp_md_call_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_call_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_call_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_call_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_call_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_LISTENER -
extern built_in_variable_s trdp_md_listener_variables[];
extern built_in_method_s trdp_md_listener_methods[];
extern built_in_class_s trdp_md_listener_class;

void bic_trdp_md_listener_consts(location_array_s &const_locations);
void bic_trdp_md_listener_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_listener_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_listener_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_trdp_md_listener_method_Enable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_trdp_md_listener_method_Disable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_listener_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_listener_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_listener_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_MD_EVENT -
extern built_in_variable_s trdp_md_event_variables[];
extern built_in_method_s trdp_md_event_methods[];
extern built_in_class_s trdp_md_event_class;

void bic_trdp_md_event_consts(location_array_s &const_locations);
void bic_trdp_md_event_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_md_event_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_md_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_msg_handle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_msg_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_call_rc_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_Reply_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_Confirm_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_md_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

