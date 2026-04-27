
if(PKG_CONFIG_FOUND)
  pkg_search_module(LUA "lua >= 5.2")
  if(LUA_FOUND)
    set(LUA_INCLUDE_DIR ${LUA_INCLUDE_DIRS})
  endif()
endif()

if(NOT LUA_FOUND)
  find_package(Lua 5.2 QUIET)
endif()

if(NOT LUA_FOUND)
  find_package(Lua CONFIG QUIET)
endif()

if(NOT LUA_FOUND)
  find_path(LUA_INCLUDE_DIR lua.h PATH_SUFFIXES lua5.3 lua5.2 lua)
  find_library(LUA_LIBRARY NAMES lua5.3 lua5.2 lua)
  if(LUA_INCLUDE_DIR AND LUA_LIBRARY)
    set(LUA_FOUND TRUE)
    set(LUA_LIBRARIES ${LUA_LIBRARY})
  endif()
endif()

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

