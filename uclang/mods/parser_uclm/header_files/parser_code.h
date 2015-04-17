
#ifndef __PARSER_CODE_H
#define __PARSER_CODE_H

@begin
include "script_parser.h"
@end

// - basic constants and definitions -

const unsigned c_base_char_cnt = 256;
const unsigned c_def_special_char_cnt = 3;
const unsigned c_no_char_base = c_base_char_cnt + c_def_special_char_cnt;

const unsigned short reg_char_white =  c_base_char_cnt;     // 'w' {' ','\t','\n'}
const unsigned short reg_char_digit =  c_base_char_cnt + 1; // 'd' {'0' - '9'}
const unsigned short reg_char_letter = c_base_char_cnt + 2; // 'l' {'a' - 'z','A' - 'Z'}

// - PARSER error identifiers -
enum
{
  c_error_FINAL_AUTOMATA_REGULAR_EXPRESSIONS_EMPTY = 0,
  c_error_FINAL_AUTOMATA_REGULAR_EXPRESSION_NOT_STRING,
  c_error_FINAL_AUTOMATA_REGULAR_EXPRESSION_PARSE_ERROR,
  c_error_PARSER_CREATE_UNSPECIFIED_ERROR,
  c_error_PARSER_CREATE_RULES_SYNTAX_ERROR,
  c_error_PARSER_CREATE_RULES_DUPLICATE_TERMINAL,
  c_error_PARSER_CREATE_RULES_DUPLICATE_NONTERMINAL,
  c_error_PARSER_CREATE_RULES_DUPLICATE_RULE,
  c_error_PARSER_CREATE_RULES_UNDEFINED_TERMINAL,
  c_error_PARSER_CREATE_RULES_UNDEFINED_NONTERMINAL,
  c_error_PARSER_CREATE_RULES_NO_TERMINALS_DEFINED,
  c_error_PARSER_CREATE_RULES_NO_NONTERMINALS_DEFINED,
  c_error_PARSER_CREATE_RULES_NO_RULES_DEFINED,
  c_error_PARSER_CREATE_MULTIPLE_PARSE_END_TERMINALS,
  c_error_PARSER_CREATE_TERMINAL_REGULAR_EXPRESSION_PARSE_ERROR,
  c_error_PARSER_CREATE_SLR1_PARSE_TABLE_CONFLICT,
  c_error_PARSER_CREATE_CANNOT_RESOLVE_RULE_HEAD_FOR_SHIFT_ACTION,
  c_error_PARSER_PARSE_UNRECOGNIZED_TERMINAL,
  c_error_PARSER_PARSE_SYNTAX_ERROR,
  c_error_PARSER_PARSE_STATE_OUTSIDE_OF_REDUCE_CALLBACK,
  c_error_PARSER_PARSE_STATE_INDEX_EXCEEDS_RULE_BODY_SIZE,
};

/*
 * identifikace operaci prirazenych k redukcim
 */

enum
{
  c_reduce_null_0 = 0,
  c_reduce_alter,
  c_reduce_null_1,
  c_reduce_conc,
  c_reduce_null_2,
  c_reduce_iter,
  c_reduce_char_eps,
  c_reduce_char,
  c_reduce_char_white,
  c_reduce_char_digit,
  c_reduce_char_letter,
  c_reduce_char_no_char,
  c_reduce_char_str,
  c_reduce_char_range,
  c_reduce_char_alter,
  c_reduce_char_except,
  c_reduce_null_3
};

// rozkladove konstanty
const unsigned c_reg_rule_cnt = 17;
const unsigned reg_rule_head_idxs[c_reg_rule_cnt] = {17, 18, 18, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, };
const unsigned reg_rule_body_lengths[c_reg_rule_cnt] = {2, 3, 1, 3, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, };

//rozkladova tabulka
#define reg_blank c_idx_not_exist
#define REG_SHIFT(VALUE) VALUE
#define REG_REDUCE(VALUE) c_reg_lalr_table_reduce_base + VALUE
#define REG_GOTO(VALUE) VALUE

