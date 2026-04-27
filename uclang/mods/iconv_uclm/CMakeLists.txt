
if(PKG_CONFIG_FOUND)
  pkg_search_module(Iconv "iconv")
endif()

if(NOT Iconv_FOUND)
  find_package(Iconv QUIET)
endif()

if(NOT Iconv_FOUND)
  find_package(Iconv CONFIG QUIET)
  if(Iconv_FOUND)
    if(TARGET Iconv::Iconv)
      get_target_property(Iconv_INCLUDE_DIRS Iconv::Iconv
          INTERFACE_INCLUDE_DIRECTORIES)
      set(Iconv_LIBRARIES Iconv::Iconv)
    endif()
  endif()
endif()

if(NOT Iconv_FOUND)
  find_path(Iconv_INCLUDE_DIR iconv.h)
  find_library(Iconv_LIBRARY NAMES iconv)
  if(Iconv_INCLUDE_DIR)
    set(Iconv_FOUND TRUE)
    set(Iconv_INCLUDE_DIRS ${Iconv_INCLUDE_DIR})
    if(Iconv_LIBRARY)
      set(Iconv_LIBRARIES ${Iconv_LIBRARY})
    endif()
  endif()
endif()

if(Iconv_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${Iconv_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${Iconv_LIBRARIES})
endif()

