
@begin
include "nacl.h"
@end

#if SYSTEM_TYPE_UNIX_CHROME_NACL == ENABLED

// - global nacl related variables -
PP_Instance pp_inst = 0;
PPB_GetInterface ppb_get_iface = NULL;

// - nacl interpreter thread pointer -
interpreter_thread_s *nacl_it_ptr = NULL;

// - nacl instance callback delegates -
location_s *nacl_destroy_dlg = NULL;
location_s *nacl_change_view_dlg = NULL;
location_s *nacl_change_focus_dlg = NULL;

#endif

