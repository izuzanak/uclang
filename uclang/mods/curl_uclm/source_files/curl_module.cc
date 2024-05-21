
@begin
include "curl_module.h"
@end

// - CURL indexes of built in classes -
unsigned c_bi_class_curl = c_idx_not_exist;
unsigned c_bi_class_curl_multi = c_idx_not_exist;
unsigned c_bi_class_curl_multi_request = c_idx_not_exist;
unsigned c_bi_class_curl_result = c_idx_not_exist;

// - CURL module -
EXPORT built_in_module_s module =
{/*{{{*/
  4,                    // Class count
  curl_classes,         // Classes

  0,                    // Error base index
  18,                   // Error count
  curl_error_strings,   // Error strings

  curl_initialize,      // Initialize function
  curl_print_exception, // Print exceptions function
};/*}}}*/

// - CURL classes -
built_in_class_s *curl_classes[] =
{/*{{{*/
  &curl_class,
  &curl_multi_class,
  &curl_multi_request_class,
  &curl_result_class,
};/*}}}*/

// - CURL error strings -
const char *curl_error_strings[] =
{/*{{{*/
  "error_CURL_CANNOT_CREATE_SESSION",
  "error_CURL_URL_ESCAPE_ERROR",
  "error_CURL_URL_UNESCAPE_ERROR",
  "error_CURL_ERROR_WHILE_PERFORMING_HTTP_REQUEST",
  "error_CURL_HTTP_HEADER_EXPECTED_STRING",
  "error_CURL_MULTI_WRONG_CALLBACK_DELEGATE",
  "error_CURL_MULTI_CANNOT_CREATE_SESSION",
  "error_CURL_MULTI_CANNOT_ADD_HANDLER",
  "error_CURL_MULTI_SOCKET_ACTION_ERROR",
  "error_CURL_MULTI_INVALID_REQUEST_INDEX",
  "error_CURL_MULTI_POLL_ERROR",
  "error_CURL_MULTI_REQUEST_INVALID_REFERENCE",
  "error_CURL_MULTI_REQUEST_UNSUPPORTED_OPTION_TYPE",
  "error_CURL_MULTI_REQUEST_WRONG_OPTION_VALUE_TYPE",
  "error_CURL_MULTI_REQUEST_WRONG_OPTION_ARRAY_SIZE",
  "error_CURL_MULTI_REQUEST_WRONG_OPTION_ARRAY_VALUE_TYPE",
  "error_CURL_RESULT_UNSUPPORTED_INFO_VALUE_TYPE",
  "error_CURL_RESULT_ERROR_WHILE_GET_INFO",
};/*}}}*/

