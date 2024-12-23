
#ifndef __UCL_PSQL_H
#define __UCL_PSQL_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <stdint.h>
#include <float.h>

#include <poll.h>
#include <postgresql/libpq-fe.h>

#define BOOLOID 16
#define INT8OID 20
#define INT2OID 21
#define INT4OID 23
#define TEXTOID 25
#define FLOAT4OID 700
#define FLOAT8OID 701
#define NUMERICOID 1700

/*
 * definition of structure psql_values_s
 */

struct psql_values_s
{
  ui_array_s oid_array;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure psql_result_s
 */

struct psql_result_s
{
  PGresult *res_ptr;
  location_s *conn_ptr;
  int tuple_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure psql_notify_s
 */

struct psql_notify_s
{
  PGnotify *ntf_ptr;
  location_s *conn_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure psql_values_s
 */

inline void psql_values_s::init()
{/*{{{*/
  oid_array.init();
}/*}}}*/

inline void psql_values_s::clear(interpreter_thread_s &it)
{/*{{{*/
  oid_array.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure psql_result_s
 */

inline void psql_result_s::init()
{/*{{{*/
  res_ptr = nullptr;
  conn_ptr = nullptr;
  tuple_idx = 0;
}/*}}}*/

inline void psql_result_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (res_ptr != nullptr)
  {
    PQclear(res_ptr);
  }

  if (conn_ptr != nullptr)
  {
    it.release_location_ptr(conn_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure psql_notify_s
 */

inline void psql_notify_s::init()
{/*{{{*/
  ntf_ptr = nullptr;
  conn_ptr = nullptr;
}/*}}}*/

inline void psql_notify_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (ntf_ptr != nullptr)
  {
    PQfreemem(ntf_ptr);
  }

  if (conn_ptr != nullptr)
  {
    it.release_location_ptr(conn_ptr);
  }

  init();
}/*}}}*/

#endif

