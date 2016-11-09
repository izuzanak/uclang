
@begin
include "android_module.h"
@end

// - ANDROID indexes of built in classes -
unsigned c_bi_class_sys_prop = c_idx_not_exist;
unsigned c_bi_class_log = c_idx_not_exist;
unsigned c_bi_class_activity = c_idx_not_exist;
unsigned c_bi_class_event = c_idx_not_exist;
unsigned c_bi_class_sensor_manager = c_idx_not_exist;
unsigned c_bi_class_sensor = c_idx_not_exist;
unsigned c_bi_class_sensor_event_queue = c_idx_not_exist;
unsigned c_bi_class_sensor_event = c_idx_not_exist;

// - ANDROID module -
built_in_module_s module =
{/*{{{*/
  8,                       // Class count
  android_classes,         // Classes
  0,                       // Error base index
  10,                      // Error count
  android_error_strings,   // Error strings

  android_initialize,      // Initialize function
  android_print_exception, // Print exceptions function
};/*}}}*/

// - ANDROID classes -
built_in_class_s *android_classes[] =
{/*{{{*/
  &sys_prop_class,
  &log_class,
  &activity_class,
  &event_class,
  &sensor_manager_class,
  &sensor_class,
  &sensor_event_queue_class,
  &sensor_event_class,
};/*}}}*/

// - ANDROID error strings -
const char *android_error_strings[] =
{/*{{{*/
  "error_SYS_PROP_NOT_EXIST",
  "error_SYS_PROP_NOT_SELECTED",
  "error_ACTIVITY_CONNECTION_DOES_NOT_EXIST",
  "error_ACTIVITY_OBJECT_ALREADY_CREATED",
  "error_ACTIVITY_WRONG_CALLBACK_DELEGATE",
  "error_ACTIVITY_EVENT_LOOP_IS_ALREADY_RUNNING",
  "error_SENSOR_MANAGER_CANNOT_CREATE_EVENT_QUEUE",
  "error_SENSOR_EVENT_QUEUE_CANNOT_ENABLE_SENSOR",
  "error_SENSOR_EVENT_QUEUE_CANNOT_DISABLE_SENSOR",
  "error_SENSOR_EVENT_QUEUE_SET_EVENT_RATE_ERROR",
};/*}}}*/

// - ANDROID initialize -
bool android_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize sys_prop class identifier -
  c_bi_class_sys_prop = class_base_idx++;

  // - initialize log class identifier -
  c_bi_class_log = class_base_idx++;

  // - initialize activity class identifier -
  c_bi_class_activity = class_base_idx++;

  // - initialize event class identifier -
  c_bi_class_event = class_base_idx++;

  // - initialize sensor_manager class identifier -
  c_bi_class_sensor_manager = class_base_idx++;

  // - initialize sensor class identifier -
  c_bi_class_sensor = class_base_idx++;

  // - initialize sensor_event_queue class identifier -
  c_bi_class_sensor_event_queue = class_base_idx++;

  // - initialize sensor_event class identifier -
  c_bi_class_sensor_event = class_base_idx++;

  return true;
}/*}}}*/

// - ANDROID print exception -
bool android_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SYS_PROP_NOT_EXIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSystem property does not exist\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SYS_PROP_NOT_SELECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSystem property not selected yet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ACTIVITY_CONNECTION_DOES_NOT_EXIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNative activity connection does not exist\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ACTIVITY_OBJECT_ALREADY_CREATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nActivity object was already created\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ACTIVITY_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for this activity callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ACTIVITY_EVENT_LOOP_IS_ALREADY_RUNNING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nActivity event loop is already running\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SENSOR_MANAGER_CANNOT_CREATE_EVENT_QUEUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSensor manager cannot create sensor event queue\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SENSOR_EVENT_QUEUE_CANNOT_ENABLE_SENSOR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while enabling sensor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SENSOR_EVENT_QUEUE_CANNOT_DISABLE_SENSOR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while disabling sensor\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SENSOR_EVENT_QUEUE_SET_EVENT_RATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while setting sensor event rate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class SYS_PROP -
built_in_class_s sys_prop_class =
{/*{{{*/
  "SysProp",
  c_modifier_public | c_modifier_final,
  7, sys_prop_methods,
  0, sys_prop_variables,
  bic_sys_prop_consts,
  bic_sys_prop_init,
  bic_sys_prop_clear,
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

built_in_method_s sys_prop_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sys_prop_operator_binary_equal
  },
  {
    "SysProp#1",
    c_modifier_public | c_modifier_final,
    bic_sys_prop_method_SysProp_1
  },
  {
    "get#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_prop_method_get_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_sys_prop_method_value_0
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_sys_prop_method_read_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_prop_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sys_prop_method_print_0
  },
};/*}}}*/

