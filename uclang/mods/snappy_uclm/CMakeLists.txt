
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBSNAPPY "snappy >= 1.0.0")
endif()

if(LIBSNAPPY_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${LIBSNAPPY_INCLUDE_DIRS}")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBSNAPPY_LIBRARIES})
endif()

