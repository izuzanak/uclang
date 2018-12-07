
#ifndef __UCL_LINUX_H
#define __UCL_LINUX_H

@begin
include "script_parser.h"
@end

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

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
 * definition of structure mmap_s
 */

struct mmap_s
{
  location_s *fd_location;
  void *mem_ptr;
  size_t length;

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

/*
 * inline methods of structure mmap_s
 */

inline void mmap_s::init()
{/*{{{*/
  fd_location = nullptr;
  mem_ptr = nullptr;
}/*}}}*/

inline void mmap_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (mem_ptr != nullptr)
  {
    munmap(mem_ptr,length);
  }

  if (fd_location != nullptr)
  {
    it.release_location_ptr(fd_location);
  }

  init();
}/*}}}*/

#endif

