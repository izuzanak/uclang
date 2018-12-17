
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBSSH2 "libssh2 >= 1.4.3")
endif()

if(LIBSSH2_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBSSH2_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBSSH2_LIBRARIES})
endif()

