
pkg_search_module(LIBPSQL REQUIRED libpq)

set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS ${LIBXML2_INCLUDE_DIRS})
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll
  ${LIBXML2_LIBRARIES})

