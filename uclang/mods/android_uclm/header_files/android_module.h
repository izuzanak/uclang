
#ifndef __ANDROID_MODULE_H
#define __ANDROID_MODULE_H

@begin
include "ucl_android.h"
@end

// - ANDROID indexes of built in classes -
extern unsigned c_bi_class_sys_prop;
extern unsigned c_bi_class_log;
extern unsigned c_bi_class_activity;
extern unsigned c_bi_class_event;
extern unsigned c_bi_class_sensor_manager;
extern unsigned c_bi_class_sensor;
extern unsigned c_bi_class_sensor_event_queue;
extern unsigned c_bi_class_sensor_event;

// - ANDROID module -
extern built_in_module_s module;

// - ANDROID classes -
extern built_in_class_s *android_classes[];

// - ANDROID error identifiers -
enum
{
  c_error_SYS_PROP_NOT_EXIST = 0,
  c_error_SYS_PROP_NOT_SELECTED,
  c_error_ACTIVITY_CONNECTION_DOES_NOT_EXIST,
  c_error_ACTIVITY_OBJECT_ALREADY_CREATED,
  c_error_ACTIVITY_WRONG_CALLBACK_DELEGATE,
  c_error_ACTIVITY_EVENT_LOOP_IS_ALREADY_RUNNING,
  c_error_SENSOR_MANAGER_CANNOT_CREATE_EVENT_QUEUE,
  c_error_SENSOR_EVENT_QUEUE_CANNOT_ENABLE_SENSOR,
  c_error_SENSOR_EVENT_QUEUE_CANNOT_DISABLE_SENSOR,
  c_error_SENSOR_EVENT_QUEUE_SET_EVENT_RATE_ERROR,
};

// - ANDROID error strings -
extern const char *android_error_strings[];

// - ANDROID initialize -
bool android_initialize(script_parser_s &sp);

// - ANDROID print exception -
bool android_print_exception(interpreter_s &it,exception_s &exception);

// - class SYS_PROP -
extern built_in_variable_s sys_prop_variables[];
extern built_in_method_s sys_prop_methods[];
extern built_in_class_s sys_prop_class;

void bic_sys_prop_consts(location_array_s &const_locations);
void bic_sys_prop_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sys_prop_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sys_prop_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_prop_method_SysProp_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_prop_method_get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_prop_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_prop_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_prop_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sys_prop_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class LOG -
extern built_in_variable_s log_variables[];
extern built_in_method_s log_methods[];
extern built_in_class_s log_class;

void bic_log_consts(location_array_s &const_locations);
void bic_log_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_log_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_log_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_Log_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_warning_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_error_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_log_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ACTIVITY -
extern built_in_variable_s activity_variables[];
extern built_in_method_s activity_methods[];
extern built_in_class_s activity_class;

void bic_activity_consts(location_array_s &const_locations);
void bic_activity_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_activity_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_activity_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_Activity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_on_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_on_display_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_on_input_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_on_command_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_on_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_on_idle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_event_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_post_redisplay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_activity_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class EVENT -
extern built_in_variable_s event_variables[];
extern built_in_method_s event_methods[];
extern built_in_class_s event_class;

void bic_event_consts(location_array_s &const_locations);
void bic_event_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_event_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_event_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SENSOR_MANAGER -
extern built_in_variable_s sensor_manager_variables[];
extern built_in_method_s sensor_manager_methods[];
extern built_in_class_s sensor_manager_class;

void bic_sensor_manager_consts(location_array_s &const_locations);
void bic_sensor_manager_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sensor_manager_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sensor_manager_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_manager_method_sensor_list_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_manager_method_default_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_manager_method_create_event_queue_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_manager_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_manager_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SENSOR -
extern built_in_variable_s sensor_variables[];
extern built_in_method_s sensor_methods[];
extern built_in_class_s sensor_class;

void bic_sensor_consts(location_array_s &const_locations);
void bic_sensor_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sensor_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sensor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_vendor_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_resolution_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_min_delay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SENSOR_EVENT_QUEUE -
extern built_in_variable_s sensor_event_queue_variables[];
extern built_in_method_s sensor_event_queue_methods[];
extern built_in_class_s sensor_event_queue_class;

void bic_sensor_event_queue_consts(location_array_s &const_locations);
void bic_sensor_event_queue_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sensor_event_queue_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sensor_event_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_enable_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_disable_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_event_rate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_has_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_get_event_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SENSOR_EVENT -
extern built_in_variable_s sensor_event_variables[];
extern built_in_method_s sensor_event_methods[];
extern built_in_class_s sensor_event_class;

void bic_sensor_event_consts(location_array_s &const_locations);
void bic_sensor_event_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sensor_event_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sensor_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_sensor_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_vector_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_vec_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_vec_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_vec_z_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_vec_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sensor_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

