
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBCRYPTO "libcrypto >= 1.0.2m")

  if(LIBCRYPTO_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBCRYPTO_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBCRYPTO_LIBRARIES})
  endif()
endif()

