
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL)

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

