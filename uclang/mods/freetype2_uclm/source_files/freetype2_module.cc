
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
  1,                         // Error count
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
  "error_FREETYPE2_DUMMY_ERROR",
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
  case c_error_FREETYPE2_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFreeType2 dummy error\n");
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
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
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
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
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
  15, ft2_face_methods,
  14 + 19 + 5 + 2, ft2_face_variables,
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
    "select_charmap#1",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_select_charmap_1
  },
  {
    "set_pixel_sizes#2",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_set_pixel_sizes_2
  },
  {
    "render_text#2",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_render_text_2
  },
  {
    "load_char#2",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_load_char_2
  },
  {
    "render_glyph#1",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_render_glyph_1
  },
  {
    "get_kerning#3",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_get_kerning_3
  },
  {
    "top#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_top_0
  },
  {
    "left#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_left_0
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_height_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_buffer_0
  },
  {
    "glyph_info#0",
    c_modifier_public | c_modifier_final,
    bic_ft2_face_method_glyph_info_0
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
  { "FT_ENCODING_NONE",           c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_UNICODE",        c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_MS_SYMBOL",      c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_ADOBE_LATIN_1",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_OLD_LATIN_2",    c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_SJIS",           c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_PRC",            c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_BIG5",           c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_WANSUNG",        c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_JOHAB",          c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_ADOBE_STANDARD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_ADOBE_EXPERT",   c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_ADOBE_CUSTOM",   c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_ENCODING_APPLE_ROMAN",    c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "FT_LOAD_DEFAULT",             c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_NO_SCALE",            c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_NO_HINTING",          c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_RENDER",              c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_NO_BITMAP",           c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_VERTICAL_LAYOUT",     c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_FORCE_AUTOHINT",      c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_CROP_BITMAP",         c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_PEDANTIC",            c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_NO_RECURSE",          c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_IGNORE_TRANSFORM",    c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_MONOCHROME",          c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_LINEAR_DESIGN",       c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_SBITS_ONLY",          c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_NO_AUTOHINT",         c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_COLOR",               c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_COMPUTE_METRICS",     c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_LOAD_BITMAP_METRICS_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "FT_RENDER_MODE_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_RENDER_MODE_LIGHT",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_RENDER_MODE_MONO",   c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_RENDER_MODE_LCD",    c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_RENDER_MODE_LCD_V",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "FT_KERNING_DEFAULT",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FT_KERNING_UNFITTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_ft2_face_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert freetype encoding constants -
  {
    const_locations.push_blanks(14);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 14);

#define CREATE_FREETYPE_ENCODING_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_NONE);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_UNICODE);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_MS_SYMBOL);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_ADOBE_LATIN_1);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_OLD_LATIN_2);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_SJIS);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_PRC);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_BIG5);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_WANSUNG);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_JOHAB);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_ADOBE_STANDARD);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_ADOBE_EXPERT);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_ADOBE_CUSTOM);
    CREATE_FREETYPE_ENCODING_BIC_STATIC(FT_ENCODING_APPLE_ROMAN);
  }

  // - insert freetype load constants -
  {
    const_locations.push_blanks(19);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 19);

#define CREATE_FREETYPE_LOAD_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_DEFAULT);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_NO_SCALE);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_NO_HINTING);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_RENDER);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_NO_BITMAP);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_VERTICAL_LAYOUT);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_FORCE_AUTOHINT);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_CROP_BITMAP);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_PEDANTIC);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_NO_RECURSE);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_IGNORE_TRANSFORM);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_MONOCHROME);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_LINEAR_DESIGN);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_SBITS_ONLY);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_NO_AUTOHINT);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_COLOR);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_COMPUTE_METRICS);
    CREATE_FREETYPE_LOAD_BIC_STATIC(FT_LOAD_BITMAP_METRICS_ONLY);
  }

  // - insert freetype render mode constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_FREETYPE_REDER_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FREETYPE_REDER_MODE_BIC_STATIC(FT_RENDER_MODE_NORMAL);
    CREATE_FREETYPE_REDER_MODE_BIC_STATIC(FT_RENDER_MODE_LIGHT);
    CREATE_FREETYPE_REDER_MODE_BIC_STATIC(FT_RENDER_MODE_MONO);
    CREATE_FREETYPE_REDER_MODE_BIC_STATIC(FT_RENDER_MODE_LCD);
    CREATE_FREETYPE_REDER_MODE_BIC_STATIC(FT_RENDER_MODE_LCD_V);
  }

  // - insert freetype kerning constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_FREETYPE_KERNING_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FREETYPE_KERNING_BIC_STATIC(FT_KERNING_DEFAULT);
    CREATE_FREETYPE_KERNING_BIC_STATIC(FT_KERNING_UNFITTED);
  }
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

