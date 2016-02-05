
@begin
include "ucl_jit.h"
@end

/*
 * constants and definitions
 */

const unsigned max_number_string_length = 12;

// - callers of parse action functions -
const unsigned c_jit_parse_action_cnt = 124;
bool(*jit_pa_callers[c_jit_parse_action_cnt])(jit_parser_s &_this) =
{/*{{{*/
  jit_pa_null,
  jit_pa_null,
  jit_pa_null,
  jit_pa_null,
  jit_pa_function,
  jit_pa_function_name,
  jit_pa_null,
  jit_pa_null,
  jit_pa_null,
  jit_pa_null,
  jit_pa_fun_parameter,
  jit_pa_null,
  jit_pa_type,
  jit_pa_pointer,
  jit_pa_null,
  jit_pa_null,
  jit_pa_declaration_end,
  jit_pa_null,
  jit_pa_null,
  jit_pa_modifier_volatile,
  jit_pa_type,
  jit_pa_null,
  jit_pa_null,
  jit_pa_null,
  jit_pa_null,
  jit_pa_declare,
  jit_pa_declare_expression,
  jit_pa_declare_array,
  jit_pa_variable,
  jit_pa_null,
  jit_pa_null,
  jit_pa_command_block_done,
  jit_pa_command_block_begin,
  jit_pa_null,
  jit_pa_if_condition,
  jit_pa_if_statement,
  jit_pa_if_else_statement,
  jit_pa_if_else,
  jit_pa_while_statement,
  jit_pa_while_begin,
  jit_pa_while_condition,
  jit_pa_do_while_statement,
  jit_pa_do_while_begin,
  jit_pa_do_while_pre_condition,
  jit_pa_break,
  jit_pa_continue,
  jit_pa_return,
  jit_pa_null,
  jit_pa_label,
  jit_pa_goto,
  jit_pa_null,
  jit_pa_expression,
  jit_pa_null,
  jit_pa_operator_binary_equal,
  jit_pa_operator_binary_plus_equal,
  jit_pa_operator_binary_minus_equal,
  jit_pa_operator_binary_asterisk_equal,
  jit_pa_operator_binary_slash_equal,
  jit_pa_operator_binary_percent_equal,
  jit_pa_operator_binary_double_ls_br_equal,
  jit_pa_operator_binary_double_rs_br_equal,
  jit_pa_operator_binary_ampersand_equal,
  jit_pa_operator_binary_pipe_equal,
  jit_pa_operator_binary_circumflex_equal,
  jit_pa_null,
  jit_pa_operator_binary_double_ampersand,
  jit_pa_operator_binary_double_pipe,
  jit_pa_null,
  jit_pa_operator_binary_double_equal,
  jit_pa_operator_binary_exclamation_equal,
  jit_pa_operator_binary_rs_br,
  jit_pa_operator_binary_ls_br,
  jit_pa_operator_binary_rs_br_equal,
  jit_pa_operator_binary_ls_br_equal,
  jit_pa_null,
  jit_pa_operator_binary_ampersand,
  jit_pa_operator_binary_pipe,
  jit_pa_operator_binary_circumflex,
  jit_pa_null,
  jit_pa_operator_binary_double_rs_br,
  jit_pa_operator_binary_double_ls_br,
  jit_pa_null,
  jit_pa_operator_binary_plus,
  jit_pa_operator_binary_minus,
  jit_pa_null,
  jit_pa_operator_binary_asterisk,
  jit_pa_operator_binary_slash,
  jit_pa_operator_binary_percent,
  jit_pa_null,
  jit_pa_operator_unary_post_double_plus,
  jit_pa_operator_unary_post_double_minus,
  jit_pa_operator_unary_pre_double_plus,
  jit_pa_operator_unary_pre_double_minus,
  jit_pa_operator_unary_pre_plus,
  jit_pa_operator_unary_pre_minus,
  jit_pa_operator_unary_pre_exclamation,
  jit_pa_operator_unary_pre_tilde,
  jit_pa_operator_unary_pre_asterisk,
  jit_pa_operator_unary_pre_ampersand,
  jit_pa_operator_binary_le_br_re_br,
  jit_pa_cast,
  jit_pa_null,
  jit_pa_identifier,
  jit_pa_conditional_expression,
  jit_pa_conditional_condition,
  jit_pa_conditional_true,
  jit_pa_function_call,
  jit_pa_null,
  jit_pa_null,
  jit_pa_parameters_begin,
  jit_pa_parameter,
  jit_pa_parameter,
  jit_pa_const_char,
  jit_pa_const_octal_char,
  jit_pa_const_hex_char,
  jit_pa_const_backslash_char,
  jit_pa_const_oct_i32,
  jit_pa_const_dec_i32,
  jit_pa_const_hex_i32,
  jit_pa_const_oct_i64,
  jit_pa_const_dec_i64,
  jit_pa_const_hex_i64,
  jit_pa_const_f32,
  jit_pa_const_f64,
};/*}}}*/

/*
 * parse action macros
 */

/*
 * functions implementing parse actions of parser
 */

bool jit_pa_null(jit_parser_s &_this)
{/*{{{*/
  cassert(0);

  return true;
}/*}}}*/

