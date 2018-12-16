
if(PKG_CONFIG_FOUND)

  pkg_search_module(LIBPNG "libpng >= 1.2.50")
  pkg_search_module(LIBJPEG "libjpeg")

  if(LIBPNG_FOUND AND LIBJPEG_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS
      ${LIBPNG_INCLUDE_DIRS}
      ${LIBJPEG_INCLUDE_DIRS})
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      libbase_ucll
      ${LIBPNG_LIBRARIES}
      ${LIBJPEG_LIBRARIES})
  endif()
endif()

