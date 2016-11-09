
@begin
include "portaudio_module.h"
@end

// - PORT_AUDIO indexes of built in classes -
unsigned c_bi_class_port_audio = c_idx_not_exist;
unsigned c_bi_class_pa_host_api = c_idx_not_exist;
unsigned c_bi_class_pa_device = c_idx_not_exist;
unsigned c_bi_class_pa_parameters = c_idx_not_exist;
unsigned c_bi_class_pa_stream = c_idx_not_exist;

// - PORT_AUDIO module -
built_in_module_s module =
{/*{{{*/
  5,                          // Class count
  port_audio_classes,         // Classes

  0,                          // Error base index
  17,                         // Error count
  port_audio_error_strings,   // Error strings

  port_audio_initialize,      // Initialize function
  port_audio_print_exception, // Print exceptions function
};/*}}}*/

// - PORT_AUDIO classes -
built_in_class_s *port_audio_classes[] =
{/*{{{*/
  &port_audio_class,
  &pa_host_api_class,
  &pa_device_class,
  &pa_parameters_class,
  &pa_stream_class,
};/*}}}*/

// - PORT_AUDIO error strings -
const char *port_audio_error_strings[] =
{/*{{{*/
  "error_PORT_AUDIO_NO_DEFAULT_HOST_API",
  "error_PORT_AUDIO_NO_DEFAULT_INPUT_DEVICE",
  "error_PORT_AUDIO_NO_DEFAULT_OUTPUT_DEVICE",
  "error_PA_HOST_API_NO_DEFAULT_INPUT_DEVICE",
  "error_PA_HOST_API_NO_DEFAULT_OUTPUT_DEVICE",
  "error_PA_STREAM_MISSING_INPUT_OR_OUTPUT_PARAMETERS",
  "error_PA_STREAM_CREATE_ERROR",
  "error_PA_STREAM_START_ERROR",
  "error_PA_STREAM_STOP_ERROR",
  "error_PA_STREAM_INPUT_ONLY_STREAM",
  "error_PA_STREAM_OUTPUT_ONLY_STREAM",
  "error_PA_STREAM_READ_AVAILABLE_ERROR",
  "error_PA_STREAM_WRITE_AVAILABLE_ERROR",
  "error_PA_STREAM_READ_WRONG_FRAME_COUNT",
  "error_PA_STREAM_READ_ERROR",
  "error_PA_STREAM_WRITE_WRONG_DATA_SIZE",
  "error_PA_STREAM_WRITE_ERROR",
};/*}}}*/

// - PORT_AUDIO initialize -
bool port_audio_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize port_audio class identifier -
  c_bi_class_port_audio = class_base_idx++;

  // - initialize pa_host_api class identifier -
  c_bi_class_pa_host_api = class_base_idx++;

  // - initialize pa_device class identifier -
  c_bi_class_pa_device = class_base_idx++;

  // - initialize pa_parameters class identifier -
  c_bi_class_pa_parameters = class_base_idx++;

  // - initialize pa_stream class identifier -
  c_bi_class_pa_stream = class_base_idx++;

  return true;
}/*}}}*/

