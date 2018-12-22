
@begin
include "soapsrv_module.h"
@end

// - SOAPSRV indexes of built in classes -
unsigned c_bi_class_calc_service = c_idx_not_exist;
unsigned c_bi_class_soap_fault = c_idx_not_exist;

// - SOAPSRV module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                        // Class count
  soapsrv_classes,          // Classes

  0,                        // Error base index
  4,                        // Error count
  soapsrv_error_strings,    // Error strings

  soapsrv_initialize,       // Initialize function
  soapsrv_print_exception,  // Print exceptions function
};/*}}}*/

// - SOAPSRV classes -
built_in_class_s *soapsrv_classes[] =
{/*{{{*/
  &calc_service_class,
  &soap_fault_class,
};/*}}}*/

// - SOAPSRV error strings -
const char *soapsrv_error_strings[] =
{/*{{{*/
  "error_GSOAP_CALL_FAULT",
  "error_GSOAP_SERVICE_BIND_ERROR",
  "error_GSOAP_SERVICE_ACCEPT_ERROR",
  "error_GSOAP_WRONG_CALLBACK_DELEGATE",
};/*}}}*/

// - SOAPSRV initialize -
bool soapsrv_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize calc_service class identifier -
  c_bi_class_calc_service = class_base_idx++;

  // - initialize soap_fault class identifier -
  c_bi_class_soap_fault = class_base_idx++;

  return true;
}/*}}}*/

// - SOAPSRV print exception -
bool soapsrv_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GSOAP_CALL_FAULT:
  {
    string_s &gsoap_fault = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\n%s",gsoap_fault.data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  }
  case c_error_GSOAP_SERVICE_BIND_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGSOAP cannot bind to socket\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GSOAP_SERVICE_ACCEPT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGSOAP connection accept error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GSOAP_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for GSOAP callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CALC_SERVICE -
built_in_class_s calc_service_class =
{/*{{{*/
  "CalcService",
  c_modifier_public | c_modifier_final,
  10, calc_service_methods,
  0, calc_service_variables,
  bic_calc_service_consts,
  bic_calc_service_init,
  bic_calc_service_clear,
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

built_in_method_s calc_service_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_calc_service_operator_binary_equal
  },
  {
    "CalcService#1",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_CalcService_1
  },
  {
    "CalcService#2",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_CalcService_2
  },
  {
    "process#0",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_process_0
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_get_fd_0
  },
  {
    "ns__add#1",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_ns__add_1
  },
  {
    "ns__sub#1",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_ns__sub_1
  },
  {
    "ns__sqrt#1",
    c_modifier_public | c_modifier_final,
    bic_calc_service_method_ns__sqrt_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_calc_service_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_calc_service_method_print_0
  },
};/*}}}*/

built_in_variable_s calc_service_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_GSOAP_CALL_FAULT_EXCEPTION() \
{/*{{{*/\
\
  /* - create exception fault string - */\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->create(c_soap_error_string_size);\
\
  soap_sprint_fault(se_ptr->soap_ptr,string_ptr->data,string_ptr->size);\
  string_ptr->size = strlen(string_ptr->data) + 1;\
\
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);\
\
  /* - clean deserialized data - */\
  soap_end(se_ptr->soap_ptr);\
\
  exception_s::throw_exception(it,module.error_base + c_error_GSOAP_CALL_FAULT,operands[c_source_pos_idx],new_location);\
  return false;\
}/*}}}*/

#define BIC_GSOAP_DELEGATE_CHECK(LOCATION,PARAM_CNT) \
{/*{{{*/\
\
  /* - retrieve delegate pointer - */\
  delegate_s *delegate_ptr = (delegate_s *)(LOCATION)->v_data_ptr;\
\
  /* - ERROR - */\
  if (delegate_ptr->param_cnt != PARAM_CNT)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GSOAP_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

#define BIC_GSOAP_DELEGATE(CLASS,NAME,DLG_PTR_NAME,PARAM_CNT) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_delegate)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,CLASS,NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;\
\
  BIC_GSOAP_DELEGATE_CHECK(src_0_location,PARAM_CNT);\
\
  /* - release previous delegate - */\
  if (se_ptr->DLG_PTR_NAME != nullptr)\
  {\
    it.release_location_ptr(se_ptr->DLG_PTR_NAME);\
  }\
\
  /* - register new delegate - */\
  src_0_location->v_reference_cnt.atomic_inc();\
  se_ptr->DLG_PTR_NAME = src_0_location;\
\
  BIC_SET_RESULT_DESTINATION();\
\
  return true;\
}/*}}}*/

void bic_calc_service_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_calc_service_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (soap_env_s *)nullptr;
}/*}}}*/

void bic_calc_service_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  soap_env_s *se_ptr = (soap_env_s *)location_ptr->v_data_ptr;

  if (se_ptr != nullptr)
  {
    se_ptr->clear(it);
    cfree(se_ptr);
  }
}/*}}}*/

