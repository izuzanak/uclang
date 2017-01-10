
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
  1, gtk_g_object_variables,
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
  { "TYPE_APPLICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_gtk_g_object_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert g_object type constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_G_OBJECT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_G_OBJECT_TYPE_BIC_STATIC(GTK_TYPE_APPLICATION);
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

