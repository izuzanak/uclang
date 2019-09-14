
#ifndef __DYNLIB_H
#define __DYNLIB_H

@begin
include "basic.h"
@end

/*
 * definition of structure dynlib_s
 */

@begin
define dynlib_s dynamic
@end

struct dynlib_s
{
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  void *lib_ptr;
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  HMODULE lib_ptr;
#endif

  inline void init();
  inline void clear();
  inline void flush_all() {}
  inline void swap(dynlib_s &a_second);
  inline dynlib_s &operator=(dynlib_s &a_src)
  {
    cassert(0);
    return *this;
  }
  inline bool operator==(dynlib_s &a_second)
  {
    cassert(0);
    return false;
  }

  /*!
   * \brief open dynamic library
   * \param a_file - file containing dynamic library object
   * \param a_flags - dynamic library open flags
   * \return true if successfully opened
   */
  inline bool open(const char *a_file,unsigned a_flags);

  /*!
   * \brief return addres to which was loaded symbol from library
   * \param a_addr_ptr - pointer to pointer to which is stored address of object
   * \return true if is symbol successfully resolved
   */
  inline bool get_symbol_addr(const char *a_symbol_name,void **a_addr_ptr);

  /*!
   * \brief test if is dynamic library loaded
   * \return true if is loaded some dynamic library
   */
  inline bool is_loaded();

  /*!
   * \brief return last received error
   * \return pointer to string describing error
   */
  inline const char *get_error();
};

/*
 * inline methods of structure dynlib_s
 */

inline void dynlib_s::init()
{/*{{{*/
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  lib_ptr = nullptr;
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  lib_ptr = nullptr;
#endif
}/*}}}*/

inline void dynlib_s::clear()
{/*{{{*/
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  if (lib_ptr != nullptr)
  {
    dlclose(lib_ptr);
  }
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  if (lib_ptr != nullptr)
  {
    FreeLibrary(lib_ptr);
  }
#endif

  init();
}/*}}}*/

inline void dynlib_s::swap(dynlib_s &a_second)
{/*{{{*/
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  void *tmp_lib_ptr = lib_ptr;
  lib_ptr = a_second.lib_ptr;
  a_second.lib_ptr = tmp_lib_ptr;
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  HMODULE tmp_lib_ptr = lib_ptr;
  lib_ptr = a_second.lib_ptr;
  a_second.lib_ptr = tmp_lib_ptr;
#endif
}/*}}}*/

inline bool dynlib_s::open(const char *a_file,unsigned a_flags)
{/*{{{*/
  clear();

#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  lib_ptr = dlopen(a_file,RTLD_LAZY | a_flags);
  return lib_ptr != nullptr;
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  lib_ptr = LoadLibraryEx(a_file,NULL,a_flags);
  return lib_ptr != nullptr;
#else
  return false;
#endif
}/*}}}*/

inline bool dynlib_s::get_symbol_addr(const char *a_symbol_name,void **a_addr_ptr)
{/*{{{*/
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  *a_addr_ptr = dlsym(lib_ptr,a_symbol_name);
  return *a_addr_ptr != nullptr;
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  *a_addr_ptr = (void *)GetProcAddress(lib_ptr,a_symbol_name);
  return *a_addr_ptr != nullptr;
#else
  return false;
#endif
}/*}}}*/

inline bool dynlib_s::is_loaded()
{/*{{{*/
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  return lib_ptr != nullptr;
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  return lib_ptr != nullptr;
#else
  return false;
#endif
}/*}}}*/

inline const char *dynlib_s::get_error()
{/*{{{*/
#if DYNAMIC_TYPE == DYNAMIC_TYPE_POSIX
  return dlerror();
#elif DYNAMIC_TYPE == DYNAMIC_TYPE_WINDOWS
  return "Unknown error";
#else
  return nullptr;
#endif
}/*}}}*/

#endif

