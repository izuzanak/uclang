
find_package(GIF 5.1.0)

if(GIF_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${GIF_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${GIF_LIBRARIES})
endif()

