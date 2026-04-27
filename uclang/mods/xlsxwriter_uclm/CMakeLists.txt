
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBXLSXWRITER "xlsxwriter >= 1.1.8")
endif()

if(NOT LIBXLSXWRITER_FOUND)
  find_package(xlsxwriter CONFIG QUIET)
  if(xlsxwriter_FOUND)
    set(LIBXLSXWRITER_FOUND TRUE)
    if(TARGET xlsxwriter::xlsxwriter)
      get_target_property(LIBXLSXWRITER_INCLUDE_DIRS xlsxwriter::xlsxwriter
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBXLSXWRITER_LIBRARIES xlsxwriter::xlsxwriter)
    endif()
  endif()
endif()

if(NOT LIBXLSXWRITER_FOUND)
  find_path(LIBXLSXWRITER_INCLUDE_DIR xlsxwriter.h)
  find_library(LIBXLSXWRITER_LIBRARY NAMES xlsxwriter)
  if(LIBXLSXWRITER_INCLUDE_DIR AND LIBXLSXWRITER_LIBRARY)
    set(LIBXLSXWRITER_FOUND TRUE)
    set(LIBXLSXWRITER_INCLUDE_DIRS ${LIBXLSXWRITER_INCLUDE_DIR})
    set(LIBXLSXWRITER_LIBRARIES ${LIBXLSXWRITER_LIBRARY})
  endif()
endif()

if(LIBXLSXWRITER_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBXLSXWRITER_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBXLSXWRITER_LIBRARIES})
endif()

