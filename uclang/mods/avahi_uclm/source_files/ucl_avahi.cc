
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
  fprintf(stderr,"avahi_poll_s::watch_new\n");

  avahi_poll_s *avahi_poll = (avahi_poll_s *)api->userdata;
  watch_array_s &watch_array = avahi_poll->watch_array;

  // - ERROR -
  if (watch_array.used > (unsigned)fd && watch_array[fd] != nullptr)
  {
    return nullptr;
  }

  watch_s *watch = (watch_s *)cmalloc(sizeof(watch_s));

  watch->fd = fd;
  watch->event = event;
  watch->revent = (AvahiWatchEvent)0;
  watch->callback = callback;
  watch->userdata = userdata;
  watch->poll = avahi_poll;

  // - resize watch array -
  while (watch_array.used <= (unsigned)fd)
  {
    watch_array.push(nullptr);
  }

  watch_array[fd] = watch;

  return (AvahiWatch *)watch;
}/*}}}*/

void avahi_poll_s::watch_update(AvahiWatch *a_watch,AvahiWatchEvent event)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::watch_update\n");

  ((watch_s *)a_watch)->event = event;
}/*}}}*/

AvahiWatchEvent avahi_poll_s::watch_get_events(AvahiWatch *a_watch)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::watch_get_events\n");

  return ((watch_s *)a_watch)->revent;
}/*}}}*/

void avahi_poll_s::watch_free(AvahiWatch *a_watch)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::watch_free\n");

  watch_s *watch = (watch_s *)a_watch;
  watch->poll->watch_array[watch->fd] = nullptr;
  cfree(watch);
}/*}}}*/

AvahiTimeout *avahi_poll_s::timeout_new(const AvahiPoll *api,const struct timeval *tv,AvahiTimeoutCallback callback,void *userdata)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::timeout_new\n");
  
  avahi_poll_s *avahi_poll = (avahi_poll_s *)api->userdata;

  timeout_s *timeout = (timeout_s *)cmalloc(sizeof(timeout_s));

  if (tv != nullptr)
  {
    struct timespec tp;
    if (clock_gettime(CLOCK_MONOTONIC,&tp) != 0)
    {
      cfree(timeout);
      return nullptr;
    }

    AvahiUsec time_usec = -avahi_age(tv);
    if (time_usec < 0) { time_usec = 0; }

    timeout->target_time = tp.tv_sec*1000000000ULL + tp.tv_nsec + time_usec*1000ULL;
  }
  else
  {
    timeout->target_time = LLONG_MAX;
  }

  timeout->callback = callback;
  timeout->userdata = userdata;
  timeout->poll = avahi_poll;
  timeout->index = avahi_poll->timeout_tree.insert(timeout);

  return (AvahiTimeout *)timeout;
}/*}}}*/

void avahi_poll_s::timeout_update(AvahiTimeout *a_timeout,const struct timeval *tv)
{/*{{{*/
  fprintf(stderr,"avahi_poll_s::timeout_update\n");

  timeout_s *timeout = (timeout_s *)a_timeout;
  timeout_tree_s &timeout_tree = timeout->poll->timeout_tree;

  timeout_tree.remove(timeout->index);

  if (tv != nullptr)
  {
    struct timespec tp;
    if (clock_gettime(CLOCK_MONOTONIC,&tp) != 0)
    {
      return;
    }

    AvahiUsec time_usec = -avahi_age(tv);
    if (time_usec < 0) { time_usec = 0; }

    timeout->target_time = tp.tv_sec*1000000000ULL + tp.tv_nsec + time_usec*1000ULL;
  }
  else
  {
    timeout->target_time = LLONG_MAX;
  }

  timeout->index = timeout_tree.insert(timeout);
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

void avahi_client_s::callback(AvahiClient *a_client,AvahiClientState state,void *userdata)
{/*{{{*/
  fprintf(stderr,"TODO - avahi_client_s::callback\n");

  // FIXME TODO set client state
  switch (state)
  {
    case AVAHI_CLIENT_S_REGISTERING:
      fprintf(stderr,"AVAHI_CLIENT_S_REGISTERING\n");
      break;
    case AVAHI_CLIENT_S_RUNNING:
      fprintf(stderr,"AVAHI_CLIENT_S_RUNNING\n");
      break;
    case AVAHI_CLIENT_S_COLLISION:
      fprintf(stderr,"AVAHI_CLIENT_S_COLLISION\n");
      break;
    case AVAHI_CLIENT_FAILURE:
      fprintf(stderr,"AVAHI_CLIENT_FAILURE\n");
      break;
    case AVAHI_CLIENT_CONNECTING:
      fprintf(stderr,"AVAHI_CLIENT_CONNECTING\n");
      break;
  }

  location_s *client_location = (location_s *)userdata;
  avahi_client_s *avahi_client = (avahi_client_s *)client_location->v_data_ptr;
  avahi_poll_s *avahi_poll = (avahi_poll_s *)avahi_client->avahi_poll_loc->v_data_ptr;

  interpreter_thread_s &it = *avahi_poll->it_ptr;
  delegate_s *delegate_ptr = (delegate_s *)avahi_client->callback_dlg->v_data_ptr;

  // - update client state -
  avahi_client->state = state;

  // - callback parameters -
  const unsigned param_cnt = 1;
  pointer *param_data = (pointer *)&client_location;

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,avahi_poll->source_pos,
    avahi_poll->ret_code = c_run_return_code_EXCEPTION;
    return;
  );
  it.release_location_ptr(trg_location);
}/*}}}*/

