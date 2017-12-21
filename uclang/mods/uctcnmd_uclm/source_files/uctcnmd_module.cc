
@begin
include "uctcnmd_module.h"
@end

// - UCTCNMD indexes of built in classes -
unsigned c_bi_class_tcn_msg = c_idx_not_exist;
unsigned c_bi_class_tcn_address = c_idx_not_exist;
unsigned c_bi_class_tcn_am_address = c_idx_not_exist;
unsigned c_bi_class_tcn_caller = c_idx_not_exist;
unsigned c_bi_class_tcn_replier = c_idx_not_exist;
unsigned c_bi_class_tcn_call_handler = c_idx_not_exist;
unsigned c_bi_class_tcn_repl_handler = c_idx_not_exist;

// - UCTCNMD module -
built_in_module_s module =
{/*{{{*/
  7,                       // Class count
  uctcnmd_classes,         // Classes

  0,                       // Error base index
  13,                      // Error count
  uctcnmd_error_strings,   // Error strings

  uctcnmd_initialize,      // Initialize function
  uctcnmd_print_exception, // Print exceptions function
};/*}}}*/

// - UCTCNMD classes -
built_in_class_s *uctcnmd_classes[] =
{/*{{{*/
  &tcn_msg_class,
  &tcn_address_class,
  &tcn_am_address_class,
  &tcn_caller_class,
  &tcn_replier_class,
  &tcn_call_handler_class,
  &tcn_repl_handler_class,
};/*}}}*/

// - UCTCNMD error strings -
const char *uctcnmd_error_strings[] =
{/*{{{*/
  "error_TCN_MSG_WRONG_U8_VALUE_RANGE",
  "error_TCN_ADDRESS_INVALID_ADDRESS_TYPE",
  "error_TCN_CALLER_WRONG_CALLBACK_DELEGATE",
  "error_TCN_CALLER_REGISTER_ERROR",
  "error_TCN_CALLER_CALL_REQUEST_INVALID_TIMEOUT",
  "error_TCN_CALLER_CALL_REQUEST_ERROR",
  "error_TCN_REPLIER_WRONG_CALLBACK_DELEGATE",
  "error_TCN_REPLIER_WRONG_CLOSE_DELEGATE",
  "error_TCN_REPLIER_REQUEST_INVALID_INSTANCE_COUNT",
  "error_TCN_REPLIER_REGISTER_ERROR",
  "error_TCN_CALL_HANDLER_CANCEL_ERROR",
  "error_TCN_REPL_HANDLER_REPLY_REQUEST_ERROR",
  "error_TCN_REPL_HANDLER_CANCEL_ERROR",
};/*}}}*/

// - UCTCNMD initialize -
bool uctcnmd_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize tcn_msg class identifier -
  c_bi_class_tcn_msg = class_base_idx++;

  // - initialize tcn_address class identifier -
  c_bi_class_tcn_address = class_base_idx++;

  // - initialize tcn_am_address class identifier -
  c_bi_class_tcn_am_address = class_base_idx++;

  // - initialize tcn_caller class identifier -
  c_bi_class_tcn_caller = class_base_idx++;

  // - initialize tcn_replier class identifier -
  c_bi_class_tcn_replier = class_base_idx++;

  // - initialize tcn_call_handler class identifier -
  c_bi_class_tcn_call_handler = class_base_idx++;

  // - initialize tcn_repl_handler class identifier -
  c_bi_class_tcn_repl_handler = class_base_idx++;

  return true;
}/*}}}*/

