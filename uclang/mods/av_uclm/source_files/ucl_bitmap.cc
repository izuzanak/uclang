
@begin
   include "ucl_bitmap.h"
@end

/*
 * methods of structure bitmap_s
 */

bool bitmap_s::load_from_file(const char *a_file)
{/*{{{*/
  FILE *f = fopen(a_file,"rb");
  if (f == nullptr) {
    return false;
  }

  if (fread(&fh,sizeof(bmp_file_header_s),1,f) != 1 ||
      fh.type != 0x4d42)
  {
    fclose(f);
    return false;
  }

  if (fread(&ih,sizeof(bmp_image_header_s),1,f) != 1 ||
      ih.planes != 1 || ih.bit_cnt != 32)
  {
    fclose(f);
    return false;
  }

  clear();

  int image_size = ih.width*ih.height*4;

  int headers_size = sizeof(bmp_file_header_s) + sizeof(bmp_image_header_s);
  if (fh.off_bits > headers_size) {
    fseek(f,fh.off_bits - headers_size,SEEK_CUR);
  }

  data = (unsigned char *)cmalloc(image_size*sizeof(unsigned char));

  if (fread(data,image_size,1,f) != 1)
  {
    cfree(data);
    fclose(f);
    return false;
  }

  fclose(f);

  return true;
}/*}}}*/

bool bitmap_s::save_to_file(const char *a_file)
{/*{{{*/
  FILE *f = fopen(a_file,"wb");
  if (f == nullptr) {
    return false;
  }

  fwrite(&fh,sizeof(bmp_file_header_s),1,f);
  fwrite(&ih,sizeof(bmp_image_header_s),1,f);
  fwrite(data,ih.image_size,1,f);

  fclose(f);

  return true;
}/*}}}*/

#define BITMAP_FROM_BUFFER(BYTES,PIXEL_CODE) \
{/*{{{*/\
  clear();\
\
  int b_line_size = a_width*4;\
  int image_size = a_height*b_line_size;\
\
  fh.type = 0x4d42;\
  fh.size = image_size + sizeof(bmp_file_header_s) + sizeof(bmp_image_header_s);\
  fh.res_1 = 0;\
  fh.res_2 = 0;\
  fh.off_bits = sizeof(bmp_file_header_s) + sizeof(bmp_image_header_s);\
\
  ih.size = sizeof(bmp_image_header_s);\
  ih.width = a_width;\
  ih.height = a_height;\
  ih.planes = 1;\
  ih.bit_cnt = 32;\
  ih.compression = 0;\
  ih.image_size = image_size;\
  ih.x_pel_per_meter = 0;\
  ih.y_pel_per_meter = 0;\
  ih.clr_used = 0;\
  ih.clr_important = 0;\
\
  data = (unsigned char *)cmalloc(image_size*sizeof(unsigned char));\
  unsigned image_ls = a_width*BYTES;\
\
  const unsigned char *ptr = a_data;\
  const unsigned char *ptr_end = ptr + (a_height - 1)*a_line_size + a_width*BYTES;\
  unsigned char *b_ptr = data + (a_height - 1)*b_line_size;\
\
  do {\
    const unsigned char *ptr_w_end = ptr + image_ls;\
    do {\
      PIXEL_CODE;\
    } while(b_ptr += 4,(ptr += BYTES) < ptr_w_end);\
\
    ptr += a_line_size - image_ls;\
    b_ptr -= b_line_size << 1;\
  } while(ptr < ptr_end);\
\
  return true;\
}/*}}}*/

bool bitmap_s::from_RGB24(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height)
{/*{{{*/
  BITMAP_FROM_BUFFER(3,
     b_ptr[0] = ptr[2];
     b_ptr[1] = ptr[1];
     b_ptr[2] = ptr[0];
     b_ptr[3] = 255;
  );

  return true;
}/*}}}*/

bool bitmap_s::from_BGR24(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height)
{/*{{{*/
  BITMAP_FROM_BUFFER(3,
     b_ptr[0] = ptr[0];
     b_ptr[1] = ptr[1];
     b_ptr[2] = ptr[2];
     b_ptr[3] = 255;
  );

  return true;
}/*}}}*/

bool bitmap_s::from_RGBA32(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height)
{/*{{{*/
  BITMAP_FROM_BUFFER(4,
     b_ptr[0] = ptr[2];
     b_ptr[1] = ptr[1];
     b_ptr[2] = ptr[0];
     b_ptr[3] = ptr[3];
  );

  return true;
}/*}}}*/

bool bitmap_s::from_BGRA32(const unsigned char *a_data,unsigned a_line_size,unsigned a_width,unsigned a_height)
{/*{{{*/
  BITMAP_FROM_BUFFER(4,
     b_ptr[0] = ptr[0];
     b_ptr[1] = ptr[1];
     b_ptr[2] = ptr[2];
     b_ptr[3] = ptr[3];
  );

  return true;
}/*}}}*/

bool bitmap_s::data_string(string_s &a_target)
{/*{{{*/
  unsigned data_size = sizeof(bmp_file_header_s) + sizeof(bmp_image_header_s) + ih.image_size;
  a_target.create(data_size);

  char *ptr = a_target.data;
  memcpy(ptr,&fh,sizeof(bmp_file_header_s));
  ptr += sizeof(bmp_file_header_s);

  memcpy(ptr,&ih,sizeof(bmp_image_header_s));
  ptr += sizeof(bmp_image_header_s);

  memcpy(ptr,data,ih.image_size);

  return true;
}/*}}}*/

