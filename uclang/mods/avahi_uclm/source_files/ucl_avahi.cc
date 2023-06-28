
@begin
include "ucl_avahi.h"
@end

/*
 * methods of generated structures
 */

// -- watch_array_s --
@begin
methods watch_array_s
@end

// -- timeout_tree_s --
@begin
methods timeout_tree_s
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
  fprintf(stderr,"avahi_poll_s::timeout_new\n");
  
  avahi_poll_s *poll = (avahi_poll_s *)api;

  timeout_s *timeout = (timeout_s *)cmalloc(sizeof(timeout_s));

  if (tv != nullptr)
  {
    struct timespec tp;
    if (clock_gettime(CLOCK_MONOTONIC,&tp) != 0)
    {
      cfree(timeout);
      return nullptr;
    }

    timeout->target_time =
      tp.tv_sec*1000000000ULL + tp.tv_nsec +
      tv->tv_sec*1000000000ULL + tv->tv_usec*1000ULL;
  }
  else
  {
    timeout->target_time = LLONG_MAX;
  }

  timeout->callback = callback;
  timeout->userdata = userdata;
  timeout->poll = poll;
  timeout->index = poll->timeout_tree.insert(timeout);

  return (AvahiTimeout *)timeout;
}/*}}}*/

void avahi_poll_s::timeout_update(AvahiTimeout *a_timeout,const struct timeval *tv)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::timeout_update\n");
}/*}}}*/

void avahi_poll_s::timeout_free(AvahiTimeout *a_timeout)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::timeout_free\n");

  timeout_s *timeout = (timeout_s *)a_timeout;
  timeout->poll->timeout_tree.remove(timeout->index);
  cfree(timeout);
}/*}}}*/

/*
 * methods of structure avahi_client_s
 */

void avahi_client_s::callback(AvahiClient *client,AvahiClientState state,void *userdata)
{/*{{{*/
  fprintf(stderr,"avahi_client_s::callback\n");
}/*}}}*/

