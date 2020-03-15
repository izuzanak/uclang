
@begin
include "ucl_pam.h"
@end

/*
 * methods of structure pam_s
 */

int pam_s::conversation_fun(int num_msg,const struct pam_message **msg,struct pam_response **resp,void *appdata_ptr)
{/*{{{*/
  *resp = *((struct pam_response **)appdata_ptr);

  return PAM_SUCCESS;
}/*}}}*/

bool pam_s::authenticate(const char *a_service_name,const char *a_user,const char *a_pass)
{/*{{{*/
  struct pam_response *response;
  const struct pam_conv conversation = {pam_s::conversation_fun,&response};

  pam_handle_t *handle = NULL;
  if (pam_start(a_service_name,a_user,&conversation,&handle) != PAM_SUCCESS)
  {
    return false;
  }

  response = (pam_response *)malloc(sizeof(struct pam_response));
  response->resp = strdup(a_pass);
  response->resp_retcode = 0;

  int auth_res = pam_authenticate(handle,0);

  if (pam_end(handle,auth_res) != PAM_SUCCESS)
  {
    return false;
  }

  if (auth_res != PAM_SUCCESS)
  {
    return false;
  }

  return true;
}/*}}}*/