// - PORT_AUDIO print exception -
bool port_audio_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_PORT_AUDIO_NO_DEFAULT_HOST_API:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio, no default host API\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PORT_AUDIO_NO_DEFAULT_INPUT_DEVICE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio, no default input device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PORT_AUDIO_NO_DEFAULT_OUTPUT_DEVICE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio, no default output device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_HOST_API_NO_DEFAULT_INPUT_DEVICE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio host API, no default input device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_HOST_API_NO_DEFAULT_OUTPUT_DEVICE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio host API, no default output device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_MISSING_INPUT_OR_OUTPUT_PARAMETERS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream, missing input or output parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream create error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_START_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream start error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_STOP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream stop error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_INPUT_ONLY_STREAM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream is input only\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_OUTPUT_ONLY_STREAM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream is output only\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_READ_AVAILABLE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream read available error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_WRITE_AVAILABLE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream write available error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_READ_WRONG_FRAME_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream negative or zero frames to read\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream read error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_WRITE_WRONG_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream wrong size of data to write\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PA_STREAM_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPort audio stream write error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class PORT_AUDIO -
built_in_class_s port_audio_class =
{/*{{{*/
  "PortAudio",
  c_modifier_public | c_modifier_final,
  10, port_audio_methods,
  6, port_audio_variables,
  bic_port_audio_consts,
  bic_port_audio_init,
  bic_port_audio_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s port_audio_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_port_audio_operator_binary_equal
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_version_0
  },
  {
    "version_text#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_version_text_0
  },
  {
    "host_api#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_host_api_0
  },
  {
    "all_apis#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_all_apis_0
  },
  {
    "input_device#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_input_device_0
  },
  {
    "output_device#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_output_device_0
  },
  {
    "all_devices#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_all_devices_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_port_audio_method_print_0
  },
};/*}}}*/

built_in_variable_s port_audio_variables[] =
{/*{{{*/

  // - portaudio sample format constants -
  { "Float32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "Int32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "Int24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "Int16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "Int8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UInt8", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_port_audio_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert portaudio sample format constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(paFloat32);
    CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(paInt32);
    CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(paInt24);
    CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(paInt16);
    CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(paInt8);
    CREATE_PORTAUDIO_SAMPLE_FORMAT_BIC_STATIC(paUInt8);
  }

}/*}}}*/

void bic_port_audio_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_port_audio_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_port_audio_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_port_audio_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  long long int result = Pa_GetVersion();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_port_audio_method_version_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  const char *version_str = Pa_GetVersionText();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version_str),version_str);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_port_audio_method_host_api_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  PaHostApiIndex index = Pa_GetDefaultHostApi();

  // - ERROR -
  if (index < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PORT_AUDIO_NO_DEFAULT_HOST_API,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const PaHostApiInfo *hai_ptr = Pa_GetHostApiInfo(index);

  BIC_SIMPLE_SET_RES(c_bi_class_pa_host_api,hai_ptr);

  return true;
}/*}}}*/

bool bic_port_audio_method_all_apis_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  PaHostApiIndex count = Pa_GetHostApiCount();

  if (count > 0)
  {
    PaHostApiIndex idx = 0;
    do {
      const PaHostApiInfo *hai_ptr = Pa_GetHostApiInfo(idx);

      // - push host api to result array -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pa_host_api,hai_ptr);
      array_ptr->push(new_location);

    } while(++idx < count);
  }

  return true;
}/*}}}*/

bool bic_port_audio_method_input_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  PaDeviceIndex index = Pa_GetDefaultInputDevice();

  // - ERROR -
  if (index < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PORT_AUDIO_NO_DEFAULT_INPUT_DEVICE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const PaDeviceInfo *di_ptr = Pa_GetDeviceInfo(index);

  // - create pa device object -
  pa_device_s *pad_ptr = (pa_device_s *)cmalloc(sizeof(pa_device_s));
  pad_ptr->init();

  pad_ptr->index = index;
  pad_ptr->di_ptr = di_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pa_device,pad_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_port_audio_method_output_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  PaDeviceIndex index = Pa_GetDefaultOutputDevice();

  // - ERROR -
  if (index < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PORT_AUDIO_NO_DEFAULT_OUTPUT_DEVICE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const PaDeviceInfo *di_ptr = Pa_GetDeviceInfo(index);

  // - create pa device object -
  pa_device_s *pad_ptr = (pa_device_s *)cmalloc(sizeof(pa_device_s));
  pad_ptr->init();

  pad_ptr->index = index;
  pad_ptr->di_ptr = di_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pa_device,pad_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_port_audio_method_all_devices_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  PaDeviceIndex count = Pa_GetDeviceCount();

  if (count > 0)
  {
    PaDeviceIndex idx = 0;
    do {
      const PaDeviceInfo *di_ptr = Pa_GetDeviceInfo(idx);

      // - create pa device object -
      pa_device_s *pad_ptr = (pa_device_s *)cmalloc(sizeof(pa_device_s));
      pad_ptr->init();

      pad_ptr->index = idx;
      pad_ptr->di_ptr = di_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pa_device,pad_ptr);

      // - push device to result array -
      array_ptr->push(new_location);

    } while(++idx < count);
  }

  return true;
}/*}}}*/

