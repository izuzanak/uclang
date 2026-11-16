
@begin
include "oath_module.h"
@end

// - OATH indexes of built in classes -
unsigned c_bi_class_oath = c_idx_not_exist;
unsigned c_bi_class_oath_hotp = c_idx_not_exist;
unsigned c_bi_class_oath_totp = c_idx_not_exist;

// - OATH module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                    // Class count
  oath_classes,         // Classes

  0,                    // Error base index
  28,                   // Error count
  oath_error_strings,   // Error strings

  oath_initialize,      // Initialize function
  oath_print_exception, // Print exceptions function
};/*}}}*/

// - OATH classes -
built_in_class_s *oath_classes[] =
{/*{{{*/
  &oath_class,
  &oath_hotp_class,
  &oath_totp_class,
};/*}}}*/

// - OATH error strings -
const char *oath_error_strings[] =
{/*{{{*/
  "error_OATH_CRYPTO_ERROR",
  "error_OATH_INVALID_DIGITS",
  "error_OATH_PRINTF_ERROR",
  "error_OATH_INVALID_HEX",
  "error_OATH_TOO_SMALL_BUFFER",
  "error_OATH_INVALID_OTP",
  "error_OATH_REPLAYED_OTP",
  "error_OATH_BAD_PASSWORD",
  "error_OATH_INVALID_COUNTER",
  "error_OATH_INVALID_TIMESTAMP",
  "error_OATH_NO_SUCH_FILE",
  "error_OATH_UNKNOWN_USER",
  "error_OATH_FILE_SEEK_ERROR",
  "error_OATH_FILE_CREATE_ERROR",
  "error_OATH_FILE_LOCK_ERROR",
  "error_OATH_FILE_RENAME_ERROR",
  "error_OATH_FILE_UNLINK_ERROR",
  "error_OATH_TIME_ERROR",
  "error_OATH_STRCMP_ERROR",
  "error_OATH_INVALID_BASE32",
  "error_OATH_BASE32_OVERFLOW",
  "error_OATH_MALLOC_ERROR",
  "error_OATH_FILE_FLUSH_ERROR",
  "error_OATH_FILE_SYNC_ERROR",
  "error_OATH_FILE_CLOSE_ERROR",
  "error_OATH_FILE_CHOWN_ERROR",
  "error_OATH_FILE_STAT_ERROR",
  "error_OATH_INVALID_ARGUMENT",
};/*}}}*/

// - OATH initialize -
bool oath_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize oath class identifier -
  c_bi_class_oath = class_base_idx++;

  // - initialize oath_hotp class identifier -
  c_bi_class_oath_hotp = class_base_idx++;

  // - initialize oath_totp class identifier -
  c_bi_class_oath_totp = class_base_idx++;

  return true;
}/*}}}*/

// - OATH print exception -
bool oath_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_OATH_CRYPTO_ERROR:
  case c_error_OATH_INVALID_DIGITS:
  case c_error_OATH_PRINTF_ERROR:
  case c_error_OATH_INVALID_HEX:
  case c_error_OATH_TOO_SMALL_BUFFER:
  case c_error_OATH_INVALID_OTP:
  case c_error_OATH_REPLAYED_OTP:
  case c_error_OATH_BAD_PASSWORD:
  case c_error_OATH_INVALID_COUNTER:
  case c_error_OATH_INVALID_TIMESTAMP:
  case c_error_OATH_NO_SUCH_FILE:
  case c_error_OATH_UNKNOWN_USER:
  case c_error_OATH_FILE_SEEK_ERROR:
  case c_error_OATH_FILE_CREATE_ERROR:
  case c_error_OATH_FILE_LOCK_ERROR:
  case c_error_OATH_FILE_RENAME_ERROR:
  case c_error_OATH_FILE_UNLINK_ERROR:
  case c_error_OATH_TIME_ERROR:
  case c_error_OATH_STRCMP_ERROR:
  case c_error_OATH_INVALID_BASE32:
  case c_error_OATH_BASE32_OVERFLOW:
  case c_error_OATH_MALLOC_ERROR:
  case c_error_OATH_FILE_FLUSH_ERROR:
  case c_error_OATH_FILE_SYNC_ERROR:
  case c_error_OATH_FILE_CLOSE_ERROR:
  case c_error_OATH_FILE_CHOWN_ERROR:
  case c_error_OATH_FILE_STAT_ERROR:
    {
      int rc = (int)exception.params[0];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nliboath error %s: %s\n",oath_strerror_name(rc),oath_strerror(rc));
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_OATH_INVALID_ARGUMENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid argument value %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - throw module error mapped from liboath return code -
#define BIC_OATH_THROW_RC(RC) \
{/*{{{*/\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + oath_rc_error_idx(RC),operands[c_source_pos_idx],(location_s *)it.blank_location);\
  new_exception->params.push(RC);\
\
  return false;\
}/*}}}*/

