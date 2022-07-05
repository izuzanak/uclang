
#ifndef __UCL_FREETYPE2_H
#define __UCL_FREETYPE2_H

@begin
include "script_parser.h"
@end

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

/*
 * constants and definitions
 */

extern unsigned c_rm_class_unicode_string;

/*
 * definition of structure ft2_bitmap_s
 */

struct ft2_bitmap_s
{
  unsigned width;
  unsigned height;
  unsigned baseline;
  unsigned char *data;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  void copy_glyph_bitmap(unsigned x_pos,unsigned y_pos,FT_GlyphSlot glyph_slot);
};

/*
 * definition of structure ft2_face_s
 */

struct ft2_face_s
{
  FT_Face face;
  location_s *library_loc;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  bool measure_text(const ui_array_s &a_text,
      int &a_left,int &a_top,unsigned &a_width,unsigned &a_height);
  bool render_text(const ui_array_s &a_text,ft2_bitmap_s &a_bitmap,
      int a_left,int a_top);
};

/*
 * inline methods of structure ft2_bitmap_s
 */

inline void ft2_bitmap_s::init()
{/*{{{*/
  data = nullptr;
}/*}}}*/

inline void ft2_bitmap_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ft2_face_s
 */

inline void ft2_face_s::init()
{/*{{{*/
  face = nullptr;
  library_loc = nullptr;
}/*}}}*/

inline void ft2_face_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (face != nullptr)
  {
    FT_Done_Face(face);
  }

  if (library_loc != nullptr)
  {
    it.release_location_ptr(library_loc);
  }

  init();
}/*}}}*/

#endif

