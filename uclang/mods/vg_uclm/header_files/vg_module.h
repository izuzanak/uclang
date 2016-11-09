
#ifndef __VG_MODULE_H
#define __VG_MODULE_H

@begin
include "ucl_vg.h"
@end

// - VG indexes of built in classes -
extern unsigned c_bi_class_vg;
extern unsigned c_bi_class_vg_paint;
extern unsigned c_bi_class_vg_path;

// - VG module -
extern built_in_module_s module;

// - VG classes -
extern built_in_class_s *vg_classes[];

// - VG error identifiers -
enum
{
  c_error_VG_UNKNOWN_STROKE_CAP_STYLE = 0,
  c_error_VG_UNKNOWN_STROKE_JOIN_STYLE,
  c_error_VG_WRONG_DASH_PATTERN_ARRAY_CONTENT,
  c_error_VG_PAINT_UNKNOWN_PAINT_TYPE,
  c_error_VG_PAINT_WRONG_TARGET_PAINT_MODES,
  c_error_VG_PAINT_WRONG_SOURCE_PAINT_MODE,
};

// - VG error strings -
extern const char *vg_error_strings[];

// - VG initialize -
bool vg_initialize(script_parser_s &sp);

// - VG print exception -
bool vg_print_exception(interpreter_s &it,exception_s &exception);

// - class VG -
extern built_in_variable_s vg_variables[];
extern built_in_method_s vg_methods[];
extern built_in_class_s vg_class;

void bic_vg_consts(location_array_s &const_locations);
void bic_vg_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vg_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_vg_method_Clear_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_ClearColor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_StrokeLineWidth_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_StrokeCapStyle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_StrokeJoinStyle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_StrokeDashPattern_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_LoadIdentity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_Translate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_Scale_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_Shear_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_Rotate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_Finish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VG_PAINT -
extern built_in_variable_s vg_paint_variables[];
extern built_in_method_s vg_paint_methods[];
extern built_in_class_s vg_paint_class;

void bic_vg_paint_consts(location_array_s &const_locations);
void bic_vg_paint_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vg_paint_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_vg_paint_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_VgPaint_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_VgPaint_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_Type_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_Color_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_Set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_Get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_paint_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VG_PATH -
extern built_in_variable_s vg_path_variables[];
extern built_in_method_s vg_path_methods[];
extern built_in_class_s vg_path_class;

void bic_vg_path_consts(location_array_s &const_locations);
void bic_vg_path_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vg_path_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_vg_path_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_VgPath_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_VgPath_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_MoveTo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_MoveTo_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_LineTo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_LineTo_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_CloseSubpath_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_Draw_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vg_path_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

