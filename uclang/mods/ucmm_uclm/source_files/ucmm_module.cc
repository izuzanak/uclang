
@begin
include "ucmm_module.h"
@end

// - UCMM indexes of built in classes -
unsigned c_bi_class_modem_manager = c_idx_not_exist;
unsigned c_bi_class_mm_device_info = c_idx_not_exist;
unsigned c_bi_class_mm_network_info = c_idx_not_exist;

// - UCMM module -
built_in_module_s module =
{/*{{{*/
  3,                    // Class count
  ucmm_classes,         // Classes

  0,                    // Error base index
  5,                    // Error count
  ucmm_error_strings,   // Error strings

  ucmm_initialize,      // Initialize function
  ucmm_print_exception, // Print exceptions function
};/*}}}*/

// - UCMM classes -
built_in_class_s *ucmm_classes[] =
{/*{{{*/
  &modem_manager_class,
  &mm_device_info_class,
  &mm_network_info_class,
};/*}}}*/

// - UCMM error strings -
const char *ucmm_error_strings[] =
{/*{{{*/
  "error_MODEM_MANAGER_CREATE_ERROR",
  "error_MODEM_MANAGER_DEVICE_INFO_READ_ERROR",
  "error_MODEM_MANAGER_NETWORK_INFO_READ_ERROR",
  "error_MODEM_MANAGER_SUBSCRIBER_ID_READ_ERROR",
  "error_MODEM_MANAGER_AT_COMMAND_ERROR",
};/*}}}*/

// - UCMM initialize -
bool ucmm_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize modem_manager class identifier -
  c_bi_class_modem_manager = class_base_idx++;

  // - initialize mm_device_info class identifier -
  c_bi_class_mm_device_info = class_base_idx++;

  // - initialize mm_network_info class identifier -
  c_bi_class_mm_network_info = class_base_idx++;

  return true;
}/*}}}*/

// - UCMM print exception -
bool ucmm_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_MODEM_MANAGER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while opening slot %" HOST_LL_FORMAT "d for modem manager\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MODEM_MANAGER_DEVICE_INFO_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while reading information about device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MODEM_MANAGER_NETWORK_INFO_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while reading information about network\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MODEM_MANAGER_SUBSCRIBER_ID_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while reading subscriber id\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MODEM_MANAGER_AT_COMMAND_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while executing AT command\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class MODEM_MANAGER -
built_in_class_s modem_manager_class =
{/*{{{*/
  "ModemManager",
  c_modifier_public | c_modifier_final,
  8, modem_manager_methods,
  0, modem_manager_variables,
  bic_modem_manager_consts,
  bic_modem_manager_init,
  bic_modem_manager_clear,
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

built_in_method_s modem_manager_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_operator_binary_equal
  },
  {
    "ModemManager#1",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_method_ModemManager_1
  },
  {
    "device_info#0",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_method_device_info_0
  },
  {
    "network_info#0",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_method_network_info_0
  },
  {
    "subscriber_id#0",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_method_subscriber_id_0
  },
  {
    "at_command#1",
    c_modifier_public | c_modifier_final,
    bic_modem_manager_method_at_command_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_modem_manager_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_modem_manager_method_print_0
  },
};/*}}}*/

built_in_variable_s modem_manager_variables[] =
{/*{{{*/
};/*}}}*/

void bic_modem_manager_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_modem_manager_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_modem_manager_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ModemManager *mm_ptr = (ModemManager *)location_ptr->v_data_ptr;

  if (mm_ptr != NULL)
  {
    mm_ptr->Close();

    delete mm_ptr;
  }
}/*}}}*/

bool bic_modem_manager_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_modem_manager_method_ModemManager_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int slot;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,slot))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ModemManager#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ModemManager *mm_ptr = new ModemManager();

  try
  {
    mm_ptr->Open(slot);
  }

  // - ERROR -
  catch (...)
  {
    delete mm_ptr;

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MODEM_MANAGER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(slot);

    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (basic_64b)mm_ptr;

  return true;
}/*}}}*/

