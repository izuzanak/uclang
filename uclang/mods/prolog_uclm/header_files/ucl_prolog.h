
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
extern unsigned c_bi_class_prolog_pred;
extern unsigned c_bi_class_prolog_term;
extern unsigned c_bi_class_prolog_query;

/*
 * definition of class prolog_c
 */
class prolog_c
{
  public:
  static qid_t qid;

  inline prolog_c();
  inline ~prolog_c();

  static bool retrieve_atom(location_s *location_ptr,atom_t &atom);

  static bool create_prolog_term(interpreter_thread_s &it,term_t term,location_s *location_ptr);
  static location_s *prolog_term_value(interpreter_thread_s &it,term_t term,uli source_pos);
};

/*
 * definition of structure prolog_query_s
 */

struct prolog_query_s
{
  fid_t fid;
  module_t plmod;
  predicate_t pred;
  term_t terms;

  inline void init();
  inline void clear(interpreter_thread_s &it);
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

/*
 * inline methods of structure prolog_query_s
 */

inline void prolog_query_s::init()
{/*{{{*/
}/*}}}*/

inline void prolog_query_s::clear(interpreter_thread_s &it)
{/*{{{*/
  PL_close_foreign_frame(fid);

  init();
}/*}}}*/

#endif

