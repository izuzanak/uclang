
#ifndef __V8_MODULE_H
#define __V8_MODULE_H

@begin
include "ucl_v8.h"
@end

// - V8 indexes of built in classes -
extern unsigned c_bi_class_v8_engine;
extern unsigned c_bi_class_v8_context;
extern unsigned c_bi_class_v8_script;
extern unsigned c_bi_class_v8_heap_stat;
extern unsigned c_bi_class_v8_object;
extern unsigned c_bi_class_v8_reference;

// - V8 module -
extern built_in_module_s module;

// - V8 classes -
extern built_in_class_s *v8_classes[];

// - V8 error identifiers -
enum
{
  c_error_V8_SCRIPT_COMPILE_ERROR = 0,
  c_error_V8_SCRIPT_EXECUTE_ERROR,
  c_error_V8_OBJECT_INVOKE_METHOD_ERROR,
  c_error_V8_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,
  c_error_V8_OBJECT_MEMBER_SELECT_ERROR,
  c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,
  c_error_V8_OBJECT_CREATE_ERROR,
  c_error_V8_OBJECT_VALUE_ERROR,
  c_error_V8_OBJECT_HAS_PROP_ERROR,
  c_error_V8_OBJECT_GET_PROP_ERROR,
  c_error_V8_OBJECT_SET_PROP_ERROR,
  c_error_V8_OBJECT_DEL_PROP_ERROR,
  c_error_V8_OBJECT_PROP_NAMES_ERROR,
  c_error_V8_OBJECT_LENGTH_ERROR,
};

// - V8 error strings -
extern const char *v8_error_strings[];

// - V8 initialize -
bool v8_initialize(script_parser_s &sp);

// - V8 print exception -
bool v8_print_exception(interpreter_s &it,exception_s &exception);

// - class V8_ENGINE -
extern built_in_variable_s v8_engine_variables[];
extern built_in_method_s v8_engine_methods[];
extern built_in_class_s v8_engine_class;

void bic_v8_engine_consts(location_array_s &const_locations);
void bic_v8_engine_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_v8_engine_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_v8_engine_method_is_dead_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_engine_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_engine_method_notify_idle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_engine_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_engine_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class V8_CONTEXT -
extern built_in_variable_s v8_context_variables[];
extern built_in_method_s v8_context_methods[];
extern built_in_class_s v8_context_class;

void bic_v8_context_consts(location_array_s &const_locations);
void bic_v8_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_v8_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_v8_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_context_method_V8Context_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_context_method_enter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_context_method_exit_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_context_method_global_object_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class V8_SCRIPT -
extern built_in_variable_s v8_script_variables[];
extern built_in_method_s v8_script_methods[];
extern built_in_class_s v8_script_class;

void bic_v8_script_consts(location_array_s &const_locations);
void bic_v8_script_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_v8_script_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_v8_script_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_script_method_compile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_script_method_run_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_script_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_script_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class V8_HEAP_STAT -
extern built_in_variable_s v8_heap_stat_variables[];
extern built_in_method_s v8_heap_stat_methods[];
extern built_in_class_s v8_heap_stat_class;

void bic_v8_heap_stat_consts(location_array_s &const_locations);
void bic_v8_heap_stat_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_v8_heap_stat_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_v8_heap_stat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_V8HeapStat_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_update_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_total_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_executable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_used_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_limit_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_heap_stat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class V8_OBJECT -
extern built_in_variable_s v8_object_variables[];
extern built_in_method_s v8_object_methods[];
extern built_in_class_s v8_object_class;

void bic_v8_object_consts(location_array_s &const_locations);
void bic_v8_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_v8_object_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_v8_object_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands);
bool bic_v8_object_member(interpreter_thread_s &it,uli *code,unsigned stack_base);

bool bic_v8_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_V8Object_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_has_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_has_own_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_get_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_set_prop_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_del_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_prop_names_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_own_prop_names_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_construct_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class V8_REFERENCE -
extern built_in_variable_s v8_reference_variables[];
extern built_in_method_s v8_reference_methods[];
extern built_in_class_s v8_reference_class;

void bic_v8_reference_consts(location_array_s &const_locations);
void bic_v8_reference_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_v8_reference_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_v8_reference_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_reference_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_v8_reference_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

