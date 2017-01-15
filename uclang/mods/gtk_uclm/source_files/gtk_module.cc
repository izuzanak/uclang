
@begin
include "gtk_module.h"
@end

// - GTK indexes of built in classes -
unsigned c_bi_class_gtk_g_object = c_idx_not_exist;

// - GTK module -
built_in_module_s module =
{/*{{{*/
  1,                   // Class count
  gtk_classes,         // Classes

  0,                   // Error base index
  11,                  // Error count
  gtk_error_strings,   // Error strings

  gtk_initialize,      // Initialize function
  gtk_print_exception, // Print exceptions function
};/*}}}*/

// - GTK classes -
built_in_class_s *gtk_classes[] =
{/*{{{*/
  &gtk_g_object_class,
};/*}}}*/

// - GTK error strings -
const char *gtk_error_strings[] =
{/*{{{*/
  "error_GTK_G_OBJECT_WRONG_PROPERTIES_ARRAY_SIZE",
  "error_GTK_G_OBJECT_PROPERTY_NAME_EXPECTED_STRING",
  "error_GTK_G_OBJECT_UNKNOWN_PROPERTY",
  "error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR",
  "error_GTK_G_OBJECT_G_VALUE_VALUE_ERROR",
  "error_GTK_G_OBJECT_UNKNOWN_SIGNAL",
  "error_GTK_G_OBJECT_SIGNAL_WRONG_CALLBACK_DELEGATE",
  "error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_COUNT",
  "error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_TYPE",
  "error_GTK_G_OBJECT_CREATE_ERROR",
  "error_GTK_G_OBJECT_MAIN_LOOP_STATE_ERROR",
};/*}}}*/

// - GTK initialize -
bool gtk_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gtk_g_object class identifier -
  c_bi_class_gtk_g_object = class_base_idx++;

  return true;
}/*}}}*/

// - GTK print exception -
bool gtk_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
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
  case c_error_GTK_G_OBJECT_UNKNOWN_PROPERTY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGObject does not contain property \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
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
  case c_error_GTK_G_OBJECT_MAIN_LOOP_STATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGTK main loop is %s running\n",exception.params[0] ? "already" : "not");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GTK_G_OBJECT -
built_in_class_s gtk_g_object_class =
{/*{{{*/
  "GtkGObject",
  c_modifier_public | c_modifier_final,
  14, gtk_g_object_methods,
  165, gtk_g_object_variables,
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
    "container_add#1",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_container_add_1
  },
  {
    "grid_attach#5",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_grid_attach_5
  },
  {
    "widget_show_all#0",
    c_modifier_public | c_modifier_final,
    bic_gtk_g_object_method_widget_show_all_0
  },
  {
    "main_loop#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_g_object_method_main_loop_0
  },
  {
    "quit_main_loop#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gtk_g_object_method_quit_main_loop_0
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

};/*}}}*/

void bic_gtk_g_object_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert g_object type constants -
  {
    const_locations.push_blanks(165);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 165);

