
#ifndef __UCL_CURL_H
#define __UCL_CURL_H

@begin
include "script_parser.h"
@end

#include <curl/curl.h>

/*
 * definition of structure read_buffer_s
 */
struct read_buffer_s
{
  string_s *string_ptr;
  unsigned index;

  inline void init(string_s &a_string);
};

/*
 * definition of structure curl_result_s
 */
struct curl_result_s
{
  CURL *curl_ptr;
  location_s *data_ptr;

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

inline void read_buffer_s::init(string_s &a_string)
{/*{{{*/
  string_ptr = &a_string;
  index = 0;
}/*}}}*/

/*
 * inline methods of structure curl_result_s
 */

inline void curl_result_s::init()
{/*{{{*/
  curl_ptr = NULL;
  data_ptr = NULL;
}/*}}}*/

inline void curl_result_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release curl_ptr -
  if (curl_ptr != NULL)
  {
    curl_easy_cleanup(curl_ptr);
  }

  // - release result data -
  if (data_ptr != NULL)
  {
    it.release_location_ptr(data_ptr);
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

