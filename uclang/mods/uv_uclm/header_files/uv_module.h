
#ifndef __UV_MODULE_H
#define __UV_MODULE_H

@begin
include "ucl_uv.h"
@end

// - UV indexes of built in classes -
extern unsigned c_bi_class_uv_loop;

// - UV module -
extern "C" IMPORT built_in_module_s module;

// - UV classes -
extern built_in_class_s *uv_classes[];

// - UV error identifiers -
enum
{
  c_error_UV_DUMMY_ERROR = 0,
};

// - UV error strings -
extern const char *uv_error_strings[];

// - UV initialize -
bool uv_initialize(script_parser_s &sp);

// - UV print exception -
bool uv_print_exception(interpreter_s &it,exception_s &exception);

// - class UV_LOOP -
extern built_in_variable_s uv_loop_variables[];
extern built_in_method_s uv_loop_methods[];
extern built_in_class_s uv_loop_class;

void bic_uv_loop_consts(location_array_s &const_locations);
void bic_uv_loop_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_uv_loop_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_uv_loop_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_uv_loop_method_UvLoop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_uv_loop_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_uv_loop_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

