
#ifndef __TZONE_MODULE_H
#define __TZONE_MODULE_H

@begin
include "ucl_tzone.h"
@end

// - TZONE indexes of built in classes -
extern unsigned c_bi_class_time_zone;

// - TZONE module -
extern "C" EXPORT built_in_module_s module;

// - TZONE classes -
extern built_in_class_s *tzone_classes[];

// - TZONE error identifiers -
enum
{
  c_error_TIME_ZONE_PARSE_ERROR = 0,
  c_error_TIME_ZONE_TO_UTC_ERROR,
};

// - TZONE error strings -
extern const char *tzone_error_strings[];

// - TZONE initialize -
bool tzone_initialize(script_parser_s &sp);

// - TZONE print exception -
bool tzone_print_exception(interpreter_s &it,exception_s &exception);

// - class TIME_ZONE -
extern built_in_variable_s time_zone_variables[];
extern built_in_method_s time_zone_methods[];
extern built_in_class_s time_zone_class;

void bic_time_zone_consts(location_array_s &const_locations);
void bic_time_zone_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_time_zone_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_time_zone_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_zone_method_TimeZone_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_zone_method_to_local_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_zone_method_to_utc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_zone_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_zone_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

