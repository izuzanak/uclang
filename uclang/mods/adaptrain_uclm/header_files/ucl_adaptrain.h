
#ifndef __UCL_ADAPTRAIN_H
#define __UCL_ADAPTRAIN_H

@begin
include "script_parser.h"
@end

#include "uctypes.h"
#include "ucf.h"

// - unicon headers -
#include "exekerifc.h"

// - adaptrain headers -
#include "optim_output_data_types.h"
#include "loco_data_types.h"
#include "train_data_types.h"
#include "trip_data_types.h"
#include "line_data_types.h"

/*
 * basic definitions and constants
 */

extern const unsigned short c_two_bytes;
extern const bool c_little_endian;

/*
 * ato aru archive cookie
 */

extern const char c_ato_aru_cookie[8];

/*
 * unicap standard datatypes
 */

#define TBOOL    7 // * boolean 1 bit
#define TSINT    8 //   short integer, 8 bits
#define TINT     9 // * integer, 16 bits
#define TDINT   10 //   double integer, 32 bits
#define TLINT   11 //   long integer, 64 bits
#define TUSINT  12 // * unsigned short integer, 8 bits
#define TUINT   13 // * unsigned integer, 16 bits
#define TUDINT  14 // * unsigned double integer, 32 bits
#define TULINT  15 //   unsigned long integer, 64 bits
#define TREAL   16 // * real, 32 bits
#define TLREAL  17 // * long real, 64 bits
#define TTIME   18 // * duration 32 bits komprim. (h m ms) - (10 6 16)
#define TDATE   19 // * date 16 bits komprim (R M D) - (7 4 5) relativne to y.2000
#define TTOD    20 // * time of day 32 bits komprim (h m ms) - (5 6 16)
#define TDT     21 // * date and time of day 48 bitu komprim: DATE + TOD
#define TSTRING 22 // * character string, length + max.255 byte
#define TBYTE   23 //   bit string of length 8
#define TWORD   24 //   bit string of length 16
#define TDWORD  25 //   bit string of length 32
#define TLWORD  26 //   bit string of length 64

/*
 * event archive records
 */

#pragma pack(8)
struct sEVTARCH_RECORD_U16
{
  R32 r32XValue;
  U8 u8TimeStampms;
  U8 u8Status;
  U16 u16Value;
};
#pragma pack()

#pragma pack(8)
struct sEVTARCH_RECORD_U32
{
  R32 r32XValue;
  U8 u8TimeStampms;
  U8 u8Status;
  U32 u32Value;
};
#pragma pack()

#pragma pack(8)
struct sEVTARCH_RECORD_R32
{
  R32 r32XValue;
  U8 u8TimeStampms;
  U8 u8Status;
  R32 r32Value;
};
#pragma pack()

#pragma pack(8)
struct sEVTARCH_RECORD_R64
{
  R32 r32XValue;
  U8 u8TimeStampms;
  U8 u8Status;
  R64 r64Value;
};
#pragma pack()

/*
 * archive MD5 sum check
 */

