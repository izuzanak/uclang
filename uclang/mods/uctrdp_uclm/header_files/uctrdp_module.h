
#ifndef __UCTRDP_MODULE_H
#define __UCTRDP_MODULE_H

@begin
include "ucl_uctrdp.h"
@end

// - UCTRDP indexes of built in classes -
extern unsigned c_bi_class_trdp;
extern unsigned c_bi_class_trdp_md;
extern unsigned c_bi_class_trdp_md_gate;
extern unsigned c_bi_class_trdp_md_gate_params;
extern unsigned c_bi_class_trdp_md_address;
extern unsigned c_bi_class_trdp_md_message;

// - UCTRDP module -
extern built_in_module_s module;

// - UCTRDP classes -
extern built_in_class_s *uctrdp_classes[];

// - UCTRDP error identifiers -
enum
{
  c_error_TRDP_INVALID_PORT_VALUE = 0,
  c_error_TRDP_INVALID_PARAMETER_VALUE,
  c_error_TRDP_SET_MODE_INVALID_MODE,
  c_error_TRDP_SET_MODE_ERROR,
  c_error_TRDP_SET_PERIOD_ERROR,
  c_error_TRDP_SET_COMPARS_ERROR,
  c_error_TRDP_MD_INITIALIZE_ERROR,
  c_error_TRDP_MD_GATE_OPEN_ERROR,
  c_error_TRDP_MD_ADDRESS_INVALID_ADDRESS,
  c_error_TRDP_MD_ADDRESS_INVALID_USER_NAME,
  c_error_TRDP_MD_MESSAGE_DATA_TOO_BIG,
};

// - UCTRDP error strings -
extern const char *uctrdp_error_strings[];

// - UCTRDP initialize -
bool uctrdp_initialize(script_parser_s &sp);

// - UCTRDP print exception -
bool uctrdp_print_exception(interpreter_s &it,exception_s &exception);

// - class TRDP -
extern built_in_variable_s trdp_variables[];
extern built_in_method_s trdp_methods[];
extern built_in_class_s trdp_class;

void bic_trdp_consts(location_array_s &const_locations);
void bic_trdp_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

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
bool bic_trdp_md_method_OpenGate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
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
bool bic_trdp_md_gate_method_Request_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
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

#endif

