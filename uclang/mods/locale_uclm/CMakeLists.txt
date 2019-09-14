
if(OS_LINUX)
  find_path(PATH_LOCALE_H NAMES "libintl.h" "locale.h")

  if(PATH_LOCALE_H)
    set(LIBLOCALE_FOUND TRUE)
  endif()

  if(LIBLOCALE_FOUND)
    set(CONF_DO_BUILD TRUE)
    set(CONF_HEADER_DIRS
      "${LIB_BASE}/header_files")
    set(CONF_INCLUDE_DIRS)
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      base_ucll)
  endif()
endif()

