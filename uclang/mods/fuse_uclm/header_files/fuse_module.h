
#ifndef __FUSE_MODULE_H
#define __FUSE_MODULE_H

@begin
include "ucl_fuse.h"
@end

// - FUSE indexes of built in classes -
extern unsigned c_bi_class_fuse_channel;
extern unsigned c_bi_class_fuse_ops;
extern unsigned c_bi_class_fuse_handle;
extern unsigned c_bi_class_fuse_stat;
extern unsigned c_bi_class_fuse_file_info;
extern unsigned c_bi_class_fuse_dir_filler;

// - FUSE module -
extern built_in_module_s module;

// - FUSE classes -
extern built_in_class_s *fuse_classes[];

// - FUSE error identifiers -
enum
{
  c_error_FUSE_ARG_EXPECTED_STRING = 0,
  c_error_FUSE_CHANNEL_CREATE_ERROR,
  c_error_FUSE_CHANNEL_ALREADY_ATTACHED,
  c_error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_SIZE,
  c_error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_CONTENT,
  c_error_FUSE_OPS_UNSUPPORTED_OPERATION,
  c_error_FUSE_OPS_DELEGATE_WRONG_PARAM_CNT,
  c_error_FUSE_OPS_DELEGATE_ALREADY_ASSIGNED_TO_OPERATION,
  c_error_FUSE_HANDLE_CREATE_ERROR,
  c_error_FUSE_HANDLE_GET_OUTSIDE_OF_FILESYS_OPERATION,
  c_error_FUSE_HANDLE_LOOP_ALREADY_RUNNING,
  c_error_FUSE_HANDLE_LOOP_ERROR,
  c_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE,
  c_error_FUSE_DIR_FILLER_FILL_ERROR,
};

// - FUSE error strings -
extern const char *fuse_error_strings[];

// - FUSE initialize -
bool fuse_initialize(script_parser_s &sp);

// - FUSE print exception -
bool fuse_print_exception(interpreter_s &it,exception_s &exception);

// - class FUSE_CHANNEL -
extern built_in_variable_s fuse_channel_variables[];
extern built_in_method_s fuse_channel_methods[];
extern built_in_class_s fuse_channel_class;

void bic_fuse_channel_consts(location_array_s &const_locations);
void bic_fuse_channel_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_channel_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_channel_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_channel_method_FuseChannel_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_channel_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_channel_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FUSE_OPS -
extern built_in_variable_s fuse_ops_variables[];
extern built_in_method_s fuse_ops_methods[];
extern built_in_class_s fuse_ops_class;

void bic_fuse_ops_consts(location_array_s &const_locations);
void bic_fuse_ops_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_ops_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_ops_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_ops_method_FuseOps_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_ops_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_ops_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FUSE_HANDLE -
extern built_in_variable_s fuse_handle_variables[];
extern built_in_method_s fuse_handle_methods[];
extern built_in_class_s fuse_handle_class;

void bic_fuse_handle_consts(location_array_s &const_locations);
void bic_fuse_handle_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_handle_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_handle_method_FuseHandle_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_handle_method_get_handle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_handle_method_private_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_handle_method_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FUSE_STAT -
extern built_in_variable_s fuse_stat_variables[];
extern built_in_method_s fuse_stat_methods[];
extern built_in_class_s fuse_stat_class;

void bic_fuse_stat_consts(location_array_s &const_locations);
void bic_fuse_stat_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_stat_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_stat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_mode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_nlink_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_uid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_gid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_size_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_atime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_mtime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_st_ctime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_stat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FUSE_FILE_INFO -
extern built_in_variable_s fuse_file_info_variables[];
extern built_in_method_s fuse_file_info_methods[];
extern built_in_class_s fuse_file_info_class;

void bic_fuse_file_info_consts(location_array_s &const_locations);
void bic_fuse_file_info_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_file_info_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_file_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FUSE_DIR_FILLER -
extern built_in_variable_s fuse_dir_filler_variables[];
extern built_in_method_s fuse_dir_filler_methods[];
extern built_in_class_s fuse_dir_filler_class;

void bic_fuse_dir_filler_consts(location_array_s &const_locations);
void bic_fuse_dir_filler_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_dir_filler_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_dir_filler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_dir_filler_method_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_dir_filler_method_fill_dir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_dir_filler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_dir_filler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FUSE_FILE_FILLER -
extern built_in_variable_s fuse_file_filler_variables[];
extern built_in_method_s fuse_file_filler_methods[];
extern built_in_class_s fuse_file_filler_class;

void bic_fuse_file_filler_consts(location_array_s &const_locations);
void bic_fuse_file_filler_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fuse_file_filler_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fuse_file_filler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_filler_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_filler_method_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_filler_method_writed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_filler_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_filler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fuse_file_filler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

