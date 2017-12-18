
@begin
include "uctcnmd_module.h"
@end

// - UCTCNMD indexes of built in classes -
unsigned c_bi_class_tcn_message = c_idx_not_exist;
unsigned c_bi_class_tcn_address = c_idx_not_exist;
unsigned c_bi_class_tcn_am_address = c_idx_not_exist;
unsigned c_bi_class_tcn_caller = c_idx_not_exist;
unsigned c_bi_class_tcn_replier = c_idx_not_exist;
unsigned c_bi_class_tcn_handler = c_idx_not_exist;

// - UCTCNMD module -
built_in_module_s module =
{/*{{{*/
  6,                       // Class count
  uctcnmd_classes,         // Classes

  0,                       // Error base index
  1,                       // Error count
  uctcnmd_error_strings,   // Error strings

  uctcnmd_initialize,      // Initialize function
  uctcnmd_print_exception, // Print exceptions function
};/*}}}*/

// - UCTCNMD classes -
built_in_class_s *uctcnmd_classes[] =
{/*{{{*/
  &tcn_message_class,
  &tcn_address_class,
  &tcn_am_address_class,
  &tcn_caller_class,
  &tcn_replier_class,
  &tcn_handler_class,
};/*}}}*/

// - UCTCNMD error strings -
const char *uctcnmd_error_strings[] =
{/*{{{*/
  "error_UCTCNMD_DUMMY_ERROR",
};/*}}}*/

// - UCTCNMD initialize -
bool uctcnmd_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize tcn_message class identifier -
  c_bi_class_tcn_message = class_base_idx++;

  // - initialize tcn_address class identifier -
  c_bi_class_tcn_address = class_base_idx++;

  // - initialize tcn_am_address class identifier -
  c_bi_class_tcn_am_address = class_base_idx++;

  // - initialize tcn_caller class identifier -
  c_bi_class_tcn_caller = class_base_idx++;

  // - initialize tcn_replier class identifier -
  c_bi_class_tcn_replier = class_base_idx++;

  // - initialize tcn_handler class identifier -
  c_bi_class_tcn_handler = class_base_idx++;

  return true;
}/*}}}*/

// - UCTCNMD print exception -
bool uctcnmd_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_UCTCNMD_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcn message data dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class TCN_MESSAGE -
built_in_class_s tcn_message_class =
{/*{{{*/
  "TcnMessage",
  c_modifier_public | c_modifier_final,
  3, tcn_message_methods,
  4, tcn_message_variables,
  bic_tcn_message_consts,
  bic_tcn_message_init,
  bic_tcn_message_clear,
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

built_in_method_s tcn_message_methods[] =
{/*{{{*/
  {
    "Main#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_message_method_Main_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_message_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_message_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_message_variables[] =
{/*{{{*/

  // - message service type constants -
  { "BLOCK_SERVICE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UNBLOCK_SERVICE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "BLOCK_SERVICE_REPLIER_FUNCTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UNBLOCK_SERVICE_REPLIER_FUNCTION", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define UCTCNMD_CHECK_INTEGER_U8_RANGE(VALUE) \
{/*{{{*/\
  if ((VALUE) < 0 || (VALUE) > 255)\
  {\
    /* FIXME TODO throw proper exception ... */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
    return false;\
  }\
}/*}}}*/

void bic_tcn_message_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert message service type constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_TCN_MESSAGE_SERVICE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCN_MESSAGE_SERVICE_TYPE_BIC_STATIC(msg_block_service);
    CREATE_TCN_MESSAGE_SERVICE_TYPE_BIC_STATIC(msg_unblock_service);
    CREATE_TCN_MESSAGE_SERVICE_TYPE_BIC_STATIC(msg_block_rpl_fct);
    CREATE_TCN_MESSAGE_SERVICE_TYPE_BIC_STATIC(msg_unblock_rpl_fct);
  }

}/*}}}*/

void bic_tcn_message_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_tcn_message_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_tcn_message_method_Main_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  tcn_message_s::it_ptr = &it;
  tcn_message_s::source_pos = operands[c_source_pos_idx];
  tcn_message_s::ret_code = c_run_return_code_OK;

  msgMain();

  // - if exception occurred -
  if (tcn_message_s::ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_tcn_message_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnMessage"),"TcnMessage")
  );

  return true;
}/*}}}*/

