
@begin
include "ucl_gsl.h"
@end

// - gsl global init object -
gsl_c g_gsl;

const gsl_interp_type *c_gsl_interp_types[] =
{
  gsl_interp_linear,
  gsl_interp_polynomial,
  gsl_interp_cspline,
  gsl_interp_cspline_periodic,
  gsl_interp_akima,
  gsl_interp_akima_periodic,
  gsl_interp_steffen,
};

