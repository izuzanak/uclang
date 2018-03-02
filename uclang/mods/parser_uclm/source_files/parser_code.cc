
@begin
include "parser_code.h"
@end

// - basic constants and definitions -

// parse constants
const unsigned reg_rule_head_idxs[c_reg_rule_cnt] = {17, 18, 18, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, };
const unsigned reg_rule_body_lengths[c_reg_rule_cnt] = {2, 3, 1, 3, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, };

// lalr parse table

const unsigned reg_lalr_table[c_reg_lalr_state_cnt*c_reg_terminal_plus_nonterminal_cnt] =
{/*{{{*/
  REG_SHIFT(4),    REG_SHIFT(6),    REG_SHIFT(7),    REG_SHIFT(8),    REG_SHIFT(5),    REG_SHIFT(9),   REG_SHIFT(10),   REG_SHIFT(11),   REG_SHIFT(12),   REG_SHIFT(13),   REG_SHIFT(14),       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,     REG_GOTO(1),     REG_GOTO(2),     REG_GOTO(3),
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_SHIFT(15),       reg_blank,   REG_SHIFT(16),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(2),       reg_blank,   REG_SHIFT(17),   REG_REDUCE(2),       reg_blank,   REG_REDUCE(2),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(4),   REG_SHIFT(18),   REG_REDUCE(4),   REG_REDUCE(4),       reg_blank,   REG_REDUCE(4),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(6),   REG_REDUCE(6),   REG_REDUCE(6),   REG_REDUCE(6),       reg_blank,   REG_REDUCE(6),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(7),   REG_REDUCE(7),   REG_REDUCE(7),   REG_REDUCE(7),       reg_blank,   REG_REDUCE(7),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(8),   REG_REDUCE(8),   REG_REDUCE(8),   REG_REDUCE(8),       reg_blank,   REG_REDUCE(8),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(9),   REG_REDUCE(9),   REG_REDUCE(9),   REG_REDUCE(9),       reg_blank,   REG_REDUCE(9),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(10),  REG_REDUCE(10),  REG_REDUCE(10),  REG_REDUCE(10),       reg_blank,  REG_REDUCE(10),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(11),  REG_REDUCE(11),  REG_REDUCE(11),  REG_REDUCE(11),       reg_blank,  REG_REDUCE(11),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(12),  REG_REDUCE(12),  REG_REDUCE(12),  REG_REDUCE(12),       reg_blank,  REG_REDUCE(12),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(13),  REG_REDUCE(13),  REG_REDUCE(13),  REG_REDUCE(13),       reg_blank,  REG_REDUCE(13),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(14),  REG_REDUCE(14),  REG_REDUCE(14),  REG_REDUCE(14),       reg_blank,  REG_REDUCE(14),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(15),  REG_REDUCE(15),  REG_REDUCE(15),  REG_REDUCE(15),       reg_blank,  REG_REDUCE(15),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  REG_SHIFT(4),    REG_SHIFT(6),    REG_SHIFT(7),    REG_SHIFT(8),    REG_SHIFT(5),    REG_SHIFT(9),   REG_SHIFT(10),   REG_SHIFT(11),   REG_SHIFT(12),   REG_SHIFT(13),   REG_SHIFT(14),       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,    REG_GOTO(19),     REG_GOTO(2),     REG_GOTO(3),
  REG_SHIFT(4),    REG_SHIFT(6),    REG_SHIFT(7),    REG_SHIFT(8),    REG_SHIFT(5),    REG_SHIFT(9),   REG_SHIFT(10),   REG_SHIFT(11),   REG_SHIFT(12),   REG_SHIFT(13),   REG_SHIFT(14),       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,    REG_GOTO(20),     REG_GOTO(2),     REG_GOTO(3),
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  REG_SHIFT(4),    REG_SHIFT(6),    REG_SHIFT(7),    REG_SHIFT(8),    REG_SHIFT(5),    REG_SHIFT(9),   REG_SHIFT(10),   REG_SHIFT(11),   REG_SHIFT(12),   REG_SHIFT(13),   REG_SHIFT(14),       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,    REG_GOTO(21),     REG_GOTO(3),
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(5),   REG_REDUCE(5),   REG_REDUCE(5),   REG_REDUCE(5),       reg_blank,   REG_REDUCE(5),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_SHIFT(22),       reg_blank,       reg_blank,   REG_SHIFT(15),       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(1),       reg_blank,       reg_blank,   REG_SHIFT(15),       reg_blank,   REG_REDUCE(1),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,   REG_REDUCE(3),       reg_blank,   REG_SHIFT(17),   REG_REDUCE(3),       reg_blank,   REG_REDUCE(3),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
  reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,       reg_blank,  REG_REDUCE(16),  REG_REDUCE(16),  REG_REDUCE(16),  REG_REDUCE(16),       reg_blank,  REG_REDUCE(16),       reg_blank,       reg_blank,       reg_blank,       reg_blank,
};/*}}}*/

/*
 * terminals read from file describing rules
 */
enum
{
  rt_space = 0,
  rt_comment,
  rt_sec_comment,
  rt_input_end,
  rt_init_code,
  rt_terminals,
  rt_nonterminals,
  rt_rules,
  rt_div_0,
  rt_div_1,
  rt_identifier,
  rt_nonterm_id,
  rt_code
};

/*
 * regular expressions describing terminals in rule file
 */
const unsigned test_reg_exp_cnt = 13;
const char *test_reg_exps[test_reg_exp_cnt] =
{
  "w.w*",//"\\w\\w\\*",
  "'$'.!'\\n'*.'\\n'",//"$\\!\\n\\*\\n",
  "'#'.!'\\n'*.'\\n'",//"#\\!\\n\\*\\n",
  "'\\0'",//"\\0",
  "\"init_code:\"",//"init_code:",
  "\"terminals:\"",//"terminals:",
  "\"nonterminals:\"",//"nonterminals:",
  "\"rules:\"",//"rules:",
  "\"->\"",//"->",
  "\"->>\"",//"->>",
  "('_'+l).('_'+l+d)*",//"\\[_\\l\\]\\[_\\l\\d\\]\\*",
  "'<'.('_'+l).('_'+l+d)*.'>'",//"<\\[_\\l\\]\\[_\\l\\d\\]\\*>",
  "'{'.((|\\\\}|)+('\\\\'.!'\\0'))*.'}'"//"'{'.!'}'*.'}'"//"{\\!}\\*}"
};

/*
 * indexes of terminals with special function
 * ktt_skip - ignored by parser
 * ktt_end - terminating parser
 */
enum
{
  ktt_skip,
  ktt_end
};

/*
 * string describing terminal with special meaning for parser
 */
const unsigned c_key_terminal_cnt = 2;
const char *key_terminals[c_key_terminal_cnt] =
{
  "'_'*.\"SKIP\".'_'*",//"_\\*SKIP_\\*",
  "\"_END_\""//"_END_"
};

/*
 * methods of generated structures
 */

// -- bb_array_s --
@begin
methods bb_array_s
@end

// -- ui_array_set_s --
@begin
methods ui_array_set_s
@end

bool ui_array_set_s::set_compare(ui_array_set_s &second)
{/*{{{*/
  if (used != second.used) { return false; }
  if (used == 0) { return true; }

  unsigned *ptr = data;
  unsigned *ptr_end = ptr + used;

  do
  {
    unsigned *s_ptr = second.data;
    unsigned *s_ptr_end = s_ptr + second.used;

    do
    {
      if (*s_ptr == *ptr)
      {
        break;
      }
    }
    while(++s_ptr < s_ptr_end);

    if (s_ptr >= s_ptr_end)
    {
      return false;
    }
  }
  while(++ptr < ptr_end);

  return true;
}/*}}}*/

void ui_array_set_s::add_to_set(p_follow_set_s &add_set)
{/*{{{*/
  if (add_set.used == 0)
  {
    return;
  }

  unsigned *a_ptr = add_set.data;
  unsigned *a_ptr_end = a_ptr + add_set.used;

  do
  {
    bool exist = false;

    if (used != 0)
    {
      unsigned *ptr = data;
      unsigned *ptr_end = ptr + used;

      do
      {
        if (*ptr == *a_ptr)
        {
          exist = true;
          break;
        }
      }
      while(++ptr < ptr_end);
    }

    if (!exist)
    {
      push(*a_ptr);
    }
  }
  while(++a_ptr < a_ptr_end);
}/*}}}*/

// -- ui_array_sets_s --
@begin
methods ui_array_sets_s
@end

// -- ui_array_sets_array_s --
@begin
methods ui_array_sets_array_s
@end

// -- reg_mul_state_move_s --
@begin
methods reg_mul_state_move_s
@end

// -- reg_mul_state_move_array_s --
@begin
methods reg_mul_state_move_array_s
@end

