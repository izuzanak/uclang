
@begin
include "gif_module.h"
@end

// - GIF indexes of built in classes -
unsigned c_bi_class_gif_file = c_idx_not_exist;
unsigned c_bi_class_gif_image = c_idx_not_exist;

// - GIF module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                   // Class count
  gif_classes,         // Classes

  0,                   // Error base index
  3,                   // Error count
  gif_error_strings,   // Error strings

  gif_initialize,      // Initialize function
  gif_print_exception, // Print exceptions function
};/*}}}*/

// - GIF classes -
built_in_class_s *gif_classes[] =
{/*{{{*/
  &gif_file_class,
  &gif_image_class,
};/*}}}*/

// - GIF error strings -
const char *gif_error_strings[] =
{/*{{{*/
  "error_GIF_FILE_OPEN_ERROR",
  "error_GIF_FILE_READ_ERROR",
  "error_GIF_FILE_INDEX_EXCEEDS_RANGE",
};/*}}}*/

// - GIF initialize -
bool gif_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gif_file class identifier -
  c_bi_class_gif_file = class_base_idx++;

  // - initialize gif_image class identifier -
  c_bi_class_gif_image = class_base_idx++;

  return true;
}/*}}}*/

// - GIF print exception -
bool gif_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GIF_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGIF file, file open error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GIF_FILE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGIF file, file read error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GIF_FILE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds GIF file range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GIF_FILE -
built_in_class_s gif_file_class =
{/*{{{*/
  "GifFile",
  c_modifier_public | c_modifier_final,
  9, gif_file_methods,
  0, gif_file_variables,
  bic_gif_file_consts,
  bic_gif_file_init,
  bic_gif_file_clear,
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

built_in_method_s gif_file_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gif_file_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_gif_file_operator_binary_le_br_re_br
  },
  {
    "GifFile#1",
    c_modifier_public | c_modifier_final,
    bic_gif_file_method_GifFile_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_gif_file_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_gif_file_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_gif_file_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_gif_file_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gif_file_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gif_file_method_print_0
  },
};/*}}}*/

built_in_variable_s gif_file_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_GIF_FILE_CHECK_INDEX() \
  /*{{{*/\
  GifFileType *gf_ptr = (GifFileType *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= gf_ptr->ImageCount) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GIF_FILE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_GIF_FILE_ITEM(NAME) \
{/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
  BIC_GIF_FILE_CHECK_INDEX();\
\
  /* - create gif_image object - */\
  gif_image_s *gi_ptr = (gif_image_s *)cmalloc(sizeof(gif_image_s));\
  gi_ptr->init();\
\
  /* - create reference to gif_file - */\
  dst_location->v_reference_cnt.atomic_inc();\
  gi_ptr->gif_file_loc = dst_location;\
\
  gi_ptr->image_index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gif_image,gi_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_gif_file_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gif_file_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (GifFileType *)nullptr;
}/*}}}*/

void bic_gif_file_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  GifFileType *gf_ptr = (GifFileType *)location_ptr->v_data_ptr;

  if (gf_ptr != nullptr)
  {
    int error;
    DGifCloseFile(gf_ptr,&error);
  }
}/*}}}*/

bool bic_gif_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gif_file_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GIF_FILE_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_gif_file_method_GifFile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method GifFile
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  int error;
  GifFileType *gf_ptr = DGifOpenFileName(string_ptr->data,&error);

  // - ERROR -
  if (gf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GIF_FILE_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (DGifSlurp(gf_ptr) == GIF_ERROR)
  {
    DGifCloseFile(gf_ptr,&error);

    exception_s::throw_exception(it,module.error_base + c_error_GIF_FILE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (GifFileType *)gf_ptr;

  return true;
}/*}}}*/

bool bic_gif_file_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GIF_FILE_ITEM("item#1")

  return true;
}/*}}}*/

bool bic_gif_file_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  GifFileType *gf_ptr = (GifFileType *)dst_location->v_data_ptr;

  if (gf_ptr->ImageCount > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_gif_file_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_GIF_FILE_CHECK_INDEX();

  if (++index < gf_ptr->ImageCount)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_gif_file_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((GifFileType *)dst_location->v_data_ptr)->ImageCount;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gif_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GifFile"),"GifFile");
  );

  return true;
}/*}}}*/

bool bic_gif_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GifFile");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GIF_IMAGE -
built_in_class_s gif_image_class =
{/*{{{*/
  "GifImage",
  c_modifier_public | c_modifier_final,
  6, gif_image_methods,
  0, gif_image_variables,
  bic_gif_image_consts,
  bic_gif_image_init,
  bic_gif_image_clear,
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

built_in_method_s gif_image_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gif_image_operator_binary_equal
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_gif_image_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_gif_image_method_height_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_gif_image_method_buffer_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gif_image_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gif_image_method_print_0
  },
};/*}}}*/

built_in_variable_s gif_image_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_gif_image_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gif_image_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gif_image_s *)nullptr;
}/*}}}*/

void bic_gif_image_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gif_image_s *gif_img_ptr = (gif_image_s *)location_ptr->v_data_ptr;

  if (gif_img_ptr != nullptr)
  {
    gif_img_ptr->clear(it);
    cfree(gif_img_ptr);
  }
}/*}}}*/

bool bic_gif_image_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gif_image_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gif_image_s *gi_ptr = (gif_image_s *)dst_location->v_data_ptr;
  GifFileType *gf_ptr = (GifFileType *)((location_s *)gi_ptr->gif_file_loc)->v_data_ptr;

  long long int result = gf_ptr->SavedImages[gi_ptr->image_index].ImageDesc.Width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gif_image_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gif_image_s *gi_ptr = (gif_image_s *)dst_location->v_data_ptr;
  GifFileType *gf_ptr = (GifFileType *)((location_s *)gi_ptr->gif_file_loc)->v_data_ptr;

  long long int result = gf_ptr->SavedImages[gi_ptr->image_index].ImageDesc.Height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gif_image_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gif_image_s *gi_ptr = (gif_image_s *)dst_location->v_data_ptr;
  GifFileType *gf_ptr = (GifFileType *)((location_s *)gi_ptr->gif_file_loc)->v_data_ptr;
  SavedImage *image_ptr = gf_ptr->SavedImages + gi_ptr->image_index;

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = image_ptr->RasterBits;
  buffer_ptr->size = image_ptr->ImageDesc.Width*image_ptr->ImageDesc.Height;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gif_image_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GifImage"),"GifImage");
  );

  return true;
}/*}}}*/

bool bic_gif_image_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GifImage");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

