
#ifndef __GTK_MODULE_H
#define __GTK_MODULE_H

@begin
include "ucl_gtk.h"
@end

// - GTK indexes of built in classes -
extern unsigned c_bi_class_gtk_g_object;

// - GTK module -
extern built_in_module_s module;

// - GTK classes -
extern built_in_class_s *gtk_classes[];

// - GTK error identifiers -
enum
{
  c_error_GTK_DUMMY_ERROR = 0,
};

// - GTK error strings -
extern const char *gtk_error_strings[];

// - GTK initialize -
bool gtk_initialize(script_parser_s &sp);

// - GTK print exception -
bool gtk_print_exception(interpreter_s &it,exception_s &exception);

// - class GTK_G_OBJECT -
extern built_in_variable_s gtk_g_object_variables[];
extern built_in_method_s gtk_g_object_methods[];
extern built_in_class_s gtk_g_object_class;

void bic_gtk_g_object_consts(location_array_s &const_locations);
void bic_gtk_g_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gtk_g_object_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gtk_g_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_GtkGObject_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_list_properties_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_signal_connect_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gtk_g_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

