
@begin
include "glut_module.h"
@end

// - GLUT indexes of built in classes -
unsigned c_bi_class_glut = c_idx_not_exist;

// - GLUT module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  glut_classes,         // Classes

  0,                    // Error base index
  6,                    // Error count
  glut_error_strings,   // Error strings

  glut_initialize,      // Initialize function
  glut_print_exception, // Print exceptions function
};/*}}}*/

// - GLUT classes -
built_in_class_s *glut_classes[] =
{/*{{{*/
  &glut_class,
};/*}}}*/

// - GLUT error strings -
const char *glut_error_strings[] =
{/*{{{*/
  "error_GLUT_OBJECT_ALREADY_CREATED",
  "error_GLUT_WRONG_THREAD_CONTEXT",
  "error_GLUT_WRONG_CALLBACK_DELEGATE",
  "error_GLUT_WINDOW_ALREADY_CREATED",
  "error_GLUT_WINDOW_NOT_CREATED_YET",
  "error_GLUT_ALREADY_IN_MAIN_LOOP",
};/*}}}*/

// - GLUT initialize -
bool glut_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize glut class identifier -
  c_bi_class_glut = class_base_idx++;

  return true;
}/*}}}*/

// - GLUT print exception -
bool glut_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GLUT_OBJECT_ALREADY_CREATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGLUT object was already created\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GLUT_WRONG_THREAD_CONTEXT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong thread <-> OpenGL rendering context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GLUT_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for this GLUT callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GLUT_WINDOW_ALREADY_CREATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGLUT window is already created\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GLUT_WINDOW_NOT_CREATED_YET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNo GLUT window was created yet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GLUT_ALREADY_IN_MAIN_LOOP:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGLUT main loop is already running\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GLUT -
built_in_class_s glut_class =
{/*{{{*/
  "Glut",
  c_modifier_public | c_modifier_final,
  25
#ifndef EMSCRIPTEN
  + 2
#endif
  , glut_methods,
  162, glut_variables,
  bic_glut_consts,
  bic_glut_init,
  bic_glut_clear,
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

built_in_method_s glut_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_glut_operator_binary_equal
  },
  {
    "Glut#0",
    c_modifier_public | c_modifier_final,
    bic_glut_method_Glut_0
  },
  {
    "InitWindowSize#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_InitWindowSize_2
  },
  {
    "InitWindowPosition#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_InitWindowPosition_2
  },
  {
    "InitDisplayMode#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_InitDisplayMode_1
  },
  {
    "CreateWindow#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_CreateWindow_1
  },
  {
    "ReshapeWindow#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_ReshapeWindow_2
  },
  {
    "DisplayFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_DisplayFunc_1
  },
  {
    "ReshapeFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_ReshapeFunc_1
  },
  {
    "KeyboardFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_KeyboardFunc_1
  },
  {
    "SpecialFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_SpecialFunc_1
  },
  {
    "MouseFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_MouseFunc_1
  },
  {
    "MotionFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_MotionFunc_1
  },
  {
    "PassiveMotionFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_PassiveMotionFunc_1
  },
  {
    "VisibilityFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_VisibilityFunc_1
  },
  {
    "EntryFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_EntryFunc_1
  },
  {
    "IdleFunc#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_IdleFunc_1
  },
  {
    "TimerFunc#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_TimerFunc_3
  },
  {
    "GetModifiers#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_GetModifiers_0
  },
  {
    "Get#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_Get_1
  },
  {
    "PostRedisplay#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_PostRedisplay_0
  },
  {
    "SwapBuffers#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_SwapBuffers_0
  },
  {
    "MainLoop#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_MainLoop_0
  },
#ifndef EMSCRIPTEN
  {
    "MainLoopEvent#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_MainLoopEvent_0
  },
  {
    "LeaveMainLoop#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_LeaveMainLoop_0
  },
#endif
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glut_method_print_0
  },
};/*}}}*/

