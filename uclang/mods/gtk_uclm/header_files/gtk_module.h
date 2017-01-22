
#ifndef __GTK_MODULE_H
#define __GTK_MODULE_H

@begin
include "ucl_gtk.h"
@end

// - GTK indexes of built in classes -
extern unsigned c_bi_class_gtk;
extern unsigned c_bi_class_gtk_g_object;
extern unsigned c_bi_class_gtk_widget;
extern unsigned c_bi_class_gtk_container;
extern unsigned c_bi_class_gtk_grid;
extern unsigned c_bi_class_gtk_window;
extern unsigned c_bi_class_gtk_dialog;
extern unsigned c_bi_class_gtk_handler;

// - GTK module -
extern built_in_module_s module;

// - GTK classes -
extern built_in_class_s *gtk_classes[];

// - GTK error identifiers -
enum
{
  c_error_GTK_MAIN_LOOP_STATE_ERROR = 0,
  c_error_GTK_WRONG_ARRAY_SIZE,
  c_error_GTK_EXPECTED_STRING,
  c_error_GTK_INVALID_VALUE_TYPE,
  c_error_GTK_G_OBJECT_INCOMPATIBLE_TYPE,
  c_error_GTK_G_OBJECT_UNKNOWN_PROPERTY,
  c_error_GTK_G_OBJECT_PROPERTY_INVALID_VALUE_TYPE,
  c_error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR,
  c_error_GTK_G_OBJECT_G_VALUE_VALUE_ERROR,
  c_error_GTK_G_OBJECT_UNKNOWN_SIGNAL,
  c_error_GTK_G_OBJECT_SIGNAL_WRONG_CALLBACK_DELEGATE,
  c_error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_COUNT,
  c_error_GTK_G_OBJECT_SIGNAL_INVALID_PARAMETER_TYPE,
  c_error_GTK_G_OBJECT_CREATE_ERROR,
  c_error_GTK_HANDLER_ALREADY_DISCONNECTED,
};

// - GTK error strings -
extern const char *gtk_error_strings[];

// - GTK initialize -
bool gtk_initialize(script_parser_s &sp);

// - GTK print exception -
bool gtk_print_exception(interpreter_s &it,exception_s &exception);

// - class GTK -
extern built_in_variable_s gtk_variables[];
extern built_in_method_s gtk_methods[];
extern built_in_class_s gtk_class;

void bic_gtk_consts(location_array_s &const_locations);
void bic_gtk_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gtk_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gtk_method_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_method_quit_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_G_OBJECT -
extern built_in_variable_s gtk_g_object_variables[];
extern built_in_method_s gtk_g_object_methods[];
extern built_in_class_s gtk_g_object_class;

void bic_gtk_g_object_consts(location_array_s &const_locations);
void bic_gtk_g_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gtk_g_object_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gtk_g_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_GtkGObject_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_GtkGObject_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_list_properties_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_set_prop_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_get_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_signal_connect_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_signal_emit_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_WIDGET -
extern built_in_variable_s gtk_widget_variables[];
extern built_in_method_s gtk_widget_methods[];
extern built_in_class_s gtk_widget_class;

void bic_gtk_widget_consts(location_array_s &const_locations);

bool bic_gtk_widget_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_widget_method_GtkWidget_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_widget_method_show_all_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_widget_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_widget_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_CONTAINER -
extern built_in_variable_s gtk_container_variables[];
extern built_in_method_s gtk_container_methods[];
extern built_in_class_s gtk_container_class;

void bic_gtk_container_consts(location_array_s &const_locations);

bool bic_gtk_container_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_container_method_GtkContainer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_container_method_add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_container_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_container_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_GRID -
extern built_in_variable_s gtk_grid_variables[];
extern built_in_method_s gtk_grid_methods[];
extern built_in_class_s gtk_grid_class;

void bic_gtk_grid_consts(location_array_s &const_locations);

bool bic_gtk_grid_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_grid_method_GtkGrid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_grid_method_attach_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_grid_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_grid_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_WINDOW -
extern built_in_variable_s gtk_window_variables[];
extern built_in_method_s gtk_window_methods[];
extern built_in_class_s gtk_window_class;

void bic_gtk_window_consts(location_array_s &const_locations);

bool bic_gtk_window_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_window_method_GtkWindow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_window_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_window_method_dialog_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_window_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_window_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_DIALOG -
extern built_in_variable_s gtk_dialog_variables[];
extern built_in_method_s gtk_dialog_methods[];
extern built_in_class_s gtk_dialog_class;

void bic_gtk_dialog_consts(location_array_s &const_locations);

bool bic_gtk_dialog_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_GtkDialog_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_add_button_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_run_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_get_filename_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_get_filenames_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_dialog_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GTK_HANDLER -
extern built_in_variable_s gtk_handler_variables[];
extern built_in_method_s gtk_handler_methods[];
extern built_in_class_s gtk_handler_class;

void bic_gtk_handler_consts(location_array_s &const_locations);
void bic_gtk_handler_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gtk_handler_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gtk_handler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_handler_method_disconnect_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_handler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_handler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

