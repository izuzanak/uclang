
#ifndef __LINUX_MODULE_H
#define __LINUX_MODULE_H

@begin
include "ucl_linux.h"
@end

// - LINUX indexes of built in classes -
extern unsigned c_bi_class_linux;
extern unsigned c_bi_class_fd;
extern unsigned c_bi_class_timer_fd;
extern unsigned c_bi_class_mmap;

// - LINUX module -
extern "C" EXPORT built_in_module_s module;

// - LINUX classes -
extern built_in_class_s *linux_classes[];

// - LINUX error identifiers -
enum
{
  c_error_LINUX_FORK_ERROR = 0,
  c_error_LINUX_SYSCONF_ERROR,
  c_error_FD_DUPLICATE_ERROR,
  c_error_FD_OPEN_ERROR,
  c_error_FD_CREATE_ERROR,
  c_error_FD_CLOSE_ERROR,
  c_error_FD_WRITE_INVALID_SOURCE_OFFSET,
  c_error_FD_OPERATION_INVALID_IOV_SEGMENT_COUNT,
  c_error_FD_WRITE_INVALID_IOV_SEGMENT_DATA_TYPE,
  c_error_FD_WRITE_ERROR,
  c_error_FD_READ_INVALID_BYTE_COUNT,
  c_error_FD_READ_INVALID_IOV_SEGMENT_SIZE,
  c_error_FD_READ_ERROR,
  c_error_FD_SYNC_ERROR,
  c_error_FD_ADVISE_ERROR,
  c_error_FD_SEEK_ERROR,
  c_error_FD_IOCTL_INVALID_ARGUMENT_TYPE,
  c_error_FD_IOCTL_UNKNOWN_REQUEST,
  c_error_FD_IOCTL_ERROR,
  c_error_FD_FLOCK_ERROR,
  c_error_FD_NOT_OPENED,
  c_error_TIMER_FD_CREATE_ERROR,
  c_error_TIMER_FD_SETTIME_ERROR,
  c_error_TIMER_FD_EXP_COUNTER_READ_ERROR,
  c_error_MMAP_INVALID_OFFSET,
  c_error_MMAP_INVALID_LENGTH,
  c_error_MMAP_CREATE_ERROR,
  c_error_MMAP_REMAP_ERROR,
  c_error_MMAP_PROTECT_ERROR,
  c_error_MMAP_SYNC_ERROR,
  c_error_MMAP_ADVISE_ERROR,
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

bool bic_linux_method_fork_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_linux_method_sync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_linux_method_sysconf_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
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
bool bic_fd_method_Fd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_open_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_creat_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_ioctl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_ioctl_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_flock_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_openat_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_write_all_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_pwrite_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_pwrite_all_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_writev_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
bool bic_fd_method_pwritev2_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_fd_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_pread_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_readv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,6,0)
bool bic_fd_method_preadv2_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_fd_method_sync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_datasync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_advise_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_seek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_mmap_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TIMER_FD -
extern built_in_variable_s timer_fd_variables[];
extern built_in_method_s timer_fd_methods[];
extern built_in_class_s timer_fd_class;

void bic_timer_fd_consts(location_array_s &const_locations);
void bic_timer_fd_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_timer_fd_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_timer_fd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_fd_method_TimerFd_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_fd_method_settime_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_fd_method_read_counter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_fd_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_fd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_timer_fd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MMAP -
extern built_in_variable_s mmap_variables[];
extern built_in_method_s mmap_methods[];
extern built_in_class_s mmap_class;

void bic_mmap_consts(location_array_s &const_locations);
void bic_mmap_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mmap_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mmap_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_remap_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_protect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_sync_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_advise_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_read_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mmap_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

