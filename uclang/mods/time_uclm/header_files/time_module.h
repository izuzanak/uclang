
#ifndef __TIME_MODULE_H
#define __TIME_MODULE_H

@begin
include "script_parser.h"
@end

// - TIME indexes of built in classes -
extern unsigned c_bi_class_time;

// - TIME module -
extern "C" EXPORT built_in_module_s module;

// - TIME classes -
extern built_in_class_s *time_classes[];

// - TIME error identifiers -
enum
{
  c_error_TIME_WRONG_INIT_STRING = 0,
};

// - TIME error strings -
extern const char *time_error_strings[];

// - TIME initialize -
bool time_initialize(script_parser_s &sp);

// - TIME print exception -
bool time_print_exception(interpreter_s &it,exception_s &exception);

// - class TIME -
extern built_in_variable_s time_variables[];
extern built_in_method_s time_methods[];
extern built_in_class_s time_class;

void bic_time_consts(location_array_s &const_locations);
void bic_time_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_time_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_time_compare(location_s *first_loc,location_s *second_loc);

bool bic_time_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_Time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_Time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_nano_sec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_micro_sec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_milli_sec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_seconds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_minutes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_hours_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_days_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_datetime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

