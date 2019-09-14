
find_library(GURUXNET_LIBRARY GuruxNet "${EXT_LIBS}/gurux/lib")
find_library(GURUXDLMS_LIBRARY GuruxDLMSLib "${EXT_LIBS}/gurux/lib")

set(CONF_DO_BUILD FALSE)
set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS
  "${EXT_LIBS}/gurux/include")
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  base_ucll
  ${GURUXNET_LIBRARY}
  ${GURUXDLMS_LIBRARY})

