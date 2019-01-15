
#ifndef __RAW_MODULE_H
#define __RAW_MODULE_H

@begin
include "ucl_raw.h"
@end

// - RAW indexes of built in classes -
extern unsigned c_bi_class_raw_lib;
extern unsigned c_bi_class_raw_processor;
extern unsigned c_bi_class_raw_image;

// - RAW module -
extern "C" EXPORT built_in_module_s module;

// - RAW classes -
extern built_in_class_s *raw_classes[];

// - RAW error identifiers -
enum
{
  c_error_RAW_PROCESSOR_OPEN_FILE_ERROR = 0,
  c_error_RAW_PROCESSOR_OPEN_BUFFER_ERROR,
  c_error_RAW_PROCESSOR_UNPACK_IMAGE_ERROR,
  c_error_RAW_PROCESSOR_UNPACK_THUMBNAIL_ERROR,
  c_error_RAW_PROCESSOR_PROCESS_ERROR,
  c_error_RAW_PROCESSOR_IMAGE_NOT_PROCESSED_YET,
  c_error_RAW_PROCESSOR_MAKE_IMAGE_ERROR,
  c_error_RAW_PROCESSOR_MAKE_THUMBNAIL_ERROR,
  c_error_RAW_IMAGE_INVALID_IMAGE_TYPE,
};

// - RAW error strings -
extern const char *raw_error_strings[];

// - RAW initialize -
bool raw_initialize(script_parser_s &sp);

// - RAW print exception -
bool raw_print_exception(interpreter_s &it,exception_s &exception);

// - class RAW_LIB -
extern built_in_variable_s raw_lib_variables[];
extern built_in_method_s raw_lib_methods[];
extern built_in_class_s raw_lib_class;

void bic_raw_lib_consts(location_array_s &const_locations);
void bic_raw_lib_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_raw_lib_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_raw_lib_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_lib_method_version_number_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_lib_method_camera_list_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_lib_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_lib_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RAW_PROCESSOR -
extern built_in_variable_s raw_processor_variables[];
extern built_in_method_s raw_processor_methods[];
extern built_in_class_s raw_processor_class;

void bic_raw_processor_consts(location_array_s &const_locations);
void bic_raw_processor_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_raw_processor_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_raw_processor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_open_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_open_buffer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_get_image_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_get_thumb_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_processor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RAW_IMAGE -
extern built_in_variable_s raw_image_variables[];
extern built_in_method_s raw_image_methods[];
extern built_in_class_s raw_image_class;

void bic_raw_image_consts(location_array_s &const_locations);
void bic_raw_image_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_raw_image_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_raw_image_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_colors_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_bits_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_raw_image_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

