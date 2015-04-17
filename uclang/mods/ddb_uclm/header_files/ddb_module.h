
#ifndef __DDB_MODULE_H
#define __DDB_MODULE_H

@begin
include "ucl_ddb.h"
@end

// - DDB indexes of built in classes -
extern unsigned c_bi_class_ddb;
extern unsigned c_bi_class_trace_storage;
extern unsigned c_bi_class_trace_record;

// - DDB module -
extern built_in_module_s module;

// - DDB classes -
extern built_in_class_s *ddb_classes[];

// - DDB error identifiers -
enum
{
  c_error_DDB_OPEN_ERROR = 0,
  c_error_DDB_GET_TRACE_INDEX_ERROR,
  c_error_DDB_GET_TRACE_NAME_ERROR,
  c_error_TRACE_STORAGE_READ_ERROR,
  c_error_TRACE_STORAGE_WRITE_ERROR,
  c_error_TRACE_STORAGE_FIND_ERROR,
  c_error_TRACE_STORAGE_ERASE_ERROR,
  c_error_TRACE_STORAGE_WRONG_RECORD_TIME,
  c_error_TRACE_STORAGE_DATA_SIZE_ERROR,
  c_error_TRACE_STORAGE_INDEX_EXCEEDS_RANGE,
};

// - DDB error strings -
extern const char *ddb_error_strings[];

// - DDB initialize -
bool ddb_initialize(script_parser_s &sp);

// - DDB print exception -
bool ddb_print_exception(interpreter_s &it,exception_s &exception);

// - class DDB -
extern built_in_variable_s ddb_variables[];
extern built_in_method_s ddb_methods[];
extern built_in_class_s ddb_class;

void bic_ddb_consts(location_array_s &const_locations);
void bic_ddb_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ddb_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ddb_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_DDB_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_nEventDescs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_nTraceDescs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_nSnapDescs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_GetTraceStorage_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ddb_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRACE_STORAGE -
extern built_in_variable_s trace_storage_variables[];
extern built_in_method_s trace_storage_methods[];
extern built_in_class_s trace_storage_class;

void bic_trace_storage_consts(location_array_s &const_locations);
void bic_trace_storage_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trace_storage_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trace_storage_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_capacity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_recIdHead_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_recIdTail_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_Read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_Write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_Write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_Find_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_FindId_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_Erase_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_storage_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRACE_RECORD -
extern built_in_variable_s trace_record_variables[];
extern built_in_method_s trace_record_methods[];
extern built_in_class_s trace_record_class;

void bic_trace_record_consts(location_array_s &const_locations);
void bic_trace_record_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trace_record_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trace_record_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_record_method_GetId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_record_method_GetTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_record_method_GetData_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_record_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trace_record_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

