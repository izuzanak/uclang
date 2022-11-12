
#ifndef __UCL_CL_H
#define __UCL_CL_H

@begin
include "script_parser.h"
@end

#define CL_TARGET_OPENCL_VERSION 220
#include <CL/cl.h>
#include <CL/cl_ext.h>

/*
 * definition of structure cl_memmap_s
 */

struct cl_memmap_s
{
  location_s *mem_loc;
  location_s *cqueue_loc;
  void *data;
  size_t size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure cl_memmap_s
 */

inline void cl_memmap_s::init()
{/*{{{*/
  mem_loc = nullptr;
  cqueue_loc = nullptr;
  data = nullptr;
  size = 0;
}/*}}}*/

inline void cl_memmap_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - unmap mapped memory -
  clEnqueueUnmapMemObject(
      (cl_command_queue)cqueue_loc->v_data_ptr,
      (cl_mem)mem_loc->v_data_ptr,
      data,0,nullptr,nullptr);

  // - release map location -
  if (mem_loc != nullptr)
  {
    it.release_location_ptr(mem_loc);
  }

  // - release command queue location -
  if (cqueue_loc != nullptr)
  {
    it.release_location_ptr(cqueue_loc);
  }

  init();
}/*}}}*/

#endif

