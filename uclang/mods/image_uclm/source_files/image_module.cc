
@begin
include "image_module.h"
@end

// - IMAGE indexes of built in classes -
unsigned c_bi_class_image = c_idx_not_exist;

// - IMAGE module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  image_classes,          // Classes

  0,                      // Error base index
  14,                     // Error count
  image_error_strings,    // Error strings

  image_initialize,       // Initialize function
  image_print_exception,  // Print exceptions function
};/*}}}*/

// - IMAGE classes -
built_in_class_s *image_classes[] =
{/*{{{*/
  &image_class,
};/*}}}*/

// - IMAGE error strings -
const char *image_error_strings[] =
{/*{{{*/
  "error_IMAGE_WRONG_PROPERTIES",
  "error_IMAGE_UNSUPPORTED_PIXEL_FORMAT",
  "error_IMAGE_CANNOT_GET_BUFFER_OF_NON_ROOT_IMAGE",
  "error_IMAGE_CANNOT_OPEN_FILE",
  "error_IMAGE_FILE_IS_NOT_PNG_FILE",
  "error_IMAGE_PNG_READ_INIT_ERROR",
  "error_IMAGE_PNG_WRITE_INIT_ERROR",
  "error_IMAGE_PNG_DATA_READ_ERROR",
  "error_IMAGE_PNG_FILE_READ_ERROR",
  "error_IMAGE_PNG_FILE_WRITE_ERROR",
  "error_IMAGE_JPEG_FILE_READ_ERROR",
  "error_IMAGE_JPEG_FILE_WRITE_ERROR",
  "error_IMAGE_IMAGE_OPERATION_ERROR",
  "error_IMAGE_IMAGE_OPERATION_INVALID_COLOR",
};/*}}}*/

// - IMAGE initialize -
bool image_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize image class identifier -
  c_bi_class_image = class_base_idx++;

  return true;
}/*}}}*/

// - IMAGE print exception -
bool image_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_IMAGE_WRONG_PROPERTIES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong properties (dimensions, pixel format) of image\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported pixel format of image\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_CANNOT_GET_BUFFER_OF_NON_ROOT_IMAGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get buffer of non root image\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_CANNOT_OPEN_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open image file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_FILE_IS_NOT_PNG_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFile \"%s\" is not regular PNG file\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_PNG_READ_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot initialize PNG read structures\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_PNG_WRITE_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot initialize PNG write structures\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_PNG_DATA_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read image from PNG data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_PNG_FILE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read image from PNG file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_PNG_FILE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot write image to PNG file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_JPEG_FILE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read image from JPEG file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_JPEG_FILE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot write image to JPEG file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_IMAGE_OPERATION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nImage operation error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMAGE_IMAGE_OPERATION_INVALID_COLOR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nImage operation, invalid image color\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class IMAGE -
built_in_class_s image_class =
{/*{{{*/
  "Image",
  c_modifier_public | c_modifier_final,
  19, image_methods,
  3, image_variables,
  bic_image_consts,
  bic_image_init,
  bic_image_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s image_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_image_operator_binary_equal
  },
  {
    "Image#3",
    c_modifier_public | c_modifier_final,
    bic_image_method_Image_3
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_image_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_image_method_height_0
  },
  {
    "format#0",
    c_modifier_public | c_modifier_final,
    bic_image_method_format_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_image_method_buffer_0
  },
  {
    "read_png_data#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_image_method_read_png_data_1
  },
  {
    "read_png_file#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_image_method_read_png_file_1
  },
  {
    "write_png_file#1",
    c_modifier_public | c_modifier_final,
    bic_image_method_write_png_file_1
  },
  {
    "read_jpeg_data#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_image_method_read_jpeg_data_1
  },
  {
    "read_jpeg_file#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_image_method_read_jpeg_file_1
  },
  {
    "write_jpeg_file#2",
    c_modifier_public | c_modifier_final,
    bic_image_method_write_jpeg_file_2
  },
  {
    "duplicate#0",
    c_modifier_public | c_modifier_final,
    bic_image_method_duplicate_0
  },
  {
    "referred#4",
    c_modifier_public | c_modifier_final,
    bic_image_method_referred_4
  },
  {
    "io_clear#0",
    c_modifier_public | c_modifier_final,
    bic_image_method_io_clear_0
  },
  {
    "io_fill#1",
    c_modifier_public | c_modifier_final,
    bic_image_method_io_fill_1
  },
  {
    "io_copy#1",
    c_modifier_public | c_modifier_final,
    bic_image_method_io_copy_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_image_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_image_method_print_0
  },
};/*}}}*/

