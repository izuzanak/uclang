
#ifndef __UCL_UCCAN_H
#define __UCL_UCCAN_H

@begin
include "script_parser.h"
@end

#include "ucf.h"
using namespace Ucf;

#include "uccanopen.h"
using namespace Lod;
using namespace CopAsi;

/*
 * definition of structure can_obj_dict_s
 */

struct can_obj_dict_s
{
  bool eds_builder;
  ObjDict *dict_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure can_object_s
 */

struct can_object_s
{
  location_s *dict_loc;
  HObj handle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure can_obj_dict_s
 */

inline void can_obj_dict_s::init()
{/*{{{*/
  dict_ptr = NULL;
}/*}}}*/

inline void can_obj_dict_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (dict_ptr != NULL)
  {
    if (eds_builder)
    {
      delete (LodEdsBuilder *)dict_ptr;
    }
    else
    {
      delete dict_ptr;
    }
  }

  init();
}/*}}}*/

/*
 * inline methods of structure can_object_s
 */

inline void can_object_s::init()
{/*{{{*/
  dict_loc = NULL;
}/*}}}*/

inline void can_object_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (dict_loc != NULL)
  {
    it.release_location_ptr(dict_loc);
  }

  init();
}/*}}}*/

#endif

