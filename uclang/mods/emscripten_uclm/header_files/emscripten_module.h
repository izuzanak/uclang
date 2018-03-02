
#ifndef __EMSCRIPTEN_MODULE_H
#define __EMSCRIPTEN_MODULE_H

@begin
include "ucl_emscripten.h"
@end

// - EMSCRIPTEN indexes of built in classes -
extern unsigned c_bi_class_emscripten;

// - EMSCRIPTEN module -
extern built_in_module_s module;

// - EMSCRIPTEN classes -
extern built_in_class_s *emscripten_classes[];

// - EMSCRIPTEN error identifiers -
enum
{
  c_error_EMSCRIPTEN_DUMMY_ERROR,
};

// - EMSCRIPTEN error strings -
extern const char *emscripten_error_strings[];

// - EMSCRIPTEN initialize -
bool emscripten_initialize(script_parser_s &sp);

// - EMSCRIPTEN print exception -
bool emscripten_print_exception(interpreter_s &it,exception_s &exception);

// - class EMSCRIPTEN -
extern built_in_variable_s emscripten_variables[];
extern built_in_method_s emscripten_methods[];
extern built_in_class_s emscripten_class;

void bic_emscripten_consts(location_array_s &const_locations);
void bic_emscripten_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_emscripten_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_emscripten_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_emscripten_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

