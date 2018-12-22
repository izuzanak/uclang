
#ifndef __GSL_MODULE_H
#define __GSL_MODULE_H

@begin
include "ucl_gsl.h"
@end

// - GSL indexes of built in classes -
extern unsigned c_bi_class_gsl_spline;

// - GSL module -
extern "C" IMPORT built_in_module_s module;

// - GSL classes -
extern built_in_class_s *gsl_classes[];

// - GSL error identifiers -
enum
{
  c_error_GSL_INVALID_DATA_VALUE_TYPE = 0,
  c_error_GSL_SPLINE_UNKNOWN_INTERP_TYPE,
  c_error_GSL_SPLINE_INVALID_DATA_LENGTHS,
  c_error_GSL_SPLINE_CREATE_ERROR,
  c_error_GSL_SPLINE_EVAL_ERROR,
};

// - GSL error strings -
extern const char *gsl_error_strings[];

// - GSL initialize -
bool gsl_initialize(script_parser_s &sp);

// - GSL print exception -
bool gsl_print_exception(interpreter_s &it,exception_s &exception);

// - class GSL_SPLINE -
extern built_in_variable_s gsl_spline_variables[];
extern built_in_method_s gsl_spline_methods[];
extern built_in_class_s gsl_spline_class;

void bic_gsl_spline_consts(location_array_s &const_locations);
void bic_gsl_spline_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gsl_spline_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gsl_spline_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gsl_spline_method_GslSpline_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gsl_spline_method_eval_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gsl_spline_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gsl_spline_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

