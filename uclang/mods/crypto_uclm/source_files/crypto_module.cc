
@begin
include "crypto_module.h"
@end

// - CRYPTO indexes of built in classes -
unsigned c_bi_class_crypto = c_idx_not_exist;
unsigned c_bi_class_crypto_pkey = c_idx_not_exist;
unsigned c_bi_class_crypto_digest_info = c_idx_not_exist;
unsigned c_bi_class_crypto_digest = c_idx_not_exist;
unsigned c_bi_class_crypto_digest_sign = c_idx_not_exist;
unsigned c_bi_class_crypto_digest_verify = c_idx_not_exist;
unsigned c_bi_class_crypto_cipher_info = c_idx_not_exist;
unsigned c_bi_class_crypto_encrypt = c_idx_not_exist;
unsigned c_bi_class_crypto_decrypt = c_idx_not_exist;

// - CRYPTO module -
built_in_module_s module =
{/*{{{*/
  9,                      // Class count
  crypto_classes,         // Classes

  0,                      // Error base index
  14,                     // Error count
  crypto_error_strings,   // Error strings

  crypto_initialize,      // Initialize function
  crypto_print_exception, // Print exceptions function
};/*}}}*/

// - CRYPTO classes -
built_in_class_s *crypto_classes[] =
{/*{{{*/
  &crypto_class,
  &crypto_pkey_class,
  &crypto_digest_info_class,
  &crypto_digest_class,
  &crypto_digest_sign_class,
  &crypto_digest_verify_class,
  &crypto_cipher_info_class,
  &crypto_encrypt_class,
  &crypto_decrypt_class,
};/*}}}*/

// - CRYPTO error strings -
const char *crypto_error_strings[] =
{/*{{{*/
  "error_CRYPTO_INVALID_BASE_DATA_SIZE",
  "error_CRYPTO_INVALID_BASE_DATA",
  "error_CRYPTO_PKEY_CANNOT_READ_KEY_FROM_FILE",
  "error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME",
  "error_CRYPTO_DIGEST_CREATE_INIT_ERROR",
  "error_CRYPTO_DIGEST_UPDATE_ERROR",
  "error_CRYPTO_DIGEST_VALUE_ERROR",
  "error_CRYPTO_DIGEST_VERIFY_ERROR",
  "error_CRYPTO_CIPHER_INVALID_ALGORITHM_NAME",
  "error_CRYPTO_CIPHER_INVALID_KEY_LENGTH",
  "error_CRYPTO_CIPHER_INVALID_INIT_VECTOR_LENGTH",
  "error_CRYPTO_CIPHER_NEW_INIT_ERROR",
  "error_CRYPTO_CIPHER_UPDATE_ERROR",
  "error_CRYPTO_CIPHER_FINALIZE_ERROR",
};/*}}}*/

// - CRYPTO initialize -
bool crypto_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize crypto class identifier -
  c_bi_class_crypto = class_base_idx++;

  // - initialize crypto_pkey class identifier -
  c_bi_class_crypto_pkey = class_base_idx++;

  // - initialize crypto_digest_info class identifier -
  c_bi_class_crypto_digest_info = class_base_idx++;

  // - initialize crypto_digest class identifier -
  c_bi_class_crypto_digest = class_base_idx++;

  // - initialize crypto_digest_sign class identifier -
  c_bi_class_crypto_digest_sign = class_base_idx++;

  // - initialize crypto_digest_verify class identifier -
  c_bi_class_crypto_digest_verify = class_base_idx++;

  // - initialize crypto_cipher_info class identifier -
  c_bi_class_crypto_cipher_info = class_base_idx++;

  // - initialize crypto_encrypt class identifier -
  c_bi_class_crypto_encrypt = class_base_idx++;

  // - initialize crypto_decrypt class identifier -
  c_bi_class_crypto_decrypt = class_base_idx++;

  return true;
}/*}}}*/