bool jit_pa_function(jit_parser_s &_this)
{/*{{{*/
  jit_context_s *ucl_context = (jit_context_s *)_this.ucl_context;
  pointer &jit_function = _this.jit_function;
  string_s &ucl_signature = _this.ucl_signature;
  var_records_s &var_records = _this.var_records;
  fun_record_s &fun_record = _this.fun_record;
  ui_array_s &fun_param_idxs = _this.fun_param_idxs;

  // *****

  // - function parameters ucl types -
  var_type_s *ucl_param_types[fun_record.param_types.used];

  // - fill array of function parameter types -
  if (fun_record.param_types.used != 0)
  {
    var_type_s *vt_ptr = fun_record.param_types.data;
    var_type_s *vt_ptr_end = vt_ptr + fun_record.param_types.used;
    var_type_s **pt_ptr = ucl_param_types;
    do {
      *pt_ptr = vt_ptr;
    } while(++pt_ptr,++vt_ptr < vt_ptr_end);
  }

  // - generate function ucl signature -
  jit_parser_s::create_signature(fun_record.name.size - 1,fun_record.name.data,fun_record.param_types.used,ucl_param_types,ucl_signature);

  // - ERROR -
  if (ucl_context->ucl_signatures.get_idx(ucl_signature) != c_idx_not_exist)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_FUNCTION_DEFINITION,0,(location_s *)it.blank_location);
    new_exception->params.push(_this.fun_name_pos.ui_first);

    return false;
  }

  jit_type_t ret_type = fun_record.ret_type.jit_type();

  // - function parameters jit types -
  jit_type_t jit_param_types[fun_record.param_types.used];

  // - fill array of function parameter types -
  if (fun_record.param_types.used != 0)
  {
    var_type_s *vt_ptr = fun_record.param_types.data;
    var_type_s *vt_ptr_end = vt_ptr + fun_record.param_types.used;
    jit_type_t *pt_ptr = jit_param_types;
    do {
      *pt_ptr = vt_ptr->jit_type();
    } while(++pt_ptr,++vt_ptr < vt_ptr_end);
  }

  // - create jit signature -
  jit_type_t jit_signature = jit_type_create_signature(jit_abi_cdecl,ret_type,jit_param_types,fun_record.param_types.used,1);

  // - create jit function -
  jit_function = (pointer)jit_function_create(ucl_context->context,jit_signature);
  jit_type_free(jit_signature);

  // - store function jit pointer -
  fun_record.jit_function = jit_function;

  // - set function optimization level -
  unsigned max_opt_level = jit_function_get_max_optimization_level();
  jit_function_set_optimization_level((jit_function_t)jit_function,max_opt_level);

  // - read values of function parameters -
  if (fun_param_idxs.used != 0)
  {
    unsigned *pi_ptr = fun_param_idxs.data;
    unsigned *pi_ptr_end = pi_ptr + fun_param_idxs.used;
    unsigned param_idx = 0;
    do {
      var_record_s &var_record = var_records[*pi_ptr];

      // - retrieve parameter value -
      var_record.value = (pointer)jit_value_get_param((jit_function_t)jit_function,param_idx);
    } while(++param_idx,++pi_ptr < pi_ptr_end);
  }

  return true;
}/*}}}*/

bool jit_pa_function_name(jit_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  fun_record_s &fun_record = _this.fun_record;
  var_types_s &tmp_var_types = _this.tmp_var_types;
  name_pos_s &fun_name_pos = _this.fun_name_pos;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - store function name -
  fun_record.name.set(name_length,name_data);

  // - store function name position -
  fun_name_pos.ui_first = lse.terminal_start;
  fun_name_pos.ui_second = lse.terminal_end;

  // - store function return value -
  fun_record.ret_type = tmp_var_types.pop();

  return true;
}/*}}}*/

bool jit_pa_fun_parameter(jit_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &var_names = _this.var_names;
  var_records_s &var_records = _this.var_records;
  fun_record_s &fun_record = _this.fun_record;
  var_types_s &tmp_var_types = _this.tmp_var_types;
  ui_array_s &fun_param_idxs = _this.fun_param_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - create variable name -
  unsigned var_idx = var_names.get_idx_char_ptr_insert(name_length,name_data);

  // - ERROR -
  if (var_idx < var_records.used)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_PARAMETER_IDENTIFIER,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - create variable record -
  do {
    var_records.push_blank();
  } while(var_records.used <= var_idx);

  // - retrieve parameter type -
  var_type_s &var_type = tmp_var_types.pop();

  // - fill variable record -
  var_records.last().set(var_type,NULL);

  // - store parameter record index -
  fun_param_idxs.push(var_records.used - 1);

  // - store function parameter type -
  fun_record.param_types.push(var_type);

  return true;
}/*}}}*/

bool jit_pa_type(jit_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  unsigned &tmp_modifiers = _this.tmp_modifiers;
  var_types_s &tmp_var_types = _this.tmp_var_types;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned type_length = lse.terminal_end - lse.terminal_start;
  char *type_data = source_string.data + lse.terminal_start;

  // - recognize type identifier -
  unsigned type_id = jit_parser_s::recognize_type(type_length,type_data);

  // - ERROR -
  if (type_id == c_idx_not_exist)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_UNKNOWN_DATA_TYPE,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  tmp_var_types.push_blank();
  tmp_var_types.last().set(type_id,0,tmp_modifiers);

  return true;
}/*}}}*/

bool jit_pa_pointer(jit_parser_s &_this)
{/*{{{*/
  var_types_s &tmp_var_types = _this.tmp_var_types;

  // *****

  tmp_var_types.last().pointer_level++;

  return true;
}/*}}}*/

bool jit_pa_declaration_end(jit_parser_s &_this)
{/*{{{*/
  unsigned &tmp_modifiers = _this.tmp_modifiers;
  var_types_s &tmp_var_types = _this.tmp_var_types;

  // *****

  tmp_modifiers = 0;
  tmp_var_types.pop();

  return true;
}/*}}}*/

bool jit_pa_modifier_volatile(jit_parser_s &_this)
{/*{{{*/
  unsigned &tmp_modifiers = _this.tmp_modifiers;

  // *****

  tmp_modifiers |= c_var_modifier_volatile;

  return true;
}/*}}}*/