built_in_variable_s sys_prop_variables[] =
{/*{{{*/
};/*}}}*/

void bic_sys_prop_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_sys_prop_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (prop_info *)NULL;
}/*}}}*/

void bic_sys_prop_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_sys_prop_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sys_prop_method_SysProp_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int nth_prop;
  const prop_info *prop_info_ptr;

  if (it.retrieve_integer(src_0_location,nth_prop))
  {
    // - retrieve nth property info -
    prop_info_ptr = __system_property_find_nth(nth_prop);
  }
  else
  {
    if (src_0_location->v_type == c_bi_class_string)
    {
      // - retrieve property name -
      string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

      // - retrieve property info by its name -
      prop_info_ptr = __system_property_find(name_ptr->data);
    }
    else
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("SysProp#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  // - ERORR -
  if (prop_info_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_PROP_NOT_EXIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set property info pointer -
  dst_location->v_data_ptr = (prop_info *)prop_info_ptr;

  return true;
}/*}}}*/

bool bic_sys_prop_method_get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sys_prop,"get#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve name string -
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create target value string -
  string_s *value_ptr = it.get_new_string_ptr();
  value_ptr->create(PROP_VALUE_MAX);

  // - get property value -
  value_ptr->size = 1 + __system_property_get(name_ptr->data,value_ptr->data);

  BIC_SET_RESULT_STRING(value_ptr);

  return true;
}/*}}}*/

bool bic_sys_prop_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve property info pointer -
  prop_info *prop_info_ptr = (prop_info *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (prop_info_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_PROP_NOT_SELECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target value string -
  string_s *value_ptr = it.get_new_string_ptr();
  value_ptr->create(PROP_VALUE_MAX);

  // - read property value -
  value_ptr->size = 1 + __system_property_read(prop_info_ptr,NULL,value_ptr->data);

  BIC_SET_RESULT_STRING(value_ptr);

  return true;
}/*}}}*/

bool bic_sys_prop_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve property info pointer -
  prop_info *prop_info_ptr = (prop_info *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (prop_info_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SYS_PROP_NOT_SELECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target name string -
  string_s *name_ptr = it.get_new_string_ptr();
  name_ptr->create(PROP_NAME_MAX);

  // - create target value string -
  string_s *value_ptr = it.get_new_string_ptr();
  value_ptr->create(PROP_VALUE_MAX);

  // - read property value -
  value_ptr->size = 1 + __system_property_read(prop_info_ptr,name_ptr->data,value_ptr->data);

  // - compute property name length -
  name_ptr->size = strlen(name_ptr->data) + 1;

  // - create target array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  array_ptr->copy_resize(2);

  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,name_ptr);
    array_ptr->push(new_location);
  }

  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,value_ptr);
    array_ptr->push(new_location);
  }

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sys_prop_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SysProp"),"SysProp")
  );

  return true;
}/*}}}*/

bool bic_sys_prop_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SysProp");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class LOG -
built_in_class_s log_class =
{/*{{{*/
  "Log",
  c_modifier_public | c_modifier_final,
  8, log_methods,
  9, log_variables,
  bic_log_consts,
  bic_log_init,
  bic_log_clear,
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

built_in_method_s log_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_log_operator_binary_equal
  },
  {
    "Log#1",
    c_modifier_public | c_modifier_final,
    bic_log_method_Log_1
  },
  {
    "write#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_log_method_write_3
  },
  {
    "info#1",
    c_modifier_public | c_modifier_final,
    bic_log_method_info_1
  },
  {
    "warning#1",
    c_modifier_public | c_modifier_final,
    bic_log_method_warning_1
  },
  {
    "error#1",
    c_modifier_public | c_modifier_final,
    bic_log_method_error_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_log_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_log_method_print_0
  },
};/*}}}*/

