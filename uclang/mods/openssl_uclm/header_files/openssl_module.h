
#ifndef __OPENSSL_MODULE_H
#define __OPENSSL_MODULE_H

@begin
include "ucl_openssl.h"
@end

// - OPENSSL indexes of built in classes -
extern unsigned c_bi_class_ssl_context;

// - OPENSSL module -
extern "C" EXPORT built_in_module_s module;

// - OPENSSL classes -
extern built_in_class_s *openssl_classes[];

// - OPENSSL error identifiers -
enum
{
  c_error_OPENSSL_DUMMY_ERROR = 0,
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
bool bic_ssl_context_method_SSLContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_use_certificate_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_use_private_key_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssl_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

