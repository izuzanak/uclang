
#ifndef __UCL_WEBSOCKET_H
#define __UCL_WEBSOCKET_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <poll.h>
#endif

#include <libwebsockets.h>

/*

XXX:

- Uvolneni objektu WsClient v zadnem pripade neukoncuje klientske websocketove
  spojeni. Toto se spravne musi ukoncit zaslanim zpravy close v ramci samotneho
  websocketoveho spojeni.
- V kazdem jednom zapisovacim callbacku (CB_CLIENT_WRITEABLE,
  CB_SERVER_WRITEABLE) muze byt zapsana prave jedna zprava pro odeslani.

 */

/*
 * constants and definitions
 */

// - websocket default extensions -
extern const lws_extension ws_default_extensions[];

extern unsigned c_bi_class_ws_conn;

/*
 * definition of generated structures
 */

// -- fd_flags_s --
@begin
struct
<
int:fd
int:flags
>
fd_flags_s;
@end

// -- fd_flags_rb_tree_s --
@begin
rb_tree<fd_flags_s> fd_flags_rb_tree_s;
@end

/*
 * definition of structure ws_context_s
 */

struct ws_context_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  lws_context *context;
  lws_protocols *protocols;
  location_s *user_data_ptr;

  string_array_s prot_names;
  pointer_array_s prot_dlgs;

  fd_flags_rb_tree_s poll_fds;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline unsigned get_protocol_idx(lws *a_wsi);
};

/*
 * definition of structure ws_conn_s
 */

struct ws_conn_s
{
  ws_context_s *wsc_ptr;
  unsigned prot_idx;
  lws *ws_ptr;
  location_s *user_data_ptr;
  lws_callback_reasons reason;
  bc_array_s message_buffer;
  bc_array_s data_buffer;
  void *data_in;
  size_t data_len;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ws_client_s
 */

struct ws_client_s
{
  location_s *wsc_location;
  lws *ws_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class websocket_c
 */
class websocket_c
{
  public:
  inline websocket_c();
  inline ~websocket_c();
};

/*
 * definition of global functions
 */

void log_emit(int level,const char *line);

int http_func(lws *wsi,enum lws_callback_reasons reason,void *user,void *in,size_t len);

int protocol_func(lws *wsi,enum lws_callback_reasons reason,void *user,void *in,size_t len);

/*
 * definition of base64 decode functions
 */

typedef enum
{/*{{{*/
  step_a, step_b, step_c, step_d
}/*}}}*/
base64_decodestep;

typedef struct
{/*{{{*/
  base64_decodestep step;
  char plainchar;
}/*}}}*/
base64_decodestate;

void base64_init_decodestate(base64_decodestate* state_in);
int base64_decode_value(int value_in);
int base64_decode_block(const char* code_in, const int length_in, char* plaintext_out, base64_decodestate* state_in);

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
 * inline methods of structure ws_context_s
 */

inline void ws_context_s::init()
{/*{{{*/
  it_ptr = nullptr;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  context = nullptr;
  protocols = nullptr;
  user_data_ptr = nullptr;

  prot_names.init();
  prot_dlgs.init();

  poll_fds.init();
}/*}}}*/

inline void ws_context_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - destroy websocket context -
  if (context != nullptr)
  {
    lws_context_destroy(context);
  }

  // - release protocols -
  if (protocols != nullptr)
  {
    cfree(protocols);
  }

  // - release user data location -
  if (user_data_ptr != nullptr)
  {
    it.release_location_ptr(user_data_ptr);
  }

  prot_names.clear();

  // - release websocket protocols delegates -
  if (prot_dlgs.used != 0)
  {
    pointer *d_ptr = prot_dlgs.data;
    pointer *d_ptr_end = d_ptr + prot_dlgs.used;
    do {
      it.release_location_ptr((location_s *)*d_ptr);
    } while(++d_ptr < d_ptr_end);
  }

  prot_dlgs.clear();
  poll_fds.clear();

  init();
}/*}}}*/

inline unsigned ws_context_s::get_protocol_idx(lws *a_wsi)
{/*{{{*/

  // - retrieve websocket protocol -
  const lws_protocols *protocol = lws_get_protocol(a_wsi);

  return prot_names.get_idx_char_ptr(strlen(protocol->name),protocol->name);
}/*}}}*/

/*
 * inline methods of structure ws_conn_s
 */

inline void ws_conn_s::init()
{/*{{{*/
  wsc_ptr = nullptr;
  prot_idx = c_idx_not_exist;
  ws_ptr = nullptr;
  user_data_ptr = nullptr;
  message_buffer.init();
  data_buffer.init();
  data_in = nullptr;
  data_len = 0;
}/*}}}*/

inline void ws_conn_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release user data location -
  if (user_data_ptr != nullptr)
  {
    it.release_location_ptr(user_data_ptr);
  }

  message_buffer.clear();
  data_buffer.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure ws_client_s
 */

inline void ws_client_s::init()
{/*{{{*/
  wsc_location = nullptr;
  ws_ptr = nullptr;
}/*}}}*/

inline void ws_client_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release websocket context -
  if (wsc_location != nullptr)
  {
    it.release_location_ptr(wsc_location);
  }

  init();
}/*}}}*/

/*
 * inline methods of class websocket_c
 */

inline websocket_c::websocket_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"websocket_init()\n"););

  lws_set_log_level(9,log_emit);
}/*}}}*/

inline websocket_c::~websocket_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"websocket_exit()\n"););
}/*}}}*/

#endif

