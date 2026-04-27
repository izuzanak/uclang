
if(PKG_CONFIG_FOUND)
  pkg_search_module(Python2 "python-2.7")
  if(Python2_FOUND)
    set(Python2_INCLUDE_DIRS ${Python2_INCLUDE_DIRS})
  endif()
endif()

if(NOT Python2_FOUND)
  find_package(Python2 2.7 COMPONENTS Development QUIET)
endif()

if(NOT Python2_FOUND)
  find_package(Python2 CONFIG QUIET COMPONENTS Development)
endif()

if(NOT Python2_FOUND)
  find_path(Python2_INCLUDE_DIR Python.h PATH_SUFFIXES python2.7)
  find_library(Python2_LIBRARY NAMES python2.7)
  if(Python2_INCLUDE_DIR AND Python2_LIBRARY)
    set(Python2_FOUND TRUE)
    set(Python2_INCLUDE_DIRS ${Python2_INCLUDE_DIR})
    set(Python2_LIBRARIES ${Python2_LIBRARY})
  endif()
endif()

if(Python2_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${Python2_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${Python2_LIBRARIES})
endif()

