
#ifndef __UCL_SHIVAVG_H
#define __UCL_SHIVAVG_H

@begin
include "script_parser.h"
@end

#include <VG/openvg.h>
#include <VG/vgu.h>

/*
 * definition of class shivavg_c
 */
class shivavg_c
{
  public:
  static bool context;

  inline shivavg_c();
  inline ~shivavg_c();
};

/*
 * inline methods of class shivavg_c
 */

inline shivavg_c::shivavg_c()
{/*{{{*/
  context = false;
}/*}}}*/

inline shivavg_c::~shivavg_c()
{/*{{{*/
  if (context)
  {
    vgDestroyContextSH();
    context = false;
  }
}/*}}}*/

#endif

