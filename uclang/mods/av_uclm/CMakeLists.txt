
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBAVUTIL "libavutil >= 54.3.0")
  pkg_search_module(LIBAVFORMAT "libavformat >= 56.1.0")
  pkg_search_module(LIBAVCODEC "libavcodec >= 56.1.0")
  pkg_search_module(LIBSWSCALE "libswscale >= 3.0.0")
endif()

if(LIBAVUTIL_FOUND AND LIBAVFORMAT_FOUND AND LIBAVCODEC_FOUND AND LIBSWSCALE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBAVUTIL_INCLUDE_DIRS}
    ${LIBAVFORMAT_INCLUDE_DIRS}
    ${LIBAVCODEC_INCLUDE_DIRS}
    ${LIBSWSCALE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    "-D__STDC_CONSTANT_MACROS -Wno-deprecated-declarations")
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBAVUTIL_LIBRARIES}
    ${LIBAVFORMAT_LIBRARIES}
    ${LIBAVCODEC_LIBRARIES}
    ${LIBSWSCALE_LIBRARIES})
endif()

