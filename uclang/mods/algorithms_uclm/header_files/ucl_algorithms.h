
#ifndef __UCL_ALGORITHMS_H
#define __UCL_ALGORITHMS_H

@begin
include "script_parser.h"
@end

/*
 * basic definitions and constants
 */

extern unsigned c_rm_class_dict;

// - filter type identifiers -
enum
{
  c_filter_type_array_map = 0,
  c_filter_type_array_filter,
  c_filter_type_dict_map,
  c_filter_type_dict_filter,
  c_filter_type_dlg_map,
  c_filter_type_dlg_filter,
};

// - range type identifiers -
enum
{
  c_range_type_ascending = 0,
  c_range_type_descending,
};

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
 * definition of structure filter_s
 */

struct filter_s
{
  unsigned type;
  location_s *map_loc;
  iterable_s iterable;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure range_s
 */

struct range_s
{
  unsigned type;
  location_s *start_location;
  location_s *end_location;
  location_s *step_location;
  location_s *actual_location;

  uli tmp_code[7];

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

/*
 * inline methods of structure filter_s
 */

inline void filter_s::init()
{/*{{{*/
  type = c_idx_not_exist;
  map_loc = NULL;
  iterable.init();
}/*}}}*/

inline void filter_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release iterable location -
  if (iterable.location != NULL)
  {
    it.release_location_ptr(iterable.location);
  }

  // - release map location -
  if (map_loc != NULL)
  {
    it.release_location_ptr(map_loc);
  }

  iterable.clear(it);

  init();
}/*}}}*/

/*
 * inline methods of structure range_s
 */

inline void range_s::init()
{/*{{{*/
  start_location = NULL;
  end_location = NULL;
  step_location = NULL;
  actual_location = NULL;
}/*}}}*/

inline void range_s::clear(interpreter_thread_s &it)
{/*{{{*/

#define RELEASE_LOCATION_PTR(LOCATION_PTR) \
{/*{{{*/\
  if (LOCATION_PTR != NULL)\
  {\
    it.release_location_ptr(LOCATION_PTR);\
  }\
}/*}}}*/

  RELEASE_LOCATION_PTR(start_location);
  RELEASE_LOCATION_PTR(end_location);
  RELEASE_LOCATION_PTR(step_location);
  RELEASE_LOCATION_PTR(actual_location);

  init();
}/*}}}*/

#endif

