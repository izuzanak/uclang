
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
extern unsigned c_rm_class_dict;

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
  static MonoDomain *domain;
  static MonoAssembly *assembly;
  static MonoImage *image;

  static MonoClass *array_class;

  static MonoMethod *list_constr;
  static MonoMethod *list_add;

  static MonoMethod *dict_constr;
  static MonoMethod *dict_add;

  public:
  inline mono_c();
  inline ~mono_c();
  
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

inline mono_c::mono_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"mono_init()\n"););

  // - initialize mono domain -
  domain = mono_jit_init("uclang");
}/*}}}*/

inline mono_c::~mono_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"mono_exit()\n"););
}/*}}}*/

#endif

