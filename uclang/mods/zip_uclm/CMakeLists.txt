
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBZIP "libzip >= 1.1.2")
endif()

if(LIBZIP_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBZIP_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBZIP_LIBRARIES})
endif()

