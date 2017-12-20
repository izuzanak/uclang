
#ifndef __UCTCNMD_MODULE_H
#define __UCTCNMD_MODULE_H

@begin
include "ucl_uctcnmd.h"
@end

// - UCTCNMD indexes of built in classes -
extern unsigned c_bi_class_tcn_msg;
extern unsigned c_bi_class_tcn_address;
extern unsigned c_bi_class_tcn_am_address;
extern unsigned c_bi_class_tcn_caller;
extern unsigned c_bi_class_tcn_replier;
extern unsigned c_bi_class_tcn_call_handler;
extern unsigned c_bi_class_tcn_repl_handler;

// - UCTCNMD module -
extern built_in_module_s module;

// - UCTCNMD classes -
extern built_in_class_s *uctcnmd_classes[];

// - UCTCNMD error identifiers -
enum
{
  c_error_TCN_MSG_WRONG_U8_VALUE_RANGE = 0,
  c_error_TCN_ADDRESS_INVALID_ADDRESS_TYPE,
  c_error_TCN_CALLER_WRONG_CALLBACK_DELEGATE,
  c_error_TCN_CALLER_REGISTER_ERROR,
  c_error_TCN_CALLER_CALL_REQUEST_INVALID_TIMEOUT,
  c_error_TCN_CALLER_CALL_REQUEST_ERROR,
  c_error_TCN_REPLIER_REQUEST_INVALID_INSTANCE_COUNT,
  c_error_TCN_REPLIER_WRONG_CALLBACK_DELEGATE,
  c_error_TCN_REPLIER_WRONG_CLOSE_DELEGATE,
  c_error_TCN_REPLIER_REGISTER_ERROR,
  c_error_TCN_CALL_HANDLER_CANCEL_ERROR,
  c_error_TCN_REPL_HANDLER_REPLY_REQUEST_ERROR,
  c_error_TCN_REPL_HANDLER_CANCEL_ERROR,
};

// - UCTCNMD error strings -
extern const char *uctcnmd_error_strings[];

// - UCTCNMD initialize -
bool uctcnmd_initialize(script_parser_s &sp);

// - UCTCNMD print exception -
bool uctcnmd_print_exception(interpreter_s &it,exception_s &exception);

// - class TCN_MSG -
extern built_in_variable_s tcn_msg_variables[];
extern built_in_method_s tcn_msg_methods[];
extern built_in_class_s tcn_msg_class;

void bic_tcn_msg_consts(location_array_s &const_locations);
void bic_tcn_msg_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_msg_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_msg_method_RpcMain_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_msg_method_Main_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_ADDRESS -
extern built_in_variable_s tcn_address_variables[];
extern built_in_method_s tcn_address_methods[];
extern built_in_class_s tcn_address_class;

void bic_tcn_address_consts(location_array_s &const_locations);
void bic_tcn_address_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_address_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_TcnAddress_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_addr_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_node_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_group_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_function_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_next_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_AM_ADDRESS -
extern built_in_variable_s tcn_am_address_variables[];
extern built_in_method_s tcn_am_address_methods[];
extern built_in_class_s tcn_am_address_class;

void bic_tcn_am_address_consts(location_array_s &const_locations);
void bic_tcn_am_address_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_am_address_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_am_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_gni_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_snu_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_node_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_group_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_function_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_next_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_topo_counter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_topo_valid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_topo_rsv_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_am_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_CALLER -
extern built_in_variable_s tcn_caller_variables[];
extern built_in_method_s tcn_caller_methods[];
extern built_in_class_s tcn_caller_class;

void bic_tcn_caller_consts(location_array_s &const_locations);
void bic_tcn_caller_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_caller_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_caller_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_caller_method_TcnCaller_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_caller_method_CallRequest_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_caller_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_caller_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_REPLIER -
extern built_in_variable_s tcn_replier_variables[];
extern built_in_method_s tcn_replier_methods[];
extern built_in_class_s tcn_replier_class;

void bic_tcn_replier_consts(location_array_s &const_locations);
void bic_tcn_replier_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_replier_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_replier_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_replier_method_TcnReplier_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_replier_method_TcnReplier_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_replier_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_replier_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_CALL_HANDLER -
extern built_in_variable_s tcn_call_handler_variables[];
extern built_in_method_s tcn_call_handler_methods[];
extern built_in_class_s tcn_call_handler_class;

void bic_tcn_call_handler_consts(location_array_s &const_locations);
void bic_tcn_call_handler_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_call_handler_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_call_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_Cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_served_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_am_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_call_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TCN_REPL_HANDLER -
extern built_in_variable_s tcn_repl_handler_variables[];
extern built_in_method_s tcn_repl_handler_methods[];
extern built_in_class_s tcn_repl_handler_class;

void bic_tcn_repl_handler_consts(location_array_s &const_locations);
void bic_tcn_repl_handler_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tcn_repl_handler_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_tcn_repl_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_ReplyRequest_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_Cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_am_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_closed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tcn_repl_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

