
#ifndef __BASIC_H
#define __BASIC_H

#define ENABLED 1
#define MP_COMMA ,

// - GCC un/likely macros -
#ifdef __GNUC__
#define likely(x) __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)
#else
#define likely(x) x
#define unlikely(x) x
#endif

#ifdef _MSC_VER
#if _MSC_VER < 1600
#define nullptr NULL
#endif
#else
#if __cplusplus < 201103
#define nullptr NULL
#endif
#endif

// - system type selection -
#define SYSTEM_TYPE_UNIX    1 // - for system calls use unix environment
#define SYSTEM_TYPE_WINDOWS 2 // - for system calls use windows environment
#define SYSTEM_TYPE_DSP     3 // - target platform is DSP processor
// --

// - atomic subsystem selection -
#define ATOMIC_TYPE_GCC     1 // - for atomic structure implementation use GCC compiler functions
#define ATOMIC_TYPE_WINDOWS 2 // - for atomic structure implementation use win32 library
// --

// - thread library selection -
#define THREAD_LIB_PTHREAD 1 // - for thread manipulation use pthread library
#define THREAD_LIB_DSP_TSK 2 // - for thread implementation use DSP Task library
#define THREAD_LIB_WINDOWS 3 // - for thread implementation use win32 library
// --

// - mutex library selection -
#define MUTEX_TYPE_PTHREAD  1 // - for mutex implementation use pthread mutex
#define MUTEX_TYPE_WINDOWS  2 // - for mutex implementation use win32 library
#define MUTEX_TYPE_DSP_LOCK 3 // - for mutex implementation use DSP task locks
// --

// - dynamic library selection -
#define DYNAMIC_TYPE_POSIX   1 // - for dynamic libraries implementation use posix
#define DYNAMIC_TYPE_WINDOWS 2 // - for dynamic libraries implementation use win32 library
// --

// - basic system configuration -
#ifdef LINUX
#define SYSTEM_TYPE SYSTEM_TYPE_UNIX
#define     SYSTEM_TYPE_UNIX_SIGACTION ENABLED
#define     SYSTEM_TYPE_UNIX_SOCKET    ENABLED
#define     SYSTEM_TYPE_UNIX_SPAWNER   ENABLED
#define ATOMIC_TYPE ATOMIC_TYPE_GCC
#define THREAD_LIB THREAD_LIB_PTHREAD
#define MUTEX_TYPE MUTEX_TYPE_PTHREAD
#define DYNAMIC_TYPE DYNAMIC_TYPE_POSIX
#define _printf_p printf
#define EXPORT
#define libbase_ucll_EXPORT
#define libnode_ucll_EXPORT
#endif

#ifdef ANDROID
#define SYSTEM_TYPE SYSTEM_TYPE_UNIX
#define     SYSTEM_TYPE_UNIX_SIGACTION ENABLED
#define     SYSTEM_TYPE_UNIX_SOCKET    ENABLED
#define ATOMIC_TYPE ATOMIC_TYPE_GCC
#define THREAD_LIB THREAD_LIB_PTHREAD
#define MUTEX_TYPE MUTEX_TYPE_PTHREAD
#define DYNAMIC_TYPE DYNAMIC_TYPE_POSIX
#define _printf_p printf
#define EXPORT
#define libbase_ucll_EXPORT
#define libnode_ucll_EXPORT
#endif

#ifdef NACL
#define SYSTEM_TYPE SYSTEM_TYPE_UNIX
#define     SYSTEM_TYPE_UNIX_CHROME_NACL ENABLED
#define ATOMIC_TYPE ATOMIC_TYPE_GCC
#define THREAD_LIB THREAD_LIB_PTHREAD
#define MUTEX_TYPE MUTEX_TYPE_PTHREAD
#define DYNAMIC_TYPE DYNAMIC_TYPE_POSIX
#define _printf_p printf
#define EXPORT
#define libbase_ucll_EXPORT
#define libnode_ucll_EXPORT
#endif

