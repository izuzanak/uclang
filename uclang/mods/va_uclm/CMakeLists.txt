
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBVA "libva-x11 >= 1.3.0")
endif()

if(LIBVA_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBVA_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    "-lva-x11"
    ${LIBVA_LIBRARIES})
endif()

