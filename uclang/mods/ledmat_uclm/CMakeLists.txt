
find_path(PATH_WIRINGPI_H NAMES "wiringPiSPI.h")

if(PATH_WIRINGPI_H)
  set(WIRINGPI_FOUND TRUE)
  set(WIRINGPI_LIBRARY wiringPi)
endif()

#set(WIRINGPI_FOUND TRUE)
#set(WIRINGPI_LIBRARY)

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