bool bic_modem_manager_method_device_info_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  DeviceInfo di;

  try 
  {
    // - retrieve device info -
    di = ((ModemManager *)dst_location->v_data_ptr)->GetDeviceInfo();
  }

  // - ERROR -
  catch (...)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MODEM_MANAGER_DEVICE_INFO_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create device info object -
  device_info_s *di_ptr = (device_info_s *)cmalloc(sizeof(device_info_s));
  di_ptr->init();

#define BIC_NEW_MM_DEVICE_INFO_LOCATION(TRG_NAME,SRC_NAME) \
{/*{{{*/\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(di.SRC_NAME.length(),di.SRC_NAME.data());\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr)\
  di_ptr->TRG_NAME = new_location;\
}/*}}}*/

  // - create device info locations -
  BIC_NEW_MM_DEVICE_INFO_LOCATION(manufacturer,manufacturer);
  BIC_NEW_MM_DEVICE_INFO_LOCATION(model,model);
  BIC_NEW_MM_DEVICE_INFO_LOCATION(revision,revision);
  BIC_NEW_MM_DEVICE_INFO_LOCATION(device_id,deviceId);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mm_device_info,di_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_modem_manager_method_network_info_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  NetworkInfo ni;

  try 
  {
    // - retrieve network info -
    ni = ((ModemManager *)dst_location->v_data_ptr)->GetNetworkInfo();
  }

  // - ERROR -
  catch (...)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MODEM_MANAGER_NETWORK_INFO_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create network info object -
  network_info_s *ni_ptr = (network_info_s *)cmalloc(sizeof(network_info_s));
  ni_ptr->init();

  ni_ptr->status = ni.status;
  ni_ptr->type   = ni.type;
  ni_ptr->signal = ni.signalStrength;

#define BIC_NEW_MM_NETWORK_INFO_LOCATION_STR(TRG_NAME,SRC_NAME) \
{/*{{{*/\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(ni.SRC_NAME.length(),ni.SRC_NAME.data());\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr)\
  ni_ptr->TRG_NAME = new_location;\
}/*}}}*/

  // - create network info string locations -
  BIC_NEW_MM_NETWORK_INFO_LOCATION_STR(oper_name,operatorName);
  BIC_NEW_MM_NETWORK_INFO_LOCATION_STR(oper_code,operatorCode);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mm_network_info,ni_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_modem_manager_method_subscriber_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve subscriber id -
  std::string sub_id;

  try
  {
    sub_id = ((ModemManager *)dst_location->v_data_ptr)->GetSubscriberId();
  }

  // - ERROR -
  catch (...)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MODEM_MANAGER_SUBSCRIBER_ID_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(sub_id.length(),sub_id.data());

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_modem_manager_method_at_command_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("at_command#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ModemManager *mm_ptr = (ModemManager *)dst_location->v_data_ptr;
  string_s *command_ptr = (string_s *)src_0_location->v_data_ptr;

  std::string resp;

  try
  {
    resp = mm_ptr->AtCommand(std::string(command_ptr->data,command_ptr->size - 1));
  }

  // - ERROR -
  catch (...)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MODEM_MANAGER_AT_COMMAND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(resp.length(),resp.data());

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_modem_manager_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ModemManager"),"ModemManager");
  );

  return true;
}/*}}}*/

bool bic_modem_manager_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ModemManager");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MM_DEVICE_INFO -
built_in_class_s mm_device_info_class =
{/*{{{*/
  "MMDeviceInfo",
  c_modifier_public | c_modifier_final,
  7, mm_device_info_methods,
  0, mm_device_info_variables,
  bic_mm_device_info_consts,
  bic_mm_device_info_init,
  bic_mm_device_info_clear,
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

built_in_method_s mm_device_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mm_device_info_operator_binary_equal
  },
  {
    "manufacturer#0",
    c_modifier_public | c_modifier_final,
    bic_mm_device_info_method_manufacturer_0
  },
  {
    "model#0",
    c_modifier_public | c_modifier_final,
    bic_mm_device_info_method_model_0
  },
  {
    "revision#0",
    c_modifier_public | c_modifier_final,
    bic_mm_device_info_method_revision_0
  },
  {
    "device_id#0",
    c_modifier_public | c_modifier_final,
    bic_mm_device_info_method_device_id_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mm_device_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mm_device_info_method_print_0
  },
};/*}}}*/

