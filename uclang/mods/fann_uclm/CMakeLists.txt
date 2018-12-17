
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFANN "fann >= 2.2.0")
endif()

if(LIBFANN_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFANN_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBFANN_LIBRARIES})
endif()

