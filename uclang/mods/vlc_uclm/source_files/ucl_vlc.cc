
@begin
include "ucl_vlc.h"
@end

extern const unsigned c_vlc_chroma_sizes[] =
{/*{{{*/
  3,
};/*}}}*/

const char *c_vlc_chroma_fourcc[] =
{/*{{{*/
  "RV24",
};/*}}}*/

void *vlc_player_s::lock(void *data,void **p_pixels)
{/*{{{*/

  // FIXME debug output
  fprintf(stderr,"vlc_player_s::lock\n");
  
  vlc_player_s *vp_ptr = (vlc_player_s *)data;

  void *id = cmalloc(vp_ptr->height*vp_ptr->pitch);
  *p_pixels = id;
  
  // FIXME TODO continue ...

  return id;
}/*}}}*/

void vlc_player_s::unlock(void *data,void *id,void *const *p_pixels)
{/*{{{*/
  
  // FIXME debug output
  fprintf(stderr,"vlc_player_s::unlock\n");
  
  // FIXME TODO continue ...
}/*}}}*/

void vlc_player_s::display(void *data,void *id)
{/*{{{*/
  
  // FIXME debug output
  fprintf(stderr,"vlc_player_s::display\n");

  cfree(id);

  // FIXME TODO continue ...
}/*}}}*/

