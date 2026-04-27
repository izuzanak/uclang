
if(PKG_CONFIG_FOUND)
  pkg_search_module(CURSES "ncurses >= 6.0.0")
endif()

if(NOT CURSES_FOUND)
  find_package(Curses 6.0.0 QUIET)
endif()

if(NOT CURSES_FOUND)
  find_package(Curses CONFIG QUIET)
endif()

if(NOT CURSES_FOUND)
  find_path(CURSES_INCLUDE_DIR curses.h)
  find_library(CURSES_LIBRARY NAMES ncurses curses)
  if(CURSES_INCLUDE_DIR AND CURSES_LIBRARY)
    set(CURSES_FOUND TRUE)
    set(CURSES_INCLUDE_DIRS ${CURSES_INCLUDE_DIR})
    set(CURSES_LIBRARIES ${CURSES_LIBRARY})
  endif()
endif()

if(CURSES_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${CURSES_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${CURSES_LIBRARIES})
endif()

