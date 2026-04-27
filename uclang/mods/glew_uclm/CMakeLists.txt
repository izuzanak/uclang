
if(PKG_CONFIG_FOUND)
  pkg_search_module(GLEW "glew")
endif()

if(NOT GLEW_FOUND)
  find_package(GLEW QUIET)
endif()

if(NOT GLEW_FOUND)
  find_package(GLEW CONFIG QUIET)
  if(GLEW_FOUND)
    if(TARGET GLEW::GLEW)
      get_target_property(GLEW_INCLUDE_DIRS GLEW::GLEW
          INTERFACE_INCLUDE_DIRECTORIES)
      set(GLEW_LIBRARIES GLEW::GLEW)
    endif()
  endif()
endif()

if(NOT GLEW_FOUND)
  find_path(GLEW_INCLUDE_DIR GL/glew.h)
  find_library(GLEW_LIBRARY NAMES GLEW)
  if(GLEW_INCLUDE_DIR AND GLEW_LIBRARY)
    set(GLEW_FOUND TRUE)
    set(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
    set(GLEW_LIBRARIES ${GLEW_LIBRARY})
  endif()
endif()

if(GLEW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${GLEW_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${GLEW_LIBRARIES})
endif()

