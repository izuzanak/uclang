
@begin
include "ucl_utf8proc.h"
@end

/*
 * methods of class utf8proc_s
 */

bool utf8proc_s::unicode_to_utf8(ui_array_s &a_ustring,bc_array_s &a_buffer)
{/*{{{*/

  if (a_ustring.used != 0)
  {
    utf8proc_int32_t *cp_ptr = (utf8proc_int32_t *)a_ustring.data;
    utf8proc_int32_t *cp_ptr_end = cp_ptr + a_ustring.used;
    do {

      // - ERROR -
      if (!utf8proc_codepoint_valid(*cp_ptr))
      {
        return false;
      }

      // - encode code point to target buffer -
      a_buffer.reserve(4);
      a_buffer.used += utf8proc_encode_char(*cp_ptr,
          (utf8proc_uint8_t *)(a_buffer.data + a_buffer.used));

    } while(++cp_ptr < cp_ptr_end);
  }

  return true;
}/*}}}*/

