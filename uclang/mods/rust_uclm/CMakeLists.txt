
find_library(RUST_UCLM_LIBRARY rust_ruclm "${MODS}/rust_uclm/rs/target/release")

set(CONF_DO_BUILD FALSE)
set(CONF_HEADER_DIRS
  "${LIB_BASE}/header_files")
set(CONF_INCLUDE_DIRS)
set(CONF_COMP_DEFS)
set(CONF_LINK_LIBS
  base_ucll
  ${RUST_UCLM_LIBRARY})

