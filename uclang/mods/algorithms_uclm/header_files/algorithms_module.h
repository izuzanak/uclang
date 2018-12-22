
#ifndef __ALGORITHMS_MODULE_H
#define __ALGORITHMS_MODULE_H

@begin
include "ucl_algorithms.h"
@end

// - ALGORITHMS indexes of built in classes -
extern unsigned c_bi_class_algo;
extern unsigned c_bi_class_filter;
extern unsigned c_bi_class_range;

// - ALGORITHMS module -
extern "C" IMPORT built_in_module_s module;

// - ALGORITHMS classes -
extern built_in_class_s *algorithms_classes[];

// - ALGORITHMS error identifiers -
enum
{
  c_error_ALGO_FILTER_WRONG_DELEGATE = 0,
  c_error_ALGO_FILTER_EXPECTED_INTEGER_AS_ARRAY_INDEX,
  c_error_ALGO_FILTER_INDEX_EXCEEDS_ARRAY_RANGE,
  c_error_ALGO_FILTER_UNDEFINED_DICTIONARY_KEY,
  c_error_RANGE_START_END_TYPES_DIFFERS,
};

// - ALGORITHMS error strings -
extern const char *algorithms_error_strings[];

// - ALGORITHMS initialize -
bool algorithms_initialize(script_parser_s &sp);

// - ALGORITHMS print exception -
bool algorithms_print_exception(interpreter_s &it,exception_s &exception);

// - class ALGO -
extern built_in_variable_s algo_variables[];
extern built_in_method_s algo_methods[];
extern built_in_class_s algo_class;

void bic_algo_consts(location_array_s &const_locations);
void bic_algo_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_algo_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_algo_method_all_true_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_any_true_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_map_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_reduce_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_filter_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_zip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_tuple_zip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FILTER -
extern built_in_variable_s filter_variables[];
extern built_in_method_s filter_methods[];
extern built_in_class_s filter_class;

void bic_filter_consts(location_array_s &const_locations);
void bic_filter_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_filter_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_filter_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_filter_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_filter_method_map_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_filter_method_filter_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_filter_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_filter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_filter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class RANGE -
extern built_in_variable_s range_variables[];
extern built_in_method_s range_methods[];
extern built_in_class_s range_class;

void bic_range_consts(location_array_s &const_locations);
void bic_range_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_range_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_range_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_range_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_Range_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_Range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_Range_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_range_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

