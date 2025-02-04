
@begin
include "ucl_tzone.h"
@end

/*
 * constants and definitions
 */

#ifndef TZDEFRULESTRING
#define TZDEFRULESTRING ",M3.2.0,M11.1.0"
#endif

#define SECSPERMIN   60
#define MINSPERHOUR  60
#define HOURSPERDAY  24
#define DAYSPERWEEK  7
#define DAYSPERNYEAR 365
#define DAYSPERLYEAR 366
#define SECSPERHOUR  (SECSPERMIN * MINSPERHOUR)
#define SECSPERDAY   ((int) SECSPERHOUR * HOURSPERDAY)
#define MONSPERYEAR  12

#define is_digit(c) isdigit(c)
#define isleap(y) (((y) % 4) == 0 && (((y) % 100) != 0 || ((y) % 400) == 0))

const int mon_lengths[2][MONSPERYEAR] = {
  { 31,28,31,30,31,30,31,31,30,31,30,31 },
  { 31,29,31,30,31,30,31,31,30,31,30,31 }
};

/*
 * methods of generated structures
 */

// -- tz_rule_s --
@begin
methods tz_rule_s
@end

// -- time_zone_s --
@begin
methods time_zone_s
@end

int time_zone_s::create(const char *a_tz)
{/*{{{*/
  const char *stdname;
  const char *dstname;
  size_t stdlen;
  size_t dstlen;

  stdname = a_tz;
  if (*a_tz == '<') {
    a_tz++;
    stdname = a_tz;
    a_tz = tzu_getqzname(a_tz,'>');
    if (*a_tz != '>') {
      return TIME_ZONE_PARSE_ERROR;
    }
    stdlen = a_tz - stdname;
    a_tz++;
  } else {
    a_tz = tzu_getzname(a_tz);
    stdlen = a_tz - stdname;
  }

  if (!stdlen) {
    return TIME_ZONE_PARSE_ERROR;
  }

  a_tz = tzu_getoffset(a_tz,&this->stdoffset);
  if (a_tz == NULL) {
    return TIME_ZONE_PARSE_ERROR;
  }

  if (*a_tz != '\0') {
    if (*a_tz == '<') {
      dstname = ++a_tz;
      a_tz = tzu_getqzname(a_tz,'>');
      if (*a_tz != '>') {
        return TIME_ZONE_PARSE_ERROR;
      }
      dstlen = a_tz - dstname;
      a_tz++;
    } else {
      dstname = a_tz;
      a_tz = tzu_getzname(a_tz);
      dstlen = a_tz - dstname; /* length of DST abbr. */
    }
    if (!dstlen) {
      return TIME_ZONE_PARSE_ERROR;
    }

    if (*a_tz != '\0' && *a_tz != ',' && *a_tz != ';') {
      a_tz = tzu_getoffset(a_tz,&this->dstoffset);
      if (a_tz == NULL) {
        return TIME_ZONE_PARSE_ERROR;
      }
    } else {
      this->dstoffset = this->stdoffset - SECSPERHOUR;
    }

    if (*a_tz == '\0') {
      a_tz = TZDEFRULESTRING;
    }

    if (*a_tz == ',' || *a_tz == ';') {
      a_tz++;
      if ((a_tz = tzu_getrule(a_tz,&this->start)) == NULL) {
        return TIME_ZONE_PARSE_ERROR;
      }
      if (*a_tz++ != ',') {
        return TIME_ZONE_PARSE_ERROR;
      }
      if ((a_tz = tzu_getrule(a_tz,&this->end)) == NULL) {
        return TIME_ZONE_PARSE_ERROR;
      }
      if (*a_tz != '\0') {
        return TIME_ZONE_PARSE_ERROR;
      }

      this->year = -1;
      this->rule_mode = 1;
    }
    else
    {
      return TIME_ZONE_PARSE_ERROR;
    }
  } else
  {
    this->rule_mode = 0;
  }

  return 0;
}/*}}}*/

void time_zone_s::to_local(lli a_src,lli *a_trg)
{/*{{{*/
  time_t utc_time = a_src / 1000000000ULL;
  unsigned subsec = a_src % 1000000000ULL;

  if (this->rule_mode)
  {
    struct tm *time_spl = gmtime(&utc_time);

    int year = time_spl->tm_year + 1900;
    if (year != this->year)
    {
      this->starttime = tzu_transtime(year,&this->start,this->stdoffset);
      this->endtime = tzu_transtime(year,&this->end,this->dstoffset);
      this->year = year;
    }

    // Actual sec position, from 1.1.this_year
    int actualtime = time_spl->tm_yday * SECSPERDAY;
    actualtime += time_spl->tm_hour * SECSPERHOUR;
    actualtime += time_spl->tm_min * SECSPERMIN;
    actualtime += time_spl->tm_sec;

    // check actual time in interval
    if ((actualtime >= this->starttime) && (actualtime <= this->endtime))
    {
      this->utc_offset = -this->dstoffset;
    }
    else
    {
      this->utc_offset = -this->stdoffset;
    }
  }
  else
  {
    this->utc_offset = -this->stdoffset;
  }

  *a_trg = (utc_time + this->utc_offset)*1000000000ULL + subsec;
}/*}}}*/