built_in_variable_s mm_device_info_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_MM_DEVICE_INFO_GET_VALUE(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  location_s *tmp_location = ((device_info_s *)dst_location->v_data_ptr)->NAME;\
  tmp_location->v_reference_cnt.atomic_inc();\
\
  BIC_SET_RESULT(tmp_location);\
\
  return true;\
}/*}}}*/

void bic_mm_device_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mm_device_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_mm_device_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  device_info_s *di_ptr = (device_info_s *)location_ptr->v_data_ptr;

  if (di_ptr != NULL)
  {
    di_ptr->clear(it);
    cfree(di_ptr);
  }
}/*}}}*/

bool bic_mm_device_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mm_device_info_method_manufacturer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_DEVICE_INFO_GET_VALUE(manufacturer);
}/*}}}*/

bool bic_mm_device_info_method_model_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_DEVICE_INFO_GET_VALUE(model);
}/*}}}*/

bool bic_mm_device_info_method_revision_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_DEVICE_INFO_GET_VALUE(revision);
}/*}}}*/

bool bic_mm_device_info_method_device_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_DEVICE_INFO_GET_VALUE(device_id);
}/*}}}*/

bool bic_mm_device_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MMDeviceInfo"),"MMDeviceInfo");
  );

  return true;
}/*}}}*/

bool bic_mm_device_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MMDeviceInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MM_NETWORK_INFO -
built_in_class_s mm_network_info_class =
{/*{{{*/
  "MMNetworkInfo",
  c_modifier_public | c_modifier_final,
  8, mm_network_info_methods,
  0, mm_network_info_variables,
  bic_mm_network_info_consts,
  bic_mm_network_info_init,
  bic_mm_network_info_clear,
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

built_in_method_s mm_network_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mm_network_info_operator_binary_equal
  },
  {
    "status#0",
    c_modifier_public | c_modifier_final,
    bic_mm_network_info_method_status_0
  },
  {
    "net_type#0",
    c_modifier_public | c_modifier_final,
    bic_mm_network_info_method_net_type_0
  },
  {
    "oper_name#0",
    c_modifier_public | c_modifier_final,
    bic_mm_network_info_method_oper_name_0
  },
  {
    "oper_code#0",
    c_modifier_public | c_modifier_final,
    bic_mm_network_info_method_oper_code_0
  },
  {
    "signal#0",
    c_modifier_public | c_modifier_final,
    bic_mm_network_info_method_signal_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mm_network_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mm_network_info_method_print_0
  },
};/*}}}*/

built_in_variable_s mm_network_info_variables[] =
{/*{{{*/
};/*}}}*/

void bic_mm_network_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mm_network_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_mm_network_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  network_info_s *ni_ptr = (network_info_s *)location_ptr->v_data_ptr;

  if (ni_ptr != NULL)
  {
    ni_ptr->clear(it);
    cfree(ni_ptr);
  }
}/*}}}*/

bool bic_mm_network_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_MM_NETWORK_INFO_GET_VALUE_INTEGER(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  long long int result = ((network_info_s *)dst_location->v_data_ptr)->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_MM_NETWORK_INFO_GET_VALUE_STRING(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  location_s *tmp_location = ((network_info_s *)dst_location->v_data_ptr)->NAME;\
  tmp_location->v_reference_cnt.atomic_inc();\
\
  BIC_SET_RESULT(tmp_location);\
\
  return true;\
}/*}}}*/

bool bic_mm_network_info_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_NETWORK_INFO_GET_VALUE_INTEGER(status);
}/*}}}*/

bool bic_mm_network_info_method_net_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_NETWORK_INFO_GET_VALUE_INTEGER(type);
}/*}}}*/

bool bic_mm_network_info_method_oper_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_NETWORK_INFO_GET_VALUE_STRING(oper_name);
}/*}}}*/

bool bic_mm_network_info_method_oper_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_NETWORK_INFO_GET_VALUE_STRING(oper_code);
}/*}}}*/

bool bic_mm_network_info_method_signal_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MM_NETWORK_INFO_GET_VALUE_INTEGER(signal);
}/*}}}*/

bool bic_mm_network_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MMNetworkInfo"),"MMNetworkInfo");
  );

  return true;
}/*}}}*/

bool bic_mm_network_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MMNetworkInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

