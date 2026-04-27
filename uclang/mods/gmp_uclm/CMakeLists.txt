
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGMP "gmp")
  if(LIBGMP_FOUND)
    set(LIBGMP_LIBRARY ${LIBGMP_LIBRARIES})
  endif()
endif()

if(NOT LIBGMP_FOUND)
  find_package(GMP CONFIG QUIET)
  if(GMP_FOUND)
    set(LIBGMP_FOUND TRUE)
    if(TARGET GMP::gmp)
      get_target_property(LIBGMP_INCLUDE_DIRS GMP::gmp
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBGMP_LIBRARY GMP::gmp)
    endif()
  endif()
endif()

if(NOT LIBGMP_FOUND)
  find_path(PATH_GMP_H NAMES "gmp.h")
  if(PATH_GMP_H)
    set(LIBGMP_FOUND TRUE)
    set(LIBGMP_LIBRARY gmp)
  endif()
endif()

if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBMPFR "mpfr")
endif()

if(NOT LIBMPFR_FOUND)
  find_package(MPFR CONFIG QUIET)
  if(MPFR_FOUND)
    set(LIBMPFR_FOUND TRUE)
    if(TARGET MPFR::mpfr)
      get_target_property(LIBMPFR_INCLUDE_DIRS MPFR::mpfr
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBMPFR_LIBRARIES MPFR::mpfr)
    endif()
  endif()
endif()

if(NOT LIBMPFR_FOUND)
  find_path(LIBMPFR_INCLUDE_DIR mpfr.h)
  find_library(LIBMPFR_LIBRARY NAMES mpfr)
  if(LIBMPFR_INCLUDE_DIR AND LIBMPFR_LIBRARY)
    set(LIBMPFR_FOUND TRUE)
    set(LIBMPFR_INCLUDE_DIRS ${LIBMPFR_INCLUDE_DIR})
    set(LIBMPFR_LIBRARIES ${LIBMPFR_LIBRARY})
  endif()
endif()

if(LIBGMP_FOUND AND LIBMPFR_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBMPFR_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBGMP_LIBRARY}
    ${LIBMPFR_LIBRARIES})
endif()

