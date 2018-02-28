
@begin
include "gl_module.h"
@end

// - GL indexes of built in classes -
unsigned c_bi_class_gl = c_idx_not_exist;
unsigned c_bi_class_gl_shader = c_idx_not_exist;
unsigned c_bi_class_gl_program = c_idx_not_exist;
unsigned c_bi_class_gl_attribute = c_idx_not_exist;
unsigned c_bi_class_gl_uniform = c_idx_not_exist;
unsigned c_bi_class_gl_texture = c_idx_not_exist;

// - GL indexes of remote classes -
unsigned c_rm_class_vec2 = c_idx_not_exist;
unsigned c_rm_class_vec3 = c_idx_not_exist;
unsigned c_rm_class_vec4 = c_idx_not_exist;
unsigned c_rm_class_mat4 = c_idx_not_exist;

// - GL module -
built_in_module_s module =
{/*{{{*/
  6,                   // Class count
  gl_classes,          // Classes

  0,                   // Error base index
  12,                  // Error count
  gl_error_strings,    // Error strings

  gl_initialize,       // Initialize function
  gl_print_exception,  // Print exceptions function
};/*}}}*/

// - GL classes -
built_in_class_s *gl_classes[] =
{/*{{{*/
  &gl_class,
  &gl_shader_class,
  &gl_program_class,
  &gl_attribute_class,
  &gl_uniform_class,
  &gl_texture_class,
};/*}}}*/

// - GL error strings -
const char *gl_error_strings[] =
{/*{{{*/
  "error_GL_WRONG_WIDTH_OR_HEIGHT_VALUE",
  "error_GL_SHADER_CANNOT_CREATE_SHADER",
  "error_GL_SHADER_CANNOT_COMPILE_SHADER",
  "error_GL_PROGRAM_CANNOT_CREATE_PROGRAM",
  "error_GL_PROGRAM_CANNOT_LINK_PROGRAM",
  "error_GL_UNIFORM_NOT_SUPPORTED_TYPE",
  "error_GL_UNIFORM_WRONG_VALUE_TYPE",
  "error_GL_TEXTURE_UNSUPPORTED_PIXEL_FORMAT",
  "error_GL_TEXTURE_INVALID_DIMENSIONS",
  "error_GL_TEXTURE_WRONG_BUFFER_SIZE",
  "error_GL_TEXTURE_IMAGE_LOAD_ERROR",
  "error_GL_TEXTURE_IMAGE_CLEAR_ERROR",
};/*}}}*/

