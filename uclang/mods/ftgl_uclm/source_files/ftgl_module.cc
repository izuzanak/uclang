
@begin
include "ftgl_module.h"
@end

// - FTGL indexes of built in classes -
unsigned c_bi_class_gl_vertex_buffer = c_idx_not_exist;
unsigned c_bi_class_gl_font = c_idx_not_exist;
unsigned c_bi_class_gl_font_buffer = c_idx_not_exist;

// - FTGL module -
built_in_module_s module =
{/*{{{*/
  3,                     // Class count
  ftgl_classes,          // Classes

  0,                     // Error base index
  11,                    // Error count
  ftgl_error_strings,    // Error strings

  ftgl_initialize,       // Initialize function
  ftgl_print_exception,  // Print exceptions function
};/*}}}*/

// - FTGL classes -
built_in_class_s *ftgl_classes[] =
{/*{{{*/
  &gl_vertex_buffer_class,
  &gl_font_class,
  &gl_font_buffer_class,
};/*}}}*/

// - FTGL error strings -
const char *ftgl_error_strings[] =
{/*{{{*/
  "error_GL_VERTEX_BUFFER_CANNOT_CREATE_NEW",
  "error_GL_VERTEX_BUFFER_VERTEX_ARRAY_IS_EMPTY",
  "error_GL_VERTEX_BUFFER_INDEX_ARRAY_IS_EMPTY",
  "error_GL_VERTEX_BUFFER_VERTEX_ARRAY_NOT_ALIGNED",
  "error_GL_VERTEX_BUFFER_WRONG_VERTEX_VALUE_TYPE",
  "error_GL_VERTEX_BUFFER_WRONG_INDEX_VALUE_TYPE",
  "error_GL_VERTEX_BUFFER_INDEX_EXCEEDS_RANGE",
  "error_GL_FONT_INVALID_TEXTURE_ATLAS_DIMENSIONS",
  "error_GL_FONT_CANNOT_READ_FROM_FILE",
  "error_GL_FONT_GLYPH_RETRIEVE_ERROR_ATLAS_SIZE",
  "error_GL_FONT_BUFFER_CONVERT_TO_WCHAR_STRING_ERROR",
};/*}}}*/

// - FTGL initialize -
bool ftgl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gl_vertex_buffer class identifier -
  c_bi_class_gl_vertex_buffer = class_base_idx++;

  // - initialize gl_font class identifier -
  c_bi_class_gl_font = class_base_idx++;

  // - initialize gl_font_buffer class identifier -
  c_bi_class_gl_font_buffer = class_base_idx++;

  return true;
}/*}}}*/

// - FTGL print exception -
bool ftgl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GL_VERTEX_BUFFER_CANNOT_CREATE_NEW:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create new vertex buffer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_VERTEX_BUFFER_VERTEX_ARRAY_IS_EMPTY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGiven vertex array is empty\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_VERTEX_BUFFER_INDEX_ARRAY_IS_EMPTY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGiven index array is empty\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_VERTEX_BUFFER_VERTEX_ARRAY_NOT_ALIGNED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGiven vertex array is not aligned to vertex item count\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_VERTEX_BUFFER_WRONG_VERTEX_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong vertex array value type at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_VERTEX_BUFFER_WRONG_INDEX_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong index array value type at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_VERTEX_BUFFER_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex value %" HOST_LL_FORMAT "d exceeds vertices range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_FONT_INVALID_TEXTURE_ATLAS_DIMENSIONS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid texture atlas dimensions %" HOST_LL_FORMAT "d x %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_FONT_CANNOT_READ_FROM_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read FreeType font from file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_FONT_GLYPH_RETRIEVE_ERROR_ATLAS_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nErrror while retrieving character glyph (texture atlas size)\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_FONT_BUFFER_CONVERT_TO_WCHAR_STRING_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while converting string to wide character string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GL_VERTEX_BUFFER -
built_in_class_s gl_vertex_buffer_class =
{/*{{{*/
  "GlVertexBuffer",
  c_modifier_public | c_modifier_final,
  8, gl_vertex_buffer_methods,
  0, gl_vertex_buffer_variables,
  bic_gl_vertex_buffer_consts,
  bic_gl_vertex_buffer_init,
  bic_gl_vertex_buffer_clear,
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

built_in_method_s gl_vertex_buffer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_vertex_buffer_operator_binary_equal
  },
  {
    "GlVertexBuffer#1",
    c_modifier_public | c_modifier_final,
    bic_gl_vertex_buffer_method_GlVertexBuffer_1
  },
  {
    "get_format#0",
    c_modifier_public | c_modifier_final,
    bic_gl_vertex_buffer_method_get_format_0
  },
  {
    "push_back#2",
    c_modifier_public | c_modifier_final,
    bic_gl_vertex_buffer_method_push_back_2
  },
  {
    "render#1",
    c_modifier_public | c_modifier_final,
    bic_gl_vertex_buffer_method_render_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_gl_vertex_buffer_method_clear_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_vertex_buffer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_vertex_buffer_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_vertex_buffer_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_vertex_buffer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_vertex_buffer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gl_vertex_buffer_s *)nullptr;
}/*}}}*/