unsigned reg_mul_state_move_array_s::get_idx_by_move_char(unsigned short a_move_char)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  reg_mul_state_move_s *ptr = data;
  reg_mul_state_move_s *ptr_end = ptr + used;

  do
  {
    if (ptr->move_char == a_move_char)
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

// -- reg_mul_state_move_queue_s --
@begin
methods reg_mul_state_move_queue_s
@end

// -- reg_mul_state_map_s --
@begin
methods reg_mul_state_map_s
@end

// -- reg_mul_state_map_array_s --
@begin
methods reg_mul_state_map_array_s
@end

unsigned reg_mul_state_map_array_s::get_idx_by_mul_state(ui_array_set_s &a_mul_state)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  reg_mul_state_map_s *ptr = data;
  reg_mul_state_map_s *ptr_end = ptr + used;

  do
  {
    if (ptr->mul_state.set_compare(a_mul_state))
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

// -- fa_state_move_s --
@begin
methods fa_state_move_s
@end

// -- fa_state_moves_s --
@begin
methods fa_state_moves_s
@end

unsigned fa_state_moves_s::get_map_idx(fa_state_move_s &a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  fa_state_move_s *ptr = data;
  fa_state_move_s *ptr_end = data + used;

  do
  {
    if (ptr->idx == a_value.idx)
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

// -- fa_state_moves_array_s --
@begin
methods fa_state_moves_array_s
@end

// -- us_array_s --
@begin
methods us_array_s
@end

// -- fa_state_s --
@begin
methods fa_state_s
@end

// -- fa_states_s --
@begin
methods fa_states_s
@end

// -- fa_states_array_s --
@begin
methods fa_states_array_s
@end

// -- reg_state_s --
@begin
methods reg_state_s
@end

// -- reg_states_s --
@begin
methods reg_states_s
@end

// -- fa_state_descr_s --
@begin
methods fa_state_descr_s
@end

// -- fa_state_reg_states_s --
@begin
methods fa_state_reg_states_s
@end

// -- fa_state_descr_queue_s --
@begin
methods fa_state_descr_queue_s
@end

// -- final_automata_s --
@begin
methods final_automata_s
@end

void final_automata_s::create_new(fa_states_array_s &states_array)
{/*{{{*/
  cassert(states_array.used != 0);

  clear();

  // - queue of new states descriptions -
  fa_state_descr_queue_s queue;
  queue.init();

  fa_state_reg_states_s state_descrs;
  state_descrs.init();

  // - array of moves used by one state -
  fa_state_moves_array_s moves_array;
  moves_array.init();

  // - work stack shared by called functions -
  ui_array_s work_stack;
  work_stack.init();

  // - description of new produced automata state -
  fa_state_descr_s new_state_descr;
  new_state_descr.init();

  // - insert first record to queue of new states description -
  {
    /*
     * source state does not exist for first state. set of regular expressions
     * contains all of them with index at position zero
     */
    queue.insert_blank();
    queue.last().from_state_id = c_idx_not_exist;
    reg_states_s &init_reg_states = queue.last().reg_states;
    init_reg_states.copy_resize(states_array.used);

    unsigned idx = 0;
    do
    {
      init_reg_states.push_blank();
      init_reg_states[idx].set(idx,0);
    }
    while(++idx < states_array.used);
  }

  // - loop while queue of news states is not empty -
  do
  {
    // - retrieve description of next state from queue -
    fa_state_descr_s q_state_descr;
    q_state_descr.init();
    q_state_descr.swap(queue.next());

    // - test if such state is not defined already -
    unsigned state_descr_idx = state_descrs.get_idx(q_state_descr.reg_states);
    if (state_descr_idx != c_idx_not_exist)
    {
      /*
       * if yes, retrieve source state for this state, retrieve move index in
       * source state that matches move character, and in source state for this
       * state set as target state already defined state
       *
       * continue at loop beginning
       */
      fa_state_s &state = states[q_state_descr.from_state_id];

      fa_state_move_s s_move;
      s_move.idx = q_state_descr.with_char;

      unsigned move_idx = state.moves.get_map_idx(s_move);
      cassert(move_idx != c_idx_not_exist);
      state.moves[move_idx].value = state_descr_idx;

      q_state_descr.clear();
      continue;
    }

    // - create new state of automata, create reference to its end terminal and set of moves-
    states.push_blank();
    unsigned &state_final = states.last().final;
    state_final = c_idx_not_exist;
    fa_state_moves_s &state_moves = states.last().moves;

    // - set moves to this state -
    reg_states_s &p_reg_states = q_state_descr.reg_states;
    cassert(p_reg_states.used != 0);

    // - if source state exists -
    if (q_state_descr.from_state_id != c_idx_not_exist)
    {
      // - set move from source state to this state -
      fa_state_s &from_state = states[q_state_descr.from_state_id];

      fa_state_move_s s_move;
      s_move.idx = q_state_descr.with_char;

      unsigned move_idx = from_state.moves.get_map_idx(s_move);
      cassert(move_idx != c_idx_not_exist);
      from_state.moves[move_idx].value = states.used - 1;
    }

    // - generate array of moves from actual regexp positions -
    moves_array.used = 0;
    reg_state_s *p_reg_state_ptr = p_reg_states.data;
    reg_state_s *p_reg_state_ptr_end = p_reg_state_ptr + p_reg_states.used;

    // - loop through regexp list, and generation of possible moves set -
    do
    {
      moves_array.push_blank();

      fa_state_s &state = states_array[p_reg_state_ptr->ui_first][p_reg_state_ptr->ui_second];
      moves_array.last() = state.moves;

      // - assign regexp to final state -
      if (state.final)
      {
        if (state_final == c_idx_not_exist || moves_array.last().used == 0)
        {
          state_final = p_reg_state_ptr->ui_first;
        }
      }

    }
    while(++p_reg_state_ptr < p_reg_state_ptr_end);

    do
    {
      unsigned short move_char = 0xffff;

      // - get next move character from set -
      fa_state_moves_s *moves_ptr = moves_array.data;
      fa_state_moves_s *moves_ptr_end = moves_ptr + moves_array.used;

      do
      {
        if (moves_ptr->used > 0)
        {
          fa_state_move_s *move_ptr = moves_ptr->data;
          fa_state_move_s *move_ptr_end = move_ptr + moves_ptr->used;

          do
          {
            if (move_ptr->idx < move_char)
            {
              move_char = move_ptr->idx;
            }
          }
          while(++move_ptr < move_ptr_end);
        }
      }
      while(++moves_ptr < moves_ptr_end);

      if (move_char == 0xffff)
      {
        break;
      }

      // - add new move from state without identification of target state -
      state_moves.push_blank();
      state_moves.last().idx = move_char;

      // - create description of move target state -
      new_state_descr.from_state_id = states.used - 1;
      new_state_descr.with_char = move_char;
      reg_states_s &new_reg_states = new_state_descr.reg_states;

      new_reg_states.used = 0;

      // - found and process all moves by this character -
      p_reg_state_ptr = p_reg_states.data;
      moves_ptr = moves_array.data;
      moves_ptr_end = moves_ptr + moves_array.used;

      // - loop through all moves -
      do
      {
        if (moves_ptr->used > 0)
        {
          fa_state_move_s *move_ptr = moves_ptr->data;
          fa_state_move_s *move_ptr_end = move_ptr + moves_ptr->used;

          do
          {
            if (move_ptr->idx != 0xffff)
            {
              unsigned short ptr_char = move_ptr->idx;
              bool match = false;
              bool eq_match = false;

              if (ptr_char >= c_no_char_base)
              {
                if (move_char == ptr_char)
                {
                  eq_match = true;
                }
                else if (move_char != (ptr_char - c_no_char_base))
                {
                  match = true;
                }
              }
              else if (ptr_char == reg_char_digit)
              {
                if (move_char == reg_char_digit)
                {
                  eq_match = true;
                }
                else if (move_char >= '0' && move_char <= '9')
                {
                  match = true;
                }
              }
              else if (ptr_char == reg_char_letter)
              {
                if (move_char == reg_char_letter)
                {
                  eq_match = true;
                }
                else if ((move_char >= 'a' && move_char <= 'z') || (move_char >= 'A' && move_char <= 'Z'))
                {
                  match = true;
                }
              }
              else if (ptr_char == reg_char_white)
              {
                if (move_char == reg_char_white)
                {
                  eq_match = true;
                }
                else if (move_char == ' ' || move_char == '\t' || move_char == '\n')
                {
                  match = true;
                }
              }
              else if (ptr_char == move_char)
              {
                eq_match = true;
              }

              if (eq_match || match)
              {
                new_reg_states.push_blank();
                new_reg_states.last().set(p_reg_state_ptr->ui_first,move_ptr->value);

                if (eq_match)
                {
                  move_ptr->idx = 0xffff;
                }
              }
            }
          }
          while(++move_ptr < move_ptr_end);
        }
      }
      while(++p_reg_state_ptr,++moves_ptr < moves_ptr_end);

      // - insert new state description to queue of new states descriptions -
      queue.insert_blank();
      queue.last().swap(new_state_descr);
    }
    while(1);

    // - store description of accepted state, for state existence control -
    state_descrs.push_blank();
    state_descrs.last().swap(q_state_descr.reg_states);
    q_state_descr.clear();

  }
  while(queue.used > 0);

  // - flush redundant memory -
  states.flush();

  // - release dynamically allocated memory -
  new_state_descr.clear();
  work_stack.clear();
  moves_array.clear();
  state_descrs.clear();
  queue.clear();

  /*
   * creates effective set of transitions
   */

  state_moves.copy_resize(states.used);

  // - loop through all automata states -
  if (states.used != 0)
  {
    fa_state_s *state_ptr = states.data;
    fa_state_s *state_ptr_end = state_ptr + states.used;

    do
    {
      state_moves.push_blank();
      ui_array_s &moves = state_moves.last();

      moves.init();
      moves.copy_resize(c_base_char_cnt);
      moves.fill(c_idx_not_exist);

      // - loop through all state moves and creation of transition table -
      if (state_ptr->moves.used != 0)
      {
        fa_state_move_s *move_ptr = state_ptr->moves.data;
        fa_state_move_s *move_ptr_end = move_ptr + state_ptr->moves.used;

        do
        {
          if (move_ptr->idx < c_base_char_cnt)
          {
            moves[move_ptr->idx] = move_ptr->value;
          }
          else
          {
            // - process special regular expressions -
            if (move_ptr->idx >= c_no_char_base)
            {
              unsigned *mt_ptr = moves.data;
              unsigned *mt_ptr_end = moves.data + (move_ptr->idx - c_no_char_base);

              do
              {
                if (*mt_ptr == c_idx_not_exist)
                {
                  *mt_ptr = move_ptr->value;
                }
              }
              while(++mt_ptr < mt_ptr_end);

              mt_ptr = mt_ptr_end + 1;
              mt_ptr_end = moves.data + moves.used;

              do
              {
                if (*mt_ptr == c_idx_not_exist)
                {
                  *mt_ptr = move_ptr->value;
                }
              }
              while(++mt_ptr < mt_ptr_end);
            }
            else
            {
              switch (move_ptr->idx)
              {
              case reg_char_white:
              {
                unsigned *mt_ptr = moves.data + ' ';
                if (*mt_ptr == c_idx_not_exist)
                {
                  *mt_ptr = move_ptr->value;
                }

                mt_ptr = moves.data + '\t';
                if (*mt_ptr == c_idx_not_exist)
                {
                  *mt_ptr = move_ptr->value;
                }

                mt_ptr = moves.data + '\n';
                if (*mt_ptr == c_idx_not_exist)
                {
                  *mt_ptr = move_ptr->value;
                }
              }
              break;
              case reg_char_digit:
              {
                unsigned *mt_ptr = moves.data + '0';
                unsigned *mt_ptr_end = moves.data + '9' + 1;

                do
                {
                  if (*mt_ptr == c_idx_not_exist)
                  {
                    *mt_ptr = move_ptr->value;
                  }
                }
                while(++mt_ptr < mt_ptr_end);
              }
              break;
              case reg_char_letter:
              {
                unsigned *mt_ptr = moves.data + 'a';
                unsigned *mt_ptr_end = moves.data + 'z' + 1;

                do
                {
                  if (*mt_ptr == c_idx_not_exist)
                  {
                    *mt_ptr = move_ptr->value;
                  }
                }
                while(++mt_ptr < mt_ptr_end);

                mt_ptr = moves.data + 'A';
                mt_ptr_end = moves.data + 'Z' + 1;

                do
                {
                  if (*mt_ptr == c_idx_not_exist)
                  {
                    *mt_ptr = move_ptr->value;
                  }
                }
                while(++mt_ptr < mt_ptr_end);
              }
              break;
              default:
                cassert(0);
              }
            }
          }
        }
        while(++move_ptr < move_ptr_end);
      }

    }
    while(++state_ptr < state_ptr_end);
  }
}/*}}}*/

unsigned final_automata_s::recognize(char *input,unsigned &input_idx,unsigned input_length)
{/*{{{*/
  debug_assert(input != nullptr);

  // - set first state -
  state_idx = 0;

  // - endless loop searching for terminal symbol -
  do
  {
    // - retrieve reference to actual state and reset next state index -
    fa_state_s &state = states[state_idx];
    unsigned next_state_idx = c_idx_not_exist;

    // - process next input character -
    unsigned short in_char;
    if (input_idx < input_length)
    {
      in_char = (unsigned char)input[input_idx];
    }
    else
    {
      in_char = '\0';
    }

    // - retrieve next state index -
    next_state_idx = state_moves[state_idx][in_char];

    // - transition to next state if it exists -
    if (next_state_idx != c_idx_not_exist)
    {
      // - input end -
      if (in_char == '\0')
      {
        return states[next_state_idx].final;
      }

      input_idx++;

      state_idx = next_state_idx;
    }

    // - if there is no next state -
    else
    {
      return state.final;
    }
  }
  while(1);
}/*}}}*/

// -- reg_parser_s --
@begin
methods reg_parser_s
@end

unsigned reg_parser_s::recognize_terminal(string_s &source_string,unsigned &input_idx)
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define GET_NEXT_CHAR() \
  {\
    if (input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
    \
    input_idx++;\
  }

  unsigned short in_char;

// - STATE 0 -
  GET_NEXT_CHAR();

  if (in_char == 0)
    goto state_1_label;

  if (in_char >= 9 && in_char < 11)
    goto state_17_label;

  if (in_char == 32)
    goto state_17_label;

  if (in_char == 33)
    goto state_2_label;

  if (in_char == 34)
    goto state_3_label;

  if (in_char == 39)
    goto state_4_label;

  if (in_char == 40)
    goto state_5_label;

  if (in_char == 41)
    goto state_6_label;

  if (in_char == 42)
    goto state_7_label;

  if (in_char == 43)
    goto state_8_label;

  if (in_char == 46)
    goto state_9_label;

  if (in_char == 60)
    goto state_10_label;

  if (in_char == 91)
    goto state_11_label;

  if (in_char == 100)
    goto state_12_label;

  if (in_char == 101)
    goto state_13_label;

  if (in_char == 108)
    goto state_14_label;

  if (in_char == 119)
    goto state_15_label;

  if (in_char == 124)
    goto state_16_label;

  return c_idx_not_exist;

// - STATE 1 -
state_1_label:
  CLOSE_CHAR(16);
  return 16;

// - STATE 2 -
state_2_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_18_label;

  return c_idx_not_exist;

// - STATE 3 -
state_3_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 34)
    goto state_3_label;

  if (in_char == 34)
    goto state_19_label;

  if (in_char >= 35 && in_char < 92)
    goto state_3_label;

  if (in_char == 92)
    goto state_20_label;

  if (in_char >= 93 && in_char < 256)
    goto state_3_label;

  return c_idx_not_exist;

// - STATE 4 -
state_4_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_22_label;

  if (in_char == 92)
    goto state_21_label;

  if (in_char >= 93 && in_char < 256)
    goto state_22_label;

  return c_idx_not_exist;

// - STATE 5 -
state_5_label:
  CLOSE_CHAR(10);
  return 10;

// - STATE 6 -
state_6_label:
  CLOSE_CHAR(11);
  return 11;

// - STATE 7 -
state_7_label:
  CLOSE_CHAR(12);
  return 12;

// - STATE 8 -
state_8_label:
  CLOSE_CHAR(14);
  return 14;

// - STATE 9 -
state_9_label:
  CLOSE_CHAR(13);
  return 13;

// - STATE 10 -
state_10_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_24_label;

  if (in_char == 92)
    goto state_23_label;

  if (in_char >= 93 && in_char < 256)
    goto state_24_label;

  return c_idx_not_exist;

// - STATE 11 -
state_11_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_26_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 12 -
state_12_label:
  CLOSE_CHAR(2);
  return 2;

// - STATE 13 -
state_13_label:
  CLOSE_CHAR(0);
  return 0;

// - STATE 14 -
state_14_label:
  CLOSE_CHAR(3);
  return 3;

// - STATE 15 -
state_15_label:
  CLOSE_CHAR(1);
  return 1;

// - STATE 16 -
state_16_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_28_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 17 -
state_17_label:
  CLOSE_CHAR(15);
  GET_NEXT_CHAR();

  if (in_char >= 9 && in_char < 11)
    goto state_17_label;

  if (in_char == 32)
    goto state_17_label;

  return 15;

// - STATE 18 -
state_18_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_30_label;

  if (in_char == 92)
    goto state_29_label;

  if (in_char >= 93 && in_char < 256)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 19 -
state_19_label:
  CLOSE_CHAR(6);
  return 6;

// - STATE 20 -
state_20_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_3_label;

  if (in_char == 39)
    goto state_3_label;

  if (in_char >= 48 && in_char < 56)
    goto state_31_label;

  if (in_char >= 62 && in_char < 64)
    goto state_3_label;

  if (in_char >= 92 && in_char < 94)
    goto state_3_label;

  if (in_char >= 97 && in_char < 99)
    goto state_3_label;

  if (in_char == 102)
    goto state_3_label;

  if (in_char == 110)
    goto state_3_label;

  if (in_char == 114)
    goto state_3_label;

  if (in_char == 116)
    goto state_3_label;

  if (in_char == 118)
    goto state_3_label;

  if (in_char == 120)
    goto state_32_label;

  if (in_char >= 124 && in_char < 126)
    goto state_3_label;

  return c_idx_not_exist;

// - STATE 21 -
state_21_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_22_label;

  if (in_char == 39)
    goto state_22_label;

  if (in_char >= 48 && in_char < 56)
    goto state_33_label;

  if (in_char >= 62 && in_char < 64)
    goto state_22_label;

  if (in_char >= 92 && in_char < 94)
    goto state_22_label;

  if (in_char >= 97 && in_char < 99)
    goto state_22_label;

  if (in_char == 102)
    goto state_22_label;

  if (in_char == 110)
    goto state_22_label;

  if (in_char == 114)
    goto state_22_label;

  if (in_char == 116)
    goto state_22_label;

  if (in_char == 118)
    goto state_22_label;

  if (in_char == 120)
    goto state_34_label;

  if (in_char >= 124 && in_char < 126)
    goto state_22_label;

  return c_idx_not_exist;

// - STATE 22 -
state_22_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_35_label;

  return c_idx_not_exist;

// - STATE 23 -
state_23_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_24_label;

  if (in_char == 39)
    goto state_24_label;

  if (in_char >= 48 && in_char < 56)
    goto state_36_label;

  if (in_char >= 62 && in_char < 64)
    goto state_24_label;

  if (in_char >= 92 && in_char < 94)
    goto state_24_label;

  if (in_char >= 97 && in_char < 99)
    goto state_24_label;

  if (in_char == 102)
    goto state_24_label;

  if (in_char == 110)
    goto state_24_label;

  if (in_char == 114)
    goto state_24_label;

  if (in_char == 116)
    goto state_24_label;

  if (in_char == 118)
    goto state_24_label;

  if (in_char == 120)
    goto state_37_label;

  if (in_char >= 124 && in_char < 126)
    goto state_24_label;

  return c_idx_not_exist;

// - STATE 24 -
state_24_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 256)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 25 -
state_25_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 26 -
state_26_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_25_label;

  if (in_char == 39)
    goto state_25_label;

  if (in_char >= 48 && in_char < 56)
    goto state_42_label;

  if (in_char >= 62 && in_char < 64)
    goto state_25_label;

  if (in_char >= 92 && in_char < 94)
    goto state_25_label;

  if (in_char >= 97 && in_char < 99)
    goto state_25_label;

  if (in_char == 102)
    goto state_25_label;

  if (in_char == 110)
    goto state_25_label;

  if (in_char == 114)
    goto state_25_label;

  if (in_char == 116)
    goto state_25_label;

  if (in_char == 118)
    goto state_25_label;

  if (in_char == 120)
    goto state_43_label;

  if (in_char >= 124 && in_char < 126)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 27 -
state_27_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 28 -
state_28_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_27_label;

  if (in_char == 39)
    goto state_27_label;

  if (in_char >= 48 && in_char < 56)
    goto state_46_label;

  if (in_char >= 62 && in_char < 64)
    goto state_27_label;

  if (in_char >= 92 && in_char < 94)
    goto state_27_label;

  if (in_char >= 97 && in_char < 99)
    goto state_27_label;

  if (in_char == 102)
    goto state_27_label;

  if (in_char == 110)
    goto state_27_label;

  if (in_char == 114)
    goto state_27_label;

  if (in_char == 116)
    goto state_27_label;

  if (in_char == 118)
    goto state_27_label;

  if (in_char == 120)
    goto state_47_label;

  if (in_char >= 124 && in_char < 126)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 29 -
state_29_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_30_label;

  if (in_char == 39)
    goto state_30_label;

  if (in_char >= 48 && in_char < 56)
    goto state_48_label;

  if (in_char >= 62 && in_char < 64)
    goto state_30_label;

  if (in_char >= 92 && in_char < 94)
    goto state_30_label;

  if (in_char >= 97 && in_char < 99)
    goto state_30_label;

  if (in_char == 102)
    goto state_30_label;

  if (in_char == 110)
    goto state_30_label;

  if (in_char == 114)
    goto state_30_label;

  if (in_char == 116)
    goto state_30_label;

  if (in_char == 118)
    goto state_30_label;

  if (in_char == 120)
    goto state_49_label;

  if (in_char >= 124 && in_char < 126)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 30 -
state_30_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_50_label;

  return c_idx_not_exist;

// - STATE 31 -
state_31_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 34)
    goto state_3_label;

  if (in_char == 34)
    goto state_19_label;

  if (in_char >= 35 && in_char < 48)
    goto state_3_label;

  if (in_char >= 48 && in_char < 56)
    goto state_51_label;

  if (in_char >= 56 && in_char < 92)
    goto state_3_label;

  if (in_char == 92)
    goto state_20_label;

  if (in_char >= 93 && in_char < 256)
    goto state_3_label;

  return c_idx_not_exist;

// - STATE 32 -
state_32_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_52_label;

  if (in_char >= 65 && in_char < 71)
    goto state_52_label;

  if (in_char >= 97 && in_char < 103)
    goto state_52_label;

  return c_idx_not_exist;

// - STATE 33 -
state_33_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_35_label;

  if (in_char >= 48 && in_char < 56)
    goto state_53_label;

  return c_idx_not_exist;

// - STATE 34 -
state_34_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_54_label;

  if (in_char >= 65 && in_char < 71)
    goto state_54_label;

  if (in_char >= 97 && in_char < 103)
    goto state_54_label;

  return c_idx_not_exist;

// - STATE 35 -
state_35_label:
  CLOSE_CHAR(4);
  return 4;

// - STATE 36 -
state_36_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_39_label;

  if (in_char >= 48 && in_char < 56)
    goto state_55_label;

  if (in_char >= 56 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 256)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 37 -
state_37_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_56_label;

  if (in_char >= 65 && in_char < 71)
    goto state_56_label;

  if (in_char >= 97 && in_char < 103)
    goto state_56_label;

  return c_idx_not_exist;

// - STATE 38 -
state_38_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_39_label;

  if (in_char == 39)
    goto state_39_label;

  if (in_char >= 48 && in_char < 56)
    goto state_57_label;

  if (in_char >= 62 && in_char < 64)
    goto state_39_label;

  if (in_char >= 92 && in_char < 94)
    goto state_39_label;

  if (in_char >= 97 && in_char < 99)
    goto state_39_label;

  if (in_char == 102)
    goto state_39_label;

  if (in_char == 110)
    goto state_39_label;

  if (in_char == 114)
    goto state_39_label;

  if (in_char == 116)
    goto state_39_label;

  if (in_char == 118)
    goto state_39_label;

  if (in_char == 120)
    goto state_58_label;

  if (in_char >= 124 && in_char < 126)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 39 -
state_39_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 62)
    goto state_59_label;

  return c_idx_not_exist;

// - STATE 40 -
state_40_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_25_label;

  if (in_char == 39)
    goto state_25_label;

  if (in_char >= 48 && in_char < 56)
    goto state_60_label;

  if (in_char >= 62 && in_char < 64)
    goto state_25_label;

  if (in_char >= 92 && in_char < 94)
    goto state_25_label;

  if (in_char >= 97 && in_char < 99)
    goto state_25_label;

  if (in_char == 102)
    goto state_25_label;

  if (in_char == 110)
    goto state_25_label;

  if (in_char == 114)
    goto state_25_label;

  if (in_char == 116)
    goto state_25_label;

  if (in_char == 118)
    goto state_25_label;

  if (in_char == 120)
    goto state_61_label;

  if (in_char >= 124 && in_char < 126)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 41 -
state_41_label:
  CLOSE_CHAR(8);
  return 8;

// - STATE 42 -
state_42_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_25_label;

  if (in_char >= 48 && in_char < 56)
    goto state_62_label;

  if (in_char >= 56 && in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 43 -
state_43_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_63_label;

  if (in_char >= 65 && in_char < 71)
    goto state_63_label;

  if (in_char >= 97 && in_char < 103)
    goto state_63_label;

  return c_idx_not_exist;

// - STATE 44 -
state_44_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_27_label;

  if (in_char == 39)
    goto state_27_label;

  if (in_char >= 48 && in_char < 56)
    goto state_64_label;

  if (in_char >= 62 && in_char < 64)
    goto state_27_label;

  if (in_char >= 92 && in_char < 94)
    goto state_27_label;

  if (in_char >= 97 && in_char < 99)
    goto state_27_label;

  if (in_char == 102)
    goto state_27_label;

  if (in_char == 110)
    goto state_27_label;

  if (in_char == 114)
    goto state_27_label;

  if (in_char == 116)
    goto state_27_label;

  if (in_char == 118)
    goto state_27_label;

  if (in_char == 120)
    goto state_65_label;

  if (in_char >= 124 && in_char < 126)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 45 -
state_45_label:
  CLOSE_CHAR(9);
  return 9;

// - STATE 46 -
state_46_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_27_label;

  if (in_char >= 48 && in_char < 56)
    goto state_66_label;

  if (in_char >= 56 && in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 47 -
state_47_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_67_label;

  if (in_char >= 65 && in_char < 71)
    goto state_67_label;

  if (in_char >= 97 && in_char < 103)
    goto state_67_label;

  return c_idx_not_exist;

// - STATE 48 -
state_48_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_50_label;

  if (in_char >= 48 && in_char < 56)
    goto state_68_label;

  return c_idx_not_exist;

// - STATE 49 -
state_49_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_69_label;

  if (in_char >= 65 && in_char < 71)
    goto state_69_label;

  if (in_char >= 97 && in_char < 103)
    goto state_69_label;

  return c_idx_not_exist;

// - STATE 50 -
state_50_label:
  CLOSE_CHAR(5);
  return 5;

// - STATE 51 -
state_51_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 34)
    goto state_3_label;

  if (in_char == 34)
    goto state_19_label;

  if (in_char >= 35 && in_char < 92)
    goto state_3_label;

  if (in_char == 92)
    goto state_20_label;

  if (in_char >= 93 && in_char < 256)
    goto state_3_label;

  return c_idx_not_exist;

// - STATE 52 -
state_52_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 34)
    goto state_3_label;

  if (in_char == 34)
    goto state_19_label;

  if (in_char >= 35 && in_char < 92)
    goto state_3_label;

  if (in_char == 92)
    goto state_20_label;

  if (in_char >= 93 && in_char < 256)
    goto state_3_label;

  return c_idx_not_exist;

// - STATE 53 -
state_53_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_35_label;

  if (in_char >= 48 && in_char < 56)
    goto state_22_label;

  return c_idx_not_exist;

// - STATE 54 -
state_54_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_35_label;

  if (in_char >= 48 && in_char < 58)
    goto state_22_label;

  if (in_char >= 65 && in_char < 71)
    goto state_22_label;

  if (in_char >= 97 && in_char < 103)
    goto state_22_label;

  return c_idx_not_exist;

// - STATE 55 -
state_55_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_39_label;

  if (in_char >= 48 && in_char < 56)
    goto state_70_label;

  if (in_char >= 56 && in_char < 62)
    goto state_39_label;

  if (in_char == 62)
    goto state_71_label;

  if (in_char >= 63 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 256)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 56 -
state_56_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_39_label;

  if (in_char >= 48 && in_char < 58)
    goto state_70_label;

  if (in_char >= 58 && in_char < 65)
    goto state_39_label;

  if (in_char >= 65 && in_char < 71)
    goto state_70_label;

  if (in_char >= 71 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 97)
    goto state_39_label;

  if (in_char >= 97 && in_char < 103)
    goto state_70_label;

  if (in_char >= 103 && in_char < 256)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 57 -
state_57_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 56)
    goto state_72_label;

  if (in_char == 62)
    goto state_59_label;

  return c_idx_not_exist;