// - GL initialize -
bool gl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gl class identifier -
  c_bi_class_gl = class_base_idx++;

  // - initialize gl_shader class identifier -
  c_bi_class_gl_shader = class_base_idx++;

  // - initialize gl_program class identifier -
  c_bi_class_gl_program = class_base_idx++;

  // - initialize gl_attribute class identifier -
  c_bi_class_gl_attribute = class_base_idx++;

  // - initialize gl_uniform class identifier -
  c_bi_class_gl_uniform = class_base_idx++;

  // - initialize gl_texture class identifier -
  c_bi_class_gl_texture = class_base_idx++;

  // - retrieve remote vec3 class index -
  c_rm_class_vec2 = sp.resolve_class_idx_by_name("Vec2",c_idx_not_exist);

  // - retrieve remote vec3 class index -
  c_rm_class_vec3 = sp.resolve_class_idx_by_name("Vec3",c_idx_not_exist);

  // - retrieve remote vec3 class index -
  c_rm_class_vec4 = sp.resolve_class_idx_by_name("Vec4",c_idx_not_exist);

  // - retrieve remote mat4 class index -
  c_rm_class_mat4 = sp.resolve_class_idx_by_name("Mat4",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_vec2 == c_idx_not_exist ||
      c_rm_class_vec3 == c_idx_not_exist ||
      c_rm_class_vec4 == c_idx_not_exist ||
      c_rm_class_mat4 == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - GL print exception -
bool gl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GL_WRONG_WIDTH_OR_HEIGHT_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong width or height value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_SHADER_CANNOT_CREATE_SHADER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create new shader object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_SHADER_CANNOT_COMPILE_SHADER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot compile shader object. Shader compile log:\n");
    fprintf(stderr,"\n%s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_PROGRAM_CANNOT_CREATE_PROGRAM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create new shader program\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_PROGRAM_CANNOT_LINK_PROGRAM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot link shader program. Program link log:\n");
    fprintf(stderr,"\n%s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_UNIFORM_NOT_SUPPORTED_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported type 0x%" HOST_LL_FORMAT "x of uniform variable\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_UNIFORM_WRONG_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nValue type differs from uniform type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_TEXTURE_UNSUPPORTED_PIXEL_FORMAT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported pixel format of texture\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_TEXTURE_INVALID_DIMENSIONS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid texture dimensions %" HOST_LL_FORMAT "d x %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_TEXTURE_WRONG_BUFFER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid texture buffer size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_TEXTURE_IMAGE_LOAD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while loading texture image data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GL_TEXTURE_IMAGE_CLEAR_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while clearing texture image data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GL -
built_in_class_s gl_class =
{/*{{{*/
  "Gl",
  c_modifier_public | c_modifier_final,
  10, gl_methods,

#if defined(UCBOX_IMX6) || defined(ANDROID) || defined(NACL) || defined(EMSCRIPTEN)
  302
#ifndef EMSCRIPTEN
  + 1
#endif
  ,
#elif defined(LINUX)
  4876,
#endif

  gl_variables,
  bic_gl_consts,
  bic_gl_init,
  bic_gl_clear,
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

built_in_method_s gl_methods[] =
{/*{{{*/
  {
    "ClearColor#4",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_ClearColor_4
  },
  {
    "Clear#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_Clear_1
  },
  {
    "BlendFunc#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_BlendFunc_2
  },
  {
    "Enable#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_Enable_1
  },
  {
    "Disable#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_Disable_1
  },
  {
    "IsEnabled#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_IsEnabled_1
  },
  {
    "Viewport#4",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_Viewport_4
  },
  {
    "Finish#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_Finish_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_method_print_0
  },
};/*}}}*/

void bic_gl_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_gl_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_gl_method_ClearColor_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  double red;
  double green;
  double blue;
  double alpha;

  if (!it.retrieve_float(src_0_location,red) ||
      !it.retrieve_float(src_1_location,green) ||
      !it.retrieve_float(src_2_location,blue) ||
      !it.retrieve_float(src_3_location,alpha))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"ClearColor#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  glClearColor(red,green,blue,alpha);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_Clear_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int mask;

  if (!it.retrieve_integer(src_0_location,mask))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"Clear#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glClear(mask);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_BlendFunc_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int sfactor;
  long long int dfactor;

  if (!it.retrieve_integer(src_0_location,sfactor) ||
      !it.retrieve_integer(src_1_location,dfactor))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"BlendFunc#1");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  glBlendFunc(sfactor,dfactor);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_Enable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int cap;

  if (!it.retrieve_integer(src_0_location,cap))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"Enable#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glEnable(cap);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_Disable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int cap;

  if (!it.retrieve_integer(src_0_location,cap))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"Disable#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glDisable(cap);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_IsEnabled_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int cap;

  if (!it.retrieve_integer(src_0_location,cap))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"IsEnabled#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int result = glIsEnabled(cap);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_method_Viewport_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int x;
  long long int y;
  long long int width;
  long long int height;

  if (!it.retrieve_integer(src_0_location,x) ||
      !it.retrieve_integer(src_1_location,y) ||
      !it.retrieve_integer(src_2_location,width) ||
      !it.retrieve_integer(src_3_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_gl,"Viewport#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - ERROR -
  if (width < 0 || height < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_WRONG_WIDTH_OR_HEIGHT_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  glViewport(x,y,width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_Finish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  glFinish();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Gl"),"Gl");
  );

  return true;
}/*}}}*/

bool bic_gl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Gl");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_SHADER -
built_in_class_s gl_shader_class =
{/*{{{*/
  "GlShader",
  c_modifier_public | c_modifier_final,
  7, gl_shader_methods,
  0, gl_shader_variables,
  bic_gl_shader_consts,
  bic_gl_shader_init,
  bic_gl_shader_clear,
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

built_in_method_s gl_shader_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_shader_operator_binary_equal
  },
  {
    "GlShader#1",
    c_modifier_public | c_modifier_final,
    bic_gl_shader_method_GlShader_1
  },
  {
    "GlShader#2",
    c_modifier_public | c_modifier_final,
    bic_gl_shader_method_GlShader_2
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_gl_shader_method_get_type_0
  },
  {
    "source#0",
    c_modifier_public | c_modifier_final,
    bic_gl_shader_method_source_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_shader_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_shader_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_shader_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_shader_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_shader_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (long long int)0;
}/*}}}*/

void bic_gl_shader_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  long long int shader = (long long int)location_ptr->v_data_ptr;

  if (shader != 0)
  {
    glDeleteShader(shader);
  }
}/*}}}*/

bool bic_gl_shader_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_shader_method_GlShader_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int shader_type;

  if (!it.retrieve_integer(src_0_location,shader_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Glshader#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int shader = glCreateShader(shader_type);

  // - ERROR -
  if (shader == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_SHADER_CANNOT_CREATE_SHADER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (long long int)shader;

  return true;
}/*}}}*/

bool bic_gl_shader_method_GlShader_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int shader_type;

  if (!it.retrieve_integer(src_0_location,shader_type) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Glshader#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  long long int shader = glCreateShader(shader_type);

  // - ERROR -
  if (shader == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_SHADER_CANNOT_CREATE_SHADER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set source code of shader object -
  int length = string_ptr->size - 1;
  glShaderSource(shader,1,(const GLchar **)&string_ptr->data,&length);

  // - compile shader object -
  glCompileShader(shader);

  // - retrieve shader compile status -
  GLint compile_status;
  glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_status);

  // - ERROR -
  if (compile_status != GL_TRUE)
  {
    // - retrieve error log size -
    GLint log_size;
    glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&log_size);

    string_s *err_string = it.get_new_string_ptr();

    if (log_size != 0)
    {
      err_string->create(log_size - 1);

      // - retrieve error log -
      glGetShaderInfoLog(shader,log_size,nullptr,err_string->data);
    }

    // - delete shader object -
    glDeleteShader(shader);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,err_string,0);

    exception_s::throw_exception(it,module.error_base + c_error_GL_SHADER_CANNOT_COMPILE_SHADER,operands[c_source_pos_idx],new_location);
    return false;
  }

  dst_location->v_data_ptr = (long long int)shader;

  return true;
}/*}}}*/

bool bic_gl_shader_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int shader = (long long int)dst_location->v_data_ptr;

  GLint shader_type;
  glGetShaderiv(shader,GL_SHADER_TYPE,&shader_type);

  long long int result = shader_type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_shader_method_source_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int shader = (long long int)dst_location->v_data_ptr;

  GLint source_size;
  glGetShaderiv(shader,GL_SHADER_SOURCE_LENGTH,&source_size);

  if (source_size != 0)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->create(source_size - 1);

    glGetShaderSource(shader,source_size,nullptr,string_ptr->data);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    BIC_SET_RESULT(new_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_gl_shader_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlShader"),"GlShader");
  );

  return true;
}/*}}}*/

bool bic_gl_shader_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlShader");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_PROGRAM -
built_in_class_s gl_program_class =
{/*{{{*/
  "GlProgram",
  c_modifier_public | c_modifier_final,
  8, gl_program_methods,
  0, gl_program_variables,
  bic_gl_program_consts,
  bic_gl_program_init,
  bic_gl_program_clear,
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

built_in_method_s gl_program_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_program_operator_binary_equal
  },
  {
    "GlProgram#0",
    c_modifier_public | c_modifier_final,
    bic_gl_program_method_GlProgram_0
  },
  {
    "GlProgram#2",
    c_modifier_public | c_modifier_final,
    bic_gl_program_method_GlProgram_2
  },
  {
    "active_attributes#0",
    c_modifier_public | c_modifier_final,
    bic_gl_program_method_active_atributes_0
  },
  {
    "active_uniforms#0",
    c_modifier_public | c_modifier_final,
    bic_gl_program_method_active_uniforms_0
  },
  {
    "use#0",
    c_modifier_public | c_modifier_final,
    bic_gl_program_method_use_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_program_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_program_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_program_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_program_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_program_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (long long int)0;
}/*}}}*/

void bic_gl_program_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  long long int program = (long long int)location_ptr->v_data_ptr;

  // - if program exists -
  if (program != 0)
  {
    glDeleteProgram(program);
  }
}/*}}}*/

bool bic_gl_program_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_program_method_GlProgram_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = glCreateProgram();

  // - ERROR -
  if (result == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_PROGRAM_CANNOT_CREATE_PROGRAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (long long int)result;

  return true;
}/*}}}*/

bool bic_gl_program_method_GlProgram_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_gl_shader ||
      src_1_location->v_type != c_bi_class_gl_shader)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GlProgram#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  long long int v_shader = (long long int)src_0_location->v_data_ptr;
  long long int f_shader = (long long int)src_1_location->v_data_ptr;

  // - create shader program -
  long long int program = glCreateProgram();

  // - ERROR -
  if (program == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_PROGRAM_CANNOT_CREATE_PROGRAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - attach shaders to program -
  glAttachShader(program,v_shader);
  glAttachShader(program,f_shader);

  // - link shader program -
  glLinkProgram(program);

  // - retrieve program link status -
  GLint link_status;
  glGetProgramiv(program,GL_LINK_STATUS,&link_status);

  // - ERROR -
  if (link_status != GL_TRUE)
  {
    // - retrieve error log size -
    GLint log_size;
    glGetProgramiv(program,GL_INFO_LOG_LENGTH,&log_size);

    string_s *err_string = it.get_new_string_ptr();

    if (log_size != 0)
    {
      err_string->create(log_size - 1);

      // - retrieve error log -
      glGetProgramInfoLog(program,log_size,nullptr,err_string->data);
    }

    // - delete shader program -
    glDeleteProgram(program);

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,err_string,0);

    exception_s::throw_exception(it,module.error_base + c_error_GL_PROGRAM_CANNOT_LINK_PROGRAM,operands[c_source_pos_idx],new_location);
    return false;
  }

  dst_location->v_data_ptr = (long long int)program;

  return true;
}/*}}}*/

