
set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS)
set(CONF_COMP_DEFS
  "-D__STDC_CONSTANT_MACROS -Wno-deprecated-declarations")
set(CONF_LINK_LIBS
  libbase_ucll
  avutil
  avformat
  avcodec
  swscale)

