
@begin
include "gtk_module.h"
@end

// - GTK indexes of built in classes -
unsigned c_bi_class_gtk = c_idx_not_exist;
unsigned c_bi_class_gtk_g_object = c_idx_not_exist;
unsigned c_bi_class_gtk_widget = c_idx_not_exist;
unsigned c_bi_class_gtk_container = c_idx_not_exist;
unsigned c_bi_class_gtk_grid = c_idx_not_exist;
unsigned c_bi_class_gtk_window = c_idx_not_exist;
unsigned c_bi_class_gtk_handler = c_idx_not_exist;

// - GTK module -
built_in_module_s module =
{/*{{{*/
  7,                   // Class count
  gtk_classes,         // Classes

  0,                   // Error base index
  14,                  // Error count
  gtk_error_strings,   // Error strings

  gtk_initialize,      // Initialize function
  gtk_print_exception, // Print exceptions function
};/*}}}*/

// - GTK classes -
built_in_class_s *gtk_classes[] =
{/*{{{*/
  &gtk_class,
  &gtk_g_object_class,
  &gtk_widget_class,
  &gtk_container_class,
  &gtk_grid_class,
  &gtk_window_class,
  &gtk_handler_class,
};/*}}}*/

// - GTK error strings -
const char *gtk_error_strings[] =
{/*{{{*/
  "error_GTK_MAIN_LOOP_STATE_ERROR",
  "error_GTK_G_OBJECT_INCOMPATIBLE_TYPE",
  "error_GTK_G_OBJECT_UNKNOWN_PROPERTY",
  "error_GTK_G_OBJECT_WRONG_PROPERTIES_ARRAY_SIZE",
  "error_GTK_G_OBJECT_PROPERTY_NAME_EXPECTED_STRING",
  "error_GTK_G_OBJECT_PROPERTY_INVALID_VALUE_TYPE",
  "error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR",
  "error_GTK_G_OBJECT_G_VALUE_VALUE_ERROR",
  "error_GTK_G_OBJECT_UNKNOWN_SIGNAL",
  "error_GTK_G_OBJECT_SIGNAL_WRONG_CALLBACK_DELEGATE",
  "error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_COUNT",
  "error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_TYPE",
  "error_GTK_G_OBJECT_CREATE_ERROR",
  "error_GTK_HANDLER_ALREADY_DISCONNECTED",
};/*}}}*/

// - GTK initialize -
bool gtk_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gtk class identifier -
  c_bi_class_gtk = class_base_idx++;

  // - initialize gtk_g_object class identifier -
  c_bi_class_gtk_g_object = class_base_idx++;

  // - initialize gtk_widget class identifier -
  c_bi_class_gtk_widget = class_base_idx++;
  gtk_c::gtk_obj_class_first = c_bi_class_gtk_widget;

  // - initialize gtk_container class identifier -
  c_bi_class_gtk_container = class_base_idx++;

  // - initialize gtk_grid class identifier -
  c_bi_class_gtk_grid = class_base_idx++;

  // - initialize gtk_window class identifier -
  c_bi_class_gtk_window = class_base_idx++;
  gtk_c::gtk_obj_class_last = c_bi_class_gtk_window;

  // - initialize gtk_handler class identifier -
  c_bi_class_gtk_handler = class_base_idx++;

  return true;
}/*}}}*/

