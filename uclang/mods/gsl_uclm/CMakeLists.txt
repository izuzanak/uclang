
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBGSL "gsl >= 2.1")

  if(LIBGSL_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBGSL_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBGSL_LIBRARIES})
  endif()
endif()

