
#ifndef __UCL_PROLOG_H
#define __UCL_PROLOG_H

@begin
include "script_parser.h"
@end

#include "SWI-Prolog.h"

/*
 * definition of class prolog_c
 */
class prolog_c
{
  public:
  inline prolog_c();
  inline ~prolog_c();
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

