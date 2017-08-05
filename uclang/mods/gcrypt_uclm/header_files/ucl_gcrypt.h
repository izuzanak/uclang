
#ifndef __UCL_GCRYPT_H
#define __UCL_GCRYPT_H

@begin
include "script_parser.h"
@end

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include "gcrypt.h"
#pragma GCC diagnostic warning "-Wdeprecated-declarations"

/*
 * definition of structure gcrypt_cipher_s
 */

struct gcrypt_cipher_s
{
  gcry_cipher_handle *handle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure gcrypt_cipher_s
 */

inline void gcrypt_cipher_s::init()
{/*{{{*/
  handle = nullptr;
}/*}}}*/

inline void gcrypt_cipher_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release gcrypt cipher handle -
  if (handle != nullptr)
  {
    gcry_cipher_close(handle);
  }

  init();
}/*}}}*/

#endif