// - GTK print exception -
bool gtk_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GTK_MAIN_LOOP_STATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGTK main loop is %s running\n",exception.params[0] ? "already" : "not");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_INCOMPATIBLE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIncompatible type of GObject, expected %s\n",g_type_name(exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_UNKNOWN_PROPERTY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGObject does not contain property \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_WRONG_PROPERTIES_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong size of GObject properties array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_PROPERTY_NAME_EXPECTED_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected string as property name at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_PROPERTY_INVALID_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid type of property value to be set\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating GValue");

    (exception.params.used >= 1) ?
      fprintf(stderr," at position %" HOST_LL_FORMAT "d\n",exception.params[0]) :
      fputc('\n',stderr);

    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_G_VALUE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving value from GValue\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_UNKNOWN_SIGNAL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGObject does not recognize signal \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_SIGNAL_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong signal callback delegate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid count of signal parameters, expected %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid type of signal parameter at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_G_OBJECT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating GObject\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GTK_HANDLER_ALREADY_DISCONNECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSignal handler was already disconnected\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GTK -
built_in_class_s gtk_class =
{/*{{{*/
  "Gtk",
  c_modifier_public | c_modifier_final,
  4, gtk_methods,
  165 + 119, gtk_variables,
  bic_gtk_consts,
  bic_gtk_init,
  bic_gtk_clear,
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

built_in_method_s gtk_methods[] =
{/*{{{*/
  {
    "main_loop#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_method_main_loop_0
  },
  {
    "quit_main_loop#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_method_quit_main_loop_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_variables[] =
{/*{{{*/

  // - g_object type constants -
  { "TYPE_ABOUT_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACCEL_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACCEL_LABEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACCEL_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACCESSIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACTION_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ADJUSTMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_APP_CHOOSER_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_APP_CHOOSER_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_APP_CHOOSER_WIDGET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_APPLICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_APPLICATION_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ASPECT_FRAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ASSISTANT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUILDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUTTON_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CALENDAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_AREA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_AREA_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_AREA_CONTEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_ACCEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_COMBO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_PIXBUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_PROGRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_SPIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_SPINNER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_TEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_TOGGLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_VIEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CHECK_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CHECK_MENU_ITEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CLIPBOARD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_COLOR_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_COLOR_CHOOSER_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_COLOR_CHOOSER_WIDGET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_COMBO_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_COMBO_BOX_TEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CONTAINER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CSS_PROVIDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DRAWING_AREA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ENTRY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ENTRY_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ENTRY_COMPLETION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EVENT_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EVENT_CONTROLLER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EXPANDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_CHOOSER_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_CHOOSER_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_CHOOSER_WIDGET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FIXED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FLOW_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FLOW_BOX_CHILD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FONT_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FONT_CHOOSER_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FONT_CHOOSER_WIDGET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FRAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_DRAG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_LONG_PRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_MULTI_PRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_PAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_ROTATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_SINGLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_SWIPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GESTURE_ZOOM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GL_AREA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GRID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_HEADER_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_INFO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_THEME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_VIEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IMAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IM_CONTEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IM_CONTEXT_SIMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IM_MULTICONTEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INFO_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INVISIBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LABEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LAYOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LEVEL_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LINK_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LIST_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LIST_BOX_ROW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LIST_STORE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LOCK_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU_ITEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU_SHELL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU_TOOL_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MESSAGE_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MOUNT_OPERATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_NOTEBOOK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_OFFSCREEN_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_OVERLAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PAD_CONTROLLER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PANED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PLACES_SIDEBAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_POPOVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_POPOVER_MENU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_OPERATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PROGRESS_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RADIO_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RADIO_MENU_ITEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RADIO_TOOL_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_CHOOSER_DIALOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_CHOOSER_MENU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_CHOOSER_WIDGET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_MANAGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_REVEALER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCALE_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCROLLBAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCROLLED_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SEARCH_BAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SEARCH_ENTRY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SEPARATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SEPARATOR_MENU_ITEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SEPARATOR_TOOL_ITEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SETTINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHORTCUT_LABEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHORTCUTS_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHORTCUTS_SECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHORTCUTS_SHORTCUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHORTCUTS_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SIZE_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SPIN_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SPINNER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STACK_SIDEBAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STACK_SWITCHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STATUSBAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STYLE_CONTEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SWITCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_CHILD_ANCHOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_MARK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_TAG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_TAG_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_VIEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOGGLE_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOGGLE_TOOL_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOLBAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOL_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOL_ITEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOL_ITEM_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOL_PALETTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_MODEL_FILTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_MODEL_SORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_SELECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_STORE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_VIEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_VIEW_COLUMN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_VIEWPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_VOLUME_BUTTON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WIDGET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WINDOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WINDOW_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "TYPE_LICENSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACCEL_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_APPLICATION_INHIBIT_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ASSISTANT_PAGE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUTTON_BOX_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUILDER_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CALENDAR_DISPLAY_OPTIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CELL_RENDERER_ACCEL_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RESIZE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CSS_PROVIDER_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CSS_SECTION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DEBUG_FLAG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DIALOG_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RESPONSE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DEST_DEFAULTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ENTRY_ICON_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ALIGN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ARROW_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BASELINE_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DELETE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DIRECTION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SENSITIVITY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_DIRECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_JUSTIFICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MENU_DIRECTION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MESSAGE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_MOVEMENT_STEP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCROLL_STEP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ORIENTATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PACK_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_POSITION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RELIEF_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCROLL_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SELECTION_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHADOW_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STATE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOLBAR_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WRAP_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SORT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IM_PREEDIT_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IM_STATUS_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PACK_DIRECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_PAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PAGE_SET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_NUMBER_UP_LAYOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PAGE_ORIENTATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_QUALITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_DUPLEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UNIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_VIEW_GRID_LINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DRAG_RESULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SIZE_GROUP_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SIZE_REQUEST_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SCROLLABLE_POLICY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STATE_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_REGION_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_JUNCTION_SIDES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BORDER_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_LEVEL_BAR_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INPUT_PURPOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INPUT_HINTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PROPAGATION_PHASE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EVENT_SEQUENCE_STATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PAN_DIRECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_POPOVER_CONSTRAINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_CHOOSER_ACTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_CHOOSER_CONFIRMATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_CHOOSER_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE_FILTER_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_LOOKUP_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_THEME_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ICON_VIEW_DROP_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_IMAGE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ARROW_PLACEMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUTTONS_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BUTTON_ROLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_NOTEBOOK_TAB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PAD_ACTION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PLACES_OPEN_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_OPERATION_RESULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_OPERATION_ACTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PRINT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_SORT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_CHOOSER_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_FILTER_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RECENT_MANAGER_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_REVEALER_TRANSITION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CORNER_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_POLICY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TARGET_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SHORTCUT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SPIN_BUTTON_UPDATE_POLICY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SPIN_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STACK_TRANSITION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_STYLE_CONTEXT_PRINT_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_BUFFER_TARGET_INFO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_SEARCH_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_WINDOW_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_VIEW_LAYER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TEXT_EXTEND_SELECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOLBAR_SPACE_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TOOL_PALETTE_DRAG_TARGETS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_MODEL_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_VIEW_DROP_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TREE_VIEW_COLUMN_SIZING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WIDGET_HELP_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WINDOW_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_WINDOW_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RC_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_RC_TOKEN_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PATH_PRIORITY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PATH_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EXPANDER_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ATTACH_OPTIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UI_MANAGER_ITEM_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_gtk_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert g_object type constants -
  {
    const_locations.push_blanks(165 + 119);
    location_s *cv_ptr = const_locations.data + (const_locations.used - (165 + 119));

    // - retrieve minimal and maximal gtk type -
    gtk_c::gtk_type_min = GTK_TYPE_ABOUT_DIALOG;
    gtk_c::gtk_type_max = GTK_TYPE_ABOUT_DIALOG;

#define CREATE_G_OBJECT_TYPE_BIC_STATIC(VALUE,TYPE_ID)\
{/*{{{*/\
  if ((int)TYPE_ID != 0)\
    g_type_set_qdata(VALUE,gtk_c::bi_class_quark,(gpointer)TYPE_ID);\
  \
  if (VALUE < gtk_c::gtk_type_min) gtk_c::gtk_type_min = VALUE;\
  if (VALUE > gtk_c::gtk_type_max) gtk_c::gtk_type_max = VALUE;\
  \
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;\
}/*}}}*/

    const struct {GType type;int type_id;} data[] =
    {/*{{{*/
      { GTK_TYPE_ABOUT_DIALOG, 0 },
      { GTK_TYPE_ACCEL_GROUP, 0 },
      { GTK_TYPE_ACCEL_LABEL, 0 },
      { GTK_TYPE_ACCEL_MAP, 0 },
      { GTK_TYPE_ACCESSIBLE, 0 },
      { GTK_TYPE_ACTION_BAR, 0 },
      { GTK_TYPE_ADJUSTMENT, 0 },
      { GTK_TYPE_APP_CHOOSER_BUTTON, 0 },
      { GTK_TYPE_APP_CHOOSER_DIALOG, 0 },
      { GTK_TYPE_APP_CHOOSER_WIDGET, 0 },
      { GTK_TYPE_APPLICATION, 0 },
      { GTK_TYPE_APPLICATION_WINDOW, 0 },
      { GTK_TYPE_ASPECT_FRAME, 0 },
      { GTK_TYPE_ASSISTANT, 0 },
      { GTK_TYPE_BIN, 0 },
      { GTK_TYPE_BOX, 0 },
      { GTK_TYPE_BUILDER, 0 },
      { GTK_TYPE_BUTTON, 0 },
      { GTK_TYPE_BUTTON_BOX, 0 },
      { GTK_TYPE_CALENDAR, 0 },
      { GTK_TYPE_CELL_AREA, 0 },
      { GTK_TYPE_CELL_AREA_BOX, 0 },
      { GTK_TYPE_CELL_AREA_CONTEXT, 0 },
      { GTK_TYPE_CELL_RENDERER, 0 },
      { GTK_TYPE_CELL_RENDERER_ACCEL, 0 },
      { GTK_TYPE_CELL_RENDERER_COMBO, 0 },
      { GTK_TYPE_CELL_RENDERER_PIXBUF, 0 },
      { GTK_TYPE_CELL_RENDERER_PROGRESS, 0 },
      { GTK_TYPE_CELL_RENDERER_SPIN, 0 },
      { GTK_TYPE_CELL_RENDERER_SPINNER, 0 },
      { GTK_TYPE_CELL_RENDERER_TEXT, 0 },
      { GTK_TYPE_CELL_RENDERER_TOGGLE, 0 },
      { GTK_TYPE_CELL_VIEW, 0 },
      { GTK_TYPE_CHECK_BUTTON, 0 },
      { GTK_TYPE_CHECK_MENU_ITEM, 0 },
      { GTK_TYPE_CLIPBOARD, 0 },
      { GTK_TYPE_COLOR_BUTTON, 0 },
      { GTK_TYPE_COLOR_CHOOSER_DIALOG, 0 },
      { GTK_TYPE_COLOR_CHOOSER_WIDGET, 0 },
      { GTK_TYPE_COMBO_BOX, 0 },
      { GTK_TYPE_COMBO_BOX_TEXT, 0 },
      { GTK_TYPE_CONTAINER, 0 },
      { GTK_TYPE_CSS_PROVIDER, 0 },
      { GTK_TYPE_DIALOG, 0 },
      { GTK_TYPE_DRAWING_AREA, 0 },
      { GTK_TYPE_ENTRY, 0 },
      { GTK_TYPE_ENTRY_BUFFER, 0 },
      { GTK_TYPE_ENTRY_COMPLETION, 0 },
      { GTK_TYPE_EVENT_BOX, 0 },
      { GTK_TYPE_EVENT_CONTROLLER, 0 },
      { GTK_TYPE_EXPANDER, 0 },
      { GTK_TYPE_FILE_CHOOSER_BUTTON, 0 },
      { GTK_TYPE_FILE_CHOOSER_DIALOG, 0 },
      { GTK_TYPE_FILE_CHOOSER_WIDGET, 0 },
      { GTK_TYPE_FIXED, 0 },
      { GTK_TYPE_FLOW_BOX, 0 },
      { GTK_TYPE_FLOW_BOX_CHILD, 0 },
      { GTK_TYPE_FONT_BUTTON, 0 },
      { GTK_TYPE_FONT_CHOOSER_DIALOG, 0 },
      { GTK_TYPE_FONT_CHOOSER_WIDGET, 0 },
      { GTK_TYPE_FRAME, 0 },
      { GTK_TYPE_GESTURE, 0 },
      { GTK_TYPE_GESTURE_DRAG, 0 },
      { GTK_TYPE_GESTURE_LONG_PRESS, 0 },
      { GTK_TYPE_GESTURE_MULTI_PRESS, 0 },
      { GTK_TYPE_GESTURE_PAN, 0 },
      { GTK_TYPE_GESTURE_ROTATE, 0 },
      { GTK_TYPE_GESTURE_SINGLE, 0 },
      { GTK_TYPE_GESTURE_SWIPE, 0 },
      { GTK_TYPE_GESTURE_ZOOM, 0 },
      { GTK_TYPE_GL_AREA, 0 },
      { GTK_TYPE_GRID, 0 },
      { GTK_TYPE_HEADER_BAR, 0 },
      { GTK_TYPE_ICON_INFO, 0 },
      { GTK_TYPE_ICON_THEME, 0 },
      { GTK_TYPE_ICON_VIEW, 0 },
      { GTK_TYPE_IMAGE, 0 },
      { GTK_TYPE_IM_CONTEXT, 0 },
      { GTK_TYPE_IM_CONTEXT_SIMPLE, 0 },
      { GTK_TYPE_IM_MULTICONTEXT, 0 },
      { GTK_TYPE_INFO_BAR, 0 },
      { GTK_TYPE_INVISIBLE, 0 },
      { GTK_TYPE_LABEL, 0 },
      { GTK_TYPE_LAYOUT, 0 },
      { GTK_TYPE_LEVEL_BAR, 0 },
      { GTK_TYPE_LINK_BUTTON, 0 },
      { GTK_TYPE_LIST_BOX, 0 },
      { GTK_TYPE_LIST_BOX_ROW, 0 },
      { GTK_TYPE_LIST_STORE, 0 },
      { GTK_TYPE_LOCK_BUTTON, 0 },
      { GTK_TYPE_MENU, 0 },
      { GTK_TYPE_MENU_BAR, 0 },
      { GTK_TYPE_MENU_BUTTON, 0 },
      { GTK_TYPE_MENU_ITEM, 0 },
      { GTK_TYPE_MENU_SHELL, 0 },
      { GTK_TYPE_MENU_TOOL_BUTTON, 0 },
      { GTK_TYPE_MESSAGE_DIALOG, 0 },
      { GTK_TYPE_MOUNT_OPERATION, 0 },
      { GTK_TYPE_NOTEBOOK, 0 },
      { GTK_TYPE_OFFSCREEN_WINDOW, 0 },
      { GTK_TYPE_OVERLAY, 0 },
      { GTK_TYPE_PAD_CONTROLLER, 0 },
      { GTK_TYPE_PANED, 0 },
      { GTK_TYPE_PLACES_SIDEBAR, 0 },
      { GTK_TYPE_POPOVER, 0 },
      { GTK_TYPE_POPOVER_MENU, 0 },
      { GTK_TYPE_PRINT_OPERATION, 0 },
      { GTK_TYPE_PROGRESS_BAR, 0 },
      { GTK_TYPE_RADIO_BUTTON, 0 },
      { GTK_TYPE_RADIO_MENU_ITEM, 0 },
      { GTK_TYPE_RADIO_TOOL_BUTTON, 0 },
      { GTK_TYPE_RANGE, 0 },
      { GTK_TYPE_RECENT_CHOOSER_DIALOG, 0 },
      { GTK_TYPE_RECENT_CHOOSER_MENU, 0 },
      { GTK_TYPE_RECENT_CHOOSER_WIDGET, 0 },
      { GTK_TYPE_RECENT_MANAGER, 0 },
      { GTK_TYPE_REVEALER, 0 },
      { GTK_TYPE_SCALE, 0 },
      { GTK_TYPE_SCALE_BUTTON, 0 },
      { GTK_TYPE_SCROLLBAR, 0 },
      { GTK_TYPE_SCROLLED_WINDOW, 0 },
      { GTK_TYPE_SEARCH_BAR, 0 },
      { GTK_TYPE_SEARCH_ENTRY, 0 },
      { GTK_TYPE_SEPARATOR, 0 },
      { GTK_TYPE_SEPARATOR_MENU_ITEM, 0 },
      { GTK_TYPE_SEPARATOR_TOOL_ITEM, 0 },
      { GTK_TYPE_SETTINGS, 0 },
      { GTK_TYPE_SHORTCUT_LABEL, 0 },
      { GTK_TYPE_SHORTCUTS_GROUP, 0 },
      { GTK_TYPE_SHORTCUTS_SECTION, 0 },
      { GTK_TYPE_SHORTCUTS_SHORTCUT, 0 },
      { GTK_TYPE_SHORTCUTS_WINDOW, 0 },
      { GTK_TYPE_SIZE_GROUP, 0 },
      { GTK_TYPE_SPIN_BUTTON, 0 },
      { GTK_TYPE_SPINNER, 0 },
      { GTK_TYPE_STACK, 0 },
      { GTK_TYPE_STACK_SIDEBAR, 0 },
      { GTK_TYPE_STACK_SWITCHER, 0 },
      { GTK_TYPE_STATUSBAR, 0 },
      { GTK_TYPE_STYLE_CONTEXT, 0 },
      { GTK_TYPE_SWITCH, 0 },
      { GTK_TYPE_TEXT_BUFFER, 0 },
      { GTK_TYPE_TEXT_CHILD_ANCHOR, 0 },
      { GTK_TYPE_TEXT_MARK, 0 },
      { GTK_TYPE_TEXT_TAG, 0 },
      { GTK_TYPE_TEXT_TAG_TABLE, 0 },
      { GTK_TYPE_TEXT_VIEW, 0 },
      { GTK_TYPE_TOGGLE_BUTTON, 0 },
      { GTK_TYPE_TOGGLE_TOOL_BUTTON, 0 },
      { GTK_TYPE_TOOLBAR, 0 },
      { GTK_TYPE_TOOL_BUTTON, 0 },
      { GTK_TYPE_TOOL_ITEM, 0 },
      { GTK_TYPE_TOOL_ITEM_GROUP, 0 },
      { GTK_TYPE_TOOL_PALETTE, 0 },
      { GTK_TYPE_TREE_MODEL_FILTER, 0 },
      { GTK_TYPE_TREE_MODEL_SORT, 0 },
      { GTK_TYPE_TREE_SELECTION, 0 },
      { GTK_TYPE_TREE_STORE, 0 },
      { GTK_TYPE_TREE_VIEW, 0 },
      { GTK_TYPE_TREE_VIEW_COLUMN, 0 },
      { GTK_TYPE_VIEWPORT, 0 },
      { GTK_TYPE_VOLUME_BUTTON, 0 },
      { GTK_TYPE_WIDGET, (int)c_bi_class_gtk_widget },
      { GTK_TYPE_WINDOW, (int)c_bi_class_gtk_window },
      { GTK_TYPE_WINDOW_GROUP, 0 },

      { GTK_TYPE_LICENSE, 0 },
      { GTK_TYPE_ACCEL_FLAGS, 0 },
      { GTK_TYPE_APPLICATION_INHIBIT_FLAGS, 0 },
      { GTK_TYPE_ASSISTANT_PAGE_TYPE, 0 },
      { GTK_TYPE_BUTTON_BOX_STYLE, 0 },
      { GTK_TYPE_BUILDER_ERROR, 0 },
      { GTK_TYPE_CALENDAR_DISPLAY_OPTIONS, 0 },
      { GTK_TYPE_CELL_RENDERER_STATE, 0 },
      { GTK_TYPE_CELL_RENDERER_MODE, 0 },
      { GTK_TYPE_CELL_RENDERER_ACCEL_MODE, 0 },
      { GTK_TYPE_RESIZE_MODE, 0 },
      { GTK_TYPE_CSS_PROVIDER_ERROR, 0 },
      { GTK_TYPE_CSS_SECTION_TYPE, 0 },
      { GTK_TYPE_DEBUG_FLAG, 0 },
      { GTK_TYPE_DIALOG_FLAGS, 0 },
      { GTK_TYPE_RESPONSE_TYPE, 0 },
      { GTK_TYPE_DEST_DEFAULTS, 0 },
      { GTK_TYPE_ENTRY_ICON_POSITION, 0 },
      { GTK_TYPE_ALIGN, 0 },
      { GTK_TYPE_ARROW_TYPE, 0 },
      { GTK_TYPE_BASELINE_POSITION, 0 },
      { GTK_TYPE_DELETE_TYPE, 0 },
      { GTK_TYPE_DIRECTION_TYPE, c_type_ui },
      { GTK_TYPE_ICON_SIZE, 0 },
      { GTK_TYPE_SENSITIVITY_TYPE, 0 },
      { GTK_TYPE_TEXT_DIRECTION, 0 },
      { GTK_TYPE_JUSTIFICATION, 0 },
      { GTK_TYPE_MENU_DIRECTION_TYPE, 0 },
      { GTK_TYPE_MESSAGE_TYPE, 0 },
      { GTK_TYPE_MOVEMENT_STEP, 0 },
      { GTK_TYPE_SCROLL_STEP, 0 },
      { GTK_TYPE_ORIENTATION, 0 },
      { GTK_TYPE_PACK_TYPE, 0 },
      { GTK_TYPE_POSITION_TYPE, 0 },
      { GTK_TYPE_RELIEF_STYLE, 0 },
      { GTK_TYPE_SCROLL_TYPE, 0 },
      { GTK_TYPE_SELECTION_MODE, 0 },
      { GTK_TYPE_SHADOW_TYPE, 0 },
      { GTK_TYPE_STATE_TYPE, 0 },
      { GTK_TYPE_TOOLBAR_STYLE, 0 },
      { GTK_TYPE_WRAP_MODE, 0 },
      { GTK_TYPE_SORT_TYPE, 0 },
      { GTK_TYPE_IM_PREEDIT_STYLE, 0 },
      { GTK_TYPE_IM_STATUS_STYLE, 0 },
      { GTK_TYPE_PACK_DIRECTION, 0 },
      { GTK_TYPE_PRINT_PAGES, 0 },
      { GTK_TYPE_PAGE_SET, 0 },
      { GTK_TYPE_NUMBER_UP_LAYOUT, 0 },
      { GTK_TYPE_PAGE_ORIENTATION, 0 },
      { GTK_TYPE_PRINT_QUALITY, 0 },
      { GTK_TYPE_PRINT_DUPLEX, 0 },
      { GTK_TYPE_UNIT, 0 },
      { GTK_TYPE_TREE_VIEW_GRID_LINES, 0 },
      { GTK_TYPE_DRAG_RESULT, 0 },
      { GTK_TYPE_SIZE_GROUP_MODE, 0 },
      { GTK_TYPE_SIZE_REQUEST_MODE, 0 },
      { GTK_TYPE_SCROLLABLE_POLICY, 0 },
      { GTK_TYPE_STATE_FLAGS, 0 },
      { GTK_TYPE_REGION_FLAGS, 0 },
      { GTK_TYPE_JUNCTION_SIDES, 0 },
      { GTK_TYPE_BORDER_STYLE, 0 },
      { GTK_TYPE_LEVEL_BAR_MODE, 0 },
      { GTK_TYPE_INPUT_PURPOSE, 0 },
      { GTK_TYPE_INPUT_HINTS, 0 },
      { GTK_TYPE_PROPAGATION_PHASE, 0 },
      { GTK_TYPE_EVENT_SEQUENCE_STATE, 0 },
      { GTK_TYPE_PAN_DIRECTION, 0 },
      { GTK_TYPE_POPOVER_CONSTRAINT, 0 },
      { GTK_TYPE_FILE_CHOOSER_ACTION, 0 },
      { GTK_TYPE_FILE_CHOOSER_CONFIRMATION, 0 },
      { GTK_TYPE_FILE_CHOOSER_ERROR, 0 },
      { GTK_TYPE_FILE_FILTER_FLAGS, 0 },
      { GTK_TYPE_ICON_LOOKUP_FLAGS, 0 },
      { GTK_TYPE_ICON_THEME_ERROR, 0 },
      { GTK_TYPE_ICON_VIEW_DROP_POSITION, 0 },
      { GTK_TYPE_IMAGE_TYPE, 0 },
      { GTK_TYPE_ARROW_PLACEMENT, 0 },
      { GTK_TYPE_BUTTONS_TYPE, 0 },
      { GTK_TYPE_BUTTON_ROLE, 0 },
      { GTK_TYPE_NOTEBOOK_TAB, 0 },
      { GTK_TYPE_PAD_ACTION_TYPE, 0 },
      { GTK_TYPE_PLACES_OPEN_FLAGS, 0 },
      { GTK_TYPE_PRINT_STATUS, 0 },
      { GTK_TYPE_PRINT_OPERATION_RESULT, 0 },
      { GTK_TYPE_PRINT_OPERATION_ACTION, 0 },
      { GTK_TYPE_PRINT_ERROR, 0 },
      { GTK_TYPE_RECENT_SORT_TYPE, 0 },
      { GTK_TYPE_RECENT_CHOOSER_ERROR, 0 },
      { GTK_TYPE_RECENT_FILTER_FLAGS, 0 },
      { GTK_TYPE_RECENT_MANAGER_ERROR, 0 },
      { GTK_TYPE_REVEALER_TRANSITION_TYPE, 0 },
      { GTK_TYPE_CORNER_TYPE, 0 },
      { GTK_TYPE_POLICY_TYPE, 0 },
      { GTK_TYPE_TARGET_FLAGS, 0 },
      { GTK_TYPE_SHORTCUT_TYPE, 0 },
      { GTK_TYPE_SPIN_BUTTON_UPDATE_POLICY, 0 },
      { GTK_TYPE_SPIN_TYPE, 0 },
      { GTK_TYPE_STACK_TRANSITION_TYPE, 0 },
      { GTK_TYPE_STYLE_CONTEXT_PRINT_FLAGS, 0 },
      { GTK_TYPE_TEXT_BUFFER_TARGET_INFO, 0 },
      { GTK_TYPE_TEXT_SEARCH_FLAGS, 0 },
      { GTK_TYPE_TEXT_WINDOW_TYPE, 0 },
      { GTK_TYPE_TEXT_VIEW_LAYER, 0 },
      { GTK_TYPE_TEXT_EXTEND_SELECTION, 0 },
      { GTK_TYPE_TOOLBAR_SPACE_STYLE, 0 },
      { GTK_TYPE_TOOL_PALETTE_DRAG_TARGETS, 0 },
      { GTK_TYPE_TREE_MODEL_FLAGS, 0 },
      { GTK_TYPE_TREE_VIEW_DROP_POSITION, 0 },
      { GTK_TYPE_TREE_VIEW_COLUMN_SIZING, 0 },
      { GTK_TYPE_WIDGET_HELP_TYPE, 0 },
      { GTK_TYPE_WINDOW_TYPE, 0 },
      { GTK_TYPE_WINDOW_POSITION, 0 },
      { GTK_TYPE_RC_FLAGS, 0 },
      { GTK_TYPE_RC_TOKEN_TYPE, 0 },
      { GTK_TYPE_PATH_PRIORITY_TYPE, 0 },
      { GTK_TYPE_PATH_TYPE, 0 },
      { GTK_TYPE_EXPANDER_STYLE, 0 },
      { GTK_TYPE_ATTACH_OPTIONS, 0 },
      { GTK_TYPE_UI_MANAGER_ITEM_TYPE, 0 },
    };/*}}}*/

    unsigned v_idx = 0;
    unsigned v_idx_end = sizeof(data)/sizeof(data[0]);
    do {
      GType type = data[v_idx].type;
      int type_id = data[v_idx].type_id;

      CREATE_G_OBJECT_TYPE_BIC_STATIC(type,type_id);
    } while(++v_idx < v_idx_end);
  }

}/*}}}*/

void bic_gtk_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_gtk_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_gtk_method_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  // - ERROR -
  if (gtk_c::main_loop)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_MAIN_LOOP_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);

    return false;
  }

  gtk_c::main_loop = true;
  gtk_c::main_source_pos = operands[c_source_pos_idx];
  gtk_c::main_ret_code = c_run_return_code_OK;

  // - run gtk main loop -
  gtk_main();

  unsigned main_ret_code = gtk_c::main_ret_code;
  gtk_c::init_static();

  // - if exception occurred in one of callbacks -
  if (main_ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_method_quit_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - ERROR -
  if (!gtk_c::main_loop)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_MAIN_LOOP_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);

    return false;
  }

  // - quit gtk main loop -
  gtk_main_quit();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Gtk"),"Gtk");
  );

  return true;
}/*}}}*/