const unsigned c_reg_lalr_table_reduce_base = 0x80000000;
const unsigned c_reg_terminal_plus_nonterminal_cnt = 21;
const unsigned c_reg_lalr_state_cnt = 23;

const unsigned reg_lalr_table[c_reg_lalr_state_cnt*c_reg_terminal_plus_nonterminal_cnt] =
{
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
};

/*
 * definition of generated structures
 */

// -- bb_array_s --
@begin
array<bool> bb_array_s;
@end

// -- ui_array_set_s --
@begin
array<unsigned>

additions
{
  bool set_compare(ui_array_set_s &second);
  void add_to_set(p_follow_set_s &add_set);
}

ui_array_set_s
p_first_set_s
p_follow_set_s;
@end

// -- ui_array_sets_s --
@begin
array<ui_array_set_s>
ui_array_sets_s
p_first_sets_s
p_follow_sets_s
p_rule_idxs_sets_s;
@end

// -- ui_array_sets_array_s --
@begin
array<ui_array_sets_s>
ui_array_sets_array_s
p_first_rules_sets_s;
@end

// -- reg_mul_state_move_s --
@begin
struct
    <
    usi:move_char
    unsigned:from_state
    ui_array_set_s:mul_state
    >
    reg_mul_state_move_s;
@end

// -- reg_mul_state_move_array_s --
@begin
array<reg_mul_state_move_s>

additions
{
  unsigned get_idx_by_move_char(unsigned short a_move_char);
}

reg_mul_state_move_array_s;
@end

// -- reg_mul_state_move_queue_s --
@begin
queue<reg_mul_state_move_s> reg_mul_state_move_queue_s;
@end

// -- reg_mul_state_map_s --
@begin
struct
    <
    ui_array_set_s:mul_state
    unsigned:dka_state_idx
    >
    reg_mul_state_map_s;
@end

// -- reg_mul_state_map_array_s --
@begin
array<reg_mul_state_map_s>

additions
{
  unsigned get_idx_by_mul_state(ui_array_set_s &a_mul_state);
}

reg_mul_state_map_array_s;
@end

// -- fa_state_move_s --
@begin
struct
    <
    usi:idx
    unsigned:value
    >
    fa_state_move_s
    reg_state_move_s;
@end

// -- fa_state_moves_s --
@begin
array<fa_state_move_s>

additions
{
  unsigned get_map_idx(fa_state_move_s &a_value);
}

fa_state_moves_s
reg_state_moves_s;
@end

// -- fa_state_moves_array_s --
@begin
array<fa_state_moves_s> fa_state_moves_array_s;
@end

// -- us_array_s --
@begin
array<usi> us_array_s;
@end

// -- fa_state_s --
@begin
struct
    <
    unsigned:final
    fa_state_moves_s:moves
    >
    fa_state_s;
@end

// -- fa_states_s --
@begin
array<fa_state_s> fa_states_s;
@end

// -- fa_states_array_s --
@begin
array<fa_states_s> fa_states_array_s;
@end

// -- reg_state_s --
@begin
struct
    <
    unsigned:ui_first
    unsigned:ui_second
    >
    reg_state_s
    p_kernel_rule_dot_s
    p_kernel_goto_s
    pcs_state_position_s;
@end

// -- reg_states_s --
@begin
array<reg_state_s>
reg_states_s
p_kernel_rule_dots_s
p_kernel_gotos_s
pcs_state_positions_s;
@end

// -- fa_state_descr_s --
@begin
struct
    <
    unsigned:from_state_id
    usi:with_char
    reg_states_s:reg_states
    >
    fa_state_descr_s;
@end

// -- fa_state_reg_states_s --
@begin
array<reg_states_s> fa_state_reg_states_s;
@end

// -- fa_state_descr_queue_s --
@begin
queue<fa_state_descr_s> fa_state_descr_queue_s;
@end