bool jit_pa_declare(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  var_records_s &var_records = _this.var_records;

  // *****

  var_record_s &var_record = var_records.last();

  // - create variable value -
  jit_value_t tmp_value = jit_value_create(jit_function,var_record.type.jit_type());

  // - process volatile modifier -
  if (var_record.type.modifiers & c_var_modifier_volatile)
  {
    jit_value_set_volatile(tmp_value);
  }

  var_record.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_declare_expression(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  var_records_s &var_records = _this.var_records;

  // *****

  var_record_s &var_record = var_records.last();
  exp_node_s &exp_node = exp_node_stack.pop();

  // - ERROR -
  if (!var_record.type.are_assignable(exp_node.type))
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - create variable value -
  jit_value_t tmp_value = jit_value_create(jit_function,var_record.type.jit_type());

  // - process volatile modifier -
  if (var_record.type.modifiers & c_var_modifier_volatile)
  {
    jit_value_set_volatile(tmp_value);
  }

  var_record.value = tmp_value;

  jit_value_t value = exp_node.load_value(jit_function);
  jit_insn_store(jit_function,tmp_value,value);

  return true;
}/*}}}*/

bool jit_pa_declare_array(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  var_records_s &var_records = _this.var_records;

  // *****

  var_record_s &var_record = var_records.last();
  exp_node_s &exp_node = exp_node_stack.pop();

  // - ERROR -
  if (exp_node.is_pointer() || !exp_node.is_integer())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 3];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t sizeof_value = jit_value_create_nint_constant(jit_function,jit_type_int,jit_type_get_size(var_record.type.jit_type()));
  jit_value_t size_value = jit_insn_mul(jit_function,value,sizeof_value);

  jit_value_t tmp_value = jit_insn_alloca(jit_function,size_value);

  // - process volatile modifier -
  if (var_record.type.modifiers & c_var_modifier_volatile)
  {
    jit_value_set_volatile(tmp_value);
  }

  var_record.type.pointer_level++;
  var_record.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_variable(jit_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &var_names = _this.var_names;
  var_records_s &var_records = _this.var_records;
  var_types_s &tmp_var_types = _this.tmp_var_types;
  ui_array_s &variable_idxs = _this.variable_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - create variable name -
  unsigned var_idx = var_names.get_idx_char_ptr_insert(name_length,name_data);

  // - ERROR -
  if (var_idx < var_records.used)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_VAR_PARAM_IDENTIFIER,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - create variable record -
  do {
    var_records.push_blank();
  } while(var_records.used <= var_idx);

  // - retrieve variable type -
  var_type_s &var_type = tmp_var_types.last();

  // - fill variable record -
  var_records.last().set(var_type,NULL);

  // - reset tmp variable type pointer level -
  var_type.pointer_level = 0;

  // - store variable index -
  variable_idxs.push(var_idx);

  return true;
}/*}}}*/

bool jit_pa_command_block_done(jit_parser_s &_this)
{/*{{{*/
  string_rb_tree_s &var_names = _this.var_names;
  ui_array_s &variable_idxs = _this.variable_idxs;
  ui_array_s &block_var_bases = _this.block_var_bases;

  // *****

  unsigned block_base = block_var_bases.pop();
  while (variable_idxs.used > block_base)
  {
    var_names.remove(variable_idxs.pop());
  }

  return true;
}/*}}}*/

bool jit_pa_command_block_begin(jit_parser_s &_this)
{/*{{{*/
  ui_array_s &variable_idxs = _this.variable_idxs;
  ui_array_s &block_var_bases = _this.block_var_bases;

  // *****

  block_var_bases.push(variable_idxs.used);

  return true;
}/*}}}*/

bool jit_pa_if_condition(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  exp_node_s &exp_node = exp_node_stack.pop();
  jit_value_t value = exp_node.load_value(jit_function);

  // - create new label -
  labels.push(jit_label_undefined);
  label_idxs.push(labels.used - 1);
  jit_label_t *label = &labels.last();

  jit_insn_branch_if_not(jit_function,value,label);

  return true;
}/*}}}*/

bool jit_pa_if_statement(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  jit_label_t *label = labels.data + label_idxs.pop();

  // - update label value -
  jit_insn_label(jit_function,label);

  return true;
}/*}}}*/

bool jit_pa_if_else_statement(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  jit_label_t *label = labels.data + label_idxs.pop();

  // - update label value -
  jit_insn_label(jit_function,label);

  return true;
}/*}}}*/

bool jit_pa_if_else(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  unsigned label_0_idx = label_idxs.pop();

  // - create new label -
  labels.push(jit_label_undefined);
  label_idxs.push(labels.used - 1);

  jit_label_t *label_1 = &labels.last();
  jit_insn_branch(jit_function,label_1);

  // - update label value -
  jit_label_t *label_0 = &labels[label_0_idx];
  jit_insn_label(jit_function,label_0);

  return true;
}/*}}}*/

bool jit_pa_while_statement(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  jit_label_t *label_1 = labels.data + label_idxs.pop();
  jit_label_t *label_0 = labels.data + label_idxs.pop();

  // - jump to loop begin -
  jit_insn_branch(jit_function,label_0);

  // - update label value -
  jit_insn_label(jit_function,label_1);

  // - remove continue break labels -
  cb_label_idxs.used -= 2;

  return true;
}/*}}}*/

bool jit_pa_while_begin(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  // - create new label -
  labels.push(jit_label_undefined);
  unsigned label_idx_0 = labels.used - 1;
  label_idxs.push(label_idx_0);
  cb_label_idxs.push(label_idx_0);

  // - update label value -
  jit_label_t *label_0 = &labels.last();
  jit_insn_label(jit_function,label_0);

  // - create new label -
  labels.push(jit_label_undefined);
  unsigned label_idx_1 = labels.used - 1;
  label_idxs.push(label_idx_1);
  cb_label_idxs.push(label_idx_1);

  return true;
}/*}}}*/

bool jit_pa_while_condition(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  exp_node_s &exp_node = exp_node_stack.pop();
  jit_value_t value = exp_node.load_value(jit_function);

  // - continue loop if true -
  jit_label_t *label = labels.data + label_idxs.last();
  jit_insn_branch_if_not(jit_function,value,label);

  return true;
}/*}}}*/

bool jit_pa_do_while_statement(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  exp_node_s &exp_node = exp_node_stack.pop();
  jit_value_t value = exp_node.load_value(jit_function);

  // - update label value -
  jit_label_t *label = labels.data + label_idxs.pop();
  jit_insn_branch_if(jit_function,value,label);

  // - update break label value -
  jit_label_t *break_label = labels.data + cb_label_idxs.last();
  jit_insn_label(jit_function,break_label);

  // - remove continue break labels -
  cb_label_idxs.used -= 2;

  return true;
}/*}}}*/

bool jit_pa_do_while_begin(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  // - create new label -
  labels.push(jit_label_undefined);
  label_idxs.push(labels.used - 1);

  // - update label value -
  jit_label_t *label_0 = &labels.last();
  jit_insn_label(jit_function,label_0);

  // - create new label -
  labels.push(jit_label_undefined);
  cb_label_idxs.push(labels.used - 1);

  // - create new label -
  labels.push(jit_label_undefined);
  cb_label_idxs.push(labels.used - 1);

  return true;
}/*}}}*/

bool jit_pa_do_while_pre_condition(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  // - update label value -
  jit_label_t *label = labels.data + cb_label_idxs[cb_label_idxs.used - 2];
  jit_insn_label(jit_function,label);

  return true;
}/*}}}*/

bool jit_pa_break(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  // - update label value -
  jit_label_t *label = labels.data + cb_label_idxs.last();
  jit_insn_branch(jit_function,label);

  return true;
}/*}}}*/

bool jit_pa_continue(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  label_array_s &labels = _this.labels;
  ui_array_s &cb_label_idxs = _this.cb_label_idxs;

  // *****

  // - update label value -
  jit_label_t *label = labels.data + cb_label_idxs[cb_label_idxs.used - 2];
  jit_insn_branch(jit_function,label);

  return true;
}/*}}}*/

bool jit_pa_return(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  fun_record_s &fun_record = _this.fun_record;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.pop();

  // - ERROR -
  if (!fun_record.ret_type.are_assignable(exp_node.type))
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 3];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value = exp_node.load_value(jit_function);
  jit_insn_return(jit_function,value);

  return true;
}/*}}}*/

