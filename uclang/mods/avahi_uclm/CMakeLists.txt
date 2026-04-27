
if(PKG_CONFIG_FOUND)
  pkg_search_module(AVAHICLIENT "avahi-client >= 0.7")
endif()

if(NOT AVAHICLIENT_FOUND)
  find_package(avahi-client CONFIG QUIET)
  if(avahi-client_FOUND)
    set(AVAHICLIENT_FOUND TRUE)
    if(TARGET avahi-client::client)
      get_target_property(AVAHICLIENT_INCLUDE_DIRS avahi-client::client
          INTERFACE_INCLUDE_DIRECTORIES)
      set(AVAHICLIENT_LIBRARIES avahi-client::client)
    endif()
  endif()
endif()

if(NOT AVAHICLIENT_FOUND)
  find_path(AVAHICLIENT_INCLUDE_DIR avahi-client/client.h)
  find_library(AVAHICLIENT_LIBRARY NAMES avahi-client)
  if(AVAHICLIENT_INCLUDE_DIR AND AVAHICLIENT_LIBRARY)
    set(AVAHICLIENT_FOUND TRUE)
    set(AVAHICLIENT_INCLUDE_DIRS ${AVAHICLIENT_INCLUDE_DIR})
    set(AVAHICLIENT_LIBRARIES ${AVAHICLIENT_LIBRARY})
  endif()
endif()

if(AVAHICLIENT_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${AVAHICLIENT_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${AVAHICLIENT_LIBRARIES})
endif()

