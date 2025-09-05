
@begin
include "openssl_module.h"
@end

// - OPENSSL indexes of built in classes -
unsigned c_bi_class_ssl_context = c_idx_not_exist;
unsigned c_bi_class_ssl_conn = c_idx_not_exist;

// - OPENSSL module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                       // Class count
  openssl_classes,         // Classes

  0,                       // Error base index
  11,                       // Error count
  openssl_error_strings,   // Error strings

  openssl_initialize,      // Initialize function
  openssl_print_exception, // Print exceptions function
};/*}}}*/

// - OPENSSL classes -
built_in_class_s *openssl_classes[] =
{/*{{{*/
  &ssl_context_class,
  &ssl_conn_class,
};/*}}}*/

// - OPENSSL error strings -
const char *openssl_error_strings[] =
{/*{{{*/
  "error_SSL_CONTEXT_INVALID_METHOD_TYPE",
  "error_SSL_CONTEXT_CREATE_ERROR",
  "error_SSL_CONTEXT_CERTIFICATE_FILE_ERROR",
  "error_SSL_CONTEXT_PRIVATE_KEY_FILE_ERROR",
  "error_SSL_CONN_CREATE_ERROR",
  "error_SSL_CONN_ACCEPT_ERROR",
  "error_SSL_CONN_CONNECT_ERROR",
  "error_SSL_CONN_WRITE_ERROR",
  "error_SSL_CONN_READ_ERROR",
  "error_SSL_CONN_READ_NEGATIVE_BYTE_COUNT",
  "error_SSL_CONN_INCORRECT_BIO_TYPE",
};/*}}}*/

// - OPENSSL initialize -
bool openssl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ssl_context class identifier -
  c_bi_class_ssl_context = class_base_idx++;

  // - initialize ssl_conn class identifier -
  c_bi_class_ssl_conn = class_base_idx++;

  return true;
}/*}}}*/

