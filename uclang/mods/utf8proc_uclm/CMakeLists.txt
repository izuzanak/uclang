
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBUTF8PROC "libutf8proc")
  if(LIBUTF8PROC_FOUND)
    set(LIBUTF8PROC_LIBRARY ${LIBUTF8PROC_LIBRARIES})
  endif()
endif()

if(NOT LIBUTF8PROC_FOUND)
  find_package(utf8proc CONFIG QUIET)
  if(utf8proc_FOUND)
    set(LIBUTF8PROC_FOUND TRUE)
    if(TARGET utf8proc::utf8proc)
      set(LIBUTF8PROC_LIBRARY utf8proc::utf8proc)
    endif()
  endif()
endif()

if(NOT LIBUTF8PROC_FOUND)
  find_path(PATH_UTF8PROC_H NAMES "utf8proc.h")
  if(PATH_UTF8PROC_H)
    set(LIBUTF8PROC_FOUND TRUE)
    set(LIBUTF8PROC_LIBRARY utf8proc)
  endif()
endif()

if(LIBUTF8PROC_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBUTF8PROC_LIBRARY})
endif()