built_in_variable_s log_variables[] =
{/*{{{*/
  { "LOG_UNKNOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_DEFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_VERBOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_DEBUG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_INFO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_WARN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_FATAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOG_SILENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_LOG_MESSAGE_LOG(NAME,PRIORITY) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  log_s *log_ptr = (log_s *)dst_location->v_data_ptr;\
  string_s *text_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - write android log message - */\
  __android_log_write(PRIORITY,log_ptr->tag.data,text_ptr->data);\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_log_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert log priority constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_LOG_PRIORITY_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_UNKNOWN);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_DEFAULT);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_VERBOSE);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_DEBUG);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_INFO);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_WARN);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_ERROR);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_FATAL);
    CREATE_LOG_PRIORITY_BIC_STATIC(ANDROID_LOG_SILENT);
  }
}/*}}}*/

void bic_log_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (log_s *)NULL;
}/*}}}*/

void bic_log_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  log_s *log_ptr = (log_s *)location_ptr->v_data_ptr;

  if (log_ptr != NULL)
  {
    log_ptr->clear(it);
    cfree(log_ptr);
  }
}/*}}}*/

bool bic_log_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_log_method_Log_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Log#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *tag_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create log object -
  log_s *log_ptr = (log_s *)cmalloc(sizeof(log_s));
  log_ptr->init();

  log_ptr->tag = *tag_ptr;

  // - set property info pointer -
  dst_location->v_data_ptr = (log_s *)log_ptr;

  return true;
}/*}}}*/

bool bic_log_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int priority;

  if (!it.retrieve_integer(src_0_location,priority) ||
      src_1_location->v_type != c_bi_class_string ||
      src_2_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_log,"write#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  string_s *tag_ptr = (string_s *)src_1_location->v_data_ptr;
  string_s *text_ptr = (string_s *)src_2_location->v_data_ptr;

  // - write android log message -
  __android_log_write(priority,tag_ptr->data,text_ptr->data);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_log_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_LOG_MESSAGE_LOG("info#1",ANDROID_LOG_INFO);
}/*}}}*/

bool bic_log_method_warning_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_LOG_MESSAGE_LOG("warning#1",ANDROID_LOG_WARN);
}/*}}}*/

bool bic_log_method_error_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_LOG_MESSAGE_LOG("error#1",ANDROID_LOG_ERROR);
}/*}}}*/

bool bic_log_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Log"),"Log")
  );

  return true;
}/*}}}*/

bool bic_log_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Log");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ACTIVITY -
built_in_class_s activity_class =
{/*{{{*/
  "Activity",
  c_modifier_public | c_modifier_final,
  14, activity_methods,
  16, activity_variables,
  bic_activity_consts,
  bic_activity_init,
  bic_activity_clear,
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

built_in_method_s activity_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_activity_operator_binary_equal
  },
  {
    "Activity#0",
    c_modifier_public | c_modifier_final,
    bic_activity_method_Activity_0
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_activity_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_activity_method_height_0
  },
  {
    "on_resize#1",
    c_modifier_public | c_modifier_final,
    bic_activity_method_on_resize_1
  },
  {
    "on_display#1",
    c_modifier_public | c_modifier_final,
    bic_activity_method_on_display_1
  },
  {
    "on_input#1",
    c_modifier_public | c_modifier_final,
    bic_activity_method_on_input_1
  },
  {
    "on_command#1",
    c_modifier_public | c_modifier_final,
    bic_activity_method_on_command_1
  },
  {
    "on_sensor#1",
    c_modifier_public | c_modifier_final,
    bic_activity_method_on_sensor_1
  },
  {
    "on_idle#1",
    c_modifier_public | c_modifier_final,
    bic_activity_method_on_idle_1
  },
  {
    "event_loop#0",
    c_modifier_public | c_modifier_final,
    bic_activity_method_event_loop_0
  },
  {
    "post_redisplay#0",
    c_modifier_public | c_modifier_final,
    bic_activity_method_post_redisplay_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_activity_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_activity_method_print_0
  },
};/*}}}*/

