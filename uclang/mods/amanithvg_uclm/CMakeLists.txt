
if(PKG_CONFIG_FOUND)
  pkg_search_module(AMANITHVG "amanithvg")
endif()

if(NOT AMANITHVG_FOUND)
  find_package(AmanithVG CONFIG QUIET)
  if(AmanithVG_FOUND)
    set(AMANITHVG_FOUND TRUE)
    if(TARGET AmanithVG::AmanithVG)
      get_target_property(AMANITHVG_INCLUDE_DIRS AmanithVG::AmanithVG
          INTERFACE_INCLUDE_DIRECTORIES)
      set(AMANITHVG_LIBRARY AmanithVG::AmanithVG)
    endif()
  endif()
endif()

if(NOT AMANITHVG_FOUND)
  find_library(AMANITHVG_LIBRARY AmanithVG "${EXT_LIBS}/AmanithVG/libs")
  if(AMANITHVG_LIBRARY)
    set(AMANITHVG_FOUND TRUE)
    set(AMANITHVG_INCLUDE_DIRS "${EXT_LIBS}/AmanithVG/include")
  endif()
endif()

if(AMANITHVG_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${AMANITHVG_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${AMANITHVG_LIBRARY})
endif()

