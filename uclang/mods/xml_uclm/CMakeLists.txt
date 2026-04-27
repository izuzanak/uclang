
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBXML2 "libxml-2.0 >= 2.9.1")
  if(LIBXML2_FOUND)
    set(LIBXML2_INCLUDE_DIR ${LIBXML2_INCLUDE_DIRS})
  endif()
endif()

if(NOT LIBXML2_FOUND)
  find_package(LibXml2 2.9.1 QUIET)
endif()

if(NOT LIBXML2_FOUND)
  find_package(LibXml2 CONFIG QUIET)
  if(LibXml2_FOUND)
    set(LIBXML2_FOUND TRUE)
    if(TARGET LibXml2::LibXml2)
      get_target_property(LIBXML2_INCLUDE_DIR LibXml2::LibXml2
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBXML2_LIBRARIES LibXml2::LibXml2)
    endif()
  endif()
endif()

if(NOT LIBXML2_FOUND)
  find_path(LIBXML2_INCLUDE_DIR libxml/parser.h PATH_SUFFIXES libxml2)
  find_library(LIBXML2_LIBRARY NAMES xml2)
  if(LIBXML2_INCLUDE_DIR AND LIBXML2_LIBRARY)
    set(LIBXML2_FOUND TRUE)
    set(LIBXML2_LIBRARIES ${LIBXML2_LIBRARY})
  endif()
endif()

if(LIBXML2_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBXML2_INCLUDE_DIR})
  set(CONF_COMP_DEFS
    ${LIBXML2_DEFINITIONS})
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBXML2_LIBRARIES})
endif()

