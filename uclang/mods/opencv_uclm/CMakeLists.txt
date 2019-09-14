
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBOPENCV "opencv >= 2.4.9.1")
endif()

if(LIBOPENCV_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBOPENCV_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBOPENCV_LIBRARIES})
endif()

