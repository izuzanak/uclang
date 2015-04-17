
#ifndef __UCL_COMELM_H
#define __UCL_COMELM_H

@begin
include "script_parser.h"
@end

#include "elmcomproc.h"

// Elektrometer namespace
using namespace Elm;

/*
 * basic definitions and constants
 */

// - comelm global log object -
extern LogExt g_log_ext;
extern LogExt *g_pLogExt;

const unsigned c_time_string_size = g_u32DateStrLength + g_u32TimeStrLength + 1;

#endif

