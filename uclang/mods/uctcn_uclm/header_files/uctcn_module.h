
#ifndef __UCTCN_MODULE_H
#define __UCTCN_MODULE_H

@begin
include "ucl_uctcn.h"
@end

// - UCTCN indexes of built in classes -
extern unsigned c_bi_class_traffic_store;
extern unsigned c_bi_class_tcn_port_config;
extern unsigned c_bi_class_traffic_port;
extern unsigned c_bi_class_proc_var_set;
extern unsigned c_bi_class_proc_variable;

// - UCTCN module -
extern built_in_module_s module;

// - UCTCN classes -
extern built_in_class_s *uctcn_classes[];

// - UCTCN error identifiers -
enum
{
  c_error_TRAFFIC_STORE_MAX_ID_EXCEEDED = 0,
  c_error_TRAFFIC_STORE_ALREADY_INITIALIZED_ERROR,
  c_error_TRAFFIC_STORE_INITIALIZATION_ERROR,
  c_error_TRAFFIC_STORE_LINK_LAYER_START_ERROR,
  c_error_TRAFFIC_STORE_LINK_LAYER_STOP_ERROR,
  c_error_TRAFFIC_STORE_PORT_CONFIGURATION_READ_ERROR,
  c_error_TRAFFIC_STORE_PORT_ALREADY_SUBSCRIBED_ERROR,
  c_error_TRAFFIC_STORE_CANNOT_FIND_PORT_CONFIGURATION,
  c_error_TRAFFIC_STORE_PORT_SUBSCRIBE_ERROR,
  c_error_TRAFFIC_PORT_INVALID_DATASET_SIZE,
  c_error_TRAFFIC_PORT_PUT_DATASET_ERROR,
  c_error_TRAFFIC_PORT_GET_DATASET_ERROR,
  c_error_TRAFFIC_PORT_GET_DATASET_NO_DATA_IN_PORT,
  c_error_TRAFFIC_PORT_ENABLE_ERROR,
  c_error_TRAFFIC_PORT_DISABLE_ERROR,
  c_error_PROC_VAR_SET_CREATE_NO_VARIABLES_DEFINED,
  c_error_PROC_VAR_SET_CREATE_WRONG_VARIABLE_DESCRIPTION,
  c_error_PROC_VAR_SET_CREATE_UNKNOWN_VARIABLE_TYPE,
  c_error_PROC_VAR_SET_CREATE_WRONG_ELEMENT_COUNT,
  c_error_PROC_VAR_SET_CREATE_NEGATIVE_OFFSET_VALUE,
  c_error_PROC_VAR_SET_CREATE_WRONG_BIT_OFFSET_VALUE,
  c_error_PROC_VAR_SET_CREATE_VARIABLE_NOT_FIT_TO_PORT,
  c_error_PROC_VAR_SET_CREATE_VARIABLE_NAME_IS_ALREADY_USED,
  c_error_PROC_VAR_SET_VARIABLE_NAME_NOT_FOUND,
  c_error_PROC_VAR_SET_INDEX_EXCEEDS_RANGE,
  c_error_PROC_VAR_SET_WRITE_ERROR,
  c_error_PROC_VAR_SET_GET_DATSET_ERROR,
  c_error_PROC_VAR_SET_READ_ERROR,
  c_error_PROC_VAR_SET_READ_NO_DATA_IN_PORT,
  c_error_PROC_VAR_SET_FORCE_ERROR,
  c_error_PROC_VAR_SET_UNFORCE_ERROR,
  c_error_PROC_VARIABLE_SET_UNKNOWN_TYPE,
  c_error_PROC_VARIABLE_SET_WRONG_TYPE,
  c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,
  c_error_PROC_VARIABLE_GET_UNKNOWN_TYPE,
};

// - UCTCN error strings -
extern const char *uctcn_error_strings[];

// - UCTCN initialize -
bool uctcn_initialize(script_parser_s &sp);

// - UCTCN print exception -
bool uctcn_print_exception(interpreter_s &it,exception_s &exception);

// - class TRAFFIC_STORE -
extern built_in_variable_s traffic_store_variables[];
extern built_in_method_s traffic_store_methods[];
extern built_in_class_s traffic_store_class;

void bic_traffic_store_consts(location_array_s &const_locations);
void bic_traffic_store_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_traffic_store_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_traffic_store_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_TrafficStore_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_start_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_port_config_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_get_port_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_PORT_CONFIG -
extern built_in_variable_s tcn_port_config_variables[];
extern built_in_method_s tcn_port_config_methods[];
extern built_in_class_s tcn_port_config_class;

void bic_tcn_port_config_consts(location_array_s &const_locations);
void bic_tcn_port_config_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_port_config_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_port_config_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_traffic_store_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_fcode_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_config_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_port_config_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRAFFIC_PORT -
extern built_in_variable_s traffic_port_variables[];
extern built_in_method_s traffic_port_methods[];
extern built_in_class_s traffic_port_class;

void bic_traffic_port_consts(location_array_s &const_locations);
void bic_traffic_port_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_traffic_port_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_traffic_port_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_port_config_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_create_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_put_dataset_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_get_dataset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_enable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_disable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_port_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PROC_VAR_SET -
extern built_in_variable_s proc_var_set_variables[];
extern built_in_method_s proc_var_set_methods[];
extern built_in_class_s proc_var_set_class;

void bic_proc_var_set_consts(location_array_s &const_locations);
void bic_proc_var_set_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_proc_var_set_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_proc_var_set_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_freshness_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_write_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_safe_write_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_force_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_unforce_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_var_set_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PROC_VARIABLE -
extern built_in_variable_s proc_variable_variables[];
extern built_in_method_s proc_variable_methods[];
extern built_in_class_s proc_variable_class;

void bic_proc_variable_consts(location_array_s &const_locations);
void bic_proc_variable_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_proc_variable_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_proc_variable_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_variable_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_variable_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_variable_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_variable_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_variable_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proc_variable_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

