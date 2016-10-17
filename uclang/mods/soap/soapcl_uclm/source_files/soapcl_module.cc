
@begin
include "soapcl_module.h"
@end

// - SOAPCL indexes of built in classes -
unsigned c_bi_class_calc_client = c_idx_not_exist;

// - SOAPCL module -
built_in_module_s module =
{/*{{{*/
  1,                       // Class count
  soapcl_classes,          // Classes

  0,                       // Error base index
  1,                       // Error count
  soapcl_error_strings,    // Error strings

  soapcl_initialize,       // Initialize function
  soapcl_print_exception,  // Print exceptions function
};/*}}}*/

// - SOAPCL classes -
built_in_class_s *soapcl_classes[] =
{/*{{{*/
  &calc_client_class,
};/*}}}*/

// - SOAPCL error strings -
const char *soapcl_error_strings[] =
{/*{{{*/
  "error_GSOAP_CLIENT_CALL_FAULT",
};/*}}}*/

// - SOAPCL initialize -
bool soapcl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize calc_client class identifier -
  c_bi_class_calc_client = class_base_idx++;

  return true;
}/*}}}*/

// - SOAPCL print exception -
bool soapcl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_GSOAP_CLIENT_CALL_FAULT:
  {
    string_s &gsoap_fault = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\n%s",gsoap_fault.data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  }
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class CALC_CLIENT -
built_in_class_s calc_client_class =
{/*{{{*/
  "CalcClient",
  c_modifier_public | c_modifier_final,
  9, calc_client_methods,
  0, calc_client_variables,
  bic_calc_client_consts,
  bic_calc_client_init,
  bic_calc_client_clear,
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

built_in_method_s calc_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_calc_client_operator_binary_equal
  },
  {
    "CalcClient#0",
    c_modifier_public | c_modifier_final,
    bic_calc_client_method_CalcClient_0
  },
  {
    "CalcClient#1",
    c_modifier_public | c_modifier_final,
    bic_calc_client_method_CalcClient_1
  },
  {
    "endpoint#0",
    c_modifier_public | c_modifier_final,
    bic_calc_client_method_endpoint_0
  },
  {
    "add#2",
    c_modifier_public | c_modifier_final,
    bic_calc_client_method_add_2
  },
  {
    "sub#2",
    c_modifier_public | c_modifier_final,
    bic_calc_client_method_sub_2
  },
  {
    "sqrt#1",
    c_modifier_public | c_modifier_final,
    bic_calc_client_method_sqrt_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_calc_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_calc_client_method_print_0
  },
};/*}}}*/

built_in_variable_s calc_client_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GSOAP_RETRIEVE_ENDPOINT() \
/*{{{*/\
  const char *endpoint_ptr = NULL;\
\
  if (se_ptr->endpoint_ptr != NULL)\
  {\
    endpoint_ptr = ((string_s *)se_ptr->endpoint_ptr->v_data_ptr)->data;\
  }\
/*}}}*/

#define BIC_GSOAP_CLIENT_CALL_FAULT_EXCEPTION() \
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
  exception_s::throw_exception(it,module.error_base + c_error_GSOAP_CLIENT_CALL_FAULT,operands[c_source_pos_idx],new_location);\
  return false;\
}/*}}}*/

void bic_calc_client_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_calc_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_calc_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  soap_env_s *se_ptr = (soap_env_s *)location_ptr->v_data_ptr;

  if (se_ptr != NULL)
  {
    se_ptr->clear(it);
    cfree(se_ptr);
  }
}/*}}}*/

bool bic_calc_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_calc_client_method_CalcClient_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create soap environment object -
  soap_env_s *se_ptr = (soap_env_s *)cmalloc(sizeof(soap_env_s));
  se_ptr->init();

  se_ptr->soap_ptr = soap_new();
  se_ptr->endpoint_ptr = NULL;

  dst_location->v_data_ptr = (basic_64b)se_ptr;

  return true;
}/*}}}*/

bool bic_calc_client_method_CalcClient_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CalcClient#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create soap environment object -
  soap_env_s *se_ptr = (soap_env_s *)cmalloc(sizeof(soap_env_s));
  se_ptr->init();

  se_ptr->soap_ptr = soap_new();

  // - set endpoint location -
  src_0_location->v_reference_cnt.atomic_inc();
  se_ptr->endpoint_ptr = src_0_location;

  dst_location->v_data_ptr = (basic_64b)se_ptr;

  return true;
}/*}}}*/

bool bic_calc_client_method_endpoint_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;

  if (se_ptr->endpoint_ptr != NULL)
  {
    location_s *ep_location = se_ptr->endpoint_ptr;
    ep_location->v_reference_cnt.atomic_inc();

    BIC_SET_RESULT(ep_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_calc_client_method_add_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double param_a;
  double param_b;

  // - ERROR -
  if (!it.retrieve_float(src_0_location,param_a) ||
      !it.retrieve_float(src_1_location,param_b))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;
  double result;

  BIC_GSOAP_RETRIEVE_ENDPOINT();

  // - ERROR -
  if (soap_call_ns__add(se_ptr->soap_ptr,endpoint_ptr,NULL,param_a,param_b,&result) != SOAP_OK)
  {
    BIC_GSOAP_CLIENT_CALL_FAULT_EXCEPTION()
  }

  // - clean deserialized data -
  soap_end(se_ptr->soap_ptr);

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_calc_client_method_sub_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double param_a;
  double param_b;

  // - ERROR -
  if (!it.retrieve_float(src_0_location,param_a) ||
      !it.retrieve_float(src_1_location,param_b))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("sub#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;
  double result;

  BIC_GSOAP_RETRIEVE_ENDPOINT();

  // - ERROR -
  if (soap_call_ns__sub(se_ptr->soap_ptr,endpoint_ptr,NULL,param_a,param_b,&result) != SOAP_OK)
  {
    BIC_GSOAP_CLIENT_CALL_FAULT_EXCEPTION()
  }

  // - clean deserialized data -
  soap_end(se_ptr->soap_ptr);

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_calc_client_method_sqrt_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double param_a;

  // - ERROR -
  if (!it.retrieve_float(src_0_location,param_a))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("sqrt#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  soap_env_s *se_ptr = (soap_env_s *)dst_location->v_data_ptr;
  double result;

  BIC_GSOAP_RETRIEVE_ENDPOINT();

  // - ERROR -
  if (soap_call_ns__sqrt(se_ptr->soap_ptr,endpoint_ptr,NULL,param_a,&result) != SOAP_OK)
  {
    BIC_GSOAP_CLIENT_CALL_FAULT_EXCEPTION();
  }

  // - clean deserialized data -
  soap_end(se_ptr->soap_ptr);

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_calc_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CalcClient"),"CalcClient");
  );

  return true;
}/*}}}*/

bool bic_calc_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("CalcClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

