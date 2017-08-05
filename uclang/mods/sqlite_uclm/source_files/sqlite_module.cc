
@begin
include "sqlite_module.h"
@end

// - SQLITE indexes of built in classes -

unsigned c_bi_class_sqlite_conn = c_idx_not_exist;
unsigned c_bi_class_sqlite_statement = c_idx_not_exist;

// - SQLITE module -
built_in_module_s module =
{/*{{{*/
  2,                      // Class count
  sqlite_classes,         // Classes
  0,                      // Error base index
  9,                      // Error count
  sqlite_error_strings,   // Error strings
  sqlite_initialize,      // Initialize function
  sqlite_print_exception, // Print exceptions function
};/*}}}*/

// - SQLITE classes -
built_in_class_s *sqlite_classes[] =
{/*{{{*/
  &sqlite_conn_class,
  &sqlite_statement_class,
};/*}}}*/

// - SQLITE error strings -
const char *sqlite_error_strings[] =
{/*{{{*/
  "error_SQLITE_CONN_DB_OPEN_ERROR",
  "error_SQLITE_CONN_EXECUTE_ERROR",
  "error_SQLITE_CONN_PREPARE_ERROR",
  "error_SQLITE_STATEMENT_BIND_UNKNOWN_HOST_PARAMETER_NAME",
  "error_SQLITE_STATEMENT_BIND_UNSUPPORTED_TYPE_ERROR",
  "error_SQLITE_STATEMENT_BIND_ERROR",
  "error_SQLITE_STATEMENT_STEP_ERROR",
  "error_SQLITE_STATEMENT_RESET_ERROR",
  "error_SQLITE_STATEMENT_CLEAR_BINDINGS_ERROR",
};/*}}}*/

// - SQLITE initialize -
bool sqlite_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize sqlite_conn class identifier -
  c_bi_class_sqlite_conn = class_base_idx++;

  // - initialize sqlite_statement class identifier -
  c_bi_class_sqlite_statement = class_base_idx++;

  return true;
}/*}}}*/

// - SQLITE print exception -
bool sqlite_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_SQLITE_CONN_DB_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite error while openning database: \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_CONN_EXECUTE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite error while executing request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_CONN_PREPARE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite error while preparing request\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_STATEMENT_BIND_UNKNOWN_HOST_PARAMETER_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite statement, unknown name \"%s\" of host parameter\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_STATEMENT_BIND_UNSUPPORTED_TYPE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite statement, unsupported variable type %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_STATEMENT_BIND_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite statement error while binding value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_STATEMENT_STEP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite statement error while processing step\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_STATEMENT_RESET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite statement error while resetting\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SQLITE_STATEMENT_CLEAR_BINDINGS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSQLite statement error while clearing bindings\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SQLITE_CONN -
built_in_class_s sqlite_conn_class =
{/*{{{*/
  "SQLiteConn",
  c_modifier_public | c_modifier_final,
  9, sqlite_conn_methods,
  20, sqlite_conn_variables,
  bic_sqlite_conn_consts,
  bic_sqlite_conn_init,
  bic_sqlite_conn_clear,
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

built_in_method_s sqlite_conn_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sqlite_conn_operator_binary_equal
  },
  {
    "SQLiteConn#1",
    c_modifier_public | c_modifier_final,
    bic_sqlite_conn_method_SQLiteConn_1
  },
  {
    "SQLiteConn#2",
    c_modifier_public | c_modifier_final,
    bic_sqlite_conn_method_SQLiteConn_2
  },
  {
    "threadsafe#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sqlite_conn_method_threadsafe_0
  },
  {
    "execute#1",
    c_modifier_public | c_modifier_final,
    bic_sqlite_conn_method_execute_1
  },
  {
    "prepare#1",
    c_modifier_public | c_modifier_final,
    bic_sqlite_conn_method_prepare_1
  },
  {
    "errmsg#0",
    c_modifier_public | c_modifier_final,
    bic_sqlite_conn_method_errmsg_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sqlite_conn_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sqlite_conn_method_print_0
  },
};/*}}}*/

