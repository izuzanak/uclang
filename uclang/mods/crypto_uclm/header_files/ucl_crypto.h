
#ifndef __UCL_CRYPTO_H
#define __UCL_CRYPTO_H

@begin
include "script_parser.h"
@end

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/opensslv.h>

// - replace deprecated function -
#if OPENSSL_VERSION_MAJOR >= 3
#define EVP_MD_CTX_MD EVP_MD_CTX_get0_md
#else
#define EVP_MD_CTX_MD EVP_MD_CTX_md
#endif

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
 * definition of structure crypto_pkey_s
 */

struct crypto_pkey_s
{
  EVP_PKEY *pkey;
  bool ispub;

  static int password_cb(char *buf,int size,int rwflag,void *userdata);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure crypto_digest_s
 */

struct crypto_digest_s
{
  EVP_MD_CTX *context;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure crypto_digest_key_s
 */

struct crypto_digest_key_s
{
  EVP_MD_CTX *context;
  EVP_PKEY_CTX *pkey_ctx;
  location_s *key_location;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure crypto_cipher_s
 */

struct crypto_cipher_s
{
  EVP_CIPHER_CTX *context;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure crypto_seal_s
 */

struct crypto_seal_s
{
  EVP_CIPHER_CTX *context;
  location_s *keys_location;
  location_s *iv_location;

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
}/*}}}*/

inline crypto_c::~crypto_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcrypto_exit()\n"););

  EVP_cleanup();
  CRYPTO_cleanup_all_ex_data();
  ERR_free_strings();
}/*}}}*/

/*
 * inline methods of structure crypto_pkey_s
 */

inline void crypto_pkey_s::init()
{/*{{{*/
  pkey = nullptr;
}/*}}}*/

inline void crypto_pkey_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto pkey -
  if (pkey != nullptr)
  {
    EVP_PKEY_free(pkey);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure crypto_digest_s
 */

inline void crypto_digest_s::init()
{/*{{{*/
  context = nullptr;
}/*}}}*/

inline void crypto_digest_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto digest context -
  if (context != nullptr)
  {
    EVP_MD_CTX_destroy(context);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure crypto_digest_key_s
 */

inline void crypto_digest_key_s::init()
{/*{{{*/
  context = nullptr;
  key_location = nullptr;
}/*}}}*/

inline void crypto_digest_key_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto digest context -
  if (context != nullptr)
  {
    EVP_MD_CTX_destroy(context);
  }

  // - release key reference -
  if (key_location != nullptr)
  {
    it.release_location_ptr(key_location);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure crypto_cipher_s
 */

inline void crypto_cipher_s::init()
{/*{{{*/
  context = nullptr;
}/*}}}*/

inline void crypto_cipher_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto cipher context -
  if (context != nullptr)
  {
    EVP_CIPHER_CTX_free(context);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure crypto_seal_s
 */

inline void crypto_seal_s::init()
{/*{{{*/
  context = nullptr;
  keys_location = nullptr;
  iv_location = nullptr;
}/*}}}*/

inline void crypto_seal_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto cipher context -
  if (context != nullptr)
  {
    EVP_CIPHER_CTX_free(context);
  }

  // - release keys location -
  if (keys_location != nullptr)
  {
    it.release_location_ptr(keys_location);
  }

  // - release initial vector location -
  if (iv_location != nullptr)
  {
    it.release_location_ptr(iv_location);
  }

  init();
}/*}}}*/

#endif

