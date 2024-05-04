
@begin
include "psql_module.h"
@end

// - PSQL indexes of built in classes -
unsigned c_bi_class_psql = c_idx_not_exist;
unsigned c_bi_class_psql_conn = c_idx_not_exist;
unsigned c_bi_class_psql_result = c_idx_not_exist;
unsigned c_bi_class_psql_notify = c_idx_not_exist;

// - PSQL module -
EXPORT built_in_module_s module =
{/*{{{*/
  4,                     // Class count
  psql_classes,          // Classes
  0,                     // Error base index
  12,                    // Error count
  psql_error_strings,    // Error strings
  psql_initialize,       // Initialize function
  psql_print_exception,  // Print exceptions function
};/*}}}*/

// - PSQL classes -
built_in_class_s *psql_classes[] =
{/*{{{*/
  &psql_class,
  &psql_conn_class,
  &psql_result_class,
  &psql_notify_class,
};/*}}}*/

// - PSQL error strings -
const char *psql_error_strings[] =
{/*{{{*/
  "error_PSQL_CONN_DB_CONNECT_ERROR",
  "error_PSQL_CONN_DB_NOT_CONNECTED",
  "error_PSQL_CONN_PROCESS_INVALID_FD",
  "error_PSQL_CONN_EXEC_QUERY_ERROR",
  "error_PSQL_CONN_SEND_QUERY_ERROR",
  "error_PSQL_CONN_SEND_FLUSH_ERROR",
  "error_PSQL_CONN_FLUSH_ERROR",
  "error_PSQL_CONN_CONSUME_INPUT_ERROR",
  "error_PSQL_CONN_GET_RESULT_WHILE_BUSY",
  "error_PSQL_CONN_GET_NOTIFY_WHILE_BUSY",
  "error_PSQL_CONN_SET_NONBLOCK_ERROR",
  "error_PSQL_CONN_PIPELINE_MODE_ERROR",
};/*}}}*/

// - PSQL initialize -
bool psql_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize psql class identifier -
  c_bi_class_psql = class_base_idx++;

  // - initialize psql_conn class identifier -
  c_bi_class_psql_conn = class_base_idx++;

  // - initialize psql_result class identifier -
  c_bi_class_psql_result = class_base_idx++;

  // - initialize psql_notify class identifier -
  c_bi_class_psql_notify = class_base_idx++;

  return true;
}/*}}}*/