#ifdef WINDOWS
#define SYSTEM_TYPE SYSTEM_TYPE_WINDOWS
#define ATOMIC_TYPE ATOMIC_TYPE_WINDOWS
#define THREAD_LIB THREAD_LIB_WINDOWS
#define MUTEX_TYPE MUTEX_TYPE_WINDOWS
#define DYNAMIC_TYPE DYNAMIC_TYPE_WINDOWS
#define EXPORT __declspec(dllexport) 
#ifdef libbase_ucll_EXPORTS
#define libbase_ucll_EXPORT __declspec(dllexport)
#else
#define libbase_ucll_EXPORT __declspec(dllimport)
#endif
#ifdef libnode_ucll_EXPORTS
#define libnode_ucll_EXPORT __declspec(dllexport)
#else
#define libnode_ucll_EXPORT __declspec(dllimport)
#endif
#endif

// - system includes -
#if THREAD_LIB == THREAD_LIB_PTHREAD || MUTEX_TYPE == MUTEX_TYPE_PTHREAD
#include <pthread.h>
#include <sched.h>
#include <errno.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
#include <winsock2.h>
#include <windows.h>
#include <signal.h>

#ifndef LLONG_MAX
#define LLONG_MAX 9223372036854775807
#endif

#ifndef strtoll
#define strtoll _strtoi64
#endif

#ifndef snprintf
#define snprintf _snprintf
#endif
#endif

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#endif

#include <math.h>

#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
#include <dlfcn.h>
#endif

// - system long long format -
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#define HOST_LL_FORMAT "ll"
#define HOST_LL_FORMAT_LENGTH 2
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
#define HOST_LL_FORMAT "I64"
#define HOST_LL_FORMAT_LENGTH 3
#endif

// - dynamic library file extensions -
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
#ifdef EMSCRIPTEN
#define DYNAMIC_LIB_EXTENSION ".js"
#else
#define DYNAMIC_LIB_EXTENSION ".so"
#endif
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
#define DYNAMIC_LIB_EXTENSION ".dll"
#endif

// - android config -
#define ANDROID_APP_DIR "/data/data/com.example.uclang_activity"

// - chrome nacl is enabled -
#if SYSTEM_TYPE_UNIX_CHROME_NACL == ENABLED

#if defined(NACL_SDK_DEBUG)
#define CONFIG_NAME "Debug"
#else
#define CONFIG_NAME "Release"
#endif

#if defined __arm__
#define NACL_ARCH "arm"
#elif defined __i686__
#define NACL_ARCH "x86_32"
#elif defined __x86_64__
#define NACL_ARCH "x86_64"
#else
#error "Unknown architecture"
#endif

#include "sys/mount.h"

#include "ppapi/c/pp_errors.h"
#include "ppapi/c/pp_module.h"
#include "ppapi/c/pp_var.h"
#include "ppapi/c/ppb.h"
#include "ppapi/c/ppb_instance.h"
#include "ppapi/c/ppp.h"
#include "ppapi/c/ppp_instance.h"
#include "ppapi/c/ppp_messaging.h"

#include "nacl_io/nacl_io.h"
#endif

// - asserts definitions -
//#define DEBUG_ASSERT ENABLED
#define CASSERT ENABLED

#if DEBUG_ASSERT == ENABLED
#define debug_assert(A_COND)\
  {\
    if (!(A_COND)) {\
      fprintf(stderr,"DEBUG_ASSERT: %s, line: %d, function: %s\n",__FILE__,__LINE__,__FUNCTION__);\
      fflush(stderr);\
      abort();\
    }\
  }
#else
#define debug_assert(A_COND)
#endif

#if CASSERT == ENABLED
#define cassert(A_COND)\
  {\
    if (!(A_COND)) {\
      fprintf(stderr,"CASSERT: %s, line: %d, function: %s\n",__FILE__,__LINE__,__FUNCTION__);\
      fflush(stderr);\
      abort();\
    }\
  }
#else
#define cassert(A_COND)
#endif

// - name and version string constants -
libbase_ucll_EXPORT extern const char *c_name_str;
libbase_ucll_EXPORT extern const char *c_version_str;

// - basic constants -
const unsigned c_array_add = 4; // 64
const unsigned c_idx_not_exist = UINT_MAX;

// - bit count of basic types -
const unsigned INT_BIT = (sizeof(int)*CHAR_BIT);
const unsigned UINT_BIT = (sizeof(unsigned)*CHAR_BIT);