built_in_variable_s sqlite_conn_variables[] =
{/*{{{*/

  // - conn open constants -
  { "OPEN_READONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_READWRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_CREATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_DELETEONCLOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_EXCLUSIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_AUTOPROXY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_URI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_MAIN_DB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_TEMP_DB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_TRANSIENT_DB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_MAIN_JOURNAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_TEMP_JOURNAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_SUBJOURNAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_MASTER_JOURNAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_NOMUTEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_FULLMUTEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_SHAREDCACHE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_PRIVATECACHE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN_WAL", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_sqlite_conn_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert sqlite connection open constants -
  {
    const_locations.push_blanks(20);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 20);

#define CREATE_SQLITE_CONN_OPEN_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_READONLY);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_READWRITE);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_CREATE);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_DELETEONCLOSE);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_EXCLUSIVE);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_AUTOPROXY);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_URI);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_MEMORY);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_MAIN_DB);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_TEMP_DB);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_TRANSIENT_DB);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_MAIN_JOURNAL);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_TEMP_JOURNAL);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_SUBJOURNAL);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_MASTER_JOURNAL);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_NOMUTEX);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_FULLMUTEX);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_SHAREDCACHE);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_PRIVATECACHE);
    CREATE_SQLITE_CONN_OPEN_BIC_STATIC(SQLITE_OPEN_WAL);
  }

}/*}}}*/

void bic_sqlite_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (sqlite3 *)nullptr;
}/*}}}*/

void bic_sqlite_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  sqlite3 *db_ptr = (sqlite3 *)location_ptr->v_data_ptr;

  if (db_ptr != nullptr)
  {
    sqlite3_close(db_ptr);
  }
}/*}}}*/

bool bic_sqlite_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_SQLiteConn_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SQLiteConn#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  sqlite3 *db_ptr;

  // - ERROR -
  if (sqlite3_open(string_ptr->data,&db_ptr) != SQLITE_OK)
  {
    sqlite3_close(db_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_CONN_DB_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (sqlite3 *)db_ptr;

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_SQLiteConn_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int flags;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,flags))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SQLiteConn#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  sqlite3 *db_ptr;

  // - ERROR -
  if (sqlite3_open_v2(string_ptr->data,&db_ptr,flags,nullptr) != SQLITE_OK)
  {
    sqlite3_close(db_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_CONN_DB_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (sqlite3 *)db_ptr;

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_threadsafe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  long long int result = sqlite3_threadsafe();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_execute_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  sqlite3 *db_ptr = (sqlite3 *)dst_location->v_data_ptr;
  string_s *query_ptr = (string_s *)src_0_location->v_data_ptr;
  sqlite3_stmt *statement_ptr;

  // - ERROR -
  if (sqlite3_prepare_v2(db_ptr,query_ptr->data,query_ptr->size - 1,&statement_ptr,nullptr) != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_CONN_EXECUTE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result array -
  pointer_array_s *res_array = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(res_array_loc,c_bi_class_array,res_array);

  int step_res = sqlite3_step(statement_ptr);
  if (step_res == SQLITE_ROW)
  {
    int column_cnt = sqlite3_column_count(statement_ptr);

    do {
      // - create row array -
      pointer_array_s *row_array = it.get_new_array_ptr();
      BIC_CREATE_NEW_LOCATION(row_array_loc,c_bi_class_array,row_array);

      res_array->push(row_array_loc);

      if (column_cnt > 0)
      {
        row_array->copy_resize(column_cnt);

        int col_idx = 0;
        do {
          switch (sqlite3_column_type(statement_ptr,col_idx))
          {
          case SQLITE_INTEGER:
            {
              sqlite3_int64 value = sqlite3_column_int64(statement_ptr,col_idx);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
              row_array->push(new_location);
            }
            break;
          case SQLITE_FLOAT:
            {
              double value = sqlite3_column_double(statement_ptr,col_idx);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
              row_array->push(new_location);
            }
            break;
          case SQLITE_TEXT:
            {
              const char *data = (const char *)sqlite3_column_text(statement_ptr,col_idx);
              unsigned length = sqlite3_column_bytes(statement_ptr,col_idx);

              string_s *string_ptr = it.get_new_string_ptr();
              string_ptr->set(length,data);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
              row_array->push(new_location);
            }
            break;
          case SQLITE_BLOB:
            {
              const char *data = (const char *)sqlite3_column_blob(statement_ptr,col_idx);
              unsigned length = sqlite3_column_bytes(statement_ptr,col_idx);

              string_s *string_ptr = it.get_new_string_ptr();
              string_ptr->set(length,data);

              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
              row_array->push(new_location);
            }
            break;
          case SQLITE_NULL:
            ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
            row_array->push(it.blank_location);
            break;
          }
        } while(++col_idx < column_cnt);
      }

      step_res = sqlite3_step(statement_ptr);
    } while(step_res == SQLITE_ROW);
  }

  sqlite3_finalize(statement_ptr);

  // - ERROR -
  if (step_res != SQLITE_DONE)
  {
    it.release_location_ptr(res_array_loc);

    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_CONN_EXECUTE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(res_array_loc);

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_prepare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("prepare#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  sqlite3 *db_ptr = (sqlite3 *)dst_location->v_data_ptr;
  string_s *query_ptr = (string_s *)src_0_location->v_data_ptr;
  sqlite3_stmt *statement_ptr;

  // - ERROR -
  if (sqlite3_prepare_v2(db_ptr,query_ptr->data,query_ptr->size - 1,&statement_ptr,nullptr) != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_CONN_PREPARE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create sqlite statement object -
  sqlite_stmt_s *stmt_ptr = (sqlite_stmt_s *)cmalloc(sizeof(sqlite_stmt_s));
  stmt_ptr->init();

  stmt_ptr->stmt_ptr = statement_ptr;

  dst_location->v_reference_cnt.atomic_inc();
  stmt_ptr->db_ptr = dst_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sqlite_statement,stmt_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_errmsg_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  sqlite3 *db_ptr = (sqlite3 *)dst_location->v_data_ptr;
  const char *message = sqlite3_errmsg(db_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(message),message);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SQLiteConn"),"SQLiteConn");
  );

  return true;
}/*}}}*/

bool bic_sqlite_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SQLiteConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SQLITE_STATEMENT -
built_in_class_s sqlite_statement_class =
{/*{{{*/
  "SQLiteStatement",
  c_modifier_public | c_modifier_final,
  9, sqlite_statement_methods,
  0, sqlite_statement_variables,
  bic_sqlite_statement_consts,
  bic_sqlite_statement_init,
  bic_sqlite_statement_clear,
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

built_in_method_s sqlite_statement_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_operator_binary_equal
  },
  {
    "bind#2",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_method_bind_2
  },
  {
    "bind_blob#2",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_method_bind_blob_2
  },
  {
    "step#0",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_method_step_0
  },
  {
    "reset#0",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_method_reset_0
  },
  {
    "reset_clear#0",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_method_reset_clear_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_sqlite_statement_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sqlite_statement_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sqlite_statement_method_print_0
  },
};/*}}}*/

built_in_variable_s sqlite_statement_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_SQLITE_STATEMENT_RETRIEVE_BIND_INDEX(NAME) \
/*{{{*/\
  sqlite_stmt_s *stmt_ptr = (sqlite_stmt_s *)dst_location->v_data_ptr;\
  sqlite3_stmt *statement_ptr = stmt_ptr->stmt_ptr;\
\
  long long int index;\
\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    if (src_0_location->v_type == c_bi_class_string)\
    {\
      string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
      index = sqlite3_bind_parameter_index(statement_ptr,string_ptr->data);\
      \
      /* - ERROR - */\
      if (index <= 0)\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_BIND_UNKNOWN_HOST_PARAMETER_NAME,operands[c_source_pos_idx],src_0_location);\
        return false;\
      }\
    }\
\
    /* - ERROR - */\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(2);\
      new_exception->params.push(src_0_location->v_type);\
      new_exception->params.push(src_1_location->v_type);\
\
      return false;\
    }\
  }\
