
set(PCRE_DEFS)

if(PKG_CONFIG_FOUND)
  pkg_search_module(PCRE "libpcreposix")
endif()

if(NOT PCRE_FOUND)
  find_package(PCRE CONFIG QUIET)
  if(PCRE_FOUND)
    if(TARGET PCRE::pcreposix)
      get_target_property(PCRE_INCLUDE_DIRS PCRE::pcreposix
          INTERFACE_INCLUDE_DIRECTORIES)
      set(PCRE_LIBRARIES PCRE::pcreposix)
    endif()
  endif()
endif()

if(NOT PCRE_FOUND)
  find_path(PCRE_INCLUDE_DIR pcreposix.h)
  find_library(PCRE_LIBRARY NAMES pcreposix)
  if(PCRE_INCLUDE_DIR AND PCRE_LIBRARY)
    set(PCRE_FOUND TRUE)
    set(PCRE_INCLUDE_DIRS ${PCRE_INCLUDE_DIR})
    set(PCRE_LIBRARIES ${PCRE_LIBRARY})
    if(OS_WINDOWS)
      set(PCRE_DEFS "-DPCRE_STATIC")
    endif()
  endif()
endif()

if(PCRE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PCRE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    ${PCRE_DEFS})
  set(CONF_LINK_LIBS
    base_ucll
    ${PCRE_LIBRARIES})
endif()

