
@begin
include "imxegl_module.h"
@end

// - IMXEGL indexes of built in classes -
unsigned c_bi_class_imx_egl = c_idx_not_exist;

#if defined(IPUROT_LINUX)
unsigned c_bi_class_imx_fb = c_idx_not_exist;
unsigned c_bi_class_imx_ipu = c_idx_not_exist;
#endif

// - IMXEGL indexes of remote classes -
unsigned c_rm_class_gl_texture = c_idx_not_exist;

// - IMXEGL module -
built_in_module_s module =
{/*{{{*/
  1                       // Class count

#if defined(IPUROT_LINUX)
  + 2
#endif
  ,
  imxegl_classes,         // Classes

  0,                      // Error base index
  7                       // Error count

#if defined(IPUROT_LINUX)
  + 4
#endif
  ,
  imxegl_error_strings,   // Error strings

  imxegl_initialize,      // Initialize function
  imxegl_print_exception, // Print exceptions function
};/*}}}*/

// - IMXEGL classes -
built_in_class_s *imxegl_classes[] =
{/*{{{*/
  &imx_egl_class,

#if defined(IPUROT_LINUX)
  &imx_fb_class,
  &imx_ipu_class,
#endif
};/*}}}*/

// - IMXEGL error strings -
const char *imxegl_error_strings[] =
{/*{{{*/
  "error_IMX_EGL_UNRECOGNIZED_API",
  "error_IMX_EGL_CREATE_ERROR",
  "error_IMX_EGL_SET_AS_GLOBAL_ERROR",
  "error_IMX_EGL_WRONG_COUNT_OF_TEXTURES_REQUESTED",
  "error_IMX_EGL_WRONG_TEXTURE_INDEX",
  "error_IMX_EGL_MAKE_CURRENT_ERROR",
  "error_IMX_EGL_SWAP_BUFFERS_ERROR",

#if defined(IPUROT_LINUX)
  "error_IMX_FB_FILE_OPEN_ERROR",
  "error_IMX_FB_CANNOT_READ_PROPERTIES",
  "error_IMX_IPU_FILE_OPEN_ERROR",
  "error_IMX_IPU_NO_TASK_PREPARED_FOR_EXECUTION",
#endif
};/*}}}*/

// - IMXEGL initialize -
bool imxegl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize imx egl class identifier -
  c_bi_class_imx_egl = class_base_idx++;

#if defined(IPUROT_LINUX)
  // - initialize imx fb class identifier -
  c_bi_class_imx_fb = class_base_idx++;

  // - initialize imx ipu class identifier -
  c_bi_class_imx_ipu = class_base_idx++;
#endif

  // - retrieve remote gl texture class index -
  c_rm_class_gl_texture = sp.resolve_class_idx_by_name("GlTexture",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_gl_texture == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - IMX_EGL print exception -
bool imxegl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_IMX_EGL_UNRECOGNIZED_API:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized requested EGL API type %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_EGL_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating imxegl redering context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_EGL_SET_AS_GLOBAL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set imxegl rendering context as global\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_EGL_WRONG_COUNT_OF_TEXTURES_REQUESTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong requested count of textures to generate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_EGL_WRONG_TEXTURE_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong index %" HOST_LL_FORMAT "d of texture to get\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_EGL_MAKE_CURRENT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set context as current rendering context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_EGL_SWAP_BUFFERS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while swapping egl buffers\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;

#if defined(IPUROT_LINUX)
  case c_error_IMX_FB_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open framebuffer device file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_FB_CANNOT_READ_PROPERTIES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read framebuffer properties\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_IPU_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open imx IPU device file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_IMX_IPU_NO_TASK_PREPARED_FOR_EXECUTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNo IPU task is prepared for execution\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
#endif
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class IMX_EGL -
built_in_class_s imx_egl_class =
{/*{{{*/
  "ImxEgl",
  c_modifier_public | c_modifier_final,
  13, imx_egl_methods,
  3 + 15, imx_egl_variables,
  bic_imx_egl_consts,
  bic_imx_egl_init,
  bic_imx_egl_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s imx_egl_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_operator_binary_equal
  },
  {
    "ImxEgl#3",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_method_ImxEgl_3
  },
  {
    "set_as_global#0",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_method_set_as_global_0
  },
  {
    "gen_textures#1",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_method_gen_textures_1
  },
  {
    "get_texture#1",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_method_get_texture_1
  },
  {
    "global_lock#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_egl_method_global_lock_0
  },
  {
    "global_unlock#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_egl_method_global_unlock_0
  },
  {
    "global_terminate#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_egl_method_global_terminate_0
  },
  {
    "MakeCurrent#0",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_method_MakeCurrent_0
  },
  {
    "SwapBuffers#0",
    c_modifier_public | c_modifier_final,
    bic_imx_egl_method_SwapBuffers_0
  },
  {
    "GetError#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_egl_method_GetError_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_egl_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_egl_method_print_0
  },
};/*}}}*/

