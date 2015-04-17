
#ifndef __UCL_FUSE_H
#define __UCL_FUSE_H

@begin
include "script_parser.h"
@end

#define FUSE_USE_VERSION 26
#include <fuse.h>

// - FUSE indexes of built in classes -
extern unsigned c_bi_class_fuse_channel;
extern unsigned c_bi_class_fuse_ops;
extern unsigned c_bi_class_fuse_handle;
extern unsigned c_bi_class_fuse_context;
extern unsigned c_bi_class_fuse_stat;
extern unsigned c_bi_class_fuse_file_info;
extern unsigned c_bi_class_fuse_dir_filler;
extern unsigned c_bi_class_fuse_file_filler;

// - external error identifiers -
extern unsigned c_ext_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE;

enum
{/*{{{*/
  c_fuse_getattr = 1,
  c_fuse_readlink,
  c_fuse_getdir,
  c_fuse_mknod,
  c_fuse_mkdir,
  c_fuse_unlink,
  c_fuse_rmdir,
  c_fuse_symlink,
  c_fuse_rename,
  c_fuse_link,
  c_fuse_chmod,
  c_fuse_chown,
  c_fuse_truncate,
  c_fuse_utime,
  c_fuse_open,
  c_fuse_read,
  c_fuse_write,
  c_fuse_statfs,
  c_fuse_flush,
  c_fuse_release,
  c_fuse_fsync,
  c_fuse_setxattr,
  c_fuse_getxattr,
  c_fuse_listxattr,
  c_fuse_removexattr,
  c_fuse_opendir,
  c_fuse_readdir,
  c_fuse_releasedir,
  c_fuse_fsyncdir,
  c_fuse_init,
  c_fuse_destroy,
  c_fuse_access,
  c_fuse_create,
  c_fuse_ftruncate,
  c_fuse_fgetattr,
  c_fuse_lock,
  c_fuse_utimens,
  c_fuse_bmap,
  c_fuse_ioctl,
  c_fuse_poll,
  c_fuse_write_buf,
  c_fuse_read_buf,
  c_fuse_flock,
  c_fuse_fallocate,
  c_fuse_ops_count,
};/*}}}*/

/*
 * definition of structure fuse_channel_s
 */

struct fuse_channel_s
{
  string_s mountpoint;
  struct fuse_chan *fuse_chan_ptr;
  bool attached;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure fuse_operations_s
 */

struct fuse_operations_s
{
  struct fuse_operations fuse_ops;
  pointer_array_s fuse_ops_dlgs;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure fuse_handle_s
 */

struct fuse_handle_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  location_s *fuse_channel_ptr;
  location_s *fuse_operations_ptr;
  location_s *private_data_ptr;
  struct fuse *fuse_ptr;

  static void *cb_fuse_init(struct fuse_conn_info *conn);
  static int cb_fuse_getattr(const char *path, struct stat *stbuf);
  static int cb_fuse_readdir(const char *path,void *buf,fuse_fill_dir_t filler,off_t offset,struct fuse_file_info *fi);
  static int cb_fuse_open(const char *path,struct fuse_file_info *fi);
  static int cb_fuse_release(const char *path,struct fuse_file_info *fi);
  static int cb_fuse_opendir(const char *path,struct fuse_file_info *fi);
  static int cb_fuse_releasedir(const char *path,struct fuse_file_info *fi);
  static int cb_fuse_read(const char *path,char *buf,size_t size,off_t offset,struct fuse_file_info *fi);
  static int cb_fuse_write(const char *path,const char *buf,size_t size,off_t offset,struct fuse_file_info *fi);
  static int cb_fuse_create(const char *path,mode_t mode,struct fuse_file_info *fi);
  static int cb_fuse_unlink(const char *path);
  static int cb_fuse_mkdir(const char *path,mode_t mode);
  static int cb_fuse_rmdir(const char *path);
  static int cb_fuse_rename(const char *path,const char *new_path);
  static int cb_fuse_truncate(const char *path,off_t size);
  static int cb_fuse_chmod(const char *path, mode_t mode);
  static int cb_fuse_chown(const char *path, uid_t uid, gid_t gid);
  static int cb_fuse_utimens(const char *path, const struct timespec tv[2]);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class fuse_c
 */
class fuse_c
{
  public:
  inline fuse_c();
  inline ~fuse_c();
};

/*
 * definition of structure fuse_dir_filler_s
 */

struct fuse_dir_filler_s
{
  void *buffer;
  fuse_fill_dir_t filler;
  off_t offset;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure fuse_file_filler_s
 */

struct fuse_file_filler_s
{
  char *buffer;
  size_t size;
  off_t offset;
  unsigned writed;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure fuse_channel_s
 */

inline void fuse_channel_s::init()
{/*{{{*/
  mountpoint.init();
  fuse_chan_ptr = NULL;
  attached = false;
}/*}}}*/

inline void fuse_channel_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (fuse_chan_ptr != NULL)
  {
    // - if channel is attached to handle -
    if (attached)
    {
      fuse_unmount(mountpoint.data,NULL);
    }
    else
    {
      fuse_unmount(mountpoint.data,fuse_chan_ptr);
    }
  }

  mountpoint.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure fuse_operations_s
 */

inline void fuse_operations_s::init()
{/*{{{*/
  memset(&fuse_ops,0,sizeof(struct fuse_operations));
  fuse_ops_dlgs.init();
}/*}}}*/

inline void fuse_operations_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release fuse operations delegates -
  if (fuse_ops_dlgs.used != 0)
  {
    pointer *d_ptr = fuse_ops_dlgs.data;
    pointer *d_ptr_end = d_ptr + fuse_ops_dlgs.used;
    do {

      // - if delegate is set -
      if (*d_ptr != NULL)
      {
        it.release_location_ptr((location_s *)*d_ptr);
      }
    } while(++d_ptr < d_ptr_end);
  }

  fuse_ops_dlgs.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure fuse_handle_s
 */

inline void fuse_handle_s::init()
{/*{{{*/
  it_ptr = NULL;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  fuse_channel_ptr = NULL;
  fuse_operations_ptr = NULL;
  private_data_ptr = NULL;
  fuse_ptr = NULL;
}/*}}}*/

inline void fuse_handle_s::clear(interpreter_thread_s &it)
{/*{{{*/
  // - release channel location -
  if (fuse_channel_ptr != NULL)
  {
    it.release_location_ptr(fuse_channel_ptr);
  }

  // - release operations location -
  if (fuse_operations_ptr != NULL)
  {
    it.release_location_ptr(fuse_operations_ptr);
  }

  // - release private data location -
  if (private_data_ptr != NULL)
  {
    it.release_location_ptr(private_data_ptr);
  }

  if (fuse_ptr != NULL)
  {
    fuse_destroy(fuse_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class fuse_c
 */

inline fuse_c::fuse_c()
{/*{{{*/
}/*}}}*/

inline fuse_c::~fuse_c()
{/*{{{*/
}/*}}}*/

/*
 * inline methods of structure fuse_dir_filler_s
 */

inline void fuse_dir_filler_s::init()
{/*{{{*/
  buffer = NULL;
  filler = NULL;
  offset = 0;
}/*}}}*/

inline void fuse_dir_filler_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure fuse_file_filler_s
 */

inline void fuse_file_filler_s::init()
{/*{{{*/
  buffer = NULL;
  size = 0;
  offset = 0;
  writed = 0;
}/*}}}*/

inline void fuse_file_filler_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

