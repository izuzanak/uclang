
@begin
include "ucl_freetype2.h"
@end

/*
 * definition of structure ft2_bitmap_s
 */

void ft2_bitmap_s::copy_glyph_bitmap(unsigned x_pos,unsigned y_pos,FT_GlyphSlot glyph_slot)
{/*{{{*/
  FT_Bitmap &bitmap = glyph_slot->bitmap;

  // - bitmap is not empty -
  if (bitmap.width != 0 && bitmap.rows != 0)
  {
    x_pos += glyph_slot->bitmap_left;
    y_pos -= glyph_slot->bitmap_top;

    unsigned row_idx = 0;
    do {
      unsigned char *g_ptr = bitmap.buffer + row_idx*bitmap.pitch;
      unsigned char *g_ptr_end = g_ptr + bitmap.width;
      unsigned char *b_ptr = data + (y_pos + row_idx)*width + x_pos;
      do {
        if (*g_ptr > *b_ptr) { *b_ptr = *g_ptr; }
      } while(++b_ptr,++g_ptr < g_ptr_end);
    } while(++row_idx < bitmap.rows);
  }
}/*}}}*/

/*
 * methods of structure ft2_face_s
 */

bool ft2_face_s::measure_text(const ui_array_s &a_text,
    int &a_left,int &a_top,unsigned &a_width,unsigned &a_height)
{/*{{{*/
  a_left = 0;
  a_top = 0;
  a_width = 0;
  a_height = 0;

  int max_bottom = 0;

  FT_GlyphSlot glyph_slot = face->glyph;

  FT_Pos origin_x = 0;
  FT_Pos last_rsb_delta = 0;

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
      if (FT_Load_Glyph(face,glyph,FT_LOAD_DEFAULT))
      {
        return false;
      }

      if (last_rsb_delta - glyph_slot->lsb_delta >  32)
      {
        origin_x -= 64;
      }
      else if (last_rsb_delta - glyph_slot->lsb_delta < -31)
      {
        origin_x += 64;
      }

      if (glyph_slot->bitmap_top > a_top) { a_top = glyph_slot->bitmap_top; }

      // - first glyph only -
      if (last_glyph == 0)
      {
        if (-glyph_slot->bitmap_left > a_left) { a_left = -glyph_slot->bitmap_left; }
      }

      int bottom = glyph_slot->bitmap.rows - glyph_slot->bitmap_top;
      if (bottom > max_bottom) { max_bottom = bottom; }

      origin_x += glyph_slot->advance.x;

      last_rsb_delta = glyph_slot->rsb_delta;
      last_glyph = glyph;
    } while(++c_ptr < c_ptr_end);
  }

  a_width = a_left + ((origin_x - glyph_slot->advance.x) >> 6) +
    glyph_slot->bitmap_left + glyph_slot->bitmap.width;

  a_height = a_top + max_bottom;

  return true;
}/*}}}*/

bool ft2_face_s::render_text(const ui_array_s &a_text,ft2_bitmap_s &a_bitmap,
    int a_left,int a_top)
{/*{{{*/
  FT_GlyphSlot glyph_slot = face->glyph;

  FT_Pos origin_x = a_left << 6;
  FT_Pos last_rsb_delta = 0;

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
      if (FT_Load_Glyph(face,glyph,FT_LOAD_RENDER))
      {
        return false;
      }

      if (last_rsb_delta - glyph_slot->lsb_delta >  32)
      {
        origin_x -= 64;
      }
      else if (last_rsb_delta - glyph_slot->lsb_delta < -31)
      {
        origin_x += 64;
      }

      // - copy glyph to bitmap -
      a_bitmap.copy_glyph_bitmap(origin_x >> 6,a_top,glyph_slot);

      origin_x += glyph_slot->advance.x;

      last_rsb_delta = glyph_slot->rsb_delta;
      last_glyph = glyph;
    } while(++c_ptr < c_ptr_end);
  }

  return true;
}/*}}}*/

