
#ifndef __UCL_PORTAUDIO_H
#define __UCL_PORTAUDIO_H

@begin
include "script_parser.h"
@end

#include "portaudio.h"

/*
 * definition of structure pa_device_s
 */

struct pa_device_s
{
  PaDeviceIndex index;
  const PaDeviceInfo *di_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure pa_stream_s
 */

struct pa_stream_s
{
  PaStream *stream_ptr;
  const PaStreamInfo *info_ptr;
  location_s *input_ptr;
  location_s *output_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class port_audio_c
 */
class port_audio_c
{
  public:
  inline port_audio_c();
  inline ~port_audio_c();
};

/*
 * inline methods of structure pa_device_s
 */

inline void pa_device_s::init()
{/*{{{*/
  index = -1;
  di_ptr = nullptr;
}/*}}}*/

inline void pa_device_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure pa_stream_s
 */

inline void pa_stream_s::init()
{/*{{{*/
  stream_ptr = nullptr;
  info_ptr = nullptr;
  input_ptr = nullptr;
  output_ptr = nullptr;
}/*}}}*/

inline void pa_stream_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (stream_ptr != nullptr)
  {
    Pa_CloseStream(stream_ptr);
  }

  // - release input parameters location -
  if (input_ptr != nullptr)
  {
    it.release_location_ptr(input_ptr);
  }

  // - release output parameters location -
  if (output_ptr != nullptr)
  {
    it.release_location_ptr(output_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class port_audio_c
 */

inline port_audio_c::port_audio_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"Pa_Initialize()\n"););

  Pa_Initialize();
}/*}}}*/

inline port_audio_c::~port_audio_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"Pa_Terminate()\n"););

  Pa_Terminate();
}/*}}}*/

#endif

