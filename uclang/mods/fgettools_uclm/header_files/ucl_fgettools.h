
#ifndef __UCL_FGETTOOLS_H
#define __UCL_FGETTOOLS_H

@begin
include "script_parser.h"
@end

#include <fcntl.h>
#include <sys/mman.h>

/*
 * definition of structure fget_target_s
 */

struct fget_target_s
{
  unsigned block_size;
  unsigned block_cnt;

  unsigned file_size;
  unsigned map_size;

  char *file_ptr;
  char *map_ptr;

  unsigned index;
  unsigned done_cnt;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure fget_target_s
 */

inline void fget_target_s::init()
{/*{{{*/
  file_ptr = NULL;
  map_ptr = NULL;
}/*}}}*/

inline void fget_target_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - unmap file -
  if (file_ptr != NULL)
  {
    munmap(file_ptr,file_size);
  }

  // - unmap map -
  if (map_ptr != NULL)
  {
    munmap(map_ptr,map_size);
  }

  init();
}/*}}}*/

#endif

