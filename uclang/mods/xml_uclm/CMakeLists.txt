
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBXML "libxml-2.0 >= 2.9.1")

  if(LIBXML_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBXML_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBXML_LIBRARIES})
  endif()
endif()

