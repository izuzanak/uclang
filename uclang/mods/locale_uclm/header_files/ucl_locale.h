
#ifndef __UCL_LOCALE_H
#define __UCL_LOCALE_H

@begin
include "script_parser.h"
@end

#include <libintl.h>
#include <locale.h>

/*
 * definition of class locale_c
 */
class locale_c
{
  public:
  inline locale_c();
  inline ~locale_c();
};

/*
 * inline methods of class locale_c
 */

inline locale_c::locale_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"locale_init()\n"););
}/*}}}*/

inline locale_c::~locale_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"locale_exit()\n"););
}/*}}}*/

#endif

