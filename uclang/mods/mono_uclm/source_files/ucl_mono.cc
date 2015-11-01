
@begin
include "ucl_mono.h"
@end

/*
 * static members of class mono_c
 */

MonoDomain *mono_c::domain;
MonoAssembly *mono_c::assembly;
MonoImage *mono_c::image;

MonoClass *mono_c::array_class;

MonoMethod *mono_c::list_constr;
MonoMethod *mono_c::list_add;

MonoMethod *mono_c::dict_constr;
MonoMethod *mono_c::dict_add;

// - mono global init object -
mono_c g_mono;

/*
 * methods of class mono_c
 */

MonoObject *mono_c::create_mono_object(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_mono_object)
  {
    return mono_gchandle_get_target((guint32)location_ptr->v_data_ptr);
  }
  else if (location_ptr->v_type == c_bi_class_mono_property)
  {/*{{{*/
    mono_property_s *mp_ptr = (mono_property_s *)location_ptr->v_data_ptr;

    MonoObject *mono_exc;
    MonoObject *mono_result = mono_property_get_value(mp_ptr->mono_prop,
      mono_gchandle_get_target(mp_ptr->gchandle),
      NULL,&mono_exc);

    // - ERROR -
    if (mono_exc)
    {
      // FIXME TODO forward exception
      cassert(0);
    }

    return mono_result;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/

    // - create new dictionary -
    MonoObject *mono_exc;
    MonoObject *mono_obj = mono_runtime_invoke(dict_constr,NULL,NULL,&mono_exc);

    // - ERROR -
    if (mono_exc)
    {
      // FIXME TODO forward exception
      cassert(0);
    }

    // FIXME TODO fill dictionary with items

    return mono_obj;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      {
        return NULL;
      }
    case c_bi_class_char:
      {
        return NULL;
      }
    case c_bi_class_integer:
      {
        long long int value = (long long int)location_ptr->v_data_ptr;
        return mono_value_box(domain,mono_get_int64_class(),&value);
      }
    case c_bi_class_float:
      {
        double value = *((double *)&location_ptr->v_data_ptr);
        return mono_value_box(domain,mono_get_double_class(),&value);
      }
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        return (MonoObject *)mono_string_new_len(domain,string_ptr->data,string_ptr->size - 1);
      }
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

        // - create new list -
        MonoObject *mono_exc;
        MonoObject *mono_list = mono_runtime_invoke(list_constr,NULL,NULL,&mono_exc);
        
        // - ERROR -
        if (mono_exc)
        {
          // FIXME TODO forward exception
          cassert(0);
        }

        if (array_ptr->used > 0)
        {
          pointer *ptr = array_ptr->data;
          pointer *ptr_end = ptr + array_ptr->used;
          do {
            MonoObject *mono_item = create_mono_object(it,it.get_location_value(*ptr));

            // - ERROR -
            if (mono_item == NULL)
            {
              return NULL;
            }

            mono_runtime_invoke(list_add,mono_list,(void **)&mono_item,&mono_exc);

            // - ERROR -
            if (mono_exc)
            {
              // FIXME TODO forward exception
              cassert(0);
            }

          } while(++ptr < ptr_end);
        }

        return mono_list;
      }/*}}}*/

    // - ERROR -
    default:
      return NULL;
    }
  }
}/*}}}*/

MonoObject *mono_c::create_mono_array(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_mono_object)
  {
    MonoObject *mono_obj = mono_gchandle_get_target((guint32)location_ptr->v_data_ptr);

    // - object is already mono array -
    if (mono_object_get_class(mono_obj) == mono_c::array_class)
    {
      return mono_obj;
    }
  }

  // - convert array to mono array -
  if (location_ptr->v_type == c_bi_class_array)
  {
    pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

    // - create new array -
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),array_ptr->used);

    if (array_ptr->used > 0)
    {
      unsigned idx = 0;
      do {
        MonoObject *mono_item = create_mono_object(it,it.get_location_value(array_ptr->data[idx]));

        // - ERROR -
        if (mono_item == NULL)
        {
          return NULL;
        }

        // - set mono array item -
        mono_array_set(mono_array,MonoObject *,idx,mono_item);

      } while(++idx < array_ptr->used);
    }

    return (MonoObject *)mono_array;
  }

  // - convert single object to mono array -
  else
  {
    // - create new array -
    MonoArray *mono_array = mono_array_new(domain,mono_get_object_class(),1);
    MonoObject *mono_item = create_mono_object(it,location_ptr);

    // - ERROR -
    if (mono_item == NULL)
    {
      return NULL;
    }

    // - set mono array item -
    mono_array_set(mono_array,MonoObject *,0,mono_item);

    return (MonoObject *)mono_array;
  }
}/*}}}*/

location_s *mono_c::mono_object_value(interpreter_thread_s &it,MonoObject *mono_obj,uli source_pos)
{/*{{{*/
  MonoClass *mono_class = mono_object_get_class(mono_obj);

#define MONO_OBJECT_UNBOX_INTEGER(TYPE) \
{/*{{{*/\
  long long value = *((TYPE *)mono_object_unbox(mono_obj));\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
  return new_location;\
}/*}}}*/

  if (mono_class == mono_get_int32_class())
  {
    MONO_OBJECT_UNBOX_INTEGER(int)
  }
  if (mono_class == mono_get_int64_class())
  {
    MONO_OBJECT_UNBOX_INTEGER(long long)
  }

#define MONO_OBJECT_UNBOX_FLOAT(TYPE) \
{/*{{{*/\
  double value = *((TYPE *)mono_object_unbox(mono_obj));\
\
  basic_64b &v_data_ptr = *((basic_64b *)&value);\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,v_data_ptr);\
  return new_location;\
}/*}}}*/

  if (mono_class == mono_get_single_class())
  {
    MONO_OBJECT_UNBOX_FLOAT(float);
  }
  if (mono_class == mono_get_double_class())
  {
    MONO_OBJECT_UNBOX_FLOAT(double);
  }
  if (mono_class == mono_get_string_class())
  {/*{{{*/
    MonoError error;
    char *utf8_str = mono_string_to_utf8_checked((MonoString *)mono_obj,&error);

    // - ERROR -
    if (!mono_error_ok(&error))
    {
      return NULL;
    }

    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(utf8_str),utf8_str);
    mono_free(utf8_str);
    
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    return new_location;
  }/*}}}*/

  return NULL;
}/*}}}*/

