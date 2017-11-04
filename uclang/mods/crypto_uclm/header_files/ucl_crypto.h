
#ifndef __UCL_CRYPTO_H
#define __UCL_CRYPTO_H

@begin
include "script_parser.h"
@end

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>

const char c_base16_map[] = "0123456789abcdef";

/*
 * definition of class crypto_c
 */
class crypto_c
{
  public:
  inline crypto_c();
  inline ~crypto_c();
};

/*
 * definition of structure crypto_digest_s
 */

struct crypto_digest_s
{
  EVP_MD_CTX *md_ctx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of class crypto_c
 */

inline crypto_c::crypto_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcrypto_init()\n"););

  ERR_load_crypto_strings();
  OpenSSL_add_all_algorithms();
  OPENSSL_config(nullptr);
}/*}}}*/

inline crypto_c::~crypto_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcrypto_exit()\n"););

  EVP_cleanup();
  CRYPTO_cleanup_all_ex_data();
  ERR_free_strings();
}/*}}}*/

/*
 * inline methods of structure crypto_digest_s
 */

inline void crypto_digest_s::init()
{/*{{{*/
  md_ctx = nullptr;
}/*}}}*/

inline void crypto_digest_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypt digest md_ctx -
  if (md_ctx != nullptr)
  {
    EVP_MD_CTX_destroy(md_ctx);
  }

  init();
}/*}}}*/

#endif

