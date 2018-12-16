
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBGLM "glm")

  if(LIBGLM_FOUND)
    set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBGLM_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBGLM_LIBRARIES})
  endif()
endif()

