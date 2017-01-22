
@begin
include "gtk_module.h"
@end

// - static members of class gtk_c -
GQuark gtk_c::dlg_idxs_quark;
GQuark gtk_c::bi_class_quark;

GType gtk_c::gtk_type_min;
GType gtk_c::gtk_type_max;

unsigned gtk_c::gtk_obj_class_first;
unsigned gtk_c::gtk_obj_class_last;

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

  // - query signal info -
  GSignalQuery signal_info;
  g_signal_query(delegate.signal_id,&signal_info);

  // - callback parameters -
  const unsigned param_cnt = signal_info.n_params + 2;
  pointer param_data[param_cnt];
  pointer *param_ptr = param_data;

  // - set object location -
  *param_ptr++ = delegate.object_loc;

  if (signal_info.n_params > 0)
  {
    va_list vlist;
    va_start(vlist,delegate_idx);

#define GTK_C_CALLBACK_HANDLER_OBJECT_PARAMETER(CLASS) \
{/*{{{*/\
  gpointer g_obj = va_arg(vlist,gpointer);\
  if (g_obj == NULL)\
  {\
    *param_ptr++ = it.blank_location;\
    continue;\
  }\
\
  g_object_ref(g_obj);\
  BIC_CREATE_NEW_LOCATION_REFS(new_location,CLASS,g_obj,0);\
  *param_ptr++ = new_location;\
  continue;\
}/*}}}*/

    // - create parameter locations -
    const GType *pt_ptr = signal_info.param_types;
    const GType *pt_ptr_end = pt_ptr + signal_info.n_params;
    do {
      GType pg_type = *pt_ptr;

      switch (pg_type)
      {
      case G_TYPE_OBJECT:
        GTK_C_CALLBACK_HANDLER_OBJECT_PARAMETER(c_bi_class_gtk_g_object)

      // - ERROR -
      default:
        {
          // - retrieve type identification -
          int type_id = (int)g_type_get_qdata(pg_type,gtk_c::bi_class_quark);
          
          switch (type_id)
          {

          // - process basic types -
          case c_type_ui:
            {
              long long int value = va_arg(vlist,unsigned);
              BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_integer,value,0);
              *param_ptr++ = new_location;
              continue;
            }
          }

          // - process known objects -
          if (type_id >= (int)gtk_c::gtk_obj_class_first &&
              type_id <= (int)gtk_c::gtk_obj_class_last)
          {
            GTK_C_CALLBACK_HANDLER_OBJECT_PARAMETER(type_id);
          }

          // - unknown parameter type -
          *param_ptr++ = it.blank_location;
        }
      }
    } while(++pt_ptr < pt_ptr_end);

    va_end(vlist);
  }

  // - set data location -
  *param_ptr++ = delegate.data_loc;

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
      if (g_type >= gtk_c::gtk_type_min && g_type <= gtk_c::gtk_type_max)
      {
        // - retrieve type identification -
        int type_id = (int)g_type_get_qdata(g_type,gtk_c::bi_class_quark);

        // - process known objects -
        if (type_id >= (int)gtk_c::gtk_obj_class_first &&
            type_id <= (int)gtk_c::gtk_obj_class_last)
        {
          return location_ptr->v_type == (unsigned)type_id;
        }
      }

      return false;
    }/*}}}*/
  }
}/*}}}*/

gpointer gtk_c::create_g_object(interpreter_thread_s &it,GType g_type,pointer_array_s *array_ptr,unsigned source_pos)
{/*{{{*/

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_WRONG_ARRAY_SIZE,source_pos,(location_s *)it.blank_location);
    new_exception->params.push(0);

    return NULL;
  }

  guint param_cnt = array_ptr->used >> 1;
  GParameter params[param_cnt] = {0};

#define BIC_GTK_CREATE_G_OBJECT_RELEASE_PARAMS() \
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
        BIC_GTK_CREATE_G_OBJECT_RELEASE_PARAMS();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_EXPECTED_STRING,source_pos,(location_s *)it.blank_location);
        new_exception->params.push(0);
        new_exception->params.push(p_ptr - params);

        return NULL;
      }

      string_s *string_ptr = (string_s *)name_location->v_data_ptr;
      p_ptr->name = string_ptr->data;

      // - ERROR -
      if (!gtk_c::create_g_value(it,value_location,&p_ptr->value))
      {
        BIC_GTK_CREATE_G_OBJECT_RELEASE_PARAMS();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_G_VALUE_CREATE_ERROR,source_pos,(location_s *)it.blank_location);
        new_exception->params.push(p_ptr - params);

        return NULL;
      }

    } while((a_ptr += 2),++p_ptr < p_ptr_end);
  }

  // - create new g_object -
  gpointer g_obj = g_object_newv(g_type,param_cnt,params);

  // - ERROR -
  if (!g_obj)
  {
    BIC_GTK_CREATE_G_OBJECT_RELEASE_PARAMS();

    exception_s::throw_exception(it,module.error_base + c_error_GTK_G_OBJECT_CREATE_ERROR,source_pos,(location_s *)it.blank_location);
    return NULL;
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

  BIC_GTK_CREATE_G_OBJECT_RELEASE_PARAMS();

  return g_obj;
}/*}}}*/

GValue *gtk_c::create_g_value(interpreter_thread_s &it,location_s *location_ptr,GValue *g_value)
{/*{{{*/
  if (location_ptr->v_type >= c_bi_class_gtk_g_object &&
      location_ptr->v_type <= gtk_c::gtk_obj_class_last)
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
      if (g_type >= gtk_c::gtk_type_min && g_type <= gtk_c::gtk_type_max)
      {
        // - retrieve type identification -
        int type_id = (int)g_type_get_qdata(g_type,gtk_c::bi_class_quark);

        // - process known objects -
        if (type_id >= (int)gtk_c::gtk_obj_class_first &&
            type_id <= (int)gtk_c::gtk_obj_class_last)
        {
          gpointer g_obj = g_value_get_object(g_value);

          if (g_obj == NULL)
            return (location_s *)it.blank_location;

          g_object_ref(g_obj);
          BIC_CREATE_NEW_LOCATION(new_location,type_id,g_obj);
          return new_location;
        }
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

