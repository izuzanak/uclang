
@begin
include "snmp_module.h"
@end

// - SNMP indexes of built in classes -
unsigned c_bi_class_snmp_session = c_idx_not_exist;
unsigned c_bi_class_snmp_agent = c_idx_not_exist;
unsigned c_bi_class_snmp_obj = c_idx_not_exist;
unsigned c_bi_class_snmp_oid = c_idx_not_exist;

// - SNMP module -
built_in_module_s module =
{/*{{{*/
  4,                     // Class count
  snmp_classes,          // Classes

  0,                     // Error base index
  21,                    // Error count
  snmp_error_strings,    // Error strings

  snmp_initialize,       // Initialize function
  snmp_print_exception,  // Print exceptions function
};/*}}}*/

// - SNMP classes -
built_in_class_s *snmp_classes[] =
{/*{{{*/
  &snmp_session_class,
  &snmp_agent_class,
  &snmp_obj_class,
  &snmp_oid_class,
};/*}}}*/

// - SNMP error strings -
const char *snmp_error_strings[] =
{/*{{{*/
  "error_SNMP_SESSION_IS_ALREADY_RUNNING",
  "error_SNMP_SESSION_ARGUMENT_MUST_BE_STRING",
  "error_SNMP_SESSION_ARGUMENTS_PARSE_ERROR",
  "error_SNMP_SESSION_OPEN_ERROR",
  "error_SNMP_SESSION_DIFFERENT_OID_AND_VALUE_ARRAY_LENGTHS",
  "error_SNMP_SESSION_EXPECTED_OID_ARRAY",
  "error_SNMP_SESSION_UNSUPPORTED_VALUE_TYPE",
  "error_SNMP_SESSION_WRITE_VALUE_ERROR",
  "error_SNMP_SESSION_READ_VALUE_ERROR",
  "error_SNMP_AGENT_UNRECOGNIZED_AGENT_TYPE",
  "error_SNMP_AGENT_IS_ALREADY_RUNNING",
  "error_SNMP_AGENT_CREATE_ERROR",
  "error_SNMP_AGENT_UNRECOGNIZED_OBJECT_TYPE",
  "error_SNMP_AGENT_OBJECT_ALREADY_EXISTS",
  "error_SNMP_AGENT_INJECT_OBJECT_ERROR",
  "error_SNMP_AGENT_CHECK_AND_PROCESS_ERROR",
  "error_SNMP_AGENT_OBJECT_NAME_NOT_FOUND",
  "error_SNMP_AGENT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_SNMP_OID_PARSE_ERROR",
  "error_SNMP_OBJ_SET_WRONG_TYPE",
  "error_SNMP_OBJ_SET_VALUE_STRING_TOO_LONG",
};/*}}}*/

// - SNMP initialize -
bool snmp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize snmp_session class identifier -
  c_bi_class_snmp_session = class_base_idx++;

  // - initialize snmp_agent class identifier -
  c_bi_class_snmp_agent = class_base_idx++;

  // - initialize snmp_obj class identifier -
  c_bi_class_snmp_obj = class_base_idx++;

  // - initialize snmp_oid class identifier -
  c_bi_class_snmp_oid = class_base_idx++;

  return true;
}/*}}}*/