// === global functions ========================================================

/*
** Given a pointer into a timezone string, scan until a character that is not
** a valid character in a time zone abbreviation is found.
** Return a pointer to that character.
*/
const char *tzu_getzname(const char *strp)
{/*{{{*/
  while (*strp!='\0' && !is_digit(*strp) && (*strp!=',') && (*strp!='-') && (*strp!='+')) {
    strp++;
  }
  return strp;
}/*}}}*/

/*
** Given a pointer into an extended timezone string, scan until the ending
** delimiter of the time zone abbreviation is located.
** Return a pointer to the delimiter.
**
** As with getzname above, the legal character set is actually quite
** restricted, with other characters producing undefined results.
** We don't do any checking here; checking is done later in common-case code.
*/
const char *tzu_getqzname(const char *strp,char delim)
{/*{{{*/
  while ((*strp!='\0') && (*strp!=delim)) {
    strp++;
  }
  return strp;
}/*}}}*/

/*
** Given a pointer into a timezone string, extract a number from that string.
** Check that the number is within a specified range; if it is not, return
** NULL.
** Otherwise, return a pointer to the first character not part of the number.
*/
const char *tzu_getnum(const char *strp,int *nump,int min,int max)
{/*{{{*/
  char c;
  int num;

  if (strp == NULL || !is_digit(c = *strp)) {
    return NULL;
  }
  num = 0;
  do {
    num = num * 10 + (c - '0');
    if (num > max) {
      return NULL; /* illegal value */
    }
    c = *++strp;
  } while (is_digit(c));
  if (num < min) {
    return NULL; /* illegal value */
  }
  *nump = num;
  return strp;
}/*}}}*/

/*
** Given a pointer into a timezone string, extract a number of seconds,
** in hh[:mm[:ss]] form, from the string.
** If any error occurs, return NULL.
** Otherwise, return a pointer to the first character not part of the number
** of seconds.
*/
const char *tzu_getsecs(const char *strp,int *secsp)
{/*{{{*/
  int num;

  /*
    ** 'HOURSPERDAY * DAYSPERWEEK - 1' allows quasi-Posix rules like
    ** "M10.4.6/26", which does not conform to Posix,
    ** but which specifies the equivalent of
    ** "02:00 on the first Sunday on or after 23 Oct".
  */
  strp = tzu_getnum(strp,&num,0,(HOURSPERDAY * DAYSPERWEEK) - 1);
  if (strp == NULL) {
    return NULL;
  }
  *secsp = num * SECSPERHOUR;
  if (*strp == ':') {
    ++strp;
    strp = tzu_getnum(strp,&num,0,MINSPERHOUR - 1);
    if (strp == NULL) {
      return NULL;
    }
    *secsp += num * SECSPERMIN;
    if (*strp == ':') {
      ++strp;
      /* 'SECSPERMIN' allows for leap seconds.  */
      strp = tzu_getnum(strp,&num,0,SECSPERMIN);
      if (strp == NULL) {
        return NULL;
      }
      *secsp += num;
    }
  }
  return strp;
}/*}}}*/

/*
** Given a pointer into a timezone string, extract an offset, in
** [+-]hh[:mm[:ss]] form, from the string.
** If any error occurs, return NULL.
** Otherwise, return a pointer to the first character not part of the time.
*/
const char *tzu_getoffset(const char *strp,int *offsetp)
{/*{{{*/
  int neg = 0;

  if (*strp == '-') {
    neg = 1;
    ++strp;
  }
  else if (*strp == '+') {
    ++strp;
  }
  strp = tzu_getsecs(strp,offsetp);
  if (strp == NULL) {
    return NULL; /* illegal time */
  }
  if (neg) {
    *offsetp = -*offsetp;
  }
  return strp;
}/*}}}*/

