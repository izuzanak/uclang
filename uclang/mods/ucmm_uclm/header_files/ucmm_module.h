
#ifndef __UCMM_MODULE_H
#define __UCMM_MODULE_H

@begin
include "ucl_ucmm.h"
@end

// - UCMM indexes of built in classes -
extern unsigned c_bi_class_modem_manager;

// - UCMM module -
extern built_in_module_s module;

// - UCMM classes -
extern built_in_class_s *ucmm_classes[];

// - UCMM error identifiers -
enum
{
  c_error_UCMM_DUMMY_ERROR = 0,
};

// - UCMM error strings -
extern const char *ucmm_error_strings[];

// - UCMM initialize -
bool ucmm_initialize(script_parser_s &sp);

// - UCMM print exception -
bool ucmm_print_exception(interpreter_s &it,exception_s &exception);

// - class MODEM_MANAGER -
extern built_in_variable_s modem_manager_variables[];
extern built_in_method_s modem_manager_methods[];
extern built_in_class_s modem_manager_class;

void bic_modem_manager_consts(location_array_s &const_locations);
void bic_modem_manager_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_modem_manager_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_modem_manager_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_ModemManager_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_modem_manager_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

