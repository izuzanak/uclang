
#ifndef __UCL_PAM_H
#define __UCL_PAM_H

@begin
include "script_parser.h"
@end

#include <security/pam_appl.h>

/*
 * definition of structure pam_s
 */

struct pam_s
{
  static int conversation_fun(int num_msg,const struct pam_message **msg, struct pam_response **resp,void *appdata_ptr);
  static bool authenticate(const char *a_service_name, const char *a_user,const char *a_pass);
};

/*
 * inline methods of structure pam_s
 */

#endif