built_in_variable_s image_variables[] =
{/*{{{*/
  {
    "PIX_FMT_GRAY8",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PIX_FMT_RGB24",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PIX_FMT_RGBA",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

#define BIC_IMAGE_CREATE_ROW_PTRS(IMG_PTR,ROW_PTRS) \
{/*{{{*/\
  unsigned line_size = (IMG_PTR)->image_data_ptr->line_bytes;\
\
  unsigned char *ptr = (IMG_PTR)->image_data_ptr->data + (IMG_PTR)->y_pos*line_size + (IMG_PTR)->x_pos*(IMG_PTR)->pixel_step;\
  unsigned char *ptr_end = ptr + ((IMG_PTR)->height - 1)*line_size + (IMG_PTR)->width*(IMG_PTR)->pixel_step;\
  png_bytepp r_ptr = ROW_PTRS;\
\
  do {\
    *r_ptr++ = ptr;\
\
    ptr += line_size;\
  } while(ptr < ptr_end);\
}/*}}}*/

#define BIC_IMAGE_READ_PNG_DATA(RELEASE_CODE) \
{/*{{{*/\
  png_set_sig_bytes(png_ptr,8);\
  png_read_info(png_ptr,info_ptr);\
\
  unsigned width      = png_get_image_width (png_ptr,info_ptr);\
  unsigned height     = png_get_image_height(png_ptr,info_ptr);\
  png_byte color_type = png_get_color_type  (png_ptr,info_ptr);\
  png_byte bit_depth  = png_get_bit_depth   (png_ptr,info_ptr);\
\
  /* - ERROR - */\
  if (bit_depth != 8)\
  {\
    png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);\
    RELEASE_CODE;\
\
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  unsigned pixel_format;\
\
  switch (color_type)\
  {\
  case PNG_COLOR_TYPE_GRAY:\
    pixel_format = c_image_pixel_format_GRAY8;\
    break;\
  case PNG_COLOR_TYPE_RGB:\
    pixel_format = c_image_pixel_format_RGB24;\
    break;\
  case PNG_COLOR_TYPE_RGB_ALPHA:\
    pixel_format = c_image_pixel_format_RGBA;\
    break;\
\
  /* - ERROR - */\
  default:\
    \
    png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);\
    RELEASE_CODE;\
\
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - create image object - */\
  image_s *img_ptr = (image_s *)cmalloc(sizeof(image_s));\
  img_ptr->init();\
\
  /* - create image content - */\
  img_ptr->create(width,height,pixel_format);\
\
  /* - ERROR - */\
  if (png_get_rowbytes(png_ptr,info_ptr) != img_ptr->image_data_ptr->line_bytes)\
  {\
    png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);\
    RELEASE_CODE;\
\
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - create target row pointer array - */\
  png_bytepp row_ptrs = (png_bytepp)cmalloc(height*sizeof(png_bytep));\
\
  /* - fill target row pointer array - */\
  BIC_IMAGE_CREATE_ROW_PTRS(img_ptr,row_ptrs)\
\
  /* - ERROR - */\
  if (setjmp(png_jmpbuf(png_ptr)))\
  {\
    cfree(row_ptrs);\
    png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);\
    RELEASE_CODE;\
\
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_DATA_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - read image data - */\
  png_read_image(png_ptr,row_ptrs);\
\
  /* - release resources - */\
  cfree(row_ptrs);\
  png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);\
  RELEASE_CODE;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_image,img_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

#define BIC_IMAGE_READ_JPEG_DATA(RELEASE_CODE) \
{/*{{{*/\
\
  /* - read jpeg image header - */\
  jpeg_read_header(&cinfo,TRUE);\
\
  unsigned pixel_format;\
\
  switch (cinfo.out_color_space)\
  {\
    case JCS_GRAYSCALE:\
      pixel_format = c_image_pixel_format_GRAY8;\
      break;\
    case JCS_RGB:\
      pixel_format = c_image_pixel_format_RGB24;\
      break;\
\
    /* - ERROR - */\
    case JCS_YCbCr:\
    case JCS_CMYK:\
    case JCS_YCCK:\
    default:\
      jpeg_destroy_decompress(&cinfo);\
      RELEASE_CODE;\
\
      exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
  }\
\
  /* - create image object - */\
  image_s *img_ptr = (image_s *)cmalloc(sizeof(image_s));\
  img_ptr->init();\
\
  /* - create image content - */\
  img_ptr->create(cinfo.image_width,cinfo.image_height,pixel_format);\
\
  /* - start decompression - */\
  jpeg_start_decompress(&cinfo);\
\
  /* - read jpeg image data - */\
  unsigned char *line_ptr = img_ptr->image_data_ptr->data;\
  unsigned line_bytes = img_ptr->image_data_ptr->line_bytes;\
  while (cinfo.output_scanline < cinfo.output_height)\
  {\
    jpeg_read_scanlines(&cinfo,&line_ptr,1);\
    line_ptr += line_bytes;\
  }\
\
  jpeg_destroy_decompress(&cinfo);\
  RELEASE_CODE;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_image,img_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_image_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert image pixel format constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_IMAGE_PIXEL_FORMAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_IMAGE_PIXEL_FORMAT_BIC_STATIC(c_image_pixel_format_GRAY8);
    CREATE_IMAGE_PIXEL_FORMAT_BIC_STATIC(c_image_pixel_format_RGB24);
    CREATE_IMAGE_PIXEL_FORMAT_BIC_STATIC(c_image_pixel_format_RGBA);
  }
}/*}}}*/

void bic_image_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (image_s *)nullptr;
}/*}}}*/