#define BIC_CHECK_MD5_DIGEST(ERROR_CODE) \
{/*{{{*/\
  U8 digest[16];\
\
  /* - ERROR - */\
  if (string_ptr->size < 17)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ ## ERROR_CODE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  Ucf::MD5Digest md5;\
  md5.Append((U8 *)string_ptr->data + 16,string_ptr->size - 17);\
  md5.Finish(digest);\
\
  /* - ERROR - */\
  if (memcmp(digest,string_ptr->data,16) != 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ ## ERROR_CODE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

/*
 * definition of structure ato_aru_s
 */

struct ato_aru_s
{
  sFILEARCH_HEAD head;
  unsigned record_count;
  void *records;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_aru_record_s
 */

struct ato_aru_record_s
{
  location_s *ato_aru_loc;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure optim_speed_profile_s
 */

struct optim_speed_profile_s
{
  sOPTIM_SPEED_PROFILE osp;
  location_s *sections_loc;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure optim_line_section_s
 */

struct optim_line_section_s
{
  sOPTIM_LINE_SECTION ols;
  sOPTIM_LINE_SEGMENT *segments;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure optim_line_segment_s
 */

struct optim_line_segment_s
{
  location_s *ols_loc;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_loco_s
 */

struct ato_loco_s
{
  sLOCO loco;
  R32 *charts;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_train_s
 */

struct ato_train_s
{
  sTRAIN train;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_trip_s
 */

struct ato_trip_s
{
  sTRIP trip;
  sLINE_SEC_DESC *sec_descrs;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_trip_sec_s
 */

struct ato_trip_sec_s
{
  location_s *trip_loc;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_line_sec_s
 */

struct ato_line_sec_s
{
  sLINE_SECTION line_sec;
  sLINE_POINT *line_points;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ato_line_sec_point_s
 */

struct ato_line_sec_point_s
{
  location_s *line_sec_loc;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of global functions
 */

inline long long int time_stamp_to_nanosec(sTIMEDATE48 &a_time_stamp);

/*
 * inline methods of structure ato_aru_s
 */

inline void ato_aru_s::init()
{/*{{{*/
  records = NULL;
}/*}}}*/

inline void ato_aru_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (records != NULL)
  {
    cfree(records);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ato_aru_record_s
 */

inline void ato_aru_record_s::init()
{/*{{{*/
  ato_aru_loc = NULL;
}/*}}}*/

inline void ato_aru_record_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release atu aro location -
  if (ato_aru_loc != NULL)
  {
    it.release_location_ptr(ato_aru_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure optim_speed_profile_s
 */

inline void optim_speed_profile_s::init()
{/*{{{*/
  sections_loc = NULL;
}/*}}}*/

inline void optim_speed_profile_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release sections location -
  if (sections_loc != NULL)
  {
    it.release_location_ptr(sections_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure optim_line_section_s
 */

inline void optim_line_section_s::init()
{/*{{{*/
  segments = NULL;
}/*}}}*/

inline void optim_line_section_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release segments -
  if (segments != NULL)
  {
    cfree(segments);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure optim_line_segment_s
 */

inline void optim_line_segment_s::init()
{/*{{{*/
  ols_loc = NULL;
}/*}}}*/

inline void optim_line_segment_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release optim line section location -
  if (ols_loc != NULL)
  {
    it.release_location_ptr(ols_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ato_loco_s
 */

inline void ato_loco_s::init()
{/*{{{*/
  charts = NULL;
}/*}}}*/

inline void ato_loco_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release loco charts -
  if (charts != NULL)
  {
    cfree(charts);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ato_train_s
 */

inline void ato_train_s::init()
{/*{{{*/
}/*}}}*/

inline void ato_train_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure ato_trip_s
 */

inline void ato_trip_s::init()
{/*{{{*/
  sec_descrs = NULL;
}/*}}}*/

inline void ato_trip_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release line section descriptions -
  if (sec_descrs != NULL)
  {
    cfree(sec_descrs);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ato_trip_sec_s
 */

inline void ato_trip_sec_s::init()
{/*{{{*/
  trip_loc = NULL;
}/*}}}*/

inline void ato_trip_sec_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release trip location -
  if (trip_loc != NULL)
  {
    it.release_location_ptr(trip_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ato_line_sec_s
 */

inline void ato_line_sec_s::init()
{/*{{{*/
  line_points = NULL;
}/*}}}*/

inline void ato_line_sec_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release line points -
  if (line_points != NULL)
  {
    cfree(line_points);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ato_line_sec_point_s
 */

inline void ato_line_sec_point_s::init()
{/*{{{*/
  line_sec_loc = NULL;
}/*}}}*/

inline void ato_line_sec_point_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release line section location -
  if (line_sec_loc != NULL)
  {
    it.release_location_ptr(line_sec_loc);
  }

  init();
}/*}}}*/

/*
 * inline global functions
 */

inline long long int time_stamp_to_nanosec(sTIMEDATE48 &a_time_stamp)
{/*{{{*/
  return a_time_stamp.seconds*1000000000LL + (a_time_stamp.ticks*1000000000LL)/0x10000;
}/*}}}*/

inline void nanosec_to_time_stamp(long long int a_nanosec,sTIMEDATE48 &a_time_stamp)
{/*{{{*/
  a_time_stamp.seconds = a_nanosec/1000000000LL;
  a_time_stamp.ticks = ((a_nanosec%1000000000LL)*0x10000)/1000000000LL;
}/*}}}*/

#endif