// - CURL initialize -
bool curl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize curl class identifier -
  c_bi_class_curl = class_base_idx++;

  // - initialize curl_multi class identifier -
  c_bi_class_curl_multi = class_base_idx++;

  // - initialize curl_multi_request class identifier -
  c_bi_class_curl_multi_request = class_base_idx++;

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
    fprintf(stderr,"\nCannot create curl session\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_URL_ESCAPE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCurl, URL escape error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_URL_UNESCAPE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCurl, URL unescape error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_ERROR_WHILE_PERFORMING_HTTP_REQUEST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing HTTP request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_HTTP_HEADER_EXPECTED_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected string as curl HTTP header\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for curl multi handler\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_CANNOT_CREATE_SESSION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create curl multi session\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_CANNOT_ADD_HANDLER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot add curl easy handler to multi handler\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_SOCKET_ACTION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while performing curl multi handler socket action\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_INVALID_REQUEST_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid curl multi request index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_POLL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while polling curl multi handler file descriptors\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_REQUEST_INVALID_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid curl multi request reference\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_REQUEST_UNSUPPORTED_OPTION_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported type of curl request option\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_REQUEST_WRONG_OPTION_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of curl option value, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_REQUEST_WRONG_OPTION_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid size of curl option value array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CURL_MULTI_REQUEST_WRONG_OPTION_ARRAY_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of value of curl option value array, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
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
  9, curl_methods,
  13 + 10 + 3, curl_variables,
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
    "url_escape#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_url_escape_1
  },
  {
    "url_unescape#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_method_url_unescape_1
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

  // - curl option constants -
  { "OPT_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_TIMEOUT_MS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_HTTPAUTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_USERNAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_PASSWORD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_DIRLISTONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_FTP_CREATE_MISSING_DIRS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_FTPPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_SSL_VERIFYPEER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_SSL_VERIFYHOST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_QUOTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_PREQUOTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPT_POSTQUOTE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - curl authentication constants -
  { "AUTH_ANY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_ANYSAFE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_BASIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_DIGEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_GSSNEGOTIATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_NTLM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_DIGEST_IE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_NTLM_WB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AUTH_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - curl ftp create dir constants -
  { "FTP_CREATE_DIR_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FTP_CREATE_DIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FTP_CREATE_DIR_RETRY", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_CURL_GET_DELETE_HEAD_METHODS(NAME,OPTIONS) \
{/*{{{*/\
@begin ucl_params
<
address:c_bi_class_string
>
class c_bi_class_curl
method NAME
static_method
macro
; @end\
\
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - create curl session - */\
  CURL *curl_ptr = curl_easy_init();\
\
  /* - ERROR - */\
  if (curl_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - create write buffer - */\
  bc_array_s write_buffer;\
  write_buffer.init();\
\
  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);\
  OPTIONS;\
  curl_easy_setopt(curl_ptr,CURLOPT_PRIVATE,nullptr);\
\
  /* - ERROR - */\
  if (curl_easy_perform(curl_ptr) != CURLE_OK)\
  {\
    write_buffer.clear();\
    curl_easy_cleanup(curl_ptr);\
\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_HTTP_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - push terminating character - */\
  write_buffer.push('\0');\
\
  /* - create result string - */\
  string_s *res_data_ptr = it.get_new_string_ptr();\
\
  res_data_ptr->size = write_buffer.used;\
  res_data_ptr->data = write_buffer.data;\
\
  /* - create curl_result object - */\
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));\
  res_ptr->init();\
\
  /* - set curl pointer - */\
  res_ptr->curl_ptr = curl_ptr;\
\
  /* - set result data location - */\
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);\
  res_ptr->data_loc = data_location;\
\
  /* - set result location - */\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

#define BIC_CURL_PUT_POST_METHODS(NAME,OPTIONS) \
{/*{{{*/\
@begin ucl_params
<
address:c_bi_class_string
data:retrieve_data_buffer
>
class c_bi_class_curl
method NAME
static_method
macro
; @end\
\
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - create curl session - */\
  CURL *curl_ptr = curl_easy_init();\
\
  /* - ERROR - */\
  if (curl_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - create read buffer - */\
  read_buffer_s read_buffer;\
  read_buffer.init(data_ptr,data_size);\
\
  /* - create write buffer - */\
  bc_array_s write_buffer;\
  write_buffer.init();\
\
  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);\
  curl_easy_setopt(curl_ptr,CURLOPT_READFUNCTION,cb_read_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_READDATA,&read_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&write_buffer);\
  OPTIONS;\
  curl_easy_setopt(curl_ptr,CURLOPT_PRIVATE,nullptr);\
\
  /* - ERROR - */\
  if (curl_easy_perform(curl_ptr) != CURLE_OK)\
  {\
    write_buffer.clear();\
    curl_easy_cleanup(curl_ptr);\
\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_ERROR_WHILE_PERFORMING_HTTP_REQUEST,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - push terminating character - */\
  write_buffer.push('\0');\
\
  /* - create result string - */\
  string_s *res_data_ptr = it.get_new_string_ptr();\
\
  res_data_ptr->size = write_buffer.used;\
  res_data_ptr->data = write_buffer.data;\
\
  /* - create curl_result object - */\
  curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));\
  res_ptr->init();\
\
  /* - set curl pointer - */\
  res_ptr->curl_ptr = curl_ptr;\
\
  /* - set result data location - */\
  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);\
  res_ptr->data_loc = data_location;\
\
  /* - set result location - */\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_result,res_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_curl_consts(location_array_s &const_locations)
{/*{{{*/

  // - curl option constants -
  {
    const_locations.push_blanks(13);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 13);

#define CREATE_CURL_OPTION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_TIMEOUT);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_TIMEOUT_MS);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_HTTPAUTH);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_USERNAME);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_PASSWORD);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_DIRLISTONLY);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_FTP_CREATE_MISSING_DIRS);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_FTPPORT);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_SSL_VERIFYPEER);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_SSL_VERIFYHOST);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_QUOTE);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_PREQUOTE);
    CREATE_CURL_OPTION_BIC_STATIC(CURLOPT_POSTQUOTE);
  }

  // - curl authentication constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_CURL_AUTHENTICATION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_ANY);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_ANYSAFE);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_BASIC);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_DIGEST);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_GSSNEGOTIATE);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_NTLM);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_DIGEST_IE);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_NTLM_WB);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_ONLY);
    CREATE_CURL_AUTHENTICATION_BIC_STATIC(CURLAUTH_NONE);
  }

  // - curl ftp create dir constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_CURL_FTP_CREATE_DIR_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CURL_FTP_CREATE_DIR_BIC_STATIC(CURLFTP_CREATE_DIR_NONE);
    CREATE_CURL_FTP_CREATE_DIR_BIC_STATIC(CURLFTP_CREATE_DIR);
    CREATE_CURL_FTP_CREATE_DIR_BIC_STATIC(CURLFTP_CREATE_DIR_RETRY);
  }
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
  BIC_CURL_GET_DELETE_HEAD_METHODS("GET#1",);
}/*}}}*/

