
#ifndef __PSQL_MODULE_H
#define __PSQL_MODULE_H

@begin
include "ucl_psql.h"
@end

// - PSQL indexes of built in classes -
extern unsigned c_bi_class_psql;
extern unsigned c_bi_class_psql_conn;
extern unsigned c_bi_class_psql_statement;

// - PSQL module -
extern "C" EXPORT built_in_module_s module;

// - PSQL classes -
extern built_in_class_s *psql_classes[];

// - PSQL error identifiers -
enum
{
  c_error_PSQL_CONN_WRONG_PARAMETER_ARRAY,
  c_error_PSQL_CONN_CANNOT_CONNECT_TO_DATABASE,
  c_error_PSQL_CONN_NOT_OPENED,
  c_error_PSQL_CONN_EXEC_FAILED
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
bool bic_psql_conn_method_prepare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PSQL_STATEMENT -
extern built_in_variable_s psql_statement_variables[];
extern built_in_method_s psql_statement_methods[];
extern built_in_class_s psql_statement_class;

void bic_psql_statement_consts(location_array_s &const_locations);
void bic_psql_statement_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_psql_statement_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_psql_statement_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_statement_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_statement_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_psql_statement_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

