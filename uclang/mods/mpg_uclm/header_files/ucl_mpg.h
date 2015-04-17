
#ifndef __UCL_MPG_H
#define __UCL_MPG_H

@begin
include "script_parser.h"
@end

#include "mpg123.h"

/*
 * basic definitions and constants
 */

enum
{
  c_mpg_handle_type_none = 0,
  c_mpg_handle_type_file,
  c_mpg_handle_type_feed,
};

/*
 * definition of structure mpg_handle_s
 */

struct mpg_handle_s
{
  mpg123_handle *handle;
  unsigned type;

  long int rate;
  int channels;
  int encoding;

  inline void init();
  inline void init_format();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class mpg_c
 */
class mpg_c
{
  public:
  inline mpg_c();
  inline ~mpg_c();
};

/*
 * inline methods of structure mpg_handle_s
 */

inline void mpg_handle_s::init()
{/*{{{*/
  handle = NULL;
  type = c_mpg_handle_type_none;
  init_format();
}/*}}}*/


inline void mpg_handle_s::init_format()
{/*{{{*/
  rate = -1;
  channels = -1;
  encoding = -1;
}/*}}}*/

inline void mpg_handle_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release handle -
  if (handle != NULL)
  {
    mpg123_close(handle);
    mpg123_delete(handle);
  }

  init();
}/*}}}*/

/*
 * inline methods of class mpg_c
 */

inline mpg_c::mpg_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"mpg123_init()\n"););

  mpg123_init();
}/*}}}*/

inline mpg_c::~mpg_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"mpg123_exit()\n"););

  mpg123_exit();
}/*}}}*/

#endif