built_in_variable_s imx_egl_variables[] =
{/*{{{*/

  // - egl api identifiers -
  { "EGL_OPENGL_ES_API", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_OPENVG_API", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_OPENGL_API", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - error codes -
  { "EGL_SUCCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_NOT_INITIALIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_ACCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_ALLOC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_ATTRIBUTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_CONTEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_CONFIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_CURRENT_SURFACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_DISPLAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_SURFACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_MATCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_PARAMETER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_NATIVE_PIXMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_BAD_NATIVE_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EGL_CONTEXT_LOST", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_imx_egl_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert egl api identifier constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_EGL_API_ID_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_EGL_API_ID_BIC_STATIC(EGL_OPENGL_ES_API);
    CREATE_EGL_API_ID_BIC_STATIC(EGL_OPENVG_API);
    CREATE_EGL_API_ID_BIC_STATIC(EGL_OPENGL_API);
  }

  // - insert egl error code constants -
  {
    const_locations.push_blanks(15);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 15);

#define CREATE_EGL_ERROR_CODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_SUCCESS);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_NOT_INITIALIZED);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_ACCESS);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_ALLOC);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_ATTRIBUTE);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_CONTEXT);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_CONFIG);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_CURRENT_SURFACE);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_DISPLAY);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_SURFACE);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_MATCH);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_PARAMETER);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_NATIVE_PIXMAP);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_BAD_NATIVE_WINDOW);
    CREATE_EGL_ERROR_CODE_BIC_STATIC(EGL_CONTEXT_LOST);
  }
}/*}}}*/

void bic_imx_egl_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (imx_egl_s *)NULL;
}/*}}}*/

void bic_imx_egl_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  imx_egl_s *ie_ptr = (imx_egl_s *)location_ptr->v_data_ptr;

  if (ie_ptr != NULL)
  {
    ie_ptr->clear(it);
    cfree(ie_ptr);
  }
}/*}}}*/

