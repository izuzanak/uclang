
#ifndef __UCL_EPOLL_H
#define __UCL_EPOLL_H

@begin
include "script_parser.h"
@end

#include <sys/epoll.h>

/*
 * definition of structure epoll_s
 */

struct epoll_s
{
  int fd;

  inline void init();
  void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure epoll_s
 */

inline void epoll_s::init()
{/*{{{*/
  fd = -1;
}/*}}}*/

inline void epoll_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - close file descriptor -
  if (fd != -1)
  {
    close(fd);
  }

  init();
}/*}}}*/

#endif

