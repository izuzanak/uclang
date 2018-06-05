
@begin
include "ucl_crypto.h"
@end

// - crypto global init object -
crypto_c g_crypto;

/*
 * methods of structure crypto_pkey_s
 */

int crypto_pkey_s::password_cb(char *buf,int size,int rwflag,void *userdata)
{/*{{{*/
  string_s *string_ptr = (string_s *)userdata;

  unsigned passwd_size = (unsigned)size < string_ptr->size ? size : string_ptr->size - 1;
  memcpy(buf,string_ptr->data,passwd_size*sizeof(char));

  return passwd_size;
}/*}}}*/