// -- final_automata_s --
@begin
struct
    <
    unsigned:state_idx
    fa_states_s:states
    ui_arrays_s:state_moves
    >

    additions
{
  void create_new(fa_states_array_s &states_array);
  unsigned recognize(char *input,unsigned &input_idx,unsigned input_length);
}

final_automata_s;
@end

// -- reg_parser_s --
@begin
struct
    <
    lalr_stack_s:lalr_stack
    unsigned:fas_idx
    fa_states_s:states
    >

    additions
{
  inline unsigned short process_char(char *&c_ptr);
  unsigned recognize_terminal(string_s &source_string,unsigned &input_idx);
  bool parse_reg_exp(string_s &source_string);
  bool NKA_to_DKA();
  inline bool process_reg_exp(string_s &source_string);
  bool process_reg_exps(string_array_s &source_strings,fa_states_array_s &states_array);
}

reg_parser_s;
@end

// -- p_terminal_s --
@begin
struct
    <
    string_s:idx
    string_s:value
    unsigned:source_pos
    >
    p_terminal_s;
@end

// -- p_terminals_s --
@begin
array<p_terminal_s>

additions
{
  unsigned get_map_idx(p_terminal_s &a_value);
  unsigned get_char_ptr_idx(unsigned a_length,char *a_data);
}

p_terminals_s;
@end

// -- p_nonterminal_s --
@begin
struct
    <
    string_s:name
    >
    p_nonterminal_s;
@end

// -- p_nonterminals_s --
@begin
array<p_nonterminal_s>

additions
{
  unsigned get_char_ptr_idx(unsigned a_length,char *a_data);
}

p_nonterminals_s;
@end

// -- p_rule_s --
@begin
struct
    <
    unsigned:head
    ui_array_s:body
    >
    p_rule_s;
@end

// -- p_rules_s --
@begin
array<p_rule_s> p_rules_s;
@end

// -- p_kernel_s --
@begin
struct
    <
    p_kernel_rule_dots_s:rule_dots
    p_kernel_gotos_s:gotos
    >
    p_kernel_s;
@end

// -- p_kernels_s --
@begin
array<p_kernel_s>

additions
{
  unsigned get_idx_by_rule_dots(p_kernel_s &a_value);
}

p_kernels_s;
@end

// -- p_lalr_table_s --
@begin
struct
    <
    unsigned:x_size
    unsigned:y_size
    ui_array_s:table
    >

    additions
{
  inline unsigned &value(unsigned a_x_idx,unsigned a_y_idx);
  inline void resize(unsigned a_x_size,unsigned a_y_size);
  inline void fill(unsigned a_value);
}

p_lalr_table_s;
@end

// -- p_creat_descr_s --
@begin
struct
    <
    pointer:it_ptr
    final_automata_s:rule_file_fa
    final_automata_s:key_terminals_fa
    p_terminals_s:terminals
    p_nonterminals_s:nonterminals
    p_rules_s:rules
    p_first_sets_s:firsts
    p_first_rules_sets_s:first_rules
    p_follow_sets_s:follows
    p_kernels_s:kernels
    >

    additions
{
  bool load_final_automata_set_new();
  bool load_from_rule_char_ptr(unsigned a_length,char *a_data);
  inline bool load_from_rule_string(string_s &rule_string);
  bool find_key_terminals(unsigned &end_terminal,ui_array_s &skip_terminals);
  bool create_final_automata_new(final_automata_s &final_automata);

  /*
   * spocita mnozinu firsts pro neterminaly
   * tj. mnozinu elementu se kterymi muze zacinat jakykoli literal rozepsatelny
   * z tohoto neterminalu
   */
  bool compute_firsts();

  /*
   * spocita mnozinu follow jednoho neterminalniho symbolu
   */
  bool compute_follows_of_nonterminal(unsigned nonterm_idx,bb_array_s &follows_created,ui_array_s &nonterm_used,p_follow_set_s &ret_follows);

  /*
   * spocita mnozinu follow ke vsem neterminalnim symbolum
   * tj. mnozinu obsahujici seznam elementu, ktere mohou v nejakem literalu
   * rozepsanem z pocatecniho symbolu gramatiky nasledovat za timto symbolem
   */
  bool compute_follows();

  /*
   * spocita jadra rozkladu prekladace podle nactenych pravidel
   * s vyuzitim mnozin firsts, first_rules a follows
   */
  bool compute_kernels();

  /*
   * vytvori rozkladovou tabulku na zaklade jader rozkladu
   */
  bool create_lalr_table(p_lalr_table_s &lalr_table);
}

