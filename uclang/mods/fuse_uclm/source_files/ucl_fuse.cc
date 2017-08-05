
@begin
include "ucl_fuse.h"
@end

// - external error identifiers -
unsigned c_ext_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE = c_idx_not_exist;

// - fuse global init object -
fuse_c g_fuse;

/*
 * methods of structure fuse_handle_s
 */

void *fuse_handle_s::cb_fuse_init(struct fuse_conn_info *conn)
{/*{{{*/
  location_s *fhnd_location = (location_s *)fuse_get_context()->private_data;
  fuse_handle_s *fhnd_ptr = (fuse_handle_s *)fhnd_location->v_data_ptr;

  // - retrieve callback delegate -
  fuse_operations_s *fops_ptr = (fuse_operations_s *)fhnd_ptr->fuse_operations_ptr->v_data_ptr;
  location_s *dlg_location = (location_s *)fops_ptr->fuse_ops_dlgs[c_fuse_init];

  // - if init delegate is set -
  if (dlg_location != nullptr)
  {
    interpreter_thread_s &it = *fhnd_ptr->it_ptr;
    delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;

    // - call delegate method -
    location_s *trg_location = nullptr;
    BIC_CALL_DELEGATE(it,delegate_ptr,nullptr,0,trg_location,fhnd_ptr->source_pos,
        fhnd_ptr->ret_code = c_run_return_code_EXCEPTION;

        // - exit from fuse event loop -
        fuse_exit(fhnd_ptr->fuse_ptr);

        return fhnd_location;
        );
    it.release_location_ptr(trg_location);
  }

  return fhnd_location;
}/*}}}*/

#define FUSE_CALL_CALLBACK_DELEGATE(DELEGATE_ID,PARAM_DATA,PARAM_CNT,PARAM_CODE) \
{/*{{{*/\
  location_s *fhnd_location = (location_s *)fuse_get_context()->private_data;\
  fuse_handle_s *fhnd_ptr = (fuse_handle_s *)fhnd_location->v_data_ptr;\
\
  interpreter_thread_s &it = *fhnd_ptr->it_ptr;\
\
  /* - retrieve callback delegate - */\
  fuse_operations_s *fops_ptr = (fuse_operations_s *)fhnd_ptr->fuse_operations_ptr->v_data_ptr;\
  location_s *dlg_location = (location_s *)fops_ptr->fuse_ops_dlgs[DELEGATE_ID];\
  delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;\
\
  PARAM_CODE;\
\
  /* - call delegate method - */\
  location_s *trg_location = nullptr;\
  BIC_CALL_DELEGATE(it,delegate_ptr,PARAM_DATA,PARAM_CNT,trg_location,fhnd_ptr->source_pos,\
      fhnd_ptr->ret_code = c_run_return_code_EXCEPTION;\
\
      /* - exit from fuse event loop - */\
      fuse_exit(fhnd_ptr->fuse_ptr);\
\
      return 0;\
      );\
\
  long long int ret_value;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(trg_location,ret_value))\
  {\
    it.release_location_ptr(trg_location);\
\
    exception_s::throw_exception(it,c_ext_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE,fhnd_ptr->source_pos,(location_s *)it.blank_location);\
    fhnd_ptr->ret_code = c_run_return_code_EXCEPTION;\
\
    /* - exit from fuse event loop - */\
    fuse_exit(fhnd_ptr->fuse_ptr);\
\
    return 0;\
  }\
\
  it.release_location_ptr(trg_location);\
\
  return ret_value;\
}/*}}}*/

