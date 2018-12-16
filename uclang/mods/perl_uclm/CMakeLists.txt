
find_library(PERL_LIBRARY perl "/usr/lib/i386-linux-gnu")

set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS
  "/usr/lib/i386-linux-gnu/perl/5.28/CORE")
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  libbase_ucll
  ${PERL_LIBRARY})

