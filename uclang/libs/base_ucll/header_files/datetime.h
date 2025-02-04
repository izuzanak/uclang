
#ifndef __DATETIME_H
#define __DATETIME_H

@begin
include "basic.h"
@end

/*
 * constants and definitions
 */

// - days in constants -
const unsigned c_days_to_epoch     = 134774;
const unsigned c_days_in_400_years = 146097;
const unsigned c_days_in_100_years = 36524;
const unsigned c_days_in_4_years   = 1461;

// - number of days in month -
const unsigned c_month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31,0};
const unsigned c_month_days_leap[] = {31,29,31,30,31,30,31,31,30,31,30,31,0};
libbase_ucll_EXPORT extern const unsigned *c_month_days_arr[2];

// - number of days of month to end of year -
const unsigned c_month_days_to_year_end[] = {0,31,59,90,120,151,181,212,243,273,304,334};

// - count of datetime values  -
const unsigned c_datetime_value_cnt = 10;

/*
 * definition of structure datetime_s
 */

@begin
define datetime_s static
@end

struct datetime_s
{
  unsigned short year;  // year
  unsigned char  month; // month (1..12)
  unsigned char  day;   // day (1..31)
  unsigned char  wday;  // day of week (0=sunday, 1=monday ..)
  unsigned char  hour;  // hour (0..23)
  unsigned char  min;   // minute (0..59)
  unsigned char  sec;   // second (0..59)
  unsigned short msec;  // millisec (0..999)
  unsigned short usec;  // microseconds (0..999)
  unsigned short nsec;  // nanoseconds (0..999)

  datetime_s() = default;
  datetime_s(const datetime_s &a_src) = delete;

  inline void init();
  inline void clear() {};

  /*!
   * \brief swap datetime variables with another datetime
   * \param second - reference to another datetime
   */
  inline void swap(datetime_s &second);

  /*!
   * \brief set datetime to values of another datetime
   * \param src - reference to another datetime
   * \return reference to this datetime
   */
  inline datetime_s &operator=(const datetime_s &src);

  /*!
   * \brief compare values with another datetime
   * \param second - reference to another datetime
   * \return result of comparison
   */
  inline bool operator==(datetime_s &second);

  /*!
   * \brief create new datetime from given count of nanoseconds
   * \param a_nanosec - count of time nanoseconds
   */
  libbase_ucll_EXPORT void from_nanosec(long long unsigned a_nanosec);

  /*!
   * \brief create new datetime from given count of seconds
   * \param a_seconds - count of time seconds
   */
  inline void from_seconds(long long unsigned a_seconds);

  /*!
   * \brief return datetime time in nanoseconds
   * \param a_nanosec - target nanoseconds variable
   * \return true if operation was successful
   */
  libbase_ucll_EXPORT bool to_nanosec(long long unsigned &a_nanosec);

  /*!
   * \brief test if given year is leap year
   * \param a_year - tear to be tested
   */
  static inline bool is_leap_year(unsigned a_year);
};


/*
 * inline methods of structure datetime_s
 */

inline void datetime_s::init()
{/*{{{*/
  memset(this,0,sizeof(datetime_s));
}/*}}}*/

inline void datetime_s::swap(datetime_s &second)
{/*{{{*/
  unsigned short us_tmp;
  unsigned char uc_tmp;

#define DATE_TIME_SWAP(TMP,FIRST,SECOND) \
  TMP = FIRST; FIRST = SECOND; SECOND = TMP;

  DATE_TIME_SWAP(us_tmp,year,second.year);
  DATE_TIME_SWAP(uc_tmp,month,second.month);
  DATE_TIME_SWAP(uc_tmp,day,second.day);
  DATE_TIME_SWAP(uc_tmp,wday,second.wday);
  DATE_TIME_SWAP(uc_tmp,hour,second.hour);
  DATE_TIME_SWAP(uc_tmp,min,second.min);
  DATE_TIME_SWAP(uc_tmp,sec,second.sec);
  DATE_TIME_SWAP(us_tmp,msec,second.msec);
  DATE_TIME_SWAP(us_tmp,usec,second.usec);
  DATE_TIME_SWAP(us_tmp,nsec,second.nsec);
}/*}}}*/

inline datetime_s &datetime_s::operator=(const datetime_s &src)
{/*{{{*/
  memcpy(this,&src,sizeof(datetime_s));
  return *this;
}/*}}}*/

inline bool datetime_s::operator==(datetime_s &second)
{/*{{{*/
  return memcmp(this,&second,sizeof(datetime_s)) == 0; // NOLINT
}/*}}}*/

inline void datetime_s::from_seconds(long long unsigned a_seconds)
{/*{{{*/
  from_nanosec(a_seconds*1000000000ULL);
}/*}}}*/

inline bool datetime_s::is_leap_year(unsigned a_year)
{/*{{{*/
  return (a_year % 4 == 0 && a_year % 100 != 0) || (a_year % 400 == 0);
}/*}}}*/

#endif

