
if(PKG_CONFIG_FOUND)
  pkg_search_module(GSL "gsl >= 2.1")
endif()

if(NOT GSL_FOUND)
  find_package(GSL 2.1 QUIET)
endif()

if(NOT GSL_FOUND)
  find_package(GSL CONFIG QUIET)
  if(GSL_FOUND)
    if(TARGET GSL::gsl)
      get_target_property(GSL_INCLUDE_DIRS GSL::gsl
          INTERFACE_INCLUDE_DIRECTORIES)
      set(GSL_LIBRARIES GSL::gsl)
    endif()
  endif()
endif()

if(NOT GSL_FOUND)
  find_path(GSL_INCLUDE_DIR gsl/gsl_math.h)
  find_library(GSL_LIBRARY NAMES gsl)
  find_library(GSL_CBLAS_LIBRARY NAMES gslcblas)
  if(GSL_INCLUDE_DIR AND GSL_LIBRARY)
    set(GSL_FOUND TRUE)
    set(GSL_INCLUDE_DIRS ${GSL_INCLUDE_DIR})
    set(GSL_LIBRARIES ${GSL_LIBRARY} ${GSL_CBLAS_LIBRARY})
  endif()
endif()

if(GSL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${GSL_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${GSL_LIBRARIES})
endif()

