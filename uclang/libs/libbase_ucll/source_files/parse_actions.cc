
@begin
include "script_parser.h"
@end

/*
 * constants and definitions
 */

const unsigned max_number_string_length = 12;

// - callers of parse action functions -
const unsigned c_script_parse_action_cnt = 189;
bool(*script_pa_callers[c_script_parse_action_cnt])(string_s &source_string,script_parser_s &_this) =
{/*{{{*/

  pa_null,
  pa_null,
  pa_null,
  pa_null,

  pa_null,
  pa_null,
  pa_import,

  pa_null,
  pa_null,
  pa_namespace_def_end,
  pa_namespace_def_name,
  pa_namespace_using_end,
  pa_namespace_using_name,
  pa_null,
  pa_null,
  pa_null,
  pa_namespace_identifier,
  pa_namespace_identifier_arrow,
  pa_null,

  pa_modifier_public,
  pa_modifier_private,
  pa_modifier_static,
  pa_modifier_abstract,
  pa_modifier_final,
  pa_modifier_parallel,

  pa_null,
  pa_null,

  pa_class_def_end,

  pa_class_name,

  pa_class_extends,
  pa_null,

  pa_null,
  pa_null,

  pa_null,
  pa_null,

  pa_null,
  pa_null,
  pa_null,

  pa_element_name,
  pa_init_expression,
  pa_operator_binary_equal,
  pa_element_name_pa_identifier,

  pa_method_def_end,
  pa_method_name,

  pa_method_parameters_done,
  pa_method_parameters_done,

  pa_null,
  pa_null,

  pa_method_parameter,
  pa_method_reference_parameter,
  pa_method_body_semicolon,
  pa_method_body_empty,

  pa_null,

  pa_method_body_begin,

  pa_command_join,
  pa_null,

  pa_null,

  pa_blank_command_block,
  pa_null,
  pa_null,

  pa_null,
  pa_try_catch_done,
  pa_try_begin,
  pa_catch_begin,

  pa_null,
  pa_if_statement,
  pa_if_else_statement,

  pa_while_statement,
  pa_while_begin,

  pa_do_while_statement,
  pa_do_while_begin,

  pa_for_statement,
  pa_for_expression,
  pa_identifier,
  pa_for_begin,

  pa_switch_statement,
  pa_switch_expression,
  pa_null,
  pa_null,
  pa_switch_item,
  pa_switch_item_begin,
  pa_switch_item_begin,
  pa_null,
  pa_null,

  pa_break,

  pa_continue,

  pa_return,

  pa_null,

  pa_elements_array,

  pa_null,
  pa_null,

  pa_array_elements_begin,

  pa_array_element,
  pa_array_element,

  pa_condition,
  pa_expression,

  pa_null,

  pa_operator_binary_equal,
  pa_operator_binary_plus_equal,
  pa_operator_binary_minus_equal,
  pa_operator_binary_asterisk_equal,
  pa_operator_binary_slash_equal,
  pa_operator_binary_percent_equal,
  pa_operator_binary_double_ls_br_equal,
  pa_operator_binary_double_rs_br_equal,
  pa_operator_binary_ampersand_equal,
  pa_operator_binary_pipe_equal,
  pa_operator_binary_circumflex_equal,
  pa_null,

  pa_operator_binary_double_ampersand,
  pa_operator_binary_double_pipe,
  pa_null,

  pa_operator_binary_double_equal,
  pa_operator_binary_exclamation_equal,
  pa_operator_binary_rs_br,
  pa_operator_binary_ls_br,
  pa_operator_binary_rs_br_equal,
  pa_operator_binary_ls_br_equal,

  pa_presence_test,
  pa_null,

  pa_operator_binary_ampersand,
  pa_operator_binary_pipe,
  pa_operator_binary_circumflex,
  pa_null,

  pa_operator_binary_double_rs_br,
  pa_operator_binary_double_ls_br,
  pa_null,

  pa_operator_binary_plus,
  pa_operator_binary_minus,
  pa_null,

  pa_operator_binary_asterisk,
  pa_operator_binary_slash,
  pa_operator_binary_percent,

  pa_null,
  pa_operator_unary_post_double_plus,
  pa_operator_unary_post_double_minus,
  pa_operator_unary_pre_double_plus,
  pa_operator_unary_pre_double_minus,
  pa_operator_unary_pre_plus,
  pa_operator_unary_pre_minus,
  pa_operator_unary_pre_exclamation,
  pa_operator_unary_pre_tilde,

  pa_null,
  pa_operator_binary_le_br_re_br,

  pa_slice_range,
  pa_slice_blank_value,
  pa_null,
  pa_null,
  pa_null,
  pa_slice_blank_value,

  pa_null,

  pa_identifier,

  pa_this_access,

  pa_new_object,
  pa_new_objects_array,
  pa_null,

  pa_free_object,

  pa_type_identification,
  pa_convert_to_string,
  pa_object_reference_copy,

  pa_conditional_expression,
  pa_logical_and,
  pa_logical_or,

  pa_null,
  pa_class_access,
  pa_object_member_select,

  pa_this_method_call,
  pa_object_method_call,

  pa_null,
  pa_null,

  pa_parameters_begin,

  pa_parameter,
  pa_parameter,

  pa_object_member_name,

  pa_lambda_end,
  pa_lambda_begin,
  pa_lambda_parameters,

  pa_const_char,
  pa_const_octal_char,
  pa_const_hex_char,
  pa_const_backslash_char,

  pa_const_oct_int,
  pa_const_dec_int,
  pa_const_hex_int,

  pa_const_float,

  pa_const_string_register,
  pa_const_string_append,
  pa_null,
  pa_const_string,
};/*}}}*/

/*
 * parse action macros
 */

// -- PA_NAMESPACE_LIST --
#define PA_NAMESPACE_LIST() \
{/*{{{*/\
\
  /* - process namespace names - */\
  unsigned *nni_ptr = namespace_name_idxs.data;\
  unsigned *nni_ptr_end = nni_ptr + namespace_name_idxs.used;\
  do {\
    \
    /* - retrieve namespace in parent namespace - */\
    namespace_ri = _this.get_parent_namespace_namespace_idx_by_name_idx(*nni_ptr,parent_namespace_ri);\
\
    /* - if namespace does not exist - */\
    if (namespace_ri == c_idx_not_exist)\
    {\
      /* - create new namespace record - */\
      namespace_records.push_blank();\
      namespace_ri = namespace_records.used - 1;\
      namespace_record_s &namespace_record = namespace_records.last();\
\
      /* - setting of variables describing namespace - */\
      namespace_record.name_idx = *nni_ptr;\
\
      /* - store namespace index to parent namespace - */\
      namespace_records[parent_namespace_ri].namespace_record_idxs.push(namespace_ri);\
    }\
\
    /* - set parent namespace index for next iteration - */\
    parent_namespace_ri = namespace_ri;\
\
  } while((nni_ptr += 2) < nni_ptr_end);\
\
  /* - remove namespace names - */\
  namespace_name_idxs.used = 0;\
}/*}}}*/

// -- PA_ELEMENT_NAME --
#define PA_ELEMENT_NAME(LALR_STACK_POSITION) \
  /*{{{*/\
  lalr_stack_element_s &lse = LALR_STACK_POSITION;\
  unsigned name_length = lse.terminal_end - lse.terminal_start;\
  char *name_data = source_string.data + lse.terminal_start;\
  \
  /* - get position of variable name - */\
  unsigned name_idx = _this.variable_symbol_names.get_idx_char_ptr_insert(name_length,name_data);\
  \
  unsigned parent_class_idx = parent_class_idxs.last();\
  class_record_s &class_record = class_records[parent_class_idx];\
  ui_array_s &class_vr_idxs = class_record.variable_record_idxs;\
  \
  unsigned *vri_ptr = class_vr_idxs.data;\
  unsigned *vri_ptr_end = vri_ptr + class_vr_idxs.used;\
  \
  if (vri_ptr < vri_ptr_end) {\
    \
    /* - test variable name uniqueness in class - */\
    do {\
      \
      /* - PARSE ERROR - */\
      if (variable_records[*vri_ptr].name_idx == name_idx) {\
        _this.error_code.push(ei_duplicate_class_element_name);\
        _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));\
        _this.error_code.push(parent_class_idx);\
        _this.error_code.push(name_idx);\
        \
        break;\
      }\
    } while(++vri_ptr < vri_ptr_end);\
  }\
  \
  /* - creation of new variable record - */\
  variable_records.push_blank();\
  variable_record_s &variable_record = variable_records.last();\
  variable_record.name_idx = name_idx;\
  \
  /* - default private modifier - */\
  if (!(_this.modifiers & c_modifier_public)) {\
    _this.modifiers |= c_modifier_private;\
  }\
  \
  /* - PARSE ERROR modifiers - */\
  if (_this.modifiers & c_variable_ilegal_modifiers) {\
    _this.error_code.push(ei_variable_ilegall_modifier);\
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));\
    _this.error_code.push(variable_records.used - 1);\
    _this.error_code.push(parent_class_idx);\
  }\
  \
  /* - PARSE ERROR modifiers - */\
  if (((_this.modifiers & c_modifier_public) && (_this.modifiers & c_modifier_private))) {\
    _this.error_code.push(ei_variable_modifier_private_and_public);\
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));\
  }\
  \
  variable_record.modifiers = _this.modifiers;\
  variable_record.parent_record = parent_class_idx;\
  variable_record.init_expression_idx = c_idx_not_exist;\
  \
  name_pos_s &name_position = variable_record.name_position;\
  name_position.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);\
  name_position.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);\
  \
  /* - insert record index to class variable - */\
  class_vr_idxs.push(variable_records.used - 1);\
  \
  /* - initialization of modifiers - */\
  _this.modifiers = 0;\
  /*}}}*/

// -- PA_OPERATOR_UNARY --
#define PA_OPERATOR_UNARY(OP_NAME) \
  {/*{{{*/\
    /* - store node position - */\
    unsigned tmp_node_idx = ed.tmp_expression.used;\
    idx_size_s &exp_info = ed.tmp_exp_info.pop();\
    \
    /* - store node to expression - */\
    ed.tmp_expression.push(c_node_type_ ## OP_NAME);\
    ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));\
    ed.tmp_expression.push(exp_info.ui_first);\
    \
    /* - create expression info node - */\
    ed.tmp_exp_info.push_blank();\
    idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();\
    \
    tmp_exp_info.ui_first = tmp_node_idx;\
    tmp_exp_info.ui_second = exp_info.ui_second + 3;\
  }/*}}}*/

// -- PA_OPERATOR_BINARY --
#define PA_OPERATOR_BINARY(OP_NAME) \
  {/*{{{*/\
    /* - store node position - */\
    unsigned tmp_node_idx = ed.tmp_expression.used;\
    idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 2;\
    \
    /* - insertion of node to expression - */\
    ed.tmp_expression.push(c_node_type_ ## OP_NAME);\
    ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));\
    ed.tmp_expression.push(tei_ptr[0].ui_first);\
    ed.tmp_expression.push(tei_ptr[1].ui_first);\
    \
    /* - remove old nodes from stack - */\
    ed.tmp_exp_info.used -= 2;\
    \
    /* - create expression info node - */\
    ed.tmp_exp_info.push_blank();\
    idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();\
    \
    tmp_exp_info.ui_first = tmp_node_idx;\
    tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second + 4;\
  }/*}}}*/

