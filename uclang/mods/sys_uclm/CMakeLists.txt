
if(OS_WINDOWS)
  set(WSOCK32_LIBS
    wsock32
    ws2_32)
endif()

set(CONF_DO_BUILD TRUE)
set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS)
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  base_ucll
  ${WSOCK32_LIBS})

