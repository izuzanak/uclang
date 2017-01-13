
@begin
include "ucl_gtk.h"
@end

// - static members of class gtk_c -
GQuark gtk_c::ucl_dlgs_quark;

GApplication *gtk_c::app_ptr;
bool gtk_c::app_running;
unsigned gtk_c::app_source_pos;
unsigned gtk_c::app_ret_code;

// - gtk global init object -
gtk_c g_gtk;

/*
 * methods of class gtk_c
 */

void gtk_c::dlg_data_release(gpointer data)
{/*{{{*/

  // - retrieve delegate data pointer -
  gtk_dlg_data_s *dlg_data_ptr = (gtk_dlg_data_s *)data;

  // - if delegate data pointer exists -
  if (dlg_data_ptr != NULL)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)dlg_data_ptr->it_ptr);
    gtk_delegate_list_s &delegates = dlg_data_ptr->delegates;

    if (delegates.first_idx != c_idx_not_exist)
    {
      unsigned idx = delegates.first_idx;
      do {
        gtk_delegate_list_s_element &element = delegates.data[idx];

        // - release delegate location -
        it.release_location_ptr((location_s *)element.object.delegate_loc);

        // - release data location -
        it.release_location_ptr((location_s *)element.object.data_loc);

        idx = element.next_idx;
      } while(idx != c_idx_not_exist);
    }

    // - release delegate data pointer -
    dlg_data_ptr->clear();
    cfree(dlg_data_ptr);
  }
}/*}}}*/

void gtk_c::callback_handler(gpointer g_obj,gpointer data)
{/*{{{*/

  // - retrieve delegate data pointer -
  gtk_dlg_data_s *dlg_data_ptr =
    (gtk_dlg_data_s *)g_object_get_qdata(G_OBJECT(g_obj),gtk_c::ucl_dlgs_quark);

  // - retrieve interpreter thread reference -
  interpreter_thread_s &it = *((interpreter_thread_s *)dlg_data_ptr->it_ptr);

  // - retrieve gtk delegate description -
  gtk_delegate_s &delegate = dlg_data_ptr->delegates[(unsigned)data];

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr =
    (delegate_s *)((location_s *)delegate.delegate_loc)->v_data_ptr;

  // - callback parameters -
  const unsigned param_cnt = 2;
  pointer param_data[param_cnt] = {
    dlg_data_ptr->object_loc,delegate.data_loc};

  // - call delegate method -
  location_s *trg_location = NULL;
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,gtk_c::app_source_pos,
      gtk_c::app_ret_code = c_run_return_code_EXCEPTION;

      // - if application exists, quit it -
      if (gtk_c::app_ptr != NULL)
      {
        g_application_quit(gtk_c::app_ptr);
      }

      return;
      );
  it.release_location_ptr(trg_location);
}/*}}}*/

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

