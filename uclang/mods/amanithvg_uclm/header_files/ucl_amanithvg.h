
#ifndef __UCL_AMANITHVG_H
#define __UCL_AMANITHVG_H

@begin
include "script_parser.h"
@end

#include <VG/openvg.h>
#include <VG/vgu.h>
#include <VG/vgext.h>

/*
 * definition of class amanith_vg_c
 */
class amanith_vg_c
{
  public:
  static location_s *context_loc;
  static location_s *surface_loc;
};

#endif

