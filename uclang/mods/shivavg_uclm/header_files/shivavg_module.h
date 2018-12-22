
#ifndef __SHIVAVG_MODULE_H
#define __SHIVAVG_MODULE_H

@begin
include "ucl_shivavg.h"
@end

// - SHIVAVG indexes of built in classes -
extern unsigned c_bi_class_shiva_vg;

// - SHIVAVG module -
extern "C" IMPORT built_in_module_s module;

// - SHIVAVG classes -
extern built_in_class_s *shivavg_classes[];

// - SHIVAVG error identifiers -
enum
{
  c_error_SHIVA_VG_CONTEXT_ALREADY_CREATED = 0,
  c_error_SHIVA_VG_CONTEXT_CREATE_ERROR,
};

// - SHIVAVG error strings -
extern const char *shivavg_error_strings[];

// - SHIVAVG initialize -
bool shivavg_initialize(script_parser_s &sp);

// - SHIVAVG print exception -
bool shivavg_print_exception(interpreter_s &it,exception_s &exception);

// - class SHIVA_VG -
extern built_in_variable_s shiva_vg_variables[];
extern built_in_method_s shiva_vg_methods[];
extern built_in_class_s shiva_vg_class;

void bic_shiva_vg_consts(location_array_s &const_locations);
void bic_shiva_vg_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_shiva_vg_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_shiva_vg_method_create_context_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shiva_vg_method_resize_surface_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shiva_vg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shiva_vg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