// - throw invalid argument error with offending value -
#define BIC_OATH_THROW_INVALID_ARGUMENT(VALUE) \
{/*{{{*/\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_OATH_INVALID_ARGUMENT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
  new_exception->params.push(VALUE);\
\
  return false;\
}/*}}}*/

// - generate hotp value to string result -
#define BIC_OATH_HOTP_GENERATE(SECRET_PTR,SECRET_SIZE,COUNTER,DIGITS,ADD_CHECKSUM,TRUNCATION_OFFSET) \
{/*{{{*/\
  char otp[c_oath_otp_buffer_size];\
\
  int rc = oath_hotp_generate((const char *)(SECRET_PTR),SECRET_SIZE,(uint64_t)(COUNTER),(unsigned)(DIGITS),ADD_CHECKSUM,TRUNCATION_OFFSET,otp);\
\
  /* - ERROR - */\
  if (rc != OATH_OK)\
  {\
    BIC_OATH_THROW_RC(rc);\
  }\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(otp),otp);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
}/*}}}*/

// - validate hotp value, result is position or blank -
#define BIC_OATH_HOTP_VALIDATE(SECRET_PTR,SECRET_SIZE,START_COUNTER,WINDOW,OTP_LOCATION) \
{/*{{{*/\
  string_s *otp_ptr = (string_s *)(OTP_LOCATION)->v_data_ptr;\
\
  int rc = oath_hotp_validate((const char *)(SECRET_PTR),SECRET_SIZE,(uint64_t)(START_COUNTER),(size_t)(WINDOW),otp_ptr->data);\
\
  if (rc == OATH_INVALID_OTP)\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
  else\
  {\
    /* - ERROR - */\
    if (rc < 0)\
    {\
      BIC_OATH_THROW_RC(rc);\
    }\
\
    long long int result = rc;\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }\
}/*}}}*/

// - generate totp value to string result -
#define BIC_OATH_TOTP_GENERATE(SECRET_PTR,SECRET_SIZE,NOW,TIME_STEP,START_OFFSET,DIGITS,FLAGS) \
{/*{{{*/\
  char otp[c_oath_otp_buffer_size];\
\
  int rc = oath_totp_generate2((const char *)(SECRET_PTR),SECRET_SIZE,(time_t)(NOW),(unsigned)(TIME_STEP),(time_t)(START_OFFSET),(unsigned)(DIGITS),(int)(FLAGS),otp);\
\
  /* - ERROR - */\
  if (rc != OATH_OK)\
  {\
    BIC_OATH_THROW_RC(rc);\
  }\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(otp),otp);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
}/*}}}*/

