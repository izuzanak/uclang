
#ifndef __UCL_JIT_H
#define __UCL_JIT_H

@begin
include "jit_parser.h"
@end

/*
 * definition of structure jit_context_s
 */

struct jit_context_s
{
  jit_context_t context;

  string_rb_tree_s ucl_signatures;
  string_rb_tree_s fun_names;
  fun_records_s fun_records;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure jit_function_s
 */

struct jit_function_s
{
  location_s *jc_ptr;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure jit_context_s
 */

inline void jit_context_s::init()
{/*{{{*/
  context = nullptr;

  ucl_signatures.init();
  fun_names.init();
  fun_records.init();
}/*}}}*/

inline void jit_context_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release jit context -
  if (context != nullptr)
  {
    jit_context_destroy(context);
  }

  ucl_signatures.clear();
  fun_names.clear();
  fun_records.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure jit_function_s
 */

inline void jit_function_s::init()
{/*{{{*/
  jc_ptr = nullptr;
}/*}}}*/

inline void jit_function_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release jit context pointer -
  if (jc_ptr != nullptr)
  {
    it.release_location_ptr(jc_ptr);
  }

  init();
}/*}}}*/

#endif

