
#ifndef __UCL_AVAHI_H
#define __UCL_AVAHI_H

@begin
include "script_parser.h"
@end

#include <avahi-client/client.h>
#include <avahi-client/lookup.h>
#include <avahi-client/publish.h>

#include <avahi-common/simple-watch.h>

/*
 * definition of structure avahi_poll_s
 */

struct avahi_poll_s
{
  static const AvahiPoll g_avahi_poll;

  AvahiPoll avahi_poll;

  static AvahiWatch *watch_new(const AvahiPoll *api,int fd,AvahiWatchEvent event,AvahiWatchCallback callback,void *userdata);
  static void watch_update(AvahiWatch *w,AvahiWatchEvent event);
  static AvahiWatchEvent watch_get_events(AvahiWatch *a_watch);
  static void watch_free(AvahiWatch *a_watch);
  static AvahiTimeout *timeout_new(const AvahiPoll *api,const struct timeval *tv,AvahiTimeoutCallback callback,void *userdata);
  static void timeout_update(AvahiTimeout *,const struct timeval *tv);
  static void timeout_free(AvahiTimeout *t);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure avahi_client_s
 */

struct avahi_client_s
{
  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure avahi_poll_s
 */

inline void avahi_poll_s::init()
{/*{{{*/
  avahi_poll = g_avahi_poll;
}/*}}}*/

inline void avahi_poll_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure avahi_client_s
 */

inline void avahi_client_s::init()
{/*{{{*/
}/*}}}*/

inline void avahi_client_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

