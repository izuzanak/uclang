
#ifndef __UCL_ATOMIC_H
#define __UCL_ATOMIC_H

@begin
include "basic.h"
@end

/*
 * definition of structure atomic_s
 */

@begin
define atomic_s static
@end

struct atomic_s
{
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  volatile int counter;
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  volatile LONG counter;
#endif

  inline void init() {}
  inline void clear() {}
  inline void swap(atomic_s &a_second)
  {
    cassert(0);
  }
  inline atomic_s &operator=(atomic_s &a_src)
  {
    cassert(0);
    return *this;
  }
  inline bool operator==(atomic_s &a_second)
  {
    cassert(0);
    return false;
  }

  /*!
   * \brief print atomic variable value
   */
  inline void print();

  /*!
   * \brief return value of atomic variable as integer
   */
  inline int value();

  /*!
   * \brief set atomic variable to given value
   * \param a_value - new value of atomic variable
   */
  inline void atomic_set(int a_value);

  /*!
   * \brief increase atomic variable by one
   */
  inline void atomic_inc();

  /*!
   * \brief decrease atomic variable by one
   */
  inline void atomic_dec();

  /*!
   * \brief add value to atomic variable
   * \param a_value - added value
   */
  inline void atomic_add(int a_value);

  /*!
   * \brief decrease atomic variable by one and return 1 if new value is equal to 0
   */
  inline int atomic_dec_and_test();

  /*!
   * \brief increase atomic variable by one and return 1 if new value is equal to a_test
   */
  inline int atomic_inc_and_test(int a_test);
};

/*
 * inline methods of structure atomic_s
 */

inline void atomic_s::print()
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  printf("atomic: %d",counter);
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  printf("atomic: %ld",counter);
#else
  cassert(0);
#endif
}/*}}}*/

inline int atomic_s::value()
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  return counter;
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  return counter;
#else
  cassert(0);
#endif
}/*}}}*/

inline void atomic_s::atomic_set(int a_value)
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  counter = a_value;
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  InterlockedExchange(&counter,a_value);
#else
  cassert(0);
#endif
}/*}}}*/

inline void atomic_s::atomic_inc()
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  __sync_add_and_fetch(&counter,1);
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  InterlockedIncrement(&counter);
#else
  cassert(0);
#endif
}/*}}}*/

inline void atomic_s::atomic_dec()
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  __sync_sub_and_fetch(&counter,1);
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  InterlockedDecrement(&counter);
#else
  cassert(0);
#endif
}/*}}}*/

inline void atomic_s::atomic_add(int a_value)
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  __sync_add_and_fetch(&counter,a_value);
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  InterlockedExchangeAdd(&counter,a_value);
#else
  cassert(0);
#endif
}/*}}}*/

inline int atomic_s::atomic_dec_and_test()
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  return __sync_sub_and_fetch(&counter,1) == 0;
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  return InterlockedDecrement(&counter) == 0;
#else
  cassert(0);
#endif
}/*}}}*/

inline int atomic_s::atomic_inc_and_test(int a_test)
{/*{{{*/
#if ATOMIC_TYPE == ATOMIC_TYPE_GCC
  return __sync_add_and_fetch(&counter,1) == a_test;
#elif ATOMIC_TYPE == ATOMIC_TYPE_WINDOWS
  return InterlockedIncrement(&counter) == a_test;
#else
  cassert(0);
#endif
}/*}}}*/

#endif

