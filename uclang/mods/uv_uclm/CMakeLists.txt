
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBUV "libuv >= 1.0")
  if(LIBUV_FOUND)
    set(LIBUV_LIBRARY ${LIBUV_LIBRARIES})
  endif()
endif()

if(NOT LIBUV_FOUND)
  find_package(libuv CONFIG QUIET)
  if(libuv_FOUND)
    set(LIBUV_FOUND TRUE)
    if(TARGET libuv::uv)
      set(LIBUV_LIBRARY libuv::uv)
    endif()
  endif()
endif()

if(NOT LIBUV_FOUND)
  find_path(PATH_UV_H NAMES "uv.h")
  if(PATH_UV_H)
    set(LIBUV_FOUND TRUE)
    set(LIBUV_LIBRARY uv)
  endif()
endif()

if(LIBUV_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBUV_LIBRARY})
endif()

