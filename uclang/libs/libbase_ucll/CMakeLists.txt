
set(CONF_DO_BUILD TRUE)
set(CONF_HEADER_DIRS)
set(CONF_INCLUDE_DIRS)
set(CONF_COMP_DEFS)

if(OS_LINUX)
  set(CONF_LINK_LIBS
    dl
    pthread)
elseif(OS_WINDOWS)
  set(CONF_LINK_LIBS)
endif()

