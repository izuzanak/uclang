
#ifndef __CURSES_MODULE_H
#define __CURSES_MODULE_H

@begin
include "ucl_curses.h"
@end

// - CURSES indexes of built in classes -
extern unsigned c_bi_class_curses;

// - CURSES module -
extern "C" EXPORT built_in_module_s module;

// - CURSES classes -
extern built_in_class_s *curses_classes[];

// - CURSES error identifiers -
enum
{
  c_error_CURSES_DUMMY_ERROR = 0,
};

// - CURSES error strings -
extern const char *curses_error_strings[];

// - CURSES initialize -
bool curses_initialize(script_parser_s &sp);

// - CURSES print exception -
bool curses_print_exception(interpreter_s &it,exception_s &exception);

// - class CURSES -
extern built_in_variable_s curses_variables[];
extern built_in_method_s curses_methods[];
extern built_in_class_s curses_class;

void bic_curses_consts(location_array_s &const_locations);
void bic_curses_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_curses_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_curses_method_dummy_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curses_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_curses_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

