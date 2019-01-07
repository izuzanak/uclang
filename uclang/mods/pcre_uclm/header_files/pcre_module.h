
#ifndef __PCRE_MODULE_H
#define __PCRE_MODULE_H

@begin
include "ucl_pcre.h"
@end

// - PCRE indexes of built in classes -
extern unsigned c_bi_class_pcre;

// - PCRE module -
extern "C" EXPORT built_in_module_s module;

// - PCRE classes -
extern built_in_class_s *pcre_classes[];

// - PCRE error identifiers -
enum
{
  c_error_PCRE_COMPILE_ERROR = 0,
  c_error_PCRE_NOT_COMPILED,
  c_error_PCRE_WRONG_MATCH_COUNT,
  c_error_PCRE_WRONG_MATCH_OFFSET,
  c_error_PCRE_STRING_SPLIT_EMPTY_MATCH,
};

// - PCRE error strings -
extern const char *pcre_error_strings[];

// - PCRE initialize -
bool pcre_initialize(script_parser_s &sp);

// - PCRE print exception -
bool pcre_print_exception(interpreter_s &it,exception_s &exception);

// - class PCRE -
extern built_in_variable_s pcre_variables[];
extern built_in_method_s pcre_methods[];
extern built_in_class_s pcre_class;

void bic_pcre_consts(location_array_s &const_locations);
void bic_pcre_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pcre_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pcre_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_Pcre_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_match_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_match_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_match_from_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_split_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_replace_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pcre_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

