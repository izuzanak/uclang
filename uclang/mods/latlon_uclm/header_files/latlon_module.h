
#ifndef __LATLON_MODULE_H
#define __LATLON_MODULE_H

@begin
include "ucl_latlon.h"
@end

// - LATLON indexes of built in classes -
extern unsigned c_bi_class_latlon;

// - LATLON module -
extern "C" EXPORT built_in_module_s module;

// - LATLON classes -
extern built_in_class_s *latlon_classes[];

// - LATLON error identifiers -
enum
{
  c_error_LATLON_DUMMY_ERROR = 0,
};

// - LATLON error strings -
extern const char *latlon_error_strings[];

// - LATLON initialize -
bool latlon_initialize(script_parser_s &sp);

// - LATLON print exception -
bool latlon_print_exception(interpreter_s &it,exception_s &exception);

// - class LATLON -
extern built_in_variable_s latlon_variables[];
extern built_in_method_s latlon_methods[];
extern built_in_class_s latlon_class;

void bic_latlon_consts(location_array_s &const_locations);
void bic_latlon_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_latlon_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_latlon_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_LatLon_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_lat_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_lon_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_distance_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_angle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_latlon_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

