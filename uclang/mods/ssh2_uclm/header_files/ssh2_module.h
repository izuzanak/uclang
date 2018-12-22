
#ifndef __SSH2_MODULE_H
#define __SSH2_MODULE_H

@begin
include "ucl_ssh2.h"
@end

// - SSH2 indexes of built in classes -
extern unsigned c_bi_class_ssh2_session;
extern unsigned c_bi_class_sftp_session;
extern unsigned c_bi_class_sftp_handle;
extern unsigned c_bi_class_ssh2_channel;

// - SSH2 module -
extern "C" IMPORT built_in_module_s module;

// - SSH2 classes -
extern built_in_class_s *ssh2_classes[];

// - SSH2 error identifiers -
enum
{
  c_error_SSH2_SESSION_SOCKET_NOT_OPENED = 0,
  c_error_SSH2_SESSION_INIT_ERROR,
  c_error_SSH2_SESSION_HANDSHAKE_ERROR,
  c_error_SSH2_SESSION_CANNOT_RETRIEVE_HOSTKEY_HASH,
  c_error_SSH2_SESSION_CANNOT_RETRIEVE_USERAUTH_LIST,
  c_error_SSH2_SESSION_USERAUTH_PASSWORD_ERROR,
  c_error_SSH2_SESSION_USERAUTH_FAKE_INTERACTIVE_ERROR,
  c_error_SSH2_SESSION_USERAUTH_PUBLICKEY_FROMFILE_ERROR,
  c_error_SSH2_SESSION_NOT_AUTHENTICATED,
  c_error_SSH2_SESSION_CHANNEL_OPEN_ERROR,
  c_error_SFTP_SESSION_INIT_ERROR,
  c_error_SFTP_SESSION_DIR_CREATE_ERROR,
  c_error_SFTP_SESSION_DIR_REMOVE_ERROR,
  c_error_SFTP_SESSION_DIR_LIST_ERROR,
  c_error_SFTP_SESSION_FILE_REMOVE_ERROR,
  c_error_SFTP_SESSION_FILE_OPEN_ERROR,
  c_error_SFTP_HANDLE_CLOSE_ERROR,
  c_error_SFTP_HANDLE_NOT_OPENED,
  c_error_SFTP_HANDLE_WRITE_ERROR,
  c_error_SFTP_HANDLE_READ_ERROR,
  c_error_SFTP_HANDLE_READ_NEGATIVE_BYTE_COUNT,
  c_error_SSH2_CHANNEL_EXEC_ERROR,
  c_error_SSH2_CHANNEL_SHELL_ERROR,
  c_error_SSH2_CHANNEL_WRITE_ERROR,
  c_error_SSH2_CHANNEL_READ_ERROR,
  c_error_SSH2_CHANNEL_FLUSH_ERROR,
  c_error_SSH2_CHANNEL_SEND_EOF_ERROR,
};

// - SSH2 error strings -
extern const char *ssh2_error_strings[];

// - SSH2 initialize -
bool ssh2_initialize(script_parser_s &sp);

// - SSH2 print exception -
bool ssh2_print_exception(interpreter_s &it,exception_s &exception);

// - class SSH2_SESSION -
extern built_in_variable_s ssh2_session_variables[];
extern built_in_method_s ssh2_session_methods[];
extern built_in_class_s ssh2_session_class;

void bic_ssh2_session_consts(location_array_s &const_locations);
void bic_ssh2_session_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ssh2_session_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ssh2_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_Ssh2Session_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_hostkey_hash_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_userauth_list_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_userauth_password_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_userauth_fake_interactive_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_userauth_publickey_fromfile_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_sftp_session_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_exec_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_shell_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SFTP_SESSION -
extern built_in_variable_s sftp_session_variables[];
extern built_in_method_s sftp_session_methods[];
extern built_in_class_s sftp_session_class;

void bic_sftp_session_consts(location_array_s &const_locations);
void bic_sftp_session_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sftp_session_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sftp_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_mkdir_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_rmdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_listdir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_open_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SFTP_HANDLE -
extern built_in_variable_s sftp_handle_variables[];
extern built_in_method_s sftp_handle_methods[];
extern built_in_class_s sftp_handle_class;

void bic_sftp_handle_consts(location_array_s &const_locations);
void bic_sftp_handle_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sftp_handle_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_sftp_handle_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_sftp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sftp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SSH2_CHANNEL -
extern built_in_variable_s ssh2_channel_variables[];
extern built_in_method_s ssh2_channel_methods[];
extern built_in_class_s ssh2_channel_class;

void bic_ssh2_channel_consts(location_array_s &const_locations);
void bic_ssh2_channel_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ssh2_channel_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ssh2_channel_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_flush_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_send_eof_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_read_stderr_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ssh2_channel_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

