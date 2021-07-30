
@begin
include "ucl_epoll.h"
@end

/*
 * methods of structure epoll_s
 */

bool epoll_s::reinit()
{/*{{{*/

  // - ERROR -
  if (close(fd) != 0)
  {
    return false;
  }

  // - create new epoll fd -
  fd = epoll_create1(flags);

  // - ERROR -
  if (fd == -1)
  {
    return false;
  }

  // - reinitialize all registered fds -
  if (fds.used != 0)
  {
    epoll_event event = {0};

    epoll_fd_s *fd_ptr = fds.data;
    epoll_fd_s *fd_ptr_end = fd_ptr + fds.used;
    do
    {
      if (fd_ptr->fd != EPOLL_FD_UNUSED)
      {
        event.events = fd_ptr->events;
        event.data.fd = fd_ptr->fd;

        // - ERROR -
        if (epoll_ctl(fd,EPOLL_CTL_ADD,fd_ptr->fd,&event) == -1)
        {
          return false;
        }
      }
    } while(++fd_ptr < fd_ptr_end);
  }

  return true;
}/*}}}*/

/*
 * methods of generated structures
 */

// -- epoll_fd_s --
@begin
methods epoll_fd_s
@end

// -- epoll_fds_s --
@begin
methods epoll_fds_s
@end

