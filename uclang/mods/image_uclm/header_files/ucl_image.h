
#ifndef __UCL_IMAGE_H
#define __UCL_IMAGE_H

@begin
include "script_parser.h"
@end

#include "png.h"
#include "jpeglib.h"

// - conversions -
#define c_icsv ((sizeof(int) - sizeof(char)) << 3)
#define c_lliisv ((sizeof(long long int) - sizeof(int)) << 3)
#define c_ulluisv ((sizeof(long long unsigned) - sizeof(unsigned)) << 3)

// - pixel formats -
const unsigned c_pixel_format_cnt = 3;
enum {
  c_image_pixel_format_GRAY8 = 0,
  c_image_pixel_format_RGB24,
  c_image_pixel_format_RGBA,

  c_image_pixel_format_blank,
};

// - sizes of pixels by format in bytes -
const unsigned c_bigest_pixel_size = 4*sizeof(unsigned char);
const unsigned c_pixel_sizes[c_pixel_format_cnt] = 
{
  sizeof(unsigned char),
  3*sizeof(unsigned char),
  4*sizeof(unsigned char),
};

const unsigned c_pixel_values_cnt[c_pixel_format_cnt] =
{
  1,
  3,
  4,
};

/*
 * definition of structure image_s
 */

struct image_data_s
{
  unsigned line_bytes;
  atomic_s reference_cnt;
  unsigned char *data;
};

struct image_s
{
  bool root;
  unsigned pixel_format;
  unsigned width;
  unsigned height;
  unsigned x_pos;
  unsigned y_pos;
  unsigned pixel_step;
  image_data_s *image_data_ptr;

  inline void init();
  inline void clear();
  inline void flush_all() {}
  inline void swap(image_s &a_second);
  inline image_s &operator=(image_s &a_src);
  bool operator==(image_s &a_second);

  bool create_header(unsigned a_width,unsigned a_height,unsigned a_pixel_format);
  inline bool create(unsigned a_width,unsigned a_height,unsigned a_pixel_format);
  inline bool create(image_s &a_img);
  bool create_referred(unsigned a_x_pos,unsigned a_y_pos,unsigned a_width,unsigned a_height,image_s &a_src);

  bool io_clear();
  bool io_fill(unsigned char *a_color);
  bool io_copy(image_s &a_src);
};

/*
 * definition of structure png_data_s
 */

struct png_data_s
{
  const char *data;
  unsigned size;
  unsigned read;

  static void read_data(png_structp a_png_ptr,png_bytep a_data,png_size_t a_length);
};

/*
 * definition of structure jpeg_error_mgr_s
 */

struct jpeg_error_mgr_s
{
  jpeg_error_mgr pub;
  jmp_buf jump_buffer;

  static void error_exit(j_common_ptr cinfo);
};

/*
 * definition of structure jpeg_source_mgr_s
 */

struct jpeg_source_mgr_s
{
  static JOCTET EOI_BYTE;

  jpeg_source_mgr pub;
  const JOCTET *data;
  unsigned length;

  static void init_source(j_decompress_ptr cinfo);
  static boolean fill_buffer(j_decompress_ptr cinfo);
  static void skip_data(j_decompress_ptr cinfo,long num_bytes);
  static void term_source(j_decompress_ptr cinfo);
  static void set_source(j_decompress_ptr cinfo,const char *data,unsigned length);
};

/*
 * inline methods of structure image_s
 */

inline void image_s::init()
{/*{{{*/
  pixel_format = c_image_pixel_format_blank;
}/*}}}*/

inline void image_s::clear()
{/*{{{*/
  if (pixel_format != c_image_pixel_format_blank)
  {
    if (image_data_ptr->reference_cnt.atomic_dec_and_test())
    {
      cfree(image_data_ptr->data);
      cfree(image_data_ptr);
    }
  }

  init();
}/*}}}*/

inline void image_s::swap(image_s &a_second)
{/*{{{*/
  bool tmp_root = root;
  root = a_second.root;
  a_second.root = tmp_root;

  unsigned tmp_unsigned = pixel_format;
  pixel_format = a_second.pixel_format;
  a_second.pixel_format = tmp_unsigned;

  tmp_unsigned = width;
  width = a_second.width;
  a_second.width = tmp_unsigned;

  tmp_unsigned = height;
  height = a_second.height;
  a_second.height = tmp_unsigned;

  tmp_unsigned = x_pos;
  x_pos = a_second.x_pos;
  a_second.x_pos = tmp_unsigned;

  tmp_unsigned = y_pos;
  y_pos = a_second.y_pos;
  a_second.y_pos = tmp_unsigned;

  tmp_unsigned = pixel_step;
  pixel_step = a_second.pixel_step;
  a_second.pixel_step = tmp_unsigned;

  image_data_s *tmp_image_data_ptr = image_data_ptr;
  image_data_ptr = a_second.image_data_ptr;
  a_second.image_data_ptr = tmp_image_data_ptr;
}/*}}}*/

inline image_s &image_s::operator=(image_s &a_src)
{/*{{{*/
  if (a_src.pixel_format == c_image_pixel_format_blank)
  {
    clear();
  }
  else
  {
    create(a_src.width,a_src.height,a_src.pixel_format);
    io_copy(a_src);
  }

  return *this;
}/*}}}*/

inline bool image_s::create(unsigned a_width,unsigned a_height,unsigned a_pixel_format)
{/*{{{*/
  if (!create_header(a_width,a_height,a_pixel_format))
  {
    return false;
  }

  image_data_ptr->data = (unsigned char *)cmalloc(height*image_data_ptr->line_bytes);
  memset(image_data_ptr->data,0,height*image_data_ptr->line_bytes);

  return true;
}/*}}}*/

inline bool image_s::create(image_s &a_img)
{/*{{{*/
   return create(a_img.width,a_img.height,a_img.pixel_format);
}/*}}}*/

#endif

