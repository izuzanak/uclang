
#ifndef __UCL_AO_H
#define __UCL_AO_H

@begin
include "script_parser.h"
@end

#include "ao/ao.h"

/*
 * definition of structure ao_format_s
 */

struct ao_format_s
{
  ao_sample_format sample_format;
  location_s *matrix_loc_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class ao_c
 */
class ao_c
{
  public:
  inline ao_c();
  inline ~ao_c();
};

/*
 * inline methods of structure ao_format_s
 */

inline void ao_format_s::init()
{/*{{{*/
  matrix_loc_ptr = NULL;
}/*}}}*/

inline void ao_format_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release matrix location -
  if (matrix_loc_ptr != NULL)
  {
    it.release_location_ptr(matrix_loc_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class ao_c
 */

inline ao_c::ao_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ao_initialize()\n"););

  ao_initialize();
}/*}}}*/

inline ao_c::~ao_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ao_shutdown()\n"););

  ao_shutdown();
}/*}}}*/

#endif

