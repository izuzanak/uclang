
@begin
include "spawner.h"
include "spawn_parse_actions.h"
@end

#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED

/*
 * constants and definitions
 */

const unsigned spwn_rule_head_idxs[c_spwn_rule_cnt] = {15, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 19, 20, 18, 19, 20, 21, 21, 21, 21, 22, };
const unsigned spwn_rule_body_lengths[c_spwn_rule_cnt] = {2, 1, 2, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
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
 * global spawner variables
 */

atomic_s g_spawner_running = {0};

/*
 * methods of generated structures
 */

// -- spawn_parser_s --
@begin
methods spawn_parser_s
@end

int spawn_parser_s::open_file(char *ptr,char *ptr_end,int flags)
{/*{{{*/

  // - remove enclosing characters -
  if (*ptr == '\'' || *ptr == '"')
  {
    ++ptr;
    --ptr_end;
  }

  char tmp_char = *ptr_end;
  *ptr_end = '\0';

  // - open file -
  int fd = open(ptr,flags,0666);
  *ptr_end = tmp_char;

  return fd;
}/*}}}*/

unsigned spawn_parser_s::recognize_terminal(unsigned &a_input_idx) // lgtm [cpp/use-of-goto]
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define SPWN_GET_NEXT_CHAR() \
  {\
    if (a_input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[a_input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define SPWN_CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
\
    a_input_idx++;\
  }

   unsigned char in_char;

// - STATE 0 -
   SPWN_GET_NEXT_CHAR();

   if (in_char == 0) {
      goto state_1_label;
   }
   if (in_char < 8) {
      goto state_2_label;
   }
   if (in_char == 8) {
      goto state_3_label;
   }
   if (in_char < 11) {
      goto state_10_label;
   }
   if (in_char < 14) {
      goto state_3_label;
   }
   if (in_char < 32) {
      goto state_2_label;
   }
   if (in_char == 32) {
      goto state_10_label;
   }
   if (in_char == 33) {
      goto state_2_label;
   }
   if (in_char == 34) {
      goto state_4_label;
   }
   if (in_char < 38) {
      goto state_2_label;
   }
   if (in_char == 38) {
      goto state_5_label;
   }
   if (in_char == 39) {
      goto state_6_label;
   }
   if (in_char < 48) {
      goto state_2_label;
   }
   if (in_char < 58) {
      goto state_7_label;
   }
   if (in_char < 60) {
      goto state_2_label;
   }
   if (in_char == 60) {
      goto state_8_label;
   }
   if (in_char == 61) {
      goto state_2_label;
   }
   if (in_char == 62) {
      goto state_9_label;
   }
   goto state_2_label;

// - STATE 1 -
state_1_label:
   SPWN_CLOSE_CHAR(14);
   return 14;

// - STATE 2 -
state_2_label:
   SPWN_CLOSE_CHAR(10);
   SPWN_GET_NEXT_CHAR();

   if (in_char >= 1 && in_char < 9) {
      goto state_2_label;
   }
   if (in_char >= 11 && in_char < 32) {
      goto state_2_label;
   }
   if (in_char == 33) {
      goto state_2_label;
   }
   if (in_char >= 35 && in_char < 38) {
      goto state_2_label;
   }
   if (in_char >= 40 && in_char < 60) {
      goto state_2_label;
   }
   if (in_char == 61) {
      goto state_2_label;
   }
   if (in_char >= 63) {
      goto state_2_label;
   }
   return 10;

// - STATE 3 -
state_3_label:
   SPWN_CLOSE_CHAR(10);
   SPWN_GET_NEXT_CHAR();

   if (in_char >= 1 && in_char < 8) {
      goto state_2_label;
   }
   if (in_char == 8) {
      goto state_3_label;
   }
   if (in_char >= 9 && in_char < 11) {
      goto state_10_label;
   }
   if (in_char >= 11 && in_char < 14) {
      goto state_3_label;
   }
   if (in_char >= 14 && in_char < 32) {
      goto state_2_label;
   }
   if (in_char == 32) {
      goto state_10_label;
   }
   if (in_char == 33) {
      goto state_2_label;
   }
   if (in_char >= 35 && in_char < 38) {
      goto state_2_label;
   }
   if (in_char >= 40 && in_char < 60) {
      goto state_2_label;
   }
   if (in_char == 61) {
      goto state_2_label;
   }
   if (in_char >= 63) {
      goto state_2_label;
   }
   return 10;

// - STATE 4 -
state_4_label:
   SPWN_CLOSE_CHAR(c_idx_not_exist);
   SPWN_GET_NEXT_CHAR();

   if (in_char < 34) {
      goto state_4_label;
   }
   if (in_char == 34) {
      goto state_12_label;
   }
   goto state_4_label;

// - STATE 5 -
state_5_label:
   SPWN_CLOSE_CHAR(8);
   SPWN_GET_NEXT_CHAR();

   if (in_char == 62) {
      goto state_13_label;
   }
   return 8;

// - STATE 6 -
state_6_label:
   SPWN_CLOSE_CHAR(c_idx_not_exist);
   SPWN_GET_NEXT_CHAR();

   if (in_char < 39) {
      goto state_6_label;
   }
   if (in_char == 39) {
      goto state_14_label;
   }
   goto state_6_label;

// - STATE 7 -
state_7_label:
   SPWN_CLOSE_CHAR(9);
   SPWN_GET_NEXT_CHAR();

   if (in_char >= 1 && in_char < 9) {
      goto state_2_label;
   }
   if (in_char >= 11 && in_char < 32) {
      goto state_2_label;
   }
   if (in_char == 33) {
      goto state_2_label;
   }
   if (in_char >= 35 && in_char < 38) {
      goto state_2_label;
   }
   if (in_char >= 40 && in_char < 48) {
      goto state_2_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_7_label;
   }
   if (in_char >= 58 && in_char < 60) {
      goto state_2_label;
   }
   if (in_char == 60) {
      goto state_15_label;
   }
   if (in_char == 61) {
      goto state_2_label;
   }
   if (in_char == 62) {
      goto state_16_label;
   }
   if (in_char >= 63) {
      goto state_2_label;
   }
   return 9;

// - STATE 8 -
state_8_label:
   SPWN_CLOSE_CHAR(0);
   return 0;

// - STATE 9 -
state_9_label:
   SPWN_CLOSE_CHAR(1);
   SPWN_GET_NEXT_CHAR();

   if (in_char == 62) {
      goto state_17_label;
   }
   return 1;

// - STATE 10 -
state_10_label:
   SPWN_CLOSE_CHAR(13);
   SPWN_GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14) {
      goto state_10_label;
   }
   if (in_char == 32) {
      goto state_10_label;
   }
   return 13;

// - STATE 11 -
state_11_label:
   SPWN_CLOSE_CHAR(9);
   SPWN_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_11_label;
   }
   if (in_char == 60) {
      goto state_15_label;
   }
   if (in_char == 62) {
      goto state_16_label;
   }
   return 9;

// - STATE 12 -
state_12_label:
   SPWN_CLOSE_CHAR(11);
   return 11;

// - STATE 13 -
state_13_label:
   SPWN_CLOSE_CHAR(6);
   SPWN_GET_NEXT_CHAR();

   if (in_char == 62) {
      goto state_18_label;
   }
   return 6;

// - STATE 14 -
state_14_label:
   SPWN_CLOSE_CHAR(12);
   return 12;

// - STATE 15 -
state_15_label:
   SPWN_CLOSE_CHAR(3);
   return 3;

// - STATE 16 -
state_16_label:
   SPWN_CLOSE_CHAR(4);
   SPWN_GET_NEXT_CHAR();

   if (in_char == 62) {
      goto state_19_label;
   }
   return 4;

// - STATE 17 -
state_17_label:
   SPWN_CLOSE_CHAR(2);
   return 2;

// - STATE 18 -
state_18_label:
   SPWN_CLOSE_CHAR(7);
   return 7;

// - STATE 19 -
state_19_label:
   SPWN_CLOSE_CHAR(5);
   return 5;

}/*}}}*/