// - UCTCNMD print exception -
bool uctcnmd_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_TCN_MSG_WRONG_U8_VALUE_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid value of parameter %" HOST_LL_FORMAT "d, out of U8 range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_ADDRESS_INVALID_ADDRESS_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid TCN address type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_CALLER_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of callback delegate for tcn caller\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_CALLER_REGISTER_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while registering caller: %s\n",c_msg_res_strings[exception.params[0]]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_CALLER_CALL_REQUEST_INVALID_TIMEOUT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcn call request invalid timeout value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_CALLER_CALL_REQUEST_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while requesting call: %s\n",c_msg_res_strings[exception.params[0]]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_REPLIER_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of callback delegate for tcn replier\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_REPLIER_WRONG_CLOSE_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of close delegate for tcn replier\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_REPLIER_REQUEST_INVALID_INSTANCE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTcn replier register invalid instance count\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_REPLIER_REGISTER_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while registering replier: %s",c_msg_res_strings[exception.params[0]]);
    if (exception.params[0] == msg_ami_err)
    {
      fprintf(stderr,": %s",amiGetResultText((AM_RESULT)exception.params[1]));
    }
    fprintf(stderr,"\n ---------------------------------------- \n");
    break;
  case c_error_TCN_CALL_HANDLER_CANCEL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while cancelling call session: %s\n",c_msg_res_strings[exception.params[0]]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_REPL_HANDLER_REPLY_REQUEST_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while requesting reply: %s\n",c_msg_res_strings[exception.params[0]]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TCN_REPL_HANDLER_CANCEL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while cancelling reply session: %s\n",c_msg_res_strings[exception.params[0]]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class TCN_MSG -