// - validate totp value, result is [otp_pos,otp_counter] or blank -
#define BIC_OATH_TOTP_VALIDATE(SECRET_PTR,SECRET_SIZE,NOW,TIME_STEP,START_OFFSET,WINDOW,FLAGS,OTP_LOCATION) \
{/*{{{*/\
  string_s *otp_ptr = (string_s *)(OTP_LOCATION)->v_data_ptr;\
\
  int otp_pos = 0;\
  uint64_t otp_counter = 0;\
\
  int rc = oath_totp_validate4((const char *)(SECRET_PTR),SECRET_SIZE,(time_t)(NOW),(unsigned)(TIME_STEP),(time_t)(START_OFFSET),(size_t)(WINDOW),&otp_pos,&otp_counter,(int)(FLAGS),otp_ptr->data);\
\
  if (rc == OATH_INVALID_OTP)\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
  else\
  {\
    /* - ERROR - */\
    if (rc < 0)\
    {\
      BIC_OATH_THROW_RC(rc);\
    }\
\
    location_s *result_location = oath_totp_result_array(it,otp_pos,otp_counter);\
    BIC_SET_RESULT(result_location);\
  }\
}/*}}}*/

// - class OATH -
built_in_class_s oath_class =
{/*{{{*/
  "Oath",
  c_modifier_public | c_modifier_final,
  8, oath_methods,
  6, oath_variables,
  bic_oath_consts,
  bic_oath_init,
  bic_oath_clear,
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

built_in_method_s oath_methods[] =
{/*{{{*/
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_version_0
  },
  {
    "check_version#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_check_version_1
  },
  {
    "base32_encode#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_base32_encode_1
  },
  {
    "base32_decode#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_base32_decode_1
  },
  {
    "hex2bin#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_hex2bin_1
  },
  {
    "bin2hex#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_bin2hex_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_oath_method_print_0
  },
};/*}}}*/

built_in_variable_s oath_variables[] =
{/*{{{*/

  // - oath totp constants -
  { "TOTP_DEFAULT_TIME_STEP_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TOTP_DEFAULT_START_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TOTP_HMAC_SHA1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TOTP_HMAC_SHA256", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TOTP_HMAC_SHA512", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - oath hotp constants -
  { "HOTP_DYNAMIC_TRUNCATION", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_oath_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert oath constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_OATH_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_OATH_BIC_STATIC(OATH_TOTP_DEFAULT_TIME_STEP_SIZE);
    CREATE_OATH_BIC_STATIC(OATH_TOTP_DEFAULT_START_TIME);
    CREATE_OATH_BIC_STATIC(0);
    CREATE_OATH_BIC_STATIC(OATH_TOTP_HMAC_SHA256);
    CREATE_OATH_BIC_STATIC(OATH_TOTP_HMAC_SHA512);
    CREATE_OATH_BIC_STATIC(-1);
  }

}/*}}}*/

void bic_oath_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_oath_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_oath_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  const char *version = oath_check_version(NULL);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_method_check_version_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
req_version:c_bi_class_string
>
class c_bi_class_oath
method check_version
static_method
; @end

  string_s *req_version_ptr = (string_s *)src_0_location->v_data_ptr;

  long long int result = oath_check_version(req_version_ptr->data) != NULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_method_base32_encode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
class c_bi_class_oath
method base32_encode
static_method
; @end

  char *out = nullptr;
  size_t out_len = 0;

  int rc = oath_base32_encode((const char *)data_ptr,data_size,&out,&out_len);

  // - ERROR -
  if (rc != OATH_OK)
  {
    free(out);

    BIC_OATH_THROW_RC(rc);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  if (out_len != 0)
  {
    string_ptr->set(out_len,out);
  }

  free(out);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_method_base32_decode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
class c_bi_class_oath
method base32_decode
static_method
; @end

  char *out = nullptr;
  size_t out_len = 0;

  int rc = oath_base32_decode((const char *)data_ptr,data_size,&out,&out_len);

  // - ERROR -
  if (rc != OATH_OK)
  {
    free(out);

    BIC_OATH_THROW_RC(rc);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  if (out_len != 0)
  {
    string_ptr->set(out_len,out);
  }

  free(out);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_method_hex2bin_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
hex:c_bi_class_string
>
class c_bi_class_oath
method hex2bin
static_method
; @end

  string_s *hex_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned hex_length = hex_ptr->size - 1;

  string_s *string_ptr = it.get_new_string_ptr();

  if (hex_length != 0)
  {
    size_t bin_length = hex_length >> 1;
    string_ptr->create(bin_length);

    int rc = oath_hex2bin(hex_ptr->data,string_ptr->data,&bin_length);

    // - ERROR -
    if (rc != OATH_OK)
    {
      string_ptr->clear();
      cfree(string_ptr);

      BIC_OATH_THROW_RC(rc);
    }

    // - adjust string size -
    string_ptr->data[bin_length] = '\0';
    string_ptr->size = bin_length + 1;
  }

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_method_bin2hex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
class c_bi_class_oath
method bin2hex
static_method
; @end

  string_s *string_ptr = it.get_new_string_ptr();

  if (data_size != 0)
  {
    string_ptr->create(data_size << 1);
    oath_bin2hex((const char *)data_ptr,data_size,string_ptr->data);
  }

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Oath"),"Oath");
  );

  return true;
}/*}}}*/

bool bic_oath_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Oath");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class OATH_HOTP -
built_in_class_s oath_hotp_class =
{/*{{{*/
  "OathHotp",
  c_modifier_public | c_modifier_final,
  11, oath_hotp_methods,
  0, oath_hotp_variables,
  bic_oath_hotp_consts,
  bic_oath_hotp_init,
  bic_oath_hotp_clear,
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

built_in_method_s oath_hotp_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_operator_binary_equal
  },
  {
    "OathHotp#2",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_OathHotp_2
  },
  {
    "OathHotp#4",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_OathHotp_4
  },
  {
    "generate#1",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_generate_1
  },
  {
    "validate#3",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_validate_3
  },
  {
    "secret#0",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_secret_0
  },
  {
    "digits#0",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_digits_0
  },
  {
    "add_checksum#0",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_add_checksum_0
  },
  {
    "truncation_offset#0",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_truncation_offset_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_oath_hotp_method_print_0
  },
};/*}}}*/

