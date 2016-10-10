
#ifndef __PERL_MODULE_H
#define __PERL_MODULE_H

@begin
include "ucl_perl.h"
@end

// - PERL indexes of built in classes -
extern unsigned c_bi_class_perl_interpreter;
extern unsigned c_bi_class_perl_value;

// - PERL module -
extern built_in_module_s module;

// - PERL classes -
extern built_in_class_s *perl_classes[];

// - PERL error identifiers -
enum
{
  c_error_PERL_INTERPRETER_TOO_FEW_ARGUMENTS = 0,
  c_error_PERL_INTERPRETER_NO_STRING_ARGUMENT,
  c_error_PERL_INTERPRETER_PARSE_ERROR,
  c_error_PERL_INTERPRETER_RUN_ERROR,
  c_error_PERL_VALUE_WRONG_VALUE_REFERENCE,
  c_error_PERL_VALUE_CREATE_ERROR,
  c_error_PERL_VALUE_VALUE_ERROR,
  c_error_PERL_VALUE_GET_VARIABLE_DOES_NOT_EXIST,
};

// - PERL error strings -
extern const char *perl_error_strings[];

// - PERL initialize -
bool perl_initialize(script_parser_s &sp);

// - PERL print exception -
bool perl_print_exception(interpreter_s &it,exception_s &exception);

// - class PERL_INTERPRETER -
extern built_in_variable_s perl_interpreter_variables[];
extern built_in_method_s perl_interpreter_methods[];
extern built_in_class_s perl_interpreter_class;

void bic_perl_interpreter_consts(location_array_s &const_locations);
void bic_perl_interpreter_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_perl_interpreter_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_perl_interpreter_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_PerlInterpreter_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_new_value_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_get_sv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_get_av_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_get_hv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_interpreter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PERL_VALUE -
extern built_in_variable_s perl_value_variables[];
extern built_in_method_s perl_value_methods[];
extern built_in_class_s perl_value_class;

void bic_perl_value_consts(location_array_s &const_locations);
void bic_perl_value_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_perl_value_clear(interpreter_thread_s &it,location_s *location_ptr);
//bool bic_perl_value_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands);
//bool bic_perl_value_member(interpreter_thread_s &it,uli *code,unsigned stack_base);

bool bic_perl_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_value_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_perl_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

