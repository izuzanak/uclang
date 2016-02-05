
@begin
include "ucl_lightning.h"
@end

/*
 * constants and definitions
 */

const unsigned max_number_string_length = 12;

// - callers of parse action functions -
const unsigned c_ltg_parse_action_cnt = 122;
bool(*ltg_pa_callers[c_ltg_parse_action_cnt])(ltg_parser_s &_this) =
{/*{{{*/
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_function,
  ltg_pa_function_name,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_fun_parameter,
  ltg_pa_null,
  ltg_pa_type,
  ltg_pa_pointer,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_declaration_end,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_modifier_volatile,
  ltg_pa_type,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_declare,
  ltg_pa_declare_expression,
  ltg_pa_declare_array,
  ltg_pa_variable,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_command_block_done,
  ltg_pa_command_block_begin,
  ltg_pa_null,
  ltg_pa_if_condition,
  ltg_pa_if_statement,
  ltg_pa_if_else_statement,
  ltg_pa_if_else,
  ltg_pa_while_statement,
  ltg_pa_while_begin,
  ltg_pa_while_condition,
  ltg_pa_do_while_statement,
  ltg_pa_do_while_begin,
  ltg_pa_do_while_pre_condition,
  ltg_pa_break,
  ltg_pa_continue,
  ltg_pa_return,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_expression,
  ltg_pa_null,
  ltg_pa_operator_binary_equal,
  ltg_pa_operator_binary_plus_equal,
  ltg_pa_operator_binary_minus_equal,
  ltg_pa_operator_binary_asterisk_equal,
  ltg_pa_operator_binary_slash_equal,
  ltg_pa_operator_binary_percent_equal,
  ltg_pa_operator_binary_double_ls_br_equal,
  ltg_pa_operator_binary_double_rs_br_equal,
  ltg_pa_operator_binary_ampersand_equal,
  ltg_pa_operator_binary_pipe_equal,
  ltg_pa_operator_binary_circumflex_equal,
  ltg_pa_null,
  ltg_pa_operator_binary_double_ampersand,
  ltg_pa_operator_binary_double_pipe,
  ltg_pa_null,
  ltg_pa_operator_binary_double_equal,
  ltg_pa_operator_binary_exclamation_equal,
  ltg_pa_operator_binary_rs_br,
  ltg_pa_operator_binary_ls_br,
  ltg_pa_operator_binary_rs_br_equal,
  ltg_pa_operator_binary_ls_br_equal,
  ltg_pa_null,
  ltg_pa_operator_binary_ampersand,
  ltg_pa_operator_binary_pipe,
  ltg_pa_operator_binary_circumflex,
  ltg_pa_null,
  ltg_pa_operator_binary_double_rs_br,
  ltg_pa_operator_binary_double_ls_br,
  ltg_pa_null,
  ltg_pa_operator_binary_plus,
  ltg_pa_operator_binary_minus,
  ltg_pa_null,
  ltg_pa_operator_binary_asterisk,
  ltg_pa_operator_binary_slash,
  ltg_pa_operator_binary_percent,
  ltg_pa_null,
  ltg_pa_operator_unary_post_double_plus,
  ltg_pa_operator_unary_post_double_minus,
  ltg_pa_operator_unary_pre_double_plus,
  ltg_pa_operator_unary_pre_double_minus,
  ltg_pa_operator_unary_pre_plus,
  ltg_pa_operator_unary_pre_minus,
  ltg_pa_operator_unary_pre_exclamation,
  ltg_pa_operator_unary_pre_tilde,
  ltg_pa_operator_unary_pre_asterisk,
  ltg_pa_operator_unary_pre_ampersand,
  ltg_pa_operator_binary_le_br_re_br,
  ltg_pa_cast,
  ltg_pa_null,
  ltg_pa_identifier,
  ltg_pa_conditional_expression,
  ltg_pa_conditional_condition,
  ltg_pa_conditional_true,
  ltg_pa_function_call,
  ltg_pa_null,
  ltg_pa_null,
  ltg_pa_parameters_begin,
  ltg_pa_parameter,
  ltg_pa_parameter,
  ltg_pa_const_char,
  ltg_pa_const_octal_char,
  ltg_pa_const_hex_char,
  ltg_pa_const_backslash_char,
  ltg_pa_const_oct_i32,
  ltg_pa_const_dec_i32,
  ltg_pa_const_hex_i32,
  ltg_pa_const_oct_i64,
  ltg_pa_const_dec_i64,
  ltg_pa_const_hex_i64,
  ltg_pa_const_f32,
  ltg_pa_const_f64,
};/*}}}*/

