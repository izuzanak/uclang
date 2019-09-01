
@begin
include "ucl_channel.h"
@end

/*
 * methods of generated structures
 */

// -- fd_conn_map_s --
@begin
methods fd_conn_map_s
@end

// -- fd_conn_map_tree_s --
@begin
methods fd_conn_map_tree_s
@end

// -- channel_conn_s --
@begin
methods channel_conn_s
@end

// -- channel_conn_list_s --
@begin
methods channel_conn_list_s
@end

// -- channel_server_s --
@begin
methods channel_server_s
@end

bool channel_server_s::create(const string_s &a_ip,unsigned short a_port,
    location_s *a_new_callback,
    location_s *a_drop_callback,
    location_s *a_message_callback,
    location_s *a_user_data)
{/*{{{*/
  debug_assert(server_fd == -1);

  sockaddr_in address;

  // - retrieve host by name address -
  struct hostent *host = gethostbyname(a_ip.data);

  // - ERROR -
  if (host == NULL)
  {
    return false;
  }

  memcpy(&address.sin_addr.s_addr,host->h_addr,host->h_length);
  address.sin_port = htons(a_port);
  address.sin_family = AF_INET;

  // - create socket -
  server_fd = socket(AF_INET,SOCK_STREAM,0);

  // - ERROR -
  if (server_fd == -1)
  {
    return false;
  }

  // - set server socket as reusable -
  int yes = 1;
  setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

  // - ERROR -
  if (bind(server_fd,(struct sockaddr *)&address,sizeof(struct sockaddr_in)) != 0)
  {
    close(server_fd);

    return false;
  }

  // - ERROR -
  if (listen(server_fd,256) != 0)
  {
    close(server_fd);

    return false;
  }

  // - retrieve callbacks -
  a_new_callback->v_reference_cnt.atomic_inc();
  new_callback = a_new_callback;

  a_drop_callback->v_reference_cnt.atomic_inc();
  drop_callback = a_drop_callback;

  a_message_callback->v_reference_cnt.atomic_inc();
  message_callback = a_message_callback;

  // - retrieve user data -
  a_user_data->v_reference_cnt.atomic_inc();
  user_data = a_user_data;

  return true;
}/*}}}*/

