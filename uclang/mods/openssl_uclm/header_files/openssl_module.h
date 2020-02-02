
#ifndef __OPENSSL_MODULE_H
#define __OPENSSL_MODULE_H

@begin
include "ucl_openssl.h"
@end

// - OPENSSL indexes of built in classes -
extern unsigned c_bi_class_ssl_context;
extern unsigned c_bi_class_ssl_conn;

// - OPENSSL module -
extern "C" EXPORT built_in_module_s module;

// - OPENSSL classes -
extern built_in_class_s *openssl_classes[];

// - OPENSSL error identifiers -
enum
{
  c_error_SSL_CONTEXT_INVALID_METHOD_TYPE = 0,
  c_error_SSL_CONTEXT_CREATE_ERROR,
  c_error_SSL_CONTEXT_CERTIFICATE_FILE_ERRROR,
  c_error_SSL_CONTEXT_PRIVATE_KEY_FILE_ERRROR,
  c_error_SSL_CONN_CREATE_ERROR,
  c_error_SSL_CONN_ACCEPT_ERROR,
  c_error_SSL_CONN_CONNECT_ERROR,
  c_error_SSL_CONN_WRITE_ERROR,
  c_error_SSL_CONN_READ_ERROR,
  c_error_SSL_CONN_READ_NEGATIVE_BYTE_COUNT,
  c_error_SSL_CONN_INCORRECT_BIO_TYPE,
};

// - OPENSSL error strings -
extern const char *openssl_error_strings[];

// - OPENSSL initialize -
bool openssl_initialize(script_parser_s &sp);

// - OPENSSL print exception -
bool openssl_print_exception(interpreter_s &it,exception_s &exception);

// - class SSL_CONTEXT -
extern built_in_variable_s ssl_context_variables[];
extern built_in_method_s ssl_context_methods[];
extern built_in_class_s ssl_context_class;

void bic_ssl_context_consts(location_array_s &const_locations);
void bic_ssl_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ssl_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ssl_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_SslContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_use_certificate_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_use_private_key_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_check_private_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_accept_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SSL_CONN -
extern built_in_variable_s ssl_conn_variables[];
extern built_in_method_s ssl_conn_methods[];
extern built_in_class_s ssl_conn_class;

void bic_ssl_conn_consts(location_array_s &const_locations);
void bic_ssl_conn_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ssl_conn_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ssl_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_conn_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_conn_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_conn_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_conn_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

