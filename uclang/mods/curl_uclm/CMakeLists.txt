
if(PKG_CONFIG_FOUND)
  pkg_search_module(CURL "libcurl >= 7.38.0")
endif()

if(NOT CURL_FOUND)
  find_package(CURL 7.38.0 QUIET)
endif()

if(NOT CURL_FOUND)
  find_package(CURL CONFIG QUIET)
  if(CURL_FOUND)
    if(TARGET CURL::libcurl)
      get_target_property(CURL_INCLUDE_DIRS CURL::libcurl
          INTERFACE_INCLUDE_DIRECTORIES)
      set(CURL_LIBRARIES CURL::libcurl)
    endif()
  endif()
endif()

if(NOT CURL_FOUND)
  find_path(CURL_INCLUDE_DIR curl/curl.h)
  find_library(CURL_LIBRARY NAMES curl)
  if(CURL_INCLUDE_DIR AND CURL_LIBRARY)
    set(CURL_FOUND TRUE)
    set(CURL_INCLUDE_DIRS ${CURL_INCLUDE_DIR})
    set(CURL_LIBRARIES ${CURL_LIBRARY})
  endif()
endif()

if(OS_WINDOWS)
  set(WSOCK32_LIBS
    wsock32
    ws2_32)
endif()

if(CURL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${CURL_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${CURL_LIBRARIES}
    ${WSOCK32_LIBS})
endif()