bool bic_curl_method_PUT_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_PUT_POST_METHODS("PUT#2",
    curl_easy_setopt(curl_ptr,CURLOPT_UPLOAD,1L);
    curl_easy_setopt(curl_ptr,CURLOPT_INFILESIZE_LARGE,(curl_off_t)data_size);
  );
}/*}}}*/

bool bic_curl_method_POST_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_PUT_POST_METHODS("POST#2",
    curl_easy_setopt(curl_ptr,CURLOPT_POST,1L);
    curl_easy_setopt(curl_ptr,CURLOPT_POSTFIELDSIZE_LARGE,(curl_off_t)data_size);
  );
}/*}}}*/

bool bic_curl_method_DELETE_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_GET_DELETE_HEAD_METHODS("DELETE#1",
    curl_easy_setopt(curl_ptr,CURLOPT_CUSTOMREQUEST,"DELETE");
  );
}/*}}}*/

bool bic_curl_method_HEAD_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_GET_DELETE_HEAD_METHODS("HEAD#1",
    curl_easy_setopt(curl_ptr,CURLOPT_HEADER,1);
    curl_easy_setopt(curl_ptr,CURLOPT_NOBODY,1);
  );
}/*}}}*/

bool bic_curl_method_url_escape_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
input:retrieve_data_buffer
>
class c_bi_class_curl
method url_escape
static_method
; @end

  char *output = nullptr;

  CURL *curl = curl_easy_init();
  if (curl != nullptr)
  {
    output = curl_easy_escape(curl,(const char *)input_ptr,input_size);
    curl_easy_cleanup(curl);
  }

  // - ERROR -
  if (output == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_URL_ESCAPE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(output),output);
  curl_free(output);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_curl_method_url_unescape_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
input:retrieve_data_buffer
>
class c_bi_class_curl
method url_unescape
static_method
; @end

  int output_len = 0;
  char *output = nullptr;

  CURL *curl = curl_easy_init();
  if (curl != nullptr)
  {
    output = curl_easy_unescape(curl,(const char *)input_ptr,input_size,&output_len);
    curl_easy_cleanup(curl);
  }

  // - ERROR -
  if (output == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_URL_UNESCAPE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(output_len,output);
  curl_free(output);

  BIC_SET_RESULT_STRING(string_ptr);

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

// - class CURL_MULTI -
built_in_class_s curl_multi_class =
{/*{{{*/
  "CurlMulti",
  c_modifier_public | c_modifier_final,
  13, curl_multi_methods,
  0, curl_multi_variables,
  bic_curl_multi_consts,
  bic_curl_multi_init,
  bic_curl_multi_clear,
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

built_in_method_s curl_multi_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_operator_binary_le_br_re_br
  },
  {
    "CurlMulti#1",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_CurlMulti_1
  },
  {
    "GET#2",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_GET_2
  },
  {
    "PUT#3",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_PUT_3
  },
  {
    "POST#3",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_POST_3
  },
  {
    "DELETE#2",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_DELETE_2
  },
  {
    "HEAD#2",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_HEAD_2
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_get_fds_0
  },
  {
    "timeout#0",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_timeout_0
  },
  {
    "process#0",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_method_process_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_multi_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_multi_method_print_0
  },
};/*}}}*/

built_in_variable_s curl_multi_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_CURL_MULTI_GET_DELETE_HEAD_METHODS(NAME,OPTIONS) \
{/*{{{*/\
@begin ucl_params
<
address:c_bi_class_string
user_data:ignore
>
method NAME
macro
; @end\
\
  curl_multi_s *cm_ptr = (curl_multi_s *)dst_location->v_data_ptr;\
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - create curl session - */\
  CURL *curl_ptr = curl_easy_init();\
\
  /* - ERROR - */\
  if (curl_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (curl_multi_add_handle(cm_ptr->curlm_ptr,curl_ptr) != CURLM_OK)\
  {\
    curl_easy_cleanup(curl_ptr);\
\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_CANNOT_ADD_HANDLER,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  curl_props_s *curl_props = (curl_props_s *)cmalloc(sizeof(curl_props_s));\
  curl_props->init();\
\
  curl_props->curl_ptr = curl_ptr;\
\
  /* - append curl to list - */\
  long long int index = cm_ptr->curl_list.append(curl_ptr);\
  curl_props->index = index;\
  curl_props->unique_id = cm_ptr->unique_counter++;\
\
  /* - set user data location - */\
  src_1_location->v_reference_cnt.atomic_inc();\
  curl_props->user_loc = src_1_location;\
\
  /* - setup curl easy - */\
  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&curl_props->write_buffer);\
  OPTIONS;\
  curl_easy_setopt(curl_ptr,CURLOPT_PRIVATE,curl_props);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,index);\
\
  return true;\
}/*}}}*/

