
find_package(OpenSSL 1.0.2)

if(OS_LINUX OR OS_MSYS2)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")

  if(OPENSSL_FOUND)
    set(CONF_INCLUDE_DIRS
      ${OPENSSL_INCLUDE_DIR})
    set(CONF_COMP_DEFS
      "-DUCL_WITH_OPENSSL")
    set(CONF_LINK_LIBS
      base_ucll
      ${OPENSSL_LIBRARIES})
  else()
    set(CONF_INCLUDE_DIRS)
    set(CONF_COMP_DEFS)
    set(CONF_LINK_LIBS
      base_ucll)
  endif()

endif()

