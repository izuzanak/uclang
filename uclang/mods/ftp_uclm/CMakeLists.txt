
if(OS_LINUX)
  find_path(LIBFTP_INCLUDE_DIRS NAMES "ftplib.h")

  if(LIBFTP_INCLUDE_DIRS)
    set(LIBFTP_FOUND TRUE)
    set(LIBFTP_LIBRARY ftp)
  endif()
endif()

if(OS_WINDOWS)
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
    libbase_ucll
    ${LIBFTP_LIBRARY})
endif()

