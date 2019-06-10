
#ifndef __UCL_NANOMSG_H
#define __UCL_NANOMSG_H

@begin
include "script_parser.h"
@end

#include <nanomsg/nn.h>

#include <nanomsg/bus.h>
#include <nanomsg/pair.h>
#include <nanomsg/pipeline.h>
#include <nanomsg/pubsub.h>
#include <nanomsg/reqrep.h>
#include <nanomsg/survey.h>

#include <nanomsg/inproc.h>
#include <nanomsg/ipc.h>
#include <nanomsg/tcp.h>
#include <nanomsg/ws.h>

enum {
  c_option_type_int = 0,
  c_option_type_string,
  c_option_type_error
};

/*
 * definition of structure nano_msg_s
 */

struct nano_msg_s
{
  static unsigned option_type(int a_level,int a_option);
};

/*
 * definition of structure nano_endpoint_s
 */

struct nano_endpoint_s
{
  location_s *socket_ptr;
  int end_id;

  inline void init();
  void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure nano_endpoint_s
 */

inline void nano_endpoint_s::init()
{/*{{{*/
  socket_ptr = nullptr;
  end_id = -1;
}/*}}}*/

inline void nano_endpoint_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (end_id != -1)
  {
    int nn_fd = (int)socket_ptr->v_data_ptr;

    do
    {
      if (nn_shutdown(nn_fd,end_id) == 0 || errno != EINTR)
      {
        break;
      }
    } while(1);
  }

  // - release socket location -
  if (socket_ptr != nullptr)
  {
    it.release_location_ptr(socket_ptr);
  }

  init();
}/*}}}*/

#endif

