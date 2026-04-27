
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFTP "ftplib")
  if(LIBFTP_FOUND)
    set(LIBFTP_LIBRARY ${LIBFTP_LIBRARIES})
  endif()
endif()

if(NOT LIBFTP_FOUND)
  find_package(Ftplib CONFIG QUIET)
  if(Ftplib_FOUND)
    set(LIBFTP_FOUND TRUE)
    if(TARGET Ftplib::ftp)
      get_target_property(LIBFTP_INCLUDE_DIRS Ftplib::ftp
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBFTP_LIBRARY Ftplib::ftp)
    endif()
  endif()
endif()

if(NOT LIBFTP_FOUND AND OS_LINUX)
  find_path(LIBFTP_INCLUDE_DIRS NAMES "ftplib.h")
  if(LIBFTP_INCLUDE_DIRS)
    set(LIBFTP_FOUND TRUE)
    set(LIBFTP_LIBRARY ftp)
  endif()
endif()

if(NOT LIBFTP_FOUND AND OS_WINDOWS)
  if(LIBFTP_INCLUDE_DIRS AND LIBFTP_LIBRARY)
    set(LIBFTP_FOUND TRUE)
  endif()
endif()

if(LIBFTP_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBFTP_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBFTP_LIBRARY})
endif()