built_in_class_s tcn_msg_class =
{/*{{{*/
  "TcnMsg",
  c_modifier_public | c_modifier_final,
  4, tcn_msg_methods,
  12 + 119, tcn_msg_variables,
  bic_tcn_msg_consts,
  bic_tcn_msg_init,
  bic_tcn_msg_clear,
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

built_in_method_s tcn_msg_methods[] =
{/*{{{*/
  {
    "RpcMain#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_msg_method_RpcMain_0
  },
  {
    "Main#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_msg_method_Main_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_msg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_msg_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_msg_variables[] =
{/*{{{*/

  // - tcn message constants -
  { "AM_MAX_FCT_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_MAX_DIR_ENTRS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_MAX_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SAME_STATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_UNKNOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_MANAGER_FCT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_AGENT_FCT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ROUTER_FCT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SAME_NODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SYSTEM_ADDR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ANY_TOPO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ADD_REM_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - tcn message result codes constants -
  { "AM_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_FAILURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_BUS_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_CONN_OVF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CONN_TMO_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SEND_TMO_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REPLY_TMO_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ALIVE_TMO_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NO_LOC_MEM_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NO_REM_MEM_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_CANC_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ALREADY_USED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ADDR_FMT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NO_REPLY_EXP_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NR_OF_CALLS_OVF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REPLY_LEN_OVF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_DUPL_LINK_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_MY_DEV_UNKNOWN_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NO_READY_INST_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NR_OF_INST_OVF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CALL_LEN_OVF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_UNKNOWN_DEST_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_INAUG_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_TRY_LATER_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_FIN_NOT_REG_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_GW_FIN_NOT_REG_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_GW_ORI_REG_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REPEAT_TMO_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ADDRESSING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_MAX_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_DUPL_START_MSNGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SEND_POOL_FULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_RECEIVE_POOL_FULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_INIT_POOL_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CREATE_THREAD_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_TRY_LATER_ALIVE_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_AMI_NOT_INIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_RECV_CNF_NOT_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REPL_CNF_NOT_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_ERRORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_NEXT_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_TOPO_CNT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_NOT_NODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_ROUT_FCT_NSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_ST_AND_NEXT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_FC_AND_NEXT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_UNDEFINED_BUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_BAD_DEV_ADDR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_ST_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_FCT_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_UNKNOWN_MTC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_BAD_PCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_DT_PCK_SIZE_OVR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_BAD_LAST_PCK_SZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_BAD_PACKET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_BAD_PACK_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_PACK_NO_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_LOC_STOP_COMM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_ERRORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_NEXT_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_TOPO_CNT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_NOT_NODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_ROUT_FCT_NSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_ST_AND_NEXT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_FC_AND_NEXT_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_UNDEFINED_BUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_BAD_DEV_ADDR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_ST_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_FCT_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_UNKNOWN_MTC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_BAD_PCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_DT_PCK_SIZE_OVR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_BAD_LAST_PCK_SZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_BAD_PACKET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_BAD_PACK_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_PACK_NO_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_STOP_COMM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NOT_MANAGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CANC_CALL_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REPL_INST_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ADD_FCT_TO_FUNDI_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SAME_FCT_ALR_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_FCT_NOT_BOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_STATION_ID_NOT_SET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_INVALID_TOPO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_BUF_NOT_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REQ_IN_PROGRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_MSNGR_NOT_RUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ZERO_IN_MSG_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_OUT_MSG_NULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_SESS_QUEUE_OVERFLOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_GROUP_NOT_IMPLEMENTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_AMI_AMA_FAILED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CALL_CNF_NULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_INVALID_STATION_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_RETURN_PATH_BAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_BAD_NET_HEADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_INVALID_EVENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_INVALID_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NO_REPLY_REQ_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_RESULT_BUFF_TOO_SMALL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_NOT_SUPPORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_CANCEL_WRONG_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_REQ_NO_FREE_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_CONF_WRONG_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_CONN_NO_MEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_CONN_NO_FREE_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_RECV_WRONG_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_DATA_TOO_BIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_INIT_MEM_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_REQ_NO_MEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_REQ_COMP_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_CM_REQ_DECOMP_ERR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_BAD_REPLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ST_ID_DIFFERENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_STADI_DIFFERENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_REM_FUNDI_DIFFERENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_ST_RD_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AM_BAD_CALL", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define UCTCNMD_CHECK_INTEGER_U8_RANGE(VALUE,INDEX) \
{/*{{{*/\
  if ((VALUE) < 0 || (VALUE) > 255)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_MSG_WRONG_U8_VALUE_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(INDEX);\
    \
    return false;\
  }\
}/*}}}*/

void bic_tcn_msg_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert tcn message constants -
  {
    const_locations.push_blanks(12);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 12);

#define CREATE_TCN_MSG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCN_MSG_BIC_STATIC(AM_MAX_FCT_ID);
    CREATE_TCN_MSG_BIC_STATIC(AM_MAX_DIR_ENTRS);
    CREATE_TCN_MSG_BIC_STATIC(AM_MAX_GROUP);
    CREATE_TCN_MSG_BIC_STATIC(AM_SAME_STATION);
    CREATE_TCN_MSG_BIC_STATIC(AM_UNKNOWN);
    CREATE_TCN_MSG_BIC_STATIC(AM_MANAGER_FCT);
    CREATE_TCN_MSG_BIC_STATIC(AM_AGENT_FCT);
    CREATE_TCN_MSG_BIC_STATIC(AM_ROUTER_FCT);
    CREATE_TCN_MSG_BIC_STATIC(AM_SAME_NODE);
    CREATE_TCN_MSG_BIC_STATIC(AM_SYSTEM_ADDR);
    CREATE_TCN_MSG_BIC_STATIC(AM_ANY_TOPO);
    CREATE_TCN_MSG_BIC_STATIC(AM_ADD_REM_ERR);
  }

  // - insert tcn message result codes constants -
  {
    const_locations.push_blanks(119);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 119);

#define CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_OK);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_FAILURE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_BUS_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_CONN_OVF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CONN_TMO_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_SEND_TMO_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REPLY_TMO_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ALIVE_TMO_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NO_LOC_MEM_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NO_REM_MEM_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_CANC_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ALREADY_USED);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ADDR_FMT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NO_REPLY_EXP_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NR_OF_CALLS_OVF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REPLY_LEN_OVF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_DUPL_LINK_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_MY_DEV_UNKNOWN_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NO_READY_INST_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NR_OF_INST_OVF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CALL_LEN_OVF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_UNKNOWN_DEST_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_INAUG_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_TRY_LATER_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_FIN_NOT_REG_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_GW_FIN_NOT_REG_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_GW_ORI_REG_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REPEAT_TMO_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ADDRESSING);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_MAX_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_DUPL_START_MSNGR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_SEND_POOL_FULL);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_RECEIVE_POOL_FULL);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_INIT_POOL_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CREATE_THREAD_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_TRY_LATER_ALIVE_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_AMI_NOT_INIT);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_RECV_CNF_NOT_DEF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REPL_CNF_NOT_DEF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_ERRORS);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_NEXT_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_TOPO_CNT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_NOT_NODE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_ROUT_FCT_NSET);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_ST_AND_NEXT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_FC_AND_NEXT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_UNDEFINED_BUS);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_BAD_DEV_ADDR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_ST_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_FCT_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_UNKNOWN_MTC);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_BAD_PCK_SIZE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_DT_PCK_SIZE_OVR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_BAD_LAST_PCK_SZ);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_BAD_PACKET);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_BAD_PACK_STATE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_PACK_NO_STATE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_LOC_STOP_COMM);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_ERRORS);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_NEXT_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_TOPO_CNT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_NOT_NODE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_ROUT_FCT_NSET);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_ST_AND_NEXT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_FC_AND_NEXT_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_UNDEFINED_BUS);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_BAD_DEV_ADDR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_ST_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_FCT_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_UNKNOWN_MTC);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_BAD_PCK_SIZE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_DT_PCK_SIZE_OVR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_BAD_LAST_PCK_SZ);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_BAD_PACKET);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_BAD_PACK_STATE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_PACK_NO_STATE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_STOP_COMM);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NOT_MANAGER);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CANC_CALL_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REPL_INST_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ADD_FCT_TO_FUNDI_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_SAME_FCT_ALR_DEF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_FCT_NOT_BOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_STATION_ID_NOT_SET);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_INVALID_TOPO);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_BUF_NOT_FOUND);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REQ_IN_PROGRESS);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_MSNGR_NOT_RUN);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ZERO_IN_MSG_SIZE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_OUT_MSG_NULL);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_SESS_QUEUE_OVERFLOW);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_GROUP_NOT_IMPLEMENTED);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_AMI_AMA_FAILED);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CALL_CNF_NULL);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_INVALID_STATION_ID);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_RETURN_PATH_BAD);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_BAD_NET_HEADER);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_INVALID_EVENT);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_INVALID_STATE);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NO_REPLY_REQ_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_RESULT_BUFF_TOO_SMALL);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_NOT_SUPPORTED);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_CANCEL_WRONG_REF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_REQ_NO_FREE_REF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_CONF_WRONG_REF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_CONN_NO_MEM);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_CONN_NO_FREE_REF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_RECV_WRONG_REF);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_DATA_TOO_BIG);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_INIT_MEM_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_REQ_NO_MEM);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_REQ_COMP_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_CM_REQ_DECOMP_ERR);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_BAD_REPLY);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ST_ID_DIFFERENT);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_STADI_DIFFERENT);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_REM_FUNDI_DIFFERENT);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_ST_RD_ONLY);
    CREATE_TCN_MSG_RESULT_CODE_BIC_STATIC(AM_BAD_CALL);
  }

}/*}}}*/

void bic_tcn_msg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_tcn_msg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_tcn_msg_method_RpcMain_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  RpcMain();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_tcn_msg_method_Main_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  tcn_msg_s::it_ptr = &it;
  tcn_msg_s::source_pos = operands[c_source_pos_idx];
  tcn_msg_s::ret_code = c_run_return_code_OK;

  RpcMain();
  as_msngr_run();
  msgMain();

  // - if exception occurred -
  if (tcn_msg_s::ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_tcn_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnMsg"),"TcnMsg")
  );

  return true;
}/*}}}*/

bool bic_tcn_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnMsg");

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
    exception_s::throw_exception(it,module.error_base + c_error_TCN_ADDRESS_INVALID_ADDRESS_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  UCTCNMD_CHECK_INTEGER_U8_RANGE(node_group,2);
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function_station,3);
  UCTCNMD_CHECK_INTEGER_U8_RANGE(next_station,4);

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
  unsigned am_address = (unsigned)dst_location->v_data_ptr;\
  AM_ADDRESS *am_ptr = (AM_ADDRESS *)&am_address;\
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
    "TcnCaller#2",
    c_modifier_public | c_modifier_final,
    bic_tcn_caller_method_TcnCaller_2
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

bool bic_tcn_caller_method_TcnCaller_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int function;

  if (!it.retrieve_integer(src_0_location,function) ||
      src_1_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TcnCaller#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - ERROR -
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function,1);

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCN_CALLER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  EMsgRes msg_res = msgRegCaller(function,&c_caller_params);
  if (msg_res != msg_ok)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_CALLER_REGISTER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);

    return false;
  }

  // - create tcn_caller object -
  tcn_caller_s *tc_ptr = (tcn_caller_s *)cmalloc(sizeof(tcn_caller_s));
  tc_ptr->init();

  tc_ptr->function = function;

  // - register callback delegate -
  src_1_location->v_reference_cnt.atomic_inc();
  tc_ptr->callback_dlg = src_1_location;

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
    exception_s::throw_exception(it,module.error_base + c_error_TCN_CALLER_CALL_REQUEST_INVALID_TIMEOUT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  tcn_caller_s *tc_ptr = (tcn_caller_s *)dst_location->v_data_ptr;
  SMsgAddress *ta_ptr = (SMsgAddress *)src_0_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create tcn_call_handler object -
  tcn_call_handler_s *th_ptr = (tcn_call_handler_s *)cmalloc(sizeof(tcn_call_handler_s));
  th_ptr->init();

  // - store reference to tcn caller -
  th_ptr->tcn_caller_loc = dst_location;

  // - store reference to message data -
  src_1_location->v_reference_cnt.atomic_inc();
  th_ptr->msg_req_loc = src_1_location;

  // - create tcn_call_handler location -
  BIC_CREATE_NEW_LOCATION(th_location,c_bi_class_tcn_call_handler,th_ptr);

  EMsgRes msg_res = msgCallRequestEx(tc_ptr->function,ta_ptr,
      string_ptr->data,string_ptr->size - 1,timeout,th_location,&th_ptr->th_ptr);

  // - ERROR -
  if (msg_res != msg_ok)
  {
    it.release_location_ptr(th_location);

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_CALLER_CALL_REQUEST_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);

    return false;
  }

  // - store handler to tcn caller -
  th_location->v_reference_cnt.atomic_inc();
  th_ptr->th_idx = tc_ptr->handler_list.append(th_location);

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
  5, tcn_replier_methods,
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
    "TcnReplier#3",
    c_modifier_public | c_modifier_final,
    bic_tcn_replier_method_TcnReplier_3
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

