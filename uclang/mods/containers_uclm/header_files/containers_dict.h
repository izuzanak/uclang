
#ifndef __CONTAINERS_DICT_H
#define __CONTAINERS_DICT_H

@begin
include "containers_module.h"
@end

// - class DICT -
extern built_in_variable_s dict_variables[];
extern built_in_method_s dict_methods[];
extern built_in_class_s dict_class;

void bic_dict_consts(location_array_s &const_locations);
void bic_dict_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_dict_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_dict_length(location_s *location_ptr);
location_s *bic_dict_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_dict_first_idx(location_s *location_ptr);
unsigned bic_dict_next_idx(location_s *location_ptr,unsigned index);
bool bic_dict_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_dict_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_Dict_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_Dict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_store_ref_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_remove_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_first_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_next_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_lee_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_gre_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

