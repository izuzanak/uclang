
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBFREETYPE2 "freetype2 >= 22.1.16")
  pkg_search_module(LIBGLEW "glew >= 2.1.0")
endif()

if(LIBFREETYPE2_FOUND AND LIBGLEW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files"
    "${LIB_FTGL}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ftgl_ucll)
endif()