bool bic_port_audio_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PortAudio"),"PortAudio");
  );

  return true;
}/*}}}*/

bool bic_port_audio_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PortAudio");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PA_HOST_API -
built_in_class_s pa_host_api_class =
{/*{{{*/
  "PaHostApi",
  c_modifier_public | c_modifier_final,
  9, pa_host_api_methods,
  0, pa_host_api_variables,
  bic_pa_host_api_consts,
  bic_pa_host_api_init,
  bic_pa_host_api_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s pa_host_api_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_operator_binary_equal
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_method_index_0
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_method_version_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_method_get_type_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_method_name_0
  },
  {
    "input_device#0",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_method_input_device_0
  },
  {
    "output_device#0",
    c_modifier_public | c_modifier_final,
    bic_pa_host_api_method_output_device_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_host_api_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_host_api_method_print_0
  },
};/*}}}*/

built_in_variable_s pa_host_api_variables[] =
{/*{{{*/
};/*}}}*/

void bic_pa_host_api_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pa_host_api_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PaHostApiInfo *)NULL;
}/*}}}*/

void bic_pa_host_api_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_pa_host_api_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pa_host_api_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PaHostApiTypeId type_id = ((PaHostApiInfo *)dst_location->v_data_ptr)->type;
  long long int result = Pa_HostApiTypeIdToHostApiIndex(type_id);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pa_host_api_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((PaHostApiInfo *)dst_location->v_data_ptr)->structVersion;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pa_host_api_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((PaHostApiInfo *)dst_location->v_data_ptr)->type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pa_host_api_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *name = ((PaHostApiInfo *)dst_location->v_data_ptr)->name;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_pa_host_api_method_input_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PaDeviceIndex index = ((PaHostApiInfo *)dst_location->v_data_ptr)->defaultInputDevice;

  // - ERROR -
  if (index < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_HOST_API_NO_DEFAULT_INPUT_DEVICE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const PaDeviceInfo *di_ptr = Pa_GetDeviceInfo(index);

  if (di_ptr != NULL)
  {
    // - create pa device object -
    pa_device_s *pad_ptr = (pa_device_s *)cmalloc(sizeof(pa_device_s));
    pad_ptr->init();

    pad_ptr->index = index;
    pad_ptr->di_ptr = di_ptr;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pa_device,pad_ptr);
    BIC_SET_RESULT(new_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_pa_host_api_method_output_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PaDeviceIndex index = ((PaHostApiInfo *)dst_location->v_data_ptr)->defaultOutputDevice;

  // - ERROR -
  if (index < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_HOST_API_NO_DEFAULT_OUTPUT_DEVICE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  const PaDeviceInfo *di_ptr = Pa_GetDeviceInfo(index);

  if (di_ptr != NULL)
  {
    // - create pa device object -
    pa_device_s *pad_ptr = (pa_device_s *)cmalloc(sizeof(pa_device_s));
    pad_ptr->init();

    pad_ptr->index = index;
    pad_ptr->di_ptr = di_ptr;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pa_device,pad_ptr);
    BIC_SET_RESULT(new_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_pa_host_api_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PaHostApi"),"PaHostApi");
  );

  return true;
}/*}}}*/

bool bic_pa_host_api_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PaHostApi");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PA_DEVICE -
built_in_class_s pa_device_class =
{/*{{{*/
  "PaDevice",
  c_modifier_public | c_modifier_final,
  14, pa_device_methods,
  0, pa_device_variables,
  bic_pa_device_consts,
  bic_pa_device_init,
  bic_pa_device_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s pa_device_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pa_device_operator_binary_equal
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_index_0
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_version_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_name_0
  },
  {
    "host_api#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_host_api_0
  },
  {
    "channels_max_in#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_channels_max_in_0
  },
  {
    "channels_max_out#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_channels_max_out_0
  },
  {
    "latency_low_in#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_latency_low_in_0
  },
  {
    "latency_low_out#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_latency_low_out_0
  },
  {
    "latency_high_in#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_latency_high_in_0
  },
  {
    "latency_high_out#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_latency_high_out_0
  },
  {
    "sample_rate#0",
    c_modifier_public | c_modifier_final,
    bic_pa_device_method_sample_rate_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_device_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_device_method_print_0
  },
};/*}}}*/

built_in_variable_s pa_device_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_PA_DEVICE_RETRIEVE_INTEGER_VALUE(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  pa_device_s *pad_ptr = (pa_device_s *)dst_location->v_data_ptr;\
  long long int result = pad_ptr->di_ptr->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_PA_DEVICE_RETRIEVE_FLOAT_VALUE(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  pa_device_s *pad_ptr = (pa_device_s *)dst_location->v_data_ptr;\
  double result = pad_ptr->di_ptr->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
\
  return true;\
}/*}}}*/

void bic_pa_device_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pa_device_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pa_device_s *)NULL;
}/*}}}*/

