
if(PKG_CONFIG_FOUND)
  pkg_search_module(OPENSSL "openssl >= 1.0.1")
endif()

if(NOT OPENSSL_FOUND)
  find_package(OpenSSL 1.0.1 QUIET)
endif()

if(NOT OPENSSL_FOUND)
  find_package(OpenSSL CONFIG QUIET)
  if(OpenSSL_FOUND)
    set(OPENSSL_FOUND TRUE)
    if(TARGET OpenSSL::SSL)
      get_target_property(OPENSSL_INCLUDE_DIR OpenSSL::SSL
          INTERFACE_INCLUDE_DIRECTORIES)
      set(OPENSSL_LIBRARIES OpenSSL::SSL OpenSSL::Crypto)
    endif()
  endif()
endif()

if(NOT OPENSSL_FOUND)
  find_path(OPENSSL_INCLUDE_DIR openssl/ssl.h)
  find_library(OPENSSL_SSL_LIBRARY NAMES ssl)
  find_library(OPENSSL_CRYPTO_LIBRARY NAMES crypto)
  if(OPENSSL_INCLUDE_DIR AND OPENSSL_SSL_LIBRARY AND OPENSSL_CRYPTO_LIBRARY)
    set(OPENSSL_FOUND TRUE)
    set(OPENSSL_LIBRARIES ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY})
  endif()
endif()

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

