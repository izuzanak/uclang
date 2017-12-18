
@begin
include "ucl_uctcnmd.h"
@end

// - uctcnmd global init object -
uctcnmd_c g_uctcnmd;

// - static members of structure tcn_message_s -

interpreter_thread_s *tcn_message_s::it_ptr = nullptr;
unsigned tcn_message_s::source_pos;
unsigned tcn_message_s::ret_code;

/*
 * methods of structure tcn_message_s
 */

void tcn_message_s::caller_block_callback(const AM_ADDRESS *psReplier,void *pReplyMsg,U32 u32ReplyMsgLen,AM_RESULT eStatus,void *pCallerRef)
{/*{{{*/
  location_s *th_location = (location_s *)pCallerRef;
  tcn_handler_s *th_ptr = (tcn_handler_s *)th_location->v_data_ptr;
  tcn_caller_s *tc_ptr = (tcn_caller_s *)th_ptr->tcn_caller_loc->v_data_ptr;

  interpreter_thread_s &it = *tcn_message_s::it_ptr;
  delegate_s *delegate_ptr = (delegate_s *)tc_ptr->callback_dlg->v_data_ptr;

  // - callback parameters -

  // - tcn handler location: will be increased and possibly released by delegate call -
  th_location->v_reference_cnt.atomic_dec(); 

  lli am_address = *((unsigned *)psReplier);
  BIC_CREATE_NEW_LOCATION_REFS(address_loc,c_bi_class_tcn_am_address,am_address,0);

  location_s *message_loc;

  // - reply message is empty -
  if (pReplyMsg == nullptr)
  {
    message_loc = (location_s *)it.blank_location;
  }

  // - eply message is not empty -
  else
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(u32ReplyMsgLen,(const char *)pReplyMsg);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);
    message_loc = new_location;
  }

  BIC_CREATE_NEW_LOCATION_REFS(status_loc,c_bi_class_integer,eStatus,0);

  const unsigned param_cnt = 4;
  pointer param_data[param_cnt] = {
    th_location MP_COMMA address_loc MP_COMMA message_loc MP_COMMA status_loc};

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,tcn_message_s::source_pos,
    tcn_message_s::ret_code = c_run_return_code_EXCEPTION;
    return;
  );
  it.release_location_ptr(trg_location);

  return;
}/*}}}*/

void tcn_message_s::caller_unblock_callback(const AM_ADDRESS *psReplier,void *pReplyMsg,U32 u32ReplyMsgLen,AM_RESULT eStatus,void *pCallerRef,void *pHandlerRef)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"tcn_message_s::caller_unblock_callback\n");

  location_s *th_location = (location_s *)pCallerRef;
  interpreter_thread_s &it = *tcn_message_s::it_ptr;

  it.release_location_ptr(th_location);
  msgCallerClose(pHandlerRef);
}/*}}}*/

void tcn_message_s::replier_block_callback(AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void **ppReplyMsgAdr,U32 *pu32ReplyMsgSize,AM_RESULT *peStatus,void **ppReplierRef)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"tcn_message_s::replier_block_callback\n");
}/*}}}*/

void tcn_message_s::replier_unblock_callback(AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void *pHandlerRef)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"tcn_message_s::replier_unblock_callback\n");
}/*}}}*/

void tcn_message_s::replier_block_function_callback(U8 u8ReplierFct,AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void **ppReplyMsgAdr,U32 *pu32ReplyMsgSize,AM_RESULT *peStatus,void **ppReplierRef)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"tcn_message_s::replier_block_function_callback\n");
}/*}}}*/

void tcn_message_s::replier_unblock_function_callback(U8 u8ReplierFct,AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void *pHandlerRef)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"tcn_message_s::replier_unblock_function_callback\n");
}/*}}}*/

void tcn_message_s::replier_close_callback(void *pReplierRef,AM_RESULT eStatus)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"tcn_message_s::replier_close_callback\n");
}/*}}}*/

