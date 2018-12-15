
@begin
include "av_module.h"
@end

// - AV indexes of built in classes -
unsigned c_bi_class_av_format = c_idx_not_exist;
unsigned c_bi_class_av_stream = c_idx_not_exist;
unsigned c_bi_class_av_video_frame = c_idx_not_exist;
unsigned c_bi_class_av_audio_frame = c_idx_not_exist;
unsigned c_bi_class_av_picture = c_idx_not_exist;
unsigned c_bi_class_av_converter = c_idx_not_exist;

// - AV module -
built_in_module_s module =
{/*{{{*/
  6,                   // Class count
  av_classes,          // Classes

  0,                   // Error base index
  11,                  // Error count
  av_error_strings,    // Error strings

  av_initialize,       // Initialize function
  av_print_exception,  // Print exceptions function
};/*}}}*/

// - AV classes -
built_in_class_s *av_classes[] =
{/*{{{*/
  &av_format_class,
  &av_stream_class,
  &av_video_frame_class,
  &av_audio_frame_class,
  &av_picture_class,
  &av_converter_class,
};/*}}}*/

// - AV error strings -
const char *av_error_strings[] =
{/*{{{*/
  "error_AV_FORMAT_OPEN_INPUT_ERROR",
  "error_AV_FORMAT_FIND_STREAM_INFO_ERROR",
  "error_AV_FORMAT_STREAM_INDEX_EXCEEDS_RANGE",
  "error_AV_FORMAT_STREAM_ALREADY_IN_DECODED",
  "error_AV_FORMAT_CANNOT_FIND_STREAM_DECODER",
  "error_AV_FORMAT_CANNOT_INITIALIZE_CODEC_CONTEXT",
  "error_AV_FORMAT_PACKED_UNRECOGNIZED_CODEC_TYPE",
  "error_AV_FORMAT_PACKED_DECODE_ERROR",
  "error_AV_PICTURE_ALLOCATE_ERROR",
  "error_AV_PICTURE_WRONG_PICTURE_PROPERTIES",
  "error_AV_PICTURE_UNSUPPORTED_PIXEL_FORMAT",
};/*}}}*/

// - AV initialize -
bool av_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize av_format class identifier -
  c_bi_class_av_format = class_base_idx++;

  // - initialize av_stream class identifier -
  c_bi_class_av_stream = class_base_idx++;

  // - initialize av_video_frame class identifier -
  c_bi_class_av_video_frame = class_base_idx++;

  // - initialize av_audio_frame class identifier -
  c_bi_class_av_audio_frame = class_base_idx++;

  // - initialize av_picture class identifier -
  c_bi_class_av_picture = class_base_idx++;

  // - initialize av_converter class identifier -
  c_bi_class_av_converter = class_base_idx++;

  return true;
}/*}}}*/

// - AV print exception -
bool av_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_AV_FORMAT_OPEN_INPUT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAV cannot open input format \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_FIND_STREAM_INFO_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while searching streams in format\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_STREAM_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds stream count\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_STREAM_ALREADY_IN_DECODED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nStream is alredy marked for decoding\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_CANNOT_FIND_STREAM_DECODER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot find proper decoder for stream\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_CANNOT_INITIALIZE_CODEC_CONTEXT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while initializing codec context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_PACKED_UNRECOGNIZED_CODEC_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized packet codec type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_FORMAT_PACKED_DECODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while decoding stream packet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_PICTURE_ALLOCATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while allocating new picture\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_PICTURE_WRONG_PICTURE_PROPERTIES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong properties (dimensions, pixel format) of picture\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AV_PICTURE_UNSUPPORTED_PIXEL_FORMAT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported pixel format of picture\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class AV_FORMAT -
built_in_class_s av_format_class =
{/*{{{*/
  "AvFormat",
  c_modifier_public | c_modifier_final,
  8, av_format_methods,
  7, av_format_variables,
  bic_av_format_consts,
  bic_av_format_init,
  bic_av_format_clear,
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

built_in_method_s av_format_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_av_format_operator_binary_equal
  },
  {
    "AvFormat#1",
    c_modifier_public | c_modifier_final,
    bic_av_format_method_AvFormat_1
  },
  {
    "stream_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_av_format_method_stream_cnt_0
  },
  {
    "stream_info#1",
    c_modifier_public | c_modifier_final,
    bic_av_format_method_stream_info_1
  },
  {
    "stream_decode#1",
    c_modifier_public | c_modifier_final,
    bic_av_format_method_stream_decode_1
  },
  {
    "next_frame#0",
    c_modifier_public | c_modifier_final,
    bic_av_format_method_next_frame_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_format_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_format_method_print_0
  },
};/*}}}*/

