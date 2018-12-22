
#ifndef __DATRIE_MODULE_H
#define __DATRIE_MODULE_H

@begin
include "ucl_datrie.h"
@end

// - DATRIE indexes of built in classes -
extern unsigned c_bi_class_datrie_alpha_map;
extern unsigned c_bi_class_datrie;
extern unsigned c_bi_class_datrie_iterator;

// - DATRIE module -
extern "C" IMPORT built_in_module_s module;

// - DATRIE classes -
extern built_in_class_s *datrie_classes[];

// - DATRIE error identifiers -
enum
{
  c_error_DATRIE_ALPHA_MAP_CREATE_ERROR = 0,
  c_error_DATRIE_ALPHA_MAP_ADD_RANGE_ERROR,
  c_error_DATRIE_CREATE_ERROR,
  c_error_DATRIE_STORE_ERROR,
  c_error_DATRIE_RETRIEVE_ERROR,
  c_error_DATRIE_INVALID_KEY,
  c_error_DATRIE_INVALID_KEY_TYPE,
  c_error_DATRIE_SOURCE_NOT_DIVISIBLE_BY_TWO,
  c_error_DATRIE_ITERATOR_CREATE_ERROR,
};

// - DATRIE error strings -
extern const char *datrie_error_strings[];

// - DATRIE initialize -
bool datrie_initialize(script_parser_s &sp);

// - DATRIE print exception -
bool datrie_print_exception(interpreter_s &it,exception_s &exception);

// - class DATRIE_ALPHA_MAP -
extern built_in_variable_s datrie_alpha_map_variables[];
extern built_in_method_s datrie_alpha_map_methods[];
extern built_in_class_s datrie_alpha_map_class;

void bic_datrie_alpha_map_consts(location_array_s &const_locations);
void bic_datrie_alpha_map_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_datrie_alpha_map_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_datrie_alpha_map_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_alpha_map_method_DatrieAlphaMap_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_alpha_map_method_add_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_alpha_map_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_alpha_map_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DATRIE -
extern built_in_variable_s datrie_variables[];
extern built_in_method_s datrie_methods[];
extern built_in_class_s datrie_class;

void bic_datrie_consts(location_array_s &const_locations);
void bic_datrie_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_datrie_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_datrie_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_Datrie_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_Datrie_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_iterator_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_remove_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_datrie_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DATRIE_ITERATOR -
extern built_in_variable_s datrie_iterator_variables[];
extern built_in_method_s datrie_iterator_methods[];
extern built_in_class_s datrie_iterator_class;

void bic_datrie_iterator_consts(location_array_s &const_locations);
void bic_datrie_iterator_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_datrie_iterator_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_datrie_iterator_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_iterator_method_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_iterator_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_iterator_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_iterator_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_iterator_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

