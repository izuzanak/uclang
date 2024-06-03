
#ifndef __UCL_CURSES_H
#define __UCL_CURSES_H

@begin
include "script_parser.h"
@end

#include <curses.h>

/*
 * definition of class curses_c
 */

class curses_c
{
  public:
  inline curses_c();
  inline ~curses_c();
};

/*
 * inline methods of class curses_c
 */

inline curses_c::curses_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcurses_init()\n"););

  initscr();
}/*}}}*/

inline curses_c::~curses_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcurses_exit()\n"););

  if (!isendwin())
  {
    endwin();
  }
}/*}}}*/

#endif