p_creat_descr_s;
@end

// -- p_rule_descr_s --
@begin
struct
    <
    unsigned:head
    unsigned:body_size
    >
    p_rule_descr_s;
@end

// -- p_rule_descrs_s --
@begin
array<p_rule_descr_s> p_rule_descrs_s;
@end

// -- parser_s --
@begin
struct
    <
    pointer:it_ptr
    unsigned:terminal_cnt
    unsigned:end_terminal
    ui_array_s:skip_terminals
    p_rule_descrs_s:rule_descrs
    final_automata_s:final_automata
    p_lalr_table_s:lalr_table
    >

    additions
{
  bool create_from_rule_string(string_s &rule_string);
}

parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- bb_array_s --
@begin
inlines bb_array_s
@end

// -- ui_array_set_s --
@begin
inlines ui_array_set_s
@end

// -- ui_array_sets_s --
@begin
inlines ui_array_sets_s
@end

// -- ui_array_sets_array_s --
@begin
inlines ui_array_sets_array_s
@end

// -- reg_mul_state_move_s --
@begin
inlines reg_mul_state_move_s
@end

// -- reg_mul_state_move_array_s --
@begin
inlines reg_mul_state_move_array_s
@end

// -- reg_mul_state_move_queue_s --
@begin
inlines reg_mul_state_move_queue_s
@end

// -- reg_mul_state_map_s --
@begin
inlines reg_mul_state_map_s
@end

// -- reg_mul_state_map_array_s --
@begin
inlines reg_mul_state_map_array_s
@end

// -- fa_state_move_s --
@begin
inlines fa_state_move_s
@end

// -- fa_state_moves_s --
@begin
inlines fa_state_moves_s
@end

// -- fa_state_moves_array_s --
@begin
inlines fa_state_moves_array_s
@end

// -- us_array_s --
@begin
inlines us_array_s
@end

// -- fa_state_s --
@begin
inlines fa_state_s
@end

// -- fa_states_s --
@begin
inlines fa_states_s
@end

// -- fa_states_array_s --
@begin
inlines fa_states_array_s
@end

// -- reg_state_s --
@begin
inlines reg_state_s
@end

// -- reg_states_s --
@begin
inlines reg_states_s
@end

// -- fa_state_descr_s --
@begin
inlines fa_state_descr_s
@end

// -- fa_state_reg_states_s --
@begin
inlines fa_state_reg_states_s
@end

// -- fa_state_descr_queue_s --
@begin
inlines fa_state_descr_queue_s
@end

// -- final_automata_s --
@begin
inlines final_automata_s
@end

// -- reg_parser_s --
@begin
inlines reg_parser_s
@end

