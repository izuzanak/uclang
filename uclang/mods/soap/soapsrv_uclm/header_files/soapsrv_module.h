
#ifndef __SOAPSRV_MODULE_H
#define __SOAPSRV_MODULE_H

@begin
include "ucl_soapsrv.h"
@end

#include "calc.nsmap"

// - SOAPSRV indexes of built in classes -
extern unsigned c_bi_class_calc_service;
extern unsigned c_bi_class_soap_fault;

// - SOAPSRV module -
extern "C" EXPORT built_in_module_s module;

// - SOAPSRV classes -
extern built_in_class_s *soapsrv_classes[];

// - SOAPSRV error identifiers -
enum
{
  c_error_GSOAP_CALL_FAULT = 0,
  c_error_GSOAP_SERVICE_BIND_ERROR,
  c_error_GSOAP_SERVICE_ACCEPT_ERROR,
  c_error_GSOAP_WRONG_CALLBACK_DELEGATE,
};

// - SOAPSRV error strings -
extern const char *soapsrv_error_strings[];

// - SOAPSRV initialize -
bool soapsrv_initialize(script_parser_s &sp);

// - SOAPSRV print exception -
bool soapsrv_print_exception(interpreter_s &it,exception_s &exception);

// - class CALC_SERVICE -
extern built_in_variable_s calc_service_variables[];
extern built_in_method_s calc_service_methods[];
extern built_in_class_s calc_service_class;

void bic_calc_service_consts(location_array_s &const_locations);
void bic_calc_service_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_calc_service_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_calc_service_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_CalcService_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_CalcService_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_ns__add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_ns__sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_ns__sqrt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_calc_service_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SOAP_FAULT -
extern built_in_variable_s soap_fault_variables[];
extern built_in_method_s soap_fault_methods[];
extern built_in_class_s soap_fault_class;

void bic_soap_fault_consts(location_array_s &const_locations);
void bic_soap_fault_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_soap_fault_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_soap_fault_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_soap_fault_method_SoapFault_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_soap_fault_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_soap_fault_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

