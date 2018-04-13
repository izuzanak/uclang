
#ifndef __UCL_VG_H
#define __UCL_VG_H

@begin
include "script_parser.h"
@end

#define GLM_FORCE_RADIANS

#if defined(LINUX) || defined(ANDROID) || defined(NACL)
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

#if defined(UCBOX_IMX6)
#include <VG/openvg.h>
#include <VG/vgext.h>
#include <VG/vgu.h>
#elif defined(LINUX)
#include <VG/openvg.h>
#include <VG/vgu.h>
#endif

/*
 * definition of class vg_c
 */
class vg_c
{
  public:
  inline vg_c();
  inline ~vg_c();
};

/*
 * inline methods of class vg_c
 */

inline vg_c::vg_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"vg_init()\n"););
}/*}}}*/

inline vg_c::~vg_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"vg_exit()\n"););
}/*}}}*/

#endif

