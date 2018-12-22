
#ifndef __FFTW_MODULE_H
#define __FFTW_MODULE_H

@begin
include "ucl_fftw.h"
@end

// - FFTW indexes of built in classes -
extern unsigned c_bi_class_fftw;
extern unsigned c_bi_class_fftw_plan;

// - FFTW module -
extern "C" EXPORT built_in_module_s module;

// - FFTW classes -
extern built_in_class_s *fftw_classes[];

// - FFTW error identifiers -
enum
{
  c_error_FFTW_DUMMY_ERROR = 0,
};

// - FFTW error strings -
extern const char *fftw_error_strings[];

// - FFTW initialize -
bool fftw_initialize(script_parser_s &sp);

// - FFTW print exception -
bool fftw_print_exception(interpreter_s &it,exception_s &exception);

// - class FFTW -
extern built_in_variable_s fftw_variables[];
extern built_in_method_s fftw_methods[];
extern built_in_class_s fftw_class;

void bic_fftw_consts(location_array_s &const_locations);
void bic_fftw_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fftw_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fftw_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fftw_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fftw_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FFTW_PLAN -
extern built_in_variable_s fftw_plan_variables[];
extern built_in_method_s fftw_plan_methods[];
extern built_in_class_s fftw_plan_class;

void bic_fftw_plan_consts(location_array_s &const_locations);
void bic_fftw_plan_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fftw_plan_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fftw_plan_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fftw_plan_method_FftwPlan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fftw_plan_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fftw_plan_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

