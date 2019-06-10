
if(PKG_CONFIG_FOUND)
  pkg_search_module(PROTOBUF "libprotobuf-c >= 1.3.1")
endif()

if(PROTOBUF_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PROTOBUF_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${PROTOBUF_LIBRARIES})
endif()

