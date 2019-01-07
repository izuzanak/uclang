
if(OS_LINUX)
  set(LIBREGEX_FOUND TRUE)
endif()

if(LIBREGEX_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll)
endif()

