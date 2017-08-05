
#ifndef __UCL_GLUT_H
#define __UCL_GLUT_H

@begin
include "script_parser.h"
@end

#if defined(LINUX)
#include <GL/freeglut.h>
#endif

/*
 * definition of structure glut_s
 */

struct glut_s
{
  static glut_s *glut_ptr;
  static interpreter_thread_s *it_ptr;
  static int window;
  static bool main_loop;
  static unsigned main_source_pos;
  static unsigned main_ret_code;

  location_s *display_dlg;
  location_s *reshape_dlg;
  location_s *keyboard_dlg;
  location_s *mouse_dlg;
  location_s *motion_dlg;
  location_s *passive_motion_dlg;
  location_s *visibility_dlg;
  location_s *entry_dlg;
  location_s *special_dlg;
  location_s *idle_dlg;
  location_s *timer_dlg;

  inline void init();
  static inline void init_static();
  inline void clear(interpreter_thread_s &it);

  static void display_func();
  static void reshape_func(int width,int height);
  static void keyboard_func(unsigned char key,int x,int y);
  static void mouse_func(int butt,int state,int x,int y);
  static void motion_func(int x,int y);
  static void passive_motion_func(int x,int y);
  static void visibility_func(int state);
  static void entry_func(int state);
  static void special_func(int key,int x,int y);
  static void idle_func();
  static void timer_func(int value);
};

/*
 * definition of class glut_c
 */
class glut_c
{
  public:
  inline glut_c();
  inline ~glut_c();
};

/*
 * inline methods of structure glut_s
 */

inline void glut_s::init()
{/*{{{*/
  display_dlg = nullptr;
  reshape_dlg = nullptr;
  keyboard_dlg = nullptr;
  mouse_dlg = nullptr;
  motion_dlg = nullptr;
  passive_motion_dlg = nullptr;
  visibility_dlg = nullptr;
  entry_dlg = nullptr;
  special_dlg = nullptr;
  idle_dlg = nullptr;
  timer_dlg = nullptr;
}/*}}}*/

inline void glut_s::init_static()
{/*{{{*/
  glut_s::glut_ptr = nullptr;
  glut_s::it_ptr = nullptr;
  glut_s::window = 0;
  glut_s::main_loop = false;
  glut_s::main_source_pos = 0;
  glut_s::main_ret_code = c_run_return_code_OK;
}/*}}}*/

inline void glut_s::clear(interpreter_thread_s &it)
{/*{{{*/

#define GLUT_STATE_RELEASE_DELEGATE(NAME) \
{/*{{{*/\
  if (NAME != nullptr)\
  {\
    it.release_location_ptr(NAME);\
  }\
}/*}}}*/

  GLUT_STATE_RELEASE_DELEGATE(display_dlg);
  GLUT_STATE_RELEASE_DELEGATE(reshape_dlg);
  GLUT_STATE_RELEASE_DELEGATE(keyboard_dlg);
  GLUT_STATE_RELEASE_DELEGATE(mouse_dlg);
  GLUT_STATE_RELEASE_DELEGATE(motion_dlg);
  GLUT_STATE_RELEASE_DELEGATE(passive_motion_dlg);
  GLUT_STATE_RELEASE_DELEGATE(visibility_dlg);
  GLUT_STATE_RELEASE_DELEGATE(entry_dlg);
  GLUT_STATE_RELEASE_DELEGATE(special_dlg);
  GLUT_STATE_RELEASE_DELEGATE(idle_dlg);
  GLUT_STATE_RELEASE_DELEGATE(timer_dlg);

  init();
}/*}}}*/

/*
 * inline methods of class glut_c
 */

inline glut_c::glut_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"glut_init()\n"););

  glut_s::init_static();
}/*}}}*/

inline glut_c::~glut_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"glut_exit()\n"););
}/*}}}*/

#endif

