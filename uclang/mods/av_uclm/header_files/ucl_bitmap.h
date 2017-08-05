
#ifndef __UCL_BITMAP_H
#define __UCL_BITMAP_H

@begin
   include "basic.h"
   include "ucl_string.h"
@end

/*
 * definition of structure bitmap_s
 */

#pragma pack(1)
struct bmp_file_header_s
{
  short type;
  int size;
  short res_1;
  short res_2;
  int off_bits;
};
#pragma pack()

#pragma pack(1)
struct bmp_image_header_s
{
  int size;
  int width;
  int height;
  short planes;
  short bit_cnt;
  int compression;
  int image_size;
  int x_pel_per_meter;
  int y_pel_per_meter;
  int clr_used;
  int clr_important;
};
#pragma pack()

struct bitmap_s
{
  bmp_file_header_s fh;
  bmp_image_header_s ih;
  unsigned char *data;

  inline void init();
  inline void clear();

  /*!
   * \brief load bitmap from file
   */
  bool load_from_file(const char *a_file);

  /*!
   * \brief save bitmap to file
   */
  bool save_to_file(const char *a_file);

  /*!
   * \brief create bitmap from buffer
   */
  bool from_RGB24(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height);
  bool from_BGR24(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height);
  bool from_RGBA32(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height);
  bool from_BGRA32(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height);

  /*!
   * \brief retrieve string representing bitmap
   */
  bool data_string(string_s &a_target);
};

/*
 * inline methods of structure bitmap_s
 */

inline void bitmap_s::init()
{/*{{{*/
  data = nullptr;
}/*}}}*/

inline void bitmap_s::clear()
{/*{{{*/
  if (data != nullptr) {
    cfree(data);
    data = nullptr;
  }
}/*}}}*/

#endif