// - PSQL print exception -
bool psql_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PSQL_CONN_DB_CONNECT_ERROR:
    {
      string_s &psql_error = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nError while connecting to database:\n");
      fprintf(stderr,"\n%s",psql_error.data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_PSQL_CONN_DB_NOT_CONNECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, not connected to database\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_PROCESS_INVALID_FD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, invalid file descriptor to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_EXEC_QUERY_ERROR:
    {
      string_s &psql_error = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nPSqlConn, execute query error:\n");
      fprintf(stderr,"\n%s",psql_error.data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_PSQL_CONN_SEND_QUERY_ERROR:
    {
      string_s &psql_error = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nPSqlConn, send query error:\n");
      fprintf(stderr,"\n%s",psql_error.data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_PSQL_CONN_SEND_FLUSH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, send flush error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_FLUSH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, flush queries error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_CONSUME_INPUT_ERROR:
    {
      string_s &psql_error = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nPSqlConn, consume input error:\n");
      fprintf(stderr,"\n%s",psql_error.data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_PSQL_CONN_GET_RESULT_WHILE_BUSY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, attempt to get result while busy\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_GET_NOTIFY_WHILE_BUSY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, attempt to get notify while busy\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_SET_NONBLOCK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, set nonblocking error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PSQL_CONN_PIPELINE_MODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPSqlConn, adjust pipeline mode error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

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
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
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
  BIC_CLASS_EMPTY_VARIABLES
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
  printf("PSql");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PSQL_CONN -
built_in_class_s psql_conn_class =
{/*{{{*/
  "PSqlConn",
  c_modifier_public | c_modifier_final,
  13
#ifdef LIBPQ_HAS_PIPELINING
  + 2
#endif
  , psql_conn_methods,
  0, psql_conn_variables,
  bic_psql_conn_consts,
  bic_psql_conn_init,
  bic_psql_conn_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s psql_conn_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_operator_binary_equal
  },
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
    "result#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_result_1
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_get_fds_0
  },
  {
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_process_2
  },
  {
    "nonblocking#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_nonblocking_1
  },
#ifdef LIBPQ_HAS_PIPELINING
  {
    "pipeline_mode#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_pipeline_mode_1
  },
  {
    "send_flush#0",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_send_flush_0
  },
#endif
  {
    "send_query#1",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_send_query_1
  },
  {
    "is_busy#0",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_is_busy_0
  },
  {
    "get_result#0",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_get_result_0
  },
  {
    "get_notify#0",
    c_modifier_public | c_modifier_final,
    bic_psql_conn_method_get_notify_0
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
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_PSQL_CONN_ERROR_STRING(CONN_PTR) \
/*{{{*/\
const char *error = PQerrorMessage(CONN_PTR);\
\
string_s *error_ptr = it.get_new_string_ptr();\
error_ptr->set(strlen(error),error);\
\
BIC_CREATE_NEW_LOCATION_REFS(err_location,c_bi_class_string,error_ptr,0);\
/*}}}*/

void bic_psql_conn_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_psql_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PGconn *)nullptr;
}/*}}}*/

void bic_psql_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  PGconn *conn_ptr = (PGconn *)location_ptr->v_data_ptr;

  if (conn_ptr != nullptr)
  {
    PQfinish(conn_ptr);
  }
}/*}}}*/

bool bic_psql_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_psql_conn_method_PSqlConn_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
conninfo:c_bi_class_string
>
method PSqlConn
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - connect to database -
  PGconn *conn_ptr = PQconnectdb(string_ptr->data);

  // - ERROR -
  if (PQstatus(conn_ptr) != CONNECTION_OK)
  {
    BIC_PSQL_CONN_ERROR_STRING(conn_ptr);

    PQfinish(conn_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_DB_CONNECT_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  // - retrieve psql connection pointer -
  dst_location->v_data_ptr = (PGconn *)conn_ptr;

  return true;
}/*}}}*/

bool bic_psql_conn_method_execute_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
query:c_bi_class_string
>
method execute
; @end

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;
  string_s *query_ptr = (string_s *)src_0_location->v_data_ptr;

  PGresult *res_ptr = PQexec(conn_ptr,query_ptr->data);
  ExecStatusType res_status = PQresultStatus(res_ptr);

  // - ERROR -
  if ((res_status != PGRES_COMMAND_OK) && res_status != PGRES_TUPLES_OK)
  {
    PQclear(res_ptr);

    BIC_PSQL_CONN_ERROR_STRING(conn_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_EXEC_QUERY_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  // - create tuple array -
  pointer_array_s *tuple_array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(tuple_array_loc,c_bi_class_array,tuple_array_ptr);

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
        BIC_CREATE_NEW_LOCATION(field_array_loc,c_bi_class_array,field_array_ptr);

        field_array_ptr->copy_resize(field_cnt);

        int field_idx = 0;
        do
        {
          switch (PQftype(res_ptr,field_idx))
          {
          case BOOLOID:
            {
              long long int value = PQgetvalue(res_ptr,tuple_idx,field_idx)[0] == 't';

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
              field_array_ptr->push(new_location);
            }
            break;
          case INT8OID:
          case INT2OID:
          case INT4OID:
            {
              char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);
              long long int value = strtoll(data,nullptr,10);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
              field_array_ptr->push(new_location);
            }
            break;
          case FLOAT4OID:
          case FLOAT8OID:
            {
              char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);
              double value = strtod(data,nullptr);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
              field_array_ptr->push(new_location);
            }
            break;
          default:
            {
              int length = PQgetlength(res_ptr,tuple_idx,field_idx);
              char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);

              string_s *string_ptr = it.get_new_string_ptr();
              string_ptr->set(length,data);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
              field_array_ptr->push(new_location);
            }
            break;
          }
        }
        while(++field_idx < field_cnt);

        // - push field array location to tuple array -
        tuple_array_ptr->push(field_array_loc);

      }
      while(++tuple_idx < tuple_cnt);
    }
  }

  PQclear(res_ptr);

  BIC_SET_RESULT(tuple_array_loc);

  return true;
}/*}}}*/

bool bic_psql_conn_method_result_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
query:c_bi_class_string
>
method result
; @end

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;
  string_s *query_ptr = (string_s *)src_0_location->v_data_ptr;

  PGresult *res_ptr = PQexec(conn_ptr,query_ptr->data);
  ExecStatusType res_status = PQresultStatus(res_ptr);

  // - ERROR -
  if ((res_status != PGRES_COMMAND_OK) && res_status != PGRES_TUPLES_OK)
  {
    PQclear(res_ptr);

    BIC_PSQL_CONN_ERROR_STRING(conn_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_EXEC_QUERY_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  // - create psql result object -
  psql_result_s *result_ptr = (psql_result_s *)cmalloc(sizeof(psql_result_s));
  result_ptr->init();

  result_ptr->res_ptr = res_ptr;

  dst_location->v_reference_cnt.atomic_inc();
  result_ptr->conn_ptr = dst_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_psql_result,result_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_psql_conn_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  long long int fd = PQsocket(conn_ptr);
  long long int events = POLLIN;

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_DB_NOT_CONNECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int res = PQflush(conn_ptr);

  // - ERROR -
  if (res == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_FLUSH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - not everything flushed, wait for writable fd -
  if (res == 1)
  {
    events |= POLLOUT;
  }

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,fd);
  array_ptr->push(fd_location);

  BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,events);
  array_ptr->push(events_location);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_psql_conn_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if (fd != PQsocket(conn_ptr))
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_PROCESS_INVALID_FD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (PQconsumeInput(conn_ptr) != 1)
  {
    BIC_PSQL_CONN_ERROR_STRING(conn_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_CONSUME_INPUT_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  // - ERROR -
  if (PQflush(conn_ptr) == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_FLUSH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = PQisBusy(conn_ptr) == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_psql_conn_method_nonblocking_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
enable:retrieve_integer
>
method nonblocking
; @end

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if (PQsetnonblocking(conn_ptr,enable) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_SET_NONBLOCK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

#ifdef LIBPQ_HAS_PIPELINING
bool bic_psql_conn_method_pipeline_mode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
enable:retrieve_integer
>
method pipeline_mode
; @end

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if ((enable ? PQenterPipelineMode(conn_ptr) : PQexitPipelineMode(conn_ptr)) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_PIPELINE_MODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_psql_conn_method_send_flush_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if (PQsendFlushRequest(conn_ptr) != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_SEND_FLUSH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/
#endif

bool bic_psql_conn_method_send_query_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
query:c_bi_class_string
>
method send_query
; @end

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;
  string_s *query_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (PQsendQueryParams(conn_ptr,query_ptr->data,0,nullptr,nullptr,nullptr,nullptr,0) != 1)
  {
    BIC_PSQL_CONN_ERROR_STRING(conn_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_SEND_QUERY_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_psql_conn_method_is_busy_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  long long int result = PQisBusy(conn_ptr) == 1;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_psql_conn_method_get_result_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if (PQisBusy(conn_ptr) == 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_GET_RESULT_WHILE_BUSY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve result -
  PGresult *res_ptr = PQgetResult(conn_ptr);

  if (res_ptr == nullptr)
  {
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    // - create psql result object -
    psql_result_s *result_ptr = (psql_result_s *)cmalloc(sizeof(psql_result_s));
    result_ptr->init();

    result_ptr->res_ptr = res_ptr;

    dst_location->v_reference_cnt.atomic_inc();
    result_ptr->conn_ptr = dst_location;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_psql_result,result_ptr);
    BIC_SET_RESULT(new_location);
  }

  return true;
}/*}}}*/

bool bic_psql_conn_method_get_notify_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PGconn *conn_ptr = (PGconn *)dst_location->v_data_ptr;

  // - ERROR -
  if (PQisBusy(conn_ptr) == 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PSQL_CONN_GET_NOTIFY_WHILE_BUSY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve notify -
  PGnotify *ntf_ptr = PQnotifies(conn_ptr);

  if (ntf_ptr == nullptr)
  {
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    // - create psql notify object -
    psql_notify_s *notify_ptr = (psql_notify_s *)cmalloc(sizeof(psql_notify_s));
    notify_ptr->init();

    notify_ptr->ntf_ptr = ntf_ptr;

    dst_location->v_reference_cnt.atomic_inc();
    notify_ptr->conn_ptr = dst_location;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_psql_notify,notify_ptr);
    BIC_SET_RESULT(new_location);
  }

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
  printf("PSqlConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PSQL_RESULT -
built_in_class_s psql_result_class =
{/*{{{*/
  "PSqlResult",
  c_modifier_public | c_modifier_final,
  5, psql_result_methods,
  10
#ifdef LIBPQ_HAS_PIPELINING
  + 2
#endif
  , psql_result_variables,
  bic_psql_result_consts,
  bic_psql_result_init,
  bic_psql_result_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s psql_result_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_psql_result_operator_binary_equal
  },
  {
    "status#0",
    c_modifier_public | c_modifier_final,
    bic_psql_result_method_status_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_psql_result_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_result_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_result_method_print_0
  },
};/*}}}*/

built_in_variable_s psql_result_variables[] =
{/*{{{*/

  // - psql result status constants -
  { "RES_EMPTY_QUERY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_COMMAND_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_TUPLES_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_COPY_OUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_COPY_IN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_BAD_RESPONSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_NONFATAL_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_FATAL_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_COPY_BOTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_SINGLE_TUPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
#ifdef LIBPQ_HAS_PIPELINING
  { "RES_PIPELINE_SYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RES_PIPELINE_ABORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
#endif

};/*}}}*/

void bic_psql_result_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert psql result status constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_PSQL_RESULT_STATUS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_EMPTY_QUERY);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_COMMAND_OK);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_TUPLES_OK);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_COPY_OUT);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_COPY_IN);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_BAD_RESPONSE);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_NONFATAL_ERROR);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_FATAL_ERROR);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_COPY_BOTH);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_SINGLE_TUPLE);
  }

