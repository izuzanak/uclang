
#ifndef __REGEX_MODULE_H
#define __REGEX_MODULE_H

@begin
include "ucl_regex.h"
@end

// - REGEX indexes of built in classes -
extern unsigned c_bi_class_regex;

// - REGEX module -
extern "C" EXPORT built_in_module_s module;

// - REGEX classes -
extern built_in_class_s *regex_classes[];

// - REGEX error identifiers -
enum
{
  c_error_REGEX_COMPILE_ERROR = 0,
  c_error_REGEX_NOT_COMPILED,
  c_error_REGEX_WRONG_MATCH_COUNT,
  c_error_REGEX_WRONG_MATCH_OFFSET,
  c_error_REGEX_UNEXPECTED_EMPTY_MATCH,
};

// - REGEX error strings -
extern const char *regex_error_strings[];

// - REGEX initialize -
bool regex_initialize(script_parser_s &sp);

// - REGEX print exception -
bool regex_print_exception(interpreter_s &it,exception_s &exception);

// - class REGEX -
extern built_in_variable_s regex_variables[];
extern built_in_method_s regex_methods[];
extern built_in_class_s regex_class;

void bic_regex_consts(location_array_s &const_locations);
void bic_regex_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_regex_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_regex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_Regex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_match_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_match_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_match_from_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_split_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_replace_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_regex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

