
#ifndef __CONTAINERS_QUEUE_H
#define __CONTAINERS_QUEUE_H

@begin
include "containers_module.h"
@end

// - class QUEUE -
extern built_in_variable_s queue_variables[];
extern built_in_method_s queue_methods[];
extern built_in_class_s queue_class;

void bic_queue_consts(location_array_s &const_locations);
void bic_queue_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_queue_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_queue_length(location_s *location_ptr);
location_s *bic_queue_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_queue_first_idx(location_s *location_ptr);
unsigned bic_queue_next_idx(location_s *location_ptr,unsigned index);
bool bic_queue_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_queue_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_Queue_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_Queue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_insert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_insert_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_next_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

