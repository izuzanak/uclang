
#ifndef __UCL_LATLON_H
#define __UCL_LATLON_H

@begin
include "script_parser.h"
@end

/*
 * contants and definitions
 */

const double c_earth_radius_meters = 6371000.0;
const double c_math_pi = 3.14159265358979323846264338327950288L;

/*
 * definition of structure latlon_s
 */

struct latlon_s
{
  double lat;
  double lon;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  double distance(latlon_s &a_second);
  double angle(latlon_s &a_second);
};

/*
 * inline methods of structure latlon_s
 */

inline void latlon_s::init()
{/*{{{*/
}/*}}}*/

inline void latlon_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

