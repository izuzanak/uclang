
#ifndef __CONTAINERS_TREE_H
#define __CONTAINERS_TREE_H

@begin
include "containers_module.h"
@end

// - class TREE -
extern built_in_variable_s tree_variables[];
extern built_in_method_s tree_methods[];
extern built_in_class_s tree_class;

void bic_tree_consts(location_array_s &const_locations);
void bic_tree_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_tree_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_tree_length(location_s *location_ptr);
location_s *bic_tree_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_tree_first_idx(location_s *location_ptr);
unsigned bic_tree_next_idx(location_s *location_ptr,unsigned index);
bool bic_tree_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_tree_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_tree_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_Tree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_Tree_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_insert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_tree_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

