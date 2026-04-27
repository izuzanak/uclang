
if(PKG_CONFIG_FOUND)
  pkg_search_module(GA "galib")
  if(GA_FOUND)
    set(GA_LIBRARY ${GA_LIBRARIES})
  endif()
endif()

if(NOT GA_FOUND)
  find_package(GAlib CONFIG QUIET)
  if(GAlib_FOUND)
    set(GA_FOUND TRUE)
    if(TARGET GAlib::ga)
      set(GA_LIBRARY GAlib::ga)
    endif()
  endif()
endif()

if(NOT GA_LIBRARY)
  find_library(GA_LIBRARY ga "${EXT_LIBS}/galib/galib247/ga")
endif()

if(GA_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${EXT_LIBS}/galib/galib247")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${GA_LIBRARY})
endif()

