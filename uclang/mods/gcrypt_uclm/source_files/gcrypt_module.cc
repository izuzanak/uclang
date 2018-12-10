
@begin
include "gcrypt_module.h"
@end

// - GCRYPT indexes of built in classes -
unsigned c_bi_class_gcrypt_cipher = c_idx_not_exist;

// - GCRYPT module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  gcrypt_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  gcrypt_error_strings,   // Error strings

  gcrypt_initialize,      // Initialize function
  gcrypt_print_exception, // Print exceptions function
};/*}}}*/

// - GCRYPT classes -
built_in_class_s *gcrypt_classes[] =
{/*{{{*/
  &gcrypt_cipher_class,
};/*}}}*/

// - GCRYPT error strings -
const char *gcrypt_error_strings[] =
{/*{{{*/
  "error_GCRYPT_CIPHER_ERROR",
};/*}}}*/

// - GCRYPT initialize -
bool gcrypt_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gcrypt_cipher class identifier -
  c_bi_class_gcrypt_cipher = class_base_idx++;

  return true;
}/*}}}*/

// - GCRYPT print exception -
bool gcrypt_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GCRYPT_CIPHER_ERROR:
  {
    string_s &gcrypt_error = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGcrypt cipher error: %s\n",gcrypt_error.data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  }
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GCRYPT_CIPHER -
built_in_class_s gcrypt_cipher_class =
{/*{{{*/
  "GcryptCipher",
  c_modifier_public | c_modifier_final,
  8, gcrypt_cipher_methods,
  23 + 8 + 4, gcrypt_cipher_variables,
  bic_gcrypt_cipher_consts,
  bic_gcrypt_cipher_init,
  bic_gcrypt_cipher_clear,
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

built_in_method_s gcrypt_cipher_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gcrypt_cipher_operator_binary_equal
  },
  {
    "GcryptCipher#4",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gcrypt_cipher_method_GcryptCipher_4
  },
  {
    "setiv#1",
    c_modifier_public | c_modifier_final,
    bic_gcrypt_cipher_method_setiv_1
  },
  {
    "setctr#1",
    c_modifier_public | c_modifier_final,
    bic_gcrypt_cipher_method_setctr_1
  },
  {
    "encrypt#1",
    c_modifier_public | c_modifier_final,
    bic_gcrypt_cipher_method_encrypt_1
  },
  {
    "decrypt#1",
    c_modifier_public | c_modifier_final,
    bic_gcrypt_cipher_method_decrypt_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gcrypt_cipher_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gcrypt_cipher_method_print_0
  },
};/*}}}*/

built_in_variable_s gcrypt_cipher_variables[] =
{/*{{{*/

  // - cipher type -
  { "CIPHER_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_IDEA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_3DES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_CAST5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_BLOWFISH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_SAFER_SK128", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_DES_SK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_AES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_AES192", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_AES256", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_TWOFISH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_ARCFOUR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_DES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_TWOFISH128", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_SERPENT128", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_SERPENT192", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_SERPENT256", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_RFC2268_40", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_RFC2268_128", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_SEED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_CAMELLIA128", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_CAMELLIA192", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_CAMELLIA256", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - cipher mode -
  { "CIPHER_MODE_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_ECB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_CFB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_CBC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_STREAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_OFB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_CTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_MODE_AESWRAP", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - cipher open flags -
  { "CIPHER_SECURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_ENABLE_SYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_CBC_CTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CIPHER_CBC_MAC", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(ERR_CODE) \
/*{{{*/\
const char *error = gcry_strerror(ERR_CODE);\
\
string_s *error_ptr = it.get_new_string_ptr();\
error_ptr->set(strlen(error),error);\
\
BIC_CREATE_NEW_LOCATION_REFS(err_location,c_bi_class_string,error_ptr,0);\
/*}}}*/

void bic_gcrypt_cipher_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert cipher type constants -
  {
    const_locations.push_blanks(23);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 23);

#define CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_NONE);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_IDEA);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_3DES);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_CAST5);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_BLOWFISH);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_SAFER_SK128);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_DES_SK);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_AES);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_AES192);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_AES256);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_TWOFISH);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_ARCFOUR);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_DES);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_TWOFISH128);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_SERPENT128);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_SERPENT192);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_SERPENT256);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_RFC2268_40);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_RFC2268_128);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_SEED);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_CAMELLIA128);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_CAMELLIA192);
    CREATE_GCRYPT_CIPHER_TYPE_BIC_STATIC(GCRY_CIPHER_CAMELLIA256);
  }

  // - insert cipher mode constants -
  {
    const_locations.push_blanks(8);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 8);

#define CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_NONE);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_ECB);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_CFB);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_CBC);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_STREAM);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_OFB);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_CTR);
    CREATE_GCRYPT_CIPHER_MODE_BIC_STATIC(GCRY_CIPHER_MODE_AESWRAP);
  }

  // - insert cipher open flags -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_GCRYPT_CIPHER_OPEN_FLAGS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GCRYPT_CIPHER_OPEN_FLAGS_BIC_STATIC(GCRY_CIPHER_SECURE);
    CREATE_GCRYPT_CIPHER_OPEN_FLAGS_BIC_STATIC(GCRY_CIPHER_ENABLE_SYNC);
    CREATE_GCRYPT_CIPHER_OPEN_FLAGS_BIC_STATIC(GCRY_CIPHER_CBC_CTS);
    CREATE_GCRYPT_CIPHER_OPEN_FLAGS_BIC_STATIC(GCRY_CIPHER_CBC_MAC);
  }

}/*}}}*/

