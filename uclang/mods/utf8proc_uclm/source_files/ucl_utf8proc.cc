
@begin
include "ucl_utf8proc.h"
@end

/*
 * methods of class utf8proc_s
 */

bool utf8proc_s::unicode_to_utf8(ui_array_s &a_ustring,bc_array_s &a_buffer)
{/*{{{*/
  if (a_ustring.used > 1)
  {
    utf8proc_int32_t *cp_ptr = (utf8proc_int32_t *)a_ustring.data;
    utf8proc_int32_t *cp_ptr_end = cp_ptr + a_ustring.used - 1;
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

void utf8proc_s::unicode_print(ui_array_s &a_ustring)
{/*{{{*/
  if (a_ustring.used > 1)
  {
    const utf8proc_ssize_t c_buff_size = 256;
    utf8proc_uint8_t buffer[c_buff_size];
    utf8proc_ssize_t buff_used = 0;

    utf8proc_int32_t *cp_ptr = (utf8proc_int32_t *)a_ustring.data;
    utf8proc_int32_t *cp_ptr_end = cp_ptr + a_ustring.used - 1;
    do {

      // - check if code point is valid -
      if (utf8proc_codepoint_valid(*cp_ptr))
      {
        if (c_buff_size - buff_used < 4)
        {
          // - print utf-8 string -
          fwrite(buffer,buff_used,1,stdout);
          buff_used = 0;
        }

        // - encode code point to target buffer -
        buff_used += utf8proc_encode_char(*cp_ptr,buffer + buff_used);
      }
    } while(++cp_ptr < cp_ptr_end);

    // - print rest of utf-8 string -
    if (buff_used > 0)
    {
      fwrite(buffer,buff_used,1,stdout);
    }
  }
}/*}}}*/

