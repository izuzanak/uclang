
#ifndef __SOAPCL_MODULE_H
#define __SOAPCL_MODULE_H

@begin
include "ucl_soapcl.h"
@end

#include "calc.nsmap"

// - SOAPCL indexes of built in classes -
extern unsigned c_bi_class_calc_client;

// - SOAPCL module -
extern built_in_module_s module;

// - SOAPCL classes -
extern built_in_class_s *soapcl_classes[];

// - SOAPCL error identifiers -
enum
{
  c_error_GSOAP_CLIENT_CALL_FAULT = 0
};

// - SOAPCL error strings -
extern const char *soapcl_error_strings[];

// - SOAPCL initialize -
bool soapcl_initialize(script_parser_s &sp);

// - SOAPCL print exception -
bool soapcl_print_exception(interpreter_s &it,exception_s &exception);

// - class CALC_CLIENT -
extern built_in_variable_s calc_client_variables[];
extern built_in_method_s calc_client_methods[];
extern built_in_class_s calc_client_class;

void bic_calc_client_consts(location_array_s &const_locations);
void bic_calc_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_calc_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_calc_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_CalcClient_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_CalcClient_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_endpoint_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_add_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_sub_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_sqrt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

