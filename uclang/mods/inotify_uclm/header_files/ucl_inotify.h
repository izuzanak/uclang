
#ifndef __UCL_INOTIFY_H
#define __UCL_INOTIFY_H

@begin
include "script_parser.h"
@end

#include "sys/inotify.h"

/*
 * definition of structure inotify_watch_s
 */

struct inotify_watch_s
{
  location_s *inotify_loc;
  location_s *name_loc;
  uint32_t mask;
  int wd;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure inotify_event_s
 */

struct inotify_event_s
{
  int wd;
  uint32_t mask;
  uint32_t cookie;
  location_s *name_loc;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure inotify_watch_s
 */

inline void inotify_watch_s::init()
{/*{{{*/
  inotify_loc = NULL;
  name_loc = NULL;
  wd = -1;
}/*}}}*/

inline void inotify_watch_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (inotify_loc != NULL)
  {
    // - release inotify watch descriptor -
    if (wd != -1)
    {
      inotify_rm_watch((int)inotify_loc->v_data_ptr,wd);
    }

    // - release inotify location -
    it.release_location_ptr(inotify_loc);
  }

  // - release name location -
  if (name_loc != NULL)
  {
    it.release_location_ptr(name_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure inotify_event_s
 */

inline void inotify_event_s::init()
{/*{{{*/
  name_loc = NULL;
}/*}}}*/

inline void inotify_event_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release name location -
  if (name_loc != NULL)
  {
    // - release inotify location -
    it.release_location_ptr(name_loc);
  }

  init();
}/*}}}*/

#endif

