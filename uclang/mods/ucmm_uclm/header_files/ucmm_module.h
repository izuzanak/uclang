
#ifndef __UCMM_MODULE_H
#define __UCMM_MODULE_H

@begin
include "ucl_ucmm.h"
@end

// - UCMM indexes of built in classes -
extern unsigned c_bi_class_modem_manager;
extern unsigned c_bi_class_mm_device_info;
extern unsigned c_bi_class_mm_network_info;

// - UCMM module -
extern built_in_module_s module;

// - UCMM classes -
extern built_in_class_s *ucmm_classes[];

// - UCMM error identifiers -
enum
{
  c_error_MODEM_MANAGER_CREATE_ERROR = 0,
  c_error_MODEM_MANAGER_DEVICE_INFO_READ_ERROR,
  c_error_MODEM_MANAGER_NETWORK_INFO_READ_ERROR,
  c_error_MODEM_MANAGER_SUBSCRIBER_ID_READ_ERROR,
  c_error_MODEM_MANAGER_AT_COMMAND_ERROR,
};

// - UCMM error strings -
extern const char *ucmm_error_strings[];

// - UCMM initialize -
bool ucmm_initialize(script_parser_s &sp);

// - UCMM print exception -
bool ucmm_print_exception(interpreter_s &it,exception_s &exception);

// - class MODEM_MANAGER -
extern built_in_variable_s modem_manager_variables[];
extern built_in_method_s modem_manager_methods[];
extern built_in_class_s modem_manager_class;

void bic_modem_manager_consts(location_array_s &const_locations);
void bic_modem_manager_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_modem_manager_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_modem_manager_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_ModemManager_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_device_info_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_network_info_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_subscriber_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_at_command_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MM_DEVICE_INFO -
extern built_in_variable_s mm_device_info_variables[];
extern built_in_method_s mm_device_info_methods[];
extern built_in_class_s mm_device_info_class;

void bic_mm_device_info_consts(location_array_s &const_locations);
void bic_mm_device_info_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mm_device_info_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mm_device_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_device_info_method_manufacturer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_device_info_method_model_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_device_info_method_revision_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_device_info_method_device_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_device_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_device_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MM_NETWORK_INFO -
extern built_in_variable_s mm_network_info_variables[];
extern built_in_method_s mm_network_info_methods[];
extern built_in_class_s mm_network_info_class;

void bic_mm_network_info_consts(location_array_s &const_locations);
void bic_mm_network_info_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mm_network_info_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mm_network_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_mm_network_info_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_network_info_method_net_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_network_info_method_oper_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_network_info_method_oper_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_network_info_method_signal_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_network_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mm_network_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

