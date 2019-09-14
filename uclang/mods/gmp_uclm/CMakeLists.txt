
find_path(PATH_GMP_H NAMES "gmp.h")

if(PATH_GMP_H)
  set(LIBGMP_FOUND TRUE)
  set(LIBGMP_LIBRARY gmp)
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
    base_ucll
    ${LIBGMP_LIBRARY}
    ${LIBMPFR_LIBRARIES})
endif()