built_in_variable_s oath_hotp_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_oath_hotp_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_oath_hotp_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (oath_hotp_s *)nullptr;
}/*}}}*/

void bic_oath_hotp_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  oath_hotp_s *hs_ptr = (oath_hotp_s *)location_ptr->v_data_ptr;

  if (hs_ptr != nullptr)
  {
    hs_ptr->clear();
    cfree(hs_ptr);
  }
}/*}}}*/

bool bic_oath_hotp_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_oath_hotp_method_OathHotp_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
secret:retrieve_data_buffer
digits:retrieve_integer
>
method OathHotp
; @end

  // - ERROR -
  if (digits < 6 || digits > 8)
  {
    BIC_OATH_THROW_RC(OATH_INVALID_DIGITS);
  }

  // - create hotp object -
  oath_hotp_s *hs_ptr = (oath_hotp_s *)cmalloc(sizeof(oath_hotp_s));
  hs_ptr->init();

  hs_ptr->secret.set(secret_size,(const char *)secret_ptr);
  hs_ptr->digits = digits;
  hs_ptr->add_checksum = 0;
  hs_ptr->truncation_offset = -1;

  dst_location->v_data_ptr = (oath_hotp_s *)hs_ptr;

  return true;
}/*}}}*/

bool bic_oath_hotp_method_OathHotp_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
secret:retrieve_data_buffer
digits:retrieve_integer
add_checksum:retrieve_integer
truncation_offset:retrieve_integer
>
method OathHotp
; @end

  // - ERROR -
  if (digits < 6 || digits > 8)
  {
    BIC_OATH_THROW_RC(OATH_INVALID_DIGITS);
  }

  // - create hotp object -
  oath_hotp_s *hs_ptr = (oath_hotp_s *)cmalloc(sizeof(oath_hotp_s));
  hs_ptr->init();

  hs_ptr->secret.set(secret_size,(const char *)secret_ptr);
  hs_ptr->digits = digits;
  hs_ptr->add_checksum = add_checksum != 0;
  hs_ptr->truncation_offset = truncation_offset < 0 ? -1 : truncation_offset;

  dst_location->v_data_ptr = (oath_hotp_s *)hs_ptr;

  return true;
}/*}}}*/

