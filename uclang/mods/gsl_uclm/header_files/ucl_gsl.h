
#ifndef __UCL_GSL_H
#define __UCL_GSL_H

@begin
include "script_parser.h"
@end

#include <gsl/gsl_errno.h>
#include <gsl/gsl_interp.h>

enum
{/*{{{*/
  c_gsl_interp_type_linear = 0,
  c_gsl_interp_type_polynomial,
  c_gsl_interp_type_cspline,
  c_gsl_interp_type_cspline_periodic,
  c_gsl_interp_type_akima,
  c_gsl_interp_type_akima_periodic,
  c_gsl_interp_type_steffen,
  c_gsl_interp_type_count,
};/*}}}*/

extern const gsl_interp_type *c_gsl_interp_types[];

/*
 * definition of structure gsl_spline_s
 */

struct gsl_spline_s
{
  gsl_interp_accel *accel;
  gsl_interp *interp;
  double *xa;
  double *ya;
  size_t size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class gsl_c
 */
class gsl_c
{
  public:
  inline gsl_c();
  inline ~gsl_c();
};

/*
 * inline methods of structure gsl_spline_s
 */

inline void gsl_spline_s::init()
{/*{{{*/
  accel  = nullptr;
  interp = nullptr;
  xa = nullptr;
  ya = nullptr;
}/*}}}*/

inline void gsl_spline_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (accel != nullptr)
  {
    gsl_interp_accel_free(accel);
  }

  if (interp != nullptr)
  {
    gsl_interp_free(interp);
  }

  if (xa != nullptr)
  {
    cfree(xa);
  }

  if (ya != nullptr)
  {
    cfree(ya);
  }

  init();
}/*}}}*/

/*
 * inline methods of class gsl_c
 */

inline gsl_c::gsl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gsl_init()\n"););

  // - turn off gsl error handler -
  gsl_set_error_handler_off();
}/*}}}*/

inline gsl_c::~gsl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gsl_exit()\n"););
}/*}}}*/

#endif

