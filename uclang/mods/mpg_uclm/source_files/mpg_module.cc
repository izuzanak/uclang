
@begin
include "mpg_module.h"
@end

// - MPG indexes of built in classes -
unsigned c_bi_class_mpg = c_idx_not_exist;
unsigned c_bi_class_mpg_handle = c_idx_not_exist;

// - MPG module -
built_in_module_s module =
{/*{{{*/
  2,                   // Class count
  mpg_classes,         // Classes

  0,                   // Error base index
  17,                  // Error count
  mpg_error_strings,   // Error strings

  mpg_initialize,      // Initialize function
  mpg_print_exception, // Print exceptions function
};/*}}}*/

// - MPG classes -
built_in_class_s *mpg_classes[] =
{/*{{{*/
  &mpg_class,
  &mpg_handle_class,
};/*}}}*/

// - MPG error strings -
const char *mpg_error_strings[] =
{/*{{{*/
  "error_MPG_HANDLE_CREATE_NEW_ERROR",
  "error_MPG_HANDLE_ALREADY_OPENED",
  "error_MPG_HANDLE_NOT_OPENED",
  "error_MPG_HANDLE_NOT_OPENED_IN_FEED_MODE",
  "error_MPG_HANDLE_OPEN_FILE_ERROR",
  "error_MPG_HANDLE_OPEN_FEED_ERROR",
  "error_MPG_HANDLE_UNKNOWN_PARAMETER_ID",
  "error_MPG_HANDLE_WRONG_PARAMETER_VALUE_TYPE",
  "error_MPG_HANDLE_PARAMETER_SET_ERROR",
  "error_MPG_HANDLE_PARAMETER_GET_ERROR",
  "error_MPG_HANDLE_VOLUME_SET_ERROR",
  "error_MPG_HANDLE_VOLUME_GET_ERROR",
  "error_MPG_HANDLE_FEED_ERROR",
  "error_MPG_HANDLE_READ_WRONG_BUFFER_SIZE",
  "error_MPG_HANDLE_ADJUST_OUTPUT_FORMAT_ERROR",
  "error_MPG_HANDLE_READ_ERROR",
  "error_MPG_HANDLE_CLOSE_ERROR",
};/*}}}*/

// - MPG initialize -
bool mpg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize mpg class identifier -
  c_bi_class_mpg = class_base_idx++;

  // - initialize mpg_handle class identifier -
  c_bi_class_mpg_handle = class_base_idx++;

  return true;
}/*}}}*/

// - MPG print exception -
bool mpg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_MPG_HANDLE_CREATE_NEW_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating new mpg handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_ALREADY_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle already has assigned data source\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle is not opened either in file or feed mode\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_NOT_OPENED_IN_FEED_MODE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle is not opened in feed mode\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_OPEN_FILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, error while opening file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_OPEN_FEED_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, error while opening feed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_UNKNOWN_PARAMETER_ID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, unknown parameter identifier\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_WRONG_PARAMETER_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, wrong parameter value type, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_PARAMETER_SET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, cannot set parameter value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_PARAMETER_GET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, cannot retrieve parameter value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_VOLUME_SET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, cannot set output volume\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_VOLUME_GET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, cannot retrieve output volume\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_FEED_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, error while feeding data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_READ_WRONG_BUFFER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, wrong read buffer size %" HOST_LL_FORMAT "d \n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_ADJUST_OUTPUT_FORMAT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, error while adjusting output format\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMpg handle, error while reading data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MPG_HANDLE_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while closing mpg handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class MPG -
built_in_class_s mpg_class =
{/*{{{*/
  "Mpg",
  c_modifier_public | c_modifier_final,
  6, mpg_methods,
  14, mpg_variables,
  bic_mpg_consts,
  bic_mpg_init,
  bic_mpg_clear,
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

built_in_method_s mpg_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_operator_binary_equal
  },
  {
    "decoders#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_method_decoders_0
  },
  {
    "supported#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_method_supported_0
  },
  {
    "feature#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_method_feature_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_method_print_0
  },
};/*}}}*/

