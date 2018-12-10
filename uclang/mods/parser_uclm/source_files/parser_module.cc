
@begin
include "parser_module.h"
@end

// - PARSER indexes of built in classes -
unsigned c_bi_class_final_automata = c_idx_not_exist;
unsigned c_bi_class_fa_source = c_idx_not_exist;
unsigned c_bi_class_parser = c_idx_not_exist;
unsigned c_bi_class_parse_state = c_idx_not_exist;

// - PARSER module -
built_in_module_s module =
{/*{{{*/
  4,                      // Class count
  parser_classes,         // Classes

  0,                      // Error base index
  21,                     // Error count
  parser_error_strings,   // Error strings

  parser_initialize,      // Initialize function
  parser_print_exception, // Print exceptions function
};/*}}}*/

// - PARSER classes -
built_in_class_s *parser_classes[] =
{/*{{{*/
  &final_automata_class,
  &fa_source_class,
  &parser_class,
  &parse_state_class,
};/*}}}*/

// - PARSER error strings -
const char *parser_error_strings[] =
{/*{{{*/
  "error_FINAL_AUTOMATA_REGULAR_EXPRESSIONS_EMPTY",
  "error_FINAL_AUTOMATA_REGULAR_EXPRESSION_NOT_STRING",
  "error_FINAL_AUTOMATA_REGULAR_EXPRESSION_PARSE_ERROR",
  "error_PARSER_CREATE_UNSPECIFIED_ERROR",
  "error_PARSER_CREATE_RULES_SYNTAX_ERROR",
  "error_PARSER_CREATE_RULES_DUPLICATE_TERMINAL",
  "error_PARSER_CREATE_RULES_DUPLICATE_NONTERMINAL",
  "error_PARSER_CREATE_RULES_DUPLICATE_RULE",
  "error_PARSER_CREATE_RULES_UNDEFINED_TERMINAL",
  "error_PARSER_CREATE_RULES_UNDEFINED_NONTERMINAL",
  "error_PARSER_CREATE_RULES_NO_TERMINALS_DEFINED",
  "error_PARSER_CREATE_RULES_NO_NONTERMINALS_DEFINED",
  "error_PARSER_CREATE_RULES_NO_RULES_DEFINED",
  "error_PARSER_CREATE_MULTIPLE_PARSE_END_TERMINALS",
  "error_PARSER_CREATE_TERMINAL_REGULAR_EXPRESSION_PARSE_ERROR",
  "error_PARSER_CREATE_SLR1_PARSE_TABLE_CONFLICT",
  "error_PARSER_CREATE_CANNOT_RESOLVE_RULE_HEAD_FOR_SHIFT_ACTION",
  "error_PARSER_PARSE_UNRECOGNIZED_TERMINAL",
  "error_PARSER_PARSE_SYNTAX_ERROR",
  "error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK",
  "error_PARSER_PARSE_STATE_INDEX_EXCEEDS_RULE_BODY_SIZE",
};/*}}}*/

// - PARSER initialize -
bool parser_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize final_automata class identifier -
  c_bi_class_final_automata = class_base_idx++;

  // - initialize fa_source class identifier -
  c_bi_class_fa_source = class_base_idx++;

  // - initialize parser class identifier -
  c_bi_class_parser = class_base_idx++;

  // - initialize parse_state class identifier -
  c_bi_class_parse_state = class_base_idx++;

  return true;
}/*}}}*/