// - pi number definitions -
const float c_pi_number = 3.14159265358979323844f;
const float c_2pi_number = 6.28318530717958647688f;
const float c_pid2_number = 1.57079632679489661922f;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = logf(2.0f);

// - red-black tree descent stack size -
#ifdef _MSC_VER
#define RB_TREE_STACK_SIZE(VAR) 32
#else
#define RB_TREE_STACK_SIZE(VAR) (VAR).get_descent_stack_size()
#endif

// - system errors and exceptions -
enum  
{/*{{{*/
  c_error_OK = 0,
  c_error_UNKNOWN,

  c_error_EINVAL,
  c_error_EDEADLK,
  c_error_EBUSY,
  c_error_EPERM,
  c_error_EAGAIN,
  c_error_ESRCH,

  // - global errors -
  c_error_USER_EXCEPTION,
  c_error_TODO_EXCEPTION,

  // - run_expression -
  c_error_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR,

  c_error_CLASS_DOES_NOT_CONTAIN_METHOD,
  c_error_CLASS_DOES_NOT_CONTAIN_VARIABLE,

  c_error_CANNOT_ACCESS_PRIVATE_METHOD,
  c_error_CANNOT_ACCESS_PRIVATE_VARIABLE,

  c_error_METHOD_CANNOT_RETURN_VALUE,
  c_error_CANNOT_TEST_TYPE_VALUE,

  c_error_CANNOT_CONVERT_TYPE_TO_INTEGER,
  c_error_CANNOT_USE_NEGATIVE_NUMBER,

  c_error_SLICE_NOT_INTEGER_ARGUMENTS,
  c_error_SLICE_START_LESS_THAN_ZERO,
  c_error_SLICE_STOP_LESS_THAN_ZERO,
  c_error_SLICE_STEP_EQUAL_TO_ZERO,

  c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,
  c_error_UNEXPECTED_END_OF_ITERABLE,

  // - built_in -
  c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,

  c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,
  c_error_WRONG_METHOD_PARAMETER_VALUE,

  c_error_DIVISION_BY_ZERO,
  c_error_NEGATIVE_SHIFT_COUNT,

  c_error_METHOD_NOT_RETURN_INTEGER,
  c_error_METHOD_NOT_RETURN_STRING,
  c_error_METHOD_NOT_RETURN_INDEX,

  c_error_INTEGER_BASE_OUT_OF_RANGE,
  c_error_INTEGER_CONVERT_INVALID_STRING,

  c_error_FLOAT_CONVERT_INVALID_STRING,

  c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,
  c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE,
  c_error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR,
  c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER,
  c_error_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED,

  c_error_STRING_INDEX_EXCEEDS_RANGE,
  c_error_STRING_WRONG_RANGE_INDEXES,
  c_error_STRING_CONVERT_FROM_INTEGER,
  c_error_STRING_CONVERT_FROM_FLOAT,

  c_error_ARRAY_INDEX_EXCEEDS_RANGE,
  c_error_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE,
  c_error_ARRAY_NO_ELEMENTS,
  c_error_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH,

  c_error_DELEGATE_NEGATIVE_PARAMETER_COUNT,
  c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,
  c_error_DELEGATE_CALL_WRONG_PARAMETER_COUNT,
  c_error_DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT,
  c_error_DELEGATE_WRONG_RETURN_VALUE_TYPE,

};/*}}}*/

#define DEBUG_MESSAGES 0

#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_0(MSG) fprintf(stderr,"thread %u, DLvl. 0: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_0(MSG) fprintf(stderr,"DLvl. 0: "); MSG
#endif

#if DEBUG_MESSAGES >= 1
#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_1(MSG) fprintf(stderr,"thread %u, DLvl. 1: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_1(MSG) fprintf(stderr,"DLvl. 1: "); MSG
#endif
#else
#define debug_message_1(MSG)
#endif

#if DEBUG_MESSAGES >= 2
#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_2(MSG) fprintf(stderr,"thread %u, DLvl. 2: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_2(MSG) fprintf(stderr,"DLvl. 2: "); MSG
#endif
#else
#define debug_message_2(MSG)
#endif

#if DEBUG_MESSAGES >= 3
#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_3(MSG) fprintf(stderr,"thread %u, DLvl. 3: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_3(MSG) fprintf(stderr,"DLvl. 3: "); MSG
#endif
#else
#define debug_message_3(MSG)
#endif

