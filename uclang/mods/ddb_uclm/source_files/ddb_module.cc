
// - ucf compilation control -
#define UCF_DISABLE_OPERATOR_NEW
#define UCF_DISABLE_PLACEMENT_NEW

@begin
include "ddb_module.h"
@end

// - DDB indexes of built in classes -
unsigned c_bi_class_ddb = c_idx_not_exist;
unsigned c_bi_class_trace_storage = c_idx_not_exist;
unsigned c_bi_class_trace_record = c_idx_not_exist;

// - DDB module -
built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  ddb_classes,         // Classes

  0,                   // Error base index
  10,                  // Error count
  ddb_error_strings,   // Error strings

  ddb_initialize,      // Initialize function
  ddb_print_exception, // Print exceptions function
};/*}}}*/

// - DDB classes -
built_in_class_s *ddb_classes[] =
{/*{{{*/
  &ddb_class,
  &trace_storage_class,
  &trace_record_class,
};/*}}}*/

// - DDB error strings -
const char *ddb_error_strings[] =
{/*{{{*/
  "error_DDB_OPEN_ERROR",
  "error_DDB_GET_TRACE_INDEX_ERROR",
  "error_DDB_GET_TRACE_NAME_ERROR",
  "error_TRACE_STORAGE_READ_ERROR",
  "error_TRACE_STORAGE_WRITE_ERROR",
  "error_TRACE_STORAGE_FIND_ERROR",
  "error_TRACE_STORAGE_ERASE_ERROR",
  "error_TRACE_STORAGE_WRONG_RECORD_TIME",
  "error_TRACE_STORAGE_DATA_SIZE_ERROR",
  "error_TRACE_STORAGE_INDEX_EXCEEDS_RANGE",
};/*}}}*/

// - DDB initialize -
bool ddb_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ddb class identifier -
  c_bi_class_ddb = class_base_idx++;

  // - initialize trace_storage class identifier -
  c_bi_class_trace_storage = class_base_idx++;

  // - initialize trace_record class identifier -
  c_bi_class_trace_record = class_base_idx++;

  return true;
}/*}}}*/

// - DDB print exception -
bool ddb_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_DDB_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open database \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DDB_GET_TRACE_INDEX_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving trace at index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DDB_GET_TRACE_NAME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving trace \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading record %" HOST_LL_FORMAT "d from trace storage\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing record to trace storage\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_FIND_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while searching for record in trace storage\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_ERASE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while erasing trace storage\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_WRONG_RECORD_TIME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong time %" HOST_LL_FORMAT "d of trace storage record\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_DATA_SIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data size %" HOST_LL_FORMAT "d according to trace storage record %" HOST_LL_FORMAT "d \n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRACE_STORAGE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds trace storage range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DDB -
built_in_class_s ddb_class =
{/*{{{*/
  "DDB",
  c_modifier_public | c_modifier_final,
  9, ddb_methods,
  0, ddb_variables,
  bic_ddb_consts,
  bic_ddb_init,
  bic_ddb_clear,
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

built_in_method_s ddb_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ddb_operator_binary_equal
  },
  {
    "DDB#2",
    c_modifier_public | c_modifier_final,
    bic_ddb_method_DDB_2
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_ddb_method_version_0
  },
  {
    "nEventDescs#0",
    c_modifier_public | c_modifier_final,
    bic_ddb_method_nEventDescs_0
  },
  {
    "nTraceDescs#0",
    c_modifier_public | c_modifier_final,
    bic_ddb_method_nTraceDescs_0
  },
  {
    "nSnapDescs#0",
    c_modifier_public | c_modifier_final,
    bic_ddb_method_nSnapDescs_0
  },
  {
    "GetTraceStorage#1",
    c_modifier_public | c_modifier_final,
    bic_ddb_method_GetTraceStorage_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ddb_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ddb_method_print_0
  },
};/*}}}*/

built_in_variable_s ddb_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ddb_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ddb_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ddb_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  DDB *ddb_ptr = (DDB *)location_ptr->v_data_ptr;

  if (ddb_ptr != NULL)
  {
    ddb_ptr->Close();
    delete ddb_ptr;
  }
}/*}}}*/

