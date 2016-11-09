
#ifndef __PORTAUDIO_MODULE_H
#define __PORTAUDIO_MODULE_H

@begin
include "ucl_portaudio.h"
@end

// - PORT_AUDIO indexes of built in classes -
extern unsigned c_bi_class_port_audio;
extern unsigned c_bi_class_pa_host_api;
extern unsigned c_bi_class_pa_device;
extern unsigned c_bi_class_pa_parameters;
extern unsigned c_bi_class_pa_stream;

// - PORT_AUDIO module -
extern built_in_module_s module;

// - PORT_AUDIO classes -
extern built_in_class_s *port_audio_classes[];

// - PORT_AUDIO error identifiers -
enum
{
  c_error_PORT_AUDIO_NO_DEFAULT_HOST_API = 0,
  c_error_PORT_AUDIO_NO_DEFAULT_INPUT_DEVICE,
  c_error_PORT_AUDIO_NO_DEFAULT_OUTPUT_DEVICE,
  c_error_PA_HOST_API_NO_DEFAULT_INPUT_DEVICE,
  c_error_PA_HOST_API_NO_DEFAULT_OUTPUT_DEVICE,
  c_error_PA_STREAM_MISSING_INPUT_OR_OUTPUT_PARAMETERS,
  c_error_PA_STREAM_CREATE_ERROR,
  c_error_PA_STREAM_START_ERROR,
  c_error_PA_STREAM_STOP_ERROR,
  c_error_PA_STREAM_INPUT_ONLY_STREAM,
  c_error_PA_STREAM_OUTPUT_ONLY_STREAM,
  c_error_PA_STREAM_READ_AVAILABLE_ERROR,
  c_error_PA_STREAM_WRITE_AVAILABLE_ERROR,
  c_error_PA_STREAM_READ_WRONG_FRAME_COUNT,
  c_error_PA_STREAM_READ_ERROR,
  c_error_PA_STREAM_WRITE_WRONG_DATA_SIZE,
  c_error_PA_STREAM_WRITE_ERROR,
};

// - PORT_AUDIO error strings -
extern const char *port_audio_error_strings[];

// - PORT_AUDIO initialize -
bool port_audio_initialize(script_parser_s &sp);

// - PORT_AUDIO print exception -
bool port_audio_print_exception(interpreter_s &it,exception_s &exception);

// - class PORT_AUDIO -
extern built_in_variable_s port_audio_variables[];
extern built_in_method_s port_audio_methods[];
extern built_in_class_s port_audio_class;

void bic_port_audio_consts(location_array_s &const_locations);
void bic_port_audio_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_port_audio_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_port_audio_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_version_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_host_api_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_all_apis_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_input_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_output_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_all_devices_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_port_audio_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PA_HOST_API -
extern built_in_variable_s pa_host_api_variables[];
extern built_in_method_s pa_host_api_methods[];
extern built_in_class_s pa_host_api_class;

void bic_pa_host_api_consts(location_array_s &const_locations);
void bic_pa_host_api_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pa_host_api_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pa_host_api_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_input_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_output_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_host_api_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PA_DEVICE -
extern built_in_variable_s pa_device_variables[];
extern built_in_method_s pa_device_methods[];
extern built_in_class_s pa_device_class;

void bic_pa_device_consts(location_array_s &const_locations);
void bic_pa_device_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pa_device_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pa_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_host_api_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_channels_max_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_channels_max_out_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_latency_low_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_latency_low_out_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_latency_high_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_latency_high_out_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_sample_rate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PA_PARAMETERS -
extern built_in_variable_s pa_parameters_variables[];
extern built_in_method_s pa_parameters_methods[];
extern built_in_class_s pa_parameters_class;

void bic_pa_parameters_consts(location_array_s &const_locations);
void bic_pa_parameters_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pa_parameters_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pa_parameters_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_parameters_method_PaParameters_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_parameters_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_parameters_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PA_STREAM -
extern built_in_variable_s pa_stream_variables[];
extern built_in_method_s pa_stream_methods[];
extern built_in_class_s pa_stream_class;

void bic_pa_stream_consts(location_array_s &const_locations);
void bic_pa_stream_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pa_stream_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pa_stream_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_PaStream_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_start_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_read_available_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_write_available_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pa_stream_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

