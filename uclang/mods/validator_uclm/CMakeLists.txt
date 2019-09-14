
set(PCRE_DEFS)

if(PKG_CONFIG_FOUND)
  pkg_search_module(PCRE "libpcreposix")
else()
  if(OS_WINDOWS AND PCRE_INCLUDE_DIRS AND PCRE_LIBRARIES)
    set(PCRE_FOUND TRUE)
    set(PCRE_DEFS "-DPCRE_STATIC")
  endif()
endif()

if(PCRE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PCRE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    ${PCRE_DEFS})
  set(CONF_LINK_LIBS
    base_ucll
    ${PCRE_LIBRARIES})
endif()

