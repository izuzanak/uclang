
@begin
include "uctrdpns_module.h"
@end

// - UCTRDPNS indexes of built in classes -
unsigned c_bi_class_trdp_ns = c_idx_not_exist;
unsigned c_bi_class_trdp_ns_target = c_idx_not_exist;
unsigned c_bi_class_trdp_ns_address = c_idx_not_exist;

// - UCTRDPNS module -
built_in_module_s module =
{/*{{{*/
  3,                        // Class count
  uctrdpns_classes,         // Classes

  0,                        // Error base index
  6,                        // Error count
  uctrdpns_error_strings,   // Error strings

  uctrdpns_initialize,      // Initialize function
  uctrdpns_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRDPNS classes -
built_in_class_s *uctrdpns_classes[] =
{/*{{{*/
  &trdp_ns_class,
  &trdp_ns_target_class,
  &trdp_ns_address_class,
};/*}}}*/

// - UCTRDPNS error strings -
const char *uctrdpns_error_strings[] =
{/*{{{*/
  "error_TRDP_NS_INITIALIZE_ERROR",
  "error_TRDP_NS_SET_MODE_INVALID_MODE",
  "error_TRDP_NS_SET_MODE_ERROR",
  "error_TRDP_NS_SET_PERIOD_ERROR",
  "error_TRDP_NS_ADD_TARGET_ERROR",
  "error_TRDP_NS_TARGET_GET_ADDRESS_ERROR",
};/*}}}*/

// - UCTRDPNS initialize -
bool uctrdpns_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trdp_ns class identifier -
  c_bi_class_trdp_ns = class_base_idx++;

  // - initialize trdp_ns_target class identifier -
  c_bi_class_trdp_ns_target = class_base_idx++;

  // - initialize trdp_ns_address class identifier -
  c_bi_class_trdp_ns_address = class_base_idx++;

  return true;
}/*}}}*/

// - UCTRDPNS print exception -
bool uctrdpns_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TRDP_NS_INITIALIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP name service, init error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_NS_SET_MODE_INVALID_MODE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP name service, invalid requested mode\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_NS_SET_MODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP name service, set mode error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_NS_SET_PERIOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP name service, set period error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_NS_ADD_TARGET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP name service, add target error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_NS_TARGET_GET_ADDRESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP name service, get target address error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRDP_NS -
built_in_class_s trdp_ns_class =
{/*{{{*/
  "TrdpNs",
  c_modifier_public | c_modifier_final,
  7, trdp_ns_methods,
  9 + 3, trdp_ns_variables,
  bic_trdp_ns_consts,
  bic_trdp_ns_init,
  bic_trdp_ns_clear,
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

built_in_method_s trdp_ns_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_operator_binary_equal
  },
  {
    "TrdpNs#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_method_TrdpNs_1
  },
  {
    "SetMode#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_method_SetMode_1
  },
  {
    "SetPeriod#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_method_SetPeriod_1
  },
  {
    "AddTarget#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_method_AddTarget_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_ns_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_ns_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_ns_variables[] =
{/*{{{*/

  // - trdp generic code constants -
  { "TRDP_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_ABORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_OUT_OF_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_SOCKET_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_TERMINATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_PENDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_REM_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - trdp mode constants -
  { "MODE_UNKNOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_CONFIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_FULLOP", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_trdp_ns_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert trdp generic code constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_TRDP_GENERIC_CODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_OK);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_FAIL);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_ABORT);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_OUT_OF_MEMORY);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_TIMEOUT);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_SOCKET_ERROR);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_TERMINATE);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_PENDING);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_REM_ERROR);
  }

  // - insert trdp mode constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_TRDP_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_MODE_BIC_STATIC(TRDP::MODE_UNKNOWN);
    CREATE_TRDP_MODE_BIC_STATIC(TRDP::MODE_CONFIG);
    CREATE_TRDP_MODE_BIC_STATIC(TRDP::MODE_FULLOP);
  }

}/*}}}*/

void bic_trdp_ns_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TRDP::NS *)nullptr;
}/*}}}*/

void bic_trdp_ns_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TRDP::NS *ns_ptr = (TRDP::NS *)location_ptr->v_data_ptr;

  if (ns_ptr != nullptr)
  {
    delete ns_ptr;
  }
}/*}}}*/

