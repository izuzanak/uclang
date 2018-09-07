
@begin
include "uctrdp_module.h"
@end

// - UCTRDP indexes of built in classes -
unsigned c_bi_class_trdp = c_idx_not_exist;
unsigned c_bi_class_trdp_md = c_idx_not_exist;
unsigned c_bi_class_trdp_md_gate = c_idx_not_exist;
unsigned c_bi_class_trdp_md_gate_params = c_idx_not_exist;
unsigned c_bi_class_trdp_md_address = c_idx_not_exist;
unsigned c_bi_class_trdp_md_message = c_idx_not_exist;

// - UCTRDP module -
built_in_module_s module =
{/*{{{*/
  6,                      // Class count
  uctrdp_classes,         // Classes

  0,                      // Error base index
  8,                      // Error count
  uctrdp_error_strings,   // Error strings

  uctrdp_initialize,      // Initialize function
  uctrdp_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRDP classes -
built_in_class_s *uctrdp_classes[] =
{/*{{{*/
  &trdp_class,
  &trdp_md_class,
  &trdp_md_gate_class,
  &trdp_md_gate_params_class,
  &trdp_md_address_class,
  &trdp_md_message_class,
};/*}}}*/

// - UCTRDP error strings -
const char *uctrdp_error_strings[] =
{/*{{{*/
  "error_TRDP_INVALID_PORT_VALUE",
  "error_TRDP_INVALID_PARAMETER_VALUE",
  "error_TRDP_SET_MODE_INVALID_MODE",
  "error_TRDP_SET_MODE_ERROR",
  "error_TRDP_SET_PERIOD_ERROR",
  "error_TRDP_SET_COMPARS_ERROR",
  "error_TRDP_MD_INITIALIZE_ERROR",
  "error_TRDP_MD_GATE_OPEN_ERROR",
};/*}}}*/

// - UCTRDP initialize -
bool uctrdp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trdp class identifier -
  c_bi_class_trdp = class_base_idx++;

  // - initialize trdp_md class identifier -
  c_bi_class_trdp_md = class_base_idx++;

  // - initialize trdp_md_gate class identifier -
  c_bi_class_trdp_md_gate = class_base_idx++;

  // - initialize trdp_md_gate_params class identifier -
  c_bi_class_trdp_md_gate_params = class_base_idx++;

  // - initialize trdp_md_address class identifier -
  c_bi_class_trdp_md_address = class_base_idx++;

  // - initialize trdp_md_message class identifier -
  c_bi_class_trdp_md_message = class_base_idx++;

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
  case c_error_TRDP_INVALID_PORT_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid TRDP port value: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_INVALID_PARAMETER_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid TRDP parameter value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_SET_MODE_INVALID_MODE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid TRDP mode requested\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_SET_MODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSet TRDP mode failed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_SET_PERIOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSet TRDP period failed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_SET_COMPARS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSet TRDP communication parameters failed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_MD_INITIALIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while initializing TRDP message data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_MD_GATE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning TRDP message data gate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRDP -
built_in_class_s trdp_class =
{/*{{{*/
  "Trdp",
  c_modifier_public | c_modifier_final,
  2, trdp_methods,
  3 + 9 + 1 + 6 + 5 + 6, trdp_variables,
  bic_trdp_consts,
  bic_trdp_init,
  bic_trdp_clear,
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

built_in_method_s trdp_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_variables[] =
{/*{{{*/

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

  // - message/listener flag constants -
  { "MF_TCP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MF_UDP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MF_PROTO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MF_STREAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MF_FREEBIND", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - message type constants -
  { "MT_NOTIFY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MT_REQUEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MT_REPLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MT_REPLYCFM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MT_CONFIRM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_trdp_consts(location_array_s &const_locations)
{/*{{{*/

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

  // - insert message/listener flag constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_TRDP_MF_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_MF_BIC_STATIC(TRDP::MF_TCP);
    CREATE_TRDP_MF_BIC_STATIC(TRDP::MF_UDP);
    CREATE_TRDP_MF_BIC_STATIC(TRDP::MF_PROTO);
    CREATE_TRDP_MF_BIC_STATIC(TRDP::MF_STREAM);
    CREATE_TRDP_MF_BIC_STATIC(TRDP::MF_FREEBIND);
  }

  // - insert message type constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(TRDP::MT_NOTIFY);
    CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(TRDP::MT_REQUEST);
    CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(TRDP::MT_REPLY);
    CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(TRDP::MT_REPLYCFM);
    CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(TRDP::MT_CONFIRM);
    CREATE_TRDP_MESSAGE_TYPE_BIC_STATIC(TRDP::MT_ERROR);
  }

}/*}}}*/

void bic_trdp_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_trdp_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_trdp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Trdp"),"Trdp");
  );

  return true;
}/*}}}*/

bool bic_trdp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Trdp");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_MD -
built_in_class_s trdp_md_class =
{/*{{{*/
  "TrdpMd",
  c_modifier_public | c_modifier_final,
  9, trdp_md_methods,
  0, trdp_md_variables,
  bic_trdp_md_consts,
  bic_trdp_md_init,
  bic_trdp_md_clear,
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

built_in_method_s trdp_md_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_operator_binary_equal
  },
  {
    "TrdpMd#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_method_TrdpMd_1
  },
  {
    "SetMode#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_method_SetMode_1
  },
  {
    "SetPeriod#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_method_SetPeriod_1
  },
  {
    "SetComParsUdp#3",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_method_SetComParsUdp_3
  },
  {
    "SetComParsTcp#3",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_method_SetComParsTcp_3
  },
  {
    "OpenGate#3",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_method_OpenGate_3
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_md_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_md_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_md_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TRDP::MD *)nullptr;
}/*}}}*/

