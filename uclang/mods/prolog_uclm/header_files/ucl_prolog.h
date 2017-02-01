
#ifndef __UCL_PROLOG_H
#define __UCL_PROLOG_H

@begin
include "script_parser.h"
@end

#include "SWI-Prolog.h"

/*
 * constants and definitions
 */

extern unsigned c_bi_class_prolog_atom;
extern unsigned c_bi_class_prolog_module;
extern unsigned c_bi_class_prolog_functor;

/*
 * definition of class prolog_c
 */
class prolog_c
{
  public:
  inline prolog_c();
  inline ~prolog_c();

  static bool retrieve_atom(location_s *location_ptr,atom_t &atom);

  static bool create_prolog_term(interpreter_thread_s &it,term_t term,location_s *location_ptr);
  static location_s *prolog_term_value(interpreter_thread_s &it,term_t term,uli source_pos);
};

/*
 * inline methods of class prolog_c
 */

inline prolog_c::prolog_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"prolog_init()\n"););

  const char *argv[] = {"uclang","-q",NULL};
  cassert(PL_initialise(2,(char **)argv));
}/*}}}*/

inline prolog_c::~prolog_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"prolog_exit()\n"););

  cassert(PL_cleanup(0));
}/*}}}*/

#endif

