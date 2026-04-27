
if(PKG_CONFIG_FOUND)
  pkg_search_module(GIF "gif >= 5.1.0")
endif()

if(NOT GIF_FOUND)
  find_package(GIF 5.1.0 QUIET)
endif()

if(NOT GIF_FOUND)
  find_package(GIF CONFIG QUIET)
endif()

if(NOT GIF_FOUND)
  find_path(GIF_INCLUDE_DIR gif_lib.h)
  find_library(GIF_LIBRARY NAMES gif ungif)
  if(GIF_INCLUDE_DIR AND GIF_LIBRARY)
    set(GIF_FOUND TRUE)
    set(GIF_INCLUDE_DIRS ${GIF_INCLUDE_DIR})
    set(GIF_LIBRARIES ${GIF_LIBRARY})
  endif()
endif()

if(GIF_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${GIF_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${GIF_LIBRARIES})
endif()

