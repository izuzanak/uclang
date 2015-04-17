
#ifndef __UCL_ANDROID_H
#define __UCL_ANDROID_H

@begin
include "script_parser.h"
include "android.h"
@end

/*
 * definition of structure log_s
 */

struct log_s
{
  string_s tag;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure log_s
 */

inline void log_s::init()
{/*{{{*/
  tag.init();
}/*}}}*/

inline void log_s::clear(interpreter_thread_s &it)
{/*{{{*/
  tag.clear();

  init();
}/*}}}*/

#endif

