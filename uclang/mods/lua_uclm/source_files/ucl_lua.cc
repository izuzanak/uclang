
@begin
include "ucl_lua.h"
@end

/*
 * methods of structure lua_s
 */

unsigned lua_s::table_key_count(lua_State *L)
{/*{{{*/
  unsigned count = 0;

  lua_pushnil(L);
  while (lua_next(L,-2) != 0)
  {
    ++count;
    lua_pop(L,1);
  }

  return count;
}/*}}}*/

bool lua_s::create_lua_object(interpreter_thread_s &it,lua_State *L,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_lua_value)
  {
    lua_value_s *lv_ptr = (lua_value_s *)location_ptr->v_data_ptr;
    lua_State *lv_ptr_L = (lua_State *)lv_ptr->lua_state_loc->v_data_ptr;

    // - lua value from another lua state -
    if (lv_ptr_L != L)
    {
      return false;
    }

    lua_rawgeti(L,LUA_REGISTRYINDEX,lv_ptr->ref);
    return true;
  }
  else if (location_ptr->v_type == c_bi_class_lua_reference)
  {/*{{{*/
    
    // FIXME TODO continue ...
    return false;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;
    lua_createtable(L,0,tree_ptr->count);

    if (tree_ptr->root_idx != c_idx_not_exist)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        pointer_map_tree_s_node &node = tree_ptr->data[t_idx];

        // - ERROR -
        if (!create_lua_object(it,L,it.get_location_value(node.object.key)))
        {
          lua_pop(L,1);
          return false;
        }

        // - ERROR -
        if (!create_lua_object(it,L,it.get_location_value(node.object.value)))
        {
          lua_pop(L,2);
          return false;
        }

        // - set lua table field -
        lua_rawset(L,-3);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return true;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      {
        lua_pushnil(L);
        return true;
      }
    case c_bi_class_char:
      {
        lua_pushinteger(L,(char)location_ptr->v_data_ptr);
        return true;
      }
    case c_bi_class_integer:
      {
        lua_pushinteger(L,(long long int)location_ptr->v_data_ptr);
        return true;
      }
    case c_bi_class_float:
      {
        lua_pushnumber(L,*((double *)&location_ptr->v_data_ptr));
        return true;
      }
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        lua_pushlstring(L,string_ptr->data,string_ptr->size - 1);
        return true;
      }
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
        lua_createtable(L,array_ptr->used,0);

        if (array_ptr->used)
        {
          unsigned idx = 0;
          do {

            // - ERROR -
            if (!create_lua_object(it,L,(location_s *)array_ptr->data[idx]))
            {
              lua_pop(L,1);
              return false;
            }

            // - set lua table item -
            lua_rawseti(L,-2,idx + 1);

          } while(++idx < array_ptr->used);
        }

        return true;
      }/*}}}*/

    // - ERROR -
    default:
      return false;
    }
  }
}/*}}}*/

location_s *lua_s::lua_object_value(interpreter_thread_s &it,lua_State *L,uli source_pos)
{/*{{{*/
  switch (lua_type(L,-1))
  {
    case LUA_TNIL:
      {
        lua_pop(L,1);
        ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
        return (location_s *)it.blank_location;
      }
    case LUA_TNUMBER:
      {
        double value = lua_tonumber(L,-1);
        lua_pop(L,1);

        basic_64b &v_data_ptr = *((basic_64b *)&value);
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,v_data_ptr);
        return new_location;
      }
    case LUA_TBOOLEAN:
      {
        long long int value = lua_toboolean(L,-1);
        lua_pop(L,1);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
        return new_location;
      }
    case LUA_TSTRING:
      {
        size_t length;
        const char *data = lua_tolstring(L,-1,&length);

        // - create string object -
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(length,data);

        lua_pop(L,1);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        return new_location;
      }
    case LUA_TTABLE:
      {
        unsigned key_cnt = table_key_count(L);

        lua_len(L,-1);
        unsigned seq_len = lua_tounsigned(L,-1);
        lua_pop(L,1);

        // - if table is sequence -
        if (key_cnt == seq_len)
        {
          pointer_array_s *array_ptr = it.get_new_array_ptr();
          BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

          lua_pushnil(L);
          while (lua_next(L,-2))
          {
            location_s *item_location = lua_object_value(it,L,source_pos);

            // - ERROR -
            if (item_location == NULL)
            {
              it.release_location_ptr(arr_location);

              lua_pop(L,2);
              return NULL;
            }

            // - insert item to array -
            array_ptr->push(item_location);
          }

          lua_pop(L,1);
          return arr_location;
        }
        else
        {
          pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
          tree_ptr->init();
          tree_ptr->it_ptr = &it;
          tree_ptr->source_pos = source_pos;

          BIC_CREATE_NEW_LOCATION(dict_location,c_rm_class_dict,tree_ptr);

          lua_pushnil(L);
          while (lua_next(L,-2))
          {
            location_s *value_location = lua_object_value(it,L,source_pos);

            // - ERROR -
            if (value_location == NULL)
            {
              it.release_location_ptr(dict_location);

              lua_pop(L,2);
              return NULL;
            }

            lua_pushvalue(L,-1);
            location_s *key_location = lua_object_value(it,L,source_pos);

            // - ERROR -
            if (value_location == NULL)
            {
              it.release_location_ptr(value_location);
              it.release_location_ptr(dict_location);

              lua_pop(L,2);
              return NULL;
            }

            pointer_map_s map = {key_location,value_location};
            unsigned index = tree_ptr->get_idx(map);

            if (((location_s *)it.exception_location)->v_type != c_bi_class_blank ||
                index != c_idx_not_exist)
            {
              it.release_location_ptr(key_location);
              it.release_location_ptr(value_location);
              it.release_location_ptr(dict_location);

              lua_pop(L,2);
              return NULL;
            }

            // - insert map to dictionary -
            tree_ptr->insert(map);

            if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
            {
              it.release_location_ptr(key_location);
              it.release_location_ptr(value_location);
              it.release_location_ptr(dict_location);

              lua_pop(L,2);
              return NULL;
            }
          }

          lua_pop(L,1);
          return dict_location;
        }
      }
    case LUA_TFUNCTION:
    case LUA_TUSERDATA:
    case LUA_TTHREAD:
    case LUA_TLIGHTUSERDATA:
      {
        lua_pop(L,1);
        return NULL;
      }
  }

  lua_pop(L,1);
  return NULL;
}/*}}}*/

