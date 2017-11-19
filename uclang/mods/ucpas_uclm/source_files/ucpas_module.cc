
@begin
include "ucpas_module.h"
@end

// - UCPAS indexes of built in classes -
unsigned c_bi_class_pas = c_idx_not_exist;
unsigned c_bi_class_pas_device = c_idx_not_exist;

// - UCPAS module -
built_in_module_s module =
{/*{{{*/
  2,                      // Class count
  ucpas_classes,          // Classes

  0,                      // Error base index
  9,                      // Error count
  ucpas_error_strings,    // Error strings

  ucpas_initialize,       // Initialize function
  ucpas_print_exception,  // Print exceptions function
};/*}}}*/

// - UCPAS classes -
built_in_class_s *ucpas_classes[] =
{/*{{{*/
  &pas_class,
  &pas_device_class,
};/*}}}*/

// - UCPAS error strings -
const char *ucpas_error_strings[] =
{/*{{{*/
  "error_PAS_LIB_ALREADY_INITIALIZED",
  "error_PAS_LIB_INITIALIZE_ERROR",
  "error_PAS_LIB_WRONG_IP_ADDRESS_FORMAT",
  "error_PAS_LIB_WRONG_SAMPLES_DATA_LENGTH",
  "error_PAS_LIB_WRONG_SINE_SAMPLE_COUNT",
  "error_PAS_LIB_WRONG_SINE_COUNT",
  "error_PAS_LIB_WRONG_SINE_AMPLITUDE",
  "error_PAS_LIB_WRONG_VOLUME_VALUE",
  "error_PAS_DEVICE_VERSION_STRING_TOO_LONG",
};/*}}}*/

// - UCPAS initialize -
bool ucpas_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize pas class identifier -
  c_bi_class_pas = class_base_idx++;

  // - initialize pas_device class identifier -
  c_bi_class_pas_device = class_base_idx++;

  return true;
}/*}}}*/

// - UCPAS print exception -
bool ucpas_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PAS_LIB_ALREADY_INITIALIZED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPAS library is already initialized\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_INITIALIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPAS library, initialize error - %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_WRONG_IP_ADDRESS_FORMAT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong format of ip address, expecting IPv4 string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_WRONG_SAMPLES_DATA_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong length of samples data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_WRONG_SINE_SAMPLE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of generated sine samples\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_WRONG_SINE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of generated sines\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_WRONG_SINE_AMPLITUDE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong amplitude of generated sines\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_LIB_WRONG_VOLUME_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong volume value %" HOST_LL_FORMAT "d, expected value 0 - 100\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PAS_DEVICE_VERSION_STRING_TOO_LONG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVersion string is too long, max length is %" HOST_LL_FORMAT "d bytes\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class PAS -
built_in_class_s pas_class =
{/*{{{*/
  "Pas",
  c_modifier_public | c_modifier_final,
  26, pas_methods,
  1, pas_variables,
  bic_pas_consts,
  bic_pas_init,
  bic_pas_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s pas_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pas_operator_binary_equal
  },
  {
    "Pas#5",
    c_modifier_public | c_modifier_final,
    bic_pas_method_Pas_5
  },
  {
    "master_ip#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_master_ip_0
  },
  {
    "master_ip#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_master_ip_1
  },
  {
    "device#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_device_0
  },
  {
    "device#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_device_1
  },
  {
    "update_device_status#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_update_device_status_0
  },
  {
    "samples_append#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_samples_append_1
  },
  {
    "samples_append_sine#3",
    c_modifier_public | c_modifier_final,
    bic_pas_method_samples_append_sine_3
  },
  {
    "samples_append_silence#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_samples_append_silence_1
  },
  {
    "samples_clear#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_samples_clear_0
  },
  {
    "samples_count#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_samples_count_0
  },
  {
    "hold_delay#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_hold_delay_0
  },
  {
    "hold_delay#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_hold_delay_1
  },
  {
    "holding#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_holding_0
  },
  {
    "audio_section#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_audio_section_0
  },
  {
    "audio_section#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_audio_section_1
  },
  {
    "priority#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_priority_0
  },
  {
    "priority#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_priority_1
  },
  {
    "volume#0",
    c_modifier_public | c_modifier_final,
    bic_pas_method_volume_0
  },
  {
    "volume#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_volume_1
  },
  {
    "pause#1",
    c_modifier_public | c_modifier_final,
    bic_pas_method_pause_1
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pas_method_version_0
  },
  {
    "debug#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pas_method_debug_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pas_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pas_method_print_0
  },
};/*}}}*/

