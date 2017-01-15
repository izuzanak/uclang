
@begin
include "ucl_gtk.h"
@end

// - static members of class gtk_c -
GQuark gtk_c::ucl_dlgs_quark;

bool gtk_c::main_loop;
unsigned gtk_c::main_source_pos;
unsigned gtk_c::main_ret_code;

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
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,gtk_c::main_source_pos,
      gtk_c::main_ret_code = c_run_return_code_EXCEPTION;

      // - quit gtk main loop -
      gtk_main_quit();

      return;
      );
  it.release_location_ptr(trg_location);
}/*}}}*/

bool gtk_c::check_g_type(location_s *location_ptr,GType g_type)
{/*{{{*/

  // FIXME debug output
  //{/*{{{*/
  //  switch (g_type)
  //  {
  //  case G_TYPE_INVALID:   fprintf(stderr,"g_type: G_TYPE_INVALID\n"); break;
  //  case G_TYPE_NONE:      fprintf(stderr,"g_type: G_TYPE_NONE\n"); break;
  //  case G_TYPE_INTERFACE: fprintf(stderr,"g_type: G_TYPE_INTERFACE\n"); break;
  //  case G_TYPE_CHAR:      fprintf(stderr,"g_type: G_TYPE_CHAR\n"); break;
  //  case G_TYPE_UCHAR:     fprintf(stderr,"g_type: G_TYPE_UCHAR\n"); break;
  //  case G_TYPE_BOOLEAN:   fprintf(stderr,"g_type: G_TYPE_BOOLEAN\n"); break;
  //  case G_TYPE_INT:       fprintf(stderr,"g_type: G_TYPE_INT\n"); break;
  //  case G_TYPE_UINT:      fprintf(stderr,"g_type: G_TYPE_UINT\n"); break;
  //  case G_TYPE_LONG:      fprintf(stderr,"g_type: G_TYPE_LONG\n"); break;
  //  case G_TYPE_ULONG:     fprintf(stderr,"g_type: G_TYPE_ULONG\n"); break;
  //  case G_TYPE_INT64:     fprintf(stderr,"g_type: G_TYPE_INT64\n"); break;
  //  case G_TYPE_UINT64:    fprintf(stderr,"g_type: G_TYPE_UINT64\n"); break;
  //  case G_TYPE_ENUM:      fprintf(stderr,"g_type: G_TYPE_ENUM\n"); break;
  //  case G_TYPE_FLAGS:     fprintf(stderr,"g_type: G_TYPE_FLAGS\n"); break;
  //  case G_TYPE_FLOAT:     fprintf(stderr,"g_type: G_TYPE_FLOAT\n"); break;
  //  case G_TYPE_DOUBLE:    fprintf(stderr,"g_type: G_TYPE_DOUBLE\n"); break;
  //  case G_TYPE_STRING:    fprintf(stderr,"g_type: G_TYPE_STRING\n"); break;
  //  case G_TYPE_POINTER:   fprintf(stderr,"g_type: G_TYPE_POINTER\n"); break;
  //  case G_TYPE_BOXED:     fprintf(stderr,"g_type: G_TYPE_BOXED\n"); break;
  //  case G_TYPE_PARAM:     fprintf(stderr,"g_type: G_TYPE_PARAM\n"); break;
  //  case G_TYPE_OBJECT:    fprintf(stderr,"g_type: G_TYPE_OBJECT\n"); break;
  //  case G_TYPE_VARIANT:   fprintf(stderr,"g_type: G_TYPE_VARIANT\n"); break;
  //  default:
  //    {/*{{{*/
  //      if (g_type == GTK_TYPE_WIDGET)
  //      {
  //        fprintf(stderr,"g_type: GTK_TYPE_WIDGET\n"); break;
  //      }
  //    }/*}}}*/
  //  }
  //}/*}}}*/

  switch (g_type)
  {
  case G_TYPE_CHAR:
  case G_TYPE_UCHAR:
    return location_ptr->v_type == c_bi_class_char;
  case G_TYPE_BOOLEAN:
  case G_TYPE_INT:
  case G_TYPE_UINT:
  case G_TYPE_LONG:
  case G_TYPE_ULONG:
  case G_TYPE_INT64:
  case G_TYPE_UINT64:
  case G_TYPE_ENUM:
  case G_TYPE_FLAGS:
    return location_ptr->v_type == c_bi_class_integer;
  case G_TYPE_FLOAT:
  case G_TYPE_DOUBLE:
    return location_ptr->v_type == c_bi_class_float;
  case G_TYPE_STRING:
    return location_ptr->v_type == c_bi_class_string;
  case G_TYPE_OBJECT:
    return location_ptr->v_type == c_bi_class_gtk_g_object;
  default:
    {/*{{{*/
      if (g_type == GTK_TYPE_WIDGET)
      {
        return location_ptr->v_type == c_bi_class_gtk_g_object;
      }

      return false;
    }/*}}}*/
  }
}/*}}}*/

