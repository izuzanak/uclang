
#ifndef __GIF_MODULE_H
#define __GIF_MODULE_H

@begin
include "ucl_gif.h"
@end

// - GIF indexes of built in classes -
extern unsigned c_bi_class_gif_file;
extern unsigned c_bi_class_gif_image;

// - GIF module -
extern "C" EXPORT built_in_module_s module;

// - GIF classes -
extern built_in_class_s *gif_classes[];

// - GIF error identifiers -
enum
{
  c_error_GIF_FILE_OPEN_ERROR = 0,
  c_error_GIF_FILE_READ_ERROR,
  c_error_GIF_FILE_INDEX_EXCEEDS_RANGE,
};

// - GIF error strings -
extern const char *gif_error_strings[];

// - GIF initialize -
bool gif_initialize(script_parser_s &sp);

// - GIF print exception -
bool gif_print_exception(interpreter_s &it,exception_s &exception);

// - class GIF_FILE -
extern built_in_variable_s gif_file_variables[];
extern built_in_method_s gif_file_methods[];
extern built_in_class_s gif_file_class;

void bic_gif_file_consts(location_array_s &const_locations);
void bic_gif_file_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gif_file_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gif_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_GifFile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GIF_IMAGE -
extern built_in_variable_s gif_image_variables[];
extern built_in_method_s gif_image_methods[];
extern built_in_class_s gif_image_class;

void bic_gif_image_consts(location_array_s &const_locations);
void bic_gif_image_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gif_image_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gif_image_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_image_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_image_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_image_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_image_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gif_image_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

