
@begin
include "datetime.h"
@end

/*
 * constants and definitions
 */

const unsigned *c_month_days_arr[2] = {c_month_days,c_month_days_leap};

/*
 * methods of structure datetime_s
 */

void datetime_s::from_nanosec(long long unsigned a_nanosec)
{/*{{{*/
  long long unsigned tmp = a_nanosec;

  // - retrieve time fields -
  nsec = tmp % 1000; tmp /= 1000;
  usec = tmp % 1000; tmp /= 1000;
  msec = tmp % 1000; tmp /= 1000;
  sec  = tmp % 60;   tmp /= 60;
  min  = tmp % 60;   tmp /= 60;
  hour = tmp % 24;   tmp /= 24;

  // - number of days plus days to epoch -
  unsigned days = tmp + c_days_to_epoch;

  // - calculate week day -
  wday = (days % 7) + 1;

  // - calculate year -
  year = 1601;

  year += (days / c_days_in_400_years) * 400;
  days %= c_days_in_400_years;

  year += (days / c_days_in_100_years) * 100;
  days %= c_days_in_100_years;

  year += (days / c_days_in_4_years) * 4;
  days %= c_days_in_4_years;

  // - last year of 4 year period can be leap year -
  if (days < 3 * 365)
  {
    year += days / 365;
    days %= 365;
  }
  else
  {
    year += 3;
    days -= 3 * 365;
  }
  // - calculate month -
  month = 1;
  const unsigned *month_days = is_leap_year(year) ? c_month_days_leap : c_month_days;
  while (days >= *month_days)
  {
    ++month;
    days -= *month_days++;
  }

  // - calculate day -
  day = days + 1;
}/*}}}*/

bool datetime_s::to_nanosec(long long unsigned &a_nanosec)
{/*{{{*/
  if (year < 1970)
  {
    return false;
  }

  unsigned tmp_year = year - 1601;

  // - number of days from epoch -
  long long unsigned time = tmp_year*365
    + tmp_year/4
    - tmp_year/100
    + tmp_year/400
    + c_month_days_to_year_end[month - 1]
    + ((is_leap_year(year) && month > 2) ? 1 : 0)
    + day - 1
    - c_days_to_epoch;

  // - calculate time from 1.1.1970 at nanoseconds -
  time *= 24;   time += hour;
  time *= 60;   time += min;
  time *= 60;   time += sec;
  time *= 1000; time += msec;
  time *= 1000; time += usec;
  time *= 1000; time += nsec;

  // - set value to result time -
  a_nanosec = time;

  return true;
}/*}}}*/

