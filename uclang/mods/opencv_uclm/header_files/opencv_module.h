
#ifndef __OPENCV_MODULE_H
#define __OPENCV_MODULE_H

@begin
include "ucl_opencv.h"
@end

// - OPENCV indexes of built in classes -
extern unsigned c_bi_class_cv;
extern unsigned c_bi_class_cv_mat;
extern unsigned c_bi_class_cv_window;
extern unsigned c_bi_class_cv_capture;
extern unsigned c_bi_class_cv_writer;

// - OPENCV module -
extern built_in_module_s module;

// - OPENCV classes -
extern built_in_class_s *opencv_classes[];

// - OPENCV error identifiers -
enum
{
  c_error_CV_MAT_ENCODE_PARAMETERS_ERROR = 0,
  c_error_CV_MAT_IMAGE_READ_ERROR,
  c_error_CV_MAT_IMAGE_WRITE_ERROR,
  c_error_CV_MAT_IMAGE_DECODE_ERROR,
  c_error_CV_MAT_IMAGE_ENCODE_ERROR,
  c_error_CV_WINDOW_CREATE_ERROR,
  c_error_CV_WINDOW_SHOW_ERROR,
  c_error_CV_CAPTURE_DEVICE_OPEN_ERROR,
  c_error_CV_CAPTURE_FILE_OPEN_ERROR,
  c_error_CV_CAPTURE_RETRIEVE_ERROR,
  c_error_CV_CAPTURE_SET_PROPERTY_ERROR,
  c_error_CV_WRITER_TOO_SHORT_FOURCC_CODE,
  c_error_CV_WRITER_CREATE_ERROR,
  c_error_CV_WRITER_WRITE_WRONG_IMAGE_SIZE,
  c_error_CV_WRITER_WRITE_ERROR,
};

// - OPENCV error strings -
extern const char *opencv_error_strings[];

// - OPENCV initialize -
bool opencv_initialize(script_parser_s &sp);

// - OPENCV print exception -
bool opencv_print_exception(interpreter_s &it,exception_s &exception);

// - class CV -
extern built_in_variable_s cv_variables[];
extern built_in_method_s cv_methods[];
extern built_in_class_s cv_class;

void bic_cv_consts(location_array_s &const_locations);
void bic_cv_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cv_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cv_method_wait_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CV_MAT -
extern built_in_variable_s cv_mat_variables[];
extern built_in_method_s cv_mat_methods[];
extern built_in_class_s cv_mat_class;

void bic_cv_mat_consts(location_array_s &const_locations);
void bic_cv_mat_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cv_mat_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cv_mat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_CvMat_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_read_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_decode_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_encode_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_mat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CV_WINDOW -
extern built_in_variable_s cv_window_variables[];
extern built_in_method_s cv_window_methods[];
extern built_in_class_s cv_window_class;

void bic_cv_window_consts(location_array_s &const_locations);
void bic_cv_window_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cv_window_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cv_window_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_window_method_CvWindow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_window_method_show_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_window_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_window_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CV_CAPTURE -
extern built_in_variable_s cv_capture_variables[];
extern built_in_method_s cv_capture_methods[];
extern built_in_class_s cv_capture_class;

void bic_cv_capture_consts(location_array_s &const_locations);
void bic_cv_capture_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cv_capture_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cv_capture_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_CvCapture_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_grab_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_retrieve_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_retrieve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_set_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_capture_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CV_WRITER -
extern built_in_variable_s cv_writer_variables[];
extern built_in_method_s cv_writer_methods[];
extern built_in_class_s cv_writer_class;

void bic_cv_writer_consts(location_array_s &const_locations);
void bic_cv_writer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cv_writer_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cv_writer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_writer_method_CvWriter_6(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_writer_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_writer_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_writer_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_writer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cv_writer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

