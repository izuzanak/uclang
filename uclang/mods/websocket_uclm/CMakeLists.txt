
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBWEBSOCKETS "libwebsockets >= 4.0.1")
endif()

if(NOT LIBWEBSOCKETS_FOUND)
  find_package(Libwebsockets CONFIG QUIET)
  if(Libwebsockets_FOUND)
    set(LIBWEBSOCKETS_FOUND TRUE)
    if(TARGET websockets)
      get_target_property(LIBWEBSOCKETS_INCLUDE_DIRS websockets
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBWEBSOCKETS_LIBRARIES websockets)
    endif()
  endif()
endif()

if(NOT LIBWEBSOCKETS_FOUND)
  find_path(LIBWEBSOCKETS_INCLUDE_DIR libwebsockets.h)
  find_library(LIBWEBSOCKETS_LIBRARY NAMES websockets)
  if(LIBWEBSOCKETS_INCLUDE_DIR AND LIBWEBSOCKETS_LIBRARY)
    set(LIBWEBSOCKETS_FOUND TRUE)
    set(LIBWEBSOCKETS_INCLUDE_DIRS ${LIBWEBSOCKETS_INCLUDE_DIR})
    set(LIBWEBSOCKETS_LIBRARIES ${LIBWEBSOCKETS_LIBRARY})
  endif()
endif()

if(OS_WINDOWS)
  set(WSOCK32_LIBS
    wsock32
    ws2_32)
endif()

if(LIBWEBSOCKETS_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBWEBSOCKETS_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBWEBSOCKETS_LIBRARIES}
    ${WSOCK32_LIBS})
endif()

