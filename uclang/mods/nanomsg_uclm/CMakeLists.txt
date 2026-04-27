
if(PKG_CONFIG_FOUND)
  pkg_search_module(NANOMSG "nanomsg >= 1.1.5")
endif()

if(NOT NANOMSG_FOUND)
  find_package(nanomsg CONFIG QUIET)
  if(nanomsg_FOUND)
    set(NANOMSG_FOUND TRUE)
    if(TARGET nanomsg::nanomsg)
      get_target_property(NANOMSG_INCLUDE_DIRS nanomsg::nanomsg
          INTERFACE_INCLUDE_DIRECTORIES)
      set(NANOMSG_LIBRARIES nanomsg::nanomsg)
    endif()
  endif()
endif()

if(NOT NANOMSG_FOUND)
  find_path(NANOMSG_INCLUDE_DIR nanomsg/nn.h)
  find_library(NANOMSG_LIBRARY NAMES nanomsg)
  if(NANOMSG_INCLUDE_DIR AND NANOMSG_LIBRARY)
    set(NANOMSG_FOUND TRUE)
    set(NANOMSG_INCLUDE_DIRS ${NANOMSG_INCLUDE_DIR})
    set(NANOMSG_LIBRARIES ${NANOMSG_LIBRARY})
  endif()
endif()

if(NANOMSG_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${NANOMSG_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${NANOMSG_LIBRARIES})
endif()