built_in_variable_s activity_variables[] =
{/*{{{*/
  { "APP_CMD_INPUT_CHANGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_INIT_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_TERM_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_WINDOW_RESIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_WINDOW_REDRAW_NEEDED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_CONTENT_RECT_CHANGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_GAINED_FOCUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_LOST_FOCUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_CONFIG_CHANGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_LOW_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_START", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_RESUME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_SAVE_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_PAUSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_STOP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "APP_CMD_DESTROY", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_ACTIVITY_DELEGATE_CHECK(LOCATION,PARAM_CNT) \
{/*{{{*/\
\
  /* - retrieve delegate pointer - */\
  delegate_s *delegate_ptr = (delegate_s *)(LOCATION)->v_data_ptr;\
\
  /* - ERROR - */\
  if (delegate_ptr->param_cnt != PARAM_CNT)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ACTIVITY_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

#define BIC_ACTIVITY_DELEGATE(NAME,DLG_PTR_NAME,PARAM_CNT) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_delegate)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  BIC_ACTIVITY_DELEGATE_CHECK(src_0_location,PARAM_CNT);\
\
  /* - release previous delegate - */\
  if (DLG_PTR_NAME != NULL)\
  {\
    it.release_location_ptr(DLG_PTR_NAME);\
  }\
\
  /* - register new delegate - */\
  src_0_location->v_reference_cnt.atomic_inc();\
  DLG_PTR_NAME = src_0_location;\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_activity_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert activity command constants -
  {
    const_locations.push_blanks(16);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 16);

#define CREATE_ACTIVITY_COMMAND_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_INPUT_CHANGED);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_INIT_WINDOW);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_TERM_WINDOW);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_WINDOW_RESIZED);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_WINDOW_REDRAW_NEEDED);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_CONTENT_RECT_CHANGED);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_GAINED_FOCUS);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_LOST_FOCUS);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_CONFIG_CHANGED);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_LOW_MEMORY);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_START);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_RESUME);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_SAVE_STATE);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_PAUSE);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_STOP);
    CREATE_ACTIVITY_COMMAND_BIC_STATIC(APP_CMD_DESTROY);
  }
}/*}}}*/

void bic_activity_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (activity_c *)NULL;
}/*}}}*/

void bic_activity_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  activity_c *act_ptr = (activity_c *)location_ptr->v_data_ptr;

  if (act_ptr != NULL)
  {
    cassert(act_ptr == &g_activity);

    // - release uclang properties of global activity -
    g_activity.clear(it);
  }
}/*}}}*/

bool bic_activity_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_activity_method_Activity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - ERROR -
  if (g_activity.event_loop_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ACTIVITY_CONNECTION_DOES_NOT_EXIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (g_activity.it_ptr != NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ACTIVITY_OBJECT_ALREADY_CREATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - initialize global activity -
  g_activity.init();

  // - set activity interpreter thread pointer -
  g_activity.it_ptr = &it;

  // - set activity pointer -
  dst_location->v_data_ptr = (activity_c *)&g_activity;

  return true;
}/*}}}*/

bool bic_activity_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - if display width is set -
  if (g_activity.width != 0)
  {
    long long int result = g_activity.width;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_activity_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - if display height is set -
  if (g_activity.height != 0)
  {
    long long int result = g_activity.height;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_activity_method_on_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ACTIVITY_DELEGATE("on_resize#1",g_activity.resize_dlg,2);
}/*}}}*/

bool bic_activity_method_on_display_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ACTIVITY_DELEGATE("on_display#1",g_activity.display_dlg,0);
}/*}}}*/

bool bic_activity_method_on_input_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ACTIVITY_DELEGATE("on_input#1",g_activity.input_dlg,0);
}/*}}}*/

bool bic_activity_method_on_command_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ACTIVITY_DELEGATE("on_command#1",g_activity.command_dlg,1);
}/*}}}*/

bool bic_activity_method_on_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ACTIVITY_DELEGATE("on_sensor#1",g_activity.sensor_dlg,0);
}/*}}}*/

bool bic_activity_method_on_idle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ACTIVITY_DELEGATE("on_idle#1",g_activity.idle_dlg,0);
}/*}}}*/

