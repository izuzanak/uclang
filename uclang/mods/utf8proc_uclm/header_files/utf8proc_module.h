
#ifndef __UTF8PROC_MODULE_H
#define __UTF8PROC_MODULE_H

@begin
include "ucl_utf8proc.h"
@end

// - UTF8PROC indexes of built in classes -
extern unsigned c_bi_class_utf8proc;
extern unsigned c_bi_class_unicode_char;
extern unsigned c_bi_class_unicode_string;

// - UTF8PROC module -
extern "C" IMPORT built_in_module_s module;

// - UTF8PROC classes -
extern built_in_class_s *utf8proc_classes[];

// - UTF8PROC error identifiers -
enum
{
  c_error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT = 0,
  c_error_UNICODE_CHAR_INVALID_CODE_POINT,
  c_error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR,
  c_error_UNICODE_STRING_UTF8_CREATE_ERROR,
  c_error_UNICODE_STRING_INDEX_EXCEEDS_RANGE,
  c_error_UNICODE_STRING_WRONG_RANGE_INDEXES,
};

// - UTF8PROC error strings -
extern const char *utf8proc_error_strings[];

// - UTF8PROC initialize -
bool utf8proc_initialize(script_parser_s &sp);

// - UTF8PROC print exception -
bool utf8proc_print_exception(interpreter_s &it,exception_s &exception);

// - class UTF8PROC -
extern built_in_variable_s utf8proc_variables[];
extern built_in_method_s utf8proc_methods[];
extern built_in_class_s utf8proc_class;

void bic_utf8proc_consts(location_array_s &const_locations);
void bic_utf8proc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_utf8proc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_utf8proc_method_to_lower_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_to_upper_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class UNICODE_CHAR -
extern built_in_variable_s unicode_char_variables[];
extern built_in_method_s unicode_char_methods[];
extern built_in_class_s unicode_char_class;

void bic_unicode_char_consts(location_array_s &const_locations);
void bic_unicode_char_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_unicode_char_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_unicode_char_compare(location_s *first_loc,location_s *second_loc);

bool bic_unicode_char_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_UnicodeChar_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_UnicodeChar_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_to_lower_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_to_upper_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_char_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class UNICODE_STRING -
extern built_in_variable_s unicode_string_variables[];
extern built_in_method_s unicode_string_methods[];
extern built_in_class_s unicode_string_class;

void bic_unicode_string_consts(location_array_s &const_locations);
void bic_unicode_string_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_unicode_string_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_unicode_string_compare(location_s *first_loc,location_s *second_loc);
unsigned bic_unicode_string_length(location_s *location_ptr);
location_s *bic_unicode_string_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_unicode_string_first_idx(location_s *location_ptr);
unsigned bic_unicode_string_next_idx(location_s *location_ptr,unsigned index);
location_s *bic_unicode_string_from_slice(interpreter_thread_s &it,location_s *location_ptr,pointer_array_s &slice_array);

bool bic_unicode_string_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_UnicodeString_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_to_lower_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_to_upper_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_head_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_tail_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_unicode_string_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

