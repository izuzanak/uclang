
#ifndef __UCL_SHAPE_H
#define __UCL_SHAPE_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <shapefil.h>

/*
 * definition of structure shp_handle_s
 */

struct shp_handle_s
{
  SHPHandle handle;
  int ent_count;
  int shape_type;
  double min_bound[4];
  double max_bound[4];

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure shp_part_s
 */

struct shp_part_s
{
  location_s *object_loc;
  int part_idx;
  unsigned length;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure shp_handle_s
 */

inline void shp_handle_s::init()
{/*{{{*/
  handle = nullptr;
}/*}}}*/

inline void shp_handle_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (handle != nullptr)
  {
    SHPClose(handle);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure shp_part_s
 */

inline void shp_part_s::init()
{/*{{{*/
  object_loc = nullptr;
}/*}}}*/

inline void shp_part_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (object_loc != nullptr)
  {
    it.release_location_ptr(object_loc);
  }

  init();
}/*}}}*/

#endif