bool bic_tcn_message_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnMessage");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_ADDRESS -
built_in_class_s tcn_address_class =
{/*{{{*/
  "TcnAddress",
  c_modifier_public | c_modifier_final,
  10, tcn_address_methods,
  4, tcn_address_variables,
  bic_tcn_address_consts,
  bic_tcn_address_init,
  bic_tcn_address_clear,
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

built_in_method_s tcn_address_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_operator_binary_equal
  },
  {
    "TcnAddress#4",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_TcnAddress_4
  },
  {
    "addr_type#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_addr_type_0
  },
  {
    "node#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_node_0
  },
  {
    "group#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_group_0
  },
  {
    "function#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_function_0
  },
  {
    "station#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_station_0
  },
  {
    "next_station#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_address_method_next_station_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_address_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_address_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_address_variables[] =
{/*{{{*/

  // - message address type constants -
  { "INDIVIDUAL_USER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INDIVIDUAL_SYSTEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GROUP_USER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GROUP_SYSTEM", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_tcn_address_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert message address type constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_TCN_ADDRESS_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCN_ADDRESS_TYPE_BIC_STATIC(msg_addr_indiv_usr);
    CREATE_TCN_ADDRESS_TYPE_BIC_STATIC(msg_addr_indiv_system);
    CREATE_TCN_ADDRESS_TYPE_BIC_STATIC(msg_addr_grp_usr);
    CREATE_TCN_ADDRESS_TYPE_BIC_STATIC(msg_addr_grp_system);
  }

}/*}}}*/

void bic_tcn_address_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SMsgAddress *)nullptr;
}/*}}}*/

void bic_tcn_address_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  SMsgAddress *ta_ptr = (SMsgAddress *)location_ptr->v_data_ptr;

  if (ta_ptr != nullptr)
  {
    cfree(ta_ptr);
  }
}/*}}}*/

bool bic_tcn_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_address_method_TcnAddress_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int addr_type;
  long long int node_group;
  long long int function_station;
  long long int next_station;

  if (!it.retrieve_integer(src_0_location,addr_type) ||
      !it.retrieve_integer(src_1_location,node_group) ||
      !it.retrieve_integer(src_2_location,function_station) ||
      !it.retrieve_integer(src_3_location,next_station))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TcnAddress#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - ERROR -
  if (addr_type < 0 || addr_type > msg_addr_grp_system)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  UCTCNMD_CHECK_INTEGER_U8_RANGE(node_group);
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function_station);
  UCTCNMD_CHECK_INTEGER_U8_RANGE(next_station);

  // - create tcn_address object -
  SMsgAddress *ta_ptr = (SMsgAddress *)cmalloc(sizeof(SMsgAddress));

  ta_ptr->eAddrType = (EMsgAddrType)addr_type;
  ta_ptr->uNG.u8Node = node_group;
  ta_ptr->uFS.u8Function = function_station;
  ta_ptr->u8NextStation = next_station;

  // - set tcn_address destination location -
  dst_location->v_data_ptr = (SMsgAddress *)ta_ptr;

  return true;
}/*}}}*/

#define BIC_TCN_ADDRESS_RETRIEVE_VALUE(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  long long int result = ((SMsgAddress *)dst_location->v_data_ptr)->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

bool bic_tcn_address_method_addr_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_ADDRESS_RETRIEVE_VALUE(eAddrType);

  return true;
}/*}}}*/

bool bic_tcn_address_method_node_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_ADDRESS_RETRIEVE_VALUE(uNG.u8Node);

  return true;
}/*}}}*/

bool bic_tcn_address_method_group_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_ADDRESS_RETRIEVE_VALUE(uNG.u8Group);

  return true;
}/*}}}*/

bool bic_tcn_address_method_function_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_ADDRESS_RETRIEVE_VALUE(uFS.u8Function);

  return true;
}/*}}}*/

bool bic_tcn_address_method_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_ADDRESS_RETRIEVE_VALUE(uFS.u8Station);

  return true;
}/*}}}*/

bool bic_tcn_address_method_next_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_ADDRESS_RETRIEVE_VALUE(u8NextStation);

  return true;
}/*}}}*/

bool bic_tcn_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnAddress"),"TcnAddress")
  );

  return true;
}/*}}}*/

