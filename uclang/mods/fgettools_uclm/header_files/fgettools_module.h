
#ifndef __FGETTOOLS_MODULE_H
#define __FGETTOOLS_MODULE_H

@begin
include "ucl_fgettools.h"
@end

// - FGETTOOLS indexes of built in classes -
extern unsigned c_bi_class_fget_target;

// - FGETTOOLS module -
extern built_in_module_s module;

// - FGETTOOLS classes -
extern built_in_class_s *fgettools_classes[];

// - FGETTOOLS error identifiers -
enum
{
  c_error_FGET_TARGET_INVALID_BLOCK_SIZE = 0,
  c_error_FGET_TARGET_CANNOT_OPEN_TARGET_FILE,
  c_error_FGET_TARGET_CANNOT_OPEN_MAP_FILE,
  c_error_FGET_TARGET_FILES_SIZE_MISMATCH,
  c_error_FGET_TARGET_CANNOT_MAP_FILES_TO_MEMORY,
  c_error_FGET_TARGET_NEGATIVE_REQUEST_COUNT,
  c_error_FGET_TARGET_INVALID_BLOCK_INDEX,
};

// - FGETTOOLS error strings -
extern const char *fgettools_error_strings[];

// - FGETTOOLS initialize -
bool fgettools_initialize(script_parser_s &sp);

// - FGETTOOLS print exception -
bool fgettools_print_exception(interpreter_s &it,exception_s &exception);

// - class FGET_TARGET -
extern built_in_variable_s fget_target_variables[];
extern built_in_method_s fget_target_methods[];
extern built_in_class_s fget_target_class;

void bic_fget_target_consts(location_array_s &const_locations);
void bic_fget_target_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fget_target_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fget_target_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_FgetTarget_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_requests_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_update_data_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_block_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_done_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_done_percent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fget_target_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