// - PARSER print exception -
bool parser_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_FINAL_AUTOMATA_REGULAR_EXPRESSIONS_EMPTY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nArray of regular expressions is empty\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FINAL_AUTOMATA_REGULAR_EXPRESSION_NOT_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected string at position %" HOST_LL_FORMAT "d in array of regular expressions\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FINAL_AUTOMATA_REGULAR_EXPRESSION_PARSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while parsing regular expression at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_UNSPECIFIED_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nReceived unspecified error while creating parser\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_RULES_SYNTAX_ERROR:
  case c_error_PARSER_CREATE_RULES_DUPLICATE_TERMINAL:
  case c_error_PARSER_CREATE_RULES_DUPLICATE_NONTERMINAL:
  case c_error_PARSER_CREATE_RULES_UNDEFINED_TERMINAL:
  case c_error_PARSER_CREATE_RULES_UNDEFINED_NONTERMINAL:
  case c_error_PARSER_CREATE_TERMINAL_REGULAR_EXPRESSION_PARSE_ERROR:
  case c_error_PARSER_CREATE_RULES_DUPLICATE_RULE:
    {
      string_s &rules_source = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);
      unsigned rules_source_pos = exception.params[0];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      fprintf(stderr,"Parser rules string on line: %u\n",rules_source.get_character_line(rules_source_pos));

      switch (exception.type - module.error_base)
      {
      case c_error_PARSER_CREATE_RULES_SYNTAX_ERROR:
        print_error_show_line(rules_source,rules_source_pos);
        fprintf(stderr,"Wrong syntax of parser rules\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_CREATE_RULES_DUPLICATE_TERMINAL:
        print_error_show_line(rules_source,rules_source_pos);
        fprintf(stderr,"Duplicate terminal symbols\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_CREATE_RULES_DUPLICATE_NONTERMINAL:
        print_error_show_line(rules_source,rules_source_pos);
        fprintf(stderr,"Duplicate nonterminal symbols\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_CREATE_RULES_UNDEFINED_TERMINAL:
        print_error_show_line(rules_source,rules_source_pos);
        fprintf(stderr,"Undefined terminal symbol\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_CREATE_RULES_UNDEFINED_NONTERMINAL:
        print_error_show_line(rules_source,rules_source_pos);
        fprintf(stderr,"Undefined nonterminal symbol\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_CREATE_TERMINAL_REGULAR_EXPRESSION_PARSE_ERROR:
        print_error_show_line(rules_source,rules_source_pos);
        fprintf(stderr,"Error while parsing regular expression of terminal symbol\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_CREATE_RULES_DUPLICATE_RULE:
        print_error_line(rules_source,rules_source_pos);
        fprintf(stderr,"\nDuplicate parser grammar rule\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      }
    }
    break;
  case c_error_PARSER_CREATE_RULES_NO_TERMINALS_DEFINED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNo terminals were defined\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_RULES_NO_NONTERMINALS_DEFINED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNo nonterminals were defined\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_RULES_NO_RULES_DEFINED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNo parser grammar rules were defined\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_MULTIPLE_PARSE_END_TERMINALS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMultiple parse end terminals were defined\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_SLR1_PARSE_TABLE_CONFLICT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSLR1 parse table construction conflict\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_CREATE_CANNOT_RESOLVE_RULE_HEAD_FOR_SHIFT_ACTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot resolve target rule head for shift action\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_PARSE_UNRECOGNIZED_TERMINAL:
  case c_error_PARSER_PARSE_SYNTAX_ERROR:
    {
      string_s &src_source = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);
      unsigned src_source_pos = exception.params[0];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      fprintf(stderr,"Source string on line: %u\n",src_source.get_character_line(src_source_pos));

      switch (exception.type - module.error_base)
      {
      case c_error_PARSER_PARSE_UNRECOGNIZED_TERMINAL:
        print_error_show_line(src_source,src_source_pos);
        fprintf(stderr,"Unrecognized terminal in parsed source string\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_PARSER_PARSE_SYNTAX_ERROR:
        print_error_show_line(src_source,src_source_pos);
        fprintf(stderr,"Syntax error in parsed source string\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      }
    }
    break;
  case c_error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nParse state method called outside of reduce callback scope\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PARSER_PARSE_STATE_INDEX_EXCEEDS_RULE_BODY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds rule body range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class FINAL_AUTOMATA -
built_in_class_s final_automata_class =
{/*{{{*/
  "FinalAutomata",
  c_modifier_public | c_modifier_final,
  5, final_automata_methods,
  0, final_automata_variables,
  bic_final_automata_consts,
  bic_final_automata_init,
  bic_final_automata_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s final_automata_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_final_automata_operator_binary_equal
  },
  {
    "FinalAutomata#1",
    c_modifier_public | c_modifier_final,
    bic_final_automata_method_FinalAutomata_1
  },
  {
    "get_source#1",
    c_modifier_public | c_modifier_final,
    bic_final_automata_method_get_source_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_final_automata_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_final_automata_method_print_0
  },
};/*}}}*/

built_in_variable_s final_automata_variables[] =
{/*{{{*/
};/*}}}*/

void bic_final_automata_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_final_automata_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (final_automata_s *)nullptr;
}/*}}}*/

void bic_final_automata_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  final_automata_s *fa_ptr = (final_automata_s *)location_ptr->v_data_ptr;

  if (fa_ptr != nullptr)
  {
    fa_ptr->clear();
    cfree(fa_ptr);
  }
}/*}}}*/

bool bic_final_automata_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_final_automata_method_FinalAutomata_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
reg_expressions:c_bi_class_array
>
method FinalAutomata
; @end

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FINAL_AUTOMATA_REGULAR_EXPRESSIONS_EMPTY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  fa_states_array_s states_array;
  states_array.init();

  reg_parser_s reg_parser;
  reg_parser.init();

  pointer *p_ptr = array_ptr->data;
  pointer *p_ptr_end = p_ptr + array_ptr->used;
  do {
    location_s *item_location = it.get_location_value(*p_ptr);

    // - ERROR -
    if (item_location->v_type != c_bi_class_string)
    {
      reg_parser.clear();
      states_array.clear();

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FINAL_AUTOMATA_REGULAR_EXPRESSION_NOT_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(p_ptr - array_ptr->data);

      return false;
    }

    // - ERROR -
    if (!reg_parser.process_reg_exp(*((string_s *)item_location->v_data_ptr)))
    {
      reg_parser.clear();
      states_array.clear();

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FINAL_AUTOMATA_REGULAR_EXPRESSION_PARSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(p_ptr - array_ptr->data);

      return false;
    }

    states_array.push_blank();
    states_array.last().swap(reg_parser.states);

  } while(++p_ptr < p_ptr_end);

  // - create final automata object -
  final_automata_s *fa_ptr = (final_automata_s *)cmalloc(sizeof(final_automata_s));
  fa_ptr->init();

  // - create final automata -
  fa_ptr->create_new(states_array);

  reg_parser.clear();
  states_array.clear();

  dst_location->v_data_ptr = (final_automata_s *)fa_ptr;

  return true;
}/*}}}*/

bool bic_final_automata_method_get_source_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method get_source
; @end

  // - create fa source object -
  fa_source_s *fs_ptr = (fa_source_s *)cmalloc(sizeof(fa_source_s));
  fs_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  fs_ptr->final_automata_loc = dst_location;

  src_0_location->v_reference_cnt.atomic_inc();
  fs_ptr->source_loc = src_0_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fa_source,fs_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_final_automata_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FinalAutomata"),"FinalAutomata");
  );

  return true;
}/*}}}*/

bool bic_final_automata_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FinalAutomata");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FA_SOURCE -
built_in_class_s fa_source_class =
{/*{{{*/
  "FaSource",
  c_modifier_public | c_modifier_final,
  7, fa_source_methods,
  0, fa_source_variables,
  bic_fa_source_consts,
  bic_fa_source_init,
  bic_fa_source_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s fa_source_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fa_source_operator_binary_equal
  },
  {
    "next_terminal#0",
    c_modifier_public | c_modifier_final,
    bic_fa_source_method_next_terminal_0
  },
  {
    "old_input_idx#0",
    c_modifier_public | c_modifier_final,
    bic_fa_source_method_old_input_idx_0
  },
  {
    "input_idx#0",
    c_modifier_public | c_modifier_final,
    bic_fa_source_method_input_idx_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_fa_source_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fa_source_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fa_source_method_print_0
  },
};/*}}}*/

built_in_variable_s fa_source_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_FA_SOURCE_NEXT_ITEM() \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  fa_source_s *fs_ptr = (fa_source_s *)dst_location->v_data_ptr;\
\
  /* - retrieve final automata and source string - */\
  final_automata_s *fa_ptr = (final_automata_s *)fs_ptr->final_automata_loc->v_data_ptr;\
  string_s *string_ptr = (string_s *)fs_ptr->source_loc->v_data_ptr;\
\
  /* - update old input index - */\
  fs_ptr->old_input_idx = fs_ptr->input_idx;\
\
  unsigned terminal;\
\
  /* - recognize next terminal symbol - */\
  if ((fs_ptr->input_idx < string_ptr->size - 1) &&\
      (terminal = fa_ptr->recognize(string_ptr->data,fs_ptr->input_idx,string_ptr->size - 1)) != c_idx_not_exist)\
  {\
    long long int result = terminal;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
\
  return true;\
}/*}}}*/

void bic_fa_source_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fa_source_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fa_source_s *)nullptr;
}/*}}}*/

