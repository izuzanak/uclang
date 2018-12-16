
if(PKG_CONFIG_FOUND)

  if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    if(EXISTS "/usr/include/i386-linux-gnu/gmp.h")
      set(LIBGMP_FOUND TRUE)
      set(LIBGMP_LIBRARIES gmp)
    endif()
  endif()

  pkg_search_module(LIBMPFR "mpfr")

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
endif()

