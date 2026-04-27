
set(OpenGL_GL_PREFERENCE "GLVND")

if(PKG_CONFIG_FOUND)
  pkg_search_module(OPENGL "gl")
endif()

if(NOT OPENGL_FOUND)
  find_package(OpenGL QUIET)
endif()

if(NOT OPENGL_FOUND)
  find_package(OpenGL CONFIG QUIET)
  if(OpenGL_FOUND)
    set(OPENGL_FOUND TRUE)
    if(TARGET OpenGL::GL)
      get_target_property(OPENGL_INCLUDE_DIR OpenGL::GL
          INTERFACE_INCLUDE_DIRECTORIES)
      set(OPENGL_LIBRARIES OpenGL::GL)
    endif()
  endif()
endif()

if(NOT OPENGL_FOUND)
  find_path(OPENGL_INCLUDE_DIR GL/gl.h)
  find_library(OPENGL_LIBRARY NAMES GL)
  if(OPENGL_INCLUDE_DIR AND OPENGL_LIBRARY)
    set(OPENGL_FOUND TRUE)
    set(OPENGL_LIBRARIES ${OPENGL_LIBRARY})
  endif()
endif()

if(OPENGL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${OPENGL_INCLUDE_DIR})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${OPENGL_LIBRARIES})
endif()

