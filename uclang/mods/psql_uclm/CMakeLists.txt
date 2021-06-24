
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBPQ "libpq >= 10.0")
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