void bic_image_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  image_s *img_ptr = (image_s *)location_ptr->v_data_ptr;

  if (img_ptr != nullptr)
  {
    img_ptr->clear();
    cfree(img_ptr);
  }
}/*}}}*/

bool bic_image_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_image_method_Image_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int width;
  long long int height;
  long long int format;

  if (!it.retrieve_integer(src_0_location,width) ||
      !it.retrieve_integer(src_1_location,height) ||
      !it.retrieve_integer(src_2_location,format))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Image#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  if (width <= 0 || height <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_WRONG_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (format)
  {
  case c_image_pixel_format_GRAY8:
  case c_image_pixel_format_RGB24:
  case c_image_pixel_format_RGBA:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_WRONG_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create image object -
  image_s *img_ptr = (image_s *)cmalloc(sizeof(image_s));
  img_ptr->init();

  // - create image content -
  cassert(img_ptr->create(width,height,format));

  dst_location->v_data_ptr = (image_s *)img_ptr;

  return true;
}/*}}}*/

bool bic_image_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;

  long long int result = img_ptr->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_image_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;

  long long int result = img_ptr->height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_image_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;

  long long int result = img_ptr->pixel_format;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_image_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!img_ptr->root)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_CANNOT_GET_BUFFER_OF_NON_ROOT_IMAGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = img_ptr->image_data_ptr->data;
  buffer_ptr->size = img_ptr->height*img_ptr->image_data_ptr->line_bytes;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_image_method_read_png_data_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_image,"read_png_data#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *data_str = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (png_sig_cmp((unsigned char *)data_str->data,0,8) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_DATA_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create png reader structure -
  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,nullptr,nullptr,nullptr);

  // - ERROR -
  if (png_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_READ_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create info structure -
  png_infop info_ptr = png_create_info_struct(png_ptr);

  // - ERROR -
  if (info_ptr == nullptr)
  {
    png_destroy_read_struct(&png_ptr,nullptr,nullptr);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_READ_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (setjmp(png_jmpbuf(png_ptr)))
  {
    png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_READ_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create png data object -
  png_data_s png_data;
  png_data.data = data_str->data;
  png_data.size = data_str->size - 1;
  png_data.read = 8;

  png_set_read_fn(png_ptr,&png_data,png_data_s::read_data);

  BIC_IMAGE_READ_PNG_DATA();
}/*}}}*/

bool bic_image_method_read_png_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_image,"read_png_file#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *file_name = (string_s *)src_0_location->v_data_ptr;

  // - open source png file -
  FILE *f = fopen(file_name->data,"rb");

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_CANNOT_OPEN_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - read png file header -
  unsigned char png_header[8];
  size_t read_size = fread(png_header,1,8,f);

  // - ERROR -
  if (read_size != 8 || png_sig_cmp(png_header,0,8) != 0)
  {
    fclose(f);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_FILE_IS_NOT_PNG_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create png reader structure -
  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,nullptr,nullptr,nullptr);

  // - ERROR -
  if (png_ptr == nullptr)
  {
    fclose(f);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_READ_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create info structure -
  png_infop info_ptr = png_create_info_struct(png_ptr);

  // - ERROR -
  if (info_ptr == nullptr)
  {
    png_destroy_read_struct(&png_ptr,nullptr,nullptr);
    fclose(f);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_READ_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (setjmp(png_jmpbuf(png_ptr)))
  {
    png_destroy_read_struct(&png_ptr,&info_ptr,nullptr);
    fclose(f);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_FILE_READ_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  png_init_io(png_ptr,f);

  BIC_IMAGE_READ_PNG_DATA(fclose(f));
}/*}}}*/

bool bic_image_method_write_png_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write_png_file#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;
  string_s *file_name = (string_s *)src_0_location->v_data_ptr;

  // - retrieve png image details -
  unsigned width = img_ptr->width;
  unsigned height = img_ptr->height;
  png_byte color_type;
  png_byte bit_depth;

  switch (img_ptr->pixel_format)
  {
  case c_image_pixel_format_GRAY8:
    color_type = PNG_COLOR_TYPE_GRAY;
    bit_depth = 8;
    break;
  case c_image_pixel_format_RGB24:
    color_type = PNG_COLOR_TYPE_RGB;
    bit_depth = 8;
    break;
  case c_image_pixel_format_RGBA:
    color_type = PNG_COLOR_TYPE_RGB_ALPHA;
    bit_depth = 8;
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create png writer structure -
  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,nullptr,nullptr,nullptr);

  // - ERROR -
  if (png_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_WRITE_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create info structure -
  png_infop info_ptr = png_create_info_struct(png_ptr);

  // - ERROR -
  if (info_ptr == nullptr)
  {
    png_destroy_write_struct(&png_ptr,nullptr);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_WRITE_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - open target png file -
  FILE *f = fopen(file_name->data,"wb");

  // - ERROR -
  if (f == nullptr)
  {
    png_destroy_write_struct(&png_ptr,&info_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_CANNOT_OPEN_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - ERROR -
  if (setjmp(png_jmpbuf(png_ptr)))
  {
    fclose(f);
    png_destroy_write_struct(&png_ptr,&info_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_FILE_WRITE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  png_init_io(png_ptr,f);

  // - write png image header -
  png_set_IHDR(png_ptr,info_ptr,
      width,height,bit_depth,color_type,
      PNG_INTERLACE_NONE,PNG_COMPRESSION_TYPE_BASE,PNG_FILTER_TYPE_BASE);

  png_write_info(png_ptr,info_ptr);

  // - create target row pointer array -
  png_bytepp row_ptrs = (png_bytepp)cmalloc(height*sizeof(png_bytep));

  // - fill target row pointer array -
  BIC_IMAGE_CREATE_ROW_PTRS(img_ptr,row_ptrs)

  // - ERROR -
  if (setjmp(png_jmpbuf(png_ptr)))
  {
    cfree(row_ptrs);
    fclose(f);
    png_destroy_write_struct(&png_ptr,&info_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_PNG_FILE_WRITE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - write image data -
  png_write_image(png_ptr,row_ptrs);
  png_write_end(png_ptr,nullptr);

  // - release resources -
  cfree(row_ptrs);
  fclose(f);
  png_destroy_write_struct(&png_ptr,&info_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_image_method_read_jpeg_data_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_image,"read_jpeg_data#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *data_str = (string_s *)src_0_location->v_data_ptr;

  jpeg_decompress_struct cinfo;
  jpeg_error_mgr_s jem;

  // - initialize error manager -
  cinfo.err = jpeg_std_error(&jem.pub);
  jem.pub.error_exit = jpeg_error_mgr_s::error_exit;

  if (setjmp(jem.jump_buffer))
  {
    jpeg_destroy_decompress(&cinfo);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_JPEG_FILE_READ_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  jpeg_create_decompress(&cinfo);
  jpeg_source_mgr_s::set_source(&cinfo,data_str->data,data_str->size - 1);

  BIC_IMAGE_READ_JPEG_DATA();
}/*}}}*/

bool bic_image_method_read_jpeg_file_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_image,"read_jpeg_file#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *file_name = (string_s *)src_0_location->v_data_ptr;

  // - open source jpeg file -
  FILE *f = fopen(file_name->data,"rb");

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_CANNOT_OPEN_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  jpeg_decompress_struct cinfo;
  jpeg_error_mgr_s jem;

  // - initialize error manager -
  cinfo.err = jpeg_std_error(&jem.pub);
  jem.pub.error_exit = jpeg_error_mgr_s::error_exit;

  if (setjmp(jem.jump_buffer))
  {
    jpeg_destroy_decompress(&cinfo);
    fclose(f);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_JPEG_FILE_READ_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  jpeg_create_decompress(&cinfo);
  jpeg_stdio_src(&cinfo,f);

  BIC_IMAGE_READ_JPEG_DATA(fclose(f));
}/*}}}*/

bool bic_image_method_write_jpeg_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int quality = 0;

  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,quality))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write_jpeg_file#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;
  string_s *file_name = (string_s *)src_0_location->v_data_ptr;

  // - retrieve jpeg image details -
  J_COLOR_SPACE color_space;
  int components;

  switch (img_ptr->pixel_format)
  {
  case c_image_pixel_format_GRAY8:
    color_space = JCS_GRAYSCALE;
    components = 1;
    break;
  case c_image_pixel_format_RGB24:
    color_space = JCS_RGB;
    components = 3;
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - open target jpeg file -
  FILE *f = fopen(file_name->data,"wb");

  // - ERROR -
  if (f == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_CANNOT_OPEN_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  jpeg_compress_struct cinfo;
  jpeg_error_mgr_s jem;

  // - initialize error manager -
  cinfo.err = jpeg_std_error(&jem.pub);
  jem.pub.error_exit = jpeg_error_mgr_s::error_exit;

  if (setjmp(jem.jump_buffer))
  {
    jpeg_destroy_compress(&cinfo);
    fclose(f);

    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_JPEG_FILE_WRITE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo,f);

  // - initialize image properties -
  cinfo.image_width = img_ptr->width;
  cinfo.image_height = img_ptr->height;
  cinfo.input_components = components;
  cinfo.in_color_space = color_space;

  // - set compression parameters -
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo,quality,TRUE);

  // - start compression -
  jpeg_start_compress(&cinfo,TRUE);

  // - write image data -
  unsigned char *line_ptr = img_ptr->image_data_ptr->data;
  unsigned line_bytes = img_ptr->image_data_ptr->line_bytes;
  while (cinfo.next_scanline < cinfo.image_height)
  {
    jpeg_write_scanlines(&cinfo,&line_ptr,1);
    line_ptr += line_bytes;
  }

  // - finish compression -
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

  fclose(f);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_image_method_duplicate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  image_s *src_ptr = (image_s *)dst_location->v_data_ptr;

  // - create target image object -
  image_s *trg_ptr = (image_s *)cmalloc(sizeof(image_s));
  trg_ptr->init();

  // - duplicate image -
  *trg_ptr = *src_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_image,trg_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_image_method_referred_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int x_pos;
  long long int y_pos;
  long long int width;
  long long int height;

  if (!it.retrieve_integer(src_0_location,x_pos) ||
      !it.retrieve_integer(src_1_location,y_pos) ||
      !it.retrieve_integer(src_2_location,width) ||
      !it.retrieve_integer(src_3_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("referred#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  image_s *src_ptr = (image_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (width <= 0 || height <= 0 || x_pos + width > src_ptr->width || y_pos + height > src_ptr->height)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_WRONG_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target image object -
  image_s *trg_ptr = (image_s *)cmalloc(sizeof(image_s));
  trg_ptr->init();

  trg_ptr->create_referred(x_pos,y_pos,width,height,*src_ptr);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_image,trg_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_image_method_io_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;
  img_ptr->io_clear();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_image_method_io_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;
  unsigned char color[4];

  switch (src_0_location->v_type)
  {
  case c_bi_class_integer:
    {/*{{{*/
      long long int components;
      it.retrieve_integer(src_0_location,components);

      switch (img_ptr->pixel_format)
      {
      case c_image_pixel_format_GRAY8:
        color[0] = components & 0xff;
        break;
      case c_image_pixel_format_RGB24:
        color[0] = (components >> 16) & 0xff;
        color[1] = (components >>  8) & 0xff;
        color[2] = components & 0xff;
        break;
      case c_image_pixel_format_RGBA:
        color[0] = (components >> 24) & 0xff;
        color[1] = (components >> 16) & 0xff;
        color[2] = (components >>  8) & 0xff;
        color[3] = components & 0xff;
        break;

      // - ERROR -
      default:

        exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }/*}}}*/
    break;

  case c_bi_class_array:
    {/*{{{*/
      pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

      bool size_err = false;

      switch (img_ptr->pixel_format)
      {
      case c_image_pixel_format_GRAY8:
        size_err = array_ptr->used != 1;
        break;
      case c_image_pixel_format_RGB24:
        size_err = array_ptr->used != 3;
        break;
      case c_image_pixel_format_RGBA:
        size_err = array_ptr->used != 4;
        break;

      // - ERROR -
      default:

        exception_s::throw_exception(it,module.error_base + c_error_IMAGE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - ERROR -
      if (size_err)
      {
        exception_s::throw_exception(it,module.error_base + c_error_IMAGE_IMAGE_OPERATION_INVALID_COLOR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - retrieve color components -
      pointer *a_ptr = array_ptr->data;
      pointer *a_ptr_end = a_ptr + array_ptr->used;
      unsigned component_idx = 0;
      do {
        location_s *item_location = it.get_location_value(*a_ptr);

        long long int component;

        // - ERROR -
        if (!it.retrieve_integer(item_location,component))
        {
          exception_s::throw_exception(it,module.error_base + c_error_IMAGE_IMAGE_OPERATION_INVALID_COLOR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        color[component_idx++] = component;
      } while(++a_ptr < a_ptr_end);
    }/*}}}*/
    break;

  // - ERROR -
  default:

    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("io_fill#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (!img_ptr->io_fill(color))
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_IMAGE_OPERATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_image_method_io_copy_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_image)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("io_copy#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  image_s *img_ptr = (image_s *)dst_location->v_data_ptr;
  image_s *src_ptr = (image_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (img_ptr->pixel_format != src_ptr->pixel_format ||
      img_ptr->width != src_ptr->width ||
      img_ptr->height != src_ptr->height ||
      img_ptr->pixel_format == c_image_pixel_format_blank)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_WRONG_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!img_ptr->io_copy(*src_ptr))
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMAGE_IMAGE_OPERATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_image_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Image"),"Image");
  );

  return true;
}/*}}}*/

bool bic_image_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Image");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

