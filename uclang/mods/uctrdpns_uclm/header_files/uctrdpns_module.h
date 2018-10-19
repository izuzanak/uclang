
#ifndef __UCTRDPNS_MODULE_H
#define __UCTRDPNS_MODULE_H

@begin
include "ucl_uctrdpns.h"
@end

// - UCTRDPNS indexes of built in classes -
extern unsigned c_bi_class_trdp_ns;
extern unsigned c_bi_class_trdp_ns_target;
extern unsigned c_bi_class_trdp_ns_address;

// - UCTRDPNS module -
extern built_in_module_s module;

// - UCTRDPNS classes -
extern built_in_class_s *uctrdpns_classes[];

// - UCTRDPNS error identifiers -
enum
{
  c_error_TRDP_NS_INITIALIZE_ERROR = 0,
  c_error_TRDP_NS_SET_MODE_INVALID_MODE,
  c_error_TRDP_NS_SET_MODE_ERROR,
  c_error_TRDP_NS_SET_PERIOD_ERROR,
  c_error_TRDP_NS_ADD_TARGET_ERROR,
  c_error_TRDP_NS_TARGET_GET_ADDRESS_ERROR,
};

// - UCTRDPNS error strings -
extern const char *uctrdpns_error_strings[];

// - UCTRDPNS initialize -
bool uctrdpns_initialize(script_parser_s &sp);

// - UCTRDPNS print exception -
bool uctrdpns_print_exception(interpreter_s &it,exception_s &exception);

// - class TRDP_NS -
extern built_in_variable_s trdp_ns_variables[];
extern built_in_method_s trdp_ns_methods[];
extern built_in_class_s trdp_ns_class;

void bic_trdp_ns_consts(location_array_s &const_locations);
void bic_trdp_ns_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_ns_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_ns_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_method_TrdpNs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_method_SetMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_method_SetPeriod_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_method_AddTarget_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_NS_TARGET -
extern built_in_variable_s trdp_ns_target_variables[];
extern built_in_method_s trdp_ns_target_methods[];
extern built_in_class_s trdp_ns_target_class;

void bic_trdp_ns_target_consts(location_array_s &const_locations);
void bic_trdp_ns_target_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_ns_target_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_ns_target_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_target_method_GetAddress_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_target_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_target_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_NS_ADDRESS -
extern built_in_variable_s trdp_ns_address_variables[];
extern built_in_method_s trdp_ns_address_methods[];
extern built_in_class_s trdp_ns_address_class;

void bic_trdp_ns_address_consts(location_array_s &const_locations);
void bic_trdp_ns_address_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_ns_address_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_ns_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_address_method_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_address_method_ip2_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_ns_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

