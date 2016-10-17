
#ifndef __UCL_UTF8PROC_H
#define __UCL_UTF8PROC_H

@begin
include "script_parser.h"
@end

#include "utf8proc.h"

/*
 * definition of structure utf8proc_s
 */

struct utf8proc_s
{
  static bool unicode_to_utf8(ui_array_s &a_ustring,bc_array_s &a_buffer);
};

#endif

