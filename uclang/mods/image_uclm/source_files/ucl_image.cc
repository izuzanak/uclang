
@begin
include "ucl_image.h"
@end

/*
 * methods of structure image_s
 */

bool image_s::operator==(image_s &a_second)
{/*{{{*/
  if (pixel_format != a_second.pixel_format)
  {
    return false;
  }

  if (pixel_format == c_image_pixel_format_blank)
  {
    return true;
  }

  if (width != a_second.width || height != a_second.height)
  {
    return false;
  }

  unsigned s_pixel_step = a_second.pixel_step;
  unsigned line_size = image_data_ptr->line_bytes;
  unsigned s_line_size = a_second.image_data_ptr->line_bytes;
  unsigned image_ls = width*pixel_step;

  unsigned char *ptr = image_data_ptr->data + y_pos*line_size + x_pos*pixel_step;
  unsigned char *ptr_end = ptr + (height - 1)*line_size + width*pixel_step;
  unsigned char *s_ptr = a_second.image_data_ptr->data + a_second.y_pos*s_line_size + a_second.x_pos*s_pixel_step;

  do {
    if (memcmp(ptr,s_ptr,image_ls) != 0) {
      return false;
    }

    ptr += line_size;
    s_ptr += s_line_size;
  } while(ptr < ptr_end);

  return true;
}/*}}}*/

bool image_s::create_header(unsigned a_width,unsigned a_height,unsigned a_pixel_format)
{/*{{{*/
  clear();
  if (a_width == 0 || a_height == 0 || a_pixel_format == c_image_pixel_format_blank)
  {
    return false;
  }

  root = true;
  pixel_format = a_pixel_format;
  width = a_width;
  height = a_height;
  x_pos = 0;
  y_pos = 0;
  pixel_step = c_pixel_sizes[pixel_format];

  // - compute line bytes count -
  unsigned tmp_line_bytes = width*pixel_step;
  if (tmp_line_bytes & (sizeof(int) - 1))
  {
    tmp_line_bytes = (tmp_line_bytes & ~(sizeof(int) - 1)) + sizeof(int);
  }

  // - creation of image data -
  image_data_ptr = (image_data_s *)cmalloc(sizeof(image_data_s));
  image_data_ptr->reference_cnt.atomic_set(1);
  image_data_ptr->line_bytes = tmp_line_bytes;
  image_data_ptr->data = NULL;

  return true;
}/*}}}*/

bool image_s::create_referred(unsigned a_x_pos,unsigned a_y_pos,unsigned a_width,unsigned a_height,image_s &a_src)
{/*{{{*/
  clear();
  if (a_src.pixel_format == c_image_pixel_format_blank || a_width == 0 || a_height == 0 || a_x_pos + a_width > a_src.width || a_y_pos + a_height > a_src.height)
  {
    return false;
  }

  root = false;
  pixel_format = a_src.pixel_format;
  width = a_width;
  height = a_height;
  x_pos = a_src.x_pos + a_x_pos;
  y_pos = a_src.y_pos + a_y_pos;
  pixel_step = a_src.pixel_step;

  image_data_ptr = a_src.image_data_ptr;
  image_data_ptr->reference_cnt.atomic_inc();

  return true;
}/*}}}*/

bool image_s::io_clear()
{/*{{{*/
  if (pixel_format == c_image_pixel_format_blank)
  {
    return false;
  }

  unsigned line_size = image_data_ptr->line_bytes;
  unsigned image_ls = width*pixel_step;

  unsigned char *ptr = image_data_ptr->data + y_pos*line_size + x_pos*pixel_step;
  unsigned char *ptr_end = ptr + (height - 1)*line_size + width*pixel_step;

  do {
    memset(ptr,0,image_ls);

    ptr += line_size;
  } while(ptr < ptr_end);

  return true;
}/*}}}*/

bool image_s::io_fill(unsigned char *a_color)
{/*{{{*/
  if (pixel_format == c_image_pixel_format_blank)
  {
    return false;
  }

  unsigned line_size = image_data_ptr->line_bytes;
  unsigned image_ls = width*pixel_step;

  unsigned char *ptr = image_data_ptr->data + y_pos*line_size + x_pos*pixel_step;
  unsigned char *ptr_end = ptr + (height - 1)*line_size + width*pixel_step;

#define IMAGE_FILL(OPERATION) \
  {\
    do {\
      unsigned char *ptr_w_end = ptr + image_ls;\
      do {\
        OPERATION;\
      } while((ptr += pixel_step) < ptr_w_end);\
      \
      ptr += line_size - image_ls;\
    } while(ptr < ptr_end);\
  }


  switch (pixel_format)
  {
    case c_image_pixel_format_GRAY8:
      IMAGE_FILL(
          *ptr = *a_color;
          );
      break;
    case c_image_pixel_format_RGB24:
      IMAGE_FILL(
          ptr[0] = a_color[0];
          ptr[1] = a_color[1];
          ptr[2] = a_color[2];
          );
      break;
    case c_image_pixel_format_RGBA:
      IMAGE_FILL(
          ptr[0] = a_color[0];
          ptr[1] = a_color[1];
          ptr[2] = a_color[2];
          ptr[3] = a_color[3];
          );
      break;
    default:
      return false;;
  }

  return true;
}/*}}}*/

