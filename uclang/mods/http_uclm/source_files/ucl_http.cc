
@begin
include "ucl_http.h"
@end

/*
 * global functions
 */

MHD_RESULT connection_func(void *cls,struct MHD_Connection *connection,
    const char *url,const char *method,const char *version,
    const char *upload_data,size_t *upload_data_size,void **con_cls)
{/*{{{*/
  location_s *srv_location = (location_s *)cls;
  http_server_s *srv_ptr = (http_server_s *)srv_location->v_data_ptr;

  interpreter_thread_s &it = *srv_ptr->it_ptr;
  delegate_s *delegate_ptr = (delegate_s *)srv_ptr->connection_dlg->v_data_ptr;

  // - connection pointer -
  http_conn_s *conn_ptr;

  if (*con_cls == nullptr)
  {
    // - create http_connection object -
    conn_ptr = (http_conn_s *)cmalloc(sizeof(http_conn_s));
    conn_ptr->init();

    // - set pointer to server -
    conn_ptr->srv_ptr = srv_ptr;

    // - retrieve connection type -
    unsigned conn_type;
    switch (strlen(method))
    {
    // - GET, PUT -
    case 3:
      conn_type = memcmp("GET",method,3) == 0 ?
        c_conn_type_GET : c_conn_type_PUT;
      break;

    // - HEAD, POST -
    case 4:
      conn_type = memcmp("HEAD",method,4) == 0 ?
        c_conn_type_HEAD : c_conn_type_POST;
      break;

    // - TRACE -
    case 5:
      conn_type = c_conn_type_TRACE;
      break;

    // - DELETE -
    case 6:
      conn_type = c_conn_type_DELETE;
      break;

    // - CONNECT, OPTIONS -
    case 7:
      conn_type = memcmp("CONNECT",method,7) == 0 ?
        c_conn_type_CONNECT : c_conn_type_OPTIONS;
      break;

    // - unrecognized connection type -
    default:
      conn_type = c_conn_type_NONE;
    }

    // - set connection properties -
    conn_ptr->conn_type = conn_type;
    conn_ptr->connection_ptr = connection;

    // - set user data pointer to blank location -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    conn_ptr->user_data_ptr = (location_s *)it.blank_location;

    conn_ptr->url = url;
    conn_ptr->method = method;
    conn_ptr->version = version;

    // - create connection location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_http_conn,conn_ptr);
    *con_cls = new_location;

    return MHD_YES;
  }

  // - retrieve connection object -
  location_s *conn_location = (location_s *)*con_cls;
  conn_ptr = (http_conn_s *)conn_location->v_data_ptr;

  // - update upload data variables -
  conn_ptr->upload_data = upload_data;
  conn_ptr->upload_data_size = upload_data_size;

  // - callback parameters -
  const unsigned param_cnt = 1;
  pointer *param_data = (pointer *)&conn_location;

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,srv_ptr->source_pos,

    // - reset upload data variables -
    conn_ptr->upload_data = nullptr;
    conn_ptr->upload_data_size = nullptr;

    srv_ptr->ret_code = c_run_return_code_EXCEPTION;
    return MHD_NO;
  );
  it.release_location_ptr(trg_location);

  // - reset upload data variables -
  conn_ptr->upload_data = nullptr;
  conn_ptr->upload_data_size = nullptr;

  return MHD_YES;
}/*}}}*/

MHD_RESULT conn_key_value_func(void *cls,enum MHD_ValueKind kind,
    const char *key,const char *value)
{/*{{{*/
  http_conn_s *conn_ptr = (http_conn_s *)cls;
  http_server_s *srv_ptr = conn_ptr->srv_ptr;

  interpreter_thread_s &it = *srv_ptr->it_ptr;

  // - pointer to key_value array -
  pointer_array_s *key_value_arr_ptr = conn_ptr->key_value_arr_ptr;

  {
    // - create key location -
    string_s *key_str_ptr = it.get_new_string_ptr();
    key_str_ptr->set(strlen(key),key);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,key_str_ptr);
    key_value_arr_ptr->push(new_location);
  }

  if (value == nullptr)
  {
    // - blank value location -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    key_value_arr_ptr->push(it.blank_location);
  }
  else
  {
    // - create value location -
    string_s *value_str_ptr = it.get_new_string_ptr();
    value_str_ptr->set(strlen(value),value);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,value_str_ptr);
    key_value_arr_ptr->push(new_location);
  }

  return MHD_YES;
}/*}}}*/

void completed_func(void *cls,struct MHD_Connection *connection,
    void **con_cls,enum MHD_RequestTerminationCode toe)
{/*{{{*/

  // - retrieve connection object -
  location_s *conn_location = (location_s *)*con_cls;

  // - if connection object exists -
  if (conn_location != nullptr)
  {
    http_conn_s *conn_ptr = (http_conn_s *)conn_location->v_data_ptr;
    conn_ptr->srv_ptr->it_ptr->release_location_ptr(conn_location);
  }
}/*}}}*/

MHD_RESULT post_proc_func(void *coninfo_cls,enum MHD_ValueKind kind,
    const char *key,const char *filename,const char *content_type,
    const char *transfer_encoding,const char *data,uint64_t off,size_t size)
{/*{{{*/
  location_s *pp_location = (location_s *)coninfo_cls;
  http_post_proc_s *pp_ptr = (http_post_proc_s *)pp_location->v_data_ptr;

  interpreter_thread_s &it = *pp_ptr->it_ptr;
  delegate_s *delegate_ptr = (delegate_s *)pp_ptr->callback_dlg->v_data_ptr;

  // - update post processor properties -
  pp_ptr->key = key;
  pp_ptr->data = data;
  pp_ptr->offset = off;
  pp_ptr->size = size;

  const unsigned param_cnt = 1;
  pointer *param_data = (pointer *)&pp_location;

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,pp_ptr->source_pos,
    pp_ptr->ret_code = c_run_return_code_EXCEPTION;
    return MHD_NO;
  );
  it.release_location_ptr(trg_location);

  return MHD_YES;
}/*}}}*/

