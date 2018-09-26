
@begin
include "uctrdp_module.h"
@end

// - UCTRDP indexes of built in classes -
unsigned c_bi_class_trdp_pd = c_idx_not_exist;
unsigned c_bi_class_trdp_pd_address = c_idx_not_exist;
unsigned c_bi_class_trdp_pd_port = c_idx_not_exist;

// - UCTRDP module -
built_in_module_s module =
{/*{{{*/
  3,                      // Class count
  uctrdp_classes,         // Classes

  0,                      // Error base index
  14,                     // Error count
  uctrdp_error_strings,   // Error strings

  uctrdp_initialize,      // Initialize function
  uctrdp_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRDP classes -
built_in_class_s *uctrdp_classes[] =
{/*{{{*/
  &trdp_pd_class,
  &trdp_pd_address_class,
  &trdp_pd_port_class,
};/*}}}*/

// - UCTRDP error strings -
const char *uctrdp_error_strings[] =
{/*{{{*/
  "error_TRDP_PD_INITIALIZE_ERROR",
  "error_TRDP_PD_SET_MODE_INVALID_MODE",
  "error_TRDP_PD_SET_MODE_ERROR",
  "error_TRDP_PD_SET_PERIOD_ERROR",
  "error_TRDP_PD_REMOVE_PORTS_ERROR",
  "error_TRDP_PD_ADDRESS_INVALID_SCOPE",
  "error_TRDP_PD_ADDRESS_INVALID_ADDRESS",
  "error_TRDP_PD_PORT_STATE_ERROR",
  "error_TRDP_PD_PORT_PUBLISH_ERROR",
  "error_TRDP_PD_PORT_SUBSCRIBE_ERROR",
  "error_TRDP_PD_PORT_GET_PORT_ERROR",
  "error_TRDP_PD_PORT_WRITE_READ_ERROR",
  "error_TRDP_PD_PORT_INVALID_PAGE_SIZE",
  "error_TRDP_PD_PORT_RELEASE_PAGE_ERROR",
};/*}}}*/

// - UCTRDP initialize -
bool uctrdp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trdp_pd class identifier -
  c_bi_class_trdp_pd = class_base_idx++;

  // - initialize trdp_pd_address class identifier -
  c_bi_class_trdp_pd_address = class_base_idx++;

  // - initialize trdp_pd_port class identifier -
  c_bi_class_trdp_pd_port = class_base_idx++;

  return true;
}/*}}}*/

// - UCTRDP print exception -
bool uctrdp_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TRDP_PD_INITIALIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, init error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_SET_MODE_INVALID_MODE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, invalid requested mode\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_SET_MODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, set mode error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_SET_PERIOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, set period error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_REMOVE_PORTS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, remove ports error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_ADDRESS_INVALID_SCOPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, invalid communication scope\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_ADDRESS_INVALID_ADDRESS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, invalid %s address\n",exception.params[0] ? "destination" : "source");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_STATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, port %s %s\n",exception.params[0] ? "already" : "not",exception.params[1] ? "published" : "subscribed");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_PUBLISH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, port %s error: %s\n",exception.params[1] ? "publish" : "unpublish",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_SUBSCRIBE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, port %s error: %s\n",exception.params[1] ? "subscribe" : "unsubscribe",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_GET_PORT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, get port error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_WRITE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, port %s error: %s\n",exception.params[1] ? "write" : "read",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_INVALID_PAGE_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, invalid port page size, expected %" HOST_LL_FORMAT "d bytes\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PD_PORT_RELEASE_PAGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, release port page error: %s\n",TRDP::GetResultStr(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRDP_PD -
built_in_class_s trdp_pd_class =
{/*{{{*/
  "TrdpPd",
  c_modifier_public | c_modifier_final,
  8, trdp_pd_methods,
  9 + 3 + 9 + 1 + 6 + 4 + 9, trdp_pd_variables,
  bic_trdp_pd_consts,
  bic_trdp_pd_init,
  bic_trdp_pd_clear,
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

built_in_method_s trdp_pd_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_operator_binary_equal
  },
  {
    "TrdpPd#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_method_TrdpPd_1
  },
  {
    "SetMode#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_method_SetMode_1
  },
  {
    "SetPeriod#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_method_SetPeriod_1
  },
  {
    "RemoveAllPorts#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_method_RemoveAllPorts_0
  },
  {
    "Port#5",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_method_Port_5
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_pd_variables[] =
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

  // - trdp qos constants -
  { "QOS_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P7", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - trdp ttl constants -
  { "TTL_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - communication scope constants -
  { "CS_LOCAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_ETB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_ETB_TOPO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_OPT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_OPT_TOPO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_ETB_ZERO", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - max data size constants -
  { "MAX_PD_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_MD_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "MAX_USR_LEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_HST_LEN", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - port flags constants -
  { "PF_SOURCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_SINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_REQUEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_CONSIST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_DEMUX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_VARSIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_FREEBIND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PF_PROMISC", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_trdp_pd_consts(location_array_s &const_locations)
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

  // - insert trdp qos constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_TRDP_QOS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_DEF);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P0);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P1);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P2);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P3);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P4);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P5);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P6);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P7);
  }

  // - insert trdp ttl constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_TRDP_TTL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_TTL_BIC_STATIC(TRDP::TTL_DEF);
  }

  // - insert communication scope constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_TRDP_CS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_LOCAL);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_ETB);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_ETB_TOPO);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_OPT);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_OPT_TOPO);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_ETB_ZERO);
  }

  // - insert max data size constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_TRDP_DATA_SIZE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_PD_SIZE);
    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_MD_SIZE);

    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_USR_LEN);
    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_HST_LEN);
  }

  // - insert port flags constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_TRDP_PF_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_SOURCE);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_SINK);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_TYPE);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_REQUEST);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_CONSIST);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_DEMUX);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_VARSIZE);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_FREEBIND);
    CREATE_TRDP_PF_BIC_STATIC(TRDP::PF_PROMISC);
  }

}/*}}}*/