void bic_trdp_md_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TRDP::MD *md_ptr = (TRDP::MD *)location_ptr->v_data_ptr;

  if (md_ptr != nullptr)
  {
    delete md_ptr;
  }
}/*}}}*/

bool bic_trdp_md_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_md_method_TrdpMd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int id;

  if (!it.retrieve_integer(src_0_location,id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpMd#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  TRDP::MD *md_ptr = new TRDP::MD();

  // - ERROR -
  if (md_ptr->Init(id) != TRDP::TRDP_OK)
  {
    delete md_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_TRDP_MD_INITIALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set trdp_md destination location -
  dst_location->v_data_ptr = (TRDP::MD *)md_ptr;

  return true;
}/*}}}*/

bool bic_trdp_md_method_SetMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_SET_MODE_INVALID_MODE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  TRDP::MD *md_ptr = (TRDP::MD *)dst_location->v_data_ptr;

  // - ERROR -
  if (md_ptr->SetMode(mode) != TRDP::TRDP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_SET_MODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_md_method_SetPeriod_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  TRDP::MD *md_ptr = (TRDP::MD *)dst_location->v_data_ptr;

  // - ERROR -
  if (md_ptr->SetPeriod(tick) != TRDP::TRDP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_SET_PERIOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

#define BIC_TRDP_SET_COMM_PARS_RETRIEVE_PARAMS(NAME) \
/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);\
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);\
  \
  long long int port;\
  long long int qos;\
  long long int ttl;\
  \
  if (!it.retrieve_integer(src_0_location,port) ||\
      !it.retrieve_integer(src_1_location,qos) ||\
      !it.retrieve_integer(src_2_location,ttl))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(3);\
    new_exception->params.push(src_0_location->v_type);\
    new_exception->params.push(src_1_location->v_type);\
    new_exception->params.push(src_2_location->v_type);\
    \
    return false;\
  }\
  \
  /* - ERROR - */\
  if (port < 0 || port > 65535)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRDP_INVALID_PORT_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(port);\
    \
    return false;\
  }\
  \
  /* - ERROR - */\
  if (qos < TRDP::QOS_DEF || qos > TRDP::QOS_P7 ||\
      ttl < 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_INVALID_PARAMETER_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  TRDP::MD::ComPars pars;\
  pars.port = port;\
  pars.qos  = qos;\
  pars.ttl  = ttl;\
/*}}}*/

bool bic_trdp_md_method_SetComParsUdp_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRDP_SET_COMM_PARS_RETRIEVE_PARAMS("SetComParsUdp#3");

  TRDP::MD *md_ptr = (TRDP::MD *)dst_location->v_data_ptr;

  // - ERROR -
  if (md_ptr->SetComPars(&pars,nullptr) != TRDP::TRDP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_SET_COMPARS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_md_method_SetComParsTcp_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRDP_SET_COMM_PARS_RETRIEVE_PARAMS("SetComParsTcp#3");

  TRDP::MD *md_ptr = (TRDP::MD *)dst_location->v_data_ptr;

  // - ERROR -
  if (md_ptr->SetComPars(nullptr,&pars) != TRDP::TRDP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_SET_COMPARS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_md_method_OpenGate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int signum;

  if (src_0_location->v_type != c_bi_class_trdp_md_gate_params ||
      src_1_location->v_type != c_bi_class_trdp_md_gate_params ||
      !it.retrieve_integer(src_2_location,signum))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("OpenGate#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  TRDP::MD *md_ptr = (TRDP::MD *)dst_location->v_data_ptr;
  TRDP::MD::Gate::Params *ipp_ptr = (TRDP::MD::Gate::Params *)src_0_location->v_data_ptr;
  TRDP::MD::Gate::Params *opp_ptr = (TRDP::MD::Gate::Params *)src_1_location->v_data_ptr;

  // - create trdp_md_gate object -
  trdp_md_gate_s *tmg_ptr = (trdp_md_gate_s *)cmalloc(sizeof(trdp_md_gate_s));
  tmg_ptr->init();

  // - retrieve unused gate identifier -
  int gate_id = uctrdp_c::new_gate_id();

  // - ERROR -
  if (md_ptr->OpenGate(tmg_ptr->gate,*ipp_ptr,*opp_ptr,signum,gate_id) != TRDP::TRDP_OK)
  {
    uctrdp_c::free_gate_id(gate_id);

    tmg_ptr->clear(it);
    cfree(tmg_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_TRDP_MD_GATE_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set reference to md -
  dst_location->v_reference_cnt.atomic_inc();
  tmg_ptr->md_location = dst_location;

  // - set gate identifier -
  tmg_ptr->gate_id = gate_id;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trdp_md_gate,tmg_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_trdp_md_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpMd"),"TrdpMd");
  );

  return true;
}/*}}}*/

bool bic_trdp_md_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpMd");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_MD_GATE -
built_in_class_s trdp_md_gate_class =
{/*{{{*/
  "TrdpMdGate",
  c_modifier_public | c_modifier_final,
  4, trdp_md_gate_methods,
  0, trdp_md_gate_variables,
  bic_trdp_md_gate_consts,
  bic_trdp_md_gate_init,
  bic_trdp_md_gate_clear,
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

built_in_method_s trdp_md_gate_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_gate_operator_binary_equal
  },
  {
    "Request#2",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_gate_method_Request_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_gate_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_gate_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_md_gate_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_md_gate_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_md_gate_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_md_gate_s *)nullptr;
}/*}}}*/

void bic_trdp_md_gate_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_md_gate_s *tmg_ptr = (trdp_md_gate_s *)location_ptr->v_data_ptr;

  if (tmg_ptr != nullptr)
  {
    tmg_ptr->clear(it);
    cfree(tmg_ptr);
  }
}/*}}}*/

bool bic_trdp_md_gate_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_md_gate_method_Request_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_integer ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Request#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__); 
  return false;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trdp_md_gate_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpMdGate"),"TrdpMdGate");
  );

  return true;
}/*}}}*/