void bic_gl_vertex_buffer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gl_vertex_buffer_s *vb_ptr = (gl_vertex_buffer_s *)location_ptr->v_data_ptr;

  // - if vertex buffer exists -
  if (vb_ptr != nullptr)
  {
    vb_ptr->clear(it);
    cfree(vb_ptr);
  }
}/*}}}*/

bool bic_gl_vertex_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_GlVertexBuffer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
format:c_bi_class_string
>
method GlVertexBuffer
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  vertex_buffer_t *buffer_ptr = vertex_buffer_new(string_ptr->data);

  // - ERROR -
  if (buffer_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_CANNOT_CREATE_NEW,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve vertex attributes -
  vertex_attribute_t **attrs = buffer_ptr->attributes;

  // - vertex item count and vertex data size -
  unsigned vert_item_cnt = 0;
  unsigned vert_size = 0;

  ui_array_s vert_item_types;
  vert_item_types.init();

  unsigned attr_idx = 0;
  do {
    if (attrs[attr_idx] == nullptr)
    {
      break;
    }

    // - retrieve attribute -
    vertex_attribute_t *attr_ptr = attrs[attr_idx];

    // - retrieve attribute size -
    unsigned attr_size;
    switch (attr_ptr->type)
    {
      case GL_BOOL:           attr_size = sizeof(GLboolean); break;
      case GL_BYTE:           attr_size = sizeof(GLbyte); break;
      case GL_UNSIGNED_BYTE:  attr_size = sizeof(GLubyte); break;
      case GL_SHORT:          attr_size = sizeof(GLshort); break;
      case GL_UNSIGNED_SHORT: attr_size = sizeof(GLushort); break;
      case GL_INT:            attr_size = sizeof(GLint); break;
      case GL_UNSIGNED_INT:   attr_size = sizeof(GLuint); break;
      case GL_FLOAT:          attr_size = sizeof(GLfloat); break;
      default:
        cassert(0);
    }

    // - increase vertex item count -
    vert_item_cnt += attr_ptr->size;

    // - insert types to vertex item types -
    for (int c_idx = 0;c_idx < attr_ptr->size;++c_idx)
    {
      vert_item_types.push(attr_ptr->type);
    }

    // - increate vertex size -
    vert_size += attr_ptr->size*attr_size;

  } while(++attr_idx < MAX_VERTEX_ATTRIBUTE);

  // - store vertex attribute count -
  unsigned vert_attr_cnt = attr_idx;

  // - create vertex buffer object -
  gl_vertex_buffer_s *vb_ptr = (gl_vertex_buffer_s *)cmalloc(sizeof(gl_vertex_buffer_s));
  vb_ptr->init();

  vb_ptr->buffer_ptr = buffer_ptr;
  vb_ptr->vert_attr_cnt = vert_attr_cnt;
  vb_ptr->vert_item_cnt = vert_item_cnt;

  vb_ptr->vert_item_types.swap(vert_item_types);
  vert_item_types.clear();

  vb_ptr->vert_size = vert_size;

  dst_location->v_data_ptr = (gl_vertex_buffer_s *)vb_ptr;

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_get_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_vertex_buffer_s *vb_ptr = (gl_vertex_buffer_s *)dst_location->v_data_ptr;

  const char *format = vertex_buffer_format(vb_ptr->buffer_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(format),format);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_push_back_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
vertex_array:c_bi_class_array
index_array:c_bi_class_array
>
method push_back
; @end

  gl_vertex_buffer_s *vb_ptr = (gl_vertex_buffer_s *)dst_location->v_data_ptr;
  pointer_array_s *vert_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  pointer_array_s *idx_array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (vert_array_ptr->used <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_VERTEX_ARRAY_IS_EMPTY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (idx_array_ptr->used <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_INDEX_ARRAY_IS_EMPTY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (vert_array_ptr->used % vb_ptr->vert_item_cnt != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_VERTEX_ARRAY_NOT_ALIGNED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned vert_cnt = vert_array_ptr->used/vb_ptr->vert_item_cnt;

  // - create vertex data buffer -
  void *vert_buffer = cmalloc(vert_cnt*vb_ptr->vert_size);
  char *v_ptr = (char *)vert_buffer;

  // - create index data buffer -
  unsigned *idx_buffer = (unsigned *)cmalloc(idx_array_ptr->used*sizeof(unsigned));
  unsigned *i_ptr = idx_buffer;

  // - retrieve item types array -
  ui_array_s &vert_item_types = vb_ptr->vert_item_types;

  // - actual item index -
  unsigned item_idx = 0;
  unsigned vert_item_cnt = vb_ptr->vert_item_cnt;

  // - process vertex values -
  {
    pointer *va_ptr = vert_array_ptr->data;
    pointer *va_ptr_end = va_ptr + vert_array_ptr->used;

    double double_value;
    bool type_error = false;
    do {
      location_s *item_location = it.get_location_value(*va_ptr);

      switch (vert_item_types[item_idx])
      {
        case GL_FLOAT:
          {
            if (!it.retrieve_float(item_location,double_value))
            {
              type_error = true;
              break;
            }

            *((float *)v_ptr) = double_value;
            v_ptr += sizeof(float);
          }
          break;
        default:
          cassert(0);
      }

      // - ERROR -
      if (type_error)
      {
        cfree(vert_buffer);
        cfree(idx_buffer);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_WRONG_VERTEX_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(va_ptr - vert_array_ptr->data);

        return false;
      }

      // - move to next item -
      if (++item_idx >= vert_item_cnt)
      {
        item_idx = 0;
      }

    } while(++va_ptr < va_ptr_end);
  }

  // - process index values -
  {
    pointer *ia_ptr = idx_array_ptr->data;
    pointer *ia_ptr_end = ia_ptr + idx_array_ptr->used;

    long long int int_value;
    do {
      location_s *item_location = it.get_location_value(*ia_ptr);

      // - ERROR -
      if (!it.retrieve_integer(item_location,int_value))
      {
        cfree(vert_buffer);
        cfree(idx_buffer);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_WRONG_INDEX_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(ia_ptr - idx_array_ptr->data);

        return false;
      }

      // - ERROR -
      if (int_value < 0 || int_value >= vert_cnt)
      {
        cfree(vert_buffer);
        cfree(idx_buffer);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(int_value);

        return false;
      }

      *i_ptr++ = (unsigned)int_value;

    } while(++ia_ptr < ia_ptr_end);
  }

  // - push data to vertex buffer -
  long long int result = vertex_buffer_push_back(vb_ptr->buffer_ptr,
      vert_buffer,vert_cnt,idx_buffer,idx_array_ptr->used);

  cfree(vert_buffer);
  cfree(idx_buffer);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_render_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
mode:retrieve_integer
>
method render
; @end

  gl_vertex_buffer_s *vb_ptr = (gl_vertex_buffer_s *)dst_location->v_data_ptr;

  vertex_buffer_render(vb_ptr->buffer_ptr,mode);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_vertex_buffer_s *vb_ptr = (gl_vertex_buffer_s *)dst_location->v_data_ptr;

  vertex_buffer_clear(vb_ptr->buffer_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlVertexBuffer"),"GlVertexBuffer");
  );

  return true;
}/*}}}*/

bool bic_gl_vertex_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlVertexBuffer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_FONT -
built_in_class_s gl_font_class =
{/*{{{*/
  "GlFont",
  c_modifier_public | c_modifier_final,
  11, gl_font_methods,
  0, gl_font_variables,
  bic_gl_font_consts,
  bic_gl_font_init,
  bic_gl_font_clear,
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

built_in_method_s gl_font_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_font_operator_binary_equal
  },
  {
    "GlFont#4",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_GlFont_4
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_height_0
  },
  {
    "linegap#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_linegap_0
  },
  {
    "ascender#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_ascender_0
  },
  {
    "descender#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_descender_0
  },
  {
    "buffer#2",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_buffer_2
  },
  {
    "measure#1",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_measure_1
  },
  {
    "bind_texture#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_method_bind_texture_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_font_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_font_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_font_variables[] =
{/*{{{*/
};/*}}}*/

#define GL_FONT_PROCESS_TEXT(POS_X,POS_Y,INITIALIZE,PROCESS_GLYPH) \
{/*{{{*/\
\
  /* - if there are any characters - */\
  if (string_ptr->size > 1)\
  {\
    /* - convert string to wchar string - */\
    unsigned *wstring = (unsigned *)cmalloc(string_ptr->size*sizeof(unsigned));\
    int wsize = string_s::utf8_to_utf32(string_ptr->data,wstring,string_ptr->size);\
\
    /* - ERROR - */\
    if (wsize < 0)\
    {\
      cfree(wstring);\
\
      exception_s::throw_exception(it,module.error_base + c_error_GL_FONT_BUFFER_CONVERT_TO_WCHAR_STRING_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
    INITIALIZE;\
\
    /* - process all wide characters - */\
    unsigned *wc_ptr = wstring;\
    unsigned *wc_ptr_end = wc_ptr + wsize - 1;\
    unsigned last_wchar = 0;\
    do {\
\
      if (*wc_ptr == '\n')\
      {\
        last_wchar = 0;\
        POS_X = 0.0f;\
        POS_Y -= font_ptr->height;\
        POS_Y = (int)POS_Y;\
\
        continue;\
      }\
\
      texture_glyph_t *glyph_ptr = texture_font_get_glyph(font_ptr,*wc_ptr);\
\
      /* - ERROR - */\
      if (glyph_ptr == nullptr)\
      {\
        cfree(wstring);\
\
        exception_s::throw_exception(it,module.error_base + c_error_GL_FONT_GLYPH_RETRIEVE_ERROR_ATLAS_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
\
      /* - if last wide char is defined - */\
      if (last_wchar != 0)\
      {\
        POS_X += texture_glyph_get_kerning(glyph_ptr,last_wchar);\
      }\
\
      PROCESS_GLYPH;\
\
      /* - change carriage position - */\
      POS_X += glyph_ptr->advance_x;\
\
      /* - update last wide char - */\
      last_wchar = *wc_ptr;\
\
    } while(++wc_ptr < wc_ptr_end);\
\
    cfree(wstring);\
  }\
}/*}}}*/

void bic_gl_font_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_font_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gl_font_s *)nullptr;
}/*}}}*/

void bic_gl_font_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gl_font_s *glf_ptr = (gl_font_s *)location_ptr->v_data_ptr;

  // - if gl font exists -
  if (glf_ptr != nullptr)
  {
    glf_ptr->clear(it);
    cfree(glf_ptr);
  }
}/*}}}*/

bool bic_gl_font_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_font_method_GlFont_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
font_size:retrieve_integer
width:retrieve_integer
height:retrieve_integer
>
method GlFont
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (width <= 0 || height <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GL_FONT_INVALID_TEXTURE_ATLAS_DIMENSIONS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(width);
    new_exception->params.push(height);

    return false;
  }

  texture_atlas_t *atlas_ptr = texture_atlas_new(width,height,1);
  texture_font_t *font_ptr = texture_font_new(atlas_ptr,string_ptr->data,font_size);

  // - ERROR -
  if (font_ptr == nullptr)
  {
    texture_atlas_delete(atlas_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_GL_FONT_CANNOT_READ_FROM_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create gl font object -
  gl_font_s *glf_ptr = (gl_font_s *)cmalloc(sizeof(gl_font_s));
  glf_ptr->init();

  glf_ptr->atlas_ptr = atlas_ptr;
  glf_ptr->font_ptr = font_ptr;

  dst_location->v_data_ptr = (gl_font_s *)glf_ptr;

  return true;
}/*}}}*/

bool bic_gl_font_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_s *glf_ptr = (gl_font_s *)dst_location->v_data_ptr;
  texture_font_t *font_ptr = glf_ptr->font_ptr;

  double result = font_ptr->height;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_gl_font_method_linegap_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_s *glf_ptr = (gl_font_s *)dst_location->v_data_ptr;
  texture_font_t *font_ptr = glf_ptr->font_ptr;

  double result = font_ptr->linegap;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_gl_font_method_ascender_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_s *glf_ptr = (gl_font_s *)dst_location->v_data_ptr;
  texture_font_t *font_ptr = glf_ptr->font_ptr;

  double result = font_ptr->ascender;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_gl_font_method_descender_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_s *glf_ptr = (gl_font_s *)dst_location->v_data_ptr;
  texture_font_t *font_ptr = glf_ptr->font_ptr;

  double result = font_ptr->descender;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_gl_font_method_buffer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
vertex_name:c_bi_class_string
tex_coord_name:c_bi_class_string
>
method buffer
; @end

  // - retrieve names of shader attribute variables -
  string_s *vertex_name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *tex_coord_name_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create buffer description string -
  string_s buff_str;
  buff_str.init();
  buff_str.setf("%s:3f,%s:2f",vertex_name_ptr->data,tex_coord_name_ptr->data);

  // - create new vertex buffer -
  vertex_buffer_t *buffer_ptr = vertex_buffer_new(buff_str.data);
  buff_str.clear();

  // - ERROR -
  if (buffer_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_VERTEX_BUFFER_CANNOT_CREATE_NEW,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create gl font buffer object -
  gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)cmalloc(sizeof(gl_font_buffer_s));
  glfb_ptr->init();

  // - set reference to gl font -
  dst_location->v_reference_cnt.atomic_inc();
  glfb_ptr->font_ptr = dst_location;

  // - set buffer pointer -
  glfb_ptr->buffer_ptr = buffer_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gl_font_buffer,glfb_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gl_font_method_measure_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
text:c_bi_class_string
>
method measure
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - maximal and minimal values -
  int max_x = 0;
  int max_y = 0;
  int min_y = 0;

  // - expand process text macro -
  GL_FONT_PROCESS_TEXT(pos_x,pos_y,

    // - retrieve font -
    gl_font_s *glf_ptr = (gl_font_s *)dst_location->v_data_ptr;
    texture_font_t *font_ptr = glf_ptr->font_ptr;

    int pos_x = 0;
    int pos_y = 0;
  ,
    int x = pos_x + glyph_ptr->offset_x + glyph_ptr->width;
    int y0 = pos_y + glyph_ptr->offset_y;
    int y1 = y0 - glyph_ptr->height;

    // - update maximal and minimal values -
    max_x = x > max_x ? x : max_x;
    max_y = y0 > max_y ? y0 : max_y;
    min_y = y1 < min_y ? y1 : min_y;
  );

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create max_x location -
  {
    long long int value = max_x;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create max_y location -
  {
    long long int value = max_y;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create min_y location -
  {
    long long int value = min_y;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gl_font_method_bind_texture_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_s *glf_ptr = (gl_font_s *)dst_location->v_data_ptr;

  texture_atlas_t *atlas_ptr = glf_ptr->atlas_ptr;
  glBindTexture(GL_TEXTURE_2D,atlas_ptr->id);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_font_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlFont"),"GlFont");
  );

  return true;
}/*}}}*/

bool bic_gl_font_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlFont");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_FONT_BUFFER -
built_in_class_s gl_font_buffer_class =
{/*{{{*/
  "GlFontBuffer",
  c_modifier_public | c_modifier_final,
  8, gl_font_buffer_methods,
  0, gl_font_buffer_variables,
  bic_gl_font_buffer_consts,
  bic_gl_font_buffer_init,
  bic_gl_font_buffer_clear,
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

built_in_method_s gl_font_buffer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_font_buffer_operator_binary_equal
  },
  {
    "set_pos#2",
    c_modifier_public | c_modifier_final,
    bic_gl_font_buffer_method_set_pos_2
  },
  {
    "get_pos#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_buffer_method_get_pos_0
  },
  {
    "push_text#1",
    c_modifier_public | c_modifier_final,
    bic_gl_font_buffer_method_push_text_1
  },
  {
    "render#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_buffer_method_render_0
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_gl_font_buffer_method_clear_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_font_buffer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_font_buffer_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_font_buffer_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_font_buffer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_font_buffer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gl_font_buffer_s *)nullptr;
}/*}}}*/

void bic_gl_font_buffer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)location_ptr->v_data_ptr;

  // - if gl font buffer exists -
  if (glfb_ptr != nullptr)
  {
    glfb_ptr->clear(it);
    cfree(glfb_ptr);
  }
}/*}}}*/

bool bic_gl_font_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_set_pos_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
pos_x:retrieve_float
pos_y:retrieve_float
>
method set_pos
; @end

  gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)dst_location->v_data_ptr;

  // - update carriage position -
  glfb_ptr->pos_x = pos_x;
  glfb_ptr->pos_y = pos_y;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_get_pos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create pos_x location -
  {
    long long int value = glfb_ptr->pos_x;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create pos_y location -
  {
    long long int value = glfb_ptr->pos_y;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  }

  // - create result array location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_push_text_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
text:c_bi_class_string
>
method push_text
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - expand process text macro -
  GL_FONT_PROCESS_TEXT(pos_x,pos_y,

    // - retrieve font and vertex buffer -
    gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)dst_location->v_data_ptr;
    gl_font_s *glf_ptr = (gl_font_s *)glfb_ptr->font_ptr->v_data_ptr;

    texture_font_t *font_ptr = glf_ptr->font_ptr;
    vertex_buffer_t *buffer_ptr = glfb_ptr->buffer_ptr;

    // - retrieve actual position -
    int &pos_x = glfb_ptr->pos_x;
    int &pos_y = glfb_ptr->pos_y;

    GLuint indices[6] = {0 MP_COMMA 1 MP_COMMA 2 MP_COMMA  0 MP_COMMA 2 MP_COMMA 3};
    float vertices[20] =
    {
      0 MP_COMMA 0 MP_COMMA 0 MP_COMMA  0 MP_COMMA 0 MP_COMMA
      0 MP_COMMA 0 MP_COMMA 0 MP_COMMA  0 MP_COMMA 0 MP_COMMA
      0 MP_COMMA 0 MP_COMMA 0 MP_COMMA  0 MP_COMMA 0 MP_COMMA
      0 MP_COMMA 0 MP_COMMA 0 MP_COMMA  0 MP_COMMA 0
    };

    float &sx0 = vertices[0];
    float &sy0 = vertices[1];
    float &ss0 = vertices[3];
    float &st0 = vertices[4];

    float &sx1 = vertices[5];
    float &sy1 = vertices[5+1];
    float &ss1 = vertices[5+3];
    float &st1 = vertices[5+4];

    float &sx2 = vertices[10];
    float &sy2 = vertices[10+1];
    float &ss2 = vertices[10+3];
    float &st2 = vertices[10+4];

    float &sx3 = vertices[15];
    float &sy3 = vertices[15+1];
    float &ss3 = vertices[15+3];
    float &st3 = vertices[15+4];
  ,
    register float x0 = pos_x + glyph_ptr->offset_x;
    register float y0 = pos_y + glyph_ptr->offset_y;
    register float x1 = x0 + glyph_ptr->width;
    register float y1 = y0 - glyph_ptr->height;
    register float s0 = glyph_ptr->s0;
    register float t0 = glyph_ptr->t0;
    register float s1 = glyph_ptr->s1;
    register float t1 = glyph_ptr->t1;

    sx0 = x0; sy0 = y0; ss0 = s0; st0 = t0;
    sx1 = x0; sy1 = y1; ss1 = s0; st1 = t1;
    sx2 = x1; sy2 = y1; ss2 = s1; st2 = t1;
    sx3 = x1; sy3 = y0; ss3 = s1; st3 = t0;

    // - push vertices to buffer -
    vertex_buffer_push_back(buffer_ptr MP_COMMA vertices MP_COMMA 4 MP_COMMA indices MP_COMMA 6);
  )

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_render_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)dst_location->v_data_ptr;
  gl_font_s *glf_ptr = (gl_font_s *)glfb_ptr->font_ptr->v_data_ptr;

  glBindTexture(GL_TEXTURE_2D,glf_ptr->atlas_ptr->id);
  vertex_buffer_render(glfb_ptr->buffer_ptr,GL_TRIANGLES);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_font_buffer_s *glfb_ptr = (gl_font_buffer_s *)dst_location->v_data_ptr;

  vertex_buffer_clear(glfb_ptr->buffer_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlFontBuffer"),"GlFontBuffer");
  );

  return true;
}/*}}}*/

bool bic_gl_font_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlFontBuffer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