void bic_trdp_pd_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TRDP::PD *)nullptr;
}/*}}}*/

void bic_trdp_pd_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TRDP::PD *pd_ptr = (TRDP::PD *)location_ptr->v_data_ptr;

  if (pd_ptr != nullptr)
  {
    delete pd_ptr;
  }
}/*}}}*/

bool bic_trdp_pd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_pd_method_TrdpPd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int id;

  if (!it.retrieve_integer(src_0_location,id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpPd#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  TRDP::PD *pd_ptr = new TRDP::PD();

  // - ERROR -
  int res = pd_ptr->Init(id);
  if (res != TRDP::TRDP_OK)
  {
    delete pd_ptr;

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_INITIALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  // - set trdp_pd destination location -
  dst_location->v_data_ptr = (TRDP::PD *)pd_ptr;

  return true;
}/*}}}*/

bool bic_trdp_pd_method_SetMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_SET_MODE_INVALID_MODE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  TRDP::PD *pd_ptr = (TRDP::PD *)dst_location->v_data_ptr;

  // - ERROR -
  int res = pd_ptr->SetMode(mode);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_SET_MODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_method_SetPeriod_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  TRDP::PD *pd_ptr = (TRDP::PD *)dst_location->v_data_ptr;

  // - ERROR -
  int res = pd_ptr->SetPeriod(tick);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_SET_PERIOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_method_RemoveAllPorts_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  TRDP::PD *pd_ptr = (TRDP::PD *)dst_location->v_data_ptr;

  // - ERROR -
  int res = pd_ptr->RemovePorts(nullptr,nullptr,0);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_REMOVE_PORTS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_method_Port_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int flags;
  long long int comm_id;
  long long int size;
  long long int cycle;

  if (src_0_location->v_type != c_bi_class_trdp_pd_address ||
      !it.retrieve_integer(src_1_location,flags) ||
      !it.retrieve_integer(src_2_location,comm_id) ||
      !it.retrieve_integer(src_3_location,size) ||
      !it.retrieve_integer(src_4_location,cycle))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Port#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  trdp_pd_address_s *tpa_ptr = (trdp_pd_address_s *)src_0_location->v_data_ptr;

  // - create trdp_pd_port object -
  trdp_pd_port_s *tpp_ptr = (trdp_pd_port_s *)cmalloc(sizeof(trdp_pd_port_s));
  tpp_ptr->init();

  TRDP::PD::Port &port = tpp_ptr->port;
  memset(&port,0,sizeof(port));

  port.flg = flags;
  port.comid = comm_id;
  port.size = size;
  port.scope = tpa_ptr->scope;
  port.cycle = cycle;
  port.dst = tpa_ptr->dst_host;
  port.src = tpa_ptr->src_host;
  port.src2 = tpa_ptr->src2_host;

  // - set reference to pd -
  dst_location->v_reference_cnt.atomic_inc();
  tpp_ptr->pd_location = dst_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trdp_pd_port,tpp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_trdp_pd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpPd"),"TrdpPd");
  );

  return true;
}/*}}}*/

