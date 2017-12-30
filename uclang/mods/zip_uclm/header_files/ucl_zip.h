
#ifndef __UCL_ZIP_H
#define __UCL_ZIP_H

@begin
include "script_parser.h"
@end

#include <zip.h>

/*
 * definition of structure zip_index_s
 */

struct zip_index_s
{
  location_s *archive_loc;
  long long int index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure zip_file_s
 */

struct zip_file_s
{
  location_s *archive_loc;
  zip_file_t *file;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure zip_index_s
 */

inline void zip_index_s::init()
{/*{{{*/
  archive_loc = nullptr;
}/*}}}*/

inline void zip_index_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (archive_loc != nullptr)
  {
    it.release_location_ptr(archive_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure zip_file_s
 */

inline void zip_file_s::init()
{/*{{{*/
  archive_loc = nullptr;
  file = nullptr;
}/*}}}*/

inline void zip_file_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (file != nullptr)
  {
    zip_fclose(file);
  }

  if (archive_loc != nullptr)
  {
    it.release_location_ptr(archive_loc);
  }

  init();
}/*}}}*/

#endif

