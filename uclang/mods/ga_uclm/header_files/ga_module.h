
#ifndef __GA_MODULE_H
#define __GA_MODULE_H

#define INSTANTIATE_REAL_GENOME

@begin
include "ucl_ga.h"
@end

// - GA indexes of built in classes -
extern unsigned c_bi_class_ga_real_genome;
extern unsigned c_bi_class_ga_tmp_real_genome;

// - GA module -
extern built_in_module_s module;

// - GA classes -
extern built_in_class_s *ga_classes[];

// - GA error identifiers -
enum
{
  c_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE = 0,
  c_error_GA_GENOME_NEGATIVE_LENGTH,
  c_error_GA_GENOME_INVALID_ALLELE_RANGE,
  c_error_GA_GENOME_WRONG_OBJECTIVE_DELEGATE,
  c_error_GA_GENERATION_COUNT_ZERO_OR_NEGATIVE,
  c_error_GA_POPULATION_SIZE_ZERO_OR_NEGATIVE,
  c_error_GA_MUTATION_PROBABILITY_RANGE_ERROR,
  c_error_GA_CROSSOVER_PROBABILITY_RANGE_ERROR,
};

// - GA error strings -
extern const char *ga_error_strings[];

// - GA initialize -
bool ga_initialize(script_parser_s &sp);

// - GA print exception -
bool ga_print_exception(interpreter_s &it,exception_s &exception);

// - class GA_REAL_GENOME -
extern built_in_variable_s ga_real_genome_variables[];
extern built_in_method_s ga_real_genome_methods[];
extern built_in_class_s ga_real_genome_class;

void bic_ga_real_genome_consts(location_array_s &const_locations);
void bic_ga_real_genome_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ga_real_genome_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ga_real_genome_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_real_genome_method_GaRealGenome_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_real_genome_method_evolve_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_real_genome_method_values_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_real_genome_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_real_genome_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GA_TMP_REAL_GENOME -
extern built_in_variable_s ga_tmp_real_genome_variables[];
extern built_in_method_s ga_tmp_real_genome_methods[];
extern built_in_class_s ga_tmp_real_genome_class;

void bic_ga_tmp_real_genome_consts(location_array_s &const_locations);
void bic_ga_tmp_real_genome_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ga_tmp_real_genome_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ga_tmp_real_genome_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_tmp_real_genome_method_values_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_tmp_real_genome_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_tmp_real_genome_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_tmp_real_genome_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ga_tmp_real_genome_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

