
#ifndef __UCL_PERL_H
#define __UCL_PERL_H

@begin
include "script_parser.h"
@end

#include <EXTERN.h>
#include <perl.h>

/*
 * constants and definitions
 */

extern unsigned c_bi_class_perl_object;
extern unsigned c_rm_class_dict;

// - max method name length -
const unsigned c_max_method_name_length = 256;

/*
 * definition of structure perl_interpreter_s
 */

struct perl_interpreter_s
{
  PerlInterpreter *interpreter;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class perl_c
 */
class perl_c
{
  public:
  inline perl_c();
  inline ~perl_c();
};

/*
 * inline methods of structure perl_interpreter_s
 */

inline void perl_interpreter_s::init()
{/*{{{*/
  interpreter = NULL;
}/*}}}*/

inline void perl_interpreter_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (interpreter != NULL)
  {
    // - set perl context -
    PerlInterpreter *my_perl = interpreter;
    PERL_SET_CONTEXT(interpreter);

    // - destruct perl interpreter -
    PL_perl_destruct_level = 1;
    perl_destruct(interpreter);
    perl_free(interpreter);
  }

  init();
}/*}}}*/

/*
 * inline methods of class perl_c
 */

inline perl_c::perl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"perl_init()\n"););

  PERL_SYS_INIT3(0,NULL,NULL);
}/*}}}*/

inline perl_c::~perl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"perl_exit()\n"););

  PERL_SYS_TERM();
}/*}}}*/

#endif

