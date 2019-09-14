
if(OS_LINUX)
  set(LIBINOTIFY_FOUND TRUE)
endif()

if(LIBINOTIFY_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll)
endif()

