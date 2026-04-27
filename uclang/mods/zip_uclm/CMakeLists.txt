
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBZIP "libzip >= 1.1.2")
endif()

if(NOT LIBZIP_FOUND)
  find_package(libzip CONFIG QUIET)
  if(libzip_FOUND)
    set(LIBZIP_FOUND TRUE)
    if(TARGET libzip::zip)
      get_target_property(LIBZIP_INCLUDE_DIRS libzip::zip
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBZIP_LIBRARIES libzip::zip)
    endif()
  endif()
endif()

if(NOT LIBZIP_FOUND)
  find_path(LIBZIP_INCLUDE_DIR zip.h)
  find_library(LIBZIP_LIBRARY NAMES zip)
  if(LIBZIP_INCLUDE_DIR AND LIBZIP_LIBRARY)
    set(LIBZIP_FOUND TRUE)
    set(LIBZIP_INCLUDE_DIRS ${LIBZIP_INCLUDE_DIR})
    set(LIBZIP_LIBRARIES ${LIBZIP_LIBRARY})
  endif()
endif()

if(LIBZIP_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBZIP_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBZIP_LIBRARIES})
endif()

