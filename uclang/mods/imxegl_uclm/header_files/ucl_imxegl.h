
#ifndef __UCL_IMXEGL_H
#define __UCL_IMXEGL_H

@begin
include "script_parser.h"
include "ucl_gl.h"
@end

// - do not redefine linux -
//#define LINUX

// - select framebuffer egl api -
//#define EGL_API_FB

// - enable patched linux extensions -
#define IPUROT_LINUX

#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/mxcfb.h>
#include <linux/ipu.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <X11/X.h>
#include <X11/Xlib.h>

// - forward type declaration -
typedef struct imx_egl_s imx_egl_s;

// - shared global egl -
extern atomic_s global_egl_terminate;
extern mutex_s global_egl_mutex;
extern imx_egl_s *global_egl_ptr;

#if defined(IPUROT_LINUX)
// - maximal size of block processed by ipu rotation -
const unsigned c_max_rotate_size = 1024;

// - framebuffer properties structure -
struct framebuffer_props_s
{/*{{{*/
  unsigned long smem_start;
  unsigned long rot_smem_start;
  unsigned smem_len;
  unsigned stride;
  unsigned xres;
  unsigned yres;
  unsigned bits_per_pixel;

  unsigned bytes_per_pixel;
  unsigned pixels_per_stride;
  unsigned buffer_size;

  bool second_buffer;
};/*}}}*/

// - framebuffer properties function -
bool read_framebuffer_properties(int fd,struct framebuffer_props_s *props);
#endif

/*
 * definition of structure imx_egl_s
 */

struct imx_egl_s
{
  unsigned width;
  unsigned height;

  EGLDisplay display;
  EGLSurface surface;
  EGLContext context;

  pointer_array_s texture_ptrs;
  pointer_array_s texture_locs;

  EGLNativeDisplayType native_display;
  EGLNativeWindowType native_window;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

#if defined(IPUROT_LINUX)
/*
 * definition of structure imx_fb_s
 */

struct imx_fb_s
{
  int fd;
  framebuffer_props_s fb_props;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};
#endif

#if defined(IPUROT_LINUX)
/*
 * definition of structure imx_ipu_s
 */

struct imx_ipu_s
{
  int fd;
  location_s *fb_location;

  bool prepared;
  unsigned buffer_idx;

  struct ipu_task task_0;
  struct ipu_task task_1;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};
#endif

/*
 * definition of class imxegl_c
 */
class imxegl_c
{
  public:
  inline imxegl_c();
  inline ~imxegl_c();
};

/*
 * inline methods of structure imx_egl_s
 */

inline void imx_egl_s::init()
{/*{{{*/
  width = 0;
  height = 0;

  display = EGL_NO_DISPLAY;
  surface = EGL_NO_SURFACE;
  context = EGL_NO_CONTEXT;

  texture_ptrs.init();
  texture_locs.init();

  native_window = 0;
  native_display = nullptr;
}/*}}}*/

inline void imx_egl_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - if this is set as global egl -
  if (global_egl_ptr == this)
  {
    // - set global egl terminate -
    global_egl_terminate.atomic_set(1);

    // - reset global egl pointer -
    global_egl_mutex.lock();
    global_egl_ptr = nullptr;
    global_egl_mutex.unlock();
  }

  // - release texture locations -
  if (texture_locs.used != 0)
  {
    pointer *ptr = texture_locs.data;
    pointer *ptr_end = ptr + texture_locs.used;
    do {
      it.release_location_ptr((location_s *)*ptr);
    } while(++ptr < ptr_end);
  }

  texture_ptrs.clear();
  texture_locs.clear();

  // - if display was created -
  if (display != EGL_NO_DISPLAY)
  {
    // - destroy context -
    eglDestroyContext(display,context);

    // - dstroy surface  -
    eglDestroySurface(display,surface);

    // - terminate display -
    eglTerminate(display);

    // - destroy native window and display -
#if defined(EGL_API_FB)
    fbDestroyWindow(native_window);
    fbDestroyDisplay(native_display);
#else
    XDestroyWindow(native_display,native_window);
    XCloseDisplay(native_display);
#endif

    // - release thread -
    eglReleaseThread();
  }

  init();
}/*}}}*/

#if defined(IPUROT_LINUX)
/*
 * inline methods of structure imx_fb_s
 */

inline void imx_fb_s::init()
{/*{{{*/
  fd = -1;
}/*}}}*/

inline void imx_fb_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - if file descriptor is open -
  if (fd != -1)
  {
    close(fd);
  }

  init();
}/*}}}*/
#endif

#if defined(IPUROT_LINUX)
/*
 * inline methods of structure imx_ipu_s
 */

inline void imx_ipu_s::init()
{/*{{{*/
  fd = -1;
  fb_location = nullptr;
  prepared = false;
  buffer_idx = 1;
}/*}}}*/

inline void imx_ipu_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - if file descriptor is open -
  if (fd != -1)
  {
    close(fd);
  }

  if (fb_location != nullptr)
  {
    // - disable ipu operations on framebuffer -
    imx_fb_s *if_ptr = (imx_fb_s *)fb_location->v_data_ptr;
    ioctl(if_ptr->fd,MXCFB_ROTATION_ENABLE,0);

    // - release framebuffer location -
    it.release_location_ptr(fb_location);
  }

  init();
}/*}}}*/
#endif

/*
 * inline methods of class imxegl_c
 */

inline imxegl_c::imxegl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"imxegl_init()\n"););

#if !defined(EGL_API_FB)
  XInitThreads();
#endif

  // - initialize global egl -
  global_egl_terminate.atomic_set(0);
  global_egl_mutex.init();
  global_egl_ptr = nullptr;
}/*}}}*/

inline imxegl_c::~imxegl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"imxegl_clear()\n"););

  // - release global egl -
  int ret_val;
  while ((ret_val = global_egl_mutex.clear()) == c_error_EBUSY)
  {
    cassert(global_egl_mutex.unlock() == c_error_OK);
  }

  cassert(ret_val == c_error_OK);
}/*}}}*/

#endif

