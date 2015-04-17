
#ifndef __NACL_H
#define __NACL_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE_UNIX_CHROME_NACL == ENABLED

// - global nacl related variables -
extern PP_Instance pp_inst;
extern PPB_GetInterface ppb_get_iface;

// - nacl interpreter thread pointer -
extern interpreter_thread_s *nacl_it_ptr;

// - nacl instance callback delegates -
extern location_s *nacl_destroy_dlg;
extern location_s *nacl_change_view_dlg;
extern location_s *nacl_change_focus_dlg;

#define NACL_CALL_CALLBACK_DELEGATE(NAME,PARAM_DATA,PARAM_CNT,PARAM_CODE) \
{/*{{{*/\
  if (nacl_it_ptr != NULL &&\
      NAME != NULL)\
  {\
    interpreter_thread_s &it = *nacl_it_ptr;\
    delegate_s *delegate_ptr = (delegate_s *)(NAME)->v_data_ptr;\
    unsigned source_pos = 0;\
\
    PARAM_CODE;\
\
    /* - call delegate method - */\
    location_s *trg_location = NULL;\
    BIC_CALL_DELEGATE(it,delegate_ptr,PARAM_DATA,PARAM_CNT,trg_location,source_pos,\
\
      /* - print exception message - */\
      exception_s *exception_ptr = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;\
      ((interpreter_s *)it.interpreter_ptr)->print_exception_message(*exception_ptr);\
\
      cassert(0);\
      return;\
    );\
    it.release_location_ptr(trg_location);\
  }\
}/*}}}*/

#endif

#endif

