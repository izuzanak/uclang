
#ifndef __UCL_UCGCG_H
#define __UCL_UCGCG_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"

using namespace Ucf2;

/*
 * definition of structure gcg_msg_s
 */

enum {
  head_term_bracket = 0,
  head_term_header,
};

enum {
  tail_term_bracket = 0,
  tail_term_crc,
  tail_term_colon_fcs_comma,
};

struct gcg_msg_s
{
  location_s *data_loc;

  static unsigned head_recognize(const char *string,unsigned &input_idx);
  static unsigned tail_recognize(const char *string,int &input_idx);

  static void head_find(const char *string,unsigned &data_begin);
  static void tail_find(const char *string,unsigned length,unsigned &crc_begin,unsigned &data_end);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure gcg_msg_s
 */

inline void gcg_msg_s::init()
{/*{{{*/
  data_loc = nullptr;
}/*}}}*/

inline void gcg_msg_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (data_loc != nullptr)
  {
    it.release_location_ptr(data_loc);
  }

  init();
}/*}}}*/

#endif

