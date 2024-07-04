
#ifndef __UCL_BTRFSUTIL_H
#define __UCL_BTRFSUTIL_H

@begin
include "script_parser.h"
@end

#include "btrfsutil.h"

/*
 * definition of structure btrfs_sub_s
 */

struct btrfs_sub_s
{
  string_s path;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure btrfs_sub_s
 */

inline void btrfs_sub_s::init()
{/*{{{*/
  path.init();
}/*}}}*/

inline void btrfs_sub_s::clear(interpreter_thread_s &it)
{/*{{{*/
  path.clear();

  init();
}/*}}}*/

#endif

