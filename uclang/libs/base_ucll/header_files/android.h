
#ifndef __ANDROID_H
#define __ANDROID_H

@begin
include "script_parser.h"
@end

#if defined(ANDROID)

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include <android/log.h>
#include <android/looper.h>
#include <android/input.h>
#include <android/sensor.h>
#include <android/native_activity.h>

#include <sys/system_properties.h>
#include <android_native_app_glue.h>

/*
 * basic constants and definitions
 */

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO,"uclang",__VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN,"uclang",__VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR,"uclang",__VA_ARGS__))

/*
 * definition of class activity_c
 */

struct activity_c
{
public:

  // - activity properties -
  struct android_app *app;
  void(*event_loop_ptr)();
  AInputEvent* event;

  // - EGL variables -
  EGLDisplay display;
  EGLSurface surface;
  EGLContext context;

  // - display properties -
  int32_t width;
  int32_t height;

  // - uclang properties -
  bool event_loop;
  unsigned loop_source_pos;
  unsigned loop_ret_code;

  interpreter_thread_s *it_ptr;

  location_s *resize_dlg;
  location_s *display_dlg;
  location_s *input_dlg;
  location_s *command_dlg;
  location_s *sensor_dlg;
  location_s *idle_dlg;

public:

  inline activity_c();

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of class activity_c
 */

#define ACTIVITY_CALL_CALLBACK_DELEGATE(NAME,PARAM_DATA,PARAM_CNT,PARAM_CODE,ERR_CODE) \
{/*{{{*/\
  if (g_activity.it_ptr != nullptr &&\
      NAME != nullptr)\
  {\
    interpreter_thread_s &it = *g_activity.it_ptr;\
    delegate_s *delegate_ptr = (delegate_s *)(NAME)->v_data_ptr;\
\
    PARAM_CODE;\
\
    /* - call delegate method - */\
    location_s *trg_location = nullptr;\
    BIC_CALL_DELEGATE(it,delegate_ptr,PARAM_DATA,PARAM_CNT,trg_location,g_activity.loop_source_pos,\
      g_activity.loop_ret_code = c_run_return_code_EXCEPTION;\
      ERR_CODE;\
    );\
    it.release_location_ptr(trg_location);\
  }\
}/*}}}*/

#define ACTIVITY_CALL_CALLBACK_DELEGATE_INTEGER(NAME,PARAM_DATA,PARAM_CNT,PARAM_CODE,ERR_CODE) \
{/*{{{*/\
  if (g_activity.it_ptr != nullptr &&\
      NAME != nullptr)\
  {\
    interpreter_thread_s &it = *g_activity.it_ptr;\
    delegate_s *delegate_ptr = (delegate_s *)(NAME)->v_data_ptr;\
\
    PARAM_CODE;\
\
    /* - call delegate method - */\
    location_s *trg_location = nullptr;\
    BIC_CALL_DELEGATE(it,delegate_ptr,PARAM_DATA,PARAM_CNT,trg_location,g_activity.loop_source_pos,\
      g_activity.loop_ret_code = c_run_return_code_EXCEPTION;\
      ERR_CODE;\
    );\
\
    /* - ERROR - */\
    if (trg_location->v_type != c_bi_class_integer)\
    {\
      it.release_location_ptr(trg_location);\
\
      /* - create exception - */\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_RETURN_INTEGER,g_activity.loop_source_pos,(location_s *)it.blank_location);\
\
      /* - if delegate is static - */\
      if (delegate_ptr->object_location == nullptr)\
      {\
        new_exception->params.push(delegate_ptr->name_idx_ri);\
      }\
\
      /* - if delegate is not static - */\
      else\
      {\
        unsigned method_ri = ((interpreter_s *)it.interpreter_ptr)->class_records[it.get_location_value(delegate_ptr->object_location)->v_type].mnri_map.map_name(delegate_ptr->name_idx_ri);\
        cassert(method_ri != c_idx_not_exist);\
\
        new_exception->params.push(method_ri);\
      }\
\
      g_activity.loop_ret_code = c_run_return_code_EXCEPTION;\
      ERR_CODE;\
    }\
\
    long long int value = (long long int)trg_location->v_data_ptr;\
    it.release_location_ptr(trg_location);\
\
    return value;\
  }\
\
  return 0;\
}/*}}}*/

inline activity_c::activity_c()
{/*{{{*/
  app = nullptr;
  event_loop_ptr = nullptr;
  event = nullptr;

  display = EGL_NO_CONTEXT;
  surface = EGL_NO_DISPLAY;
  context = EGL_NO_SURFACE;

  width = 0;
  height = 0;

  init();
}/*}}}*/

inline void activity_c::init()
{/*{{{*/
  event_loop = false;

  it_ptr = nullptr;

  resize_dlg = nullptr;
  display_dlg = nullptr;
  input_dlg = nullptr;
  command_dlg = nullptr;
  sensor_dlg = nullptr;
  idle_dlg = nullptr;
}/*}}}*/

inline void activity_c::clear(interpreter_thread_s &it)
{/*{{{*/

#define ANDROID_RELEASE_DELEGATE(NAME) \
{/*{{{*/\
  if (NAME != nullptr)\
  {\
    it.release_location_ptr(NAME);\
  }\
}/*}}}*/

  ANDROID_RELEASE_DELEGATE(resize_dlg);
  ANDROID_RELEASE_DELEGATE(display_dlg);
  ANDROID_RELEASE_DELEGATE(input_dlg);
  ANDROID_RELEASE_DELEGATE(command_dlg);
  ANDROID_RELEASE_DELEGATE(sensor_dlg);
  ANDROID_RELEASE_DELEGATE(idle_dlg);

  init();
}/*}}}*/

// - global android state -
extern activity_c g_activity;

#endif

#endif

