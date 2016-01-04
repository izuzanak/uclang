
@begin
include "lua_module.h"
@end

// - LUA indexes of built in classes -
unsigned c_bi_class_lua_state = c_idx_not_exist;
unsigned c_bi_class_lua_value = c_idx_not_exist;
unsigned c_bi_class_lua_reference = c_idx_not_exist;

// - LUA indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - LUA module -
built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  lua_classes,         // Classes

  0,                   // Error base index
  11,                  // Error count
  lua_error_strings,   // Error strings

  lua_initialize,      // Initialize function
  lua_print_exception, // Print exceptions function
};/*}}}*/

// - LUA classes -
built_in_class_s *lua_classes[] =
{/*{{{*/
  &lua_state_class,
  &lua_value_class,
  &lua_reference_class,
};/*}}}*/

// - LUA error strings -
const char *lua_error_strings[] =
{/*{{{*/
  "error_LUA_STATE_CREATE_NEW_STATE_ERROR",
  "error_LUA_STATE_DO_STRING_ERROR",
  "error_LUA_VALUE_WRONG_VALUE_REFERENCE",
  "error_LUA_VALUE_INVOKE_FUNCTION_ERROR",
  "error_LUA_VALUE_INVOKE_FUNCTION_WRONG_PARAMETER",
  "error_LUA_VALUE_INVOKE_FUNCTION_RUN_ERROR",
  "error_LUA_VALUE_MEMBER_SELECT_ERROR",
  "error_LUA_VALUE_CREATE_ERROR",
  "error_LUA_VALUE_VALUE_ERROR",
  "error_LUA_VALUE_VALUE_IS_NOT_TABLE_ERROR",
  "error_LUA_REFERENCE_SET_PROP_ERROR",
};/*}}}*/

// - LUA initialize -
bool lua_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize lua_state class identifier -
  c_bi_class_lua_state = class_base_idx++;

  // - initialize lua_value class identifier -
  c_bi_class_lua_value = class_base_idx++;

  // - initialize lua_reference class identifier -
  c_bi_class_lua_reference = class_base_idx++;

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - LUA print exception -
bool lua_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_LUA_STATE_CREATE_NEW_STATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating new Lua state\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_STATE_DO_STRING_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLua error: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_WRONG_VALUE_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to Lua value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_INVOKE_FUNCTION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while invoking Lua function\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_INVOKE_FUNCTION_WRONG_PARAMETER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot process parameter %" HOST_LL_FORMAT "d of Lua function\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_INVOKE_FUNCTION_RUN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLua error: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_MEMBER_SELECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while selecting member of Lua value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating Lua value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving value of Lua value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_VALUE_VALUE_IS_NOT_TABLE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nValue of Lua variable is not of type table\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_REFERENCE_SET_PROP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set property of Lua value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class LUA_STATE -
built_in_class_s lua_state_class =
{/*{{{*/
  "LuaState",
  c_modifier_public | c_modifier_final,
  9, lua_state_methods,
  0, lua_state_variables,
  bic_lua_state_consts,
  bic_lua_state_init,
  bic_lua_state_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s lua_state_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_lua_state_operator_binary_equal
  },
  {
    "LuaState#0",
    c_modifier_public | c_modifier_final,
    bic_lua_state_method_LuaState_0
  },
  {
    "do_string#1",
    c_modifier_public | c_modifier_final,
    bic_lua_state_method_do_string_1
  },
  {
    "new_value#1",
    c_modifier_public | c_modifier_final,
    bic_lua_state_method_new_value_1
  },
  {
    "get_global#0",
    c_modifier_public | c_modifier_final,
    bic_lua_state_method_get_global_0
  },
  {
    "get_global#1",
    c_modifier_public | c_modifier_final,
    bic_lua_state_method_get_global_1
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lua_state_method_version_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lua_state_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lua_state_method_print_0
  },
};/*}}}*/

built_in_variable_s lua_state_variables[] =
{/*{{{*/
};/*}}}*/

