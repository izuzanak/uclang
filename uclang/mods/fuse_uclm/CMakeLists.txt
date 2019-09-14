
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFUSE "fuse >= 2.9.3")
endif()

if(LIBFUSE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFUSE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    "-D_FILE_OFFSET_BITS=64 ")
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBFUSE_LIBRARIES})
endif()