/*
 * parse action macros
 */

/*
 * functions implementing parse actions of parser
 */

bool ltg_pa_null(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_null\n");

  return true;
}/*}}}*/

bool ltg_pa_function(ltg_parser_s &_this)
{/*{{{*/
  jit_state_s *ucl_jit_state = (jit_state_s *)_this.ucl_jit_state;
  jit_state_t_ptr _jit = _this._jit;
  string_s &ucl_signature = _this.ucl_signature;
  val_records_s &val_records = _this.val_records;
  fun_record_s &fun_record = _this.fun_record;
  ui_array_s &fun_param_idxs = _this.fun_param_idxs;

  // *****

  // - function parameters ucl types -
  val_type_s *ucl_param_types[fun_record.param_types.used];

  // - fill array of function parameter types -
  if (fun_record.param_types.used != 0)
  {
    val_type_s *vt_ptr = fun_record.param_types.data;
    val_type_s *vt_ptr_end = vt_ptr + fun_record.param_types.used;
    val_type_s **pt_ptr = ucl_param_types;
    do {
      *pt_ptr = vt_ptr;
    } while(++pt_ptr,++vt_ptr < vt_ptr_end);
  }

  // - generate function ucl signature -
  ltg_parser_s::create_signature(fun_record.name.size - 1,fun_record.name.data,fun_record.param_types.used,ucl_param_types,ucl_signature);

  // - ERROR -
  if (ucl_jit_state->ucl_signatures.get_idx(ucl_signature) != c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_FUNCTION_DEFINITION,0,(location_s *)it.blank_location);
    //new_exception->params.push(_this.fun_name_pos.ui_first);

    return false;
  }

  // - generate function prolog -
  jit_prolog();

  // - read values of function parameters -
  if (fun_param_idxs.used != 0)
  {
    unsigned *pi_ptr = fun_param_idxs.data;
    unsigned *pi_ptr_end = pi_ptr + fun_param_idxs.used;
    unsigned param_idx = 0;
    do {
      val_record_s &val_record = val_records[*pi_ptr];

      // - retrieve parameter value -
      val_record.value = (basic_64b)jit_arg();

    } while(++param_idx,++pi_ptr < pi_ptr_end);
  }

  return true;
}/*}}}*/

bool ltg_pa_function_name(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  fun_record_s &fun_record = _this.fun_record;
  val_types_s &tmp_val_types = _this.tmp_val_types;
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
  fun_record.ret_type = tmp_val_types.pop();

  return true;
}/*}}}*/

bool ltg_pa_fun_parameter(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &val_names = _this.val_names;
  val_records_s &val_records = _this.val_records;
  fun_record_s &fun_record = _this.fun_record;
  val_types_s &tmp_val_types = _this.tmp_val_types;
  ui_array_s &fun_param_idxs = _this.fun_param_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - create value name -
  unsigned val_idx = val_names.get_idx_char_ptr_insert(name_length,name_data);

  // - ERROR -
  if (val_idx < val_records.used)
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_PARAMETER_IDENTIFIER,0,(location_s *)it.blank_location);
    //new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - create value record -
  do {
    val_records.push_blank();
  } while(val_records.used <= val_idx);

  // - retrieve parameter type -
  val_type_s &val_type = tmp_val_types.pop();

  // - fill value record -
  val_records.last().set(val_type,0,c_idx_not_exist,c_idx_not_exist);

  // - store parameter record index -
  fun_param_idxs.push(val_records.used - 1);

  // - store function parameter type -
  fun_record.param_types.push(val_type);

  return true;
}/*}}}*/

