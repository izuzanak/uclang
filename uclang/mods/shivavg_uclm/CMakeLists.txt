
find_library(OPENVG_LIBRARY OpenVG "${EXT_LIBS}/ShivaVG-0.2.1/src/.libs")

set(CONF_DO_BUILD FALSE)
set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS
  "${EXT_LIBS}/ShivaVG-0.2.1/include")
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll
  ${OPENVG_LIBRARY}
  GL
  GLU
  )

