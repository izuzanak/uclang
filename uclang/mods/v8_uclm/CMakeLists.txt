
find_path(PATH_V8_H NAMES "v8.h")

if(PATH_V8_H)
  set(LIBV8_FOUND TRUE)
  set(LIBV8_LIBRARY v8)
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

