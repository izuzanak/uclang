
#ifndef __SERIAL_MODULE_H
#define __SERIAL_MODULE_H

@begin
include "ucl_serial.h"
@end

// - SERIAL indexes of built in classes -
extern unsigned c_bi_class_serial;

// - SERIAL module -
extern "C" EXPORT built_in_module_s module;

// - SERIAL classes -
extern built_in_class_s *serial_classes[];

// - SERIAL error identifiers -
enum
{
  c_error_SERIAL_OPEN_ERROR = 0,
  c_error_SERIAL_SETUP_ERROR,
};

// - SERIAL error strings -
extern const char *serial_error_strings[];

// - SERIAL initialize -
bool serial_initialize(script_parser_s &sp);

// - SERIAL print exception -
bool serial_print_exception(interpreter_s &it,exception_s &exception);

// - class SERIAL -
extern built_in_variable_s serial_variables[];
extern built_in_method_s serial_methods[];
extern built_in_class_s serial_class;

void bic_serial_consts(location_array_s &const_locations);
void bic_serial_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_serial_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_serial_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_Serial_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_set_format_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_serial_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_serial_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

