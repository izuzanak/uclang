
#ifndef __UCL_RUBY_H
#define __UCL_RUBY_H

@begin
include "script_parser.h"
@end

#include <ruby.h>

/*
 * constants and definitions
 */

extern unsigned c_bi_class_ruby_value;
extern unsigned c_rm_class_dict;

/*
 * definition of class ruby_c
 */
class ruby_c
{
  public:
  inline ruby_c();
  inline ~ruby_c();
};

/*
 * inline methods of class ruby_c
 */

inline ruby_c::ruby_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ruby_init()\n"););

  ruby_init();
  ruby_script("uclang");
  ruby_init_loadpath();
}/*}}}*/

inline ruby_c::~ruby_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ruby_exit()\n"););

  ruby_cleanup(0);
}/*}}}*/

#endif

