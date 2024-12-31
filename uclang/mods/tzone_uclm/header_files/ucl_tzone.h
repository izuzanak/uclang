
#ifndef __UCL_TZONE_H
#define __UCL_TZONE_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <ctype.h>

/*
 * constants and definitions
 */

// - error codes -
#define TIME_ZONE_PARSE_ERROR 1

enum {
  TZ_RULE_JULIAN_DAY = 0,       /* Jn = Julian day */
  TZ_RULE_DAY_OF_YEAR,          /* n = day of year */
  TZ_RULE_MONTH_NTH_DAY_OF_WEEK /* Mm.n.d = month, week, day of week */
};

/*
 * definition of generated structures
 */

// -- tz_rule_s --
@begin
struct
<
bi:r_type
bi:r_day
bi:r_week
bi:r_mon
bi:r_time
>
tz_rule_s;
@end

// -- time_zone_s --
@begin
struct
<
bi:rule_mode
bi:stdoffset
bi:dstoffset
tz_rule_s:start
tz_rule_s:end
bi:year
bi:starttime
bi:endtime
bi:utc_offset
>
additions {
  int create(const char *a_tz);
  void to_local(lli a_src,lli *a_trg);
}
time_zone_s;
@end

/*
 * definition of global functions
 */

const char *tzu_getzname(const char *strp);
const char *tzu_getqzname(const char *strp,char delim);
const char *tzu_getnum(const char *strp,int *nump,int min,int max);
const char *tzu_getsecs(const char *strp,int *secsp);
const char *tzu_getoffset(const char *strp,int *offsetp);
const char *tzu_getrule(const char *strp,tz_rule_s *rulep);
int tzu_transtime(int year,const tz_rule_s *rulep,int offset);

/*
 * inline methods of generated structures
 */

// -- tz_rule_s --
@begin
inlines tz_rule_s
@end

// -- time_zone_s --
@begin
inlines time_zone_s
@end

#endif