built_in_variable_s glut_variables[] =
{/*{{{*/
  { "GLUT_KEY_F1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F9", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F11", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_F12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_UP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_DOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_PAGE_UP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_PAGE_DOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_HOME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_END", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_INSERT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_LEFT_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_MIDDLE_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_RIGHT_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_DOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_UP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ENTERED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_SINGLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_DOUBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ACCUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_STENCIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_STEREO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_LUMINANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_MENU_NOT_IN_USE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_MENU_IN_USE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NOT_VISIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VISIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HIDDEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_FULLY_RETAINED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_PARTIALLY_RETAINED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_FULLY_COVERED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_STENCIL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_DEPTH_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_ACCUM_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_ACCUM_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_ACCUM_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_ACCUM_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_DOUBLEBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_PARENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_NUM_CHILDREN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_COLORMAP_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_NUM_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_STEREO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_CURSOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_SCREEN_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_SCREEN_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_SCREEN_WIDTH_MM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_SCREEN_HEIGHT_MM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_MENU_NUM_ITEMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_DISPLAY_MODE_POSSIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_INIT_WINDOW_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_INIT_WINDOW_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_INIT_WINDOW_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_INIT_WINDOW_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_INIT_DISPLAY_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ELAPSED_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_WINDOW_FORMAT_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_KEYBOARD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_MOUSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_SPACEBALL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_DIAL_AND_BUTTON_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_TABLET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NUM_MOUSE_BUTTONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NUM_SPACEBALL_BUTTONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NUM_BUTTON_BOX_BUTTONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NUM_DIALS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NUM_TABLET_BUTTONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_DEVICE_IGNORE_KEY_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_DEVICE_KEY_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_JOYSTICK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_OWNS_JOYSTICK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_BUTTONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_AXES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_POLL_RATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_OVERLAY_POSSIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_LAYER_IN_USE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_HAS_OVERLAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_TRANSPARENT_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NORMAL_DAMAGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_OVERLAY_DAMAGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_POSSIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_IN_USE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_X_DELTA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_Y_DELTA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_WIDTH_DELTA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_HEIGHT_DELTA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_VIDEO_RESIZE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_OVERLAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ACTIVE_SHIFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ACTIVE_CTRL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_ACTIVE_ALT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_RIGHT_ARROW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_LEFT_ARROW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_INFO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_DESTROY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_HELP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_CYCLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_SPRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_WAIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_TEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_CROSSHAIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_UP_DOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_LEFT_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_TOP_SIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_BOTTOM_SIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_LEFT_SIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_RIGHT_SIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_TOP_LEFT_CORNER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_TOP_RIGHT_CORNER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_BOTTOM_RIGHT_CORNER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_BOTTOM_LEFT_CORNER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_INHERIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_CURSOR_FULL_CROSSHAIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_RED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GREEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_BLUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_REPEAT_OFF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_REPEAT_ON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_KEY_REPEAT_DEFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_BUTTON_A", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_BUTTON_B", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_BUTTON_C", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_JOYSTICK_BUTTON_D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_ACTIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_POSSIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_PIXEL_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_REFRESH_RATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLUT_GAME_MODE_DISPLAY_CHANGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_GLUT_CONTEXT_CHECK() \
{/*{{{*/\
\
  /* - ERROR - */\
  if (glut_s::it_ptr != &it)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_WRONG_THREAD_CONTEXT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

#define BIC_GLUT_WINDOW_CHECK() \
{/*{{{*/\
\
  /* - ERROR - */\
  if (glut_s::window == 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_WINDOW_NOT_CREATED_YET,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

#define BIC_GLUT_DELEGATE_CHECK(LOCATION,PARAM_CNT) \
{/*{{{*/\
\
  /* - retrieve delegate pointer - */\
  delegate_s *delegate_ptr = (delegate_s *)(LOCATION)->v_data_ptr;\
\
  /* - ERROR - */\
  if (delegate_ptr->param_cnt != PARAM_CNT)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

#define BIC_GLUT_DELEGATE(NAME,GLUT_NAME,FUN_PTR_NAME,DLG_PTR_NAME,PARAM_CNT,ADDITIONAL_CHECK) \
{/*{{{*/\
@begin ucl_params
<
delegate:c_bi_class_delegate
>
class c_bi_class_glut
method NAME
static_method
macro
; @end\
\
  BIC_GLUT_CONTEXT_CHECK();\
  ADDITIONAL_CHECK;\
  BIC_GLUT_DELEGATE_CHECK(src_0_location,PARAM_CNT);\
\
  GLUT_NAME(glut_s::FUN_PTR_NAME);\
\
  /* - release previous delegate - */\
  if (glut_s::glut_ptr->DLG_PTR_NAME != nullptr)\
  {\
    it.release_location_ptr(glut_s::glut_ptr->DLG_PTR_NAME);\
  }\
\
  /* - register new delegate - */\
  src_0_location->v_reference_cnt.atomic_inc();\
  glut_s::glut_ptr->DLG_PTR_NAME = src_0_location;\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_glut_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert glut basic constants -
  {
    const_locations.push_blanks(162);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 162);

#define CREATE_GLUT_BASIC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F1);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F2);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F3);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F4);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F5);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F6);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F7);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F8);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F9);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F10);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F11);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_F12);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_LEFT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_UP);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_RIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_DOWN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_PAGE_UP);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_PAGE_DOWN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_HOME);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_END);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_INSERT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_LEFT_BUTTON);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_MIDDLE_BUTTON);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_RIGHT_BUTTON);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_DOWN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_UP);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_LEFT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ENTERED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_RGB);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_RGBA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_INDEX);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_SINGLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_DOUBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ACCUM);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ALPHA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_DEPTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_STENCIL);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_MULTISAMPLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_STEREO);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_LUMINANCE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_MENU_NOT_IN_USE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_MENU_IN_USE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NOT_VISIBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VISIBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HIDDEN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_FULLY_RETAINED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_PARTIALLY_RETAINED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_FULLY_COVERED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_X);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_Y);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_WIDTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_HEIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_BUFFER_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_STENCIL_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_DEPTH_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_RED_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_GREEN_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_BLUE_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_ALPHA_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_ACCUM_RED_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_ACCUM_GREEN_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_ACCUM_BLUE_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_ACCUM_ALPHA_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_DOUBLEBUFFER);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_RGBA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_PARENT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_NUM_CHILDREN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_COLORMAP_SIZE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_NUM_SAMPLES);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_STEREO);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_CURSOR);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_SCREEN_WIDTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_SCREEN_HEIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_SCREEN_WIDTH_MM);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_SCREEN_HEIGHT_MM);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_MENU_NUM_ITEMS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_DISPLAY_MODE_POSSIBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_INIT_WINDOW_X);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_INIT_WINDOW_Y);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_INIT_WINDOW_WIDTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_INIT_WINDOW_HEIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_INIT_DISPLAY_MODE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ELAPSED_TIME);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_WINDOW_FORMAT_ID);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_KEYBOARD);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_MOUSE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_SPACEBALL);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_DIAL_AND_BUTTON_BOX);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_TABLET);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NUM_MOUSE_BUTTONS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NUM_SPACEBALL_BUTTONS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NUM_BUTTON_BOX_BUTTONS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NUM_DIALS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NUM_TABLET_BUTTONS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_DEVICE_IGNORE_KEY_REPEAT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_DEVICE_KEY_REPEAT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_JOYSTICK);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_OWNS_JOYSTICK);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_BUTTONS);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_AXES);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_POLL_RATE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_OVERLAY_POSSIBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_LAYER_IN_USE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_HAS_OVERLAY);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_TRANSPARENT_INDEX);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NORMAL_DAMAGED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_OVERLAY_DAMAGED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_POSSIBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_IN_USE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_X_DELTA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_Y_DELTA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_WIDTH_DELTA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_HEIGHT_DELTA);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_X);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_Y);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_WIDTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_VIDEO_RESIZE_HEIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_NORMAL);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_OVERLAY);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ACTIVE_SHIFT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ACTIVE_CTRL);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_ACTIVE_ALT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_RIGHT_ARROW);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_LEFT_ARROW);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_INFO);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_DESTROY);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_HELP);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_CYCLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_SPRAY);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_WAIT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_TEXT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_CROSSHAIR);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_UP_DOWN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_LEFT_RIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_TOP_SIDE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_BOTTOM_SIDE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_LEFT_SIDE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_RIGHT_SIDE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_TOP_LEFT_CORNER);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_TOP_RIGHT_CORNER);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_BOTTOM_RIGHT_CORNER);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_BOTTOM_LEFT_CORNER);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_INHERIT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_NONE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_CURSOR_FULL_CROSSHAIR);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_RED);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GREEN);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_BLUE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_REPEAT_OFF);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_REPEAT_ON);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_KEY_REPEAT_DEFAULT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_BUTTON_A);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_BUTTON_B);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_BUTTON_C);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_JOYSTICK_BUTTON_D);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_ACTIVE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_POSSIBLE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_WIDTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_HEIGHT);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_PIXEL_DEPTH);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_REFRESH_RATE);
    CREATE_GLUT_BASIC_BIC_STATIC(GLUT_GAME_MODE_DISPLAY_CHANGED);
  }
}/*}}}*/

void bic_glut_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (glut_s *)nullptr;
}/*}}}*/

void bic_glut_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glut_s *glut_ptr = (glut_s *)location_ptr->v_data_ptr;

  // - if glut object exists -
  if (glut_ptr != nullptr)
  {
    glut_ptr->clear(it);
    cfree(glut_ptr);
  }
}/*}}}*/

bool bic_glut_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_glut_method_Glut_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

#ifndef EMSCRIPTEN
  // - ERROR -
  if (glut_s::glut_ptr != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_OBJECT_ALREADY_CREATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }
#endif

  // - dummy init arguments -
  int argc = 0;
  char *argv = nullptr;

  glutInit(&argc,&argv);

#ifndef EMSCRIPTEN
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
#endif

  // - create new glut object -
  glut_s *glut_ptr = (glut_s *)cmalloc(sizeof(glut_s));
  glut_ptr->init();
  glut_s::init_static();

  // - set glut pointer -
  glut_s::glut_ptr = glut_ptr;

  // - set interpreter thread pointer -
  glut_s::it_ptr = &it;

  dst_location->v_data_ptr = (glut_s *)glut_ptr;

  return true;
}/*}}}*/

bool bic_glut_method_InitWindowSize_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
class c_bi_class_glut
method InitWindowSize
static_method
; @end

  BIC_GLUT_CONTEXT_CHECK();

  glutInitWindowSize(width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_InitWindowPosition_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
pos_x:retrieve_integer
pos_y:retrieve_integer
>
class c_bi_class_glut
method InitWindowPosition
static_method
; @end

  BIC_GLUT_CONTEXT_CHECK();

  glutInitWindowPosition(pos_x,pos_y);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_InitDisplayMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
mode:retrieve_integer
>
class c_bi_class_glut
method InitDisplayMode
static_method
; @end

  BIC_GLUT_CONTEXT_CHECK();

  glutInitDisplayMode(mode);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_CreateWindow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
class c_bi_class_glut
method CreateWindow
static_method
; @end

  BIC_GLUT_CONTEXT_CHECK();

  // - ERROR -
  if (glut_s::window != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_WINDOW_ALREADY_CREATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  glut_s::window = glutCreateWindow(string_ptr->data);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_ReshapeWindow_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
class c_bi_class_glut
method ReshapeWindow
static_method
; @end

  BIC_GLUT_WINDOW_CHECK();

  glutReshapeWindow(width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_DisplayFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("DisplayFunc#1",glutDisplayFunc,display_func,display_dlg,0,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_ReshapeFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("ReshapeFunc#1",glutReshapeFunc,reshape_func,reshape_dlg,2,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_KeyboardFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("KeyboardFunc#1",glutKeyboardFunc,keyboard_func,keyboard_dlg,3,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_SpecialFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("SpecialFunc#1",glutSpecialFunc,special_func,special_dlg,3,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_MouseFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("MouseFunc#1",glutMouseFunc,mouse_func,mouse_dlg,4,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_MotionFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("MotionFunc#1",glutMotionFunc,motion_func,motion_dlg,2,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_PassiveMotionFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("PassiveMotionFunc#1",glutPassiveMotionFunc,passive_motion_func,passive_motion_dlg,2,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_VisibilityFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("VisibilityFunc#1",glutVisibilityFunc,visibility_func,visibility_dlg,1,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_EntryFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("EntryFunc#1",glutEntryFunc,entry_func,entry_dlg,1,
    BIC_GLUT_WINDOW_CHECK();
  );
}/*}}}*/

bool bic_glut_method_IdleFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_DELEGATE("IdleFunc#1",glutIdleFunc,idle_func,idle_dlg,0,);
}/*}}}*/

bool bic_glut_method_TimerFunc_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
millisec:retrieve_integer
delegate:c_bi_class_delegate
value:retrieve_integer
>
class c_bi_class_glut
method TimerFunc
static_method
; @end

  BIC_GLUT_CONTEXT_CHECK();
  BIC_GLUT_DELEGATE_CHECK(src_1_location,1);

  glutTimerFunc(millisec,glut_s::timer_func,value);

  // - if new delegate differs from actual delegate -
  if (src_1_location != glut_s::glut_ptr->timer_dlg)
  {
    // - release previous delegate -
    if (glut_s::glut_ptr->timer_dlg != nullptr)
    {
      it.release_location_ptr(glut_s::glut_ptr->timer_dlg);
    }

    // - register new delegate -
    src_1_location->v_reference_cnt.atomic_inc();
    glut_s::glut_ptr->timer_dlg = src_1_location;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_GetModifiers_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = glutGetModifiers();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_glut_method_Get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
state:retrieve_integer
>
class c_bi_class_glut
method Get
static_method
; @end

  BIC_GLUT_CONTEXT_CHECK();

  // - retrieve glut state variable -
  long long int result = glutGet(state);

  if (result < 0)
  {
    BIC_SET_RESULT_BLANK();
  }
  else
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }

  return true;
}/*}}}*/

bool bic_glut_method_PostRedisplay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_CONTEXT_CHECK();
  BIC_GLUT_WINDOW_CHECK();

  glutPostRedisplay();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_SwapBuffers_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_CONTEXT_CHECK();
  BIC_GLUT_WINDOW_CHECK();

  glutSwapBuffers();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_MainLoop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_CONTEXT_CHECK();
  BIC_GLUT_WINDOW_CHECK();

  // - ERROR -
  if (glut_s::main_loop)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_ALREADY_IN_MAIN_LOOP,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  glut_s::main_loop = true;
  glut_s::main_source_pos = operands[c_source_pos_idx];
  glut_s::main_ret_code = c_run_return_code_OK;

  // - start glut main loop -
  glutMainLoop();

  unsigned main_ret_code = glut_s::main_ret_code;

  glut_s::main_loop = false;
  glut_s::main_source_pos = 0;
  glut_s::main_ret_code = c_run_return_code_OK;

  // - if exception occurred in one of events -
  if (main_ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

#ifndef EMSCRIPTEN
bool bic_glut_method_MainLoopEvent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_CONTEXT_CHECK();
  BIC_GLUT_WINDOW_CHECK();

  // - ERROR -
  if (glut_s::main_loop)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GLUT_ALREADY_IN_MAIN_LOOP,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  glut_s::main_loop = true;
  glut_s::main_source_pos = operands[c_source_pos_idx];
  glut_s::main_ret_code = c_run_return_code_OK;

  // - glut main loop event -
  glutMainLoopEvent();

  unsigned main_ret_code = glut_s::main_ret_code;

  glut_s::main_loop = false;
  glut_s::main_source_pos = 0;
  glut_s::main_ret_code = c_run_return_code_OK;

  // - if exception occurred in one of events -
  if (main_ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_glut_method_LeaveMainLoop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GLUT_CONTEXT_CHECK();

  glutLeaveMainLoop();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/
#endif

bool bic_glut_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Glut"),"Glut");
  );

  return true;
}/*}}}*/

bool bic_glut_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Glut");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