#define BIC_CURL_MULTI_PUT_POST_METHODS(NAME,OPTIONS) \
{/*{{{*/\
@begin ucl_params
<
address:c_bi_class_string
data:retrieve_data_buffer
user_data:ignore
>
method NAME
macro
; @end\
\
  curl_multi_s *cm_ptr = (curl_multi_s *)dst_location->v_data_ptr;\
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - create curl session - */\
  CURL *curl_ptr = curl_easy_init();\
\
  /* - ERROR - */\
  if (curl_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (curl_multi_add_handle(cm_ptr->curlm_ptr,curl_ptr) != CURLM_OK)\
  {\
    curl_easy_cleanup(curl_ptr);\
\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_CANNOT_ADD_HANDLER,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  curl_props_s *curl_props = (curl_props_s *)cmalloc(sizeof(curl_props_s));\
  curl_props->init();\
\
  curl_props->curl_ptr = curl_ptr;\
\
  /* - append curl to list - */\
  long long int index = cm_ptr->curl_list.append(curl_ptr);\
  curl_props->index = index;\
  curl_props->unique_id = cm_ptr->unique_counter++;\
\
  curl_props->read_buffer.init(data_ptr,data_size);\
\
  /* - set read data location - */\
  src_1_location->v_reference_cnt.atomic_inc();\
  curl_props->read_loc = src_1_location;\
\
  /* - set user data location - */\
  src_2_location->v_reference_cnt.atomic_inc();\
  curl_props->user_loc = src_2_location;\
\
  /* - setup curl easy - */\
  curl_easy_setopt(curl_ptr,CURLOPT_URL,address_ptr->data);\
  curl_easy_setopt(curl_ptr,CURLOPT_READFUNCTION,cb_read_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_READDATA,&curl_props->read_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEFUNCTION,cb_write_buffer);\
  curl_easy_setopt(curl_ptr,CURLOPT_WRITEDATA,&curl_props->write_buffer);\
  OPTIONS;\
  curl_easy_setopt(curl_ptr,CURLOPT_PRIVATE,curl_props);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,index);\
\
  return true;\
}/*}}}*/

void bic_curl_multi_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_curl_multi_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (curl_multi_s *)nullptr;
}/*}}}*/

void bic_curl_multi_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  curl_multi_s *cm_ptr = (curl_multi_s *)location_ptr->v_data_ptr;

  if (cm_ptr != nullptr)
  {
    cm_ptr->clear(it);
    cfree(cm_ptr);
  }
}/*}}}*/

bool bic_curl_multi_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_curl_multi_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method operator_binary_le_br_re_br
; @end

  curl_multi_s *cm_ptr = (curl_multi_s *)dst_location->v_data_ptr;
  pointer_list_s &curl_list = cm_ptr->curl_list;

  // - ERROR -
  if (index < 0 || index >= curl_list.used || !curl_list.data[index].valid)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_INVALID_REQUEST_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  CURL *curl_ptr = (CURL *)curl_list[index];

  // - retrieve curl properties -
  curl_props_s *curl_props;
  curl_easy_getinfo(curl_ptr,CURLINFO_PRIVATE,(char **)&curl_props);

  // - create curl_multi_request object -
  curl_multi_request_s *cmr_ptr = (curl_multi_request_s *)cmalloc(sizeof(curl_multi_request_s));
  cmr_ptr->init();

  // - set curl_multi reference -
  dst_location->v_reference_cnt.atomic_inc();
  cmr_ptr->curl_multi_loc = dst_location;

  cmr_ptr->index = index;
  cmr_ptr->unique_id = curl_props->unique_id;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_curl_multi_request,cmr_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_multi_method_CurlMulti_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
