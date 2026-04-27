
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFANN "fann >= 2.2.0")
endif()

if(NOT LIBFANN_FOUND)
  find_package(FANN CONFIG QUIET)
  if(FANN_FOUND)
    set(LIBFANN_FOUND TRUE)
    if(TARGET FANN::fann)
      get_target_property(LIBFANN_INCLUDE_DIRS FANN::fann
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBFANN_LIBRARIES FANN::fann)
    endif()
  endif()
endif()

if(NOT LIBFANN_FOUND)
  find_path(LIBFANN_INCLUDE_DIR fann.h)
  find_library(LIBFANN_LIBRARY NAMES fann)
  if(LIBFANN_INCLUDE_DIR AND LIBFANN_LIBRARY)
    set(LIBFANN_FOUND TRUE)
    set(LIBFANN_INCLUDE_DIRS ${LIBFANN_INCLUDE_DIR})
    set(LIBFANN_LIBRARIES ${LIBFANN_LIBRARY})
  endif()
endif()

if(LIBFANN_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFANN_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBFANN_LIBRARIES})
endif()

