
@begin
include "curl_module.h"
@end

// - CURL indexes of built in classes -
unsigned c_bi_class_curl = c_idx_not_exist;
unsigned c_bi_class_curl_result = c_idx_not_exist;

// - CURL module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  curl_classes,         // Classes

  0,                    // Error base index
  8,                    // Error count
  curl_error_strings,   // Error strings

  curl_initialize,      // Initialize function
  curl_print_exception, // Print exceptions function
};/*}}}*/

// - CURL classes -
built_in_class_s *curl_classes[] =
{/*{{{*/
  &curl_class,
  &curl_result_class,
};/*}}}*/

// - CURL error strings -
const char *curl_error_strings[] =
{/*{{{*/
  "error_CURL_CANNOT_CREATE_SESSION",
  "error_CURL_ERROR_WHILE_PERFORMING_GET_REQUEST",
  "error_CURL_ERROR_WHILE_PERFORMING_PUT_REQUEST",
  "error_CURL_ERROR_WHILE_PERFORMING_POST_REQUEST",
  "error_CURL_ERROR_WHILE_PERFORMING_DELETE_REQUEST",
  "error_CURL_ERROR_WHILE_PERFORMING_HEAD_REQUEST",
  "error_CURL_RESULT_UNSUPPORTED_INFO_VALUE_TYPE",
  "error_CURL_RESULT_ERROR_WHILE_GET_INFO",
};/*}}}*/

// - CURL initialize -
bool curl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize curl class identifier -
  c_bi_class_curl = class_base_idx++;

  // - initialize curl_result class identifier -
  c_bi_class_curl_result = class_base_idx++;

  return true;
}/*}}}*/