#define JIT_PA_RETRIEVE_NAMED_LABEL_IDX() \
/*{{{*/\
  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];\
  unsigned name_length = lse.terminal_end - lse.terminal_start;\
  char *name_data = source_string.data + lse.terminal_start;\
\
  /* - retrieve label name index - */\
  unsigned label_name_idx = label_names.get_idx_char_ptr_insert(name_length,name_data);\
\
  /* - create named label index - */\
  while (label_name_idx >= named_label_idxs.used)\
  {\
    named_label_idxs.push(c_idx_not_exist);\
  }\
\
  /* - retrieve label index - */\
  unsigned &label_idx = named_label_idxs[label_name_idx];\
\
  /* - create label if it not exist yet - */\
  if (label_idx == c_idx_not_exist)\
  {\
    label_idx = labels.used;\
    labels.push(jit_label_undefined);\
  }\
/*}}}*/

bool jit_pa_label(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  string_rb_tree_s &label_names = _this.label_names;
  ui_array_s &named_label_idxs = _this.named_label_idxs;
  label_array_s &labels = _this.labels;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  JIT_PA_RETRIEVE_NAMED_LABEL_IDX();

  // - set label value -
  jit_label_t *label_0 = &labels[label_idx];

  // - ERROR -
  if (jit_block_from_label(jit_function,*label_0))
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_LABEL,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_insn_label(jit_function,label_0);

  return true;
}/*}}}*/

bool jit_pa_goto(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  string_rb_tree_s &label_names = _this.label_names;
  ui_array_s &named_label_idxs = _this.named_label_idxs;
  label_array_s &labels = _this.labels;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  JIT_PA_RETRIEVE_NAMED_LABEL_IDX();

  // - branch to label -
  jit_label_t *label_0 = &labels[label_idx];
  jit_insn_branch(jit_function,label_0);

  return true;
}/*}}}*/

bool jit_pa_expression(jit_parser_s &_this)
{/*{{{*/
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_stack.pop();

  return true;
}/*}}}*/

bool jit_pa_operator_binary_equal(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  // - ERROR -
  if (!exp_node_0.are_assignable(exp_node_1))
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value_1 = exp_node_1.load_value(jit_function);

  exp_node_0.store_value(jit_function,value_1);

  return true;
}/*}}}*/

bool jit_pa_operator_binary_plus_equal(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  // - ERROR -
  if (exp_node_0.is_temp_const() ||
      exp_node_1.is_pointer())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value_0 = exp_node_0.load_value(jit_function);
  jit_value_t value_1 = exp_node_1.load_value(jit_function);
  jit_value_t tmp_value;

  if (exp_node_0.is_pointer())
  {
    tmp_value = jit_insn_load_elem_address(jit_function,value_0,value_1,exp_node_0.jit_pointed_type());
  }
  else
  {
    tmp_value = jit_insn_add(jit_function,value_0,value_1);
  }

  exp_node_0.store_value(jit_function,tmp_value);

  return true;
}/*}}}*/

bool jit_pa_operator_binary_minus_equal(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  // - ERROR -
  if (exp_node_0.is_temp_const() ||
      exp_node_1.is_pointer())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value_0 = exp_node_0.load_value(jit_function);
  jit_value_t value_1 = exp_node_1.load_value(jit_function);
  jit_value_t tmp_value;

  if (exp_node_0.is_pointer())
  {
    jit_value_t neg_value = jit_insn_neg(jit_function,value_1);
    tmp_value = jit_insn_load_elem_address(jit_function,value_0,neg_value,exp_node_0.jit_pointed_type());
  }
  else
  {
    tmp_value = jit_insn_sub(jit_function,value_0,value_1);
  }

  exp_node_0.store_value(jit_function,tmp_value);

  return true;
}/*}}}*/

#define JIT_PA_OPERATOR_BINARY_EQUAL_MUL_DIV(INSN) \
{/*{{{*/\
  jit_function_t jit_function = (jit_function_t)_this.jit_function;\
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;\
\
  /* ***** */\
\
  exp_node_s &exp_node_1 = exp_node_stack.pop();\
  exp_node_s &exp_node_0 = exp_node_stack.last();\
\
  /* - ERROR - */\
  if (exp_node_0.is_temp_const() ||\
      exp_node_0.is_pointer() || exp_node_1.is_pointer())\
  {\
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];\
\
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);\
    new_exception->params.push(lse.terminal_start);\
\
    return false;\
  }\
\
  jit_value_t value_0 = exp_node_0.load_value(jit_function);\
  jit_value_t value_1 = exp_node_1.load_value(jit_function);\
  jit_value_t tmp_value = INSN(jit_function,value_0,value_1);\
\
  exp_node_0.store_value(jit_function,tmp_value);\
\
  return true;\
}/*}}}*/

bool jit_pa_operator_binary_asterisk_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_MUL_DIV(jit_insn_mul);
}/*}}}*/

bool jit_pa_operator_binary_slash_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_MUL_DIV(jit_insn_div);
}/*}}}*/

#define JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(INSN) \
{/*{{{*/\
  jit_function_t jit_function = (jit_function_t)_this.jit_function;\
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;\
\
  /* ***** */\
\
  exp_node_s &exp_node_1 = exp_node_stack.pop();\
  exp_node_s &exp_node_0 = exp_node_stack.last();\
\
  /* - ERROR - */\
  if (exp_node_0.is_temp_const() ||\
      exp_node_0.is_pointer() || exp_node_1.is_pointer() ||\
      !(exp_node_0.is_integer() && exp_node_1.is_integer()))\
  {\
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];\
\
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);\
    new_exception->params.push(lse.terminal_start);\
\
    return false;\
  }\
\
  jit_value_t value_0 = exp_node_0.load_value(jit_function);\
  jit_value_t value_1 = exp_node_1.load_value(jit_function);\
  jit_value_t tmp_value = INSN(jit_function,value_0,value_1);\
\
  exp_node_0.store_value(jit_function,tmp_value);\
\
  return true;\
}/*}}}*/

bool jit_pa_operator_binary_percent_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(jit_insn_rem);
}/*}}}*/

bool jit_pa_operator_binary_double_ls_br_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(jit_insn_shl);
}/*}}}*/

