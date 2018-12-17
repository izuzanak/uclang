
if(OS_LINUX)
  find_path(PATH_GMP_H "gmp.h" "/usr/include/")

  if(PATH_GMP_H)
    set(LIBGMP_FOUND TRUE)
    set(LIBGMP_LIBRARIES gmp)
  endif()
endif()

if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBMPFR "mpfr")
endif()

if(LIBGMP_FOUND AND LIBMPFR_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBMPFR_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBGMP_LIBRARIES}
    ${LIBMPFR_LIBRARIES})
endif()