bool bic_trdp_md_gate_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpMdGate");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_MD_GATE_PARAMS -
built_in_class_s trdp_md_gate_params_class =
{/*{{{*/
  "TrdpMdGateParams",
  c_modifier_public | c_modifier_final,
  4, trdp_md_gate_params_methods,
  0, trdp_md_gate_params_variables,
  bic_trdp_md_gate_params_consts,
  bic_trdp_md_gate_params_init,
  bic_trdp_md_gate_params_clear,
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

built_in_method_s trdp_md_gate_params_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_gate_params_operator_binary_equal
  },
  {
    "TrdpMdGateParams#4",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_gate_params_method_TrdpMdGateParams_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_gate_params_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_gate_params_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_md_gate_params_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_md_gate_params_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_md_gate_params_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TRDP::MD::Gate::Params *)nullptr;
}/*}}}*/

void bic_trdp_md_gate_params_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TRDP::MD::Gate::Params *tmgp_ptr = (TRDP::MD::Gate::Params *)location_ptr->v_data_ptr;

  if (tmgp_ptr != nullptr)
  {
    cfree(tmgp_ptr);
  }
}/*}}}*/

bool bic_trdp_md_gate_params_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_md_gate_params_method_TrdpMdGateParams_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int nslots;
  long long int nbufs;
  long long int nevts;
  long long int bufsz;

  if (!it.retrieve_integer(src_0_location,nslots) ||
      !it.retrieve_integer(src_1_location,nbufs) ||
      !it.retrieve_integer(src_2_location,nevts) ||
      !it.retrieve_integer(src_3_location,bufsz))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpMdGateParams#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - ERROR -
  if (nslots < 0 || nslots > USHRT_MAX ||
      nbufs  < 0 || nbufs  > USHRT_MAX ||
      nevts  < 0 || nevts  > UINT_MAX ||
      bufsz  < 0 || bufsz  > UINT_MAX)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_INVALID_PARAMETER_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  TRDP::MD::Gate::Params *tmgp_ptr = (TRDP::MD::Gate::Params *)cmalloc(sizeof(TRDP::MD::Gate::Params));
  tmgp_ptr->nslots = nslots;
  tmgp_ptr->nbufs = nbufs;
  tmgp_ptr->nevts = nevts;
  tmgp_ptr->bufsz = bufsz;

  // - set trdp_md destination location -
  dst_location->v_data_ptr = (TRDP::MD::Gate::Params *)tmgp_ptr;

  return true;
}/*}}}*/