GValue *gtk_c::create_g_value(interpreter_thread_s &it,location_s *location_ptr,GValue *g_value)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_gtk_g_object)
  {/*{{{*/
    gpointer g_obj = (gpointer)location_ptr->v_data_ptr;

    g_value_init(g_value,G_TYPE_OBJECT);
    g_value_set_object(g_value,G_OBJECT(g_obj));

    return g_value;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_char:
      g_value_init(g_value,G_TYPE_CHAR);
      g_value_set_schar(g_value,(char)location_ptr->v_data_ptr);
      return g_value;
    case c_bi_class_integer:
      g_value_init(g_value,G_TYPE_INT64);
      g_value_set_int64(g_value,(long long int)location_ptr->v_data_ptr);
      return g_value;
    case c_bi_class_float:
      g_value_init(g_value,G_TYPE_DOUBLE);
      g_value_set_double(g_value,(double)location_ptr->v_data_ptr);
      return g_value;
    case c_bi_class_string:
      {/*{{{*/
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

        g_value_init(g_value,G_TYPE_STRING);
        g_value_set_string(g_value,string_ptr->data);

        return g_value;
      }/*}}}*/

    // - ERROR -
    default:
      return NULL;
    }
  }
}/*}}}*/

location_s *gtk_c::g_value_value(interpreter_thread_s &it,GType g_type,GValue *g_value)
{/*{{{*/
  switch (g_type)
  {
  case G_TYPE_INVALID:
  case G_TYPE_INTERFACE:
    return NULL;
  case G_TYPE_NONE:
    {/*{{{*/
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
      return (location_s *)it.blank_location;
    }/*}}}*/
  case G_TYPE_CHAR:
  case G_TYPE_UCHAR:
    {/*{{{*/
      char value;

      switch (g_type)
      {
      case G_TYPE_CHAR:
        value = g_value_get_schar(g_value);
        break;
      case G_TYPE_UCHAR:
        value = g_value_get_uchar(g_value);
        break;
      default:
        cassert(0);
      }

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_char,value);
      return new_location;
    }/*}}}*/
  case G_TYPE_BOOLEAN:
  case G_TYPE_INT:
  case G_TYPE_UINT:
  case G_TYPE_LONG:
  case G_TYPE_ULONG:
  case G_TYPE_INT64:
  case G_TYPE_UINT64:
  case G_TYPE_ENUM:
  case G_TYPE_FLAGS:
    {/*{{{*/
      long long int value;

      switch (g_type)
      {
      case G_TYPE_BOOLEAN:
        value = g_value_get_boolean(g_value);
        break;
      case G_TYPE_INT:
        value = g_value_get_int(g_value);
        break;
      case G_TYPE_UINT:
        value = g_value_get_uint(g_value);
        break;
      case G_TYPE_LONG:
        value = g_value_get_long(g_value);
        break;
      case G_TYPE_ULONG:
        value = g_value_get_ulong(g_value);
        break;
      case G_TYPE_INT64:
        value = g_value_get_int64(g_value);
        break;
      case G_TYPE_UINT64:
        value = g_value_get_uint64(g_value);
        break;
      case G_TYPE_ENUM:
        value = g_value_get_enum(g_value);
        break;
      case G_TYPE_FLAGS:
        value = g_value_get_flags(g_value);
        break;
      default:
        cassert(0);
      }

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
      return new_location;
    }/*}}}*/
  case G_TYPE_FLOAT:
  case G_TYPE_DOUBLE:
    {/*{{{*/
      double value;

      switch (g_type)
      {
      case G_TYPE_FLOAT:
        value = g_value_get_float(g_value);
        break;
      case G_TYPE_DOUBLE:
        value = g_value_get_double(g_value);
        break;
      default:
        cassert(0);
      }

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
      return new_location;
    }/*}}}*/
  case G_TYPE_STRING:
    {/*{{{*/
      const gchar *string = g_value_get_string(g_value);

      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(strlen(string),string);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
      return new_location;
    }/*}}}*/
  case G_TYPE_POINTER:
  case G_TYPE_BOXED:
  case G_TYPE_PARAM:
    return NULL;
  case G_TYPE_OBJECT:
    {/*{{{*/
      gpointer g_obj = g_value_get_object(g_value);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gtk_g_object,g_obj);
      return new_location;
    }/*}}}*/
  case G_TYPE_VARIANT:

  // - ERROR -
  default:
    return NULL;
  }
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

