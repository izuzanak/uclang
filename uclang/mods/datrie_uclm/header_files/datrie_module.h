
#ifndef __DATRIE_MODULE_H
#define __DATRIE_MODULE_H

@begin
include "ucl_datrie.h"
@end

// - DATRIE indexes of built in classes -
extern unsigned c_bi_class_datrie_alpha_map;
extern unsigned c_bi_class_datrie;

// - DATRIE module -
extern built_in_module_s module;

// - DATRIE classes -
extern built_in_class_s *datrie_classes[];

// - DATRIE error identifiers -
enum
{
  c_error_DATRIE_ALPHA_MAP_CREATE_ERROR = 0,
  c_error_DATRIE_ALPHA_MAP_ADD_RANGE_ERROR,
  c_error_DATRIE_CREATE_ERROR,
  c_error_DATRIE_STORE_ERROR,
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
bool bic_datrie_method_Datrie_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_store_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_retrieve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_datrie_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

