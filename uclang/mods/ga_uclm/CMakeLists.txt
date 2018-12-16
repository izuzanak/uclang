
find_library(GA_LIBRARY ga "${EXT_LIBS}/galib/galib247/ga")

set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS
  "${EXT_LIBS}/galib/galib247")
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll
  ${GA_LIBRARY})