bool bic_trdp_ns_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_ns_method_TrdpNs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int id;

  if (!it.retrieve_integer(src_0_location,id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpNs#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  TRDP::NS *ns_ptr = new TRDP::NS();

  // - ERROR -
  int res = ns_ptr->Init(id);
  if (res != TRDP::TRDP_OK)
  {
    delete ns_ptr;

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_NS_INITIALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  // - set trdp_ns destination location -
  dst_location->v_data_ptr = (TRDP::NS *)ns_ptr;

  return true;
}/*}}}*/

bool bic_trdp_ns_method_SetMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int mode;

  if (!it.retrieve_integer(src_0_location,mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SetMode#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (mode < TRDP::MODE_CONFIG || mode > TRDP::MODE_FULLOP)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_NS_SET_MODE_INVALID_MODE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  TRDP::NS *ns_ptr = (TRDP::NS *)dst_location->v_data_ptr;

  // - ERROR -
  int res = ns_ptr->SetMode(mode);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_NS_SET_MODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_ns_method_SetPeriod_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int tick;

  if (!it.retrieve_integer(src_0_location,tick))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SetPeriod#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  TRDP::NS *ns_ptr = (TRDP::NS *)dst_location->v_data_ptr;

  // - ERROR -
  int res = ns_ptr->SetPeriod(tick);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_NS_SET_PERIOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_ns_method_AddTarget_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AddTarget#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  TRDP::NS *ns_ptr = (TRDP::NS *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  TRDP::Handle handle;
  int res = ns_ptr->AddTarget(string_ptr->data,&handle);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_NS_ADD_TARGET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  // - create trdp_ns_target object -
  trdp_ns_target_s *tnt_ptr = (trdp_ns_target_s *)cmalloc(sizeof(trdp_ns_target_s));
  tnt_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  tnt_ptr->ns_location = dst_location;

  tnt_ptr->handle = handle;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trdp_ns_target,tnt_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_trdp_ns_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpNs"),"TrdpNs");
  );

  return true;
}/*}}}*/

bool bic_trdp_ns_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpNs");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_NS_TARGET -
built_in_class_s trdp_ns_target_class =
{/*{{{*/
  "TrdpNsTarget",
  c_modifier_public | c_modifier_final,
  4, trdp_ns_target_methods,
  0, trdp_ns_target_variables,
  bic_trdp_ns_target_consts,
  bic_trdp_ns_target_init,
  bic_trdp_ns_target_clear,
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

built_in_method_s trdp_ns_target_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_target_operator_binary_equal
  },
  {
    "GetAddress#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_target_method_GetAddress_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_ns_target_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_ns_target_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_ns_target_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_ns_target_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_ns_target_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_ns_target_s *)nullptr;
}/*}}}*/

void bic_trdp_ns_target_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_ns_target_s *tnt_ptr = (trdp_ns_target_s *)location_ptr->v_data_ptr;

  if (tnt_ptr != nullptr)
  {
    tnt_ptr->clear(it);
    cfree(tnt_ptr);
  }
}/*}}}*/

bool bic_trdp_ns_target_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_ns_target_method_GetAddress_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_ns_target_s *tnt_ptr = (trdp_ns_target_s *)dst_location->v_data_ptr;
  TRDP::NS *ns_ptr = (TRDP::NS *)tnt_ptr->ns_location->v_data_ptr;

  TRDP::NS::Address *tna_ptr = (TRDP::NS::Address *)cmalloc(sizeof(TRDP::NS::Address));

  // - ERROR -
  int res = ns_ptr->GetAddress(tnt_ptr->handle,*tna_ptr);
  if (res != TRDP::TRDP_OK)
  {
    cfree(tna_ptr);

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_NS_TARGET_GET_ADDRESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trdp_ns_address,tna_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_trdp_ns_target_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpNsTarget"),"TrdpNsTarget");
  );

  return true;
}/*}}}*/

bool bic_trdp_ns_target_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpNsTarget");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_NS_ADDRESS -
built_in_class_s trdp_ns_address_class =
{/*{{{*/
  "TrdpNsAddress",
  c_modifier_public | c_modifier_final,
  5, trdp_ns_address_methods,
  0, trdp_ns_address_variables,
  bic_trdp_ns_address_consts,
  bic_trdp_ns_address_init,
  bic_trdp_ns_address_clear,
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

built_in_method_s trdp_ns_address_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_address_operator_binary_equal
  },
  {
    "ip#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_address_method_ip_0
  },
  {
    "ip2#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_ns_address_method_ip2_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_ns_address_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_ns_address_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_ns_address_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_TRDP_NS_ADDRESS_METHOD_IP(INDEX) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  TRDP::NS::Address *tna_ptr = (TRDP::NS::Address *)dst_location->v_data_ptr;\
  \
  if (tna_ptr->err == 0)\
  {\
    const char *address = Ucf2::IP2str(tna_ptr->ip[INDEX],nullptr,0);\
    \
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->set(strlen(address),address);\
    \
    BIC_SET_RESULT_STRING(string_ptr);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
  \
  return true;\
}/*}}}*/

void bic_trdp_ns_address_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_ns_address_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TRDP::NS::Address *)nullptr;
}/*}}}*/

void bic_trdp_ns_address_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TRDP::NS::Address *tna_ptr = (TRDP::NS::Address *)location_ptr->v_data_ptr;

  if (tna_ptr != nullptr)
  {
    cfree(tna_ptr);
  }
}/*}}}*/

bool bic_trdp_ns_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_ns_address_method_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRDP_NS_ADDRESS_METHOD_IP(0);
}/*}}}*/

bool bic_trdp_ns_address_method_ip2_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRDP_NS_ADDRESS_METHOD_IP(1);
}/*}}}*/

bool bic_trdp_ns_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpNsAddress"),"TrdpNsAddress");
  );

  return true;
}/*}}}*/

bool bic_trdp_ns_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpNsAddress");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