bool bic_activity_method_event_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  // - ERROR -
  if (g_activity.event_loop)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ACTIVITY_EVENT_LOOP_IS_ALREADY_RUNNING,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  g_activity.event_loop = true;
  g_activity.loop_source_pos = operands[c_source_pos_idx];
  g_activity.loop_ret_code = c_run_return_code_OK;

  // - enter event loop -
  g_activity.event_loop_ptr();
  
  // - reset event loop flag -
  g_activity.event_loop = false;

  unsigned loop_ret_code = g_activity.loop_ret_code;

  // - if exception occurred in one of events -
  if (loop_ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_activity_method_post_redisplay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  g_activity.app->redrawNeeded = 1;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_activity_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Activity"),"Activity")
  );

  return true;
}/*}}}*/

bool bic_activity_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Activity");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class EVENT -
built_in_class_s event_class =
{/*{{{*/
  "Event",
  c_modifier_public | c_modifier_final,
  4, event_methods,
  2, event_variables,
  bic_event_consts,
  bic_event_init,
  bic_event_clear,
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

built_in_method_s event_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_event_operator_binary_equal
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_event_method_get_type_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_event_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_event_method_print_0
  },
};/*}}}*/

built_in_variable_s event_variables[] =
{/*{{{*/
  { "TYPE_KEY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MOTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_event_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert activity command constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_EVENT_TYPE_BIC_STATIC(AINPUT_EVENT_TYPE_KEY);
    CREATE_EVENT_TYPE_BIC_STATIC(AINPUT_EVENT_TYPE_MOTION);
  }
}/*}}}*/

void bic_event_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_event_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_event_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  long long int result = AInputEvent_getType(g_activity.event);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Event"),"Event")
  );

  return true;
}/*}}}*/

bool bic_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Event");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SENSOR_MANAGER -
built_in_class_s sensor_manager_class =
{/*{{{*/
  "SensorManager",
  c_modifier_public | c_modifier_final,
  6, sensor_manager_methods,
  0, sensor_manager_variables,
  bic_sensor_manager_consts,
  bic_sensor_manager_init,
  bic_sensor_manager_clear,
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

built_in_method_s sensor_manager_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sensor_manager_operator_binary_equal
  },
  {
    "sensor_list#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_manager_method_sensor_list_0
  },
  {
    "default_sensor#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_manager_method_default_sensor_1
  },
  {
    "create_event_queue#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_manager_method_create_event_queue_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_manager_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_manager_method_print_0
  },
};/*}}}*/

built_in_variable_s sensor_manager_variables[] =
{/*{{{*/
};/*}}}*/

void bic_sensor_manager_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_sensor_manager_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_sensor_manager_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_sensor_manager_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sensor_manager_method_sensor_list_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  ASensorList list;
  int count = ASensorManager_getSensorList(ASensorManager_getInstance(),&list);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (count > 0)
  {
    ASensorList sr_ptr = list;
    ASensorList sr_ptr_end = list + count;
    do {
      ASensorRef sensor_ref = *sr_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sensor,sensor_ref);
      array_ptr->push(new_location);
    } while(++sr_ptr < sr_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sensor_manager_method_default_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int type;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_sensor_manager,"default_sensor#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ASensorRef sensor_ref = ASensorManager_getDefaultSensor(ASensorManager_getInstance(),type);

  if (sensor_ref != NULL)
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sensor,sensor_ref);
    BIC_SET_RESULT(new_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_sensor_manager_method_create_event_queue_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  ASensorEventQueue *queue_ptr = ASensorManager_createEventQueue(
        ASensorManager_getInstance(),
        ALooper_prepare(0),
        LOOPER_ID_USER,NULL,NULL);

  // - ERROR -
  if (queue_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SENSOR_MANAGER_CANNOT_CREATE_EVENT_QUEUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sensor_event_queue,queue_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sensor_manager_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SensorManager"),"SensorManager")
  );

  return true;
}/*}}}*/

bool bic_sensor_manager_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SensorManager");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SENSOR -
built_in_class_s sensor_class =
{/*{{{*/
  "Sensor",
  c_modifier_public | c_modifier_final,
  8, sensor_methods,
  5, sensor_variables,
  bic_sensor_consts,
  bic_sensor_init,
  bic_sensor_clear,
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

built_in_method_s sensor_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sensor_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_method_name_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_method_get_type_0
  },
  {
    "vendor#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_method_vendor_0
  },
  {
    "resolution#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_method_resolution_0
  },
  {
    "min_delay#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_method_min_delay_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_method_print_0
  },
};/*}}}*/

