
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBBTRFSUTIL "libbtrfsutil >= 6.2")
endif()

if(NOT LIBBTRFSUTIL_FOUND)
  find_package(BtrfsUtil CONFIG QUIET)
  if(BtrfsUtil_FOUND)
    set(LIBBTRFSUTIL_FOUND TRUE)
    if(TARGET BtrfsUtil::btrfsutil)
      get_target_property(LIBBTRFSUTIL_INCLUDE_DIRS BtrfsUtil::btrfsutil
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBBTRFSUTIL_LIBRARIES BtrfsUtil::btrfsutil)
    endif()
  endif()
endif()

if(NOT LIBBTRFSUTIL_FOUND)
  find_path(LIBBTRFSUTIL_INCLUDE_DIR btrfsutil.h)
  find_library(LIBBTRFSUTIL_LIBRARY NAMES btrfsutil)
  if(LIBBTRFSUTIL_INCLUDE_DIR AND LIBBTRFSUTIL_LIBRARY)
    set(LIBBTRFSUTIL_FOUND TRUE)
    set(LIBBTRFSUTIL_INCLUDE_DIRS ${LIBBTRFSUTIL_INCLUDE_DIR})
    set(LIBBTRFSUTIL_LIBRARIES ${LIBBTRFSUTIL_LIBRARY})
  endif()
endif()

if(LIBBTRFSUTIL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBBTRFSUTIL_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBBTRFSUTIL_LIBRARIES})
endif()

