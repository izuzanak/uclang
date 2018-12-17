
find_path(PATH_UV_H NAMES "uv.h")

if(PATH_UV_H)
  set(LIBUV_FOUND TRUE)
  set(LIBUV_LIBRARY uv)
endif()

if(LIBUV_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBUV_LIBRARY})
endif()

