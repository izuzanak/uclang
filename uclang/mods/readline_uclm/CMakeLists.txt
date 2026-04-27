
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBREADLINE "readline")
endif()

if(NOT LIBREADLINE_FOUND)
  find_package(Readline CONFIG QUIET)
  if(Readline_FOUND)
    set(LIBREADLINE_FOUND TRUE)
    if(TARGET Readline::readline)
      get_target_property(LIBREADLINE_INCLUDE_DIRS Readline::readline
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBREADLINE_LIBRARIES Readline::readline)
    endif()
  endif()
endif()

if(NOT LIBREADLINE_FOUND)
  find_path(LIBREADLINE_INCLUDE_DIR readline/readline.h)
  find_library(LIBREADLINE_LIBRARY NAMES readline)
  if(LIBREADLINE_INCLUDE_DIR AND LIBREADLINE_LIBRARY)
    set(LIBREADLINE_FOUND TRUE)
    set(LIBREADLINE_INCLUDE_DIRS ${LIBREADLINE_INCLUDE_DIR})
    set(LIBREADLINE_LIBRARIES ${LIBREADLINE_LIBRARY})
  endif()
endif()

if(LIBREADLINE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBREADLINE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBREADLINE_LIBRARIES})
endif()

