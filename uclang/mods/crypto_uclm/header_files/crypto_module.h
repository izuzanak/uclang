
#ifndef __CRYPTO_MODULE_H
#define __CRYPTO_MODULE_H

@begin
include "ucl_crypto.h"
@end

// - CRYPTO indexes of built in classes -
extern unsigned c_bi_class_crypto;
extern unsigned c_bi_class_crypto_pkey;
extern unsigned c_bi_class_crypto_digest_info;
extern unsigned c_bi_class_crypto_digest;
extern unsigned c_bi_class_crypto_digest_sign;
extern unsigned c_bi_class_crypto_digest_verify;
extern unsigned c_bi_class_crypto_cipher_info;
extern unsigned c_bi_class_crypto_encrypt;
extern unsigned c_bi_class_crypto_decrypt;

// - CRYPTO module -
extern "C" IMPORT built_in_module_s module;

// - CRYPTO classes -
extern built_in_class_s *crypto_classes[];

// - CRYPTO error identifiers -
enum
{
  c_error_CRYPTO_INVALID_BASE_DATA_SIZE = 0,
  c_error_CRYPTO_INVALID_BASE_DATA,
  c_error_CRYPTO_PKEY_CANNOT_READ_KEY_FROM_FILE,
  c_error_CRYPTO_DIGEST_INVALID_ALGORITHM_NAME,
  c_error_CRYPTO_DIGEST_CREATE_INIT_ERROR,
  c_error_CRYPTO_DIGEST_UPDATE_ERROR,
  c_error_CRYPTO_DIGEST_VALUE_ERROR,
  c_error_CRYPTO_DIGEST_VERIFY_ERROR,
  c_error_CRYPTO_CIPHER_INVALID_ALGORITHM_NAME,
  c_error_CRYPTO_CIPHER_INVALID_KEY_LENGTH,
  c_error_CRYPTO_CIPHER_INVALID_INIT_VECTOR_LENGTH,
  c_error_CRYPTO_CIPHER_NEW_INIT_ERROR,
  c_error_CRYPTO_CIPHER_UPDATE_ERROR,
  c_error_CRYPTO_CIPHER_FINALIZE_ERROR,
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

// - class CRYPTO_PKEY -
extern built_in_variable_s crypto_pkey_variables[];
extern built_in_method_s crypto_pkey_methods[];
extern built_in_class_s crypto_pkey_class;

void bic_crypto_pkey_consts(location_array_s &const_locations);
void bic_crypto_pkey_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_pkey_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_pkey_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_pkey_method_load_private_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_pkey_method_load_public_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_pkey_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_pkey_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRYPTO_DIGEST_INFO -
extern built_in_variable_s crypto_digest_info_variables[];
extern built_in_method_s crypto_digest_info_methods[];
extern built_in_class_s crypto_digest_info_class;

void bic_crypto_digest_info_consts(location_array_s &const_locations);
void bic_crypto_digest_info_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_digest_info_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_digest_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_info_method_CryptoDigestInfo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_info_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

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

// - class CRYPTO_DIGEST_SIGN -
extern built_in_variable_s crypto_digest_sign_variables[];
extern built_in_method_s crypto_digest_sign_methods[];
extern built_in_class_s crypto_digest_sign_class;

void bic_crypto_digest_sign_consts(location_array_s &const_locations);
void bic_crypto_digest_sign_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_digest_sign_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_digest_sign_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_sign_method_CryptoDigestSign_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_sign_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_sign_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_sign_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_sign_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRYPTO_DIGEST_VERIFY -
extern built_in_variable_s crypto_digest_verify_variables[];
extern built_in_method_s crypto_digest_verify_methods[];
extern built_in_class_s crypto_digest_verify_class;

void bic_crypto_digest_verify_consts(location_array_s &const_locations);
void bic_crypto_digest_verify_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_digest_verify_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_digest_verify_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_verify_method_CryptoDigestVerify_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_verify_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_verify_method_verify_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_verify_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_digest_verify_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRYPTO_CIPHER_INFO -
extern built_in_variable_s crypto_cipher_info_variables[];
extern built_in_method_s crypto_cipher_info_methods[];
extern built_in_class_s crypto_cipher_info_class;

void bic_crypto_cipher_info_consts(location_array_s &const_locations);
void bic_crypto_cipher_info_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_cipher_info_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_cipher_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_CryptoCipherInfo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_block_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_key_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_iv_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_cipher_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRYPTO_ENCRYPT -
extern built_in_variable_s crypto_encrypt_variables[];
extern built_in_method_s crypto_encrypt_methods[];
extern built_in_class_s crypto_encrypt_class;

void bic_crypto_encrypt_consts(location_array_s &const_locations);
void bic_crypto_encrypt_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_encrypt_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_encrypt_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_encrypt_method_CryptoEncrypt_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_encrypt_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_encrypt_method_finalize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_encrypt_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_encrypt_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRYPTO_DECRYPT -
extern built_in_variable_s crypto_decrypt_variables[];
extern built_in_method_s crypto_decrypt_methods[];
extern built_in_class_s crypto_decrypt_class;

void bic_crypto_decrypt_consts(location_array_s &const_locations);
void bic_crypto_decrypt_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crypto_decrypt_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crypto_decrypt_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_decrypt_method_CryptoDescrypt_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_decrypt_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_decrypt_method_finalize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_decrypt_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crypto_decrypt_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

