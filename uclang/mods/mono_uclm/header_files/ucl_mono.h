
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

  static MonoMethod *dict_unwrap;

  static MonoMethod *list_to_array;
  static MonoMethod *stack_to_array;
  static MonoMethod *queue_to_array;

  static MonoMethod *dict_add;

  public:

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
 * inline methods of class mono_c
 */

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

