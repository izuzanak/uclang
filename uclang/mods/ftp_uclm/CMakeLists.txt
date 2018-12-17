
find_path(PATH_FTPLIB_H NAMES "ftplib.h")

if(PATH_FTPLIB_H)
  set(LIBFTP_FOUND TRUE)
  set(LIBFTP_LIBRARY ftp)
endif()

if(LIBFTP_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBFTP_LIBRARY})
endif()

