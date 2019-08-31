
#ifndef __UCL_LOGGER_H
#define __UCL_LOGGER_H

@begin
include "script_parser.h"
@end

/*
 * definition of generated structures
 */

// -- log_file_s --
@begin
struct
<
ui:level
string_s:path
ui:max_size
ui:max_count
pointer:file
>

additions
{
  bool rotate();
  inline bool write(const bc_array_s &a_buffer);
}

log_file_s;
@end

// -- log_file_tree_s --
@begin
safe_rb_tree<log_file_s> log_file_tree_s;
@end

/*
 * definition of structure logger_s
 */

struct logger_s
{
  string_s user;
  log_file_tree_s files;
  bc_array_s buffer;

  bool add_file(unsigned a_level,string_s &a_path,
      unsigned a_max_size,unsigned a_max_count);
  bool write(unsigned a_level,const string_s &a_message);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- log_file_s --
@begin
inlines log_file_s
@end


inline bool log_file_s::write(const bc_array_s &a_buffer)
{/*{{{*/

  // - ERROR -
  if (file == nullptr)
  {
    return false;
  }

  // - ERROR -
  long count = ftell((FILE *)file);
  if (count == -1)
  {
    return false;
  }

  // - maximal byte count exceeded -
  if (count + a_buffer.used > max_size)
  {
    // - ERROR -
    if (!rotate())
    {
      return false;
    }
  }

  // - ERROR -
  if ((fwrite(a_buffer.data,1,a_buffer.used,(FILE *)file) != a_buffer.used) ||
      fflush((FILE *)file) != 0)
  {
    return false;
  }

  return true;
}/*}}}*/

// -- log_file_tree_s --
@begin
inlines log_file_tree_s
@end

inline int log_file_tree_s::__compare_value(log_file_s &a_first,log_file_s &a_second)
{/*{{{*/
  const string_s &f_path = a_first.path;
  const string_s &s_path = a_second.path;

  if (f_path.size < s_path.size) { return -1; }
  if (f_path.size > s_path.size) { return 1; }
  return memcmp(f_path.data,s_path.data,f_path.size - 1);
}/*}}}*/

/*
 * inline methods of structure logger_s
 */

inline void logger_s::init()
{/*{{{*/
  user.init();
  files.init();
  buffer.init();
}/*}}}*/

inline void logger_s::clear(interpreter_thread_s &it)
{/*{{{*/
  user.clear();

  // - close opened log files -
  if (files.root_idx != c_idx_not_exist)
  {
    log_file_tree_s_node *lftn_ptr = files.data;
    log_file_tree_s_node *lftn_ptr_end = lftn_ptr + files.used;
    do {
      if (lftn_ptr->valid)
      {
        fclose((FILE *)lftn_ptr->object.file);
      }
    } while(++lftn_ptr < lftn_ptr_end);
  }

  files.clear();
  buffer.clear();

  init();
}/*}}}*/

#endif