// - SNMP print exception -
bool snmp_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_SNMP_SESSION_IS_ALREADY_RUNNING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP session is already running in process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_ARGUMENT_MUST_BE_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP session argument must be string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_ARGUMENTS_PARSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP session arguments parse error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP session open error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_DIFFERENT_OID_AND_VALUE_ARRAY_LENGTHS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDifferent lengths of oid and value arrays\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_EXPECTED_OID_ARRAY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected array of OIDs as first argument\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_UNSUPPORTED_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP write request of unsupported value type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_WRITE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP session cannot write values\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_SESSION_READ_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP session cannot read requested values\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_UNRECOGNIZED_AGENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized type of requested SNMP agent\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_IS_ALREADY_RUNNING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP agent is already running in process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating SNMP agent\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_UNRECOGNIZED_OBJECT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP agent, unrecognized object type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_OBJECT_ALREADY_EXISTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP object named \"%s\" already exists\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_INJECT_OBJECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP agent error while injecting object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_CHECK_AND_PROCESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP agent check and process error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_OBJECT_NAME_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP object with name \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_AGENT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid SNMP object\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_OID_PARSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSNMP oid parse error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_OBJ_SET_WRONG_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of value according to SNMP object type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNMP_OBJ_SET_VALUE_STRING_TOO_LONG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nString value to be set to SNMP object is too long\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SNMP_SESSION -
built_in_class_s snmp_session_class =
{/*{{{*/
  "SnmpSession",
  c_modifier_public | c_modifier_final,
  6, snmp_session_methods,
  0, snmp_session_variables,
  bic_snmp_session_consts,
  bic_snmp_session_init,
  bic_snmp_session_clear,
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

built_in_method_s snmp_session_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_session_operator_binary_equal
  },
  {
    "SnmpSession#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_session_method_SnmpSession_1
  },
  {
    "set_list#2",
    c_modifier_public | c_modifier_final,
    bic_snmp_session_method_set_list_2
  },
  {
    "get_list#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_session_method_get_list_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_session_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_session_method_print_0
  },
};/*}}}*/

built_in_variable_s snmp_session_variables[] =
{/*{{{*/
};/*}}}*/

void bic_snmp_session_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_snmp_session_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (snmp_session_s *)nullptr;
}/*}}}*/

void bic_snmp_session_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  snmp_session_s *snmps_ptr = (snmp_session_s *)location_ptr->v_data_ptr;

  // - if session exists -
  if (snmps_ptr != nullptr)
  {
    snmps_ptr->clear(it);
    cfree(snmps_ptr);
  }
}/*}}}*/