bool bic_tcn_replier_method_TcnReplier_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int function;
  long long int instance_cnt;

  if (!it.retrieve_integer(src_0_location,function) ||
      !it.retrieve_integer(src_1_location,instance_cnt) ||
      src_2_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TcnReplier#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function,1);

  // - ERROR -
  if (instance_cnt < 1 || instance_cnt > 255)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_REQUEST_INVALID_INSTANCE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  AM_RESULT am_res = AM_OK;
  EMsgRes msg_res = msgRegReplierEx(function,instance_cnt,&c_replier_params,&am_res);

  // - ERROR -
  if (msg_res != msg_ok || am_res != AM_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_REGISTER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);
    new_exception->params.push(am_res);

    return false;
  }

  // - store replier location -
  tcn_msg_s::replier_locs[function] = dst_location;

  // - create tcn_replier object -
  tcn_replier_s *tr_ptr = (tcn_replier_s *)cmalloc(sizeof(tcn_replier_s));
  tr_ptr->init();

  tr_ptr->function = function;

  // - register callback delegate -
  src_2_location->v_reference_cnt.atomic_inc();
  tr_ptr->callback_dlg = src_2_location;

  // - set tcn_replier destination location -
  dst_location->v_data_ptr = (tcn_replier_s *)tr_ptr;

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

  if (!it.retrieve_integer(src_0_location,function) ||
      !it.retrieve_integer(src_1_location,instance_cnt) ||
      src_2_location->v_type != c_bi_class_delegate ||
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
  UCTCNMD_CHECK_INTEGER_U8_RANGE(function,1);

  // - ERROR -
  if (instance_cnt < 1 || instance_cnt > 255)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_REQUEST_INVALID_INSTANCE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve callback delegate pointer -
  delegate_s *callback_dlg_ptr = (delegate_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (callback_dlg_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve close delegate pointer -
  delegate_s *close_dlg_ptr = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (close_dlg_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_WRONG_CLOSE_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  AM_RESULT am_res = AM_OK;
  EMsgRes msg_res = msgRegReplierEx(function,instance_cnt,&c_replier_params,&am_res);

  // - ERROR -
  if (msg_res != msg_ok || am_res != AM_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_REPLIER_REGISTER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);
    new_exception->params.push(am_res);

    return false;
  }

  // - store replier location -
  tcn_msg_s::replier_locs[function] = dst_location;

  // - create tcn_replier object -
  tcn_replier_s *tr_ptr = (tcn_replier_s *)cmalloc(sizeof(tcn_replier_s));
  tr_ptr->init();

  tr_ptr->function = function;

  // - register callback delegate -
  src_2_location->v_reference_cnt.atomic_inc();
  tr_ptr->callback_dlg = src_2_location;

  // - register close delegate -
  src_3_location->v_reference_cnt.atomic_inc();
  tr_ptr->close_dlg = src_3_location;

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

// - class TCN_CALL_HANDLER -
built_in_class_s tcn_call_handler_class =
{/*{{{*/
  "TcnCallHandler",
  c_modifier_public | c_modifier_final,
  8, tcn_call_handler_methods,
  0, tcn_call_handler_variables,
  bic_tcn_call_handler_consts,
  bic_tcn_call_handler_init,
  bic_tcn_call_handler_clear,
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

built_in_method_s tcn_call_handler_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_call_handler_operator_binary_equal
  },
  {
    "Cancel#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_call_handler_method_Cancel_0
  },
  {
    "served#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_call_handler_method_served_0
  },
  {
    "am_address#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_call_handler_method_am_address_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_call_handler_method_data_0
  },
  {
    "status#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_call_handler_method_status_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_call_handler_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_call_handler_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_call_handler_variables[] =
{/*{{{*/
};/*}}}*/

void bic_tcn_call_handler_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcn_call_handler_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcn_call_handler_s *)nullptr;
}/*}}}*/

void bic_tcn_call_handler_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcn_call_handler_s *th_ptr = (tcn_call_handler_s *)location_ptr->v_data_ptr;

  if (th_ptr != nullptr)
  {
    th_ptr->clear(it);
    cfree(th_ptr);
  }
}/*}}}*/

bool bic_tcn_call_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_Cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcn_call_handler_s *th_ptr = (tcn_call_handler_s *)dst_location->v_data_ptr;

  // - ERROR -
  EMsgRes msg_res = msgCancSession(th_ptr->th_ptr);
  if (msg_res != msg_ok)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_CALL_HANDLER_CANCEL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);

    return false;
  }
  else
  {
    // - remove handler from caller list -
    tcn_caller_s *tc_ptr = (tcn_caller_s *)th_ptr->tcn_caller_loc->v_data_ptr;
    tc_ptr->handler_list.remove(th_ptr->th_idx);

    // - callback will not be called for cancelled session -
    it.release_location_ptr(dst_location);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_served_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((tcn_call_handler_s *)dst_location->v_data_ptr)->served;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_am_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  unsigned result = ((tcn_call_handler_s *)dst_location->v_data_ptr)->am_address;

  BIC_SIMPLE_SET_RES(c_bi_class_tcn_am_address,result);

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *msg_resp_loc = ((tcn_call_handler_s *)dst_location->v_data_ptr)->msg_resp_loc;

  if (msg_resp_loc != nullptr)
  {
    msg_resp_loc->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(msg_resp_loc);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((tcn_call_handler_s *)dst_location->v_data_ptr)->status;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnCallHandler"),"TcnCallHandler")
  );

  return true;
}/*}}}*/

