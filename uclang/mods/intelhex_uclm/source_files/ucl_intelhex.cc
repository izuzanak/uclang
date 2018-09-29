
@begin
include "ucl_intelhex.h"
@end

/*
 * methods of structure intel_hex_s
 */

bool intel_hex_s::read_line(unsigned char *a_trg_ptr,const char *a_src_ptr,unsigned a_count)
{/*{{{*/
  const char *src_ptr = a_src_ptr;
  unsigned char comp_sum = 0;

  while(a_count-- > 1)
  {
    // - read data byte -
    int byte = read_byte(src_ptr);
    if (byte < 0)
    {
      return false;
    }

    *a_trg_ptr++ = byte;

    // - update computed check sum -
    comp_sum += byte;
  }

  // - read check sum byte -
  int check_sum = read_byte(src_ptr);
  if (check_sum < 0)
  {
    return false;
  }

  *a_trg_ptr = check_sum;

  return check_sum == (unsigned char)(~comp_sum + 1);
}/*}}}*/