built_in_variable_s av_format_variables[] =
{/*{{{*/
  {
    "AVMEDIA_TYPE_UNKNOWN",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AVMEDIA_TYPE_VIDEO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AVMEDIA_TYPE_AUDIO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AVMEDIA_TYPE_DATA",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AVMEDIA_TYPE_SUBTITLE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AVMEDIA_TYPE_ATTACHMENT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AVMEDIA_TYPE_NB",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_av_format_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert av media type constants -
  {
    const_locations.push_blanks(7);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 7);

#define CREATE_AVMEDIA_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_UNKNOWN);
    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_VIDEO);
    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_AUDIO);
    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_DATA);
    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_SUBTITLE);
    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_ATTACHMENT);
    CREATE_AVMEDIA_TYPE_BIC_STATIC(AVMEDIA_TYPE_NB);
  }
}/*}}}*/

void bic_av_format_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (av_format_s *)nullptr;
}/*}}}*/

void bic_av_format_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  av_format_s *avf_ptr = (av_format_s *)location_ptr->v_data_ptr;

  // - if format exists -
  if (avf_ptr != nullptr)
  {
    avf_ptr->clear(it);
    cfree(avf_ptr);
  }
}/*}}}*/

bool bic_av_format_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_av_format_method_AvFormat_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method AvFormat
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - allocate format context -
  AVFormatContext *format_ctx = avformat_alloc_context();

  // - ERROR -
  if (avformat_open_input(&format_ctx,string_ptr->data,nullptr,nullptr) != 0)
  {
    avformat_free_context(format_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_OPEN_INPUT_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - ERROR -
  if (avformat_find_stream_info(format_ctx,nullptr) < 0)
  {
    avformat_close_input(&format_ctx);

    exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_FIND_STREAM_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create new av format object -
  av_format_s *avf_ptr = (av_format_s *)cmalloc(sizeof(av_format_s));
  avf_ptr->init();

  // - set format context -
  avf_ptr->format_ctx = format_ctx;

  // - allocate and set memory to zero -
  avf_ptr->codec_ctxs = (AVCodecContext **)cmalloc(format_ctx->nb_streams*sizeof(AVCodecContext *));
  memset(avf_ptr->codec_ctxs,0,format_ctx->nb_streams*sizeof(AVCodecContext *));

  dst_location->v_data_ptr = (av_format_s *)avf_ptr;

  return true;
}/*}}}*/

bool bic_av_format_method_stream_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve av format -
  av_format_s *avf_ptr = (av_format_s *)dst_location->v_data_ptr;

  long long int result = avf_ptr->format_ctx->nb_streams;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_format_method_stream_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
stream_idx:retrieve_integer
>
method stream_info
; @end

  // - retrieve av format -
  av_format_s *avf_ptr = (av_format_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (stream_idx < 0 || stream_idx >= avf_ptr->format_ctx->nb_streams)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_STREAM_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(stream_idx);

    return false;
  }

  // - create av stream object -
  av_stream_s *avs_ptr = (av_stream_s *)cmalloc(sizeof(av_stream_s));
  avs_ptr->init();

  // - create reference to av format -
  dst_location->v_reference_cnt.atomic_inc();
  avs_ptr->format_ctx_ptr = dst_location;

  // - set stream index -
  avs_ptr->stream_idx = stream_idx;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_av_stream,avs_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_av_format_method_stream_decode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
stream_idx:retrieve_integer
>
method stream_decode
; @end

  // - retrieve av format -
  av_format_s *avf_ptr = (av_format_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (stream_idx < 0 || stream_idx >= avf_ptr->format_ctx->nb_streams)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_STREAM_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(stream_idx);

    return false;
  }

  // - ERROR -
  if (avf_ptr->codec_ctxs[stream_idx] != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_STREAM_ALREADY_IN_DECODED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  AVStream *stream = avf_ptr->format_ctx->streams[stream_idx];
  AVCodec *codec;

  // - ERROR -
  if ((codec = avcodec_find_decoder(stream->codec->codec_id)) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_CANNOT_FIND_STREAM_DECODER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (avcodec_open2(stream->codec,codec,nullptr) < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_CANNOT_INITIALIZE_CODEC_CONTEXT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - add context to format codec context array -
  avf_ptr->codec_ctxs[stream_idx] = stream->codec;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_av_format_method_next_frame_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_format_s *avf_ptr = (av_format_s *)dst_location->v_data_ptr;

  AVFormatContext *format_ctx = avf_ptr->format_ctx;
  AVCodecContext **codec_ctxs = avf_ptr->codec_ctxs;

  AVPacket &packet = avf_ptr->packet;
  AVPacket tmp_packet;
  av_init_packet(&tmp_packet);

  // - initialize temporary packet -
  tmp_packet.side_data_elems = 0;

  int &proc_size = avf_ptr->proc_size;

  // - allocate frame -
  AVFrame *frame = av_frame_alloc();

#define BIC_AV_FORMAT_FREE_PACKET() \
  av_packet_unref(&packet);\
  packet.size = 0;

#define BIC_AV_FORMAT_FREE_FRAME() \
  av_frame_free(&frame);

#define BIC_AV_FORMAT_SET_RESULT_FRAME(FRAME_CLASS) \
{/*{{{*/\
  av_frame_s *avfr_ptr = (av_frame_s *)cmalloc(sizeof(av_frame_s));\
  avfr_ptr->init();\
\
  /* - set av frame properties - */\
  avfr_ptr->frame = frame;\
  avfr_ptr->stream_idx = packet.stream_index;\
\
  /* - create result location - */\
  BIC_CREATE_NEW_LOCATION(new_location,FRAME_CLASS,avfr_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

  // - read next frame -
  do {

    // - if packet is empty -
    if (packet.size == 0)
    {
      proc_size = 0;

      // - read next packet -
      if (av_read_frame(format_ctx,&packet) < 0)
      {
        BIC_AV_FORMAT_FREE_PACKET();
        BIC_AV_FORMAT_FREE_FRAME();

        BIC_SET_RESULT_BLANK();
        return true;
      }
    }

    // - retrieve codec context -
    AVCodecContext *codec_ctx = codec_ctxs[packet.stream_index];
    if (codec_ctx == nullptr)
    {
      BIC_AV_FORMAT_FREE_PACKET();
    }
    else
    {
      // - modify temporary packet -
      tmp_packet.data = packet.data + proc_size;
      tmp_packet.size = packet.size - proc_size;

      int got_frame;
      int proc_bytes;

      switch (format_ctx->streams[packet.stream_index]->codec->codec_type)
      {
        case AVMEDIA_TYPE_VIDEO:
          {/*{{{*/
            proc_bytes = avcodec_decode_video2(codec_ctx,frame,&got_frame,&tmp_packet);

            // - ERROR -
            if (proc_bytes < 0)
            {
              BIC_AV_FORMAT_FREE_PACKET();
              BIC_AV_FORMAT_FREE_FRAME();

              exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_PACKED_DECODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - free packet if all its data was read -
            if ((proc_size += proc_bytes) >= packet.size)
            {
              BIC_AV_FORMAT_FREE_PACKET();
            }

            if (got_frame)
            {
              BIC_AV_FORMAT_SET_RESULT_FRAME(c_bi_class_av_video_frame);
              return true;
            }
          }/*}}}*/
          break;

        // - ERROR -
        default:
          {
            BIC_AV_FORMAT_FREE_PACKET();
            BIC_AV_FORMAT_FREE_FRAME();

            exception_s::throw_exception(it,module.error_base + c_error_AV_FORMAT_PACKED_UNRECOGNIZED_CODEC_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }
      }
    }
  } while(true);
}/*}}}*/

bool bic_av_format_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvFormat"),"AvFormat");
  );

  return true;
}/*}}}*/

bool bic_av_format_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvFormat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AV_STREAM -
built_in_class_s av_stream_class =
{/*{{{*/
  "AvStream",
  c_modifier_public | c_modifier_final,
  5, av_stream_methods,
  0, av_stream_variables,
  bic_av_stream_consts,
  bic_av_stream_init,
  bic_av_stream_clear,
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

built_in_method_s av_stream_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_av_stream_operator_binary_equal
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_av_stream_method_index_0
  },
  {
    "codec_type#0",
    c_modifier_public | c_modifier_final,
    bic_av_stream_method_codec_type_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_stream_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_stream_method_print_0
  },
};/*}}}*/

built_in_variable_s av_stream_variables[] =
{/*{{{*/
};/*}}}*/

void bic_av_stream_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_av_stream_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (av_stream_s *)nullptr;
}/*}}}*/

void bic_av_stream_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  av_stream_s *avs_ptr = (av_stream_s *)location_ptr->v_data_ptr;

  // - if stream exists -
  if (avs_ptr != nullptr)
  {
    avs_ptr->clear(it);
    cfree(avs_ptr);
  }
}/*}}}*/

bool bic_av_stream_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_av_stream_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_stream_s *avs_ptr = (av_stream_s *)dst_location->v_data_ptr;
  av_format_s *avf_ptr = (av_format_s *)avs_ptr->format_ctx_ptr->v_data_ptr;

  long long int result = avf_ptr->format_ctx->streams[avs_ptr->stream_idx]->index;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_stream_method_codec_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_stream_s *avs_ptr = (av_stream_s *)dst_location->v_data_ptr;
  av_format_s *avf_ptr = (av_format_s *)avs_ptr->format_ctx_ptr->v_data_ptr;

  long long int result = avf_ptr->format_ctx->streams[avs_ptr->stream_idx]->codec->codec_type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_stream_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvStream"),"AvStream");
  );

  return true;
}/*}}}*/

bool bic_av_stream_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvStream");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AV_VIDEO_FRAME -
built_in_class_s av_video_frame_class =
{/*{{{*/
  "AvVideoFrame",
  c_modifier_public | c_modifier_final,
  7, av_video_frame_methods,
  0, av_video_frame_variables,
  bic_av_video_frame_consts,
  bic_av_video_frame_init,
  bic_av_video_frame_clear,
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

built_in_method_s av_video_frame_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_av_video_frame_operator_binary_equal
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_av_video_frame_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_av_video_frame_method_height_0
  },
  {
    "format#0",
    c_modifier_public | c_modifier_final,
    bic_av_video_frame_method_format_0
  },
  {
    "pgm_data#0",
    c_modifier_public | c_modifier_final,
    bic_av_video_frame_method_pgm_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_video_frame_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_video_frame_method_print_0
  },
};/*}}}*/

