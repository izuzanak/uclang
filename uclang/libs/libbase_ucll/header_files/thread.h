
#ifndef __THREAD_H
#define __THREAD_H

@begin
include "basic.h"
@end

/*
 * definition of structure thread_s
 */

@begin
define thread_s dynamic
@end

struct thread_s
{
#if THREAD_LIB == THREAD_LIB_PTHREAD
  pthread_t thread;
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
  TSK_Handle tsk_handle;
#endif

  inline void init()
  {
    debug_message_2(fprintf(stderr,"thread_s::init()\n"););
  }
  inline void clear()
  {
    debug_message_2(fprintf(stderr,"thread_s::clear()\n"););
  }
  inline void flush_all() {}
  inline void swap(thread_s &a_second)
  {
    cassert(0);
  }
  inline thread_s &operator=(thread_s &a_src)
  {
    cassert(0);
    return *this;
  }
  inline bool operator==(thread_s &a_second)
  {
    cassert(0);
    return false;
  }

  /*!
   * \brief execute new thread at function with given parameters
   * \param a_thread_function - pointer to function at which will be new thread executed
   * \param a_parameters - pointer to void given as parameter to new thread
   * \return error code
   */
  inline unsigned create(void *a_thread_function,void *a_parameters);

  /*!
   * \brief create thread_s for existing thread
   */
#if THREAD_LIB == THREAD_LIB_PTHREAD
  inline void create_from_actual(pthread_t a_thread);
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
  inline void create_from_actual(TSK_Handle a_tsk_handle);
#else
#endif

  /*!
   * \brief join thread to actual thread
   * \param a_return_ptr - pointer to pointer to void at which will be stored return value of thread
   */
  inline unsigned join(void **a_return_ptr);

  /*!
   * \brief try join thread to actual thread
   * \param a_return_ptr - pointer to pointer to void at which will be stored return value of thread
   */
  inline unsigned try_join(void **a_return_ptr);

  /*!
   * \brief detach thread
   * \return error code
   */
  inline unsigned detach();

  /*!
   * \brief break running of actual thread, until it is newly scheduled for execution
   * \return error code
   */
  inline static unsigned yield();
};

/*
 * inline methods of structure thread_s
 */

inline unsigned thread_s::create(void *a_thread_function,void *a_parameters)
{/*{{{*/
#if THREAD_LIB == THREAD_LIB_PTHREAD
  int ret = pthread_create(&thread,NULL,(void *(*)(void *))a_thread_function,a_parameters);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case EAGAIN:
    return c_error_EAGAIN;
  case EINVAL:
    return c_error_EINVAL;
  default:
    return c_error_UNKNOWN;
  }
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
  tsk_handle = TSK_create((Fxn)a_thread_function,NULL,a_parameters);
  if (tsk_handle != NULL)
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

#if THREAD_LIB == THREAD_LIB_PTHREAD
inline void thread_s::create_from_actual(pthread_t a_thread)
{/*{{{*/
  thread = a_thread;
}/*}}}*/
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
inline void thread_s::create_from_actual(TSK_Handle a_tsk_handle)
{/*{{{*/
  tsk_handle = a_tsk_handle;
}/*}}}*/
#else
#endif

inline unsigned thread_s::join(void **a_return_ptr)
{/*{{{*/
#if THREAD_LIB == THREAD_LIB_PTHREAD
  int ret = pthread_join(thread,a_return_ptr);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case ESRCH:
    return c_error_ESRCH;
  case EINVAL:
    return c_error_EINVAL;
  case EDEADLK:
    return c_error_EDEADLK;
  default:
    return c_error_UNKNOWN;
  }
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
  cassert(0);
  return c_error_UNKNOWN;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned thread_s::try_join(void **a_return_ptr)
{/*{{{*/
#if THREAD_LIB == THREAD_LIB_PTHREAD
#if defined(_GNU_SOURCE) && !defined(ANDROID)
  int ret = pthread_tryjoin_np(thread,a_return_ptr);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case ESRCH:
    return c_error_ESRCH;
  case EINVAL:
    return c_error_EINVAL;
  case EDEADLK:
    return c_error_EDEADLK;
  case EBUSY:
    return c_error_EBUSY;
  default:
    return c_error_UNKNOWN;
  }
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
  cassert(0);
  return c_error_UNKNOWN;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned thread_s::detach()
{/*{{{*/
#if THREAD_LIB == THREAD_LIB_PTHREAD
  int ret = pthread_detach(thread);
  switch (ret)
  {
  case 0:
    return c_error_OK;
  case ESRCH:
    return c_error_ESRCH;
  case EINVAL:
    return c_error_EINVAL;
  default:
    return c_error_UNKNOWN;
  }
#elif THREAD_LIB == THREAD_LIB_DSP_TSK

  // - implicitly detached -
  return c_error_OK;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned thread_s::yield()
{/*{{{*/
#if THREAD_LIB == THREAD_LIB_PTHREAD

#ifdef __WIN32
  // FIXME - yield ve windows
#else
  sched_yield();
#endif

  return c_error_OK;
#elif THREAD_LIB == THREAD_LIB_DSP_TSK
  TSK_yield();
  return c_error_OK;
#else
  cassert(0);
  return c_error_UNKNOWN;
#endif
}/*}}}*/

#endif