// - STATE 58 -
state_58_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_73_label;

  if (in_char >= 65 && in_char < 71)
    goto state_73_label;

  if (in_char >= 97 && in_char < 103)
    goto state_73_label;

  return c_idx_not_exist;

// - STATE 59 -
state_59_label:
  CLOSE_CHAR(7);
  return 7;

// - STATE 60 -
state_60_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_25_label;

  if (in_char >= 48 && in_char < 56)
    goto state_74_label;

  if (in_char >= 56 && in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 61 -
state_61_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_75_label;

  if (in_char >= 65 && in_char < 71)
    goto state_75_label;

  if (in_char >= 97 && in_char < 103)
    goto state_75_label;

  return c_idx_not_exist;

// - STATE 62 -
state_62_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 63 -
state_63_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 64 -
state_64_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_27_label;

  if (in_char >= 48 && in_char < 56)
    goto state_76_label;

  if (in_char >= 56 && in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 65 -
state_65_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_77_label;

  if (in_char >= 65 && in_char < 71)
    goto state_77_label;

  if (in_char >= 97 && in_char < 103)
    goto state_77_label;

  return c_idx_not_exist;

// - STATE 66 -
state_66_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 67 -
state_67_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 68 -
state_68_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_50_label;

  if (in_char >= 48 && in_char < 56)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 69 -
state_69_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_50_label;

  if (in_char >= 48 && in_char < 58)
    goto state_30_label;

  if (in_char >= 65 && in_char < 71)
    goto state_30_label;

  if (in_char >= 97 && in_char < 103)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 70 -
state_70_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 62)
    goto state_39_label;

  if (in_char == 62)
    goto state_71_label;

  if (in_char >= 63 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 256)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 71 -
state_71_label:
  CLOSE_CHAR(7);
  GET_NEXT_CHAR();

  if (in_char == 62)
    goto state_59_label;

  return 7;

// - STATE 72 -
state_72_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 56)
    goto state_39_label;

  if (in_char == 62)
    goto state_59_label;

  return c_idx_not_exist;

