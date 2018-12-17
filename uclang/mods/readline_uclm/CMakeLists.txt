
if (OS_LINUX)
  if(EXISTS "/usr/include/readline/readline.h")
    set(LIBREADLINE_FOUND TRUE)
  endif()
endif()

if(LIBREADLINE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    readline)
endif()

