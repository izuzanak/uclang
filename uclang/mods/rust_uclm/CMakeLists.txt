
if(PKG_CONFIG_FOUND)
  pkg_search_module(RUST_UCLM "rust_ruclm")
  if(RUST_UCLM_FOUND)
    set(RUST_UCLM_LIBRARY ${RUST_UCLM_LIBRARIES})
  endif()
endif()

if(NOT RUST_UCLM_LIBRARY)
  find_library(RUST_UCLM_LIBRARY rust_ruclm "${MODS}/rust_uclm/rs/target/release")
endif()

if(RUST_UCLM_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${RUST_UCLM_LIBRARY})
endif()

