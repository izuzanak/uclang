
if(PKG_CONFIG_FOUND)
  pkg_search_module(ZLIB "zlib >= 1.2.8")
endif()

if(NOT ZLIB_FOUND)
  find_package(ZLIB 1.2.8 QUIET)
endif()

if(NOT ZLIB_FOUND)
  find_package(ZLIB CONFIG QUIET)
  if(ZLIB_FOUND)
    if(TARGET ZLIB::ZLIB)
      get_target_property(ZLIB_INCLUDE_DIRS ZLIB::ZLIB
          INTERFACE_INCLUDE_DIRECTORIES)
      set(ZLIB_LIBRARIES ZLIB::ZLIB)
    endif()
  endif()
endif()

if(NOT ZLIB_FOUND)
  find_path(ZLIB_INCLUDE_DIR zlib.h)
  find_library(ZLIB_LIBRARY NAMES z zlib)
  if(ZLIB_INCLUDE_DIR AND ZLIB_LIBRARY)
    set(ZLIB_FOUND TRUE)
    set(ZLIB_INCLUDE_DIRS ${ZLIB_INCLUDE_DIR})
    set(ZLIB_LIBRARIES ${ZLIB_LIBRARY})
  endif()
endif()

if(ZLIB_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${ZLIB_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${ZLIB_LIBRARIES})
endif()

