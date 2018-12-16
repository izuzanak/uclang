
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBZ "zlib >= 1.2.8")

  if(LIBZ_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBZ_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBZ_LIBRARIES})
  endif()
endif()

