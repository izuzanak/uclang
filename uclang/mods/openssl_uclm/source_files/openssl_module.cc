
@begin
include "openssl_module.h"
@end

// - OPENSSL indexes of built in classes -
unsigned c_bi_class_ssl_context = c_idx_not_exist;

// - OPENSSL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                       // Class count
  openssl_classes,         // Classes

  0,                       // Error base index
  1,                       // Error count
  openssl_error_strings,   // Error strings

  openssl_initialize,      // Initialize function
  openssl_print_exception, // Print exceptions function
};/*}}}*/

// - OPENSSL classes -
built_in_class_s *openssl_classes[] =
{/*{{{*/
  &ssl_context_class,
};/*}}}*/

// - OPENSSL error strings -
const char *openssl_error_strings[] =
{/*{{{*/
  "error_OPENSSL_DUMMY_ERROR",
};/*}}}*/

// - OPENSSL initialize -
bool openssl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ssl_context class identifier -
  c_bi_class_ssl_context = class_base_idx++;

  return true;
}/*}}}*/

// - OPENSSL print exception -
bool openssl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_OPENSSL_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid base%" HOST_LL_FORMAT "d encoded data size\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SSL_CONTEXT -
built_in_class_s ssl_context_class =
{/*{{{*/
  "SSLContext",
  c_modifier_public | c_modifier_final,
  6, ssl_context_methods,
  2, ssl_context_variables,
  bic_ssl_context_consts,
  bic_ssl_context_init,
  bic_ssl_context_clear,
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

built_in_method_s ssl_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_operator_binary_equal
  },
  {
    "SSLContext#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_SSLContext_1
  },
  {
    "use_certificate_file#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_use_certificate_file_1
  },
  {
    "use_private_key_file#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_use_private_key_file_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssl_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssl_context_method_print_0
  },
};/*}}}*/

built_in_variable_s ssl_context_variables[] =
{/*{{{*/

  // - ssl context method type -
  { "METHOD_SERVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "METHOD_CLIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_ssl_context_consts(location_array_s &const_locations)
{/*{{{*/

  // - ssl context method type -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(c_ssl_ctx_method_server);
    CREATE_CRYPTO_PKEY_TYPE_BIC_STATIC(c_ssl_ctx_method_client);
  }

}/*}}}*/

void bic_ssl_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SSL_CTX *)nullptr;
}/*}}}*/

void bic_ssl_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  SSL_CTX *sc_ptr = (SSL_CTX *)location_ptr->v_data_ptr;

  // - if ssl context exists -
  if (sc_ptr != nullptr)
  {
    SSL_CTX_free(sc_ptr);
  }
}/*}}}*/

bool bic_ssl_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ssl_context_method_SSLContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
method_type:retrieve_integer
>
method SSLContext
; @end

  const SSL_METHOD *method = nullptr;

  // - retrieve ssl method -
  switch (method_type)
  {
  case c_ssl_ctx_method_server:
    method = TLS_server_method();
    break;
  case c_ssl_ctx_method_client:
    method = TLS_client_method();
    break;
  }

  // - ERROR -
  if (method == nullptr)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  SSL_CTX *sc_ptr = SSL_CTX_new(method);

  // - ERROR -
  if (sc_ptr == nullptr)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  dst_location->v_data_ptr = (SSL_CTX *)sc_ptr;

  return true;
}/*}}}*/

bool bic_ssl_context_method_use_certificate_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
file_name:c_bi_class_string
>
method use_certificate_file
; @end

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (SSL_CTX_use_certificate_file(sc_ptr,string_ptr->data,SSL_FILETYPE_PEM) != 1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ssl_context_method_use_private_key_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
file_name:c_bi_class_string
>
method use_private_key_file
; @end

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (SSL_CTX_use_PrivateKey_file(sc_ptr,string_ptr->data,SSL_FILETYPE_PEM) != 1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ssl_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SSLContext"),"SSLContext");
  );

  return true;
}/*}}}*/

bool bic_ssl_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("SSLContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

