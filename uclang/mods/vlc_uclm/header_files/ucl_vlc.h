
#ifndef __UCL_VLC_H
#define __UCL_VLC_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <vlc/vlc.h>

enum
{/*{{{*/
  c_vlc_chroma_Y800 = 0,
  c_vlc_chroma_RV24,
  c_vlc_chroma_count,
};/*}}}*/

// - vlc chroma size in bytes -
extern const unsigned c_vlc_chroma_sizes[];

// - vlc chroma fourcc codes -
extern const char *c_vlc_chroma_fourcc[];

/*
 * definition of structure vlc_media_s
 */

struct vlc_media_s
{
  location_s *instance_loc;
  libvlc_media_t *media_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure vlc_player_s
 */

struct vlc_player_s
{
  location_s *instance_loc;
  location_s *mutex_loc;
  libvlc_media_player_t *player_ptr;
  unsigned chroma;
  unsigned width;
  unsigned height;
  unsigned pitch;

  long long int frame_count;
  void *pixels;

  static void *lock(void *user,void **p_pixels);
  static void unlock(void *user,void *id,void *const *p_pixels);
  static void display(void *user,void *id);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure vlc_media_s
 */

inline void vlc_media_s::init()
{/*{{{*/
  instance_loc = nullptr;
  media_ptr = nullptr;
}/*}}}*/

inline void vlc_media_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (media_ptr != nullptr)
  {
    libvlc_media_release(media_ptr);
  }

  if (instance_loc != nullptr)
  {
    it.release_location_ptr(instance_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure vlc_player_s
 */

inline void vlc_player_s::init()
{/*{{{*/
  instance_loc = nullptr;
  mutex_loc = nullptr;
  player_ptr = nullptr;
  pixels = nullptr;
}/*}}}*/

inline void vlc_player_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (player_ptr != nullptr)
  {
    libvlc_media_player_release(player_ptr);
  }

  if (instance_loc != nullptr)
  {
    it.release_location_ptr(instance_loc);
  }

  if (mutex_loc != nullptr)
  {
    it.release_location_ptr(mutex_loc);
  }

  if (pixels != nullptr)
  {
    cfree(pixels);
  }

  init();
}/*}}}*/

#endif

