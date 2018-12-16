
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBCURL "libcurl >= 7.38.0")

  if(LIBCURL_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBCURL_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBCURL_LIBRARIES})
  endif()
endif()

