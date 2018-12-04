
#ifndef __UCL_LINUX_H
#define __UCL_LINUX_H

@begin
include "script_parser.h"
@end

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// - file descriptor flags -
enum
{
  FD_FLAG_NO_CLOSE = 1 << 0
};

/*
 * definition of structure fd_s
 */

struct fd_s
{
  int fd;
  int flags;

  inline void init();
  void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure fd_s
 */

inline void fd_s::init()
{/*{{{*/
  fd = -1;
  flags = 0;
}/*}}}*/

inline void fd_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - close file descriptor -
  if (fd != -1 && !(flags & FD_FLAG_NO_CLOSE))
  {
    close(fd);
  }

  init();
}/*}}}*/

#endif

