
if(PKG_CONFIG_FOUND)
  pkg_search_module(WIRINGPI "wiringpi")
  if(WIRINGPI_FOUND)
    set(WIRINGPI_LIBRARY ${WIRINGPI_LIBRARIES})
  endif()
endif()

if(NOT WIRINGPI_FOUND)
  find_package(WiringPi CONFIG QUIET)
  if(WiringPi_FOUND)
    set(WIRINGPI_FOUND TRUE)
    if(TARGET WiringPi::wiringPi)
      set(WIRINGPI_LIBRARY WiringPi::wiringPi)
    endif()
  endif()
endif()

if(NOT WIRINGPI_FOUND)
  find_path(PATH_WIRINGPI_H NAMES "wiringPiSPI.h")
  if(PATH_WIRINGPI_H)
    set(WIRINGPI_FOUND TRUE)
    set(WIRINGPI_LIBRARY wiringPi)
  endif()
endif()

if(WIRINGPI_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${WIRINGPI_LIBRARY}
  )
endif()

