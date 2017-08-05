
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
 * basic definitions and constants
 */

extern const unsigned short c_two_bytes;
extern const bool c_big_endian;

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
  struct ObjMap_s
  {
    U32  size;       // Object size [B]
    U32  alloc;      // Allocated buffer size [B]
    U32  data;       // ...
    int  type;       // ...
    int  flags;      // Bitflags (ObjAttr)
    VU32 timestamp;  // ...
    VB1  freshValid; // ...
    VB1  invalid;    // ...
    VU8  pageCnt;    // ...
    U8   copType;    // CANopen variable type (CopTypes)
    B1   swapEndian; // ...
    ObjDict::Mux     mux;  // ...
    ObjDict::ObjDesc desc; // ...
  };

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
  dict_ptr = nullptr;
}/*}}}*/

inline void can_obj_dict_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (dict_ptr != nullptr)
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
  dict_loc = nullptr;
}/*}}}*/

inline void can_object_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (dict_loc != nullptr)
  {
    it.release_location_ptr(dict_loc);
  }

  init();
}/*}}}*/

#endif

