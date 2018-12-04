
#ifndef __LINUX_MODULE_H
#define __LINUX_MODULE_H

@begin
include "ucl_linux.h"
@end

// - LINUX indexes of built in classes -
extern unsigned c_bi_class_linux;
extern unsigned c_bi_class_fd;

// - LINUX module -
extern built_in_module_s module;

// - LINUX classes -
extern built_in_class_s *linux_classes[];

// - LINUX error identifiers -
enum
{
  c_error_FD_OPEN_ERROR = 0,
  c_error_FD_CREATE_ERROR,
  c_error_FD_WRITE_INVALID_DATA_OFFSET,
  c_error_FD_WRITE_ERROR,
  c_error_FD_READ_INVALID_BYTE_COUNT,
  c_error_FD_READ_ERROR,
  c_error_FD_SYNC_ERROR,
  c_error_FD_SEEK_ERROR,
  c_error_FD_CLOSE_ERROR,
  c_error_FD_NOT_OPENED,
};

// - LINUX error strings -
extern const char *linux_error_strings[];

// - LINUX initialize -
bool linux_initialize(script_parser_s &sp);

// - LINUX print exception -
bool linux_print_exception(interpreter_s &it,exception_s &exception);

// - class LINUX -
extern built_in_variable_s linux_variables[];
extern built_in_method_s linux_methods[];
extern built_in_class_s linux_class;

void bic_linux_consts(location_array_s &const_locations);
void bic_linux_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_linux_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_linux_method_sync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_linux_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_linux_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FD -
extern built_in_variable_s fd_variables[];
extern built_in_method_s fd_methods[];
extern built_in_class_s fd_class;

void bic_fd_consts(location_array_s &const_locations);
void bic_fd_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fd_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_Fd_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_open_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_creat_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_openat_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_write_all_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_pwrite_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_pwrite_all_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_pread_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_fsync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_fdatasync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_lseek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

