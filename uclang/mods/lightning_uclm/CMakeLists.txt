
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIGHTNING "lightning >= 2.2.3")
endif()

if(NOT LIGHTNING_FOUND)
  find_package(Lightning CONFIG QUIET)
  if(Lightning_FOUND)
    set(LIGHTNING_FOUND TRUE)
    if(TARGET Lightning::lightning)
      get_target_property(LIGHTNING_INCLUDE_DIRS Lightning::lightning
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIGHTNING_LIBRARIES Lightning::lightning)
    endif()
  endif()
endif()

if(NOT LIGHTNING_FOUND)
  find_path(LIGHTNING_INCLUDE_DIR lightning.h)
  find_library(LIGHTNING_LIBRARY NAMES lightning)
  if(LIGHTNING_INCLUDE_DIR AND LIGHTNING_LIBRARY)
    set(LIGHTNING_FOUND TRUE)
    set(LIGHTNING_INCLUDE_DIRS ${LIGHTNING_INCLUDE_DIR})
    set(LIGHTNING_LIBRARIES ${LIGHTNING_LIBRARY})
  endif()
endif()

if(LIGHTNING_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIGHTNING_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIGHTNING_LIBRARIES})
endif()

