
#ifndef __UCL_SYS_H
#define __UCL_SYS_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <dirent.h>
#include <regex.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <poll.h>
#if SYSTEM_TYPE_UNIX_SOCKET == ENABLED
#define ENABLE_CLASS_SOCKET
#endif
#define ENABLE_CLASS_REGEX
#define ENABLE_CLASS_POLL
#define ENABLE_CLASS_CLOCK
#define POPEN_FNAME popen
#define PCLOSE_FNAME pclose
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
#include <process.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#define POPEN_FNAME _popen
#define PCLOSE_FNAME _pclose
#endif

/*
 * global definitions and constants
 */

const int value_on  = 1;
const int value_off = 0;


/*
 * definition of generated structures
 */

// -- timer_record_s --
@begin
struct
<
lli:target_stamp
pointer:callback_dlg
pointer:parameter
>
timer_record_s;
@end

// -- timer_record_rb_tree_s --
@begin
rb_tree<timer_record_s> timer_record_rb_tree_s;
@end

#ifdef ENABLE_CLASS_POLL
/*
 * definition of structure poll_s
 */

struct poll_s
{
  pollfd *fds;
  nfds_t nfds;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};
#endif

/*
 * definition of structure timer_s
 */

struct timer_s
{
  timer_record_rb_tree_s records;

  inline void init();
  void clear(interpreter_thread_s &it);

  inline static long long int get_stamp();
};

/*
 * inline methods of generated structures
 */

// -- timer_record_s --
@begin
inlines timer_record_s
@end

// -- timer_record_rb_tree_s --
@begin
inlines timer_record_rb_tree_s
@end

inline int timer_record_rb_tree_s::__compare_value(timer_record_s &a_first,timer_record_s &a_second)
{/*{{{*/
  return a_first.target_stamp < a_second.target_stamp ? -1 :
    a_first.target_stamp > a_second.target_stamp ? 1 : 0;
}/*}}}*/

#ifdef ENABLE_CLASS_POLL
/*
 * inline methods of structure poll_s
 */

inline void poll_s::init()
{/*{{{*/
  fds = nullptr;
  nfds = 0;
}/*}}}*/

inline void poll_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release poll file descriptors -
  if (fds != nullptr)
  {
    cfree(fds);
  }

  init();
}/*}}}*/
#endif

/*
 * inline methods of structure timer_s
 */

inline void timer_s::init()
{/*{{{*/
  records.init();
}/*}}}*/

inline long long int timer_s::get_stamp()
{/*{{{*/
  #if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
    timespec tv;
    clock_gettime(CLOCK_MONOTONIC,&tv);

    return 1000LL*tv.tv_sec + tv.tv_nsec/1000000LL;
  #else
    cassert(0);
  #endif
}/*}}}*/

#endif

