
#ifndef __UCL_QUIRC_H
#define __UCL_QUIRC_H

@begin
include "script_parser.h"
@end

#include <quirc.h>

/*
 * definition of structure quirc_s
 */

struct quirc_s
{
  quirc *quirc_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure quirc_s
 */

inline void quirc_s::init()
{/*{{{*/
  quirc_ptr = nullptr;
}/*}}}*/

inline void quirc_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (quirc_ptr != nullptr)
  {
    quirc_destroy(quirc_ptr);
  }

  init();
}/*}}}*/

#endif

