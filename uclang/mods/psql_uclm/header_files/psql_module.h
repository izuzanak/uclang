
#ifndef __PSQL_MODULE_H
#define __PSQL_MODULE_H

@begin
include "ucl_psql.h"
@end

// - PSQL indexes of built in classes -
extern unsigned c_bi_class_psql;
extern unsigned c_bi_class_psql_conn;
extern unsigned c_bi_class_psql_result;
extern unsigned c_bi_class_psql_notify;

// - PSQL module -
extern "C" EXPORT built_in_module_s module;

// - PSQL classes -
extern built_in_class_s *psql_classes[];

// - PSQL error identifiers -
enum
{
  c_error_PSQL_CONN_DB_CONNECT_ERROR = 0,
  c_error_PSQL_CONN_DB_NOT_CONNECTED,
  c_error_PSQL_CONN_PROCESS_INVALID_FD,
  c_error_PSQL_CONN_EXEC_QUERY_ERROR,
  c_error_PSQL_CONN_SEND_QUERY_ERROR,
  c_error_PSQL_CONN_SEND_FLUSH_ERROR,
  c_error_PSQL_CONN_FLUSH_ERROR,
  c_error_PSQL_CONN_CONSUME_INPUT_ERROR,
  c_error_PSQL_CONN_GET_RESULT_WHILE_BUSY,
  c_error_PSQL_CONN_GET_NOTIFY_WHILE_BUSY,
  c_error_PSQL_CONN_SET_NONBLOCK_ERROR,
  c_error_PSQL_CONN_PIPELINE_MODE_ERROR,
};

// - PSQL error strings -
extern const char *psql_error_strings[];

// - PSQL initialize -
bool psql_initialize(script_parser_s &sp);

// - PSQL print exception -
bool psql_print_exception(interpreter_s &it,exception_s &exception);

// - class PSQL -
extern built_in_variable_s psql_variables[];
extern built_in_method_s psql_methods[];
extern built_in_class_s psql_class;

void bic_psql_consts(location_array_s &const_locations);
void bic_psql_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_psql_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_psql_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PSQL_CONN -
extern built_in_variable_s psql_conn_variables[];
extern built_in_method_s psql_conn_methods[];
extern built_in_class_s psql_conn_class;

void bic_psql_conn_consts(location_array_s &const_locations);
void bic_psql_conn_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_psql_conn_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_psql_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_PSqlConn_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_execute_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_result_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_nonblocking_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifdef LIBPQ_HAS_PIPELINING
bool bic_psql_conn_method_pipeline_mode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_send_flush_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_psql_conn_method_send_query_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_is_busy_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_get_result_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_get_notify_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PSQL_RESULT -
extern built_in_variable_s psql_result_variables[];
extern built_in_method_s psql_result_methods[];
extern built_in_class_s psql_result_class;

void bic_psql_result_consts(location_array_s &const_locations);
void bic_psql_result_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_psql_result_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_psql_result_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_result_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_result_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_result_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_result_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PSQL_NOTIFY -
extern built_in_variable_s psql_notify_variables[];
extern built_in_method_s psql_notify_methods[];
extern built_in_class_s psql_notify_class;

void bic_psql_notify_consts(location_array_s &const_locations);
void bic_psql_notify_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_psql_notify_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_psql_notify_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_notify_method_channel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_notify_method_pid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_notify_method_payload_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_notify_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_notify_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

