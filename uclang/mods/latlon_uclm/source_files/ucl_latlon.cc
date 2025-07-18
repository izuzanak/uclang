
@begin
include "ucl_latlon.h"
@end

/*
 * inline methods of structure latlon_s
 */

double latlon_s::distance(latlon_s &a_second)
{/*{{{*/
  double lat1 = lat*c_math_pi/180.0;
  double lat2 = a_second.lat*c_math_pi/180.0;

  double lat_diff = lat2 - lat1;
  double lon_diff = (a_second.lon - lon)*c_math_pi/180.0;

  lat_diff = sin(lat_diff / 2.0);
  lon_diff = sin(lon_diff / 2.0);

  double a = lat_diff*lat_diff + cos(lat1)*cos(lat2)*lon_diff*lon_diff;

  return c_earth_radius_meters*(2.0*atan2(sqrt(a),sqrt(1.0 - a)));
}/*}}}*/

double latlon_s::angle(latlon_s &a_second)
{/*{{{*/
  double lat1 = lat*c_math_pi/180.0;
  double lat2 = a_second.lat*c_math_pi/180.0;

  double lon_diff = (a_second.lon - lon)*c_math_pi/180.0;

  double y = sin(lon_diff)*cos(lat2);
  double x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(lon_diff);

  double rads = atan2(y,x);
  double degs = rads*180.0/c_math_pi;

  degs += 270.0;
  if (degs > 360.0) { degs -= 360.0; }

  return degs;
}/*}}}*/

