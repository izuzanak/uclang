
#ifndef __UCL_SQLITE_H
#define __UCL_SQLITE_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <sqlite3.h>

/*
 * definition of structure sqlite_stmt_s
 */

struct sqlite_stmt_s
{
  sqlite3_stmt *stmt_ptr;
  location_s *db_ptr;
  bool done;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure sqlite_stmt_s
 */

inline void sqlite_stmt_s::init()
{/*{{{*/
  stmt_ptr = NULL;
  db_ptr = NULL;
  done = false;
}/*}}}*/

inline void sqlite_stmt_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (stmt_ptr != NULL)
  {
    sqlite3_finalize(stmt_ptr);
  }

  if (db_ptr != NULL)
  {
    it.release_location_ptr(db_ptr);
  }

  init();
}/*}}}*/

#endif

