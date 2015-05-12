
#ifndef __UCL_ALGORITHMS_H
#define __UCL_ALGORITHMS_H

@begin
include "script_parser.h"
@end

/*
 * definition of structure iterable_s
 */

struct iterable_s
{
  location_s *location;
  unsigned type;
  unsigned index;
  location_s *item_reference;
  location_s *item_location;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure iterable_s
 */

inline void iterable_s::init()
{/*{{{*/
  location = NULL;
  type = c_idx_not_exist;
  index = 0;
  item_reference = NULL;
  item_location = NULL;
}/*}}}*/

inline void iterable_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release item reference -
  if (item_reference != NULL)
  {
    it.release_location_ptr(item_reference);
  }

  init();
}/*}}}*/

#endif