delegate:c_bi_class_delegate
>
method CurlMulti
; @end

  // - ERROR -
  if (((delegate_s *)src_0_location->v_data_ptr)->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  CURLM *curlm_ptr = curl_multi_init();

  // - ERROR -
  if (curlm_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_CANNOT_CREATE_SESSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create curl_multi object -
  curl_multi_s *cm_ptr = (curl_multi_s *)cmalloc(sizeof(curl_multi_s));
  cm_ptr->init();

  cm_ptr->curlm_ptr = curlm_ptr;

  // - register callback delegate -
  src_0_location->v_reference_cnt.atomic_inc();
  cm_ptr->callback_dlg = src_0_location;

  curl_multi_setopt(curlm_ptr,CURLMOPT_SOCKETFUNCTION,curl_multi_s::socket_callback);
  curl_multi_setopt(curlm_ptr,CURLMOPT_SOCKETDATA,cm_ptr);

  // - set curl_multi destination location -
  dst_location->v_data_ptr = (curl_multi_s *)cm_ptr;

  return true;
}/*}}}*/

bool bic_curl_multi_method_GET_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_MULTI_GET_DELETE_HEAD_METHODS("GET#2",);
}/*}}}*/

bool bic_curl_multi_method_PUT_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_MULTI_PUT_POST_METHODS("PUT#3",
    curl_easy_setopt(curl_ptr,CURLOPT_UPLOAD,1L);
    curl_easy_setopt(curl_ptr,CURLOPT_INFILESIZE_LARGE,(curl_off_t)data_size);
  );
}/*}}}*/

bool bic_curl_multi_method_POST_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_MULTI_PUT_POST_METHODS("POST#3",
    curl_easy_setopt(curl_ptr,CURLOPT_POST,1L);
    curl_easy_setopt(curl_ptr,CURLOPT_POSTFIELDSIZE_LARGE,(curl_off_t)data_size);
  );
}/*}}}*/

bool bic_curl_multi_method_DELETE_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_MULTI_GET_DELETE_HEAD_METHODS("DELETE#2",
    curl_easy_setopt(curl_ptr,CURLOPT_CUSTOMREQUEST,"DELETE");
  );
}/*}}}*/

bool bic_curl_multi_method_HEAD_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CURL_MULTI_GET_DELETE_HEAD_METHODS("HEAD#2",
    curl_easy_setopt(curl_ptr,CURLOPT_HEADER,1);
    curl_easy_setopt(curl_ptr,CURLOPT_NOBODY,1);
  );
}/*}}}*/