bool bic_imx_egl_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_imx_egl_method_ImxEgl_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int api_type;
  long long int width;
  long long int height;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,api_type) ||
      !it.retrieve_integer(src_1_location,width) ||
      !it.retrieve_integer(src_2_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ImxEgl#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  unsigned api_bit;

  // - process requested egl api -
  switch (api_type)
  {
    case EGL_OPENGL_ES_API:
      api_bit = EGL_OPENGL_ES2_BIT;
      break;
    case EGL_OPENVG_API:
      api_bit = EGL_OPENVG_BIT;
      break;

    // - ERROR -
    default:

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_UNRECOGNIZED_API,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(api_type);

      return false;
  }

  // - attributes of requested configuration -
  EGLint config_attrs[] =
  {
    EGL_RED_SIZE,        5,
    EGL_GREEN_SIZE,      6,
    EGL_BLUE_SIZE,       5,
    EGL_SURFACE_TYPE,    EGL_WINDOW_BIT,
    EGL_RENDERABLE_TYPE, api_bit,
    EGL_CONFORMANT,      api_bit,
    EGL_NONE
  };

  // - create native display -
#if defined(EGL_API_FB)
  EGLNativeDisplayType native_display = fbGetDisplayByIndex(0);
#else
  EGLNativeDisplayType native_display = XOpenDisplay(NULL);
#endif

  // - ERROR -
  if (native_display == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve display -
  EGLDisplay display = eglGetDisplay(native_display);

  // - ERROR -
  if (!eglInitialize(display,NULL,NULL))
  {
    eglTerminate(display);

#if defined(EGL_API_FB)
    fbDestroyDisplay(native_display);
#else
    XCloseDisplay(native_display);
#endif

    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - bind egl api -
  eglBindAPI(api_type);

  // - choose desired configuration -
  EGLint numconfigs;
  EGLConfig config;

  // - ERROR -
  if (!eglChooseConfig(display,config_attrs,&config,1,&numconfigs) || numconfigs != 1)
  {
    eglTerminate(display);

#if defined(EGL_API_FB)
    fbDestroyDisplay(native_display);
#else
    XCloseDisplay(native_display);
#endif

    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create native window -
  EGLNativeWindowType native_window = (EGLNativeWindowType)0;

#if defined(EGL_API_FB)
  const char *vendor = eglQueryString(display,EGL_VENDOR);
  cassert(strcmp(vendor,"Vivante Corporation") == 0);
  native_window = fbCreateWindow(native_display,0,0,width,height);
#else
  int screen = DefaultScreen(native_display);
  Window root_window = RootWindow(native_display,screen);
  Window window = XCreateSimpleWindow(native_display,root_window,0,0,width,height,0,0,BlackPixel(native_display,screen));
  XMapWindow(native_display,window);
  native_window = window;
#endif

  // - ERROR -
  if (native_window == 0)
  {
    eglTerminate(display);

#if defined(EGL_API_FB)
    fbDestroyDisplay(native_display);
#else
    XCloseDisplay(native_display);
#endif

    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create window surface -
  EGLSurface surface = eglCreateWindowSurface(display,config,native_window,NULL);

  // - ERROR -
  if (surface == EGL_NO_SURFACE)
  {
    eglTerminate(display);

#if defined(EGL_API_FB)
    fbDestroyWindow(native_window);
    fbDestroyDisplay(native_display);
#else
    XDestroyWindow(native_display,native_window);
    XCloseDisplay(native_display);
#endif

    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create context -
  EGLContext context = EGL_NO_CONTEXT;

  switch (api_type)
  {
    case EGL_OPENGL_ES_API:
      {
        EGLint context_attrs[] = { EGL_CONTEXT_CLIENT_VERSION,2,EGL_NONE };
        context = eglCreateContext(display,config,EGL_NO_CONTEXT,context_attrs);
      }
      break;
    case EGL_OPENVG_API:
      context = eglCreateContext(display,config,EGL_NO_CONTEXT,NULL);
      break;
  }

  // - ERROR -
  if (context == EGL_NO_CONTEXT)
  {
    eglDestroySurface(display,surface);
    eglTerminate(display);

#if defined(EGL_API_FB)
    fbDestroyWindow(native_window);
    fbDestroyDisplay(native_display);
#else
    XDestroyWindow(native_display,native_window);
    XCloseDisplay(native_display);
#endif

    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create imx egl object -
  imx_egl_s *ie_ptr = (imx_egl_s *)cmalloc(sizeof(imx_egl_s));
  ie_ptr->init();

  // - set imx egl properties -
  ie_ptr->width = width;
  ie_ptr->height = height;

  ie_ptr->display = display;
  ie_ptr->surface = surface;
  ie_ptr->context = context;

  ie_ptr->native_display = native_display;
  ie_ptr->native_window = native_window;

  // - set imx egl destination location -
  dst_location->v_data_ptr = (imx_egl_s *)ie_ptr;

  return true;
}/*}}}*/

bool bic_imx_egl_method_set_as_global_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  global_egl_mutex.lock();

  // - ERROR -
  if (global_egl_ptr != NULL)
  {
    global_egl_mutex.unlock();

    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_SET_AS_GLOBAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set global egl pointer -
  global_egl_ptr = (imx_egl_s *)dst_location->v_data_ptr;

  global_egl_mutex.unlock();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_egl_method_gen_textures_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int count;

  if (!it.retrieve_integer(src_0_location,count))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("gen_textures#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  imx_egl_s *ie_ptr = (imx_egl_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (count <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_WRONG_COUNT_OF_TEXTURES_REQUESTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - index of first texture -
  long long int result = ie_ptr->texture_locs.used;

  // - generate requested textures -
  while (count-- > 0)
  {
    // - create gl texture object -
    gl_texture_s *glt_ptr = (gl_texture_s *)cmalloc(sizeof(gl_texture_s));
    glt_ptr->init();

    glGenTextures(1,&glt_ptr->index);
    glBindTexture(GL_TEXTURE_2D,glt_ptr->index);

    // - set default texture parameters -
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glt_ptr->format = GL_RGB;
    glt_ptr->pixel_size = 3;
    glt_ptr->width = 0;
    glt_ptr->height = 0;

    // - create texture location -
    BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_gl_texture,glt_ptr);

    // - store texture pointer -
    ie_ptr->texture_ptrs.push(glt_ptr);

    // - store texture location -
    ie_ptr->texture_locs.push(new_location);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_imx_egl_method_get_texture_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_texture#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  imx_egl_s *ie_ptr = (imx_egl_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (index < 0 || index >= ie_ptr->texture_locs.used)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_WRONG_TEXTURE_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  location_s *tex_location = (location_s *)ie_ptr->texture_locs[index];
  tex_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(tex_location);

  return true;
}/*}}}*/

bool bic_imx_egl_method_global_lock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - reference to interpreter terminate -
  atomic_s &terminate = ((interpreter_s *)it.interpreter_ptr)->terminate;

  // - nanosleep time structure -
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = 1000000L;

  do {

    // - if interpreter terminates -
    if (terminate.value())
    {
      break;
    }

    // - global egl mutex lock -
    if (global_egl_mutex.try_lock() == c_error_OK)
    {
      break;
    }

    // - sleep some time -
    nanosleep(&ts,NULL);

  } while(1);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_egl_method_global_unlock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - global egl mutex unlock -
  unsigned ret = global_egl_mutex.unlock();

  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_imx_egl_method_global_terminate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - set global egl terminate -
  global_egl_terminate.atomic_set(1);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_egl_method_MakeCurrent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_egl_s *ie_ptr = (imx_egl_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!eglMakeCurrent(ie_ptr->display,ie_ptr->surface,ie_ptr->surface,ie_ptr->context))
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_MAKE_CURRENT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_egl_method_SwapBuffers_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_egl_s *ie_ptr = (imx_egl_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!eglSwapBuffers(ie_ptr->display,ie_ptr->surface))
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMX_EGL_SWAP_BUFFERS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_egl_method_GetError_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  long long int result = eglGetError();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_imx_egl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ImxEgl"),"ImxEgl");
  );

  return true;
}/*}}}*/

bool bic_imx_egl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ImxEgl");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

#if defined(IPUROT_LINUX)
// - class IMX_FB -
built_in_class_s imx_fb_class =
{/*{{{*/
  "ImxFb",
  c_modifier_public | c_modifier_final,
  8, imx_fb_methods,
  0, imx_fb_variables,
  bic_imx_fb_consts,
  bic_imx_fb_init,
  bic_imx_fb_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s imx_fb_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_imx_fb_operator_binary_equal
  },
  {
    "ImxFb#1",
    c_modifier_public | c_modifier_final,
    bic_imx_fb_method_ImxFb_1
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_imx_fb_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_imx_fb_method_height_0
  },
  {
    "bits_per_pixel#0",
    c_modifier_public | c_modifier_final,
    bic_imx_fb_method_bits_per_pixel_0
  },
  {
    "wait_on_vsync#0",
    c_modifier_public | c_modifier_final,
    bic_imx_fb_method_wait_on_vsync_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_fb_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_fb_method_print_0
  },
};/*}}}*/

built_in_variable_s imx_fb_variables[] =
{/*{{{*/
};/*}}}*/

void bic_imx_fb_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_imx_fb_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (imx_fb_s *)NULL;
}/*}}}*/

void bic_imx_fb_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  imx_fb_s *if_ptr = (imx_fb_s *)location_ptr->v_data_ptr;

  if (if_ptr != NULL)
  {
    if_ptr->clear(it);
    cfree(if_ptr);
  }
}/*}}}*/

bool bic_imx_fb_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_imx_fb_method_ImxFb_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ImxFb#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - open framebuffer file descriptor -
  int fd = open(string_ptr->data,O_RDWR,0);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMX_FB_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create imx fb object -
  imx_fb_s *if_ptr = (imx_fb_s *)cmalloc(sizeof(imx_fb_s));
  if_ptr->init();

  // - set file descriptor -
  if_ptr->fd = fd;

  // - ERROR -
  if (!read_framebuffer_properties(if_ptr->fd,&if_ptr->fb_props))
  {
    cfree(if_ptr);
    close(fd);

    exception_s::throw_exception(it,module.error_base + c_error_IMX_FB_CANNOT_READ_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set imx fb destination location -
  dst_location->v_data_ptr = (imx_fb_s *)if_ptr;

  return true;
}/*}}}*/

bool bic_imx_fb_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_fb_s *if_ptr = (imx_fb_s *)dst_location->v_data_ptr;

  long long int result = if_ptr->fb_props.xres;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_imx_fb_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_fb_s *if_ptr = (imx_fb_s *)dst_location->v_data_ptr;

  long long int result = if_ptr->fb_props.yres;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_imx_fb_method_bits_per_pixel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_fb_s *if_ptr = (imx_fb_s *)dst_location->v_data_ptr;

  long long int result = if_ptr->fb_props.bits_per_pixel;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_imx_fb_method_wait_on_vsync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_fb_s *if_ptr = (imx_fb_s *)dst_location->v_data_ptr;

  // - wait for framebuffer vertical sync -
  ioctl(if_ptr->fd,MXCFB_WAIT_FOR_VSYNC,0);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_fb_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ImxFb"),"ImxFb");
  );

  return true;
}/*}}}*/

bool bic_imx_fb_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ImxFb");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/
#endif

#if defined(IPUROT_LINUX)
// - class IMX_IPU -
built_in_class_s imx_ipu_class =
{/*{{{*/
  "ImxIpu",
  c_modifier_public | c_modifier_final,
  6, imx_ipu_methods,
  0, imx_ipu_variables,
  bic_imx_ipu_consts,
  bic_imx_ipu_init,
  bic_imx_ipu_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s imx_ipu_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_imx_ipu_operator_binary_equal
  },
  {
    "ImxIpu#1",
    c_modifier_public | c_modifier_final,
    bic_imx_ipu_method_ImxIpu_1
  },
  {
    "prepare_rotation#0",
    c_modifier_public | c_modifier_final,
    bic_imx_ipu_method_prepare_rotation_0
  },
  {
    "execute#0",
    c_modifier_public | c_modifier_final,
    bic_imx_ipu_method_execute_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_ipu_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_imx_ipu_method_print_0
  },
};/*}}}*/

