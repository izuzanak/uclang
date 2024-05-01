
#ifndef __UCL_PSQL_H
#define __UCL_PSQL_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <postgresql/libpq-fe.h>

#define BOOLOID 16

#define INT8OID 20
#define INT2OID 21
#define INT4OID 23

#define FLOAT4OID 700
#define FLOAT8OID 701

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

#endif

