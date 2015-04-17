
@begin
include "ucl_gstreamer.h"
@end

// - gstreamer global init object -
gstreamer_c g_gstreamer;

/*
 * methods of class gstreamer_c
 */

void gstreamer_c::on_pad_add_video(GstElement *element,GstPad *new_pad,gpointer data)
{/*{{{*/
  GstCaps *pad_caps = gst_pad_query_caps(new_pad,NULL);
  GstStructure *pad_struct = gst_caps_get_structure(pad_caps,0);
  const gchar *pad_type = gst_structure_get_name(pad_struct);

  if (g_str_has_prefix(pad_type,"video/x-raw"))
  {
    GstElement *sink = (GstElement *)data;
    GstPad *sinkpad = gst_element_get_static_pad(sink,"sink");
    gst_pad_link(new_pad,sinkpad);
    gst_object_unref(sinkpad);
  }
}/*}}}*/

