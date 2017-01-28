
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
}/*}}}*/

inline prolog_c::~prolog_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"prolog_exit()\n"););
}/*}}}*/

#endif

