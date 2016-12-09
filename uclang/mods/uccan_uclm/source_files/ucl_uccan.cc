
@begin
include "ucl_uccan.h"
@end

/*
 * basic definitions and constants
 */

const unsigned short c_two_bytes = 0xff00;
const bool c_big_endian = ((unsigned char *)&c_two_bytes)[0] == 0xff;

