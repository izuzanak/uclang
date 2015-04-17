
@begin
include "parser_code.h"
@end

// - basic constants and definitions -

/*
 * terminaly nacitane ze souboru popisujiciho jazyk
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
 * regularni vyrazy popisujici terminaly v souboru pravidel
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
 * indexy terminalu definujicich specialni funkcnost v prekladaci
 * ktt_skip - ignorovane prekladacem
 * ktt_end - terminal ukoncujici rozklad
 */
enum
{
  ktt_skip,
  ktt_end
};

/*
 * retezce popisujici terminaly s vyznamem pro prekladac
 * ingnorovanych terminalu by melo byt mozne definovat vic, to je umozneno
 * zapisem libovolneho poctu podtrzitek pred a za slovem SKIP
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
  if (used != second.used) return false;
  if (used == 0) return true;

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
  if (add_set.used == 0) return;

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
  if (used == 0) return c_idx_not_exist;

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
  if (used == 0) return c_idx_not_exist;

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
  if (used == 0) return c_idx_not_exist;

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

  // - rada popisu novych stavu -
  fa_state_descr_queue_s queue;
  queue.init();

  fa_state_reg_states_s state_descrs;
  state_descrs.init();

  // - pole prechodu vyuzivane v ramci jednoho stavu -
  fa_state_moves_array_s moves_array;
  moves_array.init();

  // - pracovni zasobnik pro nektere volane funkce, aby se zbytecne nemusel alokovat pro kazdou novy -
  ui_array_s work_stack;
  work_stack.init();

  // - promenna popisujici nove vytvareny stav automatu -
  fa_state_descr_s new_state_descr;
  new_state_descr.init();

  // - vlozeni prvniho zaznamu do rady popisu stavu -
  {
    /*
     * stav ze ktereho se vstupuje do prvniho stavu neexistuje
     * mnozina reg. vyrazu obsahuje vsechny s indexem na pozici 0
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

  // - cyklus dokud neni prazdna rada popisu stavu -
  do
  {

    // - ziska nasledujici popis stavu z rady -
    fa_state_descr_s q_state_descr;
    q_state_descr.init();
    q_state_descr.swap(queue.next());

    // - kontrola jestli jiz neni stejny stav definovany -
    unsigned state_descr_idx = state_descrs.get_idx(q_state_descr.reg_states);
    if (state_descr_idx != c_idx_not_exist)
    {

      /*
       * pokud ano, tak ziskej stav ze ktereho se prechazi do tohoto stavu
       * ziskej index prechodu v tomto stavu, ktery souhlasi se znakem
       * se kterym se prechazi, a ve stavu ze ktereho se prechazi indentifikuj jako
       * cilovy tento stav
       * pokracuj od zacatku
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

    // - vytvoreni noveho stavu automatu, vytvor ref. na jeho koncovy terminal a mnozinu prechodu-
    states.push_blank();
    unsigned &state_final = states.last().final;
    state_final = c_idx_not_exist;
    fa_state_moves_s &state_moves = states.last().moves;

    // - nastaveni prechodu do tohoto stavu -
    reg_states_s &p_reg_states = q_state_descr.reg_states;
    cassert(p_reg_states.used != 0);

    // - pokud existuje stav ze ktereho se vstoupilo do tohoto stavu -
    if (q_state_descr.from_state_id != c_idx_not_exist)
    {

      // - tak v tomto stavu nastav prechod do noveho stavu -
      fa_state_s &from_state = states[q_state_descr.from_state_id];

      fa_state_move_s s_move;
      s_move.idx = q_state_descr.with_char;

      unsigned move_idx = from_state.moves.get_map_idx(s_move);
      cassert(move_idx != c_idx_not_exist);
      from_state.moves[move_idx].value = states.used - 1;
    }

    // - vygenerovani pole prechodu z aktualnich pozic ve vyrazech -
    moves_array.used = 0;
    reg_state_s *p_reg_state_ptr = p_reg_states.data;
    reg_state_s *p_reg_state_ptr_end = p_reg_state_ptr + p_reg_states.used;

    // - cyklus pres seznam regularnich vyrazu stavu a generovani mnoziny moznych prechodu -
    do
    {
      moves_array.push_blank();

      fa_state_s &state = states_array[p_reg_state_ptr->ui_first][p_reg_state_ptr->ui_second];
      moves_array.last() = state.moves;

      // - prirazeni regularniho vyrazu ke koncovemu stavu -
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

      // - vybere dalsi prechodovy znak z mnoziny -
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

      // - pridani noveho prechodu ze stavu bez urceni ciloveho stavu -
      state_moves.push_blank();
      state_moves.last().idx = move_char;

      // - vytvoreni popisu noveho stavu (cile prechodu s move_char) -
      new_state_descr.from_state_id = states.used - 1;
      new_state_descr.with_char = move_char;
      reg_states_s &new_reg_states = new_state_descr.reg_states;

      new_reg_states.used = 0;

      // - nalezeni a zpracovani vsech prechodu s timto znakem -
      p_reg_state_ptr = p_reg_states.data;
      moves_ptr = moves_array.data;
      moves_ptr_end = moves_ptr + moves_array.used;

      // - cyklus pres vsechny prechody -
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

      // - vlozi popis noveho stavu do rady popisu stavu -
      queue.insert_blank();
      queue.last().swap(new_state_descr);
    }
    while(1);

    // - ulozi popis jiz akceptovaneho stavu, pro kontrolu podobnosti stavu -
    state_descrs.push_blank();
    state_descrs.last().swap(q_state_descr.reg_states);
    q_state_descr.clear();

  }
  while(queue.used > 0);

  // - orezani zbytecne pridelene pameti -
  states.flush();

  // - odstrani docasne pouzivane dynamicke data -
  new_state_descr.clear();
  work_stack.clear();
  moves_array.clear();
  state_descrs.clear();
  queue.clear();

  /*
   * vytvoreni efektivni ale rozsahle mnoziny prechodu jednotlivych stavu
   */

  state_moves.copy_resize(states.used);

  // - cyklus pres vsechny stavy automatu -
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

      // - cyklus pres prechody stavu a jejich vyplneni do tabulky prechodu -
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
            // - zpracovani specialnich reg. znaku -
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
  debug_assert(input != NULL);

  // - nastaveni pocatecniho stavu -
  state_idx = 0;

  // - nekonecny cyklus hledajici terminal -
  do
  {
    // - ziskani ref. na aktualni stav a priprava promenne pro nasledny stav -
    fa_state_s &state = states[state_idx];
    unsigned next_state_idx = c_idx_not_exist;

    // - zpracovani nasledujiciho vstupniho znaku -
    unsigned short in_char;
    if (input_idx < input_length)
    {
      in_char = (unsigned char)input[input_idx];
    }
    else
    {
      in_char = '\0';
    }

    // - prechod do nasledujiciho stavu -
    next_state_idx = state_moves[state_idx][in_char];

    // - prechod do nasledujiciho stavu pokud existuje -
    if (next_state_idx != c_idx_not_exist)
    {
      // - ukonceni vstupu -
      if (in_char == '\0')
      {
        return states[next_state_idx].final;
      }

      input_idx++;

      state_idx = next_state_idx;
    }

    // - neexistuje prechod do dalsiho stavu, rozpoznany terminal je state.final -
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

  if (in_char >= 93 && in_char < 257)
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

  if (in_char >= 93 && in_char < 257)
    goto state_24_label;

  return c_idx_not_exist;

// - STATE 11 -
state_11_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_11_label;

  if (in_char == 92)
    goto state_25_label;

  if (in_char == 93)
    goto state_26_label;

  if (in_char >= 94 && in_char < 256)
    goto state_11_label;

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
    goto state_16_label;

  if (in_char == 92)
    goto state_27_label;

  if (in_char >= 93 && in_char < 124)
    goto state_16_label;

  if (in_char == 124)
    goto state_28_label;

  if (in_char >= 125 && in_char < 256)
    goto state_16_label;

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

  if (in_char >= 93 && in_char < 257)
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

  if (in_char >= 93 && in_char < 257)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 25 -
state_25_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_11_label;

  if (in_char == 39)
    goto state_11_label;

  if (in_char >= 48 && in_char < 56)
    goto state_40_label;

  if (in_char >= 62 && in_char < 64)
    goto state_11_label;

  if (in_char >= 92 && in_char < 94)
    goto state_11_label;

  if (in_char >= 97 && in_char < 99)
    goto state_11_label;

  if (in_char == 102)
    goto state_11_label;

  if (in_char == 110)
    goto state_11_label;

  if (in_char == 114)
    goto state_11_label;

  if (in_char == 116)
    goto state_11_label;

  if (in_char == 118)
    goto state_11_label;

  if (in_char == 120)
    goto state_41_label;

  if (in_char >= 124 && in_char < 126)
    goto state_11_label;

  return c_idx_not_exist;

// - STATE 26 -
state_26_label:
  CLOSE_CHAR(8);
  return 8;

// - STATE 27 -
state_27_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_16_label;

  if (in_char == 39)
    goto state_16_label;

  if (in_char >= 48 && in_char < 56)
    goto state_42_label;

  if (in_char >= 62 && in_char < 64)
    goto state_16_label;

  if (in_char >= 92 && in_char < 94)
    goto state_16_label;

  if (in_char >= 97 && in_char < 99)
    goto state_16_label;

  if (in_char == 102)
    goto state_16_label;

  if (in_char == 110)
    goto state_16_label;

  if (in_char == 114)
    goto state_16_label;

  if (in_char == 116)
    goto state_16_label;

  if (in_char == 118)
    goto state_16_label;

  if (in_char == 120)
    goto state_43_label;

  if (in_char >= 124 && in_char < 126)
    goto state_16_label;

  return c_idx_not_exist;

// - STATE 28 -
state_28_label:
  CLOSE_CHAR(9);
  return 9;

// - STATE 29 -
state_29_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 34)
    goto state_30_label;

  if (in_char == 39)
    goto state_30_label;

  if (in_char >= 48 && in_char < 56)
    goto state_44_label;

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
    goto state_45_label;

  if (in_char >= 124 && in_char < 126)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 30 -
