
#ifndef __AMANITHVG_MODULE_H
#define __AMANITHVG_MODULE_H

@begin
include "ucl_amanithvg.h"
@end

// - AMANITHVG indexes of built in classes -
extern unsigned c_bi_class_amanith_vg_context;
extern unsigned c_bi_class_amanith_vg_surface;

// - AMANITHVG module -
extern built_in_module_s module;

// - AMANITHVG classes -
extern built_in_class_s *amanithvg_classes[];

// - AMANITHVG error identifiers -
enum
{
  c_error_AMANITH_VG_CONTEXT_CREATE_ERROR = 0,
  c_error_AMANITH_VG_CONTEXT_MAKE_CURRENT_ERROR,
  c_error_AMANITH_VG_CONTEXT_DROP_CURRENT_ERROR,
  c_error_AMANITH_VG_CONTEXT_CURRENT_DOES_NOT_EXIST,
  c_error_AMANITH_VG_SURFACE_CREATE_ERROR,
  c_error_AMANITH_VG_SURFACE_CURRENT_DOES_NOT_EXIST,
};

// - AMANITHVG error strings -
extern const char *amanithvg_error_strings[];

// - AMANITHVG initialize -
bool amanithvg_initialize(script_parser_s &sp);

// - AMANITHVG print exception -
bool amanithvg_print_exception(interpreter_s &it,exception_s &exception);

// - class AMANITH_VG_CONTEXT -
extern built_in_variable_s amanith_vg_context_variables[];
extern built_in_method_s amanith_vg_context_methods[];
extern built_in_class_s amanith_vg_context_class;

void bic_amanith_vg_context_consts(location_array_s &const_locations);
void bic_amanith_vg_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_amanith_vg_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_amanith_vg_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_context_method_AmanithVgContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_context_method_make_current_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_context_method_drop_current_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_context_method_current_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AMANITH_VG_SURFACE -
extern built_in_variable_s amanith_vg_surface_variables[];
extern built_in_method_s amanith_vg_surface_methods[];
extern built_in_class_s amanith_vg_surface_class;

void bic_amanith_vg_surface_consts(location_array_s &const_locations);
void bic_amanith_vg_surface_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_amanith_vg_surface_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_amanith_vg_surface_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_AmanithVgSurface_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_current_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_max_dimension_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_resize_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_amanith_vg_surface_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

