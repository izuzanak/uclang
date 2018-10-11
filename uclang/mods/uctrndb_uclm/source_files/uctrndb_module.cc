
@begin
include "uctrndb_module.h"
@end

// - UCTRNDB indexes of built in classes -
unsigned c_bi_class_trndb_client = c_idx_not_exist;
unsigned c_bi_class_trndb_vehicle = c_idx_not_exist;
unsigned c_bi_class_trndb_consist = c_idx_not_exist;
unsigned c_bi_class_trndb_vehicle_info = c_idx_not_exist;
unsigned c_bi_class_trndb_consist_info = c_idx_not_exist;

// - UCTRNDB module -
built_in_module_s module =
{/*{{{*/
  5,                       // Class count
  uctrndb_classes,         // Classes

  0,                       // Error base index
  2,                       // Error count
  uctrndb_error_strings,   // Error strings

  uctrndb_initialize,      // Initialize function
  uctrndb_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRNDB classes -
built_in_class_s *uctrndb_classes[] =
{/*{{{*/
  &trndb_client_class,
  &trndb_vehicle_class,
  &trndb_consist_class,
  &trndb_vehicle_info_class,
  &trndb_consist_info_class,
};/*}}}*/

// - UCTRNDB error strings -
const char *uctrndb_error_strings[] =
{/*{{{*/
  "error_TRNDB_CLIENT_CREATE_ERROR",
  "error_TRNDB_CLIENT_WRONG_CALLBACK_DELEGATE",
};/*}}}*/

// - UCTRNDB initialize -
bool uctrndb_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trndb_client class identifier -
  c_bi_class_trndb_client = class_base_idx++;

  // - initialize trndb_vehicle class identifier -
  c_bi_class_trndb_vehicle = class_base_idx++;

  // - initialize trndb_consist class identifier -
  c_bi_class_trndb_consist = class_base_idx++;

  // - initialize trndb_vehicle_info class identifier -
  c_bi_class_trndb_vehicle_info = class_base_idx++;

  // - initialize trndb_consist_info class identifier -
  c_bi_class_trndb_consist_info = class_base_idx++;

  return true;
}/*}}}*/

// - UCTRNDB print exception -
bool uctrndb_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TRNDB_CLIENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating Trndb client\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRNDB_CLIENT_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for Trndb client connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRNDB_CLIENT -
built_in_class_s trndb_client_class =
{/*{{{*/
  "TrndbClient",
  c_modifier_public | c_modifier_final,
  15, trndb_client_methods,
  9 + 4, trndb_client_variables,
  bic_trndb_client_consts,
  bic_trndb_client_init,
  bic_trndb_client_clear,
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

built_in_method_s trndb_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_operator_binary_equal
  },
  {
    "TrndbClient#2",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_TrndbClient_2
  },
  {
    "SetCallback#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_SetCallback_1
  },
  {
    "Recall#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_Recall_0
  },
  {
    "Relock#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_Relock_0
  },
  {
    "TrnId#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_TrnId_0
  },
  {
    "TrnOperator#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_TrnOperator_0
  },
  {
    "Invalid#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_Invalid_0
  },
  {
    "EtbTopoCnt#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_EtbTopoCnt_0
  },
  {
    "OpTrnTopoCnt#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_OpTrnTopoCnt_0
  },
  {
    "vehicles#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_vehicles_0
  },
  {
    "consists#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_consists_0
  },
  {
    "info#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_client_method_info_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_client_method_print_0
  },
};/*}}}*/

