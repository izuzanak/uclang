
#ifndef __UCL_AV_H
#define __UCL_AV_H

@begin
include "ucl_bitmap.h"
include "script_parser.h"
@end

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

extern "C" {
#if LIBAVCODEC_VERSION_MAJOR < 59
// - mutex lock callback function -
int av_lock_callback(void **mutex,enum AVLockOp op);
#endif

// - log callback function -
void av_log_callback(void* ptr,int level,const char *fmt,va_list vl);
}

/*
 * definition of structure av_format_s
 */

struct av_format_s
{
  AVFormatContext *format_ctx;
  AVCodecContext **codec_ctxs;
  AVPacket packet;
  int proc_size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure av_stream_s
 */

struct av_stream_s
{
  location_s *format_ctx_ptr;
  unsigned stream_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure av_frame_s
 */

struct av_frame_s
{
  AVFrame *frame;
  unsigned stream_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure av_picture_s
 */

struct av_picture_s
{
  AVFrame picture;
  int width;
  int height;
  AVPixelFormat format;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class av_c
 */
class av_c
{
  public:
  inline av_c();
  inline ~av_c();
};

/*
 * inline methods of structure av_format_s
 */

inline void av_format_s::init()
{/*{{{*/
  format_ctx = nullptr;
  codec_ctxs = nullptr;
  packet.size = 0;
  proc_size = 0;
}/*}}}*/

inline void av_format_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - if packet is not empty -
  if (packet.size != 0)
  {
    av_packet_unref(&packet);
  }

  // - if format context exists -
  if (format_ctx != nullptr)
  {
    // - if codec context array exists -
    if (codec_ctxs != nullptr)
    {
      // - for each codec context -
      if (format_ctx->nb_streams > 0)
      {
        AVCodecContext **cc_ptr = codec_ctxs;
        AVCodecContext **cc_ptr_end = cc_ptr + format_ctx->nb_streams;
        do {

          // - if codec context exists -
          if (*cc_ptr != nullptr)
          {
            avcodec_close(*cc_ptr);
          }
        } while(++cc_ptr < cc_ptr_end);
      }

      // - release codec context array -
      cfree(codec_ctxs);
    }

    // - release format context -
    if (format_ctx->iformat != nullptr)
    {
      avformat_close_input(&format_ctx);
    }
    else
    {
      avformat_free_context(format_ctx);
    }
  }

  init();
}/*}}}*/

/*
 * inline methods of structure av_stream_s
 */

inline void av_stream_s::init()
{/*{{{*/
  format_ctx_ptr = nullptr;
  stream_idx = 0;
}/*}}}*/

inline void av_stream_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (format_ctx_ptr != nullptr)
  {
    it.release_location_ptr(format_ctx_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure av_frame_s
 */

inline void av_frame_s::init()
{/*{{{*/
  frame = nullptr;
  stream_idx = 0;
}/*}}}*/

inline void av_frame_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (frame != nullptr)
  {
    av_frame_free(&frame);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure av_picture_s
 */

inline void av_picture_s::init()
{/*{{{*/
  format = AV_PIX_FMT_NONE;
}/*}}}*/

inline void av_picture_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (format != AV_PIX_FMT_NONE)
  {
    av_frame_unref(&picture);
  }

  init();
}/*}}}*/

/*
 * inline methods of class av_c
 */

inline av_c::av_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libav_init()\n"););

#if LIBAVCODEC_VERSION_MAJOR < 58
  av_register_all();
#endif
  av_log_set_callback(&av_log_callback);
#if LIBAVCODEC_VERSION_MAJOR < 59
  av_lockmgr_register(&av_lock_callback);
#endif
}/*}}}*/

inline av_c::~av_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libav_exit()\n"););

#if LIBAVCODEC_VERSION_MAJOR < 59
  av_lockmgr_register(nullptr);
#endif
}/*}}}*/

#endif

