
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBSHAPE "shapelib >= 1.4.1")
endif()

if(NOT LIBSHAPE_FOUND)
  find_package(Shapelib CONFIG QUIET)
  if(Shapelib_FOUND)
    set(LIBSHAPE_FOUND TRUE)
    if(TARGET Shapelib::shp)
      get_target_property(LIBSHAPE_INCLUDE_DIRS Shapelib::shp
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBSHAPE_LIBRARIES Shapelib::shp)
    endif()
  endif()
endif()

if(NOT LIBSHAPE_FOUND)
  find_path(LIBSHAPE_INCLUDE_DIR shapefil.h)
  find_library(LIBSHAPE_LIBRARY NAMES shp)
  if(LIBSHAPE_INCLUDE_DIR AND LIBSHAPE_LIBRARY)
    set(LIBSHAPE_FOUND TRUE)
    set(LIBSHAPE_INCLUDE_DIRS ${LIBSHAPE_INCLUDE_DIR})
    set(LIBSHAPE_LIBRARIES ${LIBSHAPE_LIBRARY})
  endif()
endif()

if(LIBSHAPE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBSHAPE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBSHAPE_LIBRARIES})
endif()

