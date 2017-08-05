
#ifndef __UCL_NACL_H
#define __UCL_NACL_H

@begin
include "script_parser.h"
include "nacl.h"
@end

#include "ppapi/c/ppb_var.h"
#include "ppapi/c/ppb_core.h"
#include "ppapi/c/ppb_console.h"
#include "ppapi/c/ppb_messaging.h"
#include "ppapi/c/ppb_net_address.h"
#include "ppapi/c/ppb_tcp_socket.h"
#include "ppapi/c/ppb_graphics_3d.h"

#include "ppapi/lib/gl/gles2/gl2ext_ppapi.h"

// - global nacl related variables -
extern PP_Instance pp_inst;
extern PPB_GetInterface ppb_get_iface;

// - nacl interpreter thread pointer -
extern interpreter_thread_s *nacl_it_ptr;

// - nacl instance callback delegates -
extern location_s *nacl_destroy_dlg;
extern location_s *nacl_change_view_dlg;
extern location_s *nacl_change_focus_dlg;

// - nacl related variables -
extern PPB_Var *ppb_var_iface;
extern PPB_Core *ppb_core_iface;
extern PPB_Instance *ppb_inst_iface;
extern PPB_Console *ppb_console_iface;
extern PPB_Messaging *ppb_message_iface;
extern PPB_NetAddress *ppb_net_addr_iface;
extern PPB_TCPSocket *ppb_tcp_socket_iface;
extern PPB_Graphics3D *ppb_graphics_3d_iface;

// - nacl graphics 3d context -
extern PP_Resource pp_3d_context;

// - time value conversion definitions -

#define TIME_DOUBLE_TO_NANOSEC(DOUBLE,NANOSEC) \
{/*{{{*/\
  NANOSEC = (long long unsigned)DOUBLE;\
  NANOSEC = NANOSEC*1000000000ULL + (long long unsigned)((DOUBLE - NANOSEC)*1000000000.0);\
}/*}}}*/

#define TIME_NANOSEC_TO_DOUBLE(NANOSEC,DOUBLE) \
{/*{{{*/\
  DOUBLE = NANOSEC/1000000000ULL + (NANOSEC%1000000000ULL)/1000000000.0;\
}/*}}}*/

// - basic PP handle definitions -

#define PP_FROM_STRING(STRING_PTR,PP_VAR) \
{/*{{{*/\
  PP_VAR = ppb_var_iface->VarFromUtf8((STRING_PTR)->data,(STRING_PTR)->size - 1);\
}/*}}}*/

#define PP_TO_STRING(PP_VAR,STRING_PTR) \
{/*{{{*/\
  unsigned length;\
  const char *data = ppb_var_iface->VarToUtf8(PP_VAR,&length);\
  STRING_PTR->set(length,data);\
}/*}}}*/

#define PP_STRING_FWRITE(PP_VAR,STREAM) \
{/*{{{*/\
  unsigned length;\
  const char *data = ppb_var_iface->VarToUtf8(PP_VAR,&length);\
  fwrite(data,length,1,STREAM);\
}/*}}}*/

#define PP_RELEASE(PP_VAR) \
  ppb_var_iface->Release(PP_VAR)

/*
 * definition of structure callback_data_s
 */

struct callback_data_s
{
  location_s *delegate_ptr;
  location_s *user_data_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class nacl_c
 */
class nacl_c
{
  public:
  inline nacl_c();
  inline ~nacl_c();
};

/*
 * definition of global functions
 */

void on_completion_callback(void *user_data,int result);

/*
 * inline methods of structure callback_data_s
 */

inline void callback_data_s::init()
{/*{{{*/
  delegate_ptr = nullptr;
  user_data_ptr = nullptr;
}/*}}}*/

inline void callback_data_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (delegate_ptr != nullptr)
  {
    it.release_location_ptr(delegate_ptr);
  }

  if (user_data_ptr != nullptr)
  {
    it.release_location_ptr(user_data_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class nacl_c
 */

inline nacl_c::nacl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"nacl_init()\n"););

  // - retrieve nacl related variables -
  ppb_var_iface = (PPB_Var*)(ppb_get_iface(PPB_VAR_INTERFACE));
  ppb_core_iface = (PPB_Core *)(ppb_get_iface(PPB_CORE_INTERFACE));
  ppb_inst_iface = (PPB_Instance *)(ppb_get_iface(PPB_INSTANCE_INTERFACE));
  ppb_console_iface = (PPB_Console*)(ppb_get_iface(PPB_CONSOLE_INTERFACE));
  ppb_message_iface = (PPB_Messaging*)(ppb_get_iface(PPB_MESSAGING_INTERFACE));
  ppb_net_addr_iface = (PPB_NetAddress *)(ppb_get_iface(PPB_NETADDRESS_INTERFACE));
  ppb_tcp_socket_iface = (PPB_TCPSocket *)(ppb_get_iface(PPB_TCPSOCKET_INTERFACE));
  ppb_graphics_3d_iface = (PPB_Graphics3D *)(ppb_get_iface(PPB_GRAPHICS_3D_INTERFACE));

}/*}}}*/

inline nacl_c::~nacl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"nacl_exit()\n"););
}/*}}}*/

#endif