state_30_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_46_label;

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
    goto state_47_label;

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
    goto state_48_label;

  if (in_char >= 65 && in_char < 71)
    goto state_48_label;

  if (in_char >= 97 && in_char < 103)
    goto state_48_label;

  return c_idx_not_exist;

// - STATE 33 -
state_33_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_35_label;

  if (in_char >= 48 && in_char < 56)
    goto state_49_label;

  return c_idx_not_exist;

// - STATE 34 -
state_34_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_50_label;

  if (in_char >= 65 && in_char < 71)
    goto state_50_label;

  if (in_char >= 97 && in_char < 103)
    goto state_50_label;

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
    goto state_51_label;

  if (in_char >= 56 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 257)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 37 -
state_37_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_52_label;

  if (in_char >= 65 && in_char < 71)
    goto state_52_label;

  if (in_char >= 97 && in_char < 103)
    goto state_52_label;

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
    goto state_53_label;

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
    goto state_54_label;

  if (in_char >= 124 && in_char < 126)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 39 -
state_39_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 62)
    goto state_55_label;

  return c_idx_not_exist;

// - STATE 40 -
state_40_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_11_label;

  if (in_char >= 48 && in_char < 56)
    goto state_56_label;

  if (in_char >= 56 && in_char < 92)
    goto state_11_label;

  if (in_char == 92)
    goto state_25_label;

  if (in_char == 93)
    goto state_26_label;

  if (in_char >= 94 && in_char < 256)
    goto state_11_label;

  return c_idx_not_exist;

