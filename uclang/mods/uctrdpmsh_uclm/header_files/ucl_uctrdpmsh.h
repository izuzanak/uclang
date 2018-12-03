
#ifndef __UCL_UCTRDPMSH_H
#define __UCL_UCTRDPMSH_H

@begin
include "script_parser.h"
@end

/*
 * definition of trdp variable types
 */

#define TBOOL          7   // boolean 1 bit
#define TINT           9   // signed integer 16 bitu
#define TUSINT         12  // unsigned short integer, 8 bits
#define TUINT          13  // unsigned integer 16 bits
#define TUDINT         14  // unsigned double integer 32 bits
#define TREAL          16  // real 32 bits
#define TLREAL         17  // long real 64 bits
#define TTIME          18  // duration 32 bits compressed (h m ms) - (10 6 16)
#define TDATE          19  // date 16 bits compressed (R M D) - (7 4 5) relative to year 2000
#define TTOD           20  // time of day 32 bits compressed (h m ms) - (5 6 16)
#define TDT            21  // date and time of day 48 bits compressed: DATE + TOD
#define TSTRING        22  // character string, length byte + max.255 byte
#define TBYTE          23  // bit string of length 8
#define TWORD          24  // bit string of length 16
#define TDWORD         25  // bit string of length 32
#define TLWORD         26  // bit string of length 64

#define TTIMEhm        27  // UINT  0:0..1023:59    duration (h m)-(10 6)
#define TTODhm         29  // UINT  00:00 .. 23:59  time of day (h m)-(5 6)
#define TDThm          30  // UDINT .. 127-12-31 23:59 date and time of day (R M D h m)-(7 4 5 5 6)
#define TTSTAMP        43  // UDINT ..3-12-31 23:59:59.9 time stamp resolution 0.1s (2 4 5 5 | 6 10)
#define TBCD8          45  // UDINT    0..99999999 8 digit in BCD code
#define TSTRINGB       67
#define TUNICODE       98
#define TTDsecs        114 // UDINT .. Elapsed time in seconds since 1970, January 1st, 00:00
#define TTDticks       115 // UINT  .. Number of ticks (1 tick =1/65536 s)

#define ANY_ARRAY      0
#define ANY_STRUCT     65 /* any structured                                  */

// - UCTRDPMSH indexes of remote classes -
extern unsigned c_rm_class_dict;

/*
 * basic definitions and constants
 */

extern const unsigned short c_two_bytes;
extern const bool c_little_endian;

// - UCTRDPMSH error identifiers -
enum
{
  c_error_TRDP_PAGE_DESCR_TOO_SHORT = 0,
  c_error_TRDP_PAGE_DESCR_PROCESS_ERROR,
  c_error_TRDP_PAGE_DESCR_EXPECTED_STRING_AS_NAME,
  c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_TYPE,
  c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_ARRAY_SIZE,
  c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_VARIABLE_COUNT,
  c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_STRING_LENGTH,
  c_error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_ARRAY_DESCR,
  c_error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_STRUCT_DESCR,
  c_error_TRDP_PAGE_DESCR_ARRAY_INVALID_VD_COUNT,
  c_error_TRDP_PAGE_DESCR_UNSUPPORTED_TYPE,
  c_error_TRDP_PAGE_PACK_ERROR,
  c_error_TRDP_PAGE_PACK_DICT_ERROR,
  c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_COUNT,
  c_error_TRDP_PAGE_PACK_INVALID_DATA_SIZE,
  c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE,
  c_error_TRDP_PAGE_PACK_INVALID_STRING_LENGTH,
  c_error_TRDP_PAGE_UNPACK_ERROR,
};

/*
 * definition of generated structures
 */

// -- trdp_var_descr_s --
@begin
struct
<
pointer:name_location
unsigned:type
unsigned:address
unsigned:length
unsigned:size
unsigned:count
>
trdp_var_descr_s;
@end

// -- trdp_var_descrs_s --
@begin
array<trdp_var_descr_s> trdp_var_descrs_s;
@end

/*
 * definition of structure trdp_page_s
 */

struct trdp_page_s
{
  struct pass_s
  {
    unsigned char *data_ptr;
    pointer_array_s *vars_ptr;
    unsigned var_idx;
    unsigned vd_idx;
    unsigned address;
    unsigned bit_pos;
  };

  trdp_var_descrs_s var_descrs;
  unsigned size;
  unsigned var_count;

  bool process_page_description(interpreter_thread_s &it,pass_s &pass,pointer_array_s *array_ptr,unsigned &vd_count,unsigned &last_vd_idx);
  bool pack_page_data(interpreter_thread_s &it,pass_s &pass);
  bool unpack_page_data(interpreter_thread_s &it,pass_s &pass);
  location_s *to_dict(interpreter_thread_s &it,pass_s &pass,pointer_array_s *array_ptr,pointer_map_tree_s *tree_ptr);
  bool from_dict(interpreter_thread_s &it,pass_s &pass,location_s *arr_item_loc,pointer_map_tree_s *tree_ptr);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- trdp_var_descr_s --
@begin
inlines trdp_var_descr_s
@end

// -- trdp_var_descrs_s --
@begin
inlines trdp_var_descrs_s
@end

/*
 * inline methods of structure trdp_page_s
 */

inline void trdp_page_s::init()
{/*{{{*/
  var_descrs.init();
}/*}}}*/

inline void trdp_page_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release varibale descriptor names -
  if (var_descrs.used != 0)
  {
    trdp_var_descr_s *tvd_ptr = var_descrs.data;
    trdp_var_descr_s *tvd_ptr_end = tvd_ptr + var_descrs.used;

    do {
      it.release_location_ptr((location_s *)tvd_ptr->name_location);
    } while(++tvd_ptr < tvd_ptr_end);
  }

  var_descrs.clear();

  init();
}/*}}}*/

#endif