#define CREATE_G_OBJECT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ABOUT_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ACCEL_GROUP);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ACCEL_LABEL);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ACCEL_MAP);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ACCESSIBLE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ACTION_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ADJUSTMENT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_APP_CHOOSER_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_APP_CHOOSER_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_APP_CHOOSER_WIDGET);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_APPLICATION);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_APPLICATION_WINDOW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ASPECT_FRAME);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ASSISTANT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_BIN);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_BUILDER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_BUTTON_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CALENDAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_AREA);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_AREA_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_AREA_CONTEXT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_ACCEL);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_COMBO);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_PIXBUF);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_PROGRESS);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_SPIN);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_SPINNER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_TEXT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_RENDERER_TOGGLE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CELL_VIEW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CHECK_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CHECK_MENU_ITEM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CLIPBOARD);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_COLOR_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_COLOR_CHOOSER_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_COLOR_CHOOSER_WIDGET);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_COMBO_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_COMBO_BOX_TEXT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CONTAINER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_CSS_PROVIDER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_DRAWING_AREA);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ENTRY);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ENTRY_BUFFER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ENTRY_COMPLETION);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_EVENT_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_EVENT_CONTROLLER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_EXPANDER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FILE_CHOOSER_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FILE_CHOOSER_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FILE_CHOOSER_WIDGET);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FIXED);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FLOW_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FLOW_BOX_CHILD);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FONT_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FONT_CHOOSER_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FONT_CHOOSER_WIDGET);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_FRAME);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_DRAG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_LONG_PRESS);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_MULTI_PRESS);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_PAN);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_ROTATE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_SINGLE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_SWIPE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GESTURE_ZOOM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GL_AREA);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_GRID);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_HEADER_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ICON_INFO);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ICON_THEME);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_ICON_VIEW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_IMAGE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_IM_CONTEXT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_IM_CONTEXT_SIMPLE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_IM_MULTICONTEXT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_INFO_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_INVISIBLE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LABEL);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LAYOUT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LEVEL_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LINK_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LIST_BOX);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LIST_BOX_ROW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LIST_STORE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_LOCK_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MENU);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MENU_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MENU_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MENU_ITEM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MENU_SHELL);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MENU_TOOL_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MESSAGE_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_MOUNT_OPERATION);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_NOTEBOOK);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_OFFSCREEN_WINDOW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_OVERLAY);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_PAD_CONTROLLER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_PANED);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_PLACES_SIDEBAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_POPOVER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_POPOVER_MENU);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_PRINT_OPERATION);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_PROGRESS_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RADIO_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RADIO_MENU_ITEM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RADIO_TOOL_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RANGE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RECENT_CHOOSER_DIALOG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RECENT_CHOOSER_MENU);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RECENT_CHOOSER_WIDGET);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_RECENT_MANAGER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_REVEALER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SCALE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SCALE_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SCROLLBAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SCROLLED_WINDOW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SEARCH_BAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SEARCH_ENTRY);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SEPARATOR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SEPARATOR_MENU_ITEM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SEPARATOR_TOOL_ITEM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SETTINGS);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SHORTCUT_LABEL);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SHORTCUTS_GROUP);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SHORTCUTS_SECTION);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SHORTCUTS_SHORTCUT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SHORTCUTS_WINDOW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SIZE_GROUP);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SPIN_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SPINNER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_STACK);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_STACK_SIDEBAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_STACK_SWITCHER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_STATUSBAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_STYLE_CONTEXT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_SWITCH);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TEXT_BUFFER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TEXT_CHILD_ANCHOR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TEXT_MARK);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TEXT_TAG);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TEXT_TAG_TABLE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TEXT_VIEW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOGGLE_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOGGLE_TOOL_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOOLBAR);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOOL_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOOL_ITEM);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOOL_ITEM_GROUP);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TOOL_PALETTE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TREE_MODEL_FILTER);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TREE_MODEL_SORT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TREE_SELECTION);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TREE_STORE);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TREE_VIEW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_TREE_VIEW_COLUMN);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_VIEWPORT);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_VOLUME_BUTTON);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_WIDGET);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_WINDOW);
    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_WINDOW_GROUP);
  }

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

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_WRONG_PROPERTIES_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  guint param_cnt = array_ptr->used >> 1;
  GParameter params[param_cnt] = {0};

