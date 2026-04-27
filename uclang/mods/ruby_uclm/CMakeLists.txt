
if(PKG_CONFIG_FOUND)
  pkg_search_module(RUBY "ruby-2.3")
  if(RUBY_FOUND)
    set(RUBY_INCLUDE_DIRS ${RUBY_INCLUDE_DIRS})
    set(RUBY_LIBRARY ${RUBY_LIBRARIES})
  endif()
endif()

if(NOT RUBY_FOUND)
  find_package(Ruby 2.3.0 QUIET)
endif()

if(NOT RUBY_FOUND)
  find_package(Ruby CONFIG QUIET)
endif()

if(NOT RUBY_FOUND)
  find_path(RUBY_INCLUDE_DIR ruby.h PATH_SUFFIXES ruby-2.3 ruby)
  find_library(RUBY_LIBRARY NAMES ruby-2.3 ruby)
  if(RUBY_INCLUDE_DIR AND RUBY_LIBRARY)
    set(RUBY_FOUND TRUE)
    set(RUBY_INCLUDE_DIRS ${RUBY_INCLUDE_DIR})
  endif()
endif()

if(RUBY_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${RUBY_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${RUBY_LIBRARY})
endif()