void bic_lua_state_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_lua_state_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_lua_state_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  lua_State *L = (lua_State *)location_ptr->v_data_ptr;

  // - if jit context object exists -
  if (L != NULL)
  {
    // - test size of stack -
    cassert(lua_gettop(L) == 0);

    // - close lua state -
    lua_close(L);
  }
}/*}}}*/

bool bic_lua_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_lua_state_method_LuaState_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create new lua state -
  lua_State *L = luaL_newstate();

  // - ERROR -
  if (L == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_STATE_CREATE_NEW_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - open lua libraries -
  luaL_openlibs(L);

  dst_location->v_data_ptr = (basic_64b)L;

  return true;
}/*}}}*/

bool bic_lua_state_method_do_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("do_string#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  lua_State *L = (lua_State *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (luaL_dostring(L,string_ptr->data))
  {
    // - retrieve lua error string -
    size_t length;
    const char *data = lua_tolstring(L,-1,&length);

    string_s *error_ptr = it.get_new_string_ptr();
    error_ptr->set(length,data);

    lua_pop(L,1);

    BIC_CREATE_NEW_LOCATION_REFS(err_location,c_bi_class_string,error_ptr,0);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_STATE_DO_STRING_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_lua_state_method_new_value_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  lua_State *L = (lua_State *)dst_location->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,src_0_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create lua value object -
  lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
  lv_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  lv_ptr->lua_state_loc = dst_location;
  lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

  BIC_SIMPLE_SET_RES(c_bi_class_lua_value,lv_ptr);

  return true;
}/*}}}*/

bool bic_lua_state_method_get_global_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  lua_State *L = (lua_State *)dst_location->v_data_ptr;

  // - create lua value object -
  lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
  lv_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  lv_ptr->lua_state_loc = dst_location;

  lua_getglobal(L,"_G");
  lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

  BIC_SIMPLE_SET_RES(c_bi_class_lua_value,lv_ptr);

  return true;
}/*}}}*/

bool bic_lua_state_method_get_global_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_global#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  lua_State *L = (lua_State *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create lua value object -
  lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
  lv_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  lv_ptr->lua_state_loc = dst_location;

  lua_getglobal(L,string_ptr->data);
  lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

  BIC_SIMPLE_SET_RES(c_bi_class_lua_value,lv_ptr);

  return true;
}/*}}}*/

bool bic_lua_state_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  double result = *lua_version(NULL);

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_lua_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("LuaState"),"LuaState");
  );

  return true;
}/*}}}*/

bool bic_lua_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("LuaState");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class LUA_VALUE -
built_in_class_s lua_value_class =
{/*{{{*/
  "LuaValue",
  c_modifier_public | c_modifier_final,
  7, lua_value_methods,
  0, lua_value_variables,
  bic_lua_value_consts,
  bic_lua_value_init,
  bic_lua_value_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_lua_value_invoke,
  bic_lua_value_member
};/*}}}*/

built_in_method_s lua_value_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_lua_value_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_lua_value_operator_binary_le_br_re_br
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_value_0
  },
  {
    "keys#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_keys_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_items_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_print_0
  },
};/*}}}*/

built_in_variable_s lua_value_variables[] =
{/*{{{*/
};/*}}}*/

void bic_lua_value_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_lua_value_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_lua_value_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  lua_value_s *lv_ptr = (lua_value_s *)location_ptr->v_data_ptr;

  if (lv_ptr != NULL)
  {
    lv_ptr->clear(it);
    cfree(lv_ptr);
  }
}/*}}}*/

