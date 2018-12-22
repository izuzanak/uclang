
#ifndef __FTGL_MODULE_H
#define __FTGL_MODULE_H

@begin
include "ucl_ftgl.h"
@end

// - FTGL indexes of built in classes -
extern unsigned c_bi_class_gl_vertex_buffer;
extern unsigned c_bi_class_gl_font;
extern unsigned c_bi_class_gl_font_buffer;

// - FTGL module -
extern "C" EXPORT built_in_module_s module;

// - FTGL classes -
extern built_in_class_s *ftgl_classes[];

// - FTGL error identifiers -
enum
{
  c_error_GL_VERTEX_BUFFER_CANNOT_CREATE_NEW = 0,
  c_error_GL_VERTEX_BUFFER_VERTEX_ARRAY_IS_EMPTY,
  c_error_GL_VERTEX_BUFFER_INDEX_ARRAY_IS_EMPTY,
  c_error_GL_VERTEX_BUFFER_VERTEX_ARRAY_NOT_ALIGNED,
  c_error_GL_VERTEX_BUFFER_WRONG_VERTEX_VALUE_TYPE,
  c_error_GL_VERTEX_BUFFER_WRONG_INDEX_VALUE_TYPE,
  c_error_GL_VERTEX_BUFFER_INDEX_EXCEEDS_RANGE,
  c_error_GL_FONT_INVALID_TEXTURE_ATLAS_DIMENSIONS,
  c_error_GL_FONT_CANNOT_READ_FROM_FILE,
  c_error_GL_FONT_GLYPH_RETRIEVE_ERROR_ATLAS_SIZE,
  c_error_GL_FONT_BUFFER_CONVERT_TO_WCHAR_STRING_ERROR,
};

// - FTGL error strings -
extern const char *ftgl_error_strings[];

// - FTGL initialize -
bool ftgl_initialize(script_parser_s &sp);

// - FTGL print exception -
bool ftgl_print_exception(interpreter_s &it,exception_s &exception);

// - class GL_VERTEX_BUFFER -
extern built_in_variable_s gl_vertex_buffer_variables[];
extern built_in_method_s gl_vertex_buffer_methods[];
extern built_in_class_s gl_vertex_buffer_class;

void bic_gl_vertex_buffer_consts(location_array_s &const_locations);
void bic_gl_vertex_buffer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_vertex_buffer_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_vertex_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_GlVertexBuffer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_get_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_push_back_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_render_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_vertex_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_FONT -
extern built_in_variable_s gl_font_variables[];
extern built_in_method_s gl_font_methods[];
extern built_in_class_s gl_font_class;

void bic_gl_font_consts(location_array_s &const_locations);
void bic_gl_font_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_font_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_font_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_GlFont_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_linegap_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_ascender_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_descender_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_buffer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_measure_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_bind_texture_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_FONT_BUFFER -
extern built_in_variable_s gl_font_buffer_variables[];
extern built_in_method_s gl_font_buffer_methods[];
extern built_in_class_s gl_font_buffer_class;

void bic_gl_font_buffer_consts(location_array_s &const_locations);
void bic_gl_font_buffer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_font_buffer_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_font_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_set_pos_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_get_pos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_push_text_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_render_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_font_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

