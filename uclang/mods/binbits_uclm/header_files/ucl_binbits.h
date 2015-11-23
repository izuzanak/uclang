
#ifndef __UCL_BINBITS_H
#define __UCL_BINBITS_H

@begin
include "script_parser.h"
@end

// - bin array types -
enum
{
  c_bin_array_type_int32,
  c_bin_array_type_uint32,
};

/*
 * definition of structure bin_array_s
 */

struct bin_array_s
{
  unsigned type;
  void *cont;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure bin_array_ref_s
 */

struct bin_array_ref_s
{
  location_s *ba_loc;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure bin_array_s
 */

inline void bin_array_s::init()
{/*{{{*/
  cont = NULL;
}/*}}}*/

inline void bin_array_s::clear(interpreter_thread_s &it)
{/*{{{*/
  
  if (cont != NULL)
  {
    switch (type)
    {
    case c_bin_array_type_int32:
      ((bi_array_s *)cont)->clear();
      break;
    case c_bin_array_type_uint32:
      ((ui_array_s *)cont)->clear();
      break;
    default:
      cassert(0);
    }

    cfree(cont);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure bin_array_ref_s
 */

inline void bin_array_ref_s::init()
{/*{{{*/
  ba_loc = NULL;
}/*}}}*/

inline void bin_array_ref_s::clear(interpreter_thread_s &it)
{/*{{{*/
  
  // - release bin array location -
  if (ba_loc != NULL)
  {
    it.release_location_ptr(ba_loc);
  }

  init();
}/*}}}*/

#endif