// -- PA_COMMAND_JOIN --
#define PA_COMMAND_JOIN() \
  {/*{{{*/\
    /* - process top of thread stack - */\
    switch (fgd.fgts_type.pop()) {\
      \
      /* - FGTS_BLANK - */\
    case c_fgts_type_blank:\
      switch (fgd.fgts_type.last()) {\
      case c_fgts_type_blank:\
        break;\
      case c_fgts_type_thread:\
        break;\
      default:\
        debug_assert(0);\
      }\
      break;\
      \
      /* - FGTS_THREAD - */\
    case c_fgts_type_thread:\
      switch (fgd.fgts_type.last()) {\
      case c_fgts_type_blank:\
        fgd.fgts_type.last() = c_fgts_type_thread;\
        break;\
      case c_fgts_type_thread:\
      {\
        unsigned second_end_cnt = fgd.fgts_cnt.pop();\
        unsigned first_end_cnt = fgd.fgts_cnt.last();\
        unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (2 + first_end_cnt + second_end_cnt);\
        \
        if (first_end_cnt != 0) {\
          \
          if (ts_ptr[first_end_cnt + 1] >= c_fgts_bc_value_base) {\
            \
            /* - store ends of first thread a special begins - */\
            unsigned *tse_ptr = ts_ptr + 1;\
            unsigned *tse_ptr_end = tse_ptr + first_end_cnt;\
            ui_array_s &bc_ends = fgd.fgts_bc_ends_array.last()[ts_ptr[first_end_cnt + 1] - c_fgts_bc_value_base];\
            \
            do {\
              bc_ends.push(*tse_ptr);\
            } while(++tse_ptr < tse_ptr_end);\
          }\
          else {\
            \
            /* - attaching ends of first thread to begin of second - */\
            unsigned *tse_ptr = ts_ptr + 1;\
            unsigned *tse_ptr_end = tse_ptr + first_end_cnt;\
            unsigned second_begin = ts_ptr[first_end_cnt + 1];\
            \
            do {\
              tmp_flow_graph[*tse_ptr] = second_begin;\
            } while(++tse_ptr < tse_ptr_end);\
          }\
        }\
        \
        if (second_end_cnt != 0) {\
          \
          /* - setting ends of second thread as ends of new thread - */\
          unsigned *tse_ptr = ts_ptr + 1;\
          unsigned *tse_ptr_end = tse_ptr + second_end_cnt;\
          unsigned offset = first_end_cnt + 1;\
          \
          do {\
            *tse_ptr = tse_ptr[offset];\
          } while(++tse_ptr < tse_ptr_end);\
        }\
        \
        fgd.fg_thread_stack.used -= first_end_cnt + 1;\
        fgd.fgts_cnt.last() = second_end_cnt;\
      }\
      break;\
      default:\
        debug_assert(0);\
      }\
      break;\
      \
    default:\
      debug_assert(0);\
    }\
  }/*}}}*/

// -- PA_IDENTIFIER --
#define PA_IDENTIFIER(INSTRUCTION,NAME_IDX,CODE_POS) \
  {/*{{{*/\
    /* - store node position- */\
    unsigned tmp_node_idx = ed.tmp_expression.used;\
    \
    /* - store node to expression - */\
    ed.tmp_expression.push(INSTRUCTION);\
    ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,CODE_POS));\
    ed.tmp_expression.push(NAME_IDX);\
    \
    /* - create expression info node - */\
    ed.tmp_exp_info.push_blank();\
    idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();\
    \
    tmp_exp_info.ui_first = tmp_node_idx;\
    tmp_exp_info.ui_second = 3;\
  }/*}}}*/

// -- PA_EXPRESSION --
#define PA_EXPRESSION() \
  {/*{{{*/\
    /* - test if expression stack contain exactly one node - */\
    debug_assert(ed.tmp_exp_info.used == 1);\
    \
    /* - creation of description of flow graph node - */\
    fgd.fgts_type.push(c_fgts_type_thread);\
    fgd.fgts_cnt.push(1);\
    fgd.fg_thread_stack.push(tmp_flow_graph.used);\
    fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_expression_first_out);\
    \
    /* - creation of flow graph node - */\
    tmp_flow_graph.push(c_fg_type_expression);\
    tmp_flow_graph.push(tmp_expressions.used);\
    tmp_flow_graph.push(c_idx_not_exist);\
    \
    /* - insertion of expression to expression list - */\
    tmp_expressions.push_blank();\
    expression_s &expression = tmp_expressions.last();\
    \
    expression.start_node_idx = ed.tmp_exp_info.pop().ui_first;\
    expression.nodes.swap(ed.tmp_expression);\
    \
    debug_assert(ed.tmp_expression.used == 0);\
    debug_assert(ed.tmp_exp_info.used == 0);\
  }/*}}}*/

// -- PA_OBJECT_METHOD_CALL --
#define PA_OBJECT_METHOD_CALL(NAME_IDX,PARAM_CNT,CODE_POS) \
  {/*{{{*/\
    /* - position of created expression node - */\
    unsigned tmp_node_idx = ed.tmp_expression.used;\
    \
    ed.tmp_expression.push(c_node_type_object_method_call);\
    ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,CODE_POS));\
    ed.tmp_expression.push(NAME_IDX);\
    ed.tmp_expression.push(PARAM_CNT);\
    \
    idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - (PARAM_CNT + 1);\
    idx_size_s *tei_ptr_end = ed.tmp_exp_info.data + ed.tmp_exp_info.used;\
    \
    unsigned exp_size = 4;\
    \
    do {\
      ed.tmp_expression.push(tei_ptr->ui_first);\
      exp_size += 1 + tei_ptr->ui_second;\
    } while(++tei_ptr < tei_ptr_end);\
    \
    ed.tmp_exp_info.used -= PARAM_CNT + 1;\
    \
    /* - create expression info node - */\
    ed.tmp_exp_info.push_blank();\
    idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();\
    \
    tmp_exp_info.ui_first = tmp_node_idx;\
    tmp_exp_info.ui_second = exp_size;\
  }/*}}}*/

/*
 * functions implementing parse actions of parser
 */

bool pa_null(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  debug_assert(0);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_null\n"));

  return true;
}/*}}}*/

bool pa_import(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  string_array_s &module_names = _this.module_names;
  name_pos_array_s &module_names_positions = _this.module_names_positions;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get position of module name -
  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - insert module name to module names array -
  unsigned name_idx = module_names.get_idx_char_ptr(name_length,name_data);
  if (name_idx == c_idx_not_exist)
  {
    module_names.push_blank();
    module_names.last().set(name_length,name_data);

    // - set module import name position -
    module_names_positions.push_blank();
    name_pos_s &name_pos = module_names_positions.last();

    name_pos.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);
    name_pos.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);
  }

  return true;
}/*}}}*/

bool pa_namespace_def_end(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &parent_namespace_idxs = _this.parent_namespace_idxs;
  ui_array_s &using_namespace_idxs = _this.using_namespace_idxs;

  // *****

  // - remove namespace index from parent namespace stack -
  parent_namespace_idxs.used--;

  // - remove namespace index from using namespace stack -
  using_namespace_idxs.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_namespace_def_end\n"));

  return true;
}/*}}}*/

bool pa_namespace_def_name(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  namespace_records_s &namespace_records = _this.namespace_records;
  ui_array_s &namespace_name_idxs = _this.namespace_name_idxs;
  ui_array_s &parent_namespace_idxs = _this.parent_namespace_idxs;
  ui_array_s &using_namespace_idxs = _this.using_namespace_idxs;

  // *****

  // - retrieve parent namespace -
  unsigned parent_namespace_ri = parent_namespace_idxs.last();
  unsigned namespace_ri;

  PA_NAMESPACE_LIST();

  // - push namespace record index to parent namespace stack -
  parent_namespace_idxs.push(namespace_ri);

  // - push namespace record index to using namespace stack -
  using_namespace_idxs.push(namespace_ri);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_namespace_def_name\n"));

  return true;
}/*}}}*/

bool pa_namespace_using_end(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &using_namespace_idxs = _this.using_namespace_idxs;

  // *****

  // - remove namespace index from using namespace stack -
  using_namespace_idxs.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_namespace_using_end\n"));

  return true;
}/*}}}*/

bool pa_namespace_using_name(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  namespace_records_s &namespace_records = _this.namespace_records;
  ui_array_s &namespace_name_idxs = _this.namespace_name_idxs;
  ui_array_s &using_namespace_idxs = _this.using_namespace_idxs;

  // *****

  // - search from global namespace -
  unsigned parent_namespace_ri = 0;
  unsigned namespace_ri;

  PA_NAMESPACE_LIST();

  // - push namespace record index to using namespace stack -
  using_namespace_idxs.push(namespace_ri);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_namespace_using_name\n"));

  return true;
}/*}}}*/

bool pa_namespace_identifier(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &namespace_name_idxs = _this.namespace_name_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get position of namespace name -
  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of namespace name -
  unsigned name_idx = _this.class_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - store namespace name index and position -
  namespace_name_idxs.push(name_idx);
  namespace_name_idxs.push(lse.terminal_start);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_namespace_identifier: %s\n",_this.class_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_namespace_identifier_arrow(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &namespace_name_idxs = _this.namespace_name_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get position of namespace name -
  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of namespace name -
  unsigned name_idx = _this.class_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - store namespace name index and position -
  namespace_name_idxs.push(name_idx);
  namespace_name_idxs.push(lse.terminal_start);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_namespace_identifier_arrow: %s\n",_this.class_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_modifier_public(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  // - modification of modifier -
  _this.modifiers |= c_modifier_public;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_modifier_public\n"));

  return true;
}/*}}}*/

bool pa_modifier_private(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  // - modification of modifier -
  _this.modifiers |= c_modifier_private;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_modifier_private\n"));

  return true;
}/*}}}*/

bool pa_modifier_static(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  // - modification of modifier -
  _this.modifiers |= c_modifier_static;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_modifier_static\n"));

  return true;
}/*}}}*/

bool pa_modifier_abstract(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  // - modification of modifier -
  _this.modifiers |= c_modifier_abstract;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_modifier_abstract\n"));

  return true;
}/*}}}*/

bool pa_modifier_final(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  // - modification of modifier -
  _this.modifiers |= c_modifier_final;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_modifier_final\n"));

  return true;
}/*}}}*/

bool pa_modifier_parallel(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  // - modification of modifier -
  _this.modifiers |= c_modifier_parallel;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_modifier_parallel\n"));

  return true;
}/*}}}*/

bool pa_class_def_end(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;

  // *****

  // - remove class index from parent class stack -
  parent_class_idxs.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_class_def_end\n"));

  return true;
}/*}}}*/

bool pa_class_name(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  namespace_records_s &namespace_records = _this.namespace_records;
  class_records_s &class_records = _this.class_records;
  ui_array_s &parent_namespace_idxs = _this.parent_namespace_idxs;
  ui_array_s &using_namespace_idxs = _this.using_namespace_idxs;
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get position of class name -
  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of class name -
  unsigned name_idx = _this.class_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - test uniqueness of class name -
  unsigned parent_class_idx = parent_class_idxs.used != 0 ? parent_class_idxs.last() : c_idx_not_exist;
  unsigned class_record_idx = _this.get_nested_enclosing_class_idx_by_name_idx(name_idx,parent_class_idx);

  // - PARSE ERROR -
  if (class_record_idx != c_idx_not_exist)
  {
    _this.error_code.push(ei_duplicate_class_name);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
    _this.error_code.push(parent_class_idx);
    _this.error_code.push(name_idx);
  }

  // - creation of new class record -
  class_records.push_blank();
  class_record_idx = class_records.used - 1;
  class_record_s &class_record = class_records[class_record_idx];

  // - setting of class parameters -
  class_record.name_idx = name_idx;

  // - PARSE ERROR -
  if (_this.modifiers & c_class_ilegal_modifiers)
  {
    _this.error_code.push(ei_class_ilegall_modifier);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
    _this.error_code.push(class_record_idx);
    _this.error_code.push(parent_class_idx);
  }

  // - PARSE ERROR test of disallowed modifier combinations  -
  if ((_this.modifiers & c_modifier_abstract) && (_this.modifiers & c_modifier_final))
  {
    _this.error_code.push(ei_class_modifier_abstract_and_final);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
  }

  class_record.modifiers = _this.modifiers;
  class_record.parent_record = parent_class_idx;
  class_record.extend_class_idx = c_idx_not_exist;

  // - save class using namespaces -
  class_record.using_namespace_idxs = using_namespace_idxs;

  // - save class name position in code -
  name_pos_s &name_position = class_record.name_position;
  name_position.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);
  name_position.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);

  // - store new class record index in parent class record -
  if (parent_class_idx != c_idx_not_exist)
  {
    class_records[parent_class_idx].class_record_idxs.push(class_record_idx);
  }
  else
  {
    unsigned parent_namespace_ri = parent_namespace_idxs.last();

    // - store index to parent namespace -
    namespace_records[parent_namespace_ri].class_record_idxs.push(class_record_idx);
  }

  // - push class record index to parent class stack -
  parent_class_idxs.push(class_record_idx);

  // - initialization of modifiers -
  _this.modifiers = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_class_name: %s\n",_this.class_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_class_extends(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  ui_array_s &namespace_name_idxs = _this.namespace_name_idxs;
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;
  ui_array_s &extending_idxs = _this.extending_idxs;

  // *****

  // - get record index of extending class -
  unsigned extending_class_idx = parent_class_idxs.last();

  // - store extended class identification -
  class_records[extending_class_idx].extend_array.swap(namespace_name_idxs);

  // - store information of extended class to extending class -
  extending_idxs.push(extending_class_idx);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_class_extends\n"));

  return true;
}/*}}}*/