bool bic_ft2_face_method_select_charmap_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
encoding:retrieve_integer
>
method select_charmap
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (FT_Select_Charmap(ftf_ptr->face,(FT_Encoding)encoding))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ft2_face_method_set_pixel_sizes_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
method set_pixel_sizes
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (FT_Set_Pixel_Sizes(ftf_ptr->face,width,height))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

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
  ui_array_s *array_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (FT_Set_Pixel_Sizes(ftf_ptr->face,0,height))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  unsigned bitmap_width;
  if (!ftf_ptr->measure_text(*array_ptr,bitmap_width))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  unsigned bitmap_height = ftf_ptr->face->size->metrics.height >> 6;

  // - create ft2_bitmap object -
  ft2_bitmap_s *ftb_ptr = (ft2_bitmap_s *)cmalloc(sizeof(ft2_bitmap_s));
  ftb_ptr->init();

  ftb_ptr->width = bitmap_width;
  ftb_ptr->height = bitmap_height;
  ftb_ptr->data = (unsigned char *)cmalloc(bitmap_width*bitmap_height*sizeof(unsigned char));

  BIC_CREATE_NEW_LOCATION(bitmap_location,c_bi_class_ft2_bitmap,ftb_ptr);

  // - ERROR -
  if (!ftf_ptr->render_text(*array_ptr,*ftb_ptr))
  {
    it.release_location_ptr(bitmap_location);

    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT(bitmap_location);

  return true;
}/*}}}*/

bool bic_ft2_face_method_load_char_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
char_code:retrieve_integer
load_flags:retrieve_integer
>
method load_char
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (FT_Load_Char(ftf_ptr->face,char_code,load_flags))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ft2_face_method_render_glyph_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
render_mode:retrieve_integer
>
method render_glyph
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  FT_GlyphSlot slot = ftf_ptr->face->glyph;

  // - ERROR -
  if (FT_Render_Glyph(slot,(FT_Render_Mode)render_mode))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ft2_face_method_get_kerning_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
left_code:retrieve_integer
right_code:retrieve_integer
kern_mode:retrieve_integer
>
method get_kerning
; @end

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;

  FT_UInt left_glyph = FT_Get_Char_Index(ftf_ptr->face,left_code);
  FT_UInt right_glyph = FT_Get_Char_Index(ftf_ptr->face,right_code);

  // - ERROR -
  if (left_glyph == 0 || right_glyph == 0)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  FT_Vector kerning;
  if (FT_Get_Kerning(ftf_ptr->face,left_glyph,right_glyph,kern_mode,&kerning))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  long long int result = kerning.x;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_face_method_top_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  FT_GlyphSlot slot = ftf_ptr->face->glyph;

  long long int result = slot->bitmap_top;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_face_method_left_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  FT_GlyphSlot slot = ftf_ptr->face->glyph;

  long long int result = slot->bitmap_left;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_face_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  FT_Bitmap *bitmap = &ftf_ptr->face->glyph->bitmap;

  long long int result = bitmap->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_face_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  FT_Bitmap *bitmap = &ftf_ptr->face->glyph->bitmap;

  long long int result = bitmap->rows;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ft2_face_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;
  FT_Bitmap *bitmap = &ftf_ptr->face->glyph->bitmap;

  // - ERROR -
  if (bitmap->buffer == nullptr)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = bitmap->buffer;
  buffer_ptr->size = bitmap->rows*bitmap->pitch;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ft2_face_method_glyph_info_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ft2_face_s *ftf_ptr = (ft2_face_s *)dst_location->v_data_ptr;

  FT_GlyphSlot slot = ftf_ptr->face->glyph;
  FT_Bitmap *bitmap = &slot->bitmap;
  FT_Vector *advance = &slot->advance;

  // FIXME
  fprintf(stderr,"advance, x: %ld, y: %ld\n",advance->x,advance->y);
  fprintf(stderr,"posit.: %d x %d\n",slot->bitmap_left,slot->bitmap_top);
  fprintf(stderr,"bitmap: %u x %u\n",bitmap->width,bitmap->rows);
  fprintf(stderr,"pixel_mode: %hhu\n",bitmap->pixel_mode);
  fprintf(stderr,"pitch: %d\n",bitmap->pitch);
  fprintf(stderr,"\n");

  BIC_SET_RESULT_DESTINATION();

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
  3, ft2_bitmap_methods,
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