void bic_fa_source_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fa_source_s *fs_ptr = (fa_source_s *)location_ptr->v_data_ptr;

  if (fs_ptr != nullptr)
  {
    fs_ptr->clear(it);
    cfree(fs_ptr);
  }
}/*}}}*/

bool bic_fa_source_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fa_source_method_next_terminal_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FA_SOURCE_NEXT_ITEM();
}/*}}}*/

bool bic_fa_source_method_old_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fa_source_s *fs_ptr = (fa_source_s *)dst_location->v_data_ptr;

  long long int result = fs_ptr->old_input_idx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fa_source_method_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fa_source_s *fs_ptr = (fa_source_s *)dst_location->v_data_ptr;

  long long int result = fs_ptr->input_idx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fa_source_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FA_SOURCE_NEXT_ITEM();
}/*}}}*/

bool bic_fa_source_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FaSource"),"FaSource");
  );

  return true;
}/*}}}*/

bool bic_fa_source_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FaSource");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PARSER -
built_in_class_s parser_class =
{/*{{{*/
  "Parser",
  c_modifier_public | c_modifier_final,
  5, parser_methods,
  0, parser_variables,
  bic_parser_consts,
  bic_parser_init,
  bic_parser_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s parser_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_parser_operator_binary_equal
  },
  {
    "Parser#1",
    c_modifier_public | c_modifier_final,
    bic_parser_method_Parser_1
  },
  {
    "parse#2",
    c_modifier_public | c_modifier_final,
    bic_parser_method_parse_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_parser_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_parser_method_print_0
  },
};/*}}}*/

