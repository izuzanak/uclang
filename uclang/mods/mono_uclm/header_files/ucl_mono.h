
#ifndef __UCL_MONO_H
#define __UCL_MONO_H

@begin
include "script_parser.h"
@end

#ifdef __cplusplus
  extern "C" {
#endif

#include <glib.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

#ifdef __cplusplus
  }
#endif

/*
 * constants and definitions
 */

extern unsigned c_bi_class_mono_object;
extern unsigned c_bi_class_mono_property;
extern unsigned c_bi_class_mono_item_ref;
extern unsigned c_rm_class_stack;
extern unsigned c_rm_class_queue;
extern unsigned c_rm_class_set;
extern unsigned c_rm_class_list;
extern unsigned c_rm_class_dict;

#define BIC_MONO_CHECK_EXCEPTION(CODE) \
{/*{{{*/\
  if (mono_exc)\
  {\
    CODE;\
    \
    mono_print_unhandled_exception(mono_exc);\
    \
    /* FIXME TODO forward exception */\
    cassert(0);\
  }\
}/*}}}*/\

// - max method name length -
const unsigned c_max_method_name_length = 256;

/*
 * definition of structure mono_property_s
 */

struct mono_property_s
{
  MonoProperty *mono_prop;
  guint32 gchandle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure mono_reference_s
 */

struct mono_reference_s
{
  guint32 gchnd_obj;
  guint32 gchnd_key;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline MonoObject *get_item();
  inline bool set_item(MonoObject *mono_value);
};

/*
 * definition of class mono_c
 */
class mono_c
{
  public:
  static location_s *assembly_loc;
  static bool assembly_opened;

  public:
  static MonoDomain *domain;
  static MonoAssembly *assembly;
  static MonoImage *image;

  static MonoClass *array_class;
  static MonoClass *list_class;
  static MonoClass *stack_class;
  static MonoClass *queue_class;
  static MonoClass *hset_class;
  static MonoClass *llist_class;
  static MonoClass *dict_class;

  static MonoMethod *list_constr;
  static MonoMethod *stack_constr;
  static MonoMethod *queue_constr;
  static MonoMethod *hset_constr;
  static MonoMethod *llist_constr;
  static MonoMethod *dict_constr;

  static MonoMethod *hset_arr;
  static MonoMethod *llist_arr;
  static MonoMethod *dict_arr;

  static MonoMethod *list_to_array;
  static MonoMethod *stack_to_array;
  static MonoMethod *queue_to_array;

  static MonoMethod *dict_add;

  static MonoProperty *list_item;
  static MonoProperty *dict_item;

  public:

  static inline bool int_value(MonoObject *mono_obj,int &result);

  static inline void assembly_ref_inc();
  static inline void assembly_ref_dec(interpreter_thread_s &it);

  static inline guint32 gchandle_new(MonoObject *mono_obj);
  static inline void gchandle_free(interpreter_thread_s &it,guint32 gchandle);

