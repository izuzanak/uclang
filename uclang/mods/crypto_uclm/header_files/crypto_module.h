
#ifndef __CRYPTO_MODULE_H
#define __CRYPTO_MODULE_H

@begin
include "ucl_crypto.h"
@end

// - CRYPTO indexes of built in classes -
extern unsigned c_bi_class_crypto;

// - CRYPTO module -
extern built_in_module_s module;

// - CRYPTO classes -
extern built_in_class_s *crypto_classes[];

// - CRYPTO error identifiers -
enum
{
  c_error_CRYPTO_INVALID_BASE_DATA_SIZE = 0,
  c_error_CRYPTO_INVALID_BASE_DATA,
  c_error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME,
  c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR,
  c_error_CRYPTO_DIGEST_UPDATE_ERROR,
  c_error_CRYPTO_DIGEST_VALUE_ERROR,
};

// - CRYPTO error strings -
extern const char *crypto_error_strings[];

// - CRYPTO initialize -
bool crypto_initialize(script_parser_s &sp);

// - CRYPTO print exception -
bool crypto_print_exception(interpreter_s &it,exception_s &exception);

// - class CRYPTO -
extern built_in_variable_s crypto_variables[];
extern built_in_method_s crypto_methods[];
extern built_in_class_s crypto_class;

void bic_crypto_consts(location_array_s &const_locations);
void bic_crypto_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_method_random_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_method_encode_base16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_method_decode_base16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_method_encode_base64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_method_decode_base64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRYPTO_DIGEST -
extern built_in_variable_s crypto_digest_variables[];
extern built_in_method_s crypto_digest_methods[];
extern built_in_class_s crypto_digest_class;

void bic_crypto_digest_consts(location_array_s &const_locations);
void bic_crypto_digest_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_digest_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_digest_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_method_CryptoDigest_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

