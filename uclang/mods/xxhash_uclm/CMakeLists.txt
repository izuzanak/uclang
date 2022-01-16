
find_path(PATH_XXHASH_H NAMES "xxhash.h")

if(PATH_XXHASH_H)
  set(XXHASH_FOUND TRUE)
  set(XXHASH_LIBRARY xxhash)
endif()

if(XXHASH_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${XXHASH_LIBRARY})
endif()

