
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBPROLOG "swipl >= 7.2.3")
endif()

if(LIBPROLOG_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBPROLOG_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBPROLOG_LIBRARIES})
endif()

