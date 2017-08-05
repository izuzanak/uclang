
#ifndef __UCL_GSTREAMER_H
#define __UCL_GSTREAMER_H

@begin
include "script_parser.h"
@end

#include <gst/gst.h>
#include <glib.h>

/*
 * definition of structure gst_pipeline_s
 */

struct gst_pipeline_s
{
  GstElement *pipeline;
  GstBus *bus;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class gstreamer_c
 */
class gstreamer_c
{
  public:
  inline gstreamer_c();
  inline ~gstreamer_c();

  static void on_pad_add_video(GstElement *element,GstPad *new_pad,gpointer data);
};

/*
 * inline methods of structure gst_pipeline_s
 */

inline void gst_pipeline_s::init()
{/*{{{*/
  pipeline = nullptr;
  bus = nullptr;
}/*}}}*/

inline void gst_pipeline_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release bus -
  if (bus != nullptr)
  {
    gst_object_unref(bus);
  }

  // - release pipeline -
  if (pipeline != nullptr)
  {
    gst_element_set_state(pipeline,GST_STATE_NULL);
    gst_object_unref(pipeline);
  }

  init();
}/*}}}*/

/*
 * inline methods of class gstreamer_c
 */

inline gstreamer_c::gstreamer_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gst_init()\n"););

  GError *err;
  cassert(gst_init_check(0,nullptr,&err));
}/*}}}*/

inline gstreamer_c::~gstreamer_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gst_deinit()\n"););
  gst_deinit();
}/*}}}*/

#endif

