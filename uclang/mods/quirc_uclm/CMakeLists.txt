
if(PKG_CONFIG_FOUND)
  pkg_search_module(QUIRC "quirc")
  if(QUIRC_FOUND)
    set(QUIRC_LIBRARY ${QUIRC_LIBRARIES})
  endif()
endif()

if(NOT QUIRC_LIBRARY)
  find_package(Quirc CONFIG QUIET)
  if(Quirc_FOUND)
    if(TARGET Quirc::quirc)
      set(QUIRC_LIBRARY Quirc::quirc)
    endif()
  endif()
endif()

if(NOT QUIRC_LIBRARY)
  find_library(QUIRC_LIBRARY quirc "${EXT_LIBS}/quirc/quirc-1.0")
endif()

if(QUIRC_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${EXT_LIBS}/quirc/quirc-1.0/lib")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${QUIRC_LIBRARY})
endif()

