
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBQRENCODE "libqrencode >= 4.0.2")
endif()

if(NOT LIBQRENCODE_FOUND)
  find_package(QREncode CONFIG QUIET)
  if(QREncode_FOUND)
    set(LIBQRENCODE_FOUND TRUE)
    if(TARGET QREncode::qrencode)
      get_target_property(LIBQRENCODE_INCLUDE_DIRS QREncode::qrencode
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBQRENCODE_LIBRARIES QREncode::qrencode)
    endif()
  endif()
endif()

if(NOT LIBQRENCODE_FOUND)
  find_path(LIBQRENCODE_INCLUDE_DIR qrencode.h)
  find_library(LIBQRENCODE_LIBRARY NAMES qrencode)
  if(LIBQRENCODE_INCLUDE_DIR AND LIBQRENCODE_LIBRARY)
    set(LIBQRENCODE_FOUND TRUE)
    set(LIBQRENCODE_INCLUDE_DIRS ${LIBQRENCODE_INCLUDE_DIR})
    set(LIBQRENCODE_LIBRARIES ${LIBQRENCODE_LIBRARY})
  endif()
endif()

if(LIBQRENCODE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBQRENCODE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBQRENCODE_LIBRARIES})
endif()

