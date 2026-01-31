
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBQRENCODE "libqrencode >= 4.0.2")
endif()

if(LIBQRENCODE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBQRENCODE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBQRENCODE_LIBRARIES})
endif()