bool bic_snmp_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_snmp_session_method_SnmpSession_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SnmpSession#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve arguments array -
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (snmp_session_s::exists)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_IS_ALREADY_RUNNING,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - mark snmp session as existing -
  snmp_session_s::exists = true;

  int argc = array_ptr->used + 1;
  char **argv = (char **)cmalloc(argc*sizeof(char *));

  // - set program name argument -
  argv[0] = (char *)"appname";

  // - create arguments list -
  if (array_ptr->used > 0)
  {
    pointer *ptr = array_ptr->data;
    pointer *ptr_end = ptr + array_ptr->used;
    char **a_ptr = argv + 1;
    do {
      location_s *item_location = it.get_location_value(*ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_string)
      {
        cfree(argv);

        exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_ARGUMENT_MUST_BE_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - retrieve argument string -
      *a_ptr = ((string_s *)item_location->v_data_ptr)->data;

    } while(++a_ptr,++ptr < ptr_end);
  }

  // - create new snmp session object -
  snmp_session_s *snmps_ptr = (snmp_session_s *)cmalloc(sizeof(snmp_session_s));
  snmps_ptr->init();

  int arg_res = snmp_parse_args(argc,argv,&snmps_ptr->session,"",nullptr);

  // - ERROR -
  if (arg_res != argc)
  {
    snmps_ptr->clear(it);
    cfree(snmps_ptr);
    cfree(argv);

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_ARGUMENTS_PARSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  cfree(argv);

  // - open snmp session -
  snmps_ptr->ss = snmp_open(&snmps_ptr->session);

  // - ERROR -
  if (snmps_ptr->ss == nullptr)
  {
    snmps_ptr->clear(it);
    cfree(snmps_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (snmp_session_s *)snmps_ptr;

  return true;
}/*}}}*/

bool bic_snmp_session_method_set_list_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_array ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set_list#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve snmp session object -
  snmp_session_s *snmps_ptr = (snmp_session_s *)dst_location->v_data_ptr;

  // - retrieve array of oid objects -
  pointer_array_s *oid_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - retrieve array of values -
  pointer_array_s *value_array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (oid_array_ptr->used != value_array_ptr->used)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_DIFFERENT_OID_AND_VALUE_ARRAY_LENGTHS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (oid_array_ptr->used > 0)
  {
    // - construct request protocol data unit -
    netsnmp_pdu *req_pdu = snmp_pdu_create(SNMP_MSG_SET);

    // - process oid and value arrays -
    pointer *o_ptr = oid_array_ptr->data;
    pointer *o_ptr_end = o_ptr + oid_array_ptr->used;
    pointer *v_ptr = value_array_ptr->data;

    do {
      location_s *oid_location = it.get_location_value(*o_ptr);
      location_s *value_location = it.get_location_value(*v_ptr);

      // - ERROR -
      if (oid_location->v_type != c_bi_class_snmp_oid)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_EXPECTED_OID_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - retrieve snmp oid object -
      snmp_oid_s *snmpo_ptr = (snmp_oid_s *)oid_location->v_data_ptr;

      long int long_int;

      unsigned char value_type;
      void *value_ptr;
      int value_size;

      switch (value_location->v_type)
      {
      case c_bi_class_integer:
        {
          long_int = (long long int)value_location->v_data_ptr;

          value_type = ASN_INTEGER;
          value_ptr = &long_int;
          value_size = sizeof(long int);
        }
        break;

      case c_bi_class_string:
        {
          string_s *string_ptr = (string_s *)value_location->v_data_ptr;

          value_type = ASN_OCTET_STR;
          value_ptr = string_ptr->data;
          value_size = string_ptr->size - 1;
        }
        break;

      // - ERROR -
      default:
        snmp_free_pdu(req_pdu);

        exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_UNSUPPORTED_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - ERROR -
      if (snmp_pdu_add_variable(req_pdu,snmpo_ptr->data,snmpo_ptr->length,
          value_type,value_ptr,value_size) == nullptr)
      {
        snmp_free_pdu(req_pdu);

        exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_WRITE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

    } while(++v_ptr,++o_ptr < o_ptr_end);

    // - response protocol data unit -
    netsnmp_pdu *resp_pdu = nullptr;

    // - send request -
    int status = snmp_synch_response(snmps_ptr->ss,req_pdu,&resp_pdu);

    // - ERROR -
    if (status != STAT_SUCCESS || resp_pdu->errstat != SNMP_ERR_NOERROR)
    {
      if (resp_pdu != nullptr) {
        snmp_free_pdu(resp_pdu);
      }

      exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_WRITE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    if (resp_pdu != nullptr) {
      snmp_free_pdu(resp_pdu);
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_snmp_session_method_get_list_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_list#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve snmp session object -
  snmp_session_s *snmps_ptr = (snmp_session_s *)dst_location->v_data_ptr;

  // - retrieve array of oid objects -
  pointer_array_s *oid_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - construct result array -
  pointer_array_s *new_array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,new_array_ptr);
  BIC_SET_RESULT(new_location);

  if (oid_array_ptr->used > 0)
  {
    // - construct request protocol data unit -
    netsnmp_pdu *req_pdu = snmp_pdu_create(SNMP_MSG_GET);

    // - process oid array -
    pointer *ptr = oid_array_ptr->data;
    pointer *ptr_end = ptr + oid_array_ptr->used;

    do {
      location_s *item_location = it.get_location_value(*ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_snmp_oid)
      {
        snmp_free_pdu(req_pdu);

        exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_EXPECTED_OID_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - insert oid object to request protocol data unit -
      snmp_oid_s *snmpo_ptr = (snmp_oid_s *)item_location->v_data_ptr;
      snmp_add_null_var(req_pdu,snmpo_ptr->data,snmpo_ptr->length);

    } while(++ptr < ptr_end);

    // - response protocol data unit -
    netsnmp_pdu *resp_pdu = nullptr;

    // - send request -
    int status = snmp_synch_response(snmps_ptr->ss,req_pdu,&resp_pdu);

    // - ERROR -
    if (status != STAT_SUCCESS || resp_pdu->errstat != SNMP_ERR_NOERROR)
    {
      if (resp_pdu != nullptr) {
        snmp_free_pdu(resp_pdu);
      }

      exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_READ_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - process retrieved variables -
    netsnmp_variable_list *var_ptr = resp_pdu->variables;
    while (var_ptr != nullptr)
    {
      switch (var_ptr->type)
      {
      case ASN_INTEGER:
        {
          // - insert integer to result array -
          long long int result = *var_ptr->val.integer;
          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,result);
          new_array_ptr->push(new_location);
        }
        break;

      case ASN_OCTET_STR:
        {
          // - insert string to result array -
          string_s *string_ptr = it.get_new_string_ptr();
          string_ptr->set(var_ptr->val_len,(char *)var_ptr->val.string);

          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
          new_array_ptr->push(new_location);
        }
        break;

      // - ERROR -
      default:
        {
          snmp_free_pdu(resp_pdu);

          exception_s::throw_exception(it,module.error_base + c_error_SNMP_SESSION_READ_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
        break;
      }

      // - retrieve next variable -
      var_ptr = var_ptr->next_variable;
    }

    if (resp_pdu != nullptr) {
      snmp_free_pdu(resp_pdu);
    }
  }

  return true;
}/*}}}*/

bool bic_snmp_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SnmpSession"),"SnmpSession");
  );

  return true;
}/*}}}*/

bool bic_snmp_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SnmpSession");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SNMP_AGENT -
built_in_class_s snmp_agent_class =
{/*{{{*/
  "SnmpAgent",
  c_modifier_public | c_modifier_final,
  10, snmp_agent_methods,
  4, snmp_agent_variables,
  bic_snmp_agent_consts,
  bic_snmp_agent_init,
  bic_snmp_agent_clear,
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

built_in_method_s snmp_agent_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_operator_binary_le_br_re_br
  },
  {
    "SnmpAgent#2",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_method_SnmpAgent_2
  },
  {
    "add_object#3",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_method_add_object_3
  },
  {
    "check_and_process#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_method_check_and_process_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_agent_method_next_idx_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_agent_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_agent_method_print_0
  },
};/*}}}*/

built_in_variable_s snmp_agent_variables[] =
{/*{{{*/
  {
    "TYPE_MASTER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TYPE_SUBAGENT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "VALUE_INTEGER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "VALUE_STRING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

#define BIC_SNMP_AGENT_CHECK_INDEX() \
  /*{{{*/\
  snmp_object_rb_tree_s &objects = ((snmp_agent_s *)dst_location->v_data_ptr)->objects;\
\
  /* - ERROR - */\
  if (index < 0 || index >= objects.used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
\
  snmp_object_rb_tree_s_node &node = objects.data[index];\
\
  /* - ERROR - */\
  if (!node.valid)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_SNMP_AGENT_ITEM(NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int index;\
    \
    if (!it.retrieve_integer(src_0_location,index))\
    {\
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
      /* - retrieve snmp agent pointer and object name - */\
      snmp_agent_s *snmpa_ptr = (snmp_agent_s *)dst_location->v_data_ptr;\
      string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;\
      \
      snmp_object_s search_obj;\
      search_obj.name.data = name_ptr->data;\
      search_obj.name.size = name_ptr->size;\
      \
      /* - ERROR - */\
      if ((index = snmpa_ptr->objects.get_idx(search_obj)) == c_idx_not_exist)\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_OBJECT_NAME_NOT_FOUND,operands[c_source_pos_idx],src_0_location);\
        return false;\
      }\
    }\
    else {\
      BIC_SNMP_AGENT_CHECK_INDEX();\
    }\
    \
    /* - create new varstore slot object - */\
    snmp_obj_s *snmpo_ptr = (snmp_obj_s *)cmalloc(sizeof(snmp_obj_s));\
    \
    dst_location->v_reference_cnt.atomic_inc();\
    snmpo_ptr->snmpa_ptr = dst_location;\
    snmpo_ptr->index = index;\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_snmp_obj,snmpo_ptr);\
    BIC_SET_RESULT(new_location);\
    \
    return true;\
  }/*}}}*/

void bic_snmp_agent_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert agent type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_SNMP_AGENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SNMP_AGENT_TYPE_BIC_STATIC(SNMP_AGENT_TYPE_MASTER);
    CREATE_SNMP_AGENT_TYPE_BIC_STATIC(SNMP_AGENT_TYPE_SUBAGENT);
  }

  // - insert agent value type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_SNMP_VALUE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SNMP_VALUE_TYPE_BIC_STATIC(SNMP_VALUE_INTEGER);
    CREATE_SNMP_VALUE_TYPE_BIC_STATIC(SNMP_VALUE_STRING);
  }
}/*}}}*/

void bic_snmp_agent_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (snmp_agent_s *)nullptr;
}/*}}}*/

void bic_snmp_agent_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)location_ptr->v_data_ptr;

  // - if agent exists -
  if (snmpa_ptr != nullptr)
  {
    snmpa_ptr->clear(it);
    cfree(snmpa_ptr);
  }
}/*}}}*/

