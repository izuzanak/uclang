
#ifndef __UCL_HTTP_H
#define __UCL_HTTP_H

@begin
include "script_parser.h"
@end

#include <poll.h>
#include <fcntl.h>
#include <microhttpd.h>

/*
\* contants and definitions
 */

extern unsigned c_bi_class_http_conn;

// - connection types -
enum
{
  c_conn_type_NONE = 0,
  c_conn_type_CONNECT,
  c_conn_type_DELETE,
  c_conn_type_GET,
  c_conn_type_HEAD,
  c_conn_type_OPTIONS,
  c_conn_type_POST,
  c_conn_type_PUT,
  c_conn_type_TRACE,
};

// - response sources -
enum
{
  c_resp_from_string = 0,
  c_resp_from_file,
};

/*
 * definition of structure http_server_s
 */

struct http_server_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  MHD_Daemon *daemon_ptr;
  location_s *connection_dlg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure http_conn_s
 */

struct http_conn_s
{
  http_server_s *srv_ptr;

  unsigned conn_type;
  MHD_Connection *connection_ptr;
  pointer_array_s *key_value_arr_ptr;
  location_s *user_data_ptr;

  const char *url;
  const char *method;
  const char *version;
  const char *upload_data;
  size_t *upload_data_size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of global functions
 */

int connection_func(void *cls,struct MHD_Connection *connection,
    const char *url,const char *method,const char *version,
    const char *upload_data,size_t *upload_data_size,void **con_cls);

int conn_key_value_func (void *cls,enum MHD_ValueKind kind,
    const char *key,const char *value);

void completed_func(void *cls,struct MHD_Connection *connection,
    void **con_cls,enum MHD_RequestTerminationCode toe);

/*
 * inline methods of structure http_server_s
 */

inline void http_server_s::init()
{/*{{{*/
  it_ptr = nullptr;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  daemon_ptr = nullptr;
  connection_dlg = nullptr;
}/*}}}*/

inline void http_server_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (daemon_ptr != nullptr)
  {
    MHD_stop_daemon(daemon_ptr);
  }

  if (connection_dlg != nullptr)
  {
    it.release_location_ptr(connection_dlg);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure http_conn_s
 */

inline void http_conn_s::init()
{/*{{{*/
  srv_ptr = nullptr;

  conn_type = c_conn_type_NONE;
  connection_ptr = nullptr;
  key_value_arr_ptr = nullptr;
  user_data_ptr = nullptr;

  url = nullptr;
  method = nullptr;
  version = nullptr;
  upload_data = nullptr;
  upload_data_size = nullptr;
}/*}}}*/

inline void http_conn_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release user data location -
  if (user_data_ptr != nullptr)
  {
    it.release_location_ptr(user_data_ptr);
  }

  init();
}/*}}}*/

#endif

