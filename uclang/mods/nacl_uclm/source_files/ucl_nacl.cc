
@begin
include "ucl_nacl.h"
@end

// - nacl global init object -
nacl_c g_nacl;

// - nacl related variables -
PPB_Var* ppb_var_iface = NULL;
PPB_Core *ppb_core_iface = NULL;
PPB_Instance *ppb_inst_iface = NULL;
PPB_Console* ppb_console_iface = NULL;
PPB_Messaging* ppb_message_iface = NULL;
PPB_NetAddress *ppb_net_addr_iface = NULL;
PPB_TCPSocket *ppb_tcp_socket_iface = NULL;
PPB_Graphics3D *ppb_graphics_3d_iface = NULL;

// - nacl graphics 3d context -
PP_Resource pp_3d_context = 0;

/*
 * global functions
 */

void on_completion_callback(void *user_data,int result)
{/*{{{*/

  // - retrieve callback data object -
  callback_data_s *cd_ptr = (callback_data_s *)user_data;

  // - call callback delegate method -
  NACL_CALL_CALLBACK_DELEGATE(cd_ptr->delegate_ptr,param_data,param_cnt,

    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&cd_ptr->user_data_ptr;
  );

  // - release callback data object -
  cd_ptr->clear(*nacl_it_ptr);
  cfree(cd_ptr);
}/*}}}*/

