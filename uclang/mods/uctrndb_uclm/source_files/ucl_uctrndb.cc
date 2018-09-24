
@begin
include "ucl_uctrndb.h"
@end

/*
 * static members of structure trndb_proxy_s
 */

trndb_proxy_s *trndb_proxy_s::g_proxy_ptr = nullptr;

/*
 * methods of structure trndb_proxy_s
 */

void trndb_proxy_s::trndb_changed(int events)
{
  trndb_proxy_s *tdp_ptr = trndb_proxy_s::g_proxy_ptr;

  // - if global proxy pointer and its delegate are set -
  if (tdp_ptr != nullptr && tdp_ptr->callback_dlg != nullptr)
  {
    interpreter_thread_s &it = *tdp_ptr->it_ptr;
    delegate_s *delegate_ptr = (delegate_s *)tdp_ptr->callback_dlg->v_data_ptr;

    BIC_CREATE_NEW_LOCATION_REFS(events_location,c_bi_class_integer,(long long int)events,0);

    // - callback parameters -
    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&events_location;

    // - call delegate method -
    location_s *trg_location = nullptr;
    BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,tdp_ptr->source_pos,

      tdp_ptr->ret_code = c_run_return_code_EXCEPTION;
      return;
    );
    it.release_location_ptr(trg_location);
  }
}

