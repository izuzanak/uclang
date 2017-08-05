
#ifndef __UCL_OPENCV_H
#define __UCL_OPENCV_H

@begin
include "script_parser.h"
@end

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

/*
 * definition of structure cv_window_s
 */

struct cv_window_s
{
  string_s name;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure cv_writer_s
 */

struct cv_writer_s
{
  int width;
  int height;
  VideoWriter *writer_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class opencv_c
 */
class opencv_c
{
  public:
  inline opencv_c();
  inline ~opencv_c();
};

/*
 * inline methods of structure cv_window_s
 */

inline void cv_window_s::init()
{/*{{{*/
  name.init();
}/*}}}*/

inline void cv_window_s::clear(interpreter_thread_s &it)
{/*{{{*/
  name.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure cv_writer_s
 */

inline void cv_writer_s::init()
{/*{{{*/
  writer_ptr = nullptr;
}/*}}}*/

inline void cv_writer_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (writer_ptr != nullptr)
  {
    // - if video writer is opened -
    if (writer_ptr->isOpened())
    {
      writer_ptr->release();
    }

    delete writer_ptr;
  }

  init();
}/*}}}*/

/*
 * inline methods of class opencv_c
 */

inline opencv_c::opencv_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"cvInitSystem()\n"););

  cvInitSystem(0,nullptr);
}/*}}}*/

inline opencv_c::~opencv_c()
{/*{{{*/
}/*}}}*/

#endif

