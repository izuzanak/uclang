
@begin
include "ao_module.h"
@end

// - AO indexes of built in classes -
unsigned c_bi_class_ao_format = c_idx_not_exist;
unsigned c_bi_class_ao_device = c_idx_not_exist;

// - AO module -
built_in_module_s module =
{/*{{{*/
  2,                  // Class count
  ao_classes,         // Classes

  0,                  // Error base index
  6,                  // Error count
  ao_error_strings,   // Error strings

  ao_initialize,      // Initialize function
  ao_print_exception, // Print exceptions function
};/*}}}*/

// - AO classes -
built_in_class_s *ao_classes[] =
{/*{{{*/
  &ao_format_class,
  &ao_device_class,
};/*}}}*/

// - AO error strings -
const char *ao_error_strings[] =
{/*{{{*/
  "error_AO_DEVICE_UNKNOWN_DRIVER_NAME",
  "error_AO_DEVICE_OPTIONS_NOT_DIVISIBLE_BY_TWO",
  "error_AO_DEVICE_OPTION_KEY_STRING_EXPECTED",
  "error_AO_DEVICE_OPTION_VALUE_STRING_EXPECTED",
  "error_AO_DEVICE_CANNOT_OPEN_DEVICE",
  "error_AO_DEVICE_CANNOT_PLAY_AUDIO_DATA",
};/*}}}*/

// - AO initialize -
bool ao_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ao_format class identifier -
  c_bi_class_ao_format = class_base_idx++;

  // - initialize ao_device class identifier -
  c_bi_class_ao_device = class_base_idx++;

  return true;
}/*}}}*/

// - AO print exception -
bool ao_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_AO_DEVICE_UNKNOWN_DRIVER_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUknown AO driver name \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AO_DEVICE_OPTIONS_NOT_DIVISIBLE_BY_TWO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLength of options array is not divisible by two\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AO_DEVICE_OPTION_KEY_STRING_EXPECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nString expected as option key at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AO_DEVICE_OPTION_VALUE_STRING_EXPECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nString expected as option value at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AO_DEVICE_CANNOT_OPEN_DEVICE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open AO device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AO_DEVICE_CANNOT_PLAY_AUDIO_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot play audio data by AO device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class AO_FORMAT -
built_in_class_s ao_format_class =
{/*{{{*/
  "AoFormat",
  c_modifier_public | c_modifier_final,
  4, ao_format_methods,
  3, ao_format_variables,
  bic_ao_format_consts,
  bic_ao_format_init,
  bic_ao_format_clear,
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

built_in_method_s ao_format_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ao_format_operator_binary_equal
  },
  {
    "AoFormat#5",
    c_modifier_public | c_modifier_final,
    bic_ao_format_method_AoFormat_5
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ao_format_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ao_format_method_print_0
  },
};/*}}}*/

built_in_variable_s ao_format_variables[] =
{/*{{{*/

  // - byte format constants -
  { "AO_FMT_LITTLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AO_FMT_BIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AO_FMT_NATIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_ao_format_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert ao byte format constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_AO_FORMAT_BYTE_FORMAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_AO_FORMAT_BYTE_FORMAT_BIC_STATIC(AO_FMT_LITTLE);
    CREATE_AO_FORMAT_BYTE_FORMAT_BIC_STATIC(AO_FMT_BIG);
    CREATE_AO_FORMAT_BYTE_FORMAT_BIC_STATIC(AO_FMT_NATIVE);
  }

}/*}}}*/

void bic_ao_format_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ao_format_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ao_format_s *aof_ptr = (ao_format_s *)location_ptr->v_data_ptr;

  if (aof_ptr != NULL)
  {
    aof_ptr->clear(it);
    cfree(aof_ptr);
  }
}/*}}}*/

bool bic_ao_format_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ao_format_method_AoFormat_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int bits;
  long long int rate;
  long long int channels;
  long long int byte_format;

  if (!it.retrieve_integer(src_0_location,bits) ||
      !it.retrieve_integer(src_1_location,rate) ||
      !it.retrieve_integer(src_2_location,channels) ||
      !it.retrieve_integer(src_3_location,byte_format) ||
      src_4_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AoFormat#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_4_location->v_data_ptr;

  // - create ao_format object -
  ao_format_s *aof_ptr = (ao_format_s *)cmalloc(sizeof(ao_format_s));
  aof_ptr->init();

  ao_sample_format &sample_format = aof_ptr->sample_format;

  // - set reference to channel input matrix string -
  src_4_location->v_reference_cnt.atomic_inc();
  aof_ptr->matrix_loc_ptr = src_4_location;

  // - set sample format properties -
  sample_format.bits = bits;
  sample_format.rate = rate;
  sample_format.channels = channels;
  sample_format.byte_format = byte_format;
  sample_format.matrix = string_ptr->data;

  // - set ao_format destination location -
  dst_location->v_data_ptr = (basic_64b)aof_ptr;

  return true;
}/*}}}*/

bool bic_ao_format_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AoFormat"),"AoFormat");
  );

  return true;
}/*}}}*/

bool bic_ao_format_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AoFormat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AO_DEVICE -
built_in_class_s ao_device_class =
{/*{{{*/
  "AoDevice",
  c_modifier_public | c_modifier_final,
  7, ao_device_methods,
  0, ao_device_variables,
  bic_ao_device_consts,
  bic_ao_device_init,
  bic_ao_device_clear,
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

built_in_method_s ao_device_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ao_device_operator_binary_equal
  },
  {
    "AoDevice#3",
    c_modifier_public | c_modifier_final,
    bic_ao_device_method_AoDevice_3
  },
  {
    "AoDevice#5",
    c_modifier_public | c_modifier_final,
    bic_ao_device_method_AoDevice_5
  },
  {
    "driver_id#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ao_device_method_driver_id_1
  },
  {
    "play#1",
    c_modifier_public | c_modifier_final,
    bic_ao_device_method_play_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ao_device_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ao_device_method_print_0
  },
};/*}}}*/