bool bic_tcn_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnAddress");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_AM_ADDRESS -
built_in_class_s tcn_am_address_class =
{/*{{{*/
  "TcnAmAddress",
  c_modifier_public | c_modifier_final,
  13, tcn_am_address_methods,
  0, tcn_am_address_variables,
  bic_tcn_am_address_consts,
  bic_tcn_am_address_init,
  bic_tcn_am_address_clear,
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

built_in_method_s tcn_am_address_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_operator_binary_equal
  },
  {
    "gni#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_gni_0
  },
  {
    "snu#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_snu_0
  },
  {
    "node#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_node_0
  },
  {
    "group#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_group_0
  },
  {
    "function#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_function_0
  },
  {
    "station#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_station_0
  },
  {
    "next_station#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_next_station_0
  },
  {
    "topo_counter#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_topo_counter_0
  },
  {
    "topo_valid#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_topo_valid_0
  },
  {
    "topo_rsv#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_am_address_method_topo_rsv_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_am_address_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_am_address_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_am_address_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  unsigned am_addr = (unsigned)dst_location->v_data_ptr;\
  AM_ADDRESS *am_ptr = (AM_ADDRESS *)&am_addr;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,am_ptr->NAME);\
}/*}}}*/

void bic_tcn_am_address_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcn_am_address_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (unsigned)0;
}/*}}}*/

void bic_tcn_am_address_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_tcn_am_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_gni_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(gni);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_snu_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(snu);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_node_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(node_or_group);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_group_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(node_or_group);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_function_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(func_or_stat);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(func_or_stat);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_next_station_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(u8NextStation);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_topo_counter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(topo_counter);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_topo_valid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(topo_valid);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_topo_rsv_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TCN_AM_ADDRESS_RETRIEVE_VALUE(topo_rsv);

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnAmAddress"),"TcnAmAddress")
  );

  return true;
}/*}}}*/

bool bic_tcn_am_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnAmAddress");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_CALLER -
built_in_class_s tcn_caller_class =
{/*{{{*/
  "TcnCaller",
  c_modifier_public | c_modifier_final,
  5, tcn_caller_methods,
  0, tcn_caller_variables,
  bic_tcn_caller_consts,
  bic_tcn_caller_init,
  bic_tcn_caller_clear,
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

built_in_method_s tcn_caller_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_caller_operator_binary_equal
  },
  {
    "TcnCaller#3",
    c_modifier_public | c_modifier_final,
    bic_tcn_caller_method_TcnCaller_3
  },
  {
    "CallRequest#3",
    c_modifier_public | c_modifier_final,
    bic_tcn_caller_method_CallRequest_3
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_caller_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_caller_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_caller_variables[] =
{/*{{{*/
};/*}}}*/

void bic_tcn_caller_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcn_caller_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcn_caller_s *)nullptr;
}/*}}}*/

void bic_tcn_caller_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcn_caller_s *tc_ptr = (tcn_caller_s *)location_ptr->v_data_ptr;

  if (tc_ptr != nullptr)
  {
    tc_ptr->clear(it);
    cfree(tc_ptr);
  }
}/*}}}*/

bool bic_tcn_caller_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_caller_method_TcnCaller_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int function;
  long long int service_type;

  if (!it.retrieve_integer(src_0_location,function) ||
      !it.retrieve_integer(src_1_location,service_type) ||
      src_2_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TcnCaller#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function);

  const SMsgCallerPars *params;

  switch (service_type)
  {
  case msg_block_service:
    params = c_caller_params + 0;
    break;
  case msg_unblock_service:
    params = c_caller_params + 1;
    break;

  // - ERROR -
  default:

    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 4)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  if (msgRegCaller(function,params) != msg_ok)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create tcn_caller object -
  tcn_caller_s *tc_ptr = (tcn_caller_s *)cmalloc(sizeof(tcn_caller_s));
  tc_ptr->init();

  tc_ptr->function = function;
  tc_ptr->params = params;

  // - register callback delegate -
  src_2_location->v_reference_cnt.atomic_inc();
  tc_ptr->callback_dlg = src_2_location;

  // - set tcn_caller destination location -
  dst_location->v_data_ptr = (tcn_caller_s *)tc_ptr;

  return true;
}/*}}}*/

bool bic_tcn_caller_method_CallRequest_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int timeout;

  if (src_0_location->v_type != c_bi_class_tcn_address ||
      src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,timeout))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CallRequest#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  if (timeout < 0 || timeout > 65535)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  tcn_caller_s *tc_ptr = (tcn_caller_s *)dst_location->v_data_ptr;
  SMsgAddress *ta_ptr = (SMsgAddress *)src_0_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create tcn_handler object -
  tcn_handler_s *th_ptr = (tcn_handler_s *)cmalloc(sizeof(tcn_handler_s));
  th_ptr->init();

  // - store reference to tcn caller -
  dst_location->v_reference_cnt.atomic_inc();
  th_ptr->tcn_caller_loc = dst_location;

  // - store reference to message data -
  src_1_location->v_reference_cnt.atomic_inc();
  th_ptr->msg_data_loc = src_1_location;

  // - create tcn_handler location -
  BIC_CREATE_NEW_LOCATION(th_location,c_bi_class_tcn_handler,th_ptr);

  // - ERROR -
  if (msgCallRequestEx(tc_ptr->function,ta_ptr,string_ptr->data,string_ptr->size - 1,
        timeout,th_location,&th_ptr->th_ptr) != msg_ok)
  {
    it.release_location_ptr(th_location);

    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  th_location->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(th_location);

  return true;
}/*}}}*/