bool ltg_pa_type(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  unsigned &tmp_modifiers = _this.tmp_modifiers;
  val_types_s &tmp_val_types = _this.tmp_val_types;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned type_length = lse.terminal_end - lse.terminal_start;
  char *type_data = source_string.data + lse.terminal_start;

  // - recognize type identifier -
  unsigned type_id = ltg_parser_s::recognize_type(type_length,type_data);

  // - ERROR -
  if (type_id == c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_UNKNOWN_DATA_TYPE,0,(location_s *)it.blank_location);
    //new_exception->params.push(lse.terminal_start);

    return false;
  }

  tmp_val_types.push_blank();
  tmp_val_types.last().set(type_id,0,tmp_modifiers);

  return true;
}/*}}}*/

bool ltg_pa_pointer(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_pointer\n");

  return true;
}/*}}}*/

bool ltg_pa_declaration_end(ltg_parser_s &_this)
{/*{{{*/
  unsigned &tmp_modifiers = _this.tmp_modifiers;
  val_types_s &tmp_val_types = _this.tmp_val_types;

  // *****

  tmp_modifiers = 0;
  tmp_val_types.pop();

  return true;
}/*}}}*/

bool ltg_pa_modifier_volatile(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_modifier_volatile\n");

  return true;
}/*}}}*/

bool ltg_pa_declare(ltg_parser_s &_this)
{/*{{{*/
  return true;
}/*}}}*/

bool ltg_pa_declare_expression(ltg_parser_s &_this)
{/*{{{*/
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
  ui_array_s &intermediate_code = _this.intermediate_code;
  ui_array_s &block_var_idxs = _this.block_var_idxs;

  // *****

  unsigned val_idx_0 = block_var_idxs.last();
  unsigned val_idx_1 = exp_values.pop();

  val_record_s &val_record_0 = val_records[val_idx_0];
  val_record_s &val_record_1 = val_records[val_idx_1];

  // - ERROR -
  if (!val_record_0.are_assignable(val_record_1))
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    //new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - update liveness -
  unsigned im_used = intermediate_code.used;
  val_record_0.update_live(im_used);
  val_record_1.update_live(im_used);

  // - generate intermediate code -
  intermediate_code.push(im_insn_store);
  intermediate_code.push(val_idx_0);
  intermediate_code.push(val_idx_1);

  return true;
}/*}}}*/

bool ltg_pa_declare_array(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_declare_array\n");

  return true;
}/*}}}*/

bool ltg_pa_variable(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &val_names = _this.val_names;
  val_records_s &val_records = _this.val_records;
  val_types_s &tmp_val_types = _this.tmp_val_types;
  ui_array_s &block_var_idxs = _this.block_var_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - create value name -
  unsigned val_idx = val_names.get_idx_char_ptr_insert(name_length,name_data);

  // - ERROR -
  if (val_idx < val_records.used)
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_DUPLICIT_VAR_PARAM_IDENTIFIER,0,(location_s *)it.blank_location);
    //new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - create value record -
  do {
    val_records.push_blank();
  } while(val_records.used <= val_idx);

  // - retrieve value type -
  val_type_s &val_type = tmp_val_types.last();

  // - fill value record -
  val_records.last().set(val_type,0,c_idx_not_exist,c_idx_not_exist);

  // - reset tmp value type pointer level -
  val_type.pointer_level = 0;

  // - store value index -
  block_var_idxs.push(val_idx);

  return true;
}/*}}}*/

bool ltg_pa_command_block_done(ltg_parser_s &_this)
{/*{{{*/
  string_rb_tree_s &val_names = _this.val_names;
  ui_array_s &block_var_idxs = _this.block_var_idxs;
  ui_array_s &block_var_bases = _this.block_var_bases;

  // *****

  unsigned block_base = block_var_bases.pop();
  while (block_var_idxs.used > block_base)
  {
    val_names.remove(block_var_idxs.pop());
  }

  return true;
}/*}}}*/

