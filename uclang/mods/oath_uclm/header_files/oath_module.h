
#ifndef __OATH_MODULE_H
#define __OATH_MODULE_H

@begin
include "ucl_oath.h"
@end

// - OATH indexes of built in classes -
extern unsigned c_bi_class_oath;
extern unsigned c_bi_class_oath_hotp;
extern unsigned c_bi_class_oath_totp;

// - OATH module -
extern "C" EXPORT built_in_module_s module;

// - OATH classes -
extern built_in_class_s *oath_classes[];

// - OATH error identifiers -
enum
{
  // - liboath return codes, order must match oath_rc -
  c_error_OATH_CRYPTO_ERROR = 0,
  c_error_OATH_INVALID_DIGITS,
  c_error_OATH_PRINTF_ERROR,
  c_error_OATH_INVALID_HEX,
  c_error_OATH_TOO_SMALL_BUFFER,
  c_error_OATH_INVALID_OTP,
  c_error_OATH_REPLAYED_OTP,
  c_error_OATH_BAD_PASSWORD,
  c_error_OATH_INVALID_COUNTER,
  c_error_OATH_INVALID_TIMESTAMP,
  c_error_OATH_NO_SUCH_FILE,
  c_error_OATH_UNKNOWN_USER,
  c_error_OATH_FILE_SEEK_ERROR,
  c_error_OATH_FILE_CREATE_ERROR,
  c_error_OATH_FILE_LOCK_ERROR,
  c_error_OATH_FILE_RENAME_ERROR,
  c_error_OATH_FILE_UNLINK_ERROR,
  c_error_OATH_TIME_ERROR,
  c_error_OATH_STRCMP_ERROR,
  c_error_OATH_INVALID_BASE32,
  c_error_OATH_BASE32_OVERFLOW,
  c_error_OATH_MALLOC_ERROR,
  c_error_OATH_FILE_FLUSH_ERROR,
  c_error_OATH_FILE_SYNC_ERROR,
  c_error_OATH_FILE_CLOSE_ERROR,
  c_error_OATH_FILE_CHOWN_ERROR,
  c_error_OATH_FILE_STAT_ERROR,

  // - module errors -
  c_error_OATH_INVALID_ARGUMENT,
};

// - OATH error strings -
extern const char *oath_error_strings[];

// - OATH initialize -
bool oath_initialize(script_parser_s &sp);

// - OATH print exception -
bool oath_print_exception(interpreter_s &it,exception_s &exception);

// - class OATH -
extern built_in_variable_s oath_variables[];
extern built_in_method_s oath_methods[];
extern built_in_class_s oath_class;

void bic_oath_consts(location_array_s &const_locations);
void bic_oath_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_oath_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_oath_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_check_version_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_base32_encode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_base32_decode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_hex2bin_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_bin2hex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class OATH_HOTP -
extern built_in_variable_s oath_hotp_variables[];
extern built_in_method_s oath_hotp_methods[];
extern built_in_class_s oath_hotp_class;

void bic_oath_hotp_consts(location_array_s &const_locations);
void bic_oath_hotp_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_oath_hotp_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_oath_hotp_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_OathHotp_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_OathHotp_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_generate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_validate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_secret_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_digits_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_add_checksum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_truncation_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_hotp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class OATH_TOTP -
extern built_in_variable_s oath_totp_variables[];
extern built_in_method_s oath_totp_methods[];
extern built_in_class_s oath_totp_class;

void bic_oath_totp_consts(location_array_s &const_locations);
void bic_oath_totp_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_oath_totp_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_oath_totp_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_OathTotp_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_OathTotp_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_generate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_validate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_secret_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_digits_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_time_step_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_start_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_flags_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_oath_totp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

