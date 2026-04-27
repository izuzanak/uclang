
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBLOCALE "libintl")
endif()

if(NOT LIBLOCALE_FOUND)
  find_package(Intl CONFIG QUIET)
  if(Intl_FOUND)
    set(LIBLOCALE_FOUND TRUE)
  endif()
endif()

if(NOT LIBLOCALE_FOUND AND OS_LINUX)
  find_path(PATH_LOCALE_H NAMES "libintl.h" "locale.h")
  if(PATH_LOCALE_H)
    set(LIBLOCALE_FOUND TRUE)
  endif()
endif()

if(OS_LINUX AND LIBLOCALE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll)
endif()

