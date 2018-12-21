
@begin
include "comelm_module.h"
@end

// - COMELM indexes of built in classes -
unsigned c_bi_class_elm_comm = c_idx_not_exist;
unsigned c_bi_class_elm_packet = c_idx_not_exist;

// - COMELM module -
built_in_module_s module =
{/*{{{*/
  2,                       // Class count
  comelm_classes,          // Classes

  0,                       // Error base index
  7,                       // Error count
  comelm_error_strings,    // Error strings

  comelm_initialize,       // Initialize function
  comelm_print_exception,  // Print exceptions function
};/*}}}*/

// - COMELM classes -
built_in_class_s *comelm_classes[] =
{/*{{{*/
  &elm_comm_class,
  &elm_packet_class,
};/*}}}*/

// - COMELM error strings -
const char *comelm_error_strings[] =
{/*{{{*/
  "error_ELM_COMM_INITIALIZATION_ERROR",
  "error_ELM_COMM_WRONG_MAX_TIME_DIFF_VALUE",
  "error_ELM_COMM_TIME_SYNC_ERROR",
  "error_ELM_COMM_WRONG_TIME_STRING",
  "error_ELM_COMM_NEGATIVE_OFFSET_VALUE",
  "error_ELM_COMM_NEGATIVE_COMM_SPEED_VALUE",
  "error_ELM_COMM_COMMUNICATION_ERROR",
};/*}}}*/

// - COMELM initialize -
bool comelm_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize elm_comm class identifier -
  c_bi_class_elm_comm = class_base_idx++;

  // - initialize elm_packet class identifier -
  c_bi_class_elm_packet = class_base_idx++;

  return true;
}/*}}}*/

// - COMELM print exception -
bool comelm_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_ELM_COMM_INITIALIZATION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating connection to energy meter\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ELM_COMM_WRONG_MAX_TIME_DIFF_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong maximal time difference value %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ELM_COMM_TIME_SYNC_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received during time synchronisation\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ELM_COMM_WRONG_TIME_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError wrong time string, expected format: \"yyyyMMddhhmmss\"\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ELM_COMM_NEGATIVE_OFFSET_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError negative value of read offset\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ELM_COMM_NEGATIVE_COMM_SPEED_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError negative value of requested communication speed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ELM_COMM_COMMUNICATION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while communicating with energy meter\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class ELM_COMM -
built_in_class_s elm_comm_class =
{/*{{{*/
  "ElmComm",
  c_modifier_public | c_modifier_final,
  10, elm_comm_methods,
  0, elm_comm_variables,
  bic_elm_comm_consts,
  bic_elm_comm_init,
  bic_elm_comm_clear,
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

built_in_method_s elm_comm_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_operator_binary_equal
  },
  {
    "ElmComm#4",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_ElmComm_4
  },
  {
    "check_sync_time#1",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_check_sync_time_1
  },
  {
    "read_identification#0",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_read_identification_0
  },
  {
    "read_actual#0",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_read_actual_0
  },
  {
    "read_index#2",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_read_index_2
  },
  {
    "read_delta#2",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_read_delta_2
  },
  {
    "write_init_speed#1",
    c_modifier_public | c_modifier_final,
    bic_elm_comm_method_write_init_speed_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_elm_comm_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_elm_comm_method_print_0
  },
};/*}}}*/

built_in_variable_s elm_comm_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_ELM_COMM_READ_LOAD_PROFILE(NAME,DELTA_VALUES) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);\
\
  long long int offset;\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string ||\
      !it.retrieve_integer(src_1_location,offset))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(2);\
    new_exception->params.push(src_0_location->v_type);\
    new_exception->params.push(src_1_location->v_type);\
\
    return false;\
  }\
\
  /* - retrieve start time - */\
  string_s *start_time_str = (string_s *)src_0_location->v_data_ptr;\
  Time start_time;\
\
  /* - ERROR - */\
  if (start_time_str->size != c_time_string_size ||\
      !_str_time(start_time_str->data,start_time))\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_WRONG_TIME_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (offset < 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_NEGATIVE_OFFSET_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - retrieve comm proc object pointer - */\
  CElmCommProc *ecp_ptr = (CElmCommProc *)dst_location->v_data_ptr;\
\
  /* - actual values string - */\
  CElmString load_str;\
\
  /* - read actual values from meter - */\
  bool res = ecp_ptr->cmd_ReadLoadProfile(start_time,offset,DELTA_VALUES,load_str);\
\
  /* - ERROR - */\
  if (!res)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_COMMUNICATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - convert CElmString to string_s - */\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->size = load_str.GetLength() + 1;\
  string_ptr->data = (char *)load_str.GetData();\
  load_str.Initialize();\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr)\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_elm_comm_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_elm_comm_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (CElmCommProc *)nullptr;
}/*}}}*/

void bic_elm_comm_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  CElmCommProc *ecp_ptr = (CElmCommProc *)location_ptr->v_data_ptr;

  if (ecp_ptr != nullptr)
  {
    delete ecp_ptr;
  }
}/*}}}*/