built_in_variable_s sensor_variables[] =
{/*{{{*/
  { "TYPE_ACCELEROMETER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MAGNETIC_FIELD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GYROSCOPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PROXIMITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_sensor_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert sensor type constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_SENSOR_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SENSOR_TYPE_BIC_STATIC(ASENSOR_TYPE_ACCELEROMETER);
    CREATE_SENSOR_TYPE_BIC_STATIC(ASENSOR_TYPE_MAGNETIC_FIELD);
    CREATE_SENSOR_TYPE_BIC_STATIC(ASENSOR_TYPE_GYROSCOPE);
    CREATE_SENSOR_TYPE_BIC_STATIC(ASENSOR_TYPE_LIGHT);
    CREATE_SENSOR_TYPE_BIC_STATIC(ASENSOR_TYPE_PROXIMITY);
  }
}/*}}}*/

void bic_sensor_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ASensorRef)NULL;
}/*}}}*/

void bic_sensor_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_sensor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sensor_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *name = ASensor_getName((ASensorRef)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_sensor_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ASensor_getType((ASensorRef)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_method_vendor_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *name = ASensor_getVendor((ASensorRef)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_sensor_method_resolution_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ASensor_getResolution((ASensorRef)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_sensor_method_min_delay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ASensor_getMinDelay((ASensorRef)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Sensor"),"Sensor")
  );

  return true;
}/*}}}*/

bool bic_sensor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Sensor");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SENSOR_EVENT_QUEUE -
built_in_class_s sensor_event_queue_class =
{/*{{{*/
  "SensorEventQueue",
  c_modifier_public | c_modifier_final,
  8, sensor_event_queue_methods,
  0, sensor_event_queue_variables,
  bic_sensor_event_queue_consts,
  bic_sensor_event_queue_init,
  bic_sensor_event_queue_clear,
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

built_in_method_s sensor_event_queue_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_queue_operator_binary_equal
  },
  {
    "enable_sensor#1",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_queue_method_enable_sensor_1
  },
  {
    "disable_sensor#1",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_queue_method_disable_sensor_1
  },
  {
    "event_rate#2",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_queue_method_event_rate_2
  },
  {
    "has_events#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_queue_method_has_events_0
  },
  {
    "get_event#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_queue_method_get_event_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_event_queue_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_event_queue_method_print_0
  },
};/*}}}*/

built_in_variable_s sensor_event_queue_variables[] =
{/*{{{*/
};/*}}}*/

void bic_sensor_event_queue_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_sensor_event_queue_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ASensorEventQueue *)NULL;
}/*}}}*/

void bic_sensor_event_queue_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ASensorEventQueue *queue_ptr = (ASensorEventQueue *)location_ptr->v_data_ptr;

  if (queue_ptr != NULL)
  {
    ASensorManager_destroyEventQueue(ASensorManager_getInstance(),queue_ptr);
  }
}/*}}}*/

