
if(PKG_CONFIG_FOUND)
  pkg_search_module(OPENSSL "libcrypto >= 1.0.1")
  if(OPENSSL_FOUND)
    set(OPENSSL_INCLUDE_DIR ${OPENSSL_INCLUDE_DIRS})
    set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_LIBRARIES})
  endif()
endif()

if(NOT OPENSSL_FOUND)
  find_package(OpenSSL 1.0.1 QUIET)
endif()

if(NOT OPENSSL_FOUND)
  find_package(OpenSSL CONFIG QUIET)
  if(OpenSSL_FOUND)
    set(OPENSSL_FOUND TRUE)
    if(TARGET OpenSSL::Crypto)
      get_target_property(OPENSSL_INCLUDE_DIR OpenSSL::Crypto
          INTERFACE_INCLUDE_DIRECTORIES)
      set(OPENSSL_CRYPTO_LIBRARY OpenSSL::Crypto)
    endif()
  endif()
endif()

if(NOT OPENSSL_FOUND)
  find_path(OPENSSL_INCLUDE_DIR openssl/crypto.h)
  find_library(OPENSSL_CRYPTO_LIBRARY NAMES crypto)
  if(OPENSSL_INCLUDE_DIR AND OPENSSL_CRYPTO_LIBRARY)
    set(OPENSSL_FOUND TRUE)
  endif()
endif()

if(OPENSSL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${OPENSSL_INCLUDE_DIR})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${OPENSSL_CRYPTO_LIBRARY})
endif()