bool bic_curl_multi_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_multi_s *cm_ptr = (curl_multi_s *)dst_location->v_data_ptr;
  fd_flags_rb_tree_s &poll_fds = cm_ptr->poll_fds;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (poll_fds.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(poll_fds)];
    unsigned *stack_ptr = stack;

    unsigned ff_idx = poll_fds.get_stack_min_value_idx(poll_fds.root_idx,&stack_ptr);
    do {
      fd_flags_s &fd_flags = poll_fds[ff_idx];

      {
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,fd_flags.fd);
        array_ptr->push(new_location);
      }

      {
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,fd_flags.flags);
        array_ptr->push(new_location);
      }

      ff_idx = poll_fds.get_stack_next_idx(ff_idx,&stack_ptr,stack);
    } while(ff_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_curl_multi_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_multi_s *cm_ptr = (curl_multi_s *)dst_location->v_data_ptr;

  // - retrieve curl timeout -
  long timeout;
  curl_multi_timeout(cm_ptr->curlm_ptr,&timeout);

  long long result = timeout != -1 ? timeout : LLONG_MAX;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_curl_multi_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_multi_s *cm_ptr = (curl_multi_s *)dst_location->v_data_ptr;

  // - retrieve curl timeout -
  long timeout;
  curl_multi_timeout(cm_ptr->curlm_ptr,&timeout);

  if (timeout == 0)
  {
    // - ERROR -
    int running;
    if (curl_multi_socket_action(cm_ptr->curlm_ptr,CURL_SOCKET_TIMEOUT,0,&running) != CURLM_OK)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_SOCKET_ACTION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - process poll file descriptors -
  fd_flags_rb_tree_s &poll_fds = cm_ptr->poll_fds;
  if (poll_fds.root_idx != c_idx_not_exist)
  {
    // - prepare pollfd structures -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
    ULONG nfds = poll_fds.count;
#else
    nfds_t nfds = poll_fds.count;
#endif

#ifdef _MSC_VER
    pollfd *fds = (pollfd *)cmalloc(nfds*sizeof(pollfd));
#else
    pollfd fds[nfds];
#endif

    unsigned stack[RB_TREE_STACK_SIZE(poll_fds)];
    unsigned *stack_ptr = stack;

    unsigned ff_idx = poll_fds.get_stack_min_value_idx(poll_fds.root_idx,&stack_ptr);
    pollfd *fd_ptr = fds;
    do {
      fd_flags_s &fd_flags = poll_fds[ff_idx];

      fd_ptr->fd = fd_flags.fd;
      fd_ptr->events = fd_flags.flags;
      fd_ptr->revents = 0;

      ff_idx = poll_fds.get_stack_next_idx(ff_idx,&stack_ptr,stack);
    } while(++fd_ptr,ff_idx != c_idx_not_exist);

    // - call poll function -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
    int res = WSAPoll(fds,nfds,0);
#else
    int res = poll(fds,nfds,0);
#endif

    // - ERROR -
#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
    if (res == SOCKET_ERROR)
#else
    if (res == -1)
#endif
    {
#ifdef _MSC_VER
      cfree(fds);
#endif

      exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_POLL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    if (res > 0)
    {
      pollfd *fd_ptr = fds;
      pollfd *fd_ptr_end = fd_ptr + nfds;
      do {
        if (fd_ptr->revents != 0)
        {
          int events = 0;

          if (fd_ptr->revents & (POLLIN | POLLPRI)) {
            events |= CURL_CSELECT_IN;
          }
          if (fd_ptr->revents & POLLOUT) {
            events |= CURL_CSELECT_OUT;
          }
          if (fd_ptr->revents & (POLLERR | POLLHUP | POLLNVAL)) {
            events |= CURL_CSELECT_ERR;
          }

          // - ERROR -
          int running;
          if (curl_multi_socket_action(cm_ptr->curlm_ptr,fd_ptr->fd,events,&running) != CURLM_OK)
          {
#ifdef _MSC_VER
            cfree(fds);
#endif
            exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_SOCKET_ACTION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }
        }
      } while(++fd_ptr < fd_ptr_end);
    }

#ifdef _MSC_VER
    cfree(fds);
#endif
  }

  int msg_cnt;
  CURLMsg *msg = curl_multi_info_read(cm_ptr->curlm_ptr,&msg_cnt);

  // - if there are any messages in completed transfers queue -
  if (msg != nullptr)
  {
    do {
      CURL *curl_ptr = msg->easy_handle;

      // - retrieve curl properties -
      curl_props_s *curl_props;
      curl_easy_getinfo(curl_ptr,CURLINFO_PRIVATE,(char **)&curl_props);

      // - reset private data -
      curl_easy_setopt(curl_ptr,CURLOPT_PRIVATE,nullptr);

      // - retrieve write buffer -
      bc_array_s write_buffer;
      write_buffer.init();
      write_buffer.swap(curl_props->write_buffer);

      // - push terminating character -
      write_buffer.push('\0');

      // - create result string -
      string_s *res_data_ptr = it.get_new_string_ptr();

      res_data_ptr->size = write_buffer.used;
      res_data_ptr->data = write_buffer.data;

      // - remove curl from list -
      cm_ptr->curl_list.remove(curl_props->index);

      // - create curl_result object -
      curl_result_s *res_ptr = (curl_result_s *)cmalloc(sizeof(curl_result_s));
      res_ptr->init();

      // - set result code -
      res_ptr->code = msg->data.result;

      // - set result curl pointer -
      res_ptr->curl_ptr = curl_ptr;
      curl_props->curl_ptr = nullptr;

      // - set result data location -
      BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,res_data_ptr);
      res_ptr->data_loc = data_location;

      // - set user data location -
      res_ptr->user_loc = curl_props->user_loc;
      curl_props->user_loc = nullptr;

      // - release curl properties -
      curl_props->clear(it);
      cfree(curl_props);

      {
        delegate_s *delegate_ptr = (delegate_s *)cm_ptr->callback_dlg->v_data_ptr;

        // - create result location -
        BIC_CREATE_NEW_LOCATION_REFS(res_location,c_bi_class_curl_result,res_ptr,0);

        const unsigned param_cnt = 1;
        pointer *param_data = (pointer *)&res_location;

        // - call delegate method -
        location_s *trg_location = nullptr;
        BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,operands[c_source_pos_idx],
          return false;
        );
        it.release_location_ptr(trg_location);
      }

      msg = curl_multi_info_read(cm_ptr->curlm_ptr,&msg_cnt);
    } while(msg != nullptr);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_curl_multi_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CurlMulti"),"CurlMulti");
  );

  return true;
}/*}}}*/

bool bic_curl_multi_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CurlMulti");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CURL_MULTI_REQUEST -
built_in_class_s curl_multi_request_class =
{/*{{{*/
  "CurlMultiRequest",
  c_modifier_public | c_modifier_final,
  6, curl_multi_request_methods,
  0, curl_multi_request_variables,
  bic_curl_multi_request_consts,
  bic_curl_multi_request_init,
  bic_curl_multi_request_clear,
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

built_in_method_s curl_multi_request_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_request_operator_binary_equal
  },
  {
    "add_headers#1",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_request_method_add_headers_1
  },
  {
    "setopt#2",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_request_method_setopt_2
  },
  {
    "cancel#0",
    c_modifier_public | c_modifier_final,
    bic_curl_multi_request_method_cancel_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_multi_request_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_curl_multi_request_method_print_0
  },
};/*}}}*/