bool pa_element_name(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  variable_records_s &variable_records = _this.variable_records;
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  PA_ELEMENT_NAME(lalr_stack[lalr_stack.used - 2]);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_element_name: %s\n",_this.variable_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_init_expression(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  variable_records_s &variable_records = _this.variable_records;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  expressions_s &init_expressions = _this.init_expressions;

  // *****

  // - store index of initialization expression to variable -
  variable_records.last().init_expression_idx = init_expressions.used;

  // - creation of new initialization expression -
  init_expressions.push_blank();
  expression_s &expression = init_expressions.last();

  // - copy (swap) of parsed expression -
  expression.start_node_idx = ed.tmp_exp_info.pop().ui_first;
  expression.nodes.swap(ed.tmp_expression);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_init_expression\n"));

  return true;
}/*}}}*/

bool pa_element_name_pa_identifier(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  variable_records_s &variable_records = _this.variable_records;
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  PA_ELEMENT_NAME(lalr_stack.last());

  PA_IDENTIFIER(c_node_type_element_identifier,name_idx,_this.old_input_idx);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_element_name_pa_identifier: %s\n",_this.variable_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_method_def_end(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;

  code_descrs_s &code_descrs = _this.code_descrs;
  code_descr_s &code_descr = code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  exp_flow_graphs_s &method_flow_graphs = _this.method_flow_graphs;

  // *****

  // - test if thread was created on stack of graph flow -
  debug_assert(fgd.fgts_type.used > 0);

  // - if method body contains no code -
  if (fgd.fgts_type.last() == c_fgts_type_blank)
  {
    fgd.fgts_type.pop();
    pa_method_body_empty(source_string,_this);
  }

  unsigned *ts_ptr = fgd.fg_thread_stack.data;
  debug_assert(*ts_ptr < c_fgts_bc_value_base);

  // - setting flow graph index in method -
  method_record_s &method_record = method_records[parent_method_idxs.last()];
  method_record.flow_graph_idx = method_flow_graphs.used;

  // - copy (swap) parsed flow graph -
  method_flow_graphs.push_blank();
  exp_flow_graph_s &method_flow_graph = method_flow_graphs.last();

  method_flow_graph.start_node_idx = *ts_ptr;
  method_flow_graph.nodes.swap(tmp_flow_graph);
  method_flow_graph.expressions.swap(tmp_expressions);

  // - remove temporary data -
  fgd.fg_thread_stack.used = 0;
  fgd.fgts_cnt.used = 0;

  // - remove method index from parent method stack -
  parent_method_idxs.used--;

  debug_assert(tmp_flow_graph.used == 0);
  debug_assert(tmp_expressions.used == 0);
  debug_assert(fgd.fg_thread_stack.used == 0);
  debug_assert(fgd.fgts_cnt.used == 0);

  // - remove code description -
  code_descrs.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_def_end\n"));

  return true;
}/*}}}*/

bool pa_method_name(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  method_records_s &method_records = _this.method_records;
  unsigned &modifiers = _this.modifiers;
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  name_pos_array_s &tmp_name_pos_array = _this.tmp_name_pos_array;
  code_descrs_s &code_descrs = _this.code_descrs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get method name position -
  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];
  tmp_name_pos_array.push_blank();
  tmp_name_pos_array.last().set(lse.terminal_start,lse.terminal_end);

  // - get index of parent class -
  unsigned parent_class_idx = parent_class_idxs.last();
  class_record_s &class_record = class_records[parent_class_idx];

  // - creation of new method record -
  method_records.push_blank();
  unsigned method_record_idx = method_records.used - 1;
  method_record_s &method_record = method_records.last();

  // - setting of variables describing method -
  method_record.name_idx = c_idx_not_exist;

  // - default modifier private -
  if (!(modifiers & c_modifier_public))
  {
    modifiers |= c_modifier_private;
  }

  // - PARSE ERROR -
  if (((modifiers & c_modifier_public) && (modifiers & c_modifier_private)))
  {
    _this.error_code.push(ei_method_modifier_private_and_public);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
  }

  // - PARSE ERROR -
  if ((modifiers & c_modifier_abstract) && ((modifiers & c_modifier_static) || (modifiers & c_modifier_final)))
  {
    _this.error_code.push(ei_method_modifier_abstract_and_static_or_final);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
  }

  // - PARSE ERROR -
  if ((modifiers & c_modifier_parallel) && !(modifiers & c_modifier_static))
  {
    _this.error_code.push(ei_method_modifier_parallel_must_be_static);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
  }

  // - if method is defined as abstract, then parent class must be abstract too -
  if (modifiers & c_modifier_abstract)
  {
    // - PARSE ERROR -
    if (!(class_record.modifiers & c_modifier_abstract))
    {
      _this.error_code.push(ei_abstract_method_no_abstract_class);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
      _this.error_code.push(method_record_idx);
      _this.error_code.push(parent_class_idx);
    }
  }

  method_record.modifiers = modifiers;
  method_record.parent_record = parent_class_idx;
  method_record.flow_graph_idx = c_idx_not_exist;

  // - store position of method name in code -
  name_pos_s &name_position = method_record.name_position;
  name_position.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);
  name_position.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);

  // - store method index to parent class -
  class_record.method_record_idxs.push(method_record_idx);

  // - push method record index to parent method stack -
  parent_method_idxs.push(method_record_idx);

  // - initialization of modifier -
  modifiers = 0;

  // - initialize code description -
  code_descrs.push_blank();

  debug_message_4(
    char tmp_char = source_string[lse.terminal_end];
    source_string[lse.terminal_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_method_name: %s\n",source_string.data + lse.terminal_start);
    source_string[lse.terminal_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_method_parameters_done(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_class_idxs = _this.parent_class_idxs;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  name_pos_s &tmp_name_pos = _this.tmp_name_pos_array.pop();

  // *****

  class_record_s &parent_record = class_records[parent_class_idxs.last()];

  method_record_s &method_record = method_records[parent_method_idxs.last()];
  unsigned m_parameter_cnt = method_record.parameter_record_idxs.used;

  // - creation of space for method name -
  unsigned method_name_max_length = (tmp_name_pos.ui_second - tmp_name_pos.ui_first) + max_number_string_length;

  string_s name_string;
  name_string.data = (char *)cmalloc(method_name_max_length);

  // - creation of complete method name -
  char tmp_char = source_string[tmp_name_pos.ui_second];
  source_string[tmp_name_pos.ui_second] = '\0';

  name_string.size = 1 + snprintf(name_string.data,method_name_max_length,"%s#%u",source_string.data + tmp_name_pos.ui_first,m_parameter_cnt);

  // - test if method is class constructor -
  if (strcmp(source_string.data + tmp_name_pos.ui_first,_this.class_symbol_names[parent_record.name_idx].data) == 0)
  {
    // - ERROR test constructor ilegal modifiers -
    if (method_record.modifiers & c_constr_ilegal_modifiers)
    {
      _this.error_code.push(ei_constructor_ilegall_modifier);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,tmp_name_pos.ui_first));
    }
  }

  source_string[tmp_name_pos.ui_second] = tmp_char;

  // - get index of method name -
  unsigned name_idx = _this.get_method_name_idx_swap(name_string);
  name_string.clear();

  // - test uniqueness of method in parent class -
  ui_array_s &class_mr_idxs = parent_record.method_record_idxs;

  if (class_mr_idxs.used != 0)
  {
    unsigned *mri_ptr = class_mr_idxs.data;
    unsigned *mri_ptr_end = mri_ptr + class_mr_idxs.used;

    do
    {
      // - PARSE ERROR -
      if (method_records[*mri_ptr].name_idx == name_idx)
      {
        _this.error_code.push(ei_duplicate_class_method_name);
        _this.error_code.push(SET_SRC_POS(_this.source_idx,tmp_name_pos.ui_first));
        _this.error_code.push(parent_class_idxs.last());
        _this.error_code.push(name_idx);
      }
    }
    while(++mri_ptr < mri_ptr_end);
  }

  // - setting method name index -
  method_record.name_idx = name_idx;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_parameters_done: name: %s\n",_this.method_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_method_parameter(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  variable_records_s &variable_records = _this.variable_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get position of method parameter name -
  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of method parameter name -
  unsigned name_idx = _this.variable_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - get parameter parent method -
  method_record_s &method_record = method_records[parent_method_idxs.last()];

  // - test method parameter uniqueness -
  ui_array_s &method_pr_idxs = method_record.parameter_record_idxs;
  if (method_pr_idxs.used != 0)
  {
    unsigned *mpri_ptr = method_pr_idxs.data;
    unsigned *mpri_ptr_end = mpri_ptr + method_pr_idxs.used;

    do
    {
      // - PARSE ERROR -
      if (variable_records[*mpri_ptr].name_idx == name_idx)
      {
        _this.error_code.push(ei_duplicate_method_parameter);
        _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
        _this.error_code.push(name_idx);
      }
    }
    while(++mpri_ptr < mpri_ptr_end);
  }

  // - creation of parameter description -
  variable_records.push_blank();
  variable_record_s &variable_record = variable_records.last();
  variable_record.name_idx = name_idx;
  variable_record.modifiers = c_variable_modifier_blank;
  variable_record.parent_record = method_records.used - 1;
  variable_record.init_expression_idx = c_idx_not_exist;

  name_pos_s &name_position = variable_record.name_position;
  name_position.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);
  name_position.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);

  // - store index of parameter record to method record -
  method_pr_idxs.push(variable_records.used - 1);

  // - initialization of modifiers -
  _this.modifiers = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_parameter: %s\n",_this.variable_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_method_reference_parameter(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  variable_records_s &variable_records = _this.variable_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get position of method parameter name -
  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of method parameter name -
  unsigned name_idx = _this.variable_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - get parent method -
  method_record_s &method_record = method_records[parent_method_idxs.last()];

  // - test uniqueness of method parameter name in parent method -
  ui_array_s &method_pr_idxs = method_record.parameter_record_idxs;
  if (method_pr_idxs.used != 0)
  {
    unsigned *mpri_ptr = method_pr_idxs.data;
    unsigned *mpri_ptr_end = mpri_ptr + method_pr_idxs.used;

    do
    {
      // - PARSE ERROR -
      if (variable_records[*mpri_ptr].name_idx == name_idx)
      {
        _this.error_code.push(ei_duplicate_method_parameter);
        _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
        _this.error_code.push(name_idx);
      }
    }
    while(++mpri_ptr < mpri_ptr_end);
  }

  // - creation of parameter description -
  variable_records.push_blank();

  variable_record_s &variable_record = variable_records.last();
  variable_record.name_idx = name_idx;
  variable_record.modifiers = c_variable_modifier_reference;
  variable_record.parent_record = method_records.used - 1;
  variable_record.init_expression_idx = c_idx_not_exist;

  name_pos_s &name_position = variable_record.name_position;
  name_position.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);
  name_position.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);

  // - insertion of parameter record index to parent method record -
  method_pr_idxs.push(variable_records.used - 1);

  // - initialization of modifiers -
  _this.modifiers = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_reference_parameter: %s\n",_this.variable_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_method_body_semicolon(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - test if method is defined as abstract -
  method_record_s &method_record = method_records[parent_method_idxs.last()];

  // - PARSE ERROR -
  if (!(method_record.modifiers & c_modifier_abstract))
  {
    _this.error_code.push(ei_non_abstract_method_without_body);
    _this.error_code.push(method_record.name_position.ui_first);
    _this.error_code.push(method_records.used - 1);
    _this.error_code.push(method_record.parent_record);
  }

  // - creation of blank node of program flow graph -
  fgd.fgts_type.push(c_fgts_type_blank);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_body_semicolon\n"));

  return true;
}/*}}}*/

bool pa_method_body_empty(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lli_rb_tree_s &const_ints = _this.const_ints;

  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  // - creation of expression defining constant 0 -

  // - search constant in constant array -
  unsigned ci_idx = const_ints.unique_insert(0);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_int);
  ed.tmp_expression.push(ci_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  // - creation of flow graph which contain one expression -

  // - test if expression stack contain exactly one node -
  debug_assert(ed.tmp_exp_info.used == 1);

  // - creation of flow graph node description -
  fgd.fgts_type.push(c_fgts_type_thread);
  fgd.fgts_cnt.push(1);
  fgd.fg_thread_stack.push(tmp_flow_graph.used);
  fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_expression_first_out);

  // - creation of flow graph node -
  tmp_flow_graph.push(c_fg_type_expression);
  tmp_flow_graph.push(tmp_expressions.used);
  tmp_flow_graph.push(c_idx_not_exist);

  // - insertion of expression to expression list -
  tmp_expressions.push_blank();
  expression_s &expression = tmp_expressions.last();

  expression.start_node_idx = ed.tmp_exp_info.pop().ui_first;
  expression.nodes.swap(ed.tmp_expression);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_body_empty\n"));

  return true;
}/*}}}*/