// - STATE 73 -
state_73_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_39_label;

  if (in_char == 62)
    goto state_59_label;

  if (in_char >= 65 && in_char < 71)
    goto state_39_label;

  if (in_char >= 97 && in_char < 103)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 74 -
state_74_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 75 -
state_75_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_25_label;

  if (in_char == 92)
    goto state_40_label;

  if (in_char == 93)
    goto state_41_label;

  if (in_char >= 94 && in_char < 256)
    goto state_25_label;

  return c_idx_not_exist;

// - STATE 76 -
state_76_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

// - STATE 77 -
state_77_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_27_label;

  if (in_char == 92)
    goto state_44_label;

  if (in_char >= 93 && in_char < 124)
    goto state_27_label;

  if (in_char == 124)
    goto state_45_label;

  if (in_char >= 125 && in_char < 256)
    goto state_27_label;

  return c_idx_not_exist;

}/*}}}*/

int compare_unsigned_shorts(const void *a_first,const void *a_second)
{/*{{{*/
  unsigned short first = *(unsigned short *)a_first;
  unsigned short second = *(unsigned short *)a_second;

  return first < second ? -1 : first > second ? 1 : 0;
}/*}}}*/

bool reg_parser_s::parse_reg_exp(string_s &source_string)
{/*{{{*/
  lalr_stack.used = 0;
  lalr_stack.push(0);

  fas_idx = 0;
  states.clear();

  // - array containing starts and ends of final automata parts -
  ui_array_s begin_idxs;
  begin_idxs.init();

  ui_array_s end_idxs;
  end_idxs.init();

  // - variables used while parsing regular expression -
  unsigned old_input_idx = 0;
  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;
  unsigned short in_char;

  do
  {
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(source_string,input_idx);

      // - ERROR -
      if (ret_term == c_idx_not_exist)
      {
        end_idxs.clear();
        begin_idxs.clear();

        return false;
      }

      if (ret_term == 15)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - select action from parse table -
    unsigned parse_action = reg_lalr_table[lalr_stack.last().lalr_state*c_reg_terminal_plus_nonterminal_cnt + ret_term];

    // - ERROR -
    if (parse_action == c_idx_not_exist)
    {
      end_idxs.clear();
      begin_idxs.clear();

      return false;
    }

    // - akce SHIFT -
    if (parse_action < c_reg_lalr_table_reduce_base)
    {
      if (ret_term == 16)
      {
        break;
      }

      // - put new state and source string position to stack -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action REDUCE -
    else
    {
      parse_action -= c_reg_lalr_table_reduce_base;

      // - process rule reduction -
      switch (parse_action)
      {
      case c_reduce_alter:
      {/*{{{*/
        unsigned second_begin_idx = begin_idxs.pop();
        unsigned first_begin_idx = begin_idxs.pop();

        unsigned second_end_idx = end_idxs.pop();
        unsigned first_end_idx = end_idxs.pop();

        // - create new state -
        states.push_blank();
        unsigned begin_state_idx = states.used - 1;
        fa_state_s &begin_state = states[begin_state_idx];
        begin_state.final = 0;

        begin_state.moves.push_blank();
        begin_state.moves.last().set(0xffff,first_begin_idx);

        begin_state.moves.push_blank();
        begin_state.moves.last().set(0xffff,second_begin_idx);

        // - create final state -
        states.push_blank();
        unsigned end_state_idx = states.used - 1;
        states[end_state_idx].final = 0;

        // - connect ends of both parts to final state -
        {
          fa_state_s &s_state = states[second_end_idx];
          s_state.moves.push_blank();
          s_state.moves.last().set(0xffff,end_state_idx);

          fa_state_s &f_state = states[first_end_idx];
          f_state.moves.push_blank();
          f_state.moves.last().set(0xffff,end_state_idx);
        }

        begin_idxs.push(begin_state_idx);
        end_idxs.push(end_state_idx);
        }/*}}}*/
      break;

      case c_reduce_conc:
      {/*{{{*/
        unsigned second_begin_idx = begin_idxs.pop();

        // - store end of second part -
        unsigned tmp_end = end_idxs.pop();

        unsigned first_end_idx = end_idxs.pop();

        // - connect end of first part to begin of second part -
        fa_state_s &state = states[first_end_idx];
        state.moves.push_blank();
        state.moves.last().set(0xffff,second_begin_idx);

        // - store end of second part -
        end_idxs.push(tmp_end);
        }/*}}}*/
      break;

      case c_reduce_iter:
      {/*{{{*/
        unsigned begin_idx = begin_idxs.last();
        unsigned end_idx = end_idxs.pop();

        fa_state_s &state = states[end_idx];
        state.moves.push_blank();
        state.moves.last().set(0xffff,begin_idx);

        end_idxs.push(begin_idx);
        }/*}}}*/
      break;

      case c_reduce_char_eps:
      {/*{{{*/
        states.push_blank();
        unsigned state_idx = states.used - 1;

        states[state_idx].final = 0;

        begin_idxs.push(state_idx);
        end_idxs.push(state_idx);
        }/*}}}*/
      break;

      case c_reduce_char:
      {
        lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 1];

        register char *t_ptr = source_string.data + lse.terminal_start + 1;
        in_char = process_char(t_ptr);

        goto c_reduce_char_lbl;
      }

      case c_reduce_char_white:
        in_char = reg_char_white;
        goto c_reduce_char_lbl;

      case c_reduce_char_digit:
        in_char = reg_char_digit;
        goto c_reduce_char_lbl;

      case c_reduce_char_letter:
        in_char = reg_char_letter;
        goto c_reduce_char_lbl;

      case c_reduce_char_no_char:
      {
        lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 1];

        register char *t_ptr = source_string.data + lse.terminal_start + 2;
        in_char = c_no_char_base + process_char(t_ptr);
      }

c_reduce_char_lbl:
      {/*{{{*/
        states.push_blank();
        states.push_blank();

        unsigned begin_state_idx = states.used - 2;
        fa_state_s &begin_state = states[begin_state_idx];
        begin_state.final = 0;

        unsigned end_state_idx = states.used - 1;
        fa_state_s &end_state = states[end_state_idx];
        end_state.final = 0;

        begin_state.moves.push_blank();
        begin_state.moves.last().set(in_char,end_state_idx);

        begin_idxs.push(begin_state_idx);
        end_idxs.push(end_state_idx);
        }/*}}}*/
      break;

      case c_reduce_char_str:
      {/*{{{*/
        lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 1];

        unsigned first_state_idx;
        unsigned state_idx;

        first_state_idx = states.used;

        char *c_ptr = source_string.data + lse.terminal_start + 1;
        char *c_ptr_end = source_string.data + lse.terminal_end - 1;
        unsigned last_state_idx = c_idx_not_exist;

        do
        {
          unsigned short in_char = process_char(c_ptr);

          states.push_blank();
          state_idx = states.used - 1;
          fa_state_s &state = states[state_idx];

          state.final = 0;
          state.moves.push_blank();
          state.moves.last().set(in_char,c_idx_not_exist);

          if (last_state_idx != c_idx_not_exist)
          {
            states[last_state_idx].moves[0].value = state_idx;
          }

          last_state_idx = state_idx;

        }
        while(c_ptr < c_ptr_end);

        states.push_blank();
        state_idx = states.used - 1;
        fa_state_s &state = states[state_idx];

        state.final = 0;

        if (last_state_idx != c_idx_not_exist)
        {
          states[last_state_idx].moves[0].value = state_idx;
        }

        begin_idxs.push(first_state_idx);
        end_idxs.push(state_idx);
        }/*}}}*/
      break;

      case c_reduce_char_range:
      {/*{{{*/
        lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 1];
        unsigned short begin_char;
        unsigned short end_char;

        {
          char *ptr = source_string.data + lse.terminal_start + 1;

          begin_char = process_char(ptr);
          end_char = process_char(ptr);
        }

        // - ERROR -
        if (begin_char > end_char)
        {
          end_idxs.clear();
          begin_idxs.clear();

          return false;
        }

        states.push_blank();
        states.push_blank();

        unsigned begin_state_idx = states.used - 2;
        fa_state_s &begin_state = states[begin_state_idx];
        begin_state.final = 0;

        unsigned end_state_idx = states.used - 1;
        fa_state_s &end_state = states[end_state_idx];
        end_state.final = 0;

        do
        {
          begin_state.moves.push_blank();
          begin_state.moves.last().set(begin_char,end_state_idx);
        }
        while(++begin_char <= end_char);

        begin_idxs.push(begin_state_idx);
        end_idxs.push(end_state_idx);
        }/*}}}*/
      break;

      case c_reduce_char_alter:
      {/*{{{*/
        lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 1];

        char *ptr = source_string.data + lse.terminal_start + 1;
        char *ptr_end = source_string.data + lse.terminal_end - 1;

        states.push_blank();
        states.push_blank();

        unsigned begin_state_idx = states.used - 2;
        fa_state_s &begin_state = states[begin_state_idx];
        begin_state.final = 0;

        unsigned end_state_idx = states.used - 1;
        fa_state_s &end_state = states[end_state_idx];
        end_state.final = 0;

        do
        {
          unsigned short in_char = process_char(ptr);

          begin_state.moves.push_blank();
          begin_state.moves.last().set(in_char,end_state_idx);

        }
        while(ptr < ptr_end);

        begin_idxs.push(begin_state_idx);
        end_idxs.push(end_state_idx);
        }/*}}}*/
      break;

      case c_reduce_char_except:
      {/*{{{*/
        lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 1];

        char *ptr = source_string.data + lse.terminal_start + 1;
        char *ptr_end = source_string.data + lse.terminal_end - 1;

        us_array_s char_array;
        char_array.init();

        do
        {
          char_array.push(process_char(ptr));
        }
        while(ptr < ptr_end);

        qsort(char_array.data,char_array.used,sizeof(unsigned short),compare_unsigned_shorts);

        states.push_blank();
        states.push_blank();

        unsigned begin_state_idx = states.used - 2;
        fa_state_s &begin_state = states[begin_state_idx];
        begin_state.final = 0;

        unsigned end_state_idx = states.used - 1;
        fa_state_s &end_state = states[end_state_idx];
        end_state.final = 0;

        // - generate accepted characters -
        {
          unsigned b_char = 0;
          unsigned e_char_idx = 0;

          do
          {
            unsigned short e_char = char_array[e_char_idx];

            if (b_char < e_char)
            {
              do
              {
                begin_state.moves.push_blank();
                begin_state.moves.last().set(b_char,end_state_idx);
              }
              while(++b_char < e_char);
            }

            b_char = e_char + 1;

          }
          while(++e_char_idx < char_array.used);

          // - complete character set -
          if (b_char < 256)
          {
            do
            {
              begin_state.moves.push_blank();
              begin_state.moves.last().set(b_char,end_state_idx);
            }
            while(++b_char < 256);
          }
        }

        char_array.clear();

        begin_idxs.push(begin_state_idx);
        end_idxs.push(end_state_idx);
        }/*}}}*/
      break;
      }

      // - remove rule body from stack -
      lalr_stack.used -= reg_rule_body_lengths[parse_action];

      // - push new state to stack top -
      unsigned goto_val = reg_lalr_table[lalr_stack.last().lalr_state*c_reg_terminal_plus_nonterminal_cnt + reg_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  // - store final automata first state -
  fas_idx = begin_idxs.pop();

  // - mark final states -
  states[end_idxs.pop()].final = 1;

  end_idxs.clear();
  begin_idxs.clear();

  return true;
}/*}}}*/

