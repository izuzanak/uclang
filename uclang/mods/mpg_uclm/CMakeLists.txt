
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBMPG123 "libmpg123 >= 1.20.1")

  if(LIBMPG123_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBMPG123_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBMPG123_LIBRARIES})
  endif()
endif()