bool pa_method_body_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;

  // *****

  // - test if method is defined as abstract -
  method_record_s &method_record = method_records[parent_method_idxs.last()];

  // - PARSE ERROR -
  if (method_record.modifiers & c_modifier_abstract)
  {
    _this.error_code.push(ei_abstract_method_with_body);
    _this.error_code.push(method_record.name_position.ui_first);
    _this.error_code.push(method_records.used - 1);
    _this.error_code.push(method_record.parent_record);
  }

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_method_body_begin\n"));

  return true;
}/*}}}*/

bool pa_command_join(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  PA_COMMAND_JOIN();

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_command_join\n"));

  return true;
}/*}}}*/

bool pa_blank_command_block(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - insertion of blank flow graph thread -
  fgd.fgts_type.push(c_fgts_type_blank);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_blank_command_block\n"));

  return true;
}/*}}}*/

bool pa_try_catch_done(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  ui_array_s &try_fg_map_idxs = _this.try_fg_map_idxs;
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - join catch thread with first catch command -
  if (!pa_command_join(source_string,_this))
  {
    return false;
  }

  // - retrieve try flow graph map index -
  unsigned try_fg_map_idx = try_fg_map_idxs.last();

  // - process try and catch threads -
  switch (fgd.fgts_type.pop())
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:
    switch (fgd.fgts_type.last())
    {
    case c_fgts_type_blank:
    case c_fgts_type_thread:
    {
      method_record_s &method_record = method_records[parent_method_idxs.last()];
      method_record.try_fg_maps[try_fg_map_idx].tfgm_fg_idx = c_idx_not_exist;
    }
    break;
    default:
      debug_assert(0);
    }
    break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
    switch (fgd.fgts_type.last())
    {
    case c_fgts_type_blank:
    {
      unsigned second_end_cnt = fgd.fgts_cnt.pop();
      fgd.fg_thread_stack.used -= second_end_cnt + 1;

      method_record_s &method_record = method_records[parent_method_idxs.last()];
      method_record.try_fg_maps[try_fg_map_idx].tfgm_fg_idx = c_idx_not_exist;
    }
    break;
    case c_fgts_type_thread:
    {
      unsigned second_end_cnt = fgd.fgts_cnt.pop();
      unsigned first_end_cnt = fgd.fgts_cnt.last();
      unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (2 + first_end_cnt + second_end_cnt);

      // - should always be true -
      cassert(ts_ptr[first_end_cnt + 1] < c_fgts_bc_value_base);

      method_record_s &method_record = method_records[parent_method_idxs.last()];
      method_record.try_fg_maps[try_fg_map_idx].tfgm_fg_idx = ts_ptr[first_end_cnt + 1];

      if (second_end_cnt != 0)
      {
        // - adding ends of second thread to ends of first thread -
        unsigned *tse_ptr = ts_ptr + 1 + first_end_cnt;
        unsigned *tse_ptr_end = tse_ptr + second_end_cnt;

        do
        {
          *tse_ptr = tse_ptr[1];
        }
        while(++tse_ptr < tse_ptr_end);
      }

      fgd.fg_thread_stack.used -= 1;
      fgd.fgts_cnt.last() = first_end_cnt + second_end_cnt;
    }
    break;
    default:
      debug_assert(0);
    }
    break;

  default:
    debug_assert(0);
  }

  // - remove try flow graph map index from stack -
  try_fg_map_idxs.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_try_catch_done\n"));

  return true;
}/*}}}*/

bool pa_try_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  ui_array_s &try_fg_map_idxs = _this.try_fg_map_idxs;

  // *****

  // - create new method try_fg_map -
  method_record_s &method_record = method_records[parent_method_idxs.last()];
  method_record.try_fg_maps.push_blank();

  // - store try_fg_map index -
  try_fg_map_idxs.push(method_record.try_fg_maps.used - 1);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_try_begin\n"));

  return true;
}/*}}}*/

bool pa_catch_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  ui_array_s &try_fg_map_idxs = _this.try_fg_map_idxs;

  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;
  expression_descr_s &ed = code_descr.expression_descr;

  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get exception variable name -
  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];

  // - get position of variable name -
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of variable name -
  unsigned name_idx = _this.variable_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - retrieve try flow graph map index -
  unsigned try_fg_map_idx = try_fg_map_idxs.last();

  // - set last fg node, and variable name idx of method try_fg_map -
  method_record_s &method_record = method_records[parent_method_idxs.last()];
  try_fg_map_s &try_fg_map = method_record.try_fg_maps[try_fg_map_idx];
  try_fg_map.tfgm_last_fg_node = tmp_flow_graph.used;
  try_fg_map.tfgm_var_idx = name_idx;

  switch (fgd.fgts_type.last())
  {
    // - FGTS_BLANK -
    case c_fgts_type_blank:
    {
      // - PARSE ERROR -
      lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 4];

      _this.error_code.push(ei_empty_try_block_for_catch);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));

      return false;
    }

    // - FGTS_THREAD -
    case c_fgts_type_thread:
      try_fg_map.tfgm_first_fg_node = fgd.fg_thread_stack.data[fgd.fg_thread_stack.used - (1 + fgd.fgts_cnt.last())];
      break;
  }

  PA_IDENTIFIER(c_node_type_identifier,name_idx,lse.terminal_start);

  // - creation of flow graph node description -
  fgd.fgts_type.push(c_fgts_type_thread);
  fgd.fgts_cnt.push(1);
  fgd.fg_thread_stack.push(tmp_flow_graph.used);
  fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_expression_first_out);

  // - creation of flow graph node -
  tmp_flow_graph.push(c_fg_type_expression);
  tmp_flow_graph.push(tmp_expressions.used);
  tmp_flow_graph.push(c_idx_not_exist);

  // - insertion of expression to expression list -
  tmp_expressions.push_blank();
  expression_s &expression = tmp_expressions.last();

  expression.start_node_idx = ed.tmp_exp_info.pop().ui_first;
  expression.nodes.swap(ed.tmp_expression);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_catch_begin: exception var: %s\n",_this.variable_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_if_statement(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  switch (fgd.fgts_type.pop())
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:

    // - convert c_fg_type_condition to c_fg_type_expression -
    tmp_flow_graph.used -= 2;
    tmp_flow_graph[tmp_flow_graph.used - c_fg_expression_size] = c_fg_type_expression;

    fgd.fg_thread_stack.used--;
    fgd.fgts_cnt.last() = 1;
    break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
  {
    unsigned body_end_cnt = fgd.fgts_cnt.pop();
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (4 + body_end_cnt);

    if (ts_ptr[3] >= c_fgts_bc_value_base)
    {
      fgd.fgts_bc_ends_array.last()[ts_ptr[3] - c_fgts_bc_value_base].push(ts_ptr[1]);
    }
    else
    {
      tmp_flow_graph[ts_ptr[1]] = ts_ptr[3];
    }

    ts_ptr[1] = ts_ptr[2];

    if (body_end_cnt != 0)
    {
      unsigned *tse_ptr = ts_ptr + 2;
      unsigned *tse_ptr_end = tse_ptr + body_end_cnt;

      do
      {
        *tse_ptr = tse_ptr[2];
      }
      while(++tse_ptr < tse_ptr_end);
    }

    fgd.fg_thread_stack.used -= 2;
    fgd.fgts_cnt.last() = body_end_cnt + 1;
  }
  break;
  default:
    debug_assert(0);
  }

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_if_statement\n"));

  return true;
}/*}}}*/

bool pa_if_else_statement(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  switch (fgd.fgts_type.pop())
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:
    switch (fgd.fgts_type.pop())
    {
    case c_fgts_type_blank:

      // - convert c_fg_type_condition to c_fg_type_expression -
      tmp_flow_graph.used -= 2;
      tmp_flow_graph[tmp_flow_graph.used - c_fg_expression_size] = c_fg_type_expression;

      fgd.fg_thread_stack.used--;
      fgd.fgts_cnt.last() = 1;
      break;
    case c_fgts_type_thread:
    {
      unsigned true_end_cnt = fgd.fgts_cnt.pop();
      unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (4 + true_end_cnt);

      if (ts_ptr[3] >= c_fgts_bc_value_base)
      {
        fgd.fgts_bc_ends_array.last()[ts_ptr[3] - c_fgts_bc_value_base].push(ts_ptr[1]);
      }
      else
      {
        tmp_flow_graph[ts_ptr[1]] = ts_ptr[3];
      }

      ts_ptr[1] = ts_ptr[2];

      if (true_end_cnt != 0)
      {
        unsigned *tse_ptr = ts_ptr + 2;
        unsigned *tse_ptr_end = tse_ptr + true_end_cnt;

        do
        {
          *tse_ptr = tse_ptr[2];
        }
        while(++tse_ptr < tse_ptr_end);
      }

      fgd.fg_thread_stack.used -= 2;
      fgd.fgts_cnt.last() = true_end_cnt + 1;
    }
    break;
    default:
      debug_assert(0);
    }
    break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
    switch (fgd.fgts_type.pop())
    {
    case c_fgts_type_blank:
    {
      unsigned false_end_cnt = fgd.fgts_cnt.pop();
      unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (4 + false_end_cnt);

      if (ts_ptr[3] >= c_fgts_bc_value_base)
      {
        fgd.fgts_bc_ends_array.last()[ts_ptr[3] - c_fgts_bc_value_base].push(ts_ptr[2]);
      }
      else
      {
        tmp_flow_graph[ts_ptr[2]] = ts_ptr[3];
      }

      if (false_end_cnt != 0)
      {
        unsigned *tse_ptr = ts_ptr + 2;
        unsigned *tse_ptr_end = tse_ptr + false_end_cnt;

        do
        {
          *tse_ptr = tse_ptr[2];
        }
        while(++tse_ptr < tse_ptr_end);
      }

      fgd.fg_thread_stack.used -= 2;
      fgd.fgts_cnt.last() = false_end_cnt + 1;
    }
    break;
    case c_fgts_type_thread:
    {
      unsigned false_end_cnt = fgd.fgts_cnt.pop();
      unsigned true_end_cnt = fgd.fgts_cnt.pop();
      unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (5 + true_end_cnt + false_end_cnt);

      if (ts_ptr[3] >= c_fgts_bc_value_base)
      {
        fgd.fgts_bc_ends_array.last()[ts_ptr[3] - c_fgts_bc_value_base].push(ts_ptr[1]);
      }
      else
      {
        tmp_flow_graph[ts_ptr[1]] = ts_ptr[3];
      }

      if (ts_ptr[4 + true_end_cnt] >= c_fgts_bc_value_base)
      {
        fgd.fgts_bc_ends_array.last()[ts_ptr[4 + true_end_cnt] - c_fgts_bc_value_base].push(ts_ptr[2]);
      }
      else
      {
        tmp_flow_graph[ts_ptr[2]] = ts_ptr[4 + true_end_cnt];
      }

      if (true_end_cnt != 0)
      {
        unsigned *tse_ptr = ts_ptr + 1;
        unsigned *tse_ptr_end = tse_ptr + true_end_cnt;

        do
        {
          *tse_ptr = tse_ptr[3];
        }
        while(++tse_ptr < tse_ptr_end);
      }

      if (false_end_cnt != 0)
      {
        unsigned *tse_ptr = ts_ptr + true_end_cnt + 1;
        unsigned *tse_ptr_end = tse_ptr + false_end_cnt;

        do
        {
          *tse_ptr = tse_ptr[4];
        }
        while(++tse_ptr < tse_ptr_end);
      }

      fgd.fg_thread_stack.used -= 4;
      fgd.fgts_cnt.last() = true_end_cnt + false_end_cnt;
    }
    break;
    default:
      debug_assert(0);
    }
    break;
  default:
    debug_assert(0);
  }

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_if_else_statement\n"));

  return true;
}/*}}}*/