#define BIC_GTK_G_OBJECT_METHOD_GTKGOBJECT_2_RELEASE_PARAMS() \
{/*{{{*/\
  GParameter *rp_ptr = params;\
  GParameter *rp_ptr_end = rp_ptr + param_cnt;\
\
  do {\
    g_value_unset(&rp_ptr->value);\
  } while(++rp_ptr < rp_ptr_end);\
}/*}}}*/

  // - prepare parameters -
  if (param_cnt > 0)
  {
    GParameter *p_ptr = params;
    GParameter *p_ptr_end = p_ptr + param_cnt;
    pointer *a_ptr = array_ptr->data;

    do {
      location_s *name_location = it.get_location_value(a_ptr[0]);
      location_s *value_location = it.get_location_value(a_ptr[1]);

      // - ERROR -
      if (name_location->v_type != c_bi_class_string)
      {
        BIC_GTK_G_OBJECT_METHOD_GTKGOBJECT_2_RELEASE_PARAMS();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_PROPERTY_NAME_EXPECTED_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(p_ptr - params);

        return false;
      }

      string_s *string_ptr = (string_s *)name_location->v_data_ptr;
      p_ptr->name = string_ptr->data;

      // - ERROR -
      if (!gtk_c::create_g_value(it,value_location,&p_ptr->value))
      {
        BIC_GTK_G_OBJECT_METHOD_GTKGOBJECT_2_RELEASE_PARAMS();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(p_ptr - params);

        return false;
      }

    } while((a_ptr += 2),++p_ptr < p_ptr_end);
  }

  // - create new g_object -
  gpointer g_obj = g_object_newv(g_type,param_cnt,params);

  // - ERROR -
  if (!g_obj)
  {
    BIC_GTK_G_OBJECT_METHOD_GTKGOBJECT_2_RELEASE_PARAMS();

    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - acquire floating reference to object -
  if (g_object_is_floating(g_obj))
  {
    g_object_ref_sink(g_obj);
  }
  else
  {
    g_object_ref(g_obj);
  }

  BIC_GTK_G_OBJECT_METHOD_GTKGOBJECT_2_RELEASE_PARAMS();

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

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_SIGNAL_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve delegate data pointer -
  gtk_dlg_data_s *dlg_data_ptr =
    (gtk_dlg_data_s *)g_object_get_qdata(G_OBJECT(g_obj),gtk_c::ucl_dlgs_quark);

  // - if delegate data pointer does not exist -
  if (dlg_data_ptr == NULL)
  {
    // - create delegate data pointer -
    dlg_data_ptr = (gtk_dlg_data_s *)cmalloc(sizeof(gtk_dlg_data_s));
    dlg_data_ptr->init();
    dlg_data_ptr->it_ptr = &it;
    dlg_data_ptr->object_loc = dst_location;

    g_object_set_qdata_full(G_OBJECT(g_obj),gtk_c::ucl_dlgs_quark,
        dlg_data_ptr,gtk_c::dlg_data_release);
  }

  unsigned delegate_idx = dlg_data_ptr->delegates.append_blank();

  // - store delegate and associated data -
  src_1_location->v_reference_cnt.atomic_inc();
  src_2_location->v_reference_cnt.atomic_inc();
  dlg_data_ptr->delegates[delegate_idx].set(0,src_1_location,src_2_location);

  // - connect signal to handler -
  g_signal_connect(g_obj,string_ptr->data,G_CALLBACK(gtk_c::callback_handler),(gpointer)delegate_idx);

  // FIXME TODO return signal handler
  BIC_SET_RESULT_BLANK();

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
      if (!gtk_c::check_g_type(param_location,signal_info.param_types[p_idx]))
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

bool bic_gtk_g_object_method_container_add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_gtk_g_object)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("container_add#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;
  gpointer g_obj_widget = (gpointer)src_0_location->v_data_ptr;

  // - add widget to container -
  gtk_container_add(GTK_CONTAINER(g_obj),GTK_WIDGET(g_obj_widget));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_grid_attach_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  if (src_0_location->v_type != c_bi_class_gtk_g_object ||
      !it.retrieve_integer(src_1_location,left) ||
      !it.retrieve_integer(src_2_location,top) ||
      !it.retrieve_integer(src_3_location,width) ||
      !it.retrieve_integer(src_4_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("grid_attach#5");
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

  // - attach widget to grid -
  gtk_grid_attach(GTK_GRID(g_obj),GTK_WIDGET(g_obj_widget),left,top,width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_widget_show_all_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gpointer g_obj = (gpointer)dst_location->v_data_ptr;

  // - show widget and all its children -
  gtk_widget_show_all(GTK_WIDGET(g_obj));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_gtk_g_object_method_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  // - ERROR - 
  if (gtk_c::main_loop)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_MAIN_LOOP_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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

bool bic_gtk_g_object_method_quit_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - ERROR - 
  if (!gtk_c::main_loop)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_MAIN_LOOP_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);

    return false;
  }

  // - quit gtk main loop -
  gtk_main_quit();

  BIC_SET_RESULT_BLANK();

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

