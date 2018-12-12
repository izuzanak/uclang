
set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS
  "/usr/include/gstreamer-1.0"
  "/usr/include/libxml2"
  "/usr/include/glib-2.0"
  "/usr/lib/i386-linux-gnu/glib-2.0/include"
  "/usr/lib/i386-linux-gnu/gstreamer-1.0/include")
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll
  z
  gstreamer-1.0
  gobject-2.0
  gmodule-2.0
  gthread-2.0
  rt
  xml2
  glib-2.0)