bool image_s::io_copy(image_s &a_src)
{/*{{{*/
   if (pixel_format != a_src.pixel_format || width != a_src.width || height != a_src.height || pixel_format == c_image_pixel_format_blank)
   {
      return false;
   }

   unsigned s_pixel_step = a_src.pixel_step;
   unsigned line_size = image_data_ptr->line_bytes;
   unsigned s_line_size = a_src.image_data_ptr->line_bytes;
   unsigned image_ls = width*pixel_step;

   unsigned char *ptr = image_data_ptr->data + y_pos*line_size + x_pos*pixel_step;
   unsigned char *ptr_end = ptr + (height - 1)*line_size + width*pixel_step;
   unsigned char *s_ptr = a_src.image_data_ptr->data + a_src.y_pos*s_line_size + a_src.x_pos*s_pixel_step;

   do {
      memcpy(ptr,s_ptr,image_ls);

      ptr += line_size;
      s_ptr += s_line_size;
   } while(ptr < ptr_end);

   return true;
}/*}}}*/

/*
 * methods of structure png_data_s
 */

void png_data_s::read_data(png_structp a_png_ptr,png_bytep a_data,png_size_t a_length)
{/*{{{*/

  // - retrieve png data structure pointer -
  png_data_s *pd_ptr = (png_data_s *)png_get_io_ptr(a_png_ptr);

  // - check requested data size -
  if (pd_ptr->read + a_length > pd_ptr->size)
  {
    png_error(a_png_ptr,"EOF");
    return;
  }

  // - copy data to target buffer -
  memcpy(a_data,pd_ptr->data + pd_ptr->read,a_length);
  pd_ptr->read += a_length;
}/*}}}*/

/*
 * methods of structure jpeg_error_mgr_s
 */

void jpeg_error_mgr_s::error_exit(j_common_ptr cinfo)
{/*{{{*/
  longjmp(((jpeg_error_mgr_s *)cinfo->err)->jump_buffer,1);
}/*}}}*/

/*
 * static members of structure jpeg_source_mgr_s
 */

JOCTET jpeg_source_mgr_s::EOI_BYTE = JPEG_EOI;

/*
 * methods of structure jpeg_source_mgr_s
 */

void jpeg_source_mgr_s::init_source(j_decompress_ptr cinfo)
{/*{{{*/
}/*}}}*/

boolean jpeg_source_mgr_s::fill_buffer(j_decompress_ptr cinfo)
{/*{{{*/
  jpeg_source_mgr_s *src = (jpeg_source_mgr_s *)cinfo->src;

  src->pub.next_input_byte = (JOCTET *)&EOI_BYTE;
  src->pub.bytes_in_buffer = 1;

  return TRUE;
}/*}}}*/

void jpeg_source_mgr_s::skip_data(j_decompress_ptr cinfo,long num_bytes)
{/*{{{*/
  jpeg_source_mgr_s *src = (jpeg_source_mgr_s *)cinfo->src;

  if (src->pub.bytes_in_buffer < (size_t)num_bytes)
  {
    src->pub.next_input_byte = (JOCTET *)&EOI_BYTE;
    src->pub.bytes_in_buffer = 1;
  }
  else
  {
    src->pub.next_input_byte += num_bytes;
    src->pub.bytes_in_buffer -= num_bytes;
  }
}/*}}}*/

void jpeg_source_mgr_s::term_source(j_decompress_ptr cinfo)
{/*{{{*/
}/*}}}*/

void jpeg_source_mgr_s::set_source(j_decompress_ptr cinfo,const char *data,unsigned length)
{/*{{{*/
  cinfo->src = (struct jpeg_source_mgr *)(*cinfo->mem->alloc_small)((j_common_ptr)cinfo,JPOOL_PERMANENT,sizeof(jpeg_source_mgr_s));
  jpeg_source_mgr_s *src = (jpeg_source_mgr_s *)cinfo->src;

  src->pub.init_source = init_source;
  src->pub.fill_input_buffer = fill_buffer;
  src->pub.skip_input_data = skip_data;
  src->pub.resync_to_restart = jpeg_resync_to_restart;
  src->pub.term_source = term_source;

  src->data = (const JOCTET *)data;
  src->length = length;
  src->pub.bytes_in_buffer = length;
  src->pub.next_input_byte = src->data;
}/*}}}*/