bool pa_while_statement(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  switch (fgd.fgts_type.pop())
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:
  {
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - 3;

    tmp_flow_graph[ts_ptr[1]] = *ts_ptr;
    ts_ptr[1] = ts_ptr[2];

    fgd.fg_thread_stack.used--;
    fgd.fgts_cnt.last() = 1;
  }
  break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
  {
    unsigned body_end_cnt = fgd.fgts_cnt.pop();
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (4 + body_end_cnt);

    // - PARSE ERROR -
    if (ts_ptr[3] >= c_fgts_bc_value_base)
    {
      lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 3];

      _this.error_code.push(ei_break_continue_as_single_loop_action);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
      _this.error_code.push(ts_ptr[3] == c_fgts_value_continue);

      return false;
    }
    else
    {
      tmp_flow_graph[ts_ptr[1]] = ts_ptr[3];
    }

    ts_ptr[1] = ts_ptr[2];

    // - attach ends of body to begin of expression -
    if (body_end_cnt != 0)
    {
      unsigned *tse_ptr = ts_ptr + 4;
      unsigned *tse_ptr_end = tse_ptr + body_end_cnt;

      do
      {
        tmp_flow_graph[*tse_ptr] = *ts_ptr;
      }
      while(++tse_ptr < tse_ptr_end);
    }

    fgd.fg_thread_stack.used -= body_end_cnt + 2;
    fgd.fgts_cnt.last() = 1;

    // - break command processing -
    ui_array_s &break_ends = fgd.fgts_bc_ends_array.last()[c_fgts_value_break - c_fgts_bc_value_base];
    if (break_ends.used != 0)
    {
      unsigned *be_ptr = break_ends.data;
      unsigned *be_ptr_end = be_ptr + break_ends.used;

      do
      {
        fgd.fg_thread_stack.push(*be_ptr);
      }
      while(++be_ptr < be_ptr_end);

      fgd.fgts_cnt.last() += break_ends.used;
    }

    // - continue command processing -
    ui_array_s &continue_ends = fgd.fgts_bc_ends_array.last()[c_fgts_value_continue - c_fgts_bc_value_base];
    if (continue_ends.used != 0)
    {
      unsigned *ce_ptr = continue_ends.data;
      unsigned *ce_ptr_end = ce_ptr + continue_ends.used;

      do
      {
        tmp_flow_graph[*ce_ptr] = *ts_ptr;
      }
      while(++ce_ptr < ce_ptr_end);
    }
  }
  break;
  default:
    debug_assert(0);
  }

  // - remove break and continue command positions -
  fgd.fgts_bc_ends_array.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_while_statement\n"));

  return true;
}/*}}}*/

bool pa_while_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - creation of positions determined for store of records of break and continue -
  fgd.fgts_bc_ends_array.push_blank();
  ui_arrays_s &fgts_bc_ends = fgd.fgts_bc_ends_array.last();

  fgts_bc_ends.copy_resize(2);
  fgts_bc_ends.used = 2;

  fgts_bc_ends[0].used = 0;
  fgts_bc_ends[1].used = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_while_begin\n"));

  return true;
}/*}}}*/

bool pa_do_while_statement(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  switch (fgd.fgts_type[fgd.fgts_type.used - 2])
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:
  {
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - 3;

    tmp_flow_graph[ts_ptr[1]] = *ts_ptr;
    ts_ptr[1] = ts_ptr[2];

    fgd.fg_thread_stack.used--;
    fgd.fgts_cnt.last() = 1;

    unsigned *fgts_t_ptr = fgd.fgts_type.data + fgd.fgts_type.used - 2;
    *fgts_t_ptr = fgts_t_ptr[1];
    fgd.fgts_type.used--;
  }
  break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
  {
    unsigned body_end_cnt = fgd.fgts_cnt[fgd.fgts_cnt.used - 2];
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (4 + body_end_cnt);

    // - PARSE ERROR -
    if (*ts_ptr >= c_fgts_bc_value_base)
    {
      lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 5];

      _this.error_code.push(ei_break_continue_as_single_loop_action);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
      _this.error_code.push(*ts_ptr == c_fgts_value_continue);

      return false;
    }
    else
    {
      tmp_flow_graph[ts_ptr[2 + body_end_cnt]] = *ts_ptr;
    }

    if (body_end_cnt != 0)
    {
      unsigned *tse_ptr = ts_ptr + 1;
      unsigned *tse_ptr_end = tse_ptr + body_end_cnt;
      unsigned condition_begin = ts_ptr[1 + body_end_cnt];

      do
      {
        tmp_flow_graph[*tse_ptr] = condition_begin;
      }
      while(++tse_ptr < tse_ptr_end);
    }

    // - processing of continue command -
    ui_array_s &continue_ends = fgd.fgts_bc_ends_array.last()[c_fgts_value_continue - c_fgts_bc_value_base];
    if (continue_ends.used != 0)
    {
      unsigned *ce_ptr = continue_ends.data;
      unsigned *ce_ptr_end = ce_ptr + continue_ends.used;
      unsigned condition_start = body_end_cnt + 1;

      do
      {
        tmp_flow_graph[*ce_ptr] = ts_ptr[condition_start];
      }
      while(++ce_ptr < ce_ptr_end);
    }

    ts_ptr[1] = ts_ptr[body_end_cnt + 3];

    fgd.fg_thread_stack.used -= body_end_cnt + 2;

    fgd.fgts_cnt.used--;
    fgd.fgts_cnt.last() = 1;

    unsigned *fgts_t_ptr = fgd.fgts_type.data + fgd.fgts_type.used - 2;
    *fgts_t_ptr = fgts_t_ptr[1];
    fgd.fgts_type.used--;

    // - processing of break command -
    ui_array_s &break_ends = fgd.fgts_bc_ends_array.last()[c_fgts_value_break - c_fgts_bc_value_base];
    if (break_ends.used != 0)
    {
      unsigned *be_ptr = break_ends.data;
      unsigned *be_ptr_end = be_ptr + break_ends.used;

      do
      {
        fgd.fg_thread_stack.push(*be_ptr);
      }
      while(++be_ptr < be_ptr_end);

      fgd.fgts_cnt.last() += break_ends.used;
    }
  }
  break;
  default:
    debug_assert(0);
  }

  // - remove positions of break and continue records -
  fgd.fgts_bc_ends_array.used--;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_do_while_statement\n"));

  return true;
}/*}}}*/

bool pa_do_while_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - creation of positions determined for storing of break and continue records -
  fgd.fgts_bc_ends_array.push_blank();
  ui_arrays_s &fgts_bc_ends = fgd.fgts_bc_ends_array.last();

  fgts_bc_ends.copy_resize(2);
  fgts_bc_ends.used = 2;

  fgts_bc_ends[0].used = 0;
  fgts_bc_ends[1].used = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_do_while_begin\n"));

  return true;
}/*}}}*/

bool pa_for_statement(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  // *****

  switch (fgd.fgts_type.pop())
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:

    // - leave store body index set to c_idx_not_exist -
    fgd.fg_thread_stack.used--;
    fgd.fgts_cnt.last() = 1;
    break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
  {
    unsigned body_end_cnt = fgd.fgts_cnt.pop();
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (4 + body_end_cnt);

    // - PARSE ERROR -
    if (ts_ptr[3] >= c_fgts_bc_value_base)
    {
      lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 5];

      _this.error_code.push(ei_break_continue_as_single_loop_action);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
      _this.error_code.push(ts_ptr[3] == c_fgts_value_continue);

      return false;
    }

    // - store body start index -
    tmp_flow_graph[ts_ptr[2]] = ts_ptr[3];

    // - set ends of body as not continuing -
    if (body_end_cnt != 0)
    {
      unsigned *tse_ptr = ts_ptr + 4;
      unsigned *tse_ptr_end = tse_ptr + body_end_cnt;

      do
      {
        tmp_flow_graph[*tse_ptr] = c_idx_not_exist;
      }
      while(++tse_ptr < tse_ptr_end);
    }

    fgd.fg_thread_stack.used -= body_end_cnt + 2;
    fgd.fgts_cnt.last() = 1;

    // - break command processing -
    ui_array_s &break_ends = fgd.fgts_bc_ends_array.last()[c_fgts_value_break - c_fgts_bc_value_base];
    if (break_ends.used != 0)
    {
      // - create break flow graph node -
      unsigned break_fg_idx = tmp_flow_graph.used;
      tmp_flow_graph.push(c_fg_type_break);

      unsigned *be_ptr = break_ends.data;
      unsigned *be_ptr_end = be_ptr + break_ends.used;

      do
      {
        tmp_flow_graph[*be_ptr] = break_fg_idx;
      }
      while(++be_ptr < be_ptr_end);
    }

    // - continue command processing -
    ui_array_s &continue_ends = fgd.fgts_bc_ends_array.last()[c_fgts_value_continue - c_fgts_bc_value_base];
    if (continue_ends.used != 0)
    {
      // - create continue flow graph node -
      unsigned continue_fg_idx = tmp_flow_graph.used;
      tmp_flow_graph.push(c_fg_type_continue);

      unsigned *ce_ptr = continue_ends.data;
      unsigned *ce_ptr_end = ce_ptr + continue_ends.used;

      do
      {
        tmp_flow_graph[*ce_ptr] = continue_fg_idx;
      }
      while(++ce_ptr < ce_ptr_end);
    }
  }
  break;
  default:
    debug_assert(0);
  }

  // - remove positions of break and continue records -
  fgd.fgts_bc_ends_array.used--;

  // - join created thread to preceding assign expression -
  PA_COMMAND_JOIN();

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_for_statement\n"));

  return true;
}/*}}}*/

bool pa_for_expression(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  expression_descr_s &ed = code_descr.expression_descr;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  expression_descr_s id_ed;
  id_ed.init();

  // - retrieve identifier expression -
  id_ed = ed;
  id_ed.tmp_exp_info.used--;
  id_ed.tmp_expression.used = id_ed.tmp_exp_info.last().ui_second;

  // - create assign operator -
  PA_OPERATOR_BINARY(operator_binary_equal);

  // - create assign expression -
  PA_EXPRESSION();

  {
    // - test if expression stack contain exactly one node -
    debug_assert(id_ed.tmp_exp_info.used == 1);

    // - creation of description of flow graph node -
    fgd.fgts_type.push(c_fgts_type_thread);
    fgd.fgts_cnt.push(2);
    fgd.fg_thread_stack.push(tmp_flow_graph.used);
    fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_expression_first_out);
    fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_for_loop_body);

    // - creation of flow graph node -
    tmp_flow_graph.push(c_fg_type_for_loop);
    tmp_flow_graph.push(tmp_expressions.used);
    tmp_flow_graph.push(c_idx_not_exist);
    tmp_flow_graph.push(c_idx_not_exist);
    tmp_flow_graph.push(SET_SRC_POS(_this.source_idx,lalr_stack[lalr_stack.used - 2].terminal_start));

    // - insertion of expression to expression list -
    tmp_expressions.push_blank();
    expression_s &expression = tmp_expressions.last();

    expression.start_node_idx = id_ed.tmp_exp_info.pop().ui_first;
    expression.nodes.swap(id_ed.tmp_expression);

    debug_assert(id_ed.tmp_expression.used == 0);
    debug_assert(id_ed.tmp_exp_info.used == 0);
  }

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_for_expression\n"));

  id_ed.clear();
  return true;
}/*}}}*/

bool pa_for_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - creation of positions determined for storing of break and continue records -
  fgd.fgts_bc_ends_array.push_blank();
  ui_arrays_s &fgts_bc_ends = fgd.fgts_bc_ends_array.last();

  fgts_bc_ends.copy_resize(2);
  fgts_bc_ends.used = 2;

  fgts_bc_ends[0].used = 0;
  fgts_bc_ends[1].used = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_for_begin\n"));

  return true;
}/*}}}*/

