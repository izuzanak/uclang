
@begin
include "gstreamer_module.h"
@end

// - GSTREAMER indexes of built in classes -
unsigned c_bi_class_gst = c_idx_not_exist;
unsigned c_bi_class_gst_pipeline = c_idx_not_exist;

// - GSTREAMER module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                         // Class count
  gstreamer_classes,         // Classes

  0,                         // Error base index
  5,                         // Error count
  gstreamer_error_strings,   // Error strings

  gstreamer_initialize,      // Initialize function
  gstreamer_print_exception, // Print exceptions function
};/*}}}*/

// - GSTREAMER classes -
built_in_class_s *gstreamer_classes[] =
{/*{{{*/
  &gst_class,
  &gst_pipeline_class,
};/*}}}*/

// - GSTREAMER error strings -
const char *gstreamer_error_strings[] =
{/*{{{*/
  "error_GST_CANNOT_CREATE_SINK",
  "error_GST_CANNOT_CONSTRUCT_PIPELINE",
  "error_GST_PIPELANE_SET_STATE_ERROR",
  "error_GST_PIPELANE_RUNTIME_ERROR",
  "error_GST_PIPELANE_STOP_ERROR",
};/*}}}*/

// - GSTREAMER initialize -
bool gstreamer_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gst class identifier -
  c_bi_class_gst = class_base_idx++;

  // - initialize gst_pipeline class identifier -
  c_bi_class_gst_pipeline = class_base_idx++;

  return true;
}/*}}}*/

// - GSTREAMER print exception -
bool gstreamer_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GST_CANNOT_CREATE_SINK:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGStreamer cannot create sink \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GST_CANNOT_CONSTRUCT_PIPELINE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGStreamer cannot construct requested pipeline\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GST_PIPELANE_SET_STATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while setting gstreamer pipeline state\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GST_PIPELANE_RUNTIME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGStreamer pipeline runtime error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GST_PIPELANE_STOP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while trying to stop gstreamer pipeline\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GST -
built_in_class_s gst_class =
{/*{{{*/
  "Gst",
  c_modifier_public | c_modifier_final,
  5, gst_methods,
  5, gst_variables,
  bic_gst_consts,
  bic_gst_init,
  bic_gst_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s gst_methods[] =
{/*{{{*/
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_method_version_0
  },
  {
    "version_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_method_version_string_0
  },
  {
    "pipeline_video_uri_imxegl#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_method_pipeline_video_uri_imxegl_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_method_print_0
  },
};/*}}}*/

built_in_variable_s gst_variables[] =
{/*{{{*/

  // - gstreamer element state constants -
  { "GST_STATE_VOID_PENDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GST_STATE_NULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GST_STATE_READY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GST_STATE_PAUSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GST_STATE_PLAYING", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_gst_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert gstreamer element state constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_GST_ELEMENT_STATE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GST_ELEMENT_STATE_BIC_STATIC(GST_STATE_VOID_PENDING);
    CREATE_GST_ELEMENT_STATE_BIC_STATIC(GST_STATE_NULL);
    CREATE_GST_ELEMENT_STATE_BIC_STATIC(GST_STATE_READY);
    CREATE_GST_ELEMENT_STATE_BIC_STATIC(GST_STATE_PAUSED);
    CREATE_GST_ELEMENT_STATE_BIC_STATIC(GST_STATE_PLAYING);
  }
}/*}}}*/

void bic_gst_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_gst_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_gst_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  guint major;
  guint minor;
  guint micro;
  guint nano;

  // - retrieve gstreamer version -
  gst_version(&major,&minor,&micro,&nano);

  // - create return array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

