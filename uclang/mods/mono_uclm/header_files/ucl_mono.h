
#ifndef __UCL_MONO_H
#define __UCL_MONO_H

@begin
include "script_parser.h"
@end

#ifdef __cplusplus
  extern "C" {
#endif

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

#ifdef __cplusplus
  }
#endif

/*
 * definition of class mono_c
 */
class mono_c
{
  public:
  static MonoDomain *domain;

  public:
  inline mono_c();
  inline ~mono_c();
};

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