bool bic_calc_service_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_calc_service_method_CalcService_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int port;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,port))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CalcService#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create soap environment object -
  soap_env_s *se_ptr = (soap_env_s *)cmalloc(sizeof(soap_env_s));
  se_ptr->init();

  se_ptr->soap_ptr = soap_new();
  se_ptr->soap_ptr->user = se_ptr;
  se_ptr->soap_ptr->bind_flags |= SO_REUSEADDR;

  se_ptr->socket = soap_bind(se_ptr->soap_ptr,nullptr,port,100);

  // - ERROR -
  if (se_ptr->socket < 0)
  {
    se_ptr->clear(it);
    cfree(se_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_GSOAP_SERVICE_BIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (soap_env_s *)se_ptr;

  return true;
}/*}}}*/

bool bic_calc_service_method_CalcService_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int port;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,port))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CalcService#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create soap environment object -
  soap_env_s *se_ptr = (soap_env_s *)cmalloc(sizeof(soap_env_s));
  se_ptr->init();

  se_ptr->soap_ptr = soap_new();
  se_ptr->soap_ptr->user = se_ptr;
  se_ptr->soap_ptr->bind_flags |= SO_REUSEADDR;

  se_ptr->socket = soap_bind(se_ptr->soap_ptr,string_ptr->data,port,100);

  // - ERROR -
  if (se_ptr->socket < 0)
  {
    se_ptr->clear(it);
    cfree(se_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_GSOAP_SERVICE_BIND_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (soap_env_s *)se_ptr;

  return true;
}/*}}}*/

bool bic_calc_service_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve soap environment pointer -
  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;

  long long int result = se_ptr->socket;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_calc_service_method_ns__add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GSOAP_DELEGATE(c_bi_class_calc_service,"ns__add#1",ns__add_dlg,2);
}/*}}}*/

bool bic_calc_service_method_ns__sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GSOAP_DELEGATE(c_bi_class_calc_service,"ns__sub#1",ns__sub_dlg,2);
}/*}}}*/

bool bic_calc_service_method_ns__sqrt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GSOAP_DELEGATE(c_bi_class_calc_service,"ns__sqrt#1",ns__sqrt_dlg,1);
}/*}}}*/

bool bic_calc_service_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve soap environment pointer -
  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;
  int sock;

  se_ptr->it_ptr = &it;
  se_ptr->proc_source_pos = operands[c_source_pos_idx];
  se_ptr->proc_ret_code = c_run_return_code_OK;

  // - ERROR -
  if ((sock = soap_accept(se_ptr->soap_ptr)) < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GSOAP_SERVICE_ACCEPT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  soap_serve(se_ptr->soap_ptr);
  soap_end(se_ptr->soap_ptr);

  // - if exception was occurred in service routine -
  if (se_ptr->proc_ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_calc_service_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CalcService"),"CalcService");
  );

  return true;
}/*}}}*/

bool bic_calc_service_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CalcService");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SOAP_FAULT -
built_in_class_s soap_fault_class =
{/*{{{*/
  "SoapFault",
  c_modifier_public | c_modifier_final,
  4, soap_fault_methods,
  0, soap_fault_variables,
  bic_soap_fault_consts,
  bic_soap_fault_init,
  bic_soap_fault_clear,
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

built_in_method_s soap_fault_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_soap_fault_operator_binary_equal
  },
  {
    "SoapFault#2",
    c_modifier_public | c_modifier_final,
    bic_soap_fault_method_SoapFault_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_soap_fault_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_soap_fault_method_print_0
  },
};/*}}}*/

built_in_variable_s soap_fault_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_soap_fault_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_soap_fault_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (soap_fault_s *)nullptr;
}/*}}}*/

void bic_soap_fault_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  soap_fault_s *sf_ptr = (soap_fault_s *)location_ptr->v_data_ptr;

  if (sf_ptr != nullptr)
  {
    sf_ptr->clear(it);
    cfree(sf_ptr);
  }
}/*}}}*/

bool bic_soap_fault_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_soap_fault_method_SoapFault_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SoapFault#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - create soap fault object -
  soap_fault_s *sf_ptr = (soap_fault_s *)cmalloc(sizeof(soap_fault_s));
  sf_ptr->init();

  // - set string pointer -
  src_0_location->v_reference_cnt.atomic_inc();
  sf_ptr->string_ptr = src_0_location;

  // - set detail pointer -
  src_1_location->v_reference_cnt.atomic_inc();
  sf_ptr->detail_ptr = src_1_location;

  dst_location->v_data_ptr = (soap_fault_s *)sf_ptr;

  return true;
}/*}}}*/

bool bic_soap_fault_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SoapFault"),"SoapFault");
  );

  return true;
}/*}}}*/

bool bic_soap_fault_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("SoapFault");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

