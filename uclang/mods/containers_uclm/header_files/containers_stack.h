
#ifndef __CONTAINERS_STACK_H
#define __CONTAINERS_STACK_H

@begin
include "containers_module.h"
@end

// - class STACK -
extern built_in_variable_s stack_variables[];
extern built_in_method_s stack_methods[];
extern built_in_class_s stack_class;

void bic_stack_consts(location_array_s &const_locations);
void bic_stack_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_stack_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_stack_length(location_s *location_ptr);
location_s *bic_stack_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_stack_first_idx(location_s *location_ptr);
unsigned bic_stack_next_idx(location_s *location_ptr,unsigned index);
bool bic_stack_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_stack_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_stack_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_Stack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_Stack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_stack_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

