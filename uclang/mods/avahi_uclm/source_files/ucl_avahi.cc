
@begin
include "ucl_avahi.h"
@end

/*
 * static constants of structure avahi_poll_s
 */

const AvahiPoll avahi_poll_s::g_avahi_poll =
{/*{{{*/
  nullptr,
  avahi_poll_s::watch_new,
  avahi_poll_s::watch_update,
  avahi_poll_s::watch_get_events,
  avahi_poll_s::watch_free,
  avahi_poll_s::timeout_new,
  avahi_poll_s::timeout_update,
  avahi_poll_s::timeout_free
};/*}}}*/

/*
 * methods of structure avahi_poll_s
 */

AvahiWatch *avahi_poll_s::watch_new(const AvahiPoll *api,int fd,AvahiWatchEvent event,AvahiWatchCallback callback,void *userdata)
{/*{{{*/
  // typedef void(* AvahiWatchCallback) (AvahiWatch *w, int fd, AvahiWatchEvent event, void *userdata)
  fprintf(stderr,"avahi_poll_s::watch_new\n");

  // FIXME TODO continue ...
  return nullptr;
}/*}}}*/

void avahi_poll_s::watch_update(AvahiWatch *w,AvahiWatchEvent event)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::watch_update\n");
}/*}}}*/

AvahiWatchEvent avahi_poll_s::watch_get_events(AvahiWatch *a_watch)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::watch_get_events\n");

  // FIXME TODO continue ...
  return AVAHI_WATCH_IN;
}/*}}}*/

void avahi_poll_s::watch_free(AvahiWatch *a_watch)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::watch_free\n");
}/*}}}*/

AvahiTimeout *avahi_poll_s::timeout_new(const AvahiPoll *api,const struct timeval *tv,AvahiTimeoutCallback callback,void *userdata)
{/*{{{*/
  // typedef void(* AvahiTimeoutCallback) (AvahiTimeout *t, void *userdata)
  fprintf(stderr,"avahi_poll_s::timeout_new\n");

  // FIXME TODO continue ...
  return nullptr;
}/*}}}*/

void avahi_poll_s::timeout_update(AvahiTimeout *,const struct timeval *tv)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::timeout_update\n");
}/*}}}*/

void avahi_poll_s::timeout_free(AvahiTimeout *t)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::timeout_free\n");
}/*}}}*/

