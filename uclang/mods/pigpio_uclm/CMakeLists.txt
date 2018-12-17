
find_path(PATH_PIGPIO_H NAMES "pigpio.h")

if(PATH_PIGPIO_H)
  set(LIBPIGPIO_FOUND TRUE)
  set(LIBPIGPIO_LIBRARY pigpio)
endif()

if(LIBPIGPIO_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    libbase_ucll
    ${LIBPIGPIO_LIBRARY})
endif()

