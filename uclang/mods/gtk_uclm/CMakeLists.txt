
pkg_search_module(LIBGTK3 REQUIRED gtk+-3.0)

set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS
  ${LIBGTK3_INCLUDE_DIRS})
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll
  ${LIBGTK3_LIBRARIES})