inline unsigned short reg_parser_s::process_char(char *&c_ptr)
{/*{{{*/
  if (*c_ptr == '\\')
  {
    c_ptr++;

    // - process char represented by octal number -
    if (*c_ptr >= '0' && *c_ptr <= '7')
    {
      unsigned short new_char = *c_ptr++ - '0';

      if (*c_ptr >= '0' && *c_ptr <= '7')
      {
        new_char = (new_char << 3) | (*c_ptr++ - '0');

        if (*c_ptr >= '0' && *c_ptr <= '7')
        {
          new_char = (new_char << 3) | (*c_ptr++ - '0');
        }
      }

      return new_char;
    }
    // - process char represented by hexadecimal number -
    else if (*c_ptr == 'x')
    {
      c_ptr++;
      unsigned short new_char = 0;

      // - first char in hexadecimal representation -
      if (*c_ptr >= '0' && *c_ptr <= '9')
      {
        new_char = *c_ptr++ - '0';
      }
      else if (*c_ptr >= 'a' && *c_ptr <= 'f')
      {
        new_char = 10 + (*c_ptr++ - 'a');
      }
      else if (*c_ptr >= 'A' && *c_ptr <= 'F')
      {
        new_char = 10 + (*c_ptr++ - 'A');
      }
      else
      {
        debug_assert(0);
      }

      // - second char in hexadecimal representation -
      if (*c_ptr >= '0' && *c_ptr <= '9')
      {
        new_char = (new_char << 4) | (*c_ptr++ - '0');
      }
      else if (*c_ptr >= 'a' && *c_ptr <= 'f')
      {
        new_char = (new_char << 4) | (10 + (*c_ptr++ - 'a'));
      }
      else if (*c_ptr >= 'A' && *c_ptr <= 'F')
      {
        new_char = (new_char << 4) | (10 + (*c_ptr++ - 'A'));
      }

      return new_char;
    }
    else
    {
      switch (*c_ptr++)
      {
      case 'a':
        return '\a';
      case 'b':
        return '\b';
      case 'f':
        return '\f';
      case 'n':
        return '\n';
      case 'r':
        return '\r';
      case 't':
        return '\t';
      case 'v':
        return '\v';
      case '\\':
        return '\\';
      case '?':
        return'?';
      case '\'':
        return '\'';
      case '"':
        return'"';
      case '>':
        return '>';
      case '}':
        return '}';
      case ']':
        return ']';
      case '|':
        return '|';
      default:
        cassert(0);
        return 0xffff;
      }
    }
  }
  else
  {
    return *c_ptr++;
  }
}/*}}}*/

inline bool reg_parser_s::process_reg_exp(string_s &source_string)
{/*{{{*/
  return parse_reg_exp(source_string) && NKA_to_DKA();
}/*}}}*/

// -- p_terminal_s --
@begin
inlines p_terminal_s
@end

// -- p_terminals_s --
@begin
inlines p_terminals_s
@end

// -- p_nonterminal_s --
@begin
inlines p_nonterminal_s
@end

// -- p_nonterminals_s --
@begin
inlines p_nonterminals_s
@end

// -- p_rule_s --
@begin
inlines p_rule_s
@end

// -- p_rules_s --
@begin
inlines p_rules_s
@end

// -- p_kernel_s --
@begin
inlines p_kernel_s
@end

// -- p_kernels_s --
@begin
inlines p_kernels_s
@end

// -- p_lalr_table_s --
@begin
inlines p_lalr_table_s
@end

inline unsigned &p_lalr_table_s::value(unsigned a_x_idx,unsigned a_y_idx)
{/*{{{*/
  register unsigned t_idx = a_y_idx*x_size + a_x_idx;
  debug_assert(t_idx < table.used);
  return table.data[t_idx];
}/*}}}*/

inline void p_lalr_table_s::resize(unsigned a_x_size,unsigned a_y_size)
{/*{{{*/
  x_size = a_x_size;
  y_size = a_y_size;
  table.copy_resize(a_y_size*a_x_size);
}/*}}}*/

inline void p_lalr_table_s::fill(unsigned a_value)
{/*{{{*/
  table.fill(a_value);
}/*}}}*/

// -- p_creat_descr_s --
@begin
inlines p_creat_descr_s
@end

inline bool p_creat_descr_s::load_from_rule_string(string_s &rule_string)
{/*{{{*/
  return load_from_rule_char_ptr(rule_string.size - 1,rule_string.data);
}/*}}}*/

// -- p_rule_descr_s --
@begin
inlines p_rule_descr_s
@end

// -- p_rule_descrs_s --
@begin
inlines p_rule_descrs_s
@end

// -- parser_s --
@begin
inlines parser_s
@end

#endif


