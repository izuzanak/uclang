
if(PKG_CONFIG_FOUND)
  pkg_search_module(PROTOBUF "libprotobuf-c >= 1.3.1")
endif()

if(NOT PROTOBUF_FOUND)
  find_package(protobuf-c CONFIG QUIET)
  if(protobuf-c_FOUND)
    set(PROTOBUF_FOUND TRUE)
    if(TARGET protobuf-c::protobuf-c)
      get_target_property(PROTOBUF_INCLUDE_DIRS protobuf-c::protobuf-c
          INTERFACE_INCLUDE_DIRECTORIES)
      set(PROTOBUF_LIBRARIES protobuf-c::protobuf-c)
    endif()
  endif()
endif()

if(NOT PROTOBUF_FOUND)
  find_path(PROTOBUF_INCLUDE_DIR protobuf-c/protobuf-c.h)
  find_library(PROTOBUF_LIBRARY NAMES protobuf-c)
  if(PROTOBUF_INCLUDE_DIR AND PROTOBUF_LIBRARY)
    set(PROTOBUF_FOUND TRUE)
    set(PROTOBUF_INCLUDE_DIRS ${PROTOBUF_INCLUDE_DIR})
    set(PROTOBUF_LIBRARIES ${PROTOBUF_LIBRARY})
  endif()
endif()

if(PROTOBUF_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PROTOBUF_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${PROTOBUF_LIBRARIES})
endif()