// - CRYPTO print exception -
bool crypto_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CRYPTO_INVALID_BASE_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid base%" HOST_LL_FORMAT "d encoded data size\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_INVALID_BASE_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid base%" HOST_LL_FORMAT "d encoded data\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_PKEY_CANNOT_READ_KEY_FROM_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read key from file: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid name of digest algorithm: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while initializing message digest context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_DIGEST_UPDATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while updating message digest\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_DIGEST_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving message digest value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_DIGEST_VERIFY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while verifying message digest signature\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_CIPHER_INVALID_ALGORITHM_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid name of cipher algorithm: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_CIPHER_INVALID_KEY_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid length of cipher key: %" HOST_LL_FORMAT "d, expected %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_CIPHER_INVALID_INIT_VECTOR_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid length of cipher initialisation vector: %" HOST_LL_FORMAT "d, expected %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_CIPHER_NEW_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while initializing cipher context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_CIPHER_UPDATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while updating cipher context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_CIPHER_FINALIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while finalizing cipher context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CRYPTO -
built_in_class_s crypto_class =
{/*{{{*/
  "Crypto",
  c_modifier_public | c_modifier_final,
  7, crypto_methods,
  0, crypto_variables,
  bic_crypto_consts,
  bic_crypto_init,
  bic_crypto_clear,
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

built_in_method_s crypto_methods[] =
{/*{{{*/
  {
    "random#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_random_1
  },
  {
    "encode_base16#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_encode_base16_1
  },
  {
    "decode_base16#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_decode_base16_1
  },
  {
    "encode_base64#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_encode_base64_1
  },
  {
    "decode_base64#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_decode_base64_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_crypto_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_crypto_method_random_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int size;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"random#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(size);

  RAND_bytes((unsigned char *)string_ptr->data,size);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_encode_base16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"encode_base16#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(s_length << 1);

    unsigned char *s_ptr = (unsigned char *)source_ptr->data;
    unsigned char *s_ptr_end = s_ptr + s_length;
    unsigned char *t_ptr = (unsigned char *)target_ptr->data;

    do {
      *t_ptr++ = c_base16_map[*s_ptr >> 4];
      *t_ptr++ = c_base16_map[*s_ptr & 0x0f];
    } while(++s_ptr < s_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_decode_base16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"decode_base16#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  // - ERROR -
  if (s_length & 0x01)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(16);

    return false;
  }

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(s_length >> 1);

    unsigned char *s_ptr = (unsigned char *)source_ptr->data;
    unsigned char *s_ptr_end = s_ptr + s_length;
    unsigned char *t_ptr = (unsigned char *)target_ptr->data;

#define BIC_CRYPTO_METHOD_DECODE_BASE16_CHARACTER(OPERATOR) \
{/*{{{*/\
  unsigned char ch = *s_ptr++;\
  \
  if (ch >= '0' && ch <= '9')\
  {\
    *t_ptr OPERATOR ch - '0';\
  }\
  else if (ch >= 'a' && ch <= 'f')\
  {\
    *t_ptr OPERATOR 10 + (ch - 'a');\
  }\
  else if (ch >= 'A' && ch <= 'F')\
  {\
    *t_ptr OPERATOR 10 + (ch - 'A');\
  }\
  \
  /* - ERROR - */\
  else\
  {\
    target_ptr->clear();\
    cfree(target_ptr);\
    \
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(16);\
    \
    return false;\
  }\
}/*}}}*/

    do {
      BIC_CRYPTO_METHOD_DECODE_BASE16_CHARACTER(=);
      *t_ptr <<= 4;
      BIC_CRYPTO_METHOD_DECODE_BASE16_CHARACTER(+=);
    } while(++t_ptr,s_ptr < s_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_encode_base64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"encode_base64#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(((s_length/3 + 1) << 2) + 1);

    target_ptr->size = EVP_EncodeBlock(
        (unsigned char *)target_ptr->data,
        (unsigned char *)source_ptr->data,
        s_length) + 1;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_decode_base64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"encode_base64#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  // - ERROR -
  if (s_length & 0x03)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(64);

    return false;
  }

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(((s_length >> 2) * 3) + 1);

    int length = EVP_DecodeBlock(
        (unsigned char *)target_ptr->data,
        (unsigned char *)source_ptr->data,
        s_length);

    // - ERROR -
    if (length == -1)
    {
      target_ptr->clear();
      cfree(target_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(64);

      return false;
    }

    target_ptr->size = length + 1;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Crypto"),"Crypto");
  );

  return true;
}/*}}}*/

bool bic_crypto_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Crypto");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_PKEY -
built_in_class_s crypto_pkey_class =
{/*{{{*/
  "CryptoPKey",
  c_modifier_public | c_modifier_final,
  5, crypto_pkey_methods,
  3, crypto_pkey_variables,
  bic_crypto_pkey_consts,
  bic_crypto_pkey_init,
  bic_crypto_pkey_clear,
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

built_in_method_s crypto_pkey_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_pkey_operator_binary_equal
  },
  {
    "load_private#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_pkey_method_load_private_2
  },
  {
    "load_public#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_pkey_method_load_public_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_pkey_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_pkey_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_pkey_variables[] =
{/*{{{*/

  // - crypto pkey type constants -
  { "TYPE_RSA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DSA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EC", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_crypto_pkey_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert crypto pkey type constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(EVP_PKEY_RSA);
    CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(EVP_PKEY_DSA);
    CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(EVP_PKEY_EC);
  }

}/*}}}*/

void bic_crypto_pkey_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crypto_pkey_s *)nullptr;
}/*}}}*/

void bic_crypto_pkey_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crypto_pkey_s *ck_ptr = (crypto_pkey_s *)location_ptr->v_data_ptr;

  // - if crypto pkey object exists -
  if (ck_ptr != nullptr)
  {
    ck_ptr->clear(it);
    cfree(ck_ptr);
  }
}/*}}}*/