void bic_pa_device_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pa_device_s *pad_ptr = (pa_device_s *)location_ptr->v_data_ptr;

  if (pad_ptr != NULL)
  {
    pad_ptr->clear(it);
    cfree(pad_ptr);
  }
}/*}}}*/

bool bic_pa_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pa_device_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_device_s *pad_ptr = (pa_device_s *)dst_location->v_data_ptr;
  long long int result = pad_ptr->index;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pa_device_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_INTEGER_VALUE(structVersion);
}/*}}}*/

bool bic_pa_device_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_device_s *pad_ptr = (pa_device_s *)dst_location->v_data_ptr;
  const char *name = pad_ptr->di_ptr->name;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_pa_device_method_host_api_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_device_s *pad_ptr = (pa_device_s *)dst_location->v_data_ptr;
  const PaHostApiInfo *hai_ptr = Pa_GetHostApiInfo(pad_ptr->di_ptr->hostApi);

  BIC_SIMPLE_SET_RES(c_bi_class_pa_host_api,hai_ptr);

  return true;
}/*}}}*/

bool bic_pa_device_method_channels_max_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_INTEGER_VALUE(maxInputChannels);
}/*}}}*/

bool bic_pa_device_method_channels_max_out_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_INTEGER_VALUE(maxOutputChannels);
}/*}}}*/

bool bic_pa_device_method_latency_low_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_FLOAT_VALUE(defaultLowInputLatency);
}/*}}}*/

bool bic_pa_device_method_latency_low_out_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_FLOAT_VALUE(defaultLowOutputLatency);
}/*}}}*/

bool bic_pa_device_method_latency_high_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_FLOAT_VALUE(defaultHighInputLatency);
}/*}}}*/

bool bic_pa_device_method_latency_high_out_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_FLOAT_VALUE(defaultHighOutputLatency);
}/*}}}*/

bool bic_pa_device_method_sample_rate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PA_DEVICE_RETRIEVE_FLOAT_VALUE(defaultSampleRate);
}/*}}}*/

bool bic_pa_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PaDevice"),"PaDevice");
  );

  return true;
}/*}}}*/

bool bic_pa_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PaDevice");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PA_PARAMETERS -
built_in_class_s pa_parameters_class =
{/*{{{*/
  "PaParameters",
  c_modifier_public | c_modifier_final,
  4, pa_parameters_methods,
  0, pa_parameters_variables,
  bic_pa_parameters_consts,
  bic_pa_parameters_init,
  bic_pa_parameters_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s pa_parameters_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pa_parameters_operator_binary_equal
  },
  {
    "PaParameters#4",
    c_modifier_public | c_modifier_final,
    bic_pa_parameters_method_PaParameters_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_parameters_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_parameters_method_print_0
  },
};/*}}}*/

