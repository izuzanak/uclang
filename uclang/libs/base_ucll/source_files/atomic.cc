
@begin
include "atomic.h"
@end

/*
 * methods of structure atomic_s
 */

extern "C" {

int atomic_s_value(atomic_s *a_this)
{/*{{{*/
  return a_this->value();
}/*}}}*/

void atomic_s_atomic_set(atomic_s *a_this,int a_value)
{/*{{{*/
  a_this->atomic_set(a_value);
}/*}}}*/

void atomic_s_atomic_inc(atomic_s *a_this)
{/*{{{*/
  a_this->atomic_inc();
}/*}}}*/

void atomic_s_atomic_add(atomic_s *a_this,int a_value)
{/*{{{*/
  a_this->atomic_add(a_value);
}/*}}}*/
}

