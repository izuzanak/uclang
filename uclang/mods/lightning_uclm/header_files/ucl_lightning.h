
#ifndef __UCL_LIGHTNING_H
#define __UCL_LIGHTNING_H

@begin
include "lightning_parser.h"
@end

/*
 * definition of structure jit_state_s
 */

struct jit_state_s
{
  pointer_array_s jit_states;
  string_rb_tree_s ucl_signatures;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class lightning_c
 */
class lightning_c
{
  public:
  inline lightning_c();
  inline ~lightning_c();
};

/*
 * inline methods of structure jit_state_s
 */

inline void jit_state_s::init()
{/*{{{*/
  jit_states.init();
  ucl_signatures.init();
}/*}}}*/

inline void jit_state_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - destroy all jit states -
  if (jit_states.used != 0)
  {
    pointer *js_ptr = jit_states.data;
    pointer *js_ptr_end = js_ptr + jit_states.used;
    do {
      jit_state_t *_jit = (jit_state_t *)*js_ptr;
      jit_destroy_state();
    } while(++js_ptr < js_ptr_end);
  }

  jit_states.clear();
  ucl_signatures.clear();

  init();
}/*}}}*/

/*
 * inline methods of class lightning_c
 */

inline lightning_c::lightning_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"lightning_init()\n"););

  // - initialize lightning -
  init_jit((char *)"uclang");
}/*}}}*/

inline lightning_c::~lightning_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"lightning_exit()\n"););

  // - finish lightning -
  finish_jit();
}/*}}}*/

#endif

