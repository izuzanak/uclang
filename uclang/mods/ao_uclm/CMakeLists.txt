
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBAO "ao >= 1.1.0")
endif()

if(LIBAO_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBAO_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBAO_LIBRARIES})
endif()

