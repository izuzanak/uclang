
@begin
include "ucl_imxegl.h"
@end

// - imxegl global init object -
imxegl_c g_imxegl;

#ifdef IPUROT_LINUX
// - read framebuffer properties -
bool read_framebuffer_properties(int fd,struct framebuffer_props_s *props)
{/*{{{*/
  unsigned long smem_info[7];

  if (ioctl(fd,MXCFB_GET_SMEM_INFO,smem_info) < 0)
  {
    return 0;
  }

  props->smem_start     = smem_info[0];
  props->rot_smem_start = smem_info[1];
  props->smem_len       = smem_info[2];
  props->stride         = smem_info[3];
  props->xres           = smem_info[4];
  props->yres           = smem_info[5];
  props->bits_per_pixel = smem_info[6];

  props->bytes_per_pixel   = props->bits_per_pixel/8;
  props->pixels_per_stride = props->stride/props->bytes_per_pixel;
  props->buffer_size       = props->stride*props->yres;

  props->second_buffer = props->smem_len >= (props->stride*props->yres << 1);

  return 1;
}/*}}}*/
#endif

