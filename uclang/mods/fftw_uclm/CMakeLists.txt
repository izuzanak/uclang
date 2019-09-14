
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFFTW "fftw3 >= 3.3.8")
endif()

if(LIBFFTW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFFTW_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    fftw)
endif()

