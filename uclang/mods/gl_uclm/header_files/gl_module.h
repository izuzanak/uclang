
#ifndef __GL_MODULE_H
#define __GL_MODULE_H

@begin
include "ucl_gl.h"
@end

// - GL indexes of built in classes -
extern unsigned c_bi_class_gl;
extern unsigned c_bi_class_gl_shader;
extern unsigned c_bi_class_gl_program;
extern unsigned c_bi_class_gl_attribute;
extern unsigned c_bi_class_gl_uniform;
extern unsigned c_bi_class_gl_texture;

// - GL module -
extern built_in_module_s module;

// - GL classes -
extern built_in_class_s *gl_classes[];

// - GL error identifiers -
enum
{
  c_error_GL_WRONG_WIDTH_OR_HEIGHT_VALUE = 0,
  c_error_GL_SHADER_CANNOT_CREATE_SHADER,
  c_error_GL_SHADER_CANNOT_COMPILE_SHADER,
  c_error_GL_PROGRAM_CANNOT_CREATE_PROGRAM,
  c_error_GL_PROGRAM_CANNOT_LINK_PROGRAM,
  c_error_GL_UNIFORM_NOT_SUPPORTED_TYPE,
  c_error_GL_UNIFORM_WRONG_VALUE_TYPE,
  c_error_GL_TEXTURE_UNSUPPORTED_PIXEL_FORMAT,
  c_error_GL_TEXTURE_INVALID_DIMENSIONS,
  c_error_GL_TEXTURE_WRONG_BUFFER_SIZE,
  c_error_GL_TEXTURE_IMAGE_LOAD_ERROR,
  c_error_GL_TEXTURE_IMAGE_CLEAR_ERROR,
};

// - GL error strings -
extern const char *gl_error_strings[];

// - GL initialize -
bool gl_initialize(script_parser_s &sp);

// - GL print exception -
bool gl_print_exception(interpreter_s &it,exception_s &exception);

// - class GL -
extern built_in_variable_s gl_variables[];
extern built_in_method_s gl_methods[];
extern built_in_class_s gl_class;

void bic_gl_consts(location_array_s &const_locations);
void bic_gl_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_method_ClearColor_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_Clear_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_BlendFunc_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_Enable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_Disable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_IsEnabled_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_Viewport_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_Finish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_SHADER -
extern built_in_variable_s gl_shader_variables[];
extern built_in_method_s gl_shader_methods[];
extern built_in_class_s gl_shader_class;

void bic_gl_shader_consts(location_array_s &const_locations);
void bic_gl_shader_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_shader_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_shader_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_shader_method_GlShader_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_shader_method_GlShader_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_shader_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_shader_method_source_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_shader_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_shader_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_PROGRAM -
extern built_in_variable_s gl_program_variables[];
extern built_in_method_s gl_program_methods[];
extern built_in_class_s gl_program_class;

void bic_gl_program_consts(location_array_s &const_locations);
void bic_gl_program_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_program_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_program_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_GlProgram_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_GlProgram_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_active_atributes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_active_uniforms_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_use_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_program_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_ATTRIBUTE -
extern built_in_variable_s gl_attribute_variables[];
extern built_in_method_s gl_attribute_methods[];
extern built_in_class_s gl_attribute_class;

void bic_gl_attribute_consts(location_array_s &const_locations);
void bic_gl_attribute_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_attribute_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_attribute_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_attribute_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_attribute_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_attribute_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_attribute_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_attribute_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_attribute_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_UNIFORM -
extern built_in_variable_s gl_uniform_variables[];
extern built_in_method_s gl_uniform_methods[];
extern built_in_class_s gl_uniform_class;

void bic_gl_uniform_consts(location_array_s &const_locations);
void bic_gl_uniform_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_uniform_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_uniform_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_uniform_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GL_TEXTURE -
extern built_in_variable_s gl_texture_variables[];
extern built_in_method_s gl_texture_methods[];
extern built_in_class_s gl_texture_class;

void bic_gl_texture_consts(location_array_s &const_locations);
void bic_gl_texture_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gl_texture_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gl_texture_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_GlTexture_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_bind_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gl_texture_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

