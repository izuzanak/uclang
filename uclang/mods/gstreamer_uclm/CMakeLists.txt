
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGSTREAMER "gstreamer-1.0 >= 1.4.4")
endif()

if(NOT LIBGSTREAMER_FOUND)
  find_package(GStreamer CONFIG QUIET)
  if(GStreamer_FOUND)
    set(LIBGSTREAMER_FOUND TRUE)
    if(TARGET GStreamer::gstreamer-1.0)
      get_target_property(LIBGSTREAMER_INCLUDE_DIRS GStreamer::gstreamer-1.0
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBGSTREAMER_LIBRARIES GStreamer::gstreamer-1.0)
    endif()
  endif()
endif()

if(NOT LIBGSTREAMER_FOUND)
  find_path(LIBGSTREAMER_INCLUDE_DIR gst/gst.h PATH_SUFFIXES gstreamer-1.0)
  find_library(LIBGSTREAMER_LIBRARY NAMES gstreamer-1.0)
  if(LIBGSTREAMER_INCLUDE_DIR AND LIBGSTREAMER_LIBRARY)
    set(LIBGSTREAMER_FOUND TRUE)
    set(LIBGSTREAMER_INCLUDE_DIRS ${LIBGSTREAMER_INCLUDE_DIR})
    set(LIBGSTREAMER_LIBRARIES ${LIBGSTREAMER_LIBRARY})
  endif()
endif()

if(LIBGSTREAMER_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBGSTREAMER_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBGSTREAMER_LIBRARIES})
endif()

