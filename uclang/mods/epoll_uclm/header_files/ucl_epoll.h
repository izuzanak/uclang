
#ifndef __UCL_EPOLL_H
#define __UCL_EPOLL_H

@begin
include "script_parser.h"
@end

#include <sys/epoll.h>

enum
{
  EPOLL_FD_UNUSED  = -1,
  EPOLL_FD_REMOVED = -2,
};

/*
 * definition of generated structures
 */

// -- epoll_fd_s --
@begin
struct
<
int:fd
unsigned:events
>
epoll_fd_s;
@end

// -- epoll_fds_s --
@begin
array<epoll_fd_s> epoll_fds_s;
@end

/*
 * definition of structure epoll_s
 */

struct epoll_s
{
  int fd;
  epoll_fds_s fds;

  inline void init();
  void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- epoll_fd_s --
@begin
inlines epoll_fd_s
@end

// -- epoll_fds_s --
@begin
inlines epoll_fds_s
@end

/*
 * inline methods of structure epoll_s
 */

inline void epoll_s::init()
{/*{{{*/
  fd = -1;
  fds.init();
}/*}}}*/

inline void epoll_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - close file descriptor -
  if (fd != -1)
  {
    close(fd);
  }

  fds.clear();

  init();
}/*}}}*/

#endif