built_in_variable_s pa_parameters_variables[] =
{/*{{{*/
};/*}}}*/

void bic_pa_parameters_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pa_parameters_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PaStreamParameters *)NULL;
}/*}}}*/

void bic_pa_parameters_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  PaStreamParameters *sp_ptr = (PaStreamParameters *)location_ptr->v_data_ptr;

  if (sp_ptr != NULL)
  {
    cfree(sp_ptr);
  }
}/*}}}*/

bool bic_pa_parameters_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pa_parameters_method_PaParameters_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int channel_cnt;
  long long int sample_format;
  double latency;

  if (src_0_location->v_type != c_bi_class_pa_device ||
      !it.retrieve_integer(src_1_location,channel_cnt) ||
      !it.retrieve_integer(src_2_location,sample_format) ||
      !it.retrieve_float(src_3_location,latency))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PaParameters#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  pa_device_s *pad_ptr = (pa_device_s *)src_0_location->v_data_ptr;

  // - create stream parameters object -
  PaStreamParameters *sp_ptr = (PaStreamParameters *)cmalloc(sizeof(PaStreamParameters));

  sp_ptr->device = pad_ptr->index;
  sp_ptr->channelCount = channel_cnt;
  sp_ptr->sampleFormat = sample_format;
  sp_ptr->suggestedLatency = latency;
  sp_ptr->hostApiSpecificStreamInfo = NULL;

  dst_location->v_data_ptr = (PaStreamParameters *)sp_ptr;

  return true;
}/*}}}*/

bool bic_pa_parameters_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PaParameters"),"PaParameters");
  );

  return true;
}/*}}}*/

bool bic_pa_parameters_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PaParameters");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PA_STREAM -
built_in_class_s pa_stream_class =
{/*{{{*/
  "PaStream",
  c_modifier_public | c_modifier_final,
  10, pa_stream_methods,
  0, pa_stream_variables,
  bic_pa_stream_consts,
  bic_pa_stream_init,
  bic_pa_stream_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s pa_stream_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_operator_binary_equal
  },
  {
    "PaStream#4",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_PaStream_4
  },
  {
    "start#0",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_start_0
  },
  {
    "stop#0",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_stop_0
  },
  {
    "read_available#0",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_read_available_0
  },
  {
    "write_available#0",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_write_available_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_read_1
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_pa_stream_method_write_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_stream_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pa_stream_method_print_0
  },
};/*}}}*/

built_in_variable_s pa_stream_variables[] =
{/*{{{*/
};/*}}}*/

void bic_pa_stream_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pa_stream_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pa_stream_s *)NULL;
}/*}}}*/

void bic_pa_stream_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pa_stream_s *pas_ptr = (pa_stream_s *)location_ptr->v_data_ptr;

  if (pas_ptr != NULL)
  {
    pas_ptr->clear(it);
    cfree(pas_ptr);
  }
}/*}}}*/

