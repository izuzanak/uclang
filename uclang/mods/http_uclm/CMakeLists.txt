
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBMICROHTTPD "libmicrohttpd >= 0.9.37")

  if(LIBMICROHTTPD_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBMICROHTTPD_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBMICROHTTPD_LIBRARIES})
  endif()
endif()

