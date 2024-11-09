
@begin
include "ucl_logger.h"
@end

/*
 * methods of generated structures
 */

// -- log_file_s --
@begin
methods log_file_s
@end

bool log_file_s::rotate()
{/*{{{*/
  struct stat st;

  // - close log file -
  fclose((FILE *)file);
  file = nullptr;

  bc_array_s old_buff;
  old_buff.init();

  bc_array_s new_buff;
  new_buff.init();

  unsigned new_idx = max_count - 1;
  do
  {
    // - format name of new file -
    if (new_idx > 0)
    {
      new_buff.used = 0;
      new_buff.append_format("%s.%u",path.data,new_idx);
    }
    else
    {
      new_buff.used = 0;
      new_buff.append(path.size,path.data);
    }

    if (new_idx + 1 < max_count)
    {
      // - format name of old file -
      old_buff.used = 0;
      old_buff.append_format("%s.%u",path.data,new_idx + 1);

      // - unlink old file -
      if (stat(old_buff.data,&st) == 0)
      {
        // - ERROR -
        if (unlink(old_buff.data))
        {
          old_buff.clear();
          new_buff.clear();

          return false;
        }
      }

      // - rename new file to old file -
      if (stat(new_buff.data,&st) == 0)
      {
        // - ERROR -
        if (rename(new_buff.data,old_buff.data))
        {
          old_buff.clear();
          new_buff.clear();

          return false;
        }
      }
    }
    else
    {
      // - unlink new file -
      if (stat(new_buff.data,&st) == 0)
      {
        // - ERROR -
        if (unlink(new_buff.data))
        {
          old_buff.clear();
          new_buff.clear();

          return false;
        }
      }
    }

  } while(new_idx-- != 0);

  // - open new log file -
  if ((file = fopen(new_buff.data,"a")) == nullptr)
  {
    old_buff.clear();
    new_buff.clear();

    return false;
  }

  old_buff.clear();
  new_buff.clear();

  return true;
}/*}}}*/

// -- log_file_tree_s --
@begin
methods log_file_tree_s
@end

/*
 * methods of structure logger_s
 */

bool logger_s::add_file(unsigned a_level,string_s &a_path,
    unsigned a_max_size,unsigned a_max_count)
{/*{{{*/
  FILE *file;

  // - ERROR -
  if ((file = fopen(a_path.data,"a")) == nullptr)
  {
    return false;
  }

  log_file_s log_file;
  log_file.init();
  log_file.set(a_level,a_path,a_max_size,a_max_count,file);

  // - add log file to logger -
  files.swap_insert(log_file);
  log_file.clear();

  return true;
}/*}}}*/

bool logger_s::write_buffer(unsigned a_level,const bc_array_s &a_buffer)
{/*{{{*/

  // - write ok flag -
  bool write_ok = true;

  if (files.root_idx != c_idx_not_exist)
  {
    log_file_tree_s_node *lftn_ptr = files.data;
    log_file_tree_s_node *lftn_ptr_end = lftn_ptr + files.used;
    do {
      if (lftn_ptr->valid)
      {
        log_file_s &log_file = lftn_ptr->object;

        // - check log level -
        if (log_file.level >= a_level)
        {
          if (!log_file.write(a_buffer))
          {
            write_ok = false;
          }
        }
      }
    } while(++lftn_ptr < lftn_ptr_end);
  }

  return write_ok;
}/*}}}*/

