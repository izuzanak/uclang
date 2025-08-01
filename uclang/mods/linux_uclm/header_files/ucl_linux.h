
#ifndef __UCL_LINUX_H
#define __UCL_LINUX_H

@begin
include "script_parser.h"
@end

#include <fcntl.h>
#include <linux/version.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/timerfd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

// - file descriptor flags -
enum
{
  FD_FLAG_NO_CLOSE = 1 << 0
};

/*
 * definition of structure mmap_s
 */

struct mmap_s
{
  location_s *fd_location;
  void *mem_ptr;
  long long int length;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

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