built_in_variable_s parser_variables[] =
{/*{{{*/
};/*}}}*/

void bic_parser_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_parser_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (parser_s *)nullptr;
}/*}}}*/

void bic_parser_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  parser_s *parser_ptr = (parser_s *)location_ptr->v_data_ptr;

  if (parser_ptr != nullptr)
  {
    parser_ptr->clear();
    cfree(parser_ptr);
  }
}/*}}}*/

bool bic_parser_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_parser_method_Parser_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
rules:c_bi_class_string
>
method Parser
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create parser object -
  parser_s *parser_ptr = (parser_s *)cmalloc(sizeof(parser_s));
  parser_ptr->init();

  // - set interpreter thread pointer -
  parser_ptr->it_ptr = &it;

  // - ERROR -
  if (!parser_ptr->create_from_rule_string(*string_ptr))
  {
    parser_ptr->clear();
    cfree(parser_ptr);

    // - retrieve thrown exception -
    exception_s *exception = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;

    // - modify error type and position -
    exception->type += module.error_base;
    exception->position = operands[c_source_pos_idx];

    // - add source string as object to exception -
    it.release_location_ptr((location_s *)exception->obj_location);
    src_0_location->v_reference_cnt.atomic_inc();
    exception->obj_location = src_0_location;

    return false;
  }

  dst_location->v_data_ptr = (parser_s *)parser_ptr;

  return true;
}/*}}}*/