bool bic_oath_hotp_method_generate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
counter:retrieve_integer
>
method generate
; @end

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (counter < 0)
  {
    BIC_OATH_THROW_INVALID_ARGUMENT(counter);
  }

  BIC_OATH_HOTP_GENERATE(hs_ptr->secret.data,hs_ptr->secret.size - 1,counter,hs_ptr->digits,hs_ptr->add_checksum != 0,oath_truncation_offset(hs_ptr->truncation_offset));

  return true;
}/*}}}*/

bool bic_oath_hotp_method_validate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
start_counter:retrieve_integer
window:retrieve_integer
otp:c_bi_class_string
>
method validate
; @end

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (start_counter < 0)
  {
    BIC_OATH_THROW_INVALID_ARGUMENT(start_counter);
  }

  // - ERROR -
  if (window < 0)
  {
    BIC_OATH_THROW_INVALID_ARGUMENT(window);
  }

  BIC_OATH_HOTP_VALIDATE(hs_ptr->secret.data,hs_ptr->secret.size - 1,start_counter,window,src_2_location);

  return true;
}/*}}}*/

bool bic_oath_hotp_method_secret_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(hs_ptr->secret.size - 1,hs_ptr->secret.data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_hotp_method_digits_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  long long int result = hs_ptr->digits;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_hotp_method_add_checksum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  long long int result = hs_ptr->add_checksum;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_hotp_method_truncation_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  long long int result = hs_ptr->truncation_offset;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_hotp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;
    string_ptr->setf("OathHotp(digits=%u)",hs_ptr->digits);
  );

  return true;
}/*}}}*/

bool bic_oath_hotp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_hotp_s *hs_ptr = (oath_hotp_s *)dst_location->v_data_ptr;

  printf("OathHotp(digits=%u)",hs_ptr->digits);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class OATH_TOTP -
built_in_class_s oath_totp_class =
{/*{{{*/
  "OathTotp",
  c_modifier_public | c_modifier_final,
  12, oath_totp_methods,
  0, oath_totp_variables,
  bic_oath_totp_consts,
  bic_oath_totp_init,
  bic_oath_totp_clear,
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

built_in_method_s oath_totp_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_operator_binary_equal
  },
  {
    "OathTotp#2",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_OathTotp_2
  },
  {
    "OathTotp#5",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_OathTotp_5
  },
  {
    "generate#1",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_generate_1
  },
  {
    "validate#3",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_validate_3
  },
  {
    "secret#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_secret_0
  },
  {
    "digits#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_digits_0
  },
  {
    "time_step#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_time_step_0
  },
  {
    "start_offset#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_start_offset_0
  },
  {
    "flags#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_flags_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_oath_totp_method_print_0
  },
};/*}}}*/

built_in_variable_s oath_totp_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_oath_totp_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_oath_totp_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (oath_totp_s *)nullptr;
}/*}}}*/

void bic_oath_totp_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  oath_totp_s *ts_ptr = (oath_totp_s *)location_ptr->v_data_ptr;

  if (ts_ptr != nullptr)
  {
    ts_ptr->clear();
    cfree(ts_ptr);
  }
}/*}}}*/

