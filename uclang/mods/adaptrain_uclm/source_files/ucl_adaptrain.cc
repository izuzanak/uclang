
@begin
include "ucl_adaptrain.h"
@end

/*
 * basic definitions and constants
 */

const unsigned short c_two_bytes = 0xff00;
const bool c_little_endian = ((unsigned char *)&c_two_bytes)[1] == 0xff;

/*
 * ato aru archive cookie
 */

const char c_ato_aru_cookie[8] = {'<','E','V','T','A','R','C','>'};

