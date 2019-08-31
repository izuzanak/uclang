
#ifndef __LOGGER_MODULE_H
#define __LOGGER_MODULE_H

@begin
include "ucl_logger.h"
@end

// - LOGGER indexes of built in classes -
extern unsigned c_bi_class_logger;

// - LOGGER module -
extern "C" EXPORT built_in_module_s module;

// - LOGGER classes -
extern built_in_class_s *logger_classes[];

// - LOGGER error identifiers -
enum
{
  c_error_LOGGER_DUMMY_ERROR = 0,
};

// - LOGGER error strings -
extern const char *logger_error_strings[];

// - LOGGER initialize -
bool logger_initialize(script_parser_s &sp);

// - LOGGER print exception -
bool logger_print_exception(interpreter_s &it,exception_s &exception);

// - class LOGGER -
extern built_in_variable_s logger_variables[];
extern built_in_method_s logger_methods[];
extern built_in_class_s logger_class;

void bic_logger_consts(location_array_s &const_locations);
void bic_logger_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_logger_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_logger_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_logger_method_Logger_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_logger_method_add_file_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_logger_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_logger_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_logger_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