bool bic_trdp_md_gate_params_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpMdGateParams"),"TrdpMdGateParams");
  );

  return true;
}/*}}}*/

bool bic_trdp_md_gate_params_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpMdGateParams");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_MD_ADDRESS -
built_in_class_s trdp_md_address_class =
{/*{{{*/
  "TrdpMdAddress",
  c_modifier_public | c_modifier_final,
  4, trdp_md_address_methods,
  0, trdp_md_address_variables,
  bic_trdp_md_address_consts,
  bic_trdp_md_address_init,
  bic_trdp_md_address_clear,
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

built_in_method_s trdp_md_address_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_address_operator_binary_equal
  },
  {
    "TrdpMdAddress#4",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_address_method_TrdpMdAddress_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_address_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_address_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_md_address_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_md_address_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_md_address_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_md_address_s *)nullptr;
}/*}}}*/

void bic_trdp_md_address_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_md_address_s *tma_ptr = (trdp_md_address_s *)location_ptr->v_data_ptr;

  if (tma_ptr != nullptr)
  {
    tma_ptr->clear(it);
    cfree(tma_ptr);
  }
}/*}}}*/

bool bic_trdp_md_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_md_address_method_TrdpMdAddress_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int lli_dst_addr = 0;
  long long int lli_src_addr = 0;

  if (src_0_location->v_type != c_bi_class_string ||
      (!it.retrieve_integer(src_1_location,lli_dst_addr) && src_1_location->v_type != c_bi_class_string) ||
      src_2_location->v_type != c_bi_class_string ||
      (!it.retrieve_integer(src_3_location,lli_src_addr) && src_3_location->v_type != c_bi_class_string))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpMdAddress#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

