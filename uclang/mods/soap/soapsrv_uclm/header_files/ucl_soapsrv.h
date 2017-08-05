
#ifndef __UCL_SOAPSRV_H
#define __UCL_SOAPSRV_H

@begin
include "script_parser.h"
@end

#include "soapH.h"

// - basic definitions and constants -

const unsigned c_soap_error_string_size = 2048;

// - indexes of built in classes -
extern unsigned c_bi_class_soap_fault;

/*
 * definition of structure soap_env_s
 */

struct soap_env_s
{
  struct soap *soap_ptr;
  int socket;

  interpreter_thread_s *it_ptr;
  unsigned proc_source_pos;
  unsigned proc_ret_code;

  location_s *ns__add_dlg;
  location_s *ns__sub_dlg;
  location_s *ns__sqrt_dlg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure soap_fault_s
 */

struct soap_fault_s
{
  location_s *string_ptr;
  location_s *detail_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure soap_env_s
 */

inline void soap_env_s::init()
{/*{{{*/
  soap_ptr = nullptr;
  socket = -1;

  it_ptr = nullptr;
  proc_source_pos = 0;
  proc_ret_code = c_run_return_code_OK;

  ns__add_dlg = nullptr;
  ns__sub_dlg = nullptr;
  ns__sqrt_dlg = nullptr;
}/*}}}*/

inline void soap_env_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release soap pointer -
  if (soap_ptr != nullptr)
  {
    soap_end(soap_ptr);
    soap_done(soap_ptr);
    free(soap_ptr);
  }

#define RELEASE_DELEGATE(DELEGATE) \
{/*{{{*/\
  if (DELEGATE != nullptr)\
  {\
    it.release_location_ptr(DELEGATE);\
  }\
}/*}}}*/

  RELEASE_DELEGATE(ns__add_dlg);
  RELEASE_DELEGATE(ns__sub_dlg);
  RELEASE_DELEGATE(ns__sqrt_dlg);

  init();
}/*}}}*/

/*
 * inline methods of structure soap_fault_s
 */

inline void soap_fault_s::init()
{/*{{{*/
  string_ptr = nullptr;
  detail_ptr = nullptr;
}/*}}}*/

inline void soap_fault_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release string pointer -
  if (string_ptr != nullptr)
  {
    it.release_location_ptr(string_ptr);
  }

  // - release detail pointer -
  if (detail_ptr != nullptr)
  {
    it.release_location_ptr(detail_ptr);
  }
}/*}}}*/

#endif

