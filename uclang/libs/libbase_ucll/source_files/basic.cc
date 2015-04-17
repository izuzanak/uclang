
@begin
include "basic.h"
@end

// - version string constant -
const char *c_name_str = "uclang";
const char *c_version_str = "0.01";

// - time measuring data structures -
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
struct timeval tv;
struct timeval stv;
#endif

/*
 * methods of generated structures
 */

