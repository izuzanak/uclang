
find_path(PATH_UTF8PROC_H NAMES "utf8proc.h")

if(PATH_UTF8PROC_H)
  set(LIBUTF8PROC_FOUND TRUE)
  set(LIBUTF8PROC_LIBRARY utf8proc)
endif()

if(LIBUTF8PROC_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBUTF8PROC_LIBRARY})
endif()

