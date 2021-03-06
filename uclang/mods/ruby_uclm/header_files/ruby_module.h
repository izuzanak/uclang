
#ifndef __RUBY_MODULE_H
#define __RUBY_MODULE_H

@begin
include "ucl_ruby.h"
@end

// - RUBY indexes of built in classes -
extern unsigned c_bi_class_ruby_interpreter;
extern unsigned c_bi_class_ruby_symbol;
extern unsigned c_bi_class_ruby_value;
extern unsigned c_bi_class_ruby_iv_ref;
extern unsigned c_bi_class_ruby_item_ref;

// - RUBY module -
extern "C" EXPORT built_in_module_s module;

// - RUBY classes -
extern built_in_class_s *ruby_classes[];

// - RUBY error identifiers -
enum
{
  c_error_RUBY_INTERPRETER_PROCESS_CODE_ERROR = 0,
  c_error_RUBY_VALUE_INVOKE_METHOD_ERROR,
  c_error_RUBY_VALUE_INVOKE_METHOD_WRONG_PARAMETER,
  c_error_RUBY_VALUE_ITEM_SELECT_ERROR,
  c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,
  c_error_RUBY_VALUE_CREATE_ERROR,
  c_error_RUBY_VALUE_VALUE_ERROR,
  c_error_RUBY_VALUE_SET_INSTANCE_VALUE_ERROR,
  c_error_RUBY_VALUE_SET_ITEM_ERROR,
};

// - RUBY error strings -
extern const char *ruby_error_strings[];

// - RUBY initialize -
bool ruby_initialize(script_parser_s &sp);

// - RUBY print exception -
bool ruby_print_exception(interpreter_s &it,exception_s &exception);

// - class RUBY_INTERPRETER -
extern built_in_variable_s ruby_interpreter_variables[];
extern built_in_method_s ruby_interpreter_methods[];
extern built_in_class_s ruby_interpreter_class;

void bic_ruby_interpreter_consts(location_array_s &const_locations);
void bic_ruby_interpreter_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ruby_interpreter_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ruby_interpreter_method_eval_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_require_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_gv_get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RUBY_SYMBOL -
extern built_in_variable_s ruby_symbol_variables[];
extern built_in_method_s ruby_symbol_methods[];
extern built_in_class_s ruby_symbol_class;

void bic_ruby_symbol_consts(location_array_s &const_locations);
void bic_ruby_symbol_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ruby_symbol_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ruby_symbol_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_symbol_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_symbol_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RUBY_VALUE -
extern built_in_variable_s ruby_value_variables[];
extern built_in_method_s ruby_value_methods[];
extern built_in_class_s ruby_value_class;

void bic_ruby_value_consts(location_array_s &const_locations);
void bic_ruby_value_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ruby_value_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_ruby_value_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands);
bool bic_ruby_value_member(interpreter_thread_s &it,uli *code,unsigned stack_base);

bool bic_ruby_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method_RubyValue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method__new_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method__value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RUBY_IV_REF -
extern built_in_variable_s ruby_iv_ref_variables[];
extern built_in_method_s ruby_iv_ref_methods[];
extern built_in_class_s ruby_iv_ref_class;

void bic_ruby_iv_ref_consts(location_array_s &const_locations);
void bic_ruby_iv_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ruby_iv_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ruby_iv_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RUBY_ITEM_REF -
extern built_in_variable_s ruby_item_ref_variables[];
extern built_in_method_s ruby_item_ref_methods[];
extern built_in_class_s ruby_item_ref_class;

void bic_ruby_item_ref_consts(location_array_s &const_locations);
void bic_ruby_item_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ruby_item_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ruby_item_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