built_in_variable_s curl_multi_request_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_CURL_MULTI_REQUEST_CHECK_REFERENCE() \
/*{{{*/\
  curl_multi_request_s *cmr_ptr = (curl_multi_request_s *)dst_location->v_data_ptr;\
  curl_multi_s *cm_ptr = (curl_multi_s *)cmr_ptr->curl_multi_loc->v_data_ptr;\
  pointer_list_s &curl_list = cm_ptr->curl_list;\
\
  /* - ERROR - */\
  if (cmr_ptr->index < 0 || cmr_ptr->index >= curl_list.used || !curl_list.data[cmr_ptr->index].valid)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  CURL *curl_ptr = (CURL *)curl_list[cmr_ptr->index];\
\
  /* - retrieve curl properties - */\
  curl_props_s *curl_props;\
  curl_easy_getinfo(curl_ptr,CURLINFO_PRIVATE,(char **)&curl_props);\
\
  /* - ERROR - */\
  if (curl_props->unique_id != cmr_ptr->unique_id)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

void bic_curl_multi_request_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_curl_multi_request_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (curl_multi_request_s *)nullptr;
}/*}}}*/

void bic_curl_multi_request_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  curl_multi_request_s *cmr_ptr = (curl_multi_request_s *)location_ptr->v_data_ptr;

  if (cmr_ptr != nullptr)
  {
    cmr_ptr->clear(it);
    cfree(cmr_ptr);
  }
}/*}}}*/

bool bic_curl_multi_request_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_curl_multi_request_method_add_headers_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
headers:c_bi_class_array
>
method add_headers
; @end

  BIC_CURL_MULTI_REQUEST_CHECK_REFERENCE();

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  curl_slist *header_slist = nullptr;

  if (array_ptr->used != 0)
  {
    pointer *s_ptr = array_ptr->data;
    pointer *s_ptr_end = s_ptr + array_ptr->used;

    do {
      location_s *item_location = it.get_location_value(*s_ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_string)
      {
        curl_slist_free_all(header_slist);

        exception_s::throw_exception(it,module.error_base + c_error_CURL_HTTP_HEADER_EXPECTED_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - append header to list -
      string_s *string_ptr = (string_s *)item_location->v_data_ptr;
      header_slist = curl_slist_append(header_slist,string_ptr->data);

    } while(++s_ptr < s_ptr_end);
  }

  curl_easy_setopt(curl_ptr,CURLOPT_HTTPHEADER,header_slist);

  // - release old header list -
  if (curl_props->header_slist != nullptr)
  {
    curl_slist_free_all(curl_props->header_slist);
  }

  // - store header list -
  curl_props->header_slist = header_slist;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_curl_multi_request_method_setopt_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
curlopt:retrieve_integer
value:ignore
>
method setopt
; @end

  BIC_CURL_MULTI_REQUEST_CHECK_REFERENCE();

  switch (curlopt)
  {
  case CURLOPT_TIMEOUT:
  case CURLOPT_TIMEOUT_MS:
  case CURLOPT_HTTPAUTH:
  case CURLOPT_DIRLISTONLY:
  case CURLOPT_FTP_CREATE_MISSING_DIRS:
  case CURLOPT_SSL_VERIFYPEER:
  case CURLOPT_SSL_VERIFYHOST:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_1_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_WRONG_OPTION_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(c_bi_class_integer);

        return false;
      }

      curl_easy_setopt(curl_ptr,(CURLoption)curlopt,(long)value);
    }/*}}}*/
    break;
  case CURLOPT_USERNAME:
  case CURLOPT_PASSWORD:
  case CURLOPT_FTPPORT:
    {/*{{{*/

      // - ERROR -
      if (src_1_location->v_type != c_bi_class_string)
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_WRONG_OPTION_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(c_bi_class_string);

        return false;
      }

      string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;
      curl_easy_setopt(curl_ptr,(CURLoption)curlopt,string_ptr->data);
    }/*}}}*/
    break;
  case CURLOPT_QUOTE:
  case CURLOPT_PREQUOTE:
  case CURLOPT_POSTQUOTE:
    {/*{{{*/

      // - ERROR -
      if (src_1_location->v_type != c_bi_class_array)
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_WRONG_OPTION_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(c_bi_class_array);

        return false;
      }

      pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

      // - ERROR -
      if (array_ptr->used == 0)
      {
        exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_WRONG_OPTION_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      curl_slist *command_slist = nullptr;

      pointer *p_ptr = array_ptr->data;
      pointer *p_ptr_end = p_ptr + array_ptr->used;
      do {
        location_s *cmd_location = it.get_location_value(*p_ptr);

        // - ERROR -
        if (cmd_location->v_type != c_bi_class_string)
        {
          curl_slist_free_all(command_slist);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_WRONG_OPTION_ARRAY_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(c_bi_class_string);

          return false;
        }

        string_s *string_ptr = (string_s *)cmd_location->v_data_ptr;
        command_slist = curl_slist_append(command_slist,string_ptr->data);
      } while(++p_ptr < p_ptr_end);

      curl_slist **quote_slist = nullptr;

      switch (curlopt)
      {
      case CURLOPT_QUOTE:
        quote_slist = &curl_props->quote_slist;
        break;
      case CURLOPT_PREQUOTE:
        quote_slist = &curl_props->prequote_slist;
        break;
      case CURLOPT_POSTQUOTE:
        quote_slist = &curl_props->postquote_slist;
        break;
      }

      curl_easy_setopt(curl_ptr,(CURLoption)curlopt,command_slist);

      // - release old command list -
      if (*quote_slist != nullptr)
      {
        curl_slist_free_all(*quote_slist);
      }

      // - store command list -
      *quote_slist = command_slist;
    }/*}}}*/
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_CURL_MULTI_REQUEST_UNSUPPORTED_OPTION_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_curl_multi_request_method_cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_CURL_MULTI_REQUEST_CHECK_REFERENCE();

  // - remove curl easy from multi -
  curl_multi_remove_handle(cm_ptr->curlm_ptr,curl_ptr);

  // - release curl properties -
  curl_props->clear(it);
  cfree(curl_props);

  // - remove curl from list -
  curl_list.remove(cmr_ptr->index);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_curl_multi_request_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CurlMultiRequest"),"CurlMultiRequest");
  );

  return true;
}/*}}}*/