bool bic_gl_program_method_active_atributes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int program = (long long int)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  GLint attr_cnt;
  glGetProgramiv(program,GL_ACTIVE_ATTRIBUTES,&attr_cnt);

  GLint buff_size;
  glGetProgramiv(program,GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,&buff_size);

  char name_buff[buff_size];

  if (attr_cnt > 0)
  {
    GLint attr_idx = 0;
    do {
      GLsizei length;
      GLint size;
      GLenum type;

      glGetActiveAttrib(program,attr_idx,buff_size,&length,&size,&type,name_buff);

      // - create name location -
      string_s *name_ptr = it.get_new_string_ptr();
      name_ptr->set(length,name_buff);

      BIC_CREATE_NEW_LOCATION_REFS(name_location,c_bi_class_string,name_ptr,2);

      // - push attribute name -
      array_ptr->push(name_location);

      // - create gl_attribute object -
      gl_attribute_s *gla_ptr = (gl_attribute_s *)cmalloc(sizeof(gl_attribute_s));
      gla_ptr->init();

      // - create program reference -
      dst_location->v_reference_cnt.atomic_inc();
      gla_ptr->program_ptr = dst_location;

      gla_ptr->name_ptr = name_location;
      gla_ptr->index = glGetAttribLocation(program,name_buff);;
      gla_ptr->size = size;
      gla_ptr->type = type;

      BIC_CREATE_NEW_LOCATION(attr_location,c_bi_class_gl_attribute,gla_ptr);

      // - push attribute object -
      array_ptr->push(attr_location);

    } while(++attr_idx < attr_cnt);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gl_program_method_active_uniforms_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int program = (long long int)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  GLint uni_cnt;
  glGetProgramiv(program,GL_ACTIVE_UNIFORMS,&uni_cnt);

  GLint buff_size;
  glGetProgramiv(program,GL_ACTIVE_UNIFORM_MAX_LENGTH,&buff_size);

  char name_buff[buff_size];

  if (uni_cnt > 0)
  {
    GLint uni_idx = 0;
    do {
      GLsizei length;
      GLint size;
      GLenum type;

      glGetActiveUniform(program,uni_idx,buff_size,&length,&size,&type,name_buff);

      // - create name location -
      string_s *name_ptr = it.get_new_string_ptr();
      name_ptr->set(length,name_buff);

      BIC_CREATE_NEW_LOCATION_REFS(name_location,c_bi_class_string,name_ptr,2);

      // - push uniform name -
      array_ptr->push(name_location);

      // - create gl_uniform object -
      gl_uniform_s *glu_ptr = (gl_uniform_s *)cmalloc(sizeof(gl_uniform_s));
      glu_ptr->init();

      // - create program reference -
      dst_location->v_reference_cnt.atomic_inc();
      glu_ptr->program_ptr = dst_location;

      glu_ptr->name_ptr = name_location;
      glu_ptr->index = glGetUniformLocation(program,name_buff);
      glu_ptr->size = size;
      glu_ptr->type = type;

      BIC_CREATE_NEW_LOCATION(uni_location,c_bi_class_gl_uniform,glu_ptr);

      // - push uniform object -
      array_ptr->push(uni_location);

    } while(++uni_idx < uni_cnt);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gl_program_method_use_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int program = (long long int)dst_location->v_data_ptr;

  glUseProgram(program);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_program_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlProgram"),"GlProgram");
  );

  return true;
}/*}}}*/