built_in_variable_s trndb_client_variables[] =
{/*{{{*/

  // - trndb event constants -
  { "E_ETBINAUG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_TRNINAUG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_INVALID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_VALID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_SHARED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_CONFIRMED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_UNCONFIRMED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E_MAYBE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - trndb orientation constants -
  { "ORIENT_UNDEFINED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ORIENT_DIRECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ORIENT_INVERSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ORIENT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_TRNDB_CLIENT_METHOD_GET_STRING(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  const char *value = ((trndb_proxy_s *)dst_location->v_data_ptr)->proxy->NAME();\
  \
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(value),value);\
  \
  BIC_SET_RESULT_STRING(string_ptr);\
  \
  return true;\
}/*}}}*/

#define BIC_TRNDB_CLIENT_METHOD_GET_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  long long int result = ((trndb_proxy_s *)dst_location->v_data_ptr)->proxy->NAME();\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  \
  return true;\
}/*}}}*/

void bic_trndb_client_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert trndb event constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_TRNDB_EVENT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_ETBINAUG);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_TRNINAUG);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_INVALID);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_VALID);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_SHARED);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_CONFIRMED);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_UNCONFIRMED);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_ALL);
    CREATE_TRNDB_EVENT_BIC_STATIC(TrnDb::BasicOpTrnDbCli::E_MAYBE);
  }

  // - insert trndb orientation constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_TRNDB_ORIENTATION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRNDB_ORIENTATION_BIC_STATIC(TrnDb::Orientation::ORIENT_UNDEFINED);
    CREATE_TRNDB_ORIENTATION_BIC_STATIC(TrnDb::Orientation::ORIENT_DIRECT);
    CREATE_TRNDB_ORIENTATION_BIC_STATIC(TrnDb::Orientation::ORIENT_INVERSE);
    CREATE_TRNDB_ORIENTATION_BIC_STATIC(TrnDb::Orientation::ORIENT_ERROR);
  }

}/*}}}*/

void bic_trndb_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trndb_proxy_s *)nullptr;
}/*}}}*/

void bic_trndb_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trndb_proxy_s *tdp_ptr = (trndb_proxy_s *)location_ptr->v_data_ptr;

  if (tdp_ptr != nullptr)
  {
    tdp_ptr->clear(it);
    delete tdp_ptr;
  }
}/*}}}*/

bool bic_trndb_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trndb_client_method_TrndbClient_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int full_op;
  long long int auto_update;

  if (!it.retrieve_integer(src_0_location,full_op) ||
      !it.retrieve_integer(src_1_location,auto_update))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrndbClient#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - create trndb_client object -
  trndb_proxy_s *tdp_ptr = new trndb_proxy_s();
  tdp_ptr->init();

  try {

    // - create full train topology database client -
    if (full_op)
    {
      tdp_ptr->proxy = TrnDb::FullOpTrnDbCli::Create(auto_update != 0);
    }

    // - create basic train topology database client -
    else
    {
      tdp_ptr->proxy = TrnDb::BasicOpTrnDbCli::Create(auto_update != 0);
    }
  }

  // - ERROR -
  catch (Ucf2::Exception &e)
  {
    tdp_ptr->clear(it);
    delete tdp_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_TRNDB_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set trndb change callback -
  using std::placeholders::_1;
  tdp_ptr->proxy.SetCallback(std::bind(&trndb_proxy_s::trndb_changed,_1));

  // - set trndb_client destination location -
  dst_location->v_data_ptr = (trndb_proxy_s *)tdp_ptr;

  return true;
}/*}}}*/

bool bic_trndb_client_method_SetCallback_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SetCallback#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  trndb_proxy_s *tdp_ptr = (trndb_proxy_s *)dst_location->v_data_ptr;
  delegate_s *delegate_ptr = (delegate_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRNDB_CLIENT_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (tdp_ptr->callback_dlg != nullptr)
  {
    it.release_location_ptr(tdp_ptr->callback_dlg);
  }

  // - register callback delegate -
  src_0_location->v_reference_cnt.atomic_inc();
  tdp_ptr->callback_dlg = src_0_location;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trndb_client_method_Recall_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trndb_proxy_s *tdp_ptr = (trndb_proxy_s *)dst_location->v_data_ptr;

  tdp_ptr->it_ptr = &it;
  tdp_ptr->source_pos = operands[c_source_pos_idx];
  tdp_ptr->ret_code = c_run_return_code_OK;

  // - set trndb proxy global pointer -
  trndb_proxy_s::g_proxy_ptr = tdp_ptr;

  tdp_ptr->proxy.Recall();

  // - if exception occurred -
  if (tdp_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_trndb_client_method_Relock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((trndb_proxy_s *)dst_location->v_data_ptr)->proxy.Relock();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trndb_client_method_TrnId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CLIENT_METHOD_GET_STRING(TrnId);
}/*}}}*/

bool bic_trndb_client_method_TrnOperator_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CLIENT_METHOD_GET_STRING(TrnOperator);
}/*}}}*/