bool bic_crypto_pkey_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_CRYPTO_PKEY_LOAD_KEY(NAME,FUNCTION,ISPUB) \
{/*{{{*/\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);\
  \
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string ||\
      src_1_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,NAME);\
    new_exception->params.push(2);\
    new_exception->params.push(src_0_location->v_type);\
    new_exception->params.push(src_1_location->v_type);\
    \
    return false;\
  }\
  \
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
  \
  /* - ERROR - */\
  FILE *f = fopen(string_ptr->data,"r");\
  if (f == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_PKEY_CANNOT_READ_KEY_FROM_FILE,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
  \
  EVP_PKEY *pkey = FUNCTION(f,nullptr,crypto_pkey_s::password_cb,src_1_location->v_data_ptr);\
  fclose(f);\
  \
  /* - ERROR - */\
  if (pkey == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_PKEY_CANNOT_READ_KEY_FROM_FILE,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
  \
  /* - create crypto_pkey_s object - */\
  crypto_pkey_s *ck_ptr = (crypto_pkey_s *)cmalloc(sizeof(crypto_pkey_s));\
  ck_ptr->init();\
  \
  ck_ptr->pkey = pkey;\
  ck_ptr->ispub = ISPUB;\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_crypto_pkey,ck_ptr);\
  BIC_SET_RESULT(new_location);\
  \
  return true;\
}/*}}}*/

bool bic_crypto_pkey_method_load_private_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_PKEY_LOAD_KEY("load_private#2",PEM_read_PrivateKey,false);
}/*}}}*/

bool bic_crypto_pkey_method_load_public_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_PKEY_LOAD_KEY("load_public#2",PEM_read_PUBKEY,true);
}/*}}}*/

bool bic_crypto_pkey_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoPKey"),"CryptoPKey");
  );

  return true;
}/*}}}*/

bool bic_crypto_pkey_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoPKey");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_DIGEST_INFO -
built_in_class_s crypto_digest_info_class =
{/*{{{*/
  "CryptoDigestInfo",
  c_modifier_public | c_modifier_final,
  5, crypto_digest_info_methods,
  0, crypto_digest_info_variables,
  bic_crypto_digest_info_consts,
  bic_crypto_digest_info_init,
  bic_crypto_digest_info_clear,
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

built_in_method_s crypto_digest_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_info_operator_binary_equal
  },
  {
    "CryptoDigestInfo#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_info_method_CryptoDigestInfo_1
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_info_method_name_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_info_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_digest_info_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_digest_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_digest_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (EVP_MD *)nullptr;
}/*}}}*/

void bic_crypto_digest_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_crypto_digest_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_digest_info_method_CryptoDigestInfo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CryptoDigestInfo#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  const EVP_MD *mdt_ptr = EVP_get_digestbyname(((string_s *)src_0_location->v_data_ptr)->data);

  // - ERROR -
  if (mdt_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (EVP_MD *)mdt_ptr;

  return true;
}/*}}}*/

bool bic_crypto_digest_info_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *name = EVP_MD_name((EVP_MD *)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_crypto_digest_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoDigestInfo"),"CryptoDigestInfo");
  );

  return true;
}/*}}}*/

bool bic_crypto_digest_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoDigestInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_DIGEST -
built_in_class_s crypto_digest_class =
{/*{{{*/
  "CryptoDigest",
  c_modifier_public | c_modifier_final,
  6, crypto_digest_methods,
  0, crypto_digest_variables,
  bic_crypto_digest_consts,
  bic_crypto_digest_init,
  bic_crypto_digest_clear,
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

built_in_method_s crypto_digest_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_operator_binary_equal
  },
  {
    "CryptoDigest#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_method_CryptoDigest_1
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_method_update_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_digest_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_digest_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_digest_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crypto_digest_s *)nullptr;
}/*}}}*/

