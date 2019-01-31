
#ifndef __UCL_VA_H
#define __UCL_VA_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <va/va_x11.h>

/*
 * definition of structure va_display_s
 */

struct va_display_s
{
  Display *x11_display_ptr;
  VADisplay display_ptr;
  int major_version;
  int minor_version;

  static void error_callback(void *user_context,const char *message);
  static void info_callback(void *user_context,const char *message);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure va_display_s
 */

inline void va_display_s::init()
{/*{{{*/
  x11_display_ptr = nullptr;
  display_ptr = nullptr;
}/*}}}*/

inline void va_display_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (display_ptr != nullptr)
  {
    // - reset error message callback -
    vaSetErrorCallback(display_ptr,nullptr,nullptr);

    // - reset info message callback -
    vaSetInfoCallback(display_ptr,nullptr,nullptr);

    vaTerminate(display_ptr);
  }

  if (x11_display_ptr != nullptr)
  {
    XCloseDisplay(x11_display_ptr);
  }

  init();
}/*}}}*/

#endif