bool bic_gl_program_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlProgram");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_ATTRIBUTE -
built_in_class_s gl_attribute_class =
{/*{{{*/
  "GlAttribute",
  c_modifier_public | c_modifier_final,
  7, gl_attribute_methods,
  0, gl_attribute_variables,
  bic_gl_attribute_consts,
  bic_gl_attribute_init,
  bic_gl_attribute_clear,
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

built_in_method_s gl_attribute_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_attribute_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_attribute_method_name_0
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_attribute_method_index_0
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_attribute_method_size_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_attribute_method_get_type_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_attribute_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_attribute_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_attribute_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_attribute_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_attribute_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gl_attribute_s *)nullptr;
}/*}}}*/

void bic_gl_attribute_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gl_attribute_s *gla_ptr = (gl_attribute_s *)location_ptr->v_data_ptr;

  // - if gl attribute exists -
  if (gla_ptr != nullptr)
  {
    gla_ptr->clear(it);
    cfree(gla_ptr);
  }
}/*}}}*/

bool bic_gl_attribute_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_attribute_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_attribute_s *gla_ptr = (gl_attribute_s *)dst_location->v_data_ptr;

  location_s *name_location = gla_ptr->name_ptr;

  name_location->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(name_location);

  return true;
}/*}}}*/

bool bic_gl_attribute_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_attribute_s *gla_ptr = (gl_attribute_s *)dst_location->v_data_ptr;

  long long int result = gla_ptr->index;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_attribute_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_attribute_s *gla_ptr = (gl_attribute_s *)dst_location->v_data_ptr;

  long long int result = gla_ptr->size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_attribute_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_attribute_s *gla_ptr = (gl_attribute_s *)dst_location->v_data_ptr;

  long long int result = gla_ptr->type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_attribute_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlAttribute"),"GlAttribute");
  );

  return true;
}/*}}}*/