bool pa_switch_statement(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_arrays_s &sds = _this.switch_descrs;
  expression_descrs_s &seds = _this.switch_expression_descrs;

  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;
  expression_descr_s &ed = code_descr.expression_descr;

  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - reference on switch description -
  ui_array_s &sd = sds.last();

  {
    unsigned value_cnt = sd[0];

    // - test if expression stack contain requested count of nodes -
    debug_assert(ed.tmp_exp_info.used == value_cnt);

    // - position of created expression node -
    unsigned tmp_node_idx = ed.tmp_expression.used;

    // - insertion of node to expression -
    ed.tmp_expression.push(c_node_type_switch_test);
    ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,lalr_stack[lalr_stack.used - 6].terminal_start));
    ed.tmp_expression.push(value_cnt);

    idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - value_cnt;
    idx_size_s *tei_ptr_end = ed.tmp_exp_info.data + ed.tmp_exp_info.used;
    \

    unsigned exp_size = 3;

    do
    {
      ed.tmp_expression.push(tei_ptr->ui_first);
      exp_size += 1 + tei_ptr->ui_second;
    }
    while(++tei_ptr < tei_ptr_end);

    ed.tmp_exp_info.used -= value_cnt;

    // - create expression info node -
    ed.tmp_exp_info.push_blank();
    idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

    tmp_exp_info.ui_first = tmp_node_idx;
    tmp_exp_info.ui_second = exp_size;
  }

  {
    // - test if expression stack contain exactly one node -
    debug_assert(ed.tmp_exp_info.used == 1);

    // - backup temporary flow graph base -
    unsigned tmp_flow_graph_base = tmp_flow_graph.used;

    // - creation of description of flow graph node -
    fgd.fgts_type.push(c_fgts_type_thread);
    fgd.fgts_cnt.push(1);
    fgd.fg_thread_stack.push(tmp_flow_graph.used);
    fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_expression_first_out);

    // - creation of flow graph node -
    tmp_flow_graph.push(c_fg_type_switch);
    tmp_flow_graph.push(tmp_expressions.used);
    tmp_flow_graph.push(c_idx_not_exist);
    tmp_flow_graph.push(0);
    tmp_flow_graph.push(0);
    tmp_flow_graph.push(SET_SRC_POS(_this.source_idx,lalr_stack[lalr_stack.used - 6].terminal_start));

    if (sd.used > 1)
    {
      unsigned default_count = 0;
      unsigned expression_count = 0;

      // - process default cases -
      unsigned *sd_ptr = sd.data + 1;
      unsigned *sd_ptr_end = sd.data + sd.used;
      do
      {
        if (sd_ptr[0] == 0 && sd_ptr[1] != c_idx_not_exist)
        {
          tmp_flow_graph.push(sd_ptr[1]);
          default_count++;
        }
      }
      while((sd_ptr += 2) < sd_ptr_end);

      // - process expression cases -
      sd_ptr = sd.data + 1;
      do
      {
        if (sd_ptr[0] != 0)
        {
          unsigned count = sd_ptr[0];
          do
          {
            tmp_flow_graph.push(sd_ptr[1]);
            expression_count++;
          }
          while(--count > 0);
        }
      }
      while((sd_ptr += 2) < sd_ptr_end);

      // - modify count of default and expression cases -
      tmp_flow_graph[tmp_flow_graph_base + c_fg_switch_default_cnt] = default_count;
      tmp_flow_graph[tmp_flow_graph_base + c_fg_switch_exp_cnt] = expression_count;
    }

    // - insertion of expression to expression list -
    tmp_expressions.push_blank();
    expression_s &expression = tmp_expressions.last();

    expression.start_node_idx = ed.tmp_exp_info.pop().ui_first;
    expression.nodes.swap(ed.tmp_expression);

    debug_assert(ed.tmp_expression.used == 0);
    debug_assert(ed.tmp_exp_info.used == 0);
  }

  // - remove switch description from stack -
  sds.used -= 1;

  // - remove switch expression description from stack -
  seds.used -= 1;

  // - retrieve break and continue command positions -
  ui_arrays_s &fgts_bc_ends = fgd.fgts_bc_ends_array.pop();

  // - PARSE ERROR -
  if (fgts_bc_ends[0].used > 0 || fgts_bc_ends[1].used > 0)
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 6];

    _this.error_code.push(ei_break_continue_from_switch_case);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
    _this.error_code.push(fgts_bc_ends[1].used > 0);

    return false;
  }

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_switch_statement\n"));

  return true;
}/*}}}*/

bool pa_switch_expression(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_arrays_s &sds = _this.switch_descrs;
  expression_descrs_s &seds = _this.switch_expression_descrs;
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - push new switch description to stack -
  sds.push_blank();

  // - initialize switch description -
  ui_array_s &sd = sds.last();
  sd.used = 0;

  // - store switch expression count -
  sd.push(1);

  // - push new switch expression description to stack -
  seds.push_blank();

  // - initialize switch expression description -
  expression_descr_s &sed = seds.last();
  sed.tmp_expression.used = 0;
  sed.tmp_exp_info.used = 0;

  // - creation of positions determined for store of records of break and continue -
  fgd.fgts_bc_ends_array.push_blank();
  ui_arrays_s &fgts_bc_ends = fgd.fgts_bc_ends_array.last();

  fgts_bc_ends.copy_resize(2);
  fgts_bc_ends.used = 2;

  fgts_bc_ends[0].used = 0;
  fgts_bc_ends[1].used = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_switch_expression\n"));

  return true;
}/*}}}*/

bool pa_switch_item(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &sd = _this.switch_descrs.last();
  expression_descr_s &sed = _this.switch_expression_descrs.last();

  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;
  expression_descr_s &ed = code_descr.expression_descr;

  // *****

  switch (fgd.fgts_type.pop())
  {

  // - FGTS_BLANK -
  case c_fgts_type_blank:

    // - push code index to switch description -
    sd.push(c_idx_not_exist);
    break;

  // - FGTS_THREAD -
  case c_fgts_type_thread:
  {
    unsigned body_end_cnt = fgd.fgts_cnt.pop();
    unsigned *ts_ptr = fgd.fg_thread_stack.data + fgd.fg_thread_stack.used - (1 + body_end_cnt);

    // - PARSE ERROR -
    if (*ts_ptr >= c_fgts_bc_value_base)
    {
      lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

      _this.error_code.push(ei_break_continue_from_switch_case);
      _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
      _this.error_code.push(*ts_ptr == c_fgts_value_continue);

      return false;
    }

    // - push code index to switch description -
    sd.push(*ts_ptr);

    // - set ends of body as not continuing -
    if (body_end_cnt != 0)
    {
      unsigned *tse_ptr = ts_ptr + 1;
      unsigned *tse_ptr_end = tse_ptr + body_end_cnt;

      do
      {
        tmp_flow_graph[*tse_ptr] = c_idx_not_exist;
      }
      while(++tse_ptr < tse_ptr_end);
    }

    // - remove thread from thread stack -
    fgd.fg_thread_stack.used -= body_end_cnt + 1;
  }
  break;
  default:
    debug_assert(0);
  }

  // - swap temporary and switch expressions -
  ed.swap(sed);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_switch_item\n"));

  return true;
}/*}}}*/

bool pa_switch_item_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &sd = _this.switch_descrs.last();
  expression_descr_s &sed = _this.switch_expression_descrs.last();
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - push expression count to switch description -
  sd.push(ed.tmp_exp_info.used - sd[0]);

  // - update switch expression count -
  sd[0] = ed.tmp_exp_info.used;

  // - swap temporary and switch expressions -
  ed.swap(sed);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_switch_item_begin\n"));

  return true;
}/*}}}*/

bool pa_break(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - PARSE ERROR break is not located inside loop -
  if (fgd.fgts_bc_ends_array.used == 0)
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    _this.error_code.push(ei_break_continue_without_enclosing_loop);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
    _this.error_code.push(0);

    return false;
  }

  // - store thread describing break -
  fgd.fgts_type.push(c_fgts_type_thread);
  fgd.fgts_cnt.push(0);
  fgd.fg_thread_stack.push(c_fgts_value_break);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_break\n"));

  return true;
}/*}}}*/

bool pa_continue(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  flow_graph_descr_s &fgd = _this.code_descrs.last().flow_graph_descr;

  // *****

  // - PARSER ERROR continue is not located inside loop -
  if (fgd.fgts_bc_ends_array.used == 0)
  {
    lalr_stack_element_s &lse = _this.lalr_stack[_this.lalr_stack.used - 2];

    _this.error_code.push(ei_break_continue_without_enclosing_loop);
    _this.error_code.push(SET_SRC_POS(_this.source_idx,lse.terminal_start));
    _this.error_code.push(1);

    return false;
  }

  // - store thread describing continue -
  fgd.fgts_type.push(c_fgts_type_thread);
  fgd.fgts_cnt.push(0);
  fgd.fg_thread_stack.push(c_fgts_value_continue);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_continue\n"));

  return true;
}/*}}}*/

bool pa_return(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - modification of expression thread to return expression thread -
  fgd.fgts_cnt.last() = 0;
  fgd.fg_thread_stack.used--;

  unsigned tfg_idx = fgd.fg_thread_stack.last();

  tmp_flow_graph[tfg_idx] = c_fg_type_return_expression;
  tmp_flow_graph[tfg_idx + c_fg_return_expression_source_pos] = SET_SRC_POS(_this.source_idx,lalr_stack.last().terminal_start);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_return\n"));

  return true;
}/*}}}*/

bool pa_elements_array(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  unsigned array_member_cnt = member_cnt.pop();

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  // - insertion of node to expression -
  ed.tmp_expression.push(c_node_type_elements_array);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(array_member_cnt);

  unsigned exp_size = 3;

  if (array_member_cnt != 0)
  {
    idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - array_member_cnt;
    idx_size_s *tei_ptr_end = ed.tmp_exp_info.data + ed.tmp_exp_info.used;

    do
    {
      ed.tmp_expression.push(tei_ptr->ui_first);
      exp_size += 1 + tei_ptr->ui_second;
    }
    while(++tei_ptr < tei_ptr_end);

    ed.tmp_exp_info.used -= array_member_cnt;
  }

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_size;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_elements_array\n"));

  return true;
}/*}}}*/

bool pa_array_elements_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;

  // *****

  member_cnt.push(0);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_array_elements_begin\n"));

  return true;
}/*}}}*/

bool pa_array_element(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;

  // *****

  member_cnt.last()++;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_array_element\n"));

  return true;
}/*}}}*/

bool pa_condition(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;
  expression_descr_s &ed = code_descr.expression_descr;

  // *****

  // - test if expression stack contain exactly one node -
  debug_assert(ed.tmp_exp_info.used == 1);

  // - creation of description of flow graph node -
  fgd.fgts_type.push(c_fgts_type_thread);
  fgd.fgts_cnt.push(2);
  fgd.fg_thread_stack.push(tmp_flow_graph.used);
  fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_condition_first_out);
  fgd.fg_thread_stack.push(tmp_flow_graph.used + c_fg_condition_second_out);

  // - creation of flow graph node  -
  tmp_flow_graph.push(c_fg_type_condition);
  tmp_flow_graph.push(tmp_expressions.used);
  tmp_flow_graph.push(c_idx_not_exist);
  tmp_flow_graph.push(c_idx_not_exist);
  tmp_flow_graph.push(SET_SRC_POS(_this.source_idx,_this.lalr_stack.last().terminal_start));

  // - insertion of expression to list -
  tmp_expressions.push_blank();
  expression_s &expression = tmp_expressions.last();

  expression.start_node_idx = ed.tmp_exp_info.pop().ui_first;
  expression.nodes.swap(ed.tmp_expression);

  debug_assert(ed.tmp_expression.used == 0);
  debug_assert(ed.tmp_exp_info.used == 0);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_condition\n"));

  return true;
}/*}}}*/

bool pa_expression(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  code_descr_s &code_descr = _this.code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;
  expression_descr_s &ed = code_descr.expression_descr;

  // *****

  PA_EXPRESSION();

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_expression\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_plus_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_plus_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_plus_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_minus_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_minus_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_minus_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_asterisk_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_asterisk_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_asterisk_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_slash_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_slash_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_slash_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_percent_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_percent_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_percent_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_ls_br_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_ls_br_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_ls_br_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_rs_br_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_rs_br_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_rs_br_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_ampersand_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_ampersand_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_ampersand_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_pipe_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_pipe_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_pipe_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_circumflex_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_circumflex_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_circumflex_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_ampersand(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_ampersand);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_ampersand\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_pipe(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_pipe);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_pipe\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_ampersand(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_ampersand);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_ampersand\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_pipe(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_pipe);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_pipe\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_circumflex(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_circumflex);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_circumflex\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_exclamation_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_exclamation_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_exclamation_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_rs_br(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_rs_br);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_rs_br\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_ls_br(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_ls_br);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_ls_br\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_rs_br_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_rs_br_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_rs_br_equal\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_ls_br_equal(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_ls_br_equal);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_ls_br_equal\n"));

  return true;
}/*}}}*/

bool pa_presence_test(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - position of created expression node -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_object_method_call);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(c_built_in_method_idxs[c_built_in_method_contain_1]);
  ed.tmp_expression.push(1);

  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used;
  idx_size_s *tei_ptr_end = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 2;

  unsigned exp_size = 4;

  do {
    ed.tmp_expression.push((--tei_ptr)->ui_first);
    exp_size += 1 + tei_ptr->ui_second;
  } while(tei_ptr > tei_ptr_end);

  ed.tmp_exp_info.used -= 2;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_size;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_presence_test\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_rs_br(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_rs_br);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_rs_br\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_double_ls_br(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_double_ls_br);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_double_ls_br\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_plus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_plus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_plus\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_minus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_minus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_minus\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_asterisk(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_asterisk);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_asterisk\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_slash(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_slash);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_slash\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_percent(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_percent);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_percent\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_post_double_plus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_post_double_plus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_post_double_plus\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_post_double_minus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_post_double_minus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_post_double_minus\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_pre_double_plus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_pre_double_plus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_pre_double_plus\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_pre_double_minus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_pre_double_minus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_pre_double_minus\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_pre_plus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_pre_plus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_pre_plus\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_pre_minus(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_pre_minus);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_pre_minus\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_pre_exclamation(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_pre_exclamation);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_pre_exclamation\n"));

  return true;
}/*}}}*/

bool pa_operator_unary_pre_tilde(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_UNARY(operator_unary_pre_tilde);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_unary_pre_tilde\n"));

  return true;
}/*}}}*/

