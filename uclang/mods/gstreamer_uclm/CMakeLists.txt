
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGSTREAMER "gstreamer-1.0 >= 1.4.4")
endif()

if(LIBGSTREAMER_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBGSTREAMER_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBGSTREAMER_LIBRARIES})
endif()

