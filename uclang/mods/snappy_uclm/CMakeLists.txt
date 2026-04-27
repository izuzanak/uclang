
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBSNAPPY "snappy >= 1.0.0")
endif()

if(NOT LIBSNAPPY_FOUND)
  find_package(Snappy CONFIG QUIET)
  if(Snappy_FOUND)
    set(LIBSNAPPY_FOUND TRUE)
    if(TARGET Snappy::snappy)
      get_target_property(LIBSNAPPY_INCLUDE_DIRS Snappy::snappy
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBSNAPPY_LIBRARIES Snappy::snappy)
    endif()
  endif()
endif()

if(NOT LIBSNAPPY_FOUND)
  find_path(LIBSNAPPY_INCLUDE_DIR snappy.h)
  find_library(LIBSNAPPY_LIBRARY NAMES snappy)
  if(LIBSNAPPY_INCLUDE_DIR AND LIBSNAPPY_LIBRARY)
    set(LIBSNAPPY_FOUND TRUE)
    set(LIBSNAPPY_INCLUDE_DIRS ${LIBSNAPPY_INCLUDE_DIR})
    set(LIBSNAPPY_LIBRARIES ${LIBSNAPPY_LIBRARY})
  endif()
endif()

if(LIBSNAPPY_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${LIBSNAPPY_INCLUDE_DIRS}")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBSNAPPY_LIBRARIES})
endif()