built_in_variable_s av_video_frame_variables[] =
{/*{{{*/
};/*}}}*/

void bic_av_video_frame_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_av_video_frame_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (av_frame_s *)nullptr;
}/*}}}*/

void bic_av_video_frame_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  av_frame_s *avfr_ptr = (av_frame_s *)location_ptr->v_data_ptr;

  // - if frame exists -
  if (avfr_ptr != nullptr)
  {
    avfr_ptr->clear(it);
    cfree(avfr_ptr);
  }
}/*}}}*/

bool bic_av_video_frame_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_av_video_frame_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_frame_s *avfr_ptr = (av_frame_s *)dst_location->v_data_ptr;

  long long int result = avfr_ptr->frame->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_video_frame_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_frame_s *avfr_ptr = (av_frame_s *)dst_location->v_data_ptr;

  long long int result = avfr_ptr->frame->height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_video_frame_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_frame_s *avfr_ptr = (av_frame_s *)dst_location->v_data_ptr;

  long long int result = avfr_ptr->frame->format;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_video_frame_method_pgm_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_frame_s *avfr_ptr = (av_frame_s *)dst_location->v_data_ptr;
  AVFrame *frame = avfr_ptr->frame;

  int &width = frame->width;
  int &height = frame->height;

  char header[256];
  snprintf(header,256,"P5\n%d %d\n255\n",width,height);

  unsigned header_len = strlen(header);
  unsigned image_size = height*width;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(header_len + image_size);

  unsigned char *ptr = (unsigned char *)string_ptr->data;
  memcpy(ptr,header,header_len);
  ptr += header_len;

  unsigned line_size = width;
  unsigned s_line_size = frame->linesize[0];

  unsigned char *ptr_end = ptr + image_size;
  unsigned char *s_ptr = frame->data[0];
  do {
    memcpy(ptr,s_ptr,width);

    ptr += line_size;
    s_ptr += s_line_size;
  } while(ptr < ptr_end);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_av_video_frame_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvVideoFrame"),"AvVideoFrame");
  );

  return true;
}/*}}}*/