built_in_variable_s pas_variables[] =
{/*{{{*/
  {
    "PAS_SAMPLES",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_pas_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(1);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_PAS_BIC_STATIC_VALUE(VALUE)\
  {\
    cv_ptr->v_type = c_bi_class_integer;\
    cv_ptr->v_reference_cnt.atomic_set(1);\
    cv_ptr->v_data_ptr = (long long int)VALUE;\
    cv_ptr++;\
  }

  CREATE_PAS_BIC_STATIC_VALUE(PAS_SAMPLES);

}/*}}}*/

void bic_pas_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pointer)nullptr;
}/*}}}*/

void bic_pas_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - lock pas data mutex -
  pas_s::mutex.lock();

  if (pas_s::lib_status != PAS_STATUS_CLOSED)
  {
    // - close pas library -
    pas_close();

    // - update pas status -
    pas_s::lib_status = PAS_STATUS_CLOSED;
  }

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  // - clear pas object -
  pas_s::clear(it);

}/*}}}*/

bool bic_pas_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pas_method_Pas_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int multi_port;
  long long int master_port;

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,multi_port) ||
      !it.retrieve_integer(src_3_location,master_port) ||
      src_4_location->v_type != c_bi_class_pas_device)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Pas#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  // - ERROR -
  if (pas_s::lib_status != PAS_STATUS_CLOSED)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_ALREADY_INITIALIZED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *device_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *multi_ptr = (string_s *)src_1_location->v_data_ptr;
  pas_device_s *pd_ptr = (pas_device_s *)src_4_location->v_data_ptr;

  // - initialize pas object -
  pas_s::init();

  // - initialize pas device -
  pas_s::device = *pd_ptr;

  // - ERROR -
  fn_t res;
  if ((res = pas_init(device_ptr->data,multi_ptr->data,multi_port,master_port)) != SUCCESS)
  {
    pas_s::clear(it);

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_INITIALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  // - update pas library status -
  pas_s::lib_status = PAS_STATUS_INITIALIZED;

  // - register basic events -
  pas_register(PAS_EVT_IDENTIFY,pas_s::callback,0);
  pas_register(PAS_EVT_CHANGEMASTER,pas_s::callback,0);
  pas_register(PAS_EVT_TRANSMIT_AUDIO,pas_s::callback,24000);

  return true;
}/*}}}*/

bool bic_pas_method_master_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  // - retrieve pas master ip -
  unsigned master_ip = pas_s::master_ip;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  if (master_ip == 0)
  {
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    // - create address string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->create(16);

    int char_cnt;

    if (c_little_endian)
    {
      // - format address string -
      char_cnt = snprintf(string_ptr->data,string_ptr->size,"%u.%u.%u.%u",
          (master_ip >>  0) & 0xff,
          (master_ip >>  8) & 0xff,
          (master_ip >> 16) & 0xff,
          (master_ip >> 24) & 0xff);
    }
    else
    {
      // - format address string -
      char_cnt = snprintf(string_ptr->data,string_ptr->size,"%u.%u.%u.%u",
          (master_ip >> 24) & 0xff,
          (master_ip >> 16) & 0xff,
          (master_ip >>  8) & 0xff,
          (master_ip >>  0) & 0xff);
    }

    // - set result string size -
    string_ptr->size = char_cnt + 1;

    BIC_SET_RESULT_STRING(string_ptr);
  }

  return true;
}/*}}}*/

bool bic_pas_method_master_ip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("master_ip#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  do {
    long comp[4];
    char *ptr = string_ptr->data;
    char *end_ptr;

    comp[0] = strtol(ptr,&end_ptr,10);
    if (ptr == end_ptr || comp[0] < 0 || comp[0] > 255 || *end_ptr != '.') break;
    ptr = end_ptr + 1;

    comp[1] = strtol(ptr,&end_ptr,10);
    if (ptr == end_ptr || comp[1] < 0 || comp[1] > 255 || *end_ptr != '.') break;
    ptr = end_ptr + 1;

    comp[2] = strtol(ptr,&end_ptr,10);
    if (ptr == end_ptr || comp[2] < 0 || comp[2] > 255 || *end_ptr != '.') break;
    ptr = end_ptr + 1;

    comp[3] = strtol(ptr,&end_ptr,10);
    if (ptr == end_ptr || comp[3] < 0 || comp[3] > 255 || *end_ptr != '\0') break;

    unsigned master_ip = c_little_endian ?
      (comp[0] << 0) | (comp[1] << 8) | (comp[2] << 16) | (comp[3] << 24) :
      (comp[0] << 24) | (comp[1] << 16) | (comp[2] << 0) | (comp[3] << 0);

    // - lock pas data mutex -
    pas_s::mutex.lock();

    // - set pas master ip -
    pas_setmasterip(master_ip);
    pas_s::master_ip = master_ip;

    // - unlock pas data mutex -
    pas_s::mutex.unlock();

    BIC_SET_RESULT_DESTINATION();

    return true;

  } while(0);

  // - ERROR -
  exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_IP_ADDRESS_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
  return false;
}/*}}}*/

