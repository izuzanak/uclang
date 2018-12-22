
#ifndef __READLINE_MODULE_H
#define __READLINE_MODULE_H

@begin
include "ucl_readline.h"
@end

// - READLINE indexes of built in classes -
extern unsigned c_bi_class_readline;

// - READLINE module -
extern "C" EXPORT built_in_module_s module;

// - READLINE classes -
extern built_in_class_s *readline_classes[];

// - READLINE error identifiers -
enum
{
  c_error_READLINE_DUMMY_ERROR = 0,
};

// - READLINE error strings -
extern const char *readline_error_strings[];

// - READLINE initialize -
bool readline_initialize(script_parser_s &sp);

// - READLINE print exception -
bool readline_print_exception(interpreter_s &it,exception_s &exception);

// - class READLINE -
extern built_in_variable_s readline_variables[];
extern built_in_method_s readline_methods[];
extern built_in_class_s readline_class;

void bic_readline_consts(location_array_s &const_locations);
void bic_readline_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_readline_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_readline_method_readline_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_readline_method_add_history_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_readline_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_readline_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

