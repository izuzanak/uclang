
@begin
include "ucl_parser.h"
@end

/*
 * methods of structure parse_state_s
 */

bool parse_state_s::parse_source_string(location_s *parse_state_loc,delegate_s *delegate_ptr,bool &a_parser_err)
{/*{{{*/
  interpreter_thread_s &it = *it_ptr;
  parser_s &parser = *((parser_s *)parser_loc->v_data_ptr);
  string_s &source_string = *((string_s *)source_loc->v_data_ptr);

  unsigned &end_terminal = parser.end_terminal;
  ui_array_s &skip_terminals = parser.skip_terminals;
  p_rule_descrs_s &rule_descrs = parser.rule_descrs;
  final_automata_s &final_automata = parser.final_automata;
  p_lalr_table_s &lalr_table = parser.lalr_table;

  // - vychozi nastaveni lalr_stavoveho zasobniku -
  lalr_stack.used = 0;
  lalr_stack.push(0,0,0);

  // - reset parser error flag -
  a_parser_err = false;

  // - promenne popisujici stav konecneho lexikalniho automatu -
  old_input_idx = 0;
  input_idx = 0;
  unsigned input_length = source_string.size - 1;
  unsigned ret_term = c_idx_not_exist;

  do
  {
    // - rozpoznani dalsiho terminalu na vstupu -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = final_automata.recognize(source_string.data,input_idx,input_length);

      // - ERROR -
      if (ret_term == c_idx_not_exist)
      {
        a_parser_err = true;

        exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_PARSE_UNRECOGNIZED_TERMINAL,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
      }

      if (skip_terminals.get_idx(ret_term) != c_idx_not_exist)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - nalezeni akce v tabulce akci -
    parse_action = lalr_table.value(ret_term,lalr_stack.last().lalr_state);

    // - ERROR -
    if (parse_action == c_idx_not_exist)
    {
      a_parser_err = true;

      exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_PARSE_SYNTAX_ERROR,0,(location_s *)it.blank_location);
      new_exception->params.push(old_input_idx);

      return false;
    }

    // - akce SHIFT -
    if (parse_action < c_lalr_table_reduce_base)
    {
      // - kdyz byl prijmut koncovy terminal ukonci rozklad -
      if (ret_term == end_terminal)
      {
        break;
      }

      // - vlozi na zasobnik novy stav a pozici terminalu ve zdrojovem retezci -
      lalr_stack.push(parse_action,old_input_idx,input_idx);

      ret_term = c_idx_not_exist;
    }

    // - akce REDUCE -
    else
    {
      parse_action -= c_lalr_table_reduce_base;

      {
        // - set in reduce callback flag -
        in_reduce_callback = true;

        // - call delegate method -
        location_s *trg_location = NULL;
        BIC_CALL_DELEGATE(it,delegate_ptr,(void **)&parse_state_loc,1,trg_location,source_pos,
          return false
        );

        it.release_location_ptr(trg_location);

        // - reset in reduce callback flag -
        in_reduce_callback = false;
      }

      p_rule_descr_s &rule_descr = rule_descrs[parse_action];

      // - retrieve nonterminal start and end -
      unsigned nonterm_start = lalr_stack[lalr_stack.used - rule_descr.body_size].terminal_start;
      unsigned nonterm_end = lalr_stack.last().terminal_end;

      lalr_stack.used -= rule_descr.body_size;

      unsigned goto_val = lalr_table.value(rule_descr.head,lalr_stack.last().lalr_state);
      lalr_stack.push(goto_val,nonterm_start,nonterm_end);
    }
  }
  while(1);

  return true;
}/*}}}*/

