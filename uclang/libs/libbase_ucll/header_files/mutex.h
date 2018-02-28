
#ifndef __UCL_MUTEX_H
#define __UCL_MUTEX_H

@begin
include "basic.h"
@end

/*
 * definition of structure mutex_s
 */

@begin
define mutex_s dynamic
@end

struct mutex_s
{
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
  pthread_mutex_t mutex;
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
  HANDLE handle;
#elif MUTEX_TYPE == MUTEX_TYPE_DSP_LOCK
  LCK_Handle lck_handle;
#else
#endif

  inline unsigned init();
  inline unsigned clear();
  inline void flush_all() {}
  inline void swap(mutex_s &a_second)
  {
    cassert(0);
  }
  inline mutex_s &operator=(mutex_s &a_src)
  {
    cassert(0);
    return *this;
  }
  inline bool operator==(mutex_s &a_second)
  {
    cassert(0);
    return false;
  }

  /*!
   * \brief lock mutex
   * \return error code
   */
  inline unsigned lock();

  /*!
   * \brief try to lock mutex
   * \return error code
   */
  inline unsigned try_lock();

  /*!
   * \brief unlock mutex
   * \return error code
   */
  inline unsigned unlock();
};

/*
 * inline methods of structure mutex_s
 */

inline unsigned mutex_s::init()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);

#ifndef EMSCRIPTEN
  pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
#endif

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  int ret = pthread_mutexattr_setpshared(&attr,PTHREAD_PROCESS_SHARED);
  if (ret != 0)
  {
    switch (ret)
    {
    case EINVAL:
      return c_error_EINVAL;
    default:
      return c_error_UNKNOWN;
    }
  }
#endif

  pthread_mutex_init(&mutex,&attr);
  pthread_mutexattr_destroy(&attr);
  return c_error_OK;
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
  if ((handle = CreateMutex(nullptr,FALSE,nullptr)) == nullptr)
  {
    return c_error_UNKNOWN;
  }

  return c_error_OK;
#elif MUTEX_TYPE == MUTEX_TYPE_DSP_LOCK
  lck_handle = LCK_create(nullptr);
  if (lck_handle != nullptr)
  {
    return c_error_OK;
  }
  else
  {
    return c_error_UNKNOWN;
  }
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::clear()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
  int ret = pthread_mutex_destroy(&mutex);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case EBUSY:
    return c_error_EBUSY;
  default:
    return c_error_UNKNOWN;
  }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
  if (CloseHandle(handle) == 0)
  {
    return c_error_UNKNOWN;
  }

  return c_error_OK;
#elif MUTEX_TYPE == MUTEX_TYPE_DSP_LOCK
  LCK_delete(lck_handle);
  return c_error_OK;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::lock()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
  int ret = pthread_mutex_lock(&mutex);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case EINVAL:
    return c_error_EINVAL;
  case EDEADLK:
    return c_error_EDEADLK;
  default:
    return c_error_UNKNOWN;
  }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
  DWORD ret = WaitForSingleObject(handle,INFINITE);
  if (ret == WAIT_FAILED)
  {
    return c_error_UNKNOWN;
  }

  return c_error_OK;
#elif SYSTEM_TYPE == SYSTEM_TYPE_DSP
  bool ret = LCK_pend(lck_handle,SYS_FOREVER);
  return ret?c_error_OK:c_error_UNKNOWN;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::try_lock()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
  int ret = pthread_mutex_trylock(&mutex);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case EBUSY:
    return c_error_EBUSY;
  case EINVAL:
    return c_error_EINVAL;
  default:
    return c_error_UNKNOWN;
  }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
  DWORD ret = WaitForSingleObject(handle,(DWORD)0);
  switch (ret)
  {
  case WAIT_ABANDONED:
  case WAIT_OBJECT_0:
    return c_error_OK;
  case WAIT_TIMEOUT:
    return c_error_EBUSY;
  default:
    return c_error_UNKNOWN;
  }
#elif MUTEX_TYPE == MUTEX_TYPE_DSP_LOCK
  bool ret = LCK_pend(lck_handle,0);
  return ret?c_error_OK:c_error_EBUSY;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::unlock()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
  int ret = pthread_mutex_unlock(&mutex);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case EINVAL:
    return c_error_EINVAL;
  case EPERM:
    return c_error_EPERM;
  default:
    return c_error_UNKNOWN;
  }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
  if (ReleaseMutex(handle) == 0)
  {
    return c_error_UNKNOWN;
  }

  return c_error_OK;
#elif SYSTEM_TYPE == SYSTEM_TYPE_DSP
  LCK_post(lck_handle);
  return c_error_OK;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

#endif

