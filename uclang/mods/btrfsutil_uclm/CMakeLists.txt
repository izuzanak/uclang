
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBBTRFSUTIL "libbtrfsutil >= 6.2")
endif()

if(LIBBTRFSUTIL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBBTRFSUTIL_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBBTRFSUTIL_LIBRARIES})
endif()