bool bic_sensor_event_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_enable_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_sensor)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("enable_sensor#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ASensorEventQueue *queue_ptr = (ASensorEventQueue *)dst_location->v_data_ptr;
  ASensorRef sensor_ref = (ASensorRef)src_0_location->v_data_ptr;

  // - ERROR -
  if (ASensorEventQueue_enableSensor(queue_ptr,sensor_ref) < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SENSOR_EVENT_QUEUE_CANNOT_ENABLE_SENSOR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_disable_sensor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_sensor)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("disable_sensor#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ASensorEventQueue *queue_ptr = (ASensorEventQueue *)dst_location->v_data_ptr;
  ASensorRef sensor_ref = (ASensorRef)src_0_location->v_data_ptr;

  // - ERROR -
  if (ASensorEventQueue_disableSensor(queue_ptr,sensor_ref) < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SENSOR_EVENT_QUEUE_CANNOT_DISABLE_SENSOR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_event_rate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int rate;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_sensor ||
      !it.retrieve_integer(src_1_location,rate))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("event_rate#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  ASensorEventQueue *queue_ptr = (ASensorEventQueue *)dst_location->v_data_ptr;
  ASensorRef sensor_ref = (ASensorRef)src_0_location->v_data_ptr;

  // - ERROR -
  if (ASensorEventQueue_setEventRate(queue_ptr,sensor_ref,rate) < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SENSOR_EVENT_QUEUE_SET_EVENT_RATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_has_events_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ASensorEventQueue *queue_ptr = (ASensorEventQueue *)dst_location->v_data_ptr;

  long long int result = ASensorEventQueue_hasEvents(queue_ptr) > 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_get_event_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ASensorEventQueue *queue_ptr = (ASensorEventQueue *)dst_location->v_data_ptr;

  // - create sensor event object -
  ASensorEvent *event_ptr = (ASensorEvent *)cmalloc(sizeof(ASensorEvent));

  if (ASensorEventQueue_getEvents(queue_ptr,event_ptr,1) != 1)
  {
    cfree(event_ptr);

    BIC_SET_RESULT_BLANK();
  }
  else
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_sensor_event,event_ptr);
    BIC_SET_RESULT(new_location);
  }

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SensorEventQueue"),"SensorEventQueue")
  );

  return true;
}/*}}}*/

bool bic_sensor_event_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SensorEventQueue");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SENSOR_EVENT -
built_in_class_s sensor_event_class =
{/*{{{*/
  "SensorEvent",
  c_modifier_public | c_modifier_final,
  20, sensor_event_methods,
  0, sensor_event_variables,
  bic_sensor_event_consts,
  bic_sensor_event_init,
  bic_sensor_event_clear,
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

built_in_method_s sensor_event_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_operator_binary_equal
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_version_0
  },
  {
    "sensor#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_sensor_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_get_type_0
  },
  {
    "time#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_time_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_value_0
  },
  {
    "temperature#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_value_0
  },
  {
    "distance#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_value_0
  },
  {
    "light#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_value_0
  },
  {
    "pressure#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_value_0
  },
  {
    "vector#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vector_0
  },
  {
    "vec_x#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_x_0
  },
  {
    "vec_y#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_y_0
  },
  {
    "vec_z#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_z_0
  },
  {
    "vec_azimuth#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_x_0
  },
  {
    "vec_pitch#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_y_0
  },
  {
    "vec_roll#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_z_0
  },
  {
    "vec_status#0",
    c_modifier_public | c_modifier_final,
    bic_sensor_event_method_vec_status_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_event_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_sensor_event_method_print_0
  },
};/*}}}*/

built_in_variable_s sensor_event_variables[] =
{/*{{{*/
};/*}}}*/

void bic_sensor_event_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_sensor_event_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ASensorEvent *)NULL;
}/*}}}*/

void bic_sensor_event_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ASensorEvent *event_ptr = (ASensorEvent *)location_ptr->v_data_ptr;

  if (event_ptr != NULL)
  {
    cfree(event_ptr);
  }
}/*}}}*/

bool bic_sensor_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_sensor_event_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((ASensorEvent *)dst_location->v_data_ptr)->version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_sensor_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((ASensorEvent *)dst_location->v_data_ptr)->sensor;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((ASensorEvent *)dst_location->v_data_ptr)->type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((ASensorEvent *)dst_location->v_data_ptr)->timestamp;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ((ASensorEvent *)dst_location->v_data_ptr)->temperature;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_vector_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ASensorVector &vector = ((ASensorEvent *)dst_location->v_data_ptr)->vector;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  {
    double result = vector.x;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,result);
    array_ptr->push(new_location);
  }

  {
    double result = vector.y;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,result);
    array_ptr->push(new_location);
  }

  {
    double result = vector.z;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,result);
    array_ptr->push(new_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_sensor_event_method_vec_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ((ASensorEvent *)dst_location->v_data_ptr)->vector.x;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_vec_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ((ASensorEvent *)dst_location->v_data_ptr)->vector.y;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_vec_z_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ((ASensorEvent *)dst_location->v_data_ptr)->vector.z;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_vec_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((ASensorEvent *)dst_location->v_data_ptr)->vector.status;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_sensor_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SensorEvent"),"SensorEvent")
  );

  return true;
}/*}}}*/

bool bic_sensor_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SensorEvent");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