#ifdef LIBPQ_HAS_PIPELINING
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_PIPELINE_SYNC);
    CREATE_PSQL_RESULT_STATUS_BIC_STATIC(PGRES_PIPELINE_ABORTED);
  }
#endif

}/*}}}*/

void bic_psql_result_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (psql_result_s *)nullptr;
}/*}}}*/

void bic_psql_result_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  psql_result_s *result_ptr = (psql_result_s *)location_ptr->v_data_ptr;

  if (result_ptr != nullptr)
  {
    result_ptr->clear(it);
    cfree(result_ptr);
  }
}/*}}}*/

bool bic_psql_result_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_psql_result_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  psql_result_s *result_ptr = (psql_result_s *)dst_location->v_data_ptr;
  PGresult *res_ptr = result_ptr->res_ptr;

  long long int result = PQresultStatus(res_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_psql_result_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  psql_result_s *result_ptr = (psql_result_s *)dst_location->v_data_ptr;
  PGresult *res_ptr = result_ptr->res_ptr;

  int &tuple_idx = result_ptr->tuple_idx;

  // - if there are any rows -
  if (PQntuples(res_ptr) > tuple_idx)
  {
    // - create field array -
    pointer_array_s *field_array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(field_array_loc,c_bi_class_array,field_array_ptr);

    int field_cnt = PQnfields(res_ptr);
    field_array_ptr->copy_resize(field_cnt);

    // - if field array is not empty -
    if (field_cnt > 0)
    {
      int field_idx = 0;
      do
      {
        switch (PQftype(res_ptr,field_idx))
        {
        case BOOLOID:
          {
            long long int value = PQgetvalue(res_ptr,tuple_idx,field_idx)[0] == 't';

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
            field_array_ptr->push(new_location);
          }
          break;
        case INT8OID:
        case INT2OID:
        case INT4OID:
          {
            char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);
            long long int value = strtoll(data,nullptr,10);

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
            field_array_ptr->push(new_location);
          }
          break;
        case FLOAT4OID:
        case FLOAT8OID:
          {
            char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);
            double value = strtod(data,nullptr);

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
            field_array_ptr->push(new_location);
          }
          break;
        default:
          {
            int length = PQgetlength(res_ptr,tuple_idx,field_idx);
            char *data = PQgetvalue(res_ptr,tuple_idx,field_idx);

            string_s *string_ptr = it.get_new_string_ptr();
            string_ptr->set(length,data);

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
            field_array_ptr->push(new_location);
          }
          break;
        }
      }
      while(++field_idx < field_cnt);

      // - skip to next tuple -
      ++tuple_idx;
    }

    BIC_SET_RESULT(field_array_loc);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_psql_result_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PSqlResult"),"PSqlResult");
  );

  return true;
}/*}}}*/

bool bic_psql_result_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PSqlResult");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PSQL_NOTIFY -
built_in_class_s psql_notify_class =
{/*{{{*/
  "PSqlNotify",
  c_modifier_public | c_modifier_final,
  3, psql_notify_methods,
  0, psql_notify_variables,
  bic_psql_notify_consts,
  bic_psql_notify_init,
  bic_psql_notify_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s psql_notify_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_psql_notify_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_notify_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_psql_notify_method_print_0
  },
};/*}}}*/

built_in_variable_s psql_notify_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_psql_notify_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_psql_notify_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (psql_notify_s *)nullptr;
}/*}}}*/

void bic_psql_notify_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  psql_notify_s *notify_ptr = (psql_notify_s *)location_ptr->v_data_ptr;

  if (notify_ptr != nullptr)
  {
    notify_ptr->clear(it);
    cfree(notify_ptr);
  }
}/*}}}*/

bool bic_psql_notify_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_psql_notify_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PSqlNotify"),"PSqlNotify");
  );

  return true;
}/*}}}*/

bool bic_psql_notify_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PSqlNotify");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