bool pa_operator_binary_le_br_re_br(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OPERATOR_BINARY(operator_binary_le_br_re_br);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_operator_binary_le_br_re_br\n"));

  return true;
}/*}}}*/

bool pa_slice_range(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 4;

  // - insertion of node to expression -
  ed.tmp_expression.push(c_node_type_slice_range);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(tei_ptr[0].ui_first);
  ed.tmp_expression.push(tei_ptr[1].ui_first);
  ed.tmp_expression.push(tei_ptr[2].ui_first);
  ed.tmp_expression.push(tei_ptr[3].ui_first);

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 4;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second +
                           tei_ptr[2].ui_second + tei_ptr[3].ui_second + 6;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_slice_range\n"));

  return true;
}/*}}}*/

bool pa_slice_blank_value(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lli_rb_tree_s &const_ints = _this.const_ints;

  // *****

  // - search constant in constant array -
  unsigned ci_idx = const_ints.unique_insert(LLONG_MAX);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_int);
  ed.tmp_expression.push(ci_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    fprintf(stderr,"script_parser: parse_action: pa_slice_blank_value\n");
  );

  return true;
}/*}}}*/

bool pa_identifier(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  // - get position of variable name -
  unsigned name_length = lse.terminal_end - lse.terminal_start;
  char *name_data = source_string.data + lse.terminal_start;

  // - get index of variable name -
  unsigned name_idx = _this.variable_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  PA_IDENTIFIER(c_node_type_identifier,name_idx,_this.old_input_idx);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_identifier: %s\n",_this.variable_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_this_access(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_this_access);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_this_access\n"));

  return true;
}/*}}}*/

bool pa_new_object(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - count constructor parameters -
  unsigned c_parameter_cnt = member_cnt.pop();

  // - position of created node -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - (1 + c_parameter_cnt);

  ed.tmp_expression.push(c_node_type_new_object);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(c_parameter_cnt);
  ed.tmp_expression.push(tei_ptr[0].ui_first);

  unsigned exp_size = tei_ptr[0].ui_second + 4;

  if (c_parameter_cnt != 0)
  {
    ++tei_ptr;
    idx_size_s *tei_ptr_end = ed.tmp_exp_info.data + ed.tmp_exp_info.used;

    do
    {
      ed.tmp_expression.push(tei_ptr->ui_first);
      exp_size += 1 + tei_ptr->ui_second;
    }
    while(++tei_ptr < tei_ptr_end);
  }

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 1 + c_parameter_cnt;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_size;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_new_object\n"));

  return true;
}/*}}}*/

bool pa_new_objects_array(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - position of created node -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 2;

  ed.tmp_expression.push(c_node_type_new_objects_array);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(tei_ptr[0].ui_first);
  ed.tmp_expression.push(tei_ptr[1].ui_first);

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 2;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second + 4;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_new_objects_array\n"));

  return true;
}/*}}}*/

bool pa_free_object(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - position of created node -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s &exp_info = ed.tmp_exp_info.pop();

  ed.tmp_expression.push(c_node_type_free_object);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(exp_info.ui_first);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_info.ui_second + 3;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_free_object\n"));

  return true;
}/*}}}*/

bool pa_type_identification(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s &exp_info = ed.tmp_exp_info.pop();

  // - store node to expression -
  ed.tmp_expression.push(c_node_type_type_identification);
  ed.tmp_expression.push(exp_info.ui_first);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_info.ui_second + 2;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_type_identification\n"));

  return true;
}/*}}}*/

bool pa_convert_to_string(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  PA_OBJECT_METHOD_CALL(c_built_in_method_idxs[c_built_in_method_to_string_0],0,_this.old_input_idx);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_convert_to_string\n"));

  return true;
}/*}}}*/

bool pa_object_reference_copy(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 2;

  // - store node to expression -
  ed.tmp_expression.push(c_node_type_object_reference_copy);
  ed.tmp_expression.push(tei_ptr[0].ui_first);
  ed.tmp_expression.push(tei_ptr[1].ui_first);

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 2;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second + 3;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_object_reference_copy\n"));

  return true;
}/*}}}*/

bool pa_conditional_expression(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 3;

  // - store node to expression -
  ed.tmp_expression.push(c_node_type_conditional_expression);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(tei_ptr[0].ui_first);
  ed.tmp_expression.push(tei_ptr[1].ui_first);
  ed.tmp_expression.push(tei_ptr[2].ui_first);

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 3;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second + tei_ptr[2].ui_second + 5;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_conditional_expression\n"));

  return true;
}/*}}}*/

bool pa_logical_and(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 2;

  // - store node to expression -
  ed.tmp_expression.push(c_node_type_logical_and);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(tei_ptr[0].ui_first);
  ed.tmp_expression.push(tei_ptr[1].ui_first);

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 2;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second + 4;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_logical_and\n"));

  return true;
}/*}}}*/

bool pa_logical_or(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - 2;

  // - store node to expression -
  ed.tmp_expression.push(c_node_type_logical_or);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(tei_ptr[0].ui_first);
  ed.tmp_expression.push(tei_ptr[1].ui_first);

  // - remove old nodes from stack -
  ed.tmp_exp_info.used -= 2;

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = tei_ptr[0].ui_second + tei_ptr[1].ui_second + 4;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_logical_or\n"));

  return true;
}/*}}}*/

bool pa_class_access(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &namespace_name_idxs = _this.namespace_name_idxs;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  unsigned name_cnt = namespace_name_idxs.used >> 1;

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  // - insertion of node to expression -
  ed.tmp_expression.push(c_node_type_class_access);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(name_cnt);

  unsigned *nni_ptr = namespace_name_idxs.data;
  unsigned *nni_ptr_end = nni_ptr + namespace_name_idxs.used;
  do {
    ed.tmp_expression.push(*nni_ptr);
  } while((nni_ptr += 2) < nni_ptr_end);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 3 + name_cnt;

  // - remove namespace names -
  namespace_name_idxs.used = 0;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_class_access\n"));

  return true;
}/*}}}*/

bool pa_object_member_select(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  name_pos_s &tmp_name_pos = _this.tmp_name_pos_array.pop();
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - get name position -
  unsigned name_length = tmp_name_pos.ui_second - tmp_name_pos.ui_first;
  char *name_data = source_string.data + tmp_name_pos.ui_first;

  // - get index of variable name -
  unsigned name_idx = _this.variable_symbol_names.get_idx_char_ptr_insert(name_length,name_data);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;
  idx_size_s &exp_info = ed.tmp_exp_info.pop();

  ed.tmp_expression.push(c_node_type_object_member_select);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(name_idx);
  ed.tmp_expression.push(exp_info.ui_first);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_info.ui_second + 4;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_object_member_select\n"));

  return true;
}/*}}}*/

bool pa_this_method_call(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 3];

  // - count of method parameters -
  unsigned m_parameter_cnt = member_cnt.pop();

  // - creation of space for method name -
  unsigned method_name_max_length = (lse.terminal_end - lse.terminal_start) + max_number_string_length;

  string_s name_string;
  name_string.data = (char *)cmalloc(method_name_max_length);

  // - creation of complete method name -
  char tmp_char = source_string[lse.terminal_end];
  source_string[lse.terminal_end] = '\0';

  name_string.size = 1 + snprintf(name_string.data,method_name_max_length,"%s#%u",source_string.data + lse.terminal_start,m_parameter_cnt);

  source_string[lse.terminal_end] = tmp_char;

  // - get index of method name -
  unsigned name_idx = _this.get_method_name_idx_swap(name_string);
  name_string.clear();

  // - position of created expression node -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_this_method_call);
  ed.tmp_expression.push(SET_SRC_POS(_this.source_idx,_this.old_input_idx));
  ed.tmp_expression.push(name_idx);
  ed.tmp_expression.push(m_parameter_cnt);

  unsigned exp_size = 4;

  if (m_parameter_cnt != 0)
  {
    idx_size_s *tei_ptr = ed.tmp_exp_info.data + ed.tmp_exp_info.used - m_parameter_cnt;
    idx_size_s *tei_ptr_end = ed.tmp_exp_info.data + ed.tmp_exp_info.used;

    do
    {
      ed.tmp_expression.push(tei_ptr->ui_first);
      exp_size += 1 + tei_ptr->ui_second;
    }
    while(++tei_ptr < tei_ptr_end);

    ed.tmp_exp_info.used -= m_parameter_cnt;
  }

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = exp_size;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_this_method_call: %s\n",_this.method_symbol_names[name_idx].data));

  return true;
}/*}}}*/

bool pa_object_method_call(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  name_pos_s &tmp_name_pos = _this.tmp_name_pos_array.pop();
  ui_array_s &member_cnt = _this.member_cnt;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;

  // *****

  // - count of method parameters -
  unsigned m_parameter_cnt = member_cnt.pop();

  // - creation of space for method name -
  unsigned method_name_max_length = (tmp_name_pos.ui_second - tmp_name_pos.ui_first) + max_number_string_length;

  string_s name_string;
  name_string.data = (char *)cmalloc(method_name_max_length);

  // - creation of complete method name -
  char tmp_char = source_string[tmp_name_pos.ui_second];
  source_string[tmp_name_pos.ui_second] = '\0';

  name_string.size = 1 + snprintf(name_string.data,method_name_max_length,"%s#%u",source_string.data + tmp_name_pos.ui_first,m_parameter_cnt);

  source_string[tmp_name_pos.ui_second] = tmp_char;

  // - get index of method name -
  unsigned name_idx = _this.get_method_name_idx_swap(name_string);
  name_string.clear();

  PA_OBJECT_METHOD_CALL(name_idx,m_parameter_cnt,_this.old_input_idx);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_object_method_call\n"));

  return true;
}/*}}}*/

bool pa_parameters_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;

  // *****

  member_cnt.push(0);

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_parameters_begin\n"));

  return true;
}/*}}}*/

bool pa_parameter(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;

  // *****

  member_cnt.last()++;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_parameter\n"));

  return true;
}/*}}}*/