bool bic_parser_method_parse_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
source:c_bi_class_string
delegate:c_bi_class_delegate
>
method parse
; @end

  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - create parse state object -
  parse_state_s *ps_ptr = (parse_state_s *)cmalloc(sizeof(parse_state_s));
  ps_ptr->init();

  // - create parse state location -
  BIC_CREATE_NEW_LOCATION(ps_location,c_bi_class_parse_state,ps_ptr);

  // - set parser state properties -
  ps_ptr->it_ptr = &it;
  ps_ptr->source_pos = operands[c_source_pos_idx];

  dst_location->v_reference_cnt.atomic_inc();
  ps_ptr->parser_loc = dst_location;

  src_0_location->v_reference_cnt.atomic_inc();
  ps_ptr->source_loc = src_0_location;

  // - ERROR -
  bool parser_err;
  if (!ps_ptr->parse_source_string(ps_location,delegate_ptr,parser_err))
  {
    // - release parser state -
    it.release_location_ptr(ps_location);

    // - modify only parser error exceptions -
    if (parser_err)
    {
      // - retrieve thrown exception -
      exception_s *exception = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;

      // - modify error type and position -
      exception->type += module.error_base;
      exception->position = operands[c_source_pos_idx];

      // - add source string as object to exception -
      it.release_location_ptr((location_s *)exception->obj_location);
      src_0_location->v_reference_cnt.atomic_inc();
      exception->obj_location = src_0_location;
    }

    return false;
  }

  // - release parser state -
  it.release_location_ptr(ps_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_parser_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Parser"),"Parser");
  );

  return true;
}/*}}}*/

bool bic_parser_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Parser");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PARSE_STATE -
built_in_class_s parse_state_class =
{/*{{{*/
  "ParseState",
  c_modifier_public | c_modifier_final,
  7, parse_state_methods,
  0, parse_state_variables,
  bic_parse_state_consts,
  bic_parse_state_init,
  bic_parse_state_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s parse_state_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_parse_state_operator_binary_equal
  },
  {
    "rule_idx#0",
    c_modifier_public | c_modifier_final,
    bic_parse_state_method_rule_idx_0
  },
  {
    "rule_body#1",
    c_modifier_public | c_modifier_final,
    bic_parse_state_method_rule_body_1
  },
  {
    "old_input_idx#0",
    c_modifier_public | c_modifier_final,
    bic_parse_state_method_old_input_idx_0
  },
  {
    "input_idx#0",
    c_modifier_public | c_modifier_final,
    bic_parse_state_method_input_idx_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_parse_state_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_parse_state_method_print_0
  },
};/*}}}*/

built_in_variable_s parse_state_variables[] =
{/*{{{*/
};/*}}}*/

void bic_parse_state_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_parse_state_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (parse_state_s *)nullptr;
}/*}}}*/

void bic_parse_state_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  parse_state_s *ps_ptr = (parse_state_s *)location_ptr->v_data_ptr;

  if (ps_ptr != nullptr)
  {
    ps_ptr->clear(it);
    cfree(ps_ptr);
  }
}/*}}}*/

bool bic_parse_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_parse_state_method_rule_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  parse_state_s *ps_ptr = (parse_state_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!ps_ptr->in_reduce_callback)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ps_ptr->parse_action;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_parse_state_method_rule_body_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method rule_body
; @end

  parse_state_s *ps_ptr = (parse_state_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!ps_ptr->in_reduce_callback)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  parser_s &parser = *((parser_s *)ps_ptr->parser_loc->v_data_ptr);
  string_s &source_string = *((string_s *)ps_ptr->source_loc->v_data_ptr);
  lalr_stack_s &lalr_stack = ps_ptr->lalr_stack;

  p_rule_descrs_s &rule_descrs = parser.rule_descrs;

  unsigned rule_body_size = rule_descrs[ps_ptr->parse_action].body_size;

  // - ERROR -
  if (index < 0 || index >= rule_body_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PARSER_PARSE_STATE_INDEX_EXCEEDS_RULE_BODY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - rule_body_size + index];

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(lse.terminal_end - lse.terminal_start,source_string.data + lse.terminal_start);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_parse_state_method_old_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  parse_state_s *ps_ptr = (parse_state_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!ps_ptr->in_reduce_callback)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ps_ptr->old_input_idx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_parse_state_method_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  parse_state_s *ps_ptr = (parse_state_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!ps_ptr->in_reduce_callback)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ps_ptr->input_idx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_parse_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ParseState"),"ParseState");
  );

  return true;
}/*}}}*/

bool bic_parse_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ParseState");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

