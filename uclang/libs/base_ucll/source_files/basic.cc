
@begin
include "basic.h"
@end

// - version string constant -
const char *c_name_str = "uclang";
const char *c_version_str = "0.1.0";

// - time measuring data structures -
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
struct timeval g_measure_tv;
struct timeval g_measure_stv;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
long long unsigned tick_cnt;
#endif

/*
 * methods of generated structures
 */