bool bic_gl_attribute_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlAttribute");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_UNIFORM -
built_in_class_s gl_uniform_class =
{/*{{{*/
  "GlUniform",
  c_modifier_public | c_modifier_final,
  8, gl_uniform_methods,
  0, gl_uniform_variables,
  bic_gl_uniform_consts,
  bic_gl_uniform_init,
  bic_gl_uniform_clear,
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

built_in_method_s gl_uniform_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_uniform_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_name_0
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_index_0
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_size_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_get_type_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_write_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_uniform_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_uniform_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_uniform_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_uniform_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gl_uniform_s *)nullptr;
}/*}}}*/

void bic_gl_uniform_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gl_uniform_s *glu_ptr = (gl_uniform_s *)location_ptr->v_data_ptr;

  // - if gl uniform exists -
  if (glu_ptr != nullptr)
  {
    glu_ptr->clear(it);
    cfree(glu_ptr);
  }
}/*}}}*/

bool bic_gl_uniform_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_uniform_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_uniform_s *glu_ptr = (gl_uniform_s *)dst_location->v_data_ptr;

  location_s *name_location = glu_ptr->name_ptr;

  name_location->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(name_location);

  return true;
}/*}}}*/

bool bic_gl_uniform_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_uniform_s *glu_ptr = (gl_uniform_s *)dst_location->v_data_ptr;

  long long int result = glu_ptr->index;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_uniform_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_uniform_s *glu_ptr = (gl_uniform_s *)dst_location->v_data_ptr;

  long long int result = glu_ptr->size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_uniform_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_uniform_s *glu_ptr = (gl_uniform_s *)dst_location->v_data_ptr;

  long long int result = glu_ptr->type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_uniform_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  gl_uniform_s *glu_ptr = (gl_uniform_s *)dst_location->v_data_ptr;

  bool type_error = false;

  switch (glu_ptr->type)
  {

  case GL_FLOAT:
    {/*{{{*/
      double value;
      if (!it.retrieve_float(src_0_location,value))
      {
        type_error = true;
        break;
      }

      glUniform1f(glu_ptr->index,value);
    }/*}}}*/
    break;

  case GL_BOOL:
  case GL_SAMPLER_2D:
    {/*{{{*/
      long long int value;
      if (!it.retrieve_integer(src_0_location,value))
      {
        type_error = true;
        break;
      }

      glUniform1i(glu_ptr->index,value);
    }/*}}}*/
    break;

  case GL_FLOAT_VEC2:
    {/*{{{*/
      if (src_0_location->v_type != c_rm_class_vec2)
      {
        type_error = true;
        break;
      }

      glm::vec2 &v2 = *((glm::vec2 *)src_0_location->v_data_ptr);
      glUniform2fv(glu_ptr->index,1,glm::value_ptr(v2));
    }/*}}}*/
    break;

  case GL_FLOAT_VEC3:
    {/*{{{*/
      if (src_0_location->v_type != c_rm_class_vec3)
      {
        type_error = true;
        break;
      }

      glm::vec3 &v3 = *((glm::vec3 *)src_0_location->v_data_ptr);
      glUniform3fv(glu_ptr->index,1,glm::value_ptr(v3));
    }/*}}}*/
    break;

  case GL_FLOAT_VEC4:
    {/*{{{*/
      if (src_0_location->v_type != c_rm_class_vec4)
      {
        type_error = true;
        break;
      }

      glm::vec4 &v4 = *((glm::vec4 *)src_0_location->v_data_ptr);
      glUniform4fv(glu_ptr->index,1,glm::value_ptr(v4));
    }/*}}}*/
    break;

  case GL_FLOAT_MAT4:
    {/*{{{*/
      if (src_0_location->v_type != c_rm_class_mat4)
      {
        type_error = true;
        break;
      }

      glm::mat4 &m4 = *((glm::mat4 *)src_0_location->v_data_ptr);
      glUniformMatrix4fv(glu_ptr->index,1,0,glm::value_ptr(m4));
    }/*}}}*/
    break;

  // - ERROR -
  default:

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GL_UNIFORM_NOT_SUPPORTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(glu_ptr->type);

    return false;
  }

  // - ERROR -
  if (type_error)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_UNIFORM_WRONG_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_uniform_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlUniform"),"GlUniform");
  );

  return true;
}/*}}}*/

