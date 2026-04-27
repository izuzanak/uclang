
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBPIGPIO "pigpio")
  if(LIBPIGPIO_FOUND)
    set(LIBPIGPIO_LIBRARY ${LIBPIGPIO_LIBRARIES})
  endif()
endif()

if(NOT LIBPIGPIO_FOUND)
  find_package(pigpio CONFIG QUIET)
  if(pigpio_FOUND)
    set(LIBPIGPIO_FOUND TRUE)
    if(TARGET pigpio::pigpio)
      set(LIBPIGPIO_LIBRARY pigpio::pigpio)
    endif()
  endif()
endif()

if(NOT LIBPIGPIO_FOUND)
  find_path(PATH_PIGPIO_H NAMES "pigpio.h")
  if(PATH_PIGPIO_H)
    set(LIBPIGPIO_FOUND TRUE)
    set(LIBPIGPIO_LIBRARY pigpio)
  endif()
endif()

if(LIBPIGPIO_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBPIGPIO_LIBRARY})
endif()