void bic_crypto_digest_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crypto_digest_s *cd_ptr = (crypto_digest_s *)location_ptr->v_data_ptr;

  // - if crypto digest object exists -
  if (cd_ptr != nullptr)
  {
    cd_ptr->clear(it);
    cfree(cd_ptr);
  }
}/*}}}*/

bool bic_crypto_digest_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_digest_method_CryptoDigest_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  const EVP_MD *mdt_ptr;

  if (src_0_location->v_type == c_bi_class_string)
  {
    mdt_ptr = EVP_get_digestbyname(((string_s *)src_0_location->v_data_ptr)->data);

    // - ERROR -
    if (mdt_ptr == nullptr)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME,operands[c_source_pos_idx],src_0_location);
      return false;
    }
  }
  else if (src_0_location->v_type == c_bi_class_crypto_digest_info)
  {
    mdt_ptr = (EVP_MD *)src_0_location->v_data_ptr;
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CryptoDigest#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create crypto digest object -
  crypto_digest_s *cd_ptr = (crypto_digest_s *)cmalloc(sizeof(crypto_digest_s));
  cd_ptr->init();

  // - ERROR -
  if ((cd_ptr->context = EVP_MD_CTX_create()) == nullptr)
  {
    cd_ptr->clear(it);
    cfree(cd_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_DigestInit_ex(cd_ptr->context,mdt_ptr,nullptr) != 1)
  {
    cd_ptr->clear(it);
    cfree(cd_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (crypto_digest_s *)cd_ptr;

  return true;
}/*}}}*/

bool bic_crypto_digest_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("update#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  crypto_digest_s *cd_ptr = (crypto_digest_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (EVP_DigestUpdate(cd_ptr->context,string_ptr->data,string_ptr->size - 1) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_UPDATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_crypto_digest_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  crypto_digest_s *cd_ptr = (crypto_digest_s *)dst_location->v_data_ptr;

  // - ERROR -
  EVP_MD_CTX *context_copy;
  if ((context_copy = EVP_MD_CTX_create()) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_DigestInit_ex(context_copy,EVP_MD_CTX_md(cd_ptr->context),nullptr) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_MD_CTX_copy_ex(context_copy,cd_ptr->context) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(EVP_MD_CTX_size(context_copy));

  // - ERROR -
  unsigned dg_length;
  if (EVP_DigestFinal_ex(context_copy,(unsigned char *)string_ptr->data,&dg_length) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    string_ptr->clear();
    cfree(string_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  EVP_MD_CTX_destroy(context_copy);

  // - adjust result string size -
  string_ptr->size = dg_length + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_crypto_digest_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoDigest"),"CryptoDigest");
  );

  return true;
}/*}}}*/

bool bic_crypto_digest_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoDigest");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_DIGEST_SIGN -
built_in_class_s crypto_digest_sign_class =
{/*{{{*/
  "CryptoDigestSign",
  c_modifier_public | c_modifier_final,
  6, crypto_digest_sign_methods,
  0, crypto_digest_sign_variables,
  bic_crypto_digest_sign_consts,
  bic_crypto_digest_sign_init,
  bic_crypto_digest_sign_clear,
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

built_in_method_s crypto_digest_sign_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_sign_operator_binary_equal
  },
  {
    "CryptoDigestSign#2",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_sign_method_CryptoDigestSign_2
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_sign_method_update_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_sign_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_sign_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_sign_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_digest_sign_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_CRYPTO_DIGEST_SIGN_VERIFY_CONSTRUCTOR(NAME,TYPE) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);\
  \
  const EVP_MD *mdt_ptr = nullptr;\
  \
  if (src_0_location->v_type == c_bi_class_string)\
  {\
    mdt_ptr = EVP_get_digestbyname(((string_s *)src_0_location->v_data_ptr)->data);\
    \
    /* - ERROR - */\
    if (mdt_ptr == nullptr)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME,operands[c_source_pos_idx],src_0_location);\
      return false;\
    }\
  }\
  else if (src_0_location->v_type == c_bi_class_crypto_digest_info)\
  {\
    mdt_ptr = (EVP_MD *)src_0_location->v_data_ptr;\
  }\
  \
  /* - ERROR - */\
  if (mdt_ptr == nullptr ||\
      src_1_location->v_type != c_bi_class_crypto_pkey)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(2);\
    new_exception->params.push(src_0_location->v_type);\
    new_exception->params.push(src_1_location->v_type);\
    \
    return false;\
  }\
  \
  crypto_pkey_s *ck_ptr = (crypto_pkey_s *)src_1_location->v_data_ptr;\
  \
  /* - create crypto digest object - */\
  crypto_digest_key_s *cd_ptr = (crypto_digest_key_s *)cmalloc(sizeof(crypto_digest_key_s));\
  cd_ptr->init();\
  \
  /* - ERROR - */\
  if ((cd_ptr->context = EVP_MD_CTX_create()) == nullptr)\
  {\
    cd_ptr->clear(it);\
    cfree(cd_ptr);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  /* - ERROR - */\
  if (EVP_Digest ## TYPE ## Init(cd_ptr->context,nullptr,mdt_ptr,nullptr,ck_ptr->pkey) != 1)\
  {\
    cd_ptr->clear(it);\
    cfree(cd_ptr);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  /* - set key location - */\
  src_1_location->v_reference_cnt.atomic_inc();\
  cd_ptr->key_location = src_1_location;\
  \
  dst_location->v_data_ptr = (crypto_digest_key_s *)cd_ptr;\
  \
  return true;\
}/*}}}*/

#define BIC_CRYPTO_DIGEST_SIGN_VERIFY_UPDATE(TYPE) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI("update#1");\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  crypto_digest_key_s *cd_ptr = (crypto_digest_key_s *)dst_location->v_data_ptr;\
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (EVP_Digest ## TYPE ## Update(cd_ptr->context,string_ptr->data,string_ptr->size - 1) != 1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_UPDATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  BIC_SET_RESULT_DESTINATION();\
  \
  return true;\
}/*}}}*/

void bic_crypto_digest_sign_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_digest_sign_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crypto_digest_key_s *)nullptr;
}/*}}}*/

void bic_crypto_digest_sign_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crypto_digest_key_s *cd_ptr = (crypto_digest_key_s *)location_ptr->v_data_ptr;

  // - if crypto digest object exists -
  if (cd_ptr != nullptr)
  {
    cd_ptr->clear(it);
    cfree(cd_ptr);
  }
}/*}}}*/

bool bic_crypto_digest_sign_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_digest_sign_method_CryptoDigestSign_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_DIGEST_SIGN_VERIFY_CONSTRUCTOR("CryptoDigestSign#2",Sign);
}/*}}}*/

