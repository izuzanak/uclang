
#ifndef __FREETYPE2_MODULE_H
#define __FREETYPE2_MODULE_H

@begin
include "ucl_freetype2.h"
@end

// - FREETYPE2 indexes of built in classes -
extern unsigned c_bi_class_ft2_library;
extern unsigned c_bi_class_ft2_face;
extern unsigned c_bi_class_ft2_bitmap;

// - FREETYPE2 module -
extern "C" EXPORT built_in_module_s module;

// - FREETYPE2 classes -
extern built_in_class_s *freetype2_classes[];

// - FREETYPE2 error identifiers -
enum
{
  c_error_FREETYPE2_LIBRARY_INIT_ERROR = 0,
  c_error_FREETYPE2_LIBRARY_NEW_FACE_ERROR,
  c_error_FREETYPE2_FACE_INVALID_TEXT_HEIGHT,
  c_error_FREETYPE2_FACE_SELECT_CHARMAP_ERROR,
  c_error_FREETYPE2_FACE_PIXEL_SIZES_ERROR,
  c_error_FREETYPE2_FACE_MEASURE_TEXT_ERROR,
  c_error_FREETYPE2_FACE_RENDER_TEXT_ERROR,
};

// - FREETYPE2 error strings -
extern const char *freetype2_error_strings[];

// - FREETYPE2 initialize -
bool freetype2_initialize(script_parser_s &sp);

// - FREETYPE2 print exception -
bool freetype2_print_exception(interpreter_s &it,exception_s &exception);

// - class FT2_LIBRARY -
extern built_in_variable_s ft2_library_variables[];
extern built_in_method_s ft2_library_methods[];
extern built_in_class_s ft2_library_class;

void bic_ft2_library_consts(location_array_s &const_locations);
void bic_ft2_library_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ft2_library_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ft2_library_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_library_method_Ft2Library_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_library_method_face_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_library_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_library_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FT2_FACE -
extern built_in_variable_s ft2_face_variables[];
extern built_in_method_s ft2_face_methods[];
extern built_in_class_s ft2_face_class;

void bic_ft2_face_consts(location_array_s &const_locations);
void bic_ft2_face_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ft2_face_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ft2_face_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_face_method_render_text_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_face_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_face_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FT2_BITMAP -
extern built_in_variable_s ft2_bitmap_variables[];
extern built_in_method_s ft2_bitmap_methods[];
extern built_in_class_s ft2_bitmap_class;

void bic_ft2_bitmap_consts(location_array_s &const_locations);
void bic_ft2_bitmap_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ft2_bitmap_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ft2_bitmap_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_bitmap_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_bitmap_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_bitmap_method_baseline_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_bitmap_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_bitmap_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ft2_bitmap_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

