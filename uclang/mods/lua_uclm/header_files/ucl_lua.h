
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
 * constants and definitions
 */

extern unsigned c_bi_class_lua_value;
extern unsigned c_bi_class_lua_reference;
extern unsigned c_rm_class_dict;

// - max method name length -
const unsigned c_max_method_name_length = 256;

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
 * definition of structure lua_reference_s
 */

struct lua_reference_s
{
  location_s *lua_state_loc;
  int obj_ref;
  int key_ref;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline void get();
  inline void set();
};

/*
 * definition of structure lua_s
 */
class lua_s
{
  public:
  static unsigned table_key_count(lua_State *L);
  static bool create_lua_object(interpreter_thread_s &it,lua_State *L,location_s *location_ptr);
  static location_s *lua_object_value(interpreter_thread_s &it,lua_State *L,uli source_pos);
};

/*
 * inline methods of structure lua_value_s
 */

inline void lua_value_s::init()
{/*{{{*/
  lua_state_loc = NULL;
  ref = LUA_NOREF;
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

/*
 * inline methods of structure lua_reference_s
 */

inline void lua_reference_s::init()
{/*{{{*/
  lua_state_loc = NULL;
  obj_ref = LUA_NOREF;
  key_ref = LUA_NOREF;
}/*}}}*/

inline void lua_reference_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (lua_state_loc != NULL)
  {
    lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;
    luaL_unref(L,LUA_REGISTRYINDEX,obj_ref);
    luaL_unref(L,LUA_REGISTRYINDEX,key_ref);

    it.release_location_ptr(lua_state_loc);
  }

  init();
}/*}}}*/

inline void lua_reference_s::get()
{/*{{{*/
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;
  lua_rawgeti(L,LUA_REGISTRYINDEX,obj_ref);
  lua_rawgeti(L,LUA_REGISTRYINDEX,key_ref);
  lua_rawget(L,-2);
  lua_replace(L,-2);
}/*}}}*/

inline void lua_reference_s::set()
{/*{{{*/
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;
  lua_rawgeti(L,LUA_REGISTRYINDEX,obj_ref);
  lua_rawgeti(L,LUA_REGISTRYINDEX,key_ref);
  lua_pushvalue(L,-3);
  lua_rawset(L,-3);
  lua_pop(L,2);
}/*}}}*/

#endif