bool bic_oath_totp_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_oath_totp_method_OathTotp_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
secret:retrieve_data_buffer
digits:retrieve_integer
>
method OathTotp
; @end

  // - ERROR -
  if (digits < 6 || digits > 8)
  {
    BIC_OATH_THROW_RC(OATH_INVALID_DIGITS);
  }

  // - create totp object -
  oath_totp_s *ts_ptr = (oath_totp_s *)cmalloc(sizeof(oath_totp_s));
  ts_ptr->init();

  ts_ptr->secret.set(secret_size,(const char *)secret_ptr);
  ts_ptr->digits = digits;
  ts_ptr->time_step = OATH_TOTP_DEFAULT_TIME_STEP_SIZE;
  ts_ptr->start_offset = OATH_TOTP_DEFAULT_START_TIME;
  ts_ptr->flags = 0;

  dst_location->v_data_ptr = (oath_totp_s *)ts_ptr;

  return true;
}/*}}}*/

bool bic_oath_totp_method_OathTotp_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
secret:retrieve_data_buffer
digits:retrieve_integer
time_step:retrieve_integer
start_offset:retrieve_integer
flags:retrieve_integer
>
method OathTotp
; @end

  // - ERROR -
  if (digits < 6 || digits > 8)
  {
    BIC_OATH_THROW_RC(OATH_INVALID_DIGITS);
  }

  // - ERROR -
  if (!oath_time_step_valid(time_step))
  {
    BIC_OATH_THROW_INVALID_ARGUMENT(time_step);
  }

  // - ERROR -
  if (!oath_flags_valid(flags))
  {
    BIC_OATH_THROW_INVALID_ARGUMENT(flags);
  }

  // - create totp object -
  oath_totp_s *ts_ptr = (oath_totp_s *)cmalloc(sizeof(oath_totp_s));
  ts_ptr->init();

  ts_ptr->secret.set(secret_size,(const char *)secret_ptr);
  ts_ptr->digits = digits;
  ts_ptr->time_step = time_step;
  ts_ptr->start_offset = start_offset;
  ts_ptr->flags = flags;

  dst_location->v_data_ptr = (oath_totp_s *)ts_ptr;

  return true;
}/*}}}*/

bool bic_oath_totp_method_generate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
now:retrieve_integer
>
method generate
; @end

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  BIC_OATH_TOTP_GENERATE(ts_ptr->secret.data,ts_ptr->secret.size - 1,now,ts_ptr->time_step,ts_ptr->start_offset,ts_ptr->digits,ts_ptr->flags);

  return true;
}/*}}}*/

bool bic_oath_totp_method_validate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
now:retrieve_integer
window:retrieve_integer
otp:c_bi_class_string
>
method validate
; @end

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (window < 0)
  {
    BIC_OATH_THROW_INVALID_ARGUMENT(window);
  }

  BIC_OATH_TOTP_VALIDATE(ts_ptr->secret.data,ts_ptr->secret.size - 1,now,ts_ptr->time_step,ts_ptr->start_offset,window,ts_ptr->flags,src_2_location);

  return true;
}/*}}}*/

bool bic_oath_totp_method_secret_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(ts_ptr->secret.size - 1,ts_ptr->secret.data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_oath_totp_method_digits_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->digits;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_totp_method_time_step_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->time_step;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_totp_method_start_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->start_offset;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_totp_method_flags_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->flags;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_oath_totp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;
    string_ptr->setf("OathTotp(digits=%u,time_step=%u,start_offset=%" HOST_LL_FORMAT "d,flags=%d)",ts_ptr->digits,ts_ptr->time_step,ts_ptr->start_offset,ts_ptr->flags);
  );

  return true;
}/*}}}*/

bool bic_oath_totp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  oath_totp_s *ts_ptr = (oath_totp_s *)dst_location->v_data_ptr;

  printf("OathTotp(digits=%u,time_step=%u,start_offset=%" HOST_LL_FORMAT "d,flags=%d)",ts_ptr->digits,ts_ptr->time_step,ts_ptr->start_offset,ts_ptr->flags);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

