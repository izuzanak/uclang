
#ifndef __BINBITS_MODULE_H
#define __BINBITS_MODULE_H

@begin
include "ucl_binbits.h"
@end

// - BINBITS indexes of built in classes -
extern unsigned c_bi_class_bin_array;
extern unsigned c_bi_class_bin_array_ref;
extern unsigned c_bi_class_bin_dict;
extern unsigned c_bi_class_bin_dict_ref;

// - BINBITS module -
extern "C" EXPORT built_in_module_s module;

// - BINBITS classes -
extern built_in_class_s *binbits_classes[];

// - BINBITS error identifiers -
enum
{
  c_error_BIN_ARRAY_UNKNOWN_DATA_TYPE = 0,
  c_error_BIN_ARRAY_INDEX_EXCEEDS_RANGE,
  c_error_BIN_ARRAY_WRONG_RANGE_INDEXES,
  c_error_BIN_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE,
  c_error_BIN_ARRAY_NO_ELEMENTS,
  c_error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM,
  c_error_BIN_ARRAY_REF_INVALID_REFERENCE,
  c_error_BIN_DICT_UNKNOWN_DATA_TYPE,
  c_error_BIN_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,
  c_error_BIN_DICT_INVALID_KEY,
  c_error_BIN_DICT_REF_INVALID_REFERENCE,
};

// - BINBITS error strings -
extern const char *binbits_error_strings[];

// - BINBITS initialize -
bool binbits_initialize(script_parser_s &sp);

// - BINBITS print exception -
bool binbits_print_exception(interpreter_s &it,exception_s &exception);

// - class BIN_ARRAY -
extern built_in_variable_s bin_array_variables[];
extern built_in_method_s bin_array_methods[];
extern built_in_class_s bin_array_class;

void bic_bin_array_consts(location_array_s &const_locations);
void bic_bin_array_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bin_array_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_bin_array_length(location_s *location_ptr);
location_s *bic_bin_array_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_bin_array_first_idx(location_s *location_ptr);
unsigned bic_bin_array_next_idx(location_s *location_ptr,unsigned index);
bool bic_bin_array_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_bin_array_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_bin_array_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_BinArray_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_BinArray_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_last_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_head_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_tail_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BIN_ARRAY_REF -
extern built_in_variable_s bin_array_ref_variables[];
extern built_in_method_s bin_array_ref_methods[];
extern built_in_class_s bin_array_ref_class;

void bic_bin_array_ref_consts(location_array_s &const_locations);
void bic_bin_array_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bin_array_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_bin_array_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_ref_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BIN_DICT -
extern built_in_variable_s bin_dict_variables[];
extern built_in_method_s bin_dict_methods[];
extern built_in_class_s bin_dict_class;

void bic_bin_dict_consts(location_array_s &const_locations);
void bic_bin_dict_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bin_dict_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_bin_dict_length(location_s *location_ptr);
location_s *bic_bin_dict_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_bin_dict_first_idx(location_s *location_ptr);
unsigned bic_bin_dict_next_idx(location_s *location_ptr,unsigned index);
bool bic_bin_dict_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_bin_dict_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_bin_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_BinDict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_remove_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_first_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_last_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_next_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_prev_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_lee_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_gre_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BIN_DICT_REF -
extern built_in_variable_s bin_dict_ref_variables[];
extern built_in_method_s bin_dict_ref_methods[];
extern built_in_class_s bin_dict_ref_class;

void bic_bin_dict_ref_consts(location_array_s &const_locations);
void bic_bin_dict_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bin_dict_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_bin_dict_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_ref_method_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_ref_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_dict_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

