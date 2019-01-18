
#ifndef __UCL_CURL_H
#define __UCL_CURL_H

@begin
include "script_parser.h"
@end

#include <curl/curl.h>

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <poll.h>
#endif

/*
 * definition of structure read_buffer_s
 */

struct read_buffer_s
{
  const void *data_ptr;
  unsigned data_size;
  unsigned index;

  inline void init(const void *a_data_ptr,unsigned a_data_size);
};

/*
 * definition of generated structures
 */

@begin
define curl_socket_t basic
@end

// -- fd_flags_s --
@begin
struct
<
curl_socket_t:fd
int:flags
>
fd_flags_s;
@end

// -- fd_flags_rb_tree_s --
@begin
safe_rb_tree<fd_flags_s> fd_flags_rb_tree_s;
@end

/*
 * definition of structure curl_props_s
 */
struct curl_props_s
{
  CURL *curl_ptr;
  curl_slist *headers;
  unsigned index;
  long long int unique_id;
  bc_array_s write_buffer;
  read_buffer_s read_buffer;
  location_s *read_loc;
  location_s *user_loc;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure curl_multi_s
 */
struct curl_multi_s
{
  CURLM *curlm_ptr;
  location_s *callback_dlg;
  fd_flags_rb_tree_s poll_fds;
  pointer_list_s curl_list;
  long long int unique_counter;

  static int socket_callback(CURL *easy,curl_socket_t socket,int what,void *userp,void *socketp);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure curl_multi_request_s
 */
struct curl_multi_request_s
{
  location_s *curl_multi_loc;
  unsigned index;
  long long int unique_id;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure curl_result_s
 */
struct curl_result_s
{
  CURL *curl_ptr;
  location_s *data_loc;
  location_s *user_loc;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class curl_c
 */
class curl_c
{
  public:
  inline curl_c();
  inline ~curl_c();
};

/*
 * definition of global functions
 */

size_t cb_write_null(void *ptr,size_t size,size_t nmemb,void *stream);
size_t cb_write_buffer(void *ptr,size_t size,size_t nmemb,void *stream);
size_t cb_read_buffer(void *ptr,size_t size,size_t nmemb,void *stream);

/*
 * inline methods of structure read_buffer_s
 */

inline void read_buffer_s::init(const void *a_data_ptr,unsigned a_data_size)
{/*{{{*/
  data_ptr = a_data_ptr;
  data_size = a_data_size;
  index = 0;
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- fd_flags_s --
@begin
inlines fd_flags_s
@end

// -- fd_flags_rb_tree_s --
@begin
inlines fd_flags_rb_tree_s
@end

inline int fd_flags_rb_tree_s::__compare_value(fd_flags_s &a_first,fd_flags_s &a_second)
{/*{{{*/
  return a_first.fd < a_second.fd ? -1 : a_first.fd > a_second.fd ? 1 : 0;
}/*}}}*/

/*
 * inline methods of structure curl_props_s
 */

inline void curl_props_s::init()
{/*{{{*/
  curl_ptr = nullptr;
  headers = nullptr;
  write_buffer.init();
  read_loc = nullptr;
  user_loc = nullptr;
}/*}}}*/

inline void curl_props_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release curl_ptr -
  if (curl_ptr != nullptr)
  {
    curl_easy_cleanup(curl_ptr);
  }

  // - release headers list -
  if (headers != nullptr)
  {
    curl_slist_free_all(headers);
  }

  write_buffer.clear();

  // - release read data location -
  if (read_loc != nullptr)
  {
    it.release_location_ptr(read_loc);
  }

  // - release user data location -
  if (user_loc != nullptr)
  {
    it.release_location_ptr(user_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure curl_multi_s
 */

inline void curl_multi_s::init()
{/*{{{*/
  curlm_ptr = nullptr;
  callback_dlg = nullptr;;
  poll_fds.init();
  curl_list.init();
  unique_counter = 0;
}/*}}}*/

inline void curl_multi_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release all running curl transactions -
  if (curl_list.first_idx != c_idx_not_exist)
  {
    unsigned curl_idx = curl_list.first_idx;
    do {
      CURL *curl_ptr = (CURL *)curl_list[curl_idx];

      // - retrieve curl properties -
      curl_props_s *curl_props;
      curl_easy_getinfo(curl_ptr,CURLINFO_PRIVATE,(char **)&curl_props);

      // - remove curl easy from multi -
      curl_multi_remove_handle(curlm_ptr,curl_ptr);

      // - release curl properties -
      curl_props->clear(it);
      cfree(curl_props);

      curl_idx = curl_list.next_idx(curl_idx);
    } while(curl_idx != c_idx_not_exist);
  }

  curl_list.clear();

  // - cleanup curl multi -
  if (curlm_ptr != nullptr)
  {
    curl_multi_cleanup(curlm_ptr);
  }

  // - release callback delegate -
  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  poll_fds.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure curl_multi_request_s
 */

inline void curl_multi_request_s::init()
{/*{{{*/
  curl_multi_loc = nullptr;
}/*}}}*/

inline void curl_multi_request_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release curl_multi location -
  if (curl_multi_loc != nullptr)
  {
    it.release_location_ptr(curl_multi_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure curl_result_s
 */

inline void curl_result_s::init()
{/*{{{*/
  curl_ptr = nullptr;
  data_loc = nullptr;
  user_loc = nullptr;
}/*}}}*/

inline void curl_result_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release curl_ptr -
  if (curl_ptr != nullptr)
  {
    curl_easy_cleanup(curl_ptr);
  }

  // - release result data location -
  if (data_loc != nullptr)
  {
    it.release_location_ptr(data_loc);
  }

  // - release user data location -
  if (user_loc != nullptr)
  {
    it.release_location_ptr(user_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of class curl_c
 */

inline curl_c::curl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"curl_init()\n"););

  curl_global_init(CURL_GLOBAL_ALL);
}/*}}}*/

inline curl_c::~curl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"curl_exit()\n"););

  curl_global_cleanup();
}/*}}}*/

#endif