bool bic_trdp_pd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpPd");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_PD_ADDRESS -
built_in_class_s trdp_pd_address_class =
{/*{{{*/
  "TrdpPdAddress",
  c_modifier_public | c_modifier_final,
  4, trdp_pd_address_methods,
  0, trdp_pd_address_variables,
  bic_trdp_pd_address_consts,
  bic_trdp_pd_address_init,
  bic_trdp_pd_address_clear,
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

built_in_method_s trdp_pd_address_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_address_operator_binary_equal
  },
  {
    "TrdpPdAddress#4",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_address_method_TrdpPdAddress_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_address_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_address_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_pd_address_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_pd_address_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_pd_address_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_pd_address_s *)nullptr;
}/*}}}*/

void bic_trdp_pd_address_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_pd_address_s *pda_ptr = (trdp_pd_address_s *)location_ptr->v_data_ptr;

  if (pda_ptr != nullptr)
  {
    pda_ptr->clear(it);
    cfree(pda_ptr);
  }
}/*}}}*/

bool bic_trdp_pd_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_pd_address_method_TrdpPdAddress_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int scope;
  long long int lli_dst_addr = 0;
  long long int lli_src_addr = 0;
  long long int lli_src2_addr = 0;

  if (!it.retrieve_integer(src_0_location,scope) ||
      (!it.retrieve_integer(src_1_location,lli_dst_addr) && src_1_location->v_type != c_bi_class_string) ||
      (!it.retrieve_integer(src_2_location,lli_src_addr) && src_2_location->v_type != c_bi_class_string) ||
      (!it.retrieve_integer(src_3_location,lli_src2_addr) && src_3_location->v_type != c_bi_class_string))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpPdAddress#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  switch (scope)
  {
  case TRDP::CS_LOCAL:
  case TRDP::CS_ETB:
  case TRDP::CS_ETB_TOPO:
  case TRDP::CS_OPT:
  case TRDP::CS_OPT_TOPO:
  case TRDP::CS_ETB_ZERO:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_ADDRESS_INVALID_SCOPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#define BIC_TRDP_PD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(LOCATION,TARGET,DST_FLAG)\
{/*{{{*/\
  if (LOCATION->v_type == c_bi_class_string)\
  {\
    /* - ERROR - */\
    if (!Ucf2::Str2IP(((string_s *)LOCATION->v_data_ptr)->data,TARGET))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_ADDRESS_INVALID_ADDRESS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(DST_FLAG);\
      \
      return false;\
    }\
  }\
  else\
  {\
    /* - ERROR - */\
    if (lli_ ## TARGET < 0 || lli_ ## TARGET > UINT_MAX)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_ADDRESS_INVALID_ADDRESS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(DST_FLAG);\
      \
      return false;\
    }\
    \
    TARGET = lli_ ## TARGET;\
  }\
}/*}}}*/

  // - retrieve destination ip addresses -
  unsigned dst_addr;
  BIC_TRDP_PD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(src_1_location,dst_addr,1);

  // - retrieve source ip addresses -
  unsigned src_addr;
  BIC_TRDP_PD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(src_2_location,src_addr,0);

  // - retrieve second source ip addresses -
  unsigned src2_addr;
  BIC_TRDP_PD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(src_3_location,src2_addr,0);

  // - create trdp_pd_address object -
  trdp_pd_address_s *tpa_ptr = (trdp_pd_address_s *)cmalloc(sizeof(trdp_pd_address_s));
  tpa_ptr->init();

  // - set communication scope -
  tpa_ptr->scope = scope;

  // - set destination host and address -
  tpa_ptr->dst_host.h = 0;
  tpa_ptr->dst_host.ip = dst_addr;

  // - set source host and address -
  tpa_ptr->src_host.h = 0;
  tpa_ptr->src_host.ip = src_addr;

  // - set second source host and address -
  tpa_ptr->src2_host.h = 0;
  tpa_ptr->src2_host.ip = src2_addr;

  // - set trdp_pd_address destination location -
  dst_location->v_data_ptr = (trdp_pd_address_s *)tpa_ptr;

  return true;
}/*}}}*/

bool bic_trdp_pd_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpPdAddress"),"TrdpPdAddress");
  );

  return true;
}/*}}}*/

bool bic_trdp_pd_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpPdAddress");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_PD_PORT -
built_in_class_s trdp_pd_port_class =
{/*{{{*/
  "TrdpPdPort",
  c_modifier_public | c_modifier_final,
  10, trdp_pd_port_methods,
  0, trdp_pd_port_variables,
  bic_trdp_pd_port_consts,
  bic_trdp_pd_port_init,
  bic_trdp_pd_port_clear,
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

built_in_method_s trdp_pd_port_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_operator_binary_equal
  },
  {
    "Publish#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_Publish_0
  },
  {
    "Subscribe#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_Subscribe_0
  },
  {
    "Unpublish#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_Unpublish_0
  },
  {
    "Unsubscribe#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_Unsubscribe_0
  },
  {
    "write_size#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_write_size_0
  },
  {
    "Write#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_Write_1
  },
  {
    "Read#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_port_method_Read_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_port_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_port_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_pd_port_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_pd_port_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_pd_port_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_pd_port_s *)nullptr;
}/*}}}*/

