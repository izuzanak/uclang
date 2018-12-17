
find_path(PATH_SNAPPY_H NAMES "snappy.h")

if(PATH_SNAPPY_H)
  set(LIBSNAPPY_FOUND TRUE)
  set(LIBSNAPPY_LIBRARY snappy)
endif()

if(LIBSNAPPY_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBSNAPPY_LIBRARY})
endif()

