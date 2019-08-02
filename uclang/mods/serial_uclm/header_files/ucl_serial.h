
#ifndef __UCL_SERIAL_H
#define __UCL_SERIAL_H

@begin
include "script_parser.h"
@end

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
  c_serial_PAR_NONE = 0,
  c_serial_PAR_EVEN,
  c_serial_PAR_ODD,
};/*}}}*/

#endif

