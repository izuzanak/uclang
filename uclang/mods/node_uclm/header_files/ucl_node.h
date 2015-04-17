
#ifndef __UCL_NODE_H
#define __UCL_NODE_H

@begin
include "ucl_libnode.h"
@end

// - maximal callback parameters count -
const unsigned c_node_callback_max_param = 2;

/*
 * definition of structure node_callback_s
 */
struct node_callback_s
{
  void *callback_ptr;
  unsigned param_cnt;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure node_callback_s
 */

inline void node_callback_s::init()
{/*{{{*/
  callback_ptr = NULL;
  param_cnt = 0;
}/*}}}*/

inline void node_callback_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

