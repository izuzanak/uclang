
#ifndef __LUA_MODULE_H
#define __LUA_MODULE_H

@begin
include "ucl_lua.h"
@end

// - LUA indexes of built in classes -
extern unsigned c_bi_class_lua_state;
extern unsigned c_bi_class_lua_value;
extern unsigned c_bi_class_lua_reference;

// - LUA module -
extern built_in_module_s module;

// - LUA classes -
extern built_in_class_s *lua_classes[];

// - LUA error identifiers -
enum
{
  c_error_LUA_STATE_CREATE_NEW_STATE_ERROR = 0,
  c_error_LUA_STATE_DO_STRING_ERROR,
  c_error_LUA_VALUE_CREATE_ERROR,
  c_error_LUA_VALUE_VALUE_ERROR,
  c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,
};

// - LUA error strings -
extern const char *lua_error_strings[];

// - LUA initialize -
bool lua_initialize(script_parser_s &sp);

// - LUA print exception -
bool lua_print_exception(interpreter_s &it,exception_s &exception);

// - class LUA_STATE -
extern built_in_variable_s lua_state_variables[];
extern built_in_method_s lua_state_methods[];
extern built_in_class_s lua_state_class;

void bic_lua_state_consts(location_array_s &const_locations);
void bic_lua_state_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_lua_state_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_lua_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_LuaState_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_do_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_new_value_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_get_global_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_get_global_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class LUA_VALUE -
extern built_in_variable_s lua_value_variables[];
extern built_in_method_s lua_value_methods[];
extern built_in_class_s lua_value_class;

void bic_lua_value_consts(location_array_s &const_locations);
void bic_lua_value_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_lua_value_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_lua_value_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands);
bool bic_lua_value_member(interpreter_thread_s &it,uli *code,unsigned stack_base);

bool bic_lua_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_value_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lua_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class LUA_REFERENCE -
extern built_in_variable_s lua_reference_variables[];
extern built_in_method_s lua_reference_methods[];
extern built_in_class_s lua_reference_class;

void bic_lua_reference_consts(location_array_s &const_locations);
void bic_lua_reference_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_lua_reference_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_lua_reference_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

