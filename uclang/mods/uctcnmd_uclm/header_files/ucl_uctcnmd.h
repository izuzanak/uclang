
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

extern unsigned c_bi_class_tcn_repl_handler;

// - message result strings -
extern const char *c_msg_res_strings[];

/*
 * definition of structure tcn_msg_s
 */

struct tcn_msg_s
{
  static interpreter_thread_s *it_ptr;
  static unsigned source_pos;
  static unsigned ret_code;

  static pointer replier_locs[256];

  static void caller_block_callback(const AM_ADDRESS *psReplier,void *pReplyMsg,U32 u32ReplyMsgLen,AM_RESULT eStatus,void *pCallerRef);
  static void replier_unblock_function_callback(U8 u8ReplierFct,AM_ADDRESS *psCallerAddr,void *pCallMsgAdr,U32 u32CallMsgSize,void *pHandlerRef);

  static void replier_close_callback(void *pReplierRef,AM_RESULT eStatus);
};

// - caller static parameters -
const SMsgCallerPars c_caller_params =
{
  msg_block_service,
  { .pfCallerReply = tcn_msg_s::caller_block_callback }
};

// - replier static parameters -
const SMsgReplierParsEx c_replier_params =
{
  msg_unblock_rpl_fct,
  { .pfCallRcvEx = tcn_msg_s::replier_unblock_function_callback },
  tcn_msg_s::replier_close_callback
};

/*
 * definition of structure tcn_caller_s
 */

struct tcn_caller_s
{
  U8 function;
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
  location_s *callback_dlg;
  location_s *close_dlg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure tcn_call_handler_s
 */

struct tcn_call_handler_s
{
  void *th_ptr;
  location_s *tcn_caller_loc;
  location_s *msg_req_loc;

  bool served;
  unsigned am_address;
  location_s *msg_resp_loc;
  AM_RESULT status;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure tcn_repl_handler_s
 */

struct tcn_repl_handler_s
{
  void *th_ptr;
  location_s *tcn_replier_loc;
  unsigned am_address;
  location_s *msg_req_loc;

  bool replied;
  location_s *msg_resp_loc;

  bool closed;
  AM_RESULT status;

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
  close_dlg = nullptr;
}/*}}}*/

inline void tcn_replier_s::clear(interpreter_thread_s &it)
{/*{{{*/
  cassert(msgUnregReplier(function) == msg_ok);

  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  if (close_dlg != nullptr)
  {
    it.release_location_ptr(close_dlg);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure tcn_call_handler_s
 */

inline void tcn_call_handler_s::init()
{/*{{{*/
  tcn_caller_loc = nullptr;
  msg_req_loc = nullptr;

  served = false;
  am_address = 0;
  msg_resp_loc = nullptr;
  status = AM_OK;
}/*}}}*/

inline void tcn_call_handler_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (tcn_caller_loc != nullptr)
  {
    it.release_location_ptr(tcn_caller_loc);
  }

  if (msg_req_loc != nullptr)
  {
    it.release_location_ptr(msg_req_loc);
  }

  if (msg_resp_loc != nullptr)
  {
    it.release_location_ptr(msg_resp_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure tcn_repl_handler_s
 */

inline void tcn_repl_handler_s::init()
{/*{{{*/
  tcn_replier_loc = nullptr;
  msg_req_loc = nullptr;

  replied = false;
  msg_resp_loc = nullptr;

  closed = false;
  status = AM_OK;
}/*}}}*/

inline void tcn_repl_handler_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (tcn_replier_loc != nullptr)
  {
    it.release_location_ptr(tcn_replier_loc);
  }

  if (msg_req_loc != nullptr)
  {
    it.release_location_ptr(msg_req_loc);
  }

  if (msg_resp_loc != nullptr)
  {
    it.release_location_ptr(msg_resp_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of class uctcnmd_c
 */

inline uctcnmd_c::uctcnmd_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"uctcnmd_init()\n"););

  cassert(am_init() == AM_OK);
  cassert(msgInit() == msg_ok);
}/*}}}*/

inline uctcnmd_c::~uctcnmd_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"uctcnmd_exit()\n"););

  msgDestroy();
}/*}}}*/

#endif

