
find_library(QUIRC_LIBRARY quirc "${EXT_LIBS}/quirc/quirc-1.0")

if(QUIRC_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${EXT_LIBS}/quirc/quirc-1.0/lib")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${QUIRC_LIBRARY})
endif()

