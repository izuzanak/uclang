
#ifndef __RUBY_MODULE_H
#define __RUBY_MODULE_H

@begin
include "ucl_ruby.h"
@end

// - RUBY indexes of built in classes -
extern unsigned c_bi_class_ruby_interpreter;
extern unsigned c_bi_class_ruby_value;

// - RUBY module -
extern built_in_module_s module;

// - RUBY classes -
extern built_in_class_s *ruby_classes[];

// - RUBY error identifiers -
enum
{
  c_error_RUBY_INTERPRETER_PROCESS_CODE_ERROR = 0,
  c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,
  c_error_RUBY_VALUE_CREATE_ERROR,
  c_error_RUBY_VALUE_VALUE_ERROR,
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
bool bic_ruby_interpreter_method_gv_set_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_interpreter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

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
bool bic_ruby_value_method_RubyValue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ruby_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

