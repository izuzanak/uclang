
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBAO "ao >= 1.1.0")
endif()

if(NOT LIBAO_FOUND)
  find_package(Ao CONFIG QUIET)
  if(Ao_FOUND)
    set(LIBAO_FOUND TRUE)
    if(TARGET Ao::ao)
      get_target_property(LIBAO_INCLUDE_DIRS Ao::ao
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBAO_LIBRARIES Ao::ao)
    endif()
  endif()
endif()

if(NOT LIBAO_FOUND)
  find_path(LIBAO_INCLUDE_DIR ao/ao.h)
  find_library(LIBAO_LIBRARY NAMES ao)
  if(LIBAO_INCLUDE_DIR AND LIBAO_LIBRARY)
    set(LIBAO_FOUND TRUE)
    set(LIBAO_INCLUDE_DIRS ${LIBAO_INCLUDE_DIR})
    set(LIBAO_LIBRARIES ${LIBAO_LIBRARY})
  endif()
endif()

if(LIBAO_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBAO_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBAO_LIBRARIES})
endif()