bool bic_gl_uniform_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlUniform");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GL_TEXTURE -
built_in_class_s gl_texture_class =
{/*{{{*/
  "GlTexture",
  c_modifier_public | c_modifier_final,
  10, gl_texture_methods,
  0, gl_texture_variables,
  bic_gl_texture_consts,
  bic_gl_texture_init,
  bic_gl_texture_clear,
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

built_in_method_s gl_texture_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_operator_binary_equal
  },
  {
    "GlTexture#4",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_GlTexture_4
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_height_0
  },
  {
    "format#0",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_format_0
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_update_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_clear_0
  },
  {
    "bind#0",
    c_modifier_public | c_modifier_final,
    bic_gl_texture_method_bind_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_texture_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gl_texture_method_print_0
  },
};/*}}}*/

built_in_variable_s gl_texture_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gl_texture_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gl_texture_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gl_texture_s *)nullptr;
}/*}}}*/

void bic_gl_texture_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gl_texture_s *glt_ptr = (gl_texture_s *)location_ptr->v_data_ptr;

  // - if texture exists -
  if (glt_ptr != nullptr)
  {
    glt_ptr->clear(it);
    cfree(glt_ptr);
  }
}/*}}}*/

bool bic_gl_texture_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gl_texture_method_GlTexture_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int format;
  long long int width;
  long long int height;

  if (!it.retrieve_integer(src_0_location,format) ||
      !it.retrieve_integer(src_1_location,width) ||
      !it.retrieve_integer(src_2_location,height) ||
      src_3_location->v_type != c_bi_class_buffer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GlTexture#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  unsigned pixel_size;
  switch (format)
  {
  case GL_RGB:
    pixel_size = 3;
    break;

  case GL_RGBA:
    pixel_size = 4;
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  GLint mt_size;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE,&mt_size);

  // - ERROR -
  if (width <= 0 || width > mt_size || height <= 0 || height > mt_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_INVALID_DIMENSIONS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(width);
    new_exception->params.push(height);

    return false;
  }

  unsigned exp_buffer_size = width*height*pixel_size;

  // - retrieve buffer object -
  buffer_s *b_ptr = (buffer_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (b_ptr->size != exp_buffer_size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_WRONG_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create gl texture object -
  gl_texture_s *glt_ptr = (gl_texture_s *)cmalloc(sizeof(gl_texture_s));
  glt_ptr->init();

  glGenTextures(1,&glt_ptr->index);
  dst_location->v_data_ptr = (gl_texture_s *)glt_ptr;

  glBindTexture(GL_TEXTURE_2D,glt_ptr->index);

  // - set default texture parameters -
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D,0,format,width,height,0,format,GL_UNSIGNED_BYTE,b_ptr->data);

  // - ERROR -
  if (glGetError() != GL_NO_ERROR)
  {
    glBindTexture(GL_TEXTURE_2D,0);
    glDeleteTextures(1,&glt_ptr->index);

    exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_IMAGE_LOAD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  glt_ptr->format = format;
  glt_ptr->pixel_size = pixel_size;
  glt_ptr->width = width;
  glt_ptr->height = height;

  return true;
}/*}}}*/

bool bic_gl_texture_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_texture_s *glt_ptr = (gl_texture_s *)dst_location->v_data_ptr;

  long long int result = glt_ptr->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_texture_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_texture_s *glt_ptr = (gl_texture_s *)dst_location->v_data_ptr;

  long long int result = glt_ptr->height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_texture_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_texture_s *glt_ptr = (gl_texture_s *)dst_location->v_data_ptr;

  long long int result = glt_ptr->format;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gl_texture_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_buffer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("update#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  gl_texture_s *glt_ptr = (gl_texture_s *)dst_location->v_data_ptr;

  unsigned exp_buffer_size = glt_ptr->width*glt_ptr->height*glt_ptr->pixel_size;

  // - retrieve buffer object -
  buffer_s *b_ptr = (buffer_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (b_ptr->size != exp_buffer_size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_WRONG_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  glBindTexture(GL_TEXTURE_2D,glt_ptr->index);
  glTexSubImage2D(GL_TEXTURE_2D,0,0,0,glt_ptr->width,glt_ptr->height,glt_ptr->format,GL_UNSIGNED_BYTE,b_ptr->data);

  // - ERROR -
  if (glGetError() != GL_NO_ERROR)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_IMAGE_LOAD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_texture_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_texture_s *glt_ptr = (gl_texture_s *)dst_location->v_data_ptr;

  glBindTexture(GL_TEXTURE_2D,glt_ptr->index);
  glTexImage2D(GL_TEXTURE_2D,0,glt_ptr->format,0,0,0,glt_ptr->format,GL_UNSIGNED_BYTE,nullptr);

  // - ERROR -
  if (glGetError() != GL_NO_ERROR)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GL_TEXTURE_IMAGE_CLEAR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_texture_method_bind_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gl_texture_s *glt_ptr = (gl_texture_s *)dst_location->v_data_ptr;

  glBindTexture(GL_TEXTURE_2D,glt_ptr->index);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gl_texture_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GlTexture"),"GlTexture");
  );

  return true;
}/*}}}*/

bool bic_gl_texture_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GlTexture");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

