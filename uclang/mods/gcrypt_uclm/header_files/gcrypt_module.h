
#ifndef __GCRYPT_MODULE_H
#define __GCRYPT_MODULE_H

@begin
include "ucl_gcrypt.h"
@end

// - GCRYPT indexes of built in classes -
extern unsigned c_bi_class_gcrypt_cipher;

// - GCRYPT module -
extern built_in_module_s module;

// - GCRYPT classes -
extern built_in_class_s *gcrypt_classes[];

// - GCRYPT error identifiers -
enum
{
  c_error_GCRYPT_CIPHER_ERROR = 0,
};

// - GCRYPT error strings -
extern const char *gcrypt_error_strings[];

// - GCRYPT initialize -
bool gcrypt_initialize(script_parser_s &sp);

// - GCRYPT print exception -
bool gcrypt_print_exception(interpreter_s &it,exception_s &exception);

// - class GCRYPT_CIPHER -
extern built_in_variable_s gcrypt_cipher_variables[];
extern built_in_method_s gcrypt_cipher_methods[];
extern built_in_class_s gcrypt_cipher_class;

void bic_gcrypt_cipher_consts(location_array_s &const_locations);
void bic_gcrypt_cipher_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gcrypt_cipher_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gcrypt_cipher_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_GcryptCipher_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_setiv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_setctr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_encrypt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_decrypt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcrypt_cipher_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