#define BIC_GST_METHOD_VERSION_PUSH_VALUE(NAME) \
{/*{{{*/\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,NAME);\
  array_ptr->push(new_location);\
}/*}}}*/

  // - push values to return array -
  BIC_GST_METHOD_VERSION_PUSH_VALUE(major);
  BIC_GST_METHOD_VERSION_PUSH_VALUE(minor);
  BIC_GST_METHOD_VERSION_PUSH_VALUE(micro);
  BIC_GST_METHOD_VERSION_PUSH_VALUE(nano);

  // - create return location -
  BIC_CREATE_NEW_LOCATION(return_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(return_location);

  return true;
}/*}}}*/

bool bic_gst_method_version_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  // - retrieve gstreamer version -
  gchar *version = gst_version_string();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = version;
  string_ptr->size = strlen(version) + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_gst_method_pipeline_video_uri_imxegl_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
uri:c_bi_class_string
texture_id:retrieve_integer
>
class c_bi_class_gst
method pipeline_video_uri_imxegl
static_method
; @end

  string_s *uri_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create gstreamer pipeline -
  GstElement *pipeline = gst_pipeline_new("video-uri");

  // - create gstreamer elements -
  GstElement *decoder = gst_element_factory_make("uridecodebin",nullptr);
  GstElement *sink    = gst_element_factory_make("imxeglvivsink",nullptr);

  // - ERROR -
  if (!sink)
  {
    if (pipeline) { gst_object_unref(pipeline); }
    if (decoder)  { gst_object_unref(decoder); }

    exception_s::throw_exception(it,module.error_base + c_error_GST_CANNOT_CREATE_SINK,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  // - ERROR -
  if (!pipeline || !decoder || !sink)
  {
    if (pipeline) { gst_object_unref(pipeline); }
    if (decoder)  { gst_object_unref(decoder); }
    if (sink)     { gst_object_unref(sink); }

    exception_s::throw_exception(it,module.error_base + c_error_GST_CANNOT_CONSTRUCT_PIPELINE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set elements parameters -
  g_object_set(G_OBJECT(decoder),"uri",uri_ptr->data,nullptr);
  g_object_set(G_OBJECT(sink),"texture-id",texture_id,nullptr);

  // - add elements to pipeline -
  gst_bin_add_many(GST_BIN(pipeline),decoder,sink,nullptr);

  // - link elements -
  g_signal_connect(decoder,"pad-added",G_CALLBACK(gstreamer_c::on_pad_add_video),sink);

  // - create gst pipeline object -
  gst_pipeline_s *gstp_ptr = (gst_pipeline_s *)cmalloc(sizeof(gst_pipeline_s));
  gstp_ptr->init();

  gstp_ptr->pipeline = pipeline;
  gstp_ptr->bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gst_pipeline,gstp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gst_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Gst"),"Gst");
  );

  return true;
}/*}}}*/

bool bic_gst_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Gst");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GST_PIPELINE -
built_in_class_s gst_pipeline_class =
{/*{{{*/
  "GstPipeline",
  c_modifier_public | c_modifier_final,
  7, gst_pipeline_methods,
  0, gst_pipeline_variables,
  bic_gst_pipeline_consts,
  bic_gst_pipeline_init,
  bic_gst_pipeline_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s gst_pipeline_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gst_pipeline_operator_binary_equal
  },
  {
    "set_state#1",
    c_modifier_public | c_modifier_final,
    bic_gst_pipeline_method_set_state_1
  },
  {
    "get_state#0",
    c_modifier_public | c_modifier_final,
    bic_gst_pipeline_method_get_state_0
  },
  {
    "main_loop#0",
    c_modifier_public | c_modifier_final,
    bic_gst_pipeline_method_main_loop_0
  },
  {
    "stop#0",
    c_modifier_public | c_modifier_final,
    bic_gst_pipeline_method_stop_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_pipeline_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gst_pipeline_method_print_0
  },
};/*}}}*/

built_in_variable_s gst_pipeline_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_gst_pipeline_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gst_pipeline_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gst_pipeline_s *)nullptr;
}/*}}}*/

void bic_gst_pipeline_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gst_pipeline_s *gstp_ptr = (gst_pipeline_s *)location_ptr->v_data_ptr;

  if (gstp_ptr != nullptr)
  {
    gstp_ptr->clear(it);
    cfree(gstp_ptr);
  }
}/*}}}*/

