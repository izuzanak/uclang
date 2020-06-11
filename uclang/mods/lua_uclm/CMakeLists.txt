
find_package(Lua 5.2)

if(LUA_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LUA_INCLUDE_DIR})
  set(CONF_COMP_DEFS
    "-DLUA_COMPAT_5_2")
  set(CONF_LINK_LIBS
    base_ucll
    ${LUA_LIBRARIES})
endif()

