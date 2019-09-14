
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBVLC "libvlc >= 3.0.6")
endif()

if(LIBVLC_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBVLC_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBVLC_LIBRARIES})
endif()

