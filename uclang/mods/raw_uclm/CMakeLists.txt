
if(PKG_CONFIG_FOUND)
  pkg_search_module(RAW "libraw")
endif()

if(NOT RAW_FOUND)
  find_package(LibRaw CONFIG QUIET)
  if(LibRaw_FOUND)
    set(RAW_FOUND TRUE)
    if(TARGET LibRaw::raw)
      get_target_property(RAW_INCLUDE_DIRS LibRaw::raw
          INTERFACE_INCLUDE_DIRECTORIES)
      set(RAW_LIBRARIES LibRaw::raw)
    endif()
  endif()
endif()

if(NOT RAW_FOUND)
  find_path(RAW_INCLUDE_DIR libraw/libraw.h)
  find_library(RAW_LIBRARY NAMES raw)
  if(RAW_INCLUDE_DIR AND RAW_LIBRARY)
    set(RAW_FOUND TRUE)
    set(RAW_INCLUDE_DIRS ${RAW_INCLUDE_DIR})
    set(RAW_LIBRARIES ${RAW_LIBRARY})
  endif()
endif()

if(RAW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${RAW_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    ${RAW_DEFINITIONS})
  set(CONF_LINK_LIBS
    base_ucll
    ${RAW_LIBRARIES})
endif()