bool bic_tcn_call_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnCallHandler");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_REPL_HANDLER -
built_in_class_s tcn_repl_handler_class =
{/*{{{*/
  "TcnReplHandler",
  c_modifier_public | c_modifier_final,
  9, tcn_repl_handler_methods,
  0, tcn_repl_handler_variables,
  bic_tcn_repl_handler_consts,
  bic_tcn_repl_handler_init,
  bic_tcn_repl_handler_clear,
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

built_in_method_s tcn_repl_handler_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_repl_handler_operator_binary_equal
  },
  {
    "ReplyRequest#2",
    c_modifier_public | c_modifier_final ,
    bic_tcn_repl_handler_method_ReplyRequest_2
  },
  {
    "Cancel#0",
    c_modifier_public | c_modifier_final ,
    bic_tcn_repl_handler_method_Cancel_0
  },
  {
    "am_address#0",
    c_modifier_public | c_modifier_final ,
    bic_tcn_repl_handler_method_am_address_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_repl_handler_method_data_0
  },
  {
    "closed#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_repl_handler_method_closed_0
  },
  {
    "status#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_repl_handler_method_status_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_repl_handler_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_repl_handler_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_repl_handler_variables[] =
{/*{{{*/
};/*}}}*/

void bic_tcn_repl_handler_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_tcn_repl_handler_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (tcn_repl_handler_s *)nullptr;
}/*}}}*/

