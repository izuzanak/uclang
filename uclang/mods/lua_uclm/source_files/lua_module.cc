
@begin
include "lua_module.h"
@end

// - LUA indexes of built in classes -
unsigned c_bi_class_lua_state = c_idx_not_exist;
unsigned c_bi_class_lua_value = c_idx_not_exist;

// - LUA indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - LUA module -
built_in_module_s module =
{/*{{{*/
  2,                   // Class count
  lua_classes,         // Classes

  0,                   // Error base index
  2,                   // Error count
  lua_error_strings,   // Error strings

  lua_initialize,      // Initialize function
  lua_print_exception, // Print exceptions function
};/*}}}*/

// - LUA classes -
built_in_class_s *lua_classes[] =
{/*{{{*/
  &lua_state_class,
  &lua_value_class,
};/*}}}*/

// - LUA error strings -
const char *lua_error_strings[] =
{/*{{{*/
  "error_LUA_STATE_CREATE_NEW_STATE_ERROR",
  "error_LUA_STATE_DO_STRING_ERROR",
};/*}}}*/

// - LUA initialize -
bool lua_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize lua_state class identifier -
  c_bi_class_lua_state = class_base_idx++;

  // - initialize lua_value class identifier -
  c_bi_class_lua_value = class_base_idx++;

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
    fprintf(stderr,"\nError while creating new LUA state\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LUA_STATE_DO_STRING_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLUA error: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
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
  7, lua_state_methods,
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
  3, lua_value_methods,
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
  NULL,
  NULL
};/*}}}*/

built_in_method_s lua_value_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_lua_value_operator_binary_equal
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
  location_ptr->v_data_ptr = c_idx_not_exist;
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

bool bic_lua_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  lua_value_s *lv_ptr = (lua_value_s *)dst_location->v_data_ptr;
  lua_State *L = (lua_State *)lv_ptr->lua_state_loc->v_data_ptr;

  lua_rawgeti(L,LUA_REGISTRYINDEX,lv_ptr->ref);

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

  lua_value_s *lv_ptr = (lua_value_s *)dst_location->v_data_ptr;
  lua_State *L = (lua_State *)lv_ptr->lua_state_loc->v_data_ptr;

  lua_rawgeti(L,LUA_REGISTRYINDEX,lv_ptr->ref);
  printf(luaL_tolstring(L,-1,NULL));
  lua_pop(L,2);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

