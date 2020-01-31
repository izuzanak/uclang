
#ifndef __UCL_OPENSSL_H
#define __UCL_OPENSSL_H

@begin
include "script_parser.h"
@end

#include <openssl/ssl.h>
#include <openssl/err.h>

/*
 * constants and definitions
 */

// - ssl context method types -
enum
{
  c_ssl_ctx_method_server = 0,
  c_ssl_ctx_method_client,
};

/*
 * definition of class openssl_c
 */

class openssl_c
{
  public:
  inline openssl_c();
  inline ~openssl_c();
};

/*
 * inline methods of class openssl_c
 */

inline openssl_c::openssl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"openssl_init()\n"););

  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();
}/*}}}*/

inline openssl_c::~openssl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"openssl_exit()\n"););

  EVP_cleanup();
}/*}}}*/

#endif

