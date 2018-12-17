
find_library(UCF_LIBRARY ucf "${EXT_LIBS}/ucframework/1.60/build/lib")

if (UCF_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${EXT_LIBS}/ucframework/1.60/build/include"
    "${EXT_LIBS}/unicon/execnt/src"
    "${EXT_LIBS}/adaptrain/adaptrain-structs/include")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${UCF_LIBRARY})
endif()