bool bic_av_video_frame_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvVideoFrame");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AV_AUDIO_FRAME -
built_in_class_s av_audio_frame_class =
{/*{{{*/
  "AvAudioFrame",
  c_modifier_public | c_modifier_final,
  3, av_audio_frame_methods,
  0, av_audio_frame_variables,
  bic_av_audio_frame_consts,
  bic_av_audio_frame_init,
  bic_av_audio_frame_clear,
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

built_in_method_s av_audio_frame_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_av_audio_frame_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_audio_frame_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_audio_frame_method_print_0
  },
};/*}}}*/

built_in_variable_s av_audio_frame_variables[] =
{/*{{{*/
};/*}}}*/

void bic_av_audio_frame_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_av_audio_frame_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (av_frame_s *)nullptr;
}/*}}}*/

void bic_av_audio_frame_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  av_frame_s *avfr_ptr = (av_frame_s *)location_ptr->v_data_ptr;

  // - if frame exists -
  if (avfr_ptr != nullptr)
  {
    avfr_ptr->clear(it);
    cfree(avfr_ptr);
  }
}/*}}}*/

bool bic_av_audio_frame_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_av_audio_frame_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvAudioFrame"),"AvAudioFrame");
  );

  return true;
}/*}}}*/

bool bic_av_audio_frame_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvAudioFrame");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AV_PICTURE -
built_in_class_s av_picture_class =
{/*{{{*/
  "AvPicture",
  c_modifier_public | c_modifier_final,
  9, av_picture_methods,
  4, av_picture_variables,
  bic_av_picture_consts,
  bic_av_picture_init,
  bic_av_picture_clear,
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

built_in_method_s av_picture_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_av_picture_operator_binary_equal
  },
  {
    "AvPicture#3",
    c_modifier_public | c_modifier_final,
    bic_av_picture_method_AvPicture_3
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_av_picture_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_av_picture_method_height_0
  },
  {
    "format#0",
    c_modifier_public | c_modifier_final,
    bic_av_picture_method_format_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_av_picture_method_buffer_0
  },
  {
    "bmp_data#0",
    c_modifier_public | c_modifier_final,
    bic_av_picture_method_bmp_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_picture_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_picture_method_print_0
  },
};/*}}}*/

