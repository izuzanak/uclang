
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFREETYPE2 "freetype2 >= 22.1.16")
endif()

if(LIBFREETYPE2_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFREETYPE2_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBFREETYPE2_LIBRARIES})
endif()

