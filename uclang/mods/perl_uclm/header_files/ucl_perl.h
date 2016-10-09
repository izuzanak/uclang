
#ifndef __UCL_PERL_H
#define __UCL_PERL_H

@begin
include "script_parser.h"
@end

#include <EXTERN.h>
#include <perl.h>

// FIXME TODO remove ...
// int sv_isobject(SV* sv) - determine if sv is object

/*
 * constants and definitions
 */

extern unsigned c_bi_class_perl_value;
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
 * definition of structure perl_value_s
 */

struct perl_value_s
{
  location_s *pi_loc;
  SV *sv;

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

  static SV *create_perl_sv(interpreter_thread_s &it,PerlInterpreter *my_perl,location_s *location_ptr);
  static location_s *perl_sv_value(interpreter_thread_s &it,PerlInterpreter *my_perl,SV *sv,uli source_pos);
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
 * inline methods of structure perl_value_s
 */

inline void perl_value_s::init()
{/*{{{*/
  pi_loc = NULL;
  sv = NULL;
}/*}}}*/

inline void perl_value_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release value -
  if (sv != NULL)
  {
    perl_interpreter_s *pi_ptr = (perl_interpreter_s *)pi_loc->v_data_ptr;

    // - set perl context -
    PerlInterpreter *my_perl = pi_ptr->interpreter;
    PERL_SET_CONTEXT(pi_ptr->interpreter);

    // - decrement reference counter -
    SvREFCNT_dec(sv);
  }

  // - release perl interpreter location -
  if (pi_loc != NULL)
  {
    it.release_location_ptr(pi_loc);
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

