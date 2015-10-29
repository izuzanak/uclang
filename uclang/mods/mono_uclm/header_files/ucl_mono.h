
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
 * definition of structure mono_object_s
 */

struct mono_object_s
{
  MonoObject *obj;
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

  public:
  inline mono_c();
  inline ~mono_c();
};

/*
 * inline methods of structure mono_object_s
 */

inline void mono_object_s::init()
{/*{{{*/
  obj = NULL;
  gchandle = 0;
}/*}}}*/

inline void mono_object_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (obj != NULL)
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

