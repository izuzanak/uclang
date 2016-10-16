
#ifndef __UCL_UTF8PROC_H
#define __UCL_UTF8PROC_H

@begin
include "script_parser.h"
@end

#include "utf8proc.h"

/*
 * definition of structure utf8proc_s
 */

struct utf8proc_s
{
  int dummy;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure utf8proc_s
 */

inline void utf8proc_s::init()
{/*{{{*/
}/*}}}*/

inline void utf8proc_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