bool bic_snmp_agent_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_snmp_agent_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SNMP_AGENT_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_snmp_agent_method_SnmpAgent_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int agent_type;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,agent_type) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SnmpAgent#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  switch (agent_type)
  {
  case SNMP_AGENT_TYPE_MASTER:
  case SNMP_AGENT_TYPE_SUBAGENT:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_UNRECOGNIZED_AGENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve agent name -
  string_s *name_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (snmp_agent_s::exists)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_IS_ALREADY_RUNNING,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - mark snmp agent as existing -
  snmp_agent_s::exists = true;

  // - create new snmp agent object -
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)cmalloc(sizeof(snmp_agent_s));
  snmpa_ptr->init();

  snmpa_ptr->type = agent_type;
  snmpa_ptr->name = *name_ptr;

  switch (agent_type)
  {

    // - setup master agent -
    case SNMP_AGENT_TYPE_MASTER:
    {
      //init_agent(name_ptr->data);
      //init_vacm_vars();
      //init_usmUser();
      //init_snmp(name_ptr->data);
      //init_master_agent();

      snmpa_ptr->clear(it);
      cfree(snmpa_ptr);

      // FIXME TODO implement
      BIC_TODO_ERROR(__FILE__,__LINE__);
      return false;
    }

    // - setup agentx subagent -
    case SNMP_AGENT_TYPE_SUBAGENT:
    {
      // - ERROR -
      if (netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID,NETSNMP_DS_AGENT_ROLE,1) != SNMPERR_SUCCESS)
      {
        snmpa_ptr->clear(it);
        cfree(snmpa_ptr);

        exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - ERROR -
      if (init_agent(name_ptr->data) != 0)
      {
        snmpa_ptr->clear(it);
        cfree(snmpa_ptr);

        exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      init_snmp(name_ptr->data);

      break;
    }
  }

  dst_location->v_data_ptr = (snmp_agent_s *)snmpa_ptr;

  return true;
}/*}}}*/

