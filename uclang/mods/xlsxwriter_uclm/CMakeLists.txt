
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBXLSXWRITER "xlsxwriter >= 1.1.8")
endif()

if(LIBXLSXWRITER_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBXLSXWRITER_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBXLSXWRITER_LIBRARIES})
endif()

