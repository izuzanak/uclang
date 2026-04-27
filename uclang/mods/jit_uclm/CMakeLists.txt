
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBJIT "libjit >= 0.1.4")
endif()

if(NOT LIBJIT_FOUND)
  find_package(LibJIT CONFIG QUIET)
  if(LibJIT_FOUND)
    set(LIBJIT_FOUND TRUE)
    if(TARGET LibJIT::jit)
      get_target_property(LIBJIT_INCLUDE_DIRS LibJIT::jit
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBJIT_LIBRARIES LibJIT::jit)
    endif()
  endif()
endif()

if(NOT LIBJIT_FOUND)
  find_path(LIBJIT_INCLUDE_DIR jit/jit.h)
  find_library(LIBJIT_LIBRARY NAMES jit)
  if(LIBJIT_INCLUDE_DIR AND LIBJIT_LIBRARY)
    set(LIBJIT_FOUND TRUE)
    set(LIBJIT_INCLUDE_DIRS ${LIBJIT_INCLUDE_DIR})
    set(LIBJIT_LIBRARIES ${LIBJIT_LIBRARY})
  endif()
endif()

if(LIBJIT_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBJIT_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBJIT_LIBRARIES})
endif()

