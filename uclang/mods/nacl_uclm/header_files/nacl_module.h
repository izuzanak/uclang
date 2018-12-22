
#ifndef __NACL_MODULE_H
#define __NACL_MODULE_H

@begin
include "ucl_nacl.h"
@end

// - NACL indexes of built in classes -
extern unsigned c_bi_class_nacl;
extern unsigned c_bi_class_nacl_3d;
extern unsigned c_bi_class_core;
extern unsigned c_bi_class_time;
extern unsigned c_bi_class_console;
extern unsigned c_bi_class_message;
extern unsigned c_bi_class_net_address;

// - NACL module -
extern "C" EXPORT built_in_module_s module;

// - NACL classes -
extern built_in_class_s *nacl_classes[];

// - NACL error identifiers -
enum
{
  c_error_NACL_OBJECT_ALREADY_CREATED = 0,
  c_error_NACL_WRONG_CALLBACK_DELEGATE,
  c_error_NACL_3D_CONTEXT_CREATE_ERROR,
  c_error_NACL_3D_CONTEXT_ALREADY_CREATED,
  c_error_TIME_WRONG_INIT_STRING,
  c_error_CONSOLE_LOG_LEVEL_ERROR,
  c_error_NET_ADDRESS_ADDRESS_TYPE_ERROR,
  c_error_NET_ADDRESS_UNRECOGNIZED_FAMILY,
};

// - NACL error strings -
extern const char *nacl_error_strings[];

// - NACL initialize -
bool nacl_initialize(script_parser_s &sp);

// - NACL print exception -
bool nacl_print_exception(interpreter_s &it,exception_s &exception);

// - class NACL -
extern built_in_variable_s nacl_variables[];
extern built_in_method_s nacl_methods[];
extern built_in_class_s nacl_class;

void bic_nacl_consts(location_array_s &const_locations);
void bic_nacl_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_nacl_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_nacl_method_Nacl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_OnDestroy_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_OnChangeView_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_OnChangeFocus_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_CallOnMainThread_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_Get3D_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class NACL_3D -
extern built_in_variable_s nacl_3d_variables[];
extern built_in_method_s nacl_3d_methods[];
extern built_in_class_s nacl_3d_class;

void bic_nacl_3d_consts(location_array_s &const_locations);
void bic_nacl_3d_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_nacl_3d_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_nacl_3d_method_SetCurrentContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_3d_method_SwapBuffers_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_3d_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nacl_3d_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CORE -
extern built_in_variable_s core_variables[];
extern built_in_method_s core_methods[];
extern built_in_class_s core_class;

void bic_core_consts(location_array_s &const_locations);
void bic_core_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_core_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_core_method_time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_core_method_time_ticks_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_core_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_core_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TIME -
extern built_in_variable_s time_variables[];
extern built_in_method_s time_methods[];
extern built_in_class_s time_class;

void bic_time_consts(location_array_s &const_locations);
void bic_time_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_time_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_time_compare(location_s *first_loc,location_s *second_loc);

bool bic_time_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_Time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_Time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_seconds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_minutes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_hours_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_days_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_datetime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CONSOLE -
extern built_in_variable_s console_variables[];
extern built_in_method_s console_methods[];
extern built_in_class_s console_class;

void bic_console_consts(location_array_s &const_locations);
void bic_console_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_console_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_console_method_tip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_console_method_log_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_console_method_log_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_console_method_warning_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_console_method_error_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_console_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_console_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MESSAGE -
extern built_in_variable_s message_variables[];
extern built_in_method_s message_methods[];
extern built_in_class_s message_class;

void bic_message_consts(location_array_s &const_locations);
void bic_message_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_message_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_message_method_post_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_message_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_message_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class NET_ADDRESS -
extern built_in_variable_s net_address_variables[];
extern built_in_method_s net_address_methods[];
extern built_in_class_s net_address_class;

void bic_net_address_consts(location_array_s &const_locations);
void bic_net_address_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_net_address_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_net_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_net_address_method_NetAddress_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_net_address_method_family_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_net_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_net_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