void bic_tcn_repl_handler_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  tcn_repl_handler_s *th_ptr = (tcn_repl_handler_s *)location_ptr->v_data_ptr;

  if (th_ptr != nullptr)
  {
    th_ptr->clear(it);
    cfree(th_ptr);
  }
}/*}}}*/

bool bic_tcn_repl_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_ReplyRequest_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int status;

  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,status))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ReplyRequest#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  tcn_repl_handler_s *th_ptr = (tcn_repl_handler_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  EMsgRes msg_res = msgReplyRequest(string_ptr->data,string_ptr->size - 1,(AM_RESULT)status,dst_location,th_ptr->th_ptr);
  if (msg_res != msg_ok)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_REPL_HANDLER_REPLY_REQUEST_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_Cancel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  tcn_repl_handler_s *th_ptr = (tcn_repl_handler_s *)dst_location->v_data_ptr;

  // - ERROR -
  EMsgRes msg_res = msgCancSession(th_ptr->th_ptr);
  if (msg_res != msg_ok)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TCN_REPL_HANDLER_CANCEL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(msg_res);

    return false;
  }
  else
  {
    // - remove handler from replier list -
    tcn_replier_s *tr_ptr = (tcn_replier_s *)th_ptr->tcn_replier_loc->v_data_ptr;
    tr_ptr->handler_list.remove(th_ptr->th_idx);

    // - callback will not be called for cancelled session -
    it.release_location_ptr(dst_location);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_am_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  unsigned result = ((tcn_repl_handler_s *)dst_location->v_data_ptr)->am_address;

  BIC_SIMPLE_SET_RES(c_bi_class_tcn_am_address,result);

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *msg_req_loc = ((tcn_repl_handler_s *)dst_location->v_data_ptr)->msg_req_loc;

  if (msg_req_loc != nullptr)
  {
    msg_req_loc->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(msg_req_loc);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_closed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((tcn_repl_handler_s *)dst_location->v_data_ptr)->closed;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((tcn_repl_handler_s *)dst_location->v_data_ptr)->status;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnReplHandler"),"TcnReplHandler")
  );

  return true;
}/*}}}*/

bool bic_tcn_repl_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TcnReplHandler");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

