
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFFTW "fftw3 >= 3.3.8")
endif()

if(NOT LIBFFTW_FOUND)
  find_package(FFTW3 CONFIG QUIET)
  if(FFTW3_FOUND)
    set(LIBFFTW_FOUND TRUE)
    if(TARGET FFTW3::fftw3)
      get_target_property(LIBFFTW_INCLUDE_DIRS FFTW3::fftw3
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBFFTW_LIBRARIES FFTW3::fftw3)
    endif()
  endif()
endif()

if(NOT LIBFFTW_FOUND)
  find_path(LIBFFTW_INCLUDE_DIR fftw3.h)
  find_library(LIBFFTW_LIBRARY NAMES fftw3 fftw)
  if(LIBFFTW_INCLUDE_DIR AND LIBFFTW_LIBRARY)
    set(LIBFFTW_FOUND TRUE)
    set(LIBFFTW_INCLUDE_DIRS ${LIBFFTW_INCLUDE_DIR})
    set(LIBFFTW_LIBRARIES ${LIBFFTW_LIBRARY})
  endif()
endif()

if(LIBFFTW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFFTW_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    fftw)
endif()

