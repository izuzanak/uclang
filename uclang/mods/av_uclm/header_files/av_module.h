
#ifndef __AV_MODULE_H
#define __AV_MODULE_H

@begin
include "ucl_av.h"
@end

// - AV indexes of built in classes -
extern unsigned c_bi_class_av_format;
extern unsigned c_bi_class_av_stream;
extern unsigned c_bi_class_av_video_frame;
extern unsigned c_bi_class_av_audio_frame;
extern unsigned c_bi_class_av_picture;
extern unsigned c_bi_class_av_converter;

// - AV module -
extern "C" EXPORT built_in_module_s module;

// - AV classes -
extern built_in_class_s *av_classes[];

// - AV error identifiers -
enum
{
  c_error_AV_FORMAT_OPEN_INPUT_ERROR = 0,
  c_error_AV_FORMAT_FIND_STREAM_INFO_ERROR,
  c_error_AV_FORMAT_STREAM_INDEX_EXCEEDS_RANGE,
  c_error_AV_FORMAT_STREAM_ALREADY_IN_DECODED,
  c_error_AV_FORMAT_CANNOT_FIND_STREAM_DECODER,
  c_error_AV_FORMAT_CANNOT_INITIALIZE_CODEC_CONTEXT,
  c_error_AV_FORMAT_PACKED_UNRECOGNIZED_CODEC_TYPE,
  c_error_AV_FORMAT_PACKED_DECODE_ERROR,
  c_error_AV_PICTURE_ALLOCATE_ERROR,
  c_error_AV_PICTURE_WRONG_PICTURE_PROPERTIES,
  c_error_AV_PICTURE_UNSUPPORTED_PIXEL_FORMAT,
};

// - AV error strings -
extern const char *av_error_strings[];

// - AV initialize -
bool av_initialize(script_parser_s &sp);

// - AV print exception -
bool av_print_exception(interpreter_s &it,exception_s &exception);

// - class AV_FORMAT -
extern built_in_variable_s av_format_variables[];
extern built_in_method_s av_format_methods[];
extern built_in_class_s av_format_class;

void bic_av_format_consts(location_array_s &const_locations);
void bic_av_format_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_av_format_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_av_format_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_AvFormat_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_stream_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_stream_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_stream_decode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_next_frame_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_format_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AV_STREAM -
extern built_in_variable_s av_stream_variables[];
extern built_in_method_s av_stream_methods[];
extern built_in_class_s av_stream_class;

void bic_av_stream_consts(location_array_s &const_locations);
void bic_av_stream_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_av_stream_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_av_stream_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_stream_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_stream_method_codec_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_stream_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_stream_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AV_VIDEO_FRAME -
extern built_in_variable_s av_video_frame_variables[];
extern built_in_method_s av_video_frame_methods[];
extern built_in_class_s av_video_frame_class;

void bic_av_video_frame_consts(location_array_s &const_locations);
void bic_av_video_frame_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_av_video_frame_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_av_video_frame_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_video_frame_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_video_frame_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_video_frame_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_video_frame_method_pgm_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_video_frame_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_video_frame_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AV_AUDIO_FRAME -
extern built_in_variable_s av_audio_frame_variables[];
extern built_in_method_s av_audio_frame_methods[];
extern built_in_class_s av_audio_frame_class;

void bic_av_audio_frame_consts(location_array_s &const_locations);
void bic_av_audio_frame_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_av_audio_frame_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_av_audio_frame_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_audio_frame_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_audio_frame_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AV_PICTURE -
extern built_in_variable_s av_picture_variables[];
extern built_in_method_s av_picture_methods[];
extern built_in_class_s av_picture_class;

void bic_av_picture_consts(location_array_s &const_locations);
void bic_av_picture_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_av_picture_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_av_picture_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_AvPicture_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_bmp_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_picture_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AV_CONVERTER -
extern built_in_variable_s av_converter_variables[];
extern built_in_method_s av_converter_methods[];
extern built_in_class_s av_converter_class;

void bic_av_converter_consts(location_array_s &const_locations);
void bic_av_converter_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_av_converter_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_av_converter_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_converter_method_AvConverter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_converter_method_scale_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_converter_method_scale_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_converter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_av_converter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

