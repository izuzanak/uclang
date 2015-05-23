
#ifndef __UCL_LUA_H
#define __UCL_LUA_H

@begin
include "script_parser.h"
@end

#ifdef __cplusplus
  extern "C" {
#endif

#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>

#ifdef __cplusplus
  }
#endif

/*
 * definition of structure lua_value_s
 */

struct lua_value_s
{
  location_s *lua_state_loc;
  int ref;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure lua_value_s
 */

inline void lua_value_s::init()
{/*{{{*/
  lua_state_loc = NULL;
  ref = 0;
}/*}}}*/

inline void lua_value_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (lua_state_loc != NULL)
  {
    lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;
    luaL_unref(L,LUA_REGISTRYINDEX,ref);

    it.release_location_ptr(lua_state_loc);
  }

  init();
}/*}}}*/

#endif

