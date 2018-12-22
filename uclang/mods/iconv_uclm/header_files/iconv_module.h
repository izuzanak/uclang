
#ifndef __ICONV_MODULE_H
#define __ICONV_MODULE_H

@begin
include "ucl_iconv.h"
@end

// - ICONV indexes of built in classes -
extern unsigned c_bi_class_iconv;

// - ICONV module -
extern "C" EXPORT built_in_module_s module;

// - ICONV classes -
extern built_in_class_s *iconv_classes[];

// - ICONV error identifiers -
enum
{
  c_error_ICONV_OPEN_ERROR = 0,
  c_error_ICONV_CONVERT_INVALID_INPUT,
};

// - ICONV error strings -
extern const char *iconv_error_strings[];

// - ICONV initialize -
bool iconv_initialize(script_parser_s &sp);

// - ICONV print exception -
bool iconv_print_exception(interpreter_s &it,exception_s &exception);

// - class ICONV -
extern built_in_variable_s iconv_variables[];
extern built_in_method_s iconv_methods[];
extern built_in_class_s iconv_class;

void bic_iconv_consts(location_array_s &const_locations);
void bic_iconv_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_iconv_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_iconv_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_iconv_method_Iconv_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_iconv_method_convert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_iconv_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_iconv_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

