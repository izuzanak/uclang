
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBPSQL "libpq >= 9.4.1")

  if(LIBPSQL_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBPSQL_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBPSQL_LIBRARIES})
  endif()
endif()