bool reg_parser_s::NKA_to_DKA()
{/*{{{*/

  // - swap NFA to local variables -
  unsigned nka_fas_idx = fas_idx;
  fas_idx = 0;

  fa_states_s nka_states;
  nka_states.init();
  nka_states.swap(states);

  // - sets of epsilon closures of NFA states -
  ui_array_sets_s eps_closures;
  eps_closures.init();

  // - list of already processed multi states with their indexes in target DFA -
  reg_mul_state_map_array_s ms_map_array;
  ms_map_array.init();

  // - queue of potentially unprocessed states -
  reg_mul_state_move_queue_s msm_queue;
  msm_queue.init();

  // - compute epsilon closures of states, and states finality -
  {
    eps_closures.copy_resize(nka_states.used);
    eps_closures.used = nka_states.used;

    ui_array_s state_idx_stack;
    state_idx_stack.init();

    bb_array_s processed_states;
    processed_states.init();
    processed_states.copy_resize(nka_states.used);

    // - loop through all states of NFA -
    unsigned s_idx = 0;
    do
    {
      ui_array_set_s &eps_closure = eps_closures[s_idx];

      state_idx_stack.used = 0;
      state_idx_stack.push(s_idx);

      processed_states.fill(false);

      // - loop while stack is not empty -
      do
      {
        unsigned ss_idx = state_idx_stack.pop();

        // - if epsilon closure for position ss_idx is already computed, add its content to closure -
        if (ss_idx < s_idx)
        {
          ui_array_set_s &ss_eps_closure = eps_closures[ss_idx];
          eps_closure.add_to_set(ss_eps_closure);

          unsigned ss_ec_idx = 0;
          do
          {
            processed_states[ss_eps_closure[ss_ec_idx]] = true;
          }
          while(++ss_ec_idx < ss_eps_closure.used);
        }
        else
        {
          // - if state at position ss_idx is not contained in closure  -
          if (!processed_states[ss_idx])
          {
            // - push states which are target of epsilon move from inserted state
            // to stack -
            unsigned have_no_eps_move = false;

            fa_state_s &state = nka_states[ss_idx];
            if (state.moves.used != 0)
            {
              unsigned m_idx = 0;

              do
              {
                reg_state_move_s &move = state.moves[m_idx];

                if (move.idx == 0xffff)
                {
                  state_idx_stack.push(move.value);
                }
                else
                {
                  have_no_eps_move = true;
                }
              }
              while(++m_idx < state.moves.used);
            }

            // - if state contain other than epsilon moves add it to epsilon closure -
            if (have_no_eps_move || state.final)
            {
              eps_closure.push(ss_idx);
            }

            processed_states[ss_idx] = true;
          }
        }
      }
      while(state_idx_stack.used > 0);
    }
    while(++s_idx < nka_states.used);

    processed_states.clear();
    state_idx_stack.clear();
  }

  // - insert first state {0} to input queue -
  msm_queue.insert_blank();
  {
    reg_mul_state_move_s &mul_state_move = msm_queue.last();

    mul_state_move.move_char = 0xffff;
    mul_state_move.from_state = c_idx_not_exist;
    mul_state_move.mul_state = eps_closures[nka_fas_idx];
  }

  reg_mul_state_move_s mul_state_move;
  mul_state_move.init();

  reg_mul_state_move_array_s new_mul_state_moves;
  new_mul_state_moves.init();

  do
  {
    mul_state_move.swap(msm_queue.next());

    unsigned mul_state_idx = ms_map_array.get_idx_by_mul_state(mul_state_move.mul_state);
    if (mul_state_idx == c_idx_not_exist)
    {
      // - create new state -
      states.push_blank();
      fa_state_s &state = states.last();
      state.final = 0;

      ms_map_array.push_blank();
      reg_mul_state_map_s &ms_map = ms_map_array.last();
      ms_map.mul_state.swap(mul_state_move.mul_state);
      ms_map.dka_state_idx = states.used - 1;

      mul_state_idx = ms_map_array.used - 1;

      // - find next move from from new state -
      new_mul_state_moves.used = 0;
      ui_array_set_s &mul_state = ms_map.mul_state;

      // - loop through all states of NFA in epsilon closure -
      if (mul_state.used != 0)
      {
        unsigned s_idx = 0;
        do
        {
          fa_state_s &nka_state = nka_states[mul_state[s_idx]];

          // - set finality of new state -
          if (nka_state.final)
          {
            state.final = 1;
          }

          reg_state_moves_s &state_moves = nka_state.moves;

          // - loop through all moves in actual state -
          if (state_moves.used != 0)
          {
            unsigned m_idx = 0;
            do
            {
              reg_state_move_s &move = state_moves[m_idx];

              // - id move is not epsilon move -
              if (move.idx != 0xffff)
              {
                // - generate new candidates for DFA states -
                unsigned mc_idx = new_mul_state_moves.get_idx_by_move_char(move.idx);
                if (mc_idx == c_idx_not_exist)
                {
                  new_mul_state_moves.push_clear();
                  reg_mul_state_move_s &mul_state_move = new_mul_state_moves.last();
                  mul_state_move.move_char = move.idx;
                  mul_state_move.from_state = ms_map.dka_state_idx;

                  mc_idx = new_mul_state_moves.used - 1;
                }

                reg_mul_state_move_s &mul_state_move = new_mul_state_moves[mc_idx];
                mul_state_move.mul_state.add_to_set(eps_closures[move.value]);
              }

            }
            while(++m_idx < state_moves.used);
          }
        }
        while(++s_idx < mul_state.used);
      }

      if (new_mul_state_moves.used != 0)
      {
        unsigned idx = 0;
        do
        {
          msm_queue.insert_blank();
          msm_queue.last().swap(new_mul_state_moves[idx]);
        }
        while(++idx < new_mul_state_moves.used);
      }
    }

    unsigned this_state_idx = ms_map_array[mul_state_idx].dka_state_idx;

    // - write move to this state -
    if (mul_state_move.from_state != c_idx_not_exist)
    {
      fa_state_s &state = states[mul_state_move.from_state];
      state.moves.push_blank();

      reg_state_move_s &move = state.moves.last();
      move.idx = mul_state_move.move_char;
      move.value = this_state_idx;
    }

    mul_state_move.clear();
  }
  while(msm_queue.used > 0);

  new_mul_state_moves.clear();
  mul_state_move.clear();

  eps_closures.clear();
  ms_map_array.clear();
  msm_queue.clear();
  nka_states.clear();

  return true;
}/*}}}*/