built_in_variable_s mpg_variables[] =
{/*{{{*/

  // - mpg feature constants -
  { "FEATURE_ABI_UTF8OPEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_OUTPUT_8BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_OUTPUT_16BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_OUTPUT_32BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_PARSE_ID3V2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_DECODE_LAYER1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_DECODE_LAYER2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_DECODE_LAYER3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_DECODE_ACCURATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_DECODE_DOWNSAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_DECODE_NTOM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_PARSE_ICY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FEATURE_TIMEOUT_READ", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_mpg_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert mpg feature constants -
  {
    const_locations.push_blanks(14);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 14);

#define CREATE_MPG_FEATURE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_ABI_UTF8OPEN);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_OUTPUT_8BIT);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_OUTPUT_16BIT);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_OUTPUT_32BIT);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_INDEX);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_PARSE_ID3V2);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_DECODE_LAYER1);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_DECODE_LAYER2);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_DECODE_LAYER3);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_DECODE_ACCURATE);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_DECODE_DOWNSAMPLE);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_DECODE_NTOM);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_PARSE_ICY);
    CREATE_MPG_FEATURE_BIC_STATIC(MPG123_FEATURE_TIMEOUT_READ);
  }

}/*}}}*/

void bic_mpg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_mpg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_mpg_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_MPG_STRING_ARRAY_FROM_NULL_TERMINATED(POINTER) \
{/*{{{*/\
  pointer_array_s *array_ptr = it.get_new_array_ptr();\
\
  /* - fill result string array - */\
  const char **d_ptr = decoders;\
\
  while (*d_ptr != NULL)\
  {\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->set(strlen(*d_ptr),*d_ptr);\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    array_ptr->push(new_location);\
\
    ++d_ptr;\
  }\
\
  /* - create string array location - */\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

bool bic_mpg_method_decoders_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - retrieve decoders list -
  const char **decoders = mpg123_decoders();

  BIC_MPG_STRING_ARRAY_FROM_NULL_TERMINATED(decoders);

  return true;
}/*}}}*/

bool bic_mpg_method_supported_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - retrieve decoders list -
  const char **decoders = mpg123_supported_decoders();

  BIC_MPG_STRING_ARRAY_FROM_NULL_TERMINATED(decoders);

  return true;
}/*}}}*/

bool bic_mpg_method_feature_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int feature;

  if (!it.retrieve_integer(src_0_location,feature))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mpg,"feature#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int result = mpg123_feature((mpg123_feature_set)feature);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Mpg"),"Mpg");
  );

  return true;
}/*}}}*/

bool bic_mpg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Mpg");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MPG_HANDLE -
built_in_class_s mpg_handle_class =
{/*{{{*/
  "MpgHandle",
  c_modifier_public | c_modifier_final,
  18, mpg_handle_methods,
  3 + 19 + 18 + 4 + 19, mpg_handle_variables,
  bic_mpg_handle_consts,
  bic_mpg_handle_init,
  bic_mpg_handle_clear,
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

built_in_method_s mpg_handle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_operator_binary_equal
  },
  {
    "MpgHandle#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_MpgHandle_0
  },
  {
    "MpgHandle#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_MpgHandle_1
  },
  {
    "open_file#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_open_file_1
  },
  {
    "open_feed#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_open_feed_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_get_type_0
  },
  {
    "set_param#2",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_set_param_2
  },
  {
    "get_param#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_get_param_1
  },
  {
    "volume#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_volume_1
  },
  {
    "volume#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_volume_0
  },
  {
    "rate#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_rate_0
  },
  {
    "channels#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_channels_0
  },
  {
    "encoding#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_encoding_0
  },
  {
    "feed#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_feed_1
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_read_1
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_mpg_handle_method_close_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_handle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mpg_handle_method_print_0
  },
};/*}}}*/