/*}}}*/

#define BIC_SQLITE_STATEMENT_NEXT_ITEM() \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  sqlite_stmt_s *stmt_ptr = (sqlite_stmt_s *)dst_location->v_data_ptr;\
\
  /* - if statement was completed - */\
  if (stmt_ptr->done)\
  {\
    BIC_SET_RESULT_BLANK();\
\
    return true;\
  }\
\
  /* - retrieve statement pointer - */\
  sqlite3_stmt *statement_ptr = stmt_ptr->stmt_ptr;\
\
  /* - retrieve next result row - */\
  int step_res = sqlite3_step(statement_ptr);\
  if (step_res == SQLITE_ROW)\
  {\
    int column_cnt = sqlite3_column_count(statement_ptr);\
\
    /* - create row array - */\
    pointer_array_s *row_array = it.get_new_array_ptr();\
    BIC_CREATE_NEW_LOCATION(row_array_loc,c_bi_class_array,row_array);\
\
    if (column_cnt > 0)\
    {\
      row_array->copy_resize(column_cnt);\
      \
      int col_idx = 0;\
      do {\
        switch (sqlite3_column_type(statement_ptr,col_idx))\
        {\
        case SQLITE_INTEGER:\
          {\
            sqlite3_int64 value = sqlite3_column_int64(statement_ptr,col_idx);\
\
            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
            row_array->push(new_location);\
          }\
          break;\
        case SQLITE_FLOAT:\
          {\
            double value = sqlite3_column_double(statement_ptr,col_idx);\
\
            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
            row_array->push(new_location);\
          }\
          break;\
        case SQLITE_TEXT:\
          {\
            const char *data = (const char *)sqlite3_column_text(statement_ptr,col_idx);\
            unsigned length = sqlite3_column_bytes(statement_ptr,col_idx);\
\
            string_s *string_ptr = it.get_new_string_ptr();\
            string_ptr->set(length,data);\
\
            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
            row_array->push(new_location);\
          }\
          break;\
        case SQLITE_BLOB:\
          {\
            const char *data = (const char *)sqlite3_column_blob(statement_ptr,col_idx);\
            unsigned length = sqlite3_column_bytes(statement_ptr,col_idx);\
\
            string_s *string_ptr = it.get_new_string_ptr();\
            string_ptr->set(length,data);\
\
            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
            row_array->push(new_location);\
          }\
          break;\
        case SQLITE_NULL:\
          ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
          row_array->push(it.blank_location);\
          break;\
        }\
      } while(++col_idx < column_cnt);\
    }\
\
    BIC_SET_RESULT(row_array_loc);\
\
    return true;\
  }\