bool bic_lua_value_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (lua_type(L,-1) != LUA_TTABLE)
  {
    lua_pop(L,1);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_INVOKE_FUNCTION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - method name reference -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->method_symbol_names[code[icl_name_idx]];

  // - parameter count and method name length -
  unsigned param_cnt = (unsigned)code[icl_parm_cnt] - 1;
  unsigned name_length = name_ref.size - (3 + (unsigned)(logf(param_cnt)/logf(10)));

  char name[c_max_method_name_length];
  memcpy(name,name_ref.data,name_length);
  name[name_length] = '\0';

  // - retrieve function -
  lua_pushlstring(L,name,name_length);
  lua_rawget(L,-2);
  lua_replace(L,-2);

  // - ERROR -
  if (lua_type(L,-1) != LUA_TFUNCTION)
  {
    lua_pop(L,1);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_INVOKE_FUNCTION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - prepare parameters -
  if (param_cnt > 0)
  {
    // - check lua stack -
    lua_checkstack(L,param_cnt);

    unsigned param_idx = 0;
    do {
      location_s *param_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx + param_idx]);

      // - ERROR -
      if (!lua_s::create_lua_object(it,L,param_location))
      {
        lua_pop(L,1 + param_idx);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_INVOKE_FUNCTION_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }

    } while(++param_idx < param_cnt);
  }

  // - call table method -
  if (lua_pcall(L,param_cnt,LUA_MULTRET,0))
  {
    // - retrieve lua error string -
    size_t length;
    const char *data = lua_tolstring(L,-1,&length);

    string_s *error_ptr = it.get_new_string_ptr();
    error_ptr->set(length,data);

    lua_pop(L,1);

    BIC_CREATE_NEW_LOCATION_REFS(err_location,c_bi_class_string,error_ptr,0);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_INVOKE_FUNCTION_RUN_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  // - process return value/s -
  int top = lua_gettop(L);
  switch (top)
  {
    case 0:
      {
        pointer &res_location = it.data_stack[res_loc_idx];
        BIC_SET_RESULT_BLANK();
      }
      break;
    case 1:
      {
        // - create lua value object -
        lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
        lv_ptr->init();

        lua_state_loc->v_reference_cnt.atomic_inc();
        lv_ptr->lua_state_loc = lua_state_loc;
        lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_lua_value,lv_ptr);

        pointer &res_location = it.data_stack[res_loc_idx];
        BIC_SET_RESULT(new_location);
      }
      break;
    default:
      {
        pointer_array_s *array_ptr = it.get_new_array_ptr();
        array_ptr->copy_resize(top);
        array_ptr->used = top;

        int res_idx = top - 1;
        do {

          // - create lua value object -
          lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
          lv_ptr->init();

          lua_state_loc->v_reference_cnt.atomic_inc();
          lv_ptr->lua_state_loc = lua_state_loc;
          lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_lua_value,lv_ptr);
          array_ptr->data[res_idx] = new_location;

        } while(--res_idx >= 0);

        BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

        pointer &res_location = it.data_stack[res_loc_idx];
        BIC_SET_RESULT(arr_location);
      }
      break;
  }

  return true;
}/*}}}*/