bool reg_parser_s::process_reg_exps(string_array_s &source_strings,fa_states_array_s &states_array)
{/*{{{*/
  states_array.clear();

  if (source_strings.used == 0)
  {
    return true;
  }

  states_array.copy_resize(source_strings.used);

  unsigned idx = 0;
  do
  {
    if (!process_reg_exp(source_strings[idx]))
    {
      return false;
    }

    states_array.push_blank();
    states_array.last().swap(states);

  }
  while(++idx < source_strings.used);

  return true;
}/*}}}*/

// -- p_terminal_s --
@begin
methods p_terminal_s
@end

// -- p_terminals_s --
@begin
methods p_terminals_s
@end

unsigned p_terminals_s::get_map_idx(p_terminal_s &a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  p_terminal_s *ptr = data;
  p_terminal_s *ptr_end = data + used;

  do
  {
    if (ptr->idx == a_value.idx)
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

unsigned p_terminals_s::get_char_ptr_idx(unsigned a_length,char *a_data)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  p_terminal_s *ptr = data;
  p_terminal_s *ptr_end = ptr + used;

  do
  {
    if (ptr->idx.compare_char_ptr(a_length,a_data))
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

// -- p_nonterminal_s --
@begin
methods p_nonterminal_s
@end

// -- p_nonterminals_s --
@begin
methods p_nonterminals_s
@end

unsigned p_nonterminals_s::get_char_ptr_idx(unsigned a_length,char *a_data)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  p_nonterminal_s *ptr = data;
  p_nonterminal_s *ptr_end = ptr + used;

  do
  {
    if (ptr->name.compare_char_ptr(a_length,a_data))
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

// -- p_rule_s --
@begin
methods p_rule_s
@end

// -- p_rules_s --
@begin
methods p_rules_s
@end

// -- p_kernel_s --
@begin
methods p_kernel_s
@end

// -- p_kernels_s --
@begin
methods p_kernels_s
@end

unsigned p_kernels_s::get_idx_by_rule_dots(p_kernel_s &a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  p_kernel_s *ptr = data;
  p_kernel_s *ptr_end = ptr + used;

  do
  {
    if (ptr->rule_dots == a_value.rule_dots)
    {
      return ptr - data;
    }
  }
  while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

// -- p_lalr_table_s --
@begin
methods p_lalr_table_s
@end

// -- p_creat_descr_s --
@begin
methods p_creat_descr_s
@end

bool p_creat_descr_s::load_final_automata_set_new()
{/*{{{*/
  fa_states_array_s states_array;
  states_array.init();

  reg_parser_s reg_parser;
  reg_parser.init();

  // - process regular expressions for parsing of rule file -
  {
    unsigned re_idx = 0;
    do
    {
      string_s reg_exp_string;
      reg_exp_string.size = strlen(test_reg_exps[re_idx]) + 1;
      reg_exp_string.data = (char *)test_reg_exps[re_idx];

      reg_parser.process_reg_exp(reg_exp_string);

      states_array.push_blank();
      states_array.last().swap(reg_parser.states);
    }
    while(++re_idx < test_reg_exp_cnt);
  }

  rule_file_fa.clear();
  rule_file_fa.create_new(states_array);

  states_array.used = 0;

  // - process regular expressions for parsing key terminals -
  {
    unsigned re_idx = 0;
    do
    {
      string_s reg_exp_string;
      reg_exp_string.size = strlen(key_terminals[re_idx]) + 1;
      reg_exp_string.data = (char *)key_terminals[re_idx];

      reg_parser.process_reg_exp(reg_exp_string);

      states_array.push_blank();
      states_array.last().swap(reg_parser.states);
    }
    while(++re_idx < c_key_terminal_cnt);
  }

  key_terminals_fa.clear();
  key_terminals_fa.create_new(states_array);

  reg_parser.clear();
  states_array.clear();

  return true;
}/*}}}*/

bool p_creat_descr_s::load_from_rule_char_ptr(unsigned a_length,char *a_data)
{/*{{{*/
  terminals.used = 0;
  nonterminals.used = 0;
  rules.used = 0;

  unsigned old_input_idx = 0;
  unsigned input_idx = 0;
  unsigned input_length = a_length;
  unsigned ret_term;

#define LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR() \
{/*{{{*/\
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);\
  exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_SYNTAX_ERROR,0,(location_s *)it.blank_location);\
  new_exception->params.push(old_input_idx);\
\
  return false;\
}/*}}}*/

  // - skip init code flag -
  while (1)
  {
    old_input_idx = input_idx;
    if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_init_code)
    {
      break;
    }

    // - ERROR -
    if (ret_term > rt_sec_comment)
    {
      LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
    }
  }

  // - find init semantic code -
  while(1)
  {
    old_input_idx = input_idx;
    if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_code)
    {
      break;
    }

    // - ERROR -
    if (ret_term > rt_sec_comment)
    {
      LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
    }
  }

  // - skip terminals flag -
  while(1)
  {
    old_input_idx = input_idx;
    if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_terminals)
    {
      break;
    }

    // - ERROR -
    if (ret_term > rt_sec_comment)
    {
      LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
    }
  }

  // - process terminals -
  {
    unsigned terminal_state = 0;
    p_terminal_s new_terminal;
    new_terminal.init();

    do
    {
      // - while terminal rt_nonterminals is not returned -
      old_input_idx = input_idx;
      if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_nonterminals)
      {
        break;
      }

      // - skip white characters and comments -
      if (ret_term <= rt_sec_comment)
      {
        continue;
      }

      // - read terminal name -
      if (terminal_state == 0)
      {
        // - ERROR -
        if (ret_term != rt_identifier)
        {
          new_terminal.clear();

          LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
        }

        new_terminal.idx.set(input_idx - old_input_idx,a_data + old_input_idx);
        new_terminal.source_pos = old_input_idx;

        // - ERROR -
        if (terminals.get_map_idx(new_terminal) != c_idx_not_exist)
        {
          new_terminal.clear();

          interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
          exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_DUPLICATE_TERMINAL,0,(location_s *)it.blank_location);
          new_exception->params.push(old_input_idx);

          return false;
        }

        terminal_state = 1;
      }

      // - regular expression describing terminal -
      else
      {
        // - ERROR -
        if (ret_term != rt_code)
        {
          new_terminal.clear();

          LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
        }

        new_terminal.value.set(input_idx - old_input_idx - 2,a_data + old_input_idx + 1);

        terminals.push_blank();
        terminals.last().swap(new_terminal);

        terminal_state = 0;
      }
    }
    while(1);

    new_terminal.clear();
  }

  // - ERROR -
  if (terminals.used == 0)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
    exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_NO_TERMINALS_DEFINED,0,(location_s *)it.blank_location);

    return false;
  }

  // - process nonterminal -
  {
    p_nonterminal_s new_nonterminal;
    new_nonterminal.init();

    do
    {
      // - while terminal rt_rules is not returned -
      old_input_idx = input_idx;
      if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_rules)
      {
        break;
      }

      // - skip white characters and comments -
      if (ret_term <= rt_sec_comment)
      {
        continue;
      }

      // - ERROR -
      if (ret_term != rt_nonterm_id)
      {
        new_nonterminal.clear();

        LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
      }

      // - read nonterminal name -
      new_nonterminal.name.set(input_idx - old_input_idx,a_data + old_input_idx);

      // - ERROR -
      if (nonterminals.get_idx(new_nonterminal) != c_idx_not_exist)
      {
        new_nonterminal.clear();

        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_DUPLICATE_NONTERMINAL,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
      }

      nonterminals.push_blank();
      nonterminals.last().swap(new_nonterminal);

    }
    while(1);

    new_nonterminal.clear();
  }

  // - ERROR -
  if (nonterminals.used == 0)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
    exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_NO_NONTERMINALS_DEFINED,0,(location_s *)it.blank_location);

    return false;
  }

  // - process rules -
  {
    unsigned rule_head_index = 0;
    unsigned rule_state = 0;
    p_rule_s new_rule;
    new_rule.init();

    do
    {
      // - while terminal rt_input_end is not returned -
      old_input_idx = input_idx;
      if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_input_end)
      {
        break;
      }

      if (ret_term <= rt_sec_comment)
      {
        continue;
      }

      if (rule_state < 2)
      {
        // - read rule head -
        if (rule_state == 0)
        {
          // - ERROR -
          if (ret_term != rt_nonterm_id)
          {
            new_rule.clear();

            LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
          }

          unsigned idx = nonterminals.get_char_ptr_idx(input_idx - old_input_idx,a_data + old_input_idx);

          // - ERROR -
          if (idx == c_idx_not_exist)
          {
            new_rule.clear();

            interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
            exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_UNDEFINED_NONTERMINAL,0,(location_s *)it.blank_location);
            new_exception->params.push(old_input_idx);

            return false;
          }

          rule_head_index = old_input_idx;
          new_rule.head = terminals.used + idx;
          rule_state = 1;
        }

        // - read separator of rule head and its body -
        else
        {
          // - ERROR -
          if (ret_term != rt_div_0)
          {
            new_rule.clear();

            LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
          }

          new_rule.body.used = 0;
          rule_state = 2;
        }
      }
      else
      {
        // - read rule body -
        if (rule_state == 2)
        {
          if (ret_term == rt_identifier)
          {
            unsigned idx = terminals.get_char_ptr_idx(input_idx - old_input_idx,a_data + old_input_idx);

            // - ERROR -
            if (idx == c_idx_not_exist)
            {
              new_rule.clear();

              interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
              exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_UNDEFINED_TERMINAL,0,(location_s *)it.blank_location);
              new_exception->params.push(old_input_idx);

              return false;
            }

            new_rule.body.push(idx);
          }
          else if (ret_term == rt_nonterm_id)
          {
            unsigned idx = nonterminals.get_char_ptr_idx(input_idx - old_input_idx,a_data + old_input_idx);

            // - ERROR -
            if (idx == c_idx_not_exist)
            {
              new_rule.clear();

              interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
              exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_UNDEFINED_NONTERMINAL,0,(location_s *)it.blank_location);
              new_exception->params.push(old_input_idx);

              return false;
            }

            new_rule.body.push(terminals.used + idx);
          }

          // - separator of rule body and its semantic code -
          else
          {
            // - ERROR -
            if (new_rule.body.used <= 0)
            {
              new_rule.clear();
              return false;
            }

            // - ERROR -
            if (ret_term != rt_div_1)
            {
              new_rule.clear();

              LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
            }

            rule_state = 3;
          }
        }

        // - read semantic code of rule -
        else
        {
          // - ERROR -
          if (ret_term != rt_code)
          {
            new_rule.clear();

            LOAD_FROM_RULE_CHAR_PTR_SYNTAX_ERROR();
          }

          // - ignore semantic code -

          // - ERROR -
          if (rules.get_idx(new_rule) != c_idx_not_exist)
          {
            new_rule.clear();

            interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
            exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_DUPLICATE_RULE,0,(location_s *)it.blank_location);
            new_exception->params.push(rule_head_index);

            return false;
          }

          rules.push_blank();
          rules.last().swap(new_rule);

          rule_state = 0;
        }
      }

    }
    while(1);

    new_rule.clear();
  }

  // - ERROR -
  if (rules.used == 0)
  {
    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
    exception_s::throw_exception(it,c_error_PARSER_CREATE_RULES_NO_RULES_DEFINED,0,(location_s *)it.blank_location);

    return false;
  }

  return true;
}/*}}}*/

