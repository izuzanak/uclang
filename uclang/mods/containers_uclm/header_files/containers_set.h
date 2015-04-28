
#ifndef __CONTAINERS_SET_H
#define __CONTAINERS_SET_H

@begin
include "containers_module.h"
@end

// - class SET -
extern built_in_variable_s set_variables[];
extern built_in_method_s set_methods[];
extern built_in_class_s set_class;

void bic_set_consts(location_array_s &const_locations);
void bic_set_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_set_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_set_length(location_s *location_ptr);
location_s *bic_set_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_set_first_idx(location_s *location_ptr);
unsigned bic_set_next_idx(location_s *location_ptr,unsigned index);
bool bic_set_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_set_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_set_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_Set_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_Set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_insert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_set_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