bool bic_lua_value_member(interpreter_thread_s &it,uli *code,unsigned stack_base)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + code[ioms_stack_object]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (lua_type(L,-1) != LUA_TTABLE)
  {
    lua_pop(L,1);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_MEMBER_SELECT_ERROR,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve member name -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->variable_symbol_names[code[ioms_var_name]];
  lua_pushlstring(L,name_ref.data,name_ref.size - 1);

  // - create reference object -
  lua_reference_s *lr_ptr = (lua_reference_s *)cmalloc(sizeof(lua_reference_s));
  lr_ptr->init();

  lua_state_loc->v_reference_cnt.atomic_inc();
  lr_ptr->lua_state_loc = lua_state_loc;

  lr_ptr->key_ref = luaL_ref(L,LUA_REGISTRYINDEX);
  lr_ptr->obj_ref = luaL_ref(L,LUA_REGISTRYINDEX);

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_lua_reference,lr_ptr);

  pointer &trg_location = it.data_stack[stack_base + code[ioms_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  return true;
}/*}}}*/

bool bic_lua_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_lua_value_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,src_0_location))
  {
    lua_pop(L,1);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_MEMBER_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (lua_type(L,-2) != LUA_TTABLE)
  {
    lua_pop(L,2);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_MEMBER_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  lua_reference_s *lr_ptr = (lua_reference_s *)cmalloc(sizeof(lua_reference_s));
  lr_ptr->init();

  lua_state_loc->v_reference_cnt.atomic_inc();
  lr_ptr->lua_state_loc = lua_state_loc;

  lr_ptr->key_ref = luaL_ref(L,LUA_REGISTRYINDEX);
  lr_ptr->obj_ref = luaL_ref(L,LUA_REGISTRYINDEX);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_lua_reference,lr_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_lua_value_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *location_ptr = lua_s::lua_object_value(it,L,operands[c_source_pos_idx]);

  // - ERROR -
  if (location_ptr == NULL)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_lua_value_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (lua_type(L,-1) != LUA_TTABLE)
  {
    lua_pop(L,1);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_VALUE_IS_NOT_TABLE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  lua_createtable(L,0,0);
  lua_pushnil(L);

  int idx = 0;
  while (lua_next(L,-3))
  {
    lua_pop(L,1);
    lua_pushvalue(L,-1);
    lua_rawseti(L,-3,++idx);
  }

  // - create lua value object -
  lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
  lv_ptr->init();

  lua_state_loc->v_reference_cnt.atomic_inc();
  lv_ptr->lua_state_loc = lua_state_loc;
  lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

  lua_pop(L,1);

  BIC_SIMPLE_SET_RES(c_bi_class_lua_value,lv_ptr);

  return true;
}/*}}}*/

bool bic_lua_value_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (lua_type(L,-1) != LUA_TTABLE)
  {
    lua_pop(L,1);

    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_VALUE_IS_NOT_TABLE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  lua_createtable(L,0,0);
  lua_pushnil(L);

  int idx = 0;
  while (lua_next(L,-3))
  {
    lua_rawseti(L,-3,++idx);
  }

  // - create lua value object -
  lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
  lv_ptr->init();

  lua_state_loc->v_reference_cnt.atomic_inc();
  lv_ptr->lua_state_loc = lua_state_loc;
  lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

  lua_pop(L,1);

  BIC_SIMPLE_SET_RES(c_bi_class_lua_value,lv_ptr);

  return true;
}/*}}}*/

bool bic_lua_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  size_t length;
  const char *data = luaL_tolstring(L,-1,&length);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,data);

  lua_pop(L,2);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_lua_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *lua_state_loc = *((location_s **)dst_location->v_data_ptr);
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,dst_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  printf("%s",luaL_tolstring(L,-1,NULL));
  lua_pop(L,2);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class LUA_REFERENCE -
built_in_class_s lua_reference_class =
{/*{{{*/
  "LuaReference",
  c_modifier_public | c_modifier_final,
  7, lua_reference_methods,
  0, lua_reference_variables,
  bic_lua_reference_consts,
  bic_lua_reference_init,
  bic_lua_reference_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_lua_value_invoke,
  bic_lua_value_member
};/*}}}*/

built_in_method_s lua_reference_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_lua_reference_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_lua_value_operator_binary_le_br_re_br
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_value_0
  },
  {
    "keys#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_keys_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_items_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_lua_value_method_print_0
  },
};/*}}}*/

built_in_variable_s lua_reference_variables[] =
{/*{{{*/
};/*}}}*/

void bic_lua_reference_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_lua_reference_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_lua_reference_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  lua_reference_s *lr_ptr = (lua_reference_s *)location_ptr->v_data_ptr;

  if (lr_ptr != NULL)
  {
    lr_ptr->clear(it);
    cfree(lr_ptr);
  }
}/*}}}*/

bool bic_lua_reference_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  lua_reference_s *lr_ptr = (lua_reference_s *)dst_location->v_data_ptr;
  location_s *lua_state_loc = lr_ptr->lua_state_loc;
  lua_State *L = (lua_State *)lua_state_loc->v_data_ptr;

  // - ERROR -
  if (!lua_s::create_lua_object(it,L,src_0_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_REFERENCE_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  lua_pushvalue(L,-1);
  lr_ptr->set();

  // - create lua value object -
  lua_value_s *lv_ptr = (lua_value_s *)cmalloc(sizeof(lua_value_s));
  lv_ptr->init();

  lua_state_loc->v_reference_cnt.atomic_inc();
  lv_ptr->lua_state_loc = lua_state_loc;
  lv_ptr->ref = luaL_ref(L,LUA_REGISTRYINDEX);

  BIC_SIMPLE_SET_RES(c_bi_class_lua_value,lv_ptr);

  return true;
}/*}}}*/

