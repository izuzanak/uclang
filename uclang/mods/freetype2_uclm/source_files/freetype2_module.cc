
@begin
include "freetype2_module.h"
@end

// - FREETYPE2 indexes of built in classes -
unsigned c_bi_class_ft2_library = c_idx_not_exist;
unsigned c_bi_class_ft2_face = c_idx_not_exist;
unsigned c_bi_class_ft2_bitmap = c_idx_not_exist;

// - FREETYPE2 indexes of remote classes -
unsigned c_rm_class_unicode_string = c_idx_not_exist;

// - FREETYPE2 module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                         // Class count
  freetype2_classes,         // Classes

  0,                         // Error base index
  8,                         // Error count
  freetype2_error_strings,   // Error strings

  freetype2_initialize,      // Initialize function
  freetype2_print_exception, // Print exceptions function
};/*}}}*/

// - FREETYPE2 classes -
built_in_class_s *freetype2_classes[] =
{/*{{{*/
  &ft2_library_class,
  &ft2_face_class,
  &ft2_bitmap_class,
};/*}}}*/

// - FREETYPE2 error strings -
const char *freetype2_error_strings[] =
{/*{{{*/
  "error_FREETYPE2_LIBRARY_INIT_ERROR",
  "error_FREETYPE2_LIBRARY_NEW_FACE_ERROR",
  "error_FREETYPE2_FACE_INVALID_TEXT_HEIGHT",
  "error_FREETYPE2_FACE_INVALID_TEXT_DATA",
  "error_FREETYPE2_FACE_SELECT_CHARMAP_ERROR",
  "error_FREETYPE2_FACE_PIXEL_SIZES_ERROR",
  "error_FREETYPE2_FACE_MEASURE_TEXT_ERROR",
  "error_FREETYPE2_FACE_RENDER_TEXT_ERROR",
};/*}}}*/

// - FREETYPE2 initialize -
bool freetype2_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ft2_library class identifier -
  c_bi_class_ft2_library = class_base_idx++;

  // - initialize ft2_face class identifier -
  c_bi_class_ft2_face = class_base_idx++;

  // - initialize ft2_bitmap class identifier -
  c_bi_class_ft2_bitmap = class_base_idx++;

  // - retrieve remote unicode_string class index -
  c_rm_class_unicode_string = sp.resolve_class_idx_by_name("UnicodeString",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_unicode_string == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - FREETYPE2 print exception -
bool freetype2_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_FREETYPE2_LIBRARY_INIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 library, init error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_LIBRARY_NEW_FACE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 library, new face error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_FACE_INVALID_TEXT_HEIGHT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 face, invalid text height: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_FACE_INVALID_TEXT_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 face, invalid text data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_FACE_SELECT_CHARMAP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 face, select charmap error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_FACE_PIXEL_SIZES_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 face, pixel sizes error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_FACE_MEASURE_TEXT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 face, measure text error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FREETYPE2_FACE_RENDER_TEXT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 face, render text error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class FT2_LIBRARY -
built_in_class_s ft2_library_class =
{/*{{{*/
  "Ft2Library",
  c_modifier_public | c_modifier_final,
  5, ft2_library_methods,
  0, ft2_library_variables,
  bic_ft2_library_consts,
  bic_ft2_library_init,
  bic_ft2_library_clear,
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

built_in_method_s ft2_library_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ft2_library_operator_binary_equal
  },
  {
    "Ft2Library#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_library_method_Ft2Library_0
  },
  {
    "face#2",
    c_modifier_public | c_modifier_final,
    bic_ft2_library_method_face_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ft2_library_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ft2_library_method_print_0
  },
};/*}}}*/

built_in_variable_s ft2_library_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ft2_library_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ft2_library_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (FT_Library)nullptr;
}/*}}}*/

void bic_ft2_library_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve ft_library pointer -
  FT_Library ftl_ptr = (FT_Library)location_ptr->v_data_ptr;

  // - if ft_library pointer is not null release it -
  if (ftl_ptr != nullptr)
  {
    FT_Done_FreeType(ftl_ptr);
  }
}/*}}}*/

bool bic_ft2_library_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ft2_library_method_Ft2Library_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - ERROR -
  if (FT_Init_FreeType((FT_Library *)&dst_location->v_data_ptr))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_LIBRARY_INIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_ft2_library_method_face_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
file:c_bi_class_string
face_index:retrieve_integer
>
method face
; @end

  FT_Library ftl_ptr = (FT_Library)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  FT_Face face;
  if (FT_New_Face(ftl_ptr,string_ptr->data,face_index,&face))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_LIBRARY_NEW_FACE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create ft2_face object -
  ft2_face_s *ftf_ptr = (ft2_face_s *)cmalloc(sizeof(ft2_face_s));
  ftf_ptr->init();

  ftf_ptr->face = face;

  dst_location->v_reference_cnt.atomic_inc();
  ftf_ptr->library_loc = dst_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ft2_face,ftf_ptr);
  BIC_SET_RESULT(new_location)

  return true;
}/*}}}*/

bool bic_ft2_library_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Ft2Library"),"Ft2Library");
  );

  return true;
}/*}}}*/

bool bic_ft2_library_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Ft2Library");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FT2_FACE -
built_in_class_s ft2_face_class =
{/*{{{*/
  "Ft2Face",
  c_modifier_public | c_modifier_final,
  5, ft2_face_methods,
  0, ft2_face_variables,
  bic_ft2_face_consts,
  bic_ft2_face_init,
  bic_ft2_face_clear,
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

built_in_method_s ft2_face_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_operator_binary_equal
  },
  {
    "render_text#2",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_render_text_2
  },
  {
    "measure_text#2",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_measure_text_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ft2_face_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ft2_face_method_print_0
  },
};/*}}}*/