bool bic_crypto_digest_sign_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_DIGEST_SIGN_VERIFY_UPDATE(Sign);
}/*}}}*/

bool bic_crypto_digest_sign_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  crypto_digest_key_s *cd_ptr = (crypto_digest_key_s *)dst_location->v_data_ptr;
  crypto_pkey_s *ck_ptr = (crypto_pkey_s *)cd_ptr->key_location->v_data_ptr;

  // - ERROR -
  EVP_MD_CTX *context_copy;
  if ((context_copy = EVP_MD_CTX_create()) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_DigestSignInit(context_copy,nullptr,EVP_MD_CTX_md(cd_ptr->context),nullptr,ck_ptr->pkey) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_MD_CTX_copy_ex(context_copy,cd_ptr->context) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  unsigned dg_length = 0;
  if (EVP_DigestSignFinal(context_copy,nullptr,&dg_length) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(dg_length);

  // - ERROR -
  if (EVP_DigestSignFinal(context_copy,(unsigned char *)string_ptr->data,&dg_length) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    string_ptr->clear();
    cfree(string_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  EVP_MD_CTX_destroy(context_copy);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_crypto_digest_sign_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoDigestSign"),"CryptoDigestSign");
  );

  return true;
}/*}}}*/

bool bic_crypto_digest_sign_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoDigestSign");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_DIGEST_VERIFY -
built_in_class_s crypto_digest_verify_class =
{/*{{{*/
  "CryptoDigestVerify",
  c_modifier_public | c_modifier_final,
  6, crypto_digest_verify_methods,
  0, crypto_digest_verify_variables,
  bic_crypto_digest_verify_consts,
  bic_crypto_digest_verify_init,
  bic_crypto_digest_verify_clear,
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

built_in_method_s crypto_digest_verify_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_verify_operator_binary_equal
  },
  {
    "CryptoDigestVerify#2",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_verify_method_CryptoDigestVerify_2
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_verify_method_update_1
  },
  {
    "verify#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_digest_verify_method_verify_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_verify_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_digest_verify_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_digest_verify_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_digest_verify_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_digest_verify_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crypto_digest_key_s *)nullptr;
}/*}}}*/

void bic_crypto_digest_verify_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crypto_digest_key_s *cd_ptr = (crypto_digest_key_s *)location_ptr->v_data_ptr;

  // - if crypto digest object exists -
  if (cd_ptr != nullptr)
  {
    cd_ptr->clear(it);
    cfree(cd_ptr);
  }
}/*}}}*/

bool bic_crypto_digest_verify_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_digest_verify_method_CryptoDigestVerify_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_DIGEST_SIGN_VERIFY_CONSTRUCTOR("CryptoDigestVerify#2",Verify);
}/*}}}*/