bool bic_trndb_client_method_Invalid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CLIENT_METHOD_GET_INTEGER(Invalid);
}/*}}}*/

bool bic_trndb_client_method_EtbTopoCnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CLIENT_METHOD_GET_INTEGER(EtbTopoCnt);
}/*}}}*/

bool bic_trndb_client_method_OpTrnTopoCnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CLIENT_METHOD_GET_INTEGER(OpTrnTopoCnt);
}/*}}}*/

bool bic_trndb_client_method_vehicles_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trndb_proxy_s *tdp_ptr = (trndb_proxy_s *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  for (const TrnDb::OpVehicle &vehicle : tdp_ptr->proxy->Vehicles())
  {
    if (!vehicle.IsGap())
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trndb_vehicle,&vehicle);
      array_ptr->push(new_location);
    }
  }

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_trndb_client_method_consists_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trndb_proxy_s *tdp_ptr = (trndb_proxy_s *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  for (const TrnDb::OpConsist &consist : tdp_ptr->proxy->Consists())
  {
    if (!consist.IsGap())
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trndb_consist,&consist);
      array_ptr->push(new_location);
    }
  }

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_trndb_client_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  trndb_proxy_s *tdp_ptr = (trndb_proxy_s *)dst_location->v_data_ptr;

  if (src_0_location->v_type == c_bi_class_trndb_vehicle)
  {
    const TrnDb::OpVehicle *vehicle = (const TrnDb::OpVehicle *)src_0_location->v_data_ptr;
    const TrnDb::VehInfo *veh_info = tdp_ptr->proxy->VehicleInfo(vehicle->opVehNo);

    if (veh_info != nullptr)
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trndb_vehicle_info,veh_info);
      BIC_SET_RESULT(new_location);
    }
    else
    {
      BIC_SET_RESULT_BLANK();
    }
  }
  else if (src_0_location->v_type == c_bi_class_trndb_consist)
  {
    const TrnDb::OpConsist *consist = (const TrnDb::OpConsist *)src_0_location->v_data_ptr;
    const TrnDb::CstInfo *cst_info = tdp_ptr->proxy->ConsistInfo(consist->opCstNo);

    if (cst_info != nullptr)
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_trndb_consist_info,cst_info);
      BIC_SET_RESULT(new_location);
    }
    else
    {
      BIC_SET_RESULT_BLANK();
    }
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("info#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_trndb_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrndbClient"),"TrndbClient");
  );

  return true;
}/*}}}*/

bool bic_trndb_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrndbClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRNDB_VEHICLE -
built_in_class_s trndb_vehicle_class =
{/*{{{*/
  "TrndbVehicle",
  c_modifier_public | c_modifier_final,
  10, trndb_vehicle_methods,
  0, trndb_vehicle_variables,
  bic_trndb_vehicle_consts,
  bic_trndb_vehicle_init,
  bic_trndb_vehicle_clear,
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

built_in_method_s trndb_vehicle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_operator_binary_equal
  },
  {
    "vehId#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_vehId_0
  },
  {
    "opVehNo#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_opVehNo_0
  },
  {
    "trnVehNo#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_trnVehNo_0
  },
  {
    "isLead#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_isLead_0
  },
  {
    "leadDir#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_leadDir_0
  },
  {
    "vehOrient#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_vehOrient_0
  },
  {
    "ownOpCstNo#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_method_ownOpCstNo_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_vehicle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_vehicle_method_print_0
  },
};/*}}}*/

built_in_variable_s trndb_vehicle_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_TRNDB_VEHICLE_METHOD_GET_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  long long int value = ((const TrnDb::OpVehicle *)dst_location->v_data_ptr)->NAME;\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,value);\
  \
  return true;\
}/*}}}*/

void bic_trndb_vehicle_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trndb_vehicle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (const TrnDb::OpVehicle *)nullptr;
}/*}}}*/