// - STATE 41 -
state_41_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_57_label;

  if (in_char >= 65 && in_char < 71)
    goto state_57_label;

  if (in_char >= 97 && in_char < 103)
    goto state_57_label;

  return c_idx_not_exist;

// - STATE 42 -
state_42_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_16_label;

  if (in_char >= 48 && in_char < 56)
    goto state_58_label;

  if (in_char >= 56 && in_char < 92)
    goto state_16_label;

  if (in_char == 92)
    goto state_27_label;

  if (in_char >= 93 && in_char < 124)
    goto state_16_label;

  if (in_char == 124)
    goto state_28_label;

  if (in_char >= 125 && in_char < 256)
    goto state_16_label;

  return c_idx_not_exist;

// - STATE 43 -
state_43_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_59_label;

  if (in_char >= 65 && in_char < 71)
    goto state_59_label;

  if (in_char >= 97 && in_char < 103)
    goto state_59_label;

  return c_idx_not_exist;

// - STATE 44 -
state_44_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_46_label;

  if (in_char >= 48 && in_char < 56)
    goto state_60_label;

  return c_idx_not_exist;

// - STATE 45 -
state_45_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_61_label;

  if (in_char >= 65 && in_char < 71)
    goto state_61_label;

  if (in_char >= 97 && in_char < 103)
    goto state_61_label;

  return c_idx_not_exist;

