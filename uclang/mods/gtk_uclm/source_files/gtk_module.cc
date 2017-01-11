
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
  1,                   // Error count
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
  "error_GTK_DUMMY_ERROR",
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
  case c_error_GTK_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGTK dummy error\n");
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
  3, gtk_g_object_methods,
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
  
  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

void bic_gtk_g_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
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