bool pa_object_member_name(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  name_pos_array_s &tmp_name_pos_array = _this.tmp_name_pos_array;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - store position of identifier name -
  lalr_stack_element_s &lse = lalr_stack.last();
  tmp_name_pos_array.push_blank();
  tmp_name_pos_array.last().set(lse.terminal_start,lse.terminal_end);

  debug_message_4(
    char tmp_char = source_string[lse.terminal_end];
    source_string[lse.terminal_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_object_member_name: %s\n",source_string.data + lse.terminal_start);
    source_string[lse.terminal_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_lambda_end(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;

  code_descrs_s &code_descrs = _this.code_descrs;
  code_descr_s &code_descr = code_descrs.last();
  ui_array_s &tmp_flow_graph = code_descr.tmp_flow_graph;
  expressions_s &tmp_expressions = code_descr.tmp_expressions;
  flow_graph_descr_s &fgd = code_descr.flow_graph_descr;

  exp_flow_graphs_s &method_flow_graphs = _this.method_flow_graphs;

  // *****

  // - test if thread was created on stack of graph flow -
  debug_assert(fgd.fgts_type.used > 0);

  // - if method body contains no code -
  if (fgd.fgts_type.last() == c_fgts_type_blank)
  {
    fgd.fgts_type.pop();
    pa_method_body_empty(source_string,_this);
  }

  unsigned *ts_ptr = fgd.fg_thread_stack.data;
  debug_assert(*ts_ptr < c_fgts_bc_value_base);

  // - setting flow graph index in method -
  method_record_s &method_record = method_records[parent_method_idxs.last()];
  method_record.flow_graph_idx = method_flow_graphs.used;

  // - copy (swap) parsed flow graph -
  method_flow_graphs.push_blank();
  exp_flow_graph_s &method_flow_graph = method_flow_graphs.last();

  method_flow_graph.start_node_idx = *ts_ptr;
  method_flow_graph.nodes.swap(tmp_flow_graph);
  method_flow_graph.expressions.swap(tmp_expressions);

  // - remove temporary data -
  fgd.fg_thread_stack.used = 0;
  fgd.fgts_cnt.used = 0;

  // - remove method index from parent method stack -
  parent_method_idxs.used--;

  debug_assert(tmp_flow_graph.used == 0);
  debug_assert(tmp_expressions.used == 0);
  debug_assert(fgd.fg_thread_stack.used == 0);
  debug_assert(fgd.fgts_cnt.used == 0);

  // - remove code description -
  code_descrs.used--;

  // FIXME TODO create expression value ...
  {
    expression_descr_s &ed = _this.code_descrs.last().expression_descr;
    lli_rb_tree_s &const_ints = _this.const_ints;

    // - get constant position in array -
    unsigned ci_idx = const_ints.unique_insert(0);

    // - store node position -
    unsigned tmp_node_idx = ed.tmp_expression.used;

    ed.tmp_expression.push(c_node_type_const_int);
    ed.tmp_expression.push(ci_idx);

    // - create expression info node -
    ed.tmp_exp_info.push_blank();
    idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

    tmp_exp_info.ui_first = tmp_node_idx;
    tmp_exp_info.ui_second = 2;
  }

  // -----

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_lambda_end\n"));

  return true;
}/*}}}*/

bool pa_lambda_begin(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  method_records_s &method_records = _this.method_records;
  ui_array_s &parent_method_idxs = _this.parent_method_idxs;
  code_descrs_s &code_descrs = _this.code_descrs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  // - get lambda position -
  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];

  // - creation of new method record -
  method_records.push_blank();
  unsigned method_record_idx = method_records.used - 1;
  method_record_s &method_record = method_records.last();

  // - setting of variables describing method -
  method_record.name_idx = c_idx_not_exist;

  method_record.modifiers = c_modifier_public & c_modifier_static & c_modifier_final;
  method_record.parent_record = c_idx_not_exist;
  method_record.flow_graph_idx = c_idx_not_exist;

  // - store position of lambda in code -
  name_pos_s &name_position = method_record.name_position;
  name_position.ui_first = SET_SRC_POS(_this.source_idx,lse.terminal_start);
  name_position.ui_second = SET_SRC_POS(_this.source_idx,lse.terminal_end);

  // - push method record index to parent method stack -
  parent_method_idxs.push(method_record_idx);

  // - initialize code description -
  code_descrs.push_blank();

  debug_message_4(
    fprintf(stderr,"script_parser: parse_action: pa_lambda_begin\n");
  );

  return true;
}/*}}}*/

bool pa_lambda_parameters(string_s &source_string,script_parser_s &_this)
{/*{{{*/

  // FIXME TODO remove unused parse action ...

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_lambda_parameters\n"));

  return true;
}/*}}}*/

bool pa_const_char(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  bc_array_s &const_chars = _this.const_chars;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  char const_char = source_string.data[lalr_stack.last().terminal_start + 1];

  // - get constant position in array -
  unsigned cc_idx = const_chars.get_idx(const_char);
  if (cc_idx == c_idx_not_exist)
  {
    const_chars.push(const_char);
    cc_idx = const_chars.used - 1;
  }

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_char);
  ed.tmp_expression.push(cc_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(fprintf(stderr,"script_parser: parse_action: pa_const_char: '%c'\n",const_char));

  return true;
}/*}}}*/

bool pa_const_octal_char(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  bc_array_s &const_chars = _this.const_chars;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned char_num_end = (lse.terminal_end - lse.terminal_start) - 1;
  char *char_num_data = source_string.data + lse.terminal_start;

  // - retrieve char number -
  char_num_data[char_num_end] = '\0';
  char const_char = strtol(char_num_data + 2,NULL,8);
  char_num_data[char_num_end] = '\'';

  // - get constant position in array -
  unsigned cc_idx = const_chars.get_idx(const_char);
  if (cc_idx == c_idx_not_exist)
  {
    const_chars.push(const_char);
    cc_idx = const_chars.used - 1;
  }

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_char);
  ed.tmp_expression.push(cc_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    char *end_ptr = source_string.data + lse.terminal_end;
    *end_ptr = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_octal_char: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = '\'';
  );

  return true;
}/*}}}*/

bool pa_const_hex_char(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  bc_array_s &const_chars = _this.const_chars;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned char_num_end = (lse.terminal_end - lse.terminal_start) - 1;
  char *char_num_data = source_string.data + lse.terminal_start;

  // - retrieve char number -
  char_num_data[char_num_end] = '\0';
  char const_char = strtol(char_num_data + 3,NULL,16);
  char_num_data[char_num_end] = '\'';

  // - get constant position in array -
  unsigned cc_idx = const_chars.get_idx(const_char);
  if (cc_idx == c_idx_not_exist)
  {
    const_chars.push(const_char);
    cc_idx = const_chars.used - 1;
  }

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_char);
  ed.tmp_expression.push(cc_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    char_num_data[char_num_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_hex_char: %s\n",char_num_data);
    char_num_data[char_num_end] = '\'';
  );

  return true;
}/*}}}*/

bool pa_const_backslash_char(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  bc_array_s &const_chars = _this.const_chars;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  char const_char = 0;

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

  // - get constant position in array -
  unsigned cc_idx = const_chars.get_idx(const_char);
  if (cc_idx == c_idx_not_exist)
  {
    const_chars.push(const_char);
    cc_idx = const_chars.used - 1;
  }

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_char);
  ed.tmp_expression.push(cc_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    lalr_stack_element_s &lse = lalr_stack.last();
    char *end_ptr = source_string.data + lse.terminal_end;
    *end_ptr = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_backslash_char: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = '\'';
  );

  return true;
}/*}}}*/

bool pa_const_oct_int(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lli_rb_tree_s &const_ints = _this.const_ints;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve number -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  long long int const_int = strtoll(num_data,NULL,8);
  num_data[num_end] = tmp_char;

  // - get constant position in array -
  unsigned ci_idx = const_ints.unique_insert(const_int);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_int);
  ed.tmp_expression.push(ci_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    num_data[num_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_oct_int: %s\n",num_data);
    num_data[num_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_const_dec_int(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lli_rb_tree_s &const_ints = _this.const_ints;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve number -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  long long int const_int = strtoll(num_data,NULL,10);
  num_data[num_end] = tmp_char;

  // - get constant position in array -
  unsigned ci_idx = const_ints.unique_insert(const_int);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_int);
  ed.tmp_expression.push(ci_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    num_data[num_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_dec_int: %s\n",num_data);
    num_data[num_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_const_hex_int(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  lli_rb_tree_s &const_ints = _this.const_ints;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned num_end = lse.terminal_end - lse.terminal_start;
  char *num_data = source_string.data + lse.terminal_start;

  // - retrieve number -
  char tmp_char = num_data[num_end];
  num_data[num_end] = '\0';
  long long int const_int = strtoll(num_data,NULL,16);
  num_data[num_end] = tmp_char;

  // - get constant position in array -
  unsigned ci_idx = const_ints.unique_insert(const_int);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_int);
  ed.tmp_expression.push(ci_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    num_data[num_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_hex_int: %s\n",num_data);
    num_data[num_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_const_float(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  bd_rb_tree_s &const_floats = _this.const_floats;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned float_num_end = lse.terminal_end - lse.terminal_start;
  char *float_num_data = source_string.data + lse.terminal_start;

  // - retrieve number from string -
  char tmp_char = float_num_data[float_num_end];
  float_num_data[float_num_end] = '\0';
  double const_float = strtod(float_num_data,NULL);
  float_num_data[float_num_end] = tmp_char;

  // - get constant position in array -
  unsigned cd_idx = const_floats.unique_insert(const_float);

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_float);
  ed.tmp_expression.push(cd_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    float_num_data[float_num_end] = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_float: %s\n",float_num_data);
    float_num_data[float_num_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_const_string_register(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  name_pos_array_s &tmp_name_pos_array = _this.tmp_name_pos_array;
  ui_array_s &member_cnt = _this.member_cnt;
  expression_descr_s &ed = _this.code_descrs.last().expression_descr;
  string_rb_tree_s &const_strings = _this.const_strings;

  // *****

  // - retrieve string components length and count -
  unsigned *mc_ptr = member_cnt.data + member_cnt.used - 2;

  bc_array_s char_buffer;
  char_buffer.init_size(mc_ptr[0] + 1);

  // - process all string components -
  name_pos_s *np_ptr_end = tmp_name_pos_array.data + tmp_name_pos_array.used;
  name_pos_s *np_ptr = np_ptr_end - mc_ptr[1];
  do
  {
    // - if string component is not empty -
    if (np_ptr->ui_first < np_ptr->ui_second)
    {
      char *ptr = source_string.data + np_ptr->ui_first;
      char *ptr_end = source_string.data + np_ptr->ui_second;
      do
      {
        if (*ptr == '\\')
        {
          ptr++;

          // - process char represented by octal number -
          if (*ptr >= '0' && *ptr <= '7')
          {
            char new_char = *ptr++ - '0';

            if (*ptr >= '0' && *ptr <= '7')
            {
              new_char = (new_char << 3) | (*ptr++ - '0');

              if (*ptr >= '0' && *ptr <= '7')
              {
                new_char = (new_char << 3) | (*ptr++ - '0');
              }
            }

            char_buffer.push(new_char);
          }
          // - process char representation by hexadecimal number -
          else if (*ptr == 'x')
          {
            ptr++;
            char new_char = 0;

            // - first char in hexadecimal representation -
            if (*ptr >= '0' && *ptr <= '9')
            {
              new_char = *ptr++ - '0';
            }
            else if (*ptr >= 'a' && *ptr <= 'f')
            {
              new_char = 10 + (*ptr++ - 'a');
            }
            else if (*ptr >= 'A' && *ptr <= 'F')
            {
              new_char = 10 + (*ptr++ - 'A');
            }
            else
            {
              debug_assert(0);
            }

            // - second char in hexadecimal representation -
            if (*ptr >= '0' && *ptr <= '9')
            {
              new_char = (new_char << 4) | (*ptr++ - '0');
            }
            else if (*ptr >= 'a' && *ptr <= 'f')
            {
              new_char = (new_char << 4) | (10 + (*ptr++ - 'a'));
            }
            else if (*ptr >= 'A' && *ptr <= 'F')
            {
              new_char = (new_char << 4) | (10 + (*ptr++ - 'A'));
            }

            char_buffer.push(new_char);
          }
          else
          {
            switch (*ptr++)
            {
            case 'a':
              char_buffer.push('\a');
              break;
            case 'b':
              char_buffer.push('\b');
              break;
            case 'f':
              char_buffer.push('\f');
              break;
            case 'n':
              char_buffer.push('\n');
              break;
            case 'r':
              char_buffer.push('\r');
              break;
            case 't':
              char_buffer.push('\t');
              break;
            case 'v':
              char_buffer.push('\v');
              break;
            case '\\':
              char_buffer.push('\\');
              break;
            case '?':
              char_buffer.push('?');
              break;
            case '\'':
              char_buffer.push('\'');
              break;
            case '"':
              char_buffer.push('"');
              break;
            default:
              debug_assert(0);
            }
          }
        }
        else
        {
          char_buffer.push(*ptr++);
        }
      }
      while(ptr < ptr_end);
    }
  }
  while(++np_ptr < np_ptr_end);

  // - remove string component positions -
  tmp_name_pos_array.used -= mc_ptr[1];
  member_cnt.used -= 2;

  // - modification of character buffer -
  char_buffer.data[char_buffer.used] = '\0';

  string_s const_str;
  const_str.size = char_buffer.used + 1;
  const_str.data = char_buffer.data;

  // - get constant position in array -
  unsigned cs_idx = const_strings.unique_swap_insert(const_str);
  const_str.clear();

  // - store node position -
  unsigned tmp_node_idx = ed.tmp_expression.used;

  ed.tmp_expression.push(c_node_type_const_string);
  ed.tmp_expression.push(cs_idx);

  // - create expression info node -
  ed.tmp_exp_info.push_blank();
  idx_size_s &tmp_exp_info = ed.tmp_exp_info.last();

  tmp_exp_info.ui_first = tmp_node_idx;
  tmp_exp_info.ui_second = 2;

  debug_message_4(
    fprintf(stderr,"script_parser: parse_action: pa_const_string_register\n");
  );

  return true;
}/*}}}*/

bool pa_const_string_append(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  ui_array_s &member_cnt = _this.member_cnt;

  // *****

  unsigned *mc_ptr = member_cnt.data + member_cnt.used - 4;

  // - sum string components lengths and counts -
  mc_ptr[0] += mc_ptr[2];
  mc_ptr[1] += mc_ptr[3];

  member_cnt.used -= 2;

  debug_message_4(
    fprintf(stderr,"script_parser: parse_action: pa_const_string_append\n");
  );

  return true;
}/*}}}*/

bool pa_const_string(string_s &source_string,script_parser_s &_this)
{/*{{{*/
  name_pos_array_s &tmp_name_pos_array = _this.tmp_name_pos_array;
  ui_array_s &member_cnt = _this.member_cnt;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  // - store string component -
  tmp_name_pos_array.push_blank();
  name_pos_s &name_pos = tmp_name_pos_array.last();
  name_pos.set(lse.terminal_start + 1,lse.terminal_end - 1);

  // - store string component length and count -
  member_cnt.push(name_pos.ui_second - name_pos.ui_first);
  member_cnt.push(1);

  debug_message_4(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"script_parser: parse_action: pa_const_string: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

