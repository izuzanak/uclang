
@begin
include "ucl_curl.h"
@end

// - curl global init object -
curl_c g_curl;

/*
 * flobal functions
 */

size_t cb_write_null(void *ptr,size_t size,size_t nmemb,void *stream)
{/*{{{*/
  return nmemb;
}/*}}}*/

size_t cb_write_buffer(void *ptr,size_t size,size_t nmemb,void *stream)
{/*{{{*/
  bc_array_s *buff_ptr = (bc_array_s *)stream;
  buff_ptr->append(nmemb,(const char *)ptr);

  return nmemb;
}/*}}}*/

size_t cb_read_buffer(void *ptr,size_t size,size_t nmemb,void *stream)
{/*{{{*/
  read_buffer_s *buff_ptr = (read_buffer_s *)stream;
  string_s *string_ptr = buff_ptr->string_ptr;

  unsigned rest_cnt = (string_ptr->size - 1) - buff_ptr->index;

  // - if there are not enough bytes in buffer -
  if (nmemb > rest_cnt)
  {
    // - write rest of bytes -
    if (rest_cnt > 0)
    {
      memcpy(ptr,string_ptr->data + buff_ptr->index,rest_cnt);
      buff_ptr->index += rest_cnt;
    }

    return rest_cnt;
  }

  // - write requested count of bytes -
  memcpy(ptr,string_ptr->data + buff_ptr->index,nmemb);
  buff_ptr->index += nmemb;

  return nmemb;
}/*}}}*/