built_in_variable_s mpg_handle_variables[] =
{/*{{{*/

  // - mpg handle types -
  { "TYPE_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FEED", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - mpg handle parameters -
  { "PARAM_VERBOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_ADD_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_FORCE_RATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_DOWN_SAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_RVA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_DOWNSPEED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_UPSPEED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_START_FRAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_DECODE_FRAMES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_ICY_INTERVAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_OUTSCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_REMOVE_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_RESYNC_LIMIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_INDEX_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_PREFRAMES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_FEEDPOOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARAM_FEEDBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - mpg handle parameter flags -
  { "FLAG_FORCE_MONO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_MONO_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_MONO_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_MONO_MIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_FORCE_STEREO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_FORCE_8BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_QUIET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_GAPLESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_NO_RESYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_SEEKBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_FUZZY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_FORCE_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_PLAIN_ID3TEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_IGNORE_STREAMLENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_SKIP_ID3V2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_IGNORE_INFOFRAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_AUTO_RESAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_PICTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - mpg handle rva choices -
  { "RVA_OFF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RVA_MIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RVA_ALBUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RVA_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - mpg handle encoding formats -
  { "ENC_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_SIGNED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_SIGNED_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_UNSIGNED_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_UNSIGNED_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_SIGNED_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_ULAW_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_ALAW_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_SIGNED_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_UNSIGNED_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_SIGNED_24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_UNSIGNED_24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_FLOAT_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_FLOAT_64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENC_ANY", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_MPG_HANDLE_GET_FORMAT_PROPERTY(PROPERTY) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;\
\
  long long int result = mh_ptr->PROPERTY;\
\
  if (result == -1)\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
  else\
  {\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }\
\
  return true;\
}/*}}}*/

void bic_mpg_handle_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert mpg handle types constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_MPG_HANDLE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MPG_HANDLE_TYPE_BIC_STATIC(c_mpg_handle_type_none);
    CREATE_MPG_HANDLE_TYPE_BIC_STATIC(c_mpg_handle_type_file);
    CREATE_MPG_HANDLE_TYPE_BIC_STATIC(c_mpg_handle_type_feed);
  }

  // - insert mpg handle parameter constants -
  {
    const_locations.push_blanks(19);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 19);

#define CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_VERBOSE);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_FLAGS);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_ADD_FLAGS);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_FORCE_RATE);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_DOWN_SAMPLE);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_RVA);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_DOWNSPEED);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_UPSPEED);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_START_FRAME);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_DECODE_FRAMES);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_ICY_INTERVAL);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_OUTSCALE);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_TIMEOUT);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_REMOVE_FLAGS);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_RESYNC_LIMIT);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_INDEX_SIZE);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_PREFRAMES);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_FEEDPOOL);
    CREATE_MPG_HANDLE_PARAMETER_BIC_STATIC(MPG123_FEEDBUFFER);
  }

  // - insert mpg handle parameter flags constants -
  {
    const_locations.push_blanks(18);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 18);

#define CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_FORCE_MONO);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_MONO_LEFT);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_MONO_RIGHT);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_MONO_MIX);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_FORCE_STEREO);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_FORCE_8BIT);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_QUIET);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_GAPLESS);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_NO_RESYNC);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_SEEKBUFFER);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_FUZZY);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_FORCE_FLOAT);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_PLAIN_ID3TEXT);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_IGNORE_STREAMLENGTH);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_SKIP_ID3V2);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_IGNORE_INFOFRAME);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_AUTO_RESAMPLE);
    CREATE_MPG_HANDLE_PARAMETER_FLAG_BIC_STATIC(MPG123_PICTURE);
  }

  // - insert mpg handle rva choices constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_MPG_HANDLE_RVA_CHOICE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MPG_HANDLE_RVA_CHOICE_BIC_STATIC(MPG123_RVA_OFF);
    CREATE_MPG_HANDLE_RVA_CHOICE_BIC_STATIC(MPG123_RVA_MIX);
    CREATE_MPG_HANDLE_RVA_CHOICE_BIC_STATIC(MPG123_RVA_ALBUM);
    CREATE_MPG_HANDLE_RVA_CHOICE_BIC_STATIC(MPG123_RVA_MAX);
  }

  // - insert mpg handle encoding format constants -
  {
    const_locations.push_blanks(19);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 19);

#define CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_8);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_16);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_24);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_32);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_SIGNED);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_FLOAT);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_SIGNED_16);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_UNSIGNED_16);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_UNSIGNED_8);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_SIGNED_8);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_ULAW_8);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_ALAW_8);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_SIGNED_32);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_UNSIGNED_32);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_SIGNED_24);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_UNSIGNED_24);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_FLOAT_32);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_FLOAT_64);
    CREATE_MPG_HANDLE_ENCODING_FORMAT_BIC_STATIC(MPG123_ENC_ANY);
  }

}/*}}}*/

void bic_mpg_handle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (mpg_handle_s *)NULL;
}/*}}}*/

