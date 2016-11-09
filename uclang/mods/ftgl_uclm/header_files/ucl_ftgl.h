
#ifndef __UCL_FTGL_H
#define __UCL_FTGL_H

@begin
include "script_parser.h"
include "freetype-gl.h"
include "vertex-buffer.h"
@end

/*
 * definition of structure gl_vertex_buffer_s
 */

struct gl_vertex_buffer_s
{
  vertex_buffer_t *buffer_ptr;
  unsigned vert_attr_cnt;
  unsigned vert_item_cnt;
  ui_array_s vert_item_types;
  unsigned vert_size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure gl_font_s
 */

struct gl_font_s
{
  texture_atlas_t *atlas_ptr;
  texture_font_t *font_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure gl_font_buffer_s
 */

struct gl_font_buffer_s
{
  location_s *font_ptr;
  vertex_buffer_t *buffer_ptr;
  int pos_x;
  int pos_y;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class ftgl_c
 */
class ftgl_c
{
  public:
  inline ftgl_c();
  inline ~ftgl_c();
};

/*
 * inline methods of structure gl_vertex_buffer_s
 */

inline void gl_vertex_buffer_s::init()
{/*{{{*/
  buffer_ptr = NULL;
  vert_attr_cnt = 0;
  vert_item_cnt = 0;
  vert_item_types.init();;
  vert_size = 0;
}/*}}}*/

inline void gl_vertex_buffer_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release vertex buffer pointer -
  if (buffer_ptr != NULL)
  {
    vertex_buffer_delete(buffer_ptr);
  }

  // - release vertex item types -
  vert_item_types.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure gl_font_s
 */

inline void gl_font_s::init()
{/*{{{*/
  atlas_ptr = NULL;
  font_ptr = NULL;
}/*}}}*/

inline void gl_font_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release texture font -
  if (font_ptr != NULL)
  {
    texture_font_delete(font_ptr);
  }

  // - release texture atlas -
  if (atlas_ptr != NULL)
  {
    texture_atlas_delete(atlas_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure gl_font_buffer_s
 */

inline void gl_font_buffer_s::init()
{/*{{{*/
  font_ptr = NULL;
  buffer_ptr = NULL;

  pos_x = 0;
  pos_y = 0;
}/*}}}*/

inline void gl_font_buffer_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - relese font pointer -
  if (font_ptr != NULL)
  {
    it.release_location_ptr(font_ptr);
  }

  // - release vertex buffer pointer -
  if (buffer_ptr != NULL)
  {
    vertex_buffer_delete(buffer_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class ftgl_c
 */

inline ftgl_c::ftgl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ftgl_init()\n"););
}/*}}}*/

inline ftgl_c::~ftgl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ftgl_exit()\n"););
}/*}}}*/

#endif

