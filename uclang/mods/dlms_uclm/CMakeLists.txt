
if(PKG_CONFIG_FOUND)
  pkg_search_module(GURUXNET "GuruxNet")
  pkg_search_module(GURUXDLMS "GuruxDLMSLib")
endif()

if(NOT GURUXNET_FOUND)
  find_package(GuruxNet CONFIG QUIET)
  if(GuruxNet_FOUND)
    set(GURUXNET_FOUND TRUE)
    if(TARGET GuruxNet::GuruxNet)
      set(GURUXNET_LIBRARY GuruxNet::GuruxNet)
    endif()
  endif()
endif()

if(NOT GURUXNET_FOUND)
  find_library(GURUXNET_LIBRARY GuruxNet "${EXT_LIBS}/gurux/lib")
endif()

if(NOT GURUXDLMS_FOUND)
  find_package(GuruxDLMSLib CONFIG QUIET)
  if(GuruxDLMSLib_FOUND)
    set(GURUXDLMS_FOUND TRUE)
    if(TARGET GuruxDLMSLib::GuruxDLMSLib)
      set(GURUXDLMS_LIBRARY GuruxDLMSLib::GuruxDLMSLib)
    endif()
  endif()
endif()

if(NOT GURUXDLMS_FOUND)
  find_library(GURUXDLMS_LIBRARY GuruxDLMSLib "${EXT_LIBS}/gurux/lib")
endif()

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

