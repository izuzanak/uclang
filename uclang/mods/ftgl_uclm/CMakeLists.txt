
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFREETYPE2 "freetype2 >= 22.1.16")
  pkg_search_module(LIBGLEW "glew >= 2.1.0")
endif()

if(NOT LIBFREETYPE2_FOUND)
  find_package(Freetype CONFIG QUIET)
  if(Freetype_FOUND)
    set(LIBFREETYPE2_FOUND TRUE)
    if(TARGET Freetype::Freetype)
      get_target_property(LIBFREETYPE2_INCLUDE_DIRS Freetype::Freetype
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBFREETYPE2_LIBRARIES Freetype::Freetype)
    endif()
  endif()
endif()

if(NOT LIBFREETYPE2_FOUND)
  find_path(LIBFREETYPE2_INCLUDE_DIR ft2build.h PATH_SUFFIXES freetype2)
  find_library(LIBFREETYPE2_LIBRARY NAMES freetype)
  if(LIBFREETYPE2_INCLUDE_DIR AND LIBFREETYPE2_LIBRARY)
    set(LIBFREETYPE2_FOUND TRUE)
    set(LIBFREETYPE2_INCLUDE_DIRS ${LIBFREETYPE2_INCLUDE_DIR})
    set(LIBFREETYPE2_LIBRARIES ${LIBFREETYPE2_LIBRARY})
  endif()
endif()

if(NOT LIBGLEW_FOUND)
  find_package(GLEW CONFIG QUIET)
  if(GLEW_FOUND)
    set(LIBGLEW_FOUND TRUE)
    if(TARGET GLEW::GLEW)
      get_target_property(LIBGLEW_INCLUDE_DIRS GLEW::GLEW
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBGLEW_LIBRARIES GLEW::GLEW)
    endif()
  endif()
endif()

if(NOT LIBGLEW_FOUND)
  find_path(LIBGLEW_INCLUDE_DIR GL/glew.h)
  find_library(LIBGLEW_LIBRARY NAMES GLEW)
  if(LIBGLEW_INCLUDE_DIR AND LIBGLEW_LIBRARY)
    set(LIBGLEW_FOUND TRUE)
    set(LIBGLEW_INCLUDE_DIRS ${LIBGLEW_INCLUDE_DIR})
    set(LIBGLEW_LIBRARIES ${LIBGLEW_LIBRARY})
  endif()
endif()

if(LIBFREETYPE2_FOUND AND LIBGLEW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files"
    "${LIB_FTGL}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ftgl_ucll)
endif()

