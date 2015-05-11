
#ifndef __ALGORITHMS_MODULE_H
#define __ALGORITHMS_MODULE_H

@begin
include "ucl_algorithms.h"
@end

// - ALGORITHMS indexes of built in classes -
extern unsigned c_bi_class_algo;

// - ALGORITHMS module -
extern built_in_module_s module;

// - ALGORITHMS classes -
extern built_in_class_s *algorithms_classes[];

// - ALGORITHMS error identifiers -
enum
{
  c_error_ALGO_WRONG_DELEGATE = 0,
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
bool bic_algo_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_algo_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