bool bic_pa_stream_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pa_stream_method_PaStream_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  double sample_rate;
  long long int buffer_frames;

  if ((src_0_location->v_type != c_bi_class_pa_parameters && src_0_location->v_type != c_bi_class_blank) ||
      (src_1_location->v_type != c_bi_class_pa_parameters && src_1_location->v_type != c_bi_class_blank) ||
      !it.retrieve_float(src_2_location,sample_rate) ||
      !it.retrieve_integer(src_3_location,buffer_frames))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PaStream#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  const PaStreamParameters *input = NULL;
  const PaStreamParameters *output = NULL;

  // - retrieve input parameters -
  if (src_0_location->v_type == c_bi_class_pa_parameters)
  {
    input = (const PaStreamParameters *)src_0_location->v_data_ptr;
  }

  // - retrieve output parameters -
  if (src_1_location->v_type == c_bi_class_pa_parameters)
  {
    output = (const PaStreamParameters *)src_1_location->v_data_ptr;
  }

  // - ERROR -
  if (input == NULL && output == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_MISSING_INPUT_OR_OUTPUT_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PaStream *stream_ptr = NULL;

  // - ERROR -
  if (paNoError != Pa_OpenStream(&stream_ptr,input,output,sample_rate,buffer_frames,paClipOff,NULL,NULL))
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create pa stream object -
  pa_stream_s *pas_ptr = (pa_stream_s *)cmalloc(sizeof(pa_stream_s));
  pas_ptr->init();

  pas_ptr->stream_ptr = stream_ptr;
  pas_ptr->info_ptr = Pa_GetStreamInfo(stream_ptr);

  if (input != NULL)
  {
    // - set reference to input parameters -
    src_0_location->v_reference_cnt.atomic_inc();
    pas_ptr->input_ptr = src_0_location;
  }

  if (output != NULL)
  {
    // - set reference to output parameters -
    src_1_location->v_reference_cnt.atomic_inc();
    pas_ptr->output_ptr = src_1_location;
  }

  dst_location->v_data_ptr = (pa_stream_s *)pas_ptr;

  return true;
}/*}}}*/

bool bic_pa_stream_method_start_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_stream_s *pas_ptr = (pa_stream_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (paNoError != Pa_StartStream(pas_ptr->stream_ptr))
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_START_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_pa_stream_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_stream_s *pas_ptr = (pa_stream_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (paNoError != Pa_StopStream(pas_ptr->stream_ptr))
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_STOP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_pa_stream_method_read_available_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_stream_s *pas_ptr = (pa_stream_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (pas_ptr->input_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_OUTPUT_ONLY_STREAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = Pa_GetStreamReadAvailable(pas_ptr->stream_ptr);

  // - ERROR -
  if (result < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_READ_AVAILABLE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pa_stream_method_write_available_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pa_stream_s *pas_ptr = (pa_stream_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (pas_ptr->output_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_INPUT_ONLY_STREAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = Pa_GetStreamWriteAvailable(pas_ptr->stream_ptr);

  // - ERROR -
  if (result < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_WRITE_AVAILABLE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pa_stream_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int frame_count;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,frame_count))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("read#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (frame_count <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_READ_WRONG_FRAME_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pa_stream_s *pas_ptr = (pa_stream_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (pas_ptr->input_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_OUTPUT_ONLY_STREAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PaStreamParameters *input_ptr = (PaStreamParameters *)pas_ptr->input_ptr->v_data_ptr;
  PaError sample_size = Pa_GetSampleSize(input_ptr->sampleFormat);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(frame_count*input_ptr->channelCount*sample_size);

  // - ERROR -
  if (paNoError != Pa_ReadStream(pas_ptr->stream_ptr,string_ptr->data,frame_count))
  {
    string_ptr->clear();
    cfree(string_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_pa_stream_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pa_stream_s *pas_ptr = (pa_stream_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (pas_ptr->output_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_INPUT_ONLY_STREAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned string_length = string_ptr->size - 1;

  PaStreamParameters *output_ptr = (PaStreamParameters *)pas_ptr->output_ptr->v_data_ptr;
  int frame_size = output_ptr->channelCount*Pa_GetSampleSize(output_ptr->sampleFormat);

  // - ERROR -
  if (string_length % frame_size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_WRITE_WRONG_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned long frame_count = string_length / frame_size;

  // - ERROR -
  if (paNoError != Pa_WriteStream(pas_ptr->stream_ptr,string_ptr->data,frame_count))
  {
    exception_s::throw_exception(it,module.error_base + c_error_PA_STREAM_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_pa_stream_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PaStream"),"PaStream");
  );

  return true;
}/*}}}*/

bool bic_pa_stream_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PaStream");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