bool jit_pa_operator_binary_double_rs_br_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(jit_insn_shr);
}/*}}}*/

bool jit_pa_operator_binary_ampersand_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(jit_insn_and);
}/*}}}*/

bool jit_pa_operator_binary_pipe_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(jit_insn_or);
}/*}}}*/

bool jit_pa_operator_binary_circumflex_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_EQUAL_INTEGER(jit_insn_xor);
}/*}}}*/

#define JIT_PA_OPERATOR_BINARY_LOG_OPERATION(INSN) \
{/*{{{*/\
  jit_function_t jit_function = (jit_function_t)_this.jit_function;\
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;\
\
  /* ***** */\
\
  exp_node_s &exp_node_1 = exp_node_stack.pop();\
  exp_node_s &exp_node_0 = exp_node_stack.last();\
\
  jit_value_t value_0 = exp_node_0.load_value(jit_function);\
  jit_value_t value_1 = exp_node_1.load_value(jit_function);\
\
  jit_value_t value_bool_0 = jit_insn_to_bool(jit_function,value_0);\
  jit_value_t value_bool_1 = jit_insn_to_bool(jit_function,value_1);\
  jit_value_t value_tmp = INSN(jit_function,value_bool_0,value_bool_1);\
\
  exp_node_0.type.set(c_var_type_i32,0,c_var_modifier_temporary);\
  exp_node_0.value = value_tmp;\
\
  return true;\
}/*}}}*/

bool jit_pa_operator_binary_double_ampersand(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_LOG_OPERATION(jit_insn_and);
}/*}}}*/

bool jit_pa_operator_binary_double_pipe(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_LOG_OPERATION(jit_insn_or);
}/*}}}*/

#define JIT_PA_OPERATOR_BINARY_COMPARE(INSN) \
{/*{{{*/\
  jit_function_t jit_function = (jit_function_t)_this.jit_function;\
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;\
\
  /* ***** */\
\
  exp_node_s &exp_node_1 = exp_node_stack.pop();\
  exp_node_s &exp_node_0 = exp_node_stack.last();\
\
  /* - ERROR - */\
  if (!exp_node_0.are_comparable(exp_node_1))\
  {\
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];\
\
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);\
    new_exception->params.push(lse.terminal_start);\
\
    return false;\
  }\
\
  jit_value_t value_0 = exp_node_0.load_value(jit_function);\
  jit_value_t value_1 = exp_node_1.load_value(jit_function);\
  jit_value_t tmp_value = INSN(jit_function,value_0,value_1);\
\
  exp_node_0.type.set(c_var_type_i32,0,c_var_modifier_temporary);\
  exp_node_0.value = tmp_value;\
\
  return true;\
}/*}}}*/

bool jit_pa_operator_binary_double_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_COMPARE(jit_insn_eq);
}/*}}}*/

bool jit_pa_operator_binary_exclamation_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_COMPARE(jit_insn_ne);
}/*}}}*/

bool jit_pa_operator_binary_rs_br(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_COMPARE(jit_insn_gt);
}/*}}}*/

bool jit_pa_operator_binary_ls_br(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_COMPARE(jit_insn_lt);
}/*}}}*/

bool jit_pa_operator_binary_rs_br_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_COMPARE(jit_insn_ge);
}/*}}}*/

bool jit_pa_operator_binary_ls_br_equal(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_COMPARE(jit_insn_le);
}/*}}}*/

#define JIT_PA_OPERATOR_BINARY_INTEGER(INSN) \
{/*{{{*/\
  jit_function_t jit_function = (jit_function_t)_this.jit_function;\
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;\
\
  /* ***** */\
\
  exp_node_s &exp_node_1 = exp_node_stack.pop();\
  exp_node_s &exp_node_0 = exp_node_stack.last();\
\
  /* - ERROR - */\
  if (exp_node_0.is_pointer() || exp_node_1.is_pointer() ||\
      !(exp_node_0.is_integer() && exp_node_1.is_integer()))\
  {\
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];\
\
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);\
    new_exception->params.push(lse.terminal_start);\
\
    return false;\
  }\
\
  jit_value_t value_0 = exp_node_0.load_value(jit_function);\
  jit_value_t value_1 = exp_node_1.load_value(jit_function);\
  jit_value_t tmp_value = INSN(jit_function,value_0,value_1);\
\
  exp_node_0.type.set(exp_node_0.res_type_id(exp_node_1),0,c_var_modifier_temporary);\
  exp_node_0.value = tmp_value;\
\
  return true;\
}/*}}}*/

bool jit_pa_operator_binary_ampersand(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_INTEGER(jit_insn_and);
}/*}}}*/

bool jit_pa_operator_binary_pipe(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_INTEGER(jit_insn_or);
}/*}}}*/

bool jit_pa_operator_binary_circumflex(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_INTEGER(jit_insn_xor);
}/*}}}*/

bool jit_pa_operator_binary_double_rs_br(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_INTEGER(jit_insn_shr);
}/*}}}*/

bool jit_pa_operator_binary_double_ls_br(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_INTEGER(jit_insn_shl);
}/*}}}*/

bool jit_pa_operator_binary_plus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  jit_value_t value_0 = exp_node_0.load_value(jit_function);
  jit_value_t value_1 = exp_node_1.load_value(jit_function);

  if (exp_node_0.is_pointer())
  {
    // - ERROR -
    if (exp_node_1.is_pointer())
    {
      lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

      interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
      exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
      new_exception->params.push(lse.terminal_start);

      return false;
    }

    jit_value_t tmp_value = jit_insn_load_elem_address(jit_function,value_0,value_1,exp_node_0.jit_pointed_type());
    
    exp_node_0.type.modifiers = c_var_modifier_temporary;
    exp_node_0.value = tmp_value;
  }
  else
  {
    if (exp_node_1.is_pointer())
    {
      jit_value_t tmp_value = jit_insn_load_elem_address(jit_function,value_1,value_0,exp_node_1.jit_pointed_type());

      exp_node_0.type.set(exp_node_1.type.type_id,exp_node_1.type.pointer_level,c_var_modifier_temporary);
      exp_node_0.value = tmp_value;
    }
    else
    {
      jit_value_t tmp_value = jit_insn_add(jit_function,value_0,value_1);

      exp_node_0.type.set(exp_node_0.res_type_id(exp_node_1),0,c_var_modifier_temporary);
      exp_node_0.value = tmp_value;
    }
  }

  return true;
}/*}}}*/