built_in_variable_s ft2_face_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ft2_face_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ft2_face_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ft2_face_s *)nullptr;
}/*}}}*/

void bic_ft2_face_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve ft_face pointer -
  ft2_face_s *ftf_ptr = (ft2_face_s *)location_ptr->v_data_ptr;

  // - if ft_face pointer is not null release it -
  if (ftf_ptr != nullptr)
  {
    ftf_ptr->clear(it);
    cfree(ftf_ptr);
  }
}/*}}}*/

bool bic_ft2_face_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ft2_face_method_render_text_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
text:c_rm_class_unicode_string
height:retrieve_integer
>
method render_text
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  ui_array_s *text_array_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (height < 1 || height > 1024)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_INVALID_TEXT_HEIGHT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(height);

    return false;
  }

  // - ERROR -
  if (text_array_ptr->used <= 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_INVALID_TEXT_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (FT_Select_Charmap(ftf_ptr->face,FT_ENCODING_UNICODE))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_SELECT_CHARMAP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (FT_Set_Pixel_Sizes(ftf_ptr->face,0,height))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_PIXEL_SIZES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int bitmap_left;
  int bitmap_top;
  unsigned bitmap_width;
  unsigned bitmap_height;

  // - ERROR -
  if (!ftf_ptr->measure_text(*text_array_ptr,
        bitmap_left,bitmap_top,bitmap_width,bitmap_height))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_MEASURE_TEXT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create ft2_bitmap object -
  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)cmalloc(sizeof(ft2_bitmap_s));
  ftb_ptr->init();

  ftb_ptr->width = bitmap_width;
  ftb_ptr->height = bitmap_height;
  ftb_ptr->baseline = bitmap_top;

  size_t data_size = (size_t)bitmap_width*bitmap_height*sizeof(unsigned char);
  ftb_ptr->data = (unsigned char *)cmalloc(data_size);
  memset(ftb_ptr->data,0,data_size);

  BIC_CREATE_NEW_LOCATION(bitmap_location,c_bi_class_ft2_bitmap,ftb_ptr);

  // - ERROR -
  if (!ftf_ptr->render_text(*text_array_ptr,*ftb_ptr,bitmap_left,bitmap_top))
  {
    it.release_location_ptr(bitmap_location);

    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_RENDER_TEXT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(bitmap_location);

  return true;
}/*}}}*/

bool bic_ft2_face_method_measure_text_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
text:c_rm_class_unicode_string
height:retrieve_integer
>
method measure_text
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  ui_array_s *text_array_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (height < 1 || height > 1024)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_INVALID_TEXT_HEIGHT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(height);

    return false;
  }

  // - ERROR -
  if (text_array_ptr->used <= 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_INVALID_TEXT_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (FT_Select_Charmap(ftf_ptr->face,FT_ENCODING_UNICODE))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_SELECT_CHARMAP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (FT_Set_Pixel_Sizes(ftf_ptr->face,0,height))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_PIXEL_SIZES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int bitmap_left;
  int bitmap_top;
  unsigned bitmap_width;
  unsigned bitmap_height;

  // - ERROR -
  if (!ftf_ptr->measure_text(*text_array_ptr,bitmap_left,bitmap_top,bitmap_width,bitmap_height))
  {
    exception_s::throw_exception(it,module.error_base + c_error_FREETYPE2_FACE_MEASURE_TEXT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create bitmap_left location -
  {
    long long int value = bitmap_left;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create bitmap_top location -
  {
    long long int value = bitmap_top;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create bitmap_width location -
  {
    long long int value = bitmap_width;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create bitmap_height location -
  {
    long long int value = bitmap_height;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ft2_face_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Ft2Face"),"Ft2Face");
  );

  return true;
}/*}}}*/

bool bic_ft2_face_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Ft2Face");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FT2_BITMAP -
built_in_class_s ft2_bitmap_class =
{/*{{{*/
  "Ft2Bitmap",
  c_modifier_public | c_modifier_final,
  7, ft2_bitmap_methods,
  0, ft2_bitmap_variables,
  bic_ft2_bitmap_consts,
  bic_ft2_bitmap_init,
  bic_ft2_bitmap_clear,
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

built_in_method_s ft2_bitmap_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ft2_bitmap_operator_binary_equal
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_bitmap_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_bitmap_method_height_0
  },
  {
    "baseline#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_bitmap_method_baseline_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_bitmap_method_buffer_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ft2_bitmap_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ft2_bitmap_method_print_0
  },
};/*}}}*/

built_in_variable_s ft2_bitmap_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ft2_bitmap_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ft2_bitmap_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ft2_bitmap_s *)nullptr;
}/*}}}*/

void bic_ft2_bitmap_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve ft_face pointer -
  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)location_ptr->v_data_ptr;

  // - if ft_face pointer is not null release it -
  if (ftb_ptr != nullptr)
  {
    ftb_ptr->clear(it);
    cfree(ftb_ptr);
  }
}/*}}}*/

bool bic_ft2_bitmap_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ft2_bitmap_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)dst_location->v_data_ptr;

  long long int result = ftb_ptr->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_bitmap_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)dst_location->v_data_ptr;

  long long int result = ftb_ptr->height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_bitmap_method_baseline_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)dst_location->v_data_ptr;

  long long int result = ftb_ptr->baseline;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_bitmap_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)dst_location->v_data_ptr;

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = ftb_ptr->data;
  buffer_ptr->size = ftb_ptr->width*ftb_ptr->height;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ft2_bitmap_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Ft2Bitmap"),"Ft2Bitmap");
  );

  return true;
}/*}}}*/

bool bic_ft2_bitmap_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Ft2Bitmap");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