bool ltg_pa_command_block_begin(ltg_parser_s &_this)
{/*{{{*/
  ui_array_s &block_var_idxs = _this.block_var_idxs;
  ui_array_s &block_var_bases = _this.block_var_bases;

  // *****

  block_var_bases.push(block_var_idxs.used);

  return true;
}/*}}}*/

bool ltg_pa_if_condition(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_if_condition\n");

  return true;
}/*}}}*/

bool ltg_pa_if_statement(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_if_statement\n");

  return true;
}/*}}}*/

bool ltg_pa_if_else_statement(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_if_else_statement\n");

  return true;
}/*}}}*/

bool ltg_pa_if_else(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_if_else\n");

  return true;
}/*}}}*/

bool ltg_pa_while_statement(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_while_statement\n");

  return true;
}/*}}}*/

bool ltg_pa_while_begin(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_while_begin\n");

  return true;
}/*}}}*/

bool ltg_pa_while_condition(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_while_condition\n");

  return true;
}/*}}}*/

bool ltg_pa_do_while_statement(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_do_while_statement\n");

  return true;
}/*}}}*/

bool ltg_pa_do_while_begin(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_do_while_begin\n");

  return true;
}/*}}}*/

bool ltg_pa_do_while_pre_condition(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_do_while_pre_condition\n");

  return true;
}/*}}}*/

bool ltg_pa_break(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_break\n");

  return true;
}/*}}}*/

bool ltg_pa_continue(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_continue\n");

  return true;
}/*}}}*/

bool ltg_pa_return(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_return\n");

  return true;
}/*}}}*/

