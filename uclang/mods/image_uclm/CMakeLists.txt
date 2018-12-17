
find_package(PNG 1.2.50)
find_package(JPEG)

if(PNG_FOUND AND JPEG_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${PNG_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    ${PNG_DEFINITIONS})
  set(CONF_LINK_LIBS
    libbase_ucll
    ${PNG_LIBRARIES}
    ${JPEG_LIBRARIES})
endif()

