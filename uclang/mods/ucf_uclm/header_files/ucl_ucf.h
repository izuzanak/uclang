
#ifndef __UCL_UCF_H
#define __UCL_UCF_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"

using namespace Ucf2;

/*
 * basic constants and definitions
 */

#define SYSTIME_VALUE_CNT 10

extern const int c_days_in_month[2][13];

const int c_vs_max_var_size = 256;
const int c_vs_max_str_size = c_vs_max_var_size;
const unsigned c_vs_client_info_name_size = 12; // sizeof(VarStore::ClientInfo::name)
const unsigned c_vs_slot_info_name_size = 16;   // sizeof(VarStore::SlotInfo::name)
const unsigned char c_zeroes[c_vs_max_var_size] = {0};

/*
 * definition of varstore variable types
 */

#define TBOOL              7 // * boolean 1 bit
#define TSINT              8 //   short integer, 8 bits
#define TINT               9 // * integer, 16 bits
#define TDINT             10 //   double integer, 32 bits
#define TLINT             11 //   long integer, 64 bits
#define TUSINT            12 // * unsigned short integer, 8 bits
#define TUINT             13 // * unsigned integer, 16 bits
#define TUDINT            14 // * unsigned double integer, 32 bits
#define TULINT            15 //   unsigned long integer, 64 bits
#define TREAL             16 // * real, 32 bits
#define TLREAL            17 // * long real, 64 bits
#define TTIME             18 // * duration 32 bits komprim. (h m ms) - (10 6 16)
#define TDATE             19 // * date 16 bits komprim (R M D) - (7 4 5) relativne to y.2000
#define TTOD              20 // * time of day 32 bits komprim (h m ms) - (5 6 16)
#define TDT               21 // * date and time of day 48 bitu komprim: DATE + TOD
#define TSTRING           22 // * character string, length + max.255 byte
#define TBYTE             23 //   bit string of length 8
#define TWORD             24 //   bit string of length 16
#define TDWORD            25 //   bit string of length 32
#define TLWORD            26 //   bit string of length 64

/*
 * definition of structure ucf_log_s
 */

struct ucf_log_s
{
  LogSet *log_set_ptr;
  string_s source;
};

/*
 * definition of structure varstore_slot_s
 */

struct varstore_slot_s
{
  location_s *vs_ptr;
  int slot_idx;
};

/*
 * definition of structure nvm_segment_s
 */

struct nvm_segment_s
{
  NvmSegment *ns_ptr;
  pointer ram_ptr;
};

/*
 * definition of structure crc_s
 */

enum
{
  CRC_SIZE_8  =  8,
  CRC_SIZE_16 = 16,
  CRC_SIZE_32 = 32,
};

struct crc_s
{
  unsigned size;
  long long unsigned value;
};

#endif