bool ltg_pa_expression(ltg_parser_s &_this)
{/*{{{*/
  ui_array_s &exp_values = _this.exp_values;

  // *****

  exp_values.pop();

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_equal(ltg_parser_s &_this)
{/*{{{*/
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
  ui_array_s &intermediate_code = _this.intermediate_code;

  // *****

  unsigned val_idx_1 = exp_values.pop();
  unsigned val_idx_0 = exp_values.last();

  val_record_s &val_record_0 = val_records[val_idx_0];
  val_record_s &val_record_1 = val_records[val_idx_1];

  // - ERROR -
  if (!val_record_0.are_assignable(val_record_1))
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,0,(location_s *)it.blank_location);
    //new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - update liveness -
  unsigned im_used = intermediate_code.used;
  val_record_0.update_live(im_used);
  val_record_1.update_live(im_used);

  // - generate intermediate code -
  intermediate_code.push(im_insn_store);
  intermediate_code.push(val_idx_0);
  intermediate_code.push(val_idx_1);

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_plus_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_plus_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_minus_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_minus_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_asterisk_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_asterisk_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_slash_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_slash_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_percent_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_percent_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_ls_br_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_ls_br_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_rs_br_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_rs_br_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_ampersand_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_ampersand_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_pipe_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_pipe_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_circumflex_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_circumflex_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_ampersand(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_ampersand\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_pipe(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_pipe\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_exclamation_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_exclamation_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_rs_br(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_rs_br\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_ls_br(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_ls_br\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_rs_br_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_rs_br_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_ls_br_equal(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_ls_br_equal\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_ampersand(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_ampersand\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_pipe(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_pipe\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_circumflex(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_circumflex\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_rs_br(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_rs_br\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_double_ls_br(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_double_ls_br\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_plus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_plus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_minus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_minus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_asterisk(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_asterisk\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_slash(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_slash\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_percent(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_percent\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_post_double_plus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_post_double_plus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_post_double_minus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_post_double_minus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_double_plus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_double_plus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_double_minus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_double_minus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_plus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_plus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_minus(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_minus\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_exclamation(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_exclamation\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_tilde(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_tilde\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_asterisk(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_asterisk\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_unary_pre_ampersand(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_unary_pre_ampersand\n");

  return true;
}/*}}}*/

bool ltg_pa_operator_binary_le_br_re_br(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_operator_binary_le_br_re_br\n");

  return true;
}/*}}}*/

bool ltg_pa_cast(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_cast\n");

  return true;
}/*}}}*/

bool ltg_pa_identifier(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  string_rb_tree_s &val_names = _this.val_names;
  ui_array_s &exp_values = _this.exp_values;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - retrieve value index -
  unsigned val_idx = val_names.get_idx_char_ptr(name_length,name_data);

  // - ERROR -
  if (val_idx == c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    cassert(0);

    //interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
    //exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_UNDECLARED_VARIABLE,0,(location_s *)it.blank_location);
    //new_exception->params.push(lse.terminal_start);

    return false;
  }

  // - push value to expression stack -
  exp_values.push(val_idx);

  return true;
}/*}}}*/

bool ltg_pa_conditional_expression(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_conditional_expression\n");

  return true;
}/*}}}*/

bool ltg_pa_conditional_condition(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_conditional_condition\n");

  return true;
}/*}}}*/

bool ltg_pa_conditional_true(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_conditional_true\n");

  return true;
}/*}}}*/

bool ltg_pa_function_call(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_function_call\n");

  return true;
}/*}}}*/

bool ltg_pa_parameters_begin(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_parameters_begin\n");

  return true;
}/*}}}*/

bool ltg_pa_parameter(ltg_parser_s &_this)
{/*{{{*/
  fprintf(stderr,"ltg_pa_parameter\n");

  return true;
}/*}}}*/

bool ltg_pa_const_char(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  int const_char = source_string.data[lalr_stack.last().terminal_start + 1];

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_u8,0,c_val_modifier_constant);
  val_record.value = const_char;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_octal_char(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned char_num_end = (lse.terminal_end - lse.terminal_start) - 1;
  char *char_num_data = source_string.data + lse.terminal_start;

  // - retrieve char number -
  char_num_data[char_num_end] = '\0';
  int const_char = strtol(char_num_data + 2,NULL,8);
  char_num_data[char_num_end] = '\'';

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_u8,0,c_val_modifier_constant);
  val_record.value = const_char;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_hex_char(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned char_num_end = (lse.terminal_end - lse.terminal_start) - 1;
  char *char_num_data = source_string.data + lse.terminal_start;

  // - retrieve char number -
  char_num_data[char_num_end] = '\0';
  int const_char = strtol(char_num_data + 3,NULL,16);
  char_num_data[char_num_end] = '\'';

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_u8,0,c_val_modifier_constant);
  val_record.value = const_char;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_backslash_char(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_u8,0,c_val_modifier_constant);
  val_record.value = const_char;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_oct_i32(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_i32,0,c_val_modifier_constant);
  val_record.value = const_int;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_dec_i32(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_i32,0,c_val_modifier_constant);
  val_record.value = const_int;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_hex_i32(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_i32,0,c_val_modifier_constant);
  val_record.value = const_int;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_oct_i64(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_i64,0,c_val_modifier_constant);
  val_record.value = const_int;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_dec_i64(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_i64,0,c_val_modifier_constant);
  val_record.value = const_int;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_hex_i64(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_i64,0,c_val_modifier_constant);
  val_record.value = const_int;
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_f32(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_f32,0,c_val_modifier_constant);
  val_record.value = *((basic_64b *)&const_float);
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

bool ltg_pa_const_f64(ltg_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  val_records_s &val_records = _this.val_records;
  ui_array_s &exp_values = _this.exp_values;
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

  // - create constant value -
  val_records.push_blank();

  val_record_s &val_record = val_records.last();
  val_record.type.set(c_val_type_f64,0,c_val_modifier_constant);
  val_record.value = *((basic_64b *)&const_float);
  val_record.live_start = c_idx_not_exist;

  // - push value to expression stack -
  exp_values.push(val_records.used - 1);

  return true;
}/*}}}*/