void bic_gcrypt_cipher_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gcrypt_cipher_s *)nullptr;
}/*}}}*/

void bic_gcrypt_cipher_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gcrypt_cipher_s *gc_ptr = (gcrypt_cipher_s *)location_ptr->v_data_ptr;

  // - if gcrypt cipher object exists -
  if (gc_ptr != nullptr)
  {
    gc_ptr->clear(it);
    cfree(gc_ptr);
  }
}/*}}}*/

bool bic_gcrypt_cipher_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_GcryptCipher_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
type:retrieve_integer
mode:retrieve_integer
flags:retrieve_integer
key:c_bi_class_string
>
method GcryptCipher
; @end

  // - create gcrypt cipher object -
  gcrypt_cipher_s *gc_ptr = (gcrypt_cipher_s *)cmalloc(sizeof(gcrypt_cipher_s));
  gc_ptr->init();

  // - ERROR -
  gcry_error_t err;
  if ((err = gcry_cipher_open(&gc_ptr->handle,type,mode,flags)) != 0)
  {
    gc_ptr->clear(it);
    cfree(gc_ptr);

    BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(err);
    exception_s::throw_exception(it,module.error_base + c_error_GCRYPT_CIPHER_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if ((err = gcry_cipher_setkey(gc_ptr->handle,string_ptr->data,string_ptr->size - 1)) != 0)
  {
    gc_ptr->clear(it);
    cfree(gc_ptr);

    BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(err);
    exception_s::throw_exception(it,module.error_base + c_error_GCRYPT_CIPHER_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  dst_location->v_data_ptr = (gcrypt_cipher_s *)gc_ptr;

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_setiv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
init_vector:c_bi_class_string
>
method setiv
; @end

  gcrypt_cipher_s *gc_ptr = (gcrypt_cipher_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  gcry_error_t err;
  if ((err = gcry_cipher_setiv(gc_ptr->handle,string_ptr->data,string_ptr->size - 1)) != 0)
  {
    BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(err);
    exception_s::throw_exception(it,module.error_base + c_error_GCRYPT_CIPHER_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_setctr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
counter_vector:c_bi_class_string
>
method setctr
; @end

  gcrypt_cipher_s *gc_ptr = (gcrypt_cipher_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  gcry_error_t err;
  if ((err = gcry_cipher_setctr(gc_ptr->handle,string_ptr->data,string_ptr->size - 1)) != 0)
  {
    BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(err);
    exception_s::throw_exception(it,module.error_base + c_error_GCRYPT_CIPHER_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_encrypt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method encrypt
; @end

  gcrypt_cipher_s *gc_ptr = (gcrypt_cipher_s *)dst_location->v_data_ptr;

  string_s *in_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *out_ptr = (string_s *)it.get_new_string_ptr();

  // - create target sring -
  out_ptr->create(in_ptr->size - 1);

  // - ERROR -
  gcry_error_t err;
  if ((err = gcry_cipher_encrypt(gc_ptr->handle,out_ptr->data,out_ptr->size - 1,in_ptr->data,in_ptr->size - 1)) != 0)
  {
    out_ptr->clear();
    cfree(out_ptr);

    BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(err);
    exception_s::throw_exception(it,module.error_base + c_error_GCRYPT_CIPHER_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_STRING(out_ptr);

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_decrypt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method decrypt
; @end

  gcrypt_cipher_s *gc_ptr = (gcrypt_cipher_s *)dst_location->v_data_ptr;

  string_s *in_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *out_ptr = (string_s *)it.get_new_string_ptr();

  // - create target sring -
  out_ptr->create(in_ptr->size - 1);

  // - ERROR -
  gcry_error_t err;
  if ((err = gcry_cipher_decrypt(gc_ptr->handle,out_ptr->data,out_ptr->size - 1,in_ptr->data,in_ptr->size - 1)) != 0)
  {
    out_ptr->clear();
    cfree(out_ptr);

    BIC_GCRYPT_CIPHER_CREATE_ERROR_STRING(err);
    exception_s::throw_exception(it,module.error_base + c_error_GCRYPT_CIPHER_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_STRING(out_ptr);

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GcryptCipher"),"GcryptCipher");
  );

  return true;
}/*}}}*/

bool bic_gcrypt_cipher_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GcryptCipher");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