built_in_variable_s imx_ipu_variables[] =
{/*{{{*/
};/*}}}*/

void bic_imx_ipu_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_imx_ipu_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (imx_ipu_s *)NULL;
}/*}}}*/

void bic_imx_ipu_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  imx_ipu_s *ii_ptr = (imx_ipu_s *)location_ptr->v_data_ptr;

  if (ii_ptr != NULL)
  {
    ii_ptr->clear(it);
    cfree(ii_ptr);
  }
}/*}}}*/

bool bic_imx_ipu_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_imx_ipu_method_ImxIpu_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_imx_fb)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ImxIpu#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - open imx ipu file descriptor -
  int fd = open("/dev/mxc_ipu",O_RDWR,0);

  // - ERROR -
  if (fd == -1)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen("/dev/mxc_ipu"),"/dev/mxc_ipu");

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);

    exception_s::throw_exception(it,module.error_base + c_error_IMX_IPU_FILE_OPEN_ERROR,operands[c_source_pos_idx],new_location);
    return false;
  }

  // - enable ipu operations on framebuffer -
  imx_fb_s *if_ptr = (imx_fb_s *)src_0_location->v_data_ptr;
  ioctl(if_ptr->fd,MXCFB_ROTATION_ENABLE,1);

  // - create imx ipu object -
  imx_ipu_s *ii_ptr = (imx_ipu_s *)cmalloc(sizeof(imx_ipu_s));
  ii_ptr->init();

  // - set file descriptor -
  ii_ptr->fd = fd;

  // - set framebuffer location -
  src_0_location->v_reference_cnt.atomic_inc();
  ii_ptr->fb_location = src_0_location;

  // - set imx ipu destination location -
  dst_location->v_data_ptr = (imx_ipu_s *)ii_ptr;

  return true;
}/*}}}*/

