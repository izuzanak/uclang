
#ifndef __UCL_DDB_H
#define __UCL_DDB_H

@begin
include "script_parser.h"
@end

#include "ucf.h"
using namespace Ucf;

#include "uctypes.h"
#include "dddshm.h"
#include "ucxml.h"
#include "apexcls.h"
#include "ddb.h"

/*
 * basic constants and definitions
 */

// - ucf global log object -
extern LogExt g_log_ext;

/*
 * definition of structure trace_storage_s
 */

struct trace_storage_s
{
  location_s *ddb_ptr;
  TraceStorage *ts_ptr;
};

/*
 * definition of structure trace_record_s
 */

struct trace_record_s
{
  location_s *ts_ptr;
  TraceRecord *tr_ptr;
  location_s *data_ptr;
};

#endif

