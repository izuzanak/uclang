
#ifndef __UCL_GL_H
#define __UCL_GL_H

@begin
include "script_parser.h"
@end

#define GLM_FORCE_RADIANS

#if defined(LINUX) || defined(ANDROID) || defined(NACL) || defined(EMSCRIPTEN)
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

#define GL_GLEXT_PROTOTYPES

#if defined(UCBOX_IMX6) || defined(ANDROID) || defined(NACL) || defined(EMSCRIPTEN)
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#elif defined(LINUX)
#include <GL/gl.h>
#include <GL/glext.h>
#endif

/*
 * definition of structure gl_attribute_s
 */

struct gl_attribute_s
{
  location_s *program_ptr;
  location_s *name_ptr;
  GLuint index;
  GLint size;
  GLenum type;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure gl_uniform_s
 */

struct gl_uniform_s
{
  location_s *program_ptr;
  location_s *name_ptr;
  GLuint index;
  GLint size;
  GLenum type;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure gl_texture_s
 */

struct gl_texture_s
{
  GLuint index;
  unsigned format;
  unsigned pixel_size;
  unsigned width;
  unsigned height;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class gl_c
 */
class gl_c
{
  public:
  inline gl_c();
  inline ~gl_c();
};

/*
 * inline methods of structure gl_attribute_s
 */

inline void gl_attribute_s::init()
{/*{{{*/
  program_ptr = nullptr;
  name_ptr = nullptr;
  index = 0;
  size = 0;
  type = GL_NONE;
}/*}}}*/

inline void gl_attribute_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release name pointer -
  if (program_ptr != nullptr)
  {
    it.release_location_ptr(program_ptr);
  }

  // - release name pointer -
  if (name_ptr != nullptr)
  {
    it.release_location_ptr(name_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure gl_uniform_s
 */

inline void gl_uniform_s::init()
{/*{{{*/
  program_ptr = nullptr;
  name_ptr = nullptr;
  index = 0;
  size = 0;
  type = GL_NONE;
}/*}}}*/

inline void gl_uniform_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release name pointer -
  if (program_ptr != nullptr)
  {
    it.release_location_ptr(program_ptr);
  }

  // - release name pointer -
  if (name_ptr != nullptr)
  {
    it.release_location_ptr(name_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure gl_texture_s
 */

inline void gl_texture_s::init()
{/*{{{*/
  index = 0;
}/*}}}*/

inline void gl_texture_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - relese gl textures -
  if (index != 0)
  {
    glDeleteTextures(1,&index);
  }

  init();
}/*}}}*/

/*
 * inline methods of class gl_c
 */

inline gl_c::gl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gl_init()\n"););
}/*}}}*/

inline gl_c::~gl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gl_exit()\n"););
}/*}}}*/

#endif

