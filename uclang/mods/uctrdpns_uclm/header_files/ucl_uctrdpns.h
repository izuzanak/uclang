
#ifndef __UCL_UCTRDPNS_H
#define __UCL_UCTRDPNS_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"
#include <uctrdp.h>

/*
 * definition of structure trdp_ns_target_s
 */

struct trdp_ns_target_s
{
  location_s *ns_location;
  TRDP::Handle handle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure trdp_ns_target_s
 */

inline void trdp_ns_target_s::init()
{/*{{{*/
  ns_location = nullptr;
  handle = TRDP::TRDP_NULL_HANDLE;
}/*}}}*/

inline void trdp_ns_target_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release ns location -
  if (ns_location != nullptr)
  {
    TRDP::NS *ns_ptr = (TRDP::NS *)ns_location->v_data_ptr;

    // - remove target -
    if (handle != TRDP::TRDP_NULL_HANDLE)
    {
      ns_ptr->RemoveTarget(handle);
    }

    it.release_location_ptr(ns_location);
  }

  init();
}/*}}}*/

#endif

