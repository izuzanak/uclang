
#ifndef __BTRFSUTIL_MODULE_H
#define __BTRFSUTIL_MODULE_H

@begin
include "ucl_btrfsutil.h"
@end

// - BTRFS_UTIL indexes of built in classes -
extern unsigned c_bi_class_btrfs;
extern unsigned c_bi_class_btrfs_sub;

// - BTRFS_UTIL module -
extern "C" EXPORT built_in_module_s module;

// - BTRFS_UTIL classes -
extern built_in_class_s *btrfs_util_classes[];

// - BTRFS_UTIL error identifiers -
enum
{
  c_error_BTRFS_UTIL_REALPATH_ERROR = 0,
  c_error_BTRFS_UTIL_CREATE_SUBVOLUME_ERROR,
  c_error_BTRFS_UTIL_DELETE_SUBVOLUME_ERROR,
  c_error_BTRFS_UTIL_SUB_IS_NOT_SUBVOLUME,
  c_error_BTRFS_UTIL_SUB_GET_ID_ERROR,
  c_error_BTRFS_UTIL_SUB_GET_READ_ONLY_ERROR,
  c_error_BTRFS_UTIL_SUB_SET_READ_ONLY_ERROR,
  c_error_BTRFS_UTIL_SUB_SNAPSHOT_ERROR,
  c_error_BTRFS_UTIL_SUB_DELETE_ERROR,
};

// - BTRFS_UTIL error strings -
extern const char *btrfs_util_error_strings[];

// - BTRFS_UTIL initialize -
bool btrfs_util_initialize(script_parser_s &sp);

// - BTRFS_UTIL print exception -
bool btrfs_util_print_exception(interpreter_s &it,exception_s &exception);

// - class BTRFS -
extern built_in_variable_s btrfs_variables[];
extern built_in_method_s btrfs_methods[];
extern built_in_class_s btrfs_class;

void bic_btrfs_consts(location_array_s &const_locations);
void bic_btrfs_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_btrfs_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_btrfs_method_is_sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_method_create_sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_method_delete_sub_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BTRFS_SUB -
extern built_in_variable_s btrfs_sub_variables[];
extern built_in_method_s btrfs_sub_methods[];
extern built_in_class_s btrfs_sub_class;

void bic_btrfs_sub_consts(location_array_s &const_locations);
void bic_btrfs_sub_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_btrfs_sub_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_btrfs_sub_method_BtrfsSub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_is_sub_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_read_only_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_read_only_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_snapshot_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_delete_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_btrfs_sub_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

