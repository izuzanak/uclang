
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGCRYPT "libgcrypt")
  if(LIBGCRYPT_FOUND)
    set(LIBGCRYPT_LIBRARY ${LIBGCRYPT_LIBRARIES})
  endif()
endif()

if(NOT LIBGCRYPT_FOUND)
  find_package(Libgcrypt CONFIG QUIET)
  if(Libgcrypt_FOUND)
    set(LIBGCRYPT_FOUND TRUE)
    if(TARGET Libgcrypt::gcrypt)
      get_target_property(LIBGCRYPT_INCLUDE_DIRS Libgcrypt::gcrypt
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBGCRYPT_LIBRARY Libgcrypt::gcrypt)
    endif()
  endif()
endif()

if(NOT LIBGCRYPT_FOUND)
  find_path(PATH_GCRYPT_H NAMES "gcrypt.h")
  if(PATH_GCRYPT_H)
    set(LIBGCRYPT_FOUND TRUE)
    set(LIBGCRYPT_LIBRARY gcrypt)
  endif()
endif()

if(LIBGCRYPT_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBGCRYPT_LIBRARY})
endif()