bool bic_snmp_agent_method_add_object_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int value_type;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_snmp_oid ||
      !it.retrieve_integer(src_2_location,value_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add_object#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  switch (value_type)
  {
  case SNMP_VALUE_INTEGER:
  case SNMP_VALUE_STRING:
    break;

  // - ERORR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_UNRECOGNIZED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve snmp agent object -
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)dst_location->v_data_ptr;

  // - retrieve name -
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve snmp oid of object -
  snmp_oid_s *snmpo_ptr = (snmp_oid_s *)src_1_location->v_data_ptr;

  // - create new object description -
  snmp_object_s object;
  object.init();
  object.set(*name_ptr,value_type,nullptr);

  // - ERROR -
  if (snmpa_ptr->objects.get_idx(object) != c_idx_not_exist)
  {
    object.clear();

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_OBJECT_ALREADY_EXISTS,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create handler registration info -
  netsnmp_handler_registration *reginfo = nullptr;
  reginfo = netsnmp_create_handler_registration(name_ptr->data,nullptr,snmpo_ptr->data,snmpo_ptr->length,HANDLER_CAN_RWRITE);

  // - create watcher info -
  netsnmp_watcher_info *watchinfo = SNMP_MALLOC_TYPEDEF(netsnmp_watcher_info);

  switch (value_type)
  {
  case SNMP_VALUE_INTEGER:
    {
      object.data = cmalloc(sizeof(long int));
      *((long int *)object.data) = 0;

      watchinfo->data = object.data;
      watchinfo->data_size = sizeof(long int);
      watchinfo->max_size = watchinfo->data_size;
      watchinfo->type = ASN_INTEGER;
      watchinfo->flags = WATCHER_FIXED_SIZE;
    }
    break;

  case SNMP_VALUE_STRING:
    {
      object.data = cmalloc(c_snmp_max_string_size);
      ((char *)object.data)[0] = '\0';

      watchinfo->data = object.data;
      watchinfo->max_size = c_snmp_max_string_size;
      watchinfo->type = ASN_OCTET_STR;
      watchinfo->flags = WATCHER_SIZE_STRLEN;
    }
    break;
  }

  watchinfo->data_size_p = nullptr;

  // - create handler -
  netsnmp_mib_handler *handler = nullptr;

  // - ERROR -
  if ((handler = netsnmp_get_watcher_handler()) == nullptr)
  {
    object.clear();

    free(reginfo);
    free(watchinfo);

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_INJECT_OBJECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  handler->myvoid = (void *)watchinfo;
  netsnmp_owns_watcher_info(handler);

  // - ERROR -
  if (netsnmp_inject_handler(reginfo,handler) != SNMPERR_SUCCESS ||
      netsnmp_register_instance(reginfo) != SNMPERR_SUCCESS)
  {
    object.clear();

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_INJECT_OBJECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - insert object to agent structure -
  unsigned index = snmpa_ptr->objects.swap_insert(object);
  object.clear();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,index);

  return true;
}/*}}}*/

bool bic_snmp_agent_method_check_and_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int block;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,block))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("check_and_process#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int result = agent_check_and_process(block);

  // - ERROR -
  if (result == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_CHECK_AND_PROCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_snmp_agent_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SNMP_AGENT_ITEM("item#1");
}/*}}}*/

bool bic_snmp_agent_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)dst_location->v_data_ptr;
  snmp_object_rb_tree_s &objects = snmpa_ptr->objects;

  if (objects.root_idx != c_idx_not_exist)
  {
    long long int result = objects.get_min_value_idx(objects.root_idx);

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_snmp_agent_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
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

  BIC_SNMP_AGENT_CHECK_INDEX();

  long long int next_idx = objects.get_next_idx(index);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_CONT_INDEX(next_idx);

  return true;
}/*}}}*/

