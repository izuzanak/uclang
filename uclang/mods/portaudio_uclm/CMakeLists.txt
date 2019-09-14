
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBPORTAUDIO "portaudio-2.0 >= 19")
endif()

if(LIBPORTAUDIO_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBPORTAUDIO_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBPORTAUDIO_LIBRARIES})
endif()

