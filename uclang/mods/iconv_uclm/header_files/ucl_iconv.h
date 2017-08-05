
#ifndef __UCL_ICONV_H
#define __UCL_ICONV_H

@begin
include "script_parser.h"
@end

#include "iconv.h"

/*
 * definition of structure iconv_s
 */

struct iconv_s
{
  iconv_t ic_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure iconv_s
 */

inline void iconv_s::init()
{/*{{{*/
  ic_ptr = nullptr;
}/*}}}*/

inline void iconv_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release iconv pointer -
  if (ic_ptr != nullptr)
  {
    iconv_close(ic_ptr);
  }

  init();
}/*}}}*/

#endif

