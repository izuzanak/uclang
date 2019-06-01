
#ifndef __UCL_FFTW_H
#define __UCL_FFTW_H

@begin
include "script_parser.h"
@end

#include <fftw.h>

/*
 * definition of structure fftw_plan_s
 */

struct fftw_plan_s
{
  fftwnd_plan plan;
  bi_array_s dimensions;
  int flags;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure fftw_plan_s
 */

inline void fftw_plan_s::init()
{/*{{{*/
  plan = nullptr;
  dimensions.init();
}/*}}}*/

inline void fftw_plan_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (plan != nullptr)
  {
    fftwnd_destroy_plan(plan);
  }

  dimensions.clear();

  init();
}/*}}}*/

#endif

