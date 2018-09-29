
#ifndef __UCL_INTELHEX_H
#define __UCL_INTELHEX_H

@begin
include "script_parser.h"
@end

/*
 * definition of structure intel_hex_s
 */

struct intel_hex_s
{
  FILE *file;
  unsigned line_cnt;
  bool read_done;

  unsigned short esa;
  unsigned short ssa_cs;
  unsigned short ssa_ip;
  unsigned short ela;
  unsigned sla_eip;

  inline static int read_byte(const char *&a_ptr);
  static bool read_line(unsigned char *a_trg_ptr,const char *a_src_ptr,unsigned a_count);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure intel_hex_s
 */

inline int intel_hex_s::read_byte(const char *&a_ptr)
{/*{{{*/
  int value;

  char ch = *a_ptr++;
  if (ch >= '0' && ch <= '9')
  {
    value = (unsigned char)(ch << 4);
  }
  else if ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
  {
    value = 144 + (unsigned char)(ch << 4);
  }
  else
  {
    return -1;
  }

  ch = *a_ptr++;
  if (ch >= '0' && ch <= '9')
  {
    value += ch & 0x0f;
  }
  else if ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
  {
    value += 9 + (ch & 0x0f);
  }
  else
  {
    return -1;
  }

  return value;
}/*}}}*/

inline void intel_hex_s::init()
{/*{{{*/
  file = nullptr;
}/*}}}*/

inline void intel_hex_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (file != nullptr)
  {
    fclose(file);
  }

  init();
}/*}}}*/

#endif

