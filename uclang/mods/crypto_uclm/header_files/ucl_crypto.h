
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
#include <openssl/bn.h>

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
#include <openssl/param_build.h>
#include <openssl/core_names.h>
#include <openssl/kdf.h>
#else
#include <openssl/rsa.h>
#endif

// - replace deprecated function -
#if OPENSSL_VERSION_MAJOR >= 3
#define EVP_MD_CTX_MD EVP_MD_CTX_get0_md
#else
#define EVP_MD_CTX_MD EVP_MD_CTX_md
#endif

USED const char c_base16_map[] = "0123456789abcdef";

/*
 * definition of class crypto_c
 */

class crypto_c
{
  public:
  inline crypto_c() noexcept;
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

#if OPENSSL_VERSION_NUMBER >= 0x30000000L

// - kdf algorithm identifiers -
enum
{/*{{{*/
  c_crypto_kdf_argon2id = 0,
  c_crypto_kdf_scrypt,
  c_crypto_kdf_pbkdf2,
  c_crypto_kdf_count,
};/*}}}*/

// - kdf algorithm names (indexed by identifier above) -
extern const char *c_crypto_kdf_names[];

/*
 * definition of structure crypto_kdf_param_s
 */

// - description of one kdf parameter read from parameter array -
//   name is the array key, value is either String or positive Integer -
struct crypto_kdf_param_s
{
  const char *name;
  bool required;
  bool is_string;
  bool seen;
  long long int ival;
  string_s *sval;
};

/*
 * definition of structure crypto_kdf_s
 */

struct crypto_kdf_s
{
  // - resolve algorithm identifier from its name, returns -1 for unknown or compiled-out names -
  static int algorithm_idx(string_s &a_name);

  // - read parameters from array of interleaved names and values, on error set a_bad_name and return false -
  static bool read_params(interpreter_thread_s &it,location_s *a_array_location,
      crypto_kdf_param_s *a_params,unsigned a_count,const char **a_bad_name);

  // - retrieve last openssl error reason as c string -
  static const char *error_reason();
};

#endif

/*
 * inline methods of class crypto_c
 */

inline crypto_c::crypto_c() noexcept
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