bool bic_ddb_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ddb_method_DDB_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_integer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("DDB#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve database name -
  string_s *ddb_name = (string_s *)src_0_location->v_data_ptr;

  // - retrieve load dtd flag -
  bool load_dtd = (long long int)src_1_location->v_data_ptr;

  // - create database pointer -
  DDB *ddb_ptr = new DDB(&g_log_ext);

  try
  {
    // - try to open diagnostic database -
    ddb_ptr->Open(ddb_name->data,load_dtd);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete ddb_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_DDB_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (basic_64b)ddb_ptr;

  return true;
}/*}}}*/

bool bic_ddb_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  DDB *ddb_ptr = (DDB *)dst_location->v_data_ptr;

  // - retrieve database version number -
  long long int result = ddb_ptr->GetDatabaseDesc()->version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ddb_method_nEventDescs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  DDB *ddb_ptr = (DDB *)dst_location->v_data_ptr;

  // - retrieve database version number -
  long long int result = ddb_ptr->GetDatabaseDesc()->nEventDescs;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ddb_method_nTraceDescs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  DDB *ddb_ptr = (DDB *)dst_location->v_data_ptr;

  // - retrieve database version number -
  long long int result = ddb_ptr->GetDatabaseDesc()->nTraceDescs;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ddb_method_nSnapDescs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  DDB *ddb_ptr = (DDB *)dst_location->v_data_ptr;

  // - retrieve database version number -
  long long int result = ddb_ptr->GetDatabaseDesc()->nSnapDescs;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ddb_method_GetTraceStorage_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  DDB *ddb_ptr = (DDB *)dst_location->v_data_ptr;
  TraceStorage *ts_ptr = NULL;

  if (src_0_location->v_type == c_bi_class_string)
  {
    // - retrieve requested trace name -
    string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

    // - retrieve count of trace descriptors -
    int td_cnt = ddb_ptr->GetDatabaseDesc()->nTraceDescs;
    if (td_cnt > 0)
    {
      int t_idx = 0;
      do
      {
        ts_ptr = ddb_ptr->GetTraceStorage(t_idx);
        if (ts_ptr != NULL && strcmp(name_ptr->data,ts_ptr->GetDesc()->name) == 0)
        {
          break;
        }
      }
      while(++t_idx < td_cnt);

      // - ERROR -
      if (t_idx >= td_cnt)
      {
        exception_s::throw_exception(it,module.error_base + c_error_DDB_GET_TRACE_NAME_ERROR,operands[c_source_pos_idx],src_0_location);
        return false;
      }
    }
  }
  else
  {
    long long int index;

    // - ERROR -
    if (!it.retrieve_integer(src_0_location,index))
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GetTraceStorage#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    ts_ptr = ddb_ptr->GetTraceStorage(index);

    // - ERORR -
    if (ts_ptr == NULL)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DDB_GET_TRACE_INDEX_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(index);

      return false;
    }
  }

  // - create new trace storage object -
  trace_storage_s *new_ts_ptr = (trace_storage_s *)cmalloc(sizeof(trace_storage_s));

  // - set reference to database -
  dst_location->v_reference_cnt.atomic_inc();
  new_ts_ptr->ddb_ptr = dst_location;

  // - set pointer to trace storage -
  new_ts_ptr->ts_ptr = ts_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trace_storage,new_ts_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ddb_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DDB"),"DDB")
  );

  return true;
}/*}}}*/

bool bic_ddb_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DDB");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRACE_STORAGE -
built_in_class_s trace_storage_class =
{/*{{{*/
  "TraceStorage",
  c_modifier_public | c_modifier_final,
  18, trace_storage_methods,
  0, trace_storage_variables,
  bic_trace_storage_consts,
  bic_trace_storage_init,
  bic_trace_storage_clear,
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

built_in_method_s trace_storage_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_operator_binary_le_br_re_br
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_name_0
  },
  {
    "capacity#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_capacity_0
  },
  {
    "recIdHead#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_recIdHead_0
  },
  {
    "recIdTail#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_recIdTail_0
  },
  {
    "Read#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_Read_1
  },
  {
    "Write#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_Write_1
  },
  {
    "Write#2",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_Write_2
  },
  {
    "Find#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_Find_1
  },
  {
    "FindId#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_FindId_1
  },
  {
    "Erase#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_Erase_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_trace_storage_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trace_storage_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trace_storage_method_print_0
  },
};/*}}}*/