bool bic_gtk_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Gtk");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GTK_G_OBJECT -
built_in_class_s gtk_g_object_class =
{/*{{{*/
  "GtkGObject",
  c_modifier_public | c_modifier_final,
  10, gtk_g_object_methods,
  0, gtk_g_object_variables,
  bic_gtk_g_object_consts,
  bic_gtk_g_object_init,
  bic_gtk_g_object_clear,
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

built_in_method_s gtk_g_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_operator_binary_equal
  },
  {
    "GtkGObject#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_GtkGObject_1
  },
  {
    "GtkGObject#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_GtkGObject_2
  },
  {
    "list_properties#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_list_properties_0
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_set_prop_2
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_get_prop_1
  },
  {
    "signal_connect#3",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_connect_3
  },
  {
    "signal_emit#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_emit_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_g_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_g_object_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_g_object_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GTK_G_OBJECT_CREATE_FROM_OBJECT(TYPE) \
{/*{{{*/\
  gpointer g_obj = (gpointer)src_0_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (!GTK_IS_ ## TYPE(g_obj))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_INCOMPATIBLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(GTK_TYPE_ ## TYPE);\
    \
    return false;\
  }\
  \
  g_object_ref(g_obj);\
  \
  dst_location->v_data_ptr = (gpointer)g_obj;\
}/*}}}*/

#define BIC_GTK_G_OBJECT_CREATE_FROM_PROPERTIES(TYPE) \
{/*{{{*/\
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;\
\
  gpointer g_obj = gtk_c::create_g_object(it,GTK_TYPE_ ## TYPE,array_ptr,operands[c_source_pos_idx]);\
\
  /* - ERROR - */\
  if (g_obj == NULL)\
  {\
    return false;\
  }\
\
  dst_location->v_data_ptr = (gpointer)g_obj;\
}/*}}}*/

void bic_gtk_g_object_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gtk_g_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gpointer)NULL;
}/*}}}*/

