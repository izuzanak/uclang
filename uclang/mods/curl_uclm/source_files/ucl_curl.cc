
@begin
include "ucl_curl.h"
@end

// - curl global init object -
curl_c g_curl;

/*
 * methods of generated structures
 */

// -- fd_flags_s --
@begin
methods fd_flags_s
@end

// -- fd_flags_rb_tree_s --
@begin
methods fd_flags_rb_tree_s
@end

/*
 * methods of structure curl_multi_s
 */

int curl_multi_s::socket_callback(CURL *easy,curl_socket_t socket,int what,void *userp,void *socketp)
{/*{{{*/
  fd_flags_rb_tree_s &poll_fds = ((curl_multi_s *)userp)->poll_fds;
  fd_flags_s fd_flags = {socket,0};

  switch (what)
  {

  // - set poll fd -
  case CURL_POLL_IN:
  case CURL_POLL_OUT:
  case CURL_POLL_INOUT:
    {
      switch (what)
      {
      case CURL_POLL_IN:
        fd_flags.flags = POLLIN | POLLPRI;
        break;
      case CURL_POLL_OUT:
        fd_flags.flags = POLLOUT;
        break;
      case CURL_POLL_INOUT:
        fd_flags.flags = POLLIN | POLLPRI | POLLOUT;
        break;
      }

      unsigned ff_idx = poll_fds.get_idx(fd_flags);
      if (ff_idx != c_idx_not_exist)
      {
        poll_fds[ff_idx].flags = fd_flags.flags;
      }
      else
      {
        poll_fds.insert(fd_flags);
      }
    }
    break;

  // - remove poll fd -
  case CURL_POLL_REMOVE:
    {
      unsigned ff_idx = poll_fds.get_idx(fd_flags);
      cassert(ff_idx != c_idx_not_exist);

      poll_fds.remove(ff_idx);
    }
    break;
  }

  return 0;
}/*}}}*/

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