bool bic_curl_multi_request_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CurlMultiRequest");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CURL_RESULT -
built_in_class_s curl_result_class =
{/*{{{*/
  "CurlResult",
  c_modifier_public | c_modifier_final,
  7, curl_result_methods,
  43 + 1, curl_result_variables,
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
    "code#0",
    c_modifier_public | c_modifier_final,
    bic_curl_result_method_code_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_curl_result_method_data_0
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_curl_result_method_user_data_0
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

  // - curl result info constants -
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

  // - curl error constants -
  { "CURLE_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_curl_result_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert curl result info constants -
  {
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
#if LIBCURL_VERSION_NUM >= 0x073700
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SIZE_UPLOAD_T);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SIZE_DOWNLOAD_T);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SPEED_DOWNLOAD_T);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SPEED_UPLOAD_T);
#else
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SIZE_UPLOAD);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SIZE_DOWNLOAD);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SPEED_DOWNLOAD);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SPEED_UPLOAD);
#endif
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_HEADER_SIZE);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_REQUEST_SIZE);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_SSL_VERIFYRESULT);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_FILETIME);
#if LIBCURL_VERSION_NUM >= 0x073700
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_LENGTH_DOWNLOAD_T);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_LENGTH_UPLOAD_T);
#else
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_LENGTH_DOWNLOAD);
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_CONTENT_LENGTH_UPLOAD);
#endif
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
#if LIBCURL_VERSION_NUM >= 0x072d00
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_ACTIVESOCKET);
#else
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_LASTSOCKET);
#endif
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
#if LIBCURL_VERSION_NUM >= 0x073000
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_TLS_SSL_PTR);
#else
    CREATE_CURL_RESULT_INFO_BIC_STATIC(CURLINFO_TLS_SESSION);
#endif
  }

  // - insert curl error constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_CURL_ERROR_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CURL_ERROR_BIC_STATIC(CURLE_OK);
  }
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

bool bic_curl_result_method_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_result_s *res_ptr = (curl_result_s *)dst_location->v_data_ptr;

  long long int result = res_ptr->code;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_curl_result_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_result_s *res_ptr = (curl_result_s *)dst_location->v_data_ptr;

  // - set data as result -
  res_ptr->data_loc->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(res_ptr->data_loc);

  return true;
}/*}}}*/

bool bic_curl_result_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  curl_result_s *res_ptr = (curl_result_s *)dst_location->v_data_ptr;

  if (res_ptr->user_loc != nullptr)
  {
    // - set user data as result -
    res_ptr->user_loc->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(res_ptr->user_loc);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_curl_result_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
info_type:retrieve_integer
>
method info
; @end

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

  case CURLINFO_OFF_T:
    {/*{{{*/
      curl_off_t data;
      if (curl_easy_getinfo(res_ptr->curl_ptr,(CURLINFO)info_type,&data) == CURLE_OK)
      {
        long long int result = data;

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
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