bool bic_snmp_agent_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SnmpAgent"),"SnmpAgent");
  );

  return true;
}/*}}}*/

bool bic_snmp_agent_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SnmpAgent");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SNMP_OBJ -
built_in_class_s snmp_obj_class =
{/*{{{*/
  "SnmpObj",
  c_modifier_public | c_modifier_final,
  7, snmp_obj_methods,
  0, snmp_obj_variables,
  bic_snmp_obj_consts,
  bic_snmp_obj_init,
  bic_snmp_obj_clear,
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

built_in_method_s snmp_obj_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_obj_operator_binary_equal
  },
  {
    "get_name#0",
    c_modifier_public | c_modifier_final,
    bic_snmp_obj_method_get_name_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_snmp_obj_method_get_type_0
  },
  {
    "set#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_obj_method_set_1
  },
  {
    "get#0",
    c_modifier_public | c_modifier_final,
    bic_snmp_obj_method_get_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_obj_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_obj_method_print_0
  },
};/*}}}*/

built_in_variable_s snmp_obj_variables[] =
{/*{{{*/
};/*}}}*/

void bic_snmp_obj_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_snmp_obj_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (snmp_obj_s *)nullptr;
}/*}}}*/

void bic_snmp_obj_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  snmp_obj_s *snmpo_ptr = (snmp_obj_s *)location_ptr->v_data_ptr;

  // - if obj exists -
  if (snmpo_ptr != nullptr)
  {
    snmpo_ptr->clear(it);
    cfree(snmpo_ptr);
  }
}/*}}}*/

