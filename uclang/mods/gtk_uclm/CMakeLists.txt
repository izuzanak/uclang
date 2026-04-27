
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGTK3 "gtk+-3.0 >= 3.18.9")
endif()

if(NOT LIBGTK3_FOUND)
  find_package(GTK3 CONFIG QUIET)
  if(GTK3_FOUND)
    set(LIBGTK3_FOUND TRUE)
    if(TARGET GTK3::gtk)
      get_target_property(LIBGTK3_INCLUDE_DIRS GTK3::gtk
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBGTK3_LIBRARIES GTK3::gtk)
    endif()
  endif()
endif()

if(NOT LIBGTK3_FOUND)
  find_path(LIBGTK3_INCLUDE_DIR gtk/gtk.h PATH_SUFFIXES gtk-3.0)
  find_library(LIBGTK3_LIBRARY NAMES gtk-3)
  if(LIBGTK3_INCLUDE_DIR AND LIBGTK3_LIBRARY)
    set(LIBGTK3_FOUND TRUE)
    set(LIBGTK3_INCLUDE_DIRS ${LIBGTK3_INCLUDE_DIR})
    set(LIBGTK3_LIBRARIES ${LIBGTK3_LIBRARY})
  endif()
endif()

if(LIBGTK3_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBGTK3_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBGTK3_LIBRARIES})
endif()

