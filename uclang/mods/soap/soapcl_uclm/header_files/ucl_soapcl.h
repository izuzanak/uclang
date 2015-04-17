
#ifndef __UCL_SOAPCL_H
#define __UCL_SOAPCL_H

@begin
include "script_parser.h"
@end

#include "soapH.h"

// - basic definitions and constants -

const unsigned c_soap_error_string_size = 2048;

/*
 * definition of structure soap_env_s
 */

struct soap_env_s
{
  struct soap *soap_ptr;
  location_s *endpoint_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure soap_env_s
 */

inline void soap_env_s::init()
{/*{{{*/
  soap_ptr = NULL;
  endpoint_ptr = NULL;
}/*}}}*/

inline void soap_env_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release soap pointer -
  if (soap_ptr != NULL)
  {
    soap_end(soap_ptr);
    soap_done(soap_ptr);
    free(soap_ptr);
  }

  // - release endpoint location -
  if (endpoint_ptr != NULL)
  {
    it.release_location_ptr(endpoint_ptr);
  }

  init();
}/*}}}*/

#endif