bool bic_gst_pipeline_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gst_pipeline_method_set_state_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
state:retrieve_integer
>
method set_state
; @end

  gst_pipeline_s *gstp_ptr = (gst_pipeline_s *)dst_location->v_data_ptr;

  // - set pipeline state -
  GstStateChangeReturn res = gst_element_set_state(gstp_ptr->pipeline,(GstState)state);

  switch (res)
  {
  case GST_STATE_CHANGE_SUCCESS:
  case GST_STATE_CHANGE_ASYNC:
  case GST_STATE_CHANGE_NO_PREROLL:
    break;

  // - ERROR -
  case GST_STATE_CHANGE_FAILURE:
  default:

    exception_s::throw_exception(it,module.error_base + c_error_GST_PIPELANE_SET_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gst_pipeline_method_get_state_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gst_pipeline_s *gstp_ptr = (gst_pipeline_s *)dst_location->v_data_ptr;

  // - retrieve pipeline state -
  GstState state;
  gst_element_get_state(gstp_ptr->pipeline,&state,nullptr,GST_CLOCK_TIME_NONE);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,state);

  return true;
}/*}}}*/

bool bic_gst_pipeline_method_main_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gst_pipeline_s *gstp_ptr = (gst_pipeline_s *)dst_location->v_data_ptr;

  // - reference to interpreter terminate -
  atomic_s &terminate = ((interpreter_s *)it.interpreter_ptr)->terminate;

  // - enter main loop -
  bool running = true;
  do {
    GstMessage *message = gst_bus_timed_pop(gstp_ptr->bus,10000000);

    // - process message -
    if (message != nullptr)
    {
      switch (GST_MESSAGE_TYPE(message))
      {
        case GST_MESSAGE_EOS:
          running = false;
          break;

        case GST_MESSAGE_ERROR:
        {
          gchar *debug;
          GError *error;

          gst_message_parse_error(message,&error,&debug);

          g_free(debug);
          g_error_free(error);

          gst_message_unref(message);

          // - ERROR -
          exception_s::throw_exception(it,module.error_base + c_error_GST_PIPELANE_RUNTIME_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        // FIXME debug output
        //case GST_MESSAGE_UNKNOWN: fprintf(stderr,"GST_MESSAGE_UNKNOWN\n"); break;
        //case GST_MESSAGE_WARNING: fprintf(stderr,"GST_MESSAGE_WARNING\n"); break;
        //case GST_MESSAGE_INFO: fprintf(stderr,"GST_MESSAGE_INFO\n"); break;
        //case GST_MESSAGE_TAG: fprintf(stderr,"GST_MESSAGE_TAG\n"); break;
        //case GST_MESSAGE_BUFFERING: fprintf(stderr,"GST_MESSAGE_BUFFERING\n"); break;
        //case GST_MESSAGE_STATE_CHANGED: fprintf(stderr,"GST_MESSAGE_STATE_CHANGED\n"); break;
        //case GST_MESSAGE_STATE_DIRTY: fprintf(stderr,"GST_MESSAGE_STATE_DIRTY\n"); break;
        //case GST_MESSAGE_STEP_DONE: fprintf(stderr,"GST_MESSAGE_STEP_DONE\n"); break;
        //case GST_MESSAGE_CLOCK_PROVIDE: fprintf(stderr,"GST_MESSAGE_CLOCK_PROVIDE\n"); break;
        //case GST_MESSAGE_CLOCK_LOST: fprintf(stderr,"GST_MESSAGE_CLOCK_LOST\n"); break;
        //case GST_MESSAGE_NEW_CLOCK: fprintf(stderr,"GST_MESSAGE_NEW_CLOCK\n"); break;
        //case GST_MESSAGE_STRUCTURE_CHANGE: fprintf(stderr,"GST_MESSAGE_STRUCTURE_CHANGE\n"); break;
        //case GST_MESSAGE_STREAM_STATUS:
        //  {
        //    GstStreamStatusType status;
        //    GstElement *element;

        //    // - retrieve stream status -
        //    gst_message_parse_stream_status(message,&status,&element);

        //    switch (status)
        //    {
        //      case GST_STREAM_STATUS_TYPE_CREATE: fprintf(stderr,"GST_STREAM_STATUS_TYPE_CREATE\n"); break;
        //      case GST_STREAM_STATUS_TYPE_ENTER: fprintf(stderr,"GST_STREAM_STATUS_TYPE_ENTER\n"); break;
        //      case GST_STREAM_STATUS_TYPE_LEAVE: fprintf(stderr,"GST_STREAM_STATUS_TYPE_LEAVE\n"); break;
        //      case GST_STREAM_STATUS_TYPE_DESTROY: fprintf(stderr,"GST_STREAM_STATUS_TYPE_DESTROY\n"); break;
        //      case GST_STREAM_STATUS_TYPE_START: fprintf(stderr,"GST_STREAM_STATUS_TYPE_START\n"); break;
        //      case GST_STREAM_STATUS_TYPE_PAUSE: fprintf(stderr,"GST_STREAM_STATUS_TYPE_PAUSE\n"); break;
        //      case GST_STREAM_STATUS_TYPE_STOP: fprintf(stderr,"GST_STREAM_STATUS_TYPE_STOP\n"); break;
        //    }
        //  }
        //  break;
        //case GST_MESSAGE_APPLICATION: fprintf(stderr,"GST_MESSAGE_APPLICATION\n"); break;
        //case GST_MESSAGE_ELEMENT: fprintf(stderr,"GST_MESSAGE_ELEMENT\n"); break;
        //case GST_MESSAGE_SEGMENT_START: fprintf(stderr,"GST_MESSAGE_SEGMENT_START\n"); break;
        //case GST_MESSAGE_SEGMENT_DONE: fprintf(stderr,"GST_MESSAGE_SEGMENT_DONE\n"); break;
        //case GST_MESSAGE_DURATION: fprintf(stderr,"GST_MESSAGE_DURATION\n"); break;
        //case GST_MESSAGE_LATENCY: fprintf(stderr,"GST_MESSAGE_LATENCY\n"); break;
        //case GST_MESSAGE_ASYNC_START: fprintf(stderr,"GST_MESSAGE_ASYNC_START\n"); break;
        //case GST_MESSAGE_ASYNC_DONE: fprintf(stderr,"GST_MESSAGE_ASYNC_DONE\n"); break;
        //case GST_MESSAGE_REQUEST_STATE: fprintf(stderr,"GST_MESSAGE_REQUEST_STATE\n"); break;
        //case GST_MESSAGE_STEP_START: fprintf(stderr,"GST_MESSAGE_STEP_START\n"); break;
        //case GST_MESSAGE_QOS: fprintf(stderr,"GST_MESSAGE_QOS\n"); break;
        //case GST_MESSAGE_PROGRESS: fprintf(stderr,"GST_MESSAGE_PROGRESS\n"); break;
        //case GST_MESSAGE_ANY: fprintf(stderr,"GST_MESSAGE_ANY\n"); break;

        default:
          break;
      }

      gst_message_unref(message);
    }

    // - test if interpreter terminates -
    if (terminate.value())
    {
      running = false;
    }

  } while (running);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gst_pipeline_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  gst_pipeline_s *gstp_ptr = (gst_pipeline_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!gst_bus_post(gstp_ptr->bus,gst_message_new_eos(GST_OBJECT(gstp_ptr->pipeline))))
  {
    exception_s::throw_exception(it,module.error_base + c_error_GST_PIPELANE_STOP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gst_pipeline_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GstPipeline"),"GstPipeline");
  );

  return true;
}/*}}}*/

bool bic_gst_pipeline_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GstPipeline");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