built_in_variable_s ao_device_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_AO_DEVICE_RETRIEVE_PARAMETERS(DRIVER_ID_LOC,SAMPLE_FORMAT_LOC,OPTIONS_LOC) \
/*{{{*/\
\
  /* - retrieve driver by its name - */\
  if (DRIVER_ID_LOC->v_type == c_bi_class_string)\
  {\
    /* - retrieve driver id by its name - */\
    driver_id = ao_driver_id(((string_s *)DRIVER_ID_LOC->v_data_ptr)->data);\
\
    /* - ERROR - */\
    if (driver_id == -1)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_UNKNOWN_DRIVER_NAME,operands[c_source_pos_idx],DRIVER_ID_LOC);\
      return false;\
    }\
  }\
\
  ao_format_s *aof_ptr = (ao_format_s *)SAMPLE_FORMAT_LOC->v_data_ptr;\
  pointer_array_s *opt_array_ptr = (pointer_array_s *)OPTIONS_LOC->v_data_ptr;\
\
  /* - ERROR - */\
  if (opt_array_ptr->used & 1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_OPTIONS_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  ao_option *options = NULL;\
\
  /* - construct options from options array - */\
  if (opt_array_ptr->used > 0)\
  {\
    pointer *o_ptr = opt_array_ptr->data;\
    pointer *o_ptr_end = o_ptr + opt_array_ptr->used;\
\
    do {\
      location_s *key_location = it.get_location_value(o_ptr[0]);\
      location_s *value_location = it.get_location_value(o_ptr[1]);\
\
      /* - ERROR - */\
      if (key_location->v_type != c_bi_class_string)\
      {\
        ao_free_options(options);\
\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_OPTION_KEY_STRING_EXPECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push((o_ptr - opt_array_ptr->data) >> 1);\
\
        return false;\
      }\
\
      /* - ERROR - */\
      if (value_location->v_type != c_bi_class_string)\
      {\
        ao_free_options(options);\
\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_OPTION_VALUE_STRING_EXPECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push((o_ptr - opt_array_ptr->data) >> 1);\
\
        return false;\
      }\
\
      /* - append option to options - */\
      ao_append_option(&options,\
        ((string_s *)key_location->v_data_ptr)->data,\
        ((string_s *)value_location->v_data_ptr)->data);\
\
    } while((o_ptr += 2) < o_ptr_end);\
  }\
/*}}}*/

void bic_ao_device_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ao_device_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ao_device_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ao_device *aod_ptr = (ao_device *)location_ptr->v_data_ptr;

  if (aod_ptr != NULL)
  {
    ao_close(aod_ptr);
  }
}/*}}}*/

bool bic_ao_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ao_device_method_AoDevice_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int driver_id = -1;

  if (!(it.retrieve_integer(src_0_location,driver_id) || src_0_location->v_type == c_bi_class_string) ||
      src_1_location->v_type != c_bi_class_ao_format ||
      src_2_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AoDevice#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  BIC_AO_DEVICE_RETRIEVE_PARAMETERS(src_0_location,src_1_location,src_2_location);

  // - open live ao device -
  ao_device *aod_ptr = ao_open_live(driver_id,&aof_ptr->sample_format,options);

  // - ERROR -
  if (aod_ptr == NULL)
  {
    ao_free_options(options);

    exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_CANNOT_OPEN_DEVICE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - release options -
  ao_free_options(options);

  // - set ao_device destination location -
  dst_location->v_data_ptr = (basic_64b)aod_ptr;

  return true;
}/*}}}*/

bool bic_ao_device_method_AoDevice_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int driver_id = -1;
  long long int overwrite;

  if (!(it.retrieve_integer(src_0_location,driver_id) || src_0_location->v_type == c_bi_class_string) ||
      src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,overwrite) ||
      src_3_location->v_type != c_bi_class_ao_format ||
      src_4_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AoDevice#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  BIC_AO_DEVICE_RETRIEVE_PARAMETERS(src_0_location,src_3_location,src_4_location);

  string_s *filename_ptr = (string_s *)src_1_location->v_data_ptr;

  // - open file ao device -
  ao_device *aod_ptr = ao_open_file(driver_id,filename_ptr->data,overwrite,&aof_ptr->sample_format,options);

  // - ERROR -
  if (aod_ptr == NULL)
  {
    ao_free_options(options);

    exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_CANNOT_OPEN_DEVICE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - release options -
  ao_free_options(options);

  // - set ao_device destination location -
  dst_location->v_data_ptr = (basic_64b)aod_ptr;

  return true;
}/*}}}*/

bool bic_ao_device_method_driver_id_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ao_device,"driver_id#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve driver id by its name -
  long long int result = ao_driver_id(string_ptr->data);
  
  // - ERROR -
  if (result == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_UNKNOWN_DRIVER_NAME,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ao_device_method_play_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("play#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ao_device *aod_ptr = (ao_device *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  if (ao_play(aod_ptr,string_ptr->data,string_ptr->size - 1) == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AO_DEVICE_CANNOT_PLAY_AUDIO_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ao_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AoDevice"),"AoDevice");
  );

  return true;
}/*}}}*/

bool bic_ao_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AoDevice");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