bool jit_pa_operator_binary_minus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  jit_value_t value_0 = exp_node_0.load_value(jit_function);
  jit_value_t value_1 = exp_node_1.load_value(jit_function);

  if (exp_node_0.is_pointer())
  { 
    if (exp_node_1.is_pointer())
    {
      // - ERROR -
      if (exp_node_0.type.pointer_level != exp_node_1.type.pointer_level ||
          exp_node_0.type.type_id != exp_node_1.type.type_id)
      {
        lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

        interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
        new_exception->params.push(lse.terminal_start);

        return false;
      }

      jit_value_t power_value = jit_value_create_nint_constant(jit_function,jit_type_uint,exp_node_0.pointed_size_power());
      jit_value_t diff_value = jit_insn_sub(jit_function,value_0,value_1);
      jit_value_t tmp_value = jit_insn_shr(jit_function,diff_value,power_value);

      exp_node_0.type.set(c_var_type_i32,0,c_var_modifier_temporary);
      exp_node_0.value = tmp_value;
    }
    else
    {
      jit_value_t neg_value = jit_insn_neg(jit_function,value_1);
      jit_value_t tmp_value = jit_insn_load_elem_address(jit_function,value_0,neg_value,exp_node_0.jit_pointed_type());

      exp_node_0.type.modifiers = c_var_modifier_temporary;
      exp_node_0.value = tmp_value;
    }
  }
  else
  {
    jit_value_t tmp_value = jit_insn_sub(jit_function,value_0,value_1);

    exp_node_0.type.set(exp_node_0.res_type_id(exp_node_1),0,c_var_modifier_temporary);
    exp_node_0.value = tmp_value;
  }

  return true;
}/*}}}*/

#define JIT_PA_OPERATOR_BINARY_MUL_DIV(INSN) \
{/*{{{*/\
  jit_function_t jit_function = (jit_function_t)_this.jit_function;\
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;\
\
  /* ***** */\
\
  exp_node_s &exp_node_1 = exp_node_stack.pop();\
  exp_node_s &exp_node_0 = exp_node_stack.last();\
\
  /* - ERROR - */\
  if (exp_node_0.is_pointer() || exp_node_1.is_pointer())\
  {\
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];\
\
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);\
    new_exception->params.push(lse.terminal_start);\
\
    return false;\
  }\
\
  jit_value_t value_0 = exp_node_0.load_value(jit_function);\
  jit_value_t value_1 = exp_node_1.load_value(jit_function);\
  jit_value_t tmp_value = INSN(jit_function,value_0,value_1);\
\
  exp_node_0.type.set(exp_node_0.res_type_id(exp_node_1),0,c_var_modifier_temporary);\
  exp_node_0.value = tmp_value;\
\
  return true;\
}/*}}}*/

bool jit_pa_operator_binary_asterisk(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_MUL_DIV(jit_insn_mul);
}/*}}}*/

bool jit_pa_operator_binary_slash(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_MUL_DIV(jit_insn_div);
}/*}}}*/

bool jit_pa_operator_binary_percent(jit_parser_s &_this)
{/*{{{*/
  JIT_PA_OPERATOR_BINARY_INTEGER(jit_insn_rem);
}/*}}}*/

bool jit_pa_operator_unary_post_double_plus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t dup_value = jit_insn_dup(jit_function,value);
  jit_value_t one_value = jit_value_create_nint_constant(jit_function,jit_type_int,1);
  jit_value_t tmp_value;

  if (exp_node.is_pointer())
  {
    tmp_value = jit_insn_load_elem_address(jit_function,value,one_value,exp_node.jit_pointed_type());
  }
  else
  {
    tmp_value = jit_insn_add(jit_function,value,one_value);
  }

  exp_node.store_value(jit_function,tmp_value);

  exp_node.type.modifiers = c_var_modifier_temporary;
  exp_node.value = dup_value;

  return true;
}/*}}}*/

