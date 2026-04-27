
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBPQ "libpq >= 10.0")
endif()

if(NOT LIBPQ_FOUND)
  find_package(PostgreSQL CONFIG QUIET)
  if(PostgreSQL_FOUND)
    set(LIBPQ_FOUND TRUE)
    if(TARGET PostgreSQL::PostgreSQL)
      get_target_property(LIBPQ_INCLUDE_DIRS PostgreSQL::PostgreSQL
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBPQ_LIBRARIES PostgreSQL::PostgreSQL)
    endif()
  endif()
endif()

if(NOT LIBPQ_FOUND)
  find_path(LIBPQ_INCLUDE_DIR libpq-fe.h PATH_SUFFIXES postgresql)
  find_library(LIBPQ_LIBRARY NAMES pq)
  if(LIBPQ_INCLUDE_DIR AND LIBPQ_LIBRARY)
    set(LIBPQ_FOUND TRUE)
    set(LIBPQ_INCLUDE_DIRS ${LIBPQ_INCLUDE_DIR})
    set(LIBPQ_LIBRARIES ${LIBPQ_LIBRARY})
  endif()
endif()

if(LIBPQ_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBPQ_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBPQ_LIBRARIES})
endif()

