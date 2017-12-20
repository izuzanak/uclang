
@begin
include "ucl_uctcnmd.h"
@end

// - message result strings -
const char *c_msg_res_strings[] =
{/*{{{*/
  "msg_ok",
  "msg_failure",
  "msg_not_registered",
  "msg_dupl_registration",
  "msg_sess_not_found",
  "msg_no_free_inst",
  "msg_queue_is_empty",
  "msg_queue_is_full",
  "msg_try_later",
  "msg_already_init",
  "msg_not_init",
  "msg_ami_err",
};/*}}}*/

// - uctcnmd global init object -
uctcnmd_c g_uctcnmd;

// - static members of structure tcn_message_s -

interpreter_thread_s *tcn_message_s::it_ptr = nullptr;
unsigned tcn_message_s::source_pos;
unsigned tcn_message_s::ret_code;

pointer tcn_message_s::replier_locs[256];

/*
 * methods of structure tcn_message_s
 */

void tcn_message_s::caller_block_callback(const AM_ADDRESS *psReplier,void *pReplyMsg,U32 u32ReplyMsgLen,AM_RESULT eStatus,void *pCallerRef)
{/*{{{*/
  location_s *th_location = (location_s *)pCallerRef;
  tcn_call_handler_s *th_ptr = (tcn_call_handler_s *)th_location->v_data_ptr;
  tcn_caller_s *tc_ptr = (tcn_caller_s *)th_ptr->tcn_caller_loc->v_data_ptr;

  interpreter_thread_s &it = *tcn_message_s::it_ptr;
  delegate_s *delegate_ptr = (delegate_s *)tc_ptr->callback_dlg->v_data_ptr;

  // - fill call handler with response values -
  th_ptr->served = true;
  th_ptr->am_address = *((unsigned *)psReplier);

  if (pReplyMsg != nullptr)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(u32ReplyMsgLen,(const char *)pReplyMsg);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,1);
    th_ptr->msg_resp_loc = new_location;
  }

  th_ptr->status = eStatus;

  // - callback parameters -

  // - tcn handler location: will be increased and possibly released by delegate call -
  th_location->v_reference_cnt.atomic_dec(); 

  const unsigned param_cnt = 1;
  pointer *param_data = (pointer *)&th_location;

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,tcn_message_s::source_pos,
    tcn_message_s::ret_code = c_run_return_code_EXCEPTION;
    return;
  );
  it.release_location_ptr(trg_location);

  return;
}/*}}}*/

void tcn_message_s::replier_unblock_function_callback(U8 u8ReplierFct,AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void *pHandlerRef)
{/*{{{*/
  interpreter_thread_s &it = *tcn_message_s::it_ptr;

  location_s *tr_location = (location_s *)tcn_message_s::replier_locs[u8ReplierFct];
  tcn_replier_s *tr_ptr = (tcn_replier_s *)tr_location->v_data_ptr;
  delegate_s *delegate_ptr = (delegate_s *)tr_ptr->callback_dlg->v_data_ptr;

  // - create tcn_repl_handler object -
  tcn_repl_handler_s *th_ptr = (tcn_repl_handler_s *)cmalloc(sizeof(tcn_repl_handler_s));
  th_ptr->init();

  // - fill repl handler with request values -
  th_ptr->th_ptr = pHandlerRef;

  // - store reference to tcn replier -
  tr_location->v_reference_cnt.atomic_inc();
  th_ptr->tcn_replier_loc = tr_location;

  th_ptr->am_address = *((unsigned *)psCallerAddr);

  if (pCallMsgAdr != nullptr)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(u32CallMsgSize,(const char *)pCallMsgAdr);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,1);
    th_ptr->msg_req_loc = new_location;
  }

  // - callback parameters -

  // - tcn handler location: will be increased and possibly released by delegate call -
  BIC_CREATE_NEW_LOCATION_REFS(th_location,c_bi_class_tcn_repl_handler,th_ptr,0);

  const unsigned param_cnt = 1;
  pointer *param_data = (pointer *)&th_location;

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,tcn_message_s::source_pos,
    tcn_message_s::ret_code = c_run_return_code_EXCEPTION;
    return;
  );
  it.release_location_ptr(trg_location);

  return;
}/*}}}*/

void tcn_message_s::replier_close_callback(void *pReplierRef,AM_RESULT eStatus)
{/*{{{*/
  location_s *th_location = (location_s *)pReplierRef;
  tcn_repl_handler_s *th_ptr = (tcn_repl_handler_s *)th_location->v_data_ptr;
  tcn_replier_s *tr_ptr = (tcn_replier_s *)th_ptr->tcn_replier_loc->v_data_ptr;

  interpreter_thread_s &it = *tcn_message_s::it_ptr;

  if (tr_ptr->close_dlg != nullptr)
  {
    delegate_s *delegate_ptr = (delegate_s *)tr_ptr->close_dlg->v_data_ptr;

    // - fill call handler with response values -
    th_ptr->closed = true;
    th_ptr->status = eStatus;

    // - callback parameters -

    // - tcn handler location: will be increased and possibly released by delegate call -
    th_location->v_reference_cnt.atomic_dec(); 

    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&th_location;

    // - call delegate method -
    location_s *trg_location = nullptr;
    BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,tcn_message_s::source_pos,
      tcn_message_s::ret_code = c_run_return_code_EXCEPTION;
      return;
    );
    it.release_location_ptr(trg_location);
  }
  else
  {
    // - release tcn handler location -
    it.release_location_ptr(th_location);
  }

  return;
}/*}}}*/

