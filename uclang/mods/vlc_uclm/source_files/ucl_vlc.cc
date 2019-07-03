
@begin
include "ucl_vlc.h"
@end

extern const unsigned c_vlc_chroma_sizes[] =
{/*{{{*/
  1,
  3,
};/*}}}*/

const char *c_vlc_chroma_fourcc[] =
{/*{{{*/
  "Y800",
  "RV24",
};/*}}}*/

void *vlc_player_s::lock(void *user,void **p_pixels)
{/*{{{*/
  vlc_player_s *vp_ptr = (vlc_player_s *)user;
  cassert(((mutex_s *)vp_ptr->mutex_loc->v_data_ptr)->lock() == c_error_OK);

  *p_pixels = vp_ptr->pixels;
  
  return nullptr;
}/*}}}*/

void vlc_player_s::unlock(void *user,void *id,void *const *p_pixels)
{/*{{{*/
  vlc_player_s *vp_ptr = (vlc_player_s *)user;
  cassert(((mutex_s *)vp_ptr->mutex_loc->v_data_ptr)->unlock() == c_error_OK);
}/*}}}*/

void vlc_player_s::display(void *user,void *id)
{/*{{{*/
  vlc_player_s *vp_ptr = (vlc_player_s *)user;
  ++vp_ptr->frame_count;
}/*}}}*/