bool bic_crypto_digest_verify_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_DIGEST_SIGN_VERIFY_UPDATE(Verify);
}/*}}}*/

bool bic_crypto_digest_verify_method_verify_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("verify#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  crypto_digest_key_s *cd_ptr = (crypto_digest_key_s *)dst_location->v_data_ptr;
  crypto_pkey_s *ck_ptr = (crypto_pkey_s *)cd_ptr->key_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  EVP_MD_CTX *context_copy;
  if ((context_copy = EVP_MD_CTX_create()) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VERIFY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_DigestVerifyInit(context_copy,nullptr,EVP_MD_CTX_md(cd_ptr->context),nullptr,ck_ptr->pkey) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VERIFY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (EVP_MD_CTX_copy_ex(context_copy,cd_ptr->context) != 1)
  {
    EVP_MD_CTX_destroy(context_copy);

    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VERIFY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long result = EVP_DigestVerifyFinal(context_copy,(const unsigned char *)string_ptr->data,string_ptr->size - 1);

  EVP_MD_CTX_destroy(context_copy);

  // - ERROR -
  if (result & ~0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_DIGEST_VERIFY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_crypto_digest_verify_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoDigestVerify"),"CryptoDigestVerify");
  );

  return true;
}/*}}}*/

bool bic_crypto_digest_verify_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoDigestVerify");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_CIPHER_INFO -
built_in_class_s crypto_cipher_info_class =
{/*{{{*/
  "CryptoCipherInfo",
  c_modifier_public | c_modifier_final,
  8, crypto_cipher_info_methods,
  0, crypto_cipher_info_variables,
  bic_crypto_cipher_info_consts,
  bic_crypto_cipher_info_init,
  bic_crypto_cipher_info_clear,
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

built_in_method_s crypto_cipher_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_cipher_info_operator_binary_equal
  },
  {
    "CryptoCipherInfo#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_cipher_info_method_CryptoCipherInfo_1
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_cipher_info_method_name_0
  },
  {
    "block_size#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_cipher_info_method_block_size_0
  },
  {
    "key_length#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_cipher_info_method_key_length_0
  },
  {
    "iv_length#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_cipher_info_method_iv_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_cipher_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_cipher_info_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_cipher_info_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_cipher_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_cipher_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (EVP_CIPHER *)nullptr;
}/*}}}*/

void bic_crypto_cipher_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_crypto_cipher_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_CryptoCipherInfo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CryptoCipherInfo#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  const EVP_CIPHER *ct_ptr = EVP_get_cipherbyname(((string_s *)src_0_location->v_data_ptr)->data);

  // - ERROR -
  if (ct_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_INVALID_ALGORITHM_NAME,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (EVP_CIPHER *)ct_ptr;

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *name = EVP_CIPHER_name((EVP_CIPHER *)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_block_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = EVP_CIPHER_block_size((EVP_CIPHER *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_key_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = EVP_CIPHER_key_length((EVP_CIPHER *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_iv_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = EVP_CIPHER_iv_length((EVP_CIPHER *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoCipherInfo"),"CryptoCipherInfo");
  );

  return true;
}/*}}}*/

bool bic_crypto_cipher_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoCipherInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_ENCRYPT -
built_in_class_s crypto_encrypt_class =
{/*{{{*/
  "CryptoEncrypt",
  c_modifier_public | c_modifier_final,
  6, crypto_encrypt_methods,
  0, crypto_encrypt_variables,
  bic_crypto_encrypt_consts,
  bic_crypto_encrypt_init,
  bic_crypto_encrypt_clear,
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

built_in_method_s crypto_encrypt_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_encrypt_operator_binary_equal
  },
  {
    "CryptoEncrypt#3",
    c_modifier_public | c_modifier_final,
    bic_crypto_encrypt_method_CryptoEncrypt_3
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_encrypt_method_update_1
  },
  {
    "finalize#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_encrypt_method_finalize_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_encrypt_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_encrypt_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_encrypt_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_CONSTRUCTOR(TYPE,NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);\
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);\
  \
  const EVP_CIPHER *ct_ptr = nullptr;\
  \
  if (src_0_location->v_type == c_bi_class_string)\
  {\
    ct_ptr = EVP_get_cipherbyname(((string_s *)src_0_location->v_data_ptr)->data);\
  \
    /* - ERROR - */\
    if (ct_ptr == nullptr)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_INVALID_ALGORITHM_NAME,operands[c_source_pos_idx],src_0_location);\
      return false;\
    }\
  }\
  else if (src_0_location->v_type == c_bi_class_crypto_cipher_info)\
  {\
    ct_ptr = (EVP_CIPHER *)src_0_location->v_data_ptr;\
  }\
  \
  /* - ERROR - */\
  if (ct_ptr == nullptr ||\
      src_1_location->v_type != c_bi_class_string ||\
      src_2_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(3);\
    new_exception->params.push(src_0_location->v_type);\
    new_exception->params.push(src_1_location->v_type);\
    new_exception->params.push(src_2_location->v_type);\
    \
    return false;\
  }\
  \
  string_s *key_ptr = (string_s *)src_1_location->v_data_ptr;\
  string_s *iv_ptr = (string_s *)src_2_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (key_ptr->size - 1 != (unsigned)EVP_CIPHER_key_length(ct_ptr))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_INVALID_KEY_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(key_ptr->size - 1);\
    new_exception->params.push(EVP_CIPHER_key_length(ct_ptr));\
    \
    return false;\
  }\
  \
  /* - ERROR - */\
  if (iv_ptr->size - 1 != (unsigned)EVP_CIPHER_iv_length(ct_ptr))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_INVALID_INIT_VECTOR_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(iv_ptr->size - 1);\
    new_exception->params.push(EVP_CIPHER_iv_length(ct_ptr));\
    \
    return false;\
  }\
  \
  /* - create crypto cipher object - */\
  crypto_cipher_s *cc_ptr = (crypto_cipher_s *)cmalloc(sizeof(crypto_cipher_s));\
  cc_ptr->init();\
  \
  /* - ERROR - */\
  if ((cc_ptr->context = EVP_CIPHER_CTX_new()) == nullptr)\
  {\
    cc_ptr->clear(it);\
    cfree(cc_ptr);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_NEW_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  /* - ERROR - */\
  if (EVP_ ## TYPE ## Init_ex(cc_ptr->context,ct_ptr,nullptr,\
      (unsigned char *)key_ptr->data,(unsigned char *)iv_ptr->data) != 1)\
  {\
    cc_ptr->clear(it);\
    cfree(cc_ptr);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_NEW_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  dst_location->v_data_ptr = (crypto_cipher_s *)cc_ptr;\
}/*}}}*/

#define BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_UPDATE(TYPE,NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  crypto_cipher_s *cc_ptr = (crypto_cipher_s *)dst_location->v_data_ptr;\
  \
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
  unsigned string_length = string_ptr->size - 1;\
  \
  unsigned block_size = EVP_CIPHER_CTX_block_size(cc_ptr->context);\
  \
  /* - create result string - */\
  string_s *result_ptr = it.get_new_string_ptr();\
  result_ptr->create(string_length + (block_size - string_length % block_size));\
  \
  /* - ERROR - */\
  int result_length;\
  if (EVP_ ## TYPE ## Update(cc_ptr->context,\
      (unsigned char *)result_ptr->data,&result_length,\
      (unsigned char *)string_ptr->data,string_length) != 1)\
  {\
    result_ptr->clear();\
    cfree(result_ptr);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_UPDATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  result_ptr->size = result_length + 1;\
  \
  BIC_SET_RESULT_STRING(result_ptr);\
}/*}}}*/

#define BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_FINALIZE(TYPE) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  crypto_cipher_s *cc_ptr = (crypto_cipher_s *)dst_location->v_data_ptr;\
  \
  /* - ERROR - */\
  EVP_CIPHER_CTX *context_copy;\
  if ((context_copy = EVP_CIPHER_CTX_new()) == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_FINALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  /* - ERROR - */\
  if (EVP_ ## TYPE ## Init_ex(context_copy,EVP_CIPHER_CTX_cipher(cc_ptr->context),nullptr,nullptr,nullptr) != 1)\
  {\
    EVP_CIPHER_CTX_free(context_copy);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_FINALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  /* - ERROR - */\
  if (EVP_CIPHER_CTX_copy(context_copy,cc_ptr->context) != 1)\
  {\
    EVP_CIPHER_CTX_free(context_copy);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_FINALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  /* - create result string - */\
  string_s *result_ptr = it.get_new_string_ptr();\
  result_ptr->create(EVP_CIPHER_CTX_block_size(context_copy));\
  \
  /* - ERROR - */\
  int result_length;\
  if (EVP_ ## TYPE ## Final_ex(context_copy,(unsigned char *)result_ptr->data,&result_length) != 1)\
  {\
    EVP_CIPHER_CTX_free(context_copy);\
    \
    result_ptr->clear();\
    cfree(result_ptr);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_CIPHER_FINALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  EVP_CIPHER_CTX_free(context_copy);\
  \
  /* - adjust result string size - */\
  result_ptr->size = result_length + 1;\
  \
  BIC_SET_RESULT_STRING(result_ptr);\
}/*}}}*/

void bic_crypto_encrypt_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_encrypt_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crypto_cipher_s *)nullptr;
}/*}}}*/

void bic_crypto_encrypt_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crypto_cipher_s *cc_ptr = (crypto_cipher_s *)location_ptr->v_data_ptr;

  // - if crypto encrypt object exists -
  if (cc_ptr != nullptr)
  {
    cc_ptr->clear(it);
    cfree(cc_ptr);
  }
}/*}}}*/

bool bic_crypto_encrypt_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_encrypt_method_CryptoEncrypt_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_CONSTRUCTOR(Encrypt,"CryptoEncrypt#3");

  return true;
}/*}}}*/

bool bic_crypto_encrypt_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_UPDATE(Encrypt,"update#1");

  return true;
}/*}}}*/

bool bic_crypto_encrypt_method_finalize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_FINALIZE(Encrypt);

  return true;
}/*}}}*/

bool bic_crypto_encrypt_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoEncrypt"),"CryptoEncrypt");
  );

  return true;
}/*}}}*/

bool bic_crypto_encrypt_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoEncrypt");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRYPTO_DECRYPT -
built_in_class_s crypto_decrypt_class =
{/*{{{*/
  "CryptoDecrypt",
  c_modifier_public | c_modifier_final,
  6, crypto_decrypt_methods,
  0, crypto_decrypt_variables,
  bic_crypto_decrypt_consts,
  bic_crypto_decrypt_init,
  bic_crypto_decrypt_clear,
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

built_in_method_s crypto_decrypt_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_decrypt_operator_binary_equal
  },
  {
    "CryptoDecrypt#3",
    c_modifier_public | c_modifier_final,
    bic_crypto_decrypt_method_CryptoDescrypt_3
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_crypto_decrypt_method_update_1
  },
  {
    "finalize#0",
    c_modifier_public | c_modifier_final,
    bic_crypto_decrypt_method_finalize_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_decrypt_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_decrypt_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_decrypt_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_decrypt_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_decrypt_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crypto_cipher_s *)nullptr;
}/*}}}*/

void bic_crypto_decrypt_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crypto_cipher_s *cc_ptr = (crypto_cipher_s *)location_ptr->v_data_ptr;

  // - if crypto decrypt object exists -
  if (cc_ptr != nullptr)
  {
    cc_ptr->clear(it);
    cfree(cc_ptr);
  }
}/*}}}*/

bool bic_crypto_decrypt_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crypto_decrypt_method_CryptoDescrypt_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_CONSTRUCTOR(Decrypt,"CryptoDecrypt#3");

  return true;
}/*}}}*/

bool bic_crypto_decrypt_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_UPDATE(Decrypt,"update#1");

  return true;
}/*}}}*/

bool bic_crypto_decrypt_method_finalize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CRYPTO_ENCRYPT_DECRYPT_METHOD_FINALIZE(Decrypt);

  return true;
}/*}}}*/

bool bic_crypto_decrypt_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CryptoDecrypt"),"CryptoDecrypt");
  );

  return true;
}/*}}}*/

bool bic_crypto_decrypt_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CryptoDecrypt");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

