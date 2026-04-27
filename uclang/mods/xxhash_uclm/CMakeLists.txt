
if(PKG_CONFIG_FOUND)
  pkg_search_module(XXHASH "libxxhash")
  if(XXHASH_FOUND)
    set(XXHASH_LIBRARY ${XXHASH_LIBRARIES})
  endif()
endif()

if(NOT XXHASH_FOUND)
  find_package(xxHash CONFIG QUIET)
  if(xxHash_FOUND)
    set(XXHASH_FOUND TRUE)
    if(TARGET xxHash::xxhash)
      set(XXHASH_LIBRARY xxHash::xxhash)
    endif()
  endif()
endif()

if(NOT XXHASH_FOUND)
  find_path(PATH_XXHASH_H NAMES "xxhash.h")
  if(PATH_XXHASH_H)
    set(XXHASH_FOUND TRUE)
    set(XXHASH_LIBRARY xxhash)
  endif()
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