bool jit_pa_operator_unary_post_double_minus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t dup_value = jit_insn_dup(jit_function,value);
  jit_value_t one_value = jit_value_create_nint_constant(jit_function,jit_type_int,1);
  jit_value_t tmp_value;

  if (exp_node.is_pointer())
  {
    jit_value_t neg_value = jit_insn_neg(jit_function,one_value);
    tmp_value = jit_insn_load_elem_address(jit_function,value,neg_value,exp_node.jit_pointed_type());
  }
  else
  {
    tmp_value = jit_insn_sub(jit_function,value,one_value);
  }

  exp_node.store_value(jit_function,tmp_value);

  exp_node.type.modifiers = c_var_modifier_temporary;
  exp_node.value = dup_value;

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_double_plus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t one_value = jit_value_create_nint_constant(jit_function,jit_type_int,1);
  jit_value_t tmp_value;

  if (exp_node.is_pointer())
  {
    tmp_value = jit_insn_load_elem_address(jit_function,value,one_value,exp_node.jit_pointed_type());
  }
  else
  {
    tmp_value = jit_insn_add(jit_function,value,one_value);
  }

  exp_node.store_value(jit_function,tmp_value);

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_double_minus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t one_value = jit_value_create_nint_constant(jit_function,jit_type_int,1);
  jit_value_t tmp_value;

  if (exp_node.is_pointer())
  {
    jit_value_t neg_value = jit_insn_neg(jit_function,one_value);
    tmp_value = jit_insn_load_elem_address(jit_function,value,neg_value,exp_node.jit_pointed_type());
  }
  else
  {
    tmp_value = jit_insn_sub(jit_function,value,one_value);
  }

  exp_node.store_value(jit_function,tmp_value);

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_plus(jit_parser_s &_this)
{/*{{{*/
  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_minus(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  // - ERROR -
  if (exp_node.is_pointer())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t tmp_value = jit_insn_neg(jit_function,value);

  exp_node.type.modifiers = c_var_modifier_temporary;
  exp_node.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_exclamation(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t tmp_value = jit_insn_to_not_bool(jit_function,value);

  exp_node.type.set(c_var_type_i32,0,c_var_modifier_temporary);
  exp_node.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_tilde(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  // - ERROR -
  if (exp_node.is_pointer() || !exp_node.is_integer())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t tmp_value = jit_insn_not(jit_function,value);

  exp_node.type.modifiers = c_var_modifier_temporary;
  exp_node.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_asterisk(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  // - ERROR -
  if (!exp_node.is_pointer())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value = exp_node.load_value(jit_function);

  exp_node.type.modifiers = c_var_modifier_reference;
  exp_node.type.pointer_level--;
  exp_node.value = value;

  return true;
}/*}}}*/

bool jit_pa_operator_unary_pre_ampersand(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node = exp_node_stack.last();

  // - ERROR -
  if (exp_node.is_temp_const())
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t tmp_value = jit_insn_address_of(jit_function,value);

  exp_node.type.modifiers = c_var_modifier_temporary;
  exp_node.type.pointer_level++;
  exp_node.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_operator_binary_le_br_re_br(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  // - ERROR -
  if (!(exp_node_0.is_pointer() && exp_node_1.is_integer()))
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 3];

    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  jit_value_t value_0 = exp_node_0.load_value(jit_function);
  jit_value_t value_1 = exp_node_1.load_value(jit_function);

  jit_value_t tmp_value = jit_insn_load_elem_address(jit_function,value_0,value_1,exp_node_0.jit_pointed_type());

  exp_node_0.type.modifiers = c_var_modifier_reference;
  exp_node_0.type.pointer_level--;
  exp_node_0.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_cast(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  var_types_s &tmp_var_types = _this.tmp_var_types;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;

  // *****

  var_type_s &var_type = tmp_var_types.pop();
  exp_node_s &exp_node = exp_node_stack.last();

  jit_value_t value = exp_node.load_value(jit_function);
  jit_value_t tmp_value = jit_insn_convert(jit_function,value,exp_node.jit_type(),0);

  // - add temporary modifier -
  var_type.modifiers = c_var_modifier_temporary;

  // - update expression node -
  exp_node.type = var_type;
  exp_node.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_identifier(jit_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &var_names = _this.var_names;
  var_records_s &var_records = _this.var_records;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - retrieve variable index -
  unsigned var_idx = var_names.get_idx_char_ptr(name_length,name_data);

  // - ERROR -
  if (var_idx == c_idx_not_exist)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_UNDECLARED_VARIABLE,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - retrieve variable record -
  var_record_s &var_record = var_records[var_idx];

  // - push value to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type = var_record.type;
  new_exp_node.value = var_record.value;

  return true;
}/*}}}*/

bool jit_pa_conditional_expression(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  jit_label_t *label = labels.data + label_idxs.pop();

  exp_node_s &exp_node_1 = exp_node_stack.pop();
  exp_node_s &exp_node_0 = exp_node_stack.last();

  jit_value_t value_0 = exp_node_0.load_value(jit_function); 
  jit_value_t value_1 = exp_node_1.load_value(jit_function); 

  jit_insn_store(jit_function,value_0,value_1);

  // - update label value -
  jit_insn_label(jit_function,label);

  return true;
}/*}}}*/

bool jit_pa_conditional_condition(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  exp_node_s &exp_node = exp_node_stack.pop();
  jit_value_t value = exp_node.load_value(jit_function);

  // - create new label -
  labels.push(jit_label_undefined);
  label_idxs.push(labels.used - 1);
  jit_label_t *label = &labels.last();

  jit_insn_branch_if_not(jit_function,value,label);

  return true;
}/*}}}*/

bool jit_pa_conditional_true(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  label_array_s &labels = _this.labels;
  ui_array_s &label_idxs = _this.label_idxs;

  // *****

  jit_label_t *label_0 = labels.data + label_idxs.pop();

  // - create new label -
  labels.push(jit_label_undefined);
  label_idxs.push(labels.used - 1);
  jit_label_t *label_1 = &labels.last();

  exp_node_s &exp_node = exp_node_stack.last();
  jit_value_t value = exp_node.load_value(jit_function);

  jit_value_t value_tmp = jit_value_create(jit_function,jit_value_get_type(value));

  jit_insn_store(jit_function,value_tmp,value);
  jit_insn_branch(jit_function,label_1);

  // - update label value -
  jit_insn_label(jit_function,label_0);

  // - set expression node values -
  exp_node.type.modifiers = c_var_modifier_temporary;
  exp_node.value = value_tmp;

  return true;
}/*}}}*/

bool jit_pa_function_call(jit_parser_s &_this)
{/*{{{*/
  jit_context_s *ucl_context = (jit_context_s *)_this.ucl_context;
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  ui_array_s &param_cnt = _this.param_cnt;
  ui_array_s &function_idxs = _this.function_idxs;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 3];
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - retrieve parameter count -
  unsigned fun_param_cnt = param_cnt.pop();

  // - retrieve function indexes by name -
  ucl_context->fun_names.get_idxs_char_ptr(name_length,name_data,function_idxs);

  unsigned fun_idx = c_idx_not_exist;
  unsigned min_fun_score = 0xffffffff;
  bool ambiguity = false;

  // - process found function indexes -
  if (function_idxs.used != 0)
  {
    unsigned *fi_ptr = function_idxs.data;
    unsigned *fi_ptr_end = fi_ptr + function_idxs.used;
    do {
      unsigned fun_score = 0;
      fun_record_s &fun_record = ucl_context->fun_records[*fi_ptr];

      // - test function parameter count -
      if (fun_record.param_types.used == fun_param_cnt)
      {
        if (fun_param_cnt != 0)
        {
          exp_node_s *en_ptr = exp_node_stack.data + exp_node_stack.used - fun_param_cnt;
          exp_node_s *en_ptr_end = exp_node_stack.data + exp_node_stack.used;
          var_type_s *pt_ptr = fun_record.param_types.data;
          do {
            
            // - expression node type -
            var_type_s &en_type = en_ptr->type;

            // - if pointer levels differs -
            if (en_type.pointer_level != pt_ptr->pointer_level)
            {
              fun_score = 0xffffffff;
              break;
            }

            if (en_type.pointer_level > 0)
            {
              // - if pointed type differs -
              if (en_type.type_id != pt_ptr->type_id)
              {
                fun_score = 0xffffffff;
                break;
              }
            }
            else
            {
              // - retrieve type conversion penalty -
              unsigned conv_penalty = c_type_conv_dist[en_type.type_id][pt_ptr->type_id];

              if (conv_penalty == 0xffffffff)
              {
                fun_score = 0xffffffff;
                break;
              }

              // - add type conversion penalty to score -
              fun_score += conv_penalty;
            }

          } while(++pt_ptr,++en_ptr < en_ptr_end);
        }

        // - store minimal function score -
        if (fun_score < min_fun_score)
        {
          fun_idx = *fi_ptr;
          min_fun_score = fun_score;
          ambiguity = false;
        }
        else
        {
          // - if score is same as minimal score -
          if (fun_score == min_fun_score)
          {
            ambiguity = true;
          }
        }
      }
    } while(++fi_ptr < fi_ptr_end);
  }

  // - ERROR -
  if (fun_idx == c_idx_not_exist || ambiguity)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_UNDECLARED_FUNCTION,0,(location_s *)it.blank_location);
    new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - retrieve function record -
  fun_record_s &fun_record = ucl_context->fun_records[fun_idx];

  // - jit values of function parameters -
  jit_value_t jit_params[fun_param_cnt];

  // - prepare function parameters -
  if (fun_param_cnt != 0)
  {
    exp_node_s *en_ptr = exp_node_stack.data + exp_node_stack.used - fun_param_cnt;
    exp_node_s *en_ptr_end = exp_node_stack.data + exp_node_stack.used;
    jit_value_t *jv_ptr = jit_params;
    do {
      *jv_ptr++ = en_ptr->load_value(jit_function);
    } while(++en_ptr < en_ptr_end);
  }

  // - call function -
  jit_value_t tmp_value = jit_insn_call(jit_function,NULL,(jit_function_t)fun_record.jit_function,0,jit_params,fun_param_cnt,0);

  // - remove parameters from node stack -
  exp_node_stack.used -= fun_param_cnt;

  // - push function return value to expression node stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type = fun_record.ret_type;
  new_exp_node.value = tmp_value;

  return true;
}/*}}}*/

bool jit_pa_parameters_begin(jit_parser_s &_this)
{/*{{{*/
  ui_array_s &param_cnt = _this.param_cnt;

  // *****

  param_cnt.push(0);

  return true;
}/*}}}*/

bool jit_pa_parameter(jit_parser_s &_this)
{/*{{{*/
  ui_array_s &param_cnt = _this.param_cnt;

  // *****

  param_cnt.last()++;

  return true;
}/*}}}*/

bool jit_pa_const_char(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  int const_char = source_string.data[lalr_stack.last().terminal_start + 1];

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_u8,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_ubyte,const_char);

  return true;
}/*}}}*/

bool jit_pa_const_octal_char(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned char_num_end = (lse.terminal_end - lse.terminal_start) - 1;
  char *char_num_data = source_string.data + lse.terminal_start;

  // - retrieve char number -
  char_num_data[char_num_end] = '\0';
  int const_char = strtol(char_num_data + 2,NULL,8);
  char_num_data[char_num_end] = '\'';

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_u8,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_ubyte,const_char);

  return true;
}/*}}}*/

bool jit_pa_const_hex_char(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned char_num_end = (lse.terminal_end - lse.terminal_start) - 1;
  char *char_num_data = source_string.data + lse.terminal_start;

  // - retrieve char number -
  char_num_data[char_num_end] = '\0';
  int const_char = strtol(char_num_data + 3,NULL,16);
  char_num_data[char_num_end] = '\'';

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_u8,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_ubyte,const_char);

  return true;
}/*}}}*/

bool jit_pa_const_backslash_char(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  int const_char = 0;

  switch (source_string.data[lalr_stack.last().terminal_start + 2])
  {
  case 'a':
    const_char = '\a';
    break;
  case 'b':
    const_char = '\b';
    break;
  case 'f':
    const_char = '\f';
    break;
  case 'n':
    const_char = '\n';
    break;
  case 'r':
    const_char = '\r';
    break;
  case 't':
    const_char = '\t';
    break;
  case 'v':
    const_char = '\v';
    break;
  case '\\':
    const_char = '\\';
    break;
  case '?':
    const_char = '\?';
    break;
  case '\'':
    const_char = '\'';
    break;
  case '"':
    const_char = '"';
    break;
  default:
    debug_assert(0);
  }

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_u8,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_ubyte,const_char);

  return true;
}/*}}}*/

