
if(OS_LINUX OR OS_MSYS2)
  set(LIBFGETTOOLS_FOUND TRUE)
endif()

if(LIBFGETTOOLS_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll)
endif()

