
#ifndef __IMAGE_MODULE_H
#define __IMAGE_MODULE_H

@begin
include "ucl_image.h"
@end

// - IMAGE indexes of built in classes -
extern unsigned c_bi_class_image;

// - IMAGE module -
extern "C" EXPORT built_in_module_s module;

// - IMAGE classes -
extern built_in_class_s *image_classes[];

// - IMAGE error identifiers -
enum
{
  c_error_IMAGE_WRONG_PROPERTIES = 0,
  c_error_IMAGE_INVALID_SOURCE_DATA_SIZE,
  c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,
  c_error_IMAGE_CANNOT_GET_BUFFER_OF_NON_ROOT_IMAGE,
  c_error_IMAGE_CANNOT_OPEN_FILE,
  c_error_IMAGE_FILE_IS_NOT_PNG_FILE,
  c_error_IMAGE_PNG_READ_INIT_ERROR,
  c_error_IMAGE_PNG_WRITE_INIT_ERROR,
  c_error_IMAGE_PNG_DATA_READ_ERROR,
  c_error_IMAGE_PNG_FILE_READ_ERROR,
  c_error_IMAGE_PNG_FILE_WRITE_ERROR,
  c_error_IMAGE_JPEG_DATA_READ_ERROR,
  c_error_IMAGE_JPEG_FILE_READ_ERROR,
  c_error_IMAGE_JPEG_FILE_WRITE_ERROR,
  c_error_IMAGE_IMAGE_OPERATION_ERROR,
  c_error_IMAGE_IMAGE_OPERATION_INVALID_COLOR,
};

// - IMAGE error strings -
extern const char *image_error_strings[];

// - IMAGE initialize -
bool image_initialize(script_parser_s &sp);

// - IMAGE print exception -
bool image_print_exception(interpreter_s &it,exception_s &exception);

// - class IMAGE -
extern built_in_variable_s image_variables[];
extern built_in_method_s image_methods[];
extern built_in_class_s image_class;

void bic_image_consts(location_array_s &const_locations);
void bic_image_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_image_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_image_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_Image_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_Image_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_read_png_data_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_read_png_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_write_png_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_read_jpeg_data_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_read_jpeg_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_write_jpeg_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_duplicate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_referred_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_io_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_io_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_io_copy_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_io_convert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_io_apply_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_io_normalize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_image_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

