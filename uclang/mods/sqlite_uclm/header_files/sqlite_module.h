
#ifndef __SQLITE_MODULE_H
#define __SQLITE_MODULE_H

@begin
include "ucl_sqlite.h"
@end

// - SQLITE indexes of built in classes -
extern unsigned c_bi_class_sqlite_conn;
extern unsigned c_bi_class_sqlite_statement;

// - SQLITE module -
extern built_in_module_s module;

// - SQLITE classes -
extern built_in_class_s *sqlite_classes[];

// - SQLITE error identifiers -
enum
{
  c_error_SQLITE_CONN_DB_OPEN_ERROR,
  c_error_SQLITE_CONN_EXECUTE_ERROR,
  c_error_SQLITE_CONN_PREPARE_ERROR,
  c_error_SQLITE_STATEMENT_BIND_UNKNOWN_HOST_PARAMETER_NAME,
  c_error_SQLITE_STATEMENT_BIND_UNSUPPORTED_TYPE_ERROR,
  c_error_SQLITE_STATEMENT_BIND_ERROR,
  c_error_SQLITE_STATEMENT_STEP_ERROR,
  c_error_SQLITE_STATEMENT_RESET_ERROR,
  c_error_SQLITE_STATEMENT_CLEAR_BINDINGS_ERROR,
};

// - SQLITE error strings -
extern const char *sqlite_error_strings[];

// - SQLITE initialize -
bool sqlite_initialize(script_parser_s &sp);

// - SQLITE print exception -
bool sqlite_print_exception(interpreter_s &it,exception_s &exception);

// - class SQLITE_CONN -
extern built_in_variable_s sqlite_conn_variables[];
extern built_in_method_s sqlite_conn_methods[];
extern built_in_class_s sqlite_conn_class;

void bic_sqlite_conn_consts(location_array_s &const_locations);
void bic_sqlite_conn_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sqlite_conn_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sqlite_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_conn_method_SQLiteConn_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_conn_method_execute_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_conn_method_prepare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_conn_method_errmsg_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SQLITE_STATEMENT -
extern built_in_variable_s sqlite_statement_variables[];
extern built_in_method_s sqlite_statement_methods[];
extern built_in_class_s sqlite_statement_class;

void bic_sqlite_statement_consts(location_array_s &const_locations);
void bic_sqlite_statement_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_sqlite_statement_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_sqlite_statement_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_bind_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_bind_blob_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_step_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_reset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_reset_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_sqlite_statement_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