void bic_trndb_vehicle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_trndb_vehicle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trndb_vehicle_method_vehId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *value = ((const TrnDb::OpVehicle *)dst_location->v_data_ptr)->vehId;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(value),value);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_trndb_vehicle_method_opVehNo_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_METHOD_GET_INTEGER(opVehNo)
}/*}}}*/

bool bic_trndb_vehicle_method_trnVehNo_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_METHOD_GET_INTEGER(trnVehNo)
}/*}}}*/

bool bic_trndb_vehicle_method_isLead_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int value = ((const TrnDb::OpVehicle *)dst_location->v_data_ptr)->isLead.val;

  if (value == TrnDb::Antivalent8::Value::UNDEFINED)
  {
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    value = (value == TrnDb::Antivalent8::Value::ATRUE);

    BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
  }

  return true;
}/*}}}*/

bool bic_trndb_vehicle_method_leadDir_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int value = ((const TrnDb::OpVehicle *)dst_location->v_data_ptr)->leadDir;

  if (value != 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_trndb_vehicle_method_vehOrient_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_METHOD_GET_INTEGER(vehOrient);
}/*}}}*/

bool bic_trndb_vehicle_method_ownOpCstNo_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_METHOD_GET_INTEGER(ownOpCstNo);
}/*}}}*/

bool bic_trndb_vehicle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrndbVehicle"),"TrndbVehicle");
  );

  return true;
}/*}}}*/

bool bic_trndb_vehicle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrndbVehicle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRNDB_CONSIST -
built_in_class_s trndb_consist_class =
{/*{{{*/
  "TrndbConsist",
  c_modifier_public | c_modifier_final,
  7, trndb_consist_methods,
  0, trndb_consist_variables,
  bic_trndb_consist_consts,
  bic_trndb_consist_init,
  bic_trndb_consist_clear,
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

built_in_method_s trndb_consist_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_operator_binary_equal
  },
  {
    "UUID#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_method_UUID_0
  },
  {
    "opCstNo#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_method_opCstNo_0
  },
  {
    "trnCstNo#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_method_trnCstNo_0
  },
  {
    "opCstOrient#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_method_opCstOrient_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_consist_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_consist_method_print_0
  },
};/*}}}*/

built_in_variable_s trndb_consist_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_TRNDB_CONSIST_METHOD_GET_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  long long int value = ((const TrnDb::OpConsist *)dst_location->v_data_ptr)->NAME;\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,value);\
  \
  return true;\
}/*}}}*/

void bic_trndb_consist_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trndb_consist_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (const TrnDb::OpConsist *)nullptr;
}/*}}}*/

void bic_trndb_consist_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_trndb_consist_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trndb_consist_method_UUID_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *uuid = ((const TrnDb::OpConsist *)dst_location->v_data_ptr)->cstUUID.Str();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(uuid),uuid);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_trndb_consist_method_opCstNo_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CONSIST_METHOD_GET_INTEGER(opCstNo);
}/*}}}*/

bool bic_trndb_consist_method_trnCstNo_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CONSIST_METHOD_GET_INTEGER(trnCstNo);
}/*}}}*/

bool bic_trndb_consist_method_opCstOrient_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CONSIST_METHOD_GET_INTEGER(opCstOrient);
}/*}}}*/

bool bic_trndb_consist_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrndbConsist"),"TrndbConsist");
  );

  return true;
}/*}}}*/

bool bic_trndb_consist_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrndbConsist");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRNDB_VEHICLE_INFO -
built_in_class_s trndb_vehicle_info_class =
{/*{{{*/
  "TrndbVehicleInfo",
  c_modifier_public | c_modifier_final,
  8, trndb_vehicle_info_methods,
  0, trndb_vehicle_info_variables,
  bic_trndb_vehicle_info_consts,
  bic_trndb_vehicle_info_init,
  bic_trndb_vehicle_info_clear,
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

built_in_method_s trndb_vehicle_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_info_operator_binary_equal
  },
  {
    "vehId#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_info_method_vehId_0
  },
  {
    "vehType#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_info_method_vehType_0
  },
  {
    "vehOrient#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_info_method_vehOrient_0
  },
  {
    "cstVehNo#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_info_method_cstVehNo_0
  },
  {
    "tractVeh#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_vehicle_info_method_tractVeh_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_vehicle_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_vehicle_info_method_print_0
  },
};/*}}}*/