/*
** Given a pointer into a timezone string, extract a rule in the form
** date[/time]. See POSIX section 8 for the format of "date" and "time".
** If a valid rule is not found, return NULL.
** Otherwise, return a pointer to the first character not part of the rule.
*/
const char *tzu_getrule(const char *strp,tz_rule_s *rulep)
{/*{{{*/
  if (*strp == 'J') {
    /*
        ** Julian day.
    */
    rulep->r_type = TZ_RULE_JULIAN_DAY;
    ++strp;
    strp = tzu_getnum(strp,&rulep->r_day,1,DAYSPERNYEAR);
  } else if (*strp == 'M') {
    /*
        ** Month, week, day.
    */
    rulep->r_type = TZ_RULE_MONTH_NTH_DAY_OF_WEEK;
    ++strp;
    strp = tzu_getnum(strp,&rulep->r_mon,1,MONSPERYEAR);
    if (strp == NULL) {
      return NULL;
    }
    if (*strp++ != '.') {
      return NULL;
    }

    strp = tzu_getnum(strp,&rulep->r_week,1,5);
    if (strp == NULL) {
      return NULL;
    }
    if (*strp++ != '.') {
      return NULL;
    }

    strp = tzu_getnum(strp,&rulep->r_day,0,DAYSPERWEEK - 1);
  }
  else if (is_digit(*strp)) {
    /*
        ** Day of year.
    */
    rulep->r_type = TZ_RULE_DAY_OF_YEAR;
    strp = tzu_getnum(strp,&rulep->r_day,0,DAYSPERLYEAR - 1);
  } else {
    return NULL;        /* invalid format */
  }

  if (strp == NULL) {
    return NULL;
  }

  if (*strp == '/') {
    /*
        ** Time specified.
    */
    ++strp;
    strp = tzu_getoffset(strp,&rulep->r_time);
  }
  else {
    rulep->r_time = 2 * SECSPERHOUR;    /* default = 2:00:00 */
  }
  return strp;
}/*}}}*/

/*
** Given a year, a rule, and the offset from UT at the time that rule takes
** effect, calculate the year-relative time that rule takes effect.
*/
int tzu_transtime(int year,const tz_rule_s *rulep,int offset)
{/*{{{*/
  int leapyear;
  int value;
  int i;
  int d,m1,yy0,yy1,yy2,dow; // NOLINT(readability-isolate-declaration)

  //INITIALIZE(value);
  leapyear = isleap(year);
  switch (rulep->r_type)
  {
    case TZ_RULE_JULIAN_DAY:
      /*
            ** Jn - Julian day, 1 == January 1, 60 == March 1 even in leap
            ** years.
            ** In non-leap years, or if the day number is 59 or less, just
            ** add SECSPERDAY times the day number-1 to the time of
            ** January 1, midnight, to get the day.
      */
      value = (rulep->r_day - 1) * SECSPERDAY;
      if (leapyear && rulep->r_day >= 60) {
        value += SECSPERDAY;
      }
      break;

    case TZ_RULE_DAY_OF_YEAR:
      /*
            ** n - day of year.
            ** Just add SECSPERDAY times the day number to the time of
            ** January 1, midnight, to get the day.
      */
      value = rulep->r_day * SECSPERDAY;
      break;

    case TZ_RULE_MONTH_NTH_DAY_OF_WEEK:
      /*
            ** Mm.n.d - nth "dth day" of month m.
      */

      /*
            ** Use Zeller's Congruence to get day-of-week of first day of
            ** month.
      */
      m1 = (rulep->r_mon + 9) % 12 + 1;
      yy0 = (rulep->r_mon <= 2) ? (year - 1) : year;
      yy1 = yy0 / 100;
      yy2 = yy0 % 100;
      dow = ((26 * m1 - 2) / 10 +
              1 + yy2 + yy2 / 4 + yy1 / 4 - 2 * yy1) % 7;
      if (dow < 0) {
        dow += DAYSPERWEEK;
      }

      /*
            ** "dow" is the day-of-week of the first day of the month. Get
            ** the day-of-month (zero-origin) of the first "dow" day of the
            ** month.
      */
      d = rulep->r_day - dow;
      if (d < 0) {
        d += DAYSPERWEEK;
      }
      for (i = 1; i < rulep->r_week; ++i) {
        if (d + DAYSPERWEEK >=
            mon_lengths[leapyear][rulep->r_mon - 1]) {
          break;
        }
        d += DAYSPERWEEK;
      }

      /*
            ** "d" is the day-of-month (zero-origin) of the day we want.
      */
      value = d * SECSPERDAY;
      for (i = 0; i < rulep->r_mon - 1; ++i) {
        value += mon_lengths[leapyear][i] * SECSPERDAY;
      }
      break;

    default:
      value = 0;
      break;
  }

  /*
    ** "value" is the year-relative time of 00:00:00 UT on the day in
    ** question. To get the year-relative time of the specified local
    ** time on that day, add the transition time and the current offset
    ** from UT.
  */
  return value + rulep->r_time + offset;
}/*}}}*/

