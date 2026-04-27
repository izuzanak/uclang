
if(PKG_CONFIG_FOUND)
  pkg_search_module(GLUT "glut")
endif()

if(NOT GLUT_FOUND)
  find_package(GLUT QUIET)
endif()

if(NOT GLUT_FOUND)
  find_package(GLUT CONFIG QUIET)
  if(GLUT_FOUND)
    if(TARGET GLUT::GLUT)
      get_target_property(GLUT_INCLUDE_DIR GLUT::GLUT
          INTERFACE_INCLUDE_DIRECTORIES)
      set(GLUT_LIBRARIES GLUT::GLUT)
    endif()
  endif()
endif()

if(NOT GLUT_FOUND)
  find_path(GLUT_INCLUDE_DIR GL/glut.h)
  find_library(GLUT_LIBRARY NAMES glut freeglut)
  if(GLUT_INCLUDE_DIR AND GLUT_LIBRARY)
    set(GLUT_FOUND TRUE)
    set(GLUT_LIBRARIES ${GLUT_LIBRARY})
  endif()
endif()

if(GLUT_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${GLUT_INCLUDE_DIR})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${GLUT_LIBRARIES})
endif()