// - STATE 46 -
state_46_label:
  CLOSE_CHAR(5);
  return 5;

// - STATE 47 -
state_47_label:
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

// - STATE 48 -
state_48_label:
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

// - STATE 49 -
state_49_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_35_label;

  if (in_char >= 48 && in_char < 56)
    goto state_22_label;

  return c_idx_not_exist;

// - STATE 50 -
state_50_label:
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

// - STATE 51 -
state_51_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_39_label;

  if (in_char >= 48 && in_char < 56)
    goto state_62_label;

  if (in_char >= 56 && in_char < 62)
    goto state_39_label;

  if (in_char == 62)
    goto state_63_label;

  if (in_char >= 63 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 257)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 52 -
state_52_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 48)
    goto state_39_label;

  if (in_char >= 48 && in_char < 58)
    goto state_62_label;

  if (in_char >= 58 && in_char < 65)
    goto state_39_label;

  if (in_char >= 65 && in_char < 71)
    goto state_62_label;

  if (in_char >= 71 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 97)
    goto state_39_label;

  if (in_char >= 97 && in_char < 103)
    goto state_62_label;

  if (in_char >= 103 && in_char < 257)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 53 -
state_53_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 56)
    goto state_64_label;

  if (in_char == 62)
    goto state_55_label;

  return c_idx_not_exist;

// - STATE 54 -
state_54_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_65_label;

  if (in_char >= 65 && in_char < 71)
    goto state_65_label;

  if (in_char >= 97 && in_char < 103)
    goto state_65_label;

  return c_idx_not_exist;

// - STATE 55 -
state_55_label:
  CLOSE_CHAR(7);
  return 7;

// - STATE 56 -
state_56_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_11_label;

  if (in_char == 92)
    goto state_25_label;

  if (in_char == 93)
    goto state_26_label;

  if (in_char >= 94 && in_char < 256)
    goto state_11_label;

  return c_idx_not_exist;

// - STATE 57 -
state_57_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_11_label;

  if (in_char == 92)
    goto state_25_label;

  if (in_char == 93)
    goto state_26_label;

  if (in_char >= 94 && in_char < 256)
    goto state_11_label;

  return c_idx_not_exist;

// - STATE 58 -
state_58_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_16_label;

  if (in_char == 92)
    goto state_27_label;

  if (in_char >= 93 && in_char < 124)
    goto state_16_label;

  if (in_char == 124)
    goto state_28_label;

  if (in_char >= 125 && in_char < 256)
    goto state_16_label;

  return c_idx_not_exist;

// - STATE 59 -
state_59_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 92)
    goto state_16_label;

  if (in_char == 92)
    goto state_27_label;

  if (in_char >= 93 && in_char < 124)
    goto state_16_label;

  if (in_char == 124)
    goto state_28_label;

  if (in_char >= 125 && in_char < 256)
    goto state_16_label;

  return c_idx_not_exist;

// - STATE 60 -
state_60_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_46_label;

  if (in_char >= 48 && in_char < 56)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 61 -
state_61_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char == 39)
    goto state_46_label;

  if (in_char >= 48 && in_char < 58)
    goto state_30_label;

  if (in_char >= 65 && in_char < 71)
    goto state_30_label;

  if (in_char >= 97 && in_char < 103)
    goto state_30_label;

  return c_idx_not_exist;

// - STATE 62 -
state_62_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char < 62)
    goto state_39_label;

  if (in_char == 62)
    goto state_63_label;

  if (in_char >= 63 && in_char < 92)
    goto state_39_label;

  if (in_char == 92)
    goto state_38_label;

  if (in_char >= 93 && in_char < 257)
    goto state_39_label;

  return c_idx_not_exist;

