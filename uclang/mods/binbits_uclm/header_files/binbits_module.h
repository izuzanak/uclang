
#ifndef __BINBITS_MODULE_H
#define __BINBITS_MODULE_H

@begin
include "ucl_binbits.h"
@end

// - BINBITS indexes of built in classes -
extern unsigned c_bi_class_bin_array;
extern unsigned c_bi_class_bin_array_ref;

// - BINBITS module -
extern built_in_module_s module;

// - BINBITS classes -
extern built_in_class_s *binbits_classes[];

// - BINBITS error identifiers -
enum
{
  c_error_BIN_ARRAY_DUMMY_ERROR = 0,
};

// - BINBITS error strings -
extern const char *binbits_error_strings[];

// - BINBITS initialize -
bool binbits_initialize(script_parser_s &sp);

// - BINBITS print exception -
bool binbits_print_exception(interpreter_s &it,exception_s &exception);

// - class BIN_ARRAY -
extern built_in_variable_s bin_array_variables[];
extern built_in_method_s bin_array_methods[];
extern built_in_class_s bin_array_class;

void bic_bin_array_consts(location_array_s &const_locations);
void bic_bin_array_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bin_array_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_bin_array_length(location_s *location_ptr);
location_s *bic_bin_array_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_bin_array_first_idx(location_s *location_ptr);
unsigned bic_bin_array_next_idx(location_s *location_ptr,unsigned index);

// FIXME TODO continue ...
//bool bic_bin_array_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
//bool bic_bin_array_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_bin_array_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_BinArray_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BIN_ARRAY_REF -
extern built_in_variable_s bin_array_ref_variables[];
extern built_in_method_s bin_array_ref_methods[];
extern built_in_class_s bin_array_ref_class;

void bic_bin_array_ref_consts(location_array_s &const_locations);
void bic_bin_array_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bin_array_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_bin_array_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_ref_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bin_array_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