bool bic_imx_ipu_method_prepare_rotation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_ipu_s *ii_ptr = (imx_ipu_s *)dst_location->v_data_ptr;
  imx_fb_s *if_ptr = (imx_fb_s *)ii_ptr->fb_location->v_data_ptr;

  // - reference to fb properties -
  framebuffer_props_s &props = if_ptr->fb_props;

  // - reference to task structures -
  struct ipu_task &task_0 = ii_ptr->task_0;
  struct ipu_task &task_1 = ii_ptr->task_1;

  // - clear task structure -
  memset(&task_0,0,sizeof(struct ipu_task));
  memset(&task_1,0,sizeof(struct ipu_task));

  task_0.priority = 1;
  task_0.task_id = 0;
  task_0.timeout = 1000;

  unsigned t0_crop_width;
  unsigned t0_out_crop_pos_x;

  if (props.xres <= c_max_rotate_size)
  {
    t0_crop_width = props.xres;
    t0_out_crop_pos_x = 0;
  }
  else
  {
    t0_crop_width = c_max_rotate_size;
    t0_out_crop_pos_x = props.xres - c_max_rotate_size;
  }

  task_0.input.width = props.pixels_per_stride;
  task_0.input.height = props.yres;
  task_0.input.format =  v4l2_fourcc('R','G','B','P');
  task_0.input.crop.pos.x = 0;
  task_0.input.crop.pos.y = 0;
  task_0.input.crop.w = t0_crop_width;
  task_0.input.crop.h = props.yres;
  task_0.input.deinterlace.enable = 0;
  task_0.input.deinterlace.motion = 0;
  task_0.input.paddr = props.smem_start;

  task_0.output.width = props.pixels_per_stride;
  task_0.output.height = props.yres;
  task_0.output.format = v4l2_fourcc('R','G','B','P');
  task_0.output.rotate = 3;
  task_0.output.crop.pos.x = t0_out_crop_pos_x;
  task_0.output.crop.pos.y = 0;
  task_0.output.crop.w = t0_crop_width;
  task_0.output.crop.h = props.yres;
  task_0.output.paddr = props.rot_smem_start;

  // - if second task is needed -
  if (props.xres > c_max_rotate_size)
  {
    task_1.priority = 1;
    task_1.task_id = 1;
    task_1.timeout = 1000;

    task_1.input.width = props.pixels_per_stride;
    task_1.input.height = props.yres;
    task_1.input.format =  v4l2_fourcc('R','G','B','P');
    task_1.input.crop.pos.x = c_max_rotate_size;
    task_1.input.crop.pos.y = 0;
    task_1.input.crop.w = props.xres - c_max_rotate_size;
    task_1.input.crop.h = props.yres;
    task_1.input.deinterlace.enable = 0;
    task_1.input.deinterlace.motion = 0;
    task_1.input.paddr = props.smem_start;

    task_1.output.width = props.pixels_per_stride;
    task_1.output.height = props.yres;
    task_1.output.format = v4l2_fourcc('R','G','B','P');
    task_1.output.rotate = 3;
    task_1.output.crop.pos.x = 0;
    task_1.output.crop.pos.y = 0;
    task_1.output.crop.w = props.xres - c_max_rotate_size;
    task_1.output.crop.h = props.yres;
    task_1.output.paddr = props.rot_smem_start;
  }

  // - set prepared flag -
  ii_ptr->prepared = true;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_ipu_method_execute_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  imx_ipu_s *ii_ptr = (imx_ipu_s *)dst_location->v_data_ptr;
  imx_fb_s *if_ptr = (imx_fb_s *)ii_ptr->fb_location->v_data_ptr;

  // - ERROR -
  if (!ii_ptr->prepared)
  {
    exception_s::throw_exception(it,module.error_base + c_error_IMX_IPU_NO_TASK_PREPARED_FOR_EXECUTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - reference to task structures -
  struct ipu_task &task_0 = ii_ptr->task_0;
  struct ipu_task &task_1 = ii_ptr->task_1;

  // - reference to fb properties -
  framebuffer_props_s &props = if_ptr->fb_props;

  // - reference to buffer index -
  unsigned &buffer_idx = ii_ptr->buffer_idx;

  if (props.second_buffer)
  {
    // - set back buffer as target -
    task_0.output.paddr = task_1.output.paddr =
      props.rot_smem_start + buffer_idx*props.buffer_size;
  }

  // - process frame -
  ioctl(ii_ptr->fd,IPU_QUEUE_TASK,&task_0);

  if (props.xres > c_max_rotate_size)
  {
    ioctl(ii_ptr->fd,IPU_QUEUE_TASK,&task_1);
  }

  if (props.second_buffer)
  {
    // - swap display buffers -
    ioctl(if_ptr->fd,MXCFB_ROTATION_SWAP,buffer_idx);
    buffer_idx = !buffer_idx;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_imx_ipu_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ImxIpu"),"ImxIpu");
  );

  return true;
}/*}}}*/

bool bic_imx_ipu_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ImxIpu");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/
#endif