bool p_creat_descr_s::find_key_terminals(unsigned &end_terminal,ui_array_s &skip_terminals)
{/*{{{*/
  end_terminal = c_idx_not_exist;
  skip_terminals.used = 0;

  // - ERROR -
  if (terminals.used == 0)
  {
    return true;
  }

  unsigned t_idx = 0;
  do
  {
    string_s &string = terminals[t_idx].idx;

    unsigned input_idx = 0;
    unsigned input_length = string.size - 1;
    unsigned ret_term;

    ret_term = key_terminals_fa.recognize(string.data,input_idx,input_length);

    if (ret_term != c_idx_not_exist)
    {
      if (ret_term == ktt_skip)
      {
        skip_terminals.push(t_idx);
      }
      else if (ret_term == ktt_end)
      {
        // - ERROR -
        if (end_terminal != c_idx_not_exist)
        {
          interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
          exception_s::throw_exception(it,c_error_PARSER_CREATE_MULTIPLE_PARSE_END_TERMINALS,0,(location_s *)it.blank_location);

          return false;
        }

        end_terminal = t_idx;
      }
    }

  }
  while(++t_idx < terminals.used);

  return true;
}/*}}}*/

bool p_creat_descr_s::create_final_automata_new(final_automata_s &final_automata)
{/*{{{*/
  cassert(terminals.used != 0);

  fa_states_array_s states_array;
  states_array.init();

  reg_parser_s reg_parser;
  reg_parser.init();

  {
    unsigned t_idx = 0;
    do
    {
      // - ERROR -
      if (!reg_parser.process_reg_exp(terminals[t_idx].value))
      {
        reg_parser.clear();
        states_array.clear();

        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_PARSER_CREATE_TERMINAL_REGULAR_EXPRESSION_PARSE_ERROR,0,(location_s *)it.blank_location);
        new_exception->params.push(terminals[t_idx].source_pos);

        return false;
      }

      states_array.push_blank();
      states_array.last().swap(reg_parser.states);
    }
    while(++t_idx < terminals.used);
  }

  final_automata.clear();
  final_automata.create_new(states_array);

  reg_parser.clear();
  states_array.clear();

  return true;
}/*}}}*/

bool p_creat_descr_s::compute_firsts()
{/*{{{*/
  cassert(terminals.used != 0 && nonterminals.used != 0 && rules.used != 0);

  firsts.used = 0;
  first_rules.used = 0;

  p_first_set_s first_set;
  first_set.init();

  p_rule_idxs_sets_s first_rule_idxs_sets;
  first_rule_idxs_sets.init();

  // - compute firsts set for nonterminal symbols -
  {
    unsigned non_idx = 0;

    do
    {
      first_set.used = 0;
      first_rule_idxs_sets.used = 0;

      first_set.push(non_idx + terminals.used);
      first_rule_idxs_sets.push_clear();

      // - loop through elements in set first -
      unsigned fs_idx = 0;
      do
      {
        // - if element is nonterminal -
        if (first_set[fs_idx] >= terminals.used)
        {
          unsigned r_idx = 0;

          // - loop through all rules -
          do
          {
            p_rule_s &rule_ref = rules[r_idx];

            // - if head of rule is same as testing nonterminal -
            if (rule_ref.head == first_set[fs_idx])
            {
              unsigned first_body = rule_ref.body[0];

              // - if element is not yet in set first_set -
              unsigned first_body_idx = first_set.get_idx(first_body);
              if (first_body_idx == c_idx_not_exist)
              {
                first_set.push(first_body);
                first_rule_idxs_sets.push_clear();
                first_rule_idxs_sets.last().push(r_idx);
              }
              else
              {
                first_rule_idxs_sets[first_body_idx].push(r_idx);
              }
            }
          }
          while(++r_idx < rules.used);
        }
      }
      while(++fs_idx < first_set.used);

      // - insert set first nonterminals to list -
      firsts.push_blank();
      firsts.last().swap(first_set);

      first_rules.push_blank();
      first_rules.last().swap(first_rule_idxs_sets);
    }
    while(++non_idx < nonterminals.used);
  }

  first_set.clear();
  first_rule_idxs_sets.clear();

  return true;
}/*}}}*/

bool p_creat_descr_s::compute_follows_of_nonterminal(unsigned nonterm_idx,bb_array_s &follows_created,ui_array_s &nonterm_used,p_follow_set_s &ret_follows)
{/*{{{*/
  bool clean = true;
  ret_follows.used = 0;

  unsigned r_idx = 0;

  // - loop through all rules -
  do
  {
    p_rule_s &rule = rules[r_idx];
    unsigned rb_idx = 0;

    // - loop through rule body -
    do
    {
      // - if watched nonterminal was found -
      if (nonterm_idx == rule.body[rb_idx])
      {
        // - if nonterminal is inside rule body -
        if (rb_idx < rule.body.used - 1)
        {
          unsigned element = rule.body[rb_idx + 1];

          // - if element is terminal insert it to set follow -
          if (element < terminals.used)
          {
            if (ret_follows.get_idx(element) == c_idx_not_exist)
            {
              ret_follows.push(element);
            }
          }

          // - if element is nonterminal insert its set first to set follow -
          else
          {
            ret_follows.add_to_set(firsts[element - terminals.used]);
          }
        }

        // - if nonterminal is at end of rule body -
        else
        {
          // - if rule head was not used yet, use it -
          if (nonterm_used.get_idx(rule.head) == c_idx_not_exist)
          {
            // - if set follow of rule head was not computed yet -
            if (!follows_created[rule.head - terminals.used])
            {
              nonterm_used.push(rule.head);

              // - compute set follow of rule head and store it if compute was clean -
              bool this_clean = compute_follows_of_nonterminal(rule.head,follows_created,nonterm_used,follows[rule.head - terminals.used]);

              if (this_clean)
              {
                follows_created[rule.head - terminals.used] = true;
              }
              else
              {
                clean = false;
              }
            }

            // - add set follow of rule head to set follow -
            ret_follows.add_to_set(follows[rule.head - terminals.used]);
          }

          // - if rule head was already used mark computation as not clean -
          else
          {
            clean = false;
          }
        }
      }
    }
    while(++rb_idx < rule.body.used);
  }
  while(++r_idx < rules.used);

  return clean;
}/*}}}*/

