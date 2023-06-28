
if(PKG_CONFIG_FOUND)
  pkg_search_module(AVAHICLIENT "avahi-client >= 0.7")
endif()

if(AVAHICLIENT_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${AVAHICLIENT_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${AVAHICLIENT_LIBRARIES})
endif()

