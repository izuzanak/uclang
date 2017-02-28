
#ifndef __SPAWNER_H
#define __SPAWNER_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED

#include <fcntl.h>
#include <poll.h>
#include <sys/wait.h>

/*
 * constants and definitions
 */

const unsigned c_spwn_rule_cnt = 22;
const unsigned spwn_rule_head_idxs[c_spwn_rule_cnt] = {15, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 19, 20, 18, 19, 20, 21, 21, 21, 21, 22, };
const unsigned spwn_rule_body_lengths[c_spwn_rule_cnt] = {2, 1, 2, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

#define spwn_blank c_idx_not_exist
#define SPWN_SHIFT(VALUE) VALUE
#define SPWN_REDUCE(VALUE) c_spwn_lalr_table_reduce_base + VALUE
#define SPWN_GOTO(VALUE) VALUE

const unsigned c_spwn_lalr_table_reduce_base = 0x80000000;
const unsigned c_spwn_terminal_plus_nonterminal_cnt = 23;
const unsigned spwn_lalr_state_cnt = 31;

const unsigned spwn_lalr_table[spwn_lalr_state_cnt*c_spwn_terminal_plus_nonterminal_cnt] =
{/*{{{*/
   SPWN_SHIFT(10),   SPWN_SHIFT(12),   SPWN_SHIFT(14),    SPWN_SHIFT(9),   SPWN_SHIFT(11),   SPWN_SHIFT(13),    SPWN_SHIFT(6),    SPWN_SHIFT(7),       spwn_blank,   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,       spwn_blank,       spwn_blank,     SPWN_GOTO(1),     SPWN_GOTO(2),     SPWN_GOTO(3),     SPWN_GOTO(4),     SPWN_GOTO(5),     SPWN_GOTO(8),    SPWN_GOTO(15),
   SPWN_SHIFT(10),   SPWN_SHIFT(12),   SPWN_SHIFT(14),    SPWN_SHIFT(9),   SPWN_SHIFT(11),   SPWN_SHIFT(13),    SPWN_SHIFT(6),    SPWN_SHIFT(7),       spwn_blank,   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,   SPWN_SHIFT(21),       spwn_blank,       spwn_blank,    SPWN_GOTO(20),     SPWN_GOTO(3),     SPWN_GOTO(4),     SPWN_GOTO(5),     SPWN_GOTO(8),    SPWN_GOTO(15),
   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),       spwn_blank,   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),   SPWN_REDUCE(1),       spwn_blank,   SPWN_REDUCE(1),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(22),   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(23),    SPWN_GOTO(15),
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(24),   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(25),    SPWN_GOTO(15),
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(26),    SPWN_GOTO(15),
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(27),    SPWN_GOTO(15),
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(19),   SPWN_SHIFT(16),   SPWN_SHIFT(17),   SPWN_SHIFT(18),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(28),    SPWN_GOTO(15),
  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),       spwn_blank,  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),  SPWN_REDUCE(10),       spwn_blank,  SPWN_REDUCE(10),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,  SPWN_REDUCE(11),  SPWN_REDUCE(11),  SPWN_REDUCE(11),  SPWN_REDUCE(11),  SPWN_REDUCE(11),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,  SPWN_REDUCE(14),  SPWN_REDUCE(14),  SPWN_REDUCE(14),  SPWN_REDUCE(14),  SPWN_REDUCE(14),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,  SPWN_REDUCE(12),  SPWN_REDUCE(12),  SPWN_REDUCE(12),  SPWN_REDUCE(12),  SPWN_REDUCE(12),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,  SPWN_REDUCE(15),  SPWN_REDUCE(15),  SPWN_REDUCE(15),  SPWN_REDUCE(15),  SPWN_REDUCE(15),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,  SPWN_REDUCE(13),  SPWN_REDUCE(13),  SPWN_REDUCE(13),  SPWN_REDUCE(13),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,  SPWN_REDUCE(16),  SPWN_REDUCE(16),  SPWN_REDUCE(16),  SPWN_REDUCE(16),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),       spwn_blank,  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),  SPWN_REDUCE(17),       spwn_blank,  SPWN_REDUCE(17),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),       spwn_blank,  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),  SPWN_REDUCE(18),       spwn_blank,  SPWN_REDUCE(18),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),       spwn_blank,  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),  SPWN_REDUCE(19),       spwn_blank,  SPWN_REDUCE(19),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),       spwn_blank,  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),  SPWN_REDUCE(20),       spwn_blank,  SPWN_REDUCE(20),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),       spwn_blank,  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),  SPWN_REDUCE(21),       spwn_blank,  SPWN_REDUCE(21),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),       spwn_blank,   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),   SPWN_REDUCE(2),       spwn_blank,   SPWN_REDUCE(2),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(19),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(29),
   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),       spwn_blank,   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),   SPWN_REDUCE(5),       spwn_blank,   SPWN_REDUCE(5),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,   SPWN_SHIFT(19),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,    SPWN_GOTO(30),
   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),       spwn_blank,   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),   SPWN_REDUCE(6),       spwn_blank,   SPWN_REDUCE(6),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),       spwn_blank,   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),   SPWN_REDUCE(7),       spwn_blank,   SPWN_REDUCE(7),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),       spwn_blank,   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),   SPWN_REDUCE(8),       spwn_blank,   SPWN_REDUCE(8),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),       spwn_blank,   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),   SPWN_REDUCE(9),       spwn_blank,   SPWN_REDUCE(9),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),       spwn_blank,   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),   SPWN_REDUCE(3),       spwn_blank,   SPWN_REDUCE(3),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),       spwn_blank,   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),   SPWN_REDUCE(4),       spwn_blank,   SPWN_REDUCE(4),       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,       spwn_blank,
};/*}}}*/

/*
 * definition of generated structures
 */

// -- spawn_parser_s --
@begin
struct
<
string_s:source_string
unsigned:old_input_idx
bi_array_s:fd_stack
string_array_s:arguments
lalr_stack_s:lalr_stack
>

additions
{
  // - open file with requested flags -
  static int open_file(char *ptr,char *ptr_end,int flags);

  // - return index of next terminal symbol (token) in input source -
  unsigned recognize_terminal(unsigned &a_input_idx);

  // - parse input string -
  bool parse_source(string_s &a_string);
}

spawn_parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- spawn_parser_s --
@begin
inlines spawn_parser_s
@end

// - spawner global functions -

/*!
 * \brief function implementing process spawner
 * \param spawner_path - path to spawner fifo pipe
 * \param spawn_args - list of spawn arguments
 */
int run_spawner(const char *proc_name,const char *spawner_path,string_array_s &spawn_args);

#endif

#endif

