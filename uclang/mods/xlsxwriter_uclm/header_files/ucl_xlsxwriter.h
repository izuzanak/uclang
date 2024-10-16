
#ifndef __UCL_XLSXWRITER_H
#define __UCL_XLSXWRITER_H

@begin
include "script_parser.h"
@end

#include "xlsxwriter.h"

/*
 * definition of structure xlsx_workbook_s
 */

struct xlsx_workbook_s
{
  lxw_workbook *workbook;
  unsigned char *buffer;
  size_t buffer_size;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure xlsx_worksheet_s
 */

struct xlsx_worksheet_s
{
  location_s *workbook_loc;
  location_s *format_loc;
  lxw_worksheet *worksheet;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure xlsx_format_s
 */

struct xlsx_format_s
{
  location_s *workbook_loc;
  lxw_format *format;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure xlsx_workbook_s
 */

inline void xlsx_workbook_s::init()
{/*{{{*/
  workbook = nullptr;
  buffer = nullptr;
  buffer_size = 0;
}/*}}}*/

inline void xlsx_workbook_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (workbook != nullptr)
  {
    workbook_close(workbook);
  }

  if (buffer != nullptr)
  {
    free(buffer);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure xlsx_worksheet_s
 */

inline void xlsx_worksheet_s::init()
{/*{{{*/
  workbook_loc = nullptr;
  format_loc = nullptr;
  worksheet = nullptr;
}/*}}}*/

inline void xlsx_worksheet_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (workbook_loc != nullptr)
  {
    it.release_location_ptr(workbook_loc);
  }

  if (format_loc != nullptr)
  {
    it.release_location_ptr(format_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure xlsx_format_s
 */

inline void xlsx_format_s::init()
{/*{{{*/
  workbook_loc = nullptr;
  format = nullptr;
}/*}}}*/

inline void xlsx_format_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (workbook_loc != nullptr)
  {
    it.release_location_ptr(workbook_loc);
  }

  init();
}/*}}}*/

#endif

