
#ifndef __UCL_GIF_H
#define __UCL_GIF_H

@begin
include "script_parser.h"
@end

#include <gif_lib.h>

/*
 * definition of structure gif_image_s
 */

struct gif_image_s
{
  pointer gif_file_loc;
  unsigned image_index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure gif_image_s
 */

inline void gif_image_s::init()
{/*{{{*/
  gif_file_loc = nullptr;
}/*}}}*/

inline void gif_image_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release gif file location -
  if (gif_file_loc != nullptr)
  {
    it.release_location_ptr((location_s *)gif_file_loc);
  }

  init();
}/*}}}*/

#endif