bool bic_pas_method_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - create pas device object -
  pas_device_s *pd_ptr = (pas_device_s *)cmalloc(sizeof(pas_device_s));
  pd_ptr->init();

  // - lock pas data mutex -
  pas_s::mutex.lock();

  // - retrieve pas device values -
  *pd_ptr = pas_s::device;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_pas_device,pd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_pas_method_device_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_pas_device)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("update_status#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pas_device_s *pd_ptr = (pas_device_s *)src_0_location->v_data_ptr;

  // - lock pas data mutex -
  pas_s::mutex.lock();

  // - update pas device -
  pas_s::device = *pd_ptr;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_update_device_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  // - update device status -
  pas_update_status(pas_s::device.uid,pas_s::device.vid,pas_s::device.fail_code,pas_s::device.status,&pas_s::device.ident);

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_pas_method_samples_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("samples_append#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if ((string_ptr->size - 1) & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_SAMPLES_DATA_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - if string is not empty -
  if (string_ptr->size - 1 > 0)
  {
    // - lock pas data mutex -
    pas_s::mutex.lock();

    // - reset hold counter -
    pas_s::hold_counter = 0;

    if (c_little_endian)
    {
      // - append data to sample queue -
      short *s_ptr = (short *)string_ptr->data;
      short *s_ptr_end = s_ptr + ((string_ptr->size - 1) >> 1);
      do {
        pas_s::sample_queue.insert(*s_ptr);
      } while(++s_ptr < s_ptr_end);
    }
    else
    {
      // - append data to sample queue -
      char *sc_ptr = (char *)string_ptr->data;
      char *sc_ptr_end = sc_ptr + string_ptr->size - 1;

      // - temporary sample value -
      short sample_value;
      char *svc_ptr = (char *)&sample_value;

      do {
        svc_ptr[0] = sc_ptr[1];
        svc_ptr[1] = sc_ptr[0];

        pas_s::sample_queue.insert(sample_value);
      } while((sc_ptr += 2) < sc_ptr_end);
    }

    // - unlock pas data mutex -
    pas_s::mutex.unlock();
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_samples_append_sine_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int sine_sample_cnt;
  long long int sine_cnt;
  long long int amplitude;

  if (!it.retrieve_integer(src_0_location,sine_sample_cnt) ||
      !it.retrieve_integer(src_1_location,sine_cnt) ||
      !it.retrieve_integer(src_2_location,amplitude))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("samples_append_sine#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  if (sine_sample_cnt <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_SINE_SAMPLE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (sine_cnt < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_SINE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (amplitude < 0 || amplitude > 0x7fff)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_SINE_AMPLITUDE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (sine_cnt > 0)
  {
    short sine_buff[sine_sample_cnt];

    // - compute sine buffer -
    unsigned sample_idx = 0;
    do {
      sine_buff[sample_idx] = amplitude*sin(((double)c_2pi_number*sample_idx)/sine_sample_cnt);
    } while(++sample_idx < sine_sample_cnt);

    // - fix data endianity -
    if (!c_little_endian)
    {
      char *sc_ptr = (char *)sine_buff;
      char *sc_ptr_end = sc_ptr + sine_sample_cnt;
      char tmp;
      do {
        tmp = sc_ptr[0];
        sc_ptr[0] = sc_ptr[1];
        sc_ptr[1] = tmp;
      } while((sc_ptr += 2) < sc_ptr_end);
    }

    // - lock pas data mutex -
    pas_s::mutex.lock();

    // - reset hold counter -
    pas_s::hold_counter = 0;

    unsigned sine_idx = 0;
    do {

      // - insert sine samples to sample queue -
      short *sample_ptr = sine_buff;
      short *sample_ptr_end = sample_ptr + sine_sample_cnt;
      do {
        pas_s::sample_queue.insert(*sample_ptr);
      } while(++sample_ptr < sample_ptr_end);

    } while(++sine_idx < sine_cnt);

    // - unlock pas data mutex -
    pas_s::mutex.unlock();
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_samples_append_silence_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int sample_cnt;

  if (!it.retrieve_integer(src_0_location,sample_cnt))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("samples_append_silence#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (sample_cnt < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_SAMPLES_DATA_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (sample_cnt > 0)
  {
    // - lock pas data mutex -
    pas_s::mutex.lock();

    // - reset hold counter -
    pas_s::hold_counter = 0;

    // - append data to sample queue -
    long long int sample_idx = 0;
    do {
      pas_s::sample_queue.insert(0);
    } while(++sample_idx < sample_cnt);

    // - unlock pas data mutex -
    pas_s::mutex.unlock();
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_samples_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  // FIXME TODO set hold counter to delay?

  // - remove all samples from pas samples queue -
  pas_s::sample_queue.clear();

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_pas_method_samples_count_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  // - retrieve count of samples in pas queue -
  long long int result = pas_s::sample_queue.used;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pas_method_hold_delay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  long long int result = (pas_s::hold_delay*10)/PAS_SAMPLES;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pas_method_hold_delay_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int hold_delay;

  if (!it.retrieve_integer(src_0_location,hold_delay))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("hold_delay#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - lock pas data mutex -
  pas_s::mutex.lock();

  pas_s::hold_delay = (hold_delay*PAS_SAMPLES)/10;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_holding_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  long long int result = pas_s::hold_counter > 0;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pas_method_audio_section_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  long long int result = pas_s::audio_section;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pas_method_audio_section_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int audio_section;

  if (!it.retrieve_integer(src_0_location,audio_section))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("audio_section#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - lock pas data mutex -
  pas_s::mutex.lock();

  pas_s::audio_section = audio_section;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_priority_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  long long int result = pas_s::priority;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pas_method_priority_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int priority;

  if (!it.retrieve_integer(src_0_location,priority))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("priority#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - lock pas data mutex -
  pas_s::mutex.lock();

  pas_s::priority = priority;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_volume_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - lock pas data mutex -
  pas_s::mutex.lock();

  long long int result = pas_s::volume;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pas_method_volume_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int volume;

  if (!it.retrieve_integer(src_0_location,volume))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("volume#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (volume < 0 || volume > 100)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PAS_LIB_WRONG_VOLUME_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(volume);

    return false;
  }

  // - lock pas data mutex -
  pas_s::mutex.lock();

  pas_s::volume = volume;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_pause_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int state;

  if (!it.retrieve_integer(src_0_location,state))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("pause#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - lock pas data mutex -
  pas_s::mutex.lock();

  pas_s::paused = state != 0;

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - retrieve pas version -
  const char *version = pas_version(nullptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_pas_method_debug_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int level;

  if (!it.retrieve_integer(src_0_location,level))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_pas,"debug#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - set pas debug level -
  pas_debug(level);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_pas_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Pas"),"Pas");
  );

  return true;
}/*}}}*/

bool bic_pas_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Pas");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PAS_DEVICE -
built_in_class_s pas_device_class =
{/*{{{*/
  "PasDevice",
  c_modifier_public | c_modifier_final,
  16, pas_device_methods,
  2 + 7, pas_device_variables,
  bic_pas_device_consts,
  bic_pas_device_init,
  bic_pas_device_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s pas_device_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_operator_binary_equal
  },
  {
    "PasDevice#2",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_PasDevice_2
  },
  {
    "uid#0",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_uid_0
  },
  {
    "vid#0",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_vid_0
  },
  {
    "status#0",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_status_0
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_version_0
  },
  {
    "section#0",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_section_0
  },
  {
    "dev_type#0",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_dev_type_0
  },
  {
    "uid#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_uid_1
  },
  {
    "vid#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_vid_1
  },
  {
    "status#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_status_1
  },
  {
    "version#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_version_1
  },
  {
    "section#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_section_1
  },
  {
    "dev_type#1",
    c_modifier_public | c_modifier_final,
    bic_pas_device_method_dev_type_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pas_device_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pas_device_method_print_0
  },
};/*}}}*/

built_in_variable_s pas_device_variables[] =
{/*{{{*/

  // - event types -
  { "EVENT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_LOG", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - device types -
  { "DEV_TYPE_ANYCOMM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEV_TYPE_RUX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEV_TYPE_RUX_L", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEV_TYPE_HJT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEV_TYPE_HJC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEV_TYPE_RZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEV_TYPE_UCLCD", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_pas_device_consts(location_array_s &const_locations)
{/*{{{*/

  // - device types -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_PAS_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_PAS_EVENT_TYPE_BIC_STATIC(PKT_EVT_ERR);
    CREATE_PAS_EVENT_TYPE_BIC_STATIC(PKT_EVT_LOG);
  }

  // - device types -
  {
    const_locations.push_blanks(7);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 7);

#define CREATE_PAS_DEVICE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_ANYCOMM);
    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_RUX);
    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_RUX_L);
    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_HJT);
    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_HJC);
    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_RZE);
    CREATE_PAS_DEVICE_TYPE_BIC_STATIC(PKT_DEVTYPE_UCLCD);
  }

}/*}}}*/

void bic_pas_device_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pas_device_s *)nullptr;
}/*}}}*/

void bic_pas_device_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pas_device_s *pd_ptr = (pas_device_s *)location_ptr->v_data_ptr;

  // - if pas device exists -
  if (pd_ptr != nullptr)
  {
    pd_ptr->clear(it);
    cfree(pd_ptr);
  }
}/*}}}*/

bool bic_pas_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_pas_device_method_PasDevice_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int uid;
  long long int vid;

  if (!it.retrieve_integer(src_0_location,uid) ||
      !it.retrieve_integer(src_1_location,vid))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PasDevice#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - create pas device object -
  pas_device_s *pd_ptr = (pas_device_s *)cmalloc(sizeof(pas_device_s));
  pd_ptr->init();

  // - initialize pas device uid and vid -
  pd_ptr->uid = uid;
  pd_ptr->vid = vid;

  dst_location->v_data_ptr = (pas_device_s *)pd_ptr;

  return true;
}/*}}}*/

#define BIC_PAS_DEVICE_GET_INTEGER(STRUCT_NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  long long int result = ((pas_device_s *)dst_location->v_data_ptr)->STRUCT_NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_PAS_DEVICE_SET_INTEGER(VAR_NAME,STRUCT_NAME,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  long long int VAR_NAME;\
\
  if (!it.retrieve_integer(src_0_location,VAR_NAME))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  pas_device_s *pd_ptr = (pas_device_s *)dst_location->v_data_ptr;\
  pd_ptr->STRUCT_NAME = VAR_NAME;\
\
  BIC_SET_RESULT_DESTINATION();\
\
  return true;\
}/*}}}*/

