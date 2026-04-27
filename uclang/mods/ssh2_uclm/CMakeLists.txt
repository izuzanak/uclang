
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBSSH2 "libssh2 >= 1.4.3")
endif()

if(NOT LIBSSH2_FOUND)
  find_package(Libssh2 CONFIG QUIET)
  if(Libssh2_FOUND)
    set(LIBSSH2_FOUND TRUE)
    if(TARGET Libssh2::libssh2)
      get_target_property(LIBSSH2_INCLUDE_DIRS Libssh2::libssh2
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBSSH2_LIBRARIES Libssh2::libssh2)
    endif()
  endif()
endif()

if(NOT LIBSSH2_FOUND)
  find_path(LIBSSH2_INCLUDE_DIR libssh2.h)
  find_library(LIBSSH2_LIBRARY NAMES ssh2)
  if(LIBSSH2_INCLUDE_DIR AND LIBSSH2_LIBRARY)
    set(LIBSSH2_FOUND TRUE)
    set(LIBSSH2_INCLUDE_DIRS ${LIBSSH2_INCLUDE_DIR})
    set(LIBSSH2_LIBRARIES ${LIBSSH2_LIBRARY})
  endif()
endif()

if(LIBSSH2_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBSSH2_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBSSH2_LIBRARIES})
endif()

