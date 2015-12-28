
#ifndef __CONTAINERS_LIST_H
#define __CONTAINERS_LIST_H

@begin
include "containers_module.h"
@end

// - class LIST -
extern built_in_variable_s list_variables[];
extern built_in_method_s list_methods[];
extern built_in_class_s list_class;

void bic_list_consts(location_array_s &const_locations);
void bic_list_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_list_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_list_length(location_s *location_ptr);
location_s *bic_list_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_list_first_idx(location_s *location_ptr);
unsigned bic_list_next_idx(location_s *location_ptr,unsigned index);
bool bic_list_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_list_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_list_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_List_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_List_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_append_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_prepend_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_prepend_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_insert_before_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_insert_before_ref_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_insert_after_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_insert_after_ref_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_has_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_list_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

