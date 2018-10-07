
#ifndef __UCL_UCTRNDB_H
#define __UCL_UCTRNDB_H

@begin
include "script_parser.h"
@end

// - redefined in trndb.h -
#undef nullptr

#include "ucf2.h"
#include <trndb.h>

/*
 * definition of structure trndb_proxy_s
 */

struct trndb_proxy_s
{
  static trndb_proxy_s *g_proxy_ptr;

  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  TrnDb::OpTrnDbProxy proxy;
  location_s *callback_dlg;

  static void trndb_changed(int events);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure trndb_proxy_s
 */

inline void trndb_proxy_s::init()
{/*{{{*/
  it_ptr = nullptr;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  callback_dlg = nullptr;
}/*}}}*/

inline void trndb_proxy_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - reset trndb proxy global pointer -
  if (g_proxy_ptr == this)
  {
    g_proxy_ptr = nullptr;
  }

  // - release callback delegate -
  if (callback_dlg != nullptr)
  {
    it.release_location_ptr(callback_dlg);
  }

  init();
}/*}}}*/

#endif