// - OPENSSL print exception -
bool openssl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_SSL_CONTEXT_INVALID_METHOD_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSL context, invalid method type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create new SSL context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONTEXT_CERTIFICATE_FILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSL context, cannot read certificate from file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONTEXT_PRIVATE_KEY_FILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSL context, cannot read private key from file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create new SSL connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_ACCEPT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSL connection, cannot accept connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_CONNECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSSL connection, cannot connect to host\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to SSL connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from SSL connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_READ_NEGATIVE_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read %" HOST_LL_FORMAT "d bytes from ssl connection\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SSL_CONN_INCORRECT_BIO_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIncorrect SSL connection BIO type\n");
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
  "SslContext",
  c_modifier_public | c_modifier_final,
  9, ssl_context_methods,
  2 + 2, ssl_context_variables,
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
    "SslContext#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_SslContext_1
  },
  {
    "use_certificate_file#2",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_use_certificate_file_2
  },
  {
    "use_private_key_file#2",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_use_private_key_file_2
  },
  {
    "check_private_key#0",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_check_private_key_0
  },
  {
    "accept#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_accept_1
  },
  {
    "connect#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_context_method_connect_1
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

  // - ssl file type -
  { "SSL_FILETYPE_PEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SSL_FILETYPE_ASN1", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_ssl_context_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert ssl context method type -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_SSL_CONTECT_METHOD_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SSL_CONTECT_METHOD_TYPE_BIC_STATIC(c_ssl_ctx_method_server);
    CREATE_SSL_CONTECT_METHOD_TYPE_BIC_STATIC(c_ssl_ctx_method_client);
  }

  // - insert ssl file type -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_SSL_FILE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SSL_FILE_TYPE_BIC_STATIC(SSL_FILETYPE_PEM);
    CREATE_SSL_FILE_TYPE_BIC_STATIC(SSL_FILETYPE_ASN1);
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

bool bic_ssl_context_method_SslContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
method_type:retrieve_integer
>
method SslContext
; @end

  const SSL_METHOD *method = nullptr;

  // - retrieve ssl method -
  switch (method_type)
  {
  case c_ssl_ctx_method_server:
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
    method = TLS_server_method();
#else
    method = TLSv1_2_server_method();
#endif
    break;
  case c_ssl_ctx_method_client:
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
    method = TLS_client_method();
#else
    method = TLSv1_2_client_method();
#endif
    break;
  }

  // - ERROR -
  if (method == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONTEXT_INVALID_METHOD_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  SSL_CTX *sc_ptr = SSL_CTX_new(method);

  // - ERROR -
  if (sc_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (SSL_CTX *)sc_ptr;

  return true;
}/*}}}*/

bool bic_ssl_context_method_use_certificate_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
file_name:c_bi_class_string
file_type:retrieve_integer
>
method use_certificate_file
; @end

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (SSL_CTX_use_certificate_file(sc_ptr,string_ptr->data,file_type) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONTEXT_CERTIFICATE_FILE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ssl_context_method_use_private_key_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
file_name:c_bi_class_string
file_type:retrieve_integer
>
method use_private_key_file
; @end

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (SSL_CTX_use_PrivateKey_file(sc_ptr,string_ptr->data,file_type) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONTEXT_PRIVATE_KEY_FILE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ssl_context_method_check_private_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;

  long long int result = SSL_CTX_check_private_key(sc_ptr) != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ssl_context_method_accept_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
>
method accept
; @end

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;

  SSL *ssl_ptr = SSL_new(sc_ptr);

  // - ERROR -
  if (ssl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_set_fd(ssl_ptr,fd) != 1)
  {
    SSL_free(ssl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_accept(ssl_ptr) != 1)
  {
    SSL_free(ssl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ssl_conn,ssl_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ssl_context_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
>
method connect
; @end

  SSL_CTX *sc_ptr = (SSL_CTX *)dst_location->v_data_ptr;

  SSL *ssl_ptr = SSL_new(sc_ptr);

  // - ERROR -
  if (ssl_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_set_fd(ssl_ptr,fd) != 1)
  {
    SSL_free(ssl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (SSL_connect(ssl_ptr) != 1)
  {
    SSL_free(ssl_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_CONNECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ssl_conn,ssl_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ssl_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SslContext"),"SslContext");
  );

  return true;
}/*}}}*/

bool bic_ssl_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("SslContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SSL_CONN -
built_in_class_s ssl_conn_class =
{/*{{{*/
  "SslConn",
  c_modifier_public | c_modifier_final,
  7, ssl_conn_methods,
  0, ssl_conn_variables,
  bic_ssl_conn_consts,
  bic_ssl_conn_init,
  bic_ssl_conn_clear,
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

built_in_method_s ssl_conn_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_conn_operator_binary_equal
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_conn_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_ssl_conn_method_read_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_ssl_conn_method_read_1
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_ssl_conn_method_get_fd_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssl_conn_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ssl_conn_method_print_0
  },
};/*}}}*/

built_in_variable_s ssl_conn_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ssl_conn_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ssl_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SSL *)nullptr;
}/*}}}*/

void bic_ssl_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  SSL *ssl_ptr = (SSL *)location_ptr->v_data_ptr;

  // - if ssl connection exists -
  if (ssl_ptr != nullptr)
  {
    SSL_free(ssl_ptr);
  }
}/*}}}*/

bool bic_ssl_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ssl_conn_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write
; @end

  SSL *ssl_ptr = (SSL *)dst_location->v_data_ptr;

  if (data_size > 0)
  {
    int cnt;
    unsigned writed = 0;

    do
    {
      // - ERROR -
      if ((cnt = SSL_write(ssl_ptr,(const char *)data_ptr + writed,data_size - writed)) <= 0)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    while((writed += cnt) < data_size);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ssl_conn_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SSL *ssl_ptr = (SSL *)dst_location->v_data_ptr;

  const long int c_buffer_add = 4096;

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  int read_cnt;
  do
  {
    data_buffer.reserve(c_buffer_add);
    read_cnt = SSL_read(ssl_ptr,data_buffer.data + data_buffer.used,c_buffer_add);

    // - ERROR -
    if (read_cnt <= 0)
    {
      if (SSL_get_error(ssl_ptr,read_cnt) != SSL_ERROR_ZERO_RETURN)
      {
        break;
      }
      else
      {
        data_buffer.clear();

        exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }

    data_buffer.used += read_cnt;
  }
  while(SSL_pending(ssl_ptr) > 0);

  // - was any data read -
  if (data_buffer.used == 0)
  {
    data_buffer.clear();

    BIC_SET_RESULT_BLANK();
  }
  else
  {
    data_buffer.push('\0');

    // - return data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = data_buffer.data;
    string_ptr->size = data_buffer.used;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    BIC_SET_RESULT(new_location);
  }

  return true;
}/*}}}*/

bool bic_ssl_conn_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
byte_cnt:retrieve_integer
>
method read
; @end

  SSL *ssl_ptr = (SSL *)dst_location->v_data_ptr;

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data string -
  string_s data_string;
  data_string.init();
  data_string.create(byte_cnt);

  unsigned readed = 0;
  int read_cnt;

  do
  {
    read_cnt = SSL_read(ssl_ptr,data_string.data + readed,byte_cnt - readed);

    // - ERROR -
    if (read_cnt <= 0)
    {
      data_string.clear();

      exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    readed += read_cnt;
  }
  while(readed < byte_cnt);

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->swap(data_string);
  data_string.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ssl_conn_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SSL *ssl_ptr = (SSL *)dst_location->v_data_ptr;

  long long int result = SSL_get_fd(ssl_ptr);

  // - ERROR -
  if (result < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SSL_CONN_INCORRECT_BIO_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ssl_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SslConn"),"SslConn");
  );

  return true;
}/*}}}*/

bool bic_ssl_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("SslConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

