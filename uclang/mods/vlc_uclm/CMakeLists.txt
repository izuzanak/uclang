
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBVLC "libvlc >= 3.0.6")
endif()

if(NOT LIBVLC_FOUND)
  find_package(LibVLC CONFIG QUIET)
  if(LibVLC_FOUND)
    set(LIBVLC_FOUND TRUE)
    if(TARGET LibVLC::libvlc)
      get_target_property(LIBVLC_INCLUDE_DIRS LibVLC::libvlc
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBVLC_LIBRARIES LibVLC::libvlc)
    endif()
  endif()
endif()

if(NOT LIBVLC_FOUND)
  find_path(LIBVLC_INCLUDE_DIR vlc/vlc.h)
  find_library(LIBVLC_LIBRARY NAMES vlc)
  if(LIBVLC_INCLUDE_DIR AND LIBVLC_LIBRARY)
    set(LIBVLC_FOUND TRUE)
    set(LIBVLC_INCLUDE_DIRS ${LIBVLC_INCLUDE_DIR})
    set(LIBVLC_LIBRARIES ${LIBVLC_LIBRARY})
  endif()
endif()

if(LIBVLC_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBVLC_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBVLC_LIBRARIES})
endif()