bool bic_tcn_caller_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnCaller"),"TcnCaller")
  );

  return true;
}/*}}}*/

bool bic_tcn_caller_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnCaller");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_REPLIER -
built_in_class_s tcn_replier_class =
{/*{{{*/
  "TcnReplier",
  c_modifier_public | c_modifier_final,
  4, tcn_replier_methods,
  0, tcn_replier_variables,
  bic_tcn_replier_consts,
  bic_tcn_replier_init,
  bic_tcn_replier_clear,
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

built_in_method_s tcn_replier_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_replier_operator_binary_equal
  },
  {
    "TcnReplier#4",
    c_modifier_public | c_modifier_final,
    bic_tcn_replier_method_TcnReplier_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_replier_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_replier_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_replier_variables[] =
{/*{{{*/
};/*}}}*/

void bic_tcn_replier_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcn_replier_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcn_replier_s *)nullptr;
}/*}}}*/

void bic_tcn_replier_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcn_replier_s *tr_ptr = (tcn_replier_s *)location_ptr->v_data_ptr;

  if (tr_ptr != nullptr)
  {
    tr_ptr->clear(it);
    cfree(tr_ptr);
  }
}/*}}}*/

bool bic_tcn_replier_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_replier_method_TcnReplier_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int function;
  long long int instance_cnt;
  long long int service_type;

  if (!it.retrieve_integer(src_0_location,function) ||
      !it.retrieve_integer(src_1_location,instance_cnt) ||
      !it.retrieve_integer(src_2_location,service_type) ||
      src_3_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TcnReplier#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - ERROR -
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function);

  // - ERROR -
  if (instance_cnt < 1 || instance_cnt > 255)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  if (service_type < 0 || service_type > msg_unblock_rpl_fct)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  const SMsgReplierParsEx *params = c_replier_params + service_type;

  // FIXME TODO check callback delegate

  AM_RESULT am_res;
  EMsgRes msg_res = msgRegReplierEx(function,instance_cnt,params,&am_res);

  // - ERROR -
  if (msg_res != msg_ok)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  if (am_res != AM_OK)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create tcn_replier object -
  tcn_replier_s *tr_ptr = (tcn_replier_s *)cmalloc(sizeof(tcn_replier_s));
  tr_ptr->init();

  tr_ptr->function = function;
  tr_ptr->params = params;

  // - register callback delegate -
  src_3_location->v_reference_cnt.atomic_inc();
  tr_ptr->callback_dlg = src_3_location;

  // - set tcn_replier destination location -
  dst_location->v_data_ptr = (tcn_replier_s *)tr_ptr;

  return true;
}/*}}}*/

bool bic_tcn_replier_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnReplier"),"TcnReplier")
  );

  return true;
}/*}}}*/

bool bic_tcn_replier_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnReplier");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_HANDLER -
built_in_class_s tcn_handler_class =
{/*{{{*/
  "TcnHandler",
  c_modifier_public | c_modifier_final,
  4, tcn_handler_methods,
  0, tcn_handler_variables,
  bic_tcn_handler_consts,
  bic_tcn_handler_init,
  bic_tcn_handler_clear,
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

built_in_method_s tcn_handler_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_handler_operator_binary_equal
  },
  {
    "Cancel#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_handler_method_Cancel_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_handler_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_handler_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_handler_variables[] =
{/*{{{*/
};/*}}}*/

void bic_tcn_handler_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcn_handler_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcn_handler_s *)nullptr;
}/*}}}*/

void bic_tcn_handler_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcn_handler_s *th_ptr = (tcn_handler_s *)location_ptr->v_data_ptr;

  if (th_ptr != nullptr)
  {
    th_ptr->clear(it);
    cfree(th_ptr);
  }
}/*}}}*/

bool bic_tcn_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_handler_method_Cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcn_handler_s *th_ptr = (tcn_handler_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (msgCancSession(th_ptr->th_ptr) != msg_ok)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }
  else
  {
    // - callback will not be called for cancelled session -
    it.release_location_ptr(dst_location);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcn_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnHandler"),"TcnHandler")
  );

  return true;
}/*}}}*/

bool bic_tcn_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnHandler");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

