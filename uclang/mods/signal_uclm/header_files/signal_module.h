
#ifndef __SIGNAL_MODULE_H
#define __SIGNAL_MODULE_H

@begin
include "ucl_signal.h"
@end

// - SIGNAL indexes of built in classes -
extern unsigned c_bi_class_data_signal;

// - SIGNAL module -
extern "C" EXPORT built_in_module_s module;

// - SIGNAL classes -
extern built_in_class_s *signal_classes[];

// - SIGNAL error identifiers -
enum
{
  c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS = 0,
  c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS_DIMENSION,
  c_error_SIGNAL_SEARCH_INVALID_PARAMETERS,
};

// - SIGNAL error strings -
extern const char *signal_error_strings[];

// - SIGNAL initialize -
bool signal_initialize(script_parser_s &sp);

// - SIGNAL print exception -
bool signal_print_exception(interpreter_s &it,exception_s &exception);

// - class DATA_SIGNAL -
extern built_in_variable_s data_signal_variables[];
extern built_in_method_s data_signal_methods[];
extern built_in_class_s data_signal_class;

void bic_data_signal_consts(location_array_s &const_locations);
void bic_data_signal_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_data_signal_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_data_signal_method_search_6(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_data_signal_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_data_signal_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