  static MonoObject *create_mono_object(interpreter_thread_s &it,location_s *location_ptr);
  static MonoObject *create_mono_array(interpreter_thread_s &it,location_s *location_ptr);
  static location_s *mono_object_value(interpreter_thread_s &it,MonoObject *mono_obj,uli source_pos);
};

/*
 * inline methods of structure mono_property_s
 */

inline void mono_property_s::init()
{/*{{{*/
  mono_prop = NULL;
  gchandle = 0;
}/*}}}*/

inline void mono_property_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (gchandle != 0)
  {
    mono_gchandle_free(gchandle);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure mono_reference_s
 */

inline void mono_reference_s::init()
{/*{{{*/
  gchnd_obj = 0;
  gchnd_key = 0;
}/*}}}*/

inline void mono_reference_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (gchnd_obj != 0)
  {
    mono_gchandle_free(gchnd_obj);
  }

  if (gchnd_key != 0)
  {
    mono_gchandle_free(gchnd_key);
  }

  init();
}/*}}}*/

inline MonoObject *mono_reference_s::get_item()
{/*{{{*/
  MonoObject *mono_obj = mono_gchandle_get_target(gchnd_obj);
  MonoObject *mono_key = mono_gchandle_get_target(gchnd_key);
  MonoClass *mono_class = mono_object_get_class(mono_obj);
 
  // FIXME TODO continue ...

  if (mono_class == mono_c::list_class)
  {
    int idx;
    void *params[1] = {&idx};

    if (!mono_c::int_value(mono_key,idx))
    {
      return NULL;
    }

    MonoObject *mono_exc = NULL;
    MonoObject *mono_result = mono_property_get_value(mono_c::list_item,
        mono_obj,params,&mono_exc);

    BIC_MONO_CHECK_EXCEPTION();

    return mono_result;
  }
  if (mono_class == mono_c::dict_class)
  {
    MonoObject *mono_exc = NULL;
    MonoObject *mono_result = mono_property_get_value(mono_c::dict_item,
        mono_obj,(void **)&mono_key,&mono_exc);

    BIC_MONO_CHECK_EXCEPTION();

    return mono_result;
  }

  return NULL;
}/*}}}*/

inline bool mono_reference_s::set_item(MonoObject *mono_value)
{/*{{{*/
  MonoObject *mono_obj = mono_gchandle_get_target(gchnd_obj);
  MonoObject *mono_key = mono_gchandle_get_target(gchnd_key);
  MonoClass *mono_class = mono_object_get_class(mono_obj);

  // FIXME TODO continue ...

  if (mono_class == mono_c::list_class)
  {
    int idx;
    void *params[2] = {&idx,mono_value};

    if (!mono_c::int_value(mono_key,idx))
    {
      return false;
    }

    MonoObject *mono_exc = NULL;
    mono_property_set_value(mono_c::list_item,mono_obj,params,&mono_exc);

    BIC_MONO_CHECK_EXCEPTION();

    return true;
  }
  if (mono_class == mono_c::dict_class)
  {
    void *params[2] = {mono_key,mono_value};

    MonoObject *mono_exc = NULL;
    mono_property_set_value(mono_c::dict_item,mono_obj,params,&mono_exc);

    BIC_MONO_CHECK_EXCEPTION();

    return true;
  }

  return false;
}/*}}}*/

/*
 * inline methods of class mono_c
 */

inline bool mono_c::int_value(MonoObject *mono_obj,int &result)
{/*{{{*/
  MonoClass *mono_class = mono_object_get_class(mono_obj);

  if (mono_class == mono_get_int64_class())
  {
    result = *((int64_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_uint64_class())
  {
    result = *((uint64_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_int32_class())
  {
    result = *((int32_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_uint32_class())
  {
    result = *((uint32_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_int16_class())
  {
    result = *((int16_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_uint16_class())
  {
    result = *((uint16_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_sbyte_class())
  {
    result = *((int8_t *)mono_object_unbox(mono_obj));
    return true;
  }
  if (mono_class == mono_get_byte_class())
  {
    result = *((uint8_t *)mono_object_unbox(mono_obj));
    return true;
  }

  return false;
}/*}}}*/

inline void mono_c::assembly_ref_inc()
{/*{{{*/
  assembly_loc->v_reference_cnt.atomic_inc();
}/*}}}*/

inline void mono_c::assembly_ref_dec(interpreter_thread_s &it)
{/*{{{*/

  // - release mono assembly reference -
  it.release_location_ptr(assembly_loc);
}/*}}}*/

inline guint32 mono_c::gchandle_new(MonoObject *mono_obj)
{/*{{{*/

  // - increase mono assembly reference -
  assembly_loc->v_reference_cnt.atomic_inc();

  return mono_gchandle_new(mono_obj,TRUE);
}/*}}}*/

inline void mono_c::gchandle_free(interpreter_thread_s &it,guint32 gchandle)
{/*{{{*/
  mono_gchandle_free(gchandle);

  // - release mono assembly reference -
  it.release_location_ptr(assembly_loc);
}/*}}}*/

#endif

