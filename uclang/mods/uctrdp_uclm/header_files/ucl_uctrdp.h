
#ifndef __UCL_UCTRDP_H
#define __UCL_UCTRDP_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"

using namespace Ucf2;

#include <uctrdp.h>

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
#define ANY_STRUCTURED 65 /* any structured                                  */

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
 * definition of structure trdp_pd_page_s
 */

struct trdp_pd_page_s
{
  struct pass_s
  {
    char *data_ptr;
    pointer_array_s *array_ptr;
    unsigned array_idx;
    unsigned address;
    unsigned bit_pos;
  };

  trdp_var_descrs_s var_descrs;
  unsigned size;
  unsigned var_count;

  bool process_page_description(interpreter_thread_s &it,pass_s &pass,pointer_array_s *array_ptr,unsigned &vd_count,unsigned &last_vd_idx);
  bool pack_page_data(interpreter_thread_s &it,pass_s &pass,unsigned vd_idx);
  bool unpack_page_data(interpreter_thread_s &it,pass_s &pass,unsigned vd_idx);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_pd_address_s
 */

struct trdp_pd_address_s
{
  unsigned char scope;
  TRDP::IPx dst_host;
  TRDP::IPx src_host;
  TRDP::IPx src2_host;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_pd_port_s
 */

struct trdp_pd_port_s
{
  TRDP::PD::Port port;
  location_s *pd_location;
  TRDP::Handle pub_handle;
  TRDP::Handle sub_handle;

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
 * inline methods of structure trdp_pd_page_s
 */

inline void trdp_pd_page_s::init()
{/*{{{*/
  var_descrs.init();
}/*}}}*/

inline void trdp_pd_page_s::clear(interpreter_thread_s &it)
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

/*
 * inline methods of structure trdp_pd_address_s
 */

inline void trdp_pd_address_s::init()
{/*{{{*/
}/*}}}*/

inline void trdp_pd_address_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure trdp_pd_port_s
 */

inline void trdp_pd_port_s::init()
{/*{{{*/
  pd_location = nullptr;
  pub_handle = TRDP::TRDP_NULL_HANDLE;
  sub_handle = TRDP::TRDP_NULL_HANDLE;
}/*}}}*/

inline void trdp_pd_port_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release pd location -
  if (pd_location != nullptr)
  {
    TRDP::PD *pd_ptr = (TRDP::PD *)pd_location->v_data_ptr;

    // - unpublish port -
    if (pub_handle != TRDP::TRDP_NULL_HANDLE)
    {
      // FIXME TODO remove cassert
      cassert(pd_ptr->Unpublish(pub_handle) == TRDP::TRDP_OK);
    }

    // - unsubscribe port -
    if (sub_handle != TRDP::TRDP_NULL_HANDLE)
    {
      // FIXME TODO remove cassert
      cassert(pd_ptr->Unsubscribe(sub_handle) == TRDP::TRDP_OK);
    }

    it.release_location_ptr(pd_location);
  }

  init();
}/*}}}*/

#endif