void bic_gtk_g_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gpointer g_obj = (gpointer)location_ptr->v_data_ptr;

  if (g_obj != NULL)
  {
    g_object_unref(g_obj);
  }
}/*}}}*/

bool bic_gtk_g_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_GtkGObject_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type < c_bi_class_gtk_g_object ||
      src_0_location->v_type > gtk_c::gtk_obj_class_last)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GtkGObject#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)src_0_location->v_data_ptr;

  // - ERROR -
  if (!G_IS_OBJECT(g_obj))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_INCOMPATIBLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(G_TYPE_OBJECT);

    return false;
  }

  g_object_ref(g_obj);

  dst_location->v_data_ptr = (gpointer)g_obj;

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_GtkGObject_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int g_type;

  if (!it.retrieve_integer(src_0_location,g_type) ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GtkGObject#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  gpointer g_obj = gtk_c::create_g_object(it,g_type,array_ptr,operands[c_source_pos_idx]);

  // - ERROR -
  if (g_obj == NULL)
  {
    return false;
  }

  dst_location->v_data_ptr = (gpointer)g_obj;

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_list_properties_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;

  // - retrieve list of object properties -
  guint prop_cnt;
  GParamSpec **param_specs =
    g_object_class_list_properties(G_OBJECT_GET_CLASS(g_obj),&prop_cnt);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (prop_cnt > 0)
  {
    GParamSpec **ps_ptr = param_specs;
    GParamSpec **ps_ptr_end = ps_ptr + prop_cnt;

    do {
      const gchar *name = (*ps_ptr)->name;

      // - create name string -
      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(strlen(name),name);

      // - create name location -
      BIC_CREATE_NEW_LOCATION(name_location,c_bi_class_string,string_ptr);
      array_ptr->push(name_location);

    } while(++ps_ptr < ps_ptr_end);
  }

  g_free(param_specs);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_set_prop_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set_prop#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve parameter specification -
  GParamSpec *value_spec = g_object_class_find_property(
      G_OBJECT_GET_CLASS(G_OBJECT(g_obj)),string_ptr->data);

  // - ERROR -
  if (value_spec == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_UNKNOWN_PROPERTY,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - ERROR -
  if (!gtk_c::g_type_check(src_1_location,value_spec->value_type))
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_PROPERTY_INVALID_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  GValue g_value = {0};

  // - ERROR -
  if (gtk_c::create_g_value(it,src_1_location,&g_value) == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  g_object_set_property(G_OBJECT(g_obj),string_ptr->data,&g_value);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_get_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_prop#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve parameter specification -
  GParamSpec *value_spec = g_object_class_find_property(
      G_OBJECT_GET_CLASS(G_OBJECT(g_obj)),string_ptr->data);

  // - ERROR -
  if (value_spec == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_UNKNOWN_PROPERTY,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  GValue g_value = {0};
  g_value_init(&g_value,value_spec->value_type);
  g_object_get_property(G_OBJECT(g_obj),string_ptr->data,&g_value);

  // - retrieve value of g_value -
  location_s *location_ptr = gtk_c::g_value_value(it,value_spec->value_type,&g_value);

  // - ERROR -
  if (location_ptr == NULL)
  {
    g_value_unset(&g_value);

    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_G_VALUE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  g_value_unset(&g_value);

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_signal_connect_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("signal_connect#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve signal identifier -
  guint signal_id = g_signal_lookup(string_ptr->data,G_OBJECT_TYPE(g_obj));

  // - ERROR -
  if (signal_id == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_UNKNOWN_SIGNAL,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - query signal info -
  GSignalQuery signal_info;
  g_signal_query(signal_id,&signal_info);

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != signal_info.n_params + 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_SIGNAL_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set gtk interpreter pointer -
  if (gtk_c::it_ptr == NULL)
  {
    gtk_c::it_ptr = &it;
  }

  // - retrieve object delegate indexes -
  ui_list_s *obj_dlg_idxs =
    (ui_list_s *)g_object_get_qdata(G_OBJECT(g_obj),gtk_c::dlg_idxs_quark);

  // - if object delegate indexes does not exist -
  if (obj_dlg_idxs == NULL)
  {
    // - create object delegate list -
    obj_dlg_idxs = (ui_list_s *)cmalloc(sizeof(ui_list_s));
    obj_dlg_idxs->init();

    g_object_set_qdata_full(G_OBJECT(g_obj),gtk_c::dlg_idxs_quark,
        obj_dlg_idxs,gtk_c::dlg_data_release);
  }

  long long int delegate_idx = gtk_c::delegates.append_blank();

  // - store delegate index to object delegate indexes -
  unsigned dlg_idx_idx = obj_dlg_idxs->append(delegate_idx);

  // - store delegate and associated data -
  dst_location->v_reference_cnt.atomic_inc();
  src_1_location->v_reference_cnt.atomic_inc();
  src_2_location->v_reference_cnt.atomic_inc();
  gtk_c::delegates[delegate_idx].set(
      signal_id,dlg_idx_idx,0,dst_location,src_1_location,src_2_location);

  // - connect signal to handler -
  gtk_c::delegates[delegate_idx].handler_id =
    g_signal_connect_swapped(g_obj,string_ptr->data,
        G_CALLBACK(gtk_c::callback_handler),(gpointer)delegate_idx);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gtk_handler,delegate_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_signal_emit_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("signal_emit#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - retrieve signal identifier -
  guint signal_id = g_signal_lookup(string_ptr->data,G_OBJECT_TYPE(g_obj));

  // - ERROR -
  if (signal_id == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_UNKNOWN_SIGNAL,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - query signal info -
  GSignalQuery signal_info;
  g_signal_query(signal_id,&signal_info);

  // - ERROR -
  if (array_ptr->used != signal_info.n_params)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(signal_info.n_params);

    return false;
  }

  // - instance + parameters -
  GValue inst_params[array_ptr->used + 1] = {0};

  // - prepare instance value -
  cassert(gtk_c::create_g_value(it,dst_location,inst_params) != NULL);

#define BIC_GTK_G_OBJECT_METHOD_SIGNAL_EMIT_2_RELEASE_PARAMS(FIRST_UNSET) \
{/*{{{*/\
  GValue *rv_ptr = inst_params;\
  GValue *rv_ptr_end = rv_ptr + (FIRST_UNSET);\
  do {\
    g_value_unset(rv_ptr);\
  } while(++rv_ptr < rv_ptr_end);\
}/*}}}*/

  // - prepare parameters values -
  if (array_ptr->used > 0)
  {
    unsigned p_idx = 0;
    do {
      location_s *param_location = it.get_location_value(array_ptr->data[p_idx]);

      // - ERROR -
      if (!gtk_c::g_type_check(param_location,signal_info.param_types[p_idx]))
      {
        BIC_GTK_G_OBJECT_METHOD_SIGNAL_EMIT_2_RELEASE_PARAMS(p_idx);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(p_idx);

        return false;
      }

      // - retrieve parameter value -
      cassert(gtk_c::create_g_value(it,param_location,inst_params + p_idx + 1) != NULL);

    } while(++p_idx < array_ptr->used);
  }

  // - prepare result value -
  GValue ret_value = {0};
  if (signal_info.return_type != G_TYPE_NONE)
  {
    g_value_init(&ret_value,signal_info.return_type);
  }

  // - emit signal -
  g_signal_emitv(inst_params,signal_id,0,&ret_value);

  // - release parameters values -
  BIC_GTK_G_OBJECT_METHOD_SIGNAL_EMIT_2_RELEASE_PARAMS(
    array_ptr->used + 1);

  // - retrieve return location -
  location_s *ret_location = gtk_c::g_value_value(it,signal_info.return_type,&ret_value);

  // - release result value -
  g_value_unset(&ret_value);

  // - ERROR -
  if (ret_location == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(ret_location);

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GtkGObject"),"GtkGObject");
  );

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("GtkGObject");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GTK_WIDGET -
built_in_class_s gtk_widget_class =
{/*{{{*/
  "GtkWidget",
  c_modifier_public | c_modifier_final,
  10, gtk_widget_methods,
  0, gtk_widget_variables,
  bic_gtk_widget_consts,
  bic_gtk_g_object_init,
  bic_gtk_g_object_clear,
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

built_in_method_s gtk_widget_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_widget_operator_binary_equal
  },
  {
    "GtkWidget#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_widget_method_GtkWidget_1
  },
  {
    "list_properties#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_list_properties_0
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_set_prop_2
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_get_prop_1
  },
  {
    "signal_connect#3",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_connect_3
  },
  {
    "signal_emit#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_emit_2
  },
  {
    "show_all#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_widget_method_show_all_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_widget_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_widget_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_widget_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gtk_widget_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

bool bic_gtk_widget_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gtk_widget_method_GtkWidget_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type < c_bi_class_gtk_g_object ||
      src_0_location->v_type > gtk_c::gtk_obj_class_last)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GtkWidget#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_GTK_G_OBJECT_CREATE_FROM_OBJECT(WIDGET);

  return true;
}/*}}}*/

bool bic_gtk_widget_method_show_all_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;

  gtk_widget_show_all(GTK_WIDGET(g_obj));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_widget_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GtkWidget"),"GtkWidget");
  );

  return true;
}/*}}}*/

bool bic_gtk_widget_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("GtkWidget");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GTK_CONTAINER -
built_in_class_s gtk_container_class =
{/*{{{*/
  "GtkContainer",
  c_modifier_public | c_modifier_final,
  11, gtk_container_methods,
  0, gtk_container_variables,
  bic_gtk_container_consts,
  bic_gtk_g_object_init,
  bic_gtk_g_object_clear,
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

built_in_method_s gtk_container_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_container_operator_binary_equal
  },
  {
    "GtkContainer#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_container_method_GtkContainer_1
  },
  {
    "list_properties#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_list_properties_0
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_set_prop_2
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_get_prop_1
  },
  {
    "signal_connect#3",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_connect_3
  },
  {
    "signal_emit#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_emit_2
  },
  {
    "show_all#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_widget_method_show_all_0
  },
  {
    "add#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_container_method_add_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_container_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_container_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_container_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gtk_container_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

bool bic_gtk_container_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gtk_container_method_GtkContainer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type < c_bi_class_gtk_g_object ||
      src_0_location->v_type > gtk_c::gtk_obj_class_last)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GtkContainer#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_GTK_G_OBJECT_CREATE_FROM_OBJECT(CONTAINER);

  return true;
}/*}}}*/

bool bic_gtk_container_method_add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type < c_bi_class_gtk_g_object ||
      src_0_location->v_type > gtk_c::gtk_obj_class_last)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  gpointer g_obj_widget = (gpointer)src_0_location->v_data_ptr;

  // - ERROR -
  if (!GTK_IS_WIDGET(g_obj_widget))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_INCOMPATIBLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(GTK_TYPE_WIDGET);

    return false;
  }

  gtk_container_add(GTK_CONTAINER(g_obj),GTK_WIDGET(g_obj_widget));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_container_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GtkContainer"),"GtkContainer");
  );

  return true;
}/*}}}*/