void bic_mpg_handle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpg_handle_s *mh_ptr = (mpg_handle_s *)location_ptr->v_data_ptr;

  if (mh_ptr != NULL)
  {
    mh_ptr->clear(it);
    cfree(mh_ptr);
  }
}/*}}}*/

bool bic_mpg_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mpg_handle_method_MpgHandle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create new handle -
  int error;
  mpg123_handle *handle = mpg123_new(NULL,&error);

  // - ERROR -
  if (handle == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_CREATE_NEW_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mpg_handle object -
  mpg_handle_s *mh_ptr = (mpg_handle_s *)cmalloc(sizeof(mpg_handle_s));
  mh_ptr->init();

  mh_ptr->handle = handle;

  // - set mpg_handle destination location -
  dst_location->v_data_ptr = (mpg_handle_s *)mh_ptr;

  return true;
}/*}}}*/

bool bic_mpg_handle_method_MpgHandle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("MpgHandle#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create new handle -
  int error;
  mpg123_handle *handle = mpg123_new(string_ptr->data,&error);

  // - ERROR -
  if (handle == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_CREATE_NEW_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mpg_handle object -
  mpg_handle_s *mh_ptr = (mpg_handle_s *)cmalloc(sizeof(mpg_handle_s));
  mh_ptr->init();

  mh_ptr->handle = handle;

  // - set mpg_handle destination location -
  dst_location->v_data_ptr = (mpg_handle_s *)mh_ptr;

  return true;
}/*}}}*/

bool bic_mpg_handle_method_open_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("open_file#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mh_ptr->type != c_mpg_handle_type_none)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_ALREADY_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (mpg123_open(mh_ptr->handle,string_ptr->data) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_OPEN_FILE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  mh_ptr->type = c_mpg_handle_type_file;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mpg_handle_method_open_feed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mh_ptr->type != c_mpg_handle_type_none)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_ALREADY_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (mpg123_open_feed(mh_ptr->handle) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_OPEN_FEED_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  mh_ptr->type = c_mpg_handle_type_feed;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mpg_handle_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((mpg_handle_s *)dst_location->v_data_ptr)->type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpg_handle_method_set_param_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int param_type;

  if (!it.retrieve_integer(src_0_location,param_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set_param#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  long long int int_value = 0;
  double float_value = 0.0;

  // - retrieve parameter value -
  switch (param_type)
  {
    case MPG123_VERBOSE:
    case MPG123_FLAGS:
    case MPG123_ADD_FLAGS:
    case MPG123_FORCE_RATE:
    case MPG123_DOWN_SAMPLE:
    case MPG123_RVA:
    case MPG123_DOWNSPEED:
    case MPG123_UPSPEED:
    case MPG123_START_FRAME:
    case MPG123_DECODE_FRAMES:
    case MPG123_ICY_INTERVAL:
    case MPG123_OUTSCALE:
    case MPG123_TIMEOUT:
    case MPG123_REMOVE_FLAGS:
    case MPG123_RESYNC_LIMIT:
    case MPG123_INDEX_SIZE:
    case MPG123_PREFRAMES:
    case MPG123_FEEDPOOL:
    case MPG123_FEEDBUFFER:
      {
        // - ERROR -
        if (!it.retrieve_integer(src_1_location,int_value))
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_WRONG_PARAMETER_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(c_bi_class_integer);

          return false;
        }
      }
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_UNKNOWN_PARAMETER_ID,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mpg123_param(mh_ptr->handle,(mpg123_parms)param_type,int_value,float_value) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_PARAMETER_SET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mpg_handle_method_get_param_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int param_type;

  if (!it.retrieve_integer(src_0_location,param_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_param#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long int int_value = 0;
  double float_value = 0.0;

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mpg123_getparam(mh_ptr->handle,(mpg123_parms)param_type,&int_value,&float_value) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_PARAMETER_GET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve parameter value -
  switch (param_type)
  {
    case MPG123_VERBOSE:
    case MPG123_FLAGS:
    case MPG123_ADD_FLAGS:
    case MPG123_FORCE_RATE:
    case MPG123_DOWN_SAMPLE:
    case MPG123_RVA:
    case MPG123_DOWNSPEED:
    case MPG123_UPSPEED:
    case MPG123_START_FRAME:
    case MPG123_DECODE_FRAMES:
    case MPG123_ICY_INTERVAL:
    case MPG123_OUTSCALE:
    case MPG123_TIMEOUT:
    case MPG123_REMOVE_FLAGS:
    case MPG123_RESYNC_LIMIT:
    case MPG123_INDEX_SIZE:
    case MPG123_PREFRAMES:
    case MPG123_FEEDPOOL:
    case MPG123_FEEDBUFFER:
      {
        long long int result = int_value;

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

        return true;
      }
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_UNKNOWN_PARAMETER_ID,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }
}/*}}}*/

bool bic_mpg_handle_method_volume_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double volume;

  if (!it.retrieve_float(src_0_location,volume))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("volume#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mpg123_volume(mh_ptr->handle,volume) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_VOLUME_SET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mpg_handle_method_volume_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  double base;
  double really;
  double rva_db;

  // - ERROR -
  if (mpg123_getvolume(mh_ptr->handle,&base,&really,&rva_db) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_VOLUME_GET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_float,base);

  return true;
}/*}}}*/

bool bic_mpg_handle_method_rate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPG_HANDLE_GET_FORMAT_PROPERTY(rate);
}/*}}}*/

bool bic_mpg_handle_method_channels_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPG_HANDLE_GET_FORMAT_PROPERTY(channels);
}/*}}}*/

bool bic_mpg_handle_method_encoding_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPG_HANDLE_GET_FORMAT_PROPERTY(encoding);
}/*}}}*/

bool bic_mpg_handle_method_feed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("feed#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mh_ptr->type != c_mpg_handle_type_feed)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_NOT_OPENED_IN_FEED_MODE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (mpg123_feed(mh_ptr->handle,(unsigned char *)string_ptr->data,string_ptr->size - 1) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_FEED_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mpg_handle_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int buffer_size;

  if (!it.retrieve_integer(src_0_location,buffer_size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("read#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mh_ptr->type == c_mpg_handle_type_none)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (buffer_size < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_READ_WRONG_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(buffer_size);

    return false;
  }

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(buffer_size);

#define MPG_HANDLER_READ_CLEAR() \
{/*{{{*/\
  string_ptr->clear();\
  cfree(string_ptr);\
}/*}}}*/

  do {
    size_t done;
    int code = mpg123_read(mh_ptr->handle,(unsigned char *)string_ptr->data,buffer_size,&done);

    switch (code)
    {
      // - all ok -
      case MPG123_OK:
        {
          // - adjust string length -
          string_ptr->size = done + 1;
          string_ptr->data[done] = '\0';

          BIC_SET_RESULT_STRING(string_ptr);

          return true;
        }
        break;

      // - no more data to be decoded -
      case MPG123_DONE:
      case MPG123_NEED_MORE:
        {
          MPG_HANDLER_READ_CLEAR();
          BIC_SET_RESULT_BLANK();

          return true;
        }
        break;

      // - new data format -
      case MPG123_NEW_FORMAT:
        {
          // - ERROR -
          if (mpg123_getformat(mh_ptr->handle,&mh_ptr->rate,&mh_ptr->channels,&mh_ptr->encoding) != MPG123_OK)
          {
            MPG_HANDLER_READ_CLEAR();

            exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_ADJUST_OUTPUT_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          // - ERROR -
          if (mpg123_format_none(mh_ptr->handle) != MPG123_OK)
          {
            MPG_HANDLER_READ_CLEAR();

            exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_ADJUST_OUTPUT_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }

          // - ERROR -
          if (mpg123_format(mh_ptr->handle,mh_ptr->rate,mh_ptr->channels,mh_ptr->encoding) != MPG123_OK)
          {
            MPG_HANDLER_READ_CLEAR();

            exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_ADJUST_OUTPUT_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }
        }
        break;

      // - ERROR -
      default:
        MPG_HANDLER_READ_CLEAR();

        exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
    }
  } while(true);
}/*}}}*/

bool bic_mpg_handle_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpg_handle_s *mh_ptr = (mpg_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (mh_ptr->type == c_mpg_handle_type_none)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (mpg123_close(mh_ptr->handle) != MPG123_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MPG_HANDLE_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  mh_ptr->type = c_mpg_handle_type_none;
  mh_ptr->init_format();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mpg_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MpgHandle"),"MpgHandle");
  );

  return true;
}/*}}}*/

bool bic_mpg_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MpgHandle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

