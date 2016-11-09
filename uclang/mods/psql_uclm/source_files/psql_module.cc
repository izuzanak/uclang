
@begin
include "psql_module.h"
@end

// - PSQL indexes of built in classes -
unsigned c_bi_class_psql = c_idx_not_exist;
unsigned c_bi_class_psql_conn = c_idx_not_exist;

// - PSQL module -
built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  psql_classes,          // Classes
  0,                     // Error base index
  4,                     // Error count
  psql_error_strings,    // Error strings
  psql_initialize,       // Initialize function
  psql_print_exception,  // Print exceptions function
};/*}}}*/

// - PSQL classes -
built_in_class_s *psql_classes[] =
{/*{{{*/
  &psql_class,
  &psql_conn_class,
};/*}}}*/

// - PSQL error strings -
const char *psql_error_strings[] =
{/*{{{*/
  "error_PSQL_CONN_WRONG_PARAMETER_ARRAY",
  "error_PSQL_CONN_CANNOT_CONNECT_TO_DATABASE",
  "error_PSQL_CONN_NOT_OPENED",
  "error_PSQL_CONN_EXEC_FAILED",
};/*}}}*/

// - PSQL initialize -
bool psql_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize psql class identifier -
  c_bi_class_psql = class_base_idx++;

  // - initialize psql_conn class identifier -
  c_bi_class_psql_conn = class_base_idx++;

  return true;
}/*}}}*/

// - PSQL print exception -
bool psql_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_PSQL_CONN_WRONG_PARAMETER_ARRAY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nConstructor of PSqlConn expects array of five strings as argument\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_CANNOT_CONNECT_TO_DATABASE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while connecting to database\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nConnection to database was not opened yet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_EXEC_FAILED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while executing database command\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class PSQL -
built_in_class_s psql_class =
{/*{{{*/
  "PSql",
  c_modifier_public | c_modifier_final,
  2, psql_methods,
  0, psql_variables,
  bic_psql_consts,
  bic_psql_init,
  bic_psql_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s psql_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_method_print_0
  },
};/*}}}*/

built_in_variable_s psql_variables[] =
{/*{{{*/
};/*}}}*/

void bic_psql_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_psql_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_psql_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_psql_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PSql"),"PSql");
  );

  return true;
}/*}}}*/

bool bic_psql_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PSql");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PSQL_CONN -
built_in_class_s psql_conn_class =
{/*{{{*/
  "PSqlConn",
  c_modifier_public | c_modifier_final,
  4, psql_conn_methods,
  0, psql_conn_variables,
  bic_psql_conn_consts,
  bic_psql_conn_init,
  bic_psql_conn_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s psql_conn_methods[] =
{/*{{{*/
  {
    "PSqlConn#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_PSqlConn_1
  },
  {
    "execute#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_execute_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_conn_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_conn_method_print_0
  },
};/*}}}*/

built_in_variable_s psql_conn_variables[] =
{/*{{{*/
};/*}}}*/

void bic_psql_conn_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_psql_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PGconn *)NULL;
}/*}}}*/

void bic_psql_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  PGconn *conn_ptr = (PGconn *)location_ptr->v_data_ptr;

  if (conn_ptr != NULL)
  {
    PQfinish(conn_ptr);
  }
}/*}}}*/

bool bic_psql_conn_method_PSqlConn_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PSqlConn#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - connect to database -
  PGconn *conn_ptr = PQconnectdb(string_ptr->data);

  // - ERROR -
  if (PQstatus(conn_ptr) != CONNECTION_OK)
  {
    PQfinish(conn_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_CANNOT_CONNECT_TO_DATABASE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve psql connection pointer -
  dst_location->v_data_ptr = (PGconn *)conn_ptr;

  return true;
}/*}}}*/

bool bic_psql_conn_method_execute_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("execute#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if (conn_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *query_ptr = (string_s *)src_0_location->v_data_ptr;

  PGresult *res_ptr = PQexec(conn_ptr,query_ptr->data);
  ExecStatusType res_status = PQresultStatus(res_ptr);

  // - ERROR -
  if ((res_status != PGRES_COMMAND_OK) && res_status != PGRES_TUPLES_OK)
  {
    PQclear(res_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_EXEC_FAILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create tuple array -
  pointer_array_s *tuple_array_ptr = it.get_new_array_ptr();

  int tuple_cnt = PQntuples(res_ptr);
  if (tuple_cnt > 0)
  {
    tuple_array_ptr->copy_resize(tuple_cnt);

    int field_cnt = PQnfields(res_ptr);
    if (field_cnt > 0)
    {
      int tuple_idx = 0;
      do
      {
        // - create field array -
        pointer_array_s *field_array_ptr = it.get_new_array_ptr();
        field_array_ptr->copy_resize(field_cnt);

        int field_idx = 0;
        do
        {
          int length = PQgetlength(res_ptr,tuple_idx,field_idx);
          char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);

          string_s *value_ptr = it.get_new_string_ptr();
          value_ptr->set(length,data);

          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,value_ptr);

          // - push string location to field array -
          field_array_ptr->push(new_location);

        }
        while(++field_idx < field_cnt);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,field_array_ptr);

        // - push field array location to tuple array -
        tuple_array_ptr->push(new_location);

      }
      while(++tuple_idx < tuple_cnt);
    }
  }

  PQclear(res_ptr);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,tuple_array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_psql_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PSqlConn"),"PSqlConn");
  );

  return true;
}/*}}}*/

bool bic_psql_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PSqlConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