bool bic_snmp_obj_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_snmp_obj_method_get_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  snmp_obj_s *snmpo_ptr = (snmp_obj_s *)dst_location->v_data_ptr;
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)snmpo_ptr->snmpa_ptr->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = snmpa_ptr->objects.data[snmpo_ptr->index].object.name;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_snmp_obj_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  snmp_obj_s *snmpo_ptr = (snmp_obj_s *)dst_location->v_data_ptr;
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)snmpo_ptr->snmpa_ptr->v_data_ptr;

  long long int result = snmpa_ptr->objects.data[snmpo_ptr->index].object.type;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_snmp_obj_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  snmp_obj_s *snmpo_ptr = (snmp_obj_s *)dst_location->v_data_ptr;
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)snmpo_ptr->snmpa_ptr->v_data_ptr;
  snmp_object_s &object = snmpa_ptr->objects.data[snmpo_ptr->index].object;

  switch (object.type)
  {

  case SNMP_VALUE_INTEGER:
    {
      // - ERROR -
      if (src_0_location->v_type != c_bi_class_integer)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SNMP_OBJ_SET_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - update integer value -
      *((long int *)object.data) = (long long int)src_0_location->v_data_ptr;
    }
    break;

  case SNMP_VALUE_STRING:
    {
      // - ERROR -
      if (src_0_location->v_type != c_bi_class_string)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SNMP_OBJ_SET_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

      // - ERROR -
      if (string_ptr->size > c_snmp_max_string_size)
      {
        exception_s::throw_exception(it,module.error_base + c_error_SNMP_OBJ_SET_VALUE_STRING_TOO_LONG,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - update string value -
      memcpy(object.data,string_ptr->data,string_ptr->size);
    }
    break;

  // - ERORR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_UNRECOGNIZED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_snmp_obj_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  snmp_obj_s *snmpo_ptr = (snmp_obj_s *)dst_location->v_data_ptr;
  snmp_agent_s *snmpa_ptr = (snmp_agent_s *)snmpo_ptr->snmpa_ptr->v_data_ptr;
  snmp_object_s &object = snmpa_ptr->objects.data[snmpo_ptr->index].object;

  switch (object.type)
  {

  case SNMP_VALUE_INTEGER:
    {
      long long int result = *((long int *)object.data);
      BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
    }
    break;

  case SNMP_VALUE_STRING:
    {
      char *str_pointer = (char *)object.data;
      unsigned str_length = strlen(str_pointer);

      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(str_length,str_pointer);

      BIC_SET_RESULT_STRING(string_ptr);
    }
    break;

  // - ERORR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_AGENT_UNRECOGNIZED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_snmp_obj_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SnmpObj"),"SnmpObj");
  );

  return true;
}/*}}}*/

bool bic_snmp_obj_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SnmpObj");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SNMP_OID -
built_in_class_s snmp_oid_class =
{/*{{{*/
  "SnmpOid",
  c_modifier_public | c_modifier_final,
  5, snmp_oid_methods,
  0, snmp_oid_variables,
  bic_snmp_oid_consts,
  bic_snmp_oid_init,
  bic_snmp_oid_clear,
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

built_in_method_s snmp_oid_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_oid_operator_binary_equal
  },
  {
    "SnmpOid#1",
    c_modifier_public | c_modifier_final,
    bic_snmp_oid_method_SnmpOid_1
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_snmp_oid_method_items_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_oid_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snmp_oid_method_print_0
  },
};/*}}}*/

built_in_variable_s snmp_oid_variables[] =
{/*{{{*/
};/*}}}*/

void bic_snmp_oid_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_snmp_oid_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (snmp_oid_s *)nullptr;
}/*}}}*/

void bic_snmp_oid_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  snmp_oid_s *snmpo_ptr = (snmp_oid_s *)location_ptr->v_data_ptr;

  // - if oid exists -
  if (snmpo_ptr != nullptr)
  {
    snmpo_ptr->clear(it);
    cfree(snmpo_ptr);
  }
}/*}}}*/

bool bic_snmp_oid_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_snmp_oid_method_SnmpOid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SnmpOid#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve oid string -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create new snmp oid object -
  snmp_oid_s *snmpo_ptr = (snmp_oid_s *)cmalloc(sizeof(snmp_oid_s));
  snmpo_ptr->init();

  // - ERROR -
  if (snmp_parse_oid(string_ptr->data,snmpo_ptr->data,&snmpo_ptr->length) == nullptr)
  {
    snmpo_ptr->clear(it);
    cfree(snmpo_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SNMP_OID_PARSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (snmp_oid_s *)snmpo_ptr;

  return true;
}/*}}}*/

bool bic_snmp_oid_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  snmp_oid_s *snmpo_ptr = (snmp_oid_s *)dst_location->v_data_ptr;
  pointer_array_s *new_array_ptr = it.get_new_array_ptr();

  if (snmpo_ptr->length > 0)
  {
    oid *ptr = snmpo_ptr->data;
    oid *ptr_end = ptr + snmpo_ptr->length;

    do {

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,(long long int)*ptr);
      new_array_ptr->push(new_location);

    } while(++ptr < ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,new_array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_snmp_oid_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("SnmpOid"),"SnmpOid");
  );

  return true;
}/*}}}*/

bool bic_snmp_oid_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("SnmpOid");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

