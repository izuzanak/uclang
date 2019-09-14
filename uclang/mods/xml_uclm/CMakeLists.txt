
find_package(LibXml2 2.9.1)

if(LIBXML2_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBXML2_INCLUDE_DIR})
  set(CONF_COMP_DEFS
    ${LIBXML2_DEFINITIONS})
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBXML2_LIBRARIES})
endif()

