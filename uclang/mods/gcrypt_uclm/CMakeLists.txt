
find_path(PATH_GCRYPT_H NAMES "gcrypt.h")

if(PATH_GCRYPT_H)
  set(LIBGCRYPT_FOUND TRUE)
  set(LIBGCRYPT_LIBRARY gcrypt)
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