int fuse_handle_s::cb_fuse_getattr(const char *path, struct stat *stbuf)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_getattr,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(stat_location,c_bi_class_fuse_stat,stbuf,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA stat_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_readdir(const char *path,void *buf,fuse_fill_dir_t filler,off_t offset,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_readdir,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create fuse dir filler parameter -
    fuse_dir_filler_s *fdf_ptr = (fuse_dir_filler_s *)cmalloc(sizeof(fuse_dir_filler_s));
    fdf_ptr->init();

    fdf_ptr->buffer = buf;
    fdf_ptr->filler = filler;
    fdf_ptr->offset = offset;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(fdf_location,c_bi_class_fuse_dir_filler,fdf_ptr,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {
      path_location
      MP_COMMA fdf_location
      MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_open(const char *path,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_open,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_release(const char *path,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_release,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_opendir(const char *path,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_opendir,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_releasedir(const char *path,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_releasedir,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_read(const char *path,char *buf,size_t size,off_t offset,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_read,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create fuse file filler parameter -
    fuse_file_filler_s *fff_ptr = (fuse_file_filler_s *)cmalloc(sizeof(fuse_file_filler_s));
    fff_ptr->init();

    fff_ptr->buffer = buf;
    fff_ptr->size = size;
    fff_ptr->offset = offset;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(fff_location,c_bi_class_fuse_file_filler,fff_ptr,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {
      path_location
      MP_COMMA fff_location
      MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_write(const char *path,const char *buf,size_t size,off_t offset,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_write,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create data parameter -
    string_s *data_str = it.get_new_string_ptr();
    data_str->set(size,buf);

    // - create offset parameter -
    long long int lli_offset = offset;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(data_location,c_bi_class_string,data_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(off_location,c_bi_class_integer,lli_offset,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 4;
    pointer param_data[param_cnt] = {
      path_location
      MP_COMMA data_location
      MP_COMMA off_location
      MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_create(const char *path,mode_t mode,struct fuse_file_info *fi)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_create,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create mode parameter -
    long long int lli_mode = mode;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(mode_location,c_bi_class_integer,lli_mode,0);
    BIC_CREATE_NEW_LOCATION_REFS(ffi_location,c_bi_class_fuse_file_info,fi,0);

    // - callback parameters -
    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {path_location
      MP_COMMA mode_location
      MP_COMMA ffi_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_unlink(const char *path)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_unlink,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);

    // - callback parameters -
    const unsigned param_cnt = 1;
    pointer param_data[param_cnt] = {path_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_mkdir(const char *path,mode_t mode)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_mkdir,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create mode parameter -
    long long int lli_mode = mode;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(mode_location,c_bi_class_integer,lli_mode,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA mode_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_rmdir(const char *path)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_rmdir,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);

    // - callback parameters -
    const unsigned param_cnt = 1;
    pointer param_data[param_cnt] = {path_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_rename(const char *path,const char *new_path)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_rename,param_data,param_cnt,

    // - create old path parameter -
    string_s *old_str = it.get_new_string_ptr();
    old_str->set(strlen(path),path);

    // - create new path parameter -
    string_s *new_str = it.get_new_string_ptr();
    new_str->set(strlen(new_path),new_path);

    BIC_CREATE_NEW_LOCATION_REFS(old_location,c_bi_class_string,old_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,new_str,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {old_location MP_COMMA new_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_truncate(const char *path,off_t size)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_truncate,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create size parameter -
    long long int lli_size = size;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(size_location,c_bi_class_integer,lli_size,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA size_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_chmod(const char *path, mode_t mode)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_chmod,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create mode parameter -
    long long int lli_mode = mode;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(mode_location,c_bi_class_integer,lli_mode,0);

    // - callback parameters -
    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {path_location MP_COMMA mode_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_chown(const char *path, uid_t uid, gid_t gid)
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_chown,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create uid parameter -
    long long int lli_uid = uid;

    // - create gid parameter -
    long long int lli_gid = gid;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(uid_location,c_bi_class_integer,lli_uid,0);
    BIC_CREATE_NEW_LOCATION_REFS(gid_location,c_bi_class_integer,lli_gid,0);

    // - callback parameters -
    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {path_location
      MP_COMMA uid_location
      MP_COMMA gid_location};
  );
}/*}}}*/

int fuse_handle_s::cb_fuse_utimens(const char *path, const struct timespec tv[2])
{/*{{{*/
  FUSE_CALL_CALLBACK_DELEGATE(c_fuse_utimens,param_data,param_cnt,

    // - create path parameter -
    string_s *path_str = it.get_new_string_ptr();
    path_str->set(strlen(path),path);

    // - create atime parameter -
    long long int atime = tv[0].tv_sec*1000000000LL + tv[0].tv_nsec;

    // - create mtime parameter -
    long long int mtime = tv[1].tv_sec*1000000000LL + tv[1].tv_nsec;

    BIC_CREATE_NEW_LOCATION_REFS(path_location,c_bi_class_string,path_str,0);
    BIC_CREATE_NEW_LOCATION_REFS(atime_location,c_bi_class_integer,atime,0);
    BIC_CREATE_NEW_LOCATION_REFS(mtime_location,c_bi_class_integer,mtime,0);

    // - callback parameters -
    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {path_location
      MP_COMMA atime_location
      MP_COMMA mtime_location};
  );
}/*}}}*/