bool bic_pas_device_method_uid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_GET_INTEGER(uid);
}/*}}}*/

bool bic_pas_device_method_vid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_GET_INTEGER(vid);
}/*}}}*/

bool bic_pas_device_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_GET_INTEGER(status);
}/*}}}*/

bool bic_pas_device_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *version = (const char *)((pas_device_s *)dst_location->v_data_ptr)->ident.version;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_pas_device_method_section_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_GET_INTEGER(ident.section);
}/*}}}*/

bool bic_pas_device_method_dev_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_GET_INTEGER(ident.devtype);
}/*}}}*/

bool bic_pas_device_method_uid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_SET_INTEGER(uid,uid,"uid#1");
}/*}}}*/

bool bic_pas_device_method_vid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_SET_INTEGER(vid,vid,"vid#1");
}/*}}}*/

bool bic_pas_device_method_status_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_SET_INTEGER(status,status,"status#1");
}/*}}}*/

bool bic_pas_device_method_version_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("version#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pas_device_s *pd_ptr = (pas_device_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (string_ptr->size > PKT_VERSION_SIZE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PAS_DEVICE_VERSION_STRING_TOO_LONG,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(PKT_VERSION_SIZE);

    return false;
  }

  // - set device version -
  memcpy(pd_ptr->ident.version,string_ptr->data,string_ptr->size);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_pas_device_method_section_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_SET_INTEGER(section,ident.section,"section#1");
}/*}}}*/

bool bic_pas_device_method_dev_type_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PAS_DEVICE_SET_INTEGER(dev_type,ident.devtype,"dev_type#1");
}/*}}}*/

bool bic_pas_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PasDevice"),"PasDevice");
  );

  return true;
}/*}}}*/

bool bic_pas_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PasDevice");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

