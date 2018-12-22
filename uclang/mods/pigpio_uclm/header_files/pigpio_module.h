
#ifndef __PIGPIO_MODULE_H
#define __PIGPIO_MODULE_H

@begin
include "ucl_pigpio.h"
@end

// - PIGPIO indexes of built in classes -
extern unsigned c_bi_class_pigpio;

// - PIGPIO module -
extern "C" EXPORT built_in_module_s module;

// - PIGPIO classes -
extern built_in_class_s *pigpio_classes[];

// - PIGPIO error identifiers -
enum
{
  c_error_PIGPIO_DUMMY_ERROR = 0,
};

// - PIGPIO error strings -
extern const char *pigpio_error_strings[];

// - PIGPIO initialize -
bool pigpio_initialize(script_parser_s &sp);

// - PIGPIO print exception -
bool pigpio_print_exception(interpreter_s &it,exception_s &exception);

// - class PIGPIO -
extern built_in_variable_s pigpio_variables[];
extern built_in_method_s pigpio_methods[];
extern built_in_class_s pigpio_class;

void bic_pigpio_consts(location_array_s &const_locations);
void bic_pigpio_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pigpio_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pigpio_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pigpio_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

