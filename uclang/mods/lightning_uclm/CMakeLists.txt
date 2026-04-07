
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIGHTNING "lightning >= 2.2.3")
endif()

if(LIGHTNING_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIGHTNING_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIGHTNING_LIBRARIES})
endif()