bool bic_gtk_container_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("GtkContainer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GTK_GRID -
built_in_class_s gtk_grid_class =
{/*{{{*/
  "GtkGrid",
  c_modifier_public | c_modifier_final,
  12, gtk_grid_methods,
  0, gtk_grid_variables,
  bic_gtk_grid_consts,
  bic_gtk_g_object_init,
  bic_gtk_g_object_clear,
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

built_in_method_s gtk_grid_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_grid_operator_binary_equal
  },
  {
    "GtkGrid#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_grid_method_GtkGrid_1
  },
  {
    "list_properties#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_list_properties_0
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_set_prop_2
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_get_prop_1
  },
  {
    "signal_connect#3",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_connect_3
  },
  {
    "signal_emit#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_emit_2
  },
  {
    "show_all#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_widget_method_show_all_0
  },
  {
    "add#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_container_method_add_1
  },
  {
    "attach#5",
    c_modifier_public | c_modifier_final,
    bic_gtk_grid_method_attach_5
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_grid_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_grid_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_grid_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gtk_grid_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

bool bic_gtk_grid_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gtk_grid_method_GtkGrid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    if (src_0_location->v_type < c_bi_class_gtk_g_object ||
        src_0_location->v_type > gtk_c::gtk_obj_class_last)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GtkGrid#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    BIC_GTK_G_OBJECT_CREATE_FROM_OBJECT(GRID);
  }
  else
  {
    BIC_GTK_G_OBJECT_CREATE_FROM_PROPERTIES(GRID);
  }

  return true;
}/*}}}*/

