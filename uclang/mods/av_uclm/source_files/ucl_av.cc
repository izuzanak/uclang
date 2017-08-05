
@begin
include "ucl_av.h"
@end

// - av global init object -
av_c g_av;

// - mutex lock callback function -
int av_lock_callback(void **mutex,enum AVLockOp op)
{/*{{{*/
  switch(op)
  {
    case AV_LOCK_CREATE:
      {
        // - create and initialize mutex -
        mutex_s *mutex_ptr = (mutex_s *)cmalloc(sizeof(mutex_s));
        mutex_ptr->init();

        *mutex = mutex_ptr;
        break;
      }
    case AV_LOCK_OBTAIN:
      {
        // - lock mutex -
        ((mutex_s *)*mutex)->lock();
        break;
      }
    case AV_LOCK_RELEASE:
      {
        // - unlock mutex -
        ((mutex_s *)*mutex)->unlock();
        break;
      }
    case AV_LOCK_DESTROY:
      {
        mutex_s *mutex_ptr = (mutex_s *)*mutex;

        // - clear and release mutex -
        mutex_ptr->clear();
        cfree(mutex_ptr);

        *mutex = nullptr;
        break;
      }
  }
  return 0;
}/*}}}*/

// - log callback function -
void av_log_callback(void* ptr,int level,const char *fmt,va_list vl)
{/*{{{*/
  debug_message_2(vfprintf(stderr,fmt,vl););
}/*}}}*/