#define BIC_TRDP_MD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(LOCATION,TARGET)\
{/*{{{*/\
  if (LOCATION->v_type == c_bi_class_string)\
  {\
    /* - ERROR - */\
    if (!Str2IP(((string_s *)LOCATION->v_data_ptr)->data,TARGET))\
    {\
      /* FIXME TODO throw proper exception */\
      BIC_TODO_ERROR(__FILE__,__LINE__);\
      return false;\
    }\
  }\
  else\
  {\
    TARGET = lli_ ## TARGET;\
  }\
}/*}}}*/

  // - retrieve destination ip addresses -
  unsigned dst_addr;
  BIC_TRDP_MD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(src_1_location,dst_addr);

  // - retrieve source ip addresses -
  unsigned src_addr;
  BIC_TRDP_MD_ADDRESS_CONSTRUCTOR_RETRIEVE_IP(src_3_location,src_addr);

  // - ERROR -
  if (((string_s *)src_0_location->v_data_ptr)->size - 1 > TRDP::MAX_USR_LEN ||
      ((string_s *)src_2_location->v_data_ptr)->size - 1 > TRDP::MAX_USR_LEN)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create trdp_md_address object -
  trdp_md_address_s *tma_ptr = (trdp_md_address_s *)cmalloc(sizeof(trdp_md_address_s));
  tma_ptr->init();

  // - set destination host and address -
  tma_ptr->dst_host.h = 0;
  tma_ptr->dst_host.ip = dst_addr;

  src_0_location->v_reference_cnt.atomic_inc();
  tma_ptr->dst_user_loc = src_0_location;

  // - set source host and address -
  tma_ptr->src_host.h = 0;
  tma_ptr->src_host.ip = src_addr;

  src_2_location->v_reference_cnt.atomic_inc();
  tma_ptr->src_user_loc = src_2_location;

  // - set trdp_md destination location -
  dst_location->v_data_ptr = (trdp_md_address_s *)tma_ptr;

  return true;
}/*}}}*/

bool bic_trdp_md_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpMdAddress"),"TrdpMdAddress");
  );

  return true;
}/*}}}*/

bool bic_trdp_md_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpMdAddress");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRDP_MD_MESSAGE -
built_in_class_s trdp_md_message_class =
{/*{{{*/
  "TrdpMdMessage",
  c_modifier_public | c_modifier_final,
  4, trdp_md_message_methods,
  0, trdp_md_message_variables,
  bic_trdp_md_message_consts,
  bic_trdp_md_message_init,
  bic_trdp_md_message_clear,
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

built_in_method_s trdp_md_message_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_message_operator_binary_equal
  },
  {
    "TrdpMdMessage#5",
    c_modifier_public | c_modifier_final,
    bic_trdp_md_message_method_TrdpMdMessage_5
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_message_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_md_message_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_md_message_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trdp_md_message_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trdp_md_message_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_md_message_s *)nullptr;
}/*}}}*/

void bic_trdp_md_message_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_md_message_s *tmm_ptr = (trdp_md_message_s *)location_ptr->v_data_ptr;

  if (tmm_ptr != nullptr)
  {
    tmm_ptr->clear(it);
    cfree(tmm_ptr);
  }
}/*}}}*/

bool bic_trdp_md_message_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_md_message_method_TrdpMdMessage_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int type;
  long long int comm_id;
  long long int timeout;

  if (!it.retrieve_integer(src_0_location,type) ||
      src_1_location->v_type != c_bi_class_trdp_md_address ||
      !it.retrieve_integer(src_2_location,comm_id) ||
      !it.retrieve_integer(src_3_location,timeout) ||
      src_4_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpMdMessage#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  string_s *data_ptr = (string_s *)src_4_location->v_data_ptr;

  // - ERROR -
  if (data_ptr->size - 1 > TRDP::MAX_MD_SIZE)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create trdp_md_message object -
  trdp_md_message_s *tmm_ptr = (trdp_md_message_s *)cmalloc(sizeof(trdp_md_message_s));
  tmm_ptr->init();

  memset(&tmm_ptr->message,0,sizeof(tmm_ptr->message));

  // FIXME TODO continue ...

  // - set trdp_md destination location -
  dst_location->v_data_ptr = (trdp_md_message_s *)tmm_ptr;

  return true;
}/*}}}*/

bool bic_trdp_md_message_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpMdMessage"),"TrdpMdMessage");
  );

  return true;
}/*}}}*/

bool bic_trdp_md_message_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpMdMessage");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