bool bic_gtk_grid_method_attach_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int left;
  long long int top;
  long long int width;
  long long int height;

  if (src_0_location->v_type < c_bi_class_gtk_g_object ||
      src_0_location->v_type > gtk_c::gtk_obj_class_last ||
      !it.retrieve_integer(src_1_location,left) ||
      !it.retrieve_integer(src_2_location,top) ||
      !it.retrieve_integer(src_3_location,width) ||
      !it.retrieve_integer(src_4_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("attach#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  gpointer g_obj_widget = (gpointer)src_0_location->v_data_ptr;

  // - ERROR -
  if (!GTK_IS_WIDGET(g_obj_widget))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_INCOMPATIBLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(GTK_TYPE_WIDGET);

    return false;
  }

  gtk_grid_attach(GTK_GRID(g_obj),GTK_WIDGET(g_obj_widget),left,top,width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_grid_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GtkGrid"),"GtkGrid");
  );

  return true;
}/*}}}*/

bool bic_gtk_grid_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("GtkGrid");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GTK_WINDOW -
built_in_class_s gtk_window_class =
{/*{{{*/
  "GtkWindow",
  c_modifier_public | c_modifier_final,
  12, gtk_window_methods,
  0, gtk_window_variables,
  bic_gtk_window_consts,
  bic_gtk_g_object_init,
  bic_gtk_g_object_clear,
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

built_in_method_s gtk_window_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_window_operator_binary_equal
  },
  {
    "GtkWindow#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_window_method_GtkWindow_1
  },
  {
    "list_properties#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_list_properties_0
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_set_prop_2
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_get_prop_1
  },
  {
    "signal_connect#3",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_connect_3
  },
  {
    "signal_emit#2",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_signal_emit_2
  },
  {
    "show_all#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_widget_method_show_all_0
  },
  {
    "add#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_container_method_add_1
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_window_method_close_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_window_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_window_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_window_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gtk_window_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

bool bic_gtk_window_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gtk_window_method_GtkWindow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    if (src_0_location->v_type < c_bi_class_gtk_g_object ||
        src_0_location->v_type > gtk_c::gtk_obj_class_last)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GtkWindow#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    BIC_GTK_G_OBJECT_CREATE_FROM_OBJECT(WINDOW);
  }
  else
  {
    BIC_GTK_G_OBJECT_CREATE_FROM_PROPERTIES(WINDOW);
  }

  return true;
}/*}}}*/