built_in_variable_s trace_storage_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_TRACE_STORAGE_CHECK_INDEX() \
  /*{{{*/\
  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;\
  const TraceStorage::Desc *tsDesc = ts_ptr->ts_ptr->GetDesc();\
  \
  /* - ERROR - */\
  if ((QWORD)index < tsDesc->recIdTail || (QWORD)index > tsDesc->recIdHead) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_TRACE_STORAGE_ITEM(NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int index;\
    \
    /* - ERROR - */\
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
    \
    BIC_TRACE_STORAGE_CHECK_INDEX();\
    \
    /* - create target data string - */\
    string_s *data_ptr = (string_s *)it.get_new_string_ptr();\
    data_ptr->create(tsDesc->dataSize);\
    \
    /* - create new trace record object - */\
    trace_record_s *new_tr_ptr = (trace_record_s *)cmalloc(sizeof(trace_record_s));\
    new_tr_ptr->tr_ptr = new TraceRecord();\
    \
    TraceRecord &record = *new_tr_ptr->tr_ptr;\
    record.recId = index;\
    record.data = data_ptr->data;\
    record.size = tsDesc->dataSize;\
    \
    /* - read record from trace storage - */\
    try {\
      ts_ptr->ts_ptr->Read(record);\
    }\
    \
    /* - ERROR - */\
    catch (Exception e)\
    {\
      delete new_tr_ptr->tr_ptr;\
      cfree(new_tr_ptr);\
      data_ptr->clear();\
      cfree(data_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(index);\
      \
      return false;\
    }\
    \
    /* - if record is not valid - */\
    if (record.status != TraceRecord::REC_VALID)\
    {\
      delete new_tr_ptr->tr_ptr;\
      cfree(new_tr_ptr);\
      data_ptr->clear();\
      cfree(data_ptr);\
      \
      BIC_SET_RESULT_BLANK();\
    }\
    else  {\
      \
      /* - set reference to trace storage - */\
      dst_location->v_reference_cnt.atomic_inc();\
      new_tr_ptr->ts_ptr = dst_location;\
      \
      /* - create data string location - */\
      { \
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,data_ptr);\
        new_tr_ptr->data_ptr = new_location;\
      }\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trace_record,new_tr_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    \
    return true;\
  }/*}}}*/

void bic_trace_storage_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trace_storage_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_trace_storage_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trace_storage_s *ts_ptr = (trace_storage_s *)location_ptr->v_data_ptr;

  // - if trace storage exists -
  if (ts_ptr != NULL)
  {
    it.release_location_ptr(ts_ptr->ddb_ptr);
    cfree(ts_ptr);
  }
}/*}}}*/

bool bic_trace_storage_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trace_storage_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRACE_STORAGE_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_trace_storage_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  const char *name = ts_ptr->ts_ptr->GetDesc()->name;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_trace_storage_method_capacity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->ts_ptr->GetDesc()->capacity;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trace_storage_method_recIdHead_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->ts_ptr->GetDesc()->recIdHead;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trace_storage_method_recIdTail_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->ts_ptr->GetDesc()->recIdTail;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trace_storage_method_Read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRACE_STORAGE_ITEM("Read#1");
}/*}}}*/

bool bic_trace_storage_method_Erase_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  // - clear trace storage -
  try
  {
    ts_ptr->ts_ptr->Clear();
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_ERASE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_trace_storage_method_Write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve source data string -
  string_s *data_ptr = (string_s *)src_0_location->v_data_ptr;

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;
  const TraceStorage::Desc *tsDesc = ts_ptr->ts_ptr->GetDesc();

  // - ERROR -
  if (data_ptr->size - 1 != (unsigned)tsDesc->dataSize)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_DATA_SIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(data_ptr->size - 1);
    new_exception->params.push(tsDesc->dataSize);

    return false;
  }

  TraceRecord record;
  record.data = data_ptr->data;
  record.size = data_ptr->size - 1;

  // - write record to trace storage -
  try
  {
    ts_ptr->ts_ptr->Write(record);
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_trace_storage_method_Write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int record_time;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,record_time) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - ERROR -
  if (record_time < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_WRONG_RECORD_TIME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(record_time);

    return false;
  }

  // - retrieve source data string -
  string_s *data_ptr = (string_s *)src_1_location->v_data_ptr;

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;
  const TraceStorage::Desc *tsDesc = ts_ptr->ts_ptr->GetDesc();

  // - ERROR -
  if (data_ptr->size - 1 != (unsigned)tsDesc->dataSize)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_DATA_SIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(data_ptr->size - 1);
    new_exception->params.push(tsDesc->dataSize);

    return false;
  }

  TraceRecord record;
  record.recTime = record_time;
  record.data = data_ptr->data;
  record.size = data_ptr->size - 1;

  // - write record to trace storage -
  try
  {
    ts_ptr->ts_ptr->Write(record);
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_trace_storage_method_Find_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int record_time;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,record_time))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Find#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (record_time < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_WRONG_RECORD_TIME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(record_time);

    return false;
  }

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;
  const TraceStorage::Desc *tsDesc = ts_ptr->ts_ptr->GetDesc();

  // - write record to trace storage -
  try
  {
    // - create target data string -
    string_s *data_ptr = (string_s *)it.get_new_string_ptr();
    data_ptr->create(tsDesc->dataSize);
    
    // - create new trace record object -
    trace_record_s *new_tr_ptr = (trace_record_s *)cmalloc(sizeof(trace_record_s));
    new_tr_ptr->tr_ptr = new TraceRecord();
    
    TraceRecord &record = *new_tr_ptr->tr_ptr;
    record.data = data_ptr->data;
    record.size = tsDesc->dataSize;

    Time req_time(record_time);

    // - find requested record in trace storage -
    ts_ptr->ts_ptr->Find(record,req_time);

    if (record.status != TraceRecord::REC_EMPTY)
    {
      // - set reference to trace storage -
      dst_location->v_reference_cnt.atomic_inc();
      new_tr_ptr->ts_ptr = dst_location;
      
      // - create data string location -
      { 
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,data_ptr);
        new_tr_ptr->data_ptr = new_location;
      }
      
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trace_record,new_tr_ptr);
      BIC_SET_RESULT(new_location);
    }
    else {
      
      // - release trace record object -
      delete new_tr_ptr->tr_ptr;
      cfree(new_tr_ptr);

      // - release target data object -
      data_ptr->clear();
      cfree(data_ptr);

      BIC_SET_RESULT_BLANK();
    }
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_FIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_trace_storage_method_FindId_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int record_time;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,record_time))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FindId#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (record_time < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_WRONG_RECORD_TIME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(record_time);

    return false;
  }

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  // - try to find requested record -
  try
  {
    TraceRecord record;
    record.data = NULL;
    record.size = 0;

    Time req_time(record_time);

    // - find requested record in trace storage -
    ts_ptr->ts_ptr->Find(record,req_time);

    // - if record was found -
    if (record.status != TraceRecord::REC_EMPTY)
    {
      long long int result = record.recId;

      BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
    }

    // - if record was not found -
    else
    {
      BIC_SET_RESULT_BLANK();
    }
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRACE_STORAGE_FIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_trace_storage_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRACE_STORAGE_ITEM("item#1");
}/*}}}*/

