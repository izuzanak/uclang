
#ifndef __UCL_AVAHI_H
#define __UCL_AVAHI_H

@begin
include "script_parser.h"
@end

#include <avahi-client/client.h>
#include <avahi-client/lookup.h>
#include <avahi-client/publish.h>

#include <avahi-common/simple-watch.h>
#include <avahi-common/timeval.h>

typedef struct avahi_poll_s avahi_poll_s;

/*
 * definition of structure watch_s
 */

struct watch_s
{
  int fd;
  AvahiWatchEvent event;
  AvahiWatchEvent revent;
  AvahiWatchCallback callback;
  void *userdata;
  avahi_poll_s *poll;
};

typedef watch_s * watch_pointer;

/*
 * definition of structure timeout_s
 */

struct timeout_s
{
  lli target_time;
  AvahiTimeoutCallback callback;
  void *userdata;
  avahi_poll_s *poll;
  unsigned index;
};

typedef timeout_s * timeout_pointer;

/*
 * definitions of generated structures
 */

// -- watch_array_s --
@begin
define watch_pointer basic
array<watch_pointer> watch_array_s;
@end

// -- timeout_tree_s --
@begin
define timeout_pointer basic
safe_rb_tree<timeout_pointer> timeout_tree_s;
@end

/*
 * definition of structure avahi_poll_s
 */

struct avahi_poll_s
{
  static const AvahiPoll g_avahi_poll;

  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  AvahiPoll avahi_poll;
  watch_array_s watch_array;
  timeout_tree_s timeout_tree;

  static AvahiWatch *watch_new(const AvahiPoll *api,int fd,AvahiWatchEvent event,AvahiWatchCallback callback,void *userdata);
  static void watch_update(AvahiWatch *a_watch,AvahiWatchEvent event);
  static AvahiWatchEvent watch_get_events(AvahiWatch *a_watch);
  static void watch_free(AvahiWatch *a_watch);
  static AvahiTimeout *timeout_new(const AvahiPoll *api,const struct timeval *tv,AvahiTimeoutCallback callback,void *userdata);
  static void timeout_update(AvahiTimeout *a_timeout,const struct timeval *tv);
  static void timeout_free(AvahiTimeout *a_timeout);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure avahi_client_s
 */

struct avahi_client_s
{
  AvahiClient *avahi_client;
  location_s *avahi_poll_loc;
  location_s *callback_dlg;
  location_s *user_data_loc;
  AvahiClientState state;

  static void callback(AvahiClient *a_client,AvahiClientState state,void *userdata);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure avahi_service_browser_s
 */

struct avahi_service_browser_s
{
  AvahiServiceBrowser *avahi_service_browser;
  location_s *avahi_client_loc;
  location_s *browse_cb_dlg;
  location_s *resolve_cb_dlg;
  location_s *user_data_loc;

  AvahiBrowserEvent browse_event;
  AvahiIfIndex browse_interface;
  AvahiProtocol browse_protocol;
  const char *browse_name;
  const char *browse_type;
  const char *browse_domain;

  AvahiResolverEvent resolve_event;
  const char *resolve_name;
  const char *resolve_type;
  const char *resolve_domain;
  const char *resolve_host;
  uint16_t resolve_port;
  AvahiStringList *resolve_txt;

  static void browse_callback(AvahiServiceBrowser *a_browser,AvahiIfIndex interface,AvahiProtocol protocol,
      AvahiBrowserEvent event,const char *name,const char *type,const char *domain,
      AvahiLookupResultFlags flags,void *userdata);
  static void resolve_callback(AvahiServiceResolver *a_resolver,AvahiIfIndex interface,AvahiProtocol protocol,
      AvahiResolverEvent event,const char *name,const char *type,const char *domain,const char *host_name,
      const AvahiAddress *a,uint16_t port,AvahiStringList *txt,AvahiLookupResultFlags flags,void *userdata);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- watch_array_s --
@begin
inlines watch_array_s
@end

// -- timeout_tree_s --
@begin
inlines timeout_tree_s
@end

inline int timeout_tree_s::__compare_value(timeout_pointer &a_first,timeout_pointer &a_second)
{/*{{{*/
  return a_first->target_time < a_second->target_time ? -1 :
    a_first->target_time > a_second->target_time ? 1 : 0;
}/*}}}*/

/*
 * inline methods of structure avahi_poll_s
 */

inline void avahi_poll_s::init()
{/*{{{*/
  it_ptr = nullptr;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  avahi_poll = g_avahi_poll;
  watch_array.init();
  timeout_tree.init();
}/*}}}*/

inline void avahi_poll_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (watch_array.used != 0)
  {
    // - release all allocated watches -
    watch_pointer *wp_ptr = watch_array.data;
    watch_pointer *wp_ptr_end = wp_ptr + watch_array.used;
    do {
      if (*wp_ptr != nullptr)
      {
        cfree(*wp_ptr);
      }
    } while(++wp_ptr < wp_ptr_end);
  }

  watch_array.clear();

  if (timeout_tree.count != 0)
  {
    // - release all allocated timeouts -
    timeout_tree_s_node *ttn_ptr = timeout_tree.data;
    timeout_tree_s_node *ttn_ptr_end = ttn_ptr + timeout_tree.used;
    do {
      if (ttn_ptr->valid)
      {
        cfree(ttn_ptr->object);
      }
    } while(++ttn_ptr < ttn_ptr_end);
  }

  timeout_tree.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure avahi_client_s
 */

inline void avahi_client_s::init()
{/*{{{*/
  avahi_client = nullptr;
  avahi_poll_loc = nullptr;
  callback_dlg = nullptr;
  user_data_loc = nullptr;
  state = (AvahiClientState)-1;
}/*}}}*/

inline void avahi_client_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (avahi_client != nullptr)
  {
    avahi_client_free(avahi_client);
  }

  if (avahi_poll_loc != nullptr)
  {
    it.release_location_ptr(avahi_poll_loc);
  }

  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  if (user_data_loc != nullptr)
  {
    it.release_location_ptr(user_data_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure avahi_service_browser_s
 */

inline void avahi_service_browser_s::init()
{/*{{{*/
  avahi_service_browser = nullptr;
  avahi_client_loc = nullptr;
  browse_cb_dlg = nullptr;
  resolve_cb_dlg = nullptr;
  user_data_loc = nullptr;

  browse_event = (AvahiBrowserEvent)-1;
  browse_interface = AVAHI_IF_UNSPEC;
  browse_protocol = AVAHI_PROTO_UNSPEC;
  browse_name = nullptr;
  browse_type = nullptr;
  browse_domain = nullptr;

  resolve_event = (AvahiResolverEvent)-1;
  resolve_name = nullptr;
  resolve_type = nullptr;
  resolve_domain = nullptr;
  resolve_host = nullptr;
  resolve_port = 0;
  resolve_txt = nullptr;
}/*}}}*/

inline void avahi_service_browser_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (avahi_service_browser != nullptr)
  {
    avahi_service_browser_free(avahi_service_browser);
  }

  if (avahi_client_loc != nullptr)
  {
    it.release_location_ptr(avahi_client_loc);
  }

  if (browse_cb_dlg != nullptr)
  {
    it.release_location_ptr(browse_cb_dlg);
  }

  if (resolve_cb_dlg != nullptr)
  {
    it.release_location_ptr(resolve_cb_dlg);
  }

  if (user_data_loc != nullptr)
  {
    it.release_location_ptr(user_data_loc);
  }

  init();
}/*}}}*/

#endif