bool bic_gtk_window_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  gtk_window_close(GTK_WINDOW(g_obj));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_window_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GtkWindow"),"GtkWindow");
  );

  return true;
}/*}}}*/

bool bic_gtk_window_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("GtkWindow");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GTK_HANDLER -
built_in_class_s gtk_handler_class =
{/*{{{*/
  "GtkHandler",
  c_modifier_public | c_modifier_final,
  4, gtk_handler_methods,
  0, gtk_handler_variables,
  bic_gtk_handler_consts,
  bic_gtk_handler_init,
  bic_gtk_handler_clear,
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

built_in_method_s gtk_handler_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_handler_operator_binary_equal
  },
  {
    "disconnect#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_handler_method_disconnect_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_handler_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_handler_method_print_0
  },
};/*}}}*/

built_in_variable_s gtk_handler_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gtk_handler_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gtk_handler_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = -1LL;
}/*}}}*/

void bic_gtk_handler_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  long long int delegate_idx = (long long int)location_ptr->v_data_ptr;

  if (delegate_idx != -1)
  {
    gtk_delegate_s &delegate = gtk_c::delegates[delegate_idx];
    it.release_location_ptr((location_s *)delegate.object_loc);
  }
}/*}}}*/

bool bic_gtk_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gtk_handler_method_disconnect_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long delegate_idx = (long long int)dst_location->v_data_ptr;

  // - ERROR -
  if (delegate_idx == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_HANDLER_ALREADY_DISCONNECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  gtk_delegate_s &delegate = gtk_c::delegates[delegate_idx];
  gpointer g_obj = (gpointer)((location_s *)delegate.object_loc)->v_data_ptr;

  // - disconnect handle from signal -
  g_signal_handler_disconnect(g_obj,delegate.handler_id);

  // - release object reference -
  it.release_location_ptr((location_s *)delegate.object_loc);

  // - reset handler identifier -
  dst_location->v_data_ptr = -1LL;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GtkHandler"),"GtkHandler");
  );

  return true;
}/*}}}*/

bool bic_gtk_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("GtkHandler");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