bool spawn_parser_s::parse_source(string_s &a_string)
{/*{{{*/
  source_string.swap(a_string);

  old_input_idx = 0;

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

#define SPWN_PARSE_SOURCE_RETURN() \
  source_string.swap(a_string);

  do
  {
    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_6(fprintf(stderr,"spwn_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        SPWN_PARSE_SOURCE_RETURN();
        return false;
      }

      // - skipping of _SKIP_ terminals -
      if (ret_term == 13)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve action from table of actions -
    unsigned parse_action = spwn_lalr_table[(lalr_stack.last().lalr_state*c_spwn_terminal_plus_nonterminal_cnt) + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
      SPWN_PARSE_SOURCE_RETURN();
      return false;
    }

    // - action SPWN_SHIFT -
    if (parse_action < c_spwn_lalr_table_reduce_base)
    {
      if (ret_term == 14)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action SPWN_REDUCE-
    else
    {
      parse_action -= c_spwn_lalr_table_reduce_base;

      // - call function assigned to reduction -
      if (spawn_pa_callers[parse_action] != pa_spawn_null)
      {
        if (!spawn_pa_callers[parse_action](*this))
        {
          SPWN_PARSE_SOURCE_RETURN();
          return false;
        }
      }

      // - remove rule body from lalr_stack -
      lalr_stack.used -= spwn_rule_body_lengths[parse_action];

      // - insert new automat state to stack -
      unsigned goto_val = spwn_lalr_table[(lalr_stack.last().lalr_state*c_spwn_terminal_plus_nonterminal_cnt) + spwn_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(true);

  SPWN_PARSE_SOURCE_RETURN();
  return true;
}/*}}}*/

// - spawner global functions -

int run_spawner(const char *proc_name,const char *spawner_path,string_array_s &spawn_args)
{/*{{{*/

  // - set spawner running flag -
  g_spawner_running.atomic_set(1);

  // - create spawner fifo -
  if (mkfifo(spawner_path,0666) != 0)
  {
    fprintf(stderr,"%s: Cannot create spawner fifo \"%s\"\n",proc_name,spawner_path);

    return -1;
  }

  do {

    // - open spawner fifo for reading -
    int fd = open(spawner_path,O_RDONLY | O_NONBLOCK);
    if (fd == -1)
    {
      fprintf(stderr,"%s: Cannot open spawner fifo \"%s\"\n",proc_name,spawner_path);

      // - delete spawner fifo -
      remove(spawner_path);

      return -1;
    }

    // - initialize pollfd structure -
    pollfd pfd = {fd,POLLIN | POLLPRI,0};

    // - line data buffer -
    bc_array_s line_buffer;
    line_buffer.init();

#define RUN_SPAWNER_FIFO_READ_ERROR() \
{/*{{{*/\
  fprintf(stderr,"%s: Error while reading from spawner fifo\n",proc_name);\
\
  line_buffer.clear();\
\
  /* - delete spawner fifo - */\
  remove(spawner_path);\
}/*}}}*/

    {
      const ssize_t c_buffer_add = 256;

      ssize_t read_cnt;
      do
      {
        // - poll for data on spawner fifo -
        int poll_res = poll(&pfd,1,100);

        // - ERROR -
        if (poll_res == -1 && errno != EINTR)
        {
          RUN_SPAWNER_FIFO_READ_ERROR();

          return -1;
        }

        if (poll_res > 0)
        {
          unsigned old_used = line_buffer.used;
          line_buffer.push_blanks(c_buffer_add);

          // - read from spawner fifo -
          read_cnt = read(fd,line_buffer.data + old_used,c_buffer_add);

          // - ERROR -
          if (read_cnt == -1)
          {
            RUN_SPAWNER_FIFO_READ_ERROR();

            return -1;
          }

          line_buffer.used = old_used + read_cnt;

          if (read_cnt == 0)
          {
            break;
          }
        }

        // - collect child statuses -
        int status;
        while (waitpid(-1,&status,WNOHANG) > 0) {};
      }
      while(g_spawner_running.value());

      line_buffer.push('\0');
    }

    // - close spawner fifo -
    close(fd);

    // - command begin pointer -
    char *cmd_begin = line_buffer.data;
    char *buffer_end = line_buffer.data + line_buffer.used;

    do {

      // - find command end pointer -
      char *cmd_end = strchrnul(cmd_begin,'\n');
      *cmd_end = '\0';

      if (cmd_begin < cmd_end)
      {
        // - check spawner stop request -
        if (!g_spawner_running.value() ||
            strcmp("uclang-spawner-stop",cmd_begin) == 0)
        {
          line_buffer.clear();

          // - delete spawner fifo -
          if (remove(spawner_path) != 0)
          {
            fprintf(stderr,"%s: Cannot remove spawner fifo \"%s\"\n",proc_name,spawner_path);

            return -1;
          }

          return 0;
        }

        // - fork process in order to create spawn -
        pid_t pid = fork();
        if (pid == -1)
        {
          fprintf(stderr,"%s: Cannot fork in order to create spawn\n",proc_name);

          return -1;
        }

        // - process is spawned child process -
        if (pid == 0)
        {
          // - retrieve spawn command string -
          string_s spawn_cmd;
          spawn_cmd.size = (cmd_end - cmd_begin) + 1;
          spawn_cmd.data = cmd_begin;

          // - create spawn parser -
          spawn_parser_s spawn_parser;
          spawn_parser.init();

          // - parse spawn command -
          if (!spawn_parser.parse_source(spawn_cmd) ||
              spawn_parser.arguments.used == 0)
          {
            spawn_parser.clear();
            line_buffer.clear();

            fprintf(stderr,"%s: Invalid spawn command\n",proc_name);

            return -1;
          }

          // - retrieve spawn arguments -
          spawn_args.swap(spawn_parser.arguments);

          spawn_parser.clear();
          line_buffer.clear();

          return 1;
        }
      }

      // - set begin of next command -
      cmd_begin = cmd_end + 1;

    } while(cmd_begin < buffer_end);

    line_buffer.clear();

  } while(true);
}/*}}}*/

#endif