bool bic_trace_storage_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;
  const TraceStorage::Desc *tsDesc = ts_ptr->ts_ptr->GetDesc();

  if (tsDesc->recIdHead != (QWORD)-1)
  {
    long long int result = tsDesc->recIdTail;
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_trace_storage_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_TRACE_STORAGE_CHECK_INDEX();

  if ((QWORD)(++index) <= tsDesc->recIdHead)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_trace_storage_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_storage_s *ts_ptr = (trace_storage_s *)dst_location->v_data_ptr;

  long long int result = ts_ptr->ts_ptr->GetNbRecords();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trace_storage_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TraceStorage"),"TraceStorage")
  );

  return true;
}/*}}}*/

bool bic_trace_storage_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("TraceStorage");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRACE_RECORD -
built_in_class_s trace_record_class =
{/*{{{*/
  "TraceRecord",
  c_modifier_public | c_modifier_final,
  6, trace_record_methods,
  0, trace_record_variables,
  bic_trace_record_consts,
  bic_trace_record_init,
  bic_trace_record_clear,
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

built_in_method_s trace_record_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trace_record_operator_binary_equal
  },
  {
    "GetId#0",
    c_modifier_public | c_modifier_final,
    bic_trace_record_method_GetId_0
  },
  {
    "GetTime#0",
    c_modifier_public | c_modifier_final,
    bic_trace_record_method_GetTime_0
  },
  {
    "GetData#0",
    c_modifier_public | c_modifier_final,
    bic_trace_record_method_GetData_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trace_record_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trace_record_method_print_0
  },
};/*}}}*/

built_in_variable_s trace_record_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trace_record_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trace_record_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_trace_record_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trace_record_s *tr_ptr = (trace_record_s *)location_ptr->v_data_ptr;

  // - if trace record exists -
  if (tr_ptr != NULL)
  {
    it.release_location_ptr(tr_ptr->ts_ptr);
    delete tr_ptr->tr_ptr;
    it.release_location_ptr(tr_ptr->data_ptr);
    cfree(tr_ptr);
  }
}/*}}}*/

bool bic_trace_record_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trace_record_method_GetId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_record_s *tr_ptr = (trace_record_s *)dst_location->v_data_ptr;

  long long int result = tr_ptr->tr_ptr->recId;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trace_record_method_GetTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_record_s *tr_ptr = (trace_record_s *)dst_location->v_data_ptr;

  long long int result = tr_ptr->tr_ptr->recTime;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trace_record_method_GetData_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trace_record_s *tr_ptr = (trace_record_s *)dst_location->v_data_ptr;

  tr_ptr->data_ptr->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(tr_ptr->data_ptr);

  return true;
}/*}}}*/

bool bic_trace_record_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TraceRecord"),"TraceRecord")
  );

  return true;
}/*}}}*/

bool bic_trace_record_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("TraceRecord");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

