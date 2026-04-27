
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBDATRIE "datrie-0.2 >= 0.2.10")
endif()

if(NOT LIBDATRIE_FOUND)
  find_package(Datrie CONFIG QUIET)
  if(Datrie_FOUND)
    set(LIBDATRIE_FOUND TRUE)
    if(TARGET Datrie::datrie)
      get_target_property(LIBDATRIE_INCLUDE_DIRS Datrie::datrie
          INTERFACE_INCLUDE_DIRECTORIES)
      set(LIBDATRIE_LIBRARIES Datrie::datrie)
    endif()
  endif()
endif()

if(NOT LIBDATRIE_FOUND)
  find_path(LIBDATRIE_INCLUDE_DIR datrie/trie.h)
  find_library(LIBDATRIE_LIBRARY NAMES datrie)
  if(LIBDATRIE_INCLUDE_DIR AND LIBDATRIE_LIBRARY)
    set(LIBDATRIE_FOUND TRUE)
    set(LIBDATRIE_INCLUDE_DIRS ${LIBDATRIE_INCLUDE_DIR})
    set(LIBDATRIE_LIBRARIES ${LIBDATRIE_LIBRARY})
  endif()
endif()

if(LIBDATRIE_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
     ${LIBDATRIE_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBDATRIE_LIBRARIES})
endif()

