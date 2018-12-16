
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBPYTHON "python-2.7 >= 2.7")

  if(LIBPYTHON_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBPYTHON_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBPYTHON_LIBRARIES})
  endif()
endif()