bool jit_pa_const_oct_i32(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve constant integer -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  int const_int = strtoll(num_data,NULL,8);
  num_data[num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_i32,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_int,const_int);

  return true;
}/*}}}*/

bool jit_pa_const_dec_i32(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve constant integer -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  int const_int = strtoll(num_data,NULL,10);
  num_data[num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_i32,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_int,const_int);

  return true;
}/*}}}*/

bool jit_pa_const_hex_i32(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve constant integer -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  int const_int = strtoll(num_data,NULL,16);
  num_data[num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_i32,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_nint_constant(jit_function,jit_type_int,const_int);

  return true;
}/*}}}*/

bool jit_pa_const_oct_i64(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve constant integer -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  long long int const_int = strtoll(num_data,NULL,8);
  num_data[num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_i64,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_long_constant(jit_function,jit_type_long,const_int);

  return true;
}/*}}}*/

bool jit_pa_const_dec_i64(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve constant integer -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  long long int const_int = strtoll(num_data,NULL,10);
  num_data[num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_i64,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_long_constant(jit_function,jit_type_long,const_int);

  return true;
}/*}}}*/

bool jit_pa_const_hex_i64(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve constant integer -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  long long int const_int = strtoll(num_data,NULL,16);
  num_data[num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_i64,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_long_constant(jit_function,jit_type_long,const_int);

  return true;
}/*}}}*/

bool jit_pa_const_f32(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned float_num_end = lse.terminal_end - lse.terminal_start;
  char *float_num_data = source_string.data + lse.terminal_start;

  // - retrieve constant float -
  char tmp_char = float_num_data[float_num_end];
  float_num_data[float_num_end] = '\0';
  float const_float = strtof(float_num_data,NULL);
  float_num_data[float_num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_f32,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_float32_constant(jit_function,jit_type_float32,const_float);

  return true;
}/*}}}*/

bool jit_pa_const_f64(jit_parser_s &_this)
{/*{{{*/
  jit_function_t jit_function = (jit_function_t)_this.jit_function;
  string_s &source_string = _this.source_string;
  exp_nodes_s &exp_node_stack = _this.exp_node_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned float_num_end = lse.terminal_end - lse.terminal_start;
  char *float_num_data = source_string.data + lse.terminal_start;

  // - retrieve constant float -
  char tmp_char = float_num_data[float_num_end];
  float_num_data[float_num_end] = '\0';
  double const_float = strtod(float_num_data,NULL);
  float_num_data[float_num_end] = tmp_char;

  // - push constant to expression stack -
  exp_node_stack.push_blank();

  // - set expression node values -
  exp_node_s &new_exp_node = exp_node_stack.last();
  new_exp_node.type.set(c_var_type_f64,0,c_var_modifier_constant);
  new_exp_node.value = jit_value_create_float64_constant(jit_function,jit_type_float64,const_float);

  return true;
}/*}}}*/

