
#ifndef __UCL_HTTP_H
#define __UCL_HTTP_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <poll.h>
#include <fcntl.h>
#include <netdb.h>
#if SYSTEM_TYPE_UNIX_SOCKET == ENABLED
#define ENABLE_RM_CLASS_SOCKET
#endif
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#endif

#include <microhttpd.h>

#if MHD_VERSION >= 0x00097002
#define MHD_RESULT enum MHD_Result
#else
#define MHD_RESULT int
#endif

/*
 * contants and definitions
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
  pointer_list_s suspended_conns;

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
  unsigned suspend_idx;

  const char *url;
  const char *method;
  const char *version;
  const char *upload_data;
  size_t *upload_data_size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure http_post_proc_s
 */

struct http_post_proc_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  MHD_PostProcessor *post_proc;
  location_s *user_data_ptr;
  location_s *callback_dlg;

  const char *key;
  const char *data;
  uint64_t offset;
  size_t size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of global functions
 */

MHD_RESULT connection_func(void *cls,struct MHD_Connection *connection,
    const char *url,const char *method,const char *version,
    const char *upload_data,size_t *upload_data_size,void **con_cls);

MHD_RESULT conn_key_value_func (void *cls,enum MHD_ValueKind kind,
    const char *key,const char *value);

void completed_func(void *cls,struct MHD_Connection *connection,
    void **con_cls,enum MHD_RequestTerminationCode toe);

MHD_RESULT post_proc_func(void *coninfo_cls,enum MHD_ValueKind kind,
    const char *key,const char *filename,const char *content_type,
    const char *transfer_encoding,const char *data,uint64_t off,size_t size);

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
  suspended_conns.init();
}/*}}}*/

inline void http_server_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - resume suspended connections -
  if (suspended_conns.count != 0)
  {
    unsigned sc_idx = suspended_conns.first_idx;
    do {

      // - retrieve suspended connection -
      http_conn_s *conn_ptr = (http_conn_s *)((location_s *)suspended_conns[sc_idx])->v_data_ptr;

      // - resume suspended connection -
      MHD_resume_connection(conn_ptr->connection_ptr);
      conn_ptr->suspend_idx = c_idx_not_exist;

      sc_idx = suspended_conns.next_idx(sc_idx);
    } while(sc_idx != c_idx_not_exist);
  }

  suspended_conns.clear();

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
  suspend_idx = c_idx_not_exist;

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

/*
 * inline methods of structure http_post_proc_s
 */

inline void http_post_proc_s::init()
{/*{{{*/
  it_ptr = nullptr;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  post_proc = nullptr;
  user_data_ptr = nullptr;
  callback_dlg = nullptr;
}/*}}}*/

inline void http_post_proc_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (post_proc != nullptr)
  {
    MHD_destroy_post_processor(post_proc);
  }

  // - release user data location -
  if (user_data_ptr != nullptr)
  {
    it.release_location_ptr(user_data_ptr);
  }

  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  init();
}/*}}}*/

#endif