built_in_variable_s trndb_vehicle_info_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_TRNDB_VEHICLE_INFO_METHOD_GET_STRING(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  const char *value = ((const TrnDb::VehInfo *)dst_location->v_data_ptr)->NAME;\
  \
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(value),value);\
  \
  BIC_SET_RESULT_STRING(string_ptr);\
  \
  return true;\
}/*}}}*/

#define BIC_TRNDB_VEHICLE_INFO_METHOD_GET_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  long long int value = ((const TrnDb::VehInfo *)dst_location->v_data_ptr)->NAME;\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,value);\
  \
  return true;\
}/*}}}*/

void bic_trndb_vehicle_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trndb_vehicle_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TrnDb::VehInfo *)nullptr;
}/*}}}*/

void bic_trndb_vehicle_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_trndb_vehicle_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trndb_vehicle_info_method_vehId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_INFO_METHOD_GET_STRING(vehId);
}/*}}}*/

bool bic_trndb_vehicle_info_method_vehType_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_INFO_METHOD_GET_STRING(vehType);
}/*}}}*/

bool bic_trndb_vehicle_info_method_vehOrient_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_INFO_METHOD_GET_INTEGER(vehOrient);
}/*}}}*/

bool bic_trndb_vehicle_info_method_cstVehNo_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_VEHICLE_INFO_METHOD_GET_INTEGER(cstVehNo);
}/*}}}*/

bool bic_trndb_vehicle_info_method_tractVeh_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int value = ((const TrnDb::VehInfo *)dst_location->v_data_ptr)->tractVeh.val;

  if (value == TrnDb::Antivalent8::Value::UNDEFINED)
  {
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    value = (value == TrnDb::Antivalent8::Value::ATRUE);

    BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
  }

  return true;
}/*}}}*/

bool bic_trndb_vehicle_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrndbVehicleInfo"),"TrndbVehicleInfo");
  );

  return true;
}/*}}}*/

bool bic_trndb_vehicle_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrndbVehicleInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRNDB_CONSIST_INFO -
built_in_class_s trndb_consist_info_class =
{/*{{{*/
  "TrndbConsistInfo",
  c_modifier_public | c_modifier_final,
  6, trndb_consist_info_methods,
  0, trndb_consist_info_variables,
  bic_trndb_consist_info_consts,
  bic_trndb_consist_info_init,
  bic_trndb_consist_info_clear,
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

built_in_method_s trndb_consist_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_info_operator_binary_equal
  },
  {
    "cstId#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_info_method_cstId_0
  },
  {
    "cstType#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_info_method_cstType_0
  },
  {
    "UUID#0",
    c_modifier_public | c_modifier_final,
    bic_trndb_consist_info_method_UUID_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_consist_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trndb_consist_info_method_print_0
  },
};/*}}}*/

built_in_variable_s trndb_consist_info_variables[] =
{/*{{{*/
};/*}}}*/

void bic_trndb_consist_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_trndb_consist_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TrnDb::CstInfo *)nullptr;
}/*}}}*/

void bic_trndb_consist_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_trndb_consist_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_TRNDB_CONSIST_INFO_METHOD_GET_STRING(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  const char *value = ((const TrnDb::CstInfo *)dst_location->v_data_ptr)->NAME();\
  \
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(value),value);\
  \
  BIC_SET_RESULT_STRING(string_ptr);\
  \
  return true;\
}/*}}}*/

bool bic_trndb_consist_info_method_cstId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CONSIST_INFO_METHOD_GET_STRING(CstId);
}/*}}}*/

bool bic_trndb_consist_info_method_cstType_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TRNDB_CONSIST_INFO_METHOD_GET_STRING(CstType);
}/*}}}*/

bool bic_trndb_consist_info_method_UUID_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  const char *value = ((const TrnDb::CstInfo *)dst_location->v_data_ptr)->CstUUID()->Str();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(value),value);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_trndb_consist_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrndbConsistInfo"),"TrndbConsistInfo");
  );

  return true;
}/*}}}*/

bool bic_trndb_consist_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrndbConsistInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

