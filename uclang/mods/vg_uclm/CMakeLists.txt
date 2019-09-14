
find_library(AMANITHVG_LIBRARY AmanithVG "${EXT_LIBS}/AmanithVG/libs")

if(AMANITHVG_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${EXT_LIBS}/AmanithVG/include")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${AMANITHVG_LIBRARY})
endif()

