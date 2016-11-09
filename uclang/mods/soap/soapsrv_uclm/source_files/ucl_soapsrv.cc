
@begin
include "ucl_soapsrv.h"
@end

/*
 * methods of structure soap_env_s
 */

#define GSOAP_CALL_CALLBACK_DELEGATE(NAME,PARAM_DATA,PARAM_CNT,RETURN_CLASS,PARAM_CODE,ERROR_CODE,RETURN_CODE) \
{/*{{{*/\
  soap_env_s *se_ptr = (soap_env_s *)soap->user;\
\
  if (se_ptr->proc_ret_code == c_run_return_code_OK &&\
      se_ptr->NAME ## _dlg != NULL)\
  {\
    interpreter_thread_s &it = *se_ptr->it_ptr;\
    delegate_s *delegate_ptr = (delegate_s *)se_ptr->NAME ## _dlg->v_data_ptr;\
\
    PARAM_CODE;\
\
    /* - call delegate method - */\
    location_s *trg_location = NULL;\
    BIC_CALL_DELEGATE(it,delegate_ptr,PARAM_DATA,PARAM_CNT,trg_location,se_ptr->proc_source_pos,\
      se_ptr->proc_ret_code = c_run_return_code_EXCEPTION;\
\
      ERROR_CODE;\
\
      return SOAP_OK;\
    );\
\
    /* - if return value type is soap fault - */\
    if (trg_location->v_type == c_bi_class_soap_fault)\
    {\
      soap_fault_s *sf_ptr = (soap_fault_s *)trg_location->v_data_ptr;\
      string_s *string_ptr = (string_s *)sf_ptr->string_ptr->v_data_ptr;\
      string_s *detail_ptr = (string_s *)sf_ptr->detail_ptr->v_data_ptr;\
\
      int ret_val = soap_sender_fault(se_ptr->soap_ptr,string_ptr->data,detail_ptr->data);\
\
      it.release_location_ptr(trg_location);\
      return ret_val;\
    }\
\
    /* - ERROR - */\
    if (trg_location->v_type != RETURN_CLASS)\
    {\
      exception_s::throw_exception(it,c_error_DELEGATE_WRONG_RETURN_VALUE_TYPE,se_ptr->proc_source_pos,(location_s *)it.blank_location);\
\
      se_ptr->proc_ret_code = c_run_return_code_EXCEPTION;\
\
      ERROR_CODE;\
\
      return SOAP_OK;\
    }\
\
    RETURN_CODE;\
\
    it.release_location_ptr(trg_location);\
  }\
\
  return SOAP_OK;\
}/*}}}*/

int ns__add(struct soap *soap,double a,double b,double *result)
{/*{{{*/
  GSOAP_CALL_CALLBACK_DELEGATE(ns__add,param_data,param_cnt,c_bi_class_float,

    BIC_CREATE_NEW_LOCATION_REFS(a_loc,c_bi_class_float,a,0);
    BIC_CREATE_NEW_LOCATION_REFS(b_loc,c_bi_class_float,b,0);

    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {a_loc MP_COMMA b_loc};
    ,
    *result = 0.0;
    ,
    *result = (double)trg_location->v_data_ptr;
  );
}/*}}}*/

int ns__sub(struct soap *soap,double a,double b,double *result)
{/*{{{*/
  GSOAP_CALL_CALLBACK_DELEGATE(ns__sub,param_data,param_cnt,c_bi_class_float,

    BIC_CREATE_NEW_LOCATION_REFS(a_loc,c_bi_class_float,a,0);
    BIC_CREATE_NEW_LOCATION_REFS(b_loc,c_bi_class_float,b,0);

    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {a_loc MP_COMMA b_loc};
    ,
    *result = 0.0;
    ,
    *result = (double)trg_location->v_data_ptr;
  );
}/*}}}*/

int ns__sqrt(struct soap *soap,double a,double *result)
{/*{{{*/
  GSOAP_CALL_CALLBACK_DELEGATE(ns__sqrt,param_data,param_cnt,c_bi_class_float,

    BIC_CREATE_NEW_LOCATION_REFS(a_loc,c_bi_class_float,a,0);

    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&a_loc;
    ,
    *result = 0.0;
    ,
    *result = (double)trg_location->v_data_ptr;
  );
}/*}}}*/

