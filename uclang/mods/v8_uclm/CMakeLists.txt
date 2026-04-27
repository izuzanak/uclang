
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBV8 "v8")
  if(LIBV8_FOUND)
    set(LIBV8_LIBRARY ${LIBV8_LIBRARIES})
  endif()
endif()

if(NOT LIBV8_FOUND)
  find_package(V8 CONFIG QUIET)
  if(V8_FOUND)
    set(LIBV8_FOUND TRUE)
    if(TARGET V8::v8)
      set(LIBV8_LIBRARY V8::v8)
    endif()
  endif()
endif()

if(NOT LIBV8_FOUND)
  find_path(PATH_V8_H NAMES "v8.h")
  if(PATH_V8_H)
    set(LIBV8_FOUND TRUE)
    set(LIBV8_LIBRARY v8)
  endif()
endif()

if(LIBV8_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBV8_LIBRARY})
endif()