// - CURL print exception -
bool curl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CURL_CANNOT_CREATE_SESSION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create cURL session\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_ERROR_WHILE_PERFORMING_GET_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing HTTP GET request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_ERROR_WHILE_PERFORMING_PUT_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing HTTP PUT request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_ERROR_WHILE_PERFORMING_POST_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing HTTP POST request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_ERROR_WHILE_PERFORMING_DELETE_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing HTTP DELETE request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_ERROR_WHILE_PERFORMING_HEAD_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing HTTP HEAD request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_RESULT_UNSUPPORTED_INFO_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported type of curl result information value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_RESULT_ERROR_WHILE_GET_INFO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading curl result information value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CURL -
built_in_class_s curl_class =
{/*{{{*/
  "Curl",
  c_modifier_public | c_modifier_final,
  7, curl_methods,
  0, curl_variables,
  bic_curl_consts,
  bic_curl_init,
  bic_curl_clear,
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

built_in_method_s curl_methods[] =
{/*{{{*/
  {
    "GET#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_GET_1
  },
  {
    "PUT#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_PUT_2
  },
  {
    "POST#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_POST_2
  },
  {
    "DELETE#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_DELETE_1
  },
  {
    "HEAD#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_HEAD_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_print_0
  },
};/*}}}*/

built_in_variable_s curl_variables[] =
{/*{{{*/
};/*}}}*/

void bic_curl_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_curl_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_curl_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_curl_method_GET_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_curl,"GET#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create curl session -
  CURL *curl_ptr = curl_easy_init();

  // - ERROR -
  if (curl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create write buffer -
  bc_array_s write_buffer;
  write_buffer.init();

  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);

  // - ERROR -
  if (curl_easy_perform(curl_ptr) != CURLE_OK)
  {
    write_buffer.clear();
    curl_easy_cleanup(curl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_GET_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character -
  write_buffer.push('\0');

  // - create result string -
  string_s *res_data_ptr = it.get_new_string_ptr();

  res_data_ptr->size = write_buffer.used;
  res_data_ptr->data = write_buffer.data;

  // - create curl_result object -
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));
  res_ptr->init();

  // - set curl pointer -
  res_ptr->curl_ptr = curl_ptr;

  // - set result data location -
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);
  res_ptr->data_ptr = data_location;

  // - set result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_method_PUT_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_curl,"PUT#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *data_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create curl session -
  CURL *curl_ptr = curl_easy_init();

  // - ERROR -
  if (curl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create read buffer -
  read_buffer_s read_buffer;
  read_buffer.init(*data_ptr);

  // - create write buffer -
  bc_array_s write_buffer;
  write_buffer.init();

  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);
  curl_easy_setopt(curl_ptr,CURLOPT_READFUNCTION,cb_read_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_READDATA,&read_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_UPLOAD,1L);
  curl_easy_setopt(curl_ptr,CURLOPT_INFILESIZE_LARGE,(curl_off_t)(data_ptr->size - 1));

  // - ERROR -
  if (curl_easy_perform(curl_ptr) != CURLE_OK)
  {
    write_buffer.clear();
    curl_easy_cleanup(curl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_PUT_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character -
  write_buffer.push('\0');

  // - create result string -
  string_s *res_data_ptr = it.get_new_string_ptr();

  res_data_ptr->size = write_buffer.used;
  res_data_ptr->data = write_buffer.data;

  // - create curl_result object -
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));
  res_ptr->init();

  // - set curl pointer -
  res_ptr->curl_ptr = curl_ptr;

  // - set result data location -
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);
  res_ptr->data_ptr = data_location;

  // - set result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_method_POST_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_curl,"POST#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *data_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create curl session -
  CURL *curl_ptr = curl_easy_init();

  // - ERROR -
  if (curl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create read buffer -
  read_buffer_s read_buffer;
  read_buffer.init(*data_ptr);

  // - create write buffer -
  bc_array_s write_buffer;
  write_buffer.init();

  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);
  curl_easy_setopt(curl_ptr,CURLOPT_READFUNCTION,cb_read_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_READDATA,&read_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_POST,1L);
  curl_easy_setopt(curl_ptr,CURLOPT_POSTFIELDSIZE_LARGE,(curl_off_t)(data_ptr->size - 1));

  // - ERROR -
  if (curl_easy_perform(curl_ptr) != CURLE_OK)
  {
    write_buffer.clear();
    curl_easy_cleanup(curl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_POST_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character -
  write_buffer.push('\0');

  // - create result string -
  string_s *res_data_ptr = it.get_new_string_ptr();

  res_data_ptr->size = write_buffer.used;
  res_data_ptr->data = write_buffer.data;

  // - create curl_result object -
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));
  res_ptr->init();

  // - set curl pointer -
  res_ptr->curl_ptr = curl_ptr;

  // - set result data location -
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);
  res_ptr->data_ptr = data_location;

  // - set result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_method_DELETE_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_curl,"DELETE#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create curl session -
  CURL *curl_ptr = curl_easy_init();

  // - ERROR -
  if (curl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create write buffer -
  bc_array_s write_buffer;
  write_buffer.init();

  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_CUSTOMREQUEST,"DELETE");

  // - ERROR -
  if (curl_easy_perform(curl_ptr) != CURLE_OK)
  {
    write_buffer.clear();
    curl_easy_cleanup(curl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_DELETE_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character -
  write_buffer.push('\0');

  // - create result string -
  string_s *res_data_ptr = it.get_new_string_ptr();

  res_data_ptr->size = write_buffer.used;
  res_data_ptr->data = write_buffer.data;

  // - create curl_result object -
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));
  res_ptr->init();

  // - set curl pointer -
  res_ptr->curl_ptr = curl_ptr;

  // - set result data location -
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);
  res_ptr->data_ptr = data_location;

  // - set result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_method_HEAD_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_curl,"HEAD#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create curl session -
  CURL *curl_ptr = curl_easy_init();

  // - ERROR -
  if (curl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create write buffer -
  bc_array_s write_buffer;
  write_buffer.init();

  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);
  curl_easy_setopt(curl_ptr,CURLOPT_HEADER,1);
  curl_easy_setopt(curl_ptr,CURLOPT_NOBODY,1);

  // - ERROR -
  if (curl_easy_perform(curl_ptr) != CURLE_OK)
  {
    write_buffer.clear();
    curl_easy_cleanup(curl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_HEAD_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character -
  write_buffer.push('\0');

  // - create result string -
  string_s *res_data_ptr = it.get_new_string_ptr();

  res_data_ptr->size = write_buffer.used;
  res_data_ptr->data = write_buffer.data;

  // - create curl_result object -
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));
  res_ptr->init();

  // - set curl pointer -
  res_ptr->curl_ptr = curl_ptr;

  // - set result data location -
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);
  res_ptr->data_ptr = data_location;

  // - set result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Curl"),"Curl");
  );

  return true;
}/*}}}*/

bool bic_curl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Curl");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CURL_RESULT -
built_in_class_s curl_result_class =
{/*{{{*/
  "CurlResult",
  c_modifier_public | c_modifier_final,
  5, curl_result_methods,
  43, curl_result_variables,
  bic_curl_result_consts,
  bic_curl_result_init,
  bic_curl_result_clear,
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

built_in_method_s curl_result_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_curl_result_operator_binary_equal
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_curl_result_method_data_0
  },
  {
    "info#1",
    c_modifier_public | c_modifier_final,
    bic_curl_result_method_info_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_result_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_result_method_print_0
  },
};/*}}}*/

