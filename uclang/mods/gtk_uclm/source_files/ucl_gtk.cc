
@begin
include "ucl_gtk.h"
@end

// - gtk global init object -
gtk_c g_gtk;

/*
 * methods of class gtk_c
 */

GValue *gtk_c::create_g_value(interpreter_thread_s &it,location_s *location_ptr,GValue *value)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_gtk_g_object)
  {/*{{{*/
    gpointer g_obj = (gpointer)location_ptr->v_data_ptr;

    g_value_init(value,G_TYPE_OBJECT);
    g_value_set_object(value,g_obj);

    return value;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_char:
      g_value_init(value,G_TYPE_CHAR);
      g_value_set_schar(value,(char)location_ptr->v_data_ptr);
      return value;
    case c_bi_class_integer:
      g_value_init(value,G_TYPE_INT64);
      g_value_set_int64(value,(long long int)location_ptr->v_data_ptr);
      return value;
    case c_bi_class_float:
      g_value_init(value,G_TYPE_DOUBLE);
      g_value_set_double(value,(double)location_ptr->v_data_ptr);
      return value;
    case c_bi_class_string:
      {/*{{{*/
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

        g_value_init(value,G_TYPE_STRING);
        g_value_set_string(value,string_ptr->data);

        return value;
      }/*}}}*/

    // - ERROR -
    default:
      return NULL;
    }
  }
}/*}}}*/

location_s *gtk_c::g_value_value(interpreter_thread_s &it,GValue *value,uli source_pos)
{/*{{{*/

  // FIXME TODO continue ...
  return NULL;
}/*}}}*/

/*
 * methods of generated structures
 */

// -- gtk_delegate_s --
@begin
methods gtk_delegate_s
@end

// -- gtk_delegate_list_s --
@begin
methods gtk_delegate_list_s
@end

// -- gtk_dlg_data_s --
@begin
methods gtk_dlg_data_s
@end

