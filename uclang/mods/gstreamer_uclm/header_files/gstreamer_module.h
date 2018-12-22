
#ifndef __GSTREAMER_MODULE_H
#define __GSTREAMER_MODULE_H

@begin
include "ucl_gstreamer.h"
@end

// - GSTREAMER indexes of built in classes -
extern unsigned c_bi_class_gst;
extern unsigned c_bi_class_gst_pipeline;

// - GSTREAMER module -
extern "C" EXPORT built_in_module_s module;

// - GSTREAMER classes -
extern built_in_class_s *gstreamer_classes[];

// - GSTREAMER error identifiers -
enum
{
  c_error_GST_CANNOT_CREATE_SINK = 0,
  c_error_GST_CANNOT_CONSTRUCT_PIPELINE,
  c_error_GST_PIPELANE_SET_STATE_ERROR,
  c_error_GST_PIPELANE_RUNTIME_ERROR,
  c_error_GST_PIPELANE_STOP_ERROR,
};

// - GSTREAMER error strings -
extern const char *gstreamer_error_strings[];

// - GSTREAMER initialize -
bool gstreamer_initialize(script_parser_s &sp);

// - GSTREAMER print exception -
bool gstreamer_print_exception(interpreter_s &it,exception_s &exception);

// - class GST -
extern built_in_variable_s gst_variables[];
extern built_in_method_s gst_methods[];
extern built_in_class_s gst_class;

void bic_gst_consts(location_array_s &const_locations);
void bic_gst_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gst_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gst_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_method_version_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_method_pipeline_video_uri_imxegl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GST_PIPELINE -
extern built_in_variable_s gst_pipeline_variables[];
extern built_in_method_s gst_pipeline_methods[];
extern built_in_class_s gst_pipeline_class;

void bic_gst_pipeline_consts(location_array_s &const_locations);
void bic_gst_pipeline_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gst_pipeline_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gst_pipeline_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_pipeline_method_set_state_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_pipeline_method_get_state_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_pipeline_method_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_pipeline_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_pipeline_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gst_pipeline_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

