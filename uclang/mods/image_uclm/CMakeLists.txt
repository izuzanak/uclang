
if(PKG_CONFIG_FOUND)
  pkg_search_module(PNG "libpng >= 1.2.50")
  pkg_search_module(JPEG "libjpeg")
endif()

if(NOT PNG_FOUND)
  find_package(PNG 1.2.50 QUIET)
endif()

if(NOT PNG_FOUND)
  find_package(PNG CONFIG QUIET)
  if(PNG_FOUND)
    if(TARGET PNG::PNG)
      get_target_property(PNG_INCLUDE_DIRS PNG::PNG
          INTERFACE_INCLUDE_DIRECTORIES)
      set(PNG_LIBRARIES PNG::PNG)
    endif()
  endif()
endif()

if(NOT PNG_FOUND)
  find_path(PNG_INCLUDE_DIR png.h)
  find_library(PNG_LIBRARY NAMES png png16 png12)
  if(PNG_INCLUDE_DIR AND PNG_LIBRARY)
    set(PNG_FOUND TRUE)
    set(PNG_INCLUDE_DIRS ${PNG_INCLUDE_DIR})
    set(PNG_LIBRARIES ${PNG_LIBRARY})
  endif()
endif()

if(NOT JPEG_FOUND)
  find_package(JPEG QUIET)
endif()

if(NOT JPEG_FOUND)
  find_package(JPEG CONFIG QUIET)
  if(JPEG_FOUND)
    if(TARGET JPEG::JPEG)
      get_target_property(JPEG_INCLUDE_DIRS JPEG::JPEG
          INTERFACE_INCLUDE_DIRECTORIES)
      set(JPEG_LIBRARIES JPEG::JPEG)
    endif()
  endif()
endif()

if(NOT JPEG_FOUND)
  find_path(JPEG_INCLUDE_DIR jpeglib.h)
  find_library(JPEG_LIBRARY NAMES jpeg)
  if(JPEG_INCLUDE_DIR AND JPEG_LIBRARY)
    set(JPEG_FOUND TRUE)
    set(JPEG_INCLUDE_DIRS ${JPEG_INCLUDE_DIR})
    set(JPEG_LIBRARIES ${JPEG_LIBRARY})
  endif()
endif()

if(PNG_FOUND AND JPEG_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PNG_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    ${PNG_DEFINITIONS})
  set(CONF_LINK_LIBS
    base_ucll
    ${PNG_LIBRARIES}
    ${JPEG_LIBRARIES})
endif()

