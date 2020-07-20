
pkg_search_module(LIBSHAPE "shapelib >= 1.4.1")

if(LIBSHAPE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBSHAPE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBSHAPE_LIBRARIES})
endif()