bool bic_elm_comm_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_elm_comm_method_ElmComm_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int init_speed;
  long long int read_speed;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,init_speed) ||
      !it.retrieve_integer(src_3_location,read_speed))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ElmComm#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - retrieve comm port name -
  string_s *port_name = (string_s *)src_0_location->v_data_ptr;

  // - retrieve device name -
  string_s *device_name = (string_s *)src_1_location->v_data_ptr;

  // - create comm proc object -
  CElmCommProc *ecp_ptr = new CElmCommProc();

  // - initialize comm port object -
  if (!ecp_ptr->Init(port_name->data,device_name->data,init_speed,read_speed))
  {
    delete ecp_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_INITIALIZATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (CElmCommProc *)ecp_ptr;

  return true;
}/*}}}*/

bool bic_elm_comm_method_check_sync_time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int max_time_diff;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,max_time_diff))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("check_sync_time#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (max_time_diff < 0 || max_time_diff > UINT_MAX)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_WRONG_MAX_TIME_DIFF_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(max_time_diff);

    return false;
  }

  // - retrieve comm proc object pointer -
  CElmCommProc *ecp_ptr = (CElmCommProc *)dst_location->v_data_ptr;

  // - synchronise meter time to system time -
  bool res = ecp_ptr->cmd_CheckSyncTime(max_time_diff);

  // - ERROR -
  if (!res)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_TIME_SYNC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_elm_comm_method_read_identification_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve comm proc object pointer -
  CElmCommProc *ecp_ptr = (CElmCommProc *)dst_location->v_data_ptr;

  // - array of identification strings -
  const unsigned id_cnt = 5;
  CElmString id_arr[id_cnt];

  // - read identification values from meter -
  bool res = ecp_ptr->cmd_ReadIdentification(id_arr[0],id_arr[1],id_arr[2],id_arr[3],id_arr[4]);

  // - ERROR -
  if (!res)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_COMMUNICATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  array_ptr->copy_resize(id_cnt);
  array_ptr->used = id_cnt;

  unsigned id_idx = 0;
  do {
    CElmString &id_str = id_arr[id_idx];

    // - convert CElmString to string_s -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->size = id_str.GetLength() + 1;
    string_ptr->data = (char *)id_str.GetData();
    id_str.Initialize();

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr)
    array_ptr->data[id_idx] = (pointer)new_location;

  } while(++id_idx < id_cnt);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_elm_comm_method_read_actual_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve comm proc object pointer -
  CElmCommProc *ecp_ptr = (CElmCommProc *)dst_location->v_data_ptr;

  // - actual values string -
  CElmString actual_str;

  // - read actual values from meter -
  bool res = ecp_ptr->cmd_ReadActual(actual_str);

  // - ERROR -
  if (!res)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_COMMUNICATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - convert CElmString to string_s -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = actual_str.GetLength() + 1;
  string_ptr->data = (char *)actual_str.GetData();
  actual_str.Initialize();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr)
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_elm_comm_method_read_index_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ELM_COMM_READ_LOAD_PROFILE("read_index#2",false);
}/*}}}*/

bool bic_elm_comm_method_read_delta_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ELM_COMM_READ_LOAD_PROFILE("read_delta#2",true);
}/*}}}*/

bool bic_elm_comm_method_write_init_speed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int init_speed;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,init_speed))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write_init_speed#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (init_speed < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_NEGATIVE_COMM_SPEED_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve comm proc object pointer -
  CElmCommProc *ecp_ptr = (CElmCommProc *)dst_location->v_data_ptr;

  // - set meter initial communication speed -
  bool res = ecp_ptr->cmd_WriteInitSpeed(init_speed);

  // - ERROR -
  if (!res)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ELM_COMM_COMMUNICATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_elm_comm_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ElmComm"),"ElmComm")
  );

  return true;
}/*}}}*/

bool bic_elm_comm_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ElmComm");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ELM_PACKET -
built_in_class_s elm_packet_class =
{/*{{{*/
  "ElmPacket",
  c_modifier_public | c_modifier_final,
  4, elm_packet_methods,
  8, elm_packet_variables,
  bic_elm_packet_consts,
  bic_elm_packet_init,
  bic_elm_packet_clear,
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

built_in_method_s elm_packet_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_elm_packet_operator_binary_equal
  },
  {
    "ElmPacket#0",
    c_modifier_public | c_modifier_final,
    bic_elm_packet_method_ElmPacket_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_elm_packet_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_elm_packet_method_print_0
  },
};/*}}}*/

built_in_variable_s elm_packet_variables[] =
{/*{{{*/
  {
    "PACKET_ADDRESS",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_IDENTIFY",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_ACK_COMMAND",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_ACK",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_NOT_ACK",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_DATA",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_PROG_DATA",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PACKET_PROG_COMMAND",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_elm_packet_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert standard file stream constants -
  {
    const_locations.push_blanks(8);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 8);

#define CREATE_ELM_PACKET_BIC_STATIC(PACKET_TYPE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)PACKET_TYPE;\
  cv_ptr++;

    CREATE_ELM_PACKET_BIC_STATIC(PACKET_ADDRESS);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_IDENTIFY);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_ACK_COMMAND);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_ACK);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_NOT_ACK);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_DATA);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_PROG_DATA);
    CREATE_ELM_PACKET_BIC_STATIC(PACKET_PROG_COMMAND);
  }
}/*}}}*/

void bic_elm_packet_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pointer)nullptr;
}/*}}}*/

void bic_elm_packet_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_elm_packet_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_elm_packet_method_ElmPacket_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_elm_packet_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ElmPacket"),"ElmPacket")
  );

  return true;
}/*}}}*/

bool bic_elm_packet_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ElmPacket");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

