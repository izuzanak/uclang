
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBRUBY "ruby >= 2.3.0")

  if(LIBRUBY_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBRUBY_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBRUBY_LIBRARIES})
  endif()
endif()

