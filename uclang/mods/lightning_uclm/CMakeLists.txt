
find_path(PATH_LIGHTNING_H NAMES "lightning.h")

if(PATH_LIGHTNING_H)
  set(LIBLIGHTNING_FOUND TRUE)
  set(LIBLIGHTNING_LIBRARY lightning)
endif()

if(LIBLIGHTNING_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBLIGHTNING_LIBRARY})
endif()