\
  /* - ERROR - */\
  if (step_res != SQLITE_DONE)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_STEP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - mark statement as completed - */\
  stmt_ptr->done = true;\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_sqlite_statement_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_sqlite_statement_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (sqlite_stmt_s *)nullptr;
}/*}}}*/

void bic_sqlite_statement_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  sqlite_stmt_s *stmt_ptr = (sqlite_stmt_s *)location_ptr->v_data_ptr;

  if (stmt_ptr != nullptr)
  {
    stmt_ptr->clear(it);
    cfree(stmt_ptr);
  }
}/*}}}*/

bool bic_sqlite_statement_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sqlite_statement_method_bind_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  BIC_SQLITE_STATEMENT_RETRIEVE_BIND_INDEX("bind#2");

  int result = SQLITE_OK;
  switch (src_1_location->v_type)
  {
    case c_bi_class_blank:
      result = sqlite3_bind_null(statement_ptr,index);
      break;
    case c_bi_class_integer:
      {
        long long int value = (long long int)src_1_location->v_data_ptr;
        result = sqlite3_bind_int64(statement_ptr,index,value);
      }
      break;
    case c_bi_class_float:
      {
        double value = (double)src_1_location->v_data_ptr;
        result = sqlite3_bind_double(statement_ptr,index,value);
      }
      break;
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;
        result = sqlite3_bind_text(statement_ptr,index,string_ptr->data,string_ptr->size - 1,SQLITE_TRANSIENT);
      }
      break;

    // - ERROR -
    default:
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_BIND_UNSUPPORTED_TYPE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(src_1_location->v_type);

      return false;
  }

  // - ERROR -
  if (result != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_BIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_sqlite_statement_method_bind_blob_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  BIC_SQLITE_STATEMENT_RETRIEVE_BIND_INDEX("bind_blob#2");

  // - ERROR -
  if (src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("bind_blob#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
  }

  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (sqlite3_bind_blob(statement_ptr,index,string_ptr->data,string_ptr->size - 1,SQLITE_TRANSIENT) != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_BIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_sqlite_statement_method_step_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SQLITE_STATEMENT_NEXT_ITEM();
}/*}}}*/

bool bic_sqlite_statement_method_reset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve statement pointer -
  sqlite_stmt_s *stmt_ptr = (sqlite_stmt_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (sqlite3_reset(stmt_ptr->stmt_ptr) != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_RESET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - reset statement complete flag -
  stmt_ptr->done = false;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_sqlite_statement_method_reset_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve statement pointer -
  sqlite_stmt_s *stmt_ptr = (sqlite_stmt_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (sqlite3_reset(stmt_ptr->stmt_ptr) != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_RESET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (sqlite3_clear_bindings(stmt_ptr->stmt_ptr) != SQLITE_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SQLITE_STATEMENT_CLEAR_BINDINGS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - reset statement complete flag -
  stmt_ptr->done = false;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_sqlite_statement_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SQLITE_STATEMENT_NEXT_ITEM();
}/*}}}*/

bool bic_sqlite_statement_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SQLiteStatement"),"SQLiteStatement");
  );

  return true;
}/*}}}*/

bool bic_sqlite_statement_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SQLiteStatement");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