built_in_variable_s curl_result_variables[] =
{/*{{{*/
  { "INFO_EFFECTIVE_URL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_RESPONSE_CODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_TOTAL_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_NAMELOOKUP_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_CONNECT_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_PRETRANSFER_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_SIZE_UPLOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_SIZE_DOWNLOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_SPEED_DOWNLOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_SPEED_UPLOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_HEADER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_REQUEST_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_SSL_VERIFYRESULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_FILETIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_CONTENT_LENGTH_DOWNLOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_CONTENT_LENGTH_UPLOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_STARTTRANSFER_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_CONTENT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_REDIRECT_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_REDIRECT_COUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_PRIVATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_HTTP_CONNECTCODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_HTTPAUTH_AVAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_PROXYAUTH_AVAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_OS_ERRNO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_NUM_CONNECTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_SSL_ENGINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_COOKIELIST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_LASTSOCKET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_FTP_ENTRY_PATH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_REDIRECT_URL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_PRIMARY_IP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_APPCONNECT_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_CERTINFO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_CONDITION_UNMET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_RTSP_SESSION_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_RTSP_CLIENT_CSEQ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_RTSP_SERVER_CSEQ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_RTSP_CSEQ_RECV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_PRIMARY_PORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_LOCAL_IP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_LOCAL_PORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INFO_TLS_SESSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_curl_result_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(43);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 43);

#define CREATE_CURL_RESULT_INFO_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_EFFECTIVE_URL);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_RESPONSE_CODE);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_TOTAL_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_NAMELOOKUP_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONNECT_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_PRETRANSFER_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SIZE_UPLOAD);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SIZE_DOWNLOAD);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SPEED_DOWNLOAD);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SPEED_UPLOAD);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_HEADER_SIZE);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_REQUEST_SIZE);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SSL_VERIFYRESULT);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_FILETIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_LENGTH_DOWNLOAD);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_LENGTH_UPLOAD);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_STARTTRANSFER_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_TYPE);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_REDIRECT_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_REDIRECT_COUNT);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_PRIVATE);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_HTTP_CONNECTCODE);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_HTTPAUTH_AVAIL);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_PROXYAUTH_AVAIL);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_OS_ERRNO);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_NUM_CONNECTS);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SSL_ENGINES);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_COOKIELIST);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_LASTSOCKET);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_FTP_ENTRY_PATH);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_REDIRECT_URL);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_PRIMARY_IP);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_APPCONNECT_TIME);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CERTINFO);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONDITION_UNMET);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_RTSP_SESSION_ID);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_RTSP_CLIENT_CSEQ);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_RTSP_SERVER_CSEQ);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_RTSP_CSEQ_RECV);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_PRIMARY_PORT);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_LOCAL_IP);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_LOCAL_PORT);
  CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_TLS_SESSION);
}/*}}}*/

void bic_curl_result_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (curl_result_s *)nullptr;
}/*}}}*/

void bic_curl_result_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  curl_result_s *res_ptr = (curl_result_s *)location_ptr->v_data_ptr;

  if (res_ptr != nullptr)
  {
    res_ptr->clear(it);
    cfree(res_ptr);
  }
}/*}}}*/

bool bic_curl_result_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_curl_result_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_result_s *res_ptr = (curl_result_s *)dst_location->v_data_ptr;

  // - set data as result -
  res_ptr->data_ptr->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(res_ptr->data_ptr);

  return true;
}/*}}}*/

bool bic_curl_result_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int info_type;

  if (!it.retrieve_integer(src_0_location,info_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("info#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  curl_result_s *res_ptr = (curl_result_s *)dst_location->v_data_ptr;

  // - process info type -
  switch (info_type & CURLINFO_TYPEMASK)
  {
  case CURLINFO_STRING:
    {/*{{{*/
      char *data;
      if (curl_easy_getinfo(res_ptr->curl_ptr,(CURLINFO)info_type,&data) == CURLE_OK)
      {
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(strlen(data),data);

        BIC_SET_RESULT_STRING(string_ptr);
        return true;
      }
    }/*}}}*/
    break;

  case CURLINFO_LONG:
    {/*{{{*/
      long data;
      if (curl_easy_getinfo(res_ptr->curl_ptr,(CURLINFO)info_type,&data) == CURLE_OK)
      {
        long long int result = data;

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
        return true;
      }
    }/*}}}*/
    break;

  case CURLINFO_DOUBLE:
    {/*{{{*/
      double data;
      if (curl_easy_getinfo(res_ptr->curl_ptr,(CURLINFO)info_type,&data) == CURLE_OK)
      {
        BIC_SIMPLE_SET_RES(c_bi_class_float,data);
        return true;
      }
    }/*}}}*/
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_CURL_RESULT_UNSUPPORTED_INFO_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  exception_s::throw_exception(it,module.error_base + c_error_CURL_RESULT_ERROR_WHILE_GET_INFO,operands[c_source_pos_idx],(location_s *)it.blank_location);
  return false;
}/*}}}*/

bool bic_curl_result_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CurlResult"),"CurlResult");
  );

  return true;
}/*}}}*/

bool bic_curl_result_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CurlResult");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