#if DEBUG_MESSAGES >= 4
#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_4(MSG) fprintf(stderr,"thread %u, DLvl. 4: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_4(MSG) fprintf(stderr,"DLvl. 4: "); MSG
#endif
#else
#define debug_message_4(MSG)
#endif

#if DEBUG_MESSAGES >= 5
#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_5(MSG) fprintf(stderr,"thread %u, DLvl. 5: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_5(MSG) fprintf(stderr,"DLvl. 5: "); MSG
#endif
#else
#define debug_message_5(MSG)
#endif

#if DEBUG_MESSAGES >= 6
#if THREAD_LIB == THREAD_LIB_PTHREAD
#define debug_message_6(MSG) fprintf(stderr,"thread %u, DLvl. 6: ",(unsigned)pthread_self()); MSG
#else
#define debug_message_6(MSG) fprintf(stderr,"DLvl. 6: "); MSG
#endif
#else
#define debug_message_6(MSG)
#endif

// - t_ps_uint should have always same size as pointer -
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX || SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
typedef long unsigned t_ps_uint;
#elif SYSTEM_TYPE == SYSTEM_TYPE_DSP
typedef unsigned t_ps_uint;
#endif

// - cont basic types -
typedef bool bb;
typedef char bc;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef int bi;
typedef unsigned int ui;
typedef long int li;
typedef unsigned long uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef float bf;
typedef double bd;
typedef long double ld;

// - pointer typedef -
typedef void * pointer;
@begin
define pointer basic
@end

// - pointer_ptr typedef -
typedef void ** pointer_ptr;
@begin
define pointer_ptr basic
@end

// - time measuring data structures -
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
extern struct timeval tv;
extern struct timeval stv;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
libbase_ucll_EXPORT extern long long unsigned tick_cnt;
#endif

// - mark time in nanoseconds -
inline void tm_mark_time()
{/*{{{*/
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  gettimeofday(&tv,nullptr);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  tick_cnt = GetTickCount64();
#endif
}/*}}}*/

// - compute difference of actual time from marked time -
inline long long int tm_time_diff()
{/*{{{*/
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  gettimeofday(&stv,nullptr);
  return stv.tv_usec - tv.tv_usec + (stv.tv_sec - tv.tv_sec)*1000000LL;
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  return (GetTickCount64() - tick_cnt)*1000;
#else
  return 0;
#endif
}/*}}}*/

// - definition of cmalloc function -
inline void *cmalloc(unsigned a_size)
{/*{{{*/
  return malloc(a_size);
}/*}}}*/

// - definition of crealloc function -
inline void *crealloc(void *a_location,unsigned a_size)
{/*{{{*/
  return realloc(a_location,a_size);
}/*}}}*/

// - definition of cfree function -
inline void cfree(void *a_location)
{/*{{{*/
  free(a_location);
}/*}}}*/

// - memcpy with byte order change on request -
inline void memcpy_bo(void *a_dst,const void *a_src,size_t a_cnt,bool a_ob)
{/*{{{*/
  if (a_cnt <= 0)
  {
    return;
  }

  if (a_ob)
  {
    char *d_ptr = (char *)a_dst;
    char *d_ptr_end = d_ptr + a_cnt;
    const char *s_ptr = ((const char *)a_src) + a_cnt - 1;

    switch (a_cnt)
    {
    case 8: *d_ptr++ = *s_ptr--;
    case 7: *d_ptr++ = *s_ptr--;
    case 6: *d_ptr++ = *s_ptr--;
    case 5: *d_ptr++ = *s_ptr--;
    case 4: *d_ptr++ = *s_ptr--;
    case 3: *d_ptr++ = *s_ptr--;
    case 2: *d_ptr++ = *s_ptr--;
    case 1: *d_ptr++ = *s_ptr--;
      break;
    default:
      do {
        *d_ptr = *s_ptr;
      } while(--s_ptr,++d_ptr < d_ptr_end);
    }
  }
  else
  {
    memcpy(a_dst,a_src,a_cnt);
  }
}/*}}}*/

/*
 * definitions of generated structures
 */

/*
 * inline methods of generated structures
 */

#endif

