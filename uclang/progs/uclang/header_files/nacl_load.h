
#ifndef __NACL_LOAD_H
#define __NACL_LOAD_H

@begin
include "script_parser.h"
include "nacl.h"
@end

#if SYSTEM_TYPE_UNIX_CHROME_NACL == ENABLED

// - global nacl related variables -
extern PP_Instance pp_inst;
extern PPB_GetInterface ppb_get_iface;

// - nacl interpreter thread pointer -
extern interpreter_thread_s *nacl_it_ptr;

// - nacl instance callback delegates -
extern location_s *nacl_destroy_dlg;
extern location_s *nacl_change_view_dlg;
extern location_s *nacl_change_focus_dlg;

// - dummy nacl arguments -
const int c_argc = 3;
const char *c_argv[c_argc] = {"main","-mods=/http/ucl","/http/ucl/test.ucl"};
const pointer c_mt_start_info[2] = {(pointer)c_argc,(pointer)c_argv};

#endif

#endif

