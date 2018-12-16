
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  set(CONF_DO_BUILD TRUE)
endif()

set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS)
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll)