built_in_variable_s av_picture_variables[] =
{/*{{{*/
  {
    "AV_PIX_FMT_RGB24",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AV_PIX_FMT_BGR24",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AV_PIX_FMT_RGBA",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "AV_PIX_FMT_BGRA",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_av_picture_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert hostkey type constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_AV_PICTURE_AV_PIX_FMT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_AV_PICTURE_AV_PIX_FMT_BIC_STATIC(AV_PIX_FMT_RGB24);
    CREATE_AV_PICTURE_AV_PIX_FMT_BIC_STATIC(AV_PIX_FMT_BGR24);
    CREATE_AV_PICTURE_AV_PIX_FMT_BIC_STATIC(AV_PIX_FMT_RGBA);
    CREATE_AV_PICTURE_AV_PIX_FMT_BIC_STATIC(AV_PIX_FMT_BGRA);
  }
}/*}}}*/

void bic_av_picture_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (av_picture_s *)nullptr;
}/*}}}*/

void bic_av_picture_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  av_picture_s *avp_ptr = (av_picture_s *)location_ptr->v_data_ptr;

  // - if frame exists -
  if (avp_ptr != nullptr)
  {
    avp_ptr->clear(it);
    cfree(avp_ptr);
  }
}/*}}}*/

bool bic_av_picture_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_av_picture_method_AvPicture_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
int_format:retrieve_integer
>
method AvPicture
; @end

  AVPixelFormat format = (AVPixelFormat)int_format;

  // - create av picture object -
  av_picture_s *avp_ptr = (av_picture_s *)cmalloc(sizeof(av_picture_s));
  avp_ptr->init();

  // - pointer to picture -
  AVFrame *picture = &avp_ptr->picture;

  memset(picture,0,sizeof(AVFrame));
  picture->format = format;
  picture->width = width;
  picture->height = height;

  // - ERROR -
  if (av_frame_get_buffer(picture,1) != 0)
  {
    avp_ptr->clear(it);
    cfree(avp_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_ALLOCATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set picture properties -
  avp_ptr->width = width;
  avp_ptr->height = height;
  avp_ptr->format = format;

  dst_location->v_data_ptr = (av_picture_s *)avp_ptr;

  return true;
}/*}}}*/

bool bic_av_picture_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_picture_s *avp_ptr = (av_picture_s *)dst_location->v_data_ptr;

  long long int result = avp_ptr->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_picture_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_picture_s *avp_ptr = (av_picture_s *)dst_location->v_data_ptr;

  long long int result = avp_ptr->height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_picture_method_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_picture_s *avp_ptr = (av_picture_s *)dst_location->v_data_ptr;

  long long int result = avp_ptr->format;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_av_picture_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_picture_s *avp_ptr = (av_picture_s *)dst_location->v_data_ptr;

  switch (avp_ptr->format)
  {
  case AV_PIX_FMT_RGB24:
  case AV_PIX_FMT_BGR24:
  case AV_PIX_FMT_RGBA:
  case AV_PIX_FMT_BGRA:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = avp_ptr->picture.data[0];
  buffer_ptr->size = avp_ptr->height*avp_ptr->picture.linesize[0];

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_av_picture_method_bmp_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  av_picture_s *avp_ptr = (av_picture_s *)dst_location->v_data_ptr;
  AVFrame &pic = avp_ptr->picture;

  // - create result location -
  string_s *string_ptr = it.get_new_string_ptr();
  BIC_SET_RESULT_STRING(string_ptr);

  // - create bitmap object -
  bitmap_s bitmap;
  bitmap.init();

  switch (avp_ptr->format)
  {
    case AV_PIX_FMT_RGB24:
      bitmap.from_RGB24(pic.data[0],pic.linesize[0],avp_ptr->width,avp_ptr->height);
      break;

    case AV_PIX_FMT_BGR24:
      bitmap.from_BGR24(pic.data[0],pic.linesize[0],avp_ptr->width,avp_ptr->height);
      break;

    case AV_PIX_FMT_RGBA:
      bitmap.from_RGBA32(pic.data[0],pic.linesize[0],avp_ptr->width,avp_ptr->height);
      break;

    case AV_PIX_FMT_BGRA:
      bitmap.from_BGRA32(pic.data[0],pic.linesize[0],avp_ptr->width,avp_ptr->height);
      break;

    // - ERROR -
    default:
    {
      bitmap.clear();

      exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_UNSUPPORTED_PIXEL_FORMAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  bitmap.data_string(*string_ptr);
  bitmap.clear();

  return true;
}/*}}}*/

bool bic_av_picture_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvPicture"),"AvPicture");
  );

  return true;
}/*}}}*/

bool bic_av_picture_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvPicture");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AV_CONVERTER -
built_in_class_s av_converter_class =
{/*{{{*/
  "AvConverter",
  c_modifier_public | c_modifier_final,
  6, av_converter_methods,
  0, av_converter_variables,
  bic_av_converter_consts,
  bic_av_converter_init,
  bic_av_converter_clear,
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

built_in_method_s av_converter_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_av_converter_operator_binary_equal
  },
  {
    "AvConverter#0",
    c_modifier_public | c_modifier_final,
    bic_av_converter_method_AvConverter_0
  },
  {
    "scale#2",
    c_modifier_public | c_modifier_final,
    bic_av_converter_method_scale_2
  },
  {
    "scale#4",
    c_modifier_public | c_modifier_final,
    bic_av_converter_method_scale_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_converter_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_av_converter_method_print_0
  },
};/*}}}*/

