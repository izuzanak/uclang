
@begin
include "ucl_freetype2.h"
@end

/*
 * definition of structure ft2_bitmap_s
 */

/*
 * methods of structure ft2_face_s
 */

bool ft2_face_s::measure_text(const ui_array_s &a_text,unsigned &a_width)
{/*{{{*/
  a_width = 0;

  FT_GlyphSlot slot = face->glyph;

  FT_Pos origin_x = 0;
  FT_Pos prev_rsb_delta = 0;

  FT_UInt glyph = 0;
  FT_UInt last_glyph = 0;

  FT_Vector kerning;

  if (a_text.used > 1)
  {
    unsigned *c_ptr = a_text.data;
    unsigned *c_ptr_end = c_ptr + a_text.used - 1;
    do {

      // - ERROR -
      if ((glyph = FT_Get_Char_Index(face,*c_ptr)) == 0)
      {
        return false;
      }

      if (last_glyph != 0)
      {
        // - ERROR -
        if (FT_Get_Kerning(face,last_glyph,glyph,FT_KERNING_DEFAULT,&kerning))
        {
          return false;
        }

        origin_x += kerning.x;
      }

      // - ERROR -
      if (FT_Load_Glyph(face,glyph,0))
      {
        return false;
      }

      if (prev_rsb_delta - slot->lsb_delta >  32)
      {
        origin_x -= 64;
      }
      else if (prev_rsb_delta - slot->lsb_delta < -31)
      {
        origin_x += 64;
      }

      prev_rsb_delta = slot->rsb_delta;
      origin_x += slot->advance.x;

      last_glyph = glyph;
    } while(++c_ptr < c_ptr_end);
  }

  a_width = origin_x >> 6;

  return true;
}/*}}}*/

bool ft2_face_s::render_text(const ui_array_s &a_text,ft2_bitmap_s &a_bitmap)
{/*{{{*/
  //FT_Size_Metrics *metrics = &ftf_ptr->face->size->metrics;

  //FT_Pos ascender = metrics->ascender >> 6;
  //FT_Pos descender = metrics->descender >> 6;

  return true;
}/*}}}*/