// - STATE 63 -
state_63_label:
  CLOSE_CHAR(7);
  GET_NEXT_CHAR();

  if (in_char == 62)
    goto state_55_label;

  return 7;

// - STATE 64 -
state_64_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 56)
    goto state_39_label;

  if (in_char == 62)
    goto state_55_label;

  return c_idx_not_exist;

// - STATE 65 -
state_65_label:
  CLOSE_CHAR(c_idx_not_exist);
  GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_39_label;

  if (in_char == 62)
    goto state_55_label;

  if (in_char >= 65 && in_char < 71)
    goto state_39_label;

  if (in_char >= 97 && in_char < 103)
    goto state_39_label;

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

  // - pole obsahujici zacatky a konce jednotlivych casti konecneho automatu -
  ui_array_s begin_idxs;
  begin_idxs.init();

  ui_array_s end_idxs;
  end_idxs.init();

  // - promenne pouzivane pri rozkladu regularniho vyrazu -
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

    // - nalezeni akce v tabulce akci -
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

      // - vlozi na zasobnik novy stav a pozici terminalu ve zdrojovem retezci -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // -akce REDUCE-
    else
    {
      parse_action -= c_reg_lalr_table_reduce_base;

      // - vypis indexu pravidla redukce na vystup -
      switch (parse_action)
      {
      case c_reduce_alter:
      {/*{{{*/
        unsigned second_begin_idx = begin_idxs.pop();
        unsigned first_begin_idx = begin_idxs.pop();

        unsigned second_end_idx = end_idxs.pop();
        unsigned first_end_idx = end_idxs.pop();

        // - vytvoreni noveho stavu -
        states.push_blank();
        unsigned begin_state_idx = states.used - 1;
        fa_state_s &begin_state = states[begin_state_idx];
        begin_state.final = 0;

        begin_state.moves.push_blank();
        begin_state.moves.last().set(0xffff,first_begin_idx);

        begin_state.moves.push_blank();
        begin_state.moves.last().set(0xffff,second_begin_idx);

        // - vytvoreni koncoveho stavu -
        states.push_blank();
        unsigned end_state_idx = states.used - 1;
        states[end_state_idx].final = 0;

        // - spojeni koncu obou casti do koncoveho stavu -
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

        // - poznamenani konce druhe casti -
        unsigned tmp_end = end_idxs.pop();

        unsigned first_end_idx = end_idxs.pop();

        // - pripojeni konce prvni casti k zacatku druhe casti -
        fa_state_s &state = states[first_end_idx];
        state.moves.push_blank();
        state.moves.last().set(0xffff,second_begin_idx);

        // - zapis konce druhe casti -
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

        // - vygenerovani prijimanych znaku -
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

          // - doplneni znaku -
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

      // - odstraneni tela pravidla z vrcholu zasobniku -
      lalr_stack.used -= reg_rule_body_lengths[parse_action];

      // - ulozeni noveho stavu automatu na zasobnik -
      unsigned goto_val = reg_lalr_table[lalr_stack.last().lalr_state*c_reg_terminal_plus_nonterminal_cnt + reg_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  // - zapsani pocatecniho stavu automatu -
  fas_idx = begin_idxs.pop();

  // - oznaceni konecnych stavu -
  states[end_idxs.pop()].final = 1;

  end_idxs.clear();
  begin_idxs.clear();

  return true;
}/*}}}*/

bool reg_parser_s::NKA_to_DKA()
{/*{{{*/

  // - presunuti nedeterministickeho automatu -
  unsigned nka_fas_idx = fas_idx;
  fas_idx = 0;

  fa_states_s nka_states;
  nka_states.init();
  nka_states.swap(states);

  // - mnoziny eps-uzaveru jednotlivych stavu nk-automatu -
  ui_array_sets_s eps_closures;
  eps_closures.init();

  // - seznam jiz zpracovanych multi stavu s jejich indexy ve vytvarenem automatu -
  reg_mul_state_map_array_s ms_map_array;
  ms_map_array.init();

  // - rada potencialne nezpracovanych stavu -
  reg_mul_state_move_queue_s msm_queue;
  msm_queue.init();

  // - spocitani eps-uzaveru jednotlivych stavu, a konecnosti stavu pri uvazovani eps. prechodu -
  {
    eps_closures.copy_resize(nka_states.used);
    eps_closures.used = nka_states.used;

    ui_array_s state_idx_stack;
    state_idx_stack.init();

    bb_array_s processed_states;
    processed_states.init();
    processed_states.copy_resize(nka_states.used);

    // - cyklus pres vsechny stavy nedeterministickeho automatu -
    unsigned s_idx = 0;
    do
    {
      ui_array_set_s &eps_closure = eps_closures[s_idx];

      state_idx_stack.used = 0;
      state_idx_stack.push(s_idx);

      processed_states.fill(false);

      // - cyklus do vyprazdneni zasobniku -
      do
      {
        unsigned ss_idx = state_idx_stack.pop();

        // - pokud je jiz uzaver stavu na pozici ss_idx spocitan, zkopiruj jeho obsah do pocitaneho uzaveru -
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

          // - pokud se stav na pozici ss_idx v uzaveru nenachazi tak jej do nej vloz -
          if (!processed_states[ss_idx])
          {

            // - stavy do kterych se z vlozeneho stavu prechazi s eps. prechodem pridej do
            // zasobniku -
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

            // - pokud stav obsahuje i jine nez eps. prechody pridej jej do eps uzaveru -
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

  // - vlozeni pocatecniho stavu {0} do vstupni rady -
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

      // - vytvoreni noveho stavu -
      states.push_blank();
      fa_state_s &state = states.last();
      state.final = 0;

      ms_map_array.push_blank();
      reg_mul_state_map_s &ms_map = ms_map_array.last();
      ms_map.mul_state.swap(mul_state_move.mul_state);
      ms_map.dka_state_idx = states.used - 1;

      mul_state_idx = ms_map_array.used - 1;

      // - nalezeni dalsich prechodu z noveho stavu -
      new_mul_state_moves.used = 0;
      ui_array_set_s &mul_state = ms_map.mul_state;

      // - cyklus pres vsechny nka stavy v eps. uzaveru -
      if (mul_state.used != 0)
      {
        unsigned s_idx = 0;
        do
        {
          fa_state_s &nka_state = nka_states[mul_state[s_idx]];

          // - nastaveni konecnosti noveho stavu -
          if (nka_state.final)
          {
            state.final = 1;
          }

          reg_state_moves_s &state_moves = nka_state.moves;

          // - cyklus pres vsechny prechody v aktualnim stavu (z eps. uzaveru) -
          if (state_moves.used != 0)
          {
            unsigned m_idx = 0;
            do
            {
              reg_state_move_s &move = state_moves[m_idx];

              // - kdyz se nejedna o eps. prechod -
              if (move.idx != 0xffff)
              {

                // - generuj nove kandidaty na stav deterministickeho automatu -
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

    // - zapis prechodu do tohoto stavu -
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
  if (used == 0) return c_idx_not_exist;

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
  if (used == 0) return c_idx_not_exist;

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
  if (used == 0) return c_idx_not_exist;

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
  if (used == 0) return c_idx_not_exist;

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

  // - zpracovani reg. vyrazu urcenych pro cteni souboru pravidel -
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

  // - zpracovani reg. vyrazu rozpoznavajicich klicove terminaly -
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

  // - skip semantic code -
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
      // - dokud neni vracen terminal rt_nonterminals -
      old_input_idx = input_idx;
      if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_nonterminals)
      {
        break;
      }

      // - preskakuj bile mista a kometare -
      if (ret_term <= rt_sec_comment)
      {
        continue;
      }

      // - nacteni jmena terminalu -
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

      // - regularni vyraz popisujici terminal -
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

  // - zpracovani nonterminalu -
  {
    p_nonterminal_s new_nonterminal;
    new_nonterminal.init();

    do
    {
      // - dokud neni vracen terminal rt_rules -
      old_input_idx = input_idx;
      if ((ret_term = rule_file_fa.recognize(a_data,input_idx,input_length)) == rt_rules)
      {
        break;
      }

      // - preskoc bila mista -
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

      // - nacteni jmena neterminalniho symbolu -
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

  // - zpracovani pravidel -
  {
    unsigned rule_head_index = 0;
    unsigned rule_state = 0;
    p_rule_s new_rule;
    new_rule.init();

    do
    {
      // - dokud neni vracen konec vstupu -
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
        // - nacteni hlavy pravidla -
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

        // - potvrzeni oddeleni hlavy pravidla a jeho tela -
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
        // - nacteni tela pravidla -
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

          // - oddeleni tela pravidla a jeho semantickeho kodu -
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

        // - nacteni semantickeho kodu pravidla -
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

  // - vypocet mnozin firsts pro nonterminalni symboly
  {
    unsigned non_idx = 0;

    do
    {
      first_set.used = 0;
      first_rule_idxs_sets.used = 0;

      first_set.push(non_idx + terminals.used);
      first_rule_idxs_sets.push_clear();

      // - cyklus pres elementy v mnozine first -
      unsigned fs_idx = 0;
      do
      {
        // - pokud je element nonterminal -
        if (first_set[fs_idx] >= terminals.used)
        {
          unsigned r_idx = 0;

          // - cyklus pres vsechny pravidla -
          do
          {
            p_rule_s &rule_ref = rules[r_idx];

            // - kdyz je hlava pravidla stejna jako kontrolovany nonterminal -
            if (rule_ref.head == first_set[fs_idx])
            {
              unsigned first_body = rule_ref.body[0];

              // - kdyz element jeste neni v mnozine first_set -
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

      // - vlozeni mnoziny first nonterminalu do seznamu -
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

  // - cyklus pres vsechny pravidla -
  do
  {
    p_rule_s &rule = rules[r_idx];
    unsigned rb_idx = 0;

    // - cyklus pres pravou stranu pravidla -
    do
    {
      // - kdyz je nalezen sledovany nonterminal -
      if (nonterm_idx == rule.body[rb_idx])
      {

        // - pokud se nachazi uvnitr tela pravidla -
        if (rb_idx < rule.body.used - 1)
        {
          unsigned element = rule.body[rb_idx + 1];

          // - kdyz je element terminal vloz jej do mnoziny follow -
          if (element < terminals.used)
          {
            if (ret_follows.get_idx(element) == c_idx_not_exist)
            {
              ret_follows.push(element);
            }
          }

          // - kdyz je element nonterminal vloz jeho first mnozinu do mnoziny follow -
          else
          {
            ret_follows.add_to_set(firsts[element - terminals.used]);
          }
        }

        // - kdyz se nachazi na konci pravidla -
        else
        {

          // - pokud hlava pravidla jeste nebyla pouzita na rozepsani pouzij ji -
          if (nonterm_used.get_idx(rule.head) == c_idx_not_exist)
          {

            // - jestli jiz byla spocitana mnozina follow hlavy vloz ji do mnoziny follow
            // jinak ji spocitej a spocitej a zaznamenej vypocet jeji mnoziny follow pokud
            // probehl ciste (tj. bez omezeni pocitani nekterych neterminalu) -
            if (!follows_created[rule.head - terminals.used])
            {
              nonterm_used.push(rule.head);

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

            ret_follows.add_to_set(follows[rule.head - terminals.used]);
          }

          // - kdyz uz byla pouzita hlava pravidla na rozepsani nepokracuj ale oznac vypocet za necisty -
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

  // - cyklus pres vsechny neterminaly -
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

  // - vytvoreni prvniho jadra rozkladu obsahujiciho prvni pravidlo s iteratorem pred prvnim elementem pravidla -
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

  // - cyklus pres jiz vytvorena jadra -
  do
  {
    // - pokud jadro obsahuje nejake pravidla -
    if (kernels[k_idx].rule_dots.used != 0)
    {
      p_kernel_rule_dots_s *rule_dots = &kernels[k_idx].rule_dots;

      unsigned rd_idx = 0;

      // - cyklus pres vsechny pravidla jadra -
      do
      {
        p_kernel_rule_dot_s *rule_dot = rule_dots->data + rd_idx;

        // - kdyz iterator neni na konci tela pravidla -
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

            // - cyklus pres vsechny cleny v mnozine element_first -
            do
            {
              // - vyvor nove jadro rozkladu -
              p_kernel_rule_dots_s &nk_rule_dots = new_kernel.rule_dots;
              nk_rule_dots.used = 0;

              // - vloz vsechny pravidla ktera generuji element v mnozine first s iteratorem za timto
              // prvnim elementem -
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

              // - pokud je prvkem v mnozine first samotny element zkopiruj jeho pravidlo z aktualniho jadra
              // a posun iterator za nej -
              if (ef_idx == 0)
              {
                nk_rule_dots.push(kernels[k_idx].rule_dots[rd_idx]);
                nk_rule_dots.last().ui_second++;
              }

              // - do mnoziny prechodu vloz prechod ze zpracovavaneho jadra se zpracovavanym elementem
              // ve first -
              p_kernel_gotos_s &gotos = new_kernel.gotos;
              gotos.used = 0;
              gotos.push_blank();
              gotos.data[0].set(k_idx,element_first[ef_idx]);

              // - prohledej jiz vygenerovane jadra -
              unsigned tmp_k_idx = kernels.get_idx_by_rule_dots(new_kernel);

              // - pokud neexistuje jadro se stejnou mnozinou rule_dots uloz nove -
              if (tmp_k_idx == c_idx_not_exist)
              {
                kernels.push_blank();
                kernels.last().swap(new_kernel);

                // - obnoveni ukazatelu po mozne realokaci pole -
                rule_dots = &kernels[k_idx].rule_dots;
                rule_dot = rule_dots->data + rd_idx;
              }

              // - pokud jiz existuje takove jadro pridej do jeho mnoziny gotos vygenerovany prechod -
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

  // - vytvori prazdnou tabulku -
  lalr_table.clear();
  lalr_table.resize(terminals.used + nonterminals.used,kernels.used);
  lalr_table.fill(c_idx_not_exist);

  {
    unsigned k_idx = 0;

    // - cyklus pres vsechny jadra rozkladu -
    do
    {
      p_kernel_gotos_s &gotos = kernels[k_idx].gotos;

      // - pokud pole gotos obsahuje nejake prvky -
      if (gotos.used != 0)
      {
        unsigned g_idx = 0;

        // - cyklus pres vsechny prvky v poli gotos -
        do
        {
          unsigned &value = lalr_table.value(gotos[g_idx].ui_second,gotos[g_idx].ui_first);

          // - pokud je element nonterminal (gotos[g_idx].ui_second < terminals.used)
          // zapis do tabulky akci shift, jinak zapis do tabulky prechodu cislo
          // stavu, na ktery se presunout po redukci -

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

      // - cyklus pres vsechny pravidla v jadre  -
      do
      {
        p_kernel_rule_dot_s &rule_dot = rule_dots[rd_idx];

        // - pokud se iterator nachazi na konci tela pravidla -
        if (rules[rule_dot.ui_first].body.used == rule_dot.ui_second)
        {

          p_follow_set_s &head_follow = follows[rules[rule_dot.ui_first].head - terminals.used];

          // - pokud neni follow mnozina hlavy pravidla prazdna -
          if (head_follow.used != 0)
          {
            unsigned hf_idx = 0;

            // - cyklus pres vsechny prvky v mnozine head_follow -
            do
            {
              // - pokud je element terminalni symbol -
              if (head_follow[hf_idx] < terminals.used)
              {
                bool good = true;
                unsigned rd2_idx = 0;

                // - Kontrola zda neexistuje v jadre takove pravidlo, ktere by umoznovalo akci shift tj. redukce by byla predcasna. Pokud ne good == true -
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

                // - pokud good zapise do tabulky redukci podle pravidla rule_dots[rd_idx] -
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

  // - nacteni konecnych automatu vyuzivanych ke zpracovani souboru pravidel -
  creat_descr.load_final_automata_set_new();

  // - nacteni terminalu, neterminalu a pravidel z retezce -
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

  // - ulozeni poctu terminalu gramatiky -
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

  // - vytvoreni popisu pravidel parseru -
  {
    p_rules_s &rules = creat_descr.rules;
    rule_descrs.used = 0;

    if (rules.used != 0)
    {
      rule_descrs.copy_resize(rules.used);

      unsigned r_idx = 0;

      // - cyklus pres vsechny pravidla -
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

