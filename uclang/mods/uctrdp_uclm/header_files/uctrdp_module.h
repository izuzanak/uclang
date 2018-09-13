
#ifndef __UCTRDP_MODULE_H
#define __UCTRDP_MODULE_H

@begin
include "ucl_uctrdp.h"
@end

// - UCTRDP indexes of built in classes -
extern unsigned c_bi_class_trdp_pd;

// - UCTRDP module -
extern built_in_module_s module;

// - UCTRDP classes -
extern built_in_class_s *uctrdp_classes[];

// - UCTRDP error identifiers -
enum
{
  c_error_TRDP_PD_INITIALIZE_ERROR = 0,
};

// - UCTRDP error strings -
extern const char *uctrdp_error_strings[];

// - UCTRDP initialize -
bool uctrdp_initialize(script_parser_s &sp);

// - UCTRDP print exception -
bool uctrdp_print_exception(interpreter_s &it,exception_s &exception);

// - class TRDP_PD -
extern built_in_variable_s trdp_pd_variables[];
extern built_in_method_s trdp_pd_methods[];
extern built_in_class_s trdp_pd_class;

void bic_trdp_pd_consts(location_array_s &const_locations);
void bic_trdp_pd_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_pd_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_pd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_TrdpPd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

