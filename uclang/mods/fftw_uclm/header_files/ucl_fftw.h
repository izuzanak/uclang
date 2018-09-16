
#ifndef __UCL_FFTW_H
#define __UCL_FFTW_H

@begin
include "script_parser.h"
@end

#include <fftw3.h>

/*
 * definition of structure fftw_plan_s
 */

struct fftw_plan_s
{
  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure fftw_plan_s
 */

inline void fftw_plan_s::init()
{/*{{{*/
}/*}}}*/

inline void fftw_plan_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