void bic_trdp_pd_port_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)location_ptr->v_data_ptr;

  if (pdp_ptr != nullptr)
  {
    pdp_ptr->clear(it);
    cfree(pdp_ptr);
  }
}/*}}}*/

bool bic_trdp_pd_port_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_Publish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->pub_handle != TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);
    new_exception->params.push(1);

    return false;
  }

  int res = pd_ptr->Publish(&pdp_ptr->port,&pdp_ptr->pub_handle);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_PUBLISH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);
    new_exception->params.push(1);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_Subscribe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->sub_handle != TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);
    new_exception->params.push(0);

    return false;
  }

  int res = pd_ptr->Subscribe(&pdp_ptr->port,&pdp_ptr->sub_handle);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_SUBSCRIBE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);
    new_exception->params.push(1);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_Unpublish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->pub_handle == TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    new_exception->params.push(1);

    return false;
  }

  int res = pd_ptr->Unpublish(pdp_ptr->pub_handle);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_PUBLISH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);
    new_exception->params.push(0);

    return false;
  }

  pdp_ptr->pub_handle = TRDP::TRDP_NULL_HANDLE;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_Unsubscribe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->sub_handle == TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    new_exception->params.push(0);

    return false;
  }

  int res = pd_ptr->Unsubscribe(pdp_ptr->sub_handle);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_SUBSCRIBE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);
    new_exception->params.push(0);

    return false;
  }

  pdp_ptr->sub_handle = TRDP::TRDP_NULL_HANDLE;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_write_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->pub_handle == TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    new_exception->params.push(1);

    return false;
  }

  TRDP::PD::Port port;

  // - ERROR -
  int res = pd_ptr->GetPort(pdp_ptr->pub_handle,port);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_GET_PORT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  long long int result = port.size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_Write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->pub_handle == TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    new_exception->params.push(1);

    return false;
  }

  unsigned status;
  const TRDP::PD::Indicators *indicators;
  TRDP::PD::Page page;

  // - ERROR -
  int res = pd_ptr->WritePort(pdp_ptr->pub_handle,&page,&status,&indicators);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_WRITE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);
    new_exception->params.push(1);

    return false;
  }

  // - ERROR -
  if (page.size != string_ptr->size - 1)
  {
    pd_ptr->ReleasePage(&page,0);

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_INVALID_PAGE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(page.size);

    return false;
  }

  // - write page data -
  memcpy(page.data,string_ptr->data,page.size);

  // - ERROR -
  res = pd_ptr->ReleasePage(&page,0);
  if (res != TRDP::TRDP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_RELEASE_PAGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_Read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_pd_port_s *pdp_ptr = (trdp_pd_port_s *)dst_location->v_data_ptr;
  TRDP::PD *pd_ptr = (TRDP::PD *)pdp_ptr->pd_location->v_data_ptr;

  // - ERROR -
  if (pdp_ptr->sub_handle == TRDP::TRDP_NULL_HANDLE)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    new_exception->params.push(0);

    return false;
  }

  unsigned status;
  const TRDP::PD::Indicators *indicators;
  TRDP::PD::Page page;

  // - ERROR -
  int res = pd_ptr->ReadPort(pdp_ptr->sub_handle,&page,&status,&indicators);

  switch (res)
  {
    case TRDP::TRDP_NO_DATA:
    {/*{{{*/
      BIC_SET_RESULT_BLANK();
    }/*}}}*/
    break;

    case TRDP::TRDP_OK:
    {/*{{{*/
      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->create(page.size);

      // - read page data -
      memcpy(string_ptr->data,page.data,page.size);

      // - ERROR -
      res = pd_ptr->ReleasePage(&page,0);
      if (res != TRDP::TRDP_OK)
      {
        string_ptr->clear();
        cfree(string_ptr);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_RELEASE_PAGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(res);

        return false;
      }

      BIC_SET_RESULT_STRING(string_ptr);
    }/*}}}*/
    break;

    // - ERROR -
    default:

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_PD_PORT_WRITE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(res);
      new_exception->params.push(0);

      return false;
  }

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpPdPort"),"TrdpPdPort");
  );

  return true;
}/*}}}*/

bool bic_trdp_pd_port_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpPdPort");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

