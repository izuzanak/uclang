
@begin
include "lua_module.h"
@end

// - LUA indexes of built in classes -
unsigned c_bi_class_lua_state = c_idx_not_exist;

// - LUA indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - LUA module -
built_in_module_s module =
{/*{{{*/
  1,                   // Class count
  lua_classes,         // Classes

  0,                   // Error base index
  1,                   // Error count
  lua_error_strings,   // Error strings

  lua_initialize,      // Initialize function
  lua_print_exception, // Print exceptions function
};/*}}}*/

// - LUA classes -
built_in_class_s *lua_classes[] =
{/*{{{*/
  &lua_state_class,
};/*}}}*/

// - LUA error strings -
const char *lua_error_strings[] =
{/*{{{*/
  "error_LUA_STATE_CREATE_NEW_STATE_ERROR",
};/*}}}*/

// - LUA initialize -
bool lua_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize lua_state class identifier -
  c_bi_class_lua_state = class_base_idx++;

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
  4, lua_state_methods,
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
  lua_State *lua_state = (lua_State *)location_ptr->v_data_ptr;

  // - if jit context object exists -
  if (lua_state != NULL)
  {
    // - close lua state -
    lua_close(lua_state);
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
  lua_State *lua_state = luaL_newstate();

  // - ERROR -
  if (lua_state == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LUA_STATE_CREATE_NEW_STATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (basic_64b)lua_state;

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

