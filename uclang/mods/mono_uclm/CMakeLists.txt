
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGLIB2 "glib-2.0")
  pkg_search_module(LIBMONOSGEN "monosgen-2 >= 3.2.8")
endif()

if(LIBGLIB2_FOUND AND LIBMONOSGEN_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBGLIB2_INCLUDE_DIRS}
    ${LIBMONOSGEN_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBGLIB2_LIBRARIES}
    ${LIBMONOSGEN_LIBRARIES})
endif()

