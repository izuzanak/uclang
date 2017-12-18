
#ifndef __UCL_UCTCNMD_H
#define __UCL_UCTCNMD_H

@begin
include "script_parser.h"
@end

#include "ucf.h"
using namespace Ucf;

#include "uctcn.h"
using namespace Tcn;

/*
 * contants and definitions
 */

extern unsigned c_bi_class_tcn_am_address;

/*
 * definition of structure tcn_message_s
 */

struct tcn_message_s
{
  static interpreter_thread_s *it_ptr;
  static unsigned source_pos;
  static unsigned ret_code;

  static void caller_block_callback(const AM_ADDRESS *psReplier,void *pReplyMsg,U32 u32ReplyMsgLen,AM_RESULT eStatus,void *pCallerRef);
  static void caller_unblock_callback(const AM_ADDRESS *psReplier,void *pReplyMsg,U32 u32ReplyMsgLen,AM_RESULT eStatus,void *pCallerRef,void *pHandlerRef);

  static void replier_block_callback(AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void **ppReplyMsgAdr,U32 *pu32ReplyMsgSize,AM_RESULT *peStatus,void **ppReplierRef);
  static void replier_unblock_callback(AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void *pHandlerRef);
  static void replier_block_function_callback(U8 u8ReplierFct,AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void **ppReplyMsgAdr,U32 *pu32ReplyMsgSize,AM_RESULT *peStatus,void **ppReplierRef);
  static void replier_unblock_function_callback(U8 u8ReplierFct,AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void *pHandlerRef);

  static void replier_close_callback(void *pReplierRef,AM_RESULT eStatus);
};

// - caller static parameters -
const SMsgCallerPars c_caller_params[] =
{
  {msg_block_service  ,{ .pfCallerReply   = tcn_message_s::caller_block_callback }},
  {msg_unblock_service,{ .pfCallerReplyEx = tcn_message_s::caller_unblock_callback }},
};

// - replier static parameters -
const SMsgReplierParsEx c_replier_params[] =
{
  {
    msg_block_service,
    { .pfReplierCall = tcn_message_s::replier_block_callback },
    tcn_message_s::replier_close_callback
  },
  {
    msg_unblock_service,
    { .pfReplierCallEx = tcn_message_s::replier_unblock_callback },
    tcn_message_s::replier_close_callback
  },
  {
    msg_block_rpl_fct,
    { .pfCallRcv = tcn_message_s::replier_block_function_callback },
    tcn_message_s::replier_close_callback
  },
  {
    msg_unblock_rpl_fct,
    { .pfCallRcvEx = tcn_message_s::replier_unblock_function_callback },
    tcn_message_s::replier_close_callback
  },
};

/*
 * definition of structure tcn_caller_s
 */

struct tcn_caller_s
{
  U8 function;
  const SMsgCallerPars *params;
  location_s *callback_dlg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure tcn_replier_s
 */

struct tcn_replier_s
{
  U8 function;
  const SMsgReplierParsEx *params;
  location_s *callback_dlg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure tcn_handler_s
 */

struct tcn_handler_s
{
  void *th_ptr;
  location_s *tcn_caller_loc;
  location_s *msg_data_loc;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class uctcnmd_c
 */

class uctcnmd_c
{
  public:
  inline uctcnmd_c();
  inline ~uctcnmd_c();
};

// - uctcnmd global init object -
extern uctcnmd_c g_uctcnmd;

/*
 * inline methods of structure tcn_caller_s
 */

inline void tcn_caller_s::init()
{/*{{{*/
  callback_dlg = nullptr;
}/*}}}*/

inline void tcn_caller_s::clear(interpreter_thread_s &it)
{/*{{{*/
  cassert(msgUnregCaller(function) == msg_ok);

  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure tcn_replier_s
 */

inline void tcn_replier_s::init()
{/*{{{*/
  callback_dlg = nullptr;
}/*}}}*/

inline void tcn_replier_s::clear(interpreter_thread_s &it)
{/*{{{*/
  cassert(msgUnregReplier(function) == msg_ok);

  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure tcn_handler_s
 */

inline void tcn_handler_s::init()
{/*{{{*/
  tcn_caller_loc = nullptr;
  msg_data_loc = nullptr;
}/*}}}*/

inline void tcn_handler_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (tcn_caller_loc != nullptr)
  {
    it.release_location_ptr(tcn_caller_loc);
  }

  if (msg_data_loc != nullptr)
  {
    it.release_location_ptr(msg_data_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of class uctcnmd_c
 */

inline uctcnmd_c::uctcnmd_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"uctcnmd_init()\n"););

  // FIXME TODO continue ...

  //cassert(am_init() == AM_OK);
  cassert(msgInit() == msg_ok);
}/*}}}*/

inline uctcnmd_c::~uctcnmd_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"uctcnmd_exit()\n"););

  cassert(msgDestroy() == msg_ok);
}/*}}}*/

#endif