built_in_variable_s av_converter_variables[] =
{/*{{{*/
};/*}}}*/

void bic_av_converter_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_av_converter_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SwsContext *)nullptr;
}/*}}}*/

void bic_av_converter_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  SwsContext *avc_ptr = (SwsContext *)location_ptr->v_data_ptr;

  // - if converter exists -
  if (avc_ptr != nullptr)
  {
    sws_freeContext(avc_ptr);
  }
}/*}}}*/

bool bic_av_converter_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_av_converter_method_AvConverter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_av_converter_method_scale_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
src_frame_picture:ignore
trg_picture:c_bi_class_av_picture
>
method scale
; @end

  // - source picture variables -
  AVFrame *src_pic;
  int src_width;
  int src_height;
  AVPixelFormat src_format;

  // - process source frame -
  if (src_0_location->v_type == c_bi_class_av_video_frame)
  {
    av_frame_s *avfr_ptr = (av_frame_s *)src_0_location->v_data_ptr;
    AVFrame *frame = avfr_ptr->frame;

    src_pic = frame;
    src_width = frame->width;
    src_height = frame->height;
    src_format = (AVPixelFormat)frame->format;
  }

  // - process source picture -
  else if (src_0_location->v_type == c_bi_class_av_picture)
  {
    av_picture_s *avp_ptr = (av_picture_s *)src_0_location->v_data_ptr;

    src_pic = &avp_ptr->picture;
    src_width = avp_ptr->width;
    src_height = avp_ptr->height;
    src_format = avp_ptr->format;
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("scale#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  av_picture_s *avtp_ptr = (av_picture_s *)src_1_location->v_data_ptr;

  // - target picture variables -
  AVFrame *trg_pic = &avtp_ptr->picture;
  long long int trg_width = avtp_ptr->width;
  long long int trg_height = avtp_ptr->height;
  AVPixelFormat trg_format = avtp_ptr->format;

  // - retrieve av converter object -
  SwsContext **avc_ptr = (SwsContext **)&(dst_location->v_data_ptr);

  // - ERROR -
  if (src_width <= 0 || src_height <= 0 || src_format <= AV_PIX_FMT_NONE || src_format >= AV_PIX_FMT_NB)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_WRONG_PICTURE_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (trg_width <= 0 || trg_height <= 0 || trg_format <= AV_PIX_FMT_NONE || trg_format >= AV_PIX_FMT_NB)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_WRONG_PICTURE_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - update converter context -
  *avc_ptr = sws_getCachedContext(*avc_ptr,
    src_width,src_height,src_format,
    trg_width,trg_height,trg_format,
    SWS_BICUBIC,nullptr,nullptr,nullptr);

  // - scale source picture to target -
  sws_scale(*avc_ptr,src_pic->data,src_pic->linesize,0,src_height,trg_pic->data,trg_pic->linesize);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_av_converter_method_scale_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
src_frame_picture:ignore
trg_width:retrieve_integer
trg_height:retrieve_integer
int_format:retrieve_integer
>
method scale
; @end

  // - convert target format to enum AVPixelFormat -
  AVPixelFormat trg_format = (AVPixelFormat)int_format;

  // - source picture variables -
  AVFrame *src_pic;
  int src_width;
  int src_height;
  AVPixelFormat src_format;

  // - process source frame -
  if (src_0_location->v_type == c_bi_class_av_video_frame)
  {
    av_frame_s *avfr_ptr = (av_frame_s *)src_0_location->v_data_ptr;
    AVFrame *frame = avfr_ptr->frame;

    src_pic = frame;
    src_width = frame->width;
    src_height = frame->height;
    src_format = (AVPixelFormat)frame->format;
  }

  // - process source picture -
  else if (src_0_location->v_type == c_bi_class_av_picture)
  {
    av_picture_s *avp_ptr = (av_picture_s *)src_0_location->v_data_ptr;

    src_pic = &avp_ptr->picture;
    src_width = avp_ptr->width;
    src_height = avp_ptr->height;
    src_format = avp_ptr->format;
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("scale#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  // - retrieve av converter object -
  SwsContext **avc_ptr = (SwsContext **)&(dst_location->v_data_ptr);

  // - ERROR -
  if (src_width <= 0 || src_height <= 0 || src_format <= AV_PIX_FMT_NONE || src_format >= AV_PIX_FMT_NB)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_WRONG_PICTURE_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (trg_width <= 0 || trg_height <= 0 || trg_format <= AV_PIX_FMT_NONE || trg_format >= AV_PIX_FMT_NB)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_WRONG_PICTURE_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create av picture object -
  av_picture_s *avp_ptr = (av_picture_s *)cmalloc(sizeof(av_picture_s));
  avp_ptr->init();

  // - pointer to target picture -
  AVFrame *trg_pic = &avp_ptr->picture;

  memset(trg_pic,0,sizeof(AVFrame));
  trg_pic->format = trg_format;
  trg_pic->width = trg_width;
  trg_pic->height = trg_height;

  // - ERROR -
  if (av_frame_get_buffer(trg_pic,1) != 0)
  {
    avp_ptr->clear(it);
    cfree(avp_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_AV_PICTURE_ALLOCATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set picture properties -
  avp_ptr->width = trg_width;
  avp_ptr->height = trg_height;
  avp_ptr->format = trg_format;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_av_picture,avp_ptr);
  BIC_SET_RESULT(new_location);

  // - update converter context -
  *avc_ptr = sws_getCachedContext(*avc_ptr,
      src_width,src_height,src_format,
      trg_width,trg_height,trg_format,
      SWS_BICUBIC,nullptr,nullptr,nullptr);

  // - scale source picture to target -
  sws_scale(*avc_ptr,src_pic->data,src_pic->linesize,0,src_height,trg_pic->data,trg_pic->linesize);

  return true;
}/*}}}*/

bool bic_av_converter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvConverter"),"AvConverter");
  );

  return true;
}/*}}}*/

bool bic_av_converter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvConverter");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

