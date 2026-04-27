
if(PKG_CONFIG_FOUND)
  pkg_search_module(PERLLIBS "libperl")
  if(PERLLIBS_FOUND)
    set(PERL_INCLUDE_PATH ${PERLLIBS_INCLUDE_DIRS})
    set(PERL_LIBRARY ${PERLLIBS_LIBRARIES})
  endif()
endif()

if(NOT PERLLIBS_FOUND)
  find_package(PerlLibs QUIET)
endif()

if(NOT PERLLIBS_FOUND)
  find_package(PerlLibs CONFIG QUIET)
endif()

if(NOT PERLLIBS_FOUND)
  find_path(PERL_INCLUDE_PATH EXTERN.h)
  find_library(PERL_LIBRARY NAMES perl)
  if(PERL_INCLUDE_PATH AND PERL_LIBRARY)
    set(PERLLIBS_FOUND TRUE)
  endif()
endif()

if(PERLLIBS_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PERL_INCLUDE_PATH})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${PERL_LIBRARY})
endif()

