
#ifndef __UCL_SERIAL_H
#define __UCL_SERIAL_H

@begin
include "script_parser.h"
@end

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#ifndef CRS485
#define CRS485 0x08000000
#endif

// - serial flow control -
enum
{/*{{{*/
  c_serial_FC_NONE = 0,
  c_serial_FC_RTS_CTS,
  c_serial_FC_RS_485,
};/*}}}*/

// - serial parity -
enum
{/*{{{*/
  c_serial_PARITY_NONE = 0,
  c_serial_PARITY_EVEN,
  c_serial_PARITY_ODD,
};/*}}}*/

/*
 * definition of structure serial_s
 */

struct serial_s
{
  int fd;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure serial_s
 */

inline void serial_s::init()
{/*{{{*/
  fd = -1;
}/*}}}*/

inline void serial_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (fd != -1)
  {
    close(fd);
  }

  init();
}/*}}}*/

#endif

