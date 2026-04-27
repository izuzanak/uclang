
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBVA "libva-x11 >= 1.3.0")
endif()

if(NOT LIBVA_FOUND)
  find_package(LibVA CONFIG QUIET)
  if(LibVA_FOUND)
    set(LIBVA_FOUND TRUE)
    if(TARGET LibVA::va-x11)
      get_target_property(LIBVA_INCLUDE_DIRS LibVA::va-x11
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBVA_LIBRARIES LibVA::va-x11)
    endif()
  endif()
endif()

if(NOT LIBVA_FOUND)
  find_path(LIBVA_INCLUDE_DIR va/va_x11.h)
  find_library(LIBVA_LIBRARY NAMES va-x11)
  if(LIBVA_INCLUDE_DIR AND LIBVA_LIBRARY)
    set(LIBVA_FOUND TRUE)
    set(LIBVA_INCLUDE_DIRS ${LIBVA_INCLUDE_DIR})
    set(LIBVA_LIBRARIES ${LIBVA_LIBRARY})
  endif()
endif()

if(LIBVA_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBVA_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    "-lva-x11"
    ${LIBVA_LIBRARIES})
endif()

