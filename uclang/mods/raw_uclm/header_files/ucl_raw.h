
#ifndef __UCL_RAW_H
#define __UCL_RAW_H

@begin
include "script_parser.h"
@end

#include "libraw/libraw.h"

// - raw processor state -
enum
{
  c_raw_proc_state_unpacked       = 1 << 0,
  c_raw_proc_state_unpacked_thumb = 1 << 1,
  c_raw_proc_state_processed      = 1 << 2,
};

/*
 * definition of structure raw_processor_s
 */

struct raw_processor_s
{
  location_s *buffer_loc;
  LibRaw *lr_ptr;
  unsigned state;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure raw_processor_s
 */

inline void raw_processor_s::init()
{/*{{{*/
  buffer_loc = nullptr;
  lr_ptr = nullptr;
  state = 0;
}/*}}}*/

inline void raw_processor_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release buffer location -
  if (buffer_loc != nullptr)
  {
    it.release_location_ptr(buffer_loc);
  }

  delete lr_ptr;

  init();
}/*}}}*/

#endif

