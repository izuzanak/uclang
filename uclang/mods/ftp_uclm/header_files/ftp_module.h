
#ifndef __FTP_MODULE_H
#define __FTP_MODULE_H

@begin
include "ucl_ftp.h"
@end

// - FTP indexes of built in classes -
extern unsigned c_bi_class_ftp_session;
extern unsigned c_bi_class_ftp_handle;

// - FTP module -
extern built_in_module_s module;

// - FTP classes -
extern built_in_class_s *ftp_classes[];

// - FTP error identifiers -
enum
{
  c_error_FTP_SESSION_CONNECT_ERROR = 0,
  c_error_FTP_SESSION_LOGIN_ERROR,
  c_error_FTP_SESSION_DIR_CREATE_ERROR,
  c_error_FTP_SESSION_DIR_REMOVE_ERROR,
  c_error_FTP_SESSION_DIR_CHANGE_ERROR,
  c_error_FTP_SESSION_DIR_GET_CWD_ERROR,
  c_error_FTP_SESSION_DIR_LIST_ERROR,
  c_error_FTP_SESSION_FILE_GET_ERROR,
  c_error_FTP_SESSION_FILE_PUT_ERROR,
  c_error_FTP_SESSION_FILE_REMOVE_ERROR,
  c_error_FTP_SESSION_FILE_RENAME_ERROR,
  c_error_FTP_SESSION_ACCESS_ERROR,
  c_error_FTP_HANDLE_CLOSE_ERROR,
  c_error_FTP_HANDLE_NOT_OPENED,
  c_error_FTP_HANDLE_WRITE_ERROR,
  c_error_FTP_HANDLE_READ_ERROR,
  c_error_FTP_HANDLE_READ_NEGATIVE_BYTE_COUNT,
};

// - FTP error strings -
extern const char *ftp_error_strings[];

// - FTP initialize -
bool ftp_initialize(script_parser_s &sp);

// - FTP print exception -
bool ftp_print_exception(interpreter_s &it,exception_s &exception);

// - class FTP_SESSION -
extern built_in_variable_s ftp_session_variables[];
extern built_in_method_s ftp_session_methods[];
extern built_in_class_s ftp_session_class;

void bic_ftp_session_consts(location_array_s &const_locations);
void bic_ftp_session_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ftp_session_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ftp_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_FtpSession_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_login_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_mkdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_rmdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_listdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_chdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_getcwd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_get_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_put_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_rename_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_open_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FTP_HANDLE -
extern built_in_variable_s ftp_handle_variables[];
extern built_in_method_s ftp_handle_methods[];
extern built_in_class_s ftp_handle_class;

void bic_ftp_handle_consts(location_array_s &const_locations);
void bic_ftp_handle_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ftp_handle_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_ftp_handle_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_ftp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ftp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