bool p_creat_descr_s::compute_follows()
{/*{{{*/
  cassert(terminals.used != 0 && nonterminals.used != 0 && rules.used != 0 && firsts.used != 0);

  follows.used = 0;
  follows.copy_resize(nonterminals.used);

  {
    p_follow_set_s follow_set;
    follow_set.init();

    follows.fill(follow_set);

    follow_set.clear();
  }

  bb_array_s follows_created;
  follows_created.init_size(nonterminals.used);
  follows_created.fill(false);

  ui_array_s nonterm_used;
  nonterm_used.init();

  unsigned non_idx = 0;

  // - loop through all nonterminals -
  do
  {
    if (!follows_created[non_idx])
    {
      nonterm_used.used = 0;
      nonterm_used.push(terminals.used + non_idx);

      compute_follows_of_nonterminal(terminals.used + non_idx,follows_created,nonterm_used,follows[non_idx]);
    }
  }
  while(++non_idx < nonterminals.used);

  nonterm_used.clear();
  follows_created.clear();

  return true;
}/*}}}*/

bool p_creat_descr_s::compute_kernels()
{/*{{{*/
  cassert(terminals.used != 0 && nonterminals.used != 0 && rules.used != 0 && firsts.used != 0 && follows.used != 0);

  kernels.used = 0;

  // - create first kernel containing first rule with iter before first item of body -
  {
    kernels.push_clear();
    p_kernel_rule_dots_s &rule_dots = kernels.last().rule_dots;

    rule_dots.push_blank();
    rule_dots.last().set(0,0);
  }

  p_first_set_s terminal_first;
  terminal_first.init_size(1);
  terminal_first.used = 1;

  p_kernel_s new_kernel;
  new_kernel.init();

  unsigned k_idx = 0;

  // - loop through already created kernels -
  do
  {
    // - if kernel contain some rules -
    if (kernels[k_idx].rule_dots.used != 0)
    {
      p_kernel_rule_dots_s *rule_dots = &kernels[k_idx].rule_dots;

      unsigned rd_idx = 0;

      // - loop through all rules of kernel -
      do
      {
        p_kernel_rule_dot_s *rule_dot = rule_dots->data + rd_idx;

        // - if iter is not at end of rule body -
        if (rule_dot->ui_second < rules[rule_dot->ui_first].body.used)
        {
          unsigned element = rules[rule_dot->ui_first].body[rule_dot->ui_second];

          if (element < terminals.used)
          {
            terminal_first.data[0] = element;
          }

          p_first_set_s &element_first = (element < terminals.used)?terminal_first:firsts[element - terminals.used];

          if (element_first.used != 0)
          {
            unsigned ef_idx = 0;

            // - loop through all members in set element_first -
            do
            {
              // - create new kernel -
              p_kernel_rule_dots_s &nk_rule_dots = new_kernel.rule_dots;
              nk_rule_dots.used = 0;

              // - insert all rules generating element in set first with
              // iterator after first element -
              if (element >= terminals.used)
              {
                ui_array_set_s &ef_rules = first_rules[element - terminals.used][ef_idx];

                nk_rule_dots.copy_resize(ef_rules.used + 1);

                if (ef_rules.used != 0)
                {
                  unsigned _idx = 0;

                  do
                  {
                    nk_rule_dots.data[_idx].ui_first = ef_rules[_idx];
                    nk_rule_dots.data[_idx].ui_second = 1;
                  }
                  while(++_idx < ef_rules.used);

                  nk_rule_dots.used = ef_rules.used;
                }
              }

              // - if element in set first is tested element, copy its rule
              // from actual kernel, and place iterator after it -
              if (ef_idx == 0)
              {
                nk_rule_dots.push(kernels[k_idx].rule_dots[rd_idx]);
                nk_rule_dots.last().ui_second++;
              }

              // - to set of transitions insert transition from processed
              // kernel with element in set first -
              p_kernel_gotos_s &gotos = new_kernel.gotos;
              gotos.used = 0;
              gotos.push_blank();
              gotos.data[0].set(k_idx,element_first[ef_idx]);

              // - search in already generated kernels -
              unsigned tmp_k_idx = kernels.get_idx_by_rule_dots(new_kernel);

              // - if kernel with same set rule_dots does not exists, store new kernel -
              if (tmp_k_idx == c_idx_not_exist)
              {
                kernels.push_blank();
                kernels.last().swap(new_kernel);

                // - retrieve pointers after possible reallocation -
                rule_dots = &kernels[k_idx].rule_dots;
              }

              // - if such kernel does exist, add generated transition to its set gotos -
              else
              {
                kernels[tmp_k_idx].gotos.push(gotos[0]);
              }

            }
            while(++ef_idx < element_first.used);
          }
        }
      }
      while(++rd_idx < rule_dots->used);
    }
  }
  while(++k_idx < kernels.used);

  new_kernel.clear();
  terminal_first.clear();

  return true;
}/*}}}*/

bool p_creat_descr_s::create_lalr_table(p_lalr_table_s &lalr_table)
{/*{{{*/
  cassert(terminals.used != 0 && nonterminals.used != 0 && firsts.used != 0 && follows.used != 0 && kernels.used != 0);

  // - create empty table -
  lalr_table.clear();
  lalr_table.resize(terminals.used + nonterminals.used,kernels.used);
  lalr_table.fill(c_idx_not_exist);

  {
    unsigned k_idx = 0;

    // - loop through all kernels -
    do
    {
      p_kernel_gotos_s &gotos = kernels[k_idx].gotos;

      // - if array gotos contain some elements -
      if (gotos.used != 0)
      {
        unsigned g_idx = 0;

        // - loop through all elements in gotos array -
        do
        {
          unsigned &value = lalr_table.value(gotos[g_idx].ui_second,gotos[g_idx].ui_first);

          // - if element is terminal (gotos[g_idx].ui_second < terminals.used)
          // write action shift to table of actions, otherwise write index of
          // target state to table of transitions -

          // - ERROR -
          if (value != c_idx_not_exist)
          {
            interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
            exception_s::throw_exception(it,c_error_PARSER_CREATE_SLR1_PARSE_TABLE_CONFLICT,0,(location_s *)it.blank_location);

            return false;
          }

          value = k_idx;
        }
        while(++g_idx < gotos.used);
      }
    }
    while(++k_idx < kernels.used);
  }

  {
    unsigned k_idx = 0;

    do
    {
      p_kernel_rule_dots_s &rule_dots = kernels[k_idx].rule_dots;
      unsigned rd_idx = 0;

      // - loop through all rules in kernel -
      do
      {
        p_kernel_rule_dot_s &rule_dot = rule_dots[rd_idx];

        // - if iterator is at end of rule body -
        if (rules[rule_dot.ui_first].body.used == rule_dot.ui_second)
        {
          p_follow_set_s &head_follow = follows[rules[rule_dot.ui_first].head - terminals.used];

          // - if set follow of rule head is not empty -
          if (head_follow.used != 0)
          {
            unsigned hf_idx = 0;

            // - loop through all elements in set head_follow -
            do
            {
              // - if element is terminal symbol -
              if (head_follow[hf_idx] < terminals.used)
              {
                bool good = true;
                unsigned rd2_idx = 0;

                // - check if there is such rule in kernel, that enables shift action, if no good == true -
                do
                {
                  p_kernel_rule_dot_s &rule_dot2 = rule_dots[rd2_idx];

                  if (rules[rule_dot2.ui_first].body.used > rule_dot2.ui_second)
                  {
                    if (head_follow[hf_idx] == rules[rule_dot2.ui_first].body[rule_dot2.ui_second])
                    {
                      good = false;
                      break;
                    }
                  }
                }
                while(++rd2_idx < rule_dots.used);

                // - if reduction is not premature, write reduction to reduction table bz rule rule_dots[rd_idx] -
                if (good)
                {
                  unsigned &value = lalr_table.value(head_follow[hf_idx],k_idx);

                  // - ERROR -
                  if (value != c_idx_not_exist)
                  {
                    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
                    exception_s::throw_exception(it,c_error_PARSER_CREATE_SLR1_PARSE_TABLE_CONFLICT,0,(location_s *)it.blank_location);

                    return false;
                  }

                  value = c_lalr_table_reduce_base + rule_dots[rd_idx].ui_first;
                }
                else
                {
                  unsigned &value = lalr_table.value(head_follow[hf_idx],k_idx);

                  // - ERROR -
                  if (value == c_idx_not_exist)
                  {
                    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
                    exception_s::throw_exception(it,c_error_PARSER_CREATE_CANNOT_RESOLVE_RULE_HEAD_FOR_SHIFT_ACTION,0,(location_s *)it.blank_location);

                    return false;
                  }
                }
              }
            }
            while(++hf_idx < head_follow.used);
          }
        }
      }
      while(++rd_idx < rule_dots.used);
    }
    while(++k_idx < kernels.used);
  }

  return true;
}/*}}}*/

// -- p_rule_descr_s --
@begin
methods p_rule_descr_s
@end

// -- p_rule_descrs_s --
@begin
methods p_rule_descrs_s
@end

// -- parser_s --
@begin
methods parser_s
@end

bool parser_s::create_from_rule_string(string_s &rule_string)
{/*{{{*/
  clear();

  p_creat_descr_s creat_descr;
  creat_descr.init();

  // - set interpreter thread pointer -
  creat_descr.it_ptr = it_ptr;

  // - read final automata set used for processing rules file -
  creat_descr.load_final_automata_set_new();

  // - read terminals, nonterminals and rules from string -
  if (!creat_descr.load_from_rule_string(rule_string))
  {
    creat_descr.clear();

    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

    // - throw exception if not thrown yet -
    if (it.exception_location == it.blank_location)
    {
      exception_s::throw_exception(it,c_error_PARSER_CREATE_UNSPECIFIED_ERROR,0,(location_s *)it.blank_location);
    }

    return false;
  }

  // - store count of grammar terminals -
  terminal_cnt = creat_descr.terminals.used;

  if (!(creat_descr.find_key_terminals(end_terminal,skip_terminals)
        && creat_descr.create_final_automata_new(final_automata)
        && creat_descr.compute_firsts()
        && creat_descr.compute_follows()
        && creat_descr.compute_kernels()
        && creat_descr.create_lalr_table(lalr_table)))
  {
    creat_descr.clear();

    interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

    // - throw exception if not thrown yet -
    if (it.exception_location == it.blank_location)
    {
      exception_s::throw_exception(it,c_error_PARSER_CREATE_UNSPECIFIED_ERROR,0,(location_s *)it.blank_location);
    }

    return false;
  }

  // - retrieve init semantic code -
  {
    p_rules_s &rules = creat_descr.rules;
    rule_descrs.used = 0;

    if (rules.used != 0)
    {
      rule_descrs.copy_resize(rules.used);

      unsigned r_idx = 0;

      // - loop through all rules -
      do
      {
        p_rule_descr_s &rule_descr = rule_descrs.data[r_idx];
        p_rule_s &rule = rules[r_idx];

        rule_descr.head = rule.head;
        rule_descr.body_size = rule.body.used;

      }
      while(++r_idx < rules.used);

      rule_descrs.used = rules.used;
    }
  }

  creat_descr.clear();

  return true;
}/*}}}*/

