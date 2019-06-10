
#ifndef __UCL_PROTOBUF_H
#define __UCL_PROTOBUF_H

@begin
include "script_parser.h"
@end

#include <protobuf-c/protobuf-c.h>

/*
 * definition of structure proto_msg_descr_s
 */

struct proto_msg_descr_s
{
  ProtobufCMessageDescriptor *descr;

  inline void init();
  void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure proto_msg_descr_s
 */

inline void proto_msg_descr_s::init()
{/*{{{*/
  descr = nullptr;
}/*}}}*/

inline void proto_msg_descr_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

