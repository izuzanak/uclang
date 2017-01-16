
@begin
include "ucl_gtk.h"
@end

// - static members of class gtk_c -
GQuark gtk_c::dlg_idxs_quark;

interpreter_thread_s *gtk_c::it_ptr;
gtk_delegate_list_s gtk_c::delegates;

bool gtk_c::main_loop;
unsigned gtk_c::main_source_pos;
unsigned gtk_c::main_ret_code;

// - gtk global init object -
gtk_c g_gtk;

/*
 * methods of class gtk_c
 */

void gtk_c::dlg_data_release(gpointer delegate_data)
{/*{{{*/

  // - retrieve object delegate indexes -
  ui_list_s *obj_dlg_idxs = (ui_list_s *)delegate_data;
  debug_assert(obj_dlg_idxs != NULL);

  if (obj_dlg_idxs->first_idx != c_idx_not_exist)
  {
    unsigned idx = obj_dlg_idxs->first_idx;
    do {
      unsigned delegate_idx = obj_dlg_idxs->data[idx].object;
      gtk_delegate_s &delegate = gtk_c::delegates[delegate_idx];

      // - release delegate location -
      gtk_c::it_ptr->release_location_ptr((location_s *)delegate.delegate_loc);

      // - release data location -
      gtk_c::it_ptr->release_location_ptr((location_s *)delegate.data_loc);
      
      // - remove delegate from delegates list -
      gtk_c::delegates.remove(delegate_idx);

      idx = obj_dlg_idxs->next_idx(idx);
    } while(idx != c_idx_not_exist);
  }

  obj_dlg_idxs->clear();
  cfree(obj_dlg_idxs);
}/*}}}*/

void gtk_c::callback_handler(gpointer delegate_idx,...)
{/*{{{*/
  gtk_delegate_s &delegate = gtk_c::delegates[(unsigned)delegate_idx];

  // - retrieve interpreter thread reference -
  interpreter_thread_s &it = *gtk_c::it_ptr;

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr =
    (delegate_s *)((location_s *)delegate.delegate_loc)->v_data_ptr;

  // - callback parameters -
  const unsigned param_cnt = 2;
  pointer param_data[param_cnt] = {
    delegate.object_loc,delegate.data_loc};

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

void gtk_c::g_type_print(GType g_type)
{/*{{{*/
  switch (g_type)
  {
  case G_TYPE_INVALID:   fprintf(stderr,"g_type: G_TYPE_INVALID\n"); break;
  case G_TYPE_NONE:      fprintf(stderr,"g_type: G_TYPE_NONE\n"); break;
  case G_TYPE_INTERFACE: fprintf(stderr,"g_type: G_TYPE_INTERFACE\n"); break;
  case G_TYPE_CHAR:      fprintf(stderr,"g_type: G_TYPE_CHAR\n"); break;
  case G_TYPE_UCHAR:     fprintf(stderr,"g_type: G_TYPE_UCHAR\n"); break;
  case G_TYPE_BOOLEAN:   fprintf(stderr,"g_type: G_TYPE_BOOLEAN\n"); break;
  case G_TYPE_INT:       fprintf(stderr,"g_type: G_TYPE_INT\n"); break;
  case G_TYPE_UINT:      fprintf(stderr,"g_type: G_TYPE_UINT\n"); break;
  case G_TYPE_LONG:      fprintf(stderr,"g_type: G_TYPE_LONG\n"); break;
  case G_TYPE_ULONG:     fprintf(stderr,"g_type: G_TYPE_ULONG\n"); break;
  case G_TYPE_INT64:     fprintf(stderr,"g_type: G_TYPE_INT64\n"); break;
  case G_TYPE_UINT64:    fprintf(stderr,"g_type: G_TYPE_UINT64\n"); break;
  case G_TYPE_ENUM:      fprintf(stderr,"g_type: G_TYPE_ENUM\n"); break;
  case G_TYPE_FLAGS:     fprintf(stderr,"g_type: G_TYPE_FLAGS\n"); break;
  case G_TYPE_FLOAT:     fprintf(stderr,"g_type: G_TYPE_FLOAT\n"); break;
  case G_TYPE_DOUBLE:    fprintf(stderr,"g_type: G_TYPE_DOUBLE\n"); break;
  case G_TYPE_STRING:    fprintf(stderr,"g_type: G_TYPE_STRING\n"); break;
  case G_TYPE_POINTER:   fprintf(stderr,"g_type: G_TYPE_POINTER\n"); break;
  case G_TYPE_BOXED:     fprintf(stderr,"g_type: G_TYPE_BOXED\n"); break;
  case G_TYPE_PARAM:     fprintf(stderr,"g_type: G_TYPE_PARAM\n"); break;
  case G_TYPE_OBJECT:    fprintf(stderr,"g_type: G_TYPE_OBJECT\n"); break;
  case G_TYPE_VARIANT:   fprintf(stderr,"g_type: G_TYPE_VARIANT\n"); break;
  default:
    {/*{{{*/
      if (g_type == GTK_TYPE_WIDGET)
      {
        fprintf(stderr,"g_type: GTK_TYPE_WIDGET\n"); break;
      }
      else
      {
        fprintf(stderr,"g_type: UNKNOWN\n"); break;
      }
    }/*}}}*/
  }
}/*}}}*/

bool gtk_c::g_type_check(location_s *location_ptr,GType g_type)
{/*{{{*/
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

      if (g_obj == NULL)
        return (location_s *)it.blank_location;

      g_object_ref(g_obj);
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gtk_g_object,g_obj);
      return new_location;
    }/*}}}*/
  case G_TYPE_VARIANT:

  // - ERROR -
  default:
    {/*{{{*/
      if (g_type == GTK_TYPE_WIDGET)
      {
        gpointer g_obj = g_value_get_object(g_value);

        if (g_obj == NULL)
          return (location_s *)it.blank_location;

        g_object_ref(g_obj);
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gtk_g_object,g_obj);
        return new_location;
      }

      return NULL;
    }/*}}}*/
  }
}/*}}}*/

/*
 * methods of generated structures
 */

// -- ui_list_s --
@begin
methods ui_list_s
@end

// -- gtk_delegate_s --
@begin
methods gtk_delegate_s
@end

// -- gtk_delegate_list_s --
@begin
methods gtk_delegate_list_s
@end

